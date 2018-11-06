/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:includes some definitions for operating IAP module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */

#ifndef ___IAP_H___
#define ___IAP_H___

/* ----- @header file ----- */
#include <stc10.h>
#include <stdbool.h>
#include "util.h"
#include "macro.h"

/* mark command of IAP */
typedef enum
{
    IAP_command_idle  = 0x0,
    IAP_command_read  = 0x1,
    IAP_command_write = 0x2,
    IAP_command_erase = 0x3
} IAP_command;

/* ---------- address define --------- */
#define IAP_ADDR_START 0x0000

#if (_MCU_MODEL_ == _MCU_STC10F02XE_) || \
    (_MCU_MODEL_ == _MCU_STC10L02XE_) || \
    (_MCU_MODEL_ == _MCU_STC10F04XE_) || \
    (_MCU_MODEL_ == _MCU_STC10L04XE_) || \
    (_MCU_MODEL_ == _MCU_STC10F06XE_) || \
    (_MCU_MODEL_ == _MCU_STC10L06XE_) || \
    (_MCU_MODEL_ == _MCU_STC10F08XE_) || \
    (_MCU_MODEL_ == _MCU_STC10L08XE_)
    #define IAP_ADDR_END 0x13FF
#else
    #if (_MCU_MODEL_ == _MCU_STC10F10XE_)   || \
        (_MCU_MODEL_ == _MCU_STC10L10XE_)
        #define IAP_ADDR_END 0x0BFF
    #elif (_MCU_MODEL_ == _MCU_STC10F12XE_) || \
          (_MCU_MODEL_ == _MCU_STC10L12XE_)
          #define IAP_ADDR_END 0x03FF
    #elif (_MCU_MODEL_ == _MCU_IAP10F14X_)  || \
          (_MCU_MODEL_ == _MCU_IAP10L14X_)
          #define IAP_ADDR_END 0x37FF
    #endif
#endif

/* ----- @function ----- */
void IAP_cmd(Action a);
bool IAP_eraseByte(unsigned int addr);
void IAP_idle(void);
bool IAP_isSuccess(void);
byte IAP_readByte(unsigned int addr);
void IAP_setAddress(unsigned int addr);
void IAP_setCommand(IAP_command cmd);
void IAP_trig(void);
bool IAP_writeByte(unsigned int addr,byte dat);

#endif