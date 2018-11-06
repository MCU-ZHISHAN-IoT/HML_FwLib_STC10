/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:reset and clock control
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */
 
#ifndef ___RCC_H___
#define ___RCC_H___

/* ----- @header file ----- */
#include <stc10.h>
#include <stdint.h>
#include "macro.h"
#include "util.h"

/* mark division factor */
typedef enum
{
	CLK_divFactor_1   = 0x00,
	CLK_divFactor_2   = 0x01,
	CLK_divFactor_4   = 0x02,
	CLK_divFactor_8   = 0x03,
	CLK_divFactor_16  = 0x04,
	CLK_divFactor_32  = 0x05,
	CLK_divFactor_64  = 0x06,
	CLK_divFactor_128 = 0x07
} RCC_CLK_divFactor;

/* mark prescaler factor */
typedef enum
{
	RCC_BRT_prescaler_1  = 0x04,  /* count per 1 clock cycle */
	RCC_BRT_prescaler_12 = 0x00   /* count per 12 clock cycles */
} RCC_BRT_prescaler;

/* ----- @function ----- */
void RCC_BRT_cmd(Action a);
void RCC_BRT_setClockOutput(Action a);
void RCC_BRT_setPrescaler(RCC_BRT_prescaler pre);
void RCC_BRT_setValue(unsigned char val);
void RCC_setClockDivisionFactor(RCC_CLK_divFactor d);
void RCC_softwareReset(void);
uint32_t RCC_getSystemClockFrequency(void);

#endif
