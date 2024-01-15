#include <stdarg.h>
#include <stdio.h>
typedef struct streamIn_S
{
  char (*get)(void);
  uint16_t (*count)(void);
} streamIn_t;
float streamIn_t_ptr_to_float(streamIn_t*);
char streamIn_t_ptr_to_char(streamIn_t*);
uint8_t streamIn_t_ptr_to_uint8_t(streamIn_t*);
uint16_t streamIn_t_ptr_to_uint16_t(streamIn_t*);
uint32_t streamIn_t_ptr_to_uint32_t(streamIn_t*);
uint64_t streamIn_t_ptr_to_uint64_t(streamIn_t*);
int8_t streamIn_t_ptr_to_int8_t(streamIn_t*);
int16_t streamIn_t_ptr_to_int16_t(streamIn_t*);
int32_t streamIn_t_ptr_to_int32_t(streamIn_t*);
int64_t streamIn_t_ptr_to_int64_t(streamIn_t*);
void streamIn_t_ptr_to_ascii(streamIn_t*,char*,int);
