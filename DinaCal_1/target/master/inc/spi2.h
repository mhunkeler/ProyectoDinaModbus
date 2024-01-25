#define _SPI2_MASTER_H_
uint8_t* spi2_pending_data;
uint8_t spi2_response_data[32];
uint8_t spi2_package_size = 8;
uint8_t spi2_ready = 1;
int spi2_indice = 0;
void (*spi2_fun_ptr)(uint8_t *, uint8_t);
void SPI2_init (uint8_t mode16, uint8_t spi_mode);
void SPI2_disable();
void SPI2_enable();
uint8_t SPI2_send_async(uint8_t * new_data, uint8_t package_size, uint8_t * proccess_function);
uint8_t xchangeSPI2b_8(uint8_t data);
void SPI2_clr(void);
