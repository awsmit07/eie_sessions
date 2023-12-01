/*!*********************************************************************************************************************
@file user_app1.c
@brief User's tasks / applications are written here.  This description
should be replaced by something specific to the task.

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------------------------------
GLOBALS
- NONE

CONSTANTS
- NONE

TYPES
- NONE

PUBLIC FUNCTIONS
- NONE

PROTECTED FUNCTIONS
- void UserApp1Initialize(void)
- void UserApp1RunActiveState(void)


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_<type>UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                          /*!< @brief Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemTime1ms;                   /*!< @brief From main.c */
extern volatile u32 G_u32SystemTime1s;                    /*!< @brief From main.c */
extern volatile u32 G_u32SystemFlags;                     /*!< @brief From main.c */
extern volatile u32 G_u32ApplicationFlags;                /*!< @brief From main.c */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_<type>" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_pfStateMachine;               /*!< @brief The state machine function pointer */
//static u32 UserApp1_u32Timeout;                           /*!< @brief Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */
/*--------------------------------------------------------------------------------------------------------------------*/
static void cycleLEDs(void);
/*!--------------------------------------------------------------------------------------------------------------------
@fn void UserApp1Initialize(void)

@brief
Initializes the State Machine and its variables.

Should only be called once in main init section.

Requires:
- NONE

Promises:
- NONE

*/
void UserApp1Initialize(void)
{
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_pfStateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_pfStateMachine = UserApp1SM_Error;
  }
  LedOff(LCD_RED);
  LedOff(LCD_GREEN);
  LedOff(LCD_BLUE);
} /* end UserApp1Initialize() */


/*!----------------------------------------------------------------------------------------------------------------------
@fn void UserApp1RunActiveState(void)

@brief Selects and runs one iteration of the current state in the state machine.

All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
- State machine function pointer points at current state

Promises:
- Calls the function to pointed by the state machine function pointer

*/
void UserApp1RunActiveState(void)
{
  UserApp1_pfStateMachine();

} /* end UserApp1RunActiveState */


/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------------*/
/* What does this state do? */
static void UserApp1SM_Idle(void)
{
  debug_printf("Hello World %d!\n", 1);
  if(IsButtonPressed(BUTTON0) && G_u32SystemTime1ms % 10 < 5)
  {
    PWMAudioSetFrequency(BUZZER1, 200);
    PWMAudioOn(BUZZER1);
  }
  else
  {
    PWMAudioOff(BUZZER1);
  }
  if(IsButtonPressed(BUTTON1) && G_u32SystemTime1ms % 10 >= 5)
  {
    PWMAudioSetFrequency(BUZZER1, 253);
    PWMAudioOn(BUZZER1);
  }
  else
  {
    PWMAudioOff(BUZZER1);
  }
  if (IsButtonPressed(BUTTON2) && G_u32SystemTime1ms % 10 < 5)
  {
    PWMAudioSetFrequency(BUZZER2, 300);
    PWMAudioOn(BUZZER2);
  }
  else
  {
    PWMAudioOff(BUZZER2);
  }
  if (IsButtonPressed(BUTTON3) && G_u32SystemTime1ms % 10 >= 5)
  {
    PWMAudioSetFrequency(BUZZER2, 400);
    PWMAudioOn(BUZZER2);
  }
  else
  {
    PWMAudioOff(BUZZER2);
  }

  static u8 counter[3] = {0, 0, 0};
  static LedNameType led = LCD_RED;
  static bool increasing = TRUE;
  if(G_u32SystemTime1ms % 200 == 0)
  {
    if(increasing)
    {
      LedPWM(led, counter[led-LCD_RED]);

      if(counter[led-LCD_RED] == 20)
      {
        if(led == LCD_BLUE)
        {
          increasing = FALSE;
          led = LCD_RED;
        }
        else
        {
          led++;
        }
      }
      else
      {
        counter[led-LCD_RED]++;
      }
    }
    else
    {
      LedPWM(led, counter[led-LCD_RED]);

      if(counter[led-LCD_RED] == 0)
      {
        if(led == LCD_BLUE)
        {
          increasing = TRUE;
          led = LCD_RED;
        }
        else
        {
          led++;
        }
      }
      else
      {
        counter[led-LCD_RED]--;
      }
    }
  }
} /* end UserApp1SM_Idle() */

static void cycleLEDs(void)
{
  static u8 led_counter = 0;

  switch (led_counter % 8)
  {
  case WHITE:
    LedOn(WHITE);
    LedOff(RED);
    break;
  case PURPLE:
    LedOn(PURPLE);
    LedOff(WHITE);
    break;
  case BLUE:
    LedOn(BLUE);
    LedOff(PURPLE);
    break;
  case CYAN:
    LedOn(CYAN);
    LedOff(BLUE);
    break;
  case GREEN:
    LedOn(GREEN);
    LedOff(CYAN);
    break;
  case YELLOW:
    LedOn(YELLOW);
    LedOff(GREEN);
    break;
  case ORANGE:
    LedOn(ORANGE);
    LedOff(YELLOW);
    break;
  case RED:
    LedOn(RED);
    LedOff(ORANGE);
    break;
  }
    led_counter++;

}

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)
{

} /* end UserApp1SM_Error() */




/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
