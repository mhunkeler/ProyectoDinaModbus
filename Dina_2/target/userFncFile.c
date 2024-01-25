void eAccReady(int16_t AccX,int16_t AccY,int16_t AccZ)
{
	switch(detectarCiclo((uint16_t)AccX, getForce()))
	{
	case 1:
		AccPower(0);
		ApiForce_OFF();
		resample();
		pFSKD();
		setTime1(1000, 'T');
		break;
	case 3:
		AccPower(0);
		ApiForce_OFF();
		resample();
		pFSKD();
		setTime1(1000, 'T');
		break;
	}

}

void onReset()
{
	blkLed2(20, 180, 10);
	setTime2(2000, 'T');
}

void errorFSK()
{
}

void etOut1()
{
	RadioSleep();
}

void sleepFSK()
{
	deepSleep();
}

void etOut2()
{
	initDetector();
	AccPower(1);
}

