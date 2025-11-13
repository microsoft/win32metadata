#ifndef _PLATFORM_TYPES_H
#define _PLATFORM_TYPES_H
/**
 * @file
 *
 * This file defines basic platform-specific types for Windows
 */

/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#include <stddef.h>
#include <windows.h>

#if _MSC_VER >= 1600   /* MSVC 2010 or higher */
#include <stdint.h>
#else
typedef signed char int8_t;           ///< 8-bit signed integer.
typedef unsigned char uint8_t;        ///< 8-bit unsigned integer.
typedef signed short int16_t;         ///< 16-bit signed integer.
typedef unsigned short uint16_t;      ///< 16-bit unsigned integer.
typedef signed int int32_t;           ///< 32-bit signed integer.
typedef unsigned int uint32_t;        ///< 32-bit unsigned integer.
typedef signed long long int64_t;     ///< 64-bit signed integer.
typedef unsigned long long uint64_t;  ///< 64-bit unsigned integer.
#endif

#ifdef __cplusplus
namespace qcc {
typedef UINT_PTR SocketFd;      /**< Socket file descriptor type. */
typedef UINT_PTR UARTFd;        /**< UART file descriptor type. */
}
#else
typedef UINT_PTR qcc_SocketFd; /**< Socket file descriptor type. */
typedef UINT_PTR qcc_UARTFd;   /**< UART file descriptor type. */
#endif

/* Some windows header files define min and max as macros */
#undef min
#undef max

#ifndef PRIi64 /* From C9x inttypes.h */
/**
 * 64-bit signed integer from C9x inttypes.h
 */
#define PRIi64 "I64i"
/**
 * 64-bit unsigned integer from C9x inttypes.h
 */
#define PRIu64 "I64u"
#endif

#ifndef PRIuSIZET
/**
 * Platform pointer-sized unsigned integer (i.e., size_t)
 */
#define PRIuSIZET "Iu"
/**
 * Platform pointer-sized signed integer (i.e., ssize_t)
 */
#define PRIiSIZET "Id"
#endif

/**
 * Zero-terminated strings.
 * They also have better support for Microsoft's static code analysis in comparison to char*.
 */
typedef PSTR AJ_PSTR;
typedef PCSTR AJ_PCSTR;

#endif
