void FSK_Init(void)			//TODO: Unicamente para TESTEO
{
    FskChart.packet0 = (uint8_t*) &resampledAcc[0];   // Puntero al inicio de resampledAcc
    FskChart.packet1 = (uint8_t*) &resampledAcc[16];  // Puntero al elemento 16 de resampledAcc
    FskChart.packet2 = (uint8_t*) &resampledAcc[32];  // Puntero al elemento 32 de resampeAcc
    FskChart.packet3 = (uint8_t*) &resampledAcc[48];  // Puntero al elemento 48 de resampeAcc
    FskChart.packet4 = (uint8_t*) &resampledForc[0];   // Puntero al inicio de resampledForc
    FskChart.packet5 = (uint8_t*) &resampledForc[16];  // Puntero al elemento 16 de resampledForc
    FskChart.packet6 = (uint8_t*) &resampledForc[32];  // Puntero al elemento 32 de resampledForc
    FskChart.packet7 = (uint8_t*) &resampledForc[48];  // Puntero al elemento 48 de resampledForc
    FskChart.packet8 = (uint8_t*) &sourfaceCardInfo;  // Puntero a ..
    FskChart.packet9 = (uint8_t*) &sourfaceCardInfo;  // Puntero a ..
}
void RadioSleep(void)
{
	Radio_Int_Sleep();
}
void RadioWakeUp(void)
{
	Radio_Int_WakeUp();
}
void pFSKM(char* message)
{
	fskSendFlag = 2;
	fskMessageLength = strlen(message);
	fskMessage[0] = FRAME_MESSAGE;
	strcpy((char*)(fskMessage+1),(char*)message);
}
void pFSKD()
{
	fskSendFlag = 1;
	Sended_Data = 0;
}
void FSK_Poll(void)
{
	switch (FskApi_state)
	{
	case SENDING_CHART:
		switch (Sending_Available())
		{
		case TX_NO_ACK:
		{
			errorFSK();
			FskApi_state = WAITING;
			break;
		}
		case TX_SENDING:
			break;
		case TX_AVAILABLE:
		{
			if(Sended_Data >= PacketsCounts)
			{
				Sended_Data=0;
				FskApi_state=WAITING;
				break;
			}
			uint8_t data[34] = "";
			data[0] = FRAME_DATA;
			data[1] = Sended_Data;
			switch(data[1])
                {
					case 0:
						for(int i = 0; i < 32 ; i++)
						{
							data[i+2] = FskChart.packet0[i];
						}
						break;
                    case 1:
                        for(int i = 0; i < 32 ; i++)
                        {
                            data[i+2] = FskChart.packet1[i];
                        }
                        break;
                    case 2:
                        for(int i = 0; i < 32 ; i++)
                        {
                        	data[i+2] = FskChart.packet2[i];
                        }
                        break;
                    case 3:
                        for(int i = 0 ; i < 32 ; i++)
                        {
                            data[i+2] = FskChart.packet3[i];
                        }
                        break;
					case 4:
						for(int i = 0; i < 32 ; i++)
						{
							data[i+2] = FskChart.packet4[i];
						}
						break;
                    case 5:
                        for(int i = 0; i < 32 ; i++)
                        {
                            data[i+2] = FskChart.packet5[i];
                        }
                        break;
                    case 6:
                        for(int i = 0; i < 32 ; i++)
                        {
                        	data[i+2] = FskChart.packet6[i];
                        }
                        break;
                    case 7:
                        for(int i = 0 ; i < 32 ; i++)
                        {
                            data[i+2] = FskChart.packet7[i];
                        }
                        break;
                    case 8:
                        for(int i = 0 ; i < 32 ; i++)
                        {
                            data[i+2] = FskChart.packet8[i];
                        }
                        break;
                }
			SendFSKMessage(data, 34);
			Sended_Data++;
			break;
		}
		default:
			break;
		}
		break;
	case WAITING:
	{
		if(Data_Available())
		{
			uint8_t data[34] = "";
			uint8_t length = Read_Data(data);
			switch (data[0])
			{
			case FRAME_MESSAGE:
				break;
			case FRAME_DATA:
				switch(data[1])
                {
                    case 0:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet0[i-2] = data[i];
                        }
                        break;
                    case 1:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet1[i-2] = data[i];
                        }
                        break;
                    case 2:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet2[i-2] = data[i];
                        }
                        break;
                    case 3:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet3[i-2] = data[i];
                        }
                        break;
                    case 4:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet4[i-2] = data[i];
                        }
                        break;
                    case 5:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet5[i-2] = data[i];
                        }
                        break;
                    case 6:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet6[i-2] = data[i];
                        }
                        break;
                    case 7:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet7[i-2] = data[i];
                        }
                        break;
                    case 8:
                        for(int i = 2 ; i < length ; i++)
                        {
                           FskChart.packet8[i-2] = data[i];
                        }
                        break;
					default:
						break;
                }
				break;
			default:
				break;
			}
		}
		else if (fskSendFlag == 1)
		{
			FskApi_state = SENDING_CHART;
			fskSendFlag = 0;
		}
		else if (fskSendFlag == 2)
		{
			FskApi_state = SENDING_MESSAGE;
		}
	}
		break;
	case SENDING_MESSAGE:
	{
		switch (Sending_Available())
		{
			case TX_SENDING:
				break;
			case TX_NO_ACK:
			{
				errorFSK();
				FskApi_state = WAITING;
				fskSendFlag = 0;
				break;
			}
			case TX_AVAILABLE:
			{
				if (fskSendFlag)
				{
					SendFSKMessage(fskMessage, fskMessageLength+1);
					fskSendFlag = 0;
				}
				else
				{
					FskApi_state = WAITING;
				}
				break;
			}
			default:
				break;
		}
	}
		break;	
	default:
		break;
	}
}
