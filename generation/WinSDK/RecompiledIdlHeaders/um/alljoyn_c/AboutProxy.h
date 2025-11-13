/**
 * @file
 * alljoyn_aboutproxy gives proxy access to the org.alljoyn.About interface
 * exposing the following methods: GetObjectDescriptions, GetAboutData and GetVersion.
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

#ifndef _ALLJOYN_ABOUTPROXY_C_H_
#define _ALLJOYN_ABOUTPROXY_C_H_

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/MsgArg.h>
#include <alljoyn_c/BusAttachment.h>
#include <alljoyn_c/Session.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_aboutproxy give proxy access to the org.alljoyn.About interface
 * alljoyn_aboutproxy object enables the user to interact with the remote
 * alljoyn_aboutobj instances.
 *
 * This exposes the following org.alljoyn.About methods:
 * - GetObjectDescriptions
 * - GetAboutData
 * - GetVersion
 */
typedef struct _alljoyn_aboutproxy_handle* alljoyn_aboutproxy;

/**
 * Allocate a new alljoyn_aboutproxy object.
 *
 * @param[in] bus       reference to alljoyn_busattachment
 * @param[in] busName   unique or well-known name of remote AllJoyn bus
 * @param[in] sessionId the session received after joining AllJoyn session
 *
 * @return The allocated alljoyn_aboutproxy.
 */
extern AJ_API alljoyn_aboutproxy AJ_CALL alljoyn_aboutproxy_create(alljoyn_busattachment bus,
                                                                   const char* busName,
                                                                   alljoyn_sessionid sessionId);

/**
 * Free an alljoyn_aboutproxy object.
 *
 * @param proxy The alljoyn_aboutproxy to be freed
 */
extern AJ_API void AJ_CALL alljoyn_aboutproxy_destroy(alljoyn_aboutproxy proxy);

/**
 * Get the ObjectDescription array for specified bus name.
 *
 * @param[in]  proxy       The alljoyn_aboutproxy object to get object description from
 * @param[out] objectDesc  Description of busName's remote objects.
 *
 * @return
 *   - ER_OK if successful.
 *   - ER_BUS_REPLY_IS_ERROR_MESSAGE on unknown failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutproxy_getobjectdescription(alljoyn_aboutproxy proxy,
                                                                      alljoyn_msgarg objectDesc);

/**
 * Get the About data for specified bus name.
 *
 * @param[in]  proxy   The alljoyn_aboutproxy object to get the about data from
 * @param[in] language the language used to request the About data.
 * @param[out] data    reference of About data that is filled by the function
 *
 * @return
 *    - ER_OK if successful.
 *    - ER_LANGUAGE_NOT_SUPPORTED if the language specified is not supported
 *    - ER_BUS_REPLY_IS_ERROR_MESSAGE on unknown failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutproxy_getaboutdata(alljoyn_aboutproxy proxy,
                                                              const char* language,
                                                              alljoyn_msgarg data);

/**
 * GetVersion get the About version
 *
 * @param[in]  proxy   The alljoyn_aboutproxy object to get the version from
 * @param[out] version of the service.
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutproxy_getversion(alljoyn_aboutproxy proxy,
                                                            uint16_t* version);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _ALLJOYN_ABOUTPROXY_C_H_ */
