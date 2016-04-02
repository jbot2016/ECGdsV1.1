#ifndef CORAZON_H_
#define CORAZON_H_

/*****************************************************************************
 * File Name : Corazon.h 
 *
 * Brief	 : This file contains the Chip Description for CORAZON
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

//#ifndef _CORAZON_H
//#define _CORAZON_H


#include "cslr_001.h" //had to make 001 to match ecg ref project jb
#include "tistdtypes.h"
#include "csl_ioport.h"

/*****************************************************************************\
* Include files for all the modules in the device
\*****************************************************************************/

#include "cslr_i2c.h"
#include "cslr_i2s.h"
#include "cslr_emif.h"
#include "cslr_uart.h" //was 001, changed to work with CSL uart example
#include "cslr_spi_001.h"
#include "cslr_mmcsd.h"
#include "cslr_lcdc.h"
#include "cslr_rtc.h"
#include "cslr_dma_001.h"
#include "cslr_dmaevtint_001.h" 
#include "cslr_sar.h"
#include "cslr_usb.h"
#include "cslr_pll_001.h" 


#define PLL_CNFIG(VP,VS) \
	CSL_FINS(CSL_PLL_REGS->PLLCNTL2,CSL_PLL_PLLCNTL2_PLL_DIS,1);\
	CSL_FINS(CSL_PLL_REGS->PLLCNTL1,CSL_PLL_PLLCNTL1_VP,VP);\
	CSL_FINS(CSL_PLL_REGS->PLLINCNTL,CSL_PLL_PLLINCNTL_VS,VS);\
	CSL_FINS(CSL_PLL_REGS->PLLOUTCNTL,CSL_PLL_PLLOUTCNTL_OUT_DIV_EN,0);\
	CSL_FINS(CSL_PLL_REGS->PLLINCNTL,CSL_PLL_PLLINCNTL_RP_BYPASS,0);\
	CSL_FINS(CSL_PLL_REGS->PLLINCNTL,CSL_PLL_PLLINCNTL_RD,120);\
	CSL_FINS(CSL_PLL_REGS->PLLCNTL1,CSL_PLL_PLLCNTL1_PLL_STANDBY,0);\
	CSL_FINS(CSL_PLL_REGS->PLLCNTL2,CSL_PLL_PLLCNTL2_PLL_DIS,0);\
	asm("\trpt #1000");\
	asm("\tnop");

/*
RP_bypass is 0 since Input clock is 12MHz and has to be scaled down betweek 30kHz-170kHz for PD input
*/

/*****************************************************************************\
* Peripheral Instance counts
\*****************************************************************************/
#define CSL_SAR_PER_CNT		1
#define CSL_USB_PER_CNT		1
#define CSL_I2C_PER_CNT		1                                              
#define CSL_UART_PER_CNT	1                                       
#define CSL_SPI_PER_CNT		1                                       
#define CSL_MMCSD_PER_CNT	2                                       
#define CSL_LCDC_PER_CNT		1    
#define CSL_RTC_PER_CNT		1      
#define CSL_DMA_PER_CNT		4                                

#define CORAZON_SILICON		                                   	
#define SDRAMTIMING0	0x5810
#define SDRAMTIMING1	0x4221
//#define	PLL_60MHz
//#define	PLL_100MHz

/*****************************************************************************\
* Peripheral Overlay Structures
\*****************************************************************************/
typedef volatile ioport CSL_UsbRegs          * CSL_UsbRegsOvly;    
typedef volatile ioport CSL_I2cRegs          * CSL_I2cRegsOvly;    
typedef volatile ioport CSL_I2sRegs          * CSL_I2sRegsOvly;         
typedef volatile ioport CSL_EmifRegs         * CSL_EmifRegsOvly;                          
typedef volatile ioport CSL_UartRegs         * CSL_UartRegsOvly;                  
typedef volatile ioport CSL_SpiRegs          * CSL_SpiRegsOvly;                   
typedef volatile ioport CSL_MmcsdRegs        * CSL_MmcsdRegsOvly;                 
typedef volatile ioport CSL_LcdcRegs         * CSL_LcdcRegsOvly;   
typedef volatile ioport CSL_RtcRegs          * CSL_RtcRegsOvly;      
typedef volatile ioport CSL_DmaRegs          * CSL_DmaRegsOvly;
//typedef volatile ioport CSL_SarRegs          * CSL_SarRegsOvly; //jb   
typedef volatile ioport CSL_PllRegs          * CSL_PllRegsOvly;  
typedef volatile ioport CSL_DmaEvtRegs       * CSL_DmaEvtIntRegsOvly;



/*****************************************************************************\
* Peripheral Base Address
\*****************************************************************************/
#define CSL_USB_REGS                    ((CSL_UsbRegsOvly)  0x8000) 
//#define CSL_SAR_REGS                    ((CSL_SarRegsOvly)  0x7000) //jb
#define CSL_EMIF_REGS                   ((CSL_EmifRegsOvly) 0x1000) 
#define CSL_I2C_0_REGS                  ((CSL_I2cRegsOvly)  0x1A00) 
#define CSL_I2S0_REGS              		((CSL_I2sRegsOvly) 	0x2800)       
#define CSL_I2S1_REGS              		((CSL_I2sRegsOvly) 	0x2900)       
#define CSL_I2S2_REGS              		((CSL_I2sRegsOvly) 	0x2A00)       
#define CSL_I2S3_REGS              		((CSL_I2sRegsOvly) 	0x2B00)   
#define CSL_UART_REGS                   ((CSL_UartRegsOvly) 0x1B00)
#define CSL_SPI_REGS                   	((CSL_SpiRegsOvly)  0x3000)          
#define CSL_MMCSD0_REGS           		((CSL_MmcsdRegsOvly)0x3A00)        
#define CSL_MMCSD1_REGS           		((CSL_MmcsdRegsOvly)0x3B00)        
#define CSL_LCDC_REGS              		((CSL_LcdcRegsOvly) 0x2E00)  
#define CSL_RTC_REGS              		((CSL_RtcRegsOvly)  0x1900) 
#define CSL_PLL_REGS              		((CSL_PllRegsOvly)  0x1C20)  
#define CSL_DMA0_REGS              		((CSL_DmaRegsOvly)  0x0C00)       
#define CSL_DMA1_REGS              		((CSL_DmaRegsOvly)  0x0D00)       
#define CSL_DMA2_REGS              		((CSL_DmaRegsOvly)  0x0E00)       
#define CSL_DMA3_REGS              		((CSL_DmaRegsOvly)  0x0F00)  
#define CSL_DMAEVTINT_REGS              ((CSL_DmaEvtIntRegsOvly)0x1C1A)            

/** \brief I2C Module Instances
* 
*/
typedef enum {
  CSL_I2C_ANY    = -1, /**< <b>: Any instance of I2C module</b> */
  CSL_I2C_0      =  0  /**< <b>: I2C Instance 0</b> */
} CSL_I2cNum;


/** \brief GPIO Module Instances
* 
*/
typedef enum {
  CSL_GPIO_ANY    = -1, /**< <b>: Any instance of GPIO module</b> */
  CSL_GPIO        =  0,  /**< <b>: GPIO </b> */
  CSL_MGPIO       =  1  /**< <b>: Multiplexed GPIO </b> */
} CSL_GpioNum;


/** \brief  UART Module Instances
* 
*/
typedef enum {
  CSL_UART_ANY    = -1, /**< <b>: Any instance of UART module</b> */
  CSL_UART_0          =  0,  /**< <b>: UART Instance 0</b> */
  CSL_UART_1          =  1  /**< <b>: UART Instance 1</b> */
} CSL_UartNum;

/** \brief  SPI Module Instances
* 
*/
typedef enum {
  CSL_SPI_ANY    = -1, /**< <b>: Any instance of SPI module</b> */
  CSL_SPI_0      =  0  /**< <b>: SPI Instance 0</b> */
} CSL_SpiNum;

/** \brief  MMC/SD Module Instances
* 
*/
typedef enum {
  CSL_MMCSD_ANY    = -1, /**< <b>: Any instance of MMCSD module</b> */
  CSL_MMCSD_0      =  0  /**< <b>: MMCSD Instance 0</b> */
} CSL_MmcsdNum;


/** \brief  DMA Module Instances
* 
*/
typedef enum {
  CSL_DMA_ANY    = -1, /**< <b>: Any instance of DMA module</b> */
  CSL_DMA_0      =  0  /**< <b>: DMA Instance 0</b> */
} CSL_DmaNum;

/** @brief Enumerations for DMA channels */
typedef enum {
    CSL_DMA_CHA_ANY		   =		     -1,  /**< Any Channel */
    CSL_DMA_CHA_0		   =		      0,  /**< Channel 0 */
    CSL_DMA_CHA_1		   =		      1,  /**< Channel 1 */
    CSL_DMA_CHA_2		   =		      2   /**< Channel 2 */
} CSL_DmaChaNum;

/** \brief  ATA Module Instances
* 
*/
typedef enum {
    CSL_ATA_PRIMARY = 0,
    CSL_ATA_0 = 0,
    CSL_ATA_SECONDARY = 1,
    CSL_ATA_1 = 0,    
    CSL_ATA_ANY = -1
} CSL_AtaNum;

/** \brief LCDC Module Instances
*
*/

typedef enum {
  CSL_LCDC_ANY    = -1, /**< <b>: Used to refer any instance of LCDC
			      module</b> */
  CSL_LCDC_0      =  0  /**< <b>: LCDC Instance 0</b> */
} CSL_LcdcNum;

/** \brief  NTSC/PAL Module Instances
* 
*/
typedef enum {
  CSL_NTSC_ANY    = -1, /**< <b>: Any instance of NTSC module</b> */
  CSL_NTSC_0      =  0  /**< <b>: NTSC Instance 0</b> */
} CSL_NtscNum;

/** \brief EMIF Module Instances
* 
*/
typedef enum {
  CSL_EMIF_ANY    = -1, /**< <b>: Any instance of EMIF module</b> */
  CSL_EMIF_0      =  0  /**< <b>: EMIF Instance 0</b> */
} CSL_EmifNum;

extern void * _CSL_mmcsdlookup[];

/*
extern void * _CSL_i2clookup[];
extern void * _CSL_uartlookup[];
extern void * _CSL_spilookup[];
extern void * _CSL_lcdclookup[];
*/
//#endif


#endif /*CORAZON_H_*/
