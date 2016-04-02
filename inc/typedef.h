#ifndef TYPEDEF_H_
#define TYPEDEF_H_

/*****************************************************************************
 *  File Name : Typedef.h                                               
 *  Brief	  : The file holds all the typedefinitions used in ECG system
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



typedef int ECG_Status;						


typedef struct 					/* Global structure for ECG system*/
{
	Uint16 	ECG_LeadOff;			/* Current Leadoff Value*/
	Uint8 	FE_Status;				/* Current FE status*/
	Uint8 	KEY_PressStatus;		/* Current KeyPress Status*/
	Uint8 	ECG_HeartRate;			/* Current Heart Rate*/
	Uint8 	ECG_FreezeStatus;
	Uint8 	ECG_CurrentDisplayLead;		/* Current Display lead*/
}ECG_System_Info;


typedef struct 				
{
	/* Pointer to the current filling row of Leadinfo Buff*/
    unsigned int main_index_ptr;	
	/* LeadInfo Buffer*/
    Int16 lead_info_data[LEADINFOSIZE][MAXLEAD];
	
}ECG_Lead_Info;


#endif /*TYPEDEF_H_*/
