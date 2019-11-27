/*****************************************************************************/
/** 
 * \file       uart_sendString_brt_12t.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       
 * \brief      a example which shows how to send string via UART which works on
 *             12T mode and used BRT as baud rate generator
 * \note       
 * \version    v0.2
 * \ingroup    example
 * \remarks    test-board: TS51-V2.0; test-MCU: STC10F08XE
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    UART_configTypeDef uc;
    
    uc.baudrate                    = 9600;                          /* baud rate is 9600bps */
    uc.baudrateGenerator           = UART_baudrateGenerator_brt;    /* select BRT as baud rate generator */
    uc.baudGeneratorPrescalerState = ENABLE;                        /* 12T mode */
    uc.interruptState              = ENABLE;
    uc.interruptPriority           = DISABLE;
    uc.mode                        = UART_mode_1;
    uc.multiBaudrate               = DISABLE;
    uc.pinmap                      = UART_pinmap_0;
    uc.receiveState                = ENABLE;

    UART_config(&uc);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void main(void)
{    
    sys_init();

    while(true)
    {
        /* send per 500ms */
        sleep(500);
        UART_sendString("Hello,world!\r\n");
    }
}
