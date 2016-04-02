#ifndef LLC_UARTIF_H_
#define LLC_UARTIF_H_

/*****************************************************************************
 * File Name : llc_uartIf.h 
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


//#ifndef _LLC_UARTIF_H
//#define _LLC_UARTIF_H

#include "llc_uartTypes.h"

/**
 * \defgroup LLCUartMain LLC UART Interface Definition
 *
 * Top-level Encapsulation of all documentation for UART LLC
 *
 * @{
 */

/**
 * \defgroup LLCUartInterfaces LLC UART Interfaces
 *
 * Interfaces exported by the LLC, which are used to setup or operate the
 * controller in a specific mode of operation and in a specific manner
 *
 * @{
 */

#define LLC_UART_LOOPBACK_MASK 0x10u

#define LLC_UART_TRANSMITTER_EMPTY  0x40u

#define LLC_UART_PARITY_MASK 0x18

#define LLC_UART_STOP_BITS_MASK     0x4

#define LLC_UART_NUM_DATA_BITS_MASK 0x3

#define LLC_UART_TX_FIFO_RESET    0x04u
/*#define LLC_uartClearXmitterFifo(hUart)                                     \
    do {                                                                    \
    } while(0)*/
/**< *** NOT USED/SUPPORTED IN THIS DRIVER VERSION ***  */

#define LLC_UART_RX_FIFO_RESET    0x02u
/*#define LLC_uartClearReceiverFifo(hUart)                                    \
    do {                                                                    \
    } while(0)*/
/**< *** NOT USED/SUPPORTED IN THIS DRIVER VERSION ***  */

#define LLC_UART_UNRESET                    0x8000u
#define LLC_UART_RESET                      0x0

/* @} LLCUartControl */

/**
 * \defgroup LLCUartIo LLC UART IO
 *
 * Interfaces for performing IO operations and for obtaining the status of
 * an IO operation
 *
 * @{
 */

#define LLC_UART_HW_FLOW_CONTROL_ENABLE     0x22u
#define LLC_UART_HW_FLOW_CONTROL_MASK       0x20u

#define LLC_uartGetLineStatus(hUart)    ((hUart)->regs->LSR)
/**< Get line status
 * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */

/**< This define reads the UART receive buffer registers and returns the read char
 * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */

 #define LLC_UART_RX_LINE_ERR_MASK      (CSL_UART_LSR_PE_MASK | CSL_UART_LSR_FE_MASK | CSL_UART_LSR_BI_MASK)

 #define LLC_uartStatusIsXmitterFull(hUart)  (((hUart)->txFifoCount > 0) ? 0 : 1)
/**< This returns the transmitter full status
 * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */

#define LLC_uartStatusIsOverrunError(hUart, status)     /**< *** NOT USED IN THIS DRIVER VERSION *** */
#define LLC_uartStatusIsParityError(hUart, status)      /**< *** NOT USED IN THIS DRIVER VERSION *** */
#define LLC_uartStatusIsFrameError(hUart, status)       /**< *** NOT USED IN THIS DRIVER VERSION *** */
#define LLC_uartStatusIsBreakInd(hUart, status)         /**< *** NOT USED IN THIS DRIVER VERSION *** */

/* @} LLCUartIo */

/**
 * \defgroup LLCUartIntr LLC UART Interrupt Control
 *
 * Interfaces for controlling the Interrupt generation and handling and for
 * obtaining the status of an interrupt condition
 *
 * @{
 */

#define LLC_uartIntrGetStatus(hUart)   ((hUart)->regs->IIR & 0xFu)
/**< Get interrupt status */

#define LLC_UART_RX_LINE_STATUS_INT         0x6u
#define LLC_uartIntrIsReceiverLineError(hUart, status)  (((status) == (Uint32)LLC_UART_RX_LINE_STATUS_INT) ? 1 : 0)
/**< Return 1 if receiver line error */


#define LLC_UART_RX_DATA_AVAILABLE_INT      0x4u
#define LLC_uartIntrIsDataReceived(hUart, status)       (((status) == LLC_UART_RX_DATA_AVAILABLE_INT) ? 1 : 0)
/**< Return 1 if data received */


#define LLC_UART_RX_CHAR_TIMEOUT_INT        0xCu
#define LLC_uartIntrIsCharacterTimeout(hUart, status)   (((status) == LLC_UART_RX_CHAR_TIMEOUT_INT) ? 1 : 0)
/**< Return 1 if character timeout occured */


#define LLC_UART_TX_HOLDING_REG_EMPTY_INT   0x2u
#define LLC_uartIntrIsXmitterHoldingRegEmpty(hUart, status)   (((status) == LLC_UART_TX_HOLDING_REG_EMPTY_INT) ? 1 : 0)
/**< Return 1 if character timeout occured */

#define LLC_UART_MODEMSTAT_INT              0x0
#define LLC_uartIntrIsModemStatus(hUart, status)        (((status) == LLC_UART_MODEMSTAT_INT) ? 1 : 0)
/**< Return 1 if modem status event occured */

#define LLC_uartIntrIsSpecialChar(hUart, status)        0
/**< Special character identification not supported - return 0 always */

#define _LLC_UART_LCR_STORE(val)        /**< *** NOT USED IN THIS DRIVER VERSION *** */
#define _LLC_UART_LCR_RESTORE(val)      /**< *** NOT USED IN THIS DRIVER VERSION *** */
#define _LLC_UART_SETLCR_BF             /**< *** NOT USED IN THIS DRIVER VERSION *** */
#define _LLC_UART_SETLCRBIT7_0          /**< *** NOT USED IN THIS DRIVER VERSION *** */
#define _LLC_UART_SETLCRBIT7_1          /**< *** NOT USED IN THIS DRIVER VERSION *** */

#define LLC_uartModemSetDtr(hUart, flag)                /**< *** NOT SUPPORTED IN THIS DRIVER VERSION *** */
#define LLC_uartModemSetRts(hUart, flag)                /**< *** NOT SUPPORTED IN THIS DRIVER VERSION *** */
#define LLC_uartModemSetRi(hUart, flag)                 /**< *** NOT SUPPORTED IN THIS DRIVER VERSION *** */
#define LLC_uartModemSetDcd(hUart, flag)                /**< *** NOT SUPPORTED IN THIS DRIVER VERSION *** */
#define LLC_uartEnableAutoFlowControl(hUart, flag)      /**< *** NOT SUPPORTED IN THIS DRIVER VERSION *** */
#define LLC_uartModemGetStatus(hUart, bitmap)           /**< *** NOT SUPPORTED IN THIS DRIVER VERSION *** */

/* @} LLCUartModem */

/**
 * \defgroup LLCUartDma LLC UART DMA Operation and Control
 *
 * NOT SUPPORTED IN THIS DRIVER VERSION
 *
 * Interfaces for programming the DMA and for obtaining the status of a
 * specific DMA channel
 *
 * @{
 */

extern Int  LLC_uartGetIntrNum(
                Int                     deviceId);
extern void LLC_uartInit(
                Ptr                     uartObj,
                Uint32                  instId);
extern void LLC_uartHwSetup(
                LLC_UartHandle      hUart,
                Ptr                 hHwConfig,
                Bool                enableDma);


/**< This clears the line status
 * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */


/* @} LLCUartIntr */

extern  void LLC_uartClearXmitterFifo(LLC_UartHandle hUart);

extern  void LLC_uartClearReceiverFifo(LLC_UartHandle hUart);

extern  void LLC_uartSetReceiverThreshold(LLC_UartHandle hUart, Uint32 threshold);


extern  void LLC_uartReset(LLC_UartHandle hUart);

extern  void LLC_uartEnableHwFlowControl(LLC_UartHandle hUart);

extern  void LLC_uartDisableHwFlowControl(LLC_UartHandle hUart);

extern  Uint32 LLC_uartRead(LLC_UartHandle hUart);

extern void LLC_uartEnableLoopback(LLC_UartHandle hUart);

extern void LLC_uartEnableParity(LLC_UartHandle hUart, Uint32 parity);

extern void LLC_uartSetNumStopBits(LLC_UartHandle hUart, Uint32 numBits);

extern void LLC_uartDisableLoopback(LLC_UartHandle hUart);

extern void LLC_uartSetTxFifoCntFull(LLC_UartHandle hUart,Bool fifoEnabled);

extern  Int LLC_uartStatusIsLineError(LLC_UartHandle hUart);

extern  Int LLC_uartHandleRxError(LLC_UartHandle hUart);

extern  Int LLC_uartStatusIsDataReady(LLC_UartHandle hUart);

extern  void LLC_uartWrite(LLC_UartHandle hUart, Char ch);

extern  Int LLC_uartIntrIsXmitterEmpty(LLC_UartHandle hUart);

extern  Int LLC_uartIntrIsPending(LLC_UartHandle hUart);

extern  void LLC_uartIntrEnable(LLC_UartHandle hUart, LLC_UartRegister bitmask);

extern void LLC_uartIntrDisable(LLC_UartHandle hUart, LLC_UartRegister bitmask);


extern  void LLC_uartClearLineStatus(LLC_UartHandle hUart);

extern void LLC_uartSetBaudRate(LLC_UartHandle hUart, Uint32 baudRate);

extern void LLC_uartSetNumDataBits(LLC_UartHandle hUart, Uint32 numBits);

/* @} LLCUartInterfaces */

/* @} LLCUartMain */

//#endif  /* _LLC_UARTIF_H_ */



#endif /*LLC_UARTIF_H_*/
