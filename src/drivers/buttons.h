/*!**********************************************************************************************************************
@file buttons.h
@brief Header file for buttons.c
***********************************************************************************************************************/

#ifndef __BUTTONS_H
#define __BUTTONS_H

// #include "config.h"
#include "typedefs.h"

#ifdef EIE_ASCII
  #include "eief1-pcb-01.h"
#elif defined EIE_DOT_MATRIX
  #include "mpgl2-ehdw-01.h"
  #include "mpgl2-ehdw-02.h"
#else
  #error "No board defined!"
#endif

/***********************************************************************************************************************
Type Definitions
***********************************************************************************************************************/

/*!
@enum ButtonStateType
@brief Self-documenting button state type */
typedef enum {RELEASED, PRESSED} ButtonStateType;


/*!
@struct ButtonStatusType
@brief Required parameters for the task to track what each button is doing.
*/
typedef struct
{
  bool bDebounceActive;                   /*!< @brief TRUE by ISR if a button interrupt occurs */
  bool bNewPressFlag;                     /*!< @brief TRUE if the press has not been acknowledged */
  ButtonStateType eCurrentState;          /*!< @brief Current state of the button */
  ButtonStateType eNewState;              /*!< @brief New state of the button */
  u32 u32DebounceTimeStart;               /*!< @brief System time loaded by ISR when button interrupt occurs */
  u32 u32TimeStamp;                       /*!< @brief System time when the button was pressed */
}ButtonStatusType;


/***********************************************************************************************************************
Function Declarations
***********************************************************************************************************************/

/*------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */
/*--------------------------------------------------------------------------------------------------------------------*/
bool IsButtonPressed(ButtonNameType eButton_);
bool WasButtonPressed(ButtonNameType eButton_);
void ButtonAcknowledge(ButtonNameType eButton_);
bool IsButtonHeld(ButtonNameType eButton_, u32 u32ButtonHeldTime_);


/*------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */
/*--------------------------------------------------------------------------------------------------------------------*/
void ButtonInitialize(void);
void ButtonRunActiveState(void);
void ButtonStartDebounce(u32 u32BitPosition_, PortOffsetType ePort_);


/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */
/*--------------------------------------------------------------------------------------------------------------------*/






/***********************************************************************************************************************
Constants / Definitions
***********************************************************************************************************************/
#define U32_DEBOUNCE_TIME       (u32)10       /*! @brief Time in ms for button debouncing */



#endif /* __BUTTONS_H */

/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
