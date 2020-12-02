#include "header.h"
void main(void)
{
	cgram_init();
	lcd8_init();
	lcd8_data(0);
	lcd8_data('v');
	lcd8_string("vector \n");
	lcd8_data('B');
	
	while(1);
}