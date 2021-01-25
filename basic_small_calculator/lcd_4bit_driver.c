#include<reg51.h>
#include"header.h"
sbit rs=P0^4;    //rs=1 -->data    rs=0 -->command
sbit rw=P0^5;    //rs=1--->read    rw=0--->write
sbit en=P0^6;    //en=0--->desable readwrite en=1---->enable read write
sfr LCD_PORT=0x80;
void lcd4_cmd(u8 cmd)
{
	LCD_PORT=cmd>>4;    //cmd data place into port pin in which lcd is connected
	rs=0;            //command
	rw=0;            //write
	en=1;            //enable
	delay_ms(2);     //imp lcd takes 1.5 ms to read data so we need to keed data on data bus for 2 ms
	en=0;            //imp,to proctect lcd
	
	LCD_PORT=cmd&0x0f;    //cmd data place into port pin in which lcd is connected
	rs=0;            //command
	rw=0;            //write
	en=1;            //enable
	delay_ms(2);     //imp lcd takes 1.5 ms to read data so we need to keed data on data bus for 2 ms
	en=0;            //imp,to proctect lcd
}

void lcd4_data(u8 d)
{
	LCD_PORT=d>>4;    //data place into port pin in which lcd is connected
	rs=1;            //data
	rw=0;            //write
	en=1;            //enable
	delay_ms(2);     //imp lcd takes 1.5 ms to read data so we need to keed data on data bus for 2 ms
	en=0;            //imp,to proctect lcd
	
		LCD_PORT=d&0x0f;    //data place into port pin in which lcd is connected
	rs=1;            //data
	rw=0;            //write
	en=1;            //enable
	delay_ms(2);     //imp lcd takes 1.5 ms to read data so we need to keed data on data bus for 2 ms
	en=0;           
}
void lcd4_init()
{
	lcd4_cmd(0x1);   //crear screen
	lcd4_cmd(0x2);   //return to home not clear screen
	lcd4_cmd(0x28);  //4 bit mode 
	lcd4_cmd(0x80);  //set curser to 1st raw 1st position
	lcd4_cmd(0xf);   //cursor on
}
void lcd4_string(u8 *str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		lcd4_data(str[i]);
	}
}

/**************list of usefull commands
0x1=clearscreen
0x2=set cursur in home without clear the screen
0xc-->off  cursor
0xE-->on cursor
0xF-->blink cursor
0x28-->lcd mode 4
0x38-->lcd mode 8
0x80-->1st row 1st pos
0xc0-->2nd row 1st pos
**********************************/