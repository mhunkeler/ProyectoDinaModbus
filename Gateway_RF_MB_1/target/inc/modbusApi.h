int8 inputs_old = 0b00000000;
uint16_t MBbaud = UARTX1_baud;      /**< Modbus baud rate */
uint8_t MBid = 1;                            /**< Modbus Address */
void set_modBus(char select, uint8_t n, int16_t data);
void init_ModBus(void);
void poll_DinaModbus(void);
