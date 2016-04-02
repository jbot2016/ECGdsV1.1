/*****************************************************************************
 * File Name : util_circ.c
 *
 * Brief	 : Circular buffer implementation
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

#include "util_circ.h"


Uint16 offset = 1u;

/*
 *  ======== UTIL_circNew ========
 *
 *  Initializes the circular buffer structure
 */
void UTIL_circNew(UTIL_CircHandle hCirc, Ptr hBuf, Uint16 size)
{
    Char * buf = (Char*)hBuf;
    hCirc->writeIndex = 0;
    hCirc->readIndex = 0;
    hCirc->charCount = 0;
    hCirc->buf = buf;
    hCirc->size = size;
}

/*
 *  ======== UTIL_circReadChar ========
 *
 *  Reads a character from the circular buffer.
 */
Char UTIL_circReadChar(UTIL_CircHandle hCirc)
{
    Char c;

    /* read character and increment the character count */
    c = hCirc->buf[hCirc->readIndex];
    hCirc->readIndex = (Uint16)UTIL_circNextIndex(hCirc, hCirc->readIndex);
    hCirc->charCount--;

    return (c);
}

/*
 *  ======== UTIL_circWriteChar ========
 *
 *  Writes a character into the circular buffer
 */
void UTIL_circWriteChar(UTIL_CircHandle hCirc, Char c)
{
    /* write character and decrement the character count */
    hCirc->buf[hCirc->writeIndex] = c;
    hCirc->writeIndex = (Uint16)UTIL_circNextIndex(hCirc, hCirc->writeIndex);
    hCirc->charCount++;
}

/*
 *  ======== UTIL_circReadMultiple ========
 *
 *  Reads multiple chars from the buffer
 */
Int UTIL_circReadMultiple(UTIL_CircHandle hCirc, Ptr hBuf, Int num)
{
    Int     i;
    Int     available;
	Char    *buf;

	buf = (Char*)hBuf;

    available = (Int)UTIL_circFullCount(hCirc);
    num = (num < available) ? num : available;

    for (i = 0; i < num; i++) {
        *buf++ = hCirc->buf[hCirc->readIndex];
        hCirc->readIndex = (Uint16)UTIL_circNextIndex(hCirc, hCirc->readIndex);
        hCirc->charCount--;
    }

    return (num);
}

/*
 *  ======== UTIL_circWriteMultiple ========
 *
 *  Writes multiple characters into the circular buffer
 */
Int UTIL_circWriteMultiple(UTIL_CircHandle hCirc, const Char *buf, Int num)
{
    Int     i;
    Int     available;

    available = (Int)UTIL_circEmptyCount(hCirc);
    num = (num < available) ? num : available;

    for (i = 0; i < num; i++) {
        hCirc->buf[hCirc->writeIndex] = (*buf);
		buf++;
        hCirc->writeIndex = (Uint16)UTIL_circNextIndex(hCirc, hCirc->writeIndex);
        hCirc->charCount++;
    }

    return (num);
}

/*
 *  ======== UTIL_circUnget ========
 *
 *  Move the read-index back 1 space to unget the character read
 */
void UTIL_circUnget(UTIL_CircHandle hCirc)
{
    hCirc->readIndex = (Uint16)UTIL_circPrevIndex(hCirc, hCirc->readIndex);
}

