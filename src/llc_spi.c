/*****************************************************************************
 * File Name : llc_spi.c
 *
 * Brief	 : This file contains the low level controller implementation for SPI
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


#include "llc_spi.h"
#include "corazon.h"

/**< Globals                                                        */
//ioport CSL_SpiRegs *spiReg;

/**
 *  \brief  LLC SPI initialization API
 *
 *  \param  Uint16 spiClkRate,
 *  \param  Uint16 frameLength,
 *  \param  Uint16 wordLength
 *
 *  \return status of init
 */
PSP_Result LLC_spiInit(
                 Uint16 spiClkRate,
                 Uint16 frameLen,
                 Uint16 wordLen)
{
    PSP_Result result = PSP_SOK;

//    spiReg = (CSL_SpiRegs *)(CSL_SPI_REGS);

    LLC_SPI_Disable();

    LLC_SPI_ClockSet(spiClkRate);

    result = LLC_SPI_WLenSet(wordLen);
    if (result != PSP_SOK)
        return (result);

    result = LLC_SPI_FLenSet(frameLen);
    if (result != PSP_SOK)
        return (result);

    LLC_SPI_WordInterruptEnable();

    LLC_SPI_Enable();

    return (result);
}

/**
 *  \brief  enable spi clock
 *
 *  \return status of spi enable
 */
void LLC_SPI_Enable(void)
{
    CSL_SPI_REGS->SPICC2 = (Uint16)(SPI_CLK_ENABLE << CSL_SPI_SPICC2_CLKEN_SHIFT);
}

/**
 *  \brief  disable spi clock
 *
 *  \return status of spi disable
 */
void LLC_SPI_Disable(void)
{
    CSL_SPI_REGS->SPICC2 = (Uint16)(SPI_CLK_DISABLE << CSL_SPI_SPICC2_CLKEN_SHIFT);
}

/**
 *  \brief  set clock divisor
 *
 *  \return status of set clock
 */
void LLC_SPI_ClockSet(Uint16 spiClkRate)
{
	Uint16 sysClkDiv;
	extern Uint32 sysClk;
//	Uint32 sysClk = 100000;

    if(sysClk <= 10000)
	{
        sysClkDiv = SPI_PRESCALE;	//99
	}
	else
	{
		sysClkDiv = spiDivFun(sysClk, spiClkRate);
		/* clock diviser increased by 2 as sysClk is not taking same value as
		 system clock speed */
	    sysClkDiv = sysClkDiv + 2 ;
	}
    CSL_SPI_REGS->SPICC1 = sysClkDiv;
}

/**
 *  \brief  select a slave
 *
 *  \param SPI_SlaveSel spiSlaveSelect
 *
 *  \return status of slave select
 */
PSP_Result LLC_SPI_SlaveSelect(SPI_SlaveSel spiSlaveSelect)
{
    if( spiSlaveSelect < SPI_SLAVE_UNKNOWN )
    {
        (CSL_SPI_REGS->SPICR2) |= ((Uint16)(spiSlaveSelect << CSL_SPI_SPICR2_CSNUM_SHIFT));
        return (PSP_SOK);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }
}

/**
 *  \brief  get current slave selected
 *
 *  \return slave number
 */
SPI_SlaveSel LLC_SPI_SlaveGet(void)
{
    SPI_SlaveSel spiSlave;
    spiSlave = (SPI_SlaveSel)((CSL_SPI_REGS->SPICR2 & CSL_SPI_SPICR2_CSNUM_MASK)
                                      >> CSL_SPI_SPICR2_CSNUM_SHIFT);
    return (spiSlave);
}

/**
 *  \brief  select spi mode
 *
 *  \param SPI_HwMode spiModeSelect
 *
 *  \return status of mode select
 */
PSP_Result LLC_SPI_ModeSelect(SPI_HwMode spiModeSelect)
{
    SPI_SlaveSel spiSlave;
    PSP_Result result;

    result = PSP_SOK;
    spiSlave = LLC_SPI_SlaveGet();

    if(spiSlave >= SPI_SLAVE_UNKNOWN)
        return (PSP_E_INVAL_PARAM);

    switch(spiSlave)
    {
        case SPI_EEPROM:
            /* CLKP0 */
            CSL_SPI_REGS->SPIDC1 = ((CSL_SPI_REGS->SPIDC1 & (Uint16)(~CSL_SPI_SPIDC1_CKP0_MASK)) |
                                    (Uint16)((spiModeSelect >> 0x01) << CSL_SPI_SPIDC1_CKP0_SHIFT));

            /* CLKPH0 */
            CSL_SPI_REGS->SPIDC1 = ((CSL_SPI_REGS->SPIDC1 & (Uint16)(~CSL_SPI_SPIDC1_CKPH0_MASK))|
                                    (Uint16)((spiModeSelect & 0x01) << CSL_SPI_SPIDC1_CKPH0_SHIFT));
            result = PSP_SOK;
            break;

        case SPI_LCD:
            /* CLKP1 */
            CSL_SPI_REGS->SPIDC1 = ((CSL_SPI_REGS->SPIDC1 & (Uint16)(~CSL_SPI_SPIDC1_CKP1_MASK)) |
                                    (Uint16)((spiModeSelect >> 0x01) << CSL_SPI_SPIDC1_CKP1_SHIFT));

            /* CLKPH1 */
            CSL_SPI_REGS->SPIDC1 = ((CSL_SPI_REGS->SPIDC1 & (Uint16)(~CSL_SPI_SPIDC1_CKPH1_MASK))|
                                    (Uint16)((spiModeSelect & 0x01) << CSL_SPI_SPIDC1_CKPH1_SHIFT));
            result = PSP_SOK;
            break;

        default:
            result = PSP_E_INVAL_PARAM;
            break;
    }
    return (result);
}

/**
 *  \brief  slave data delay select
 *
 *  \param SPI_SlaveDataDly spiDataDelay
 *
 *  \return status of slave data delay set
 */
PSP_Result LLC_SPI_DataDelay(SPI_SlaveDataDly spiDataDelay)
{
    SPI_SlaveSel spiSlave;
    PSP_Result result;

    result = PSP_SOK;

    spiSlave = LLC_SPI_SlaveGet();
    switch(spiSlave)
    {
        case SPI_EEPROM:
            /* CSP0 */
            CSL_SPI_REGS->SPIDC1 = ((CSL_SPI_REGS->SPIDC1 & (Uint16)(~CSL_SPI_SPIDC1_DD0_MASK)) |
                                    (Uint16)(spiDataDelay << CSL_SPI_SPIDC1_DD0_SHIFT));
            result = PSP_SOK;
            break;

        case SPI_LCD:
            /* CSP0 */
            CSL_SPI_REGS->SPIDC1 = ((CSL_SPI_REGS->SPIDC1 & (Uint16)(~CSL_SPI_SPIDC1_DD1_MASK)) |
                                    (Uint16)(spiDataDelay << CSL_SPI_SPIDC1_DD1_SHIFT));
            result = PSP_SOK;
            break;

        default:
            result = PSP_E_INVAL_PARAM;
            break;
    }
    return (result);
}

/**
 *  \brief  select a slave
 *
 *  \param Bool loopBackEnable
 *
 *  \return status loopbackmode select
 */
PSP_Result LLC_SPI_LoopBackMode(Bool loopBackMode)
{
    if((SPI_LOOP_BACK_ENABLE == loopBackMode) ||
       (SPI_LOOP_BACK_DISABLE == loopBackMode))
    {
        CSL_SPI_REGS->SPIDC2 |= (Uint16)(loopBackMode << CSL_SPI_SPIDC2_LPBK_SHIFT);
        return (PSP_SOK);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }
}

/**
 *  \brief  get loopback mode
 *
 *  \return loopback mode
 */
Bool LLC_SPI_LoopBackGet(void)
{
    Uint16 loopBackStatus;
    loopBackStatus = (Uint16)((CSL_SPI_REGS->SPIDC2 & CSL_SPI_SPIDC2_LPBK_MASK)
                                          >> CSL_SPI_SPIDC2_LPBK_SHIFT);
    return (loopBackStatus);
}

/**
 *  \brief  select slave polarity
 *
 *  \param SPI_SlaveSelPol slaveSelPol
 *
 *  \return status of slave polarity set
 */
PSP_Result LLC_SPI_SlaveSelectPolSet(SPI_SlaveSelPol slaveSelPol)
{
    SPI_SlaveSel spiSlave;
    PSP_Result result;

    result = PSP_SOK;

    spiSlave = LLC_SPI_SlaveGet();
    if(spiSlave >= SPI_SLAVE_UNKNOWN)
        return (PSP_E_INVAL_PARAM);

    switch(spiSlave)
    {
        case SPI_EEPROM:
            /* CSP0 */
            CSL_SPI_REGS->SPIDC1 |= (Uint16)(slaveSelPol << CSL_SPI_SPIDC1_CSP0_SHIFT);
            result = PSP_SOK;
            break;

        case SPI_LCD:
            /* CSP1 */
            CSL_SPI_REGS->SPIDC1 |= (Uint16)(slaveSelPol << CSL_SPI_SPIDC1_CSP1_SHIFT);
            //LLC_SPI_WordInterruptEnable();
            result = PSP_SOK;
            break;

        default:
            result = PSP_E_INVAL_PARAM;
            break;
    }
    return (result);
}

/**
 *  \brief  wordlength set
 *
 *  \param Uint16 wordLen
 *
 *  \return status of word length set
 */
PSP_Result LLC_SPI_WLenSet(Uint16 wordLen)
{
    if((SPI_WORD_LEN_8 == wordLen ) ||
       (SPI_WORD_LEN_16 == wordLen))
    {
        CSL_SPI_REGS->SPICR2 |= (Uint16)((wordLen - 1) << CSL_SPI_SPICR2_WLEN_SHIFT);
        return (PSP_SOK);
    }
    else
    {
        /* word length of 8 bits and 16 bits are only supported */
        return (PSP_E_INVAL_PARAM);
    }
}

/**
 *  \brief  get wordlength
 *
 *  \return word length
 */
Uint16 LLC_SPI_WLenGet(void)
{
    Uint16   wordLen;

    wordLen = (((CSL_SPI_REGS->SPICR2 & CSL_SPI_SPICR2_WLEN_MASK)
                >> CSL_SPI_SPICR2_WLEN_SHIFT) + 1);
    return (wordLen);
}

/**
 *  \brief  send SPI command
 *
 *  \param SPI_Command spiCmd
 *
 *  \return status of command set
 */
PSP_Result LLC_SPI_CmdSet(SPI_Command spiCmd)
{
    if((SPI_READ == spiCmd) ||
       (SPI_WRITE == spiCmd))
    {
        CSL_SPI_REGS->SPICR2 = (((CSL_SPI_REGS->SPICR2) & (Uint16)(~CSL_SPI_SPICR2_CMD_MASK))
                    | ((Uint16)(spiCmd << CSL_SPI_SPICR2_CMD_SHIFT)));
        return (PSP_SOK);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }
}

/**
 *  \brief  set frame length
 *
 *  \param Uint16 frameLen
 *
 *  \return status of frame length set
 */
PSP_Result LLC_SPI_FLenSet(Uint16 frameLen)
{
    if(frameLen <= SPI_MAX_FLEN)
    {
        CSL_SPI_REGS->SPICR1 = (Uint16)((CSL_SPI_REGS->SPICR1) & ((Uint16)~CSL_SPI_SPICR1_FLEN_MASK) )|(frameLen - 1);
        return (PSP_SOK);
    }
    else
    {
        return (PSP_E_INVAL_PARAM);
    }
}

/**
 *  \brief get frame length
 *
 *  \return frame length
 */
Uint16   LLC_SPI_FLenGet(void)
{
    Uint16   frameLen;

    frameLen = (((CSL_SPI_REGS->SPICR1 & CSL_SPI_SPICR1_FLEN_MASK)
                >> CSL_SPI_SPICR1_FLEN_SHIFT) + 1);

    return (frameLen);
}

/**
 *  \brief  read status register
 *
 *  \param Uint16 *spiStatus
 *
 */
void LLC_SPI_StatusRead(Uint16 *spiStatus)
{
    *spiStatus = (CSL_SPI_REGS->SPISR1);
    *spiStatus = *spiStatus;
}

/**
 *  \brief  read byte
 *
 *  \return Uint16 byteRead
 */
Uint16 LLC_SPI_ByteRead(void)
{
    Uint16 spiStatusReg;
    Uint16 wordComplete;
    Uint16 spiBusStatus;
    Uint16 byteRead;

    spiStatusReg = 0;
    wordComplete = 0;
    spiBusStatus = 0;
    byteRead = 0;

    do {
        LLC_SPI_StatusRead(&spiStatusReg);
        spiBusStatus = (spiStatusReg & SPI_STATUS_BUSY_MASK);
        wordComplete = (spiStatusReg & SPI_STATUS_WC_MASK );
    } while((SPI_STATUS_BUSY == spiBusStatus) && (wordComplete != SPI_WORD_COMPLETE));

    byteRead = (CSL_SPI_REGS->SPIDR1 & 0xFF);

    return (byteRead);
}

/**
 *  \brief  read word
 *
 *  \return Uint16 wordRead
 *
 */
Uint16 LLC_SPI_WordRead(void)
{
    Uint16 wordRead;
    Uint16 spiStatusReg;
    Uint16 wordComplete;
    Uint16 spiBusStatus;

    spiStatusReg = 0;
    wordComplete = 0;
    spiBusStatus = 0;
    wordRead = 0;

    do {
        LLC_SPI_StatusRead(&spiStatusReg);
        spiBusStatus = (spiStatusReg & SPI_STATUS_BUSY_MASK);
        wordComplete = (spiStatusReg & SPI_STATUS_WC_MASK );
    } while((SPI_STATUS_BUSY == spiBusStatus) && (wordComplete != SPI_WORD_COMPLETE));

    wordRead = CSL_SPI_REGS->SPIDR1;

    return (wordRead);
}

/**
 *  \brief  read double word
 *
 *  \return Uint32 dWordRead
 *
 */
Uint32 LLC_SPI_DoubleWordRead(void)
{
    Uint16 dwordMSW;
    Uint16 dwordLSW;
    Uint32 dWordRead;

    dwordLSW = (CSL_SPI_REGS->SPIDR2 & 0xFFFF);
    dwordMSW = (CSL_SPI_REGS->SPIDR1 << 0x08);

    dWordRead = (dwordLSW ||dwordMSW);
    return (dWordRead);
}

/**
 *  \brief  write byte
 *
 *  \param Uint16 byteWrite
 *
 */
void LLC_SPI_ByteWrite(Uint16 byteWrite)
{
    CSL_SPI_REGS->SPIDR2 = (Uint16)(byteWrite <<0x08);
    CSL_SPI_REGS->SPIDR1 = 0x0000;
}

/**
 *  \brief  write word
 *
 *  \param Uint16 wordWrite
 *
 */
void LLC_SPI_WordWrite(Uint16 wordWrite)
{
     CSL_SPI_REGS->SPIDR2 = wordWrite;
     CSL_SPI_REGS->SPIDR1 = 0x0000;
}

/**
 *  \brief  write double word
 *
 *  \param Uint32 dWordWrite
 *
 */
void LLC_SPI_DoubleWordWrite(Uint32 dWordWrite)
{
     CSL_SPI_REGS->SPIDR2 = (Uint16)(dWordWrite & 0xFFFF);
     CSL_SPI_REGS->SPIDR1 = (Uint16)((dWordWrite >> 0x08) & 0xFFFF);
}

/**
 *  \brief  enable word interrupt
 *
 */
void LLC_SPI_WordInterruptEnable(void)
{
    CSL_SPI_REGS->SPICR1 = ((CSL_SPI_REGS->SPICR1 & CSL_SPI_SPICR1_WIRQ_MASK) |
                            (1 << CSL_SPI_SPICR1_WIRQ_SHIFT));
}

/**
 *  \brief  enable frame interrupt
 *
 */
void LLC_SPI_FrameInterruptEnable(void)
{
    /* dummy functions */
}

/**
 *  \brief  get word interrupt state
 *
 */
void LLC_SPI_WordIntrRx_Get(void)
{
    /* dummy functions */
}

/**
 *  \brief  get frame interrupt state
 *
 */
void LLC_SPI_FrameIntrRx_Get(void)
{
    /* dummy functions */
}

/**
  * \brief 
  *         division of two integer number.
  *         
  * \param     Dividend     [IN]
  * \param     Divisor     [IN]
  *
  * \return    Uint16
  */
Uint16 spiDivFun(
          Uint32 Dividend,
          Uint32 Divisor  )
{
    Uint16 Quoitient;

    Quoitient = 0;

    while (Dividend >= Divisor)
    {
        Quoitient++;
        Dividend = Dividend - Divisor;
    }

    return Quoitient;
}

/* end of file */

