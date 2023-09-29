/*!
@file exceptions.h
@brief Atmel-supplied header file for exceptions.c
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
//         Types
//------------------------------------------------------------------------------

/*!
@enum IntFunc
@brief Function pointer defintion for interrupt handler functions.
*/
typedef void( *IntFunc )( void );

/// __attribute__(( weak )) attribute
    // #define __attribute__(( weak )) ____attribute__(( weak ))

//------------------------------------------------------------------------------
//         Global functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Exception Handlers
//------------------------------------------------------------------------------

extern __attribute__(( weak )) void NMI_Handler( void );
extern __attribute__(( weak )) void HardFault_Handler( void );
extern __attribute__(( weak )) void MemManage_Handler( void );
extern __attribute__(( weak )) void BusFault_Handler( void );
extern __attribute__(( weak )) void UsageFault_Handler( void );
extern __attribute__(( weak )) void SVC_Handler( void );
extern __attribute__(( weak )) void DebugMon_Handler( void );
extern __attribute__(( weak )) void PendSV_Handler( void );
extern __attribute__(( weak )) void SysTick_Handler( void );
void IrqHandlerNotUsed(void);


// System Controller
extern void SYS_IrqHandler(void);
// SUPPLY CONTROLLER
extern __attribute__(( weak )) void SUPC_IrqHandler(void);
// RESET CONTROLLER
extern __attribute__(( weak )) void RSTC_IrqHandler(void);
// REAL TIME CLOCK
extern __attribute__(( weak )) void RTC_IrqHandler(void);
// REAL TIME TIMER
extern __attribute__(( weak )) void RTT_IrqHandler(void);
// WATCHDOG TIMER
extern __attribute__(( weak )) void WDT_IrqHandler(void);
// PMC
extern __attribute__(( weak )) void PMC_IrqHandler(void);
// EFC0
extern __attribute__(( weak )) void EFC0_IrqHandler(void);
// EFC1
extern __attribute__(( weak )) void EFC1_IrqHandler(void);
// DBGU
extern __attribute__(( weak )) void DBGU_IrqHandler(void);
// HSMC4
extern __attribute__(( weak )) void HSMC4_IrqHandler(void);
// Parallel IO Controller A
extern __attribute__(( weak )) void PIOA_IrqHandler(void);
// Parallel IO Controller B
extern __attribute__(( weak )) void PIOB_IrqHandler(void);
// Parallel IO Controller C
extern __attribute__(( weak )) void PIOC_IrqHandler(void);
// USART 0
extern __attribute__(( weak )) void USART0_IrqHandler(void);
// USART 1
extern __attribute__(( weak )) void USART1_IrqHandler(void);
// USART 2
extern __attribute__(( weak )) void USART2_IrqHandler(void);
// USART 3
extern __attribute__(( weak )) void USART3_IrqHandler(void);
// Multimedia Card Interface
extern __attribute__(( weak )) void MCI0_IrqHandler(void);
// TWI 0
extern __attribute__(( weak )) void TWI0_IrqHandler(void);
// TWI 1
extern __attribute__(( weak )) void TWI1_IrqHandler(void);
// Serial Peripheral Interface 0
extern __attribute__(( weak )) void SPI0_IrqHandler(void);
// Serial Synchronous Controller 0
extern __attribute__(( weak )) void SSC0_IrqHandler(void);
// Timer Counter 0
extern __attribute__(( weak )) void TC0_IrqHandler(void);
// Timer Counter 1
extern __attribute__(( weak )) void TC1_IrqHandler(void);
// Timer Counter 2
extern __attribute__(( weak )) void TC2_IrqHandler(void);
// PWM Controller
extern __attribute__(( weak )) void PWM_IrqHandler(void);
// ADC controller0
extern __attribute__(( weak )) void ADCC0_IrqHandler(void);
// ADC controller1
extern __attribute__(( weak )) void ADCC1_IrqHandler(void);
// HDMA
extern __attribute__(( weak )) void HDMA_IrqHandler(void);
// USB Device High Speed UDP_HS
extern __attribute__(( weak )) void UDPD_IrqHandler(void);

