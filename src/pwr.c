/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations about power management
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */

#include "pwr.h"

#ifdef ___COMPILE_PWR___

/*
 * @Prototype:void PWR_idle(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:enter idle mode
 */
void PWR_idle(void)
{
    PCON = PCON | 0x01;
}

/*
 * @Prototype:void PWR_powerDown(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:make MCU enter power down mode
 */
void PWR_powerDown(void)
{
    PCON = PCON | 0x02;
}

/*
 * @Prototype:void PWR_LVD_clearFlag(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:clear LVDF bit in PCON register
 */
void PWR_LVD_clearFlag(void)
{
    PCON = PCON & 0xDF;
}

/*
 * @Prototype:void PWR_LVD_cmd(Action a)
 * @Parameter:(1)a:expected status
 * @Ret-val:None
 * @Note:enable or disable LVD(low voltage level detect) module
 */
void PWR_LVD_cmd(Action a)
{
    GPIO_P46_cmd(~a);
}

/*
 * @Prototype:FunctionalState PWR_LVD_getFlag(void)
 * @Parameter:None
 * @Ret-val:current value of LVDF bit
 * @Note:get value of LVDF bit in PCON register
 */
FunctionalState PWR_LVD_getFlag(void)
{
    return (FunctionalState)((PCON & 0x20) >> 0x5);
}

/*
 * @Prototype:void PWR_LVD_INT_cmd(Action a)
 * @Parameter:(1)a:expected status
 * @Ret-val:
 * @Note:enable or disable interrupt status of LVD(low voltage level detect) module
 */
void PWR_LVD_INT_cmd(Action a)
{
    ELVD = (FunctionalState)a;
}

/*
 * @Prototype:void PWR_PD_IE_cmd(PWR_PD_IEPIN pin,Action a)
 * @Parameter:(1)pin:target pin;(2)a:expected status
 * @Ret-val:
 * @Note:disable or enable one pin for waking up MCU from power down state
 */
void PWR_PD_IE_cmd(PWR_PD_IEPIN pin,Action a)
{
    switch(pin)
    {
        case PWR_PD_IEPIN_RXD:WAKE_CLKO = (WAKE_CLKO & 0xBF) | (a << 0x6);break;
        case PWR_PD_IEPIN_T0 :WAKE_CLKO = (WAKE_CLKO & 0xEF) | (a << 0x4);break;
        case PWR_PD_IEPIN_T1 :WAKE_CLKO = (WAKE_CLKO & 0xDF) | (a << 0x5);break;
        default:break;
    }
}

#endif
