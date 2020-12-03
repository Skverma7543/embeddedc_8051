#include<reg51.h>
#include "header.h"
void delay_1ms(void)    //for 1 ms delay
{
		TMOD|=0x1;
		TH0=0xFC;
		//TL0=0x25;
		TL0=0x50;
		TR0=1;
		while(TF0==0);
		TR0=0;
		TF0=0;
	 
}
void delay_ms(u32 ms)  // for n ms delay
{
	while(ms--)
		delay_1ms();
}
void sdelay_ms(u32 ms)
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