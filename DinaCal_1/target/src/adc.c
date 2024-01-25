 uint16_t readADC()
{
	int16_t count;
	uint16_t result;
	SD1CON1bits.PWRLVL = 0; // Low power, normal bandwidth
	SD1CON1bits.SDREFP = 0; // Positive Voltage Reference is SVDD
	SD1CON1bits.SDREFN = 0; // Negative Voltage Reference is SVSS
	SD1CON1bits.VOSCAL = 0; // Internal Offset Measurement is disabled
	SD1CON1bits.DITHER = 1; // Low Dither
	SD1CON1bits.SDGAIN = 2; // Gain is 1:4
	SD1CON2bits.RNDRES = 2; // Round result to 16-bit
	SD1CON2bits.SDWM = 1; // SDxRESH/SDxRESL updated on every Interrupt
	SD1CON2bits.CHOP = 3; // Chopping should be enabled
	SD1CON3bits.SDCH = 2; // CH1SE/SVSS (single-ended measurement of CH1SE) // 0; Channel 0 (see the specific device data sheet)
	SD1CON3bits.SDCS = 1; // Clock Source is a 8 MHz FRC
	SD1CON3bits.SDOSR = 0; // Oversampling Ratio (OSR) is 1024 (best quality)
	SD1CON3bits.SDDIV = 1; // Input Clock Divider is 2 (SD ADC clock is 4MHz)
	SD1CON2bits.SDINT = 3; // Interrupt on every data output
	IFS6bits.SDA1IF = 0; // Clear interrupt flag
	SD1CON1bits.SDON = 1;
	for(count=0; count<8; count++)
	{
	IFS6bits.SDA1IF = 0;
	while(IFS6bits.SDA1IF == 0);
	}
	result = SD1RESH;
    return result;
}
void analog_init()
{
}
