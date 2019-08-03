/*****************************************************************************/
/** 
 * \file        macro.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML macro define
 * \note        
 * \version     v0.1
 * \ingroup     generic
******************************************************************************/

#ifndef ___MACRO_H___
#define ___MACRO_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "conf.h"

/*****************************************************************************
 *                             type define                                   *
 *****************************************************************************/
typedef unsigned char byte;
typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned int  word;

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: mark user action
 */
typedef enum
{
    DISABLE = 0x0,
    ENABLE  = !DISABLE
} Action;

/**
 *\brief: mark bit value/state
 */
typedef enum
{
    RESET = 0x0,
    SET   = !RESET
} FunctionalState;

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: mark MCU model of STC10 series
 */
#define MCU_MODEL_GENERIC         0x01
#define MCU_MODEL_STC10F02XE      0x02
#define MCU_MODEL_STC10L02XE      0x02
#define MCU_MODEL_STC10F04XE      0x03
#define MCU_MODEL_STC10L04XE      0x03
#define MCU_MODEL_STC10F06XE      0x04
#define MCU_MODEL_STC10L06XE      0x04
#define MCU_MODEL_STC10F08XE      0x05
#define MCU_MODEL_STC10L08XE      0x05
#define MCU_MODEL_STC10F10XE      0x06
#define MCU_MODEL_STC10L10XE      0x06
#define MCU_MODEL_STC10F12XE      0x07
#define MCU_MODEL_STC10L12XE      0x07
#define MCU_MODEL_IAP10F14X       0x08
#define MCU_MODEL_IAP10L14X       0x08

/**
 *\brief: check macro for MCU model
 */
/**
 *\brief: check macro for MCU model
 */
#define IS_STC10_MCU_MODEL(model)           \
    (                                       \
      (model == MCU_MODEL_GENERIC)       || \
      (model == MCU_MODEL_STC10F02XE)    || \
      (model == MCU_MODEL_STC10L02XE)    || \
      (model == MCU_MODEL_STC10F04XE)    || \
      (model == MCU_MODEL_STC10L04XE)    || \
      (model == MCU_MODEL_STC10F06XE)    || \
      (model == MCU_MODEL_STC10L06XE)    || \
      (model == MCU_MODEL_STC10F08XE)    || \
      (model == MCU_MODEL_STC10L08XE)    || \
      (model == MCU_MODEL_STC10F10XE)    || \
      (model == MCU_MODEL_STC10L10XE)    || \
      (model == MCU_MODEL_STC10F12XE)    || \
      (model == MCU_MODEL_STC10L12XE)    || \
      (model == MCU_MODEL_IAP10F14X)     || \
      (model == MCU_MODEL_IAP10L14X)        \
    )

/*****************************************************************************
 *                           run-time check                                  *
 *****************************************************************************/
/**
 *\brief: MCU clock configuration check
 */
#if (defined __CONF_FRE_CLKIN)
    #define MCU_FRE_CLK __CONF_FRE_CLKIN
#else
    #error HML run-time check: error: HML need define input clock frequency! (ERROR_CODE-0x01)
#endif

/**
 *\brief: MCU model check
 */
#if (defined __CONF_MCU_MODEL)
    #if IS_STC10_MCU_MODEL(__CONF_MCU_MODEL)
        #if (__CONF_MCU_MODEL == MCU_MODEL_GENERIC)
            #warning the value of macro HML_MCU_MODEL will be filled with MCU_MODEL_STC10F02XE
            #define HML_MCU_MODEL MCU_MODEL_STC10F02XE
        #else
            #define HML_MCU_MODEL __CONF_MCU_MODEL
        #endif
    #else
        #error HML run-time check: error: unknow or unsupported MCU model!(ERROR_CODE-0x02)
    #endif
#else
    #error HML run-time check: error: unspecify MCU model!(ERROR_CODE-0x03)
#endif

/**
 *\brief: HML compile selection check
 */
#if (defined __CONF_COMPILE_RCC) && (!defined __CONF_COMPILE_UTIL)
    #error HML run-time check: error: RCC depends on UTIL, please make sure to enable them it in conf.h (ERROR_CODE-0x04)
#endif

#ifdef __CONF_COMPILE_UART
    #if (!defined __CONF_COMPILE_RCC) || (!defined __CONF_COMPILE_TIM) || (!defined __CONF_COMPILE_UTIL)
        #error HML run-time check: error: UART epends on RCC, TIM and UTIL, please make sure to enable them all at the same time in conf.h. (ERROR_CODE-0x05)
    #endif
#endif

/**
 *\brief: SDCC version check
 */
#if (__SDCC_VERSION_MAJOR == 3)
    #if (__SDCC_VERSION_MINOR < 6)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x05)
    #endif
#else
    #if (__SDCC_VERSION_MAJOR < 3)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x05)
    #endif
#endif

#endif
