//jb comment out for building purposes
///*****************************************************************************
// * File Name : ddc_uart.c
// *
// * Brief	 : This file contains UART Driver Core
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
//#include "psp_common.h"
//#include "pal_osProtect.h"
//#include "pal_osWait.h"
//#include "pal_oscache.h"
//#include "dda_uart.h"
//#include "ddc_uart.h"
//#include "util_circ.h"
//#include "llc_uartIf.h"
//#include "llc_uartTypes.h"
//#include "pal_ostime.h"
//
//#ifdef PSP_UART_CONFIG_CHUNK
//#define CHUNK       PSP_UART_CONFIG_CHUNK
//#else
//#define CHUNK       16
//#endif
//
//#ifdef PSP_UART_CONFIG_RX_RE_ENABLE_COUNT
//#define RX_RE_ENABLE_COUNT      PSP_UART_CONFIG_RX_RE_ENABLE_COUNT
//#else
//#define RX_RE_ENABLE_COUNT      8
//#endif
//
//extern Bool checkDmaTimeout;
//
//#define UART_DDC_MIN(x,y)    ( ((x) < (y)) ? (x) : (y) )
//
///**
// *  \brief clears the DDC error stats
// *
// *  This function clears the stats of the DDC and clears them
// *
// *  \param  DDC [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static void clearStats(Ptr hDDC);
//
///**
// *  \brief Receiver ISR
// *
// *  This function is the Receiver ISR.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static void ddc_uartRxIntrHandler(DDC_UartHandle DDC);
//
///**
// *  \brief Transmit ISR
// *
// *  This function is the Transmitter ISR.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static void ddc_uartTxIntrHandler(DDC_UartHandle DDC);
//
///**
// *  \brief Receiver Errors
// *
// *  This function finds errors on the Receiver buffer.
// *
// *  \param  hDDC    [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static PAL_Result ddc_uartHandleRxError(DDC_UartHandle  hDDC);
//
///**
// *  \brief Cancels all Receiver iops
// *
// *  This function cancels on the Receiver list.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *  \param  flag    [IN]            flag passed depending upon the Flush or Abort
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static PAL_Result ddc_uartCancelAllRxIo(DDC_UartHandle DDC, Int flag);
//
///**
// *  \brief Cancels all Transmitter iops
// *
// *  This function cancels on the Transmitter list.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *  \param  flag    [IN]            flag passed depending upon the Flush or Abort
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static PAL_Result ddc_uartCancelAllTxIo(DDC_UartHandle DDC, Int flag);
//
///**
// *  \brief Read multiple characters
// *
// *  Read Multiple characters from hardware and returns the no. of bytes read
// *
// *  \param  hUart    [IN]    UART Driver Instance Handle
// *  \param  buf      [IN]    Character Buffer pointer
// *  \param  bufSize  [IN]    Size of character buffer
// *
// *  \return Number of bytes read
// *
// */
//static Int ddc_uartReadMultiple(LLC_UartHandle hUart, Char *buf,Int bufSize);
//
///**
// *  \brief Write multiple characters
// *
// *  Write Multiple characters to hardware and returns the no. of btyes written
// *
// *  \param  hUart    [IN]    UART Driver Instance Handle
// *  \param  buf      [IN]    Character Buffer pointer
// *  \param  nwrite   [IN]    Number of characters to write
// *
// *  \return Number of bytes written
// *
// */
//static Int ddc_uartWriteMultiple(LLC_UartHandle hUart, const Char *buf, Int nwrite);
//
///**
// *  \brief Notify Completion function
// *
// *  \param  hIop   [IN]    Iop pointer
// *  \param  result [IN]    Result
// *
// *  \return Number of bytes written
// *
// */
//static void notifyCompletion(Ptr hIop, PAL_Result result);
//
//
///**
// *  \brief Read multiple characters
// *
// *  Read Multiple characters from hardware and returns the no. of bytes read
// *
// *  \param  hUart    [IN]    UART Driver Instance Handle
// *  \param  buf      [IN]    Character Buffer pointer
// *  \param  bufSize  [IN]    Size of character buffer
// *
// *  \return Number of bytes read
// *
// */
//static Int ddc_uartReadMultiple(LLC_UartHandle hUart, Char *buf,Int bufSize)
//{
//    Int size;
//
//    size = bufSize;
//
//    if((NULL != hUart) && (NULL != buf))
//    {
//        for (;;)
//        {
//            /* writing to specified location by the user once the H/w is ready*/
//            if ((LLC_uartStatusIsDataReady(hUart) != FALSE) && (bufSize != 0) )
//            {
//                *buf = (Char)LLC_uartRead(hUart); /* reading from the H/w*/
//                buf++;
//                --bufSize;
//            }
//            else
//            {
//                break; /* return back the control */
//            }
//        }
//    }
//    return (size - bufSize);
//}
//
///**
// *  \brief Write multiple characters
// *
// *  Write Multiple characters to hardware and returns the no. of btyes written
// *
// *  \param  hUart    [IN]    UART Driver Instance Handle
// *  \param  buf      [IN]    Character Buffer pointer
// *  \param  nwrite   [IN]    Number of characters to write
// *
// *  \return Number of bytes written
// *
// */
//static Int ddc_uartWriteMultiple(LLC_UartHandle hUart, const Char *buf, Int nwrite)
//{
//    Int size;
//
//    size = nwrite;
//
//    if( (hUart != NULL) && (buf != NULL) )
//    {
//        for (;;)
//        {
//            if ((LLC_uartStatusIsXmitterFull(hUart) == FALSE) && (nwrite != 0))
//            {
//                LLC_uartWrite(hUart, *buf); /* Writing to the H/w */
//                buf++;
//                nwrite--;
//            }
//            else
//            {
//                break; /* return back the control */
//            }
//        }
//    }
//    /* Returns the size actually written */
//    return (size - nwrite);
//}
//
///**
// *  \brief Notify Completion function
// *
// *  \param  hIop   [IN]    Iop pointer
// *  \param  result [IN]    Result
// *
// *  \return Number of bytes written
// *
// */
//static void notifyCompletion(Ptr hIop, PAL_Result result)
//{
//    DDC_UartIoPacket      *iop;
//    DDC_UartObj           *DDC;
//
//    iop = NULL;
//    DDC = NULL;
//
//    if(hIop != NULL)
//    {
//        iop = (DDC_UartIoPacket*)hIop;
//        DDC = (DDC_UartObj *)(iop->hDDC);
//        if (result == PAL_SOK)
//        {
//           iop->xferActual = iop->xferRequest;
//        }
//
//        iop->result = result;
//
//        /* makes a call to the callback function in the IOM Layer */
//        _DDA_uartIoComplete(DDC->hDDA, iop);
//    }
//    return;
//}
//
///* ARGSUSED */
///**
// *  \brief Instance of DDC Created
// *
// *  This function creates the instance of the DDC
// *
// *  \param  instId [IN]         Instance id of the Uart
// *  \param  hDDA [IN]           Handle of the Upper layer
// *  \param  hDDC [IN]           Handle of the DDC Object
// *  \param  param [IN]          User Parameters for further use
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartCreateInstance(
//            Uint32                     instId,
//            DDA_UartHandle              hDDA,
//            DDC_UartHandle              hDDC,
//            Ptr                     param)
//{
//    DDC_UartObj         *DDC;
//    PAL_Result          retVal;
//
//    DDC    = NULL;
//    retVal = PAL_SOK;
//
//    if( ( (instId > PSP_UART_NUM_INSTANCES ) || (hDDC == NULL) ) || (hDDA == NULL) )
//    {
//        retVal = PSP_E_INVAL_PARAM;
//    }
//    else
//    {
//        DDC = (DDC_UartObj *)(hDDC);
//        /* Assignment of the function pointers */
//        DDC->hDDA = hDDA;
//        DDC->instId = instId;
//        DDC->state = PSP_DRIVER_STATE_CREATED;
//        DDC->versionId = 0xFFFFFFFF;
//    }
//    return(retVal);
//}
//
///* ARGSUSED */
///**
// *  \brief Instance of DDC Deleted
// *
// *  This function deletes the instance of the DDC
// *
// *  \param  hDDC [IN]           Handle of the DDC Object
// *  \param  param [IN]          User Parameters for further use
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartDelInst(
//            DDC_UartHandle  hDDC,
//            Ptr         param)
//{
//    PAL_Result  result;
//    DDC_UartObj *DDC;
//
//    result = PAL_SOK;
//    DDC    = NULL;
//
//    if(hDDC != NULL)
//    {
//        DDC = (DDC_UartObj *)hDDC;
//        DDC->state = PSP_DRIVER_STATE_DELETED;
//    }
//    else
//    {
//        result = PSP_E_INVAL_PARAM;
//    }
//
//    return (result);
//}
//
///**
// *  \brief Instance of DDC Initiated
// *
// *  This function initiates the instance of the DDC
// *
// *  \param  hDDC [IN]           Handle of the DDC Object
// *  \param  param [IN]          User Parameters for further use
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartInit(
//            DDC_UartHandle  hDDC,
//            Ptr         param)
//{
//    PAL_Result          result;
//    DDC_UartObj         *DDC;
//    DDC_UartInitConfig  *initConfig;
//
//    result     = PAL_SOK;
//    DDC        = NULL;
//    initConfig = NULL;
//
//    if ((hDDC == NULL) && (param != NULL))
//    {
//        result = PSP_E_INVAL_PARAM;
//    }
//    else
//    {
//        DDC = (DDC_UartObj *)hDDC;
//        initConfig = (DDC_UartInitConfig *)param;
//        if (DDC->state != PSP_DRIVER_STATE_CREATED)
//        {
//            result = PSP_E_INVAL_PARAM;
//        }
//        else
//        {
//            if ((PSP_OPMODE_DMAINTERRUPT != initConfig->opMode) &&
//                ((PSP_OPMODE_INTERRUPT != initConfig->opMode) &&
//                (PSP_OPMODE_POLLED != initConfig->opMode)) )
//            {
//                result =  PSP_E_INVAL_PARAM;
//            }
//            else
//            {
//                /* Assignment of the mode to the DDC Layer */
//                DDC->opMode = initConfig->opMode;
//
//                /* Clearing the global stats for the read/write operation */
//                clearStats(DDC);
//
//                /* creating the receive/transmission list */
//                PAL_OSLIST_MKNODE(&DDC->rxPendListHeadNode);
//                PAL_OSLIST_MKNODE(&DDC->txPendListHeadNode);
//
//                /* Creating the internal circular Buffer */
//                UTIL_circNew(initConfig->hRxCirc, initConfig->rxBuf, initConfig->rxBufSize);
//                UTIL_circNew(initConfig->hTxCirc, initConfig->txBuf, initConfig->txBufSize);
//
//                /* Assigning params to the DDC layer */
//                DDC->hRxCirc = initConfig->hRxCirc;
//                DDC->hTxCirc = initConfig->hTxCirc;
//                DDC->msecPoll = initConfig->msecPoll;
//                DDC->rxActiveIop = NULL;
//                DDC->txActiveIop = NULL;
//                DDC->txInProgress = False;
//                DDC->hEdma = initConfig->hEdma;
//
//                /* Initiating the LLC layer and updating the state */
//                LLC_uartInit(initConfig->llc, DDC->instId);
//                DDC->llc = initConfig->llc;
//                DDC->state = PSP_DRIVER_STATE_INITIALIZED;
//            }
//        }
//    }
//    return (result);
//}
//
///* ARGSUSED */
///**
// *  \brief Instance of DDC De-Initiated
// *
// *  This function de-initiates the instance of the DDC
// *
// *  \param  hDDC [IN]           Handle of the DDC Object
// *  \param  param [IN]          User Parameters for further use
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartDeInit(
//            DDC_UartHandle  hDDC,
//            Ptr         param)
//{
//    PAL_Result  result;
//    DDC_UartObj *DDC;
//
//    result = PAL_SOK;
//    DDC    = NULL;
//
//    if(hDDC != NULL)
//    {
//        DDC = (DDC_UartObj *)hDDC;
//        /* Check for the state */
//        if ((DDC->state != PSP_DRIVER_STATE_INITIALIZED)
//                && (DDC->state != PSP_DRIVER_STATE_CLOSED))
//        {
//            result =  (PSP_E_INVAL_STATE);
//        }
//        else
//        {
//            DDC->state = PSP_DRIVER_STATE_DEINITIALIZED;
//        }
//    }/* Check for DDC object */
//    else
//    {
//        result =  (PSP_E_INVAL_STATE);
//    }
//    return (result);
//}
//
///* ARGSUSED */
///**
// *  \brief Instance of DDC opened
// *
// *  This function open the instance of the DDC and sets up the H/W
// *
// *  \param  hDDC [IN]           Handle of the DDC Object
// *  \param  param [IN]          User Parameters for further use
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartOpen(
//            DDC_UartHandle  hDDC,
//            Ptr         param)
//{
//    PAL_Result      result;
//    DDC_UartObj         *DDC;
//    DDC_UartOpenParams  *openParams;
//    LLC_UartRegister    intrBitmask;
//
//    result      = PAL_SOK;
//    DDC         = NULL;
//    openParams  = NULL;
//    intrBitmask = 0;
//
//    if((hDDC != NULL) && (param != NULL))
//    {
//        DDC = (DDC_UartObj *)hDDC;
//        openParams = (DDC_UartOpenParams *)param;
//        if ((DDC->state != PSP_DRIVER_STATE_INITIALIZED)  &&
//            (DDC->state != PSP_DRIVER_STATE_CLOSED))
//        {
//          result = PSP_E_INVAL_STATE;
//        }
//
//        if ((DDC->opMode == PSP_OPMODE_DMAINTERRUPT) &&
//            (openParams->hwConfig->cfgBasic.enableLoopback == TRUE))
//        {
//            result = PSP_E_INVAL_PARAM;
//        }
//
//            if(result == PAL_SOK)
//            {
//                Bool enableDma = FALSE;
//
//                /* Reset UART and setup hardware params */
//                LLC_uartReset(DDC->llc);
//                if (PSP_OPMODE_DMAINTERRUPT == DDC->opMode) {
//                    enableDma = TRUE;
//                }
//                LLC_uartHwSetup(DDC->llc, openParams->hwConfig, enableDma);
//
//                /* Disable all interrupts */
//                LLC_uartIntrDisable(DDC->llc, 0xFFu);
//
//                /* If the set parameters set the H/w Flowcontrol */
//                if (openParams->hwConfig->cfgFlowControl.fcType == LLC_UART_FLOWCONTROL_HW)
//                {
//                   /* Call to LLC layer */
//                    LLC_uartEnableHwFlowControl(DDC->llc);
//                }
//
//                /* In Fifo mode if TX or RX interrupts are disabled, the operation becomes
//                 * Fifo polled mode automatically - though TX and RX operation is separate
//                 * and either can be in polled mode */
//
//                /* Disable Receive Status IRQ - (LLC_UART_INTR_RLS); */
//                intrBitmask = LLC_UART_INTR_MS;
//
//                if (DDC->opMode == PSP_OPMODE_INTERRUPT)
//                {
//                    intrBitmask |= LLC_UART_INTR_RHR;
//                }
//
//                if (DDC->opMode != PSP_OPMODE_POLLED)
//                {
//                    LLC_uartIntrEnable(DDC->llc, intrBitmask);
//                }
//
//                DDC->fifoEnabled  = openParams->hwConfig->cfgBasic.enableFifo;
//                /* Enable Loopback */
//                if(openParams->hwConfig->cfgBasic.enableLoopback == (Bool)TRUE)
//                {
//                    LLC_uartEnableLoopback(DDC->llc);
//                }
//
//                DDC->state = PSP_DRIVER_STATE_OPENED;
//            }
//    } /* Check for DDC Object */
//    else
//    {
//        result = PSP_E_INVAL_PARAM;
//    }
//
//    return (result);
//}
//
///* ARGSUSED */
///**
// *  \brief Instance of DDC closed
// *
// *  This function close the instance of the DDC and releases the Handle
// *
// *  \param  hDDC [IN]           Handle of the DDC Object
// *  \param  param [IN]          User Parameters for further use
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartClose(
//            DDC_UartHandle  hDDC,
//            Ptr         param)
//{
//    PAL_Result  result;
//    DDC_UartObj *DDC;
//    Uint32 status;
//
//    result = PAL_SOK;
//    DDC    = NULL;
//    status = 0;
//
//    if(hDDC != NULL)
//    {
//        DDC = (DDC_UartObj *)hDDC;
//        status = LLC_uartGetLineStatus(DDC->llc);
//        while(  ( status & LLC_UART_TRANSMITTER_EMPTY  ) == 0  )
//        {
//            status = LLC_uartGetLineStatus(DDC->llc);
//        }
//
//        if (DDC->state != PSP_DRIVER_STATE_OPENED)
//        {
//            result = PSP_E_INVAL_STATE;
//        }
//        else
//        {
//            DDC->state = PSP_DRIVER_STATE_CLOSED;
//        }
//    }
//    else
//    {
//        result = PSP_E_INVAL_STATE;
//    }
//
//    return (result);
//}
//
///* ARGSUSED */
///**
// *  \brief Instance of DDC control
// *
// *  This function control the instance of the DDC and make the corresponding
// *  changes in the Hardware
// *
// *  \param  hDDC [IN]           Handle of the DDC Object
// *  \param  cmd [IN]            IOCTL command for DDC
// *  \param  cmdArg [IN]         Additional argument for the IOCTL
// *  \param  param [IN]          User Parameters for further use
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartControl(
//            DDC_UartHandle  hDDC,
//            Uint32         cmd,
//            Ptr         cmdArg,
//            Ptr         param)
//{
//    PAL_Result  result;
//    DDC_UartObj *DDC;
//
//    result = PAL_SOK;
//    DDC    = NULL;
//
//     if(hDDC != NULL)
//     {
//        DDC = (DDC_UartObj *)hDDC;
//
//        /* If the state is invalid */
//        if (DDC->state != PSP_DRIVER_STATE_OPENED)
//        {
//            result =  (PSP_E_INVAL_STATE);
//        }
//        else
//        {
//            switch (cmd)
//            {
//                case DDC_UART_IOCTL_SET_OPMODE:
//                    if (NULL != cmdArg) {
//                        /* Setting the opmode */
//                        DDC->opMode = *(PSP_OpMode *)cmdArg;
//                    } else {
//                        result = PSP_E_INVAL_PARAM;
//                    }
//                    break;
//
//                case DDC_UART_IOCTL_SET_BAUD_RATE:
//                    if (NULL != cmdArg) {
//                        /* Setting the baud rate  */
//                        LLC_uartSetBaudRate(DDC->llc, *(Uint32 *)cmdArg);
//                    } else {
//                        result = PSP_E_INVAL_PARAM;
//                    }
//                    break;
//
//                case DDC_UART_IOCTL_SET_CHARLEN:
//                    if (NULL != cmdArg) {
//                        /* Setting the character length */
//                        LLC_uartSetNumDataBits(DDC->llc, (Uint32) *(Int *)cmdArg);
//                    } else {
//                        result = PSP_E_INVAL_PARAM;
//                    }
//                    break;
//
//                case DDC_UART_IOCTL_SET_PARITY:
//                    if (NULL != cmdArg) {
//                        /* Setting the parity */
//                        LLC_uartEnableParity(DDC->llc, (Uint32) *(Int *)cmdArg);
//                    } else {
//                        result = PSP_E_INVAL_PARAM;
//                    }
//                    break;
//
//                case DDC_UART_IOCTL_SET_NUM_STOP_BITS:
//                    if (NULL != cmdArg) {
//                        /* Setting the stop bits */
//                        LLC_uartSetNumStopBits(DDC->llc, (Uint32) *(Int *)cmdArg);
//                    } else {
//                        result = PSP_E_INVAL_PARAM;
//                    }
//                    break;
//
//                case DDC_UART_IOCTL_SET_LOOPBACK:
//                    if (NULL != cmdArg) {
//                        /* Enabling/Disabling Loopback */
//                        if ( (*(Int *)cmdArg) != FALSE)
//                        {
//                           LLC_uartEnableLoopback(DDC->llc);
//                        }
//                        else
//                        {
//                           LLC_uartDisableLoopback(DDC->llc);
//                        }
//                    }
//                    else {
//                        result = PSP_E_INVAL_PARAM;
//                    }
//                    break;
//
//                case DDC_UART_IOCTL_GET_STATS:
//                    if (NULL != cmdArg) {
//                        ((DDC_UartStats *)cmdArg)->rxBytes  = DDC->stats.rxBytes;
//                        ((DDC_UartStats *)cmdArg)->txBytes  = DDC->stats.txBytes;
//                        ((DDC_UartStats *)cmdArg)->errors   = DDC->stats.errors;
//                        ((DDC_UartStats *)cmdArg)->nefc     = DDC->stats.nefc;
//                        ((DDC_UartStats *)cmdArg)->fefc     = DDC->stats.fefc;
//                        ((DDC_UartStats *)cmdArg)->overrun  = DDC->stats.overrun;
//                        ((DDC_UartStats *)cmdArg)->rxTimeout= DDC->stats.rxTimeout;
//                    } else {
//                        result = PSP_E_INVAL_PARAM;
//                    }
//                    break;
//
//                case DDC_UART_IOCTL_SET_STATSCLEAR:
//                    /* Getting the stats */
//                    clearStats(DDC);
//                    break;
//
//                case DDC_UART_IOCMD_ABORT:
//                case DDC_UART_IOCTL_CANCEL_IO:
//                    /* Cancel all the IO's in the Rx pending list */
//                    ddc_uartCancelAllRxIo(DDC, DDC_UART_ABORT);
//                    /* Cancel all the IO's in the Tx pending list */
//                    ddc_uartCancelAllTxIo(DDC, DDC_UART_ABORT);
//                    break;
//                case DDC_UART_IOCMD_FLUSH:
//                /* Cancel all the IO's in the Rx pending list */
//                    ddc_uartCancelAllRxIo(DDC, DDC_UART_FLUSH);
//
//                break;
//                default:
//                    break;
//            }
//        }
//     }/* Check for DDC Object */
//     else
//     {
//        result = PSP_E_INVAL_STATE;
//     }
//
//    return (result);
//}
//
///**
// *  \brief Read/Write operation are performed
// *
// *  This function read/write function as requested by the application
// *  corresponding to iop packets as requeseted in all the modes i.e.
// *  POLLED/INTERRUPT.
// *
// *  \param  hDDC [IN]           Handle of the DDC
// *  \param  iop [IN]            Packet passed by the upper layer
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartSubmitIoReq(
//            const DDC_UartObj       *hDDC,
//            Ptr                     hIop)
//{
//    DDC_UartHandle          DDC;
//    Uint32                  allocRef;
//    Uint32                  cookie;
//    Int                     xfer;
//    Int                     count;
//    DDC_UartIoPacket        *iop;
//
//    DDC         = (DDC_UartHandle)hDDC;
//    allocRef    = 0;
//    cookie      = 0;
//    xfer        = 0;
//    count       = 0;
//    iop         = (DDC_UartIoPacket*)hIop;
//
//    /* Setting the iop Params */
//    iop->hDDC = (Ptr)hDDC;
//    iop->iopLink.next = NULL;
//    iop->iopLink.prev = NULL;
//    iop->xferActual = 0;
//    allocRef = iop->allocRef;
//    DDC->stats.errors = 0 ;
//
//    switch (iop->cmd)
//    {
//    case DDC_UART_IOCMD_READ:
//        /* If polled mode set the active iop as the received iop and call the
//         * function "uartRxIntrHandler" where the control will block till it
//         * gets the requested number of bytes. */
//        if (DDC->opMode == PSP_OPMODE_POLLED)
//        {
//            DDC->rxActiveIop = iop;
//            DDC->rxActiveBuf = iop->buf;
//            DDC->rxRemaining = (Int)iop->xferRequest;
//            ddc_uartRxIntrHandler(DDC);
//            return (iop->result);
//        }
//
//        PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT, &cookie);
//        /* If not in polled mode, then it may be in INT mode or DMA mode.
//        * Disable the interrupts.check if any IOP is active, if yes check if
//        * the new IOP has a timeout value. If not then post an error. else
//        * enque the iop into the list and return back. */
//        if (DDC->rxActiveIop != NULL)
//        {
//            /* If timeout has not occured then enqueue else timeout error */
//            if (iop->timeout == 0)
//            {
//                iop->result = DDC_UART_E_REQ_TIMEOUT;
//            }
//            else
//            {
//                /* Queue it and update the result */
//                PAL_osListEnqueue(&DDC->rxPendListHeadNode, iop);
//                iop->result = PAL_SINPROGRESS;
//            }
//        }
//        else
//        {
//            /*
//            * No other IOP is active, We can process this IOP, set it as
//            * active IOP */
//            DDC->rxActiveIop = iop;
//            DDC->rxActiveBuf = iop->buf;
//            DDC->rxRemaining = (Int)iop->xferRequest;
//
//            /* Interrupt Mode */
//            for (;;)
//            {
//                /* Checking if the request has been completed */
//                if( (DDC->rxRemaining == 0) )
//                {
//                    iop->xferActual = iop->xferRequest - (Uint32)DDC->rxRemaining;
//                    DDC->rxActiveIop = NULL;
//                    iop->result = PAL_SOK;
//                    break;
//                }
//                /* Check if there is anything in the circular buff, if it has
//                    no data, and the timeout of the new IOP is 0 then, set the
//                    result as success and return */
//                if ( (UTIL_circFullCount(DDC->hRxCirc) == 0)  )
//                {
//                    /* If timeout occurs then stop processing the packet and
//                     * increment the timeout count */
//                    if (iop->timeout == 0)
//                    {
//                        iop->xferActual = iop->xferRequest - (Uint32)DDC->rxRemaining;
//                        DDC->rxActiveIop = NULL;
//                        iop->result = PAL_SOK;
//                    }
//                    else
//                    {
//                        /* Else keep the status in progress */
//                        DDC->rxActiveIop = iop;
//                        iop->result = PAL_SINPROGRESS;
//                    }
//
//                    /* if there is no data in the circ buffer and the timeout
//                    * in not 0, then set the iop as active and in progress
//                    * enable the interrupt and return back */
//                    if (DDC->opMode == PSP_OPMODE_INTERRUPT)
//                    {
//                        LLC_uartIntrEnable(DDC->llc, LLC_UART_INTR_RHR);
//                    }
//                    break; /* Break from the for loop */
//                }
//                /* If there is any data in the circ buffer copy the same into
//                * the active IOP */
//                xfer = UTIL_circReadMultiple(DDC->hRxCirc,
//                            DDC->rxActiveBuf,
//                            ( UART_DDC_MIN(CHUNK, DDC->rxRemaining) ) );
//                DDC->rxRemaining -= xfer;
//                DDC->rxActiveBuf += xfer;
//                /*
//                 * If RX had been disabled, wait till a configured
//                 * number of bytes have been read out, before re-enabling
//                 * RHR
//                 */
//                /* if there is any space iin the circ buffer enable the UART
//                * interrupt
//                */
//                if (DDC->rxDisableCount > 0)
//                {
//                    DDC->rxDisableCount -= xfer;
//                    if (DDC->rxDisableCount <= 0)
//                    {
//                        LLC_uartIntrEnable(DDC->llc, LLC_UART_INTR_RHR);
//                    }
//                }
//            } /* End of for;; loop */
//        } /* End of else loop */
//
//        PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//        break;
//
//    case DDC_UART_IOCMD_WRITE:
//        if (DDC->opMode == PSP_OPMODE_POLLED)
//        {
//            DDC->txActiveIop = iop;
//            DDC->txActiveBuf = iop->buf;
//            DDC->txRemaining = (Int)iop->xferRequest;
//
//            /* Since interrupt path is not being followed,
//             * init the tx fifo counter */
//
//            /* Getting status of the Tx register and checking if it is empty*/
//            if ( LLC_uartIntrIsXmitterEmpty(DDC->llc) == (Bool)TRUE )
//            {
//                LLC_uartSetTxFifoCntFull(DDC->llc,DDC->fifoEnabled);
//            }
//            ddc_uartTxIntrHandler(DDC);
//            return (iop->result);
//        }
//
//        PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT, &cookie);
//
//        if ( DDC->txActiveIop != NULL)
//        {
//            /* If timeout has not occured then enqueue else timeout error */
//            if (iop->timeout == 0)
//            {
//                iop->result = DDC_UART_E_REQ_TIMEOUT;
//            }
//            else
//            {
//                /* else queue for future processing */
//                PAL_osListEnqueue(&DDC->txPendListHeadNode, iop);
//                iop->result = PAL_SINPROGRESS;
//            }
//        }
//        else
//        {
//            /* Assigning packet to the channel */
//            DDC->txActiveIop = iop;
//            DDC->txActiveBuf = iop->buf;
//            DDC->txRemaining = (Int)iop->xferRequest;
//
//            /* Interrupt Mode */
//            for (;;)
//            {
//                if (DDC->txRemaining == 0)
//                {
//                    DDC->txActiveIop = iop;
//                    iop->result = PAL_SINPROGRESS;
//
//                    if( (UTIL_circFullCount(DDC->hTxCirc) != NULL ) && (DDC->txInProgress == FALSE ) )
//                    {
//                        /* Calling the ISR */
//                        if (DDC->opMode == PSP_OPMODE_INTERRUPT)
//                        {
//                            LLC_uartIntrEnable(DDC->llc, LLC_UART_INTR_THR);
//                        }
//
//                        /* If TX Circular buffer has some bytes,
//                         * write out to hardware and trigger interrupt */
//                        if ( LLC_uartIntrIsXmitterEmpty(DDC->llc) == (Bool)TRUE )
//                        {
//                            LLC_uartSetTxFifoCntFull(DDC->llc,DDC->fifoEnabled);
//                        }
//
//                        DDC->txInProgress = True;
//
//                        /* checking the bytes in the internal buffer */
//                        count = (Int)UTIL_circFullCount(DDC->hTxCirc);
//
//                        while (count > 0)
//                        {
//                            /* Checks if the buffer is not full */
//                            if ( LLC_uartStatusIsXmitterFull(DDC->llc) == FALSE )
//                            {
//                                LLC_uartWrite(DDC->llc,
//                                            UTIL_circReadChar(DDC->hTxCirc));
//
//                                count--;
//                            }
//                            else
//                            {
//                                /* Restore the Interrupts */
//                                PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//                                /* Return PAL_SINPROGRESS to ensure that SEM is taken */
//                                /* Sempahore will be released after getting callback/timeout */
//                                return (PAL_SINPROGRESS); /* FIFO Full */
//                            }
//                        }
//                        PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//                        /* Return PAL_SINPROGRESS to ensure that SEM is taken */
//                        /* Sempahore will be released after getting callback/timeout */
//                        return (PAL_SINPROGRESS);
//                    }
//                    break;
//                }
//
//                if (UTIL_circEmptyCount(DDC->hTxCirc) == 0)
//                {
//                    /* If timeout occurs then stop processing the packet and
//                     * increment the timeout count */
//                    if (iop->timeout == 0)
//                    {
//                        iop->xferActual = iop->xferRequest - (Uint32)DDC->txRemaining;
//                        DDC->txActiveIop = NULL;
//                        iop->result = PAL_SOK;
//                    }
//                    else
//                    {
//                        /* else update the result */
//                        iop->result = PAL_SINPROGRESS;
//                        DDC->txActiveIop = iop;
//                    }
//
//                    if (DDC->txInProgress == FALSE)
//                    {
//                        /* Call the ISR depending on the state */
//                        if (DDC->opMode == PSP_OPMODE_INTERRUPT)
//                        {
//                            LLC_uartIntrEnable(DDC->llc, LLC_UART_INTR_THR);
//                        }
//                        /* If Tx is not in progress, then write out available
//                         * FIFO to hardware and trigger interrupt */
//                        if ( LLC_uartIntrIsXmitterEmpty(DDC->llc) == (Bool)TRUE )
//                        {
//                            LLC_uartSetTxFifoCntFull(DDC->llc,DDC->fifoEnabled);
//                        }
//                        DDC->txInProgress = True;
//
//                        /* Checking the bytes in the buffer and checking them
//                         * against error */
//                        count = (Int)UTIL_circFullCount(DDC->hTxCirc);
//                        while (count > 0)
//                        {
//                            /* Checks if the buffer is Full */
//                            if (LLC_uartStatusIsXmitterFull(DDC->llc) == 0)
//                            {
//                                LLC_uartWrite(DDC->llc,
//                                        UTIL_circReadChar(DDC->hTxCirc));
//
//                                count--;
//                            }
//                            else
//                            {
//                                /* Restore the Interrupts */
//                                PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//                                /* Return PAL_SINPROGRESS to ensure that SEM is taken */
//                                /* Sempahore will be released after getting callback/timeout */
//                                return (PAL_SINPROGRESS); /* FIFO Full */
//                            }
//                        }
//                        PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//                        /* Return PAL_SINPROGRESS to ensure that SEM is taken */
//                        /* Sempahore will be released after getting callback/timeout */
//                        return (PAL_SINPROGRESS);
//                    }
//                    break;
//                }
//
//                xfer = UTIL_circWriteMultiple(DDC->hTxCirc,
//                                    DDC->txActiveBuf,
//                                    UART_DDC_MIN(CHUNK, DDC->txRemaining));
//                DDC->txRemaining -= xfer;
//                DDC->txActiveBuf += xfer;
//
//            } /* For loop */
//        }
//
//        PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//        break;
//    default:
//        iop->result = DDC_UART_E_NOT_SUPPORTED;
//		break;
//    }
//
//    /* Does not come here for POLLED mode of operation */
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT, &cookie);
//    /* If the process gets completed w/o going into ISR then update the stats
//     * and call the callback function */
//    if ((iop->allocRef == allocRef)  &&  (iop->result != PAL_SINPROGRESS))
//    {
//        if(iop->cmd == DDC_UART_IOCMD_READ)
//        {
//            DDC->stats.rxBytes += iop->xferActual;
//        }
//        else
//        {
//            if(iop->cmd == DDC_UART_IOCMD_WRITE)
//            {
//                DDC->stats.txBytes += iop->xferActual;
//            }
//        }
//        _DDA_uartIoComplete(DDC->hDDA, iop);
//        iop->allocRef++;
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//
//    if(DDC->stats.errors != 0)
//    {
//        return(DDC_UART_E_IOP_ERROR);
//    }
//
//    /* Return PAL_SINPROGRESS to ensure that SEM is taken */
//    /* Sempahore will be released after getting callback/timeout */
//    return (PAL_SINPROGRESS);
//}
//
///**
// *  \brief Receiver ISR
// *
// *  This function is the Receiver ISR.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static void ddc_uartRxIntrHandler(
//                DDC_UartHandle  DDC)
//{
//    Int                   xfer;
//    Int                   count;
//    DDC_UartIoPacket      *iop;
//    DDC_UartIoPacket      *iopDone;
//    Bool                  checkTimeout;
//    Uint32                currentTick;
//
//    xfer         = 0;
//    count        = 0;
//    iop          = NULL;
//    iopDone      = NULL;
//    checkTimeout = FALSE;
//    currentTick  = 0;
//
//    currentTick = PAL_osGetCurrentTick();
//
//    if(DDC != NULL)
//    {
//        iop = DDC->rxActiveIop;
//        if (iop != NULL)
//        {
//            for (;;)
//            {
//                xfer = ddc_uartReadMultiple(DDC->llc, DDC->rxActiveBuf,
//                                        DDC->rxRemaining);
//
//                if (xfer == 0)
//                {
//                    if(DDC->opMode != PSP_OPMODE_POLLED)
//                    {
//                           return;
//                    }
//                    else
//                    {
//                       //PAL_osWaitMsecs(DDC->msecPoll);
//                    }
//                }
//
//                if(DDC->opMode == PSP_OPMODE_POLLED)
//                {
//                    checkTimeout = (Bool)PAL_osCheckTimeOut(currentTick,iop->timeout);
//                }
//
//                DDC->rxRemaining -= xfer;
//                DDC->rxActiveBuf += xfer;
//
//                if ( (DDC->rxRemaining == 0) || (checkTimeout == (Bool)TRUE) )
//                {
//                    iopDone = iop;
//                    /* Get next IOP from RX pending list - do this before
//                     * notifyCompletion is called as it will manipulate the
//                     * next and prev pointers of iop disturbing the pending list */
//                    DDC->stats.rxBytes += (Uint32)(iop->xferRequest - DDC->rxRemaining);
//					if(checkTimeout == (Bool)TRUE)
//					{
//						notifyCompletion(iopDone, (PSP_E_TIMEOUT) );
//					}
//					else
//					{
//	                	notifyCompletion(iopDone, PAL_SOK);
//					}
//                    iopDone->allocRef++;
//                    if(PAL_osListIsEmpty(&DDC->rxPendListHeadNode) == (Bool)True)
//                    {
//                        DDC->rxActiveIop = NULL;
//                        break;
//                    }
//                    else
//                    {
//                        iop = (DDC_UartIoPacket *)PAL_osListDequeue(&DDC->rxPendListHeadNode);
//                        if(iop != NULL)
//                        {
//                            DDC->rxActiveIop = iop;
//                            DDC->rxActiveBuf = iop->buf;
//                            DDC->rxRemaining = (Int)iop->xferRequest;
//                        }
//                    }
//                }
//            } /* For loop */
//        } /* If IOP active */
//
//        if (DDC->opMode == PSP_OPMODE_POLLED)
//        {
//            return;
//        }
//
//        count = (Int)UTIL_circEmptyCount(DDC->hRxCirc);
//        while (count > 0)
//        {
//            /* Max _count_ chars can be read into the circ buffer */
//            /* Check if there is an error,
//             * if yes then clear the characters from FIFO
//             * until errored characters are removed
//             */
//            if ( LLC_uartStatusIsLineError(DDC->llc) == (Bool)TRUE )
//            {
//                ddc_uartHandleRxError (DDC);
//            }
//
//            if ( LLC_uartStatusIsDataReady(DDC->llc) == (Bool)TRUE)
//            {
//                UTIL_circWriteChar(DDC->hRxCirc, (Char)LLC_uartRead(DDC->llc));
//                --count;
//            }
//            else
//            {
//                break;
//            }
//        }
//
//        if (UTIL_circEmptyCount(DDC->hRxCirc) == 0)
//        {
//            /*
//             * No more place in internal buffers. Disable the interrupt to the
//             * processor till some configured chunk of data has been read by
//             * the application
//             */
//            LLC_uartIntrDisable(DDC->llc, LLC_UART_INTR_RHR);
//            DDC->rxDisableCount = RX_RE_ENABLE_COUNT;
//        }
//    }
//}
//
///**
// *  \brief Transmit ISR
// *
// *  This function is the Transmitter ISR.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static void ddc_uartTxIntrHandler(
//                DDC_UartHandle  DDC)
//{
//    Int                  xfer;
//    Int                  count;
//    DDC_UartIoPacket     *iop;
//    DDC_UartIoPacket     *iopDone;
//    Bool                 checkTimeout;
//    Uint32               currentTick;
//
//    xfer         = 0;
//    count        = 0;
//    iop          = NULL;
//    iopDone      = NULL;
//    checkTimeout = FALSE;
//    currentTick  = 0;
//
//    currentTick = PAL_osGetCurrentTick();
//
//    if (DDC->opMode != PSP_OPMODE_POLLED)
//    {
//        count = (Int)UTIL_circFullCount(DDC->hTxCirc);
//        while (count > 0)
//        {
//            if (LLC_uartStatusIsXmitterFull(DDC->llc) == 0)
//            {
//                LLC_uartWrite(DDC->llc, UTIL_circReadChar(DDC->hTxCirc));
//                count--;
//            }
//            else
//            {
//                return; /* FIFO Full */
//            }
//        }
//    }
//
//    iop = DDC->txActiveIop;
//    if (iop != NULL)
//    {
//        for (;;)
//        {
//            if ( (DDC->txRemaining == 0) || (checkTimeout == (Bool)TRUE) )
//            {
//                iopDone = iop;
//                /* Get next IOP from TX pending list - do this before
//                 * notifyCompletion is called as it will manipulate
//                 * the next and prev pointers of iop disturbing
//                 * the pending list */
//                DDC->stats.txBytes += (Uint32)( iop->xferRequest - DDC->txRemaining);
//				if(checkTimeout == (Bool)TRUE)
//				{
//					notifyCompletion(iopDone, (-11) );
//				}
//				else
//				{
//                	notifyCompletion(iopDone, PAL_SOK);
//				}
//                iopDone->allocRef++;
//                if( PAL_osListIsEmpty(&DDC->txPendListHeadNode) == (Bool)TRUE)
//                {
//                    DDC->txActiveIop = NULL;
//                    DDC->txInProgress = False;
//                    LLC_uartIntrDisable(DDC->llc, LLC_UART_INTR_THR);
//                    break;
//                }
//                else
//                {
//                    iop = (DDC_UartIoPacket *)
//                                   PAL_osListDequeue(&DDC->txPendListHeadNode);
//                    DDC->txActiveIop = iop;
//                    DDC->txActiveBuf = iop->buf;
//                    DDC->txRemaining = (Int)iop->xferRequest;
//                }
//            }
//
//            xfer = ddc_uartWriteMultiple(DDC->llc,
//                                     DDC->txActiveBuf,
//                                     DDC->txRemaining);
//
//            if (xfer == 0)
//            {
//                if (DDC->opMode != PSP_OPMODE_POLLED)
//                {
//                    return;
//                }
//                else
//                {
//                   //PAL_osWaitMsecs(DDC->msecPoll);
//                }
//            }
//            DDC->txRemaining -= xfer;
//            DDC->txActiveBuf += xfer;
//
//            if ((DDC->opMode == PSP_OPMODE_POLLED) && (DDC->txRemaining != 0))
//            {
//                if ( LLC_uartIntrIsXmitterEmpty(DDC->llc) == (Bool)TRUE )
//                {
//                    LLC_uartSetTxFifoCntFull(DDC->llc,DDC->fifoEnabled);
//                    checkTimeout = (Bool)PAL_osCheckTimeOut(currentTick,iop->timeout);
//                }
//            }
//
//        } /* For loop */
//    } /* IOP Active */
//    else
//    {
//        LLC_uartIntrDisable(DDC->llc, LLC_UART_INTR_THR);
//        DDC->txInProgress = False;
//    }
//}
//
///**
// *  \brief Cancels the io
// *
// *  This function cancels io request for one packet
// *
// *  \param  hDDC    [IN]            Handle of the DDC
// *  \param  hIop    [IN]            StreamIO Packet to be completed
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//PAL_Result _DDC_uartCancelIo(
//            DDC_UartHandle      hDDC,
//            Ptr                 hIop)
//{
//    DDC_UartHandle        DDC;
//    Uint32                cookie;
//    DDC_UartIoPacket      *iopDone;
//    DDC_UartIoPacket      *iopNext;
//    DDC_UartIoPacket      *iop;
//
//    DDC      = hDDC;
//    cookie   = 0;
//    iopDone  = NULL;
//    iopNext  = NULL;
//    iop      = (DDC_UartIoPacket*)hIop;
//
//    /* Protect from UART interrupt and task switching so that
//     * the process is cancellation is fast */
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT, &cookie);
//
//    /* Remove the IOP from Pending list */
//    if (DDC_UART_IOCMD_WRITE == iop->cmd)
//    {
//        iopDone = iop;
//
//        if(DDC->txActiveIop == iop)
//        {
//            /* Current IOP */
//            DDC->txActiveIop = NULL;
//            iopDone->xferActual = iopDone->xferRequest - (Uint32)DDC->txRemaining;
//            iopDone->allocRef++;
//
//            DDC->txRemaining = 0;
//
//            if(PAL_osListIsEmpty(&DDC->txPendListHeadNode) == FALSE)
//            {
//                /*
//                 * The last Active IOP got completed, so need
//                 * to modify this pointer
//                 */
//                iopNext = (&DDC->txPendListHeadNode)->next;
//
//                PAL_osList_NP_Remove((Ptr)iopNext);
//
//                DDC->txActiveIop = iopNext;
//                DDC->txActiveBuf = iopNext->buf;
//                DDC->txRemaining = (Int)iopNext->xferRequest;
//            }
//        }
//        else
//        {
//            PAL_osList_NP_Remove((Ptr)iop);
//        }
//
//        DDC->stats.txBytes += iopDone->xferActual;
//        notifyCompletion(iopDone, DDC_UART_E_REQ_TIMEOUT);
//    }
//    else
//    {
//        iopDone = iop;
//
//        if(DDC->rxActiveIop == iop)
//        {
//            /* Current IOP */
//            DDC->rxActiveIop = NULL;
//            iopDone->xferActual = iopDone->xferRequest - (Uint32)DDC->rxRemaining;
//            iopDone->allocRef++;
//
//            DDC->rxRemaining = 0;
//
//            if (PAL_osListIsEmpty(&DDC->rxPendListHeadNode)== FALSE)
//            {
//                /*
//                 * The last Active IOP got completed, so need
//                 * to modify this pointer
//                 */
//                iopNext = (&DDC->rxPendListHeadNode)->next;
//
//                PAL_osList_NP_Remove((Ptr)iopNext);
//
//                DDC->rxActiveIop = iopNext;
//                DDC->rxActiveBuf = iopNext->buf;
//                DDC->rxRemaining = (Int)iopNext->xferRequest;
//            }
//        }
//        else
//        {
//            PAL_osList_NP_Remove((Ptr)iop);
//        }
//
//        DDC->stats.rxBytes += iopDone->xferActual;
//        notifyCompletion(iopDone, DDC_UART_E_REQ_TIMEOUT);
//    }
//
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//    return (PAL_SOK);
//}
//
///**
// *  \brief clears the DDC error stats
// *
// *  This function clears the stats of the DDC and clears them
// *
// *  \param  DDC [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static void clearStats(
//                Ptr hDDC)
//{
//    DDC_UartObj *DDC;
//
//	DDC = (DDC_UartObj *)hDDC;
//
//    DDC->stats.rxBytes = 0;
//    DDC->stats.txBytes = 0;
//    DDC->stats.errors = 0;
//    DDC->stats.nefc = 0;
//    DDC->stats.fefc = 0;
//    DDC->stats.overrun = 0;
//    DDC->stats.rxTimeout = 0;
//    DDC->stats.rxFramingError = 0;
//    DDC->stats.rxBreakError = 0;
//    DDC->stats.rxParityError = 0;
//}
//
///**
// *  \brief ISR
// *
// *  This function is the ISR and calls the corresponding ISR Context
// *
// *  \param  hDDC    [IN]            Handle of the DDC Object
// *  \param  isrArgs [IN]            Not used
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//Int _DDC_uartIsr(DDC_UartHandle  hDDC, Ptr isrArgs)
//{
//    DDC_UartObj         *DDC;
//    volatile Uint32  status;
//    Uint32 regs_address;
//    Uint32  intrCnt;
//
//    DDC          = (DDC_UartObj *)hDDC;
//    status       = 0x01u;
//    regs_address = 0x01C20000u;
//    intrCnt      = 0;
//
//	regs_address = (Uint32)DDC->llc->regs;
//
//    /* Remove -pdr remarks */
//    isrArgs = isrArgs;
//
//    status = (Uint32)LLC_uartIntrGetStatus(DDC->llc);
//
//    while (((status & 0x1u) == FALSE) && ((intrCnt) < (MAX_UART_ISR_LOOP)))
//    {
//        intrCnt++;
//        if ( (Bool)LLC_uartIntrIsReceiverLineError(DDC->llc, status) == (Bool)TRUE ) {
//            ddc_uartHandleRxError (hDDC);
//        } else if  ((LLC_uartIntrIsDataReceived(DDC->llc, status) == 1)  ||
//                    (LLC_uartIntrIsCharacterTimeout(DDC->llc, status) ==1)) {
//
//            if( (Bool)LLC_uartIntrIsCharacterTimeout(DDC->llc, status) == (Bool)TRUE)
//            {
//                DDC->stats.rxTimeout++;
//            }
//
//            ddc_uartRxIntrHandler(DDC);
//        } else if ( (Bool)LLC_uartIntrIsXmitterHoldingRegEmpty(DDC->llc, status) == (Bool)TRUE) {
//            LLC_uartSetTxFifoCntFull(DDC->llc,DDC->fifoEnabled);
//            ddc_uartTxIntrHandler(DDC);
//        } else if ( (Bool)LLC_uartIntrIsModemStatus(DDC->llc, status) == (Bool)TRUE ) {
//            volatile Uint32 value;
//            /* Value of MSR is read so as to clear it if the interrupt comes
//               so as to clear the interrupt and allow the peripheral to raise
//               the interrupts further (If not cleared then interrupts will be
//               kept pending )   */
//
//            /* 0x18u is used as there is no MSR register in the CSL Register
//               overlay and MSR register is at offset of 0x18                 */
//			value = (Uint32)(*((Uint32 *)(Uint32)((Uint32)regs_address + (Uint32)0x18u)));
//        } else {
//            if (LLC_uartIntrIsSpecialChar(DDC->llc, status)) {
//            /* Do nothing */
//            }
//        }
//
//        status = LLC_uartIntrGetStatus(DDC->llc);
//    }
//
//    return (PAL_SOK);
//}
//
///**
// *  \brief Receiver Errors
// *
// *  This function finds errors on the Receiver buffer.
// *
// *  \param  hDDC    [IN]            Handle of the DDC Object
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static PAL_Result ddc_uartHandleRxError (DDC_UartHandle  hDDC)
//{
//    DDC_UartObj         *DDC;
//    Uint32              status;
//    PAL_Result          result;
//
//    DDC    = (DDC_UartObj *)hDDC;
//    status = 0;
//    result = PAL_SOK;
//
//    status = LLC_uartGetLineStatus(DDC->llc);
//    if( (Bool)(status & CSL_UART_LSR_OE_MASK) != FALSE)
//    {
//        DDC->stats.overrun++;
//        DDC->stats.errors++;
//    }
//
//    if( (Bool)(status & CSL_UART_LSR_RXFIFOE_MASK) != FALSE )
//    {
//        if( (status & CSL_UART_LSR_FE_MASK) != FALSE )
//        {
//            DDC->stats.rxFramingError++ ;
//            DDC->stats.errors++;
//        }
//
//        if( (status & CSL_UART_LSR_PE_MASK) != FALSE )
//        {
//            DDC->stats.rxParityError++ ;
//            DDC->stats.errors++;
//        }
//
//        if( (status & CSL_UART_LSR_BI_MASK) != FALSE )
//        {
//            DDC->stats.rxBreakError++ ;
//            DDC->stats.errors++;
//        }
//    }
//
//	/* Return Critical Error after servicing Recieve Interrupt */
//    result = PAL_CRITICAL_ERROR;
//
//    ddc_uartRxIntrHandler(DDC);
//
//    return result;
//}
//
///**
// *  \brief Cancels all Receiver iops
// *
// *  This function cancels on the Receiver list.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *  \param  flag    [IN]            flag passed depending upon the Flush or Abort
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static PAL_Result ddc_uartCancelAllRxIo(DDC_UartHandle DDC,Int flag)
//{
//    Uint32    cookie;
//    DDC_UartIoPacket      *iopDone;
//    DDC_UartIoPacket      *iopNext;
//
//    cookie  = 0;
//    iopDone = NULL;
//    iopNext = NULL;
//
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT, &cookie);
//
//    if( DDC->rxActiveIop != NULL)
//    {
//        iopDone = DDC->rxActiveIop;
//        /* Current IOP */
//        DDC->rxActiveIop = NULL;
//        /* Update the attributes of the iop */
//        iopDone->xferActual = iopDone->xferRequest - (Uint32)DDC->rxRemaining;
//        iopDone->allocRef++;
//        DDC->rxRemaining = 0;
//        DDC->stats.rxBytes += iopDone->xferActual;
//        if(flag == DDC_UART_ABORT)
//        {
//            notifyCompletion(iopDone, DDC_UART_E_IOP_ABORTED);
//        }
//        else
//        {
//            notifyCompletion(iopDone, DDC_UART_E_IOP_FLUSHED);
//        }
//    }
//
//    /* Getting the packets from the que and removing them */
//    while(PAL_osListIsEmpty(&DDC->rxPendListHeadNode) == FALSE)
//    {
//        /* The last Active IOP got completed,
//         * so need to modify this pointer */
//        iopNext = (&DDC->rxPendListHeadNode)->next;
//
//        PAL_osList_NP_Remove((Ptr)iopNext);
//
//        if(flag == DDC_UART_ABORT)
//        {
//            notifyCompletion(iopDone, DDC_UART_E_IOP_ABORTED);
//        }
//        else
//        {
//            notifyCompletion(iopDone, DDC_UART_E_IOP_FLUSHED);
//        }
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//    return (PAL_SOK);
//}
//
///**
// *  \brief Cancels all Transmitter iops
// *
// *  This function cancels on the Transmitter list.
// *
// *  \param  DDC     [IN]            Handle of the DDC Object
// *  \param  flag    [IN]            flag passed depending upon the Flush or Abort
// *
// *  \return If successful, returns PAL_SOK else PAL Error
// *
// */
//static PAL_Result ddc_uartCancelAllTxIo(DDC_UartHandle DDC, Int flag)
//{
//    Uint32    cookie;
//    DDC_UartIoPacket      *iopDone;
//    DDC_UartIoPacket      *iopNext;
//
//    cookie  = 0;
//    iopDone = NULL;
//    iopNext = NULL;
//
//    /* Remove -pdr remarks */
//    flag = flag;
//    PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT, &cookie);
//
//    if( DDC->txActiveIop != NULL)
//    {
//        iopDone = DDC->txActiveIop;
//        /* Current IOP */
//        DDC->txActiveIop = NULL;
//        /* Update the attributes of the iop */
//        iopDone->xferActual = iopDone->xferRequest - (Uint32)DDC->txRemaining;
//        iopDone->allocRef++;
//        DDC->txRemaining = 0;
//        DDC->stats.txBytes += iopDone->xferActual;
//        notifyCompletion(iopDone, DDC_UART_E_IOP_ABORTED);
//    }
//
//    /* Getting the packets from the que and removing them */
//    while(PAL_osListIsEmpty(&DDC->txPendListHeadNode) == FALSE)
//    {
//        /* The last Active IOP got completed,
//         * so need to modify this pointer */
//        iopNext = (&DDC->txPendListHeadNode)->next;
//
//        PAL_osList_NP_Remove((Ptr)iopNext);
//        notifyCompletion(iopNext, DDC_UART_E_IOP_ABORTED);
//    }
//    PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//    return (PAL_SOK);
//}
///* End of file */
//
