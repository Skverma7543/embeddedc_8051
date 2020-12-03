#include<reg51.h>
#include "header.h"
sbit r0=P3^0;
sbit r1=P3^1;
sbit r2=P3^2;
sbit r3=P3^3;
sbit c0=P1^0;
sbit c1=P1^1;
sbit c2=P1^2;
sbit c3=P1^3;
u8 tab[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'N','0','=','+'}};
u8 keyscan_cal(void)
{
	u8 row,col;
	r1=r2=r3=r0=0;
	while(c1&c2&c0&c3);
	r1=r2=r3=r0=1;
	r0=0;
	if((c1&c2&c0&c3)==0)
	{
		row=0;
		goto col_check;
	}
	r1=r2=r3=r0=1;
	r1=0;
	if((c1&c2&c0&c3)==0)
	{
		row=1;
		goto col_check;
	}
	r1=r2=r3=r0=1;
	r2=0;
	if((c1&c2&c0&c3)==0)
	{
		row=2;
		goto col_check;
	}
	r1=r2=r3=r0=1;
	r3=0;
	if((c1&c2&c0&c3)==0)
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
	else if(c3==0)
		col=3;
	while(c1&c2&c0==0);
	return tab[row][col];
}