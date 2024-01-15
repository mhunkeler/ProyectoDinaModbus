void SPI2_init (uint8_t mode16, uint8_t spi_mode)
{
	__builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
	RPOUT_ACC_MISO	= _RPOUT_SDO2;
	RPOUT_ACC_CLK	= _RPOUT_SCK2OUT;
	_SDI2R = RPIN_ACC_MOSI;
	__builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS
	SPI2STATbits.SPIEN   = 0;             //Disable SPI port
	SPI2STATbits.SPISIDL = 0;             //Continue module operation in Idle mode
    SPI2BUF              = 0;             //Clear SPI buffer data Master
    _SPI2IF              = 0;             //Clear flag interrupt
    _SPI2IE              = 0;             //Disable Interrupt
    _SPI2IP              = 1;             //Set the interrupt priority to low
    SPI2CON1bits.DISSCK  = 0;             //Internal SPI Clock is Enabled
    SPI2CON1bits.DISSDO  = 0;             //SDOx pin is controlled by the module (Enable SDO)
    SPI2CON1bits.MODE16  = mode16;        //Communication is word-wide (8 bits or 16 bits)
    switch (spi_mode)
    {
    case 0:
    	SPI2CON1bits.SMP     = 0;             //Input Data is sampled at the middle of data output time
    	SPI2CON1bits.CKP     = 0;             //Serial output data changes on falling transition
    	SPI2CON1bits.CKE     = 1;             //Idle state for the clock is a high level; active state is a low level
    	break;
    case 1:
    	SPI2CON1bits.SMP     = 0;             //Input Data is sampled at the middle of data output time
    	SPI2CON1bits.CKP     = 1;             //Serial output data changes on falling transition
    	SPI2CON1bits.CKE     = 0;             //Idle state for the clock is a low level; active state is a high level
    	break;
    case 2:
    	SPI2CON1bits.SMP     = 1;             //Input Data is sampled at the end of data output time
    	SPI2CON1bits.CKP     = 0;             //Serial output data changes on falling transition
    	SPI2CON1bits.CKE     = 1;             //Idle state for the clock is a high level; active state is a low level
    	break;
    case 3:
    	SPI2CON1bits.SMP     = 1;             //Input Data is sampled at the end of data output time
    	SPI2CON1bits.CKP     = 1;             //Serial output data changes on falling transition
    	SPI2CON1bits.CKE     = 0;             //Idle state for the clock is a low level; active state is a high level
    	break;
    }
    SPI2CON1bits.SSEN    = 0;
    SPI2CON1bits.SPRE    = 6;         // secondary prescale as  SPRE=4 4:1 -- SPRE=7 1:1 --SPRE=6 2:1
    SPI2CON1bits.PPRE    = 3; 		  // Primary prescale as  PPRE=2 4:1 -- PPRE=3 1:1
    SPI2CON1bits.MSTEN   = 1;         //Master Mode Enabled
    SPI2CON2             = 0;         //non-framed mode
    SPI2STATbits.SPIEN   = 1;         //Enable SPI Module
}
void SPI2_enable(){
    SPI2STATbits.SPIEN   = 1;             //Enable SPI port
}
void SPI2_disable(){
    SPI2STATbits.SPIEN   = 0;             //Disable SPI port
}
#define spi2_put(data) SPI2BUF=data
#define spi2_get() SPI2BUF
uint8_t xchangeSPI2b_8(uint8_t data)
{
    SPI2BUF = data;					    // write to buffer for TX
    while(!SPI2STATbits.SPIRBF);        // wait for transfer to complete
    uint8_t ret = SPI2BUF;
    return ret;    				        // read the received value
}
void SPI2_clr()
{
    uint8_t damy;
    while(SPI2STATbits.SPIRBF)
    {
        damy = SPI2BUF;
    }
}
