/*****************************************************************************/
/** 
 * \file        util.h
 * \author      Weillun Fong | wlf@zhishan-iot.tk
 * \brief       public interface
 * \note        
 * \version     v0.2
 * \ingroup     UTIL
******************************************************************************/

#ifndef ___HML_UTIL_H___
#define ___HML_UTIL_H___

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include <compiler.h>
/*****************************************************************************/
#include "hml/stc10.h"
#include "hml/macro.h"
#include "hml/types.h"

/*****************************************************************************
 *                          function declare                                 *
 *****************************************************************************/
void disableAllInterrupts(void);
void enableAllInterrupts(void);
void sleep(uint16_t t);

#ifdef HAVE_HML_POW
uint16_t pow(uint8_t x, uint8_t y);
#endif

#endif
