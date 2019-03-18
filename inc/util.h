/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:provides some public functions
 * @Required-complier:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */

#ifndef ___UTIL_H___
#define ___UTIL_H___

/* ----- @header file ----- */
#include "stc10.h"
#include "intrasm.h"
#include "macro.h"

/* ----- @function ----- */
void disableAllInterrupts(void);
void enableAllInterrupts(void);
unsigned int pow(unsigned char x,unsigned char y);    /* self-define pow function */
void sleep(u16 t);

#endif
