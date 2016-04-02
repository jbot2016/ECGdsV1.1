/*****************************************************************************
 * File Name : dda_uartCfg.c
 *
 * Brief	 : This file contains configuration data for adaptation of UART driver
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

#include "dda_uart.h"

LLC_UartHwConfig        gDDAHwCfg[PSP_UART_NUM_INSTANCES] =
{
        {   /* UART 0 config start*/
            {   /* LLC_UartBasicConfig */
                0u,     /* Module clock frequency */
                /* Baud rates supported are :110, 300, 1200, 2400, 4800, 9600, 19200,
                 * 38400, 57600 and 115200
                 */
                //NOTE: Assingn direct values, dont use Enum.
				19200, /* Mistral: Changed Baud rate PSP_UART_BAUD_RATE_115_2K, */  /* Baud rate */
                TRUE,                       /*  Enable/Disable Fifo */
                FALSE,                      /* Enable Loopback */
                FALSE,                      /* NOT SUPPORTED - Enable Transmit parity check - Always set to False */
                LLC_UART_CHARLEN_8,         /* Character Length */
                LLC_UART_NUM_STOP_BITS_1,   /* Number of stop bits */
                LLC_UART_PARITY_NONE,       /* Parity */
                LLC_UART_RX_TRIG4,      	/* Hardware RX Threshold - refer to hardware manual for details  */

            },
            {   /* LLC_UartFlowControlConfig */
                LLC_UART_FLOWCONTROL_NONE,  /* Flow control type */
                FALSE,                      /* Auto RTS/CTS */
            }
        }  /* UART config end */

};

LLC_UartHwConfig        *gDDA_UartHwConfig = &gDDAHwCfg[0];

