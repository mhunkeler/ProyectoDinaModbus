#define _ACELERACIONAPOSICION_
#define INPUT_REGS_SIZE 160
float posicion[64];
float aceleracion[64];
float velocidad[64];
int16_t presist_ carrera;
int16_t presist_ offsetAcc;
int16_t presist_ spanAcc;
int16_t presist_ offsetFuerza;
int16_t presist_ spanFuerzaN;
int16_t presist_ spanFuerzaD;
int16_t presist_ metodoAcc;
int16_t presist_ ajusteAcc;
extern int16_t input_regs[INPUT_REGS_SIZE];
void cargarenMODBUS(float _posicion[], int16_t _fuerza[], union sourfaceCardInfo_U _info);
void procesarPosicion(int16_t aceleracion_u16[], int tam_array, float time, float _posicion[]);
void procesar();
