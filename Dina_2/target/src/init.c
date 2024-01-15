void initSystem(void)
{
	if(_DPSLP)
    {
        _RELEASE = 0; // libera los pines de su estado anterior
        _RELEASE = 0; // debe hacerce dos veces
        _DPSLP = 0;
    }
	CLKDIV=0x3000;
	ANSA = 0x0000;
	ANSB = 0x0000;
	ANSC = 0x0000;
	ANSD = 0x0000;
	ANSE = 0x0000;
	ANSF = 0x0000;
}
