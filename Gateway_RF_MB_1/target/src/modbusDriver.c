#define MODBUS_SERIAL_TIMEOUT    1000000
#define MODBUS_SERIAL_RX_BUFFER_SIZE  64      //size of send/rcv buffer
int1 modbus_serial_new=0;
typedef enum _exception
{
	ILLEGAL_FUNCTION=1,
	ILLEGAL_DATA_ADDRESS=2,
	ILLEGAL_DATA_VALUE=3,
	SLAVE_DEVICE_FAILURE=4,
	ACKNOWLEDGE=5,
	SLAVE_DEVICE_BUSY=6, 
	MEMORY_PARITY_ERROR=8,
	GATEWAY_PATH_UNAVAILABLE=10,
	GATEWAY_TARGET_NO_RESPONSE=11,
	TIMEOUT=12
} exception;
typedef enum _function
{
	FUNC_READ_COILS=0x01,
	FUNC_READ_DISCRETE_INPUT=0x02,
	FUNC_READ_HOLDING_REGISTERS=0x03,
	FUNC_READ_INPUT_REGISTERS=0x04,
	FUNC_WRITE_SINGLE_COIL=0x05,
	FUNC_WRITE_SINGLE_REGISTER=0x06,
	FUNC_READ_EXCEPTION_STATUS=0x07,
	FUNC_DIAGNOSTICS=0x08,
	FUNC_GET_COMM_EVENT_COUNTER=0x0B,
	FUNC_GET_COMM_EVENT_LOG=0x0C,
	FUNC_WRITE_MULTIPLE_COILS=0x0F,
	FUNC_WRITE_MULTIPLE_REGISTERS=0x10,
	FUNC_REPORT_SLAVE_ID=0x11,
	FUNC_READ_FILE_RECORD=0x14,
	FUNC_WRITE_FILE_RECORD=0x15,
	FUNC_MASK_WRITE_REGISTER=0x16,
	FUNC_READ_WRITE_MULTIPLE_REGISTERS=0x17,
	FUNC_READ_FIFO_QUEUE=0x18
} function;
   enum {MODBUS_GETADDY=0, MODBUS_GETFUNC=1, MODBUS_GETDATA=2} modbus_serial_state = 0;
union
{
	uint8_t b[2];
	uint16_t d;
} modbus_serial_crc;
struct
{
   uint8_t address;
   uint8_t len;                       //number of bytes in the message received
   function func;                           //the function of the message received
   exception error;                         //error recieved, if any
   uint8_t data[MODBUS_SERIAL_RX_BUFFER_SIZE]; //data of the message received
} modbus_rx;
const unsigned char modbus_auchCRCHi[] = {
0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,
0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,
0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,
0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,
0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,
0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,
0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,
0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,
0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,
0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,
0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,
0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,
0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,
0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,
0x40
};
const unsigned char modbus_auchCRCLo[] = {
0x00,0xC0,0xC1,0x01,0xC3,0x03,0x02,0xC2,0xC6,0x06,0x07,0xC7,0x05,0xC5,0xC4,
0x04,0xCC,0x0C,0x0D,0xCD,0x0F,0xCF,0xCE,0x0E,0x0A,0xCA,0xCB,0x0B,0xC9,0x09,
0x08,0xC8,0xD8,0x18,0x19,0xD9,0x1B,0xDB,0xDA,0x1A,0x1E,0xDE,0xDF,0x1F,0xDD,
0x1D,0x1C,0xDC,0x14,0xD4,0xD5,0x15,0xD7,0x17,0x16,0xD6,0xD2,0x12,0x13,0xD3,
0x11,0xD1,0xD0,0x10,0xF0,0x30,0x31,0xF1,0x33,0xF3,0xF2,0x32,0x36,0xF6,0xF7,
0x37,0xF5,0x35,0x34,0xF4,0x3C,0xFC,0xFD,0x3D,0xFF,0x3F,0x3E,0xFE,0xFA,0x3A,
0x3B,0xFB,0x39,0xF9,0xF8,0x38,0x28,0xE8,0xE9,0x29,0xEB,0x2B,0x2A,0xEA,0xEE,
0x2E,0x2F,0xEF,0x2D,0xED,0xEC,0x2C,0xE4,0x24,0x25,0xE5,0x27,0xE7,0xE6,0x26,
0x22,0xE2,0xE3,0x23,0xE1,0x21,0x20,0xE0,0xA0,0x60,0x61,0xA1,0x63,0xA3,0xA2,
0x62,0x66,0xA6,0xA7,0x67,0xA5,0x65,0x64,0xA4,0x6C,0xAC,0xAD,0x6D,0xAF,0x6F,
0x6E,0xAE,0xAA,0x6A,0x6B,0xAB,0x69,0xA9,0xA8,0x68,0x78,0xB8,0xB9,0x79,0xBB,
0x7B,0x7A,0xBA,0xBE,0x7E,0x7F,0xBF,0x7D,0xBD,0xBC,0x7C,0xB4,0x74,0x75,0xB5,
0x77,0xB7,0xB6,0x76,0x72,0xB2,0xB3,0x73,0xB1,0x71,0x70,0xB0,0x50,0x90,0x91,
0x51,0x93,0x53,0x52,0x92,0x96,0x56,0x57,0x97,0x55,0x95,0x94,0x54,0x9C,0x5C,
0x5D,0x9D,0x5F,0x9F,0x9E,0x5E,0x5A,0x9A,0x9B,0x5B,0x99,0x59,0x58,0x98,0x88,
0x48,0x49,0x89,0x4B,0x8B,0x8A,0x4A,0x4E,0x8E,0x8F,0x4F,0x8D,0x4D,0x4C,0x8C,
0x44,0x84,0x85,0x45,0x87,0x47,0x46,0x86,0x82,0x42,0x43,0x83,0x41,0x81,0x80,
0x40
};
void modbus_init_()
{
   _ANSE4=0;
   HAL_GPIO_PinCfg(MODBUS_RX,GPIO_INPUT);     // (D3.0) 
   HAL_GPIO_PinCfg(MODBUS_TX,GPIO_OUTPUT);    // (D3.0) 
   UARTX1_Init(MODBUS_SERIAL_BAUD);
   UARTX1_simplexMode();
}
void modbus_enable_timeout(int1 enable)
{
   timeOut_enabled = enable;                       //D3.0
   if(enable)                                      //D3.0
   {                                               //D3.0
      modbus_Timeout = timeStamp;                  //D3.0
   }
}
void modbus_timeout_now(void)
{
   if((modbus_serial_state == MODBUS_GETDATA) && (modbus_serial_crc.d == 0x0000) && (!modbus_serial_new))
   {
      modbus_rx.len-=2;
      modbus_serial_new=TRUE;
   }
   else
      modbus_serial_new=FALSE;
   modbus_serial_crc.d=0xFFFF;
   modbus_serial_state=MODBUS_GETADDY;
   modbus_enable_timeout(FALSE);
}
void modbus_calc_crc(uint8_t data)
{
	unsigned int8 uIndex ; // will index into CRC lookup table
	uIndex = (modbus_serial_crc.b[1]) ^ data; // calculate the CRC
	modbus_serial_crc.b[1] = (modbus_serial_crc.b[0]) ^ modbus_auchCRCHi[uIndex];
	modbus_serial_crc.b[0] = modbus_auchCRCLo[uIndex];
}
void modbus_serial_putc(uint8_t c)
{
   	  UARTX_MODBUS_UART_push_OUT(c);  //fputc(c, MODBUS_SERIAL);
      modbus_calc_crc(c);
}
char UARTX_MODBUS_UART_ctrlRxByteEvent(char c)
{   
   if (!modbus_serial_new)
   {
         if(modbus_serial_state == MODBUS_GETADDY)
         {
            modbus_serial_crc.d = 0xFFFF;
            modbus_rx.address = c;
            modbus_serial_state++;
            modbus_rx.len = 0;
            modbus_rx.error=0;
         }
         else if(modbus_serial_state == MODBUS_GETFUNC)
         {
            modbus_rx.func = c;
            modbus_serial_state++;
         }
         else if(modbus_serial_state == MODBUS_GETDATA)
         {
            if (modbus_rx.len>=MODBUS_SERIAL_RX_BUFFER_SIZE) {modbus_rx.len=MODBUS_SERIAL_RX_BUFFER_SIZE-1;}
            modbus_rx.data[modbus_rx.len]=(uint8_t)c;
            modbus_rx.len++;
         }
         modbus_calc_crc(c);
         modbus_enable_timeout(TRUE);
   }
	return 0;
}
void modbus_serial_send_start(unsigned int8 to, unsigned int8 func)
{
   modbus_serial_crc.d=0xFFFF;
   modbus_serial_new=FALSE;
   modbus_serial_putc(to);
   modbus_serial_putc(func);
}
void modbus_serial_send_stop()
{
	unsigned int8 crc_low, crc_high;
	crc_high=modbus_serial_crc.b[1];
	crc_low=modbus_serial_crc.b[0];
	modbus_serial_putc(crc_high);
	modbus_serial_putc(crc_low);
	modbus_serial_crc.d=0xFFFF;
}
int1 modbus_kbhit()
{
   if(!modbus_serial_new)
      return FALSE;
   else if(modbus_rx.func & 0x80)           //did we receive an error?
   {
      modbus_rx.error = modbus_rx.data[0];  //if so grab the error and return true
      modbus_rx.len = 1;
   }
   modbus_serial_new=FALSE;
   return TRUE;
}
typedef struct _modbus_read_sub_request_rsp
{
   uint8_t record_length;
   uint8_t reference_type;
   uint16_t data[((MODBUS_SERIAL_RX_BUFFER_SIZE)/2)-3];
} modbus_read_sub_request_rsp;
typedef struct _modbus_write_sub_request_rsp
{
   uint8_t reference_type;
   uint16_t file_number;
   uint16_t record_number;
   uint16_t record_length;
   uint16_t data[((MODBUS_SERIAL_RX_BUFFER_SIZE)/2)-8];
} modbus_write_sub_request_rsp;
void modbus_read_coils_rsp(unsigned int8 address, unsigned int8 byte_count, unsigned int8* coil_data)
{
   unsigned int8 i;
   modbus_serial_send_start(address, FUNC_READ_COILS);
   modbus_serial_putc(byte_count);
   for(i=0; i < byte_count; ++i)
   {
      modbus_serial_putc(*coil_data);
      coil_data++;
   }
   modbus_serial_send_stop();
}
void modbus_read_discrete_input_rsp(unsigned int8 address, unsigned int8 byte_count, unsigned int8 *input_data)
{
   unsigned int8 i;
   modbus_serial_send_start(address, FUNC_READ_DISCRETE_INPUT);
   modbus_serial_putc(byte_count);
   for(i=0; i < byte_count; ++i)
   {
      modbus_serial_putc(*input_data);
      input_data++;
   }
   modbus_serial_send_stop();
}
void modbus_read_holding_registers_rsp(unsigned int8 address, unsigned int8 byte_count, 
                                        unsigned int16 *reg_data)
{
   unsigned int8 i;
   modbus_serial_send_start(address, FUNC_READ_HOLDING_REGISTERS);
   modbus_serial_putc(byte_count);
   for(i=0; i < byte_count; i+=2)
   {
      modbus_serial_putc(make8(*reg_data,1));
      modbus_serial_putc(make8(*reg_data,0));
      reg_data++;
   }
   modbus_serial_send_stop();
}
void modbus_read_input_registers_rsp(unsigned int8 address, unsigned int8 byte_count, 
                                        unsigned int16 *input_data)
{
   unsigned int8 i;
   modbus_serial_send_start(address, FUNC_READ_INPUT_REGISTERS);
   modbus_serial_putc(byte_count);
   for(i=0; i < byte_count; i+=2)
   {
      modbus_serial_putc(make8(*input_data,1));
      modbus_serial_putc(make8(*input_data,0));
      input_data++;
   }
   modbus_serial_send_stop();
}
void modbus_write_single_coil_rsp(unsigned int8 address, unsigned int16 output_address, 
                                    unsigned int16 output_value)
{
   modbus_serial_send_start(address, FUNC_WRITE_SINGLE_COIL);
   modbus_serial_putc(make8(output_address,1));
   modbus_serial_putc(make8(output_address,0));
   modbus_serial_putc(make8(output_value,1));
   modbus_serial_putc(make8(output_value,0));
   modbus_serial_send_stop();
}
void modbus_write_single_register_rsp(unsigned int8 address, unsigned int16 reg_address, 
                                        unsigned int16 reg_value)
{
   modbus_serial_send_start(address, FUNC_WRITE_SINGLE_REGISTER);
   modbus_serial_putc(make8(reg_address,1));
   modbus_serial_putc(make8(reg_address,0));
   modbus_serial_putc(make8(reg_value,1));
   modbus_serial_putc(make8(reg_value,0));
   modbus_serial_send_stop();
}
void modbus_read_exception_status_rsp(unsigned int8 address, unsigned int8 data)
{
   modbus_serial_send_start(address, FUNC_READ_EXCEPTION_STATUS);
   modbus_serial_send_stop();
}
void modbus_diagnostics_rsp(unsigned int8 address, unsigned int16 sub_func, unsigned int16 data)
{
   modbus_serial_send_start(address, FUNC_DIAGNOSTICS);
   modbus_serial_putc(make8(sub_func,1));
   modbus_serial_putc(make8(sub_func,0));
   modbus_serial_putc(make8(data,1));
   modbus_serial_putc(make8(data,0));
   modbus_serial_send_stop();
}
void modbus_get_comm_event_counter_rsp(unsigned int8 address, unsigned int16 status, 
                                        unsigned int16 event_count)
{
   modbus_serial_send_start(address, FUNC_GET_COMM_EVENT_COUNTER);
   modbus_serial_putc(make8(status, 1));
   modbus_serial_putc(make8(status, 0));
   modbus_serial_putc(make8(event_count, 1));
   modbus_serial_putc(make8(event_count, 0));
   modbus_serial_send_stop();
}
void modbus_get_comm_event_log_rsp(unsigned int8 address, unsigned int16 status,
                                    unsigned int16 event_count, unsigned int16 message_count, 
                                    unsigned int8 *events, unsigned int8 events_len)
{
   unsigned int8 i;
   modbus_serial_send_start(address, FUNC_GET_COMM_EVENT_LOG);
   modbus_serial_putc(events_len+6);
   modbus_serial_putc(make8(status, 1));
   modbus_serial_putc(make8(status, 0));
   modbus_serial_putc(make8(event_count, 1));
   modbus_serial_putc(make8(event_count, 0));
   modbus_serial_putc(make8(message_count, 1));
   modbus_serial_putc(make8(message_count, 0));
   for(i=0; i < events_len; ++i)
   {
      modbus_serial_putc(*events);
      events++;
   }
   modbus_serial_send_stop();
}
void modbus_write_multiple_coils_rsp(unsigned int8 address, unsigned int16 start_address, 
                                        unsigned int16 quantity)
{
   modbus_serial_send_start(address, FUNC_WRITE_MULTIPLE_COILS);
   modbus_serial_putc(make8(start_address,1));
   modbus_serial_putc(make8(start_address,0));
   modbus_serial_putc(make8(quantity,1));
   modbus_serial_putc(make8(quantity,0));
   modbus_serial_send_stop();
}
void modbus_write_multiple_registers_rsp(unsigned int8 address, unsigned int16 start_address, 
                                            unsigned int16 quantity)
{
   modbus_serial_send_start(address, FUNC_WRITE_MULTIPLE_REGISTERS);
   modbus_serial_putc(make8(start_address,1));
   modbus_serial_putc(make8(start_address,0));
   modbus_serial_putc(make8(quantity,1));
   modbus_serial_putc(make8(quantity,0));
   modbus_serial_send_stop();
}
void modbus_report_slave_id_rsp(unsigned int8 address, unsigned int8 slave_id, unsigned int1 run_status,
                              unsigned int8 *data, unsigned int8 data_len)
{
   unsigned int8 i;
   modbus_serial_send_start(address, FUNC_REPORT_SLAVE_ID);
   modbus_serial_putc(data_len+2);
   modbus_serial_putc(slave_id);
   if(run_status)
    modbus_serial_putc(0xFF);
   else
    modbus_serial_putc(0x00);
   for(i=0; i < data_len; ++i)
   {
      modbus_serial_putc(*data);
      data++;
   }
   modbus_serial_send_stop();
}
void modbus_read_file_record_rsp(unsigned int8 address, unsigned int8 byte_count, 
                                    modbus_read_sub_request_rsp *request)
{
   unsigned int8 i=0,j;
   modbus_serial_send_start(address, FUNC_READ_FILE_RECORD);
   modbus_serial_putc(byte_count);
   while(i < byte_count);
   {
      modbus_serial_putc(request->record_length);
      modbus_serial_putc(request->reference_type);
      for(j=0; (j < request->record_length); j+=2)
      {
         modbus_serial_putc(make8(request->data[j], 1));
         modbus_serial_putc(make8(request->data[j], 0));
      }
      i += (request->record_length)+1;
      request++;
   }
   modbus_serial_send_stop();
}
void modbus_write_file_record_rsp(unsigned int8 address, unsigned int8 byte_count, 
                                    modbus_write_sub_request_rsp *request)
{
   unsigned int8 i, j=0;
   modbus_serial_send_start(address, FUNC_WRITE_FILE_RECORD);
   modbus_serial_putc(byte_count);
   for(i=0; i < byte_count; i+=(7+(j*2)))
   {
      modbus_serial_putc(request->reference_type);
      modbus_serial_putc(make8(request->file_number, 1));
      modbus_serial_putc(make8(request->file_number, 0));
      modbus_serial_putc(make8(request->record_number, 1));
      modbus_serial_putc(make8(request->record_number, 0));
      modbus_serial_putc(make8(request->record_length, 1));
      modbus_serial_putc(make8(request->record_length, 0));
      for(j=0; (j < request->record_length); j+=2)
      {
         modbus_serial_putc(make8(request->data[j], 1));
         modbus_serial_putc(make8(request->data[j], 0));
      }
   }
   modbus_serial_send_stop();
}
void modbus_mask_write_register_rsp(unsigned int8 address, unsigned int16 reference_address,
                           unsigned int16 AND_mask, unsigned int16 OR_mask)
{
   modbus_serial_send_start(address, FUNC_MASK_WRITE_REGISTER);
   modbus_serial_putc(make8(reference_address,1));
   modbus_serial_putc(make8(reference_address,0));
   modbus_serial_putc(make8(AND_mask,1));
   modbus_serial_putc(make8(AND_mask,0));
   modbus_serial_putc(make8(OR_mask, 1));
   modbus_serial_putc(make8(OR_mask, 0));
   modbus_serial_send_stop();
}
void modbus_read_write_multiple_registers_rsp(unsigned int8 address, unsigned int8 data_len, 
                                                unsigned int16 *data)
{
   unsigned int8 i;
   modbus_serial_send_start(address, FUNC_READ_WRITE_MULTIPLE_REGISTERS);
   modbus_serial_putc(data_len*2);
   for(i=0; i < data_len*2; i+=2)
   {
      modbus_serial_putc(make8(data[i], 1));
      modbus_serial_putc(make8(data[i], 0));
   }
   modbus_serial_send_stop();
}
void modbus_read_FIFO_queue_rsp(unsigned int8 address, unsigned int16 FIFO_len, unsigned int16 *data)
{
   unsigned int8 i;
   unsigned int16 byte_count;
   byte_count = ((FIFO_len*2)+2);
   modbus_serial_send_start(address, FUNC_READ_FIFO_QUEUE);
   modbus_serial_putc(make8(byte_count, 1));
   modbus_serial_putc(make8(byte_count, 0));
   modbus_serial_putc(make8(FIFO_len, 1));
   modbus_serial_putc(make8(FIFO_len, 0));
   for(i=0; i < FIFO_len; i+=2)
   {
      modbus_serial_putc(make8(data[i], 1));
      modbus_serial_putc(make8(data[i], 0));
   }
   modbus_serial_send_stop();
}
void modbus_exception_rsp(unsigned int8 address, unsigned int16 func, exception error)
{
   modbus_serial_send_start(address, func|0x80);
   modbus_serial_putc(error);
   modbus_serial_send_stop();
}
int8 swap_bits(int8 c)
{
   return ((c&1)?128:0)|((c&2)?64:0)|((c&4)?32:0)|((c&8)?16:0)|((c&16)?8:0)
          |((c&32)?4:0)|((c&64)?2:0)|((c&128)?1:0);
}
void poll_modbusDriver(void)
{
   if(UARTX1_IN_count())
   {
      UARTX_MODBUS_UART_ctrlRxByteEvent(UARTX1_IN_pop());
   }
   if(timeOut_enabled)
   {
      if(timeStamp - modbus_Timeout > (32000/MODBUS_SERIAL_BAUD))     //(timeout > 3,5 characters) 4 characters
      {
         modbus_timeout_now();
         modbus_Timeout = timeStamp;
      }
   }
   if(!modbus_kbhit()) return;
   if((modbus_rx.address == MODBUS_ADDRESS) || modbus_rx.address == 0) 
   {
      switch(modbus_rx.func)
      {
         case FUNC_READ_COILS:    //read coils
         case FUNC_READ_DISCRETE_INPUT:    //read inputs
            if(modbus_rx.data[0] || modbus_rx.data[2] || modbus_rx.data[1] >= 8 || modbus_rx.data[3]+modbus_rx.data[1] > 8)
            {
               modbus_exception_rsp(MODBUS_ADDRESS,modbus_rx.func,ILLEGAL_DATA_ADDRESS);
            }
            else
            {
               int8 data;
               if(modbus_rx.func == FUNC_READ_COILS)
               {
                  data = coils >> (modbus_rx.data[1]);      //move to the starting coil
               }  
               else
               {
                  data = inputs >> (modbus_rx.data[1]);      //move to the starting input
               }
               data = data & (0xFF >> (8-modbus_rx.data[3]));  //0 out values after quantity
               if(modbus_rx.func == FUNC_READ_COILS)
               {
                  modbus_read_coils_rsp((unsigned int8)MODBUS_ADDRESS,(unsigned int8) 0x01, &data);
               }  
               else
               {
                  modbus_read_discrete_input_rsp(MODBUS_ADDRESS, 0x01, &data);
               }
               event_count++;
            }
            break;
         case FUNC_READ_HOLDING_REGISTERS:
         case FUNC_READ_INPUT_REGISTERS:
            {
               if(modbus_rx.func == FUNC_READ_HOLDING_REGISTERS)
               {
                  modbus_read_holding_registers_rsp(MODBUS_ADDRESS,(modbus_rx.data[3]*2),hold_regs+modbus_rx.data[1]);
               }
               else
               {
                  modbus_read_input_registers_rsp(MODBUS_ADDRESS,(modbus_rx.data[3]*2),input_regs+modbus_rx.data[1]);
               }
               event_count++;
            }
            break;
         case FUNC_WRITE_SINGLE_COIL:      //write coil
            if(modbus_rx.data[0] || modbus_rx.data[3] || modbus_rx.data[1] > 8)
            {
               modbus_exception_rsp(MODBUS_ADDRESS,modbus_rx.func,ILLEGAL_DATA_ADDRESS);
            }
            else if(modbus_rx.data[2] != 0xFF && modbus_rx.data[2] != 0x00)
            {
               modbus_exception_rsp(MODBUS_ADDRESS,modbus_rx.func,ILLEGAL_DATA_VALUE);
            } 
            else
            {
               if(modbus_rx.data[2] == 0xFF)
               {
                  bit_set(coils,modbus_rx.data[1]);   
               }
               else
               {
                  bit_clear(coils,modbus_rx.data[1]);
               }
               modbus_write_single_coil_rsp(MODBUS_ADDRESS,modbus_rx.data[1],((int16)(modbus_rx.data[2]))<<8);
               event_count++;
            }
            break;
         case FUNC_WRITE_SINGLE_REGISTER:
            if(modbus_rx.data[0] || modbus_rx.data[1] >= 8)
            {
               modbus_exception_rsp(MODBUS_ADDRESS,modbus_rx.func,ILLEGAL_DATA_ADDRESS);
            }
            else
            {
				  hold_regs[modbus_rx.data[1]] = make16(modbus_rx.data[2],modbus_rx.data[3]);
               modbus_write_single_register_rsp(MODBUS_ADDRESS,make16(modbus_rx.data[0],modbus_rx.data[1]),make16(modbus_rx.data[2],modbus_rx.data[3]));
            }
            break;
         case FUNC_WRITE_MULTIPLE_COILS:
            if(modbus_rx.data[0] || modbus_rx.data[2] || modbus_rx.data[1] >= 8 || modbus_rx.data[3]+modbus_rx.data[1] > 8)
            {
               modbus_exception_rsp(MODBUS_ADDRESS,modbus_rx.func,ILLEGAL_DATA_ADDRESS);
            }
            else
            {
               int i,j;
               for(i=modbus_rx.data[1],j=0; i < modbus_rx.data[1]+modbus_rx.data[3]; ++i,++j)
               {  
                  if(bit_test(modbus_rx.data[5],j))
                  {
                     bit_set(coils,i);
                  }
                  else
                  {
                     bit_clear(coils,i);
                  }
               }
               modbus_write_multiple_coils_rsp(MODBUS_ADDRESS, make16(modbus_rx.data[0],modbus_rx.data[1]), make16(modbus_rx.data[2],modbus_rx.data[3]));
               event_count++;
            }
            break;
         case FUNC_WRITE_MULTIPLE_REGISTERS:
            if(modbus_rx.data[0] || modbus_rx.data[2] || modbus_rx.data[1] >= 8 || modbus_rx.data[3]+modbus_rx.data[1] > 8)
            {
               modbus_exception_rsp(MODBUS_ADDRESS,modbus_rx.func,ILLEGAL_DATA_ADDRESS);
            }
            else
            {
               int i,j;
               for(i=0,j=5; i < modbus_rx.data[4]/2; ++i,j+=2)
               {
				  	   hold_regs[i] = make16(modbus_rx.data[j],modbus_rx.data[j+1]);
				   }
               modbus_write_multiple_registers_rsp(MODBUS_ADDRESS,make16(modbus_rx.data[0],modbus_rx.data[1]),make16(modbus_rx.data[2],modbus_rx.data[3]));
               event_count++;
            }
         break;           
         default:    //We don't support the function, so return exception
            modbus_exception_rsp(MODBUS_ADDRESS,modbus_rx.func,ILLEGAL_FUNCTION);
         }
      }
}
