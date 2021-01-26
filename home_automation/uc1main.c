#include "header.h"
//code u8 *menu="menu\r\n1.bulb1\r\n2.bulb2\r\n3.fan1\r\n4.fan2\r\n";
void main()
{
	uart_init(9600);
	enable_ex_interrupt();
	uart_tx_string("hello");
		while(1);
}