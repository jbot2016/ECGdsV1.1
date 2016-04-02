
#include"ezdsp5535.h"
#include"ezdsp5535_lcd.h"

//#include "app_globals.h"
//#include "psp_i2s.h"
//#include "psp_i2c.h"
//#include "dda_i2c.h"
#include "psp_common.h"
#include "oledDisplay.h"
#include "stdio.h"
#include "string.h"
//#include "dsplib.h"
//#include "VC5505_CSL_BIOS_cfg.h"

//#ifdef C5535_EZDSP_DEMO

//#define OSD9616_I2C_ADDR 0x3C    // OSD9616 I2C address

#pragma DATA_SECTION(CharGen_6x8, ".gcharrom")
Uint16 CharGen_6x8[256*3];

/*
 *  Int16 oledDisplay()
 *
 *      Testing function for the OSD9616 display
 */
Int16 oledDisp()
{
	Int16 i;
	Uint16 cmd[10];    // For multibyte commands
	//char banner[30];
	EZDSP5535_OSD9616_init( ); //lcd init
	
	EZDSP5535_OSD9616_send(0x00,0x2e);  // Deactivate Scrolling
	
	    /* Fill page 0 */ 
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
    for(i=0;i<128;i++)
    {
    	EZDSP5535_OSD9616_send(0x40,0xff);
    }
    
    /* Write to page 0 */
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
    for(i=0;i<165;i++)
    {
    	EZDSP5535_OSD9616_send(0x40,0x00);  // Spaces
    }
    printchar('W');
    printchar('W');
    printchar('E');
    printchar('C');
    printchar('G');
	
//    for(i=0;i<128;i++)
//    {
//    	EZDSP5535_OSD9616_send(0x40,0x00);  // Spaces
//    }
    
    /* Fill page 1*/ 
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
    for(i=0;i<128;i++)
    {
    	EZDSP5535_OSD9616_send(0x40,0xff);
    }
    
    /* Write to page 1*/ 
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
    for(i=0;i<151;i++)
    {
    	EZDSP5535_OSD9616_send(0x40,0x00);
    }
	printchar('U');
	printchar('C');
	printchar('F');
	printchar(':');
	EZDSP5535_OSD9616_printLetter(0x32,0x49,0x49,0x26);  // S
	EZDSP5535_OSD9616_printLetter(0x7F,0x41,0x41,0x3E);  // D   
    
    for(i=0;i<5;i++)
    {
    	EZDSP5535_OSD9616_send(0x40,0x00);  // Spaces
    }
    EZDSP5535_OSD9616_printLetter(0x7F,0x49,0x49,0x41);  // E
	EZDSP5535_OSD9616_printLetter(0x3E,0x41,0x41,0x22);  // C
	EZDSP5535_OSD9616_printLetter(0x7F,0x49,0x49,0x41);  // E
		
     EZDSP5535_OSD9616_send(0x00,0x2e);  // Deactivate Scrolling
    
    /* Set vertical and horizontal scrolling */
    cmd[0] = 0x00;
    cmd[1] = 0x29;  // Vertical and Right Horizontal Scroll
    cmd[2] = 0x00;  // Dummy byte
    cmd[3] = 0x00;  // Define start page address
    cmd[4] = 0x03;  // Set time interval between each scroll step
    cmd[5] = 0x01;  // Define end page address
    cmd[6] = 0x01;  // Vertical scrolling offset
    EZDSP5535_OSD9616_multiSend( cmd, 7 );
    EZDSP5535_OSD9616_send(0x00,0x2f);
    
    /* Keep first 8 rows from vertical scrolling  */
    cmd[0] = 0x00;
    cmd[1] = 0xa3;  // Set Vertical Scroll Area
    cmd[2] = 0x08;  // Set No. of rows in top fixed area
    cmd[3] = 0x00;  // Set No. of rows in scroll area //jb was 0x08 now 0x00
    EZDSP5535_OSD9616_multiSend( cmd, 4 );
    
    return 0;
    
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 printchar(unsigned char a)              *
 *                                                                          *
 *      Send 6 bytes representing a Character                               *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 printchar(unsigned char a)
{
	Uint8 data;

	data = ((CharGen_6x8[a*3])>>8) & 0x00FF;
   EZDSP5535_OSD9616_send(0x40,data);
    data = (CharGen_6x8[a*3]) & 0x00FF;
   EZDSP5535_OSD9616_send(0x40,data);
    data = ((CharGen_6x8[a*3+1])>>8) & 0x00FF;
   EZDSP5535_OSD9616_send(0x40,data);
    data = (CharGen_6x8[a*3+1]) & 0x00FF;
   EZDSP5535_OSD9616_send(0x40,data);
    data = ((CharGen_6x8[a*3+2])>>8) & 0x00FF;
   EZDSP5535_OSD9616_send(0x40,data);
    data = (CharGen_6x8[a*3+2]) & 0x00FF;
   EZDSP5535_OSD9616_send(0x40,data);

    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 printstring(char *a)              *
 *                                                                          *
 *      print a string                               *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 printstring(char *a)
{
	Uint16 i, len;
	
	len = strlen(a);
	if ((len ==0) | (len>22)) len=16;
	
	for (i=0; i<len; i++) {
		printchar(a[i]);
	}
	return 0;	
}	

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 printstring(char *a)              *
 *                                                                          *
 *      print a string                               *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 clear_lcd()
{
	Uint16 i;

    /* clear page 0 */ 
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5		
	for (i=0; i<128; i++) {
		EZDSP5535_OSD9616_send(0x40,0x00);
	}
    /* clear page 1 */ 
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5	
    for (i=0; i<128; i++) {
		EZDSP5535_OSD9616_send(0x40,0x00);
	}
	return 0;	
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 print_ti()                                                       *
 *                                                                          *
 *      Print "Texas Instruments"                            				*
 *            "C5535 eZdsp stk"                                                              *
 * ------------------------------------------------------------------------ */
Int16 print_ti()
{
	char ti[23]; 
		
	EZDSP5535_OSD9616_send(0x00,0x2e); // Turn off scrolling 
	clear_lcd();
	sprintf(ti,"                       "); //clear	
	    /* Write to page 1 */
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
   	
   	sprintf(ti,"  Texas Instruments");
	printstring(ti);
	    /* Write to page 0*/ 
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
	sprintf(ti," C5535 eZdsp USB stick");
	printstring(ti);
	
	EZDSP5535_OSD9616_send(0x00,0x2f); // Turn on scrolling 
	
	return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 print_dsp()                                                       *
 *                                                                          *
 *      Print "Industry lowest"                            				*
 *            "power dsp C5535"                                                             *
 * ------------------------------------------------------------------------ */
Int16 print_dsp()
{
	char ti[23]; 
	Uint16 i;
	
	EZDSP5535_OSD9616_send(0x00,0x2e); // Turn off scrolling 
	clear_lcd();
	
	for (i=0; i<23; i++) 
	  ti[i] = 0x20;      //clear buffer
	  
	//sprintf(ti,"                       "); //clear	
	    /* Write to page 1 */
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
   	
   	sprintf(ti,"  Industry's lowest");
	printstring(ti);
	    /* Write to page 0*/ 
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
	sprintf(ti,"  power DSP C5535");
	printstring(ti);
	
	EZDSP5535_OSD9616_send(0x00,0x2f); // Turn on scrolling 
	return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 print_playaudio()                                                 *
 *                                                                          *
 *      Print "   Play Audio"                            				    *
 *            "      Play Audio"                                            *
 * ------------------------------------------------------------------------ */
Int16 print_playaudio()
{
	char ti[23]; 
		
	EZDSP5535_OSD9616_send(0x00,0x2e); // Turn off scrolling 
	clear_lcd();
	sprintf(ti,"                       "); //clear	
	    /* Write to page 1 */
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
   	
   	sprintf(ti,"  Play Audio");
	printstring(ti);
	    /* Write to page 0*/ 
   EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
   EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
   EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
	sprintf(ti,"  From Your PC");
	printstring(ti);
	
	EZDSP5535_OSD9616_send(0x00,0x2f); // Turn on scrolling 
	
	return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 print_two(s1, s2)                                                 *
 *                                                                          *
 *      Print s1				                            				*
 *            s2                                                            *
 * ------------------------------------------------------------------------ */
Int16 print_two(char *s1, char *s2)
{
	EZDSP5535_OSD9616_send(0x00,0x2e); // Turn off scrolling 
	clear_lcd();
	    /* Write to page 1 */
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
   	
	printstring(s1);
	    /* Write to page 0*/ 
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
	printstring(s2);
	
	//EZDSP5535_OSD9616_send(0x00,0x2f); // Turn on scrolling 
	
	return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Int16 print_charROM()                                                       *
 *                                                                          *
 *      Print "Industry lowest"                            				*
 *            "power dsp C5515"                                                             *
 * ------------------------------------------------------------------------ */
Int16 print_charROM()
{
	char crom[16]; 
	Uint16 i,j;
	
	EZDSP5535_OSD9616_send(0x00,0x2e); // Turn off scrolling 
	clear_lcd();
	
	for (j=0; j<8; j++) {
	    /* Write to page 1 */
    	EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    	EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    	EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
   		for (i=0; i<16; i++) {
   			crom[i] = i + j*32;
   		}
		printstring(crom);
	 
	    /* Write to page 0*/ 
    	EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    	EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    	EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
   		for (i=0; i<16; i++) {
   			crom[i] = i + 16 + j*32;
   		}	
		printstring(crom);
		//USBSTK5515_waitusec(3000000);
	}
	//EZDSP5535_OSD9616_send(0x00,0x2f); // Turn on scrolling 
	return 0;
}



/*****************************************************************************/
/* amplitude2bargraph()                                                      */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Parameter 1:  Input value in range -32767 to - 32768.                     */
/*                                                                           */
/* RETURNS: Bargraph pixel value between 0 and FFFFh.                        */
/*                                                                           */
/*****************************************************************************/
#if 0
static unsigned int amplitude2bargraph(int input)
{
 if ( input < 0 ) 
  {
    input = -input;
  }

 if ( input > 23166)
  {
    return (0xFFFF); /* All LEDs on */
  }
 else if (input > 16384)
  {
    return (0xFFFF);
  }
 else if ( input > 11583)
  {
    return (0xFFFF);
  }
 else if ( input > 8192)
  {
    return (0xFFFF);
  }
 else if ( input > 5791)
  {
    return (0xFFFF);
  }
 else if ( input > 4096)
  {
    return (0xFFFF);
  }
 else if (input > 2896)
  {
    return ( 0xFFFF);
  }
 else if ( input > 2048)
  {
    return (0xFFFF);
  }
 else if ( input > 1448)
  {
   return (0xFFFF);
  }
 else if ( input > 1024)
  {
   return (0xFFFE );
  }
 else if ( input > 724)
  {
   return (0xFFFC);
  }
 else if ( input > 512)
  {
   return (0xFFF8);
  }
 else if ( input > 362)
  {
   return (0xFFF0);
  }
 else if ( input > 256)
  {
   return (0xFFE0);
  }
 else if ( input > 181)
  {
   return (0xFFC0);
  }
 else if ( input > 128)
  {
   return (0xFF80);
  }
 else if ( input > 90)
  {
   return (0xFF00);
  } 
 else if ( input > 64)
  {
   return (0xFE00);
  } 
 else if ( input > 45)
  {
   return (0xFC00);
  } 
 else if ( input > 32)
  {
   return (0xF800);
  }  
 else if (input > 22)
  {
   return (0xF000);
  } 
 else if ( input > 16)
  {
   return(0xE000);
  } 
 else if ( input > 11)
  {
   return (0xC000);
  } 
 else if ( input > 8)
  {
   return (0x8000);
  } 
 else
  {
    return (0);
  }
}
#else
static unsigned int amplitude2bargraph(int input)
{
 if ( input < 0 ) 
  {
    input = -input;
  }

 if ( input > 23166)
  {
    return (0xFFFF); /* All LEDs on */
  }
 else if (input > 16384)
  {
    return (0xFFFF);
  }
 else if ( input > 11583)
  {
    return (0xFFFF);
  }
 else if ( input > 8192)
  {
    return (0xFFFF);
  }
 else if ( input > 5791)
  {
    return (0xFFFF);
  }
 else if ( input > 4096)
  {
    return (0xFFFF);
  }
 else if (input > 2896)
  {
    return ( 0xFFFF);
  }
 else if ( input > 2048)
  {
    return (0xFFFF);
  }
 else if ( input > 1448)
  {
   return (0xFFFF);
  }
 else if ( input > 1024)
  {
   return (0x7FFF );
  }
 else if ( input > 724)
  {
   return (0x3FFF);
  }
 else if ( input > 512)
  {
   return (0x1FFF);
  }
 else if ( input > 362)
  {
   return (0x0FFF);
  }
 else if ( input > 256)
  {
   return (0x07FF);
  }
 else if ( input > 181)
  {
   return (0x03FF);
  }
 else if ( input > 128)
  {
   return (0x01FF);
  }
 else if ( input > 90)
  {
   return (0x00FF);
  } 
 else if ( input > 64)
  {
   return (0x007F);
  } 
 else if ( input > 45)
  {
   return (0x003F);
  } 
 else if ( input > 32)
  {
   return (0x001F);
  }  
 else if (input > 22)
  {
   return (0x000F);
  } 
 else if ( input > 16)
  {
   return(0x0007);
  } 
 else if ( input > 11)
  {
   return (0x0003);
  } 
 else if ( input > 8)
  {
   return (0x0001);
  } 
 else
  {
    return (0);
  }
}
#endif

/*****************************************************************************/
/* oled_display_bargraph()                                                   */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/* Parameter 1:  Pointer to array containing 96 16-bit input values.         */
/*                                                                           */
/* RETURNS: Nothing                                                          */
/*                                                                           */
/*****************************************************************************/
int oled_display_bargraph (int * message)
{
    int i;
    Uint16 input;
    Uint16 pixels;	

	EZDSP5535_OSD9616_send(0x00,0x2E);           // Turn off scrolling
	
    /* Fill page 0 */ 
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5

    /* Send topline from high to low */
    for ( i = 0; i <96/2; i++)
     {
       input = amplitude2bargraph(message[i]);       
     
       pixels = (input&0xFF); /* Extract low byte */

       EZDSP5535_OSD9616_send(0x40,pixels);
       EZDSP5535_OSD9616_send(0x40,pixels);
     }
    
    /* Write to page 1*/ 
    EZDSP5535_OSD9616_send(0x00,0x00);   // Set low column address
    EZDSP5535_OSD9616_send(0x00,0x10);   // Set high column address
    EZDSP5535_OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
   

  /* Send bottomline */
    for ( i = 0 ; i < 96/2; i++ )
     {
       input = amplitude2bargraph(message[i]);       
     
       pixels = (input>>8 ); /* Extract high byte */
       
       EZDSP5535_OSD9616_send(0x40,pixels);
       EZDSP5535_OSD9616_send(0x40,pixels);
     }

	return 0;
}
//#endif


       