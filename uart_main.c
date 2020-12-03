#include "header.h"

void main(void)
{
	
	u8 temp;
	enable_ex0_interrupt();
	uart_init(9600);
	while(1)
	{
		//temp=uart_rx();
		//uart_tx(temp);
		//uart_tx_string("success \r\n");
	}
}