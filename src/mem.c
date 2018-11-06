/*
 * @Author:
 *  #Weilun Fong | wlf(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:
 * #contains definitions that allow you to directly access the different memory areas of the 8051.
 * #have the similar functions like <absacc.h> in Keil
 * @Required-compiler:SDCC
 * @Support-mcu:Intel MCS-51 based microprocessors
 * @Version:V0
 */

#include "mem.h"

#ifdef ___COMPILE_MEM___

/*
 * @Prototype:void MEM_cmd_ale(Action a)
 * @Parameter:(1)a:expected state
 * @Ret-val:None
 * @Note:enable or disable ALE pin
 */
void MEM_cmd_ale(Action a)
{
	GPIO_P45_cmd(~a);
}

/*
 * @Prototype:void MEM_cmd_internalExtendedRam(Action a)
 * @Parameter:(1)a:expected state
 * @Ret-val:
 * @Note:enable or disable internal extended RAM access
 *  > there is a RAM area integrated insides STC90 MCUs and it's independent in physics
 *  > if you enable this function,this area will occupy address zone in the beginning(RD+ series is 0000H~03FFH(1024 bytes),RC series is 0000H~00FFH(256 bytes));or this RAM area is hide,the MCU is as same as classical 8051 MCU now
 *  > if you want to enable this function,please remember select the option in STC-ISP
 */
void MEM_cmd_internalExtendedRam(Action a)
{
	AUXR = (AUXR & 0xFD) | ((~a) << 0x1);
}

#endif

