/*
 * $$$MODULE_NAME lcd_osd.h
 *
 * $$$MODULE_DESC lcd_osd.h
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This software is licensed under the  standard terms and conditions in the Texas Instruments  Incorporated
 *  Technology and Software Publicly Available Software License Agreement , a copy of which is included in the
 *  software download.
*/

#ifndef _LCD_OSD_H_
#define _LCD_OSD_H_

#include <cslr_001.h>

#include <tistdtypes.h>
#include <csl_general.h>
#include "ezdsp5535.h"
#include "ezdsp5535_lcd.h"
//extern PSP_Handle hi2c;

Int16 oledDisp();
//Int16 OSD9616_send( Uint16 regAddr, Uint16 regData);
//Int16 OSD9616_multiSend( Uint16 *regData, Uint16 length, PSP_Handle hi2c );
Int16 printchar(unsigned char a);
Int16 printstring(char *a);
Int16 clear_lcd();
Int16 print_ti();
Int16 print_dsp();
Int16 print_playaudio();
Int16 print_two(char *s1, char *s2);
Int16 print_charROM();
//Int16 oled_init();
int oled_display_bargraph (int * message);



#endif
