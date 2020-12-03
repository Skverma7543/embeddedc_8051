#include<reg51.h>
#include "header.h"
sbit r0=P2^4;
sbit r1=P2^5;
sbit r2=P2^6;
sbit r3=P2^7;
sbit c0=P2^0;
sbit c1=P2^1;
sbit c2=P2^2;
u8 tab[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
u8 keyscan_phone(void)
{
	u8 row,col;
	r1=r2=r3=r0=0;
	while(c1&c2&c0);
	r1=r2=r3=r0=1;
	r0=0;
	if((c1&c2&c0)==0)
	{
		row=0;
		goto col_check;
	}
	r1=r2=r3=r0=1;
	r1=0;
	if((c1&c2&c0)==0)
	{
		row=1;
		goto col_check;
	}
	r1=r2=r3=r0=1;
	r2=0;
	if((c1&c2&c0)==0)
	{
		row=2;
		goto col_check;
	}
	r1=r2=r3=r0=1;
	r3=0;
	if((c1&c2&c0)==0)
	{
		row=3;
		goto col_check;
	}
	col_check:
	if(c0==0)
		col=0;
	else if(c1==0)
		col=1;
	else if(c2==0)
		col=2;
	while(c1&c2&c0==0);
	return tab[row][col];
}