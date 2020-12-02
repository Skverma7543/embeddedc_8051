#ifndef __HEADER__
#define __HEADER__
#include<reg51.h>
/***************DATA TYPES*********************/
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;
typedef double d32;

/****************PORT*****************/
#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3

/****************PINS******************/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*****************set/clear***************/
#define SET 1
#define CLEAR 0
#define PRESSED 0 //for active low switch
#define SUCCESS 0
#define ERROR (-1)

/**********io driver function prototypes************/
s8 io_write(u8,u8,u8);  //write in a pin 
s8 io_read(u8,u8);     //read a pin
s8 io_set(u8,u8);    //set a pin 
s8 io_clr(u8,u8);    // clear a pin
s8 write_port(u8,u8);
s8 read_port(u8);

/***************delay functions prototype***/
void delay_ms(u32);