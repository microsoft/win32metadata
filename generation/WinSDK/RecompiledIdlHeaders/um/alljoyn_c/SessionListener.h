/**
 * @file
 * alljoyn_sessionlistener is an collection of callback functions implemented by
 * users of the AllJoyn API in order to receive sessions related event information.
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
#ifndef _ALLJOYN_C_SESSIONLISTENER_H
#define _ALLJOYN_C_SESSIONLISTENER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Session.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Reason for the session being lost */
typedef enum {
    ALLJOYN_SESSIONLOST_INVALID                      = 0x00, /**< Invalid */
    ALLJOYN_SESSIONLOST_REMOTE_END_LEFT_SESSION      = 0x01, /**< Remote end called LeaveSession */
    ALLJOYN_SESSIONLOST_REMOTE_END_CLOSED_ABRUPTLY   = 0x02, /**< Remote end closed abruptly */
    ALLJOYN_SESSIONLOST_REMOVED_BY_BINDER            = 0x03, /**< Session binder removed this endpoint by calling RemoveSessionMember */
    ALLJOYN_SESSIONLOST_LINK_TIMEOUT                 = 0x04, /**< Link was timed-out */
    ALLJOYN_SESSIONLOST_REASON_OTHER                 = 0x05 /**< Unspecified reason for session loss */
} alljoyn_sessionlostreason;

/**
 * alljoyn_sessionlistener contains callback functions implemented by AllJoyn users
 * and called by AllJoyn to inform users of session related events.
 */
typedef struct _alljoyn_sessionlistener_handle*             alljoyn_sessionlistener;

/**
 * Type for the SesionLost callback.
 *
 * Called by the bus when an existing session becomes disconnected.
 *
 * @param context       context pointer that was passed into the alljoyn_sessionlistener_create function
 * @param alljoyn_sessionid     Id of session that was lost.
 * @param reason        The reason for the session being lost
 */
typedef void (AJ_CALL * alljoyn_sessionlistener_sessionlost_ptr)(const void* context, alljoyn_sessionid sessionId, alljoyn_sessionlostreason reason);

/**
 * Type for the SessionMemberAdded callback.
 *
 * Called by the bus when a member of a multipoint session is added.
 *
 * @param context       context pointer that was passed into the alljoyn_sessionlistener_create function
 * @param alljoyn_sessionid     Id of session whose member(s) changed.
 * @param uniqueName    Unique name of member who was added.
 */
typedef void (AJ_CALL * alljoyn_sessionlistener_sessionmemberadded_ptr)(const void* context, alljoyn_sessionid sessionId,
                                                                        const char* uniqueName);

/**
 * Type for the SessionMemberRemoved callback.
 *
 * Called by the bus when a member of a multipoint session is removed.
 *
 * @param context       context pointer that was passed into the alljoyn_sessionlistener_create function
 * @param alljoyn_sessionid     Id of session whose member(s) changed.
 * @param uniqueName    Unique name of member who was removed.
 */
typedef void (AJ_CALL * alljoyn_sessionlistener_sessionmemberremoved_ptr)(const void* context, alljoyn_sessionid sessionId,
                                                                          const char* uniqueName);

/**
 * Structure used during alljoyn_sessionlistener_create to provide callbacks into C.
 */
typedef struct {
    /**
     * Called by the bus when an existing session becomes disconnected.
     */
    alljoyn_sessionlistener_sessionlost_ptr session_lost;
    /**
     * Called by the bus when a member of a multipoint session is added.
     */
    alljoyn_sessionlistener_sessionmemberadded_ptr session_member_added;
    /**
     * Called by the bus when a member of a multipoint session is removed.
     */
    alljoyn_sessionlistener_sessionmemberremoved_ptr session_member_removed;
} alljoyn_sessionlistener_callbacks;

/**
 * Create an alljoyn_sessionlistener which will trigger the provided callbacks,
 * passing along the provided context.
 *
 * @param callbacks Callbacks to trigger for associated events.
 * @param context   Context to pass to callback functions
 *
 * @return Handle to newly allocated alljoyn_sessionlistener.
 */
extern AJ_API alljoyn_sessionlistener AJ_CALL alljoyn_sessionlistener_create(const alljoyn_sessionlistener_callbacks* callbacks,
                                                                             const void* context);

/**
 * Destroy an alljoyn_sessionlistener.
 *
 * @param listener alljoyn_sessionlistener to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_sessionlistener_destroy(alljoyn_sessionlistener listener);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
