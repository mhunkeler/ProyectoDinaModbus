void init_timer4(void)
{
			T4CON = TMR_INTERNAL | TMR_DIV_BY_64;			//Interrupcion cada 0.001 Seg a CLK = 120 MH	
			PR4 =  ((FOSC/2)/64)/1000 ;	//938; 		
			IEC1bits.T4IE = 1;
}
void __attribute__((interrupt(auto_psv))) _T4Interrupt( void )	//TODO: analizar si es necesario interrupt(auto_psv)
		{
	IFS1bits.T4IF = 0;
	timeStamp++;
}
