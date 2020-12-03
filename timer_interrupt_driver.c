#include<reg51.c>
#include "header.h"
void timer0_isr(void) interrupt 1
{
	TR0=0;  //to stop the timer
	/*define task here */
	//reinitialise timer ex set 50ms
}
void timer1_isr(void) interrupt 3
{
	TR1=0;  //to stop the timer
	/*define task here */
	//reinitialise timer ex:-50 ms
}
void enable_timer0_interrupt()
{
	EA=ET1=1;
}
void enable_timer1_interrupt()
{
	EA=ET0=1;
}
//timer interrupt can be used for implement multitasking in system
/*interrupt registers
IP-for priority changing by default it is 0-->x x x ES ET1 EX1 ET0 EX0
IE-enabling interrupt register --->EA x x ES ET1 EX1 ET0 EX0
TCON -> for setting clock triggering o for level and 1 for edge-->TF1 TR1 TF0 TR0 IE1 IT1 IE0 IT0
SCON->timer flag TI and RI ----->     SM0 SM1 x REN x x TI RI
TMOD-> G C/T M1 M0 | G C/T M1 M0
/*