/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operate on-chip GPIO module
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */
 
#ifndef ___GPIO_H___
#define ___GPIO_H___
 
/* ----- @header file ----- */
#include "stc10.h"
#include "macro.h"
 
/* ----- @enumeration type ----- */
/* define port */
typedef enum
{
    PERIPH_GPIO_0 = 0x0,
    PERIPH_GPIO_1 = 0x1,
    PERIPH_GPIO_2 = 0x2,
    PERIPH_GPIO_3 = 0x3,
    PERIPH_GPIO_4 = 0x4
} PERIPH_GPIO;

/* define pin */
typedef enum
{
    PERIPH_GPIO_PIN_0 = 0x01,
    PERIPH_GPIO_PIN_1 = 0x02,
    PERIPH_GPIO_PIN_2 = 0x04,
    PERIPH_GPIO_PIN_3 = 0x08,
    PERIPH_GPIO_PIN_4 = 0x10,
    PERIPH_GPIO_PIN_5 = 0x20,
    PERIPH_GPIO_PIN_6 = 0x40,
    PERIPH_GPIO_PIN_7 = 0x80
} PERIPH_GPIO_PIN;

/* mark input/output mode */
typedef enum
{
    GPIO_mode_HIS = 0x2,     /* high-impedance state */
    GPIO_mode_OD  = 0x3,     /* open drain output */
    GPIO_mode_PP  = 0x1,     /* push-pull output */
    GPIO_mode_QBD = 0x0      /* quasi-bidirectional(be compatible with classical 8051 MCUs) */
} GPIO_mode;

/* ----- @structure define ----- */
/* a structure for GPIO configuration */
typedef struct
{
    FunctionalState value;
    GPIO_mode       mode;
    PERIPH_GPIO_PIN pin;
} GPIO_configTypeDef;

/* ----- @function ----- */
void GPIO_config(PERIPH_GPIO gpio,GPIO_configTypeDef *gc);
void GPIO_configBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin,FunctionalState f);
void GPIO_configMode(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin,GPIO_mode mode);
void GPIO_configPortValue(PERIPH_GPIO gpio,byte val);
FunctionalState GPIO_getBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
unsigned char GPIO_getPortValue(PERIPH_GPIO gpio);
void GPIO_resetBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_setBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_toggleBitValue(PERIPH_GPIO gpio,PERIPH_GPIO_PIN pin);
void GPIO_P44_cmd(Action a);
void GPIO_P45_cmd(Action a);
void GPIO_P46_cmd(Action a);

#endif
