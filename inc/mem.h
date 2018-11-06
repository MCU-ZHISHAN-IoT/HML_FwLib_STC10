/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:
 * #define macro that allow you to directly access the different memory areas of the 8051.
 * #include the similar functions like <absacc.h> in Keil
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */

#ifndef ___MEM_H___
#define ___MEM_H___

/* ----- @header file ----- */
#include <stc10.h>
#include "gpio.h"
#include "macro.h"

/* ----- @macro ----- */
#define __CBYTE ((unsigned char volatile __code  *) 0)
#define __DBYTE ((unsigned char volatile __data  *) 0)
#define __PBYTE ((unsigned char volatile __pdata *) 0)
#define __XBYTE ((unsigned char volatile __xdata *) 0)

#define __CWORD ((unsigned int volatile __code  *) 0)
#define __DWORD ((unsigned int volatile __data  *) 0)
#define __PWORD ((unsigned int volatile __pdata *) 0)
#define __XWORD ((unsigned int volatile __xdata *) 0)

/* ----- @function ----- */
void MEM_cmd_ale(Action a);
void MEM_cmd_internalExtendedRam(Action a);

#endif
