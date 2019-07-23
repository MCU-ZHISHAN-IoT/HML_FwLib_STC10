/*****************************************************************************/
/** 
 * \file        pwr.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       operations for power management
 * \note        
 * \version     v0.1
 * \ingroup     PWR
******************************************************************************/
 
#ifndef ___PWR_H___
#define ___PWR_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hw/stc10.h"
#include "macro.h"

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: mark wakeup pins for power-down mode
 */
typedef enum
{
    PWR_PD_IEPIN_RXD = 0x1,
    PWR_PD_IEPIN_T0  = 0x2,
    PWR_PD_IEPIN_T1  = 0x3
} PWR_PD_IEPIN;

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/
void PWR_idle(void);
void PWR_powerDown(void);
void PWR_LVD_clearFlag(void);
void PWR_LVD_cmd(Action a);
FunctionalState PWR_LVD_getFlag(void);
void PWR_LVD_INT_cmd(Action a);
void PWR_PD_IE_cmd(PWR_PD_IEPIN pin,Action a);

#endif
