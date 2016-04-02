#ifndef LLC_UARTTYPES_H_
#define LLC_UARTTYPES_H_

/*****************************************************************************
 * File Name : llc_uartTypes.h 
 *
 * Brief	 : UART low-level controller interface 
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

//#ifndef _LLC_UARTTYPES_H
//#define _LLC_UARTTYPES_H

#include <corazon.h>

/**
 * \defgroup LLCUartMain LLC UART Interface Definition
 *
 * Top-level Encapsulation of all documentation for UART LLC
 *
 * @{
 */

/**
 * \defgroup LLCUartControllerSpecificDefs LLC Specific Definitions
 *
 * Definitions specific to this IP of the UART
 *
 * @{
 */


#define LLC_UART_TX_FIFO_SIZE           16u
/**< TX FIFO size */

#define LLC_UART_RX_FIFO_SIZE           16u
/**< RX FIFO size */

#define LLC_UART_BAUD_MULTIPLIER        16u
/**< Baud Multiplier */


typedef Uint32   LLC_UartRegister;
/**< LLC UART Register */

/* @} LLCUartControllerSpecificDefs */


/**
 * \defgroup LLCUartGenericDefs LLC UART Generic Definitions Structures
 *
 * UART definitions that are applicable to any controller and agnostic of a
 * specific IP block
 *
 * @{
 */

 typedef enum
{
    LLC_UART_PARITY_NONE    = 0x0,
    /**< None Parity                                                        */
    LLC_UART_PARITY_ODD     = 0x8,
    /**< Odd Parity                                                         */
    LLC_UART_PARITY_EVEN    = 0x18
    /**< Even Parity                                                        */
} LLC_UartParity;

typedef enum
{
    LLC_UART_NUM_STOP_BITS_1    = 0,
    /**< Number of stop bits == 1                                           */
    LLC_UART_NUM_STOP_BITS_1_5  = 0x4,
    /**< Number of stop bits == 1.5                                         */
    LLC_UART_NUM_STOP_BITS_2    = 0x4
    /**< Number of stop bits == 2                                           */
} LLC_UartNumStopBits;

typedef enum
{
    LLC_UART_CHARLEN_5  = 0x0,
    /**< Number of bits in a char == 5                                      */
    LLC_UART_CHARLEN_6  = 0x1,
    /**< Number of bits in a char == 6                                      */
    LLC_UART_CHARLEN_7  = 0x2,
    /**< Number of bits in a char == 7                                      */
    LLC_UART_CHARLEN_8  = 0x3
    /**< Number of bits in a char == 8                                      */
} LLC_UartCharLen;

typedef enum
{
    LLC_UART_FLOWCONTROL_NONE   = 0,
    /**< Neither HW,nor S/W flow Control */
    LLC_UART_FLOWCONTROL_SW     = 1,
    /**< Software Flow Control */
    LLC_UART_FLOWCONTROL_HW     = 2
    /**< Hardware Flow Control */
} LLC_UartFlowControl;

/**
 * Software Flow control
 * NOT SUPPORTED IN THIS DRIVER
 */
typedef enum
{
    LLC_UART_SWFLOW_NONE        = 0,
    /**< No Flow Control                                                    */
    LLC_UART_SWFLOW_XONXOFF_1   = 2,
    /**< Receiver/Transmitter compares XON1, XOFF1                          */
    LLC_UART_SWFLOW_XONXOFF_2   = 1,
    /**< Receiver/Transmitter compares XON2, XOFF2                          */
    LLC_UART_SWFLOW_XONXOFF_12  = 3
    /**< Receiver/Transmitter compares XON1, XON2; XOFF1, XOFF2             */
} LLC_UartSwFlow;
/**
 * Uart interrupts
 */
typedef enum
{
    LLC_UART_INTR_RHR   = (1L << 0),
    /**< Data ready in receive register                                     */
    LLC_UART_INTR_THR   = (1L << 1),
    /**< Transmitter empty interrupt                                        */
    LLC_UART_INTR_RLS   = (1L << 2),
    /**< A line status changed or an error condition was detected           */
    LLC_UART_INTR_MS    = (1L << 3),
    /**< Modem status interrupt */
    LLC_UART_INTR_ALL   = (0xF)
    /**< All interrupts */
} LLC_UartIntr;

/**
 * Uart receive trigger levels
 */

typedef enum
{
    LLC_UART_RX_TRIG1   = 1,
    /**< RX Trigger Level = 01                                              */
    LLC_UART_RX_TRIG4   = 4,
    /**< RX Trigger Level = 04                                              */
    LLC_UART_RX_TRIG8   = 8,
    /**< RX Trigger Level = 08                                              */
    LLC_UART_RX_TRIG14  = 14
    /**< RX Trigger Level = 14                                              */
} LLC_UartRxTrigLvl;


/**
 * \brief UART Basic configuration structure
 *
 * This structure contains the bacic uart configuration parameters.
 */

typedef struct
{
    Uint32          moduleClock;
    /**< Module Clock Frequency(Hz)                                         */
    Uint32          baudRate;
    /**< Division factor of the moduleClock that is used to derive the
     * required baud on the wire                                            */
    Bool            enableFifo;
    /**< Enable/ Disable FIFO mode              \n
     *  TRUE: Enable                            \n
     *  False: Disable                          \n                          */
    Bool            enableLoopback;
    /**< Enable/ Disable Loopback operation     \n
     *  TRUE: Enable                            \n
     *  False: Disable                          \n                          */
    Bool            enableXmitParityCheck;
    /**< Enable/ Disable transmit parity check  \n
     *  TRUE: Enable                            \n
     *  False: Disable                          \n                          */
    LLC_UartCharLen charLen;
    /**< Length of each transmitted character, in bits                      */
    LLC_UartNumStopBits numStopBits;
    /**< Number of Stop bits                                                */
    LLC_UartParity  parity;
    /**< Even or Odd Parity                                                 */
    LLC_UartRxTrigLvl rxThreshold;
    /**< Trigger level setting for the RX FIFO                              */
} LLC_UartBasicConfig;

/**
 * \brief UART Flow control configuration structure
 *
 */

typedef struct
{
    LLC_UartFlowControl fcType;
    /**< Standard Flow Control Types                                        */
    Bool    autoRtsCts;
    /**< AUTO RTS/CTS Enable        \n
     *  TRUE: Enable Auto RTS/CTS   \n
     *  False: Disable Auto RTS/CTS \n                                      */
} LLC_UartFlowControlConfig;

/**
 * \brief UART hardware initialzation structure
 *
 * This structure contains the hardware initialization data. This is further
 * divided into three sub-sections. First set contains the UART hardware
 * setup/ initialization configuration. The next two contains the DMA Rx and
 * Tx hardware initialization configuration.
 */
typedef struct
{
    LLC_UartBasicConfig         cfgBasic;
    /**< UART Hardware control setup                                        */
    LLC_UartFlowControlConfig   cfgFlowControl;
    /**< UART Flow Control Setup                                            */
} LLC_UartHwConfig;

typedef Uint32 LLC_UartIntrStatus;

/* @} LLCUartGenericDefs */

/**
 * \defgroup LLCUartControllerSpecificDefs LLC Specific Definitions
 *
 * Definitions specific to this IP of the UART
 *
 * @{
 */

typedef struct
{
    Uint32              instId;
    /**< Instance number */
    CSL_UartRegsOvly    regs;
    /**< Register overlay */
    Uint32              intrNum;
    /**< Interrupt number */
    Uint32              txFifoCount;
    /**< TX Fifo counter - reflects currently available space in FIFO - maintained by the driver */
    LLC_UartHwConfig    *hwConfig;
    /**< Hardware configuration */
} LLC_UartObj, *LLC_UartHandle;

/* @} LLCUartControllerSpecificDefs */

/* @} LLCUartMain */

//#endif  /* _LLC_UARTTYPES_H_ */



#endif /*LLC_UARTTYPES_H_*/
