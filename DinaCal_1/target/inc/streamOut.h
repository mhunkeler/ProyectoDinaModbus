#include <stdarg.h>
#include <stdio.h>
typedef struct streamOut_S
{
    void (*put)(char);
    uint16_t (*getAvailable)(void);
} streamOut_t;
void sendDataToStream(const streamOut_t*, char*,va_list);
