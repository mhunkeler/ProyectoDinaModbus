void analog_init()
{
	ADCON1=0;
	ADCON2=0;
	ADCON3=0;
	ADCON2bits.PVCFG = 0; // Vref+ = AVdd
	ADCON2bits.NVCFG = 0; // Vref- = AVss
	ADCON3bits.ADRC = 0; // Conversion clock derived from system clock.
	ADCON3bits.ADCS = 15; // Divide system clock by 16(TAD = 1uS @ 16 MIPS).
	ADCON1bits.FORM = 0; // Output format is unsigned integer.
	ADCON2bits.BUFORG = 1; // Result buffer is an indexed buffer.
	ADCON1bits.PWRLVL = 0; // Low power, reduced frequency operation.
	ADL0CONL = 0;
	ADL0CONH = 0;
	ADL0CONLbits.SLSIZE = 1-1; // Sample list length: 1 channels.
	ADL0CONHbits.ASEN = 1; // Enable auto-scan.
	ADL0CONHbits.SLINT = 1; // Interrupt after auto-scan completion.
	ADL0CONHbits.SAMC = 15; // Sample time is 15 TAD.
	ADL0CONLbits.SLTSRC = 0; // Single trigger generated when SAMP is cleared.
	ADL0PTR = 0; // Start from the first list entry.
	ADL0CONHbits.CM = 0; // Disable threshold compare.
	ADTBL0bits.ADCH = 13; // Channel #13.  //TODO: hardcodeado el 13
	ADCON1bits.ADON = 1; // Enable A/D.
	while(ADSTATHbits.ADREADY == 0); // Wait for ready flag set.
	ADL0CONLbits.SAMP = 1; // Close sample switch.
	ADL0CONLbits.SLEN = 1; // Enable sample list.
}
uint16_t readADC()
{
	IFS0bits.AD1IF = 0; // Start conversion.
	ADL0CONLbits.SAMP = 0; // Wait for the result.
	while(IFS0bits.AD1IF == 0);
	ADL0CONLbits.SAMP = 1; // Close the sample switch.
	return ADRES0; // Read result for the channel #2.
}
