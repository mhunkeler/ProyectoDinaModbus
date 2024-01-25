#pragma config JTAGEN = OFF 		// JTAG Port Enable (JTAG port is disabled)
#pragma config GCP = OFF 			// General Code Segment Code Protect (Code protection is disabled)
#pragma config GWRP = OFF 			// General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config LPCFG = OFF          // Disabled - regardless of RETEN
#pragma config ICS = PGx1 			// Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = WDT_DIS 	// Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config WINDIS = OFF 		// Watchdog Timer Window (Windowed Watchdog Timer enabled; FWDTEN must be 1)
#pragma config FWPSA = PR128 		// WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WDTPS = PS32768 		// Watchdog Timer Postscaler (1:32,768)
#pragma config IESO = OFF 			// Internal External Switch Over Mode (IESO mode (Two-Speed Start-up) disabled)
#pragma config WDTCMX = LPRC        // WDT Clock Multiplex Control bit ( Disabled clock multiplexing)
#pragma config ALTCVREF = CVREF_RB  // External CVREF+/CVREF- Location Select bit (PIC24FJ128GC006 should always be programmed to ‘0’)
#pragma config ALTADREF = AVREF_RB  // External AVREF+/AVREF- Location Select bit (PIC24FJ128GC006 should always be programmed to ‘0’)
#pragma config FNOSC = FRCPLL 		// Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))
#pragma config FCKSM = CSECMD 		// Clock Switching and Monitor (Clock switching Enabled and Fail-Safe Clock Monitor disabled)
#pragma config OSCIOFCN = ON 		// Use RC15 as I/O;
#pragma config WDTCLK = LPRC        // WDT Clock Source Select bits (WDT uses LPRC)
#pragma config POSCMD = NONE 		// Primary Oscillator Select (Primary oscillator disabled)
#pragma config WPEND = WPENDMEM     // Segment Write Protection End Page Select (Write Protect from WPFP to the last page of memory)
#pragma config WPCFG = WPCFGDIS     // Write Protect Configuration Page Select (Disabled)
#pragma config WPDIS = WPDIS        // Segment Write Protection Disable (Disabled)
#pragma config BOREN = OFF          // Brown-out Reset Enable (Brown-out Reset Disabled)
#pragma config WDTWIN = PS25_0      // Window Mode Watchdog Timer Window Width Select (Watch Dog Timer Window Width is 25 percent)
#pragma config SOSCSEL = OFF        // SOSC Selection bits (Digital (SCLKI) mode)
#pragma config WPFP = WPFP127       // Write Protection Flash Page Segment Boundary->Page 127 (0x1FC00)
#pragma config IOL1WAY = OFF 		// IOLOCK Protection (Once IOLOCK is set, cannot be changed)
#pragma config PLLDIV = DIV2        // USB 96 MHz PLL Prescaler Select bits (Oscillator input divided by 2 (8 MHz input))
#pragma config RTCBAT = OFF          // RTC Battery Operation Enable->RTC operation is continued through VBAT
#pragma config DSSWEN = ON         // DSEN Bit Enable (Deep Sleep is controlled by the register bit DSEN)
#pragma config DSWDTEN = ON        // Deep Sleep Watchdog Timer Enable (DSWDT Enabled)
#pragma config DSBOREN = ON        // Deep Sleep BOR Enable bit (DSBOR Enabled)
#pragma config DSWDTOSC = LPRC      // DSWDT Reference Clock Select (DSWDT uses LPRC as reference clock)
#pragma config DSWDTPS = DSWDTPS14    // Deep Sleep Watchdog Timer Postscale Select bits->1:33554432 (18 Minutes)
#define FOSC 32000000
#define FCY (FOSC/2)
#include <xc.h> //No RFI scan
#include <libpic30.h>
#define S_I2C2
#define TRIS_Led1 _TRISE2
#define PIN_Led1  _RE2
#define LAT_Led1  _LATE2
#define ODC_Led1 _ODE2
#define HAL_PinMap_Led1(cfg_type)
#define TRIS_Led2 _TRISE3
#define PIN_Led2  _RE3
#define LAT_Led2  _LATE3
#define ODC_Led2 _ODE3
#define HAL_PinMap_Led2(cfg_type)
#define TRIS_CS_RAM _TRISE7
#define PIN_CS_RAM  _RE7
#define LAT_CS_RAM  _LATE7
#define ODC_CS_RAM _ODE7
#define HAL_PinMap_CS_RAM(cfg_type)
#define TRIS_HOLD_RAM _TRISB4
#define PIN_HOLD_RAM  _RB4
#define LAT_HOLD_RAM  _LATB4
#define ODC_HOLD_RAM _ODB4
#define RPOUT_HOLD_RAM  _RP28R
#define RPIN_HOLD_RAM  28
#define HAL_PinMap_HOLD_RAM(cfg_type)
#define TRIS_SCK_RAM _TRISB3
#define PIN_SCK_RAM  _RB3
#define LAT_SCK_RAM  _LATB3
#define ODC_SCK_RAM _ODB3
#define HAL_PinMap_SCK_RAM(cfg_type)
#define TRIS_SIO0_RAM _TRISB2
#define PIN_SIO0_RAM  _RB2
#define LAT_SIO0_RAM  _LATB2
#define ODC_SIO0_RAM _ODB2
#define RPOUT_SIO0_RAM  _RP13R
#define RPIN_SIO0_RAM  13
#define HAL_PinMap_SIO0_RAM(cfg_type)       //TODO: implementar analógico
#define TRIS_SIO1_RAM _TRISG7
#define PIN_SIO1_RAM  _RG7
#define LAT_SIO1_RAM  _LATG7
#define ODC_SIO1_RAM _ODG7
#define RPOUT_SIO1_RAM  _RP26R
#define RPIN_SIO1_RAM   26
#define HAL_PinMap_SIO1_RAM(cfg_type)
#define TRIS_SIO2_RAM _TRISG8
#define PIN_SIO2_RAM  _RG8
#define LAT_SIO2_RAM  _LATG8
#define ODC_SIO2_RAM _ODG8
#define RPOUT_SIO2_RAM  _RP19R
#define RPIN_SIO2_RAM   19
#define HAL_PinMap_SIO2_RAM(cfg_type)
#define TRIS_POW_RAM _TRISG9
#define PIN_POW_RAM  _RG9
#define LAT_POW_RAM  _LATG9
#define ODC_POW_RAM _ODG9
#define RPOUT_POW_RAM  _RP27R
#define RPIN_POW_RAM   27
#define HAL_PinMap_POW_RAM(cfg_type)
#define TRIS_DIV_REF_POW _TRISB12
#define PIN_DIV_REF_POW  _RB12
#define LAT_DIV_REF_POW  _LATB12
#define ODC_DIV_REF_POW _ODB12
#define PORT_DIV_REF_POW  PORTB
#define PORTn_DIV_REF_POW  12
#define TRIS_FORCE _TRISB13
#define PIN_FORCE  _RB13
#define LAT_FORCE  _LATB13
#define ODC_FORCE _ODB13
#define ADC_value_FORCE              ADRES13
#define HAL_SetAnalog_FORCE()        _TRISB13=1;_ANSB13=1
#define ADC_channel_FORCE            13
#define TRIS_OP_CELDA_POW _TRISB14
#define PIN_OP_CELDA_POW  _RB14
#define LAT_OP_CELDA_POW  _LATB14
#define ODC_OP_CELDA_POW _ODB14
#define RPOUT_OP_CELDA_POW  _RP14R
#define RPIN_OP_CELDA_POW  14
#define PORT_OP_CELDA_POW  PORTB
#define PORTn_OP_CELDA_POW  14
#define TRIS_CELDA_POWN _TRISB15
#define PIN_CELDA_POWN  _RB15
#define LAT_CELDA_POWN  _LATB15
#define ODC_CELDA_POWN _ODB15
#define RPOUT_CELDA_POWN  _RP29R
#define RPIN_CELDA_POWN  29
#define TRIS_CELDA_POWP _TRISG2
#define PIN_CELDA_POWP  _RG2
#define LAT_CELDA_POWP  _LATG2
#define ODC_CELDA_POWP _ODG2
#define HAL_PinMap_CELDA_POWP(cfg_type)
#define TRIS_SCLK_RF _TRISD1
#define PIN_SCLK_RF  _RD1
#define LAT_SCLK_RF  _LATD1
#define ODC_SCLK_RF _ODD1
#define RPOUT_SCLK_RF  _RP24R
#define RPIN_SCLK_RF   24
#define HAL_PinMap_SCLK_RF(cfg_type)
#define TRIS_SDI_RF _TRISD2
#define PIN_SDI_RF  _RD2
#define LAT_SDI_RF  _LATD2
#define ODC_SDI_RF _ODD2
#define RPOUT_SDI_RF  _RP23R
#define RPIN_SDI_RF   23
#define HAL_PinMap_SDI_RF(cfg_type)
#define TRIS_SDO_RF _TRISD3
#define PIN_SDO_RF  _RD3
#define LAT_SDO_RF  _LATD3
#define ODC_SDO_RF _ODD3
#define RPOUT_SDO_RF  _RP22R
#define RPIN_SDO_RF   22
#define HAL_PinMap_SDO_RF(cfg_type)
#define TRIS_IRQ_RF _TRISD4
#define PIN_IRQ_RF  _RD4
#define LAT_IRQ_RF  _LATD4
#define ODC_IRQ_RF _ODD4
#define RPOUT_IRQ_RF  _RP25R
#define RPIN_IRQ_RF   25
#define HAL_PinMap_IRQ_RF(cfg_type)
#define TRIS_SEL_RF _TRISD5
#define PIN_SEL_RF  _RD5
#define LAT_SEL_RF  _LATD5
#define ODC_SEL_RF _ODD5
#define RPOUT_SEL_RF  _RP20R
#define RPIN_SEL_RF   20
#define HAL_PinMap_SEL_RF(cfg_type)
#define TRIS_DIO6_RF _TRISD6
#define PIN_DIO6_RF  _RD6
#define LAT_DIO6_RF  _LATD6
#define ODC_DIO6_RF _ODD6
#define HAL_PinMap_DIO6_RF(cfg_type)
#define TRIS_DIO5_RF _TRISD7
#define PIN_DIO5_RF  _RD7
#define LAT_DIO5_RF  _LATD7
#define ODC_DIO5_RF _ODD7
#define HAL_PinMap_DIO5_RF(cfg_type)
#define TRIS_DIO1_RF _TRISE0
#define PIN_DIO1_RF  _RE0
#define LAT_DIO1_RF  _LATE0
#define ODC_DIO1_RF _ODE0
#define HAL_PinMap_DIO1_RF(cfg_type)
#define TRIS_RESET_RF _TRISE1
#define PIN_RESET_RF  _RE1
#define LAT_RESET_RF  _LATE1
#define ODC_RESET_RF _ODE1
#define HAL_PinMap_RESET_RF(cfg_type)
#define TRIS_WAKEUP_RF _TRISF0
#define PIN_WAKEUP_RF  _RF0
#define LAT_WAKEUP_RF  _LATF0
#define ODC_WAKEUP_RF _ODF0
#define HAL_PinMap_WAKEUP_RF(cfg_type)
#define TRIS_DIO2_RF _TRISF1
#define PIN_DIO2_RF  _RF1
#define LAT_DIO2_RF  _LATF1
#define ODC_DIO2_RF _ODF1
#define HAL_PinMap_DIO2_RF(cfg_type)
#define TRIS_AD_BAT _TRISF3
#define PIN_AD_BAT  _RF3
#define LAT_AD_BAT  _LATF3
#define ODC_AD_BAT _ODF3
#define RPOUT_AD_BAT  _RP16R
#define RPIN_AD_BAT   16
#define HAL_PinMap_AD_BAT(cfg_type)
#define TRIS_adDivPow _TRISG3
#define PIN_adDivPow  _RG3
#define LAT_adDivPow  _LATG3
#define ODC_adDivPow _ODG3
#define HAL_PinMap_adDivPow(cfg_type)
#define PIN_DC_EN  _RC13
#define LAT_DC_EN  _LATC13
#define ODC_DC_EN _ODC13
#define HAL_PinMap_DC_EN(cfg_type)
#define TRIS_ACC_POW _TRISC15
#define PIN_ACC_POW  _RC15
#define LAT_ACC_POW  _LATC15
#define ODC_ACC_POW _ODC15
#define HAL_PinMap_ACC_POW(cfg_type)
#define TRIS_ACC_CSB _TRISC12
#define PIN_ACC_CSB  _RC12
#define LAT_ACC_CSB  _LATC12
#define ODC_ACC_CSB _ODC12
#define HAL_PinMap_ACC_CSB(cfg_type)
#define TRIS_ACC_INT2 _TRISD11
#define PIN_ACC_INT2  _RD11
#define LAT_ACC_INT2  _LATD11
#define ODC_ACC_INT2 _ODD11
#define RPOUT_ACC_INT2  _RP12R
#define RPIN_ACC_INT2   12
#define HAL_PinMap_ACC_INT2(cfg_type)
#define TRIS_ACC_CLK _TRISD10
#define PIN_ACC_CLK  _RD10
#define LAT_ACC_CLK  _LATD10
#define ODC_ACC_CLK _ODD10
#define RPOUT_ACC_CLK  _RP3R
#define RPIN_ACC_CLK   3
#define HAL_PinMap_ACC_CLK(cfg_type)
#define TRIS_ACC_MOSI _TRISD9
#define PIN_ACC_MOSI  _RD9
#define LAT_ACC_MOSI  _LATD9
#define ODC_ACC_MOSI _ODD9
#define RPOUT_ACC_MOSI  _RP4R
#define RPIN_ACC_MOSI   4
#define HAL_PinMap_ACC_MOSI(cfg_type)
#define TRIS_ACC_MISO _TRISD8
#define PIN_ACC_MISO  _RD8
#define LAT_ACC_MISO  _LATD8
#define ODC_ACC_MISO _ODD8
#define RPOUT_ACC_MISO  _RP2R
#define RPIN_ACC_MISO   2
#define HAL_PinMap_ACC_MISO(cfg_type)
#define TRIS_ACC_INT1 _TRISD0
#define PIN_ACC_INT1  _RD0
#define LAT_ACC_INT1  _LATD0
#define ODC_ACC_INT1 _ODD0
#define RPOUT_ACC_INT1  _RP11R
#define RPIN_ACC_INT1   11
#define HAL_PinMap_ACC_INT1(cfg_type)
#define TRIS_RS232A_TX _TRISF4
#define PIN_RS232A_TX  _RF4
#define LAT_RS232A_TX  _LATF4
#define ODC_RS232A_TX _ODF4
#define RPOUT_RS232A_TX  _RP10R
#define RPIN_RS232A_TX   10
#define HAL_PinMap_RS232A_TX(cfg_type)
#define TRIS_RS232A_RX _TRISF5
#define PIN_RS232A_RX  _RF5
#define LAT_RS232A_RX  _LATF5
#define ODC_RS232A_RX _ODF5
#define RPOUT_RS232A_RX  _RP17R
#define RPIN_RS232A_RX   17
#define HAL_PinMap_RS232A_RX(cfg_type)
#define nombrePCB "DinaAIB_FA_V2"
