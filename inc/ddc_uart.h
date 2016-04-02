#ifndef DDC_UART_H_
#define DDC_UART_H_

/*****************************************************************************
 * File Name : ddc_uart.h 
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

//#ifndef _DDC_UART_H
//#define _DDC_UART_H

#include "pal_osSem.h"
#include "pal_osList.h"
#include "llc_uartIf.h"
#include "util_circ.h"
#include "psp_common.h"

/**
 * \defgroup DDCUartMain UART DDC Interface Definitions
 *
 * All interface definitions for a UART DDC are contained in this file.
 *
 * @{
 */
#define DDC_UART_ABORT 0
/**< UART abort */
#define DDC_UART_FLUSH 1
/**< UART flush */

/**
 * \defgroup DDCUartIoctl Ioctl Codes
 *
 * The IOCTL codes present here are specific to UART.
 *
 * @{
 */
#define DDC_UART_IOCTL_SET_BAUD_RATE            0x1234u
/**< Macro to set baud rate using ioctl function                            */
#define DDC_UART_IOCTL_SET_CHARLEN              0x1235u
/**< Macro to set character length using ioctl function                     */
#define DDC_UART_IOCTL_SET_PARITY               0x1236u
/**< Macro to set parity using ioctl function                               */
#define DDC_UART_IOCTL_SET_NUM_STOP_BITS        0x1237u
/**< Macro to set stop bits using ioctl function                            */
#define DDC_UART_IOCTL_SET_OPMODE               0x1238u
/**< Macro to set opmode using ioctl function                               */
#define DDC_UART_IOCTL_SET_LOOPBACK             0x1239u
/**< Macro to set loopback mode using ioctl function                        */
#define DDC_UART_IOCTL_CANCEL_IO                0x123Au
/**< Macro to cancel IO operation using ioctl function                      */
#define DDC_UART_IOCTL_SET_STATSREADCLEAR       0x123Bu
/**< Macro to clear read status using ioctl function                        */
#define DDC_UART_IOCTL_GET_STATS                0x123Cu
/**< Macro to get status using ioctl function                               */
#define DDC_UART_IOCTL_SET_STATSCLEAR           0x123Du
/**< Macro to clear status using ioctl function                             */

#define DDC_UART_IOCMD_WRITE                    0x1u
/**< Write command to UART                                                  */
#define DDC_UART_IOCMD_READ                     0x2u
/**< Read command to UART                                                   */
#define DDC_UART_IOCMD_FLUSH                    0x3u
/**< Flush command to UART                                                  */
#define DDC_UART_IOCMD_ABORT                    0x4u
/**< Abort command to UART                                                  */

#define DDC_UART_IOP_FLAGS_SYNCIO_PEND          0x1
/**< Pend flag for IO synchronization                                       */

#define MAX_UART_ISR_LOOP   5u
/**< UART Isr loop value                                                    */

/* @} DDCUartIoctl */

/**
 * \defgroup DDCUartErrorCodes Error Codes
 *
 * UART specific error codes. All error codes of the Stream hierarchy are
 * also applicable.
 *
 * @{
 */

#define DDC_UART_ERROR_BASE                     (-11)
/**< Error code base value                                                  */
#define DDC_UART_E_DMA_TRANSFER_FAIL            (DDC_UART_ERROR_BASE - 1)
/**< Error code for DMA transfer failure                                    */
#define DDC_UART_E_INVALID_DEVICE_ID            (DDC_UART_ERROR_BASE - 2)
/**< Error code for invalid device Id                                       */
#define DDC_UART_E_REQ_TIMEOUT                  (DDC_UART_ERROR_BASE - 3)
/**< Error code for request time out                                        */
#define DDC_UART_E_NOT_SUPPORTED                (DDC_UART_ERROR_BASE - 4)
/**< Error code for not supported features                                  */
#define DDC_UART_E_IOP_CANCELED                 (DDC_UART_ERROR_BASE - 5)
/**< Error code to indiacate IO cancellation                                */
#define DDC_UART_E_IOP_ABORTED                  (DDC_UART_ERROR_BASE - 6)
/**< Error code to indicate IO abortion                                     */
#define DDC_UART_E_IOP_FLUSHED                  (DDC_UART_ERROR_BASE - 7)
/**< Error code for IO flushed                                              */
#define DDC_UART_E_IOP_ERROR                    (DDC_UART_ERROR_BASE - 8)
/**< Error code for IO operation error                                      */
/* @} DDCUartErrorCodes */


#define DDC_UART_FLAG_FIRSTBITPOS   (DDC_STREAM_FLAG_LASTBITPOS + 1)
/**< First bit-position applicable to UART flags                            */
#define DDC_UART_FLAG_LASTBITPOS    (DDC_UART_FLAG_FIRSTBITPOS + 0)
/**< Last bit-position applicable to UART flags                             */

#define DDA_UART_NFY_FIRST          (DDA_STREAM_NFY_LAST + 1)
/**< The first notification code into DDA through DDA_ControlCb, from UART  */
#define DDA_UART_NFY_FLOWCONTROL    (DDA_UART_NFY_FIRST + 0)
/**< To indicate to DDA that the far-end has initiated a flow-control
 * throttle. When the throttle condition is removed, again this notification
 * is sent to the DDA. _cmdArg_ is a pointer to a boolean which will contain
 * TRUE or False, depending on whether the flow control is active or the
 * condition is removed, respectively. _param_ is unused.                   */
#define DDA_UART_NFY_LAST           (DDA_UART_NFY_FIRST + 0)
/**< The last notification code into DDA through DDA_ControlCb, from UART   */

/* @} DDAUartCallbacks */

/**
 * \brief DDC Stream Device Packet/ Buffer Objects
 *
 * All DDC Stream Devices use the following buffer/ packet objects to request
 * asynchronous IO transaction
 */
typedef struct _DDC_UartIoPacket
{
    PAL_OsListNodeHeader    iopLink;
    /**< [IN/ INTERNAL] List of IO requests, tracked at the device          */
    Uint32                   cmd;
    /**< [IN] Typically one from DDC_STREAM_IOCMD_XXX or an extension       */
    Uint32                           numIoVecs;
    /**< [IN] Number of iovec elements of type DDC_StreamIoVec pointed to by
     * _buf_ below. If the buffer pointed to by _buf_ is not of type
     * DDC_StreamIoVec, then this field must be set to 0. If this is
     * non-zero, the field _xferRequest_ shall not be used                  */
    Ptr                     buf;
    /**< [IN] Points to the application supplied IO buffer for the IO
     * transaction. This may point to the actual buffer, an array of
     * scatter/ gather buffers or some other driver specific payload format */
    Uint32                  xferRequest;
    /**< [IN] Number of bytes being requested in this transaction           */
    Uint32                  timeout;
    /**< [IN] Amount of time given to this iop to complete                  */
    Ptr                     appContext;
    /**< [IN] Application supplied application context                      */
    Uint32                          flags;
    /**< [IN] Flags as defined here or extended by a specific driver        */
    PAL_Result                      result;
    /**< [OUT] Status of IO transaction                                     */
    Uint32                          xferActual;
    /**< [OUT] Number of bytes actually transferred                         */
    Ptr                             * hDDC;
    /**< [OUT] Channel handle to which this IO request corresponds. This is
     * assigned internally by the DDC                                       */
    Uint32                          allocRef;
    /**< [INTERNAL] A monotonically increasing number that is updated
     * whenever an IO transaction completes                                 */
} DDC_UartIoPacket;

/**
 * \brief UART DDC Initialization and Configuration Object
 *
 * Structure of the Initialization and Configuration object for UART. This
 * object is per controller. No assumption is made within the driver that
 * this object shall persist beyond the device initialization phase.
 * Therefore, contents of this structure are used for device and data
 * structure initialization. A direct reference to this structure is not
 * tracked any beyond the initialization phase.
 */
typedef struct _DDC_UartInitConfig
{
    UTIL_CircHandle         hRxCirc;
    /**< Handle to the receive side circular buffer object                  */
    Char                    *rxBuf;
    /**< Recevie path circular buffer                                       */
    Uint16                  rxBufSize;
    /**< Size of circular buffer on the recevie path                        */
    UTIL_CircHandle         hTxCirc;
    /**< Handle to the transmit side circular buffer object                 */
    Char                    *txBuf;
    /**< Transmit path circular buffer                                      */
    Uint16                  txBufSize;
    /**< Size of circular buffer on the transmit path                       */

    PSP_OpMode          opMode;
    /**< "base" InitConfig object from the "stream" hierarchy               */

    LLC_UartObj             *llc;
    /**< Low level controller object                                        */
    Int                     msecPoll;
    /**< The interval between two poll requests to the underlying hardware
     * to perform IO                                                        */

    Ptr                     hEdma;
    /**< Handle to DMA object                                               */
    Uint32                  instId;
    /**< UART instance Id                                                   */
} DDC_UartInitConfig;

/**
 * \brief UART open parameters
 *
 * This structure holds the UART hardware configuration prameter structure
 */
typedef struct _DDC_UartOpenParams
{
    LLC_UartHwConfig        *hwConfig;
    /**< UART hardware configuration that must be applied to the controller */
} DDC_UartOpenParams;

/**
 * \brief UART DDC Statistics Collection Object
 *
 * Statistics are collected on a per-controller basis for UART. Hence, an
 * object of this type is found embedded in the DDC_UartObj structure.
 */
typedef struct _DDC_UartStats
{
    Uint32  rxBytes;
    /**< Number bytes received                                              */
    Uint32  txBytes;
    /**< Number bytes transmitted                                           */
    Uint32  errors;
    /**< Number of times an error was detected                              */
    Uint32  nefc;
    /**< Number of times a near-end flow control was initiated              */
    Uint32  fefc;
    /**< Number of times a far-end flow control was initiated               */
    Uint32  overrun;
    /**< Number of overrun errors                                           */
    Uint32  rxTimeout;
    /**< Number of Rx timeouts                                              */
    Uint32  rxFramingError;
    /**< Number of Rx Framing errors                                        */
    Uint32  rxBreakError;
    /**< Number of Rx Break Errors                                          */
    Uint32  rxParityError;
    /**< Number of Rx Parity Errors                                         */
} DDC_UartStats;

/*
 * A DDC UART driver will implement these functions and pass the pointers to
 * DDA layer
 */

/**
 * \name DDCUartFunctions UART DDC Functions
 *
 * UART extends the Stream Class Driver Interfaces
 *
 * @{
 */

/**
 * \brief UART DDC persistent context object
 *
 * A singleton of this type per UART controller instance in the system
 */
typedef struct _DDC_UartObj
{
    UTIL_CircHandle         hRxCirc;
    /**< Handle to the receive side circular buffer object                  */
    UTIL_CircHandle         hTxCirc;
    /**< Handle to the transmit side circular buffer object                 */
    LLC_UartHandle          llc;
    /**< Handle to the low level controller object                          */
    DDC_UartStats           stats;
    /**< UART specific stats                                                */
    PAL_OsListNodeHeader    rxPendListHeadNode;
    /**< Pending IO requests, waiting for reception to complete             */
    PAL_OsListNodeHeader    txPendListHeadNode;
    /**< Pending IO requests, waiting for transmission to complete          */
    PAL_OsSemHandle         hSemSyncIo;
    /**< Handle to the semaphore which is required to take exclusive control
     * over this peripheral instance in order to do synchronous IO          */
    DDC_UartIoPacket        *rxActiveIop;
    /**< Receive active Io packets                                          */
    Char                    *rxActiveBuf;
    /**< Receive active Io buffer                                           */
    Int                     rxRemaining;
    /**< Remaining number characters in Rx buffer                           */
    DDC_UartIoPacket        *txActiveIop;
    /**< Transmit active Io packets                                         */
    Char                    *txActiveBuf;
    /**< Transmit active Io buffer                                          */
    Int                     txRemaining;
    /**< Remaining number characters in Tx buffer                           */
    Int                     msecPoll;
    /**< msec poll                                                          */
    Bool                    txInProgress;
    /**< Transmission in progress                                           */
    Int                     rxDisableCount;
    /**< Rx disable count                                                   */
    Bool                    userBufferInDma;
    /**< user buffer in DMA                                                 */
    Int                     txDmaLastChunkSize;
    /**< Last DMA chunk size                                                */

    Bool                    fifoEnabled;
    /**< Fifo anable variable                                               */
/* FOR DMA */
    /**< Handle to DMA object                                               */
    Ptr                     hEdma;
    /* Rx Channel Related */
    Uint32                  RxTcc;
    /**< DMA Channel for Rx                                                 */
    Uint32                  RxChId;
    /**< Receive channel Id                                                 */
/*    Uint32                  RxPaRAMId;*/
    /* Tx Channel Related */
    Uint32                  TxTcc;
    /**< DMA Channel for Rx                                                 */
    Uint32                  TxChId;
    /**< Transmit channel Id                                                */
    Ptr                     hDDA;
    /**< DDA handle                                                         */
    Uint32                  versionId;  /**< Version Id                     */
    Uint32                  instId;     /**< Instance id/number             */
    PSP_DriverState         state;      /**< DDC State                      */
    PSP_OpMode              opMode;     /**< Operation mode of driver       */
} DDC_UartObj, *DDC_UartHandle;

/* @} DDCUartFunctions */

/**
 * \name DDAUartCallbacks UART DDA Callback Functions
 *
 * UART DDA Callback Functions, into the service-user. These functions are
 * called by the UART DDC and must be implemented by the service-user.
 *
 * @{
 */

/**
 * \brief DDA Handle
 *
 */
typedef Ptr *DDA_UartHandle;

/**
 *  \brief Instance of DDC Created
 *
 *  This function creates the instance of the DDC
 *
 *  \param  instId [IN]         Instance id of the Uart
 *  \param  hDDA [IN]           Handle of the Upper layer
 *  \param  hDDC [IN]           Handle of the DDC Object
 *  \param  param [IN]          User Parameters for further use
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartCreateInstance(
            Uint32                     instId,
            DDA_UartHandle              hDDA,
            DDC_UartHandle              hDDC,
            Ptr                     param);

/**
 *  \brief Instance of DDC Deleted
 *
 *  This function deletes the instance of the DDC
 *
 *  \param  hDDC [IN]           Handle of the DDC Object
 *  \param  param [IN]          User Parameters for further use
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartDelInst(DDC_UartHandle hDDC, Ptr param);


/**
 *  \brief Instance of DDC Initiated
 *
 *  This function initiates the instance of the DDC
 *
 *  \param  hDDC [IN]           Handle of the DDC Object
 *  \param  param [IN]          User Parameters for further use
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartInit(DDC_UartHandle hDDC, Ptr param);


/**
 *  \brief Instance of DDC De-Initiated
 *
 *  This function de-initiates the instance of the DDC
 *
 *  \param  hDDC [IN]           Handle of the DDC Object
 *  \param  param [IN]          User Parameters for further use
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartDeInit(DDC_UartHandle hDDC, Ptr param);


/**
 *  \brief Instance of DDC opened
 *
 *  This function open the instance of the DDC and sets up the H/W
 *
 *  \param  hDDC [IN]           Handle of the DDC Object
 *  \param  param [IN]          User Parameters for further use
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartOpen(DDC_UartHandle hDDC, Ptr param);

/**
 *  \brief Instance of DDC closed
 *
 *  This function close the instance of the DDC and releases the Handle
 *
 *  \param  hDDC [IN]           Handle of the DDC Object
 *  \param  param [IN]          User Parameters for further use
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartClose(DDC_UartHandle hDDC, Ptr param);


/**
 *  \brief Instance of DDC control
 *
 *  This function control the instance of the DDC and make the corresponding
 *  changes in the Hardware
 *
 *  \param  hDDC [IN]           Handle of the DDC Object
 *  \param  cmd [IN]            IOCTL command for DDC
 *  \param  cmdArg [IN]         Additional argument for the IOCTL
 *  \param  param [IN]          User Parameters for further use
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartControl(DDC_UartHandle hDDC, Uint32 cmd, Ptr cmdArg, Ptr param);


/**
 *  \brief Read/Write operation are performed
 *
 *  This function read/write function as requested by the application
 *  corresponding to iop packets as requeseted in all the modes i.e.
 *  POLLED/INTERRUPT.
 *
 *  \param  hDDC [IN]           Handle of the DDC
 *  \param  iop [IN]            Packet passed by the upper layer
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartSubmitIoReq(const DDC_UartObj *hDDC,Ptr iop);


/**
 *  \brief Operations once performed are submitted to the completion list
 *
 *  This function performs the submission to the completion list
 *
 *  \param  hChannel [IN]               Handle of the DDC Channel
 *  \param  completionListHead [IN]     Completed iop list
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result ddc_uartGetIoCompletionList(DDC_UartObj  *hChannel,
                                    PAL_OsListNodeHeader  *completionListHead);


/**
 *  \brief ISR
 *
 *  This function is the ISR and calls the corresponding ISR Context
 *
 *  \param  hDDC    [IN]            Handle of the DDC Object
 *  \param  isrArgs [IN]            Not used
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
Int _DDC_uartIsr(DDC_UartHandle hDDC, Ptr isrArgs);


/**
 *  \brief Cancels the io
 *
 *  This function cancels io request for one packet
 *
 *  \param  hDDC    [IN]            Handle of the DDC
 *  \param  hIop    [IN]            StreamIO Packet to be completed
 *
 *  \return If successful, returns PAL_SOK else PAL Error
 *
 */
PAL_Result _DDC_uartCancelIo(DDC_UartHandle hDDC,  Ptr hIop);

//#endif /* _DDC_UART_H_ */


#endif /*DDC_UART_H_*/
