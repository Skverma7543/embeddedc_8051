#ifndef __HEADER__
#define __HEADER__
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

/*******cgram pages******************/
#define PAGE0 0
#define PAGE1 1
#define PAGE2 2
#define PAGE3 3
#define PAGE4 4
#define PAGE5 5
#define PAGE6 6
#define PAGE7 7


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
void sdelay_ms(u32);
void delay_ms(u32);
void delay_1ms(void);


/**************lcd lm016l driver prototype******/
void lcd8_init(void);
void lcd8_data(u8);
void lcd8_cmd(u8);
void lcd8_string(u8 *);
void lcd4_init(void);
void lcd4_data(u8);
void lcd4_cmd(u8);
void lcd4_string(u8 *);
void cgram_init(void);

/*************keypad*******************/
u8 keyscan_cal(void);
u8 keyscan_phone(void);

/***********uart driver ***************/
void uart_init(u32);
u8 uart_rx(void);
void uart_tx(u8);
void uart_tx_string(u8 *);

/***************interrupt*******************/
void enable_ex0_interrupt();
void enable_ex1_interrupt();
void enable_ex_interrupt();
void enable_timer0_interrupt();
void enable_timer1_interrupt();



extern void fun();
extern void load(u8);
extern void floor_menu0();
extern void floor_menu1();
extern void floor_menu2();
extern void floor_menu3();
extern void main_menu();
extern void load(u8);
/**************************load*************************/
extern void load1();
extern void load2();
extern void load3();
extern void load4();
extern void load5();
extern void load6();
extern void load7();
extern void load8();

#endif