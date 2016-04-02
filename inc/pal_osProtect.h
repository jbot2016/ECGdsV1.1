#ifndef PAL_OSPROTECT_H_
#define PAL_OSPROTECT_H_

/*****************************************************************************
 * File Name : pal_osprotect.h 
 *
 * Brief	 : OsPROTECT Services Header File 
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



//#ifndef _PAL_OSPROTECT_H_
//#define _PAL_OSPROTECT_H_

#include "psp_common.h"

/**
 * \defgroup PalOSProtect PAL OS Protect Interface
 *
 * PAL OS Protect Interface
 * \{
 */

/** \name PAL OS Protect Interface
 *  PAL OS Protect Interface
 * \{
 */

#define PAL_OSPROTECT_INTERRUPT (-1)
#define PAL_OSPROTECT_SCHEDULER (-2)

/**
 * \brief   PAL OS Protect Entry
 *
 *      This function saves the current state of protection in cookie
 *      variable passed by caller. It then applies the requested level
 *      of protection
 * \param   level  [IN] is numeric identifier of the desired degree of protection.
 * \param   cookie [IN] is memory location where current state of protection is
 *      saved for future use while restoring it via PAL_osProtectExit()
 * \note    user is not expected to interpret the cookie in any manner. It
 *      is intended for use in terminating the presently enforced
 *      protection via a matching PAL_osProtectExit() call discssed
 *      later in this file.
 * \return  None
 */
void PAL_osProtectEntry(Int level, Uint32* const cookie);

/**
 * \brief   PAL OS Protect Exit
 *
 *      This function undoes the protection enforced to original state
 *      as is specified by the cookie passed.
 * \param   level  [IN]is numeric identifier of the desired degree of protection.
 * \param   cookie [IN] is original state of protection at time when the
 *      corresponding PAL_osProtectEnter() was called.
 * \return  None
 */
void PAL_osProtectExit(Int level, Uint32 cookie);

/*\}*/
/*\}*/

//#endif /* _PAL_OS_PROTECT_H_ */


#endif /*PAL_OSPROTECT_H_*/
