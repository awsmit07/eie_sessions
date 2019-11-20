#include "password.h"
#include "configuration.h"

void main_pass()
{
    // Create a holder for the digits on the LCD
    static int digits[4] = {0, 0, 0, 0};
    // Create a password initially set to 0
    static int password = 0;
    
    // Initially put the device into a unlocked state 
    char static status = UNLOCKED;
    
    set_status_led(status);
    
    if(status == UNLOCKED)
    {
        
    }
    else if(status == LOCKED)
    {
        
    }
}
    
void pass_init()
{
    LedOff(LCD_RED);
    LedOff(LCD_GREEN);
    LedOff(LCD_BLUE);
}


void set_status_led(char status)
{
    if(status)
    {
        LedOn(LCD_GREEN);
        LedOff(LCD_RED);
    }
    else
    {
        LedOn(LCD_RED);
        LedOff(LCD_GREEN);
    }
}