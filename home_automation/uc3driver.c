#include<reg51.h>
#include "header.h"
sbit l1=P2^0;
sbit l2=P2^1;
sbit l3=P2^2;
sbit l4=P2^3;
sbit l5=P2^4;
sbit l6=P2^5;
sbit l7=P2^6;
sbit l8=P2^7;

sbit sw1=P3^2;  //int0
sbit sw2=P3^3;  //int1

char temp;   //data register
void uart_handler(void) interrupt 4
{
	if(RI==1)
	{
		RI=0;
		temp=SBUF;
		sw1=0;
     
	}
	if(TI==1)
		TI=0;
}
//**********************interupt defination***********************//
void ex0_isr(void) interrupt 0
{
	sw1=1;
	fun();     //led will toggle after each intterrupt
}

/*void ex1_isr(void) interrupt 2
{
	led2=~led2;   //led will toggle after each intterpt
}*/


//*************************************************************/
void enable_ex_interrupt(void)
{
	EA=EX0=1; //enable ex0 and ex1 interupt
	IT0=1;  //for edge triger
	
}

/***************************************************************/
void uart_init(u32 baud)
{
	SCON=0x50; //mode1 and recieve enable sm0 sm1 x REN x x TI RI 
	TMOD|=0x20; //timer 1 mode 2 selected G1 C/T M1 M0 G0 C0/T0 M1 M0
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
/*u8 uart_rx(void)
{
	u8 temp;
	while(RI==0);
	RI=0;
	temp=SBUF;
	return temp;
}*/
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

//*****************************functions******************************************//
void fun()
{
	switch(temp)
	{
		case '1':l1=~l1;
		      break;
		case '2':l2=~l2;
		     break;
		case '3':l3=~l3;
		      break;
		case '4':l4=~l4;
		     break;
		case '5':l5=~l5;
		      break;
		case '6':l6=~l6;
		     break;
		case '7':l7=~l7;
		      break;
		case '8':l8=~l8;
		     break;
		
		default:
			break;
	}
}