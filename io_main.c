#include "header.h"
void main(void)
{
	//io_clr(PORT1,PIN1);
	//delay_ms(100);
	//io_set(PORT1,PIN1);
	//write_port(PORT1,0x1);
	//s8 temp;
	//write_port(PORT1,0x1);
	//temp=io_read(PORT1,PIN1);
//	delay_ms(1);
	while(1)
	{
		io_clr(PORT2,PIN0);
		delay_ms(100);
		io_set(PORT2,PIN0);
		delay_ms(100);
	}
}
