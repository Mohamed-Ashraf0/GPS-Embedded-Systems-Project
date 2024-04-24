#ifndef LCD_H_
#define LCD_H_
#include<stdint.h>
#define PA7 7
#define PA6 6
#define PA5 5
#define PB4 4
#define PE5 5
#define PE4 4
#define PB1 1
#define PB0 0
void Print_Data(uint8_t data);
void LCD_Data (uint8_t data);
void LCD_CMD (uint8_t data);
void LCD_String_First_line (uint8_t* str , uint8_t len);
void LCD_String_Second_line (uint8_t* str , uint8_t len);
void LCD_Init (void);

#endif

