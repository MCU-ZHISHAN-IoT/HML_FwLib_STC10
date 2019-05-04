/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations for watch dog resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC10 series
 * @Version:V0
 */
 
#include "wdt.h"

#ifdef ___COMPILE_WDT___

/*
 * @Prototype:void WDT_clear(void)
 * @Parameter:
 * @Ret-val:
 * @Note:feeds the watch dog 
 */
void WDT_clear(void)
{
    SET_BIT_MASK(WDT_CONTR,CLR_WDT);
}

/*
 * @Prototype:void WDT_cmd(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:launch or stop watch dog
 */
void WDT_cmd(Action a)
{
    CONFB(WDT_CONTR,BIT_NUM_EN_WDT,a);
}

/*
 * @Prototype:void WDT_cmd_idleCount(Action a)
 * @Parameter:(1)a:expected action
 * @Ret-val:
 * @Note:enable or disable watch dog when during mode
 */
void WDT_cmd_idleCount(Action a)
{
    CONFB(WDT_CONTR,BIT_NUM_IDLE_WDT,a);
}

/*
 * @Prototype:void WDT_setPrescale(WDT_prescale pre)
 * @Parameter:(1)pre:prescale factor
 * @Ret-val:
 * @Note:set prescale
 */
void WDT_setPrescale(WDT_prescale pre)
{
    WDT_CONTR = (WDT_CONTR & 0xF8) | pre;
}

#endif
