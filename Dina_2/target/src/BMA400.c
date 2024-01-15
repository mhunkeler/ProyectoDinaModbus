#include <stdio.h>
#include <time.h>
uint8_t BMA_Command(uint8_t command, uint8_t data)
{
    HAL_GPIO_PinSet(ACC_CSB, GPIO_LOW);
    __delay_us(1);
    xchangeSPI2b_8(command);
    __delay_us(2);
    uint8_t ret = xchangeSPI2b_8(data);
    __delay_us(1);
    HAL_GPIO_PinSet(ACC_CSB, GPIO_HIGH);
    __delay_us(2);
    return ret;
}
uint8_t BMA_Read(uint8_t command, uint8_t data)
{
    uint8_t ret;
    HAL_GPIO_PinSet(ACC_CSB, GPIO_LOW);
    __delay_us(1);
    xchangeSPI2b_8(command);
    __delay_us(2);
    xchangeSPI2b_8(data);
    ret = xchangeSPI2b_8(data);
    __delay_us(1);
    HAL_GPIO_PinSet(ACC_CSB, GPIO_HIGH);
    __delay_us(2);
    return ret;
}
void BMA400_Init(void)
{
    uint16_t response = 0;
    uint8_t chip_id;
    HAL_GPIO_PinCfg(ACC_POW, GPIO_OUTPUT);
    HAL_GPIO_PinSet(ACC_POW, GPIO_HIGH);
    HAL_GPIO_PinCfg(ACC_CSB, GPIO_OUTPUT);
    HAL_GPIO_PinSet(ACC_CSB, GPIO_LOW);
    __delay_ms(100);
    HAL_GPIO_PinSet(ACC_CSB, GPIO_HIGH);
    SPI2_init(0, 0);
    SPI2_clr();
    do 
    {
        chip_id = BMA_Read(read(CHIP_ID_ADDR), 0x00);
    }while (chip_id != CHIP_ID_CODE);    //If the SPI communication doesn't work correctly
    __delay_ms(1);
    BMA_Command(write(ACC_CONFIG0), 0x21); //0x1921 low power mode ->frecuencia de sampleo fija en 25Hz Se configura el rendimiento del ruido y el consumo segun el osr_lp
    __delay_ms(1);
    BMA_Command(write(ACC_CONFIG1), 0x00); //0x1A00 No se configura nada ya que esta trabajando en low power mode
    __delay_ms(1);
    BMA_Command(write(INT_CONFIG0), 0x80); //0x1F80 habilita la interrupcion de dataready
    __delay_ms(1);
    BMA_Command(write(INT_CONFIG1), 0x00); //0X2000 No habilita ninguna otra interrupcion
    __delay_ms(1);
    BMA_Command(write(INT1_MAP), 0x80);    //0X2180 Setea que la INT1 este conectada a la interrupcion dataready
    __delay_ms(1);
    BMA_Command(write(INT12_IO_CTRL), 0x02);//0X2402 Se configura la INT1, para que este en HIGH al activarse la interrupcion
    __delay_ms(1);
    SPI2_clr();
    response = BMA_Read(read(ACC_CONFIG0), 0x00);
    response = BMA_Read(read(ACC_CONFIG1), 0x00);
}
void BMA400_sleep(void)
{
    BMA_Command(write(ACC_CONFIG0), sleep_mode << power_mode_conf);
}
void BMA400_wakeup(void)
{
    BMA_Command(write(ACC_CONFIG0), normal_mode << power_mode_conf);
}
void BMA400_setFreqDataSample(uint8_t freqDataSample)
{
    acc_odr_t new_conf;
    switch (freqDataSample)
    {
        default:
        case 0:
            new_conf = odr_12p5;
            break;
        case 1:
            new_conf = odr_25;
            break;
        case 2:
            new_conf = odr_50;
            break;
        case 3:
            new_conf = odr_100;
            break;
        case 4:
            new_conf = odr_200;
            break;
        case 5:
            new_conf = odr_400;
            break;
        case 6:
            new_conf = odr_800;
            break;
    }
    BMA_Command(write(ACC_CONFIG1), (new_conf << acc_odr));
}
void BMA400_setSensitivity(uint8_t sensitivity)
{
    acc_range_t new_conf;
    switch (sensitivity)
    {
        default:
        case 0:
            new_conf = range_2g;
            break;
        case 1:
            new_conf = range_4g;
            break;
        case 2:
            new_conf = range_8g;
            break;
        case 3:
            new_conf = range_16g;
            break;
    }
    BMA_Command(write(ACC_CONFIG1), (new_conf << acc_range));
}
void read_acc_data(void)
{
    static uint8_t read_package[] = {read(DATA), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t data[6];
    HAL_GPIO_PinSet(ACC_CSB, GPIO_LOW); 
    __delay_us(1);
    xchangeSPI2b_8(read(DATA));
    __delay_us(2);
    xchangeSPI2b_8(0x00);
    data[0] = xchangeSPI2b_8(0x00);
    data[1] = xchangeSPI2b_8(0x00);
    data[2] = xchangeSPI2b_8(0x00);
    data[3] = xchangeSPI2b_8(0x00);
    data[4] = xchangeSPI2b_8(0x00);
    data[5] = xchangeSPI2b_8(0x00);
    SPI_data_proccess(data);
    __delay_us(1);
    HAL_GPIO_PinSet(ACC_CSB, GPIO_HIGH);
}
void read_temperature(void)
{
    int8_t raw_temperature = BMA_Read(read(TEMPERATURE), 0x00);;
    temperature = (float)raw_temperature * 0.5 + 23;
}
void SPI_data_proccess(uint8_t * data)
{
    accX = data16(data[1], data[0]);
    accY = data16(data[3], data[2]);
    accZ = data16(data[5], data[4]);
    if (accX > 2047)
    {
        accX -= 4096;
    }
    if (accY > 2047)
    {
        accY -= 4096;
    }
    if (accX > 2047)
    {
        accX -= 4096;
    }
}
uint8_t BMA400_Poll(void)
{
    uint8_t response = BMA_Read(read(STATUS), 0x00);
    if(response & 0x80)                            //Si la interrupcion de dataready esta activa
    {
        read_acc_data();
        return 1;
    }
    return 0;
}
