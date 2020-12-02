#include<reg51.h>
#include "header.h"
s8 io_write(u8 port,u8 pin,u8 BIT)
{
	if(port>3||port<0||pin>7||pin<0)
		return -1;
	switch(port)
	{
		case PORT0:
			if(BIT==CLEAR)
				P0&=~(1<<pin);
			else
				P0|=1<<pin;
				
			break;
		case PORT1:
			if(BIT==CLEAR)
				P1&=~(1<<pin);
			else
				P1|=1<<pin;
			break;
		case PORT2:
			if(BIT==CLEAR)
				P2&=~(1<<pin);
			else
				P2|=1<<pin;
			break;
		case PORT3:
			if(BIT==CLEAR)
				P3&=~(1<<pin);
			else
				P3|=1<<pin;
			break;
	}
	return 0;
}

s8 io_read(u8 port,u8 pin)
{
	s8 status;
	if(port>3||port<0||pin>7||pin<0)
		return -1;
	switch(port)
	{
		case PORT0:
			status=((P0>>pin)&1)?1:0;
			break;
		case PORT1:
			status=((P1>>pin)&1)?1:0;
			break;
		case PORT2:
			status=((P2>>pin)&1)?1:0;
			break;
		case PORT3:
			status=((P3>>pin)&1)?1:0;
			break;
		
	}
	return status;
}

s8 io_set(u8 port,u8 pin)
{
	if(port>3||port<0||pin>7||pin<0)
		return -1;
	switch(port)
	{
		case PORT0:
			P0|=1<<pin;
			break;
		case PORT1:
			P1|=1<<pin;
			break;
		case PORT2:
			P2|=1<<pin;
			break;
		case PORT3:
			P3|=1<<pin;
			break;
	}
	return 0;
}
s8 io_clr(u8 port,u8 pin)
{
	if(port>4||port<0||pin>7||pin<0)
		return -1;
	switch(port)
	{
		case PORT0:
			P0&=~(1<<pin);
			break;
		case PORT1:
			P1&=~(1<<pin);
			break;
		case PORT2:
			P2&=~(1<<pin);
			break;
		case PORT3:
			P3&=~(1<<pin);
			break;
	}
	return 0;
}

s8 write_port(u8 port,u8 Data)
{
	if(port>3||port<0)
		return -1;
	switch(port)
	{
		case PORT0:P0=Data;
			break;
		case PORT1:P1=Data;
			break;
		case PORT2:P2=Data;
			break;
		case PORT3:P3=Data;
			break;
		
	}
	return 0;
}
s8 read_port(u8 port)
{
	s8 temp;
	switch(port)
	{
		case PORT0:temp=P0;
			break;
		case PORT1:temp=P1;
			break;
		case PORT2:temp=P2;
			break;
		case PORT3:temp=P3;
			break;
	}
	return temp;
}