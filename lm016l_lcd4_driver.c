#include<reg51.h>
#include "header.h"
sfr lcd_port=0xA0;
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void lcd4_data(u8 Data)
{
	lcd_port=Data&0xf0; 
	rs=1;     //data mode
	rw=0;     //command mode
	en=1;     // enable lcd for reading writing
	delay_ms(2);  //delay is must becouse lcd take 1.5 ms to read data bus
	en=0;        //disable read write
	lcd_port=(Data<<4)&0xf0; 
	rs=1;     //data mode
	rw=0;     //command mode
	en=1;     // enable lcd for reading writing
	delay_ms(2);  //delay is must becouse lcd take 1.5 ms to read data bus
	en=0;        //disable read write
}
void lcd4_cmd(u8 cmd)
{
	lcd_port=cmd&0xf0;
	rs=0; //command mode
	rw=0; //write mode
	en=1;
	delay_ms(2);
	en=0;
	lcd_port=(cmd<<4)&0xf0;
	rs=0; //command mode
	rw=0; //write mode
	en=1;
	delay_ms(2);
	en=0;
}

void lcd4_init(void)
{
	lcd4_cmd(0x1);
	lcd4_cmd(0x2);   //clear and home
	lcd4_cmd(0x28); // 4bit mode
	lcd4_cmd(0xC); //cursor off and increament address pointer
	lcd4_cmd(0x80); //starting position of lcd
}

void lcd4_string(u8 *ptr)
{
	s8 i;
	for(i=0;ptr[i];i++)
	{
		if(ptr[i]=='\n')
		{
			lcd4_cmd(0xC0);
			continue;
		}
		lcd4_data(ptr[i]);
	}
}