/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:a demo which shows power-down mode
 * @Test-board:TS51-V2.0
 * @Test-mcu:STC10F08XE
 * @Version:V0
 */

#include "conf.h"

/* ----- @main ----- */
void main(void)
{
    GPIO_resetBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_0);
    
    /* blink */
    while(true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_0);
    }    
}