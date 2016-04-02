#ifndef PAL_OSCACHE_H_
#define PAL_OSCACHE_H_

/*****************************************************************************
 * File Name : pal_oscache.h 
 *
 * Brief	 : OsLIST Services Header File 
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


//#ifndef __PAL_OS_CACHE_H__
//#define __PAL_OS_CACHE_H__

#include "psp_common.h"

/**
 * \defgroup PalOSCache PAL OS Cache Interface
 *
 * PAL OS Cache Interface
 * \{
 */

/** \name PAL OS Cache Interface
 *  PAL OS Cache Interface
 * \{
 */

 typedef enum
 {
    PAL_osCache_NOT_DEFINED
 } PAL_osCacheMemAddrSpace;



/**
 * \brief   PAL OS Cache Invalidate
 *
 * This function invalidates the D cache.
 *
 *  NOTE : cache is NOT USED in this API
 *  \parm   cache         [IN]      Cache address space
 *  \param  mem_start_ptr [IN]      Starting adress of memory.
 *                                  Please note that this should be
 *                                  32 bytes alinged.
 *  \param  num_bytes     [IN]      length of buffer
 * \return  nil return value
 */
void PAL_osCacheInvalidate(PAL_osCacheMemAddrSpace  cache,
                           Uint32                   mem_start_ptr,
                           Uint32                   num_bytes);

/**
 * \brief   PAL OS Cache Flush
 *
 * This function flushes (cleans) the Cache
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cache  [IN]      Cache address space
 *  \param  mem_start_ptr [IN]  Starting adress of memory. Please note that this should be 32 bytes alinged.
 *  \param  num_bytes [IN]      length of buffer
 * \return  nil return value
 */
void PAL_osCacheFlush(PAL_osCacheMemAddrSpace   cache,
                      Uint32                    mem_start_ptr,
                      Uint32                    num_bytes);


/**
 * \brief   PAL OS Cache Flush and Invalidate
 *
 * This function flushes (cleans) and invalidates the Cache
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cache     [IN]      Cache address space
 *  \param  mem_start_ptr [IN]      Starting adress of memory. Please note that this should be 32 bytes alinged.
 *  \param  num_bytes [IN]         length of buffer
 * \return  nil
 */
void PAL_osCacheFlushAndInvalidate(PAL_osCacheMemAddrSpace  cache,
                                   Uint32                   mem_start_ptr,
                                   Uint32                   num_bytes);


/**
 * \brief   PAL OS Set Cache line Length
 *
 * This function sets the cache line
 *
 *  NOTE : cache is not cared in this API
 *  \parm   cache   [IN]      Cache address space
 *  \param  length  [IN]     Cache line Length
 * \return nil
 */
void PAL_osCacheSetCacheLineLength(PAL_osCacheMemAddrSpace  cache,
                                   Uint8                    length);

/**
 * \brief   PAL OS GEt Cache line Length
 *
 * This function returns the length of cache line
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cache   [IN]      Cache address space
 * \return  Cache Length
 */
Uint8 PAL_osCacheGetCacheLineLength(PAL_osCacheMemAddrSpace cache);


/**
 *  \brief Drain the write buffer
 *
 *  This function Drain the write buffer
 *
 *  NOTE : cache is not cared in this API
 *  \parm   cache      [IN]   Cache address space
 *  \param  waitForInt [IN]  if TRUE -- Drains the writebuffer and put processor in low
 *                                    power mode till next interrupts occurs.
 *                          if FALSE -- Drains the writebuffer and stops excuting further
 *                                  till buffer is drained.
 *  \return void
 */
void PSP_cacheDrainWriteBuffer(PAL_osCacheMemAddrSpace  cache,
                               Bool                     waitForInt);


/*\}*/

/*\}*/

//#endif /* __PAL_OS_CACHE_H__ */


#endif /*PAL_OSCACHE_H_*/
