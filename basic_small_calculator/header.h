/***********HEADER ******************/
#ifndef _header_
#define _header_
typedef int s16;
typedef char s8;
typedef unsigned int u16;
typedef unsigned char u8;
typedef unsigned long int u32;
typedef long int s32;
typedef float f32;



/******************defin *************************/
#define SET 1
#define CLEAR 0




/***********function proto type************/
/***********LED function*****************/
extern void io_write(u8 port_num,u8 pin_num,u8 val);
extern u8 io_read(u8 port_num,u8 pin_num);
/************delay*************************/
extern void delay_ms(u32 ms);

/************lcd8bit fuctions prototype***************/
extern void lcd8_init(void);
extern void lcd8_cmd(u8 );
extern void lcd8_data(u8 );
extern void lcd8_string(s8 *);

/************lcd8bit fuctions prototype***************/
extern void lcd4_init(void);
extern void lcd4_cmd(u8 );
extern void lcd4_data(u8 );
extern void lcd4_string(u8 *);

/*************keypad matrix**********************/
extern u8 keyscan_smallcal(void);
extern u8 * float_to_str(f32);

/***********cgram*****************************/
void cgram_init(void);

/*************uart**************************/
extern void uart_init(u16);
extern void uart_tx(u8);
extern u8 uart_rx(void);
extern void uart_tx_string(u8 *);

/***********T@C protocol*******************/
extern void i2c_start(void);
extern void i2c_stop(void);
extern void i2c_write(u8);
extern u8 i2c_read(void);
extern bit i2c_ack(void);
extern void i2c_noack(void);
//i2c frames
extern void i2c_byte_write_frame(u8,u8,u8);
extern u8 i2c_byte_read_frame(u8,u8);


#endif