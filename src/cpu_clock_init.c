/*****************************************************************************
 * File Name : cpu_clock_init.c
 *
 * Brief	 : Sets the CPU clock by modifying the PLL control and clock
 *  configuration registers.
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



#include "tistdtypes.h"
#include "psp_common.h"
#include "cpu_clock_init.h"
#include "cslr_pll_001.h"
#include "corazon.h"

/* Global variable, that has the system clock in terms of KHz */
Uint32 sysClk       = 0;


PSP_Result CpuClockInit(int pllmult ,int plldiv)
{
    ioport Uint16* CLK_CONFIG_MSW;
    ioport Uint16* PLL_CNTL_LSW ;

    Uint32 maxClk       = 0;
    Uint32 sysClkReqd = 0;

    Uint16 Vp;
    Uint16 Rd;
    Uint16 Vs = 0;

    Uint16 tempVal;

    CLK_CONFIG_MSW  = (Uint16*)CLK_CONFIG_MSW_ADDR;
    PLL_CNTL_LSW    = (Uint16*)PLL_CNTL_LSW_ADDR;

    /* In terms of KHz, This is the required clock frequency */
    sysClkReqd = (INPUT_CLK * (Uint32) pllmult)/(plldiv);

    /* In terms of KHz */
    maxClk = (Uint32)((Uint32)SYS_CLK_MAX * 1000);

    if(maxClk < sysClkReqd) return (PSP_E_INVAL_PARAM);

    /* In terms of KHz, The Input to the VCO is 60 KHz */
    Rd = INPUT_CLK/60;

    tempVal = ( (Rd + 4) * (sysClkReqd/INPUT_CLK) );

    /* This is to ensure that when Vp is calculated, we do not have a decimal point */
    for(Vs=0; Vs<4; Vs++)
    {
        if( ((tempVal-Vs) % 4) == 0)
        {
            break;
        }
    }

    Vp = (tempVal - Vs - 4)/4;

    /* This would be the system clock that the system would be running at */
    sysClk = (Uint32) (INPUT_CLK * ( ( (Vp*4) +Vs+4 ) / (Rd+4) ) );

    /* force to BYPASS mode */
    *CLK_CONFIG_MSW &= (SYS_PLL_BYPASS);

    /* wait for BYPASS mode to be active */
    while(*CLK_CONFIG_MSW & SYS_PLL_SEL);

    /* PLLCNTL1 register values */
    CSL_PLL_REGS->PLLCNTL1 &= ~CSL_PLL_PLLCNTL1_PLL_STANDBY_MASK;
    CSL_PLL_REGS->PLLCNTL1 &= ~CSL_PLL_PLLCNTL1_PLL_PWRDN_MASK;
    CSL_PLL_REGS->PLLCNTL1 |= CSL_PLL_PLLCNTL1_CLR_CNTL_MASK;
    CSL_PLL_REGS->PLLCNTL1 &= ~(CSL_PLL_PLLCNTL1_VP_MASK);
    CSL_PLL_REGS->PLLCNTL1 |= (Vp << CSL_PLL_PLLCNTL1_VP_SHIFT);

    /* PLLINCNTL register values */
    CSL_PLL_REGS->PLLINCNTL &= ~CSL_PLL_PLLINCNTL_RP_BYPASS_MASK;
    CSL_PLL_REGS->PLLINCNTL &= ~CSL_PLL_PLLINCNTL_VS_MASK;
    CSL_PLL_REGS->PLLINCNTL |= (Vs << CSL_PLL_PLLINCNTL_VS_SHIFT);
    CSL_PLL_REGS->PLLINCNTL &= ~CSL_PLL_PLLINCNTL_RD_MASK;
    CSL_PLL_REGS->PLLINCNTL |= (Rd << CSL_PLL_PLLINCNTL_RD_SHIFT);

    /* PLLCNTL2 register values */
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_PLL_DIS_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_CLK_DIS_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_EN_VCO_DIV_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_ENTP_SIG_MASK;
    CSL_PLL_REGS->PLLCNTL2 |= CSL_PLL_PLLCNTL2_EN_LW_JITTER_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_PDSW_CNTL_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_PDSW_TOGDIS_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_LP_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_LW_BIAS_CURR_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_TST_LCK_MON_MASK;
    CSL_PLL_REGS->PLLCNTL2 |= CSL_PLL_PLLCNTL2_LNG_CLK_CNT_MASK;
    CSL_PLL_REGS->PLLCNTL2 |= CSL_PLL_PLLCNTL2_FSTRT_EN_MASK;
    CSL_PLL_REGS->PLLCNTL2 &= ~CSL_PLL_PLLCNTL2_NB_SEL_MASK;

    /* PLLOUTCNTL register values */
    CSL_PLL_REGS->PLLOUTCNTL = CSL_PLL_PLLOUTCNTL_RESETVAL;

    /* wait for PLL mode to be powered on */
    while(*PLL_CNTL_LSW & 0x1000);

    /* select pll */
    *CLK_CONFIG_MSW |= SYS_PLL_SEL;

    /* wait for pll selection */
    while (!(*CLK_CONFIG_MSW & SYS_PLL_SEL));

    return (PSP_SOK);
}

