void RS232_Init()
{
	Init_RS232Driver();
}
void pRS232(char* format,...)
{
	va_list arg;
    va_start(arg, format);
	sendDataToStream(&streamOut_Uart1,format,arg);
	va_end(arg);
	UARTX1_OUT_push(RS232FrameLf); 
}
void Poll_RS232(void)
{
}
