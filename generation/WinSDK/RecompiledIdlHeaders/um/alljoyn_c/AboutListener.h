/**
 * @file
 * alljoyn_aboutlistener provides a callback for the org.alljoyn.About.Announce signal.
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
#ifndef _ALLJOYN_ABOUTLISTENER_C_H
#define _ALLJOYN_ABOUTLISTENER_C_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/MsgArg.h>
#include <alljoyn_c/Session.h>
#include <alljoyn_c/SessionListener.h>
#include <alljoyn_c/SessionPortListener.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_aboutlistener is called by AllJoyn to inform users of About interface
 * related events.
 */
typedef struct _alljoyn_aboutlistener_handle* alljoyn_aboutlistener;

/**
 * Callback type for the handler of an org.alljoyn.About.Anounce sessionless signal.
 *
 * The objectDescriptionArg contains an array with a signature of `a(oas)`
 * this is an array object paths with a list of interfaces found at those paths.
 *
 * The aboutDataArg contains a dictionary with About data fields that have been
 * announced. These fields are the following:
 * - AppId
 * - DefaultLanguage
 * - DeviceName
 * - DeviceId
 * - AppName
 * - Manufacturer
 * - ModelNumber
 *
 * The DeviceName is optional and is allowed to not be included in the aboutDataArg.
 *
 * DeviceName, AppName, Manufacturer are localizable values. The localization
 * for these values in the aboutDataArg will always be for the language specified
 * in the DefaultLanguage field.
 *
 * @param[in] context               the context pointer that was passed into the
 *                                  alljoyn_aboutlistener_create function
 * @param[in] busName               well known name of the remote BusAttachment
 * @param[in] version               version of the Announce signal from the remote About Object
 * @param[in] port                  session port used by the announcer
 * @param[in] objectDescriptionArg  the list of object paths and interfaces in the announcement
 * @param[in] aboutDataArg          alljoyn_msgarg containing a dictionary of Key/Value pairs of the About data
 */
typedef void (AJ_CALL * alljoyn_about_announced_ptr)(const void* context,
                                                     const char* busName,
                                                     uint16_t version,
                                                     alljoyn_sessionport port,
                                                     const alljoyn_msgarg objectDescriptionArg,
                                                     const alljoyn_msgarg aboutDataArg);

/**
 * The callback used for creation of an alljoyn_aboutlistener.
 */
typedef struct {
    /**
     * handler for the org.alljoyn.About.Anounce sessionless signal
     */
    alljoyn_about_announced_ptr about_listener_announced;
} alljoyn_aboutlistener_callback;


/**
 * Allocate a new alljoyn_aboutlistener.
 * @param callback Callback to trigger for About interface associated events.
 * @param context  Context to pass along to callback functions.
 * @return allocated alljoyn_aboutlistener
 */
extern AJ_API alljoyn_aboutlistener AJ_CALL alljoyn_aboutlistener_create(const alljoyn_aboutlistener_callback* callback,
                                                                         const void* context);

/**
 * Free an alljoyn_aboutlistener.
 */
extern AJ_API void AJ_CALL alljoyn_aboutlistener_destroy(alljoyn_aboutlistener listener);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //_ALLJOYN_ABOUTLISTENER_C_H
