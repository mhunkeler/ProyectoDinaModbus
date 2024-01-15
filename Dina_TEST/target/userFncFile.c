void eAccReady(int16_t AccX,int16_t AccY,int16_t AccZ)
{
	blkLed2(20, 21, 1);
	switch(detectarCiclo((uint16_t)AccX, getForce()))
	{
	case 1:
		AccPower(0);
		resample();
		pFSKD();
		blkLed1(100, 200, 1);
		setTime1(5000, 'T');
		break;
	case 2:
		AccPower(0);
		resample();
		pFSKD();
		blkLed1(100, 200, 1);
		setTime1(5000, 'T');
		break;
	}

}

void onReset()
{
	blkLed2(20, 100, 1);
	AccPower(1);
}

void errorFSK()
{
	blkLed2(200, 500, 5);
	setTime1(5000, 'T');
}

void etOut1()
{
	initDetector();
	AccPower(1);
}

