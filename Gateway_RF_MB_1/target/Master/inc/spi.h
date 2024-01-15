#define _SPI_MASTER_H_
uint8_t * pending_data;
uint8_t spi_response_data[32];
uint8_t spi_package_size = 8;
uint8_t ready = 1;
int indice = 0;
void (*fun_ptr)(uint8_t *, uint8_t);
void SPI1_init (uint8_t mode16, uint8_t spi_mode);
void SPI1_disable();
void SPI1_enable();
uint8_t SPI1_send_async(uint8_t * new_data, uint8_t package_size, uint8_t * proccess_function);
uint8_t xchangeSPI1b_8(uint8_t data);
uint16_t xchangeSPI1b_16(uint16_t data);
void SPI_clr(void);
