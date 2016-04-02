#ifndef TIMER_H_
#define TIMER_H_

/*****************************************************************************
 * File Name : timer.h 
 *
 * Brief	 : Timer register declaration 
 *
 * Copyright (C) 2009 -2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
******************************************************************************/

#define CPU_TIM0_CTRL ((ioport volatile unsigned*)0x1810)
#define CPU_TIM0_PLWR ((ioport volatile unsigned*)0x1812)
#define CPU_TIM0_PHWR ((ioport volatile unsigned*)0x1813)
#define CPU_TIM0_CLWR ((ioport volatile unsigned*)0x1814)
#define CPU_TIM0_CHWR ((ioport volatile unsigned*)0x1815)
#define CPU_TIM0_IER ((ioport volatile unsigned*)0x1816)
#define CPU_TIMINT_AGGR ((ioport volatile unsigned*)0x1c14)
#define CPU_PRCR ((ioport volatile unsigned*)0x1c05)


void ECG_Timer_Init(void);	   // function to Initialize the timer



#endif /*TIMER_H_*/
