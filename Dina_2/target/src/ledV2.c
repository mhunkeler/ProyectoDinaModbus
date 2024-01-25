void init_led (void)
{
	HAL_GPIO_PinCfg(Led1, GPIO_OUTPUT);
		HAL_GPIO_PinCfg(Led2, GPIO_OUTPUT);
}
uint16_t blkLed2_timerOn = 0; 
uint16_t blkLed2_period = 0; 
uint16_t blkLed2_times = 0; 
uint32_t blkLed2_tStamp;
void blkLed2(uint16_t timeOn, uint16_t period, uint16_t times)
{
	HAL_GPIO_PinSet(Led2, GPIO_HIGH);
	blkLed2_timerOn = timeOn;
	blkLed2_period = period;
	blkLed2_times = times;
	blkLed2_tStamp = timeStamp;
}
void Poll_LEDs()
{
	if (blkLed2_period > 0)
	{
		if (blkLed2_tStamp + blkLed2_period < timeStamp)
		{
			if (blkLed2_times > 0)
			{
				blkLed2_times--;
				if (blkLed2_times == 0)
				{
					blkLed2_period = 0;
				}
			}
			if (blkLed2_period > 0)
			{
				HAL_GPIO_PinSet(Led2, GPIO_HIGH);
				blkLed2_tStamp = timeStamp;
			}
		}
		else if (blkLed2_tStamp + blkLed2_timerOn < timeStamp)
		{
			HAL_GPIO_PinSet(Led2, GPIO_LOW);
		}
	}
}
