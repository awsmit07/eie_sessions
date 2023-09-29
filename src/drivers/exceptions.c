/*!
@file exceptions.c
@brief Atmel-supplied source file for all default exception handlers.

These definitions are declared "extern __attribute__(( weak ))" so any re-definitions will take
their place when the code is built.
*/

/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/*
** This file contains the default exception handlers
** and exception table.
*/

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "configuration.h"

//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Exception Handlers
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Default irq handler
//------------------------------------------------------------------------------
void IrqHandlerNotUsed(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Provide extern __attribute__(( weak )) aliases for each Exception handler to the IrqHandlerNotUsed.
// As they are extern __attribute__(( weak )) aliases, any function with the same name will override
// this definition.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// System interrupt
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void NMI_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void HardFault_Handler(void)
{
  while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void MemManage_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void BusFault_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void UsageFault_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void SVC_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void DebugMon_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void PendSV_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// for Cortex M3
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void SysTick_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// External interrupt
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// for SAM7/9
//------------------------------------------------------------------------------
void SYS_IrqHandler( void )
{
    while(1);
}

//------------------------------------------------------------------------------
// SUPPLY CONTROLLER
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void SUPC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// RESET CONTROLLER
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void RSTC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// REAL TIME CLOCK
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void RTC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// REAL TIME TIMER
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void RTT_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// WATCHDOG TIMER
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void WDT_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// PMC
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void PMC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// EFC0
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void EFC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// EFC1
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void EFC1_IrqHandler(void)
{
    while(1);
}
//------------------------------------------------------------------------------
// DBGU
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void DBGU_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// HSMC4
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void HSMC4_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Parallel IO Controller A
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void PIOA_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Parallel IO Controller B
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void PIOB_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Parallel IO Controller C
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void PIOC_IrqHandler(void)
{
    while(1);
}


//------------------------------------------------------------------------------
// USART 0
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void USART0_IrqHandler(void)
{
    while(1);
}


//------------------------------------------------------------------------------
// USART 1
//------------------------------------------------------------------------------
#if 0
extern __attribute__(( weak )) void USART1_IrqHandler(void)
{
    while(1);
}
#endif

//------------------------------------------------------------------------------
// USART 2
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void USART2_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// USART 3
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void USART3_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Multimedia Card Interface
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void MCI0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// TWI 0
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void TWI0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// TWI 1
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void TWI1_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Serial Peripheral Interface 0
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void SPI0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Serial Synchronous Controller 0
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void SSC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Timer Counter 0
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void TC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Timer Counter 1
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void TC1_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Timer Counter 2
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void TC2_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// PWM Controller
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void PWM_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// ADC controller0
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void ADCC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// ADC controller1
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void ADCC1_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// HDMA
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void HDMA_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// USB Device High Speed UDP_HS
//------------------------------------------------------------------------------
extern __attribute__(( weak )) void UDPD_IrqHandler(void)
{
    while(1);
}