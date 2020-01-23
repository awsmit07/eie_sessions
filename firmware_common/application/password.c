
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
    u8 text[7];

    set_status_led(status);

    if(status == UNLOCKED)
    {
        sprintf(text, "%d%d%d%dSL", digits[3], digits[2], digits[1], digits[0]);
        cursor_max = 6;
    }
    else if(status == LOCKED)
    {
        sprintf(text, "%d%d%d%dE", digits[3], digits[2], digits[1], digits[0]);
        cursor_max = 5;
    }

    cursor_pos = move_cursor(cursor_pos, cursor_max);

    // Check if cursor is pointing to a number or a key
    if(cursor_pos < 4)
    {
        change_digit(digits, cursor_pos);
    }
    else if(status == UNLOCKED)
    {
        if(cursor_pos == 4 && (IsButtonPressed(BUTTON1) || IsButtonPressed(BUTTON2)))
        {
            password = digits_to_num(digits);
            //u8 * debug;
            //sprintf(debug, "password %d\n", password);
            //DebugPrintf(debug);
        }
          
        if(cursor_pos == 5 && (IsButtonPressed(BUTTON1) || IsButtonPressed(BUTTON2)))
        {
            status = LOCKED;
            LcdCommand(LCD_CLEAR_CMD);
            digits[0] = 0;
            digits[1] = 0;
            digits[2] = 0;
            digits[3] = 0;
            //DebugPrintf("Locked\n");
        }
    }
    else if(status == LOCKED)
    {
        if(IsButtonPressed(BUTTON1) || IsButtonPressed(BUTTON2))
        {
            int test_value = digits_to_num(digits);
            status = check_password(password, test_value);
        }
    }
    write_lcd(text, cursor_pos);
    //draw_cursor(cursor_pos);
    
}

int move_cursor(int cursor_pos, int cursor_max)
{
    static bool button_left_held = FALSE;
    static bool button_right_held = FALSE;

    static bool dec_flag = FALSE;
    static bool inc_flag = FALSE;
    
    
    //DebugPrintf("Test");
    // Detect right and left button presses.
    if(IsButtonPressed(BUTTON0) && !button_left_held)
    {
        button_left_held = TRUE;
        dec_flag = TRUE;
        //DebugPrintf("Button 0 pressed");
    }
    else if(IsButtonPressed(BUTTON3) && !button_right_held)
    {
        button_right_held = TRUE;
        inc_flag = TRUE;
        //DebugPrintf("Button 3 pressed");
    }


    // Detect release of buttons
    if(!IsButtonPressed(BUTTON0))
    {
        button_left_held = FALSE;
    }
    if(!IsButtonPressed(BUTTON3))
    {
        button_right_held = FALSE;
    }

    // Increment Cursor if applicable
    if(inc_flag)
    {
        cursor_pos = (cursor_pos + 1) % cursor_max;
        inc_flag = FALSE;
    }
    // Decrement Cursor if applicable
    if(dec_flag)
    {
        // Check if the cursor position is currently 0
        cursor_pos = !cursor_pos ? cursor_max: cursor_pos;
        // Decrement cursor postion
        cursor_pos--;
        dec_flag = FALSE;
    }
    //u8 debug[3];
    //sprintf(debug, "%d\n\r", cursor_pos);
    //DebugPrintf(debug);
    return cursor_pos;
}

void change_digit(int *digits, int cursor_pos)
{
    static bool button_down_held = FALSE;
    static bool button_up_held = FALSE;

    bool dec_flag = FALSE;
    bool inc_flag = FALSE;

    // Detect right and left button presses.
    if(IsButtonPressed(BUTTON1) && !button_down_held)
    {
        button_down_held = TRUE;
        dec_flag = TRUE;
        DebugPrintf("Button 1 pressed");
    }
    if(IsButtonPressed(BUTTON2) && !button_up_held)
    {
        button_up_held = TRUE;
        inc_flag = TRUE;
        DebugPrintf("Button 2 pressed");
    }


    // Detect release of buttons
    if(!IsButtonPressed(BUTTON1) && button_down_held)
    {
        button_down_held = FALSE;
    }
    if(!IsButtonPressed(BUTTON2) && button_up_held)
    {
        button_up_held = FALSE;
    }

    // Increment Cursor if applicable
    if(inc_flag)
    {
        digits[3 - cursor_pos] = (digits[3 - cursor_pos] + 1) % 10;
        inc_flag = FALSE;
    }
    // Decrement Cursor if applicable
    if(dec_flag)
    {
        // Check if the cursor position is currently 0
        digits[3 - cursor_pos] = !digits[3 - cursor_pos] ? 10: digits[3 - cursor_pos];
        // Decrement cursor postion
        digits[3 - cursor_pos]--;
        dec_flag = FALSE;
    }
}

int check_password(int password, int entered_value)
{
    return (password == entered_value)? 1: 0;
}


void write_lcd(u8 * message, int cursor_pos)
{
    static u16 lcd_count = 0;
    static u8 past_cursor = 0;
    
    lcd_count++;
    if(lcd_count == 100)
    {
        LcdMessage(LINE1_START_ADDR, message);
        if(past_cursor != cursor_pos)
        {
            LcdCommand(LCD_CLEAR_CMD);
            LcdMessage(LINE2_START_ADDR + cursor_pos, "^");
            past_cursor = cursor_pos;
        }
        LcdCommand(LCD_HOME_CMD);
        lcd_count = 0;
        //DebugPrintf("LCD Display update");
    }
    
}

void pass_init()
{
    LedOff(LCD_RED);
    LedOff(LCD_GREEN);
    LedOff(LCD_BLUE);
    LcdCommand(LCD_CLEAR_CMD);
    LcdMessage(LINE2_START_ADDR, "^");
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
