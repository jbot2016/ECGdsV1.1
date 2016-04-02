#ifndef DDA_SPI_H_
#define DDA_SPI_H_

/*****************************************************************************
 * File Name : dda_spi.h 
 *
 * Brief	 : header file for SPI driver adaptation
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

//#ifndef _DDA_SPI_H_
//#define _DDA_SPI_H_

#include "ddc_spi.h"

/**
 *  \brief spi controller mode value
 *
 *  enum for spi controller mode
 */
typedef enum
{
    SPI_MODE = 0,
    SPI_MIBSPI_MODE,
    SPI_UNKNOWN_MODE
} DDA_SPI_CTRLMODE;

/**
 *  \brief spi controller master/slave mode value
 *
 *  enum for spi controller master/slave mode
 */
typedef enum
{
    SPI_MASTER = 0,
    SPI_SLAVE,
    SPI_UNKNOWN
} DDA_SPI_MASTER_SLAVE;

/**
 *  \brief spi driver mode value
 *
 *  enum for spi driver mode
 */
typedef enum
{
    SPI_POLLED = 0,
    SPI_INTERRUPT,
    SPI_DMA_INTERRUPT,
    SPI_UNKNOWN_OPMODE
} DDA_SPI_OPMODE;

/**
 *  \brief spi instance value
 *
 *  enum for spi instance
 */
typedef enum
{
    SPI_SINGLE_INST = 0,
    SPI_MULTI_INST,
    SPI_UNKNOWN_INST
} DDA_SPI_DRV_INST;

/**
 *  \brief spi mode of transfer value
 *
 *  enum for spi mode of transfer
 */
typedef enum
{
    SPI_SYNC = 0,
    SPI_ASYNC,
    SPI_UNKNOWN_TX_MODE
} DDA_SPI_SYNC_ASYNC;

/**
 *  \brief spi driver configuration
 *
 *  structure for spi driver configuration
 */
typedef struct
{
    DDA_SPI_CTRLMODE        spiCtrlMode; /**< spi controllor mode */
    DDA_SPI_MASTER_SLAVE    spiMaster; /**< spi master/slave */
    DDA_SPI_OPMODE          opMode;/**< spi operation mode */
    DDA_SPI_DRV_INST        instances;/**< spi driver instances */
    DDA_SPI_SYNC_ASYNC      syncMode;/**< spi sync/async mode */
} DDA_spiConfig;

/**
 *  \brief  enable the SPI module
 *
 *  \return None.
 */
void spiPreInit(void);

/**
 *  \brief Initialize SPI controller
 *
 *  \param  spiConfig   [IN]   spi config structure
 *  \param  spiClkRate  [IN]
 *  \param  frameLen    [IN]
 *  \param  wordLen [IN]
 *  \param  slaveNo [IN]
 *  \param  dataDly [IN]
 *  \param  csPol   [IN]
 *  \param  clkPh   [IN]
 *  \param  clkPol  [IN]
 *
 *  \return status of init
 */
PSP_Result SPI_INIT(
              DDA_spiConfig spiConfig,
              Uint16 spiClkRate,
              Uint16 frameLen,
              Uint16 wordLen,
              Uint16 slaveNo,
              Uint16 dataDly,
              Uint16 csPol,
              Uint16 clkPh,
              Uint16 clkPol);
/**
 *  \brief  Read/Write N Bytes from/to SPI slave
 *
 *  \param  buffer  [IN]
 *  \param  count   [IN]
 *  \param  cmdBuf  [IN]
 *  \param  cmdCount    [IN]
 *  \param  readOrWrite [IN]
 *
 *  \return status of read/write
 */
PSP_Result SPI_READ_WRITE_N_BYTES(
                              Uint16 *buffer,
                              Uint16 count,
                              Uint16 *cmdBuf,
                              Uint16 cmdCount,
                              Uint16 readOrWrite);

/**
 *                   SPI_WRITE_BYTES
 *  \brief  write 1 byte
 *
 *  \param  data
 *
 *  \return status of write
 */
PSP_Result SPI_WRITE_BYTES(Uint16 data);

/**
 *  \brief  spi driver configurations
 *
 *  \param spiCtrlMode  [IN]
 *  \param spiMaster    [IN]
 *  \param opMode   [IN]
 *  \param instance [IN]
 *  \param syncMode [IN]
 *
 *  \return spi driver configurations result
 */
PSP_Result DDA_spiConfiguration(
                           DDA_SPI_CTRLMODE         spiCtrlMode,
                           DDA_SPI_MASTER_SLAVE     spiMaster,
                           DDA_SPI_OPMODE           opMode,
                           DDA_SPI_DRV_INST         instance,
                           DDA_SPI_SYNC_ASYNC       syncMode);

/**
 *  \brief SPI slave configurations
 *
 *  \param slaveNo  [IN]
 *  \param slvClkPhase  [IN]
 *  \param slvClkPolr   [IN]
 *  \param slvDataDly   [IN]
 *  \param csPolr   [IN]
 *
 *  \return spi slave configurations result
 */
PSP_Result DDA_spiSlaveSelect(
                        SPI_SlaveSel            slaveNo,
                        SPI_SlaveClkPh          slvClkPhase,
                        SPI_SlaveClkPolarity    slvClkPolr,
                        SPI_SlaveDataDly        slvDataDly,
                        SPI_SlaveSelPol         csPolr);
/**
 *  \brief SPI slave deselect
 *
 *  \return spi slave deselect status
 */
PSP_Result SPI_DeInit(void);

/**
 *  \brief Write enable for EEPROM
 *
 *  \return void
 */
void DDA_SPI_DeviceConfigToWrite(void);

//#endif /* _DDA_SPI_H_ */



#endif /*DDA_SPI_H_*/
