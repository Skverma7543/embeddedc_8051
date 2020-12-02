#include<reg51.h>
#include "header.h"
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
sfr lcd_port=0x80;
void lcd8_data(u8 Data)
{
	lcd_port=Data; 
	rs=1;     //data mode
	rw=0;     //command mode
	en=1;     // enable lcd for reading writing
	delay_ms(2);  //delay is must becouse lcd take 1.5 ms to read data bus
	en=0;        //disable read write
}
void lcd8_cmd(u8 cmd)
{
	lcd_port=cmd;
	rs=0; //command mode
	rw=0; //write mode
	en=1;
	delay_ms(2);
	en=0;
}

void lcd8_init(void)
{
	lcd8_cmd(0x1);
	lcd8_cmd(0x2);   //clear and home
	lcd8_cmd(0x38); // 8bit mode
	lcd8_cmd(0xC); //cursor off and increament address pointer
	lcd8_cmd(0x80); //starting position of lcd
}

void lcd8_string(u8 *ptr)
{
	s8 i;
	for(i=0;ptr[i];i++)
	{
		if(ptr[i]=='\n')
		{
			lcd8_cmd(0xC0);
			continue;
		}
		lcd8_data(ptr[i]);
	}
}
