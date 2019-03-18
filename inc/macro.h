/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.tk
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:include some important macro
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */

#ifndef ___MACRO_H___
#define ___MACRO_H___

/* ----- @type define ----- */
typedef unsigned char byte;
typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned int  word;

/* ----- @enumeration type ----- */
/* mark user action */
typedef enum
{
    DISABLE = 0x0,
    ENABLE  = !DISABLE
} Action;

/* mark bit value/state */
typedef enum
{
    RESET = 0x0,
    SET   = !RESET
} FunctionalState;

/* ----- @macro ----- */
/* mark model */
#define _MCU_NULL_           0
#define _MCU_STC10F02XE_     1
#define _MCU_STC10L02XE_     1
#define _MCU_STC10F04XE_     2
#define _MCU_STC10L04XE_     2
#define _MCU_STC10F06XE_     3
#define _MCU_STC10L06XE_     3
#define _MCU_STC10F08XE_     4
#define _MCU_STC10L08XE_     4
#define _MCU_STC10F10XE_     5
#define _MCU_STC10L10XE_     5
#define _MCU_STC10F12XE_     6
#define _MCU_STC10L12XE_     6
#define _MCU_IAP10F14X_      7
#define _MCU_IAP10L14X_      7

/* ---------- NEED TO CONFIG MANUALLY !!! ---------- */
/* configure MCU model, default value is MCU_STC10F02XE */
#define _MCU_MODEL_ _MCU_STC10F02XE_

/* configure input clock frequency */
#define _FRE_OSC_ 11059200L
//#define _FRE_OSC_ 12000000L

/* select the part you need  compile due to limited store zone of MCU */
#define ___COMPILE_EXTI___
#define ___COMPILE_GPIO___
#define ___COMPILE_IAP___
#define ___COMPILE_MEM___
#define ___COMPILE_PWR___
#define ___COMPILE_RCC___
#define ___COMPILE_TIM___
#define ___COMPILE_UART___
#define ___COMPILE_UTIL___
#define ___COMPILE_WDT___

/* ---------- END OF MANUAL CONFIGURATON PART --------- */

/* ---------- @run-time check --------- */
#if (_MCU_MODEL_ == _MCU_NULL_)
    #error HML run-time check:not specify MCU model! (ERROR_CODE-0x01)
#endif

#ifndef _FRE_OSC_
    #error HML run-time check:the firmware library need define extern clcok frequency! (ERROR_CODE-0x02)
#endif

#if (defined ___COMPILE_PWR___) && (!defined ___COMPILE_GPIO___)
    #error HML run-time check:PWR part need sextern part GPIO, please enable macro define ___COMPILE_GPIO___ (ERROR_CODE-0x04)
#endif

#if (defined ___COMPILE_RCC___) && (!defined ___COMPILE_UTIL___)
    #error HML run-time check:RCC part need extern part UTIL, please make sure enable them all (ERROR_CODE-0x05)
#endif

#ifdef ___COMPILE_UART___
    #if (!defined ___COMPILE_RCC___) || (!defined ___COMPILE_TIM___) || (!defined ___COMPILE_UTIL___)
        #error HML run-time check:UART part need extern part RCC, TIM and UTIL, please make sure enable them all (ERROR_CODE-0x06)
    #endif
#endif

/* ---------- ---------- */

#endif
