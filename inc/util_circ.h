#ifndef UTIL_CIRC_H_
#define UTIL_CIRC_H_

/*****************************************************************************
 * File Name : util_circ.h 
 *
 * Brief	 : Circular buffer header  
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


//#ifndef _UTIL_CIRC_H_
//#define _UTIL_CIRC_H_

#include "psp_common.h"

extern Uint16 offset ;

#define UTIL_circFullCount(hCirc)       ((hCirc)->charCount)
#define UTIL_circEmptyCount(hCirc)      ((hCirc)->size - (hCirc)->charCount)
/* NOTE: The circular buffers are expected to be a power of 2. If not, then 
 * the following macros will not work
 */
#define UTIL_circNextIndex(hCirc,index) (((index) + offset) & ((hCirc)->size - offset))
#define UTIL_circPrevIndex(hCirc,index) (((index) - offset) & ((hCirc)->size - offset))
#define UTIL_circIsFull(hCirc)          ((hCirc)->charCount == (hCirc)->size)

typedef struct
{
    Uint16  writeIndex; /* write pointer for the buffer                     */
    Uint16  readIndex;  /* read pointer fro the buffer                      */
    Uint16  charCount;  /* buffer character count                           */
    Uint16  size;       /* buffer size                                      */
    Char    *buf;       /* circular buffer                                  */
} UTIL_CircObj, *UTIL_CircHandle;



extern void UTIL_circNew(UTIL_CircHandle hCirc, Ptr hBuf, Uint16 size);
extern Char UTIL_circReadChar(UTIL_CircHandle hCirc);
extern void UTIL_circWriteChar(UTIL_CircHandle hCirc, Char c);
extern Int UTIL_circReadMultiple(UTIL_CircHandle hCirc, Ptr hBuf, Int num);
extern Int UTIL_circWriteMultiple(UTIL_CircHandle hCirc, const Char *buf, Int num);
extern void UTIL_circUnget(UTIL_CircHandle hCirc);



//#endif /* _UTIL_CIRC_H_ */


#endif /*UTIL_CIRC_H_*/
