#define _DETECTORCICLO_
#include <stdbool.h>
#define MAX_SIZE 512
int16_t bufferIndex_g;
int16_t bufferAcel_g[MAX_SIZE];
uint16_t bufferFuer_g[MAX_SIZE];
uint8_t detectarCiclo(int16_t acel, uint16_t fuerza);
