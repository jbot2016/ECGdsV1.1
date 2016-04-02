#ifndef ECGNONBIOS_H_
#define ECGNONBIOS_H_

#include "stdio.h"
#include "file.h"
#include "stdio.h"
#include "math.h"
#include "psp_common.h" //need to add jb
#include "cpu_clock_init.h" //need to add jb
#include "dda_spi.h" //need to add jb
#include "llc_spi.h" //need to add jb
#include "csl_ioport.h" //need to add jb
#include "corazon.h" //need to add jb
#include "cslr.h"
#include "ECGGlobals.h" //need to add jb
#include "ADS1258.h" //need to add jb
#include "typedef.h" //need to add
#include "timer.h" //need to add jb
#include "psp_uart.h" //need to add jb
#include "dda_uart.h" //need to add jb

//
///* Function to toggle GPIO according to channel*/
//void ECG_ToggleGPIO(Uint8);
///* function to process samples for 1 sec*/	
ECG_Status ECG_System();	
///* function to read channel data*/	 		
//extern void ADS1258_Read_ChannelData(Uint8*,Uint8*);
extern void ADS1258_Read_ChannelData(Uint16*,Uint16*);
///* convert the 4 byte channel data to 24bit sample*/
//extern Int32 ECG_GetCurrAqsnSample(Uint8*);
extern Int32 ECG_GetCurrAqsnSample(Uint16*); //jb
///* process the current sample*/
extern void ECG_ProcessCurrSample(Uint32,Uint8,Uint32, Uint32);
///* function which is called by the main thread at filling of every(N/3) */
///* samples in Lead_Info_Buffer                                          */
extern void QRS_Algorithm_Interface(Uint32);
///* plot the current sample in LCD*/ //not needed
//extern void ECG_LCDPlotCurrSample(Uint32,Uint32);
///* Send the LeadInfo thru UART to plot in the PC Application*/
extern void ECG_UARTTxCurrSamples(Uint32,Uint32);
///*Function to display the HR Rate on LCD*/ //not needed
void ECG_LCD_HRDisplay(void);
///*Function to display the Lead Off status on LCD*/ //not needed
//void ECG_LCD_LeadOffDisplay(void);
///* function to initialize peripherals*/
extern ECG_Status ECG_C5505Init();	
///* function to display LCD startup screen*/
//extern void ECG_DisplayLCDStartUpScreen(); //jb
///* function to Initialize the timer*/
extern void ECG_TIMER_INIT();


#endif /*ECGNONBIOS_H_*/
