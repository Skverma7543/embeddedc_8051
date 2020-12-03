#include<reg51.h>
void uart_handler(void) interrupt 4
{
	char temp;
	if(RI==1)
	{
		RI=0;
		temp=SBUF;
		SBUF=temp; //for loopback
     
	}
	if(TI==1)
		TI=0;
}