#ifndef I2C_H_
#define I2C_H_

/*****************************************************************************
 *  File Name : I2C.h                                                  
 *   Description: The file declares all the functions defined in I2C.c
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

//#ifndef _I2C_H
//#define _I2C_H


#include "psp_common.h"

/*   PCA9535 Comand values*/
#define CMD_PCA9535_IP0 0x00
#define CMD_PCA9535_IP1 0x01
#define CMD_PCA9535_OP0 0x02
#define CMD_PCA9535_OP1 0x03
#define CMD_PCA9535_PIP0 0x04
#define CMD_PCA9535_PIP1 0x05
#define CMD_PCA9535_CP0 0x06
#define CMD_PCA9535_CP1 0x07

#define I2C_OWN_ADDR 		   		(0x2F)    /* Dummy address */
#define I2C_BUS_FREQ 		   		(10000u) 

/* function to write a register through i2c */
void i2c_write_reg(Uint8, Uint8*);	
/* function to read register through i2c */
void i2c_read_reg(Uint8, Uint8*);	

//#endif


#endif /*I2C_H_*/
