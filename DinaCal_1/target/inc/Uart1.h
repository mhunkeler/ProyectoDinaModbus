#define UARTX1_baud     9600
#define UARTX1_IN_MAX     512
#define UARTX1_OUT_MAX    512
#define UARTX1_frame_indentifier  0x0A
#define UART1_frame_indentifier 0
uint8_t UARTX1_bufferEmpty;
uint16_t UARTX1_IN_punt_entr;
uint16_t UARTX1_IN_punt_sal;
uint16_t UARTX1_IN_cont_byte;
uint16_t UARTX1_IN_n_frame;
char UARTX1_IN_fifo[UARTX1_IN_MAX];
uint16_t UARTX1_OUT_punt_entr;
uint16_t UARTX1_OUT_punt_sal;
uint16_t UARTX1_OUT_cont_byte;
unsigned char UARTX1_cont_byte_BUFFER_HRD;
char UARTX1_OUT_fifo[UARTX1_OUT_MAX];
uint8_t UARTX1_invertido=0;
uint8_t UARTX1_flowControlVar=0;
void UARTX1_bd(uint32_t);
void UARTX1_simplexMode(void);
void UARTX1_flowControl(uint8_t enabled);
void UARTX1_IN_ini(void);
void UARTX1_IN_push(char dato);
char UARTX1_IN_pop();
uint16_t UARTX1_IN_count(void);
uint16_t UARTX1_OUT_available(void)
{
    return UARTX1_OUT_MAX - ( (UARTX1_OUT_MAX-1) & (UARTX1_IN_punt_sal - UARTX1_IN_punt_entr ) );
}
void UARTX1_OUT_ini(void);
void UARTX1_OUT_push(char dato);
char UARTX1_OUT_pop(void);
void UARTX1_init(void);
void UARTX1_TXREG(uint16_t d);
uint8_t UARTX1_TRMT(void);
const streamIn_t  streamIn_Uart1  = {UARTX1_IN_pop,UARTX1_IN_count};
const streamOut_t streamOut_Uart1 = {UARTX1_OUT_push,UARTX1_OUT_available};
