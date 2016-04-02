#ifndef DDA_UARTCFG_H_
#define DDA_UARTCFG_H_

/*****************************************************************************
 * File Name : dda_uartCfg.h 
 *
 * Brief	 : UART DDA Configuration definitions
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


//#ifndef _DDA_UARTCFG_H
//#define _DDA_UARTCFG_H
/* Get LLC header for configuration information */
#include "llc_uartTypes.h"

/* Dimensioning Configurable Elements */
#define PSP_UART_NUM_INSTANCES              CSL_UART_PER_CNT   /**< Number of UART instances - get from SOC */
#define PSP_UART_NUM_CHANNELS               1u   /**< Number of UART Channels */
/* NOTE: DO NOT CHANGE THIS PARAM VALUE since only 1 channel is supported by this implementation */

#define PSP_UART_NUM_DEVICES_PER_CONTROLLER 1   /**< Number of UART devices per controller. */
/* NOTE: DO NOT CHANGE THIS PARAM VALUE since only 1 device per controller is supported by this implementation */

#define PSP_UART_NUM_IOP                    20u  /**< Number of IOP's */
#define DDC_UART_NUM_IOP                    PSP_UART_NUM_IOP 

/* IMPORTANT CRITICAL NOTE:
 * CIRCULAR BUFFER SIZE SHOULD BE A POWER OF 2, ELSE CODE WILL **NOT** WORK
 */
#define PSP_UART_CIRC_BUFSIZE               256u /**< Size of circular buffer */
/* Other Configurable Elements */
#define UART_TPOLL_MSECS                    1               /**< Poll time in milliSeconds */
#define UART_IOP_TIMEOUT_TICK               100             /**< Timeout monitoring tick period in mSecs */
/* Note: All IOP timeout's will have to have a min timeperiod of above mSecs */


//#endif  /* _DDA_UART_CFG_H_ */



#endif /*DDA_UARTCFG_H_*/
