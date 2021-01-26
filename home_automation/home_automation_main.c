#include "header.h"
u8 *menu="welcome\r\npress m to see menu\r\n";
void main()
{
	uart_init(9600);
	enable_ex_interrupt();
	uart_tx_string(menu);
		while(1);
}