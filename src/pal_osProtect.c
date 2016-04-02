////jb commenting out for testing purposes
///*****************************************************************************
// * File Name : pal_osProtect.c
// *
// * Brief	 : OsPROTECT Services Source File for BIOS
// *             This file implements OS abstraction services for reentrancy protection.
// *             For interrupt protection, assembly code is used since BIOS does not provide
// *             a function that returns previous interrupt status (cpsr).
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
//
//#include "std.h"
//#include "pal_osProtect.h"
//#include "hwi.h"
//#include "tsk.h"
//
//
///** \brief PAL OS Protect Entry
//	
//	This function is called to start a critical section (from interrupts/scheduler)
//	When PAL_OSPROTECT_INTERRUPT is called the returned mask should be passed
//	to the corresponding PAL_osProtectExit function. PAL_OSPROTECT_SCHEDULER
//	does not take/return any parameters.
//
//	BIOS has constrains and calling constraints for the HWI_disable and 
//	TSK_disable functions. Refer to BIOS API reference guide for further 
//	details
//*/
//void PAL_osProtectEntry(Int level, Uint32* imask)
//{
//	if (NULL != imask) 
//	{
//	    if (level == PAL_OSPROTECT_INTERRUPT)
//	    {
//	    //sree    *imask = HWI_disable();
//	    }
//	    else 
//		{
//			if (level == PAL_OSPROTECT_SCHEDULER)
//			{
//			//sree	TSK_disable();
//			}
//		}
//	}
//    return;
//}
//
//
///** \brief PAL OS Protect Exit
//	
//	This function is called to exit from a critical section.
//	When PAL_OSPROTECT_INTERRUPT is called the mask returned from the corresponding
//	entry function should be passed.PAL_OSPROTECT_SCHEDULER does not take any 
//	parameter.
//
//	BIOS has constrains and calling constraints for the HWI_restore and 
//	TSK_enable functions. Refer to BIOS API reference guide for further 
//	details
//*/
//void PAL_osProtectExit(Int level, Uint32 imask)
//{
//    if (level == PAL_OSPROTECT_INTERRUPT)
//    {
// //sree       HWI_restore(imask);
//    }
//	else {
//		if (level == PAL_OSPROTECT_SCHEDULER)
//		{
//		//sree	TSK_enable();
//		}
//	}
//    return;
//}
//
//
