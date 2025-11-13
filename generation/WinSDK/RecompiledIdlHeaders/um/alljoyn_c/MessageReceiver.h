/**
 * @file
 * MessageReceiver is a base class implemented by any class
 * which wishes to receive AllJoyn messages
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
#ifndef _ALLJOYN_C_MESSAGERECEIVER_H
#define _ALLJOYN_C_MESSAGERECEIVER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Message.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ALLJOYN_OPAQUE_BUSOBJECT_
#define _ALLJOYN_OPAQUE_BUSOBJECT_
/**
 * Message bus object
 */
typedef struct _alljoyn_busobject_handle*                   alljoyn_busobject;
#endif

/**
 * MethodHandlers are %MessageReceiver functions which are called by AllJoyn library
 * to forward AllJoyn method_calls to AllJoyn library users.
 *
 * @param bus       The bus object triggering this callback.
 * @param member    Method interface member entry.
 * @param message   The received method call message.
 */
typedef void (AJ_CALL * alljoyn_messagereceiver_methodhandler_ptr)(alljoyn_busobject bus,
                                                                   const alljoyn_interfacedescription_member* member,
                                                                   alljoyn_message message);

/**
 * ReplyHandlers are %MessageReceiver functions which are called by AllJoyn library
 * to forward AllJoyn method_reply and error responses to AllJoyn library users.
 *
 * @param message   The received message.
 * @param context   User-defined context passed to MethodCall and returned upon reply.
 */
typedef void (AJ_CALL * alljoyn_messagereceiver_replyhandler_ptr)(alljoyn_message message, void* context);

/**
 * SignalHandlers are %MessageReceiver functions which are called by AllJoyn library
 * to forward AllJoyn received signals to AllJoyn library users.
 *
 * @param member    Method or signal interface member entry.
 * @param srcPath   Object path of signal emitter.
 * @param message   The received message.
 */
typedef void (AJ_CALL * alljoyn_messagereceiver_signalhandler_ptr)(const alljoyn_interfacedescription_member* member,
                                                                   const char* srcPath, alljoyn_message message);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
