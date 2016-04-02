#ifndef DDA_UART_H_
#define DDA_UART_H_

/*****************************************************************************
 * File Name : dda_uart.h 
 *
 * Brief	 : DDC defined for a typical UART controller
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


//#ifndef _DDA_UART_H
//#define _DDA_UART_H

#include "psp_uart.h"
#include "ddc_uart.h"
#include "pal_osSem.h"
#include "util_circ.h"
#include "dda_uartCfg.h"

/* DDA UART Object forward declaration */
struct _DDA_UartObj;

/**
 *  \brief UART Channel Object
 */
typedef struct
{
#ifdef BIOS_BUILD
	Ptr						hPORT;
#endif
    Bool                    syncMode;   /**< Sync mode enabled? */
    PSP_DriverState         ddaState;   /**< DDA State */
    PAL_OsListNodeHeader    ddcIopListHead; /**< Free Iop List head */
    Int                     ddcIntrNum; /**< Interrupt number */
    /**
	 *  \brief  Device info structure
     */
    struct {
        Uint32              instanceId; /**< Instance number */
        DDC_UartObj         ddcObj;     /**< DDC Object */
		PSP_AppCallback     appCallback;    /**< Application Callback function */
    	Ptr                 cbkContext;     /**< Application Callback parameter */
    	PAL_OsSemHandle     hTxSemSync;     /**< Tx Sync semaphore handle */
    	PAL_OsSemHandle     hRxSemSync;     /**< Rx Sync semaphore handle */
        LLC_UartObj         llc;        /**< LLC Object */
        PSP_UartConfigParams    configParams;
        /**< Configuration/Current Status params */
    } device;

        UTIL_CircObj        rxBufContext;
        /**< RX Circular buffer object */
        UTIL_CircObj        txBufContext;
        /**< TX Circular buffer object */
        Char                rxBuf[PSP_UART_CIRC_BUFSIZE];
        /**< RX Circular buffer */
        Char                txBuf[PSP_UART_CIRC_BUFSIZE];
        /**< TX Circular buffer */

} DDA_UartObj;

extern LLC_UartHwConfig     *gDDA_UartHwConfig;
/**< UART configuration structure */
extern DDA_UartObj          gDDA_UartObj[PSP_UART_NUM_INSTANCES];
/**< DDA UART object */

/**
 *  \brief Call back function to indicate IO completion
 *
 *  \param  hDDA [IN]     DDA handle
 *  \param  iop  [IN]     IO packet pointer
 *  \return PSP_SOK or PSP Error code
 */
extern PAL_Result _DDA_uartIoComplete(
                    DDA_UartHandle          hDDA,
                    DDC_UartIoPacket  *iop);

/**
 *  \brief Gets the ticks from OS
 *
 *  \param  mSecs [IN]   Time in msecs
 *  \return PSP_SOK or PSP Error code
 */
extern Int _DDA_uartOsGetTicks(Int  mSecs);
//#endif  /* _DDA_UART_H_ */


#endif /*DDA_UART_H_*/
