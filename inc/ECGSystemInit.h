#ifndef ECGSYSTEMINIT_H_
#define ECGSYSTEMINIT_H_

/*****************************************************************************
 * File Name : ECGSystemInit.h                                                    
 *  Brief	 : Definitions used for ECGSystemInit, and function prototypes for all 
 *  		   module Initialization         
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




//#ifndef _ECGSYSTEMINIT_H
//#define _ECGSYSTEMINIT_H

#include<stdio.h>
#include<math.h>
#include<file.h>
#include <stdio.h>
//#include <std.h>
#include "psp_common.h"
#include "dda_spi.h"
#include "timer.h"
#include "llc_spi.h"
#include "ADS1258.h"
#include "ADS1220.h"
//#include "cpu_power.h"
#include "csl_ioport.h"
#include "corazon.h"
#include "cslr.h"
//#include "lcd.h"
#include "I2C.h"
//#include "LCD_FontTable.h"
#include "sar.h"
#include "ECGGlobals.h"
#include "typedef.h"
#include "dda_dma.h"
#include "dda_uart.h"
//#include "ezdsp5535.h" //jb added 


#define GPIO10 10
#define GPIO11 11

/* function to initialize peripherals*/
ECG_Status ECG_C5505Init();	
/* function to initialize ADS1258*/	 
ECG_Status ECG_ADS1258_INIT();
/*function to initialize SPI*/
ECG_Status ECG_SPI_INIT();
/* function to Initialize I2C*/	 
ECG_Status ECG_I2C_INIT();
/* function to Initialize SAR*/    
ECG_Status ECG_SAR_INIT();  
/* function to Initialize DMA*/  
ECG_Status ECG_DMA_INIT();
/* function to init Leadoff detection*/    
ECG_Status ECG_LEADOFF_DETECT_INIT(); 
/* function to Initialize LCD*/
//void ECG_LCD_INIT(void);
/* function to INIT GPIO*/			 
void ECG_GPIO_INIT();
/* function to Initialize UART*/
void ECG_UART_INIT(void);
/* function to Init FE*/				
ECG_Status ECG_FE_INIT();
/* function to detect FE*/			
Uint8 FE_DETECT();					
/* Function to Initialize timer*/
void ECG_TIMER_INIT();
/*	function give wait cycles*/
extern void EZDSP5535_wait(Uint32);

//#endif


#endif /*ECGSYSTEMINIT_H_*/
