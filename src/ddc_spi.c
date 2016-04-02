/*****************************************************************************
 * File Name : ddc_spi.c
 *
 * Brief	 : SPI implementation
 *  This file contains the implementation of the SPI core driver to utilize the
 *  serivces of the SPI device driver.
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


#include "ddc_spi.h"

/**<  Globals                                                       */
SPI_Handle  spiInstance;
SPI_Handle  *pSpiInst;

/**
 *  \brief  spi instance initialization
 *
 *  \return status of init
 */
void spiInitInstance(void)
{
    pSpiInst = &spiInstance;

    /* Transition parameters init */
    pSpiInst->spiTransParam.frameLen = 0;
    pSpiInst->spiTransParam.isFrameComplete = FALSE;
    pSpiInst->spiTransParam.isWordComplete = FALSE;
    pSpiInst->spiTransParam.spiCmd = (SPI_Command)0;
    pSpiInst->spiTransParam.wordCnt = 0;
    pSpiInst->spiTransParam.wordLen = 0;

    /* controller status init */
    pSpiInst->spiCtrlrStatus.isAddrError = FALSE;
    pSpiInst->spiCtrlrStatus.spiBusy = (SPI_TransactionStatus)FALSE;

    /* slave config init */
    pSpiInst->spiSlaveConfig.slvClkPhase = (SPI_SlaveClkPh)0xFF;
    pSpiInst->spiSlaveConfig.slvClkPolr = (SPI_SlaveClkPolarity)0xFF;
    pSpiInst->spiSlaveConfig.csPolr = (SPI_SlaveSelPol)0xFF;
    pSpiInst->spiSlaveConfig.slvDataDly = (SPI_SlaveDataDly)0xFF;

    /* no of SPI instance open */
    pSpiInst->noOfOpen = 0;
    pSpiInst->spiSlaveState = SPI_SLAVE_CREATED;
}

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
                  Uint16 spiClkRate,
                  Uint16 frameLength,
                  Uint16 wordLength)
{
    PSP_Result result = PSP_E_INVAL_PARAM;

    /* spi Instance init */
    spiInitInstance();

    pSpiInst->spiSlaveState = SPI_SLAVE_DELETED;

    /* set clock for the desired SPI clock rate */
    result = (PSP_Result) LLC_spiInit(spiClkRate, frameLength, wordLength);
    if (result != PSP_SOK)
    {
        return (result);
    }

    return (result);
}

/**
 *  \brief  DDC SPI Deinitialization API
 *
 *  \param  void
 *
 *  \return status of deInit
 */
PSP_Result DDC_SPI_DeInit(void)
{
    pSpiInst->spiSlaveState = SPI_SLAVE_DELETED;
    pSpiInst = NULL;
    return (PSP_SOK);
}

/**
 *  \brief  DDC SPI Instance open
 *
 *  \param  SPI_HwMode mode
 *  \param  SPI_SlaveConfig slvConfig
 *
 *  \return status of spi instance open
 */
SPI_Handle* DDC_SPI_Open(
                     SPI_HwMode         mode,
                     SPI_SlaveConfig    slvConfig)
{
    PSP_Result sts;

    sts = 0;

    if( (pSpiInst->noOfOpen > SPI_OPEN_INSTANCES_MAX) ||
        (mode >= SPI_MODE_UNKNOWN)                          ||
        (slvConfig.slvDataDly >= SPI_SLV_DATA_DLY_UNKNOWN))
    {
        return ((SPI_Handle*)NULL);
    }
    else
    {
        sts = LLC_SPI_SlaveSelect(slvConfig.slaveNo);
        if(sts == SPI_FAILURE) { return (NULL); }

        sts = LLC_SPI_DataDelay(slvConfig.slvDataDly);
        if(sts == SPI_FAILURE) { return (NULL); }

        sts = LLC_SPI_SlaveSelectPolSet(slvConfig.csPolr);
        if(PSP_SOK == sts)
        {
            pSpiInst->noOfOpen += 1;
            /* update SPI handle */
            pSpiInst->spiSlaveState = SPI_SLAVE_OPENED;
            pSpiInst->spiSlaveConfig = slvConfig;

            return (pSpiInst);
        }
        else
        {
            return ((SPI_Handle*)NULL);
        }
    }
}

/**
 *  \brief  DDC SPI instance close
 *
 *  \param  SPI_Handle *spiHandle
 *
 *  \return status of spi instance close
 */
Uint16 DDC_SPI_Close(
               SPI_Handle *spiHandle)
{
    Uint16 result = SPI_FAILURE;
    if((SPI_SLAVE_OPENED == pSpiInst->spiSlaveState))
    {
        if((pSpiInst->noOfOpen) > 0)
        {
            pSpiInst->noOfOpen -= 1;
        }
        pSpiInst->spiSlaveState = SPI_SLAVE_CLOSED;
        result = PSP_SOK;
        pSpiInst = NULL;
    }

    return (result);
}

/**
 *  \brief  spi Data transaction
 *
 *  \return status of data transfer
 */
PSP_Result DDC_SpiDataTransaction(
                         SPI_Handle *hSPI,
                         Uint16     *transactionBuffer,
                         Uint16     count,
                         Uint16     readOrWrite)
{
    PSP_Result  result = PSP_SOK;

    Uint16 getWLen;

    getWLen = 0;
    if (hSPI == NULL)
        return (PSP_E_INVAL_PARAM);

    if (transactionBuffer == NULL)
        return (PSP_E_INVAL_PARAM);

    /*
     * check if the instance is open, if not read/write
     * operation should not be performed, return error
     * check for bus busy status. return if bus busy
     */
    if(SPI_SLAVE_OPENED != hSPI->spiSlaveState)
    {
        return (PSP_E_INVAL_STATE);
    }
    getWLen = LLC_SPI_WLenGet();
    if (getWLen > SPI_MAX_WORD_LEN)
    {
        return (PSP_E_INVAL_PARAM);
    }

    /*
     * based on the operation requested, and on the wlen
     * call the appropriate read/write apis
     */
    if(SPI_READ == readOrWrite)
    {
        /* perform read operation for the count provided */
        result = spiReadData(transactionBuffer,count,getWLen);
        if (PSP_SOK != result)
            return (result);
    }
    else if(SPI_WRITE == readOrWrite)
    {
        /* perform write operation for the count provided */
        result = spiWriteData(transactionBuffer,count,getWLen);
        if (PSP_SOK != result)
            return (result);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }

    return (result);
}

/**
 *  \brief  spi Read Data
 *
 *  \param  readBuf
 *  \param  readCnt
 *  \param  wLen
 *
 *  \return status of spi read
 */
PSP_Result spiReadData(
                 Uint16 *readBuffer,
                 Uint16 readCnt,
                 Uint16 wLen)
{
    PSP_Result result = PSP_SOK;
    Uint16 bufIndex;

    if (NULL == readBuffer)
        return (PSP_E_INVAL_PARAM);

    if (0 == readCnt)
        return (PSP_E_INVAL_PARAM);


    if(SPI_WORD_LEN_16 == wLen)
    {
        for(bufIndex = 0; bufIndex < readCnt; bufIndex++)
        {
             /* set operation */
            result = LLC_SPI_CmdSet(SPI_READ);
            if (result != PSP_SOK)
                {
                return (result);
                }

            readBuffer[bufIndex] = LLC_SPI_WordRead();
        }
    }
    else if(SPI_WORD_LEN_8 == wLen)
    {
        for(bufIndex = 0; bufIndex < readCnt; bufIndex++)
        {
            result = LLC_SPI_CmdSet(SPI_READ);
            if (result != PSP_SOK)
                {
                return (result);
                }

            readBuffer[bufIndex] = LLC_SPI_ByteRead();
        }
    }
    else
    {
        result = PSP_E_INVAL_PARAM;
    }

    return (result);
}

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
                  Uint16 *writeBuf,
                  Uint16 writeCnt,
                  Uint16  wLen)
{
    PSP_Result result = PSP_SOK;
    Uint16 bufIndex;
    Uint16 sts;

    if (NULL == writeBuf)
        return (PSP_E_INVAL_PARAM);

    if (0 == writeCnt)
        return (PSP_E_INVAL_PARAM);

    /* set write operation */
    if(SPI_WORD_LEN_16 == wLen)
    {
        for(bufIndex = 0; bufIndex < writeCnt; bufIndex++)
        {
            LLC_SPI_WordWrite(writeBuf[bufIndex]);
            result = LLC_SPI_CmdSet(SPI_WRITE);

            if (result != PSP_SOK)
            {
                return (result);
            }

            do
            {
            LLC_SPI_StatusRead(&sts);
            }while(((sts & 0x02) != 0x01) && ((sts & 0x01) == 0x01));
        }
    }
    else if(SPI_WORD_LEN_8 == wLen)
    {
        for(bufIndex = 0; bufIndex < writeCnt; bufIndex++)
        {
            LLC_SPI_ByteWrite(writeBuf[bufIndex]);

            result = LLC_SPI_CmdSet(SPI_WRITE);
            if (result != PSP_SOK)
            {
                return (result);
            }

            do
            {
            LLC_SPI_StatusRead(&sts);
            }while(((sts & 0x02) != 0x01) && ((sts & 0x01) == 0x01));
        }
    }
    else
    {
        result = PSP_E_INVAL_PARAM;
    }

    return (result);
}

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
                  Uint16 *cmdBuf,
                  Uint16 cmdCnt,
                  Uint16 cLen,
                  Uint16 rdOrWr)
{
    PSP_Result result = PSP_SOK;
    Uint16 bufIndex;
    Uint16 sts;

    if (NULL == cmdBuf)
        return (PSP_E_INVAL_PARAM);

    if (0 == cmdCnt)
        return (PSP_E_INVAL_PARAM);

    /* write data into data register and set the command based on the operation */
    if(SPI_WORD_LEN_16 == cLen)
    {
        //for(bufIndex = 0; bufIndex < cmdCnt; bufIndex++)
        {
            LLC_SPI_ByteWrite(cmdBuf[0]);
            result = LLC_SPI_CmdSet((SPI_Command)rdOrWr);
            if (result != PSP_SOK)
            {
                return (result);
            }
            do
            {
            LLC_SPI_StatusRead(&sts);
            }while(((sts & 0x02) != 0x01) && ((sts & 0x01) == 0x01));

            LLC_SPI_WordWrite((cmdBuf[1] << 8) | (cmdBuf[1]  & 0xFF));
            result = LLC_SPI_CmdSet((SPI_Command)rdOrWr);
            if (result != PSP_SOK)
            {
                return (result);
            }
            do
            {
            LLC_SPI_StatusRead(&sts);
            }while(((sts & 0x02) != 0x01) && ((sts & 0x01) == 0x01));
        }
    }
    else if(SPI_WORD_LEN_8 == cLen)
    {
        for(bufIndex = 0; bufIndex < cmdCnt; bufIndex++)
        {
            LLC_SPI_ByteWrite(cmdBuf[bufIndex]);
            result = LLC_SPI_CmdSet((SPI_Command)rdOrWr);
            if (result != PSP_SOK)
            {
                return (result);
            }

            do
            {
            LLC_SPI_StatusRead(&sts);
            }while(((sts & 0x02) != 0x01) && ((sts & 0x01) == 0x01));
        }
    }
    else
    {
        result = PSP_E_INVAL_PARAM;
    }
    return (result);
}

/**
 *  \brief  DDC SPI slave configurations
 *
 *  \param  SPI_SlaveSel        slNo
 *  \param  SPI_SlaveDataDly    DD
 *  \param  SPI_SlaveSelPol     csPol
 *
 *  \return status of slave configurations
 */
PSP_Result DDC_DeviceConfig(SPI_SlaveSel slNo, SPI_SlaveDataDly DD, SPI_SlaveSelPol csPol)
{
    PSP_Result  result = PSP_SOK;

    result = LLC_SPI_SlaveSelect(slNo);
    if (PSP_SOK != result)
        return (result);

    result = LLC_SPI_DataDelay(DD);
    if (PSP_SOK != result)
        return (result);

    result = LLC_SPI_SlaveSelectPolSet(csPol);
    if (PSP_SOK != result)
        return (result);

    result = LLC_SPI_ModeSelect(SPI_MODE_1); //jb changed to 1
    if (PSP_SOK != result)
        return (result);

    return (result);
}

/* end of file */

