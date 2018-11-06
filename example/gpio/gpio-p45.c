/*
 * @Author:
 *  #Amy Chung | zhongliguo(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:a example which shows how to configure pin ALE/P45 as GPIO
 * @Support-mcu:STC micro STC10 series
 * @Test-board:TS51-V2.0
 * @Test-mcu:STC10F08XE
 * @Version:V0
 */

#include "conf.h"

/* ----- @main ----- */
void main(void)
{	
	GPIO_P45_cmd(ENABLE);
	GPIO_resetBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
	
	/* blink */
	while(true)
	{
		sleep(500);
		GPIO_toggleBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);   /* P45 is connected to a LED for testing */
	}	
}
