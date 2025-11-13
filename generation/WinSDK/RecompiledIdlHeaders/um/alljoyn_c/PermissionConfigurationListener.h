/**
 * @file
 * This file defines the alljoyn_permissionconfigurationlistener and related functions that provides
 * the interface between authentication mechansisms and applications.
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
#ifndef _ALLJOYN_C_PERMISSIONCONFIGURATIONLISTENER_H
#define _ALLJOYN_C_PERMISSIONCONFIGURATIONLISTENER_H

#include <alljoyn_c/AjAPI.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_permissionconfigurationlistener allows security 2.0 mechanisms to
 * interact with the user or application.
 */
typedef struct _alljoyn_permissionconfigurationlistener_handle* alljoyn_permissionconfigurationlistener;

/**
 * Type for the FactoryReset callback.
 *
 * Framework requests application do a factory reset of its state.
 *
 * @param context  The context pointer passed into the alljoyn_permissionconfigurationlistener_create function.
 */
typedef QStatus (AJ_CALL * alljoyn_permissionconfigurationlistener_factoryreset_ptr)(const void* context);

/**
 * Type for the PolicyChanged callback.
 *
 * Framework notifies application of a security policy change.
 *
 * @param context  The context pointer passed into the alljoyn_permissionconfigurationlistener_create function.
 */
typedef void (AJ_CALL * alljoyn_permissionconfigurationlistener_policychanged_ptr)(const void* context);

/**
 * Type for the StartManagement callback.
 *
 * Framework requests application to prepare for Security 2.0 settings changes from the Security Manager.
 *
 * @param context    The context pointer passed into the alljoyn_permissionconfigurationlistener_startmanagement_ptr function.
 */
typedef void (AJ_CALL * alljoyn_permissionconfigurationlistener_startmanagement_ptr)(const void* context);

/**
 * Type for the EndManagement callback.
 *
 * Framework notifies the application that the Security 2.0 configuration has been finished.
 *
 * @param context    The context pointer passed into the alljoyn_permissionconfigurationlistener_endmanagement_ptr function.
 */
typedef void (AJ_CALL * alljoyn_permissionconfigurationlistener_endmanagement_ptr)(const void* context);

/**
 * Structure used during alljoyn_permissionconfigurationlistener_create to provide callbacks into C.
 */
typedef struct {
    /**
     * Framework requests application factory reset.
     */
    alljoyn_permissionconfigurationlistener_factoryreset_ptr factory_reset;

    /**
     * Framework notifies application of a security policy change.
     */
    alljoyn_permissionconfigurationlistener_policychanged_ptr policy_changed;

    /**
     * Notification provided before Security Manager is starting to change settings for this application.
     *
     * NOTE: The application must assume any kind of possible Security 2.0
     * configuration changes, including a full reset. It is strongly advised
     * to put all current actions on hold and close all open sessions as they
     * might need to be reauthenticated or security policies might change.
     * The application should wait for "end_management" to be called before
     * attempting to start or continue its operation. The caller will wait
     * for this call to return until a regular method call timeout is hit.
     * It is thus advised to return from this callback as quickly as possible.
     */
    alljoyn_permissionconfigurationlistener_startmanagement_ptr start_management;

    /**
     * Notification provided after Security Manager finished changing settings for this application.
     * The caller will wait for this call to return until a regular method call timeout is hit.
     * It is thus advised to return from this callback as quickly as possible.
     * At this point the application may conclude one of two things has occurred,
     * depending on its current state:
     *
     * CLAIMED state - all Security 2.0-related provisioning
     * has finished and it's safe to resume or begin regular operation.
     * CLAIMABLE state - the application has been reset and cannot establish any
     * sessions to claimed applications until it is claimed once more.
     */
    alljoyn_permissionconfigurationlistener_endmanagement_ptr end_management;
} alljoyn_permissionconfigurationlistener_callbacks;

/**
 * Create an alljoyn_permissionconfigurationlistener which will trigger the
 * provided callbacks, passing along the provided context.
 *
 * @param callbacks Callbacks to trigger for associated events.
 * @param context   Context to pass to callback functions.
 *
 * @return Handle to newly allocated alljoyn_permissionconfigurationlistener.
 */
extern AJ_API alljoyn_permissionconfigurationlistener AJ_CALL alljoyn_permissionconfigurationlistener_create(const alljoyn_permissionconfigurationlistener_callbacks* callbacks, const void* context);

/**
 * Destroy an alljoyn_permissionconfigurationlistener.
 *
 * @param listener alljoyn_permissionconfigurationlistener to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_permissionconfigurationlistener_destroy(alljoyn_permissionconfigurationlistener listener);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
