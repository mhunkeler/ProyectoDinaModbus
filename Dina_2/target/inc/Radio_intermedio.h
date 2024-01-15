enum EstadosRADIO
{
	RF_WAIT,			// Espera datos para transmitir o rssi
	RF_TX,				// Transmite los datos pendientes
	RF_RX,				// Lee los paquetes recibidos y devuelve el ACK.
	RF_SLEEP,			// Al salir de este, ejecuta un mensaje de wakeup al otro dispositivo.
};
enum EstadosTX
{
	TX_IN,				// Pone el chip en estado TX.
	TX_SENDING_DATA,	// Comienza a transmitir el paquete.
	TX_WAITING_ACK		// Espera a recibir un CRC OK.
};
enum EstadosRX
{
	RX_IN,				// Lee el paquete recibido.
	RX_SEND_ACK_IN,		// Cambia al modo TX para transmitir el ACK.
	RX_SENDING_ACK		// Transmite el CRC OK.
};
enum Sending_status
{
	TX_NO_ACK = -1,
	TX_SENDING = 0,
	TX_AVAILABLE = 1
};
uint8_t idGrupo=0;
int8_t SleepFlag = 0;
uint8_t message [46];									//Data to send.
uint8_t message_length;									//Length of data to send.
uint8_t read_data[66];									//Received data.
uint8_t read_data_length;								//Length of read data.
uint8_t new_data_to_read = 0;							//Flag that indicates if there are new data to read. 
uint8_t tx_pending_data = 0;							//Flag that indicates if there is sending data.
int8_t tx_right = 1;									//Flag that indicates if the RFM69 could be transmitted correctly.
uint8_t tx_packet_id = 0;
uint8_t last_rx_packet_id = -1;
void Intermedio_FSK_Init(void);
void SendFSKMessage(uint8_t* data, uint8_t length);		//Send data, return if the data could be transmitted
uint8_t ReadFSKMessage(void);							//Read the data from RFM69, and pass this to the api.
int8_t Sending_Available(void);							//Return true if there isn't sending data.
uint8_t Data_Available(void);							//Return true if there are data avaiable to read.
uint8_t Read_Data(uint8_t* data);						//Return data and the data's length.
void Radio_Int_Sleep(void);									//Puts the radio to sleep.
void Radio_Int_WakeUp(void);								//Puts the radio to wakeup.
void Intermedio_FSK_Poll(void);
