#define FILTRO_LONGITUD 32
#define UMBRAL 980
int16_t inicio_g = 0;
int16_t fin_g = 0;
int16_t FIFOsize_g = 0;
bufferIndex_g = 0;
int32_t aceleracion_acum_g = 0;
uint32_t fuerza_acum_g = 0;
int16_t estado_g = 0;
int16_t anterior_g = 0;
typedef struct
{
    int16_t aceleracion;
    uint16_t fuerza;
} DataPoint;
DataPoint cola_g[64];
void push(int16_t acel, int16_t fuer)
{
    cola_g[fin_g].aceleracion = acel;
    cola_g[fin_g].fuerza = fuer;
    fin_g = (fin_g + 1) % FILTRO_LONGITUD;
    FIFOsize_g++;
}
DataPoint pop()
{
    DataPoint dp = cola_g[inicio_g];
    inicio_g = (inicio_g + 1) % FILTRO_LONGITUD;
    FIFOsize_g--;
    return dp;
}
void clearFIFO()
{
    inicio_g = 0;
    fin_g = 0;
    FIFOsize_g = 0;
}
void initDetector()
{
    inicio_g = 0;
    fin_g = 0;
    FIFOsize_g = 0;
    bufferIndex_g = 0;
    aceleracion_acum_g = 0;
    fuerza_acum_g = 0;
    estado_g = 0;
    anterior_g = 0;
}
uint8_t detectarCiclo(int16_t acel, uint16_t fuerza)
{
    push(acel - UMBRAL, fuerza);
    aceleracion_acum_g += (acel - UMBRAL);
    fuerza_acum_g += fuerza;
    if (FIFOsize_g >= FILTRO_LONGITUD)
    {
        switch (estado_g)
        {
            case 0:
                if (bufferIndex_g < (MAX_SIZE / 2 )) // Verificación para evitar desbordamiento de buffer
                {
                    bufferAcel_g[bufferIndex_g] = aceleracion_acum_g / 4;//  / FILTRO_LONGITUD;
                    bufferFuer_g[bufferIndex_g] = fuerza_acum_g / 32;// / FILTRO_LONGITUD;
                    bufferIndex_g++;
                    if (anterior_g < 0 && aceleracion_acum_g >= 0)
                    {
                        bufferIndex_g = 0;
                        bufferAcel_g[bufferIndex_g] = aceleracion_acum_g / 4;//  / FILTRO_LONGITUD;
                        bufferFuer_g[bufferIndex_g] = fuerza_acum_g / 32;// / FILTRO_LONGITUD;
                        bufferIndex_g++;
                        estado_g = 1;
                    }
                }
                else
                {
                    sourfaceCardInfo.GPM = 0;
                    sourfaceCardInfo.period  = bufferIndex_g * 40;
                    sourfaceCardInfo.status = 3;
                    return 3;
                }
                break;
            case 1:
                if (bufferIndex_g < MAX_SIZE) // Verificación para evitar desbordamiento de buffer
                {
                    bufferAcel_g[bufferIndex_g] = aceleracion_acum_g / 4;// / FILTRO_LONGITUD;
                    bufferFuer_g[bufferIndex_g] = fuerza_acum_g  / 32;// / FILTRO_LONGITUD;
                    bufferIndex_g++;
                    if (anterior_g < 0 && aceleracion_acum_g >= 0)
                    {
                        bufferIndex_g--;
                        sourfaceCardInfo.period  = bufferIndex_g * 40;
                        sourfaceCardInfo.GPM = (uint16_t)  (6000000.0 / (float) sourfaceCardInfo.period);
                        sourfaceCardInfo.status = 1;
                        return 1;
                    }
                }
                else
                {
                    sourfaceCardInfo.GPM = 0;
                    sourfaceCardInfo.period  = bufferIndex_g * 40;
                    sourfaceCardInfo.status = 3;
                    return 3;
                }
                break;
        }
        anterior_g = aceleracion_acum_g;
        DataPoint removido = pop();
        aceleracion_acum_g -= removido.aceleracion;
        fuerza_acum_g -= removido.fuerza;
    }
    return 0;
}
