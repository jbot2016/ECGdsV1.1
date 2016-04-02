#ifndef LLC_SPI_H_
#define LLC_SPI_H_

/*****************************************************************************
 * File Name : llc_spi.h 
 *
 * Brief	 : header file for SPI LLC implementation
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

//#ifndef _LLC_SPI_H_
//#define _LLC_SPI_H_

#include "tistdtypes.h"
#include "psp_common.h"
#include "cslr_spi_001.h"

#define SPI_STATUS_BUSY_MASK        (0x00000001)
/**< spi status register busy bit mask                                      */
#define SPI_STATUS_BUSY_SHIFT       (0x0000)
/**< spi status register busy  bit shift                                    */
#define SPI_STATUS_WC_MASK          (0x00000002)                            
/**< spi status register word complete bit mask                             */
#define SPI_STATUS_WC_SHIFT         (0x0001)                                
/**< spi status register word complete bit shift                            */
#define SPI_STATUS_FC_MASK          (0x00000004)                            
/**< spi status register frame complete bit mask                            */
#define SPI_STATUS_FC_SHIFT         (0x0002)                                
/**< spi status register frame complete bit shift                           */
#define SPI_STATUS_AE_MASK          (0x00000008)                            
/**< spi status register address error bit mask                             */
#define SPI_STATUS_AE_SHIFT         (0x0003)                                
/**< spi status register address error bit shift                            */
#define SPI_STATUS_WDCNT_MASK       (0x1FFF0000)                            
/**< spi status register word count bit mask                                */
#define SPI_STATUS_WDCNT_SHIFT      (0x0010)                                
/**< spi status register word count bit shift                               */
#define SPI_MAX_WDCNT               (4095)                                  
/**< word count                                                             */
#define SPI_MAX_FLEN                (4096)                                  
/**< max frame lenght                                                       */
#define SPI_FAILURE                 (0xFFFF)                                
/**< Return values - Errors                                                 */

#define SPI_STATUS_BUSY             (0x0001)
#define SPI_WORD_COMPLETE           (0x0002)

#define SPI_WORD_LEN_8              (8)
#define SPI_WORD_LEN_16             (16)
#define SPI_WORD_LEN_24             (24)
#define SPI_WORD_LEN_32             (32)

#define SPI_LOOP_BACK_ENABLE        (1)
#define SPI_LOOP_BACK_DISABLE       (2)

#define SPI_CLK_ENABLE              (1)
#define SPI_CLK_DISABLE             (0)

// Prescale value to change 100MHz to 7MHz for ADCCLK
#define SPI_PRESCALE 				(13) //7MHz(19) 5MHz//(216) 460KHz

/**
 *  \brief spi slave data delay value
 *
 *  enum for spi slave data delay
 */
typedef enum SPI_SlaveDataDly
{
    SPI_SLV_DATA_DLY_0 = 0,
    SPI_SLV_DATA_DLY_1,
    SPI_SLV_DATA_DLY_2,
    SPI_SLV_DATA_DLY_3,
    SPI_SLV_DATA_DLY_UNKNOWN
} SPI_SlaveDataDly;

/**
 *  \brief spi slave clock polarity vlaue
 *
 *  enum for spi instance handle
 */
typedef enum SPI_SlaveClkPolarity
{
    SPI_LOW_AT_IDLE = 0,
    SPI_HIGH_AT_IDLE,
    SPI_UNKNOWN_AT_IDLE
}SPI_SlaveClkPolarity;

/**
 *  \brief spi slave clock phase value
 *
 *  enum for spi slave clock phase
 */
typedef enum SPI_SlaveClkPh
{
    SPI_SLV_PH_FALL_EDGE = 0,
    SPI_SLV_PH_RISE_EDGE,
    SPI_SLV_PH_UNKNOWN
} SPI_SlaveClkPh;

/**
 *  \brief spi slave select polarity value
 *
 *  enum for spi slave select polarity
 */
typedef enum SPI_SlaveSelPol
{
    SPI_SLV_ACTIVE_LOW = 0,
    SPI_SLV_ACTIVE_HIGH,
    SPI_CLK_POL_UNKNOWN
} SPI_SlaveSelPol;

/**
 *  \brief spi slave select value
 *
 *  enum for spi slave select
 */
typedef enum SPI_SlaveSel
{
    SPI_EEPROM = 0,
    SPI_LCD,
    SPI_SLAVE_RSVD,
    SPI_SLAVE_RSVD1,
    SPI_SLAVE_UNKNOWN
} SPI_SlaveSel;

/**
 *  \brief spi command value
 *
 *  enum for spi command
 */
typedef enum SPI_Command
{
    SPI_RSVD_CMD = 0,
    SPI_READ,
    SPI_WRITE,
    SPI_RSVD1_CMD,
    SPI_UNKNOWN_CMD
} SPI_Command;

/**
 *  \brief spi slave mode value
 *
 *  enum for spi slave mode
 */
typedef enum SPI_HwMode
{
    SPI_MODE_0 = 0,
    SPI_MODE_1,
    SPI_MODE_2,
    SPI_MODE_3,
    SPI_MODE_UNKNOWN
} SPI_HwMode;

/**
 *  \brief spi controller transaction status
 *
 *  enum for spi controller transation status
 */
typedef enum SPI_TransactionStatus
{
    SPI_BUSY = 0,
    SPI_IDLE,
    SPI_STATUS_UNKNOWN
} SPI_TransactionStatus;

/**
 *  \brief  LLC SPI initialization API
 *
 *  \param  clkDivisor      [IN]    clock divisor
 *  \param  frameLength     [IN]    Frame length
 *  \param  wordLength      [IN]    Word length
 *
 *  \return status of init
 */
PSP_Result LLC_spiInit(
                Uint16 clkDiv,
                Uint16 frameLen,
                Uint16 wordLen);

/**
 *  \brief  enable spi clock
 *
 *  \return status of spi enable
 */
void LLC_SPI_Enable(void);

/**
 *  \brief  disable spi clock
 *
 *  \return status of spi disable
 */
void LLC_SPI_Disable(void);

/**
 *  \brief  set clock divisor
 *
 *  \return status of set clock
 */
void LLC_SPI_ClockSet(Uint16 spiClkRate);

/**
 *  \brief  select a slave
 *
 *  \param SPI_SlaveSel spiSlaveSelect
 *
 *  \return status of slave select
 */
PSP_Result LLC_SPI_SlaveSelect(SPI_SlaveSel spiSlaveSelect);

/**
 *  \brief  select a slave
 *
 *  \return slave number
 */
SPI_SlaveSel LLC_SPI_SlaveGet(void);

/**
 *  \brief  select spi mode
 *
 *  \param SPI_HwMode spiModeSelect
 *
 *  \return status of mode select
 */
PSP_Result LLC_SPI_ModeSelect(SPI_HwMode spiModeSelect);

/**
 *  \brief  slave data delay select
 *
 *  \param SPI_SlaveDataDly spiDataDelay
 *
 *  \return status of slave data delay set
 */
PSP_Result LLC_SPI_DataDelay(SPI_SlaveDataDly spiDataDelay);

/**
 *  \brief  select a slave
 *
 *  \param Bool loopBackEnable
 *
 *  \return status loopbackmode select
 */
PSP_Result LLC_SPI_LoopBackMode(Bool loopBackMode);

/**
 *  \brief  get loopback mode
 *
 *  \return loopback mode
 */
Bool LLC_SPI_LoopBackGet(void);

/**
 *  \brief  select slave polarity
 *
 *  \param SPI_SlaveSelPol slaveSelPol
 *
 *  \return status of slave polarity set
 */
PSP_Result LLC_SPI_SlaveSelectPolSet(SPI_SlaveSelPol slaveSelPol);

/**
 *  \brief  wordlength set
 *
 *  \param Uint16 wordLen
 *
 *  \return status of word length set
 */
PSP_Result LLC_SPI_WLenSet(Uint16 wordLen);

/**
 *  \brief  send SPI command
 *
 *  \param SPI_Command spiCmd
 *
 *  \return status of command set
 */
PSP_Result LLC_SPI_CmdSet(SPI_Command spiCmd);

/**
 *  \brief  framelength set
 *
 *  \param Uint16 frameLen
 *
 *  \return status of frame length set
 */
PSP_Result LLC_SPI_FLenSet(Uint16 frameLen);

/**
 *  \brief  read status register
 *
 *  \param Uint16 *spiStatus
 *
 */
void LLC_SPI_StatusRead(Uint16 *spiStatus);

/**
 *  \brief  read byte
 *
 *  \return Uint16 byteRead
 */
Uint16 LLC_SPI_ByteRead(void);

/**
 *  \brief  read word
 *
 *  \return Uint16 wordRead
 *
 */
Uint16 LLC_SPI_WordRead(void);

/**
 *  \brief  read double word
 *
 *  \return Uint32 dWordRead
 *
 */
Uint32 LLC_SPI_DoubleWordRead(void);

/**
 *  \brief  write byte
 *
 *  \param Uint16 byteWrite
 *
 */
void LLC_SPI_ByteWrite(Uint16 byteWrite);

/**
 *  \brief  write word
 *
 *  \param Uint16 wordWrite
 *
 */
void LLC_SPI_WordWrite(Uint16 wordWrite);

/**
 *  \brief  write double word
 *
 *  \param Uint32 dWordWrite
 *
 */
void LLC_SPI_DoubleWordWrite(Uint32 dWordWrite);

/**
 *  \brief  enable word interrupt
 *
 */
void LLC_SPI_WordInterruptEnable(void);

/**
 *  \brief  enable frame interrupt
 *
 */
void LLC_SPI_FrameInterruptEnable(void);

/**
 *  \brief  get word interrupt state
 *
 */
void LLC_SPI_WordIntrRx_Get(void);

/**
 *  \brief  get frame interrupt state
 *
 */
void LLC_SPI_FrameIntrRx_Get(void);

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
          Uint32 Divisor  );

//#endif /* #ifndef  _LLC_SPI_H_ */

/* end of file */


#endif /*LLC_SPI_H_*/
