#ifndef PAL_OSWAIT_H_
#define PAL_OSWAIT_H_

/*****************************************************************************
 * File Name : pal_oswait.h 
 *
 * Brief	 : OsWAIT Services Header File
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


//#ifndef _PAL_OSWAIT_H_
//#define _PAL_OSWAIT_H_

#include "psp_common.h"

/**
 * \defgroup PalOSWait PAL OS Wait Interface
 *
 * PAL OS Wait Interface
 * \{
 */

/** \name PAL OS Wait Interface
 *  PAL OS Wait Interface
 * \{
 */

/**
 * \brief   PAL_osWaitMsecs()
 *
 *      This function leverages OS implemented "wait" to delay
 *      further execution of current thread for specified milliseconds
 *      period of time.
 * \note    The currently running thread might be preempted and placed
 *      on scheduler's wait queue for the specified duration of time.
 *      If a more effecient (w/o context switch overhead) wait is required
 *      at finer time granularity (order of microseconds), please use
 *      SysWAIT services defined in pal_sys.h file
 * \note    The function will do any milliseconds-to-ticks conversion
 *      as appropriate for implementing the wait using underlying
 *      OS supported APIs.
 * \param   mSecs [IN] is the duration in milliseconds to wait for
 * \return  PAL_SOK if succesful else a suitable error code
 */
PAL_Result PAL_osWaitMsecs(Uint32 mSecs);

/**
 * \brief   PAL_osWaitTicks()
 *
 *      This function leverages OS implemented "wait" to delay
 *      further execution of current thread for specified number
 *      of operating system ticks.
 * \note    The currently running thread might be preempted and placed
 *      on scheduler's wait queue for the specified duration of time.
 *      If a more effecient (w/o context switch overhead) wait is required
 *      at finer time granularity (order of microseconds), please use
 *      SysWAIT services defined in pal_sys.h file
 * \param   ticks [IN] is the number of operating system ticks to wait for
 * \return  PAL_SOK if succesful else a suitable error code
 */
PAL_Result PAL_osWaitTicks(Uint32 ticks);

/*\}*/
/*\}*/

//#endif /* _PAL_OSWAIT_H_ */


#endif /*PAL_OSWAIT_H_*/
