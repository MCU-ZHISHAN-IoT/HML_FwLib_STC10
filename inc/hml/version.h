/*****************************************************************************/
/** 
 * \file        version.h
 * \author      Weilun Fong | wlf@zhishan-iot.tk
 * \brief       HML version information
 * \note        
 * \version     v0.2
 * \ingroup     VERSION
******************************************************************************/

#ifndef ___HML_VERSION_H___
#define ___HML_VERSION_H___

/*****************************************************************************
 *                                macro                                      *
 *****************************************************************************/

/**
 * \brief string literal representation of the current library name
 */
#define __HML_NAME_STRING__ "HML_FwLib_STC10"

/**
 * \brief string literal representation of the current library version
 */
#define __HML_VERSION_STRING__ "0.2.1"

/**
 * \deprecated these macro will be abolished in next minor version
 */
#define HML_VERSION_CODE "0.2.1"
#define HML_VERSION_NAME "HML_FwLib_STC10"

/**
 * \brief
 * Numerical representation of the current library version.
 *
 * In the numerical representation, the major number is multiplied by
 * 10000, the minor number by 100, and all three parts are then
 * added.  It is intented to provide a monotonically increasing
 * numerical value that can easily be used in numerical checks.
 */
#define __HML_VERSION__ 000201UL

/**
 * \brief string literal representation of the release date.
 */
#define __HML_DATE_STRING__ "20201029"

/**
 * \brief numerical representation of the release date.
 */
#define __HML_DATE__ 20201029UL

/**
 * \brief library major version number.
 */
#define __HML_VERSION_MAJOR__ 0

/**
 * \brief library minor version number.
 */
#define __HML_VERSION_MINOR__ 2

/**
 * \brief library patch version number.
 */
#define __HML_VERSION_PATCH__ 1

/**
 * \deprecated following macro will be abolished in next minor version
 */
#ifdef HML_VERSION_MAJOR
    #undef HML_VERSION_MAJOR
#endif
#define HML_VERSION_MAJOR 0

#ifdef HML_VERSION_MINOR
    #undef HML_VERSION_MINOR
#endif
#define HML_VERSION_MINOR 2

#ifdef HML_VERSION_PATCH
    #undef HML_VERSION_PATCH
#endif
#define HML_VERSION_PATCH 1

#endif
