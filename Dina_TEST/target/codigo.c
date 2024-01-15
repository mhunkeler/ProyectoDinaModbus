#define event_eAccReady_active
#define use_blkLed2_function
#define use_pullLeds_function
#define usexSeleV1
#define use_detectarCiclo_function
#define use_getForce_function
#define use_AccPower_function
#define use_resample_function
#define use_pFSKD_function
#define use_blkLed1_function
#define use_pullLeds_function
#define use_setTime1_function
#define use_blkLed1_function
#define use_pullLeds_function
#define event_onReset_active
#define use_blkLed2_function
#define use_pullLeds_function
#define event_errorFSK_active
#define use_blkLed2_function
#define use_pullLeds_function
#define event_etOut1_active
#define use_initDetector_function
#define nombreModulo "Dina"
#include "inc\Dina_PCB_V2.h"
#define presist_ __attribute__((section(".presist")))
char presist_ persistInit;
#define presistArray_ __attribute__((section(".presistArray")))
char presistArray_ persistArrayInit[2];
#include "inc/gpio.h"
#define _PIC_pinMap_EMIC_
#include "inc/pinMap.h"
#define _TIMER_EMIC_
#include "inc\timer.h"
#include "inc\ledV2.h"
#define _TIMER_API_EMIC_
#include "inc\Timer_API_V1.h"
#define carta_EMIC
#include "inc/CartaTest.h"
#include "inc/sourfaceCard.h"
#include "inc/DetectorCiclo.h"
#include "inc/Resample.h"
#define BMA400_EMIC
#define SPI2_EMIC
#include "master\inc\spi2.h"
#include "inc\BMA400.h"
#include "inc\Accelerometer.h"
#define FORCE_API_EMIC
#define FORCE_EMIC
#define __PIC_ADC_EMIC__
#include "inc\adc.h"
#include "inc/Force.h"
#include "inc/adc_FORCE_api.h"
#define SPI_EMIC
#include "Master\inc\spi.h"
#include "inc\Radio_intermedio.h"
#include "inc\RadioFSK.h"
#include "inc\Radio_FSK.h"
#include "inc\INP_CHAN_NOTI.h"
#include "inc\Power_manager.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "inc\conversionFunctions.h"
#include "userFncFile.h"  //No RFI scan
#include "userVars.h"  //No RFI scan
#include "src.c"  //No RFI scan
#include "userFncFile.c"  //No RFI scan
#define _INIT_EMIC
#include "inc\init.h"
char presist_ persistEnd;
char presistArray_ persistArrayEnd[2];
int main(void)
{
	initSystem();
	init_timer4();
	init_led();
	init_timer_api ();
	Accelerometer_Init();
	init_ForceApi();
	Intermedio_FSK_Init();
	FSK_Init();
	onReset();
	do
	{
	Poll_LEDs();
	TicPoll();
	Accelerometer_Poll();
	Intermedio_FSK_Poll();
	FSK_Poll();
	}
	while(1);
}
