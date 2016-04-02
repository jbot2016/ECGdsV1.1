/*****************************************************************************
 * File Name : ECGSystemFunctions.c 
 *
 * Brief	 : The file holds all the functions implementation and th
 *  			Algorithm implementation for the ECG system. The file   
 *  			includes the following functions:-                      
 *                                                                      
 * 	- ADS1258 Channel Data Read                                  

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

//jb go over all functions again to understand algorithm and code
//add arrhythmia detection functions in this portion of src code

#include "ECGSystemFunctions.h"
//#include <csl_sar.h>
//#include <csl_general.h>
#include <stdio.h>
//#include "oled.h"
//#include "lcd_command.h"
//#include "register_LCD.h"

#define MAX_PEAK_TO_SEARCH 				5
#define THREE_SEC_SAMPLES  				900 // actually two seconds



#pragma DATA_SECTION(WorkingBuff,".WorkBuffer");
/* Working Buffer Used for Filtering*/
Int16 WorkingBuff[MAXCHAN][FILTERORDER];
/* Last Aquired sample of each channel*/
Int32 PrevAqsnVal[MAXCHAN];
/* Acquisition Buffer to store the values read from ADS1258 */
extern Int32 AqsnBuff[];
/* LeadInfo Buffer*/
extern ECG_Lead_Info Lead_Info;
/* System Information structure*/
extern ECG_System_Info ECG_Info;
/* Multi band FIR LPF coefficients*/
extern Int16 CoeffBuf[];
extern Int16 LP_100_CoeffBuf[];
extern Int16 HP_pt5_CoeffBuf[];
extern Int16 LP_20_CoeffBuf[];

extern Uint16 adcSAR();
/* structure which stores the UART configuration values*/
PSP_UartConfig uartCfg;
/* Instance no used for UART */
Uint8 instNum = 0;
/* Handle for UART driver*/
PSP_Handle hUart = 0;


/*  This will point to the sample index for which the processing has to be */
/*  done i.e 1st and 2nd differentiation should be applied                 */

Uint32 QRS_Lead_Data_Process_Ptr = 0 ;

/*  Buffer which holds the processed data */
Uint32 QRS_Proc_Data_Buffer4[THREE_SEC_SAMPLES] ;
/*  Pointer which points to the index in B4 buffer where the processed data*/
/*  has to be filled */
static Uint32 QRS_B4_Buffer_ptr = 0 ;
/* Variable which will indicate the number of samples after which the */
/* heart rate has to be calculated again.                             */
//static Uint32 QRS_Refresh_Data_Count = 0;

//Uint16 QRS_Start_Refresh_Flag = 0 ;

Uint32 sample_count = 0 ;

Uint16 QRS_Calc_Maxima_Flag = 1 ;
/* Variable which will hold the calculated heart rate */
Uint32 QRS_Heart_Rate = 0 ;

/* 	Variable which holds the threshold value to calculate the maxima*/
float QRS_Threshold_Old = 0;
float QRS_Threshold_New = 0;

/* Variables to hold the sample data for calculating the 1st and 2nd */
/* differentiation                                                   */


Int32 QRS_Second_Prev_Sample = 0 ;
Int32 QRS_Prev_Sample = 0 ;
Int32 QRS_Current_Sample = 0 ;
Int32 QRS_Next_Sample = 0 ;
Int32 QRS_Second_Next_Sample = 0 ;
Int32 InitialFill = 0;

Uint32 i,j;
Int32 cs_flag=0;
Uint8 col = 0;

/*Flag which identifies the duration for which sample count has to be incremented*/
Uint8 Start_Sample_Count_Flag = 0;
Uint8 first_peak_detect = FALSE ;

Uint32 sample_index[MAX_PEAK_TO_SEARCH] = {0};

/* indicates the Zoom-in/ Zoom-out status of the waveform displayed on LCD */
Uint8 Zoom_Flag = 0;
/* variable to hold the status of the lead to be displayed on a key-press */
Uint8 Key_Count = 0;
/* variable to store the zooming value */
Uint32 Zoom_Factor = MEDIUM;
Uint16 FB[128][3];





/*-------------------------------------------------------------------------**
** Function Name 	: ECG_UARTTxCurrSamples()                              **
** Description		: 	- The function transmits the current row () of the **
** 					LeadInfo buffer i.e., current samples of all the       **
** 					leads through UART At every 1 sec, the UART Packet     **
** 					Header has to be transmitted. Also the LeadOff         **
** 					Status and the HR value has to be transmitted The      **
** 					Packet No is transmitted along with all the packets.   **
** 					The Packet no has to start from 0 at every 1 sec.      **
**                                                                         **
** Parameters	  : CurrLead 		- In - Current processing lead         **
** 				    LeadInfoBufRow  - In - Currently filled row            **
** Return			: None                                                 **
**-------------------------------------------------------------------------*/

	unsigned char UARTPacket[256] = {0};

	unsigned char UARTstart = 0;
	unsigned char UARTend =0;
	unsigned UARTdataRdy = 1; //jb was 0, set to 1 to get in initial loop in main

void ECG_UARTTxCurrSamples(Uint32 LeadInfoBufRow,Uint32 CurrLead)
{
	extern Uint16 LeadOff_Flag ;
	static Uint16 UART_PacketNo = 0;
	Uint8 Count1 = 0;
	static Uint8 Count2=0;
	Uint8 ECG_UART_Header[5] = {0x00,0x80,0x00,0x80,0x00};
	extern Uint16 LeadOffStatus;
//	int i;

	if(LeadInfoBufRow == 0)
	UART_PacketNo = 0;


	if((LeadInfoBufRow-1) % UARTDECIMATOR == 0)
	{

		if(CurrLead == 0)
		{

			if(UART_PacketNo == 0)
			{
				/*  Set the UART Header for Tx*/
				for(Count1=0;Count1<5;Count1++)
				UARTPacket[UARTstart++] = ECG_UART_Header[Count1];

				/* Set the packet No for Tx*/
				UARTPacket[UARTstart++] = UART_PacketNo;

				/* Set the Current Heart rate*/
				UARTPacket[UARTstart++] = ECG_Info.ECG_HeartRate;

				/* Set the current Leadoff status*/
				UARTPacket[UARTstart++] = LeadOffStatus & 0x00FF;
				UARTPacket[UARTstart++] = (LeadOffStatus & 0xFF00)>>8 ;


			}
			else
			{
				/* Set the packet No for Tx*/
				UARTPacket[UARTstart++] = UART_PacketNo;
			}

			UART_PacketNo++;

		}
			/* Set the Lead value for 8 leads for Tx*/

		UARTPacket[UARTstart++]= (Lead_Info.lead_info_data[LeadInfoBufRow][CurrLead] & 0x00FF);
		UARTPacket[UARTstart++]= (Lead_Info.lead_info_data[LeadInfoBufRow][CurrLead] & 0xFF00) >> 8 ;
		UARTdataRdy = 1;

		Count2 += 1;

		if(!(UART_PacketNo < 0xFF))
		UART_PacketNo = 0;

	}


	return;
}

//skipping ECG_LCDPlotCurrentSample jb
//add a way to do this for testing


//assembly errors causing most problems jb
//uncomment when solution determined possibly fixed
//jb to fix asm set codegen to output alg assembly in runtime options
void ECG_FilterProcess(Int16* X,Int16* A, Int16* Y)
{


	asm("	*AR2 = #0");
	asm("	T0 = #351");
	asm("	AC0 = #0");

	asm("LOOP?	");
	asm("	T0 -= #1");
	asm("	AC0 += ((*AR0+)*(*AR1+))");
	asm("	if (T0 != #0) goto LOOP?");	/* if count2 !=0, go to loop*/

	asm("	nop");
	asm("	nop");
	asm("	(*AR2+) = HI(AC0) ");
	asm("	*AR2 = AC0 ");


	
}

/*--------------------------------------------------------------------------**
** Function Name : ECG_ProcessCurrSample()                                  **
** Description	  :                                                         **
** 				The function process one sample of data at a time and       **
** 				which stores the filtered out sample in the Leadinfobuff.   **
** 				The function does the following :-                          **
**                                                                          **
** 				- DC Removal of the current sample                          **
** 				- Multi band FIR LPF with Notch at 50Hz filtering           **
** Parameters	  :                                                         **
** 				- CurrAqsSample		- In - AqsnBuf Row count                **
** 				- FirstFlag			- In - Flag to idenftify the first exec **
** 				- CurrFilterChan	- In - Current Row of filtering         **
** 				- CurrLeadInfoRow	- In - Current row of lead info buff    **
** Return 		  : None                                                    **
**--------------------------------------------------------------------------*/

void ECG_ProcessCurrSample(Uint32 CurrAqsSample,Uint8 FirstFlag,Uint32 CurrFilterChan,Uint32 CurrLeadInfoRow)
{
	/* Variables used for DC removal  */
	Int32 CurrInp,PrevInp, CurrOut, PrevOut,CurrVal;

	/* Variable for Filtering */
	//long long FilterOut1=0,FilterOut2=0;
	Int32 FilterOut = 0;
	//long long MulVal = 0;
	/* Count variable*/
	Uint16 Count2;
	//static int i = 0,j=0;

	Int16 *val1, *val2;
	Int16 Sample1, Sample2, Sample3, Sample4, Sample5, Sample6, Sample7;

	 /* The loop does the buffer shifting of the current aquired lead for */
	 /* 	 the Working buffer	                                          */
 
	val1 = &WorkingBuff[CurrFilterChan][FILTERORDER-2];
	val2 = &WorkingBuff[CurrFilterChan][FILTERORDER-1];
	
//	*GPIO_DOUT0_ADDR = *GPIO_DOUT0_ADDR | GPIO7SET;

	for(Count2= 0 ; Count2 < 50; Count2++) //Min((FILTERORDER-1),InpIndex)
	{

		Sample1 = 	*val1--;
		Sample2 = 	*val1--;
		Sample3 = 	*val1--;
		Sample4 = 	*val1--;
		Sample5 = 	*val1--;
		Sample6 = 	*val1--;
		Sample7 = 	*val1--;

		*val2-- = Sample1;
		*val2-- = Sample2;
		*val2-- = Sample3;
		*val2-- = Sample4;
		*val2-- = Sample5;
		*val2-- = Sample6;
		*val2-- = Sample7;

	}

	CurrVal = 0;/* reseting Current val*/
	CurrOut = 0;/* resetting currentout*/
	PrevInp = 0;/* reseting previn*/
	PrevOut = 0;/* resetting prevout*/

	/* For the first time of each lead, the PrevInp will be zero.
	   From the second time of the main loop onwards, the PrevInp
	   is taken from the array PrevAqsnVal */


	if(CurrAqsSample >= MAXCHAN  || FirstFlag == 1)
	{
		if(CurrAqsSample < MAXCHAN )
			PrevInp = PrevAqsnVal[CurrAqsSample];
		else
			PrevInp = AqsnBuff[CurrAqsSample-MAXCHAN];
	}

	/* Current input value from AqsnBuff */
	CurrInp = AqsnBuff[CurrAqsSample];

	/* Previous Out value from Working buffer */
	PrevOut = WorkingBuff[CurrFilterChan][1];



	/* DC Removal of the current sample*/
	CurrVal = (NRCOEFF * PrevOut);
	CurrOut = CurrInp - PrevInp + CurrVal;


	/* Store the DC removed value in Working buffer in millivolts range*/
	WorkingBuff[CurrFilterChan][0] = (Int16)(CurrOut);

	/*  Multi band LPF with Notch.*///jb need to uncomment when fixed
	ECG_FilterProcess(&WorkingBuff[CurrFilterChan][0],CoeffBuf,(Int16*)&FilterOut);

	//jb additional filtering
	//.5Hz HP
	WorkingBuff[CurrFilterChan][0] = (Int16)(((FilterOut >> 15) & (0x0000FFFF))) ;//(CurrOut);
	ECG_FilterProcess(&WorkingBuff[CurrFilterChan][0],HP_pt5_CoeffBuf,(Int16*)&FilterOut);

	//jb additional filtering
	//100Hz LP
	WorkingBuff[CurrFilterChan][0] = (Int16)(((FilterOut >> 15) & (0x0000FFFF))) ;//(CurrOut);
	ECG_FilterProcess(&WorkingBuff[CurrFilterChan][0],LP_100_CoeffBuf,(Int16*)&FilterOut);
	
	/* Store the filtered out sample to the LeadInfo buffer*/
	Lead_Info.lead_info_data[CurrLeadInfoRow][CurrFilterChan] = (Int16)(((FilterOut >> 15) & (0x0000FFFF))) ;//(CurrOut);

	printf(" %d\n", Lead_Info.lead_info_data[CurrLeadInfoRow][CurrFilterChan]);
	
	//FilterOut = 0;
    //FilterOut1 = 0;


	return ;
}


/*-----------------------------------------------------------------------**
** Function Name : ECG_GetCurrAqsnSample()                               **
** Description	  :                                                      **
**                                                                       **
** 				This function convert the current channel data, which is **
** 				of 4 bytes to 24 bit sample information for further      **
** 				processing and convert into the corresponding voltage    **
** 				equivalent                                               **
** Parameters    : ChannelData - In - Channel Data buffer if 4 bytes     **
** Return		  : Current input Voltage                                **
**-----------------------------------------------------------------------*/


//Int32 ECG_GetCurrAqsnSample(Uint8* ChannelData)
Int32 ECG_GetCurrAqsnSample(Uint16* ChannelData)
{
	Int32 AqsnData = 0;

	/*double CurrentInpVolt = 0;*/
    Int32 CurrentInpVolt = 0;

	/* This loop convert the three 8 bit channeldata value to one 24 bit */
	/* 	sample and store it in the AqsnBuff.                             */

	//AqsnData = (((Uint32)ChannelData[0] & BYTEMASK ) << 16 )|
		//	   (((Uint16)ChannelData[1] & BYTEMASK ) << 8 ) |
			//   ((ChannelData[2] & BYTEMASK ) );

	/* Convert the Aqsn value to corresponding voltage */
	CurrentInpVolt  = ((Uint32) ChannelData[0] & BYTEMASK); //AqsnData;
	//printf("test %d\n", (Int16)CurrentInpVolt);
	return CurrentInpVolt;
}

/*--------------------------------------------------------------------------**
**                                                                          **
**                                                                          **
** 	Function Name : - ADS1258_Read_ChannelData                              **
** 	Description : 	This function reads the current channel data and        **
** 					store into the  Channel Data buffer. The function       **
** 					does the following:-                                    **
** 					                                                        **
** 					  - Set the MUXSCH registers AIMP to the current        **
** 					  required channel                                      **
**                                                                          **
** 					  - Give the PULSE Convert Command                      **
**                                                                          **
** 					  - Get the Channel Read data                           **
** 					                                                        **
** 	Parameters	: - ChannelData - In - the pointer to ChannelData memory    **
** 				  - CurrChannel - In - Pointer ti the current channel       **
** 	Return      : None			                                            **
**--------------------------------------------------------------------------*/


//void ADS1258_Read_ChannelData(Uint8 *ChannelData,Uint8 *CurrChannel)
void ADS1258_Read_ChannelData(Uint16 *ChannelData,Uint16 *CurrChannel)
{

//	Uint8 Count1;
//	static Uint8 PosChan = 0;	/* Variable to store the Positive Channel */
//	Uint16 	SPIBuffer[4] = {0};	/* SPI Buff for Rx *///jb same as below ads1220
//	Uint16  SPICount = 4; 		/* No of words to read for a single chann */ //might have to change to 1 for ads1220, jb
//	Uint16  SPICmdBuf = 0 ;		/* CmdBuf variable */
//	Uint16  SPICmdCount = 0;	/* Cmd count */
//	Uint16  SPIReadOrWrite = SPI_READ;/* SPI read/write */
//	Uint16 SPIBuf = 0;
//	static Uint8 PrevChan = 7; //jb might have to change to 1 for ads1220
//
//	printf("jb debug in ads1258 readchannel, nned to change to ADS1220\n");
//	/* CurrentChannel Read is set  to the last channel given for conversion */
//	*CurrChannel = PrevChan;
//
//
//	/*  Set the MUXSCH AINP to the Current REQUIRED Channel*/
//
//	SPICount = 1;
//	SPICmdCount = 1;
//
//	SPIBuf = (PosChan << 4) | 0x09;
//
//	SPICmdBuf = (CMD_REGWR |  REG_MUXSCH);
//	SPIReadOrWrite = SPI_WRITE;
//
//	SPI_READ_WRITE_N_BYTES(&SPIBuf,SPICount,&SPICmdBuf,SPICmdCount,SPIReadOrWrite);
//
//
//	/* Give PULSE Convert Command*/
//
//	SPICount = 0;
//	SPICmdCount = 1;
//
//	SPIBuf = 0;
//	SPICmdBuf = (CMD_PULCON | CMD_MUL);
//	SPIReadOrWrite = SPI_WRITE;
//
//	SPI_READ_WRITE_N_BYTES(&SPIBuf,SPICount,&SPICmdBuf,SPICmdCount,SPIReadOrWrite);
//
//	/*  Channel Data Read */
//
//	SPICount = 4;
//	SPICmdCount = 1;
//
//	SPICmdBuf = (CMD_CDRC | CMD_MUL);
//	SPIReadOrWrite = SPI_READ;
//
//	SPI_READ_WRITE_N_BYTES((Uint16*)&SPIBuffer,SPICount,&SPICmdBuf,SPICmdCount,SPIReadOrWrite);
//
//
//	PrevChan =PosChan;
//
//	PosChan++;
//
//	if(PosChan == MAXCHAN)			/* Check if posChan reached MAXCHAN */
//	{
//		PosChan = 0;				/* if yes reset poschan */
//	}
//
//
//
//	/*  ChannelData Buffer is loaded with the current SPI Buffer value*/
//	for(Count1=0;Count1<3;Count1++)
//		ChannelData[Count1] = (Uint8)SPIBuffer[Count1+1];
	ChannelData[0] = adcSAR();
 	return;
}

//jb not using currently, also asm code causes issues
//
///*-------------------------------------------------------------------------------**
//** 	Function Name : Wait()                                                       **
//** 	Description : 	- The function gives a delay of n CPU cycles where n is the  **
//** 					  parameter Count                                            **
//** 	Parameters	:	- Count - In - no of delay cycles                            **
//** 	Return		: none                                                           **
//**-------------------------------------------------------------------------------*/
//
//void wait(Uint32 count)
//{
//	Int32 i;
//
//	for(i=0;i<count;i++)
//	asm("	nop");
//}

/*---------------------------------------------------------------------**
** 	Function Name : CurrInp_Voltage()                                  **
** 	Description : The  function converts the Hex input values to a     **
** 				  corresponding signed  integer value                  **
** 	                                                                   **
** 	Parameters	: - hexVal - In - The Hexadecimal value which needs to **
** 				  be converted to  voltage                             **
** 	Return		: None                                                 **
**---------------------------------------------------------------------*/

double CurrInp_Voltage(Uint32 hexVal)
{
	double Volt = 0;

	if (hexVal >0x00800000)						// -ve voltage
	{
		Volt = ((long long)hexVal - MAXHEXVAL);///(double)UNITVOLT;
	}
	else if(hexVal < 0x00800000)				// +ve voltage
	{
    	Volt = hexVal;///(double)UNITVOLT;
    }
	else
	     Volt = hexVal;							// 0 volt

	return Volt;
}


/*----------------------------------------------------------------------**
**                                                                      **
** 	Function Name : QRS_Algorithm_Interface                             **
** 	Description -   This function is called by the main acquisition     **
** 					thread when (N/3) samples are filled in   **
** 					the Lead_Info_buffer for Lead II.Here N = 351 and   **
** 					thus it is called for a fill of every 117 **
** 					samples                                             **
**                                                                      **
** 	Parameters  : - CurrLeadInfoRow - In - Index of Current row which is filled in Lead Info Buffer                                                 **
** 	Return		: None                                                  **
**----------------------------------------------------------------------*/

void QRS_Algorithm_Interface(Uint32 CurrLeadInfoRow)
{
	Lead_Info.main_index_ptr = CurrLeadInfoRow;	// Current Row(Sample) filled in the Lead Info buffer

	QRS_call_process_buffer() ;
}

/*-----------------------------------------------------------------------**
** 	Function Name : QRS_call_process_buffer                              **
** 	Description -   Before calling the process_buffer() the below check  **
** 					has to be done. i.e. We have always received +2      **
** 					samples before starting the processing  for each     **
** 					samples. This function basically checks the          **
** 					difference between the QRS_Lead_Process_Ptr and      **
** 					Main_Index_Ptr and picks the data from               **
** 					Lead_Info_Buffer for processing.  This function also **
** 					checks for the roll back and fill the variables      **
** 					accordingly which will be used in the 1st and 2nd    **
** 					differentiation calculations.                        **
**                                                                       **
** 	Parameters  - Nil                                                    **
** 	Return	- None                                                       **
**-----------------------------------------------------------------------*/


static void QRS_call_process_buffer( void )
{
	if( QRS_Lead_Data_Process_Ptr > Lead_Info.main_index_ptr )
	{
		/* Check if the difference is more than two	*/

		while( QRS_Lead_Data_Process_Ptr < (LEADINFOSIZE - 2) )
			// This also implies that we have received more than 2 samples
		{
			QRS_Current_Sample =
						Lead_Info.lead_info_data[ QRS_Lead_Data_Process_Ptr][ 1 ] ;
			QRS_Next_Sample =
						Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr + 1)][ 1 ] ;
			QRS_Second_Next_Sample =
						Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr + 2)][ 1 ] ;

			if( QRS_Lead_Data_Process_Ptr >= 2 )
			{
				QRS_Prev_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr - 1)][ 1 ] ;
				QRS_Second_Prev_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr - 2)][ 1 ] ;
			}
			else if( QRS_Lead_Data_Process_Ptr == 1 )
			{
				QRS_Prev_Sample =
							Lead_Info.lead_info_data[ 0 ][ 1  ] ;
				QRS_Second_Prev_Sample =
							Lead_Info.lead_info_data[ (LEADINFOSIZE - 1)][ 1 ] ;
			}
			else if( QRS_Lead_Data_Process_Ptr == 0 )
			{
				QRS_Prev_Sample =
							Lead_Info.lead_info_data[ (LEADINFOSIZE - 1)][ 1] ;
				QRS_Second_Prev_Sample =
							Lead_Info.lead_info_data[ (LEADINFOSIZE - 2)][ 1 ] ;
			}
			QRS_process_buffer() ;
			QRS_Lead_Data_Process_Ptr ++ ;
			if( QRS_Lead_Data_Process_Ptr >= LEADINFOSIZE )
			{
				QRS_Lead_Data_Process_Ptr = 0 ;
			}
		}
		while( (QRS_Lead_Data_Process_Ptr != 0) && (Lead_Info.main_index_ptr != 0) )
		{


			/* Check if we have received more than two samples  This */
			/* condition occurS only when the                        */
			/* QRS_Lead_Data_Process_Ptr > LEADINFOSIZE-2 i.e.        */
			/* QRS_Lead_Data_Process_Ptr will be either              */
			/* LEADINFOSIZE or LEADINFOSIZE-1                          */


			if( ( (LEADINFOSIZE - QRS_Lead_Data_Process_Ptr) + Lead_Info.main_index_ptr ) >= 2 )
			{
				QRS_Second_Prev_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr - 2)][ 1 ] ;
				QRS_Prev_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr - 1)][ 1 ] ;
				QRS_Current_Sample =
							Lead_Info.lead_info_data[ QRS_Lead_Data_Process_Ptr][ 1 ] ;

				if( QRS_Lead_Data_Process_Ptr == (LEADINFOSIZE - 2) )
				{
					QRS_Next_Sample =
								Lead_Info.lead_info_data[ (LEADINFOSIZE - 1)][ 1 ] ;
					QRS_Second_Next_Sample =
								Lead_Info.lead_info_data[ 0][ 1 ] ;
				}
				else if( QRS_Lead_Data_Process_Ptr == (LEADINFOSIZE - 1) )
				{
					QRS_Next_Sample =
								Lead_Info.lead_info_data[ 0][ 1 ] ;
					QRS_Second_Next_Sample =
								Lead_Info.lead_info_data[ 1][ 1 ] ;
				}
				QRS_process_buffer() ;
				QRS_Lead_Data_Process_Ptr ++ ;
				if( QRS_Lead_Data_Process_Ptr >= LEADINFOSIZE )
				{
					QRS_Lead_Data_Process_Ptr = 0 ;
				}
			}
		}
	}
	if( QRS_Lead_Data_Process_Ptr < Lead_Info.main_index_ptr )
	{
		/* start processing only if we have received more than 2 samples */
		while( (Lead_Info.main_index_ptr - QRS_Lead_Data_Process_Ptr) > 2 )
		{
			QRS_Current_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr)][ 1 ] ;
			QRS_Next_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr + 1)][ 1 ] ;
			QRS_Second_Next_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr + 2)][ 1 ] ;

			if( QRS_Lead_Data_Process_Ptr >= 2 )
			{
				QRS_Prev_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr - 1)][ 1 ] ;
				QRS_Second_Prev_Sample =
							Lead_Info.lead_info_data[ (QRS_Lead_Data_Process_Ptr - 2)][ 1 ] ;
			}
			else if( QRS_Lead_Data_Process_Ptr == 1 )
			{
				QRS_Prev_Sample =
							Lead_Info.lead_info_data[ 0 ][ 1 ] ;
				QRS_Second_Prev_Sample =
							Lead_Info.lead_info_data[ (LEADINFOSIZE - 1) ][ 1 ] ;
			}
			else if( QRS_Lead_Data_Process_Ptr == 0 )
			{
				if(InitialFill == 0)
				{
					QRS_Prev_Sample = 0;
					QRS_Second_Prev_Sample = 0;

					InitialFill =1;
				}
				else
				{
					QRS_Prev_Sample =
								Lead_Info.lead_info_data[ (LEADINFOSIZE - 1)][ 1 ] ;
					QRS_Second_Prev_Sample =
								Lead_Info.lead_info_data[ (LEADINFOSIZE - 2)][1 ] ;
				}
			}

			QRS_process_buffer() ;
			QRS_Lead_Data_Process_Ptr ++ ;
			if( QRS_Lead_Data_Process_Ptr >= LEADINFOSIZE )
			{
				QRS_Lead_Data_Process_Ptr = 0 ;
			}
		}
	}
}

/*-----------------------------------------------------------------------**
** 	Function Name : QRS_process_buffer()                                 **
** 	Description -                                                        **
** 	                                                                     **
** 					This function will be doing the first and second     **
** 					order differentiation for 	input sample,            **
** 					QRS_Current_Sample.After we process the data we can  **
** 					fill the 	QRS_Proc_Data_Buffer which is the input  **
** 					for HR calculation Algorithm. This function is       **
** 					called for each n sample.Once we have received 6s of **
** 					processed 	data(i.e.Sampling rate*6) in the B4      **
** 					buffer we will start the heart rate calculation for  **
** 					first time and later we will do heart rate           **
** 					calculations once we receive the defined 	number   **
** 					of samples for the expected number of refresh        **
** 					seconds.                                             **
** 	                                                                     **
** 	Parameters  - Nil                                                    **
** 	Return 		- None                                                   **
**-----------------------------------------------------------------------*/
static void QRS_process_buffer( void )
{

	//extern LeadOff_Flag;
	//Int32 A=0, B=0;
	extern Uint16 LeadOffStatus;
	Int32 first_derivative = 0 ;
	//Int32 second_derivative = 0 ;
	float scaled_result = 0 ;

//	static Uint8 first_peak_detect = FALSE ;
	Uint8 loop_count = 0 ;
	Uint32 max = 0 ;
	//

	/* calculating first derivative*/
	first_derivative = QRS_Next_Sample - QRS_Prev_Sample  ;

	/*taking the absolute value*/

	if(first_derivative < 0)
	{
		first_derivative = -(first_derivative);
	}

	scaled_result = first_derivative;
	
#if 0
	/* calculating second derivative*/
	A = (2 * QRS_Current_Sample);
	B = QRS_Second_Next_Sample + QRS_Second_Prev_Sample ;
	second_derivative = B - A;

	/*taking the absolute value*/

	if(second_derivative < 0)
	{
		second_derivative = -(second_derivative);
	}

	scaled_result = (float)
				( FD_SCALE_FACTOR * first_derivative ) + ( SD_SCALE_FACTOR * second_derivative ) ;

#endif
	
	if( FALSE == first_peak_detect )
	{
		/*
		For the fist two seconds just store the sample values for
		calculating the first threshold.
		*/
		QRS_Proc_Data_Buffer4[ QRS_B4_Buffer_ptr ++ ] = scaled_result ;

		if( QRS_B4_Buffer_ptr >= THREE_SEC_SAMPLES )
		{

			for( loop_count = 0 ; loop_count < THREE_SEC_SAMPLES ; loop_count ++ )
			{
			    if( QRS_Proc_Data_Buffer4[ loop_count ] > max )
				{
					max = QRS_Proc_Data_Buffer4[ loop_count ] ;
				}
				loop_count ++ ;
			}
			
			QRS_Threshold_Old = (float)( QRS_THRESHOLD_FRACTION * max ) ;
			QRS_Threshold_New = QRS_Threshold_Old ;
			if(max > 180)
			first_peak_detect = TRUE ;
		}
	}
	else
	{
		QRS_check_sample_crossing_threshold( scaled_result ) ;
	}
}

/*-------------------------------------------------------------------**
** 	Function Name : QRS_Get_Heart_Rate()                             **
** 	Description - This function gives the HR value when called       **
** 	Parameter -   Nil                                                **
** 	Return - QRS_Heart_Rate                                          **
**-------------------------------------------------------------------*/

Uint32 QRS_Get_Heart_Rate( )
{
	return ( QRS_Heart_Rate ) ;
}

static void QRS_check_sample_crossing_threshold( float scaled_result )
{
	/* array to hold the sample indexes S1,S2,S3 etc */
	extern Uint16 LeadOffStatus;
	
	static Uint16 s_array_index = 0 ;
	static Uint32 maximum_index[MAX_PEAK_TO_SEARCH] ;
	static Uint16 m_array_index = 0 ;
	
	static Uint8 threshold_crossed = FALSE ;
	static Uint16 maxima_search = 0 ;
	static Uint8 peak_detected = FALSE ;
	static Uint16 skip_window = 0 ;
	static double maxima_sum = 0 ;
	static Uint32 peak = 0;
	float Average_RR = 0;
	static Uint32 sample_sum = 0;
	static Uint32 nopeak=0;
	Uint32 max = 0 ;

	extern Uint16 HR_flag;
	extern Uint16 Initial_HR_Flag;

	if( TRUE == threshold_crossed )
	{
		/*
		Once the sample value crosses the threshold check for the
		maxima value till MAXIMA_SEARCH_WINDOW samples are received
		*/
		sample_count ++ ;
		maxima_search ++ ;

		if( scaled_result > peak )
		{
			peak = scaled_result ;
		}

		if( maxima_search >= MAXIMA_SEARCH_WINDOW )
		{
			// Store the maxima values for each peak
			maximum_index[ m_array_index ++ ] = peak ;
			maxima_sum += peak ;
			maxima_search = 0 ;

			threshold_crossed = FALSE ;
			peak_detected = TRUE ;
		}

	}
	else if( TRUE == peak_detected )
	{
		/*
		Once the sample value goes below the threshold
		skip the samples untill the SKIP WINDOW criteria is meet
		*/
		sample_count ++ ;
		skip_window ++ ;

		if( skip_window >= MINIMUM_SKIP_WINDOW )
		{
			skip_window = 0 ;
			peak_detected = FALSE ;
		}

		if( m_array_index == MAX_PEAK_TO_SEARCH )
		{
			
			Average_RR =  ( (float) sample_sum / (MAX_PEAK_TO_SEARCH - 1) ) ;

			if(((LeadOffStatus & 0x0007)== 0x0007)||((LeadOffStatus & 0x01FF)== ELECTRODE_LA))
			{
				QRS_Heart_Rate = ( 60 *  SAMPLING_RATE ) / (float)(Average_RR) ;
				if(QRS_Heart_Rate > 250)
					QRS_Heart_Rate = 250 ;
			}
			else
			{
				QRS_Heart_Rate = 0;
			}


			/* Setting the Current HR value in the ECG_Info structure*/
			ECG_Info.ECG_HeartRate = QRS_Heart_Rate;
			HR_flag = 1;
			Initial_HR_Flag = 1;

			max = ((float) maxima_sum / MAX_PEAK_TO_SEARCH ) ;

			/*  calculating the new QRS_Threshold based on the maxima obtained in 4 peaks */
			
			QRS_Threshold_New = (float)( QRS_THRESHOLD_FRACTION * max );

			/* Limiting the QRS Threshold to be in the permissible range*/
			if(QRS_Threshold_New > (4.0 * QRS_Threshold_Old))
			{
				QRS_Threshold_New = QRS_Threshold_Old;
	 		}

	 		sample_count = 0 ;
	 		s_array_index = 0 ;
	 		m_array_index = 0 ;
	 		maxima_sum = 0 ;
			sample_index[0] = 0 ;
			sample_index[1] = 0 ;
			sample_index[2] = 0 ;
			sample_index[3] = 0 ;
			Start_Sample_Count_Flag = 0;
			peak_detected = FALSE ;
			sample_sum = 0;
		}
	}
	else if( scaled_result > QRS_Threshold_New )
	{
		/*
			If the sample value crosses the threshold then store the sample index
		*/
		Start_Sample_Count_Flag = 1;
		sample_count ++ ;
		threshold_crossed = TRUE ;
		peak = scaled_result ;
		nopeak = 0;

		/*	storing sample index*/
	   	sample_index[ s_array_index ] = sample_count ;
		if( s_array_index >= 1 )
		{
			sample_sum += sample_index[ s_array_index ] - sample_index[ s_array_index - 1 ] ;
		}
		s_array_index ++ ;
	}

	else if(( scaled_result < QRS_Threshold_New ) && (Start_Sample_Count_Flag == 1))
	{
		sample_count ++ ;
        nopeak++;	
        if (nopeak > (3 * SAMPLING_RATE))
        { 
        	sample_count = 0 ;
	 		s_array_index = 0 ;
	 		m_array_index = 0 ;
	 		maxima_sum = 0 ;
			sample_index[0] = 0 ;
			sample_index[1] = 0 ;
			sample_index[2] = 0 ;
			sample_index[3] = 0 ;
			Start_Sample_Count_Flag = 0;
			peak_detected = FALSE ;
			sample_sum = 0;
        	    	
        	first_peak_detect = FALSE;
	      	nopeak=0;

			QRS_Heart_Rate = 0;
			ECG_Info.ECG_HeartRate = QRS_Heart_Rate;
			HR_flag = 1;
			Initial_HR_Flag = 1;

        }
	}

   else
   {
    nopeak++;	
   	if (nopeak > (3 * SAMPLING_RATE))
     { 
     	sample_count = 0 ;
	 		s_array_index = 0 ;
	 		m_array_index = 0 ;
	 		maxima_sum = 0 ;
			sample_index[0] = 0 ;
			sample_index[1] = 0 ;
			sample_index[2] = 0 ;
			sample_index[3] = 0 ;
			Start_Sample_Count_Flag = 0;
			peak_detected = FALSE ;
			sample_sum = 0;
     	
     	first_peak_detect = FALSE;
	 	nopeak = 0;
		QRS_Heart_Rate = 0;
		ECG_Info.ECG_HeartRate = QRS_Heart_Rate;
		HR_flag = 1;
		Initial_HR_Flag = 1;

     }
   }

}
