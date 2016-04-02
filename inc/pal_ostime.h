#ifndef PAL_OSTIME_H_
#define PAL_OSTIME_H_

/*****************************************************************************
 * File Name : pal_ostime.h 
 *
 * Brief	 : PAL OS Service Header File 
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


//#ifndef _PAL_OSTIME_H
//#define _PAL_OSTIME_H

#include <psp_common.h>


/**
 * \defgroup PrOS_OsServ PAL OS Time Interface
 *
 * PAL OS TIME INTERFACE
 * @{
 */

/**
 * \brief   PAL OS Get Current System Time
 *
 *      This checks the start value against the timeout to
 *      determine whether a time out has happened or not
 * \param   startValue[IN] Start time
 * \param   timeout[IN]     Timeout value
 * \return  Bool Whether timed-out or not
 */
Bool PAL_osCheckTimeOut(Uint32 startValue,Int32 timeout);

/**
 * \brief   PAL OS Get Current Tick
 *
 *      This returns the current time in seconds
 * \param   None
 * \return  Uint32 Tick in seconds
 */
Uint32 PAL_osGetCurrentTick(void);
/*@}*/

//#endif /* _PAL_OSTIME_H */


#endif /*PAL_OSTIME_H_*/
