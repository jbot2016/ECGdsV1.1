////jb commenting out for testing purposes
///*****************************************************************************
// * File Name : pal_osSem.c
// *
// * Brief	 : OsSem Services Source File for BIOS
// *  This file implements OS abstraction services for counting semaphores.
// *  All services run in the context of the calling thread or program.
// *  OsSEM does not spawn a thread of its own to implement the APIs
// *  declared here. 
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
//#include "std.h"
//#include "psp_common.h"
//#include "pal_osSem.h"
//#include "sem.h"
//
///* To create a semaphore */
//PAL_Result PAL_osSemCreate(const char * name,
//                           Int32 initVal,
//                           const PAL_OsSemAttrs *attrs, 
//                           PAL_OsSemHandle * const hSem)
//{
//    SEM_Attrs   temp; /* used for passing the 'name' parameter to SEM_create */
//	PAL_Result semCreateResult = PAL_SOK;
//
//	if(NULL == hSem)
//	{
//		semCreateResult	=	PSP_E_RESOURCES;
//	}
//	else
//	{
//	    temp.name = (String) name;
///*sree		*hSem = (PAL_OsSemHandle)SEM_create(initVal, &temp);
//		if ( (*hSem) == NULL )
//		{
//			semCreateResult = PSP_E_RESOURCES;
//		}*/
//	}
//	return semCreateResult;
//}
//
///* To Delete a semaphore */
//PAL_Result PAL_osSemDelete(PAL_OsSemHandle hSem)
//{
//	PAL_Result semDeleteResult = PAL_SOK;
////sree	SEM_delete(hSem);
//	return semDeleteResult;
//}
//
///* To take a semaphore */
//PAL_Result PAL_osSemTake(PAL_OsSemHandle hSem, Int32 mSecTimeout)
//{
//	PAL_Result semTakeResult = PAL_SOK;
//	Bool		semPendResult;
///*sree	semPendResult = SEM_pend(hSem, mSecTimeout);
//	if ( semPendResult == FALSE )
//	{
//		semTakeResult = PSP_E_RESOURCES;
//	}
//	else
//	{
//		semTakeResult = PAL_SOK;
//	}
//*/	semTakeResult = PAL_SOK;
//	return semTakeResult;
//}
//
///* To give a semaphore */
//PAL_Result PAL_osSemGive(PAL_OsSemHandle hSem)
//{
//	PAL_Result semGiveResult = PAL_SOK;
////sree	SEM_post(hSem);
//	return semGiveResult;
//}
//
//
