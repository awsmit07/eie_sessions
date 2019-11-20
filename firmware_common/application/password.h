#ifndef PASSWORD
#define PASSWORD

#include <string.h>

typedef enum
{
    UNLOCKED = 1,
    LOCKED = 0
} PASSWORD_STATUS;

void main_pass(void);

void pass_init(void);

//void write_lcd(const char * message);
///*
// * Writes the message 'message' to the LCD display 
// */

void set_status_led(char status);
//
//int digits_to_num(const int *digs);
//
//void lock(int *digits);
//
//int set_password(int new_password);



//int check_password(int password, int entered value);

#endif