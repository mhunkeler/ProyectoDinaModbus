#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = OFF                // General Segment Code-Protect bit (General Segment Code protect is disabled)
#pragma config GSSK = OFF               // General Segment Key bits (General Segment Write Protection and Code Protection is Disabled)
#pragma config FNOSC = FRCPLL           // Initial Oscillator Source Selection bits (Internal Fast RC with PLL (FRCPLL))
#pragma config IESO = ON                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary Oscillator disabled)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = OFF             // Peripheral pin select configuration (Allow only one reconfiguration)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)
#pragma config WDTPOST = PS16           // Watchdog Timer Postscaler bits (1:16)
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler bit (1:128)
#pragma config PLLKEN = ON              // PLL Lock Wait Enable bit (Clock switch to PLL source will wait until the PLL lock signal is valid.)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF              // Watchdog Timer Enable bit (Watchdog timer always enabled) (pasar a ON para grabar)
#pragma config FPWRT = PWR128           // Power-on Reset Timer Value Select bits (128ms)
#pragma config BOREN = ON               // Brown-out Reset (BOR) Detection Enable bit (BOR is enabled)
#pragma config ALTI2C1 = OFF            // Alternate I2C pins for I2C1 (SDA1/SCK1 pins are selected as the I/O pins for I2C1)
#pragma config ICS = PGD3               // ICD Communication Channel Select bits (Communicate on PGEC3 and PGED3)
#pragma config RSTPRI = PF              // Reset Target Vector Select bit (Device will obtain reset instruction from Primary flash)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)
#pragma config AWRP = OFF               // Auxiliary Segment Write-protect bit (Aux Flash may be written)
#pragma config APL = OFF                // Auxiliary Segment Code-protect bit (Aux Flash Code protect is disabled)
#pragma config APLK = OFF   
#define FOSC 46062500  //TODO: se cambio a mano por error de baud en la compu
#define FCY (FOSC/2)
#include <xc.h>
#include <libpic30.h>
#define S_I2C1
#define TRIS_MODBUS_RX _TRISE4
#define PIN_MODBUS_RX  _RE4
#define LAT_MODBUS_RX  _LATE4
#define RPOUT_MODBUS_RX              RPOR5bits.RP84R
#define RPIN_MODBUS_RX              84
#define HAL_PinMap_MODBUS_RX(cfg_type)
#define TRIS_MODBUS_TX _TRISE5
#define PIN_MODBUS_TX  _RE5
#define LAT_MODBUS_TX  _LATE5
#define RPOUT_MODBUS_TX              RPOR6bits.RP85R
#define RPIN_MODBUS_TX              85
#define HAL_PinMap_MODBUS_TX(cfg_type)
#define TRIS_Led1 _TRISD8
#define PIN_Led1  _RD8
#define LAT_Led1  _LATD8
#define ODC_Led1 _ODCD8
#define RPIN_Led1  72
#define HAL_PinMap_Led1(cfg_type)
#define TRIS_Led2 _TRISD9
#define PIN_Led2  _RD9
#define LAT_Led2  _LATD9
#define ODC_Led2 _ODCD9
#define RPIN_Led2  73
#define HAL_PinMap_Led2(cfg_type)
#define TRIS_Led3 _TRISD10
#define PIN_Led3  _RD10
#define LAT_Led3  _LATD10
#define ODC_Led3 _ODCD10
#define RPIN_Led3  74
#define HAL_PinMap_Led3(cfg_type)
#define TRIS_Led4 _TRISB3
#define PIN_Led4  _RB3
#define LAT_Led4  _LATB3
#define RPIN_Led4  35
#define HAL_PinMap_Led4(cfg_type)
#define TRIS_Led5 _TRISB2
#define PIN_Led5  _RB2
#define LAT_Led5  _LATB2
#define RPIN_Led5  34
#define HAL_PinMap_Led5(cfg_type)       //TODO: implementar analógico
#define TRIS_Led6 _TRISB6
#define PIN_Led6  _RB6
#define LAT_Led6  _LATB6
#define RPIN_Led6  38
#define HAL_PinMap_Led6(cfg_type)
#define TRIS_SCLKRF _TRISF5
#define PIN_SCLKRF  _RF5
#define LAT_SCLKRF  _LATF5
#define ODC_SCLKRF _ODCF5
#define RPOUT_SCLKRF              RPOR9bits.RP101R
#define RPIN_SCLKRF              101
#define HAL_PinMap_SCLKRF(cfg_type)
#define TRIS_SDI _TRISB8
#define PIN_SDI  _RB8
#define LAT_SDI  _LATB8
#define RPIN_SDI  40
#define TRIS_SDO _TRISF4
#define PIN_SDO  _RF4
#define LAT_SDO  _LATF4
#define ODC_SDO _ODCF4
#define RPOUT_SDO              RPOR9bits.RP100R
#define RPIN_SDO              100
#define HAL_PinMap_SDO(cfg_type)
#define TRIS_SEL _TRISB10
#define PIN_SEL  _RB10
#define LAT_SEL  _LATB10
#define RPIN_SEL  42
#define TRIS_RESET _TRISB11
#define PIN_RESET  _RB11
#define LAT_RESET  _LATB11
#define RPIN_RESET  43
#define TRIS_IRQ _TRISB12
#define PIN_IRQ  _RB12
#define LAT_IRQ  _LATB12
#define RPIN_IRQ  44
#define TRIS_WAKEUP _TRISB13
#define PIN_WAKEUP  _RB13
#define LAT_WAKEUP  _LATB13
#define RPIN_WAKEUP  45
#define TRIS_RAM_SIO0 _TRISD2
#define PIN_RAM_SIO0  _RD2
#define LAT_RAM_SIO0  _LATD2
#define ODC_RAM_SIO0 _ODCD2
#define RPOUT_RAM_SIO0              RPOR1bits.RP66R
#define RPIN_RAM_SIO0              66
#define HAL_PinMap_RAM_SIO0(cfg_type)
#define TRIS_RAM_SIO1 _TRISC14
#define PIN_RAM_SIO1  _RC14
#define LAT_RAM_SIO1  _LATC14
#define RPIN_RAM_SIO1              62
#define HAL_PinMap_RAM_SIO1(cfg_type)
#define TRIS_RAM_SCK _TRISD3
#define PIN_RAM_SCK  _RD3
#define LAT_RAM_SCK  _LATD3
#define ODC_RAM_SCK _ODCD3
#define RPOUT_RAM_SCK              RPOR1bits.RP67R
#define RPIN_RAM_SCK              67
#define HAL_PinMap_RAM_SCK(cfg_type)
#define TRIS_SRAM_CS _TRISD1
#define PIN_SRAM_CS  _RD1
#define LAT_SRAM_CS  _LATD1
#define ODC_SRAM_CS _ODCD1
#define RPOUT_SRAM_CS              RPOR0bits.RP65R
#define RPIN_SRAM_CS              65
#define HAL_PinMap_SRAM_CS(cfg_type)
#define TRIS_FLASH_CS _TRISF0
#define PIN_FLASH_CS  _RF0
#define LAT_FLASH_CS  _LATF0
#define ODC_FLASH_CS _ODCF0
#define RPOUT_FLASH_CS              RPOR7bits.RP96R
#define RPIN_FLASH_CS              96
#define HAL_PinMap_FLASH_CS(cfg_type)
#define TRIS_nHOLD _TRISD4
#define PIN_nHOLD  _RD4
#define LAT_nHOLD  _LATD4
#define ODC_nHOLD _ODCD4
#define RPOUT_nHOLD              RPOR2bits.RP68R
#define RPIN_nHOLD              68
#define HAL_PinMap_nHOLD(cfg_type)
#define TRIS_GPS_RX _TRISD5
#define PIN_GPS_RX  _RD5
#define LAT_GPS_RX  _LATD5
#define ODC_GPS_RX _ODCD5
#define RPOUT_GPS_RX              RPOR2bits.RP69R
#define RPIN_GPS_RX              69
#define HAL_PinMap_GPS_RX(cfg_type)
#define TRIS_GPS_TX _TRISD6
#define PIN_GPS_TX  _RD6
#define LAT_GPS_TX  _LATD6
#define RPOUT_GPS_TX              RPOR3bits.RP70R
#define RPIN_GPS_TX              70
#define HAL_PinMap_GPS_TX(cfg_type)
#define nombrePCB "HRD_BASE_G_E V1.3"
