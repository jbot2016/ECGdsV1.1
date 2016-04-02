#ifndef DDC_SPI_H_
#define DDC_SPI_H_

/*****************************************************************************
 * File Name : ddc_spi.h 
 *
 * Brief	 : header file for SPI implementation
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

//#ifndef _DDC_SPI_H_
//#define _DDC_SPI_H_

#include "llc_spi.h"

#ifndef NULL /* Move to a common place! */
#define NULL 0
#endif

/**< definitions                                                     */
#define SPI_OPEN_INSTANCES_MAX       (1)

/**< ddc return values                                               */
#define SPI_E_INV_OPER               (0xFF)
//#define SPI_WORD_LENGTH_IN_BITS    (0x08)
#define SPI_CMD_LENGTH               (0x08)
#define SPI_WRITE_1_WORD             (0x01)
#define SPI_MAX_WORD_LEN             (0x32)

/**
 *  \brief spi state value
 *
 *  enum for spi stae
 */
typedef enum
{
    SPI_SLAVE_DELETED = 1,
    SPI_SLAVE_CREATED,
    SPI_SLAVE_OPENED,
    SPI_SLAVE_CLOSED
} SPI_InstanceState;

/**
 *  \brief spi slave configuration
 *
 *  structure for spi slave config
 */
typedef struct SPI_SlaveConfig
{
    SPI_SlaveClkPolarity    slvClkPolr;
    SPI_SlaveSelPol         csPolr;
    SPI_SlaveClkPh          slvClkPhase;
    SPI_SlaveDataDly        slvDataDly;
    SPI_SlaveSel            slaveNo;
} SPI_SlaveConfig;

/**
 *  \brief spi controller state
 *
 *  struct for spi controller state and addr error
 */
typedef struct SPI_CtrlrStatus
{
    SPI_TransactionStatus   spiBusy;
    Bool                    isAddrError;
} SPI_CtrlrStatus;

/**
 *  \brief spi transfer parameter
 *
 *  struct for spi transfer parameter
 */
typedef struct SPI_TransParam
{
    SPI_Command spiCmd;
    Uint16      frameLen;
    Uint16      wordCnt;
    Uint16      wordLen;
    Bool        isFrameComplete;
    Bool        isWordComplete;
} SPI_TransParam;

/**
 *  \brief spi instance handle
 *
 *  struct for spi instance handle
 */
typedef struct SPI_Handle
{
    SPI_SlaveConfig     spiSlaveConfig;
    SPI_CtrlrStatus     spiCtrlrStatus;
    SPI_TransParam      spiTransParam;
    Uint16              noOfOpen;
    SPI_InstanceState   spiSlaveState;
} SPI_Handle;

/**
 *  \brief  DDC SPI initialization API
 *
 *  \param  Uint16 spiClkRate,
 *  \param  Uint16 frameLength,
 *  \param  Uint16 wordLength
 *
 *  \return status of init
 */
PSP_Result DDC_SPI_Init(
                    Uint16       spiClkRate,
                    Uint16       frameLength,
                    Uint16       wordLength);

/**
 *  \brief  DDC SPI Deinitialization API
 *
 *  \param  void
 *
 *  \return status of deInit
 */
PSP_Result DDC_SPI_DeInit(void);

/**
 *  \brief  DDC SPI Instance open
 *
 *  \param  SPI_HwMode mode
 *  \param  SPI_SlaveConfig slvConfig
 *
 *  \return status of spi instance open
 */
SPI_Handle* DDC_SPI_Open(
                    SPI_HwMode      mode,
                    SPI_SlaveConfig slvConfig);

/**
 *  \brief  DDC SPI instance close
 *
 *  \param  SPI_Handle *spiHandle
 *
 *  \return status of spi instance close
 */
Uint16 DDC_SPI_Close(SPI_Handle *spiHandle);

/**
 *  \brief  spi instance initialization
 *
 *  \return status of init
 */
void spiInitInstance(void);

/**
 *  \brief  spi instance initialization
 *
 *  \return status of init
 */
PSP_Result DDC_SpiDataTransaction(
                         SPI_Handle *hSPI,
                         Uint16     *transactionBuffer,
                         Uint16     count,
                         Uint16     readOrWrite);

/**
 *  \brief  spi Read Data
 *
 *  \param  Uint16 *readBuf
 *  \param  Uint16 readCnt
 *  \param  Uint16 wLen
 *
 *  \return status of spi read
 */
PSP_Result spiReadData(
                    Uint16      *readBuf,
                    Uint16      readCnt,
                    Uint16      wLen);

/**
 *  \brief  spi Write Data
 *
 *  \param  Uint16 *writeBuf
 *  \param  Uint16 writeCnt
 *  \param  Uint16 wLen
 *
 *  \return status of spi write
 */
PSP_Result spiWriteData(
                    Uint16      *writeBuf,
                    Uint16      writeCnt,
                    Uint16      wLen);

/**
 *  \brief  spi Write Data
 *
 *  \param  Uint16 *cmdBuf
 *  \param  Uint16 cmdCnt
 *  \param  Uint16 cLen
 *  \param  Uint16 rdOrWr
 *
 *  \return status of spi cmd write
 */
PSP_Result spiWriteCmd(
                    Uint16      *cmdBuf,
                    Uint16      cmdCnt,
                    Uint16      cLen,
                    Uint16      rdOrWr);

/**
 *  \brief  DDC SPI slave configurations
 *
 *  \param  SPI_SlaveSel        slNo
 *  \param  SPI_SlaveDataDly    DD
 *  \param  SPI_SlaveSelPol     csPol
 *
 *  \return status of slave configurations
 */
PSP_Result DDC_DeviceConfig(SPI_SlaveSel    slNo,
                        SPI_SlaveDataDly    DD,
                        SPI_SlaveSelPol     csPol);

//#endif /* #ifndef _DDC_SPI_H_ */



#endif /*DDC_SPI_H_*/
