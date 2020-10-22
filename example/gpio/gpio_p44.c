/*****************************************************************************/
/** 
 * \file        gpio_p44.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \date        
 * \brief       a example which shows how to configure pin P44 as GPIO
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
    GPIO_P44_cmd(ENABLE);
    GPIO_resetBitValue(PERIPH_GPIO_4, PERIPH_GPIO_PIN_4);

    /* blink LED */
    while (true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_4, PERIPH_GPIO_PIN_4);   /* P44 is connected to a LED for testing */
    }
}
