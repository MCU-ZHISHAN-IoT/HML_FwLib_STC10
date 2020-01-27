/*****************************************************************************/
/** 
 * \file        pwr.c
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operations for power management
 * \note        
 * \version     v0.2
 * \ingroup     PWR
******************************************************************************/

#include "hml/pwr.h"

#ifdef COMPILE_PWR

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable idle mode
 * \param[in]   
 * \return      none
 * \ingroup     PWR
 * \remarks     
******************************************************************************/
void PWR_idle(void)
{
    SET_BIT_MASK(PCON,IDL);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable power down mode
 * \param[in]   
 * \return      none
 * \ingroup     PWR
 * \remarks     
******************************************************************************/
void PWR_powerDown(void)
{
    SET_BIT_MASK(PCON,PD);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       clear LVDF bit in PCON register
 * \param[in]   
 * \return      none
 * \ingroup     PWR
 * \remarks     
******************************************************************************/
void PWR_LVD_clearFlag(void)
{
    CLR_BIT_MASK(PCON,LVDF);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable LVD(low voltage level detect) module
 * \param[in]   a: expected status
 * \return      none
 * \ingroup     PWR
 * \remarks     
******************************************************************************/
void PWR_LVD_cmd(Action a)
{
     CONFB(P4SW,BIT_NUM_NA_P46,~a);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       get value of LVDF bit in PCON register
 * \param[in]   
 * \return      none
 * \ingroup     PWR
 * \remarks     current value of LVDF bit
******************************************************************************/
FunctionalState PWR_LVD_getFlag(void)
{
    return ((FunctionalState)GET_BIT(PCON,LVDF));
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       enable or disable interrupt status of LVD module
 * \param[in]   a: expected status
 * \return      none
 * \ingroup     PWR
 * \remarks     
******************************************************************************/
void PWR_LVD_INT_cmd(Action a)
{
    ELVD = (FunctionalState)a;
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       disable or enable specified pin for waking up MCU from power 
 *              down state
 * \param[in]   a  : expected status
 * \param[in]   pin: target pin
 * \return      none
 * \ingroup     PWR
 * \remarks     
******************************************************************************/
void PWR_PD_IE_cmd(PWR_PD_IEPIN pin,Action a)
{
    switch(pin)
    {
        case PWR_PD_IEPIN_RXD: CONFB(WAKE_CLKO,BIT_NUM_RD_PIN_IE,a); break;
        case PWR_PD_IEPIN_T0 : CONFB(WAKE_CLKO,BIT_NUM_T0_PIN_IE,a); break;
        case PWR_PD_IEPIN_T1 : CONFB(WAKE_CLKO,BIT_NUM_T1_PIN_IE,a); break;
        default: break;
    }
}

#else
    #warning Nothing to be done... User should remove .c file which is disabled by compile control macro from current directory.
#endif
