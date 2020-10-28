/*****************************************************************************/
/** 
 * \file        macro.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML macro define
 * \note        
 * \version     v0.2
 * \ingroup     generic
******************************************************************************/

#ifndef ___HML_MACRO_H___
#define ___HML_MACRO_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/conf.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief mark MCU model of STC10 series
 *        - suffix 'E': with integrated EEPROM
 *        - suffix 'X': with integrated extended RAM 
 */

/**
 * \note  it seems that some models are actually exist on market, but we can't
 *        find them on current datasheet and disable their model macro via code
 *        comment
 */
#define MCU_MODEL_GENERIC         0x01
// #define MCU_MODEL_STC10F01E       0x02
// #define MCU_MODEL_STC10F01XE      0x03
// #define MCU_MODEL_STC10F02E       0x04
// #define MCU_MODEL_STC10F02XE      0x05
// #define MCU_MODEL_STC10L02XE      0x06
#define MCU_MODEL_STC10F04        0x07
#define MCU_MODEL_STC10L04        0x08
// #define MCU_MODEL_STC10F04E       0x09
#define MCU_MODEL_STC10F04XE      0x0A
#define MCU_MODEL_STC10L04XE      0x0B
#define MCU_MODEL_STC10F06        0x0C
#define MCU_MODEL_STC10L06        0x0D
#define MCU_MODEL_STC10F06XE      0x0E
#define MCU_MODEL_STC10L06XE      0x0F
#define MCU_MODEL_STC10F08        0x10
// #define MCU_MODEL_STC10F08E       0x11
#define MCU_MODEL_STC10F08XE      0x12
#define MCU_MODEL_STC10L08XE      0x13
#define MCU_MODEL_STC10F10        0x14
#define MCU_MODEL_STC10L10        0x15
#define MCU_MODEL_STC10F10XE      0x16
#define MCU_MODEL_STC10L10XE      0x17
#define MCU_MODEL_STC10F12        0x18
#define MCU_MODEL_STC10L12        0x19
#define MCU_MODEL_STC10F12XE      0x1A
#define MCU_MODEL_STC10L12XE      0x1B

/**
 * \note Following models support the function that all flash zone can be configured
 *       as EEPROM.
 *       In order to iron out name difference between Chinese revision datasheet and
 *       English revision, some model macro will be redirect to other macro.
 */
#define MCU_MODEL_IAP10F14X       0x1C
#define MCU_MODEL_IAP10L14X       0x1D
#define MCU_MODEL_STC10F14X       MCU_MODEL_IAP10F14X
#define MCU_MODEL_STC10L14X       MCU_MODEL_IAP10L14X

/**
 * \brief check macro for MCU model
 */
#define IS_STC10_MCU_MODEL(model)           \
    (                                       \
        (model == MCU_MODEL_GENERIC)     || \
        (model == MCU_MODEL_STC10F02XE)  || \
        (model == MCU_MODEL_STC10L02XE)  || \
        (model == MCU_MODEL_STC10F04)    || \
        (model == MCU_MODEL_STC10L04)    || \
        (model == MCU_MODEL_STC10F04XE)  || \
        (model == MCU_MODEL_STC10L04XE)  || \
        (model == MCU_MODEL_STC10F06)    || \
        (model == MCU_MODEL_STC10L06)    || \
        (model == MCU_MODEL_STC10F06XE)  || \
        (model == MCU_MODEL_STC10L06XE)  || \
        (model == MCU_MODEL_STC10F08)    || \
        (model == MCU_MODEL_STC10F08XE)  || \
        (model == MCU_MODEL_STC10L08XE)  || \
        (model == MCU_MODEL_STC10F10)    || \
        (model == MCU_MODEL_STC10L10)    || \
        (model == MCU_MODEL_STC10F10XE)  || \
        (model == MCU_MODEL_STC10L10XE)  || \
        (model == MCU_MODEL_STC10F12)    || \
        (model == MCU_MODEL_STC10L12)    || \
        (model == MCU_MODEL_STC10F12XE)  || \
        (model == MCU_MODEL_STC10L12XE)  || \
        (model == MCU_MODEL_IAP10F14X)   || \
        (model == MCU_MODEL_IAP10L14X)   || \
        (model == MCU_MODEL_STC10F14X)   || \
        (model == MCU_MODEL_STC10L14X)      \
    )

/**
 * \brief have macro for IAP function
 */
#define IS_IAP_MODEL(model)                 \
    (                                       \
        (model == MCU_MODEL_STC10F02XE)  || \
        (model == MCU_MODEL_STC10L02XE)  || \
        (model == MCU_MODEL_STC10F04XE)  || \
        (model == MCU_MODEL_STC10L04XE)  || \
        (model == MCU_MODEL_STC10F06XE)  || \
        (model == MCU_MODEL_STC10L06XE)  || \
        (model == MCU_MODEL_STC10F08XE)  || \
        (model == MCU_MODEL_STC10L08XE)  || \
        (model == MCU_MODEL_STC10F10XE)  || \
        (model == MCU_MODEL_STC10L10XE)  || \
        (model == MCU_MODEL_STC10F12XE)  || \
        (model == MCU_MODEL_STC10L12XE)  || \
        (model == MCU_MODEL_IAP10F14X)   || \
        (model == MCU_MODEL_IAP10L14X)      \
    )

/**
 * \brief compile select
 */
#if (__CONF_COMPILE_EXTI == 1)
    #define COMPILE_EXTI
#endif
#if (__CONF_COMPILE_GPIO == 1)
    #define COMPILE_GPIO
#endif
#if (__CONF_COMPILE_IAP == 1)
    #define COMPILE_IAP
#endif
#if (__CONF_COMPILE_MEM == 1)
    #define COMPILE_MEM
#endif
#if (__CONF_COMPILE_PWR == 1)
    #define COMPILE_PWR
#endif
#if (__CONF_COMPILE_EXTI == 1)
    #define COMPILE_EXTI
#endif
#if (__CONF_COMPILE_RCC == 1)
    #define COMPILE_RCC
#endif
#if (__CONF_COMPILE_TIM == 1)
    #define COMPILE_TIM
#endif
#if (__CONF_COMPILE_UART == 1)
    #define COMPILE_UART
#endif
#if (__CONF_COMPILE_UTIL == 1)
    #define COMPILE_UTIL
#endif
#if (__CONF_COMPILE_WDT == 1)
    #define COMPILE_WDT
#endif

/*****************************************************************************
 *                           run-time check                                  *
 *****************************************************************************/
/**
 * \brief MCU clock configuration check
 */
#if (defined __CONF_FRE_CLKIN)
    #define MCU_FRE_CLK __CONF_FRE_CLKIN
#else
    #error HML run-time check: error: HML need define input clock frequency! (ERROR_CODE-0x01)
#endif

/**
 * \brief MCU model check
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
    #error HML run-time check: error: please specify MCU model in conf.h!(ERROR_CODE-0x03)
#endif

#if IS_IAP_MODEL(HML_MCU_MODEL)
    #define HAVE_IAP
#endif

/**
 * \brief HML compile selection check
 */
#ifndef HAVE_IAP
    #ifdef COMPILE_IAP
        #error HML run-time check: error: specified MCU model does not support IAP function. (ERROR_CODE-0x04)
    #endif
#endif

#if (defined COMPILE_RCC) && (!defined COMPILE_UTIL)
    #error HML run-time check: error: RCC depends on UTIL, please make sure to enable them it in conf.h (ERROR_CODE-0x05)
#endif

#ifdef COMPILE_UART
    #if (!defined COMPILE_RCC) || (!defined COMPILE_TIM) || (!defined COMPILE_UTIL)
        #error HML run-time check: error: UART epends on RCC, TIM and UTIL, please make sure to enable them all at the same time in conf.h. (ERROR_CODE-0x06)
    #endif
#endif

/**
 * \brief SDCC version check
 */
#if (__SDCC_VERSION_MAJOR == 3)
    #if (__SDCC_VERSION_MINOR < 6)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x07)
    #endif
#else
    #if (__SDCC_VERSION_MAJOR < 3)
        #error HML run-time check: HML requires SDCC v3.6.0 or later versions (ERROR_CODE-0x07)
    #endif
#endif

#endif
