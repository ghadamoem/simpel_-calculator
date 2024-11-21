#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_config.h"

#define CURSOR_ON_DISPLAY_ON 0x0E
#define ENTRY_MODE 0x06
#define RETURN_MODE 0x02
#define CLR_SCREEN 0x01

#if defined four_bits_mode
    #define EN 0
    #define RS 1
    #define RW 2
    #define FOUR_BITS 0x28
#elif defined eight_bits_mode
    #define EN 0
    #define RS 1
    #define RW 2
    #define EIGHT_BITS 0x38
#endif

void LCD_Initial(void);
static void send_falling_edge(void);
void LCD_Send_Cmd( char cmd);
void LCD_Send_data(unsigned char data);
void LCD_Send_String(unsigned char *data);
void LCD_CLR_Screen(void);
void LCD_Move_Cursor(unsigned char row, unsigned char column);
unsigned char LCD_Get_Cursor_Position();
 void LCD_Send_Integer(int  num);
#endif /* LCD_H_ */

