void ICN_init(uint8_t number)
{
}
void ICN_Config(uint8_t cnNum)
{
	__builtin_write_OSCCONL(OSCCON & 0xBF);
	if(cnNum <= 15)
	{
		CNEN1 = CNEN1 | (0x01<<cnNum);
	}
	else
	{
		CNEN2 = CNEN2 | (0x01<<(cnNum-16));
	}
	IEC1bits.CNIE=1;
	IFS1bits.CNIF=0;
	__builtin_write_OSCCONL(OSCCON | 0x40);
}
void __attribute__((interrupt(auto_psv))) _CNInterrupt (void)
{
	IFS1bits.CNIF=0;
}
