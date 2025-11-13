/**
 * @file
 * alljoyn_sessionportlistener is a collection of functions implemented by users
 * of the AllJoyn API in order to receive session port related event information.
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
#ifndef _ALLJOYN_C_SESSIONPORTLISTENER_H
#define _ALLJOYN_C_SESSIONPORTLISTENER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Session.h>
#include <alljoyn_c/SessionListener.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_sessionportlistener is an abstract interface implemented by users of the
 * AllJoyn API in order to receive session port related event information.
 */
typedef struct _alljoyn_sessionportlistener_handle*         alljoyn_sessionportlistener;

/**
 * Type for the AcceptSessionJoiner callback.

 * Accept or reject an incoming JoinSession request. The session does not exist until
 * after this function returns.
 *
 * This callback is only used by session creators. Therefore it is only called on listeners
 * passed to alljoyn_busattachment_bindsessionport.
 *
 * @param context        the context pointer that was passed to alljoyn_sessionportlistener_create
 * @param sessionPort    Session port that was joined.
 * @param joiner         Unique name of potential joiner.
 * @param opts           Session options requested by the joiner.
 * @return   Return true if JoinSession request is accepted. false if rejected.
 */
typedef QCC_BOOL (AJ_CALL * alljoyn_sessionportlistener_acceptsessionjoiner_ptr)(const void* context, alljoyn_sessionport sessionPort,
                                                                                 const char* joiner,  const alljoyn_sessionopts opts);

/**
 * Type for the SessionJoined callback.
 *
 * Called by the bus when a session has been successfully joined. The session is now fully up.
 *
 * This callback is only used by session creators. Therefore it is only called on the alljoyn_sessionportlistener_callbacks
 * passed in when calling alljoyn_busattachment_bindsessionport.
 *
 * @param context        the context pointer that was passed to alljoyn_sessionportlistener_create
 * @param sessionPort    Session port that was joined.
 * @param id             Id of session.
 * @param joiner         Unique name of the joiner.
 */
typedef void (AJ_CALL * alljoyn_sessionportlistener_sessionjoined_ptr)(const void* context, alljoyn_sessionport sessionPort,
                                                                       alljoyn_sessionid id, const char* joiner);

/**
 * Structure used during alljoyn_sessionportlistener_create to provide callbacks into C.
 */
typedef struct {
    /**
     * Accept or reject an incoming JoinSession request. The session does not
     * exist until this after this function returns.
     */
    alljoyn_sessionportlistener_acceptsessionjoiner_ptr accept_session_joiner;
    /**
     * Called by the bus when a session has been successfully joined. The session
     * is now fully up.
     */
    alljoyn_sessionportlistener_sessionjoined_ptr session_joined;
} alljoyn_sessionportlistener_callbacks;

/**
 * Create an alljoyn_sessionportlistener which will trigger the provided callbacks, passing along the provided context.
 *
 * @param callbacks Callbacks to trigger for associated events.
 * @param context   Context to pass to callback functions
 *
 * @return Handle to newly allocated alljoyn_sessionportlistener.
 */
extern AJ_API alljoyn_sessionportlistener AJ_CALL alljoyn_sessionportlistener_create(const alljoyn_sessionportlistener_callbacks* callbacks,
                                                                                     const void* context);

/**
 * Destroy an alljoyn_sessionportlistener.
 *
 * @param listener alljoyn_sessionportlistener to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_sessionportlistener_destroy(alljoyn_sessionportlistener listener);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
