/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:includes some definitions for operating watch dog
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */
 
#ifndef ___WDT_H___
#define ___WDT_H___

/* ----- @header file ----- */
#include <stc10.h>
#include "macro.h"

/* ----- @enumeration type ----- */
/* mark prescale factor */
typedef enum
{
    WDT_prescale_2   = 0x00,
    WDT_prescale_4   = 0x01,
    WDT_prescale_8   = 0x02,
    WDT_prescale_16  = 0x03,
    WDT_prescale_32  = 0x04,
    WDT_prescale_64  = 0x05,
    WDT_prescale_128 = 0x06,
    WDT_prescale_256 = 0x07
} WDT_prescale;

/* ----- @function ----- */
void WDT_clear(void);
void WDT_cmd(Action a);
void WDT_cmd_idleCount(Action a);
void WDT_setPrescale(WDT_prescale pre);

#endif
