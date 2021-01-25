#include "header.h"
u8 expr[16];
void main()
{
	u8 ch,i=0,temp;
	f32 t1=0,t2=0,sum;
	l1:
	lcd4_init();
	i=0;
	t1=t2=0;
	/**************scaning 1st operand******************/
	while(1)
	{
		ch=keyscan_smallcal();
		if(ch=='N')
			goto l1;
		lcd4_data(ch);
		if(ch<'0'||ch>'9')
			break;
		t1=t1*10+ch-48;
		delay_ms(100);
	}
	l2:
	temp=ch;
	t2=0;
	/*******************scaning 2nd operand****************/
	while(1)
	{
		ch=keyscan_smallcal();
		if(ch=='N')
			goto l1;
		if(ch<'0'||ch>'9')
		{
			if(ch=='=')
			lcd4_cmd(0xc0); //next line
			lcd4_data(ch);
			break;
		}
		lcd4_data(ch);
		
		t2=t2*10+ch-48;
		delay_ms(100);
	}
	switch(temp)
	{
		case '+':
			t1=t1+t2;
			break;
		case '-':
			t1=t1-t2;
			break;
		case '*':
			t1=t1*t2;
			break;
		case '/':
			t1=t1/t2;
		break;	
	}
	if(ch!='=')
		goto l2;
	
	lcd4_string(float_to_str(t1));
	delay_ms(100);
	while(1)
	{
		ch=keyscan_smallcal();
		if(ch=='N')
			goto l1;
	}
}
