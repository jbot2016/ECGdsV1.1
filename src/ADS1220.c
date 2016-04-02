////jb botched it
////******************************************************************************
//// ADS1220 Demo C Function Calls  
////                    
////
//// Description: Use of the MSP430F5528 USCI A0 peripheral for setting up and 
////    communicating to the ADS1220 24-bit ADC.
////    
////    
////                                                   
////                 MSP430x552x
////             ------------------                        
////         /|\|                  |                       
////          | |                  |                       
////          --|RST           P3.4|<-- MISO (DOUT)           
////            |                  |                                         
////            |              P3.3|--> MOSI (DIN)
////            |                  |  
////            |              P2.7|--> SCLK
////            |                  | 
////            |              P2.6|<-- INT (DRDY) 
////            |                  | 
////            |              P1.2|--> CS 
////
////   R. Benjamin
////   Texas Instruments Inc.
////   January 2014
////   
////******************************************************************************
//#include "ADS1220.h"
//#include "csl_spi.h"
//#include "csl_general.h"
//#include "cslr_spi_001.h"
//#include "corazon.h"
//#include "stdio.h"
///* This is MSP430 Code */
//extern Uint16 spiWriteBuff;
//extern Uint16 spiReadBuff;
//#define	CSL_SPI_BUF_LEN			(1)//(64)
//#define CSL_TEST_FAILED         (1)
//#define CSL_TEST_PASSED         (0)
////void ADS1220Init(void)
////{
////     
////	P3SEL |= ADS1220_DIN + ADS1220_DOUT ;
////	P2SEL |= ADS1220_SCLK;
////	P2SEL &= ~(ADS1220_DRDY | ADS1220_CS); 
////	 
////	// define initial states
////	P1OUT |=  (ADS1220_CS); 					// CS is really 'not' CS, so it should be disabled high
////	
////	// define inputs
////	P2DIR &= ~(ADS1220_DRDY);					// DRDY is an input to the micro
////	P2IES |= ADS1220_DRDY;						// and should be used as an interrupt to retrieve data
////	// define outputs
////	P1DIR |= ADS1220_CS;
////   
////   return;
////}
//
//// ADS1220 Initial Configuration
//void ADS1220Config(void)
//{
//	Uint16 Temp;
//	
//	ADS1220ReadRegister(ADS1220_0_REGISTER, 0x01, &Temp);
//   
//	// clear prev value;
//   	Temp &= 0x0f;
//   	Temp |= (ADS1220_MUX_1_G + ADS1220_PGA_BYPASS);
//   
//   	// write the register value containing the new value back to the ADS
//   	ADS1220WriteRegister(ADS1220_0_REGISTER, 0x01, &Temp);
//   
//	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
//   
//	// clear prev DataRate code;
//	Temp &= 0x1f;
//	Temp |= (ADS1220_DR_1000 + ADS1220_CC + ADS1220_MODE_DUTY);		// Set default start mode to 600sps and continuous conversions
//   
//	// write the register value containing the new value back to the ADS
//	ADS1220WriteRegister(ADS1220_1_REGISTER, 0x01, &Temp);
//	
//	//jb add
//	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
//   
//	// clear prev DataRate code;
//	Temp &= 0x1f;
//	Temp |= (ADS1220_VREF_SUPPLY + ADS1220_REJECT_60);		// Set default start mode to 600sps and continuous conversions
//   
//	// write the register value containing the new value back to the ADS
//	ADS1220WriteRegister(ADS1220_2_REGISTER, 0x01, &Temp);
//	
//	ADS1220ReadRegister(ADS1220_3_REGISTER, 0x01, &Temp);
//   
//	// clear prev DataRate code;
//	Temp &= 0x1f;
//	Temp |= (ADS1220_DRDY_MODE);		// Set default start mode to 600sps and continuous conversions
//   
//	// write the register value containing the new value back to the ADS
//	ADS1220WriteRegister(ADS1220_3_REGISTER, 0x01, &Temp);
//	
//}
/////*  Polling Function */
////int ADS1220WaitForDataReady(int Timeout)
////{
////   if (Timeout > 0)
////   {
////      // wait for /DRDY = 1
////      while (!(P2IN & ADS1220_DRDY) && (Timeout-- >= 0))
////         ;
////      // wait for /DRDY = 0
////      while ( (P2IN & ADS1220_DRDY) && (Timeout-- >= 0))
////         ;
////      if (Timeout < 0)
////         return 0; //ADS1220_TIMEOUT_WARNING;
////   }
////   else
////   {
////      // wait for /DRDY = 1
////      while (!(P2IN & ADS1220_DRDY))
////         ;
////      // wait for /DRDY = 0
////      while ( (P2IN & ADS1220_DRDY))
////         ;
////   }
////   return ADS1220_NO_ERROR;
////}
//
//CSL_SpiHandle ADS1220AssertCS( int fAssert)
//{
// 	CSL_Status	result;
//	CSL_SpiHandle	hSpi;  
//   if (fAssert){
//		//P1OUT &=  ~(ADS1220_CS);
//		hSpi = SPI_open(SPI_CS_NUM_1, SPI_POLLING_MODE);
//		return hSpi; 
//   }
//   else{
//		//P1OUT |=  (ADS1220_CS); 
//      result = SPI_close(hSpi);
//      return;
//   }
//}
//
//void ADS1220SendByte(Uint16 Byte, CSL_SpiHandle hSpi)
//{	Uint16 dummy;
//	Int16 			status = CSL_TEST_PASSED;
//	Int16 			result;
//	//while(!(UCA0IFG&UCTXIFG));
//	spiWriteBuff[0] = Byte;//UCA0TXBUF = Byte;		
//	result = SPI_dataTransaction(hSpi ,spiWriteBuff, CSL_SPI_BUF_LEN, SPI_WRITE);
//	if(CSL_SOK != result)
//	{
//		printf("CSL_TEST_FAILED\n");
//	}
//	else
//	{
//		printf ("SPI Instance Write successfully\n");
//	}
//	//while(!(UCA0IFG&UCRXIFG));
//	/* Read the Data to the SPI*/
//	result = SPI_dataTransaction(hSpi ,spiReadBuff, CSL_SPI_BUF_LEN, SPI_READ);
//	if(CSL_SOK != result)
//	{
//		printf("CSL_TEST_FAILED\n");
//	}
//	else
//	{
//		printf ("SPI Instance Read successfully\n");
//	}
//	dummy = spiReadBuff[0]; //UCA0RXBUF;			
//   
//}
//
//Uint16 ADS1220ReceiveByte(CSL_SpiHandle hSpi)
//{
//    Uint16 Result = 0;
//    Int16 			status = CSL_TEST_PASSED;
//	Int16 			result;
//	//CSL_SpiHandle	hSpi;
//	//while(!(UCA0IFG&UCTXIFG));	// Make sure nothing is currently transmitting
//	
//	spiWriteBuff[0] = 0xff; //UCA0TXBUF = 0xff;		 	// Send out NOP to initiate SCLK
//	//while(!(UCA0IFG&UCRXIFG));	// Wait until all data is transmitted (received)
//	/* Read the Data to the SPI*/
//	result = SPI_dataTransaction(hSpi ,spiReadBuff, CSL_SPI_BUF_LEN, SPI_READ);
//	if(CSL_SOK != result)
//	{
//		return (CSL_TEST_FAILED);
//	}
//	else
//	{
//		printf ("SPI Instance Read successfully\n");
//	}
//	Result = spiReadBuff[0]; //UCA0RXBUF;	// Capture the receive buffer 
//		
//	return Result;
//}
/////*
////******************************************************************************
//// higher level functions
////*/
//long ADS1220ReadData(void)
//{
//   long Data;
//   CSL_SpiHandle hSpi;
//      
//   // assert CS to start transfer
//   hSpi = ADS1220AssertCS(1);
//
//   // send the command byte
//   ADS1220SendByte(ADS1220_CMD_RDATA, hSpi);
//   //spi_dataTransaction(   
//   // get the conversion result
//#ifdef ADS1120
//   Data = ADS1220ReceiveByte(hSpi);
//   Data = (Data << 8) | ADS1220ReceiveByte(hSpi);
//   //Data = (Data << 8) | ADS1220ReceiveByte(hSpi);
//
//   // sign extend data
//   if (Data & 0x8000)
//      Data |= 0xffff0000;
//#else
//   Data = ADS1220ReceiveByte(hSpi);
//   Data = (Data << 8) | ADS1220ReceiveByte(hSpi);
//   Data = (Data << 8) | ADS1220ReceiveByte(hSpi);
//
//   // sign extend data
//   if (Data & 0x800000)
//      Data |= 0xff000000;
//   
//#endif
//   // de-assert CS
//   hSpi = ADS1220AssertCS(0);
//   return Data;
//}
//
//void ADS1220ReadRegister(int StartAddress, int NumRegs, Uint16 * pData)
//{
//   int i;
//	CSL_SpiHandle hSpi;	
//	// assert CS to start transfer
//	hSpi = ADS1220AssertCS(1);
//   
//	// send the command byte
//	ADS1220SendByte((ADS1220_CMD_RREG | (((StartAddress<<2) & 0x0c) |((NumRegs-1)&0x03))), hSpi);
//   
//	// get the register content
//	for (i=0; i< NumRegs; i++)
//	{
//		*pData++ = ADS1220ReceiveByte(hSpi);
//	}
//   
//	// de-assert CS
//	hSpi = ADS1220AssertCS(0);
//	
//	return;
//}
//
//void ADS1220WriteRegister(int StartAddress, int NumRegs, Uint16 *pData)
//{
//	int i;
//   CSL_SpiHandle hSpi;
//	// assert CS to start transfer
//	hSpi = ADS1220AssertCS(1);
//   
//	// send the command byte
//	ADS1220SendByte((ADS1220_CMD_WREG | (((StartAddress<<2) & 0x0c) |((NumRegs-1)&0x03))), hSpi);
//   
//    // send the data bytes
//	for (i=0; i< NumRegs; i++)
//	{
//		ADS1220SendByte(*pData++, hSpi);
//	}
//   
//	// de-assert CS
//	hSpi = ADS1220AssertCS(0);
//   
//	return;
//}
//
//void ADS1220SendResetCommand(void)
//{
//	CSL_SpiHandle hSpi;
//	// assert CS to start transfer
//	hSpi = ADS1220AssertCS(1);
//   
//	// send the command byte
//	ADS1220SendByte(ADS1220_CMD_RESET, hSpi);
//   
//	// de-assert CS
//	hSpi = ADS1220AssertCS(0);
//   
//	return;
//}
//
//void ADS1220SendStartCommand(void)
//{
//	CSL_SpiHandle hSpi;
//	// assert CS to start transfer
//	hSpi = ADS1220AssertCS(1);
//   
//	// send the command byte
//	ADS1220SendByte(ADS1220_CMD_SYNC, hSpi);
//   
//	// de-assert CS
//	hSpi = ADS1220AssertCS(0);
//     
//	return;
//}
//
//void ADS1220SendShutdownCommand(void)
//{
//	CSL_SpiHandle hSpi;
//	// assert CS to start transfer
//	hSpi = ADS1220AssertCS(1);
//   
//	// send the command byte
//	ADS1220SendByte(ADS1220_CMD_SHUTDOWN, hSpi);
//   
//	// de-assert CS
//	hSpi = ADS1220AssertCS(0);
//     
//	return;
//}
//
/////*
////******************************************************************************
////register set value commands
////*/
////
////int ADS1220SetChannel(int Mux)
////{
////	unsigned int cMux = Mux;	   
////   // write the register value containing the new value back to the ADS
////   ADS1220WriteRegister(ADS1220_0_REGISTER, 0x01, &cMux);
////   
////   return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetGain(int Gain)
////{
////	unsigned int cGain = Gain;   
////	// write the register value containing the new code back to the ADS
////	ADS1220WriteRegister(ADS1220_0_REGISTER, 0x01, &cGain);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetPGABypass(int Bypass)
////{
////	unsigned int cBypass = Bypass;
////	// write the register value containing the new code back to the ADS
////	ADS1220WriteRegister(ADS1220_0_REGISTER, 0x01, &cBypass);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetDataRate(int DataRate)
////{
////	unsigned int cDataRate = DataRate;  
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_1_REGISTER, 0x01, &cDataRate);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetClockMode(int ClockMode)
////{
////	unsigned int cClockMode = ClockMode;
////   
////	// write the register value containing the value back to the ADS
////	ADS1220WriteRegister(ADS1220_1_REGISTER, 0x01, &cClockMode);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetPowerDown(int PowerDown)
////{
////	unsigned int cPowerDown = PowerDown;
////   
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_1_REGISTER, 0x01, &cPowerDown);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetTemperatureMode(int TempMode)
////{
////	unsigned int cTempMode = TempMode;
////   
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_1_REGISTER, 0x01, &cTempMode);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetBurnOutSource(int BurnOut)
////{
////	unsigned int cBurnOut = BurnOut;
////   
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_1_REGISTER, 0x01, &cBurnOut);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetVoltageReference(int VoltageRef)
////{
////	unsigned int cVoltageRef = VoltageRef;
////   
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_2_REGISTER, 0x01, &cVoltageRef);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220Set50_60Rejection(int Rejection)
////{
////	unsigned int cRejection = Rejection;
////   
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_2_REGISTER, 0x01, &cRejection);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetLowSidePowerSwitch(int PowerSwitch)
////{
////	unsigned int cPowerSwitch = PowerSwitch;
////   
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_2_REGISTER, 0x01, &cPowerSwitch);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetCurrentDACOutput(int CurrentOutput)
////{
////	unsigned int cCurrentOutput = CurrentOutput;
////   
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_2_REGISTER, 0x01, &cCurrentOutput);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetIDACRouting(int IDACRoute)
////{
////	unsigned int cIDACRoute = IDACRoute;
////	
////	// write the register value containing the new value back to the ADS
////	ADS1220WriteRegister(ADS1220_3_REGISTER, 0x01, &cIDACRoute);
////	
////	return ADS1220_NO_ERROR;
////}
////
////int ADS1220SetDRDYMode(int DRDYMode)
////{
////	unsigned int cDRDYMode = DRDYMode;
////   
////	// write the register value containing the new gain code back to the ADS
////	ADS1220WriteRegister(ADS1220_3_REGISTER, 0x01, &cDRDYMode);
////	
////	return ADS1220_NO_ERROR;
////}
////
/////*
////******************************************************************************
////register get value commands
////*/
////
////int ADS1220GetChannel(void)
////{
////	unsigned Temp;
////	
////	//Parse Mux data from register
////	ADS1220ReadRegister(ADS1220_0_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return (Temp >>4);
////}
////
////int ADS1220GetGain(void)
////{
////	unsigned Temp;
////	
////	//Parse Gain data from register
////	ADS1220ReadRegister(ADS1220_0_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( (Temp & 0x0e) >>1);
////}
////
////int ADS1220GetPGABypass(void)
////{
////	unsigned Temp;
////	
////	//Parse Bypass data from register
////	ADS1220ReadRegister(ADS1220_0_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return (Temp & 0x01);
////}
////
//int ADS1220GetDataRate(void)
//{
//	unsigned Temp;
//	
//	//Parse DataRate data from register
//	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
//	
//	// return the parsed data
//	return ( Temp >>5 );
//}
//
////int ADS1220GetClockMode(void)
////{
////	unsigned Temp;
////	
////	//Parse ClockMode data from register
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( (Temp & 0x18) >>3 );
////}
////
////int ADS1220GetPowerDown(void)
////{
////	unsigned Temp;
////	
////	//Parse PowerDown data from register
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( (Temp & 0x04) >>2 );
////}
////
////int ADS1220GetTemperatureMode(void)
////{
////	unsigned Temp;
////	
////	//Parse TempMode data from register
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( (Temp & 0x02) >>1 );
////}
////
////int ADS1220GetBurnOutSource(void)
////{
////	unsigned Temp;
////	
////	//Parse BurnOut data from register
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( Temp & 0x01 );
////}
////
////int ADS1220GetVoltageReference(void)
////{
////	unsigned Temp;
////	
////	//Parse VoltageRef data from register
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( Temp >>6 );
////}
////
////int ADS1220Get50_60Rejection(void)
////{
////	unsigned Temp;
////	
////	//Parse Rejection data from register
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( (Temp & 0x30) >>4 );
////}
//
////int ADS1220GetLowSidePowerSwitch(void)
////{
////	unsigned Temp;
////	
////	//Parse PowerSwitch data from register
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( (Temp & 0x08) >>3);
////}
////
////int ADS1220GetCurrentDACOutput(void)
////{
////	unsigned Temp;
////	
////	//Parse IDACOutput data from register
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( Temp & 0x07 );
////}
////
////int ADS1220GetIDACRouting(int WhichOne)
////{
////	unsigned Temp;
////	// Check WhichOne sizing
////	if (WhichOne >1) return ADS1220_ERROR;
////	
////	
////	
////	//Parse Mux data from register
////	ADS1220ReadRegister(ADS1220_3_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	if (WhichOne) return ( (Temp & 0x1c) >>2);
////	
////	else return ( Temp >>5 );
////	
////}
//
////int ADS1220GetDRDYMode(void)
////{
////	unsigned Temp;
////	
////	//Parse DRDYMode data from register
////	ADS1220ReadRegister(ADS1220_3_REGISTER, 0x01, &Temp);
////	
////	// return the parsed data
////	return ( (Temp & 0x02) >>1 );
////}
//
/////* Useful Functions within Main Program for Setting Register Contents
////*
////*  	These functions show the programming flow based on the header definitions.
////*  	The calls are not made within the demo example, but could easily be used by calling the function
////*  		defined within the program to complete a fully useful program.
////*	Similar function calls were made in the firwmare design for the ADS1220EVM.
////*  
////*  The following function calls use ASCII data sent from a COM port to control settings 
////*	on the ADS1220.  The data is recontructed from ASCII and then combined with the
////*	register contents to save as new configuration settings.
////*
////* 	Function names correspond to datasheet register definitions
////*/
////void set_MUX(char c)
////{
////	int mux = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	if (mux>=49 && mux<=54) mux -= 39;
////	
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_0_REGISTER, 0x01, &Temp);
////
////	Temp &= 0x0f;									// strip out old settings
////	// Change Data rate
////	switch(mux) {
////		case 0:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_0_1);
////			break;
////		case 1:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_0_2);
////			break;
////		case 2:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_0_3);
////			break;
////		case 3:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_1_2);
////			break;
////		case 4:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_1_3);
////			break;
////		case 5:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_2_3);
////			break;
////		case 6:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_1_0);
////			break;
////		case 7:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_3_2);
////			break;
////		case 8:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_0_G);
////			break;
////		case 9:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_1_G);
////			break;
////		case 10:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_2_G);
////			break;
////		case 11:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_3_G);
////			break;
////		case 12:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_EX_VREF);
////			break;
////		case 13:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_AVDD);
////			break;
////		case 14:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_DIV2);
////			break;
////		case 15:
////			dERROR = ADS1220SetChannel(Temp + ADS1220_MUX_DIV2);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;												
////	}
////	
////	if (dERROR==ADS1220_ERROR)
////		set_ERROR();
////	
////}
////
////void set_GAIN(char c)
////{
////	int pga = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_0_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xf1;									// strip out old settings
////	// Change gain rate
////	switch(pga) {
////		case 0:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_1);
////			break;
////		case 1:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_2);
////			break;
////		case 2:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_4);
////			break;
////		case 3:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_8);
////			break;
////		case 4:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_16);
////			break;
////		case 5:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_32);
////			break;
////		case 6:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_64);
////			break;
////		case 7:
////			dERROR = ADS1220SetGain(Temp + ADS1220_GAIN_128);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;	
////		}
////											
////	
////	
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////}
////
////void set_PGA_BYPASS(char c)
////{
////	int buff = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_0_REGISTER, 0x01, &Temp);
////		
////	Temp &= 0xfe;									// strip out old settings
////	// Change PGA Bypass
////	switch(buff) {
////		case 0:
////			dERROR = ADS1220SetPGABypass(Temp);
////			break;
////		case 1:
////			dERROR = ADS1220SetPGABypass(Temp + ADS1220_PGA_BYPASS);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////	
////}
////
////void set_DR(char c)
////{
////	int spd = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0x1f;									// strip out old settings
////	// Change Data rate
////	switch(spd) {
////		case 0:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_20);
////			break;
////		case 1:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_45);
////			break;
////		case 2:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_90);
////			break;
////		case 3:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_175);
////			break;
////		case 4:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_330);
////			break;
////		case 5:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_600);
////			break;
////		case 6:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_1000);
////			break;
////		case 7:
////			dERROR = ADS1220SetDataRate(Temp + ADS1220_DR_1000);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////			
////}
////
////void set_MODE(char c)
////{
////	int spd = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xe7;									// strip out old settings
////	// Change Data rate
////	switch(spd) {
////		case 0:
////			dERROR = ADS1220SetClockMode(Temp + ADS1220_MODE_NORMAL);
////			break;
////		case 1:
////			dERROR = ADS1220SetClockMode(Temp + ADS1220_MODE_DUTY);
////			break;
////		case 2:
////			dERROR = ADS1220SetClockMode(Temp + ADS1220_MODE_TURBO);
////			break;
////		case 3:
////			dERROR = ADS1220SetClockMode(Temp + ADS1220_MODE_DCT);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////		}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////
////}
////
////void set_CM(char c)
////{
////	int pwrdn = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xfb;									// strip out old settings
////	// Change power down mode
////	switch(pwrdn) {
////		case 0:
////			dERROR = ADS1220SetPowerDown(Temp);
////			break;
////		case 1:
////			dERROR = ADS1220SetPowerDown(Temp + ADS1220_CC);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////	
////}
////
////void set_TS(char c)
////{
////	int tmp = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xfd;									// strip out old settings
////	// Change Temp Diode Setting
////	switch(tmp) {
////		case 0:
////			dERROR = ADS1220SetTemperatureMode(Temp);
////			break;
////		case 1:
////			dERROR = ADS1220SetTemperatureMode(Temp + ADS1220_TEMP_SENSOR);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////	
////}
////
////void set_BCS(char c)
////{
////	int bo = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_1_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xfe;									// strip out old settings
////	// Change PGA Bypass
////	switch(bo) {
////		case 0:
////			dERROR = ADS1220SetBurnOutSource(Temp);
////			break;
////		case 1:
////			dERROR = ADS1220SetBurnOutSource(Temp + ADS1220_BCS);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////	
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////		
////}
////
////void set_VREF(char c)
////{
////	int ref = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0x3f;									// strip out old settings
////	// Change Reference
////	switch(ref) {
////		case 0:
////			dERROR = ADS1220SetVoltageReference(Temp + ADS1220_VREF_INT);
////			break;
////		case 1:
////			dERROR = ADS1220SetVoltageReference(Temp + ADS1220_VREF_EX_DED);
////			break;
////		case 2:
////			dERROR = ADS1220SetVoltageReference(Temp + ADS1220_VREF_EX_AIN);
////			break;
////		case 3:
////			dERROR = ADS1220SetVoltageReference(Temp + ADS1220_VREF_SUPPLY);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////		
////}
////void set_50_60(char c)
////{
////	int flt = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////	
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xcf;									// strip out old settings
////	// Change Filter
////	switch(flt) {
////		case 0:
////			dERROR = ADS1220Set50_60Rejection(Temp + ADS1220_REJECT_OFF);
////			break;
////		case 1:
////			dERROR = ADS1220Set50_60Rejection(Temp + ADS1220_REJECT_BOTH);
////			break;
////		case 2:
////			dERROR = ADS1220Set50_60Rejection(Temp + ADS1220_REJECT_50);
////			break;
////		case 3:
////			dERROR = ADS1220Set50_60Rejection(Temp + ADS1220_REJECT_60);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////		
////}
////
////void set_PSW(char c)
////{
////	int sw = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xf7;									// strip out old settings
////		// Change power down mode
////	switch(sw) {
////		case 0:
////			dERROR = ADS1220SetLowSidePowerSwitch(Temp);
////			break;
////		case 1:
////			dERROR = ADS1220SetLowSidePowerSwitch(Temp + ADS1220_PSW_SW);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////	
////}
////
////void set_IDAC(char c)
////{
////	int current = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_2_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xf8;									// strip out old settings
////	// Change IDAC Current Output
////	switch(current) {
////		case 0:
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_OFF);
////			break;
////		case 1:
////		  #ifdef ADS1120
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_OFF);
////		  #else
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_10);
////		  #endif
////
////			break;
////		case 2:
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_50);
////			break;
////		case 3:
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_100);
////			break;
////		case 4:
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_250);
////			break;
////		case 5:
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_500);
////			break;
////		case 6:
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_1000);
////			break;
////		case 7:
////			dERROR = ADS1220SetCurrentDACOutput(Temp + ADS1220_IDAC_2000);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////		
////		}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////	
////}
////
////void set_IMUX(char c, int i)
////{
////	int mux = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_3_REGISTER, 0x01, &Temp);
////	
////	if (i==1) {
////		Temp &= 0xe3;									// strip out old settings
////		
////		// Change IDAC2 MUX Output
////	
////		switch(mux) {
////			case 0:
////				Temp |= ADS1220_IDAC2_OFF;
////				break;
////			case 1:
////				Temp |= ADS1220_IDAC2_AIN0;
////				break;
////			case 2:
////				Temp |= ADS1220_IDAC2_AIN1;
////				break;
////			case 3:
////				Temp |= ADS1220_IDAC2_AIN2;
////				break;
////			case 4:
////				Temp |= ADS1220_IDAC2_AIN3;
////				break;
////			case 5:
////				Temp |= ADS1220_IDAC2_REFP0;
////				break;
////			case 6:
////				Temp |= ADS1220_IDAC2_REFN0;
////				break;
////			case 7:
////				Temp |= ADS1220_IDAC2_REFN0;
////				break;
////			default:
////				dERROR = ADS1220_ERROR;
////				break;
////		
////		}
////	}
////	else {
////		Temp &= 0x1f;
////		// Change IDAC1 MUX Output
////		switch(mux) {
////			case 0:
////				Temp |= ADS1220_IDAC1_OFF;
////				break;
////			case 1:
////				Temp |= ADS1220_IDAC1_AIN0;
////				break;
////			case 2:
////				Temp |= ADS1220_IDAC1_AIN1;
////				break;
////			case 3:
////				Temp |= ADS1220_IDAC1_AIN2;
////				break;
////			case 4:
////				Temp |= ADS1220_IDAC1_AIN3;
////				break;
////			case 5:
////				Temp |= ADS1220_IDAC1_REFP0;
////				break;
////			case 6:
////				Temp |= ADS1220_IDAC1_REFN0;
////				break;
////			case 7:
////				Temp |= ADS1220_IDAC1_REFN0;
////				break;
////			default:
////				dERROR = ADS1220_ERROR;
////				break;
////		}
////	}
////	
////	if (dERROR==ADS1220_NO_ERROR) 
////		dERROR = ADS1220SetIDACRouting(Temp); 
////	
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////	
////}
////
////void set_DRDYM(char c)
////{
////	int drdy = (int) c - 48;
////	int dERROR;
////	unsigned Temp;
////		
////	// the DataRate value is only part of the register, so we have to read it back
////	// and massage the new value into it
////	ADS1220ReadRegister(ADS1220_3_REGISTER, 0x01, &Temp);
////	
////	Temp &= 0xfd;									// strip out old settings
////	// Change DRDY Mode Setting
////	switch(drdy) {
////		case 0:
////			dERROR = ADS1220SetDRDYMode(Temp);
////			break;
////		case 1:
////			dERROR = ADS1220SetDRDYMode(Temp + ADS1220_DRDY_MODE);
////			break;
////		default:
////			dERROR = ADS1220_ERROR;
////			break;
////	
////	}
////								
////	if (dERROR==ADS1220_ERROR) 
////		set_ERROR();
////	
////}
////
////void set_ERROR(void)
////{
////	/* Add some error routine here is desired */
////}
////
