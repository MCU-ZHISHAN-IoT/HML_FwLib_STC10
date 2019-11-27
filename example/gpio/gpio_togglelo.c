/*****************************************************************************/
/** 
 * \file        gpio_toggleIo.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \date        
 * \brief       a example which shows how to toggle state of specified IO
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
    GPIO_resetBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_0);

    /* blink */
    while(true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_2,PERIPH_GPIO_PIN_0);
    }
}
