/*****************************************************************************/
/** 
 * \file        conf.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML configurations, this file need to be modified by users
 * \note        
 * \version     v0.2
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_CONF_H___
#define ___HML_CONF_H___

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: configure clock frequency of MCU
 */
#define __CONF_FRE_CLKIN 11059200L

/**
 *\brief: configure module of MCU
 */
#define __CONF_MCU_MODEL MCU_MODEL_STC10F02XE

/**
 *\brief: select HML module which take part in compilation
 */
#define __CONF_COMPILE_EXTI
#define __CONF_COMPILE_GPIO
#define __CONF_COMPILE_IAP
#define __CONF_COMPILE_MEM
#define __CONF_COMPILE_PWR
#define __CONF_COMPILE_RCC
#define __CONF_COMPILE_TIM
#define __CONF_COMPILE_UART
#define __CONF_COMPILE_UTIL
#define __CONF_COMPILE_WDT

#endif
