;/*****************************************************************************
; * @file:    startup_SAM3N.s
; * @purpose: CMSIS Cortex-M3 Core Device Startup File
; *           for the Atmel SAM3N Device Series
; * @version: V1.20
; * @date:    14. December 2015
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; * Copyright (C) 2010-2013 ARM Limited. All rights reserved.
; * ARM Limited (ARM) is supplying this software for use with Cortex-M3
; * processor based microcontrollers.  This file can be freely distributed
; * within development tools that are supporting such ARM based processors.
; *
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; *****************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ;  0: Top of Stack
                DCD     Reset_Handler             ;  1: Reset Handler
                DCD     NMI_Handler               ;  2: NMI Handler
                DCD     HardFault_Handler         ;  3: Hard Fault Handler
                DCD     MemManage_Handler         ;  4: MPU Fault Handler
                DCD     BusFault_Handler          ;  5: Bus Fault Handler
                DCD     UsageFault_Handler        ;  6: Usage Fault Handler
                DCD     0                         ;  7: Reserved
                DCD     0                         ;  8: Reserved
                DCD     0                         ;  9: Reserved
                DCD     0                         ; 10: Reserved
                DCD     SVC_Handler               ; 11: SVCall Handler
                DCD     DebugMon_Handler          ; 12: Debug Monitor Handler
                DCD     0                         ; 13: Reserved
                DCD     PendSV_Handler            ; 14: PendSV Handler
                DCD     SysTick_Handler           ; 15: SysTick Handler

                ; External Interrupts
                DCD     SUPC_IRQHandler           ;  0: Supply Controller (SUPC)
                DCD     RSTC_IRQHandler           ;  1: Reset Controller (RSTC)
                DCD     RTC_IRQHandler            ;  2: Real Time Clock (RTC)
                DCD     RTT_IRQHandler            ;  3: Real Time Timer (RTT)
                DCD     WDT_IRQHandler            ;  4: Watchdog Timer (WDT)
                DCD     PMC_IRQHandler            ;  5: Power Management Controller (PMC)
                DCD     EFC_IRQHandler            ;  6: Enhanced Flash Controller (EFC)
                DCD     0                         ;  7: Reserved
                DCD     UART0_IRQHandler          ;  8: UART 0 (UART0)
                DCD     UART1_IRQHandler          ;  9: UART 1 (UART1)
                DCD     0                         ; 10: Reserved
                DCD     PIOA_IRQHandler           ; 11: Parallel I/O Controller A (PIOA)
                DCD     PIOB_IRQHandler           ; 12: Parallel I/O Controller B (PIOB)
                DCD     PIOC_IRQHandler           ; 13: Parallel I/O Controller C (PIOC)
                DCD     USART0_IRQHandler         ; 14: USART 0 (USART0)
                DCD     USART1_IRQHandler         ; 15: USART 1 (USART1)
                DCD     0                         ; 16: Reserved
                DCD     0                         ; 17: Reserved
                DCD     0                         ; 18: Reserved
                DCD     TWI0_IRQHandler           ; 19: Two Wire Interface 0 (TWI0)
                DCD     TWI1_IRQHandler           ; 20: Two Wire Interface 1 (TWI1)
                DCD     SPI_IRQHandler            ; 21: Serial Peripheral Interface (SPI)
                DCD     0                         ; 22: Reserved
                DCD     TC0_IRQHandler            ; 23: Timer/Counter 0 (TC0)
                DCD     TC1_IRQHandler            ; 24: Timer/Counter 1 (TC1)
                DCD     TC2_IRQHandler            ; 25: Timer/Counter 2 (TC2)
                DCD     TC3_IRQHandler            ; 26: Timer/Counter 3 (TC3)
                DCD     TC4_IRQHandler            ; 27: Timer/Counter 4 (TC4)
                DCD     TC5_IRQHandler            ; 28: Timer/Counter 5 (TC5)
                DCD     ADC_IRQHandler            ; 29: Analog To Digital Converter (ADC)
                DCD     DACC_IRQHandler           ; 30: Digital To Analog Converter (DACC)
                DCD     PWM_IRQHandler            ; 31: Pulse Width Modulation (PWM)

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  SUPC_IRQHandler           [WEAK]
                EXPORT  RSTC_IRQHandler           [WEAK]
                EXPORT  RTC_IRQHandler            [WEAK]
                EXPORT  RTT_IRQHandler            [WEAK]
                EXPORT  WDT_IRQHandler            [WEAK]
                EXPORT  PMC_IRQHandler            [WEAK]
                EXPORT  EFC_IRQHandler            [WEAK]
                EXPORT  UART0_IRQHandler          [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
                EXPORT  PIOA_IRQHandler           [WEAK]
                EXPORT  PIOB_IRQHandler           [WEAK]
                EXPORT  PIOC_IRQHandler           [WEAK]
                EXPORT  USART0_IRQHandler         [WEAK]
                EXPORT  USART1_IRQHandler         [WEAK]
                EXPORT  TWI0_IRQHandler           [WEAK]
                EXPORT  TWI1_IRQHandler           [WEAK]
                EXPORT  SPI_IRQHandler            [WEAK]
                EXPORT  TC0_IRQHandler            [WEAK]
                EXPORT  TC1_IRQHandler            [WEAK]
                EXPORT  TC2_IRQHandler            [WEAK]
                EXPORT  TC3_IRQHandler            [WEAK]
                EXPORT  TC4_IRQHandler            [WEAK]
                EXPORT  TC5_IRQHandler            [WEAK]
                EXPORT  ADC_IRQHandler            [WEAK]
                EXPORT  DACC_IRQHandler           [WEAK]
                EXPORT  PWM_IRQHandler            [WEAK]

SUPC_IRQHandler
RSTC_IRQHandler
RTC_IRQHandler
RTT_IRQHandler
WDT_IRQHandler
PMC_IRQHandler
EFC_IRQHandler
UART0_IRQHandler
UART1_IRQHandler
PIOA_IRQHandler
PIOB_IRQHandler
PIOC_IRQHandler
USART0_IRQHandler
USART1_IRQHandler
TWI0_IRQHandler
TWI1_IRQHandler
SPI_IRQHandler
TC0_IRQHandler
TC1_IRQHandler
TC2_IRQHandler
TC3_IRQHandler
TC4_IRQHandler
TC5_IRQHandler
ADC_IRQHandler
DACC_IRQHandler
PWM_IRQHandler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
