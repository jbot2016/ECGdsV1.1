////jb commenting out for testing purposes
///*****************************************************************************
// * File Name : pal_osTime.c
// *
// * Brief	 : BIOS OS time Source File
// *    This file implements additional OS abstraction services for BIOS.
// *    The following BIOS services are provided: 
// *
// * Copyright (C) 2009 -2010 Texas Instruments Incorporated - http://www.ti.com/ 
// * 
// * 
// *  Redistribution and use in source and binary forms, with or without 
// *  modification, are permitted provided that the following conditions 
// *  are met:
// *
// *    Redistributions of source code must retain the above copyright 
// *    notice, this list of conditions and the following disclaimer.
// *
// *    Redistributions in binary form must reproduce the above copyright
// *    notice, this list of conditions and the following disclaimer in the 
// *    documentation and/or other materials provided with the   
// *    distribution.
// *
// *    Neither the name of Texas Instruments Incorporated nor the names of
// *    its contributors may be used to endorse or promote products derived
// *    from this software without specific prior written permission.
// *
// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
//******************************************************************************/
//
//#include "psp_common.h"
//#include "trc.h"
//#include "log.h"
//#include "prd.h"
//
//#ifdef __TMS320C55X__
//extern LOG_Obj trace;
//#else
//extern far LOG_Obj trace;
//#endif // __TMS320C55X__
//
///* BIOS Get OS Ticks per mSecs */
//Uint32 PAL_osGetCurrentTick(void)
//{
////sree    return PRD_getticks();
//}
//
//Bool PAL_osCheckTimeOut(Uint32 startValue,Uint32 timeout)
//{
//	Uint32 checkValue;
//	Bool	retVal;
//	checkValue = PAL_osGetCurrentTick();
//	if ( checkValue < startValue )
//	{
//		checkValue = (((0xFFFFFFFFU) - startValue) + checkValue) + (1U) ;
//	}
//	else
//	{
//		checkValue = checkValue - startValue;
//	}
//
//	if (checkValue < timeout)
//	{
//		retVal	=	FALSE;
//	}
//	else
//	{
//		retVal	=	TRUE;
//	}
//	return	retVal;
//}
//
