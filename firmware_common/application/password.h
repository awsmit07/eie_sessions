#ifndef PASSWORD
#define PASSWORD

#include <string.h>
#include <stdio.h>
typedef enum
{
    LOCKED = 0,
    UNLOCKED = 1
    
} PASSWORD_STATUS;

void main_pass(void);

void pass_init(void);

void write_lcd(u8 * message, int cursor_pos);
/*
* Writes the message 'message' to the LCD display
*/
void draw_cursor(int cursor_pos);

void set_status_led(char status);

int digits_to_num(const int *digs);

void lock(int *digits);

int set_password(int new_password);

int check_password(int password, int entered_value);

int move_cursor(int cursor_pos, int cursor_max);

void change_digit(int *digits, int cursor_pos);
#endif
