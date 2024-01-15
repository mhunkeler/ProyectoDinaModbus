void Radio_Encrypt(uint8_t* ptrClave)
{
	uint8_t i;
	uint8_t aux8=0x3E;
	if(ptrClave!=NULL)
	{
		if(strlen(ptrClave)<=16&&strlen(ptrClave))
		{
			Radio_spiWriteCMD(0x3D,0x13);//AES ON
			for(i=0;i<16;i++)
			{
				Radio_spiWriteCMD(aux8,*ptrClave);
				aux8&=0xFF;
				aux8+=0x01;
				if(*ptrClave!=0)
					ptrClave++;
			}
			return;
		}
	}
	Radio_spiWriteCMD(0x3D,0x02);//AES OFF
}
void Radio_Config()
{
  uint8_t i;
  for(i=0;i<3;i++)
	  Radio_spiWriteCMD(RFM69HFreqTbl[RadioFreqBuf_Addr][i]>>8,RFM69HFreqTbl[RadioFreqBuf_Addr][i]&0xff);           //setting frequency parameter
  for(i=0;i<2;i++)
	  Radio_spiWriteCMD(RFM69HRateTbl[RadioRateBuf_Addr][i]>>8,RFM69HRateTbl[RadioRateBuf_Addr][i]&0xff);           //setting rf rate parameter
  for(i=0;i<23;i++)
	  Radio_spiWriteCMD(RFM69HConfigTbl[i]>>8,RFM69HConfigTbl[i]&0xff);                          //setting base parameter
  Radio_spiWriteCMD(0x3A,idGrupo);//bdrcst
}
void Radio_EntryStandby(void)
{
	Radio_spiWriteCMD(0x01,0x04);
}
void Radio_EntryRx(void)
{
	uint8_t i;
	for(i=0;i<7;i++)                                         					//Define to Rx mode
		Radio_spiWriteCMD(RFM69HRxTbl[i]>>8,RFM69HRxTbl[i]&0xff);
}
void Radio_EntryTx(void)
{
	uint8_t i;
	Radio_spiWriteCMD(0x2D, 0x02);												//2 byte of preamble
	Radio_spiWriteCMD(RFM69HPowerTbl[0]>>8,RFM69HPowerTbl[0]&0xff); 			//Setting output power parameter
	for(i=0;i<6;i++)                                  							//Define to Tx mode
		Radio_spiWriteCMD(RFM69HTxTbl[i]>>8,RFM69HTxTbl[i]&0xff);
}
uint16_t Radio_getStatus(void)
{
	union Radio_Status_U ret;
	uint8_t highByte,lowByte;
	ret.b[1] = Radio_spiReadCMD(0x27);
	ret.b[0]  = Radio_spiReadCMD(0x28);
	return ret.w;
}
void Radio_ClearFIFO(void)
{
	Radio_spiWriteCMD(0x01,0x04);                                        //Standby
	Radio_spiWriteCMD(0x01,0x10);                                        //entry RxMode
}
void Radio_Sleep(void)
{
	Radio_spiWriteCMD(0x01,0x00);                                        //Sleep
}
void Radio_Standby(void)
{
	Radio_spiWriteCMD(0x01,0x04);                                        //Standby
}
uint8_t Radio_Read(uint8_t* buffer)
{
	uint8_t length;
	length=Radio_spiReadCMD(0x00);
	Radio_spiBurstRead(0x00, buffer,  length);
	return length; 
}
void Radio_Transmit(uint8_t* buffer, uint8_t length)
{
	Radio_spiWriteCMD(0x00,length);//addrx+addtx+ack
	Radio_spiBurstWrite(0x00, buffer, length);
}
void RF_Init()
{
		_ANSD1 = 0x00;
		_ANSD2 = 0x00;
		_ANSD3 = 0x00;
		_ANSD5 = 0x00;
		_ANSD4 = 0x00;
	HAL_GPIO_PinCfg(RFXReset, GPIO_OUTPUT);
	HAL_GPIO_PinCfg(RFXNCS, GPIO_OUTPUT);
  	HAL_GPIO_PinSet(RFXReset, GPIO_HIGH);
	HAL_GPIO_PinSet(RFXNCS, GPIO_HIGH);
  	SPI1_init(0,2);
	__delay_ms(50);
	HAL_GPIO_PinSet(RFXReset, GPIO_LOW);
	__delay_ms(40);
	HAL_GPIO_PinSet(RFXNCS, GPIO_LOW);
	uint8_t miClave[17];
	strcpy(miClave,"");
	Radio_Config();
	Radio_Encrypt(NULL);
	Radio_EntryRx();
}
void Radio_spiBurstWrite(uint8_t addr, uint8_t* ptr, uint8_t length)
{
	uint8_t i=0;
	HAL_GPIO_PinSet(RFXNCS, GPIO_LOW);
	addr |= 0x80;
	xchangeSPI1b_8(addr);
	for(i=0;i<length;i++)
	{
		xchangeSPI1b_8(ptr[i]);
	}
	HAL_GPIO_PinSet(RFXNCS, GPIO_HIGH);
}
void Radio_spiBurstRead(uint8_t addr, uint8_t* ptr, uint8_t length)
{
	uint8_t i=0;
	HAL_GPIO_PinSet(RFXNCS, GPIO_LOW);
	xchangeSPI1b_8(addr);
	for(i=0;i<length;i++)
	{
		ptr[i] = xchangeSPI1b_8(0x00);
	}
	HAL_GPIO_PinSet(RFXNCS, GPIO_HIGH);
}
uint8_t Radio_spiReadCMD(uint8_t addr)
{
	uint8_t data=0;
	HAL_GPIO_PinSet(RFXNCS, GPIO_LOW);
	xchangeSPI1b_8(addr);
	data = xchangeSPI1b_8(0x00);
	HAL_GPIO_PinSet(RFXNCS, GPIO_HIGH);
	return data;
}
void Radio_spiWriteCMD(uint8_t addr, uint8_t data)
{
	addr |= 0x80; //MSB must be "1" for write
	HAL_GPIO_PinSet(RFXNCS, GPIO_LOW);
	xchangeSPI1b_8(addr);
	xchangeSPI1b_8(data);
	HAL_GPIO_PinSet(RFXNCS, GPIO_HIGH);
}
uint8_t Radio_spiWriteRead(uint8_t byte)
{
	uint8_t data=0;
	HAL_GPIO_PinSet(RFXNCS, GPIO_LOW);
	data = xchangeSPI1b_8(byte);
	HAL_GPIO_PinSet(RFXNCS, GPIO_HIGH);
	return data;
}
