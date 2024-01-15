#define event_eFSKD_active
#define use_blkLed4_function
#define use_pullLeds_function
#define use_loadCal_function
#define use_procesar_function
#define event_onReset_active
#define use_blkLed4_function
#define use_pullLeds_function
#include "inc\DynaBase_PCB_V2.0.h"
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
#include "inc/sourfaceCard.h"
#include "_api\Dyna\inc\AceleracionAPosicion.h"
#define SPI_EMIC
#include "Master\inc\spi.h"
#include "inc\Radio_intermedio.h"
#include "inc\RadioFSK.h"
#include "inc\Radio_FSK.h"
#define _UART_1_EMIC
#define __streamIn_emic__
#include "inc/streamIn.h"
#define __streamOut_emic__
#include "inc/streamOut.h"
#include "inc/Uart1.h"
#include "inc/modbusDriver.h"
#include "inc\modbusApi.h"
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
	Intermedio_FSK_Init();
	FSK_Init();
	init_ModBus();
	onReset();
	do
	{
	Poll_LEDs();
	TicPoll();
	Intermedio_FSK_Poll();
	FSK_Poll();
	poll_modbusDriver();
	poll_DinaModbus();
	}
	while(1);
}
