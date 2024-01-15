#define miPuerto 1
void UARTX1_simplexMode(void)
{
	U1MODEbits.RTSMD=1;
	U1MODEbits.UEN1=1;
	U1MODEbits.UEN0=0;
}
void UARTX1_flowControl(uint8_t enabled)
{
	if(enabled==1)
	{
		UARTX1_flowControlVar=1;
		U1MODEbits.RTSMD=0;
		U1MODEbits.UEN1=1;
		U1MODEbits.UEN0=0;
	}
	else
	{
		UARTX1_flowControlVar=0;
		U1MODEbits.RTSMD=0;
		U1MODEbits.UEN1=0;
		U1MODEbits.UEN0=0;
	}
}
void UARTX1_invertir(uint8_t invertido)
{
	if(invertido)
	{
		U1STAbits.UTXINV=1;
		U1MODEbits.RXINV=1;
		UARTX1_invertido=1;
	}
	else
	{
		U1STAbits.UTXINV=0;
		U1MODEbits.RXINV=0;
		UARTX1_invertido=0;
	}
}
void UARTX1_IN_ini(void)
{
	UARTX1_IN_punt_entr	= 0;
	UARTX1_IN_punt_sal	= 0;
	UARTX1_IN_cont_byte	= 0;
	UARTX1_IN_n_frame	= 0;
}
void UARTX1_OUT_ini(void)
{
	UARTX1_OUT_punt_entr	= 0;
	UARTX1_OUT_punt_sal	= 0;
	UARTX1_OUT_cont_byte	= 0;
}
void UARTX1_IN_push(char dato)
{
	UARTX1_IN_fifo[UARTX1_IN_punt_entr] = dato;
	UARTX1_IN_punt_entr ++;
	UARTX1_IN_cont_byte ++;
	if (dato == UARTX1_frame_indentifier)
		UARTX1_IN_n_frame++;
	if (UARTX1_IN_punt_entr == UARTX1_IN_MAX)
		UARTX1_IN_punt_entr = 0;
}
void UARTX1_OUT_push(char dato)
{
	if ( UARTX1_OUT_cont_byte < UARTX1_OUT_MAX )
	{
		IEC0bits.U1TXIE = 0;
		UARTX1_OUT_fifo[UARTX1_OUT_punt_entr] = dato;
		UARTX1_OUT_punt_entr ++;
		UARTX1_OUT_cont_byte ++;
		if (UARTX1_OUT_punt_entr == UARTX1_OUT_MAX)
			UARTX1_OUT_punt_entr = 0;
			if(!U1STAbits.UTXBF)
			{
				U1TXREG = UARTX1_OUT_pop();
			}
		if(!UARTX1_OUT_cont_byte)
		UARTX1_bufferEmpty=1;
		IEC0bits.U1TXIE = 1;
	}
}
char UARTX1_IN_pop()
{
	IEC0bits.U1RXIE = 0;
	char dato;
	dato = UARTX1_IN_fifo[UARTX1_IN_punt_sal];
	UARTX1_IN_punt_sal ++;
	UARTX1_IN_cont_byte --;
	if (dato == UARTX1_frame_indentifier)
	{
		UARTX1_IN_n_frame--;
	}
	if (UARTX1_IN_punt_sal == UARTX1_IN_MAX)
	{
		UARTX1_IN_punt_sal = 0;
	}
	IEC0bits.U1RXIE = 1;
	return dato;
}
char UARTX1_OUT_pop(void)
{
	char dato;
	dato = UARTX1_OUT_fifo[UARTX1_OUT_punt_sal];
	if ( UARTX1_OUT_cont_byte )
	{
		UARTX1_OUT_punt_sal ++;
		UARTX1_OUT_cont_byte --;
	}
	if (UARTX1_OUT_punt_sal == UARTX1_OUT_MAX) UARTX1_OUT_punt_sal = 0;
	return dato;
}
uint16_t UARTX1_IN_count(void)
{
	return UARTX1_IN_cont_byte;
}
void UARTX1_init(void)
{
	__builtin_write_OSCCONL(OSCCON & 0xBF);
	RPOUT_U1_TX =_RPOUT_U1TX;	// RPIN_TX1 -> UART1:U1TX
	_U1RXR = RPIN_U1_RX;  		//	RPINR18bits.U1RXR = RPIN_U1RX		// RB15->UART1:U1RX
	__builtin_write_OSCCONL(OSCCON | 0x40);
	U1MODEbits.BRGH = 0;
    UARTX1_bd((uint32_t)UARTX1_baud);
 	U1MODE = 0;                     //8-bit data, no parity, 1 stop bit
    U1MODEbits.UARTEN = 1;          //enable the module
	U1STAbits.UTXISEL0=0;
	U1STAbits.UTXISEL1=0;
 	U1STAbits.UTXEN = 1; 
 	IEC0bits.U1RXIE = 1;
    IEC0bits.U1TXIE = 1;
	UARTX1_IN_ini();
	UARTX1_OUT_ini();
	UARTX1_cont_byte_BUFFER_HRD=0;
	UARTX1_bufferEmpty=0;
}
void UARTX1_Init(uint32_t uartSpeed)
{
	UARTX1_init();
	switch(uartSpeed)
	{
		case 600:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 1200:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 2400:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 4800:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 9600:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 14400:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 19200:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 28800:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 38400:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 56000:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 57600:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
	}
	UARTX1_invertir(UARTX1_invertido);
}
void UARTX1_bd(uint32_t uartSpeed)
{
	switch(uartSpeed)
	{
		case 600:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 1200:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 2400:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 4800:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 9600:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 14400:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 19200:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 28800:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 38400:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 56000:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
		case 57600:
			U1BRG = ((FCY/(16*uartSpeed))-1);
			break;
	}
}
void UARTX1_TXREG(uint16_t d)
{
	U1TXREG = d;
}
uint8_t UARTX1_TRMT(void)
{
	return U1STAbits.TRMT; 
}
void __attribute__((interrupt(auto_psv))) _U1TXInterrupt( void )
{
	IFS0bits.U1TXIF = 0;
	while(UARTX1_OUT_cont_byte)
	{
		if(!U1STAbits.UTXBF)//si hay espacio en el buffer de hard
			U1TXREG = UARTX1_OUT_pop();
		else
			return;
	}
}
void __attribute__((interrupt(auto_psv))) _U1RXInterrupt( void )
{
	unsigned char d;
		IFS0bits.U1RXIF = 0;
	while (U1STAbits.URXDA)
	{
		d = U1RXREG ;  //getc();
		UARTX1_IN_push(d);
	}	
	return;
}
#undef miPuerto
