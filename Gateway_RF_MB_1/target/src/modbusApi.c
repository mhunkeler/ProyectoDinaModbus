void init_ModBus(void)
{
	modbus_init_();
}
void set_modBus(char select, uint8_t n, int16_t data)
{
	switch (select)
	{
		case 'I':
		case 'i':
			if(data)
			{
				bit_set(inputs, n);
			}
			else
			{
				bit_clear(inputs, n);
			}
			break;
		case 'C':
		case 'c':
			if(data)
			{
				bit_set(coils, n);
			}
			else
			{
				bit_clear(coils, n);
			}
			break;
		case 'R':
		case 'r':
			input_regs[n] = data;
			break;
		case 'H':
		case 'h':
			hold_regs[n]  = data; 
			break;
	}		
}
void poll_DinaModbus()
{
	uint8_t i;
	uint8_t modbusEvents,inputsValues;
	modbusEvents = coils ^ inputs_old;
	inputsValues = coils;
	for (i = 1; i <= 8 ; i++)
	{
		if (modbusEvents & 0x01)
		{
		}
		inputsValues >>= 1;
		modbusEvents >>= 1;
	}
	inputs_old = coils;
}	
