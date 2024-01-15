#define PIC_GPIO_H_
typedef enum
{
	GPIO_OUTPUT,
	GPIO_INPUT,
}gpio_pinConfig_t;
typedef enum
{
	GPIO_LOW,
	GPIO_HIGH,
	GPIO_TOGGLE
}gpio_state_t;
#define HAL_GPIO_PinCfg(name,cfg_value) TRIS_##name = cfg_value
#define HAL_GPIO_PinSet(name,value)  while(LAT_##name != value){LAT_##name = value;__builtin_nop();__builtin_nop();}
#define HAL_GPIO_PinGet(name) PIN_##name
#define HAL_GPIO_PORT_Set(name) while(PORT_##name | ~(1<<PORTn_##name)){PORT_##name   = PORT_##name | 1<<PORTn_##name; }
#define HAL_GPIO_PORT_Reset(name) PORT_##name = PORT_##name & ~(1<<PORTn_##name)
