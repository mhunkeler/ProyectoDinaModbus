void Accelerometer_Init()
{
    AccPowerOn = 0;
    BMA400_Init();
}
void AccPower(int8_t on_off)
{
    AccPowerOn = on_off;
}
void Accelerometer_PowerMode(uint8_t mode)
{
    switch (mode)
    {
        case 0:
            BMA400_sleep();             //Sets the accelerometer in sleep mode.
            break;
        case 1:
        default:
            BMA400_wakeup();            //Sets the accelerometer en normal mode.
    }
}
void Accelerometer_FreqDataSample(uint8_t freqDataSample)
{
    BMA400_setFreqDataSample(freqDataSample);
}
void Accelerometer_Sensitivity(uint8_t sensitivity)
{
    BMA400_setSensitivity(sensitivity);
}
void Accelerometer_Poll(void)
{
    if (BMA400_Poll())
    {
        if (AccPowerOn == 1)
        {
            uint16_t miAccX = aceleraciones_m[indexCardA++];
            eAccReady(miAccX,accY,accZ);
        }
    }
}
