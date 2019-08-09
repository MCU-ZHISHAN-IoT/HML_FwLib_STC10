/*****************************************************************************/
/** 
 * \file       rcc-softwareReset.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       
 * \brief      a example which shows software reset
 * \note       
 * \version    v0.1
 * \ingroup    example
 * \remarks    test-board: TS51-V2.0; test-MCU: STC10F08XE
******************************************************************************/

/**
 *\extra-note: on-board LED group will change way of blinking when the MCU is 
 *             going to reset
 */

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml.h"

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    EXTI_configTypeDef ec;

    ec.mode     = EXTI_mode_fallEdge;
    ec.priority = DISABLE;
    EXTI_config(PERIPH_EXTI_0,&ec);
    EXTI_cmd(PERIPH_EXTI_0,ENABLE);

    GPIO_configPortValue(PERIPH_GPIO_1,0xFF);
    enableAllInterrupts();
}

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
    sys_init();
    while(true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0);
    }
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       interrupt service function for EXTI0
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     interrupt function for EXTI0
******************************************************************************/
void exti0_isr(void) __interrupt IE0_VECTOR
{    
    disableAllInterrupts();

    /* indicate the MCU is going to reset */
    GPIO_setBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0 | PERIPH_GPIO_PIN_1 | PERIPH_GPIO_PIN_2);
    sleep(500);
    GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0);
    sleep(250);
    GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_1);
    sleep(250);
    GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_2);
    sleep(250);

    RCC_softwareReset();
}