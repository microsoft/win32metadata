/**
 * @file
 * This file defines the alljoyn_applicationstatelistener and related functions that provide
 * the callback to react to the application state changes.
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

#ifndef _ALLJOYN_C_APPLICATIONSTATELISTENER_H
#define _ALLJOYN_C_APPLICATIONSTATELISTENER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Status.h>
#include <alljoyn_c/PermissionConfigurator.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_applicationstatelistener is a handle which allows receiving
 * the org.alljoyn.Bus.Application State signal
 */
typedef struct _alljoyn_applicationstatelistener_handle* alljoyn_applicationstatelistener;

/**
 * Type for the ApplicationState callback.
 *
 * Handler for the org.allseen.Bus.Application's State sessionless signal.
 *
 * @param[in] busName           Unique name of the remote BusAttachment that sent the State signal.
 * @param[in] publicKey         The remote application's public key in PEM format.
 * @param[in] applicationState  The application state.
 * @param[in] context           Application context that was passed in "alljoyn_applicationstatelistener_create".
 */
typedef void (AJ_CALL * alljoyn_applicationstatelistener_state_ptr)(AJ_PCSTR busName,
                                                                    AJ_PCSTR publicKey,
                                                                    alljoyn_applicationstate applicationState,
                                                                    void* context);

/**
 * Structure used during alljoyn_applicationstatelistener_callbacks_create to provide callbacks into the listener.
 */
typedef struct {
    /**
     * Application state changed callback
     */
    alljoyn_applicationstatelistener_state_ptr state;
} alljoyn_applicationstatelistener_callbacks;

/**
 * Create an alljoyn_applicationstatelistener which will trigger the provided callbacks.
 *
 * @param[in] callbacks Callbacks to trigger for associated events.
 * @param[in] context   Application context to be passed into the callbacks.
 *                      The context must not be deallocated before the application listener is destroyed.
 *
 * @return Handle to newly allocated alljoyn_applicationstatelistener.
 */
AJ_API alljoyn_applicationstatelistener AJ_CALL alljoyn_applicationstatelistener_create(const alljoyn_applicationstatelistener_callbacks* callbacks, void* context);

/**
 * Destroy an alljoyn_applicationstatelistener.
 *
 * @param[in] listener alljoyn_applicationstatelistener to destroy.
 */
AJ_API void AJ_CALL alljoyn_applicationstatelistener_destroy(alljoyn_applicationstatelistener listener);

#ifdef __cplusplus
} /* extern "C"  */
#endif

#endif
