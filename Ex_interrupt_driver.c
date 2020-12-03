#include<reg51.h>
#include "header.h"
sbit led1=P2^0;
sbit led2=P2^1;
sbit sw1=P3^2;  //int0
sbit sw2=P3^3;  //int1
void ex0_isr(void) interrupt 0
{
	led1=~led1;     //led will toggle after each intterrupt
}
void ex1_isr(void) interrupt 2
{
	led2=~led2;   //led will toggle after each intterpt
}
void enable_ex_interrupt(void)
{
	EA=EX0=EX1=1; //enable ex0 and ex1 interupt
	IT0=IT1=1;  //for edge triger
	
}

/*interrupt registers
IP-for priority changing by default it is 0-->x x x ES ET1 EX1 ET0 EX0
IE-enabling interrupt register --->EA x x ES ET1 EX1 ET0 EX0
TCON -> for setting clock triggering o for level and 1 for edge-->TF1 TR1 TF0 TR0 IE1 IT1 IE0 IT0
/*