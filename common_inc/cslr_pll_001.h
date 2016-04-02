#ifndef CSLR_PLL_001_H_
#define CSLR_PLL_001_H_

/*****************************************************************************
 * File Name : cslr_pll_001.h 
 *
 * Brief	 : Define PLL register structure
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

//#ifndef _CSLR__PLL_1_H_
//#define _CSLR__PLL_1_H_

#include <cslr_001.h> //had to make 001 to match ecg ref proj jb


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint16 PLLCNTL1;               //1
    volatile Uint16 PLLINCNTL;              //2
    volatile Uint16 PLLCNTL2;               //3
    volatile Uint16 PLLOUTCNTL;             //4
    volatile Uint16 CLK_OUT; 
} CSL_PllRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PLLCNTL1 */

#define CSL_PLL_PLLCNTL1_CLR_CNTL_MASK (0x8000u)
#define CSL_PLL_PLLCNTL1_CLR_CNTL_SHIFT (0x000Fu)
#define CSL_PLL_PLLCNTL1_CLR_CNTL_RESETVAL (0x0001u)


#define CSL_PLL_PLLCNTL1_PLL_STANDBY_MASK (0x2000u)
#define CSL_PLL_PLLCNTL1_PLL_STANDBY_SHIFT (0x000Du)
#define CSL_PLL_PLLCNTL1_PLL_STANDBY_RESETVAL (0x0001u)

#define CSL_PLL_PLLCNTL1_PLL_PWRDN_MASK (0x1000u)
#define CSL_PLL_PLLCNTL1_PLL_PWRDN_SHIFT (0x000Cu)
#define CSL_PLL_PLLCNTL1_PLL_PWRDN_RESETVAL (0x0000u)


#define CSL_PLL_PLLCNTL1_VP_MASK (0x03FFu)
#define CSL_PLL_PLLCNTL1_VP_SHIFT (0x0000u)
#define CSL_PLL_PLLCNTL1_VP_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL1_RESETVAL (0xA000u)

/* PLLINCNTL */

#define CSL_PLL_PLLINCNTL_RP_BYPASS_MASK (0x8000u)
#define CSL_PLL_PLLINCNTL_RP_BYPASS_SHIFT (0x000Fu)
#define CSL_PLL_PLLINCNTL_RP_BYPASS_RESETVAL (0x0000u)


#define CSL_PLL_PLLINCNTL_VS_MASK (0x3000u)
#define CSL_PLL_PLLINCNTL_VS_SHIFT (0x000Cu)
#define CSL_PLL_PLLINCNTL_VS_RESETVAL (0x0000u)

#define CSL_PLL_PLLINCNTL_RD_MASK (0x0FFFu)
#define CSL_PLL_PLLINCNTL_RD_SHIFT (0x0000u)
#define CSL_PLL_PLLINCNTL_RD_RESETVAL (0x0000u)

#define CSL_PLL_PLLINCNTL_RESETVAL (0x0000u)

/* PLLCNTL2 */

#define CSL_PLL_PLLCNTL2_PLL_DIS_MASK (0x8000u)
#define CSL_PLL_PLLCNTL2_PLL_DIS_SHIFT (0x000Fu)
#define CSL_PLL_PLLCNTL2_PLL_DIS_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_CLK_DIS_MASK (0x4000u)
#define CSL_PLL_PLLCNTL2_CLK_DIS_SHIFT (0x000Eu)
#define CSL_PLL_PLLCNTL2_CLK_DIS_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_EN_VCO_DIV_MASK (0x2000u)
#define CSL_PLL_PLLCNTL2_EN_VCO_DIV_SHIFT (0x000Du)
#define CSL_PLL_PLLCNTL2_EN_VCO_DIV_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_ENTP_SIG_MASK (0x1000u)
#define CSL_PLL_PLLCNTL2_ENTP_SIG_SHIFT (0x000Cu)
#define CSL_PLL_PLLCNTL2_ENTP_SIG_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_EN_LW_JITTER_MASK (0x0800u)
#define CSL_PLL_PLLCNTL2_EN_LW_JITTER_SHIFT (0x000Bu)
#define CSL_PLL_PLLCNTL2_EN_LW_JITTER_RESETVAL (0x0001u)


#define CSL_PLL_PLLCNTL2_PDSW_CNTL_MASK (0x0200u)
#define CSL_PLL_PLLCNTL2_PDSW_CNTL_SHIFT (0x0009u)
#define CSL_PLL_PLLCNTL2_PDSW_CNTL_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_PDSW_TOGDIS_MASK (0x0100u)
#define CSL_PLL_PLLCNTL2_PDSW_TOGDIS_SHIFT (0x0008u)
#define CSL_PLL_PLLCNTL2_PDSW_TOGDIS_RESETVAL (0x0000u)


#define CSL_PLL_PLLCNTL2_LP_MASK (0x0020u)
#define CSL_PLL_PLLCNTL2_LP_SHIFT (0x0005u)
#define CSL_PLL_PLLCNTL2_LP_RESETVAL (0x0001u)

#define CSL_PLL_PLLCNTL2_LW_BIAS_CURR_MASK (0x0010u)
#define CSL_PLL_PLLCNTL2_LW_BIAS_CURR_SHIFT (0x0004u)
#define CSL_PLL_PLLCNTL2_LW_BIAS_CURR_RESETVAL (0x0001u)

#define CSL_PLL_PLLCNTL2_TST_LCK_MON_MASK (0x0008u)
#define CSL_PLL_PLLCNTL2_TST_LCK_MON_SHIFT (0x0003u)
#define CSL_PLL_PLLCNTL2_TST_LCK_MON_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_LNG_CLK_CNT_MASK (0x0004u)
#define CSL_PLL_PLLCNTL2_LNG_CLK_CNT_SHIFT (0x0002u)
#define CSL_PLL_PLLCNTL2_LNG_CLK_CNT_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_FSTRT_EN_MASK (0x0002u)
#define CSL_PLL_PLLCNTL2_FSTRT_EN_SHIFT (0x0001u)
#define CSL_PLL_PLLCNTL2_FSTRT_EN_RESETVAL (0x0001u)

#define CSL_PLL_PLLCNTL2_NB_SEL_MASK (0x0001u)
#define CSL_PLL_PLLCNTL2_NB_SEL_SHIFT (0x0000u)
#define CSL_PLL_PLLCNTL2_NB_SEL_RESETVAL (0x0000u)

#define CSL_PLL_PLLCNTL2_RESETVAL (0x0832u)

/* PLLOUTCNTL */


#define CSL_PLL_PLLOUTCNTL_OUT_DIV_EN_MASK (0x0200u)
#define CSL_PLL_PLLOUTCNTL_OUT_DIV_EN_SHIFT (0x0009u)
#define CSL_PLL_PLLOUTCNTL_OUT_DIV_EN_RESETVAL (0x0000u)

#define CSL_PLL_PLLOUTCNTL_OUT_DIV2_BYP_MASK (0x0100u)
#define CSL_PLL_PLLOUTCNTL_OUT_DIV2_BYP_SHIFT (0x0008u)
#define CSL_PLL_PLLOUTCNTL_OUT_DIV2_BYP_RESETVAL (0x0000u)


#define CSL_PLL_PLLOUTCNTL_OUT_DIV_MASK (0x003Fu)
#define CSL_PLL_PLLOUTCNTL_OUT_DIV_SHIFT (0x0000u)
#define CSL_PLL_PLLOUTCNTL_OUT_DIV_RESETVAL (0x0000u)

#define CSL_PLL_PLLOUTCNTL_RESETVAL (0x0000u)

/*CLK_OUT*/
#define CSL_CLKOUT_CLKSRC_MASK (0x000fu)
#define CSL_CLKOUT_CLKSRC_SHIFT (0x0000u)
#define CSL_CLKOUT_CLKSRC_RESETVAL (0x0000u)

//#endif


#endif /*CSLR_PLL_001_H_*/
