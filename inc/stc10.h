/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:STC10xx header file
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */

#ifndef ___STC10_H___
#define ___STC10_H___

#include <8051.h>

/*  BYTE Register  */
__sfr __at (0x8E) AUXR      ;
__sfr __at (0xA2) AUXR1     ;
__sfr __at (0x9C) BRT       ;
__sfr __at (0xA1) BUS_SPEED ;
__sfr __at (0x97) CLK_DIV   ;
__sfr __at (0xC3) IAP_ADDRH ;
__sfr __at (0xC4) IAP_ADDRL ;
__sfr __at (0xC5) IAP_CMD   ;
__sfr __at (0xC2) IAP_DATA  ;
__sfr __at (0xC6) IAP_TRIG  ;
__sfr __at (0xC7) IAP_CONTR ;
__sfr __at (0x94) P0M0      ;
__sfr __at (0x93) P0M1      ;
__sfr __at (0x92) P1M0      ;
__sfr __at (0x91) P1M1      ;
__sfr __at (0x96) P2M0      ;
__sfr __at (0x95) P2M1      ;
__sfr __at (0xB2) P3M0      ;
__sfr __at (0xB1) P3M1      ;
__sfr __at (0xC0) P4        ;
__sfr __at (0xB4) P4M0      ;
__sfr __at (0xB3) P4M1      ;
__sfr __at (0xBB) P4SW      ;
__sfr __at (0xA9) SADDDR    ;
__sfr __at (0xB9) SADEN     ;
__sfr __at (0x8F) WAKE_CLKO ;
__sfr __at (0xC1) WDT_CONTR ;
__sfr __at (0xAB) WKTCH     ;     /* can't work in STC10 series */
__sfr __at (0xAA) WKTCL     ;     /* can't work in STC10 series */

/*  BIT Register  */
/* IE */
__sbit __at (0xAE) ELVD ;

/* P4 */
__sbit __at (0xC0) P4_0 ;
__sbit __at (0xC1) P4_1 ;
__sbit __at (0xC2) P4_2 ;
__sbit __at (0xC3) P4_3 ;
__sbit __at (0xC4) P4_4 ;
__sbit __at (0xC5) P4_5 ;
__sbit __at (0xC6) P4_6 ;
__sbit __at (0xC7) P4_7 ;

/* ----- @interrupt vector ----- */
#define LVD_VECTOR 6    /* 0x33 LVD(low voltage ditect)*/

#endif
