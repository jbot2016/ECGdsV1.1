#ifndef PSP_UART_H_
#define PSP_UART_H_

/*****************************************************************************
 * File Name : psp_uart.h 
 *
 * Brief	 : UART interface definition 
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

//#ifndef _PSP_UART_H_
//#define _PSP_UART_H_

/* PSP Common header provides standard driver return codes, operation modes
 * and other generic defines required by all PSP drivers
 */
#include "psp_common.h"
#include "tistdtypes.h"


/**
 * \defgroup PSPUartMain PSP UART Interface Definitions
 *
 * All interface definitions for PSP UART are contained in this file.
 *
 * @{
 */


#define PSP_UART_MODULE_CLOCK 12000000u		/**< Input freq to UART module */

/**
 *  \brief  default Init Config at Init time
 *
 *  Default value to be used by the driver if user does not give any specifications.
 */


#define UARTMD_DEVPARAMS_DEFAULT 		\
{      									\
    PSP_OPMODE_INTERRUPT,				\
    TRUE,								\
	PSP_UART_MODULE_CLOCK,				\
	NULL								\
}


#define PSP_UART_EVENTQUEUE_USED   0
/**< EDMA Event Queue used          */

/* Mistral: Use Direct values for setting the baud rate instead of using enum values
 * Refer to UART documentation for supported baud rate values.
 */
/**
 *  \brief  PSP Uart Baud Rate
 *
 *  Uart Baud rate
 */
typedef enum
{
	PSP_UART_BAUD_RATE_0_3K     = 300,
    PSP_UART_BAUD_RATE_1_2K     = 1200,
    PSP_UART_BAUD_RATE_2_4K     = 2400,
    PSP_UART_BAUD_RATE_4_8K     = 4800,
    PSP_UART_BAUD_RATE_9_6K     = 9600,
    PSP_UART_BAUD_RATE_19_2K    = 19200
} PSP_UartBaudRate;

/**
 *  \brief  PSP Uart Character Length
 *
 *  Uart Character length
 */
typedef enum
{
    PSP_UART_CHARLEN_5  = 5,
    PSP_UART_CHARLEN_6  = 6,
    PSP_UART_CHARLEN_7  = 7,
    PSP_UART_CHARLEN_8  = 8
} PSP_UartCharLen;

/**
 *  \brief  PSP Uart Parity
 *
 *  Uart Parity
 */
typedef enum
{
    PSP_UART_PARITY_ODD     = 0,
    PSP_UART_PARITY_EVEN    = 1,
    PSP_UART_PARITY_NONE    = 2
} PSP_UartParity;

/**
 *  \brief  PSP Uart Stop Bits
 *
 *  Uart Stop Bits
 */
typedef enum
{
    PSP_UART_NUM_STOP_BITS_1    = 0,
    PSP_UART_NUM_STOP_BITS_1_5  = 1,
    PSP_UART_NUM_STOP_BITS_2    = 2
} PSP_UartNumStopBits;

/**
 *  \brief  PSP Uart Flow Control
 *
 *  Uart Flow Control
 */
typedef enum
{
    PSP_UART_FC_TYPE_NONE   = 0,    /**< No Flow Control */
    PSP_UART_FC_TYPE_SW     = 1,    /**< Software Flow Control - NOT SUPPORTED IN THIS DRIVER */
    PSP_UART_FC_TYPE_HW     = 2     /**< Hardware Flow Control */
} PSP_UartFcType;

/**
 *  \brief  PSP Uart Software Flow Control Param
 *
 *  Uart Software Flow Control Mode Param
 */
typedef enum
{
    PSP_UART_SWFC_NONE          = 0,
    PSP_UART_SWFC_XONXOFF_1     = 1,
    PSP_UART_SWFC_XONXOFF_2     = 2,
    PSP_UART_SWFC_XONXOFF_12    = 3
} PSP_UartFcParam;

/**
 *  \brief  PSP Uart Rx Trigger Level Param
 *
 *  Uart Receive Trigger Level Param
 */
typedef enum
{
    PSP_UART_RX_TRIG1   = 1,    /**< Trigger Level 1*/
    PSP_UART_RX_TRIG4   = 4,    /**< Trigger Level 4*/
    PSP_UART_RX_TRIG8   = 8,    /**< Trigger Level 8*/
    PSP_UART_RX_TRIG14  = 14    /**< Trigger Level 14*/
}PSP_UartRxTrigLvl;
/**
 *  \brief  PSP Uart Flow Control Configuration
 *
 *  Uart Software Flow Control Configuration
 */
typedef struct
{
    PSP_UartFcType  fcType;         /**< Flow Control type */
    PSP_UartFcParam fcParam;        /**< Flow Control param */
} PSP_UartFlowControl;


/**
 *  \brief  UART Configuration Parameters
 *
 *  UART Configuration Parameters that should be passed by the application
 *  during PSP_uartCreate
 *
 *  Note: Loopback is not supported in DMA mode. In case DMA mode is selected and
 *		   loopback is TRUE, driver will return an invalid parameter error code.
 */
typedef struct
{
    PSP_OpMode          opmode;			/**< Mode of Operation Polled/Interrupt/DMA */
    Uint32              baudRate;		/**< Baud Rate */
    PSP_UartNumStopBits stopBits;		/**< Number of Stop Bits */
    PSP_UartCharLen     charLen;		/**< Character Lenght */
    PSP_UartParity      parity;			/**< Parity Settings */
    PSP_UartFlowControl fc;				/**< Flow Control Enable/Disable */
    PSP_UartRxTrigLvl   trigLvl;        /**< UART trigger level */
    Bool                loopback;		/**< Enable or Disable the Loopback */
    Bool                fifoEnable;		/**< FIFO Enable/Disable */
} PSP_UartConfigParams;


/**
 *  \brief  PSP Uart Ioctl commands
 *
 *  Uart Ioctl commands
 */
typedef enum
{
    PSP_UART_IOCTL_GET_CONFIG_PARAMS = 0,	/**< Get UART config params, cmdArg = struct* UartConfigParams */
    PSP_UART_IOCTL_SET_BAUD,				/**< Set baud rate, cmdArg= struct* UartBaudRate */
    PSP_UART_IOCTL_SET_STOPBITS,			/**< Set number of stop bits, cmdArg = sturct* UartNumStopBits */
    PSP_UART_IOCTL_SET_DATABITS,			/**< Set number of Data bits, cmdArg = sturct* UartCharLen*/
    PSP_UART_IOCTL_SET_PARITY,				/**< Set parity type, cmdArg = sturct* UartParity */
    PSP_UART_IOCTL_SET_FLOWCONTROL,			/**< Set flowcontrol, cmdArg = sturct* UartFlowControl*/
	PSP_UART_IOCTL_SET_TRIGGER_LEVEL,		/**< Changing Trigger level  */
	PSP_UART_IOCTL_SET_RX_FIFO_CLEAR,		/**< Clears the RX  FIFO    	*/
	PSP_UART_IOCTL_SET_TX_FIFO_CLEAR,		/**< Clears the  TX FIFO    	*/
	PSP_UART_IOCTL_CANCEL_IO,				/**< Cancel IO           */
	PSP_UART_IOCTL_GET_STATS,				/**< Getting the Uart stats for DDC  */
	PSP_UART_IOCTL_CLEAR_STATS,     		/**< Clearing the Stats of DDC */
	PSP_UART_IOCTL_SET_FIFO_MODE,			/**< Enabling/Disabling the FIFO */
    PSP_UART_IOCTL_SET_LOOPBACK,			/**< Set loopback, cmdArg=Bool */
    PSP_UART_IOCTL_SET_OPMODE,				/**< Set operation mode, cmdArg= struct* IOM_OpMode */
	PSP_UART_IOCTL_MAX_IOCTL				/**< Book-keep - Max ioctl's */
} PSP_UartIoctlCmd;



/**
 * \brief UART DDC Statistics Collection Object
 *
 * Statistics are collected on a per-controller basis for UART. Hence, an
 * object of this type is found embedded in the DDC_UartObj structure.
 */
typedef struct
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
} PSP_UartStats;


/**
 *  \brief  PSP Uart Config (at Init/Create time)
 *
 *  UART Configuration structure pointer passed to PSP_uartCreate function
 */
typedef struct
{
    Uint32              inputFreq;          /**< Input Frequency in MHZ */
    Uint32              heapSegId;          /**< *** NOT USE IN THIS DRIVER VERSION *** */
    Bool                syncMode;           /**< Sync mode enabled? */
    PSP_AppCallback     appCallback;        /**< Application Callback function when in Async mode - Can be called in interrupt context */
    Ptr                 cbkContext;         /**< Application Callback context when in Async mode*/
    PSP_OpMode          opMode;             /**< Operational mode of the UART instance - polled/interrupt/dma - DMA NOT SUPPORTED */
    Ptr                 hEdma;              /**< Dma handle for UART transfer */
} PSP_UartConfig;


/**
 *  \brief  Init Config at Init time
 *
 *  UART Configuration structure pointer passed to mdBindDev function.
 */
typedef struct
{
    PSP_OpMode	opMode;			/**< Opmode defined at init (eg. POLLED mode)*/
    Bool        syncMode;   	/**< Sync mode enabled 						 */
	Uint32 		inputFrequency; /**< Default input frequency of the uart	 */
	Ptr         hEdma;			/**< EDMA Handle							 */
} UARTMD_DevParams;



/**
 *  \brief  IOM_PACKET element structure
 *
 *  Structure for the uart specific buffer address to be passed to the GIO.
 */
typedef struct
{
	char * addr;               /**< Address of the data buffer */
	Uint32 timeout;            /**< Timeout variable */
} PSP_uartDataParam;


/**
 *  \brief Create (and initialize) a given UART driver (instance)
 *
 *  After the instance is "created", DDA calls the initialization function
 *  on the DDC to initialize the instance of the device. Typically, software
 *  bookkeeping functions are performed in this call. Memory for device
 *  instance specific data structures may be allocated and initialized.
 *  Configuration information may be passed in the call and initialization
 *  based upon this information is done.
 *
 *  \param  instNum [IN]        Uart instance number
 *  \param  param [IN/OUT]      PSP_UartConfigParams structure pointer
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result  PSP_uartCreate(Uint32 instNum, Ptr param);

/**
 *  \brief Delete a given UART driver (instance)
 *
 *  The instance of UART is deleted in softare. Memory allocated in Create
 *  funciton is released
 *
 *  \param  instNum [IN]        Uart instance number
 *  \param  param [IN/OUT]      Extra parameter (implementation specific)
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result  PSP_uartDelete(Uint32 instNum, Ptr param);

/**
 *  \brief Open Instance of the UART device
 *
 *  This function prepares the device hardware for data transfers and
 *  usage by the upper layer driver software. The DDA layer is expected
 *  to install the ISR and enable it only after the completion of this
 *  call. The function prepares the driver instance for data transfers
 *  and returns an handle to the driver instance.
 *
 *  \param  instNum [IN]        Uart instance number
 *  \param  param [IN/OUT]      Extra parameter (implementation specific)
 *  \return PSP_Handle          Uart Driver Instance Handle
 */
PSP_Handle  PSP_uartOpen(Uint32 instNum, Ptr param);

/**
 *  \brief Close Instance of the UART device
 *
 *  This function closes the device for data transfers and usage by the
 *  upper layer driver software. The hardware is programmed to stop/abort data
 *  transfer (depending upon the type of device and its specifics) and the
 *  device ISR is "disabled" by the upper layer driver software after the
 *  completion of this call. After the successful completion of this call, the
 *  device cannot perform any data IO.
 *
 *  \param  hUart [IN]          UART Driver Instance Handle
 *  \param  param [IN/OUT]      Extra parameter (implementation specific)
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result  PSP_uartClose(PSP_Handle hUart, Ptr param);

/**
 *  \brief Read data from UART Instance
 *
 *  This function reads data from the UART Instance.
 *
 *  \param  hUart [IN]          UART Driver Instance Handle
 *  \param  buf [IN/OUT]        Character Buffer pointer - where read data is to be stored
 *  \param  size [IN]           Size of character buffer - number of bytes to read
 *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
 *  \param  param [IN/OUT]      Extra parameter (implementation specific)
 *  \return If successful, returns positive number - number of bytes read
 *          In Async mode, if number of bytes read is less than size, the request
 *          is pending and in progress.
 *          If failed, returns negative number - PSP Error code
 */
Int  PSP_uartRead(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param);

/**
 *  \brief Write data to UART Instance
 *
 *  This function writes data to the UART Instance.
 *
 *  \param  hUart [IN]          UART Driver Instance Handle
 *  \param  buf [IN]            Character Buffer pointer - data to be written
 *  \param  size [IN]           Size of character buffer - number of bytes to write
 *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
 *  \param  param [IN/OUT]      Extra parameter (implementation specific)
 *  \return If successful, returns positive number - number of bytes written
 *          In Async mode, if number of bytes written is less than size, the request
 *          is pending and in progress.
 *          If failed, returns negative number - PSP Error code
 */
Int  PSP_uartWrite(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param );


/**
 *  \brief UART Ioctl
 *
 *  This function provides ioctl functionality for UART
 *
 *  \param  hUart [IN]          UART Driver Instance Handle
 *  \param  cmd [IN]            Operation to be performed, typically an enum gets passed
 *  \param  cmdArg [IN/OUT]     Provides additonal information related to the operation
 *  \param  param [IN/OUT]      Device/Cmd specific argument
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result  PSP_uartIoctl(PSP_Handle hUart, PSP_UartIoctlCmd cmd, Ptr cmdArg, Ptr param);

/**
 *  \brief UART initialization function
 *
 *  This function creates the function pointer to the DDC Layer
 * and sets the parameters for the internal buffer
 * and initializes the DDC
 *
 *  \param  instNum [IN]      UART Driver Instance Number
 *  \param  param [IN/OUT]    Extra parameter(Implementation specific)
 *  \return Handle to the UART instance
 */
PSP_Handle dda_uartInit(Uint32 instNum, Ptr param);

/**
 *  \brief Write data to UART Instance
 *
 *  This function writes data to the UART Instance.
 *
 *  \param  hUart [IN]          UART Driver Instance Handle
 *  \param  buf [IN]            Character Buffer pointer - data to be written
 *  \param  size [IN]           Size of character buffer - number of bytes to write
 *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
 *  \param  param [IN/OUT]      Extra parameter (implementation specific)
 *  \return If successful, returns positive number - number of bytes written
 *          If failed, returns negative number - PSP Error code
 */
Int dda_uartWrite(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param);


/**
 *  \brief Read data from UART Instance
 *
 *  This function reads data from the UART Instance.
 *
 *  \param  hUart [IN]          UART Driver Instance Handle
 *  \param  buf [IN/OUT]        Character Buffer pointer - where read data is to be stored
 *  \param  size [IN]           Size of character buffer - number of bytes to read
 *  \param  timeout [IN]        NOT SUPPORTED - Timeout (typically in milliSeconds)
 *  \param  param [IN/OUT]      Extra parameter (implementation specific)
 *  \return If successful, returns positive number - number of bytes read
 *          If failed, returns negative number - PSP Error code
 */
Int dda_uartRead(PSP_Handle hUart, const Char *buf, Int size, Int timeout, Ptr param);

/*@} PSPUartMain */
//#endif  /* _PSP_UART_H_ */



#endif /*PSP_UART_H_*/
