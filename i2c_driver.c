#include<reg51.h>
#include<intrins.h> //for __nop__() is use for 1 usec delay;
#include "header.h"
sbit sda=P2^0;   //data pin
sbit scl=P2^1;   //clock pin
/*********************i2c fields****************/
void i2c_start(void)
{
	scl=1;
	sda=1;
	scl=1;
	sda=0;
}
void i2c_stop(void)
{
	sda=0;
	scl=0;
	sda=1;
	scl=1;
}
u8 i2c_ack(void)
{
	scl=-0;
	sda=1;
	scl=1;
	/* master will wait for slave acknowledgeme 3.4 u sec*/ 
	__nop__();
	__nop__();
	__nop__();
	__nop__();
	if(sda==0)
		return SUCCESS;
	else
		return ERROR;
}
 void i2c_noack(void)
 {
	 scl=0;
	 sda=1;
	 scl=1;
 }
 void i2c_writef(u8 Data)
 {
	 s8 i;
	 for(i=7;i>=0;i--)
	 {
		 sda=0;
		 sda=((Data>>i)&1)?1:0;
		 scl=1;
	 }
 }
 u8 i2c_readf(void)
 {
	 s8 i;
	 u8 temp=0x0;
	 for(i=7;i>=0;i--)
	 {
		 scl=1;
		 if(sda==1)
			 temp|=1<<i;
		 scl=0;
	 }
	 
 }
 
 /********************i2c frames*****************************/
 void i2c_write(u8 sa,u8 mr, u8 d)
 {
	 i2c_start();
	 i2c_writef(sa);
	 i2c_ack();
	 i2c_writef(mr);
	 i2c_ack();
	 i2c_writef(d);
	 i2c_ack();
	 i2c_stop();
 }
 
 u8 i2c_read(u8 sa,u8 mr)
 {
	 u8 temp;
	 i2c_start();
	 i2c_writef(sa);
	 i2c_ack();
	 i2c_writef(mr);
	 i2c_ack();
	 i2c_start();
	 i2c_writef(sa|1);   //write sa with read option
	 i2c_ack;
	 temp=i2c_readf();
	 i2c_noack();
	 i2c_stop();
	 return temp;
 }
 
	 