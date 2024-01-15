#define int8 short
#define int1 short
#define int16 int
#define TRUE 1
#define FALSE 0
uint32_t modbus_Timeout = 0;
int1 timeOut_enabled = FALSE;
#define MODBUS_SERIAL_BAUD MBbaud
#define RPOUT_U1_TX RPOUT_MODBUS_TX
#define RPIN_U1_RX  RPIN_MODBUS_RX
#define UARTX_MODBUS_UART_push_OUT(dato) UARTX1_OUT_push(dato)
#define make8(value, option) ((option == 1) ? ((value >> 8) & 0xFF) : (value & 0xFF))
#define make16(high, low) (((int16_t)(high) << 8) | (low))
#define bit_set(var, bit) ((var) |= (1 << (bit)))
#define bit_clear(var, bit) ((var) &= ~(1 << (bit)))
#define bit_test(var, bit) (((var) & (1 << (bit))) != 0)
#define MODBUS_ADDRESS MBid
int8_t coils  = 0b00000101;
int8_t inputs = 0b00001001;
int16_t hold_regs[8] = {168,0,1,0,1,1,1,1024}; // carrera, offsetAcc,spanAcc, offsetFuerza,spanFuerzaN,spanFuerzaD, metodoAcc, ajustAcc, damy
int16_t input_regs[160];
int16_t event_count = 0;
void poll_modbusDriver(void);
