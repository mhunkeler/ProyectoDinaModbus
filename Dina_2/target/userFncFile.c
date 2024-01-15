void eAccReady(int16_t AccX,int16_t AccY,int16_t AccZ)
{
	blkLed2(20, 21, 1);
	switch(detectarCiclo((uint16_t)AccX, getForce()))
	{
	case 1:
		AccPower(0);
		ApiForce_OFF();
		resample();
		pFSKD();
		blkLed1(100, 200, 1);
		setTime1(1000, 'T');
		break;
	case 3:
		AccPower(0);
		ApiForce_OFF();
		resample();
		pFSKD();
		blkLed1(100, 200, 1);
		setTime1(1000, 'T');
		break;
	}

}

void onReset()
{
	blkLed2(20, 100, 10);
	setTime2(2000, 'T');
}

void errorFSK()
{
	blkLed2(200, 500, 5);
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

