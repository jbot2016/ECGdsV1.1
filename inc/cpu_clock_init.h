#ifndef CPU_CLOCK_INIT_H_
#define CPU_CLOCK_INIT_H_

/*****************************************************************************
 * File Name : cpu_clock_init.h 
 *
 * Brief	 : header file - contains macros for bits in PLL clk registers.
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

//#ifndef CPU_CLOCK_INIT_H_
//#define CPU_CLOCK_INIT_H_

/* Clock configuration MSW */
#define SYS_PLL_BYPASS                      (0xFFFE)
/**< PLL Bypass mode mask                                                   */
#define SYS_PLL_SEL                         (0x0001)
/**< PLL selection mask                                                     */

/* pll control LSW */
#define PLL_MULT_MASK                       (0x03FF)
/**< PLL multiplier mask                                                    */

/* pll control MSW */
#define PLL_DIV_MASK                        (0x0FFF)
/**< PLL Divisor mask                                                       */

#define PLL_PWR_DWN                         (0xEFFF)
/**< PLL powerdown mask                                                     */
#define PLL_ERROR_INCORRECT_INPUT           (-1)
/**< PLL update error                                                       */
#define PLL_MAX_VP_FOR_100MHz               (779)
/**< Max VP value for 100 MHz clock frequency                               */
#define PLL_RP_BYPASS_ENABLE_MASK           (0x8000)
/**< RP Bypass enable Mask                                                  */
#define PLL_OP_DIV_BYPASS_MASK              (0x0100)
/**< O/P Div bypass Mask                                                    */
#define PLL_OP_DIV2_BYPASS_MASK             (0x0200)
/**< O/P Div_2 bypass Mask                                                  */
#define PLL_RP_BYPASS_ENABLE_SHIFT          (15)
/**< RP Bypass enable shift                                                 */
#define PLL_OP_DIV_BYPASS_SHIFT             (8)
/**< O/P Div bypass shift                                                   */
#define PLL_OP_DIV2_BYPASS_SHIFT            (9)
/**< O/P Div_2 bypass shift                                                 */
#define PLL_OP_DIV_MASK                     (0x003F)
/**< O/P Div Mask                                                           */
#define PLL_VS_MASK                         (0x0003)
/**< VS Mask                                                                */
#define PLL_VS_SHIFT                        (12)
/**< VS Shift                                                               */
#define INPUT_CLK                           (12000)
/**< Input clock - 12 MHz                                                   */

#define SYS_CLK_NUMERATOR(MULT,VS)          ((INPUT_CLK)*((MULT<<2)+VS+4))
/**< Numerator of System clock formula                                      */

#define SYS_CLK_MAX                         (100)
/**< Max system clock - 100 MHz                                             */

#define CLK_CONFIG_MSW_ADDR                 ((ioport volatile unsigned*)0x1C1F)
/**< Clock configuration register MSW                                       */
#define PLL_CNTL_LSW_ADDR                   ((ioport volatile unsigned*)0x1C20)
/**< PLL control register LSW                                               */
#define PLL_CNTL_MSW_ADDR                   ((ioport volatile unsigned*)0x1C21)
/**< PLL control register MSW                                               */
#define PLL_OP_CTRL_REG_ADDR                ((ioport volatile unsigned*)0x1C23)
/**< PLL output control register                                            */

/**
 *  \brief Initialize the PLL
 *
 *  Sets the CPU clock by modifying the PLL control and clock
 *  configuration registers. Enable the PLL and wait for locking.
 *
 *  \note:
 *   - The DSP maximum operating frequency is 100MHz @ 1.3V.
 *   - The input to the VCO has to fall between 30KHz and 170KHz.
 *
 *  The PLL input clock supports 32KHz to 40MHz input frequency, but the
 *  reference divider must ensure that the input to the Phase Detector
 *  falls between 30KHz and 170KHz.
 *
 *  Refer to the formula in section 9.8.1.4.1, on page 53 of Corazon spec v1.11
 *  on how system clock is generated.
 *
 *
 * The API returns error, if the systemClock output exceeds 100 MHz. Else, the
 * parameters are allowed and set.
 *
 * \param   pllmult [IN]    PLL Multiplier value
 * \param   plldiv  [IN]    PLL Divisor value
 *
 * \return Success, if the system clock doesn't go past 100MHz for pllmult and plldiv,
 *         failure otherwise.
 */
PSP_Result CpuClockInit(int pllmult ,int plldiv);

//#endif



#endif /*CPU_CLOCK_INIT_H_*/
