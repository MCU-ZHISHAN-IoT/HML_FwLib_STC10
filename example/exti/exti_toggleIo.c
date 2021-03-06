/*****************************************************************************/
/** 
 * \file        exti_toggleIo.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \date        
 * \brief       a example which shows how to toggle IO by EXTI module
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
    EXTI_config(PERIPH_EXTI_1, &ec);
    EXTI_cmd(PERIPH_EXTI_1, ENABLE);
    enableAllInterrupts();

    GPIO_setBitValue(PERIPH_GPIO_2, PERIPH_GPIO_PIN_0);
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
    while (true);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       interrupt service function for EXTI1
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     interrupt function for EXTI1, pin INT1 is connected to a button
 *              on board
******************************************************************************/
void exti1_isr(void) __interrupt IE1_VECTOR
{
    GPIO_toggleBitValue(PERIPH_GPIO_2, PERIPH_GPIO_PIN_0);
}
