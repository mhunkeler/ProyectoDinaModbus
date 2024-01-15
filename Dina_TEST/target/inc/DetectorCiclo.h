#define _DETECTORCICLO_
#include <stdbool.h>
#define MAX_SIZE 512
int16_t bufferIndex_g;
int16_t bufferAcel_g[MAX_SIZE];
int16_t bufferFuer_g[MAX_SIZE];
uint8_t detectarCiclo(int16_t acel, int16_t fuerza);
