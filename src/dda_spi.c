/*****************************************************************************
 * File Name : dda_spi.c
 *
 * Brief	 : header file for SPI driver adaptation
 *  This file contains implementations of SPI driver interfaces for application
 *  to utilize. 
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


#include "corazon.h"

#include "dda_spi.h"

DDA_spiConfig   spiConfig;
/**< structure to hold spi configuration details                    */
//SPI_Handle      spiHandle;
/**< spi handle                                                     */
Uint16          spiSlavesOpen;
/**< no of slaves open                                              */

extern SPI_Handle  *pSpiInst;
/**< pointer spi handle                                             */

/**
 *  \brief  enable the SPI module
 *
 *  \return None.
 */
void spiPreInit(void)
{
    Uint16 delay;

	CSL_FINS((*IDLE_PCGCRL_ADDR), IDLE_PCGCRL_SPI_IDLE, 0);

	/* Value of 'Reset Counter' */
	CSL_FINS((*PER_RSTCOUNT_ADDR), PER_RSTCOUNT, 4);
	CSL_FINS((*PER_RESET_ADDR), PER_RESET_RESETEN_LCD_IIS2_IIS3_UART_SPI, 1);

	for(delay = 0; delay < 100; delay++);

	CSL_FINS((*PERIPHSEL0_ADDR),PERIPHSEL0_SEL_PARALLELPORT, 0x5);
}

/**
 *  \brief Initialize SPI controller
 *
 *  \param  spiConfig   [IN]   spi config structure
 *  \param  spiClkRate      [IN]    Clock divisor value
 *  \param  frameLen    [IN]    Frame length
 *  \param  wordLen     [IN]    Word length
 *  \param  slaveNo     [IN]    slave number to transact
 *  \param  dataDly     [IN]    Data delay
 *  \param  csPol       [IN]    CS polarity
 *  \param  clkPh       [IN]    Clock Phase
 *  \param  clkPol      [IN]    Clock Polarity
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
              Uint16 clkPol)
{
    PSP_Result  result = PSP_SOK;

    result = DDA_spiConfiguration(spiConfig.spiCtrlMode,
                                  spiConfig.spiMaster,
                                  spiConfig.opMode,
                                  spiConfig.instances,
                                  spiConfig.syncMode);
    if (PSP_SOK != result)
    {
        return (result);
    }
   /* Initialization required for enable SPI module*/
	spiPreInit();

    pSpiInst = NULL;

    result = DDC_SPI_Init(spiClkRate, frameLen, wordLen);
    if (result != PSP_SOK)
    {
        return(result);
    }

    spiSlavesOpen = 0;

    /* chip select and slave configurations */
    result = DDA_spiSlaveSelect((SPI_SlaveSel)slaveNo,
                                (SPI_SlaveClkPh)clkPh,
                                (SPI_SlaveClkPolarity)clkPol,
                                (SPI_SlaveDataDly)dataDly,
                                (SPI_SlaveSelPol)csPol);
    if(PSP_SOK != result)
    {
        return (result);
    }

    return (result);
}

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
                              Uint16 readOrWrite)
{
    Uint16 wordLength = 0;
    PSP_Result result = PSP_E_INVAL_PARAM;
    PSP_Result transferStatus = PSP_E_INVAL_PARAM;

    if ((count > 0) && (buffer == NULL))
        return (result);

    if ((cmdCount > 0) && (cmdBuf == NULL))
        return (result);

    wordLength = LLC_SPI_WLenGet();
    if (wordLength == 8)
    {
        result = (PSP_Result) LLC_SPI_FLenSet(count+cmdCount);
        if (result != PSP_SOK)
            return (result);
    }
    else if(wordLength == 16)
    {
        result = (PSP_Result) LLC_SPI_FLenSet(count+2);
        if (result != PSP_SOK)
            return (result);
    }
    else
        return (result);

    if(cmdCount != 0)
    {
        transferStatus = (PSP_Result) spiWriteCmd(cmdBuf,cmdCount,wordLength,readOrWrite);
        if(transferStatus != PSP_SOK)
            return (transferStatus);
    }

    if(count != 0)
    {
       if(readOrWrite == SPI_READ)
       {
           transferStatus = (PSP_Result) spiReadData(buffer,count,wordLength);
       }
       else if (readOrWrite == SPI_WRITE)
       {
           transferStatus = (PSP_Result) spiWriteData(buffer,count,wordLength);
       }
       else
       {
           return (PSP_E_INVAL_PARAM);
       }
       if(transferStatus != PSP_SOK)
        return (transferStatus);
    }
    return transferStatus;
}

/**
 *  \brief  write 1 byte
 *
 *  \param  data    [IN]
 *
 *  \return status of write
 */
PSP_Result SPI_WRITE_BYTES(
                       Uint16 data)
{
    PSP_Result writeStatus;

    writeStatus = PSP_E_DRIVER_INIT;

    writeStatus = spiWriteData(&data, SPI_WRITE_1_WORD, 16);

    return writeStatus;
}

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
                        DDA_SPI_CTRLMODE        spiCtrlMode,
                        DDA_SPI_MASTER_SLAVE    spiMaster,
                        DDA_SPI_OPMODE          opMode,
                        DDA_SPI_DRV_INST        instance,
                        DDA_SPI_SYNC_ASYNC      syncMode)
{
    if( (SPI_MODE        == spiCtrlMode) &&
        (SPI_MASTER      == spiMaster)   &&
        (SPI_POLLED      == opMode)      &&
        (SPI_SINGLE_INST == instance)    &&
        (SPI_SYNC        == syncMode))
    {
        spiConfig.spiCtrlMode = spiCtrlMode;
        spiConfig.spiMaster   = spiMaster;
        spiConfig.opMode      = opMode;
        spiConfig.instances   = instance;
        spiConfig.syncMode    = syncMode;
        return (PSP_SOK);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }
}

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
                        SPI_SlaveSelPol         csPolr
                        )
{
    SPI_SlaveConfig slaveConfig;

    slaveConfig.slaveNo = slaveNo;
    slaveConfig.slvClkPhase = slvClkPhase;
    slaveConfig.slvClkPolr = slvClkPolr;
    slaveConfig.slvDataDly = slvDataDly;
    slaveConfig.csPolr = csPolr;

    /*
     * check if a slave is already open and communicating over SPI.
     * If so another slave cannot be opened, return failure
     */
    if(spiSlavesOpen > SPI_OPEN_INSTANCES_MAX)
        return (PSP_E_INVAL_PARAM);

    pSpiInst = DDC_SPI_Open(SPI_MODE_1, slaveConfig); //jb changed to 1
    if (pSpiInst != NULL)
    {
        spiSlavesOpen++;
        return (PSP_SOK);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }
}

/**
 *  \brief SPI slave deselect
 *
 *  \return spi slave deselect status
 */
PSP_Result SPI_DeInit(void)
{
    /*
     * slave deselect is only allowed if already a slave is present
     * if a slave is not already selected, return failure
     */
    if (spiSlavesOpen <= 0)
    {
        return (PSP_E_INVAL_PARAM);
    }

    DDC_SPI_Close(pSpiInst);
    if(NULL == pSpiInst)
    {
        spiSlavesOpen--;
        return (PSP_SOK);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }
}

void DDA_SPI_DeviceConfigToWrite(void)
{
    Uint16 value = 0;

    do { /* Check for bsy status */
            value=CSL_FEXT(CSL_SPI_REGS->SPISR1,SPI_SPISR1_BSY);
        }while(value & 0x01==1);


    CSL_FINS(CSL_SPI_REGS->SPICR1,SPI_SPICR1_FLEN,1);       /* set one word */
    /* Send Read Status Command */
    CSL_FINS(CSL_SPI_REGS->SPIDR2,SPI_SPIDR2_DATA,0x0500);
    CSL_FINS(CSL_SPI_REGS->SPIDR1,SPI_SPIDR1_DATA,0x0);

    /* set start CMD - Read */
    CSL_FINS(CSL_SPI_REGS->SPICR2,SPI_SPICR2_CMD,0x01);

    do { /* Check for Word Complete status */
        value=CSL_FEXT(CSL_SPI_REGS->SPISR1,SPI_SPISR1_WC);
    }while(value & 0x02==0);

    do { /* Check for bsy status */
        value=CSL_FEXT(CSL_SPI_REGS->SPISR1,SPI_SPISR1_BSY);
    }while(value & 0x01==1);

    //Read the Status --- Dummy clock cycles
    CSL_FINS(CSL_SPI_REGS->SPIDR2,SPI_SPIDR2_DATA,0x0);
    CSL_FINS(CSL_SPI_REGS->SPICR2,SPI_SPICR2_CMD,0x01);

    do { /* Check for Word Complete status */
        value=CSL_FEXT(CSL_SPI_REGS->SPISR1,SPI_SPISR1_WC);
    }while(value & 0x02==0);
    do { /* Check for bsy status */
        value=CSL_FEXT(CSL_SPI_REGS->SPISR1,SPI_SPISR1_BSY);
    }while(value & 0x01==1);

    // Enable write using WREN command
    CSL_FINS(CSL_SPI_REGS->SPICR1,SPI_SPICR1_FLEN,0x0);

    /* Write Enable command */
    CSL_FINS(CSL_SPI_REGS->SPIDR2,SPI_SPIDR2_DATA,0x0600);
    CSL_FINS(CSL_SPI_REGS->SPIDR1,SPI_SPIDR1_DATA,0x0000);

    /* set start CMD - Write */
    CSL_FINS(CSL_SPI_REGS->SPICR2,SPI_SPICR2_CMD,0x02);

    do { /* Check for Word Complete status */
        value=CSL_FEXT(CSL_SPI_REGS->SPISR1,SPI_SPISR1_WC); //jb
    }while(value & 0x02==0);

    do { /* Check for bsy status */
        value=CSL_FEXT(CSL_SPI_REGS->SPISR1,SPI_SPISR1_BSY);
    }while(value & 0x01==1);

}
/* end of file */

