/*****************************************************************************
 * File Name : ECG_Filter_Co-efficients.c
 *
 * Description : The file contains the coefficients for Multi  band FIR LPF 
 * 			  used for filtering the DC Removed samples
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


#include "ECGGlobals.h"
#include "tistdtypes.h"

#define SPS 500
//add other filters jb

#pragma DATA_SECTION(Coeffbuf,".Coeff");
/*   Q15 Multiplication Format  */
#if (SPS == 500)		// SPS = 500
#if NOTCHFILTERSEL
/* Coeff for Notch @ 60Hz for 500SPS/60Hz Notch coeff13102008*/
Int16 CoeffBuf[FILTERORDER] = {             2,
    12,
     5,
     1,
     2,
    -7,
   -13,
    -1,
     5,
     3,
     9,
    11,
    -6,
   -13,
    -5,
    -6,
    -4,
    14,
    16,
     1,
    -3,
    -4,
   -19,
   -14,
    11,
    13,
     8,
    16,
     3,
   -25,
   -20,
    -3,
    -4,
    11,
    35,
    16,
   -15,
   -12,
   -19,
   -32,
     2,
    38,
    22,
    13,
    15,
   -26,
   -54,
   -15,
    12,
    10,
    42,
    52,
   -13,
   -46,
   -25,
   -36,
   -26,
    51,
    71,
    15,
     4,
   -11,
   -79,
   -67,
    26,
    43,
    35,
    76,
    30,
   -83,
   -76,
   -24,
   -36,
    24,
   126,
    70,
   -30,
   -24,
   -63,
  -127,
   -18,
   107,
    67,
    54,
    78,
   -58,
  -167,
   -59,
    11,
    -3,
   117,
   173,
   -10,
  -107,
   -52,
  -116,
  -115,
   113,
   183,
    43,
    45,
    21,
  -197,
  -193,
    43,
    67,
    50,
   210,
   123,
  -174,
  -157,
   -44,
  -137,
    -7,
   286,
   168,
   -55,
    16,
   -87,
  -317,
   -82,
   211,
    83,
    92,
   249,
   -63,
  -350,
   -90,
    12,
  -123,
   187,
   401,
   -17,
  -185,
    22,
  -216,
  -342,
   198,
   343,
   -26,
   124,
   218,
  -368,
  -409,
   165,
    45,
  -123,
   445,
   355,
  -402,
  -199,
   151,
  -405,
  -234,
   656,
   250,
  -352,
   304,
   155,
  -862,
  -163,
   720,
  -269,
  -248,
  1063,
   -16,
 -1289,
   502,
   696,
 -1638,
   190,
  2737,
 -1859,
 -3066,
  9726,
 19385,
  9726,
 -3066,
 -1859,
  2737,
   190,
 -1638,
   696,
   502,
 -1289,
   -16,
  1063,
  -248,
  -269,
   720,
  -163,
  -862,
   155,
   304,
  -352,
   250,
   656,
  -234,
  -405,
   151,
  -199,
  -402,
   355,
   445,
  -123,
    45,
   165,
  -409,
  -368,
   218,
   124,
   -26,
   343,
   198,
  -342,
  -216,
    22,
  -185,
   -17,
   401,
   187,
  -123,
    12,
   -90,
  -350,
   -63,
   249,
    92,
    83,
   211,
   -82,
  -317,
   -87,
    16,
   -55,
   168,
   286,
    -7,
  -137,
   -44,
  -157,
  -174,
   123,
   210,
    50,
    67,
    43,
  -193,
  -197,
    21,
    45,
    43,
   183,
   113,
  -115,
  -116,
   -52,
  -107,
   -10,
   173,
   117,
    -3,
    11,
   -59,
  -167,
   -58,
    78,
    54,
    67,
   107,
   -18,
  -127,
   -63,
   -24,
   -30,
    70,
   126,
    24,
   -36,
   -24,
   -76,
   -83,
    30,
    76,
    35,
    43,
    26,
   -67,
   -79,
   -11,
     4,
    15,
    71,
    51,
   -26,
   -36,
   -25,
   -46,
   -13,
    52,
    42,
    10,
    12,
   -15,
   -54,
   -26,
    15,
    13,
    22,
    38,
     2,
   -32,
   -19,
   -12,
   -15,
    16,
    35,
    11,
    -4,
    -3,
   -20,
   -25,
     3,
    16,
     8,
    13,
    11,
   -14,
   -19,
    -4,
    -3,
     1,
    16,
    14,
    -4,
    -6,
    -5,
   -13,
    -6,
    11,
     9,
     3,
     5,
    -1,
   -13,
    -7,
     2,
     1,
     5,
    12,
     2
 };	//coeff

#else
/* Coeff for Notch @ 50Hz @ 500 SPS*/
Int16 CoeffBuf[FILTERORDER] = {                -2,
    -2,
   -11,
    -9,
     3,
     4,
     3,
    12,
     9,
    -4,
    -5,
    -4,
   -13,
   -10,
     6,
     7,
     5,
    15,
    10,
    -9,
   -10,
    -7,
   -17,
   -10,
    13,
    13,
     9,
    20,
    10,
   -17,
   -18,
   -11,
   -22,
    -9,
    24,
    23,
    12,
    24,
     8,
   -31,
   -29,
   -14,
   -25,
    -5,
    41,
    35,
    14,
    26,
     1,
   -52,
   -42,
   -14,
   -25,
     4,
    65,
    49,
    12,
    23,
   -11,
   -79,
   -56,
    -8,
   -19,
    19,
    94,
    62,
     2,
    13,
   -28,
  -110,
   -67,
     7,
    -6,
    39,
   127,
    70,
   -19,
    -4,
   -50,
  -144,
   -71,
    35,
    15,
    62,
   160,
    69,
   -55,
   -28,
   -72,
  -175,
   -65,
    78,
    42,
    82,
   188,
    56,
  -105,
   -56,
   -90,
  -200,
   -45,
   136,
    70,
    95,
   209,
    29,
  -171,
   -82,
   -96,
  -216,
   -11,
   208,
    93,
    93,
   221,
   -11,
  -249,
  -100,
   -85,
  -224,
    36,
   292,
   102,
    70,
   226,
   -63,
  -338,
  -100,
   -49,
  -229,
    91,
   386,
    90,
    20,
   233,
  -119,
  -438,
   -71,
    18,
  -241,
   148,
   495,
    42,
   -66,
   259,
  -175,
  -561,
     0,
   128,
  -293,
   199,
   644,
   -63,
  -210,
   356,
  -221,
  -759,
   157,
   324,
  -477,
   238,
   946,
  -312,
  -509,
   734,
  -252,
 -1336,
   635,
   909,
 -1464,
   260,
  2705,
 -1944,
 -3135,
  9717,
 19411,
  9717,
 -3135,
 -1944,
  2705,
   260,
 -1464,
   909,
   635,
 -1336,
  -252,
   734,
  -509,
  -312,
   946,
   238,
  -477,
   324,
   157,
  -759,
  -221,
   356,
  -210,
   -63,
   644,
   199,
  -293,
   128,
     0,
  -561,
  -175,
   259,
   -66,
    42,
   495,
   148,
  -241,
    18,
   -71,
  -438,
  -119,
   233,
    20,
    90,
   386,
    91,
  -229,
   -49,
  -100,
  -338,
   -63,
   226,
    70,
   102,
   292,
    36,
  -224,
   -85,
  -100,
  -249,
   -11,
   221,
    93,
    93,
   208,
   -11,
  -216,
   -96,
   -82,
  -171,
    29,
   209,
    95,
    70,
   136,
   -45,
  -200,
   -90,
   -56,
  -105,
    56,
   188,
    82,
    42,
    78,
   -65,
  -175,
   -72,
   -28,
   -55,
    69,
   160,
    62,
    15,
    35,
   -71,
  -144,
   -50,
    -4,
   -19,
    70,
   127,
    39,
    -6,
     7,
   -67,
  -110,
   -28,
    13,
     2,
    62,
    94,
    19,
   -19,
    -8,
   -56,
   -79,
   -11,
    23,
    12,
    49,
    65,
     4,
   -25,
   -14,
   -42,
   -52,
     1,
    26,
    14,
    35,
    41,
    -5,
   -25,
   -14,
   -29,
   -31,
     8,
    24,
    12,
    23,
    24,
    -9,
   -22,
   -11,
   -18,
   -17,
    10,
    20,
     9,
    13,
    13,
   -10,
   -17,
    -7,
   -10,
    -9,
    10,
    15,
     5,
     7,
     6,
   -10,
   -13,
    -4,
    -5,
    -4,
     9,
    12,
     3,
     4,
     3,
    -9,
   -11,
    -2,
    -2

};	//coeff

#endif
#endif

//fc = 100Hz order = 351(really 350) at fs = 500sps
Int16 LP_100_CoeffBuf[FILTERORDER] = {0,-5,-3,3,5,0,-5,-3,3,5,0,-5,-3,
4,6,0,-6,-4,4,7,0,-7,-5,5,8,0,-9,-6,6,10,0,-10,-7,7,11,0,-12,-8,8,14,
0,-15,-9,10,16,0,-18,-11,12,19,0,-21,-13,14,23,0,-24,-16,16,27,0,-29,
-18,19,31,0,-33,-21,22,37,0,-39,-25,25,42,0,-45,-28,29,49,0,-51,-33,34,
56,0,-59,-37,38,64,0,-67,-43,44,73,0,-77,-49,50,83,0,-87,-55,57,94,0,
-99,-63,65,107,0,-113,-72,74,122,0,-129,-82,84,139,0,-147,-93,96,160,0,
-169,-107,110,184,0,-195,-124,128,213,0,-227,-145,150,250,0,-268,-171,
177,298,0,-321,-207,215,363,0,-396,-256,269,457,0,-508,-333,353,608,0,
-698,-466,506,894,0,-1096,-763,873,1649,0,-2478,-2043,3065,9921,13110,
9921,3065,-2043,-2478,0,1649,873,-763,-1096,0,894,506,-466,-698,0,608,
353,-333,-508,0,457,269,-256,-396,0,363,215,-207,-321,0,298,177,-171,
-268,0,250,150,-145,-227,0,213,128,-124,-195,0,184,110,-107,-169,0,160,
96,-93,-147,0,139,84,-82,-129,0,122,74,-72,-113,0,107,65,-63,-99,0,94,
57,-55,-87,0,83,50,-49,-77,0,73,44,-43,-67,0,64,38,-37,-59,0,56,34,-33,
-51,0,49,29,-28,-45,0,42,25,-25,-39,0,37,22,-21,-33,0,31,19,-18,-29,0,
27,16,-16,-24,0,23,14,-13,-21,0,19,12,-11,-18,0,16,10,-9,-15,0,14,8,-8,
-12,0,11,7,-7,-10,0,10,6,-6,-9,0,8,5,-5,-7,0,7,4,-4,-6,0,6,4,-3,-5,0,5,
3,-3,-5,0,5,3,-3,-5,0};

//fc = .5Hz order = 351(really 350) at fs = 500sps	
Int16 HP_pt5_CoeffBuf[FILTERORDER] = {-4,-4,-4,-4,-4,-4,-4,-5,-5,-5,-5,
-5,-5,-5,-5,-5,-5,-6,-6,-6,-6,-6,-6,-7,-7,-7,-7,-8,-8,-8,-8,-9,-9,
-9,-9,-10,-10,-10,-11,-11,-11,-12,-12,-12,-13,-13,-13,-14,-14,-15,
-15,-15,-16,-16,-17,-17,-17,-18,-18,-19,-19,-20,-20,-21,-21,-22,
-22,-23,-23,-24,-24,-25,-25,-26,-26,-27,-27,-28,-28,-29,-30,-30,
-31,-31,-32,-32,-33,-33,-34,-34,-35,-36,-36,-37,-37,-38,-38,-39,
-39,-40,-41,-41,-42,-42,-43,-43,-44,-44,-45,-45,-46,-46,-47,-47,
-48,-49,-49,-49,-50,-50,-51,-51,-52,-52,-53,-53,-54,-54,-55,-55,
-55,-56,-56,-57,-57,-57,-58,-58,-59,-59,-59,-60,-60,-60,-61,-61,
-61,-61,-62,-62,-62,-63,-63,-63,-63,-63,-64,-64,-64,-64,-64,-64,
-65,-65,-65,-65,-65,-65,-65,-65,-65,-65,-65,-66,-66,32698,-66,-66,
-65,-65,-65,-65,-65,-65,-65,-65,-65,-65,-65,-64,-64,-64,-64,-64,
-64,-63,-63,-63,-63,-63,-62,-62,-62,-61,-61,-61,-61,-60,-60,-60,
-59,-59,-59,-58,-58,-57,-57,-57,-56,-56,-55,-55,-55,-54,-54,-53,
-53,-52,-52,-51,-51,-50,-50,-49,-49,-49,-48,-47,-47,-46,-46,-45,
-45,-44,-44,-43,-43,-42,-42,-41,-41,-40,-39,-39,-38,-38,-37,-37,
-36,-36,-35,-34,-34,-33,-33,-32,-32,-31,-31,-30,-30,-29,-28,-28,
-27,-27,-26,-26,-25,-25,-24,-24,-23,-23,-22,-22,-21,-21,-20,-20,
-19,-19,-18,-18,-17,-17,-17,-16,-16,-15,-15,-15,-14,-14,-13,-13,
-13,-12,-12,-12,-11,-11,-11,-10,-10,-10,-9,-9,-9,-9,-8,-8,-8,-8,
-7,-7,-7,-7,-6,-6,-6,-6,-6,-6,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-4,-4,
-4,-4,-4,-4,-4};

//fc = 20Hz order = 351(really 350) at fs = 500sps	
Int16 LP_20_CoeffBuf[FILTERORDER] = {0,-1,-2,-3,-4,-5,-5,-5,-5,-4,
-3,-2,-1,1,2,4,5,6,7,7,7,6,5,4,2,0,-2,-5,-7,-9,-10,-11,-11,-11,-9,
-7,-5,-2,2,5,9,12,15,16,17,17,16,13,10,5,0,-5,-11,-16,-20,-24,-26,
-26,-25,-22,-17,-11,-4,4,12,20,27,33,37,38,38,34,29,21,11,0,-12,-23,
-34,-43,-50,-54,-55,-52,-45,-35,-23,-8,8,25,40,54,66,73,76,75,68,57,
41,22,0,-23,-45,-66,-84,-97,-104,-105,-99,-87,-68,-44,-15,16,47,78,
104,126,140,146,143,131,109,79,42,0,-44,-88,-129,-163,-189,-205,-207,
-197,-173,-136,-88,-31,32,97,160,217,264,297,313,309,285,241,176,95,0,
-104,-210,-313,-406,-482,-534,-556,-544,-493,-402,-271,-99,108,346,609,
889,1175,1460,1732,1983,2202,2381,2514,2597,2624,2597,2514,2381,2202,
1983,1732,1460,1175,889,609,346,108,-99,-271,-402,-493,-544,-556,-534,
-482,-406,-313,-210,-104,0,95,176,241,285,309,313,297,264,217,160,97,
32,-31,-88,-136,-173,-197,-207,-205,-189,-163,-129,-88,-44,0,42,79,109,
131,143,146,140,126,104,78,47,16,-15,-44,-68,-87,-99,-105,-104,-97,-84,
-66,-45,-23,0,22,41,57,68,75,76,73,66,54,40,25,8,-8,-23,-35,-45,-52,-55,
-54,-50,-43,-34,-23,-12,0,11,21,29,34,38,38,37,33,27,20,12,4,-4,-11,-17,
-22,-25,-26,-26,-24,-20,-16,-11,-5,0,5,10,13,16,17,17,16,15,12,9,5,2,-2,
-5,-7,-9,-11,-11,-11,-10,-9,-7,-5,-2,0,2,4,5,6,7,7,7,6,5,4,2,1,-1,-2,-3,
-4,-5,-5,-5,-5,-4,-3,-2,-1,0};	
