#ifndef ECGSYSTEMFUNCTIONS_H_
#define ECGSYSTEMFUNCTIONS_H_

/*****************************************************************************
 * File Name : ECGSystemFunctions.h 
 *
 * Description: The file defines all the functions used in the ECGSystemFunctions.c
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


//#ifndef _ECGSYSTEMALGORITHMS_H
//#define _ECGSYSTEMALGORITHMS_H

#include<stdio.h>
#include<math.h>
#include<file.h>
#include <stdio.h>
//#include "std.h"
#include "psp_common.h"
#include "dda_spi.h"
#include "timer.h"
#include "llc_spi.h"
#include "ADS1258.h"
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
#include "dda_uart.h"


#define LCDDECIMATOR 2
#define UARTDECIMATOR 2
#define BYTEMASK 0x00000FFF //was 0ff
		

/* function to read channel data*/	 		
//void ADS1258_Read_ChannelData(Uint8*,Uint8*);
void ADS1258_Read_ChannelData(Uint16*,Uint16*);
/*	function give wait cycles*/
void wait(Uint32 count);
/* function to convert the hex values to signed int*/
double CurrInp_Voltage(Uint32);
/* convert the 4 byte channel data to 24bit sample*/
//Int32 ECG_GetCurrAqsnSample(Uint8*); //jb
Int32 ECG_GetCurrAqsnSample(Uint16*);
/* process the current sample*/
void ECG_ProcessCurrSample(Uint32,Uint8,Uint32, Uint32);
/* plot the current sample in LCD*/
//void ECG_LCDPlotCurrSample(Uint32,Uint32);
/* function to get the sample from structure Lead_Info_Buffer*/
static void QRS_call_process_buffer(void);
/*function to calculate the derivatives and fill in process buffer B4*/	
static void QRS_process_buffer(void);
/* function to find the first maxima in a window of defined samples*/
static Uint32 QRS_maxima(void);
/*function to calculate HR when B4 is filled with 2700 samples */
static void QRS_Heart_Rate_Calc(void);
/* function which is called by the main thread at filling of every(N/3) */
/* samples in Lead_Info_Buffer                                          */
void QRS_Algorithm_Interface(Uint32);
/* Return the current calculated heart rate*/
Uint32 QRS_Get_Heart_Rate( void );
Uint32 QRS_main(void);
/* Transmission of the curret set of sample thru UART*/
void ECG_UARTTxCurrSamples();
/*Check Lead Off Status for all electrodes for every 2s*/
void QRS_LeadOffStatus_Check(void);

static void QRS_check_sample_crossing_threshold( float );
//#endif


#endif /*ECGSYSTEMFUNCTIONS_H_*/
