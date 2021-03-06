#ifndef CSL_IOPORT_H_
#define CSL_IOPORT_H_

/*****************************************************************************
 * File Name : csl_ioport.h 
 *
 * Brief	 : CSL file for CPU registers
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


//#ifndef _CSLR_IOPORT_H_
//#define _CSLR_IOPORT_H_

/* Macro definitions for register addresses */

#define PERIPHSEL0_ADDR     ((ioport volatile unsigned*)0x1C00)
/**< Extenral bus selection register address                                */
#define IDLE_PCGCRL_ADDR    ((ioport volatile unsigned*)0x1C02)             
/**< IDLE PCGCR LSW address                                                 */
#define IDLE_PCGCRM_ADDR    ((ioport volatile unsigned*)0x1C03)             
/**< IDLE PCGCR MSW address                                                 */
#define PER_RSTCOUNT_ADDR   ((ioport volatile unsigned*)0x1C04)             
/**< Peripheral reset counter register address                              */
#define PER_RESET_ADDR      ((ioport volatile unsigned*)0x1C05)             
/**< Peripheral reset control register address                              */
#define GPIO_DIR0_ADDR      ((ioport volatile unsigned*)0x1C06)             
/**< GPIO Direction Register0 address                                       */
#define GPIO_DIR1_ADDR      ((ioport volatile unsigned*)0x1C07)             
/**< GPIO Direction Register1 address                                       */
#define GPIO_DIN0_ADDR     ((ioport volatile unsigned*)0x1C08)             
/**< GPIO Data In Register0 address                                        */
#define GPIO_DIN1_ADDR     ((ioport volatile unsigned*)0x1C09)             
/**< GPIO Data In Register1 address                                        */

#define GPIO_DOUT0_ADDR     ((ioport volatile unsigned*)0x1C0A)             
/**< GPIO Data Out Register0 address                                        */
#define GPIO_DOUT1_ADDR     ((ioport volatile unsigned*)0x1C0B)             
/**< GPIO Data Out Register1 address                                        */

#define GPIO_IER0_ADDR     ((ioport volatile unsigned*)0x1C0E)             
/**< GPIO IER Register0 address                                        */
#define GPIO_IER1_ADDR     ((ioport volatile unsigned*)0x1C0F)             
/**< GPIO IER Register1 address                                        */

#define CPU_IER0_ADDR       ((volatile unsigned*)0x0000)
/**< CPU interrupt enable register0 address                                 */
#define CPU_IER1_ADDR       ((volatile unsigned*)0x0045)                        
/**< CPU interrupt enable register1 address                                 */
#define CPU_IFR0_ADDR       ((volatile unsigned*)0x0001)                        
/**< CPU interrupt flag register0 address                                   */
#define CPU_IFR1_ADDR       ((volatile unsigned*)0x0046)                        
/**< CPU interrupt flag register1 address                                   */


/* Extenral bus selection register bit fields */

#define CSL_PERIPHSEL0_SEL_PARALLELPORT_MASK (0x7000u)
#define CSL_PERIPHSEL0_SEL_PARALLELPORT_SHIFT (0x000Cu)
#define CSL_PERIPHSEL0_SEL_PARALLELPORT_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_SERIALPORT1_MASK (0x0C00u)
#define CSL_PERIPHSEL0_SEL_SERIALPORT1_SHIFT (0x000Au)
#define CSL_PERIPHSEL0_SEL_SERIALPORT1_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_SERIALPORT0_MASK (0x0300u)
#define CSL_PERIPHSEL0_SEL_SERIALPORT0_SHIFT (0x0008u)
#define CSL_PERIPHSEL0_SEL_SERIALPORT0_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_A20GPIO26_MASK (0x0020u)
#define CSL_PERIPHSEL0_SEL_A20GPIO26_SHIFT (0x0005u)
#define CSL_PERIPHSEL0_SEL_A20GPIO26_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_A19GPIO25_MASK (0x0010u)
#define CSL_PERIPHSEL0_SEL_A19GPIO25_SHIFT (0x0004u)
#define CSL_PERIPHSEL0_SEL_A19GPIO25_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_A18GPIO24_MASK (0x0008u)
#define CSL_PERIPHSEL0_SEL_A18GPIO24_SHIFT (0x0003u)
#define CSL_PERIPHSEL0_SEL_A18GPIO24_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_A17GPIO23_MASK (0x0004u)
#define CSL_PERIPHSEL0_SEL_A17GPIO23_SHIFT (0x0002u)
#define CSL_PERIPHSEL0_SEL_A17GPIO23_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_A16GPIO22_MASK (0x0002u)
#define CSL_PERIPHSEL0_SEL_A16GPIO22_SHIFT (0x0001u)
#define CSL_PERIPHSEL0_SEL_A16GPIO22_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_SEL_A15GPIO21_MASK (0x0001u)
#define CSL_PERIPHSEL0_SEL_A15GPIO21_SHIFT (0x0000u)
#define CSL_PERIPHSEL0_SEL_A15GPIO21_RESETVAL (0x0000u)

#define CSL_PERIPHSEL0_RESETVAL (0x0000u)


/* IDLE PCGCR LSW bit fields */

#define CSL_IDLE_PCGCRL_MASTER_CLK_DIS_MASK (0x8000u)
#define CSL_IDLE_PCGCRL_MASTER_CLK_DIS_SHIFT (0x000Fu)
#define CSL_IDLE_PCGCRL_MASTER_CLK_DIS_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_IIS2_IDLE_MASK (0x4000u)
#define CSL_IDLE_PCGCRL_IIS2_IDLE_SHIFT (0x000Eu)
#define CSL_IDLE_PCGCRL_IIS2_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_TIMER2_IDLE_MASK (0x2000u)
#define CSL_IDLE_PCGCRL_TIMER2_IDLE_SHIFT (0x000Du)
#define CSL_IDLE_PCGCRL_TIMER2_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_TIMER1_IDLE_MASK (0x1000u)
#define CSL_IDLE_PCGCRL_TIMER1_IDLE_SHIFT (0x000Cu)
#define CSL_IDLE_PCGCRL_TIMER1_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_EMIF_IDLE_MASK (0x0800u)
#define CSL_IDLE_PCGCRL_EMIF_IDLE_SHIFT (0x000Bu)
#define CSL_IDLE_PCGCRL_EMIF_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_TIMER0_IDLE_MASK (0x0400u)
#define CSL_IDLE_PCGCRL_TIMER0_IDLE_SHIFT (0x000Au)
#define CSL_IDLE_PCGCRL_TIMER0_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_IIS1_IDLE_MASK (0x0200u)
#define CSL_IDLE_PCGCRL_IIS1_IDLE_SHIFT (0x0009u)
#define CSL_IDLE_PCGCRL_IIS1_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_IIS0_IDLE_MASK (0x0100u)
#define CSL_IDLE_PCGCRL_IIS0_IDLE_SHIFT (0x0008u)
#define CSL_IDLE_PCGCRL_IIS0_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_MMCSD1_IDLE_MASK (0x0080u)
#define CSL_IDLE_PCGCRL_MMCSD1_IDLE_SHIFT (0x0007u)
#define CSL_IDLE_PCGCRL_MMCSD1_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_I2C_IDLE_MASK (0x0040u)
#define CSL_IDLE_PCGCRL_I2C_IDLE_SHIFT (0x0006u)
#define CSL_IDLE_PCGCRL_I2C_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_COPROC_IDLE_MASK (0x0020u)
#define CSL_IDLE_PCGCRL_COPROC_IDLE_SHIFT (0x0005u)
#define CSL_IDLE_PCGCRL_COPROC_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_MMCSD0_IDLE_MASK (0x0010u)
#define CSL_IDLE_PCGCRL_MMCSD0_IDLE_SHIFT (0x0004u)
#define CSL_IDLE_PCGCRL_MMCSD0_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_DMA0_IDLE_MASK (0x0008u)
#define CSL_IDLE_PCGCRL_DMA0_IDLE_SHIFT (0x0003u)
#define CSL_IDLE_PCGCRL_DMA0_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_UART_IDLE_MASK (0x0004u)
#define CSL_IDLE_PCGCRL_UART_IDLE_SHIFT (0x0002u)
#define CSL_IDLE_PCGCRL_UART_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_SPI_IDLE_MASK (0x0002u)
#define CSL_IDLE_PCGCRL_SPI_IDLE_SHIFT (0x0001u)
#define CSL_IDLE_PCGCRL_SPI_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_IIS3_IDLE_MASK (0x0001u)
#define CSL_IDLE_PCGCRL_IIS3_IDLE_SHIFT (0x0000u)
#define CSL_IDLE_PCGCRL_IIS3_IDLE_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRL_RESETVAL (0x0000u)


/* IDLE PCGCR MSW bit fields */

#define CSL_IDLE_PCGCRM_ANAREG_CG_MASK (0x0040u)
#define CSL_IDLE_PCGCRM_ANAREG_CG_SHIFT (0x0006u)
#define CSL_IDLE_PCGCRM_ANAREG_CG_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRM_DMA3_CG_MASK (0x0020u)
#define CSL_IDLE_PCGCRM_DMA3_CG_SHIFT (0x0005u)
#define CSL_IDLE_PCGCRM_DMA3_CG_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRM_DMA2_CG_MASK (0x0010u)
#define CSL_IDLE_PCGCRM_DMA2_CG_SHIFT (0x0004u)
#define CSL_IDLE_PCGCRM_DMA2_CG_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRM_DMA1_CG_MASK (0x0008u)
#define CSL_IDLE_PCGCRM_DMA1_CG_SHIFT (0x0003u)
#define CSL_IDLE_PCGCRM_DMA1_CG_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRM_USB_CG_MASK (0x0004u)
#define CSL_IDLE_PCGCRM_USB_CG_SHIFT (0x0002u)
#define CSL_IDLE_PCGCRM_USB_CG_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRM_SAR_CG_MASK (0x0002u)
#define CSL_IDLE_PCGCRM_SAR_CG_SHIFT (0x0001u)
#define CSL_IDLE_PCGCRM_SAR_CG_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRM_LCD_CG_MASK (0x0001u)
#define CSL_IDLE_PCGCRM_LCD_CG_SHIFT (0x0000u)
#define CSL_IDLE_PCGCRM_LCD_CG_RESETVAL (0x0000u)

#define CSL_IDLE_PCGCRM_RESETVAL (0x0000u)


/* Peripheral reset counter register */

#define CSL_PER_RSTCOUNT_MASK (0xFFFFu)
#define CSL_PER_RSTCOUNT_SHIFT (0x0000u)
#define CSL_PER_RSTCOUNT_RESETVAL (0x0000u)


/* Peripheral Reset Control Register bit fields */

#define CSL_PER_RESET_HOLDINRESET_LCD_IIS2_IIS3_UART_SPI_MASK (0x8000u)
#define CSL_PER_RESET_HOLDINRESET_LCD_IIS2_IIS3_UART_SPI_SHIFT (0x000Fu)
#define CSL_PER_RESET_HOLDINRESET_LCD_IIS2_IIS3_UART_SPI_RESETVAL (0x0000u)

#define CSL_PER_RESET_HOLDINRESET_FFTCOP_MASK (0x4000u)
#define CSL_PER_RESET_HOLDINRESET_FFTCOP_SHIFT (0x000Eu)
#define CSL_PER_RESET_HOLDINRESET_FFTCOP_RESETVAL (0x0000u)

#define CSL_PER_RESET_HOLDINRESET_MMCSD0_MMCSD1_IIS0_IIS1_MASK (0x2000u)
#define CSL_PER_RESET_HOLDINRESET_MMCSD0_MMCSD1_IIS0_IIS1_SHIFT (0x000Du)
#define CSL_PER_RESET_HOLDINRESET_MMCSD0_MMCSD1_IIS0_IIS1_RESETVAL (0x0000u)

#define CSL_PER_RESET_HOLDINRESET_DMA_MASK (0x1000u)
#define CSL_PER_RESET_HOLDINRESET_DMA_SHIFT (0x000Cu)
#define CSL_PER_RESET_HOLDINRESET_DMA_RESETVAL (0x0000u)

#define CSL_PER_RESET_HOLDINRESET_USB_MASK (0x0800u)
#define CSL_PER_RESET_HOLDINRESET_USB_SHIFT (0x000Bu)
#define CSL_PER_RESET_HOLDINRESET_USB_RESETVAL (0x0000u)

#define CSL_PER_RESET_HOLDINRESET_ANALOG_SAR_MASK (0x0400u)
#define CSL_PER_RESET_HOLDINRESET_ANALOG_SAR_SHIFT (0x000Au)
#define CSL_PER_RESET_HOLDINRESET_ANALOG_SAR_RESETVAL (0x0000u)

#define CSL_PER_RESET_HOLDINRESET_EMIF_TIMERS_RTC_MASK (0x0200u)
#define CSL_PER_RESET_HOLDINRESET_EMIF_TIMERS_RTC_SHIFT (0x0009u)
#define CSL_PER_RESET_HOLDINRESET_EMIF_TIMERS_RTC_RESETVAL (0x0000u)

#define CSL_PER_RESET_HOLDINRESET_I2C_MASK (0x0100u)
#define CSL_PER_RESET_HOLDINRESET_I2C_SHIFT (0x0008u)
#define CSL_PER_RESET_HOLDINRESET_I2C_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_LCD_IIS2_IIS3_UART_SPI_MASK (0x0080u)
#define CSL_PER_RESET_RESETEN_LCD_IIS2_IIS3_UART_SPI_SHIFT (0x0007u)
#define CSL_PER_RESET_RESETEN_LCD_IIS2_IIS3_UART_SPI_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_FFTCOP_MASK (0x0040u)
#define CSL_PER_RESET_RESETEN_FFTCOP_SHIFT (0x0006u)
#define CSL_PER_RESET_RESETEN_FFTCOP_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_MMCSD0_MMCSD1_IIS0_IIS1_MASK (0x0020u)
#define CSL_PER_RESET_RESETEN_MMCSD0_MMCSD1_IIS0_IIS1_SHIFT (0x0005u)
#define CSL_PER_RESET_RESETEN_MMCSD0_MMCSD1_IIS0_IIS1_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_DMA_MASK (0x0010u)
#define CSL_PER_RESET_RESETEN_DMA_SHIFT (0x0004u)
#define CSL_PER_RESET_RESETEN_DMA_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_USB_MASK (0x0008u)
#define CSL_PER_RESET_RESETEN_USB_SHIFT (0x0003u)
#define CSL_PER_RESET_RESETEN_USB_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_ANALOG_SAR_MASK (0x0004u)
#define CSL_PER_RESET_RESETEN_ANALOG_SAR_SHIFT (0x0002u)
#define CSL_PER_RESET_RESETEN_ANALOG_SAR_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_EMIF_TIMERS_RTC_MASK (0x0002u)
#define CSL_PER_RESET_RESETEN_EMIF_TIMERS_RTC_SHIFT (0x0001u)
#define CSL_PER_RESET_RESETEN_EMIF_TIMERS_RTC_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETEN_I2C_MASK (0x0001u)
#define CSL_PER_RESET_RESETEN_I2C_SHIFT (0x0000u)
#define CSL_PER_RESET_RESETEN_I2C_RESETVAL (0x0000u)

#define CSL_PER_RESET_RESETVAL (0x0000u)


/* GPIO Direction Register0 */

#define CSL_GPIO_DIR0_MASK (0xFFFFu)
#define CSL_GPIO_DIR0_SHIFT (0x0000u)
#define CSL_GPIO_DIR0_RESETVAL (0x0000u)


/* GPIO Direction Register1 */

#define CSL_GPIO_DIR1_MASK (0xFFFFu)
#define CSL_GPIO_DIR1_SHIFT (0x0000u)
#define CSL_GPIO_DIR1_RESETVAL (0x0000u)


/* GPIO Data Out Register0 */

#define CSL_GPIO_DOUT0_MASK (0xFFFFu)
#define CSL_GPIO_DOUT0_SHIFT (0x0000u)
#define CSL_GPIO_DOUT0_RESETVAL (0x0000u)


/* GPIO Data Out Register1 */

#define CSL_GPIO_DOUT1_MASK (0xFFFFu)
#define CSL_GPIO_DOUT1_SHIFT (0x0000u)
#define CSL_GPIO_DOUT1_RESETVAL (0x0000u)


/* CPU interrupt enable register0 bit fields */

#define CSL_CPUIER0_RCV2INT_ENABLE_MASK (0x8000u)
#define CSL_CPUIER0_RCV2INT_ENABLE_SHIFT (0x000Fu)
#define CSL_CPUIER0_RCV2INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_XMT2INT_ENABLE_MASK (0x4000u)
#define CSL_CPUIER0_XMT2INT_ENABLE_SHIFT (0x000Eu)
#define CSL_CPUIER0_XMT2INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_SARINT_ENABLE_MASK (0x2000u)
#define CSL_CPUIER0_SARINT_ENABLE_SHIFT (0x000Du)
#define CSL_CPUIER0_SARINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_LCDINT_ENABLE_MASK (0x1000u)
#define CSL_CPUIER0_LCDINT_ENABLE_SHIFT (0x000Cu)
#define CSL_CPUIER0_LCDINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_RVC1INT_ENABLE_MASK (0x0800u)
#define CSL_CPUIER0_RVC1INT_ENABLE_SHIFT (0x000Bu)
#define CSL_CPUIER0_RVC1INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_COPROCINT_ENABLE_MASK (0x0400u)
#define CSL_CPUIER0_COPROCINT_ENABLE_SHIFT (0x000Au)
#define CSL_CPUIER0_COPROCINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_XMT1INT_ENABLE_MASK (0x0200u)
#define CSL_CPUIER0_XMT1INT_ENABLE_SHIFT (0x0009u)
#define CSL_CPUIER0_XMT1INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_DMAINT_ENABLE_MASK (0x0100u)
#define CSL_CPUIER0_DMAINT_ENABLE_SHIFT (0x0008u)
#define CSL_CPUIER0_DMAINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_RCV0INT_ENABLE_MASK (0x0080u)
#define CSL_CPUIER0_RCV0INT_ENABLE_SHIFT (0x0007u)
#define CSL_CPUIER0_RCV0INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_UARTINT_ENABLE_MASK (0x0040u)
#define CSL_CPUIER0_UARTINT_ENABLE_SHIFT (0x0006u)
#define CSL_CPUIER0_UARTINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_XMT0INT_ENABLE_MASK (0x0020u)
#define CSL_CPUIER0_XMT0INT_ENABLE_SHIFT (0x0005u)
#define CSL_CPUIER0_XMT0INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_TIMERINT_ENABLE_MASK (0x0010u)
#define CSL_CPUIER0_TIMERINT_ENABLE_SHIFT (0x0004u)
#define CSL_CPUIER0_TIMERINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_INT1_ENABLE_MASK (0x0008u)
#define CSL_CPUIER0_INT1_ENABLE_SHIFT (0x0003u)
#define CSL_CPUIER0_INT1_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_INT0_ENABLE_MASK (0x0004u)
#define CSL_CPUIER0_INT0_ENABLE_SHIFT (0x0002u)
#define CSL_CPUIER0_INT0_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER0_RESETVAL (0x0000u)


/* CPU interrupt enable register1 bit fields */

#define CSL_CPUIER1_RTOSINT_ENABLE_MASK (0x0400u)
#define CSL_CPUIER1_RTOSINT_ENABLE_SHIFT (0x000Au)
#define CSL_CPUIER1_RTOSINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_DLOGINT_ENABLE_MASK (0x0200u)
#define CSL_CPUIER1_DLOGINT_ENABLE_SHIFT (0x0009u)
#define CSL_CPUIER1_DLOGINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_BERRINT_ENABLE_MASK (0x0100u)
#define CSL_CPUIER1_BERRINT_ENABLE_SHIFT (0x0008u)
#define CSL_CPUIER1_BERRINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_I2CINT_ENABLE_MASK (0x0080u)
#define CSL_CPUIER1_I2CINT_ENABLE_SHIFT (0x0007u)
#define CSL_CPUIER1_I2CINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_GPIOINT_ENABLE_MASK (0x0020u)
#define CSL_CPUIER1_GPIOINT_ENABLE_SHIFT (0x0005u)
#define CSL_CPUIER1_GPIOINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_USBINT_ENABLE_MASK (0x0010u)
#define CSL_CPUIER1_USBINT_ENABLE_SHIFT (0x0004u)
#define CSL_CPUIER1_USBINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_SPIINT_ENABLE_MASK (0x0008u)
#define CSL_CPUIER1_SPIINT_ENABLE_SHIFT (0x0003u)
#define CSL_CPUIER1_SPIINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_RTCINT_ENABLE_MASK (0x0004u)
#define CSL_CPUIER1_RTCINT_ENABLE_SHIFT (0x0002u)
#define CSL_CPUIER1_RTCINT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_RCV3INT_ENABLE_MASK (0x0002u)
#define CSL_CPUIER1_RCV3INT_ENABLE_SHIFT (0x0001u)
#define CSL_CPUIER1_RCV3INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_XMT3INT_ENABLE_MASK (0x0001u)
#define CSL_CPUIER1_XMT3INT_ENABLE_SHIFT (0x0000u)
#define CSL_CPUIER1_XMT3INT_ENABLE_RESETVAL (0x0000u)

#define CSL_CPUIER1_RESETVAL (0x0000u)


/* CPU interrupt flag register0 */

#define CSL_CPUIFR0_RESET_MASK (0xFFFFu)
#define CSL_CPUIFR0_RESET_SHIFT (0x0000u)
#define CSL_CPUIFR0_RESETVAL (0xFFFFu)


/* CPU interrupt flag register1 */

#define CSL_CPUIFR1_RESET_MASK (0xFFFFu)
#define CSL_CPUIFR1_RESET_SHIFT (0x0000u)
#define CSL_CPUIFR1_RESETVAL (0xFFFFu)


//#endif


#endif /*CSL_IOPORT_H_*/
