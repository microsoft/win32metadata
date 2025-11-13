/**
 * @file
 * alljoyn_aboutobj represents a bus object that implements the org.alljoyn.About interface.
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
#ifndef _ALLJOYN_ABOUT_C_H
#define _ALLJOYN_ABOUT_C_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/AboutData.h>
#include <alljoyn_c/AboutDataListener.h>
#include <alljoyn_c/BusAttachment.h>
#include <alljoyn_c/Session.h>
#include <alljoyn_c/SessionListener.h>
#include <alljoyn_c/SessionPortListener.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * An AllJoyn BusObject that implements the org.alljoyn.About interface.
 *
 * This BusObject is used to announce the capabilities and other identifying
 * details of the application or device.
 */
typedef struct _alljoyn_aboutobj_handle* alljoyn_aboutobj;

/**
 * Allocate a new About object as an alljoyn_aboutobj
 *
 * This object is responsible for transmitting information about the
 * interfaces that are available for other applications to use. It also
 * provides application specific information that is contained in the
 * alljoyn_aboutdata object and helps applications to respond to certain
 * requests concerning the interfaces.
 *
 * By default the org.alljoyn.About interface is excluded from the list of
 * announced interfaces. Since simply receiving the announce signal tells
 * the client that the service implements the org.alljoyn.About interface.
 * Changing the isAnnounced flag from UNANNOUNCED, its default, to ANNOUNCED,
 * will cause the org.alljoyn.About interface to be part of the announce signal.
 * Unless the application is talking with a legacy application that expects
 * the org.alljoyn.About interface to be part of the announce signal it is best
 * to leave the isAnnounced to use its default value.
 *
 * @param[in] bus         the alljoyn_busattachment that will contain the about information
 * @param[in] isAnnounced will the org.alljoyn.About interface be part of the announced interfaces.
 *
 * @return allocated alljoyn_aboutobj
 */
extern AJ_API alljoyn_aboutobj AJ_CALL alljoyn_aboutobj_create(alljoyn_busattachment bus,
                                                               alljoyn_about_announceflag isAnnounced);

/**
 * Free an alljoyn_aboutobj object.
 *
 * @param obj The alljoyn_aboutobj to be freed.
 */
extern AJ_API void AJ_CALL alljoyn_aboutobj_destroy(alljoyn_aboutobj obj);

/**
 * This is used to send the Announce signal.  It announces the list of all
 * interfaces available at given object paths as well as the announced
 * fields from the About data.
 *
 * This method will automatically obtain the announced object description from the
 * alljoyn_busattachment that was used to create the alljoyn_aboutobj. Only alljoyn_busattachment
 * objects that have marked their interfaces as announced and are registered will be announced.
 *
 * @see alljoyn_busattachment_registerbusobject
 * @see alljoyn_busobject_addinterface
 *
 * @param obj         the alljoyn_aboutobj object this call is made for
 * @param sessionPort the session port the interfaces can be connected with
 * @param aboutData   the alljoyn_aboutdata that contains the About data for this announce signal
 *
 * @return
 *  - ER_OK on success
 *  - ER_ABOUT_SESSIONPORT_NOT_BOUND if the SessionPort given is not bound
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutobj_announce(alljoyn_aboutobj obj,
                                                        alljoyn_sessionport sessionPort,
                                                        alljoyn_aboutdata aboutData);


/**
 * This is used to send the Announce signal.  It announces the list of all
 * interfaces available at given object paths as well as the announced
 * fields from the About data.
 *
 * This method will automatically obtain the announced object description from the
 * alljoyn_busattachment that was used to create the alljoyn_aboutobj. Only alljoyn_busattachment
 * objects that have marked their interfaces as announced and are registered will be announced.
 *
 * @see alljoyn_busattachment_registerbusobject
 * @see alljoyn_busobject_addinterface
 *
 * @param obj           the alljoyn_aboutobj object this call is made for
 * @param sessionPort   the session port the interfaces can be connected with
 * @param aboutListener the alljoyn_aboutdatalistener that contains the About data for this announce signal
 *
 * @return
 *  - ER_OK on success
 *  - ER_ABOUT_SESSIONPORT_NOT_BOUND if the SessionPort given is not bound
 */
QStatus AJ_CALL alljoyn_aboutobj_announce_using_datalistener(alljoyn_aboutobj obj,
                                                             alljoyn_sessionport sessionPort,
                                                             alljoyn_aboutdatalistener aboutListener);


/**
 * Cancel the last announce signal sent. If no signals have been sent this
 * method call will return.
 *
 * @param obj the AllJoyn About object
 *
 * @return
 *     - ER_OK on success
 *     - annother status indicating failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutobj_unannounce(alljoyn_aboutobj obj);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //_ALLJOYN_ABOUT_C_H
