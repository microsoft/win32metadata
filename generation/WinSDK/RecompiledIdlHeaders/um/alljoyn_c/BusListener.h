/**
 * @file
 * BusListener is an abstract base class (interface) implemented by users of the
 * AllJoyn API in order to asynchronously receive bus  related event information.
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
#ifndef _ALLJOYN_C_BUSLISTENER_H
#define _ALLJOYN_C_BUSLISTENER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/TransportMask.h>
#include <alljoyn_c/MsgArg.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * alljoyn_buslistener consists of a collection of function pointers implemented by
 * AllJoyn users and called by AllJoyn to inform users of bus related events.
 */
typedef struct _alljoyn_buslistener_handle*                 alljoyn_buslistener;
#ifndef _ALLJOYN_OPAQUE_BUSATTACHMENT_
#define _ALLJOYN_OPAQUE_BUSATTACHMENT_
/**
 * alljoyn_busattachment is the top level object responsible for connecting to and
 * managing an AllJoyn message bus
 */
typedef struct _alljoyn_busattachment_handle*               alljoyn_busattachment;
#endif

/**
 * Type for the ListenerRegistered callback.
 *
 * Called by the bus when the listener is registered. This gives the listener implementation the
 * opportunity to save a reference to the bus.
 *
 * @param context  The context pointer that was passed into the alljoyn_buslistener_create function
 * @param bus      The alljoyn_busattachment the listener is registered with.
 */
typedef void (AJ_CALL * alljoyn_buslistener_listener_registered_ptr)(const void* context, alljoyn_busattachment bus);

/**
 * Type for the ListenerUnregistered callback.
 *
 * Called by the bus when the listener is unregistered.
 *
 * @param context  The context pointer that was passed into the alljoyn_buslistener_create function
 */
typedef void (AJ_CALL * alljoyn_buslistener_listener_unregistered_ptr)(const void* context);

/**
 * Type for the FoundAdvertisedName callback.
 *
 * Called by the bus when an external bus is discovered that is advertising a well-known name
 * that this attachment has registered interest in via a DBus call to org.alljoyn.Bus.FindAdvertisedName
 *
 * @param context      The context pointer that was passed into the alljoyn_buslistener_create function
 * @param name         A well known name that the remote bus is advertising.
 * @param transport    Transport that received the advertisement.
 * @param namePrefix   The well-known name prefix used in call to FindAdvertisedName that triggered this callback.
 */
typedef void (AJ_CALL * alljoyn_buslistener_found_advertised_name_ptr)(const void* context, const char* name, alljoyn_transportmask transport, const char* namePrefix);

/**
 * This callback is deprecated, it will not be called any more.  Use the property change notification mechanism for proxy bus objects.
 * Type for the LostAdvertisedName callback.
 *
 * Called by the bus when an advertisement previously reported through FoundName has become unavailable.
 *
 * @param context      The context pointer that was passed into the alljoyn_buslistener_create function
 * @param name         A well known name that the remote bus is advertising that is of interest to this attachment.
 * @param transport    Transport that stopped receiving the given advertised name.
 * @param namePrefix   The well-known name prefix that was used in a call to FindAdvertisedName that triggered this callback.
 */
typedef void (AJ_CALL * alljoyn_buslistener_lost_advertised_name_ptr)(const void* context, const char* name, alljoyn_transportmask transport, const char* namePrefix);

/**
 * Type for the NameOwnerChanged callback.
 *
 * Called by the bus when the ownership of any well-known name changes.
 *
 * @param context        The context pointer that was passed into the alljoyn_buslistener_create function
 * @param busName        The well-known name that has changed.
 * @param previousOwner  The unique name that previously owned the name or NULL if there was no previous owner.
 * @param newOwner       The unique name that now owns the name or NULL if there is no new owner.
 */
typedef void (AJ_CALL * alljoyn_buslistener_name_owner_changed_ptr)(const void* context, const char* busName, const char* previousOwner, const char* newOwner);


/**
 * Type for the BusStopping callback.
 *
 * @param context  The context pointer that was passed into the alljoyn_buslistener_create function
 */
typedef void (AJ_CALL * alljoyn_buslistener_bus_stopping_ptr)(const void* context);

/**
 * Type for the BusDisconnected callback.
 *
 * @param context  The context pointer that was passed into the alljoyn_buslistener_create function
 */
typedef void (AJ_CALL * alljoyn_buslistener_bus_disconnected_ptr)(const void* context);

/**
 * Type for the PropertyChanged callback.
 *
 * Called by the bus when the value of a property changes if that property has annotation
 *
 * @param context        The context pointer that was passed into the alljoyn_buslistener_create function
 * @param propName       The well-known name that has changed.
 * @param propValue      The new value of the property; NULL if not present
 */
typedef void (AJ_CALL * alljoyn_buslistener_bus_prop_changed_ptr)(const void* context, const char* prop_name, alljoyn_msgarg prop_value);

/**
 * Struct containing callbacks used for creation of an alljoyn_buslistener.
 */
typedef struct {
    /**
     * Function pointer called by the bus when the listener is registered
     */
    alljoyn_buslistener_listener_registered_ptr listener_registered;
    /**
     * Function pointer called by the bus when the listener is unregistered
     */
    alljoyn_buslistener_listener_unregistered_ptr listener_unregistered;
    /**
     * Function pointer called by the bus when an external bus is discovered that is advertising
     * a well-known name that this alljoyn_busattachment has registered interest
     * in via a DBus call to org.alljoyn.Bus.FindAdvertisedName
     */
    alljoyn_buslistener_found_advertised_name_ptr found_advertised_name;
    /**
     * Function pointer called by the bus when an advertisement previously reported through FoundName has become unavailable.
     */
    alljoyn_buslistener_lost_advertised_name_ptr lost_advertised_name;
    /**
     * Function pointer called by the bus when the ownership of any well-known name changes.
     */
    alljoyn_buslistener_name_owner_changed_ptr name_owner_changed;
    /**
     * Function pointer called when an alljoyn_busattachment this listener is registered with is stopping.
     */
    alljoyn_buslistener_bus_stopping_ptr bus_stopping;
    /**
     * Function pointer called when an alljoyn_busattachment this listener is registered with has become disconnected from
     * the bus.
     */
    alljoyn_buslistener_bus_disconnected_ptr bus_disconnected;
    /**
     * Function pointer called by the bus when the value of a property changes if that property has annotation
     */
    alljoyn_buslistener_bus_prop_changed_ptr property_changed;
} alljoyn_buslistener_callbacks;
/**
 * Create an alljoyn_buslistener which will trigger the provided callbacks, passing along the provided context.
 *
 * @param callbacks Callbacks to trigger for associated events.
 * @param context   Context to pass to callback functions
 *
 * @return Handle to newly allocated alljoyn_buslistener.
 */
extern AJ_API alljoyn_buslistener AJ_CALL alljoyn_buslistener_create(const alljoyn_buslistener_callbacks* callbacks, const void* context);

/**
 * Destroy an alljoyn_buslistener.
 *
 * @param listener alljoyn_buslistener to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_buslistener_destroy(alljoyn_buslistener listener);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
