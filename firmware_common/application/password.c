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

    static int cursor_pos = 0;
    int cursor_max;
    char *text;

    set_status_led(status);

    if(status == UNLOCKED)
    {
        text = sprintf("%04dSL", digits_to_num(digits));
        cursor_max = 6;
    }
    else if(status == LOCKED)
    {
        text = sprintf("%04dE", digits_to_num(digits));
        cursor_max = 5;
    }

    cursor_pos = move_cursor(cursor_pos, cursor_max);

    // Check if cursor is pointing to a number or a key
    if(cursor_pos < 4)
    {
        change_digit(digits, cursor_pos);
    }
}

int move_cursor(int cursor_pos, int cursor_max)
{
    static int button_left_held = 0;
    static int button_right_held = 0;

    int dec_flag = 0;
    int inc_flag = 0;

    // Detect right and left button presses.
    if(IsButtonPressed(BUTTON0) && !button_left_held)
    {
        button_left_held = 1;
        dec_flag = 1;
    }
    else if(IsButtonPressed(BUTTON3) && !button_right_held)
    {
        button_right_held = 1;
        inc_flag = 1;
    }


    // Detect release of buttons
    if(!IsButtonPressed(BUTTON0) && button_left_held)
    {
        button_left_held = 0;
    }
    if(!IsButtonPressed(BUTTON3) && button_right_held)
    {
        button_right_held = 0;
    }

    // Increment Cursor if applicable
    if(inc_flag)
    {
        cursor_pos = (cursor_pos + 1) % cursor_max;
        inc_flag = 0;
    }
    // Decrement Cursor if applicable
    if(dec_flag)
    {
        // Check if the cursor position is currently 0
        cursor_pos = !cursor_pos ? cursor_max: cursor_pos;
        // Decrement cursor postion
        cursor_pos--;
        dec_flag = 0;
    }

    return cursor_pos;
}

void change_digit(digits, cursor_pos)
{
    static int button_down_held = 0;
    static int button_up_held = 0;

    int dec_flag = 0;
    int inc_flag = 0;

    // Detect right and left button presses.
    if(IsButtonPressed(BUTTON1) && !button_down_held)
    {
        button_down_held = 1;
        dec_flag = 1;
    }
    else if(IsButtonPressed(BUTTON2) && !button_up_held)
    {
        button_up_held = 1;
        inc_flag = 1;
    }


    // Detect release of buttons
    if(!IsButtonPressed(BUTTON1) && button_down_held)
    {
        button_left_held = 0;
    }
    if(!IsButtonPressed(BUTTON2) && button_up_held)
    {
        button_right_held = 0;
    }

    // Increment Cursor if applicable
    if(inc_flag)
    {
        digits[cursor_pos] = (digits[cursor_pos] + 1) % 10;
        inc_flag = 0;
    }
    // Decrement Cursor if applicable
    if(dec_flag)
    {
        // Check if the cursor position is currently 0
        digits[cursor_pos] = !digits[cursor_pos] ? 10: digits[cursor_pos];
        // Decrement cursor postion
        cursor_pos--;
        dec_flag = 0
    }
}

int check_password(int password, int entered_value)
{
    return (password == entered_value)? 1: 0;
}

void draw_cursor(int cursor_pos)
{
    LCDCommand(LCD_ADDRESS_CMD | cursor_pos);
    LCDCommand(LCD_DISPLAY_CMD | LCD_DISPLAY_CURSOR);
}

void pass_init()
{
    LedOff(LCD_RED);
    LedOff(LCD_GREEN);
    LedOff(LCD_BLUE);
    LCDCommand(LCD_CLEAR_CMD);
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


int digits_to_num(const int *digs)
{
    int num = 0;
    for(int i = 3; i>=0; i--)
    {
        num = num * 10 + digs[i];
    }
    return num;
}
