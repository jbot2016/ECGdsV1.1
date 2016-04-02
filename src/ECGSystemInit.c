/*****************************************************************************
 **  File Name : ECGSystemInit.c                                              
 *  Brief	 : The file does all the initialization regarding the ECG system. 
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

//jb whole c file commented out right now to ensure compilation and test other important parts of program
//think of work around jb
//pray lol jb
#include "ECGSystemInit.h"
#include "tistdtypes.h"
//#include <csl_sar.h>
//#include <csl_general.h>
//#include <stdio.h>


extern ECG_System_Info ECG_Info;

/* ADS1258 Register values*/

Uint8 	ADS1258RegVal[11] = {
	/* CONFIG0 - BYPAS = 0 , STAT = 1, MUXMOD = 1(Fixed Chan scan) */
	0x2A,
	/* CONFIG1 - DELAY = 0x001(1), DRATE = 0x00(0) 1831 SPS PER Channel (1688)*/
	0x01,
	/* MUXSCH - No effect in Auto scan mode */
	0x08,
	/* MUXDIF - No differential channel selected */			
	0x00,		
	/* MUXSG0 - Single Channel 0 - 7  selected*/
	0x00,
	/* MUXSG1 - Single Channel 8 - 15 not selected */
	0x00,		
	/* SYSRED - System Reading not selected*/
	0x00,		
	/* GPIOC - GPIO 0 - 7 as input*/
	0xFF,		
	/* GPIOD - Data zero*/
	0x00,		
	/* ID - Device ID - Readonly*/
	0x00};		

/* variable to store the active FE*/
static Uint8 FE_Active = NULL;
/* structure which stores the UART configuration values*/
extern PSP_UartConfig uartCfg;
/* Instance no used for UART */
extern Uint8 instNum;
/* Handle for UART driver*/
extern PSP_Handle hUart;
extern int adcSarInit();
/*--------------------------------------------------------------------------------------**
** 	Function Name : ECG_C5505Init()                                                     **
** 	Description : 	- The function initializes all the peripherals of                   **
** 					  the C5505 as required for the ECG system. Also it                 **
** 					  initializes the Front End board components as                     **
** 					  required by the system Has the following                          **
** 					  initialization                                                    **
**                                                                                      **
** 					 - LCD                                                              **
** 					 - GPIO                                                             **
** 					 - SPI                                                              **
** 					 - I2C                                                              **
** 					 - Front End(Consistes of ADS1258, PCA9535)                         **
** 					 - SAR                                                              **
** 					 - DMA                                                              **
**                                                                                      **
** 	Parameters	:	- ECG_Status - Output : return the status ECG_OK on successful Init **
** 	Return		: Status                                                                **
**--------------------------------------------------------------------------------------*/
//need to double check every function, somehow
ECG_Status ECG_C5505Init()
{
	ECG_Status Status;
	//printf("debug jb\n");//jb
	// clock enable to Timer, SPI, DMA, UART,SAR, LCD.
//    *IDLE_PCGCRL_ADDR = 0x4BB1;
//    *IDLE_PCGCRM_ADDR = 0x0004;
    
	/*making Serial Port 0 and Serial Port 1 to mode 10 
	so that serial port 0 pins are configured as GPIO*/
	// set parallel port to 5
	//*PERIPHSEL0_ADDR = 0x5A00;

	//Disable all interrupts
//	*CPU_IER0_ADDR = 0; 
//	*CPU_IER1_ADDR = 0;
//    // clear interrupt flags
//	*CPU_IFR0_ADDR = *CPU_IFR0_ADDR; 
//	*CPU_IFR1_ADDR = *CPU_IFR1_ADDR;

	//asm("\tBIT (ST1, #ST1_INTM) = #1");	  		/*Disable GLobal Int.Mask*/   	
	
	/*//making Serial Port 0 Mode to 10  here */
	//*PERIPHSEL0_ADDR = *PERIPHSEL0_ADDR & 0xFEFF; //clearing bit 8//ravi27/03/2009
	//*PERIPHSEL0_ADDR = *PERIPHSEL0_ADDR | 0x0200; // setting bit 9//ravi27/03/2009

	/*Enable  interrupt for Leadoff - INT1 of CPU*/
	//*CPU_IER0_ADDR = *CPU_IER0_ADDR | 0x0008;  

	/*  Call GPIO Init*/
	//ECG_GPIO_INIT();
	//printf("debug GPIO success jb\n");//jb
	/*  Call I2C init*/
	//Status = ECG_I2C_INIT();
	//printf("debug I2C success jb\n");//jb
	//if(Status != ECG_OK)
	//{
		//printf("I2C Init FAIL\n");
		//while(1);
	//}
	//else
	//{
		//printf("I2C Init PASS\n");
	//}

	//EZDSP5535_wait(1000);

//	/* Call SPI Init*/
//	Status = ECG_SPI_INIT();
//	if(Status != ECG_OK)
//	{
//		printf("SPI Init FAIL\n");
//		while(1);
//	}
//	else
//	{
//		printf("SPI Init PASS\n");
//	}
//
//	EZDSP5535_wait(1000);
//	
//	/* Call UART initialisation*/
//	//ECG_UART_INIT();
//
//	EZDSP5535_wait(1000);
//
//	/*  Call Front End Init*/
//	Status = ECG_FE_INIT(); //not sure if correct, leadoff causes problem
//	if(Status != ECG_OK)
//	{
//		printf("FE Init FAIL\n");
//		while(1);
//	}
//	else
//	{
//		printf("FE Init PASS\n");
//	}
//
//	EZDSP5535_wait(1000); 
#if 1	
	/* Call LCD initialisation*/
	//ECG_LCD_INIT();
	
	//EZDSP5535_wait(1000);
	
#endif

	/*   Call SAR Init*/
	Status = ECG_SAR_INIT();
//	if(Status != ECG_OK)
//	{
//		printf("SAR Init FAIL\n");
//		while(1);
//	}
//	else
//	{
//		printf("SAR Init PASS\n");
//	}

	EZDSP5535_wait(1000);

	/*   Call DMA Init*/
//	Status = ECG_DMA_INIT();
//	if(Status != ECG_OK)
//	{
//		printf("DMA Init FAIL\n");
//		while(1);
//	}
//	else
//	{
//		printf("DMA Init PASS\n");
//	}
//
//	EZDSP5535_wait(1000);
	
	/*	Call Timer Initialization*/
	//ECG_TIMER_INIT();

//	// Enable Interrupt SAR,Timer
//	*CPU_IER0_ADDR = *CPU_IER0_ADDR | 0x3090;
//	/*Enable  interrupt for Leadoff - INT1 of CPU*/
//	*CPU_IER0_ADDR = *CPU_IER0_ADDR | 0x0008;  
//
//	asm("\tBIT (ST1, #ST1_INTM) = #0");	  		/*Enalbe GLobal Int.Mask*/   	

	return Status;
}

/*----------------------------------------------------------------------**
** Function Name 	: ECG_UART_INIT()                                   **
** Description 	: 	- The function initializes the UART module so as to **
** 					transmit the Lead Information at a rate of 115200   **
** 					bps                                                 **
** Parameters		: -	None                                            **
** Return			: - void                                            **
**----------------------------------------------------------------------*/


//void ECG_UART_INIT()
//{
//
//   uartCfg.inputFreq = 100000000; //UART_INPUT_CLK; /* Input Clock to UART */
//   uartCfg.opMode = PSP_OPMODE_POLLED; /* Supporting only Polled Mode */
//   uartCfg.syncMode = True;
///*	uartCfg.baudRate = 115200;
////	uartCfg.charLen = 8;
//	uartCfg.opmode = PSP_OPMODE_POLLED;
//	uartCfg.parity = 1;
//*/
//
//    instNum = 0;
//
//	*(ioport volatile int *)0x1C02 &= 0x7FFB;
//
//	/* changing parallel port mode to 5 - supports UART */
//	*(ioport volatile unsigned *)0x1C00=0x5A00;
//	
//
//	EZDSP5535_wait(500);
//
//	hUart = dda_uartInit(instNum, &uartCfg);
//		
//	/* To override the driver setting for baud rate so as to set 115.2 kbps */
//				
//	*(ioport volatile int *)0x1B10 = 0x36;
//	*(ioport volatile int *)0x1B12 = 0x00;
//
//	return;
//}


/*-----------------------------------------------------------------------**
** 	Function Name : ECG_SAR_INIT()                                       **
** 	Description : 	-  The function initializes the SAR module to select **
** 					   GPAIN1(AIN3) Also set the saradc interrupt for    **
** 					   all key press                                     **
**                                                                       **
** 	Parameters	:	- ECG_Status - Output : return the status ECG_OK on  **
** 											successful Init              **
** 	Return	: Status                                                     **
**-----------------------------------------------------------------------*/

ECG_Status ECG_SAR_INIT()
{
	int pass = 0;
	ECG_Status Status = ECG_OK;
	pass = adcSarInit();
//	CSL_Status    status;
//    CSL_SarHandleObj *SarHandle;
//    CSL_SarChSetup param; //set sampling frequency here as sysclk divisor
//
//    printf("Testing SAR in polling mode\n");
//
//    /* Initialize the SAR module */
//    status = SAR_init();
//    if(status != CSL_SOK)
//    {
//        printf("SAR Init Failed!!\n");
//        return(!ECG_OK);
//    }
//    /* Open SAR channel */
//    status = SAR_chanOpen(&SarObj,CSL_SAR_CHAN_3);
//    SarHandle = &SarObj;
//    if(status != CSL_SOK)
//    {
//        printf("SAR_chanOpen Failed!!\n");
//        return (!ECG_OK);
//    }
//    /* Initialize channel */
//    status = SAR_chanInit(SarHandle);
//    if(status != CSL_SOK)
//    {
//        printf("SAR_chanInit Failed!!\n");
//        return(!ECG_OK);
//    }
//    param.OpMode = CSL_SAR_POLLING;
//    param.MultiCh = CSL_SAR_NO_DISCHARGE;
//    param.RefVoltage = CSL_SAR_REF_VIN;
//    param.SysClkDiv = 0x1869; //was ox0b 0x1869; sample at 500Hz
//    /* Configuration for SAR module */
//    status = SAR_chanSetup(SarHandle,&param);
//    if(status != CSL_SOK)
//    {
//        printf("SAR_chanConfig Failed!!\n");
//        return(!ECG_OK);
//    }
//    
//    status = SAR_GPODirSet(SarHandle,CSL_SAR_GPO_1,CSL_SAR_GPO_IN);
//    if(CSL_SOK != status)
//    {
//        printf("SAR_GPODirSet test Failed\n");
//        return (!ECG_OK);
//    }
//    
//    /* Set channel cycle set */
//    status = SAR_chanCycSet(SarHandle,CSL_SAR_CONTINUOUS_CONVERSION);
//    if(status != CSL_SOK)
//    {
//        printf("SAR_chanCycSet Failed!!\n");
//        return(!ECG_OK);
//    }
//    SarHan = SarHandle;
//	
//  	*SARCTRL = 0x0000;		/* reset the CTRL Reg */
//    *SARCTRL = 0x3400; 		/* select AIN3, which is GPAIN1 */
//	*SARCLKCTRL = 0x0064;   /* 100/100 = 1MHz */ 
//    *SARPINCTRL = 0x7104;   /* Set the AD reference & PIN control values */
//    *SARGPOCTRL = 0x0100;   /* Set the PEN interrupt */
 
	return Status;
}
	
/*-----------------------------------------------------------------------**
** 	Function Name : ECG_DMA_INIT                                         **
** 	Description : 	- The function initializes the DMA module to be used **
** 					  for any                                            **
** 					  other peripheral                                   **
** 	Parameters	:	- ECG_Status - Output : return the status ECG_OK on  **
** 											successful Init              **
** 	Return : Status                                                      **
**                                                                       **
**-----------------------------------------------------------------------*/
ECG_Status ECG_DMA_INIT()
{
	ECG_Status Status = ECG_OK;
	
		
	/* DMA hardware initialization */
	DMA_HwInit();

	/* DMA driver initialization */
	DMA_DrvInit();


	return Status;
}

/*----------------------------------------------------------------------------**
** 	Function Name : ECG_SPI_INIT                                              **
** 	Description : 	- 	The function initializes the SPI peripheral for       **
** 						the the Tx and Rx as required for the                 **
** 						ADS1258.The function uses:-                           **
**                                                                            **
** 						- SPI CLK 	 - 7 MHz                                  **
** 						- WordLength - 8                                      **
** 						- csDelay 	 - 0 (other delay not supported in C5505) **
** 	Parameters	:	- None                                                    **
** 	Return	: ECG_Status - Output : return the status ECG_OK on               **
** 											successful Init                   **
**----------------------------------------------------------------------------*/
ECG_Status ECG_SPI_INIT()
{
	ECG_Status Status;
	DDA_spiConfig spiConfig;
	Uint16 spiClkRate = 7000000; /* 7MHz Max possible for SPI, but not used- hardcoded  */
								/* the SPI_PRESCALE to 13 so as to achieve 7MHz	        */
	Uint16 frameLen = 1;		 /* Frame Len 1 */
	Uint16 wordLen = 8;			/* Word len 8 */	
	Uint16 slaveNo = 0;			/* SlaveNo 0 */
	Uint16 dataDly = 0;			/* delay 0 */
	Uint16 csPol = 0;			/* cspol 0 */
	Uint16 clkPh = 0;			/* clkphase 0 */
	Uint16 clkPol = 0;			/* clkpol 0 */

    Status = SPI_FAILURE;

    /* Driver configuration initialization */
  
    spiConfig.spiCtrlMode   = SPI_MODE;			/* SPI Mode */
    spiConfig.spiMaster     = SPI_MASTER;		/* SPI Master */
    spiConfig.opMode        = SPI_POLLED;		/* SPI polling mode */
    spiConfig.instances     = SPI_SINGLE_INST;	/* Single instance */
    spiConfig.syncMode      = SPI_SYNC;			/* Sync Mode */

	/* Initialize the SPI with */
	Status = SPI_INIT(spiConfig,spiClkRate,frameLen,wordLen,slaveNo,dataDly,csPol,clkPh,clkPol);
	

	return Status;
}



/*--------------------------------------------------------------------------------**
** 	Function Name : ECG_I2C_INIT                                                  **
** 	Description : 	- The function initializes the I2C module with slave address  **
** 					  as the PCA9535 I2C Expander                                 **
** 	Parameter : None                                                              **
** 	Returns	:	- ECG_Status - Output : return the status ECG_OK on               **
** 										successful Init                           **
**--------------------------------------------------------------------------------*/

//jb might not be necessary
ECG_Status ECG_I2C_INIT()
{
	
    Uint16 i=0,j=0;
    Uint16 slvaddr = I2C_ECGFE_ADDR;
	

	for(i=0;i<100;i++) {;}
	
	
	CSL_FINS(CSL_I2C_0_REGS->ICPSC,I2C_ICPSC_IPSC,0x04);  /* Prescalar value */
	CSL_FINS(CSL_I2C_0_REGS->ICCLKL,I2C_ICCLKL_ICCL,0x23);/* Clock Low div value*/
   	CSL_FINS(CSL_I2C_0_REGS->ICCLKH,I2C_ICCLKH_ICCH,0x23);/* Clock High div value*/
	CSL_FINS(CSL_I2C_0_REGS->ICOAR,I2C_ICOAR_OADDR,0x2F); /* I2C Set own Address*/
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_IRS,0);	  /* I2C in reset state*/
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_MST,1);	  /* I2C Set Mode as Master*/
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_TRX,1); 	  /* I2C Set the direction Master transmitter*/
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_XA,0);		  /* I2C Set Address mode as 7-bit*/
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_IRS,1);	  /* I2C in Out of reset state*/
	CSL_FINS(CSL_I2C_0_REGS->ICMDR,I2C_ICMDR_FDF,0);	  /* I2C Free Data format Disabled*/
	CSL_FINS(CSL_I2C_0_REGS->ICSAR,I2C_ICSAR_SADDR,slvaddr); /* Set the Slave Address*/
     
  
    for(j=0;j<100;j++);  
    
	*CPU_IFR0_ADDR = *CPU_IFR0_ADDR | 0x0008;   /*Clear  interrupt flag for Leadoff - INT1 of CPU*/
//	*CPU_IER0_ADDR = *CPU_IER0_ADDR | 0x0008;  /*Enable  interrupt for Leadoff - INT1 of CPU*/

   
	return 	ECG_OK;
}

/*---------------------------------------------------------------------**
** 	FunctionName : ECG_GPIO_INIT                                       **
** 	Description : 	- 	This function initializes the GPIO module and  **
** 						set the direction of the GPIO pin as required. **
**                                                                     **
** 					  GPIO 6 - ADS START 	- Out                      **
** 					  GPIO 7 - GPIOFlag Ch0 - Out                      **
** 					  GPIO 8 - GPIOFlag Ch1 - Out                      **
** 					  GPIO 9 - ADS DRDY		- In                       **
** 					  GPIO 10- BrdDet1 		- In                       **
** 					  GPIO 11- BrdDet0 		- In                       **
** 	Parameter : None                                                   **
** 	Returns	:	- ECG_Status - Output : return the status ECG_OK on    **
** 											successful Init            **
**---------------------------------------------------------------------*/
	
//jb might not be necessary
void ECG_GPIO_INIT()
{
	/*GPIO4- START as o/p, GPIO0 - DRDY as i/p, Rest as i/p*/
	//GPIO11 output

	*GPIO_DIR0_ADDR = *GPIO_DIR0_ADDR | 0x0810;
}

/*---------------------------------------------------------------------**
** 	FunctionName : ECG_FE_INIT                                         **
** 	Description : 	- 	This function initializes all the modules/     **
** 						components in the  ECG Front End.This includes **
**                                                                     **
** 					  	- FE detection                                 **
** 					  	- Leadoff initialization                       **
** 					  	- ADS1258 Initialization                       **
** 	Parameter : None                                                   **
** 	Return	:	- ECG_Status - Output : return the status ECG_OK on    **
** 											successful Init            **
**---------------------------------------------------------------------*/
//jb check if necessary, maybe used to initiate ADS1220
ECG_Status ECG_FE_INIT()
{
	ECG_Status status = PSP_SOK;
   	Uint16 FE_Active = 0;

	/* Call the Leadoff Initialization function*/
	//jb not working status = ECG_LEADOFF_DETECT_INIT();
	if(status != ECG_OK)
	while(1);


	/*  Call the ADS1258 initialization function*/
	status  = ECG_ADS1258_INIT();
	if(status != ECG_OK)
	while(1);
	
	return status;
}
//jb comment out where this function is used
/*------------------------------------------------------------------------------**
** 	FunctionName : ECG_LEADOFF_DETECT_INIT                                      **
** 	Description : 	- This function initializes the leadoff functionality.The   **
** 					  function initializes the PCA9535 I2C expander as follows. **
** 					                                                            **
** 					  PA0-PA7  as input                                         **
** 					  PB0 as input                                              **
** 	Parameter : None                                                            **
** 	Returns	:	- ECG_Status - Output : return the status ECG_OK on             **
** 											successful Init                     **
**------------------------------------------------------------------------------*/

ECG_Status ECG_LEADOFF_DETECT_INIT()
{
	PSP_Result Status = PSP_SOK;
	Uint8 i2cdata[2], i2cRxData[2] = {0,0},pca9535PolReg[2] = {0,0};
    extern Uint16 LeadOffStatus;
	Uint8 A1=0,A2=0,B1=0,B2=0,nA1=0,nA2=0,nB1=0,nB2 =0, PortA =0, PortB = 0;
	
	/* Value to set PA0 -PA7 as input*/
	i2cdata[0] 	= 0xFF;	
	/*Value to set PB0 as input, PB0 -PB7 as input*/		
	i2cdata[1]  = 0xFF;			
	

	EZDSP5535_wait(200);
	/*  Read ConfigPort0 - 1 represents Input*/
	i2c_read_reg(CMD_PCA9535_CP0,&i2cRxData[0]);
	EZDSP5535_wait(200);
	/*  Read ConfigPort1*/
	i2c_read_reg(CMD_PCA9535_CP1,&i2cRxData[1]);
	EZDSP5535_wait(200);


	/*  Read PolarityInPort0 - 0 represents no inversion*/
	i2c_read_reg(CMD_PCA9535_PIP0,&pca9535PolReg[0]);
	EZDSP5535_wait(200);
	/*  Read PolarityInPort1*/
	i2c_read_reg(CMD_PCA9535_PIP1,&pca9535PolReg[1]);
	EZDSP5535_wait(200);

	/* Read the Ports A and B once so as to clear any interrupts
	  Set the currnt Lead off status as the init status.       */


	i2cRxData[0] = 0;
	i2cRxData[1] = 0;
 
	EZDSP5535_wait(200);
	i2c_read_reg(CMD_PCA9535_IP0,&i2cRxData[0]);/* Read Input Port0*/ 
	EZDSP5535_wait(200);
	i2c_read_reg(CMD_PCA9535_IP1,&i2cRxData[1]);/* Read Input Port1*/
 
	/* Getting the Leadoff value by XOR ing with the corresponding
	   Polarity register value so as to avoid any polarity changes */
	A1 = i2cRxData[0];
	A2 = i2cRxData[1];
	B1 = pca9535PolReg[0];
	B2 = pca9535PolReg[1];

	nA1 = LEADOFFMASK - i2cRxData[0];
	nA2 = LEADOFFMASK - i2cRxData[1];
	nB1 = LEADOFFMASK - pca9535PolReg[0];
	nB2 = LEADOFFMASK - pca9535PolReg[1];

	PortA = ( nA1 & B1 ) | (A1 & nB1);
	PortB = ( nA2 & B2 ) | (A2 & nB2);

	LeadOffStatus =  ((PortB << 8) | PortA);
/*Gayathri*/
//	LeadOffStatus = 0x01FF;

	return Status;

}

/*--------------------------------------------------------------------------------------------**
** 	Function Name: ECG_ADS1258_INIT                                                           **
** 	Description : 	- The function initializes the ADS1258 registers with the                 **
** 					  required values. ADS1258 is configured as follows:-                     **
** 					                                                                          **
** 					  CONFIG0 - BYPAS = 0 , STAT = 1, MUXMOD = 1(Fixed Chan scan)             **
** 					  CONFIG1 - DELAY = 0x001(1), DRATE = 0x00(0) 1831 SPS PER Channel (1688) **
** 					  MUXSCH - 	ANIN = Ch9  ANIP  = Ch0 & Ch1                                 **
** 					  MUXDIF - No effect in Fixed channel scan mode                           **
** 					  MUXSG0 - No effect in Fixed channel scan mode	                          **
** 					  MUXSG1 - No effect in Fixed channel scan mode                           **
** 					  SYSRED - No effect in Fixed channel scan mode                           **
** 					  GPIOC - GPIO 0 - 7 as input                                             **
** 					  GPIOD - Data zero                                                       **
** 	Parameter : None						   		                                          **
** 	Return	:	- ECG_Status - Output : return the status ECG_OK on                           **
** 										successful Init                                       **
**--------------------------------------------------------------------------------------------*/

//jb switch to ADS1220 init
ECG_Status ECG_ADS1258_INIT()
{
	PSP_Result Status = 0;

	Uint16 cmdVal = 0;						/* Variable to store the cmd value*/
	Uint16 	*SPIBuf = 0;					/* SPI Tx or Rx Buffer*/
	Uint16  SPICount = 10; 					/* SPIBuff count*/
    Uint16  SPICmdBuf = 0 ;					/* Buff to store the cmd*/		  
    Uint16  SPICmdCount = 0;  				/* CmdBuff count*/
    Uint16  SPIReadOrWrite = SPI_WRITE;		/* Variable to store the current operation of SPI*/
	Uint16 	SPIBufRece[11] = {0};

   /* ADS1258 Register Initialization Values */
	cmdVal = (CMD_REGWR | CMD_MUL);			/* Register Write with MUL enabled is set as Command*/
	SPICmdBuf = cmdVal;
	/* Assigning the address of the memory which stores the Register Values*/
	SPIBuf = (Uint16*)ADS1258RegVal;		
	SPICount = 11; 							/* Count is set to 11 - for 11 registers*/
 	SPICmdCount = 1;						/* Command count = 1*/
						
	/* Set ADS1258 registers with initialization Values */
	
	Status = SPI_READ_WRITE_N_BYTES(SPIBuf,SPICount,&SPICmdBuf,SPICmdCount,SPIReadOrWrite);

	cmdVal = (CMD_REGRD | CMD_MUL);
	SPICmdBuf = cmdVal;
	SPIReadOrWrite = SPI_READ;
	SPIBuf = SPIBufRece;
	
	/* Get ADS1258 registers Values back to verify */

	Status = SPI_READ_WRITE_N_BYTES(SPIBufRece,SPICount,&SPICmdBuf,SPICmdCount,SPIReadOrWrite);

	
 	return Status;
}

////jb most likely not going to use this function
///*-------------------------------------------------------------------**
//**                                                                   **
//** 	Function Name : ECG_LCD_INIT                                     **
//** 	Description : 	- The function sets the data to LCD registers of **
//** 					  C5505. Also initializes the  LCD controller    **
//** 					  registers                                      **
//** 	Return	:	- None                                               **
//** 					                                                 **
//**-------------------------------------------------------------------*/
//
//void ECG_LCD_INIT(void)
//{
//	//Uint16  data;
//	Uint32 i;
//	
//   /*Enable the Frame Done interrupt*/
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCRL,LCDC_LCDLIDDCRL_DONE_INT_EN,0x1); 
//	
//	 
//	/* Set AsyncMPU80 mode*/
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCRL,LCDC_LCDLIDDCRL_LIDD_MODE_SEL,0x3); 
//
//
//	/* Max out strobe, setup and hold timings*/
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGL,LCDC_LCDLIDDCS0CONFIGL_R_SU,0xF); 
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGL,LCDC_LCDLIDDCS0CONFIGL_R_STROBE,0x3F); 
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGL,LCDC_LCDLIDDCS0CONFIGL_R_HOLD,0xF); 
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGL,LCDC_LCDLIDDCS0CONFIGL_TA,0x1); 
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGM,LCDC_LCDLIDDCS0CONFIGM_W_SU,0x1F); 
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGM,LCDC_LCDLIDDCS0CONFIGM_W_STROBE,0x3F); 
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGM,LCDC_LCDLIDDCS0CONFIGM_W_HOLD,0xF); 
//	CSL_FINS(CSL_LCDC_REGS->LCDLIDDCS0CONFIGM,LCDC_LCDLIDDCS0CONFIGM_R_SU,0x1); 
//
//	for(i=1;i<5000;i++ )
//		asm("	nop");
//
//	/*  Call LCD controller initialization function*/
//	Init_LCD();    
//}
//jb understand better
void ECG_TIMER_INIT()
{



	/*  Timer0 Initialization so as to process 1 sample of one
	channel at an interval of 4 ms */

	/* TIM0 EN | AutoReload En | Prescale = 0(100/2 = 50MHz) */
	*CPU_TIM0_CTRL = 0x8002; 
	/*  Timer0 period set to 0x186A0 = 2msms */
	/*  Timer0 period set to 0x15F90 = 1.8ms */
//	*CPU_TIM0_PLWR = 0x7530;//.6ms//822D;-0.665ms/*C350 = 1ms*/
// 0.55 ms was tried but not working 0.58 ms is working
// 0x30D4 = .25ms ( 500 SPS)  0x2710 = .2ms  ;  0x2328 = .18ms 0x3633 = .2775(450SPS)

	*CPU_TIM0_PLWR = 0x30D4;//3A98;//.3ms//445C;//.35ms//4E20;//.4m //574E;//.45ms//7148;//.58ms//822D;-0.665ms/*C350 = 1ms*/
	*CPU_TIM0_PHWR = 0x0000; 

	*CPU_TIM0_CLWR = 0x0000;
	*CPU_TIM0_CHWR = 0x0000;
	
	/*  Clearing timer Aggregation register*/
	*CPU_TIMINT_AGGR = *CPU_TIMINT_AGGR;

	
}
