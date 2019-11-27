/*****************************************************************************/
/** 
 * \file        iap.h
 * \author      Jiabin Hsu | zsiothsu@zhishan-iot.tk
 * \brief       operations for IAP module
 * \note        
 * \version     v0.3
 * \ingroup     IAP
******************************************************************************/

#ifndef ___HML_IAP_H___
#define ___HML_IAP_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/util.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 *\brief: define IAP address
 */
#define IAP_ADDR_START 0x0000

#if (HML_MCU_MODEL == MCU_MODEL_STC10F02XE)   || \
    (HML_MCU_MODEL == MCU_MODEL_STC10L02XE)   || \
    (HML_MCU_MODEL == MCU_MODEL_STC10F04XE)   || \
    (HML_MCU_MODEL == MCU_MODEL_STC10L04XE)   || \
    (HML_MCU_MODEL == MCU_MODEL_STC10F06XE)   || \
    (HML_MCU_MODEL == MCU_MODEL_STC10L06XE)   || \
    (HML_MCU_MODEL == MCU_MODEL_STC10F08XE)   || \
    (HML_MCU_MODEL == MCU_MODEL_STC10L08XE)
        #define IAP_ADDR_END 0x13FF
#elif (HML_MCU_MODEL == MCU_MODEL_STC10F10XE) || (HML_MCU_MODEL == MCU_MODEL_STC10L10XE)
    #define IAP_ADDR_END 0x0BFF
#elif (HML_MCU_MODEL == MCU_MODEL_STC10F12XE) || (HML_MCU_MODEL == MCU_MODEL_STC10L12XE)
      #define IAP_ADDR_END 0x03FF
#elif (HML_MCU_MODEL == MCU_MODEL_IAP10F14X)  || (HML_MCU_MODEL == MCU_MODEL_IAP10L14X)
      #define IAP_ADDR_END 0x37FF
#endif

/*****************************************************************************
 *                           enumeration type                                *
 *****************************************************************************/

/**
 *\brief: define IAP command
 */
typedef enum
{
    IAP_command_idle  = 0x0,
    IAP_command_read  = 0x1,
    IAP_command_write = 0x2,
    IAP_command_erase = 0x3
} IAP_command;

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void IAP_cmd(Action a);
bool IAP_eraseByte(uint16_t addr);
void IAP_idle(void);
bool IAP_isSuccess(void);
byte IAP_readByte(uint16_t addr);
void IAP_setAddress(uint16_t addr);
void IAP_setCommand(IAP_command cmd);
void IAP_trig(void);
bool IAP_writeByte(uint16_t addr,byte dat);

#endif
