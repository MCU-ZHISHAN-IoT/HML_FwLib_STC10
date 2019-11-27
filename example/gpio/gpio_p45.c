/*****************************************************************************/
/** 
 * \file        gpio_p45.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \date        
 * \brief       a example which shows how to configure pin ALE as GPIO(P45)
 * \note        
 * \version     v0.2
 * \ingroup     example
 * \remarks     test-board: TS51-V2.0; test-MCU: STC10F08XE
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
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
