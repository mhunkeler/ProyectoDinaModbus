void init_led (void)
{
	HAL_GPIO_PinCfg(Led1, GPIO_OUTPUT);
		HAL_GPIO_PinCfg(Led2, GPIO_OUTPUT);
		HAL_GPIO_PinCfg(Led3, GPIO_OUTPUT);
		HAL_GPIO_PinCfg(Led4, GPIO_OUTPUT);
	HAL_GPIO_PinCfg(Led5, GPIO_OUTPUT);
	HAL_GPIO_PinCfg(Led6, GPIO_OUTPUT);
}
uint16_t blkLed4_timerOn = 0; 
uint16_t blkLed4_period = 0; 
uint16_t blkLed4_times = 0; 
uint32_t blkLed4_tStamp;
void blkLed4(uint16_t timeOn, uint16_t period, uint16_t times)
{
	HAL_GPIO_PinSet(Led4, GPIO_HIGH);
	blkLed4_timerOn = timeOn;
	blkLed4_period = period;
	blkLed4_times = times;
	blkLed4_tStamp = timeStamp;
}
void Poll_LEDs()
{
	if (blkLed4_period > 0)
	{
		if (blkLed4_tStamp + blkLed4_period < timeStamp)
		{
			if (blkLed4_times > 0)
			{
				blkLed4_times--;
				if (blkLed4_times == 0)
				{
					blkLed4_period = 0;
				}
			}
			if (blkLed4_period > 0)
			{
				HAL_GPIO_PinSet(Led4, GPIO_HIGH);
				blkLed4_tStamp = timeStamp;
			}
		}
		else if (blkLed4_tStamp + blkLed4_timerOn < timeStamp)
		{
			HAL_GPIO_PinSet(Led4, GPIO_LOW);
		}
	}
}
