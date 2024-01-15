#include <wdt.h>	//No RFI scan
enum enumEstadoPowerSaving
{
	estadoPsSleep,
	estadoPsIdle,
	estadoPsRun
};
uint8_t miEstadoPowerSave = estadoPsRun;
void deepSleep(void);
