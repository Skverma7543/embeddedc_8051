#include "header.h"
void main(void)
{
	u8 temp;
	lcd4_init();
	lcd4_data('A');
	while(1)
	{
		temp=keyscan_phone();
		lcd4_data(temp);
		delay_ms(100);
	}
}