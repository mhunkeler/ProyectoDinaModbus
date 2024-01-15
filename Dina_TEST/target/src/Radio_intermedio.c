void Intermedio_FSK_Init(void)
{
    RF_Init();
}
void SendFSKMessage(uint8_t* data, uint8_t length)
{
	if (!tx_pending_data)   //If there isn't data to send.
	{
		message_length = length + 2;
		message[0] = idGrupo;
        message[1] = tx_packet_id++;
        for(int i = 0; i<length; i++)
        {
            message[i+2]=data[i];
        }
		tx_pending_data = 1;
        tx_right = TX_SENDING;
	}
}
uint8_t ReadFSKMessage(void)
{
    read_data_length = Radio_Read(read_data);   //Read the new data.
    if (read_data_length > 2 && read_data[1] != last_rx_packet_id)
    {
        last_rx_packet_id = read_data[1];
        new_data_to_read = 1;                   //Set the flag that indicates this.
        return 1;
    }
    else return 0;
}
int8_t Sending_Available(void)
{
    if (tx_right == TX_NO_ACK)
    {
        tx_right = TX_AVAILABLE;
        return TX_NO_ACK;
    }
    else
    return tx_right;
}
uint8_t Data_Available(void)
{
    if (new_data_to_read)
    {
        new_data_to_read = 0;
        return 1;
    }
    return 0;
}
uint8_t Read_Data(uint8_t* data)
{
    for(int i = 0 ; i < read_data_length-2 ; i++)
    {
        data[i]=read_data[i+2];
    }
    return read_data_length-2;
}
void Radio_Int_Sleep(void)
{
    SleepFlag = 1;
}
void Radio_Int_WakeUp(void)
{
    SleepFlag = -1;
}
void Intermedio_FSK_Poll(void)
{
	static int8_t estadoRf = RF_WAIT;
	static int8_t estadoRx = RX_IN;
    static int8_t estadoTx = TX_IN;
    static uint8_t txRetries = 0;
    static uint32_t txCRCTimeOut = 0;
	static uint32_t txSendingTimeOut = 0;
    static uint8_t rxACKcount = 0;
    uint16_t radioStatus;
	radioStatus = Radio_getStatus();
	switch (estadoRf)
	{
		case RF_SLEEP:
		{
            switch (SleepFlag)
            {
            case 1:
                SleepFlag = 0;
                break;
            case -1:
                SleepFlag = 0;
                estadoRf = RF_WAIT;
                Radio_EntryRx();
                break;
            default:
                break;
            }
			break;
		}
		case RF_WAIT:
		{
            if (SleepFlag == 1)
            {
                SleepFlag = 0;
                estadoRf = RF_SLEEP;
                Radio_Sleep();
            }
			else if (Radio_isPayloadReady(radioStatus)) 	    //Is there a message?
			{           
				estadoRf = RF_RX;					            //Reads data.
			} else if (tx_pending_data)				            //If not, and if there is data to send.
            {           
                estadoRf = RF_TX;					            //Sends data.
            }
            break;
        }
		case RF_TX:
		{
			switch(estadoTx)
			{
				case TX_IN:
				{
                    Radio_EntryStandby();
                    __delay_ms(1);
                    Radio_Transmit(message, message_length);    //Put the new message in the chip´s FIFO.
					Radio_EntryTx();                            //Put the chip in TX mode.
                    estadoTx = TX_SENDING_DATA;                 //Changes to the next state.
                    txSendingTimeOut = timeStamp;               //Save the current time to avoid freezing caused by incorrect FIFO data.
					break;
				}
				case TX_SENDING_DATA:
				{
					if (Radio_isPacketSent(radioStatus))        //ACA HAY UN PROBLEMA
					{
                        Radio_EntryRx();                        //Put the chip in RX mode.
						estadoTx = TX_WAITING_ACK;              //Goes to the next state.
                        txCRCTimeOut = timeStamp;               //Set the current time for time out control.
					}
                    break;
				}
                case TX_WAITING_ACK:
                {
                    if (Radio_isCrcOk(radioStatus)) 	        //Is there a CRC OK?
			        {
                        Radio_ClearFIFO();                      //Clear the chip FIFO.
                        estadoTx = TX_IN;                       //Reinitialize the TX states machine.
                        estadoRf = RF_WAIT;                     //Go to the stable state.
						tx_pending_data = 0;                    //Clear the flag that indicates that there are sending data.
                        tx_right = TX_AVAILABLE;
                        txRetries = 0;
                    }
                    else if (timeStamp - txCRCTimeOut > 25)     //Is timeOut?   
                    {
                        if (txRetries < 10)                     //Are there retries left?
                        {
                            txRetries++;                        //Try a new retry.
                            estadoTx = TX_IN;                   //Goes to the first state.                   
                        }
                        else                                    
                        {
                            txRetries = 0;                      //Clear the number of tries.
                            estadoTx = TX_IN;                   //Reinitialize the TX states machine.           
                            estadoRf = RF_WAIT;                 //Go to the stable state.
                            tx_pending_data = 0;                //Clear the flag that indicates that there are sending data.
                            tx_right = TX_NO_ACK;               //Set the flag that indicates that an error occurs.
                        }
                    }
                }
			}			
			break;
		}
        case RF_RX:
        {
			switch (estadoRx)
            {
                case RX_IN:
                {
                    if(ReadFSKMessage())						//Executes the event.
                    {
                        estadoRx = RX_SEND_ACK_IN;                  //Changes to the next state.
                        rxACKcount = 0;
                    }
                    else
                    {
                        estadoRf = RF_WAIT;	                    //Go to the stable state.
                    }
                    Radio_ClearFIFO();                      //Clear the chip FIFO.
                    break;
                }
                case RX_SEND_ACK_IN:
                {
                    if (rxACKcount < 3)
                    {
                        rxACKcount++;
                        Radio_EntryStandby();
                        __delay_ms(1);
                        Radio_Transmit(&idGrupo, 1);            //Sending a CRC OK.
                        Radio_EntryTx();                        //Put the chip in TX mode.
                        estadoRx = RX_SENDING_ACK;              //Changes to the next state.
                    }
                    else if (Radio_isPacketSent(radioStatus))        //Was the CRC OK message sent?
                    {
                        Radio_EntryRx();                        //Put the chip in RX mode.
                        estadoRx = RX_IN;                       //Reinitilize the RX states machine.
                        estadoRf = RF_WAIT;	                    //Go to the stable state.
                    }
                    break;
                }
                case RX_SENDING_ACK:
                {
                    if (Radio_isPacketSent(radioStatus))        //Was the CRC OK message sent?
                    {
                        estadoRx = RX_SEND_ACK_IN;                       //Reinitilize the RX states machine.
                    }
                    break;
                }
            }
        }
    }
}
