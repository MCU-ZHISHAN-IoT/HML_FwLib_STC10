/*****************************************************************************/
/** 
 * \file       mem_getFactoryClockData.c
 * \author     Weilun Fong | wlf@zhishan-iot.tk
 * \date       
 * \brief      a example which shows how to get frequency of the factory RC clock
 *             from internal RAM
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
/**
 *\brief: mark address
 */
#define ADDR_RAM_FACTORY_RC_CLK 0xFC

/*****************************************************************************/
/** 
 * \author      Weilun Fong
 * \date        
 * \brief       initial MCU
 * \param[out]  dat: pointer to the area for storing data
 * \return      none
 * \ingroup     example
 * \remarks     get factory clock data from internal RAM(address is 0xFC~0xFF)
******************************************************************************/
void app_getFactoryClockData(byte *dat)
{
    uint8_t i = 0;

    /**
     * \note the data is stored in a specified area, address range of the ara is
     *       from 0xFC to 0xFF in internal RAM of STC10 MCU
     */
    for(i = 0;i < 4;i++)
    {
        dat[i] = __PBYTE[ADDR_RAM_FACTORY_RC_CLK + i];
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
void util_byteToHexString(byte src,char *res)
{
    uint8_t i = 2;
    byte tmp  = 0x00;

    res = res + 2;
    *res = '\0';

    while(i--)
    {
        res--;
        tmp = src % 0x10;

        if(tmp < 10)
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
    byte accessResult[4];    /* store results */
    char buffer[2];
    uint8_t i = 0;

    sys_init();

    while(true)
    {  
        app_getFactoryClockData(accessResult);   /* get data */
        UART_sendString("Access result:");

        /* show data */
        for(i= 0;i < 4;i++)
        {
            UART_sendString(" 0x");
            util_byteToHexString(accessResult[i],buffer);
            UART_sendString(buffer);
        }
        UART_sendString("\r\n");
        sleep(1000);    /* gap time */
    }
}
