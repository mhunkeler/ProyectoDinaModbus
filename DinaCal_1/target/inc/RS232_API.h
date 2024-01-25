#define _RS232_H_
#define RS232FrameLf '\n'
#include <stdarg.h>
void RS232_Init(void);
void pRS232(char* format,...);
void Poll_RS232(void);
