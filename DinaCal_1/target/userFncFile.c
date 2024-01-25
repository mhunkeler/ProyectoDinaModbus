void onReset()
{
	setTime1(1000, 'A');
	strcpy(acel,"----");
	AccPower(1);
}

void etOut1()
{
	uint16_t_to_ascii(getForce(),fuerza,sizeof(fuerza));
	pRS232("C:\tF:$s\tA:$s",fuerza,acel);
	blkLed1(120, 250, 1);
}

void eAccReady(int16_t AccX,int16_t AccY,int16_t AccZ)
{
	int16_t_to_ascii(AccX,acel,sizeof(acel));
}

