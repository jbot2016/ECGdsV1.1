//main for ECG DSP system
#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_led.h" //jb
#include "ECGNonBios.h"
#include "oledDisplay.h"
/*Define global variables*/


/*Acquisition buffer used to store the values read from ADS1258 ADC*/
//Int32 AqsnBuff[AQSNBUFFSIZE] = {0};
Int16 AqsnBuff[AQSNBUFFSIZE] = {0}; //jb
/* Flag which is getting set once the acquisition for all the channels is */
/* done for 1 sec                                                         */ 		 
Uint8 AqsnBuffFullInt;
/* varaible to store the current acquisition channel */
//Uint8 CurrAqsnChan;
Uint16 CurrAqsnChan; //jb
/* array to store the last one acquisition sample for all channels  */
extern Int32 PrevAqsnVal[];//jb dbl check this
/* LeadInfo Buffer*/
ECG_Lead_Info Lead_Info;
/* System Information structure*/								
ECG_System_Info ECG_Info;			
/* Leadoffstatus variable*/
Uint16 LeadOffStatus = 0x01FF;	

extern Uint8 FE_Active;
Uint32 Count =0;

/* Handle for UART driver*/
extern PSP_Handle hUart;
/* structure which stores the UART configuration values*/
extern PSP_UartConfig uartCfg;	
Uint16 Initial_HR_Flag = 0;
Uint16 HR_flag = 0;
Uint16 LeadOff_Flag = 0;
Uint16 HR_display_count = 1;	
Uint16 lead_digit_count = 0;
static Uint8 digit1,digit2,digit3;

/*-------------------------------------------------------------------------**
**    Function name : ECG_System()                                         **
**    Description : The main function does the following:-                 **
**                                                                         **
**                     - Call the ADS Read Channel data for one channel    **
**                                                                         **
**                     - Call the fuction to make it to current sample of  **
**                     24 bit                                              **
**                                                                         **
**                     - Call the Process function for the current sample  **
**                                                                         **
**                     - Store it in the LeadInfo buffer                   **
**                                                                         **
**                     - Call the QRS Algorithm                            **
**                                                                         **
**                     - Call the LCD plot function for the current sample **
**                                                                         **
**                 All the above tasks will be done for 1 sec of samples   **
**                 for 2 channels with a sample rate of 173 SPS            **
**                                                                         **
**     Parameters  : None                                                  **
** 	  Return	   : ECG system status                                     **
**-------------------------------------------------------------------------*/

ECG_Status ECG_System()
{
     
      /* Declare all the variables used in the function*/
	ECG_Status Status = ECG_OK; /* Status Variable */
	/* Count variables used for Aquisition */
	static Uint16 CurrAqsnRow = 0,DecimatorCount = 1;
	/* pointer to the Current Aqsn channel */
	//Uint8 *CurrChannel; //jb only one channel, dbl check
	Uint16 *CurrChannel; //jb
	/* Array to hold Current Channel data */             
	//Uint8 ChannelData[4] = {0};
	Uint16 ChannelData[1] = {0}; //jb
	/* Count variables used for Filter  */ 
	static Uint32 CurrProcLead = 0,CurrLeadInfoRow = 0;
	/* variable to check the first time of execution*/ 
	static Uint8 FirstFlag = 0;
	/* Counter variable*/
	Uint32 Count1=0;
	/* Count used to check the no of times of execution of the function */  
	static Uint16 TimCount =0;

	
	/* Assign the address for Current Aqsn Channel pointer */
    CurrChannel = &CurrAqsnChan;
	
	/* The  loop does the aquisition, DC removal, Filtering and Display of one */
	/* sample at a time. The loop expires ones the aquisition counter reaches  */
	/* the AQSNBUFFSIZE                                                        */ 
    
    
	/* Get the current channel data from ADS1259 */
   // do 
    //{
		/* Channel data Read function */     
        ADS1258_Read_ChannelData(ChannelData,CurrChannel);
        //printf("debug jb ads1258\n");//jb
       	/* check the read data channel with expected channle of data */  
    //}while(*CurrChannel != (CurrProcLead));

	/* If ECG samples is going beyond 450 samples then decimation can */
	/* be performed. This is selected by the value of DECIMATOR. If   */
	/* DECIMATOR = 1 no decimation is performed.	                  */
       
	/* check if the decimator count reach
	es the decimate factor */
    if(DecimatorCount == DECIMATOR)
    {
        /* Clear the data to store the current aqsn data */
        AqsnBuff[CurrAqsnRow]= 0;

		/* Get the current channels 24 bit sample from the ADS1258 */
		/* channel data                                            */
		AqsnBuff[CurrAqsnRow] = ((ECG_GetCurrAqsnSample(ChannelData))/ 16);
    	
       	
       	/* Process the current sample so as to remove the DC and filter */
		/* the data                                                     */

       	ECG_ProcessCurrSample(CurrAqsnRow,FirstFlag,CurrProcLead,CurrLeadInfoRow);
#if 1		
		/*  Display the HR in LCD*/
		//ECG_LCD_HRDisplay();	
#endif
		/* Display Lead Off Status on LCD*/
#if 1		 
		 //if(LeadOff_Flag)
		 //jb not using lcd stuff ECG_LCD_LeadOffDisplay();	
#endif


		/* Start the QRS and LCD display only after 3 seconds */
		if(TimCount > 4) //causing problem
       	{
           
			/* QRS Algorithm is called for every (N/3) samples filled in */
			/* Lead_info Buffer where N- Filter Order	                 */

            if(((CurrLeadInfoRow+1) % (Int16)QRSCALLFACT) == 0)
            {
				/* Call QRS algorithm interface */
           	QRS_Algorithm_Interface(CurrLeadInfoRow) ;
            } 
            
            /* Tx the current sample through UART */
           ECG_UARTTxCurrSamples(CurrLeadInfoRow,CurrProcLead);  
#if 1          
           /* Plot the current processed sample in the LCD */
           //jb not plotting ECG_LCDPlotCurrSample(CurrLeadInfoRow,CurrProcLead);     
            
#endif

        
        }       
                    
	    /* reset the Filter count values on completing all the leads */        
	    if(CurrProcLead == MAXCHAN-1)       
	    {
	    	CurrProcLead = 0;
	        DecimatorCount = 1;
				
			CurrLeadInfoRow++;/* Else Increment the count*/
				
			/* reset the lead info buffer on completing the LEADINFOSIZE */
	        if(CurrLeadInfoRow == LEADINFOSIZE)
			{
	        	CurrLeadInfoRow = 0;

				/* increment the timer count if less than 5*/
				if(TimCount<10)
			    	TimCount++;
				else
					TimCount = 10;
			}
	            
	                
	     }
	     else
		 {
	     	CurrProcLead++;/* Else increment the count */
		 }

	    CurrAqsnRow++;/* increment the aqsn count*/   

	    }
	    else
	    {
	        DecimatorCount++;/* increment the decimator count*/
	    }

       
    if(CurrAqsnRow == AQSNBUFFSIZE)
    {
	    /* This loop will store the last processed sample of each channel 
	    to be used by the DC removal on next cycle*/

	    for(Count1 = MAXCHAN;Count1 > 0 ; Count1--)
	    PrevAqsnVal[MAXCHAN - Count1] = AqsnBuff[AQSNBUFFSIZE - Count1]; 
		
		/* Set to one after the first seconds execution*/
	    FirstFlag=1;
	    	          
		/* Set the current aquisition row to zero*/
		CurrAqsnRow = 0;

		 /* Clear the Aquisition Buffer */
		
		for(Count=0;Count<AQSNBUFFSIZE;Count++)
		AqsnBuff[Count] = 0;

    } 

    return Status;
}


void ECG_StartTimer0()
{
	/* Start the Timer 0*/
	*CPU_TIM0_CTRL = *CPU_TIM0_CTRL | 0x0001; 
}

/*-------------------------------------------------------------------------**
**     Function Name	: main()                                           **
**     Description 	: The main function does the following:-               **
**                                                                         **
**                     - Clears all the global buffers                     **
**                                                                         **
**                     - Call the C5505 Initialization function            **
**                                                                         **
**                     - Clear the LCD and display the startup screen      **
**                                                                         **
**                     - Call the ECG System function in an infinite while **
**                     loop                                                **
**                                                                         **
**  Parameters  : None	                                                   **
** 	Returns		: void                                                     **
**-------------------------------------------------------------------------*/
extern 	unsigned char UARTPacket[256];
extern 	int adcMain(); //jb just for testing
extern	unsigned char UARTstart;
extern	unsigned char UARTend;
extern	unsigned UARTdataRdy;

void main()
{
	ECG_Status Status; //jb initialized to 0 real beginning of code, same with other comment
	Int16 proc = 0; //counter for led to show successfully processing
	Int16 adcTest = 0; //jb adc testing flag
	EZDSP5535_init();
	EZDSP5535_LED_init();
    oledDisp(); //jb display header on lcd to show running program
	EZDSP5535_LED_setall(0x00); //turn on all status leds
	EZDSP5535_XF_on();
////jb real start of main
					
    //Uint8 UARTVal[1] = 0xA5;
	//PSP_Result retVal = 0;

	Status = ECG_OK; //jb set for debug only
	/* Call  Initialization function for the ECG system */
    Status = ECG_C5505Init(); //jb causing issue, expected
    if(Status != ECG_OK)
    {
		printf("ECG System Initialization FAIL\n"); //jb uncommented for debug
		EZDSP5535_LED_off(3); //blue led off means not working
		while(1);
	}
	else
	{
		//printf("ECG System Initialization PASS\n"); //jb for dbg
		EZDSP5535_LED_on(3); //blue led on means now working
	}
    
	EZDSP5535_wait(1000);

	/* Display the ECG startup screen in LCD */
    //ECG_DisplayLCDStartUpScreen(); //jb not using lcd currently

	/* Start the Timer0*/
	ECG_StartTimer0();
	//skip main processing to test adc, remove later jb
	if(adcTest){
		adcMain();
		//return;
	}
	//EZDSP5535_wait(1000);
	/* Infinite loop - the ECG processing will be done according to timer*/
	while(1)
	{
 			//printf("made it in while\n"); //jb delete after test
 			//ECG_System();
 			//break;
 			
 			//jb make new if statement for switch press to force break out of loop
 			//move led into if statement below in final implementation
 			proc++;
 			if(proc%25 == 0){
 				proc =0;
 				EZDSP5535_LED_toggle(2); //toggle orange led, consistent with processing led from wrist sensor	
 			}
 			if ( UARTdataRdy )
			{
//				while ( UARTstart != UARTend)
//				{
//					//jb wondering if necessary or not. causing issues
//					//jb dda_uartWrite(hUart,&UARTPacket[UARTend], 1, -1, &uartCfg);
//					UARTend++;
//					if ( UARTstart == UARTend)
//					{
//						UARTstart =	UARTend = 0;
//					}
//
//				}
				//printf("made it in if\n"); //jb delete after test	
				UARTdataRdy = 0;
				
				//printf("made it after system\n"); //jb delete after test			
			}
			ECG_System();
	}
	return;
}


void ECG_LCD_HRDisplay(void)	
{

	extern Uint32 QRS_Heart_Rate; 
   	Uint32 HR;
	Uint16 new_val; 
	static Uint16 PrevHr = 0;
	static Uint16 digit1_count = 0;  
	char digit[1];

	if(HR_flag)
	{
		if(PrevHr != QRS_Heart_Rate)
		{
		if(Initial_HR_Flag)
		{
			clear_lcd();
			printchar('H');
			printchar('R');
			printchar('=');
			HR = QRS_Heart_Rate;
			digit1 = HR/100;
			sprintf(digit,"%d", digit1);
			printstring(digit);
			new_val = HR % 100;
 			digit2 = new_val / 10;
 			sprintf(digit,"%d", digit2);
 			printstring(digit);
			digit3 = new_val % 10;
			sprintf(digit,"%d",digit3);
			printstring(digit);
			Initial_HR_Flag = 0;

		}
		if(digit1_count<8)
		{	
			digit1 = HR/100;				/*getting the first digit of HR value*/
 			//draw_font_HR(82,13,(digit1+48),BLUE);/*displaying it by adding ASCII value*/
		}

 		if((digit1_count >= 8)&&(digit1_count <= 15))
		{	
			new_val = HR % 100;
 			digit2 = new_val / 10;				/*getting the second digit of HR value*/
 			//draw_font_HR(90,13,(digit2+48),BLUE);/*displaying it by adding ASCII value*/
		}
		if((digit1_count >15)&&(digit1_count <= 23))
		{							
 			digit3 = new_val % 10;				/*getting the third digit of HR value*/
			//draw_font_HR(98,13,(digit3+48),BLUE);/*displaying it by adding ASCII value*/
		}
		
		digit1_count++;	
		if(digit1_count >= 24)
			{
			digit1_count = 0;
			HR_flag = 0;	
			PrevHr = QRS_Heart_Rate;	
			}	
		}
	}

}

