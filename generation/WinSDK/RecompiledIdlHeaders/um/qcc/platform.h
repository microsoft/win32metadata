#ifndef _QCC_PLATFORM_H
#define _QCC_PLATFORM_H
/**
 * @file
 *
 * This file just wraps including actual OS and toolchain specific header
 * files depding on the OS group setting.
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

#if defined(QCC_OS_GROUP_POSIX)
#include <qcc/posix/platform_types.h>
#elif defined(QCC_OS_GROUP_WINDOWS)
#include <qcc/windows/platform_types.h>
#include <qcc/windows/mapping.h>

/*
 * This pragma prevents Microsoft compiler warning C4407: cast between different pointer to member representations, compiler may generate incorrect code.
 * This is equivalent to /vmm and /vmg compiler options but without the burden of requiring all apps to specify these non-default options.
 */
#pragma pointers_to_members(full_generality, virtual_inheritance)
#else
#error No OS GROUP defined.
#endif

/**
 * Platform-independent assertion macro. If this is not defined in the
 * platform-specific header file or by other preprocessor define, it defaults
 * to assert.
 */
#ifndef QCC_ASSERT
#include <assert.h>
#define QCC_ASSERT(expr) assert(expr)
#endif

#if defined(__GNUC__)

#define GCC_VERSION ((__GNUC__ * 10000) + (__GNUC_MINOR__ * 100) + __GNUC_PATCHLEVEL__)
#if (GCC_VERSION < 40700L)
/*
 * Versions of GCC prior to 4.7.0 have an annoying but intentional bug where
 * __cplusplus is set to 1 rather than the appropriate date code so that it
 * would be compatible with Solaris 8.
 */

#if (GCC_VERSION >= 40600L) && defined(__GXX_EXPERIMENTAL_CXX0X__)
/*
 * GCC 4.6.x supports C++11, at least in terms of unordered_map, etc. when the
 * -std=gnu++0x option is passed in.  Thus, fix the value of __cplusplus.
 */
#undef __cplusplus
#define __cplusplus 201100L
#endif  // GCC version >= 4.6 and -std=gnu++0x
#endif  // GCC version < 4.7



#if (__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1))
#define QCC_DEPRECATED(func) func __attribute__((deprecated)) /**< mark a function as deprecated in gcc. */
#define QCC_DEPRECATED_ON(func, date) QCC_DEPRECATED(func) /**< same as above but with date of the AllJoyn release applying this macro (date format: YY.MM). */
#define QCC_DEPRECATED_CLASS __attribute__((deprecated)) /**< mark a class as deprecated in qcc. */
#define QCC_DEPRECATED_CLASS_ON(date) QCC_DEPRECATED_CLASS /**< same as above but with date of the AllJoyn release applying this macro (date format: YY.MM). */

#if (GCC_VERSION >= 40500L)
#define QCC_DEPRECATED_MSG(func, msg, date) func __attribute__((deprecated(msg))) /**< same as QCC_DEPRECATED_ON, but with user-defined text message to be displayed. */
#define QCC_DEPRECATED_CLASS_MSG(msg, date) __attribute__((deprecated(msg))) /**< same as QCC_DEPRECATED_CLASS_ON, but with user-defined text message to be displayed. */
#else
#define QCC_DEPRECATED_MSG(func, msg, date) QCC_DEPRECATED_ON(func, date) /**< gcc versions older than 4.5 do not support the text message. */
#define QCC_DEPRECATED_CLASS_MSG(msg, date) QCC_DEPRECATED_CLASS_ON(date) /**< gcc versions older than 4.5 do not support the text message. */
#endif // GCC version >= 4.5

#else
#define QCC_DEPRECATED(func) func /**< not all gcc versions support the deprecated attribute. */
#define QCC_DEPRECATED_ON(func, date) func /**< not all gcc versions support the deprecated attribute. */
#define QCC_DEPRECATED_CLASS /**< not all gcc versions support the deprecated attribute. */
#define QCC_DEPRECATED_CLASS_ON(date) /**< not all gcc versions support the deprecated attribute. */
#define QCC_DEPRECATED_MSG(func, msg, date) func /**< not all gcc versions support the deprecated attribute. */
#define QCC_DEPRECATED_CLASS_MSG(msg, date) /**< not all gcc versions support the deprecated attribute. */
#endif // GCC version >= 3.1


#elif defined(_MSC_VER)

#define QCC_DEPRECATED(func) __declspec(deprecated) func /**< mark a function as deprecated in msvc. */
#define QCC_DEPRECATED_ON(func, date) QCC_DEPRECATED(func) /**< same as above but with date of the AllJoyn release applying this macro (date format: YY.MM). */
#define QCC_DEPRECATED_CLASS __declspec(deprecated) /**< mark a class as deprecated in msvc. */
#define QCC_DEPRECATED_CLASS_ON(date) QCC_DEPRECATED_CLASS /**< same as above but with date of the AllJoyn release applying this macro (date format: YY.MM). */
#define QCC_DEPRECATED_MSG(func, msg, date) __declspec(deprecated(msg)) func /**< same as QCC_DEPRECATED_ON, but with user-defined text message to be displayed. */
#define QCC_DEPRECATED_CLASS_MSG(msg, date) __declspec(deprecated(msg)) /**< same as QCC_DEPRECATED_CLASS_ON, but with user-defined text message to be displayed. */
#else /* Some unknown compiler */

#define QCC_DEPRECATED(func) func
#define QCC_DEPRECATED_ON(func, date) func
#define QCC_DEPRECATED_CLASS
#define QCC_DEPRECATED_CLASS_ON(date)
#define QCC_DEPRECATED_MSG(func, msg, date) func
#define QCC_DEPRECATED_CLASS_MSG(msg, date)

#endif /* Compiler type */

/**
 * Macro used to avoid unused variable warning in release code.
 * This Macro is only used when a variable is only used in the debug build
 * variant. When building in release mode the compiler will give an unused
 * variable warning.
 *
 * Example usage:
   @code
     String errMsg
     const char* errName = reply->GetErrorName(&errMsg);
     QCC_LogError(status, ("TimedPing returned ERROR_MESSAGE (error=%s, \"%s\")", errName, errMsg.c_str()));
     QCC_UNUSED(errName); // avoid unused variable warning in release build
   @endcode
 *
 * The `QCC_LogError` is an empty macro for release build variants but in debug
 * build variants it is not empty so it uses the errName variable.
 */
#define QCC_UNUSED(x) (void)(x)

#if defined(_MSC_VER)
//disable 'conditional expression is constant' warning to use do{ ... }while(0)
#pragma warning( disable: 4127 )
#endif

/** Boolean type for C */
typedef int32_t QCC_BOOL;
/** Boolean logic true for QCC_BOOL type*/
#define QCC_TRUE 1
/** Boolean logic false for QCC_BOOL type*/
#define QCC_FALSE 0

/** This @#define allows for calling convention redefinition on relevant platforms */
#ifndef AJ_CALL
#  if defined(QCC_OS_GROUP_WINDOWS)
#    define AJ_CALL __stdcall
#  else
#    define AJ_CALL
#  endif
#endif

#endif // _QCC_PLATFORM_H
