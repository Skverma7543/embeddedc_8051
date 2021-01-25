#include<reg51.h>
#include"header.h"
code u8 keys[4][4]={'7','8','9','/',
	                 '4','5','6','*',
	                 '1','2','3','-',
	                  'N','0','=','+'};
sbit r1=P2^0;
sbit r2=P2^1;
sbit r3=P2^2;
sbit r4=P2^3;
sbit c1=P2^4;
sbit c2=P2^5;
sbit c3=P2^6;
sbit c4=P2^7;
extern u8 expr[16];
u8 keyscan_smallcal()
{
	u8 row,col;
	r1=r2=r3=r4=0;
	while((c1&c2&c3&c4)==1);
	r2=r3=r4=1;
	if((c1&c2&c3&c4)==0)
	{
		row=0;
		goto colcheck;
	}
	r1=1;
	r2=0;
	if((c1&c2&c3&c4)==0)
	{
		row=1;
		goto colcheck;
	}
	r2=1;
	r3=0;
	if((c1&c2&c3&c4)==0)
	{
		row=2;
		goto colcheck;
	}
	r3=1;
	r4=0;
	if((c1&c2&c3&c4)==0)
	{
		row=3;
		goto colcheck;
	}
	colcheck:
	if(c1==0)
		col=0;
	else if(c2==0)
		col=1;
	else if(c3==0)
		col=2;
	else 
		col=3;
	while((c1&c2&c3&c4)==0);
	return keys[row][col];
}
u8 * float_to_str(f32 sum)
{
	s32 t1,t2,n=0;
	u8 i,j=0,temp;
	if(sum<0)
	{
		n=1;
		sum=-sum;
	}
	t1=sum;
	t2=100*(sum-t1);
	i=0;
	while(t2)
	{
		expr[i++]=t2%10+48;
		t2=t2/10;
		j++;
	}
	if(j!=0)
	expr[i++]='.';
	while(t1)
	{
		expr[i++]=t1%10+48;
		t1=t1/10;
	}
	if(n==1)
		expr[i++]='-';
	expr[i]=0;
	j=0;
	i=i-1;
	for(;j<i;j++,i--)
	{
		temp=expr[i];
		expr[i]=expr[j];
		expr[j]=temp;
	}
	return expr;
}
