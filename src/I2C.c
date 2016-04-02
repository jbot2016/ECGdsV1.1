/*****************************************************************************
 * File Name : I2C.c                                                         
 *  Brief	 : The file includes two function which is done on i2C peripheral 
 * 			- I2C read -  A read function through i2c                         
 * 			- I2C write - A write function through i2c  
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

#include "I2C.h"
#include "corazon.h"

/*--------------------------------------------------------------------------**
** 	Function Nmae : i2c_write_reg                                           **
** 	Description : 	- The  function write the command and data through the  **
** 					  I2C module                                            **
** 	Parameters	:	- cmd - In - The cmd to be send through I2C-8bit        **
** 					- data - In - The data to  be send through I2C-8bit     **
** 	Rteurn : None                                                           **
**--------------------------------------------------------------------------*/

void i2c_write_reg(Uint8 cmd, Uint8* data)
{
    Uint16 response =0, j;


	
	// I2C data count reg 1) RegAddr 2  data 
	*(ioport volatile int *)0x1A14 = 0x0002;

	// I2C IMR - disable all interrupts 
	*(ioport volatile int *)0x1A04 = 0x0000;

	
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_MST,1); /*Set as Master*/
    CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_STT,1); /* Set the Start Condition*/

     
    if(CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_NACK)) {
       while(1);
    }


	/*Check if Transmit Data Register is Ready */
    do	{
      response=CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_ICXRDY);
    }while((response & 0x01)==0);
	 

    
	/*Write data Transmit Data Register - Reg Address*/
    CSL_FINS(CSL_I2C_0_REGS->ICDXR,I2C_ICDXR_D,(cmd & 0xff));
    

      
    if(CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_NACK)) {
       while(1);
    }


	   for(j=0;j<1000;j++);
 

	/*Check if Transmit Data Register is Ready */
    do	{
      response=CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_ICXRDY);
    }while((response & 0x01)==0);
	 

	/*Write data Transmit Data Register - Reg Data1*/
    CSL_FINS(CSL_I2C_0_REGS->ICDXR,I2C_ICDXR_D,(*(data+0) & 0xff));
    

     
    if(CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_NACK)) {
       while(1);
    }


	/*Stop the Transmission from I2C*/
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_STP,1);

 
}


/*------------------------------------------------------------------------------------**
** 	FunctionName: i2c_read_reg                                                        **
** 	Description : 	- The  function reads the command and data through the I2C module **
** 	Parameters	:	- cmd - In - The cmd to be send through I2C                       **
** 					- data - Out - The data to  read through I2C                      **
** 	Return : None                                                                     **
**------------------------------------------------------------------------------------*/


void i2c_read_reg(Uint8 cmd, Uint8* data)
{
    Uint16 response =0, j;

	// I2C data count-0  reg 1) RegAddr 2  data 
	*(ioport volatile int *)0x1A14 = 0x0001;


	*(ioport volatile int *)0x1A24 = 0x22A0;


	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_MST,1); // set as Master
    CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_STT,1); // set a Start Condition


  
    if(CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_NACK)) {
       while(1);
    }


	/*Check if Transmit Data Register is Ready */
    do	{
      response=CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_ICXRDY);
    }while((response & 0x01)==0);
	 

	/*Write data Transmit Data Register - Reg Address*/
    CSL_FINS(CSL_I2C_0_REGS->ICDXR,I2C_ICDXR_D,(cmd & 0xff));
    
    
    if(CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_NACK)) {
       while(1);
    }

	for(j=0;j<1000;j++);
	
  	/* Set in Receive mode*/
	*(ioport volatile int *)0x1A24 = 0x04A0;

	/*Set the start bit*/
	*(ioport volatile int *)0x1A24 = 0xA4A0;

	/*Check for NACK */       
    for(j=0;j<1000;j++);
    
    if(CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_NACK)) {
       while(1);
    }

	   /*Check if Receive Data Register is Ready */
    do	{
      response=CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_ICRRDY);
    }while((response & 0x01)==0);

    /* Receive 1 byte of data sent by the SLAVE*/
	*data = CSL_FEXT(CSL_I2C_0_REGS->ICDRR,I2C_ICDRR_D);

     
    if(CSL_FEXT(CSL_I2C_0_REGS->ICSTR,I2C_ICSTR_NACK)) {
       while(1);
    }

 /* Set in Tx mode // Set back ACK enable*/
	*(ioport volatile int *)0x1A24 = 0xA6A0;

	
	/* Stop I2C tx*/
	*(ioport volatile int *)0x1A24 = 0x2EA0;


	  
}
