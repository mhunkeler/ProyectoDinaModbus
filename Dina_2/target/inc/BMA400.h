#define _BMA400_H_
#define TEMP_INCLUDE
#define BMA_TECH
#define CHIP_ID_CODE      0x90
#define CHIP_ID_ADDR      0x00
#define STATUS            0x03
#define ACC_CONFIG0       0x19
#define ACC_CONFIG1       0x1A
#define ACC_CONFIG2       0x1B
#define INT_CONFIG0       0x1F
#define INT_CONFIG1       0x20
#define CMD               0x7E
#define FIFO_CONFIG_0     0x26
#define FIFO_CONFIG_1     0x27
#define FIFO_CONFIG_2     0x28
#define FIFO_PWR_CONFIG   0x29
#define INT1_MAP          0x21
#define INT2_MAP          0x22
#define INT12_MAP         0x23
#define INT12_IO_CTRL     0x24
#define IF_CONF           0x7C
#define TEMPERATURE       0x11
#define DATA              0x04
#define ACC_X             0x04
#define ACC_X_low         0x04
#define ACC_X_high        0x05
#define ACC_y             0x06
#define ACC_Y_low         0x06
#define ACC_Y_high        0x07
#define ACC_Z             0x08
#define ACC_Z_low         0x08
#define ACC_Z_high        0x09
#define GRAVITY           9.80665f
#define drdy_stat         0x70
#define power_mode_conf   0x00
#define osr_lp            0x05
#define filt1_bw          0x07
#define acc_odr           0x00
#define osr               0x04
#define acc_range         0x06
#define data_src_reg      0x02
#define high(value) ( value << 8 )
#define data16(high_data, low_data) ((high_data << 8) | (0x00FF & low_data))
#define read(data) (data | 0b10000000)  //The write or read operation depends only of the first bit of the communication,
#define write(data) (data & 0b01111111) //it's the reason why this macros modify only the high value
typedef enum acc_odr_t 
{
  odr_12p5 = 0x05,
  odr_25,
  odr_50,
  odr_100,
  odr_200,
  odr_400,
  odr_800
} acc_odr_t;
typedef enum acc_perf_mode_t
{
  cic_avg,  //Averaging mode
  cont      //Continuous filter function
} acc_perf_mode_t;
typedef enum acc_range_t
{
  range_2g, //+/-2g
  range_4g, //+/-4g
  range_8g, //+/-8g
  range_16g //+/-16g
} acc_range_t;
typedef enum power_mode_conf_t
{
  sleep_mode,     //Sleep mode
  low_power_mode, //Low power mode
  normal_mode,    //Normal mode
} power_mode_conf_t;
typedef enum filt1_bw_t
{
  high, //0.4x ODR
  low   //0.2x ODR
} filt1_bw_t;
typedef enum osr_t
{
  osr_0 = 0x00,
  osr_1,
  osr_2,
  osr_3
} osr_t;
typedef enum data_src_reg_t
{
  acc_filt1 = 0x00,
  acc_filt2,
  acc_filt_lp
} data_src_reg_t;
extern int16_t accX;
extern int16_t accY;
extern int16_t accZ;
float temperature;
uint8_t data_ready_flag = 0;
void BMA400_Init(void);
void BMA400_sleep(void);
void BMA400_wakeup(void);
void BMA400_setFreqDataSample(uint8_t freqDataSample);
void BMA400_setSensitivity(uint8_t sensitivity);
void read_acc_data(void);
void read_temperature(void);
uint8_t BMA400_Poll(void);
