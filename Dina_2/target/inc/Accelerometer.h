int16_t* Data_X = &accX; /**< X axis acceleration. */
int16_t* Data_Y = &accY; /**< Y axis acceleration. */
int16_t* Data_Z = &accZ; /**< Z axis acceleration. */
float* Temperature = &temperature; /**< Temperature measured by accelerometer. */
int16_t accX;
int16_t accY;
int16_t accZ;
void Accelerometer_Init(void);
void AccPower(int8_t on_off);
uint8_t AccPowerOn = 1;
void Accelerometer_PowerMode(uint8_t mode);                 //Configure the power mode.
void Accelerometer_FreqDataSample(uint8_t freqDataSample);  //Configure the sample frequency.
void Accelerometer_Sensitivity(uint8_t sensitivity);        //Configure the sensitivity.
void Accelerometer_Poll(void);
