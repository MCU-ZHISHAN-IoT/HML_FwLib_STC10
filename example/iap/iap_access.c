/*****************************************************************************/
/** 
 * \file       iap_access.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       
 * \brief      a example which shows how to access IAP area
 * \note       
 * \version    v0.2
 * \ingroup    example
 * \remarks    test-board: TS51-V2.0; test-MCU: STC10F08XE
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/
#define IAP_ADDR_TEST IAP_ADDR_START    /* mark target area */   

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

    uc.baudrate                    = 9600;                           /* baud rate is 9600bps */
    uc.baudrateGenerator           = UART_baudrateGenerator_brt;     /* select BRT as baud rate generator */
    uc.baudGeneratorPrescalerState = ENABLE;
    uc.interruptState              = ENABLE;
    uc.interruptPriority           = DISABLE;
    uc.mode                        = UART_mode_1;
    uc.multiBaudrate               = DISABLE;
    uc.pinmap                      = UART_pinmap_0;
    uc.receiveState                = ENABLE;

    UART_config(&uc);
    IAP_cmd(ENABLE);
}

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       transfer byte data to hex string
 * \param[in]   src: the byte of date which is going to transfer
 * \param[out]  res: a pinter to the area for storing result
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void util_byteToHexString(byte src, char *res)
{
    uint8_t i = 2;
    byte tmp = 0;

    res = res + 2;
    *res = '\0';

    while (i--)
    {
        res--;
        tmp = src % 0x10;

        if (tmp < 10)
        {
            *res = '0' + tmp;
        }
        else
        {
            *res = 'A' + (tmp - 0x0A);
        }
        src = src / 0x10;
    }

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
    char accessResult[3];                             /* store results */
    byte __code test_data[3] = {0x20, 0x19, 0x04};    /* test data */
    uint8_t i = 0;

    sys_init();
    UART_sendString("MCU boot...\r\n\0");

    while (true)
    {
        for (i = 0; i < 3; i++)
        {
            IAP_eraseByte(IAP_ADDR_TEST+i);      /* it's necessary step */
            /* write */
            if (IAP_writeByte(IAP_ADDR_TEST + i, test_data[i]))
            {
                UART_sendString("Succeeded to write test byte\r\n\0");
            }
            else
            {
                UART_sendString("Fail to write test byte\r\n\0");
            }

            /* read and show access result */
            util_byteToHexString(IAP_readByte(IAP_ADDR_TEST + i), accessResult);
            UART_sendString("Access result: 0x");
            UART_sendString(accessResult);
            UART_sendString("\r\n\0");
            sleep(1000);
        }
        i = 0;
    }
}
