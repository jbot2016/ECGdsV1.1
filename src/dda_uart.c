////jb commented out for testing purposes
///*****************************************************************************
// * File Name : dda_uart.c
// *
// * Brief	 : This file contains adaptation of UART driver
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
//
//#include "psp_common.h"
//#include "dda_uart.h"
//#include <pal_osProtect.h>
//#include <pal_osSem.h>
//
//volatile Bool checkDmaTimeout = FALSE;
///**< Variable to check DMA timeout */
//DDA_UartObj gDDA_UartObj[PSP_UART_NUM_INSTANCES];
///**< UART object structure instances */
//
///**
// *  \brief UART init function
// *
// *  \param  instNum [IN]     UART Driver Instance Handle
// *  \param  uartCfg [IN]     UART configuration parameters
// *
// *  \return PSP_SOK or PSP Error code
// */
//static PSP_Result _init(Uint32 instNum , const PSP_UartConfig  *uartCfg);
//
///**
// *  \brief IO processing function
// *
// *  \param  hUart   [IN]     UART Driver Instance Handle
// *  \param  buf     [IN]     Character Buffer pointer
// *  \param  size    [IN]     Size of character buffer
// *  \param  cmd     [IN]     Operation to be performed, typically an enum gets passed
// *  \param  timeout [IN]     Timeout (typically in milliSeconds)
// *
// *  \return PAL_SOK If success or suitable error code
// */
//static Int  _io(PSP_Handle  hUart, const Char *buf, Int size, Uint32 cmd, Uint32 timeout);
//
///**
// *  \brief Allocates IOP from the free list
// *
// *  \param  hDDA [IN]     DDA handle
// *  \return IOP If success or NULL
// */
//static DDC_UartIoPacket *allocIop(Ptr hDDA);
//
///**
// *  \brief Call back function to indicate IO completion
// *
// *  \param  hDDA [IN]     DDA handle
// *  \param  iop  [IN]     IO packet pointer
// *  \return PSP_SOK or PSP Error code
// */
//extern PAL_Result _DDA_uartIoComplete(DDA_UartHandle hDDA,DDC_UartIoPacket *iop);
//
///**
// *  \brief UART initialization function
// *
// *  This function creates the function pointer to the DDC Layer
// * and sets the parameters for the internal buffer
// * and initializes the DDC
// *
// *  \param  instNum [IN]      UART Driver Instance Number
// *  \param  param [IN/OUT]    Extra parameter(Implementation specific)
// *  \return Handle to the UART instance
// */
//PSP_Handle dda_uartInit(Uint32 instNum, Ptr param)
//{
//    PSP_Result retVal;
//    PSP_Handle hUart;
//
//    if( (param == NULL) || (instNum > PSP_UART_NUM_INSTANCES) )
//    {
//        hUart = NULL;
//    }
//    else
//    {
//        retVal = PSP_uartCreate(instNum, param);
//
//        if(retVal != PAL_SOK)
//        {
//            //retVal = PSP_E_DRIVER_INIT;    //Mistral: Commented
//			hUart = NULL;    //Mistral: Added
//        }
//        else
//        {
//            hUart = PSP_uartOpen(instNum, param);
//        }
//    }
//
//    return hUart;
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Read data from UART Instance
// *
// *  This function reads data from the UART Instance.
// *
// *  \param  hUart [IN]          UART Driver Instance Handle
// *  \param  buf [IN/OUT]        Character Buffer pointer - where read data is to be stored
// *  \param  size [IN]           Size of character buffer - number of bytes to read
// *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
// *  \param  param [IN/OUT]      Extra parameter (implementation specific)
// *  \return If successful, returns positive number - number of bytes read
// *          If failed, returns negative number - PSP Error code
// */
//Int dda_uartRead(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param)
//{
//    PSP_Result retVal;
//
//    if( (hUart == NULL) || (buf == NULL) || (size == 0) )
//    {
//        retVal = PSP_E_INVAL_PARAM;
//    }
//    else
//    {
//        retVal = PSP_uartRead(hUart, buf, size, timeout, param);
//    }
//
//    return retVal;
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Write data to UART Instance
// *
// *  This function writes data to the UART Instance.
// *
// *  \param  hUart [IN]          UART Driver Instance Handle
// *  \param  buf [IN]            Character Buffer pointer - data to be written
// *  \param  size [IN]           Size of character buffer - number of bytes to write
// *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
// *  \param  param [IN/OUT]      Extra parameter (implementation specific)
// *  \return If successful, returns positive number - number of bytes written
// *          If failed, returns negative number - PSP Error code
// */
//Int dda_uartWrite(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param)
//{
//    PSP_Result retVal;
//
//    if( (hUart == NULL) || (buf == NULL) || (size == 0) )
//    {
//        retVal = PSP_E_INVAL_PARAM;
//    }
//    else
//    {
//        retVal = PSP_uartWrite(hUart, buf, size, timeout, param);
//    }
//
//    return retVal;
//}
//
///**
// *  \brief UART init function
// *
// *  \param  instNum [IN]     UART Driver Instance Handle
// *  \param  uartCfg [IN]     UART configuration parameters
// *
// *  \return PSP_SOK or PSP Error code
// */
//static PSP_Result _init(Uint32 instNum , const PSP_UartConfig  *uartCfg)
//{
//    PAL_Result              result;
//    DDC_UartInitConfig      initConfig = {NULL,};
//    DDA_UartObj             *DDA;
//
//	result = PSP_SOK;
//	DDA = NULL;
//    DDA = &gDDA_UartObj[instNum];
//
//    if ((NULL == DDA) || (NULL  == uartCfg ))
//    {
//        result = ((PSP_Result) PSP_E_INVAL_PARAM);
//    }
//    else
//    {
//        DDA->device.instanceId = instNum;
//        result = _DDC_uartCreateInstance(
//                        instNum,             /* Instance Id          */
//                        (DDA_UartHandle)DDA, /* DDA Handle           */
//                        &DDA->device.ddcObj, /* DDC handle           */
//                        NULL);               /* No argument needed   */
//        if (result != PAL_SOK)
//        {
//            result =  (PSP_E_DRIVER_INIT);
//        }
//        else
//        {
//            initConfig.instId = DDA->device.instanceId;
//            initConfig.hEdma = uartCfg->hEdma;
//
//            if (uartCfg->opMode != PSP_OPMODE_POLLED)
//                 /* (uartCfg->opMode != PSP_OPMODE_INTERRUPT) ) &&
//                 (uartCfg->opMode != PSP_OPMODE_DMAINTERRUPT) ) */ //Mistral: Commented
//            {
//				result = ((PSP_Result) PSP_E_INVAL_PARAM);     //Mistral: Added
//                //initConfig.opMode = PSP_OPMODE_INTERRUPT;    //Mistral: Commented
//            }
//            else
//            {
//                initConfig.opMode = uartCfg->opMode;
//            }
//
//			if(result == PSP_SOK)    //Mistral: Added
//			{
//				initConfig.msecPoll = UART_TPOLL_MSECS;
//
//				initConfig.hRxCirc = &DDA->rxBufContext;
//				initConfig.hTxCirc = &DDA->txBufContext;
//				initConfig.rxBuf = DDA->rxBuf;
//				initConfig.rxBufSize = PSP_UART_CIRC_BUFSIZE;
//				initConfig.txBuf = DDA->txBuf;
//				initConfig.txBufSize = PSP_UART_CIRC_BUFSIZE;
//				initConfig.llc = &DDA->device.llc;
//
//				result = _DDC_uartInit(&DDA->device.ddcObj, &initConfig);
//				if (result != PAL_SOK)
//				{
//					/* No need to DeInit.. since the DDC functions would have unwound the operations */
//					result = PSP_E_DRIVER_INIT;
//				}
//			}
//        }
//    }
//    return result;
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Create (and initialize) a given UART driver (instance)
// *
// *  After the instance is "created", DDA calls the initialization function
// *  on the DDC to initialize the instance of the device. Typically, software
// *  bookkeeping functions are performed in this call. Memory for device
// *  instance specific data structures may be allocated and initialized.
// *  Configuration information may be passed in the call and initialization
// *  based upon this information is done.
// *
// *  \param  instNum [IN]        Uart instance number
// *  \param  param [IN/OUT]      PSP_UartConfigParams structure pointer
// *  \return PSP_SOK or PSP Error code
// */
//PSP_Result  PSP_uartCreate(Uint32 instNum, Ptr param)
//{
//    PAL_Result      result;
//    DDA_UartObj     *DDA;
//    Uint32          i;
//    PSP_UartConfig  *uartCfg;
//    static DDC_UartIoPacket     iopPool[PSP_UART_NUM_INSTANCES][PSP_UART_NUM_IOP];
//
//    result  = PAL_SOK;
//    DDA     = NULL;
//    uartCfg = NULL;
//    i       = 0;
//
//    if (NULL == param)
//    {
//        result =  ((PSP_Result) PSP_E_INVAL_PARAM);
//    }
//    else
//    {
//        uartCfg = (PSP_UartConfig *) param;
//        if ((instNum <= PSP_UART_NUM_INSTANCES) && (uartCfg->syncMode == True))
//        {
//            DDA = &gDDA_UartObj[instNum];
//            if (DDA == NULL)
//            {
//                result = (PSP_E_INVAL_PARAM);
//            }
//            else
//            {
//                DDA->device.configParams.opmode = uartCfg->opMode;
//                DDA->syncMode = uartCfg->syncMode;
//                gDDA_UartHwConfig[instNum].cfgBasic.moduleClock = uartCfg->inputFreq;
//
//                DDA->device.appCallback = uartCfg->appCallback;
//                DDA->device.cbkContext = uartCfg->cbkContext;
//                DDA->device.instanceId = instNum;
//
//                result = _init(instNum, uartCfg);
//                if (result == PAL_SOK)
//                {
//                    PAL_OSLIST_MKNODE(&DDA->ddcIopListHead);
//                    for (i = 0; i < PSP_UART_NUM_IOP; i++)
//                    {
//                        PAL_osListEnqueue((PAL_OsListNodeHeader *)&DDA->ddcIopListHead,  &iopPool[instNum][i]);
//                    }
//                    DDA->ddaState = PSP_DRIVER_STATE_CREATED;
//                }
//                else
//                {
//                    result = PSP_E_INVAL_PARAM;
//                }
//            }/* DDA verfication */
//        }
//        else
//        {
//            result = PSP_E_INVAL_PARAM;
//        }
//    }
//    return (result);
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Delete a given UART driver (instance)
// *
// *  The instance of UART is deleted in softare. Memory allocated in Create
// *  funciton is released
// *
// *  \param  instNum [IN]        Uart instance number
// *  \param  param [IN/OUT]      Extra parameter (implementation specific)
// *  \return PSP_SOK or PSP Error code
// */
//PSP_Result  PSP_uartDelete(Uint32 instNum, Ptr param)
//{
//    DDA_UartObj *DDA;
//    PSP_Result  result;
//
//    DDA    = NULL;
//    result = PSP_SOK;
//
//    /* Error checking on params */
//    if (instNum >= PSP_UART_NUM_INSTANCES)
//    {
//        result = (PSP_E_INVAL_PARAM);
//    }
//    else
//    {
//        DDA = &gDDA_UartObj[instNum];
//        if(DDA == NULL)
//        {
//            result =  (PSP_E_INVAL_PARAM);
//        }
//        else
//        {
//            if ((DDA->ddaState != PSP_DRIVER_STATE_CREATED) && (DDA->ddaState != PSP_DRIVER_STATE_CLOSED))
//            {
//                  result = PSP_E_INVAL_STATE;
//            }
//            else
//            {
//                /* De-Init DDC */
//                _DDC_uartDeInit(&DDA->device.ddcObj, NULL);
//
//                /* Delete DDC Instance */
//                _DDC_uartDelInst(&DDA->device.ddcObj, NULL);
//                DDA->ddaState = PSP_DRIVER_STATE_DELETED;
//            }
//        }
//    }
//
//    return result;
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Open Instance of the UART device
// *
// *  This function prepares the device hardware for data transfers and
// *  usage by the upper layer driver software. The DDA layer is expected
// *  to install the ISR and enable it only after the completion of this
// *  call. The function prepares the driver instance for data transfers
// *  and returns an handle to the driver instance.
// *
// *  \param  instNum [IN]        Uart instance number
// *  \param  param [IN/OUT]      Extra parameter (implementation specific)
// *  \return PSP_Handle          Uart Driver Instance Handle
// */
//PSP_Handle  PSP_uartOpen(Uint32 instNum, Ptr param)
//{
//    PAL_Result          result;
//    DDA_UartObj         *DDA;
//    DDC_UartOpenParams  openParams = {NULL,};
//    PAL_OsSemAttrs      semAttrs = {PAL_OSSEM_TYPE_FIFO, NULL};
//
//    result = PAL_SOK;
//    DDA    = NULL;
//
//    /* Check instance parameter */
//    if (instNum > PSP_UART_NUM_INSTANCES)
//    {
//            DDA = (NULL);
//            result = PSP_E_INVAL_STATE;
//    }
//    else
//    {
//        DDA = &gDDA_UartObj[instNum];
//        if(DDA == NULL)
//        {
//            result = PSP_E_INVAL_STATE;
//        }
//        else
//        {
//            if ((DDA->ddaState != PSP_DRIVER_STATE_CREATED) && (DDA->ddaState != PSP_DRIVER_STATE_CLOSED))
//            {
//                DDA = (NULL);
//                result = PSP_E_INVAL_STATE;
//            }
//        }
//    }
//    if(result == PAL_SOK)
//    {
//        /* Init the config param on DDA for get config Ioctl purpose */
//        openParams.hwConfig = &gDDA_UartHwConfig[instNum];
//        DDA->device.configParams.loopback = openParams.hwConfig->cfgBasic.enableLoopback;
//        DDA->device.configParams.fc.fcType =(PSP_UartFcType) openParams.hwConfig->cfgFlowControl.fcType;
//        DDA->device.configParams.fc.fcParam = PSP_UART_SWFC_NONE;
//
//        DDA->device.configParams.fifoEnable = openParams.hwConfig->cfgBasic.enableFifo;
//        if(DDA != NULL)
//        {
//            switch (openParams.hwConfig->cfgBasic.baudRate)
//            {
//				//Mistral Changed the code to support baud rates higher than 19200
//				//case PSP_UART_BAUD_RATE_0_3K:
//				//case PSP_UART_BAUD_RATE_1_2K:
//                //case PSP_UART_BAUD_RATE_2_4K:
//				//case PSP_UART_BAUD_RATE_4_8K:
//				//case PSP_UART_BAUD_RATE_9_6K:
//				//case PSP_UART_BAUD_RATE_19_2K:
//				case 110:
//				case 300:
//				case 1200:
//                case 2400:
//				case 4800:
//				case 9600:
//				case 19200:
//				case 38400:
//				case 57600:
//				case 115200:
//                        DDA->device.configParams.baudRate =
//                        (PSP_UartBaudRate) openParams.hwConfig->cfgBasic.baudRate;
//                        break;
//
//              default:
//                    DDA = (NULL);
//               break;
//            }
//        }
//
//        if(DDA != NULL)
//        {
//            /* Get the stop bits from user configuration */
//            switch (openParams.hwConfig->cfgBasic.numStopBits)
//            {
//                case LLC_UART_NUM_STOP_BITS_1:
//                    DDA->device.configParams.stopBits = PSP_UART_NUM_STOP_BITS_1;
//                    break;
//                case LLC_UART_NUM_STOP_BITS_2:
//                    DDA->device.configParams.stopBits = PSP_UART_NUM_STOP_BITS_2;
//                    break;
//                default:
//                    DDA = (NULL);
//                    break;
//            }
//        }
//
//        if(DDA != NULL)
//        {
//            /* Get the char len from user configuration */
//            switch (openParams.hwConfig->cfgBasic.charLen)
//            {
//                case LLC_UART_CHARLEN_5:
//                    DDA->device.configParams.charLen = PSP_UART_CHARLEN_5;
//                    break;
//                case LLC_UART_CHARLEN_6:
//                    DDA->device.configParams.charLen = PSP_UART_CHARLEN_6;
//                    break;
//                case LLC_UART_CHARLEN_7:
//                    DDA->device.configParams.charLen = PSP_UART_CHARLEN_7;
//                    break;
//                case LLC_UART_CHARLEN_8:
//                    DDA->device.configParams.charLen = PSP_UART_CHARLEN_8;
//                    break;
//                default:
//                    DDA = (NULL);
//                    break;
//            }
//        }
//
//        if(DDA != NULL)
//        {
//            /* Get the parity from user configuration */
//            switch (openParams.hwConfig->cfgBasic.parity)
//            {
//                case LLC_UART_PARITY_ODD:
//                    DDA->device.configParams.parity = PSP_UART_PARITY_ODD;
//                    break;
//                case LLC_UART_PARITY_EVEN:
//                    DDA->device.configParams.parity = PSP_UART_PARITY_EVEN;
//                    break;
//                case LLC_UART_PARITY_NONE:
//                    DDA->device.configParams.parity = PSP_UART_PARITY_NONE;
//                    break;
//                default:
//                    DDA = (NULL);
//                    break;
//            }
//        }
//
//        if(DDA != NULL)
//        {
//            /* DDC Open */
//            result = _DDC_uartOpen(&DDA->device.ddcObj, &openParams);
//            if (result != PAL_SOK)
//            {
//                DDA = (NULL);
//            }
//            else
//            {
//                /* Get interrupt number from LLC and register interrupt handler with OS */
//                DDA->ddcIntrNum = LLC_uartGetIntrNum((Int)instNum);
//
//                /* TX Sync Semaphore */
//                result = PAL_osSemCreate("UART_TX_SYNC_SEM", 1, &semAttrs, &DDA->device.hTxSemSync);
//                if (result != PAL_SOK)
//                {
//                    DDA = (NULL);
//                }
//                else
//                {
//                    if( PAL_osSemTake(DDA->device.hTxSemSync, PAL_OSSEM_NO_TIMEOUT) != PAL_SOK)
//                    {
//                        PAL_osSemDelete(DDA->device.hTxSemSync);
//                        DDA = (NULL);
//                    }
//                    else
//                    {
//                        /* RX Sync Semaphore */
//                        result = PAL_osSemCreate("UART_RX_SYNC_SEM", 1, &semAttrs, &DDA->device.hRxSemSync);
//                        if (result != PAL_SOK)
//                        {
//                            PAL_osSemDelete(DDA->device.hTxSemSync);
//                            DDA = (NULL);
//                        }
//                        else
//                        {
//                            PAL_osSemTake(DDA->device.hRxSemSync, PAL_OSSEM_NO_TIMEOUT);
//                            if (result != PAL_SOK)
//                            {
//                                PAL_osSemDelete(DDA->device.hTxSemSync);
//                                PAL_osSemDelete(DDA->device.hRxSemSync);
//                                DDA = (NULL);
//                            }
//                            else
//                            {
//                                DDA->ddaState = PSP_DRIVER_STATE_OPENED;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return ((PSP_Handle)DDA);
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Close Instance of the UART device
// *
// *  This function closes the device for data transfers and usage by the
// *  upper layer driver software. The hardware is programmed to stop/abort data
// *  transfer (depending upon the type of device and its specifics) and the
// *  device ISR is "disabled" by the upper layer driver software after the
// *  completion of this call. After the successful completion of this call, the
// *  device cannot perform any data IO.
// *
// *  \param  hUart [IN]          UART Driver Instance Handle
// *  \param  param [IN/OUT]      Extra parameter (implementation specific)
// *  \return PSP_SOK or PSP Error code
// */
//PSP_Result  PSP_uartClose(PSP_Handle hUart, Ptr param)
//{
//    DDA_UartObj     *DDA;
//    PSP_Result      retCode;
//
//    retCode = PSP_SOK;
//    DDA     = NULL;
//
//    if (NULL == hUart)
//    {
//        retCode = (PSP_E_INVAL_PARAM);
//    }
//    else
//    {
//        DDA = (DDA_UartObj *)hUart;
//        if(DDA != NULL) {
//            if (DDA->ddaState == PSP_DRIVER_STATE_OPENED)
//            {
//                /* Close DDC */
//                _DDC_uartClose(&DDA->device.ddcObj,NULL);
//
//                if (DDA->syncMode == True)
//                {
//                    /* Delete TX Sempahore for sync */
//                    PAL_osSemDelete(DDA->device.hTxSemSync);
//
//                    /* Delete RX Sempahore for sync */
//                    PAL_osSemDelete(DDA->device.hRxSemSync);
//                }
//                DDA->ddaState = PSP_DRIVER_STATE_CLOSED;
//            }
//        }
//        else
//        {
//            retCode = PSP_E_INVAL_STATE;
//        }
//    }
//    return (retCode);
//}
//
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Read data from UART Instance
// *
// *  This function reads data from the UART Instance.
// *
// *  \param  hUart [IN]          UART Driver Instance Handle
// *  \param  buf [IN/OUT]        Character Buffer pointer - where read data is to be stored
// *  \param  size [IN]           Size of character buffer - number of bytes to read
// *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
// *  \param  param [IN/OUT]      Extra parameter (implementation specific)
// *  \return If successful, returns positive number - number of bytes read
// *          In Async mode, if number of bytes read is less than size, the request
// *          is pending and in progress.
// *          If failed, returns negative number - PSP Error code
// */
//Int PSP_uartRead(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param)
//{
//    return (_io(hUart, buf, size, DDC_UART_IOCMD_READ, (Uint32)timeout));
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief Write data to UART Instance
// *
// *  This function writes data to the UART Instance.
// *
// *  \param  hUart [IN]          UART Driver Instance Handle
// *  \param  buf [IN]            Character Buffer pointer - data to be written
// *  \param  size [IN]           Size of character buffer - number of bytes to write
// *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
// *  \param  param [IN/OUT]      Extra parameter (implementation specific)
// *  \return If successful, returns positive number - number of bytes written
// *          In Async mode, if number of bytes written is less than size, the request
// *          is pending and in progress.
// *          If failed, returns negative number - PSP Error code
// */
//Int PSP_uartWrite(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param)
//{
//    return (_io(hUart, buf, size, DDC_UART_IOCMD_WRITE, (Uint32)timeout));
//}
//
///**
// *  \brief IO processing function
// *
// *  \param  hUart   [IN]     UART Driver Instance Handle
// *  \param  buf     [IN]     Character Buffer pointer
// *  \param  size    [IN]     Size of character buffer
// *  \param  cmd     [IN]     Operation to be performed, typically an enum gets passed
// *  \param  timeout [IN]     Timeout (typically in milliSeconds)
// *
// *  \return PAL_SOK If success or suitable error code
// */
//static Int _io(PSP_Handle hUart,const Char *buf, Int size, Uint32 cmd, Uint32 timeout)
//{
//    DDA_UartObj         *DDA;
//    DDC_UartIoPacket    *iop;
//    PAL_Result          result;
//
//    DDA = NULL;
//    iop = NULL;
//    result = PAL_SOK;
//
//    if ( ( ( (hUart == NULL)  || (buf == NULL) ) || (size <= 0) ) )
//    {
//        result = PSP_E_INVAL_PARAM;
//    }
//    else
//    {
//        DDA = (DDA_UartObj *)hUart;
//
//        if (PSP_DRIVER_STATE_OPENED != DDA->ddaState)
//        {
//            result = PSP_E_INVAL_STATE;
//        }
//        else
//        {
//            if(DDA->device.configParams.opmode == PSP_OPMODE_DMAINTERRUPT)
//            {
//                if( ( (Uint32)buf & (Uint32)0x1Fu ) != 0)
//                {
//                    result = (PSP_E_INVAL_PARAM);
//                }
//            }
//
//            if(timeout == 0)
//            {
//                result = PSP_E_TIMEOUT;
//            }
//
//            if(result == PAL_SOK)
//            {
//                /* Allocate IOP */
//                iop = allocIop(DDA);
//                if (iop == NULL)
//                {
//                    result = PSP_E_NO_MEMORY;
//                }
//                else
//                {
//                    iop->appContext     = hUart;
//                    iop->cmd            = (Uint8)cmd;
//                    iop->buf            = (Ptr)buf;
//                    iop->xferRequest    = (Uint32)size;
//                    iop->xferActual     = 0;
//                    iop->timeout        = timeout;
//                    iop->flags          = 0;
//                    checkDmaTimeout     = FALSE;
//
//                    /* Submit IOP to DDC */
//                    result = _DDC_uartSubmitIoReq(&DDA->device.ddcObj, iop);
//                    if (result == PAL_SINPROGRESS)
//                    {
//                        /* Sync Mode Operation: So wait on a semaphore for the timeout or completion or error */
//                        Uint32  cookie;
//
//                        if (DDC_UART_IOCMD_WRITE == cmd)
//                        {
//                            result = PAL_osSemTake(DDA->device.hTxSemSync, timeout);
//                        }
//                        else
//                        {
//                            result = PAL_osSemTake(DDA->device.hRxSemSync, timeout);
//                        }
//
//
//                        if (PAL_SOK != result)
//                        {
//                            if(DDA->device.configParams.opmode == PSP_OPMODE_DMAINTERRUPT)
//                            {
//                                checkDmaTimeout = TRUE;
//                                if (DDC_UART_IOCMD_WRITE == cmd)
//                                {
//                                    result = PAL_osSemTake(DDA->device.hTxSemSync, -1);
//                                }
//                                else
//                                {
//                                    result = PAL_osSemTake(DDA->device.hRxSemSync, -1);
//                                }
//                            }
//                            else
//                            {
//                                /* Either IOP timedout or error occurred and the notifycallback released the sem
//                                    so cancel the IOP */
//                                PAL_osProtectEntry(PAL_OSPROTECT_INTERRUPT, &cookie);
//                                result = _DDC_uartCancelIo(&DDA->device.ddcObj, iop);
//                                PAL_osProtectExit(PAL_OSPROTECT_INTERRUPT, cookie);
//                            }
//                            iop->result = PSP_E_TIMEOUT;
//                        }
//                        else
//                        {
//                            iop->result = result;
//                            /* IOP was successful */
//                        }
//                    }
//                    else
//                    {
//                        if(result == PAL_SOK)
//                        {
//                            iop->result = PAL_SOK;
//                        }
//                        else
//                        {
//                            iop->result = PSP_E_INVAL_PARAM;
//                        }
//                    }
//                }
//            } /* End of if(result == PAL_SOK) */
//        }
//    }
//
//    if(iop != NULL)
//    {
//        result = iop->result;
//    }
//    return result;
//}
//
///* Note: "param" not used in this implementation */
///**
// *  \brief UART Ioctl
// *
// *  This function provides ioctl functionality for UART
// *
// *  \param  hUart [IN]          UART Driver Instance Handle
// *  \param  cmd [IN]            Operation to be performed, typically an enum gets passed
// *  \param  cmdArg [IN/OUT]     Provides additonal information related to the operation
// *  \param  param [IN/OUT]      Device/Cmd specific argument
// *  \return PSP_SOK or PSP Error code
// */
//PSP_Result  PSP_uartIoctl(PSP_Handle hUart,
//                          PSP_UartIoctlCmd cmd,
//                          Ptr cmdArg,
//                          Ptr param)
//{
//    DDA_UartObj             *DDA;
//    PSP_UartCharLen         charLen;
//    LLC_UartCharLen         ddcCharLen;
//    PSP_UartParity          parity;
//    LLC_UartParity          ddcParity;
//    PSP_UartNumStopBits     stopBits;
//    LLC_UartNumStopBits     ddcStopBits;
//    Uint32                  baudRate;
//    PSP_UartFlowControl     *fc;
//    PAL_Result              result;
//    PSP_UartRxTrigLvl       trigLevel;
//    Uint32 value;
//
//    DDA    = NULL;
//    fc     = NULL;
//    result = PSP_SOK;
//    value  = 0;
//
//
//    /* Error checking of params */
//    if (hUart == NULL)
//    {
//        result = (PSP_E_INVAL_STATE);
//    }
//    else
//    {
//        DDA = (DDA_UartObj *)hUart;
//        if (DDA->ddaState != PSP_DRIVER_STATE_OPENED)
//        {
//              result = (PSP_E_INVAL_STATE);
//        }
//    }
//
//    if(result == PAL_SOK)
//    {
//        switch (cmd)
//        {
//            case PSP_UART_IOCTL_CANCEL_IO: /* Cancel all the Tx and Rx requests */
//                {
//                    result = _DDC_uartControl(&DDA->device.ddcObj, DDC_UART_IOCTL_CANCEL_IO, cmdArg, NULL);
//                    if (result != PAL_SOK)
//                    {
//                        result = PSP_E_IO_CANCEL_FAIL;
//                    }
//                }
//                break;
//
//            case PSP_UART_IOCTL_GET_STATS:
//                result = _DDC_uartControl(&DDA->device.ddcObj, DDC_UART_IOCTL_GET_STATS, cmdArg, NULL);
//                break;
//
//            case PSP_UART_IOCTL_CLEAR_STATS:
//                result = _DDC_uartControl(&DDA->device.ddcObj, DDC_UART_IOCTL_SET_STATSCLEAR, cmdArg, NULL);
//                break;
//
//            case PSP_UART_IOCTL_SET_TRIGGER_LEVEL:
//            {
//                trigLevel = *((PSP_UartRxTrigLvl *)cmdArg);
//                if(DDA->device.configParams.fifoEnable == TRUE)
//                {
//                    switch (trigLevel)
//                    {
//                        case PSP_UART_RX_TRIG1:
//                             value |= 0x0;/* Receive FIFO trigger level 1 byte */
//                             DDA->device.configParams.trigLvl = PSP_UART_RX_TRIG1;
//                             break;
//                        case PSP_UART_RX_TRIG4:
//                            value |= 0x40u;/* Receive FIFO trigger level 4 byte */
//                            DDA->device.configParams.trigLvl = PSP_UART_RX_TRIG4;
//                            break;
//                        case PSP_UART_RX_TRIG8:
//                            value |= 0x80u;/* Receive FIFO trigger level 8 byte */
//                            DDA->device.configParams.trigLvl = PSP_UART_RX_TRIG8;
//                            break;
//                        case PSP_UART_RX_TRIG14:
//                        default:
//                            value |= 0xC0u;/* Receive FIFO trigger level 14 byte */
//                            DDA->device.configParams.trigLvl = PSP_UART_RX_TRIG14;
//                            break;
//                    }
//
//                    LLC_uartSetReceiverThreshold(DDA->device.ddcObj.llc,value);
//                }
//                else
//                {
//                    result = PSP_E_FIFO_NOT_ENABLED;
//                }
//            }
//            break;
//
//            case PSP_UART_IOCTL_SET_TX_FIFO_CLEAR:
//                /* check if FIFO is supported and then Call to DDC layer */
//                if(DDA->device.configParams.fifoEnable == TRUE)
//                {
//                  LLC_uartClearXmitterFifo(DDA->device.ddcObj.llc);
//                }
//                else
//                {
//                    result = PSP_E_FIFO_NOT_ENABLED;
//                }
//
//                break;
//
//            case PSP_UART_IOCTL_SET_RX_FIFO_CLEAR:
//                /* check if FIFO is supported and then Call to DDC layer */
//                if(DDA->device.configParams.fifoEnable == TRUE)
//                {
//                  LLC_uartClearReceiverFifo(DDA->device.ddcObj.llc);
//                }
//                else
//                {
//                    result = PSP_E_FIFO_NOT_ENABLED;
//                }
//                break;
//
//            case PSP_UART_IOCTL_SET_FIFO_MODE:
//                {
//                     /* Mode not supported */
//                    result = PSP_E_NOT_SUPPORTED;
//                    break;
//                }
//
//            case PSP_UART_IOCTL_GET_CONFIG_PARAMS:
//                /* Return current params */
//                if (cmdArg == NULL)
//                {
//                    result = PSP_E_INVAL_PARAM;
//                }
//                else
//                {
//                    *((PSP_UartConfigParams *)cmdArg) = DDA->device.configParams;
//                }
//                break;
//
//            case PSP_UART_IOCTL_SET_OPMODE:
//                /* Mode not supported */
//                result = PSP_E_NOT_SUPPORTED;
//                break;
//
//            case PSP_UART_IOCTL_SET_BAUD:
//                {
//                    /* Perform error checking on baud rate */
//                    baudRate = *((Uint32 *)cmdArg);
//                    switch(baudRate)
//                    {
//						//Mistral Changed the code to support baud rates higher than 19200
//                        //case PSP_UART_BAUD_RATE_2_4K:
//                        //case PSP_UART_BAUD_RATE_4_8K:
//                        //case PSP_UART_BAUD_RATE_9_6K:
//                        //case PSP_UART_BAUD_RATE_19_2K:
//                        case 110:
//				        case 300:
//				        case 1200:
//                        case 2400:
//				        case 4800:
//				        case 9600:
//				        case 19200:
//				        case 38400:
//				        case 57600:
//				        case 115200:
//                            result = PSP_SOK;
//                            break;
//
//                        default:
//                            result = PSP_E_INVAL_PARAM;
//                            break;
//                    }
//
//                    if (result == PSP_SOK)
//                    {
//                        result = _DDC_uartControl(&DDA->device.ddcObj, DDC_UART_IOCTL_SET_BAUD_RATE, cmdArg, NULL);
//                        if (PAL_SOK == result)
//                        {
//                            DDA->device.configParams.baudRate = *((PSP_UartBaudRate *)cmdArg);
//                        }
//                    }
//                }
//                break;
//
//            case PSP_UART_IOCTL_SET_STOPBITS:
//                {
//                    stopBits = *((PSP_UartNumStopBits *)cmdArg);
//                    switch (stopBits)
//                    {
//                        case PSP_UART_NUM_STOP_BITS_1:
//                            ddcStopBits = LLC_UART_NUM_STOP_BITS_1;
//                            break;
//                        case PSP_UART_NUM_STOP_BITS_1_5:
//                            ddcStopBits = LLC_UART_NUM_STOP_BITS_1_5;
//                            break;
//                        case PSP_UART_NUM_STOP_BITS_2:
//                            ddcStopBits = LLC_UART_NUM_STOP_BITS_2;
//                            break;
//                        default:
//                            result = (PSP_E_INVAL_PARAM);
//                    }
//
//                    if(result == PAL_SOK)
//                    {
//                        result = _DDC_uartControl(&DDA->device.ddcObj, DDC_UART_IOCTL_SET_NUM_STOP_BITS, &ddcStopBits, NULL);
//                        if (PAL_SOK == result)
//                        {
//                            DDA->device.configParams.stopBits = stopBits;
//                        }
//                    }
//                }
//                break;
//
//            case PSP_UART_IOCTL_SET_DATABITS:
//                {
//                    charLen = *((PSP_UartCharLen *)cmdArg);
//                    switch (charLen)
//                    {
//                        case PSP_UART_CHARLEN_5:
//                            ddcCharLen = LLC_UART_CHARLEN_5;
//                            break;
//                        case PSP_UART_CHARLEN_6:
//                            ddcCharLen = LLC_UART_CHARLEN_6;
//                            break;
//                        case PSP_UART_CHARLEN_7:
//                            ddcCharLen = LLC_UART_CHARLEN_7;
//                            break;
//                        case PSP_UART_CHARLEN_8:
//                            ddcCharLen = LLC_UART_CHARLEN_8;
//                            break;
//                        default:
//                            result = (PSP_E_INVAL_PARAM);
//                    }
//
//                    if(result == PAL_SOK)
//                    {
//                        result = _DDC_uartControl(&DDA->device.ddcObj, DDC_UART_IOCTL_SET_CHARLEN, &ddcCharLen, NULL);
//                        if (PAL_SOK == result)
//                        {
//                           DDA->device.configParams.charLen = charLen;
//                        }
//                    }
//                }
//                break;
//
//            case PSP_UART_IOCTL_SET_PARITY:
//                {
//                    parity = *((PSP_UartParity *)cmdArg);
//                    switch (parity)
//                    {
//                        case PSP_UART_PARITY_ODD:
//                            ddcParity= LLC_UART_PARITY_ODD;
//                            break;
//                        case PSP_UART_PARITY_EVEN:
//                            ddcParity = LLC_UART_PARITY_EVEN;
//                            break;
//                        case PSP_UART_PARITY_NONE:
//                            ddcParity = LLC_UART_PARITY_NONE;
//                            break;
//                        default:
//                            result = (PSP_E_INVAL_PARAM);
//                    }
//
//                    if(result == PAL_SOK)
//                    {
//                        result = _DDC_uartControl(&DDA->device.ddcObj, DDC_UART_IOCTL_SET_PARITY, &ddcParity, NULL);
//                        if (PAL_SOK == result)
//                        {
//                            DDA->device.configParams.parity = parity;
//                        }
//                    }
//                }
//                break;
//
//            case PSP_UART_IOCTL_SET_LOOPBACK:
//                /* Mode not supported */
//                result = PSP_E_NOT_SUPPORTED;
//                break;
//
//            case PSP_UART_IOCTL_SET_FLOWCONTROL:
//                fc = (PSP_UartFlowControl *)cmdArg;
//                if(fc != NULL)
//                {
//                    switch(fc->fcType)
//                    {
//                        case PSP_UART_FC_TYPE_HW:
//                            /* Directly call LLC as there is no need to go through DDC in this case */
//                            LLC_uartEnableHwFlowControl(DDA->device.ddcObj.llc);
//                            break;
//
//                        case PSP_UART_FC_TYPE_NONE:
//                            /* Directly call LLC as there is no need to go through DDC in this case */
//                            LLC_uartDisableHwFlowControl(DDA->device.ddcObj.llc);
//                            break;
//                        case PSP_UART_FC_TYPE_SW:
//                        default:
//                            result = PSP_E_NOT_SUPPORTED;
//                        break;
//                    }
//                }
//                else
//                {
//                    result = PSP_E_INVAL_PARAM;
//                }
//
//                if (PAL_SOK == result)
//                {
//                    DDA->device.configParams.fc = *((PSP_UartFlowControl *)cmdArg);
//                }
//                break;
//
//            default:
//                result = PSP_E_INVAL_PARAM;
//                break;
//        }
//    }
//
//    return (result);
//}
//
///**
// *  \brief Allocates IOP from the free list
// *
// *  \param  hDDA [IN]     DDA handle
// *  \return IOP If success or NULL
// */
//static DDC_UartIoPacket *allocIop(
//                    Ptr         hDDA)
//{
//    DDA_UartObj         *DDA;
//    DDC_UartIoPacket    *iop;
//
//    DDA = NULL;
//    iop = NULL;
//
//    if(hDDA != NULL)
//    {
//      DDA = (DDA_UartObj*)hDDA;
//      if ( PAL_osListIsEmpty(&DDA->ddcIopListHead) == NULL )
//      {
//          iop = (DDC_UartIoPacket *)PAL_osListRemoveHead(&DDA->ddcIopListHead);
//          if(iop != NULL)
//          {
//                PAL_OSLIST_MKNODE((PAL_OsListNodeHeader *)iop);
//          }
//      }
//    }
//    return (iop);
//}
//
///* Mistral: Added call back routine. */
///**
// *  \brief Call back function to indicate IO completion
// *
// *  \param  hDDA [IN]     DDA handle
// *  \param  iop  [IN]     IO pointer
// *  \return PSP_SOK or PSP Error code
// */
//PAL_Result _DDA_uartIoComplete(DDA_UartHandle hDDA,DDC_UartIoPacket * const iop)
//{
//	PAL_Result result = PAL_SOK;
//	DDA_UartObj *DDA = NULL;
//	Bool flag_giveSem = FALSE;
//
//   	if ( ( (hDDA != NULL) && (iop != NULL) ) == TRUE )
//   	{
//		DDA = (DDA_UartObj *)hDDA;
//
//		switch(iop->result)
//		{
//
//			case DDC_UART_E_REQ_TIMEOUT:
//			{
//				if(DDA->device.configParams.opmode == PSP_OPMODE_DMAINTERRUPT)
//				{
//					flag_giveSem = TRUE;
//				}
//				break;
//			}
//
//			case DDC_UART_E_DMA_TRANSFER_FAIL:
//			{
//				flag_giveSem = TRUE;
//				break;
//			}
//
//			case DDC_UART_E_IOP_ABORTED:
//			{
//				flag_giveSem = TRUE;
//				break;
//			}
//
//			case DDC_UART_E_IOP_FLUSHED:
//			{
//				flag_giveSem = TRUE;
//				break;
//			}
//
//			case PAL_SOK:
//				default:
//				{
//					flag_giveSem = TRUE;
//					break;
//				}
//		}
//
//
//		if ( DDA->device.configParams.opmode != PSP_OPMODE_POLLED )
//        {
//           	if( flag_giveSem == TRUE )
//           	{
//				if (DDC_UART_IOCMD_WRITE == iop->cmd)
//				{
//					result = PAL_osSemGive(DDA->device.hTxSemSync);
//				}
//				else
//				{
//					result = PAL_osSemGive(DDA->device.hRxSemSync);
//				}
//			}
//        }
//
//    	if (DDA->device.appCallback != NULL)
//    	{
//			//Mistral: Commented as Asynchronous Mode is not supported in this implementation
//        //	DDA->device.appCallback(DDA->device.cbkContext, iop->buf, iop->xferActual);
//    	}
//     	/* Free packet structure */
//     	PAL_osListEnqueue(&DDA->ddcIopListHead, (Ptr)iop);
//   	}
//
//    return (result);
//}
///* End of file */
