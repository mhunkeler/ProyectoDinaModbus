#define FRAME_MESSAGE 0
#define FRAME_DATA  1
struct _FskChart {
    uint8_t *packet0;    // Puntero al primer conjunto de datos
    uint8_t *packet1;    // Puntero al primer conjunto de datos
    uint8_t *packet2;    // Puntero al segundo conjunto de datos
    uint8_t *packet3;    // Puntero al tercer conjunto de datos
    uint8_t *packet4;    // Puntero al cuarto conjunto de datos
    uint8_t *packet5;    // Puntero al n conjunto de datos
    uint8_t *packet6;    // Puntero al n conjunto de datos
    uint8_t *packet7;    // Puntero al n conjunto de datos
    uint8_t *packet8;    // Puntero al n conjunto de datos
    uint8_t *packet9;    // extra packet 
}FskChart;
#define PacketsCounts 9
enum FskApiStates
{
	SENDING_CHART,
	SENDING_MESSAGE,
	WAITING,
};
uint8_t Sended_Data = 0;
uint8_t fskSendFlag = 0;
uint8_t FskApi_state = WAITING;
uint8_t fskMessage[46] = "";
uint8_t fskMessageLength = 0;
void FSK_Init(void);
void FSK_Poll(void);
void pFSKD();
void pFSKM(char* message);
void RadioSleep(void);
void RadioWakeUp(void);
