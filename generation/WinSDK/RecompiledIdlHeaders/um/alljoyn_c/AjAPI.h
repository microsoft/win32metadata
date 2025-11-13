/**
 * @file
 * This file defines the attributes of exported functions.
 *
 * This file also defines the deferred callback mechanism used to make sure the
 * callbacks occur on the same thread that registered for the callback.
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
#ifndef _ALLJOYN_C_AJAPI_H
#define _ALLJOYN_C_AJAPI_H

#if defined(QCC_OS_GROUP_POSIX)
#include <qcc/posix/platform_types.h>
#elif defined(QCC_OS_GROUP_WINDOWS)
#include <qcc/windows/platform_types.h>
#include <qcc/windows/mapping.h>
#else
#error No OS GROUP defined.
#endif


/**
 * --------------------------------------------------------------------------
 * Note: ensure this portion matches the C++ binding <qcc/platform.h>
 */

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

#if (GCC_VERSION >= 40500L)
#define QCC_DEPRECATED_MSG(func, msg, date) func __attribute__((deprecated(msg))) /**< same as QCC_DEPRECATED_ON, but with user-defined text message to be displayed. */
#else
#define QCC_DEPRECATED_MSG(func, msg, date) QCC_DEPRECATED_ON(func, date) /**< gcc versions older than 4.5 do not support the text message. */
#endif // GCC version >= 4.5

#else
#define QCC_DEPRECATED(func) func /**< not all gcc versions support the deprecated attribute. */
#define QCC_DEPRECATED_ON(func, date) func /**< not all gcc versions support the deprecated attribute. */
#endif // GCC version >= 3.1

#elif defined(_MSC_VER)

#define QCC_DEPRECATED(func) __declspec(deprecated) func /**< mark a function as deprecated in msvc. */
#define QCC_DEPRECATED_ON(func, date) QCC_DEPRECATED(func) /**< same as above but with date of the AllJoyn release applying this macro (date format: YY.MM). */
#define QCC_DEPRECATED_MSG(func, msg, date) __declspec(deprecated(msg)) func /**< same as QCC_DEPRECATED_ON, but with user-defined text message to be displayed. */

#else /* Some unknown compiler */

#define QCC_DEPRECATED(func) func
#define QCC_DEPRECATED_ON(func, date) func
#define QCC_DEPRECATED_MSG(func, msg, date) func

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


/**
 * End <qcc/platform.h> match
 * --------------------------------------------------------------------------
 */


/**
 * This @#define allows for setting of visibility support on relevant platforms
 */
#ifndef AJ_API
#  if defined(QCC_OS_GROUP_POSIX)
#    define AJ_API __attribute__((visibility("default")))
#  else
#    define AJ_API
#  endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Used to specify if an interface is part of an About announcement or not.
 */
typedef enum {
    UNANNOUNCED, ///< The interface is not announced
    ANNOUNCED    ///< The interface is announced
} alljoyn_about_announceflag;

/**
 * Unity-specific function to process alternate-thread callbacks on the main thread.
 *
 * @return the number of callbacks processed.
 */
extern AJ_API int AJ_CALL alljoyn_unity_deferred_callbacks_process();

/**
 * Enable/disable main thread callback behavior.
 */
extern AJ_API void AJ_CALL alljoyn_unity_set_deferred_callback_mainthread_only(QCC_BOOL mainthread_only);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
