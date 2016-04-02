////jb comment out for current testing purposes
///*****************************************************************************
// * File Name : llc_uart.c
// *
// * Brief	 : UART Low level controller code. This file contains UART LLC code.
// *
// * Copyright (C) 2009 -2010 Texas Instruments Incorporated - http://www.ti.com/ 
// * 
// * 
// *  Redistribution and use in source and binary forms, with or without 
// *  modification, are permitted provided that the following conditions 
// *  are met:
// *
// *    Redistributions of source code must retain the above copyright 
// *    notice, this list of conditions and the following disclaimer.
// *
// *    Redistributions in binary form must reproduce the above copyright
// *    notice, this list of conditions and the following disclaimer in the 
// *    documentation and/or other materials provided with the   
// *    distribution.
// *
// *    Neither the name of Texas Instruments Incorporated nor the names of
// *    its contributors may be used to endorse or promote products derived
// *    from this software without specific prior written permission.
// *
// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
//******************************************************************************/
//
//#include "tistdtypes.h"
//#include "llc_uartIf.h"
//#include "llc_uartTypes.h"
//
//#define CSL_INTC_EVENTID_UARTINT	(0x09u) //HS: Caution: To be verified.
//
///*
// *================================
// * Prototypes of Static Functions
// *================================
// */
//
///*
// *=============================================
// * Definitions of Externally Visible Functions
// *=============================================
// */
//
///* Init UART LLC */
//void LLC_uartInit(
//                Ptr                 hUartObj,
//                Uint32              instId)
//{
//    Uint16 regs;
//    LLC_UartObj    *uartObj;
//
//    regs    = 0;
//    uartObj = (LLC_UartObj *)hUartObj;
//    uartObj->instId = instId;
//
//    /* Set the base address and interrupt number */
//    switch (uartObj->instId) {
//        case 0:
//            uartObj->intrNum = CSL_INTC_EVENTID_UARTINT;
//            regs = (Uint32)CSL_UART_REGS;
//            break;
//
//        default:
//            uartObj->intrNum = 0xFFFFu;
//            /* Large number outside interrut number range */
//            regs = 0;
//			break;
//    }
//    uartObj->regs = (CSL_UartRegsOvly)regs;
//    return;
//}
//
//
///* Hardware setup of UART LLC */
//void LLC_uartHwSetup(
//                LLC_UartHandle      hUart,
//                Ptr                 hHwConfig,
//                Bool                enableDma)
//{
//    Uint32  value;
//    LLC_UartHwConfig*  hwConfig;
//
//	hwConfig = (LLC_UartHwConfig*)hHwConfig;
//    hUart->hwConfig = hwConfig;
//
//    /* Set the divisor */
//    value = hwConfig->cfgBasic.moduleClock / \
//    (LLC_UART_BAUD_MULTIPLIER * hwConfig->cfgBasic.baudRate);
//
//	hUart->regs->PWREMU_MGMT |= 0x01u;
//
//    hUart->regs->DLL = (Uint8)(value & 0xFF);
//    hUart->regs->DLH = (Uint8) ((value & 0xFF00) >> 8);
//
//    /* Set the Fifo control - FIFO Disable not supported */
//    hUart->regs->FCR = 0; /* Clear FIFO counters */
//
//    value = 0;
//    if(hwConfig->cfgBasic.enableFifo == (Bool)TRUE)
//    {
//      value = (CSL_UART_FCR_FIFOEN_ENABLE);
//      /* | CSL_UART_FCR_TXCLR_MASK | CSL_UART_FCR_RXCLR_MASK);*/
//      switch (hwConfig->cfgBasic.rxThreshold)
//       {
//         case 1:
//            value |= 0x0;   /* Receive FIFO trigger level 1 byte */
//            break;
//         case 4:
//            value |= 0x40u;   /* Receive FIFO trigger level 4 byte */
//            break;
//         case 8:
//            value |= 0x80u;   /* Receive FIFO trigger level 8 byte */
//            break;
//         case 14:
//         default:
//            value |= 0xC0u;   /* Receive FIFO trigger level 14 byte */
//            break;
//       }
//    }
//    if(TRUE == enableDma)
//    {
//        value |= 0x0008u;
//    }
//
//    hUart->regs->FCR = value;
//
//    /* Set other parameters based upon configuration */
//    hUart->regs->MCR = 0;  /* modem control register not programmed */
//
//    value = ((Uint32) hwConfig->cfgBasic.charLen |
//             (Uint32) hwConfig->cfgBasic.numStopBits |
//             (Uint32) hwConfig->cfgBasic.parity);
//    hUart->regs->LCR = value;
//
//    hUart->regs->PWREMU_MGMT |= 0x01u;
//
//    return;
//}
//
///* Get interrupt number from LLC */
//Int LLC_uartGetIntrNum(Int deviceId)
//{
//    Uint32     intrNum;
//    Int        ret_intrNum;
//
//    intrNum     = 0;
//    ret_intrNum = 0;
//
//    switch (deviceId) {
//	    case 0:
//	        intrNum = CSL_INTC_EVENTID_UARTINT;
//	        break;
//
//	    default:
//	        intrNum = 0xFFFFFFFF; /* Error */
//			break;
//	    }
//
//    ret_intrNum = (Int)intrNum;
//    return (ret_intrNum);
//}
//
//void LLC_uartSetTxFifoCntFull(LLC_UartHandle hUart,Bool fifoEnabled)
//{
//    if(fifoEnabled != FALSE)
//    {
//       hUart->txFifoCount = LLC_UART_TX_FIFO_SIZE;
//    }
//    else
//    {
//      hUart->txFifoCount = 1u;
//    }
//}
//
///**
// * \defgroup LLCUartConfig LLC UART Configuration
// *
// * Interfaces for configuring the UART controller for a specific mode of
// * operation
// *
// * @{
// */
//void LLC_uartEnableLoopback(LLC_UartHandle hUart)
//{
//    LLC_UartRegister mcr;
//    mcr = hUart->regs->MCR;
//    mcr &= (~LLC_UART_LOOPBACK_MASK);
//    mcr |= LLC_UART_LOOPBACK_MASK;
//    hUart->regs->MCR = mcr;
//}
//
///**< Put the UART in loopback mode of operation.
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */
//void LLC_uartDisableLoopback(LLC_UartHandle hUart)
//{
//    LLC_UartRegister mcr;
//    mcr = hUart->regs->MCR;
//    mcr &= (~LLC_UART_LOOPBACK_MASK);
//    hUart->regs->MCR = mcr;
//}
//
///**< Take the UART out of loopback mode of operation.
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */
//void LLC_uartEnableParity(LLC_UartHandle hUart, Uint32 parity)
//{
//    LLC_UartRegister lcr;
//    lcr = hUart->regs->LCR;
//    lcr &= (~LLC_UART_PARITY_MASK);
//    lcr |= (Uint32)parity;
//    hUart->regs->LCR = lcr;
//}
//
///**< This enables parity generation and detection. Odd/ Even parity is
// * specified through the parameter.
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// * \param   parity  [IN]    {LLC_UartParity}
// *                              LLC_UART_PARITY_NONE: No Parity
// *                              LLC_UART_PARITY_ODD: Odd Parity,
// *                              LLC_UART_PARITY_EVEN: Even Parity           */
//void LLC_uartSetNumStopBits(LLC_UartHandle hUart, Uint32 numBits)
//{
//    LLC_UartRegister lcr;
//    lcr = hUart->regs->LCR;
//    lcr &= (~LLC_UART_STOP_BITS_MASK);
//    lcr |= (Uint32)numBits;
//    hUart->regs->LCR = lcr;
//}
//
///**< This programs the number of Stop bits to be used when transmitting
// * data and the same number to be assumed when receiving data.
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// * \param   numBits [IN]    {LLC_UartNumStopBits}   Number of stop bits,
// *                              LLC_UART_NUM_STOP_BITS_1: 1 Stop-bit,
// *                              LLC_UART_NUM_STOP_BITS_1_5: : 1.5 Stop-bits,
// *                              LLC_UART_NUM_STOP_BITS_2: : 2 Stop-bits     */
//void LLC_uartSetNumDataBits(LLC_UartHandle hUart, Uint32 numBits)
//{
//    LLC_UartRegister lcr;
//    lcr = hUart->regs->LCR;
//    lcr &= (~LLC_UART_NUM_DATA_BITS_MASK);
//    lcr |= (Uint32)numBits;
//    hUart->regs->LCR = lcr;
//}
//
///**< This programs the number of Data bits to be used when transmitting
// * data and the same number to be assumed when receiving data.
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// * \param   numBits [IN]    {LLC_UartNumDataBits}   Number of Data bits,
// *                              LLC_UART_NUM_DATA_BITS_5: 5 Data bits,
// *                              LLC_UART_NUM_DATA_BITS_6: 6 Data bits,
// *                              LLC_UART_NUM_DATA_BITS_7: 7 Data bits,
// *                              LLC_UART_NUM_DATA_BITS_8: 8 Data bits       */
//void LLC_uartSetBaudRate(LLC_UartHandle hUart, Uint32 baudRate)
//{
//        Uint32 value;
//        value = (Uint32)( (Uint32)(hUart->hwConfig->cfgBasic.moduleClock) / (Uint32)((Uint32)LLC_UART_BAUD_MULTIPLIER * (Uint32)baudRate) );
//        if (((((Uint32)(hUart->hwConfig->cfgBasic.moduleClock)) %
//        		((Uint32)baudRate))) > ((Uint32)(baudRate/2))) {
//            /* Rouding off required */
//            if ((value & 0xFF)  != 0xFF) {
//                hUart->regs->DLL = (Uint8)(value & 0xFF) + 1;
//                hUart->regs->DLH = (Uint8)((value & 0xFF00) >> 8);
//            } else {
//                hUart->regs->DLL = (Uint8)(value & 0xFF);
//                hUart->regs->DLH = (Uint8)(((value & 0xFF00) +1) >> 8);
//            }
//        } else {
//            /* Rounding off not required */
//            hUart->regs->DLL = (Uint8)(value & 0xFF);
//            hUart->regs->DLH = (Uint8)((value & 0xFF00) >> 8);
//        }
//}
//
///**< Set the baud rate at which the UART must operate in.
// * \param   hUart       [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// * \param   baudRate    [IN]    {Int}           Baud rate provided by upper layer
// */
///* @} LLCUartConfig */
//
///**
// * \defgroup LLCUartControl LLC UART Control
// *
// * Interfaces for controlling the operation of the UART controller when in a
// * specific mode of operation
// *
// * \note    Except for Reset none of the other operations are USED/SUPPORTED
// *          IN THIS DRIVER VERSION
// *
// * @{
// */
//void LLC_uartClearXmitterFifo(LLC_UartHandle hUart)
//{
//   hUart->regs->FCR |= LLC_UART_TX_FIFO_RESET;
//}
//
///**< Clear the Tx FIFO.
// * \param   hUart       [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// */
//void LLC_uartClearReceiverFifo(LLC_UartHandle hUart)
//{
//   hUart->regs->FCR |= LLC_UART_RX_FIFO_RESET;
//}
//
///**< Clear the Rx FIFO.
// * \param   hUart       [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// */
//
//void LLC_uartSetReceiverThreshold(LLC_UartHandle hUart, Uint32 threshold)
//{
//       hUart->regs->FCR |= threshold;
//}
//
///**< Set the Rx FIFO threshold.
// * \param   hUart       [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// * \param   threshold   [IN]    {Uint32} Threshold value for Rx FIFO
// */
//void LLC_uartReset(LLC_UartHandle hUart)
//{
//    volatile Uint32 cnt;
//
//    cnt = 10000u;
//		/* Reset Counter value */
////	*(ioport volatile unsigned *)0x1C04=0x2;
//
//	/* UART Module out of reset */
////	*(ioport volatile unsigned *)0x1C05&=0x7f;
//
///* changing parallel port mode to 5 - supports UART */
////	*(ioport volatile unsigned *)0x1C00=0x5000;
//
///* changing parallel port mode to 1 - supports UART */
////	*(ioport volatile unsigned *)0x1C00=0x1000;
//
//	/* changing parallel port mode to 4 - supports UART */
////	*(ioport volatile unsigned *)0x1C00=0x4000;
//
//    hUart->regs->PWREMU_MGMT = LLC_UART_RESET;
//    while (--cnt > 0)
//    {
//        ;
//    }
//   // hUart->regs->PWREMU_MGMT = LLC_UART_UNRESET | 0xE003u ;
//   hUart->regs->PWREMU_MGMT |= 0xE000;
//}
//
///**< This resets the UART and brings it out of reset
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object  */
//void LLC_uartEnableHwFlowControl(LLC_UartHandle hUart)
//{
//    LLC_UartRegister mcr;
//    mcr = hUart->regs->MCR;
//    mcr &= (~LLC_UART_HW_FLOW_CONTROL_MASK);
//    mcr |= LLC_UART_HW_FLOW_CONTROL_ENABLE;
//    hUart->regs->MCR = mcr;
//}
//
///**< This enables the hardware flow control for the UART - the hardware supports
// *   auto rts/cts functionality
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */
//void LLC_uartDisableHwFlowControl(LLC_UartHandle hUart)
//{
//    LLC_UartRegister mcr;
//    mcr = hUart->regs->MCR;
//    mcr &= (~LLC_UART_HW_FLOW_CONTROL_MASK);
//    hUart->regs->MCR = mcr;
//}
//
///**< This disables the hardware flow control for the UART - the hardware supports
// *   auto rts/cts functionality
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */
//Uint32 LLC_uartRead(LLC_UartHandle hUart)
// {
//    Uint32  dummy;
//
//    while ((LLC_uartGetLineStatus(hUart)) & LLC_UART_RX_LINE_ERR_MASK)
//    {
//        dummy = hUart->regs->RBR;
//        dummy = dummy;
//    }
//
//    return (hUart->regs->RBR);
// }
//
//Int LLC_uartStatusIsLineError(LLC_UartHandle hUart)
//{
//    Uint32 status;
//
//    status = LLC_uartGetLineStatus(hUart);
//
//    return (Int) ((status & CSL_UART_LSR_RXFIFOE_MASK ) ? 1 : 0);
//}
//
//Int LLC_uartHandleRxError(LLC_UartHandle hUart)
//{
//    return (LLC_uartStatusIsLineError(hUart));
//}
//
//Int LLC_uartStatusIsDataReady(LLC_UartHandle hUart)
//{
//    Uint32 status;
//
//    status = LLC_uartGetLineStatus(hUart);
//
//    /* Added for error checks */
//    if ( (status & CSL_UART_LSR_RXFIFOE_MASK) != FALSE )
//    {
//        LLC_uartHandleRxError(hUart);
//    }
//
//    return (Int) ((status & CSL_UART_LSR_DR_MASK ) ? 1 : 0);
//}
//
///**< Return 1 if data ready
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */
//void LLC_uartWrite(LLC_UartHandle hUart, Char ch)
//{
//    --hUart->txFifoCount;
//    //hUart->regs->THR = (Uint32)ch;
//	hUart->regs->RBR = (Uint32)ch;
//}
//
///**< This define writes the character to the UART transmit holding register and
// *   decremens the Tx FIFO count
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object   */
//Int LLC_uartIntrIsXmitterEmpty(LLC_UartHandle hUart)
//{
//    LLC_UartIntrStatus  status;
//
//    status = LLC_uartGetLineStatus(hUart);
//    return (Int) (((status & CSL_UART_LSR_TEMT_MASK) == CSL_UART_LSR_TEMT_MASK) ? 1: 0);
//}
//
///**< Return 1 if transmitter is empty */
//Int LLC_uartIntrIsPending(LLC_UartHandle hUart)
//{
//    Uint32 status;
//
//    status = hUart->regs->IIR & 0xFu;
//    if( (status & 0x1u) != (Bool)FALSE)
//    {
//        status = 0;
//    }
//    else
//    {
//        status = 1u;
//    }
//    return (Int)(status);
//}
//
///**< Return status of pending interrupt */
//void LLC_uartIntrEnable(LLC_UartHandle hUart, LLC_UartRegister bitmask)
//{
//    LLC_UartRegister temp;
//
//    temp = hUart->regs->IER;
//    temp |= (bitmask & 0xFFu);
//    hUart->regs->IER = temp;
//}
//
///**< This enables the UART interrupt as per mask
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// * \param   bitmask [IN]    Mask for interrupt enable                       */
//void LLC_uartIntrDisable(LLC_UartHandle hUart, LLC_UartRegister bitmask)
//{
//    LLC_UartRegister    temp;
//
//    temp = hUart->regs->IER;
//    temp &= (~bitmask);
//    hUart->regs->IER = temp & 0xFFu;
//}
//
///**< This disables the UART interrupt as per mask
// * \param   hUart   [IN]    {LLC_UartObj *} Handle to the LLC Uart Object
// * \param   bitmask [IN]    Mask for interrupt disable                      */
//void LLC_uartClearLineStatus(LLC_UartHandle hUart)
//{
//    while (LLC_uartStatusIsLineError(hUart))
//    {
//        volatile Char   tempChar = (Char)LLC_uartRead(hUart);
//    }
//}
///* End of file. */
//
