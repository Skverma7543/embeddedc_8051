#include<reg51.h>
#include "header.h"
void delay_ms(u32 ms)
{
	u8 i;
	while(ms--)
	{
		i=250;
		while(i--);
		i=247;
		while(i--);
	}
}