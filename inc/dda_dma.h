#ifndef DDA_DMA_H_
#define DDA_DMA_H_

/*****************************************************************************
 * File Name : dda_dma.h 
 *
 * Brief	 : header file for DMA DDA implementation
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

//#ifndef _DDA_DMA_H_
//#define _DDA_DMA_H_

#include "ddc_dma.h"

/* Macros for DMA interrupt register addresses */
#define DMA_IFR_ADDR             (0x1C30)/**< DMA IFR address                */
#define DMA_IMR_ADDR             (0x1C31)/**< DMA IMR register address       */
#define DMA_IFR_RESET_VAL        (0xFFFF)/**< DMA IFR register reset val     */
#define DMA_IMR_VAL              (0xFFFF)/**< DMA IMR register enable value  */

/**
 * \brief initializes the CPU hardware registers of DMA
 *
 * This API must be called only once from the system init function
 * to initialize CPU registers for bringing the DMA out of idle
 * and to enable interrupts.
 *
 * Caution !!!! This function has to be called only once.
 *
 * \return   void
 */
void DMA_HwInit(void);

/**
 * \brief Initializes DMA driver.
 *
 * This API initializes all the DMA engine and channel objects.
 * This API assigns base address for hardware register pointers and
 * initializes channel related information.
 * This API must be called only once at the time of system initialization.
 *
 * Caution !!!! This function has to be called only once.
 *
 * \return   None
 */
void DMA_DrvInit(void);

/**
 * \brief Allocates a requested channel
 *
 * This API checks the availability of requested channel and allocates it
 * if available and returns the handle to that channel.
 * This API checks for one free channel out of four channels that are
 * accessible for a particular IO peripheral.
 * Only one channel can be requested in one call.
 *
 * \param    dmaReqDevId [IN]    Id of the device requesting DMA
 *
 * \return   hDma                DMA channel handle.
 */
DMA_ChanHandle DMA_RequestChan(PSP_DMAReqDevId    dmaReqDevId);

/**
 * \brief Releases a channel
 *
 * This API releases a channel allocated to a device, so that
 * it can be used by other devices.No further transfers are allowed on the
 * released channel until it is allocated again. Only one channel can be
 * released in one call.
 *
 * NOTE: This API 'must' be called after completing all the DMA transfers
 *       to make the channel available for other modules.
 *
 * \param    hDma     [IN]    DMA channel handle.
 *
 * \return   PSP_SOK - If operation is successful
 *                     else suitable error.
 */
PSP_Result DMA_ReleaseChan(DMA_ChanHandle    hDma);

/**
 * \brief Configures the DMA channel
 *
 * This API configures the DMA channels with given configuration parameters
 * This API is called by the application after getting the valid handle
 * to the requested channel.
 *
 * \param    hDma      [IN]    DMA instance handle.
 * \param    dmaConfig [IN]    DMA configuration structure
 *
 * \return   PSP_SOK - If operation is successful
 *                     else suitable error.
 */
PSP_Result DMA_ConfigChan(DMA_ChanHandle    hDma,
                          PSP_DMAConfig     *dmaConfig);

/**
 * \brief Starts DMA data transfer
 *
 * This function starts data transfer on a given DMA channel.
 * Transfer length of bytes are transferred in each call in
 * non-auto reload mode. This API just initiates the data transfer and
 * returns back to the application. Completion of the data transfer is
 * intimated to the application through application callback function.
 *
 * \param    hDma     [IN]    DMA channel handle
 *
 * \return   PSP_SOK - If operation is successful
 *                     else suitable error.
 */
PSP_Result DMA_StartTransfer(DMA_ChanHandle    hDma);

/**
 * \brief Stops DMA data transfer
 *
 * This function stops data transfer on given channel.
 * This can be used to abort the data transfer in normal mode or to stop
 * the data transfer in Auto-reload mode.
 *
 * \param    hDma     [IN]    DMA channel handle.
 *
 * \return   PSP_SOK - If operation is successful
 *                     else suitable error.
 */
PSP_Result DMA_StopTransfer(DMA_ChanHandle    hDma);

/**
 * \brief Routine to modify address for DMA offset
 *
 * This function modifies the source/destination address specified by the
 * application according to the requirement of DMA
 *
 *  \param      address [IN]	Address given by application
 *
 *  \return		modAddr - modified address
 */
Uint32 DMA_AdjustAddrOffset(Uint32    address);

/**
 * \brief Changes the source address
 *
 * This API is called to change the source address of any channel.
 * This API is used for supporting PING - PONG buffer configuration
 *
 * \param    hDma       [IN]    DMA channel handle.
 * \param    newSrcAddr [IN]    New source address
 *
 * \return   PSP_SOK - If operation is successful
 *                     else suitable error.
 */
PSP_Result DMA_ChangeSrcAddr(DMA_ChanHandle    hDma,
                             Uint32            newSrcAddr);

/**
 * \brief Changes the destination address
 *
 * This API is called to change the destination address of any channel.
 * This API is used for supporting PING - PONG buffer configuration
 *
 * \param    hDma        [IN]    DMA instance handle.
 * \param    newDestAddr [IN]    New destination address
 *
 * \return   PSP_SOK - If operation is successful
 *                     else suitable error.
 */
PSP_Result DMA_ChangeDestAddr(DMA_ChanHandle    hDma,
                              Uint32            newDestAddr);

//#endif    /* _DDA_DMA_H_ */


#endif /*DDA_DMA_H_*/
