#include<reg51.h>
#include "header.h"


void uart_init(u32 baud)
{
	SCON=0x50; //mode1 and recieve enable
	TMOD|=0x20; //timer 1 mode 2 selected
	switch(baud)
	{
		case 7200:TH1=252;break;
		case 9600:TH1=253;break;
		case 14400:TH1=254;break;
		case 28800:TH1=255;break;
		case 57600:PCON|=0x80;
		           TH1=255;break;
	}
	TR1=1;
	EA=ES=1; //enabling uart interrupt
}
u8 uart_rx(void)
{
	u8 temp;
	while(RI==0);
	RI=0;
	temp=SBUF;
	return temp;
}
void uart_tx(u8 Data)
{
	SBUF=Data;
	while(TI==0);
	TI=0;
}
void uart_tx_string(u8 *ptr)
{
	s8 i;
	for(i=0;ptr[i];i++)
	{
		uart_tx(ptr[i]);
	}
}