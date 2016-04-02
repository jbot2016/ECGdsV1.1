#ifndef ADS1258_H_
#define ADS1258_H_

/*****************************************************************************
 * File Name : ADS1258.h 
 *
 * Brief	 : Global definitions used for ADS configuration and accessing
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


//#ifndef _ADS1258_H
//#define _ADS1258_H

/* ADS1258 Commands*/

#define CMD_MUL     0x10		/* Muliple Enabled*/
#define CMD_CDRD 	0x00		/* Channel Data Read Direct Command*/
#define CMD_CDRC  	0x20		/* Channel Data Read Command*/
#define CMD_REGRD 	0x40	  	/* Register Read Command*/
#define CMD_REGWR 	0x60		/* Register Write Command*/
#define CMD_PULCON 	0x80  		/* Pulse Convert Command*/
#define CMD_RESET 	0xC0		/* Reset Command*/

/* Status Bits  of read Data*/

#define STAT_NEW 0x80
#define STAT_OVF 0x40
#define STAT_SUPPLY 0x20
#define STAT_CHID 0x1F

/* Channel ID */

#define	DIFF0	0x0
#define	DIFF1	0x1
#define	DIFF2	0x02
#define	DIFF3	0x03
#define	DIFF4	0x04
#define	DIFF5	0x05
#define	DIFF6	0x06
#define	DIFF7	0x07
#define	AIN0	0x08
#define	AIN1	0x09
#define	AIN2	0x0A
#define	AIN3	0x0B
#define	AIN4	0x0C
#define	AIN5	0x0D
#define	AIN6	0x0E
#define	AIN7	0x0F
#define	AIN8	0x10
#define	AIN9	0x11
#define	AIN10	0x12
#define	AIN11	0x13
#define	AIN12	0x14
#define	AIN13	0x15
#define	AIN14	0x16
#define	AIN15	0x17
#define	OFFSET	0x18
#define	VCC		0x1A
#define	TEMP	0x1B
#define	GAIN	0x1C
#define	REF		0x1D

#define ADS_GPIOC 0x07
#define ADS_GPIOD 0x08
#define REG_MUXSCH 0x02

/* MASKS */

#define CHID_MASK 0x001F

//#endif


#endif /*ADS1258_H_*/
