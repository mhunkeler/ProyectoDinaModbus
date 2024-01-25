#define _rs232_H_
#define RPOUT_U1_TX RPOUT_RS232A_TX
#define RPIN_U1_RX  RPIN_RS232A_RX
#define RS232_tx()  UARTX1_OUT_push()
#define RS232_rx()   UARTX1_IN_pop()
#define USBFrameLf '\n'
void Init_RS232Driver(void);
