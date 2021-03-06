/*****************************************************************************
 * File Name : cslr_dma_001.h 
 *
 * Brief	 : Define DMA register structure
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
#ifndef _CSLR__DMA_H_
#define _CSLR__DMA_H_

#include "cslr_001.h"


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint16 DMACH0SADR0;
    volatile Uint16 DMACH0SADR1;
    volatile Uint16 DMACH0DADR0;
    volatile Uint16 DMACH0DADR1;
    volatile Uint16 DMACH0TC0;
    volatile Uint16 DMACH0TC1;
    volatile Uint16 RSVD0[26];
    volatile Uint16 DMACH1SADR0;
    volatile Uint16 DMACH1SADR1;
    volatile Uint16 DMACH1DADR0;
    volatile Uint16 DMACH1DADR1;
    volatile Uint16 DMACH1TC0;
    volatile Uint16 DMACH1TC1;
    volatile Uint16 RSVD1[26];
    volatile Uint16 DMACH2SADR0;
    volatile Uint16 DMACH2SADR1;
    volatile Uint16 DMACH2DADR0;
    volatile Uint16 DMACH2DADR1;
    volatile Uint16 DMACH2TC0;
    volatile Uint16 DMACH2TC1;
    volatile Uint16 RSVD2[26];
    volatile Uint16 DMACH3SADR0;
    volatile Uint16 DMACH3SADR1;
    volatile Uint16 DMACH3DADR0;
    volatile Uint16 DMACH3DADR1;
    volatile Uint16 DMACH3TC0;
    volatile Uint16 DMACH3TC1;
} CSL_DmaRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* DMACH0SADR0 */

#define CSL_DMA_DMACH0SADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH0SADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH0SADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0SADR0_RESETVAL (0x0000u)

/* DMACH0SADR1 */

#define CSL_DMA_DMACH0SADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH0SADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH0SADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0SADR1_RESETVAL (0x0000u)

/* DMACH0DADR0 */

#define CSL_DMA_DMACH0DADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH0DADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH0DADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0DADR0_RESETVAL (0x0000u)

/* DMACH0DADR1 */

#define CSL_DMA_DMACH0DADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH0DADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH0DADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0DADR1_RESETVAL (0x0000u)

/* DMACH0TC0 */

#define CSL_DMA_DMACH0TC0_TXLEN_MASK (0xFFFFu)
#define CSL_DMA_DMACH0TC0_TXLEN_SHIFT (0x0000u)
#define CSL_DMA_DMACH0TC0_TXLEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC0_RESETVAL (0x0000u)

/* DMACH0TC1 */

#define CSL_DMA_DMACH0TC1_DMASTART_MASK (0x8000u)
#define CSL_DMA_DMACH0TC1_DMASTART_SHIFT (0x000Fu)
#define CSL_DMA_DMACH0TC1_DMASTART_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_DMASTATUS_MASK (0x4000u)
#define CSL_DMA_DMACH0TC1_DMASTATUS_SHIFT (0x000Eu)
#define CSL_DMA_DMACH0TC1_DMASTATUS_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_INTEN_MASK (0x2000u)
#define CSL_DMA_DMACH0TC1_INTEN_SHIFT (0x000Du)
#define CSL_DMA_DMACH0TC1_INTEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_AUTORELOAD_MASK (0x1000u)
#define CSL_DMA_DMACH0TC1_AUTORELOAD_SHIFT (0x000Cu)
#define CSL_DMA_DMACH0TC1_AUTORELOAD_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_DESTDATASIZE_MASK (0x0C00u)
#define CSL_DMA_DMACH0TC1_DESTDATASIZE_SHIFT (0x000Au)
#define CSL_DMA_DMACH0TC1_DESTDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_DESTADRMODE_MASK (0x0300u)
#define CSL_DMA_DMACH0TC1_DESTADRMODE_SHIFT (0x0008u)
#define CSL_DMA_DMACH0TC1_DESTADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_SRCADRMODE_MASK (0x00C0u)
#define CSL_DMA_DMACH0TC1_SRCADRMODE_SHIFT (0x0006u)
#define CSL_DMA_DMACH0TC1_SRCADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_BURSTMODE_MASK (0x0038u)
#define CSL_DMA_DMACH0TC1_BURSTMODE_SHIFT (0x0003u)
#define CSL_DMA_DMACH0TC1_BURSTMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_SYNC_MASK (0x0004u)
#define CSL_DMA_DMACH0TC1_SYNC_SHIFT (0x0002u)
#define CSL_DMA_DMACH0TC1_SYNC_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_SRCDATASIZE_MASK (0x0003u)
#define CSL_DMA_DMACH0TC1_SRCDATASIZE_SHIFT (0x0000u)
#define CSL_DMA_DMACH0TC1_SRCDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH0TC1_RESETVAL (0x0000u)

/* DMACH1SADR0 */

#define CSL_DMA_DMACH1SADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH1SADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH1SADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1SADR0_RESETVAL (0x0000u)

/* DMACH1SADR1 */

#define CSL_DMA_DMACH1SADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH1SADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH1SADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1SADR1_RESETVAL (0x0000u)

/* DMACH1DADR0 */

#define CSL_DMA_DMACH1DADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH1DADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH1DADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1DADR0_RESETVAL (0x0000u)

/* DMACH1DADR1 */

#define CSL_DMA_DMACH1DADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH1DADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH1DADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1DADR1_RESETVAL (0x0000u)

/* DMACH1TC0 */

#define CSL_DMA_DMACH1TC0_TXLEN_MASK (0xFFFFu)
#define CSL_DMA_DMACH1TC0_TXLEN_SHIFT (0x0000u)
#define CSL_DMA_DMACH1TC0_TXLEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC0_RESETVAL (0x0000u)

/* DMACH1TC1 */

#define CSL_DMA_DMACH1TC1_DMASTART_MASK (0x8000u)
#define CSL_DMA_DMACH1TC1_DMASTART_SHIFT (0x000Fu)
#define CSL_DMA_DMACH1TC1_DMASTART_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_DMASTATUS_MASK (0x4000u)
#define CSL_DMA_DMACH1TC1_DMASTATUS_SHIFT (0x000Eu)
#define CSL_DMA_DMACH1TC1_DMASTATUS_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_INTEN_MASK (0x2000u)
#define CSL_DMA_DMACH1TC1_INTEN_SHIFT (0x000Du)
#define CSL_DMA_DMACH1TC1_INTEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_AUTORELOAD_MASK (0x1000u)
#define CSL_DMA_DMACH1TC1_AUTORELOAD_SHIFT (0x000Cu)
#define CSL_DMA_DMACH1TC1_AUTORELOAD_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_DESTDATASIZE_MASK (0x0C00u)
#define CSL_DMA_DMACH1TC1_DESTDATASIZE_SHIFT (0x000Au)
#define CSL_DMA_DMACH1TC1_DESTDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_DESTADRMODE_MASK (0x0300u)
#define CSL_DMA_DMACH1TC1_DESTADRMODE_SHIFT (0x0008u)
#define CSL_DMA_DMACH1TC1_DESTADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_SRCADRMODE_MASK (0x00C0u)
#define CSL_DMA_DMACH1TC1_SRCADRMODE_SHIFT (0x0006u)
#define CSL_DMA_DMACH1TC1_SRCADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_BURSTMODE_MASK (0x0038u)
#define CSL_DMA_DMACH1TC1_BURSTMODE_SHIFT (0x0003u)
#define CSL_DMA_DMACH1TC1_BURSTMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_SYNC_MASK (0x0004u)
#define CSL_DMA_DMACH1TC1_SYNC_SHIFT (0x0002u)
#define CSL_DMA_DMACH1TC1_SYNC_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_SRCDATASIZE_MASK (0x0003u)
#define CSL_DMA_DMACH1TC1_SRCDATASIZE_SHIFT (0x0000u)
#define CSL_DMA_DMACH1TC1_SRCDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH1TC1_RESETVAL (0x0000u)

/* DMACH2SADR0 */

#define CSL_DMA_DMACH2SADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH2SADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH2SADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2SADR0_RESETVAL (0x0000u)

/* DMACH2SADR1 */

#define CSL_DMA_DMACH2SADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH2SADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH2SADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2SADR1_RESETVAL (0x0000u)

/* DMACH2DADR0 */

#define CSL_DMA_DMACH2DADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH2DADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH2DADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2DADR0_RESETVAL (0x0000u)

/* DMACH2DADR1 */

#define CSL_DMA_DMACH2DADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH2DADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH2DADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2DADR1_RESETVAL (0x0000u)

/* DMACH2TC0 */

#define CSL_DMA_DMACH2TC0_TXLEN_MASK (0xFFFFu)
#define CSL_DMA_DMACH2TC0_TXLEN_SHIFT (0x0000u)
#define CSL_DMA_DMACH2TC0_TXLEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC0_RESETVAL (0x0000u)

/* DMACH2TC1 */

#define CSL_DMA_DMACH2TC1_DMASTART_MASK (0x8000u)
#define CSL_DMA_DMACH2TC1_DMASTART_SHIFT (0x000Fu)
#define CSL_DMA_DMACH2TC1_DMASTART_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_DMASTATUS_MASK (0x4000u)
#define CSL_DMA_DMACH2TC1_DMASTATUS_SHIFT (0x000Eu)
#define CSL_DMA_DMACH2TC1_DMASTATUS_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_INTEN_MASK (0x2000u)
#define CSL_DMA_DMACH2TC1_INTEN_SHIFT (0x000Du)
#define CSL_DMA_DMACH2TC1_INTEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_AUTORELOAD_MASK (0x1000u)
#define CSL_DMA_DMACH2TC1_AUTORELOAD_SHIFT (0x000Cu)
#define CSL_DMA_DMACH2TC1_AUTORELOAD_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_DESTDATASIZE_MASK (0x0C00u)
#define CSL_DMA_DMACH2TC1_DESTDATASIZE_SHIFT (0x000Au)
#define CSL_DMA_DMACH2TC1_DESTDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_DESTADRMODE_MASK (0x0300u)
#define CSL_DMA_DMACH2TC1_DESTADRMODE_SHIFT (0x0008u)
#define CSL_DMA_DMACH2TC1_DESTADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_SRCADRMODE_MASK (0x00C0u)
#define CSL_DMA_DMACH2TC1_SRCADRMODE_SHIFT (0x0006u)
#define CSL_DMA_DMACH2TC1_SRCADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_BURSTMODE_MASK (0x0038u)
#define CSL_DMA_DMACH2TC1_BURSTMODE_SHIFT (0x0003u)
#define CSL_DMA_DMACH2TC1_BURSTMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_SYNC_MASK (0x0004u)
#define CSL_DMA_DMACH2TC1_SYNC_SHIFT (0x0002u)
#define CSL_DMA_DMACH2TC1_SYNC_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_SRCDATASIZE_MASK (0x0003u)
#define CSL_DMA_DMACH2TC1_SRCDATASIZE_SHIFT (0x0000u)
#define CSL_DMA_DMACH2TC1_SRCDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH2TC1_RESETVAL (0x0000u)

/* DMACH3SADR0 */

#define CSL_DMA_DMACH3SADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH3SADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH3SADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3SADR0_RESETVAL (0x0000u)

/* DMACH3SADR1 */

#define CSL_DMA_DMACH3SADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH3SADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH3SADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3SADR1_RESETVAL (0x0000u)

/* DMACH3DADR0 */

#define CSL_DMA_DMACH3DADR0_LSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH3DADR0_LSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH3DADR0_LSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3DADR0_RESETVAL (0x0000u)

/* DMACH3DADR1 */

#define CSL_DMA_DMACH3DADR1_MSWADDR_MASK (0xFFFFu)
#define CSL_DMA_DMACH3DADR1_MSWADDR_SHIFT (0x0000u)
#define CSL_DMA_DMACH3DADR1_MSWADDR_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3DADR1_RESETVAL (0x0000u)

/* DMACH3TC0 */

#define CSL_DMA_DMACH3TC0_TXLEN_MASK (0xFFFFu)
#define CSL_DMA_DMACH3TC0_TXLEN_SHIFT (0x0000u)
#define CSL_DMA_DMACH3TC0_TXLEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC0_RESETVAL (0x0000u)

/* DMACH3TC1 */

#define CSL_DMA_DMACH3TC1_DMASTART_MASK (0x8000u)
#define CSL_DMA_DMACH3TC1_DMASTART_SHIFT (0x000Fu)
#define CSL_DMA_DMACH3TC1_DMASTART_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_DMASTATUS_MASK (0x4000u)
#define CSL_DMA_DMACH3TC1_DMASTATUS_SHIFT (0x000Eu)
#define CSL_DMA_DMACH3TC1_DMASTATUS_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_INTEN_MASK (0x2000u)
#define CSL_DMA_DMACH3TC1_INTEN_SHIFT (0x000Du)
#define CSL_DMA_DMACH3TC1_INTEN_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_AUTORELOAD_MASK (0x1000u)
#define CSL_DMA_DMACH3TC1_AUTORELOAD_SHIFT (0x000Cu)
#define CSL_DMA_DMACH3TC1_AUTORELOAD_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_DESTDATASIZE_MASK (0x0C00u)
#define CSL_DMA_DMACH3TC1_DESTDATASIZE_SHIFT (0x000Au)
#define CSL_DMA_DMACH3TC1_DESTDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_DESTADRMODE_MASK (0x0300u)
#define CSL_DMA_DMACH3TC1_DESTADRMODE_SHIFT (0x0008u)
#define CSL_DMA_DMACH3TC1_DESTADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_SRCADRMODE_MASK (0x00C0u)
#define CSL_DMA_DMACH3TC1_SRCADRMODE_SHIFT (0x0006u)
#define CSL_DMA_DMACH3TC1_SRCADRMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_BURSTMODE_MASK (0x0038u)
#define CSL_DMA_DMACH3TC1_BURSTMODE_SHIFT (0x0003u)
#define CSL_DMA_DMACH3TC1_BURSTMODE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_SYNC_MASK (0x0004u)
#define CSL_DMA_DMACH3TC1_SYNC_SHIFT (0x0002u)
#define CSL_DMA_DMACH3TC1_SYNC_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_SRCDATASIZE_MASK (0x0003u)
#define CSL_DMA_DMACH3TC1_SRCDATASIZE_SHIFT (0x0000u)
#define CSL_DMA_DMACH3TC1_SRCDATASIZE_RESETVAL (0x0000u)

#define CSL_DMA_DMACH3TC1_RESETVAL (0x0000u)

#endif
