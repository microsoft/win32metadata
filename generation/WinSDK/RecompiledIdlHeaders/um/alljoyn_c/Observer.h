/**
 * @file
 * The alljoyn_observer takes care of discovery, session management and
 * alljoyn_proxybusobject creation for bus objects that implement a
 * specific set of interfaces.
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
#ifndef _ALLJOYN_OBSERVER_C_H
#define _ALLJOYN_OBSERVER_C_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/BusAttachment.h>
#include <alljoyn_c/ProxyBusObject.h>

#ifdef __cplusplus
extern "C" {
#endif

/* the proxybusobject_ref part */

/**
 * Data structure holding a reference to an alljoyn_proxybusobject and an
 * associated reference count. If the reference count reaches zero, both
 * the proxy bus object and the reference structure get destroyed.
 */
typedef struct _alljoyn_proxybusobject_ref_handle* alljoyn_proxybusobject_ref;

/**
 * Create a new refcounted proxy bus object reference with initial refcount 1.
 *
 * @param proxy The proxy bus object that will be managed by this reference.
 *
 * @return the newly created reference
 *
 * @note The alljoyn_proxybusobject_ref will take over ownership of the
 * alljoyn_proxybusobject, and will destroy it when the refcount reaches zero.
 */
AJ_API alljoyn_proxybusobject_ref AJ_CALL alljoyn_proxybusobject_ref_create(alljoyn_proxybusobject proxy);

/**
 * Get the alljoyn_proxybusobject managed by this reference.
 *
 * @param ref the alljoyn_proxybusobject_ref to dereference
 *
 * @return the alljoyn_proxybusobject managed by this reference.
 *
 * @note This does not increase the refcount of the reference.
 */
AJ_API alljoyn_proxybusobject AJ_CALL alljoyn_proxybusobject_ref_get(alljoyn_proxybusobject_ref ref);

/**
 * Increase the refcount of the alljoyn_proxybusobject reference.
 *
 * @param ref the alljoyn_proxybusobject_ref to dereference
 */
AJ_API void AJ_CALL alljoyn_proxybusobject_ref_incref(alljoyn_proxybusobject_ref ref);

/**
 * Decrease the refcount of the alljoyn_proxybusobject reference.
 *
 * If the refcount reaches zero, both the reference and the proxy bus object it
 * manages will be destroyed.
 *
 * @param ref the alljoyn_proxybusobject_ref to dereference
 */
AJ_API void AJ_CALL alljoyn_proxybusobject_ref_decref(alljoyn_proxybusobject_ref ref);

/* The observerlistener part */

/**
 * Data structure holding the callbacks to be invoked by the
 * observer whenever objects of interest are discovered or lost.
 */
typedef struct _alljoyn_observerlistener_handle* alljoyn_observerlistener;

/**
 * Callback to be invoked when a new object has been discovered.
 *
 * @param context   the context pointer that was passed into the
 *                  alljoyn_observerlistener_create function
 * @param proxyref  a reference to a proxy bus object supporting all interfaces
 *                  announced in the About signal.
 *
 * @note the proxyref is guaranteed to remain valid throughout the execution of
 *       this callback. If you want to keep it around for longer than that, you
 *       have to manually increase the reference count.
 */
typedef void (AJ_CALL * alljoyn_observer_object_discovered_ptr)(const void* context,
                                                                alljoyn_proxybusobject_ref proxyref);
/**
 * Callback to be invoked when a previously discovered object has been lost.
 *
 * @param context  the context pointer that was passed into the
 *                 alljoyn_observerlistener_create function
 * @param proxyref a reference to the proxy bus object representing the object
 *                 that has been lost.
 *
 * @note the proxyref is guaranteed to remain valid throughout the execution of
 *       this callback. If you want to keep it around for longer than that, you
 *       have to manually increase the reference count.
 */
typedef void (AJ_CALL * alljoyn_observer_object_lost_ptr)(const void* context,
                                                          alljoyn_proxybusobject_ref proxyref);

/**
 * The callbacks used for creation of an alljoyn_observerlistener.
 */
typedef struct {
    /**
     * A new object has been discovered.
     */
    alljoyn_observer_object_discovered_ptr object_discovered;
    /**
     * A previously discovered object has been lost.
     */
    alljoyn_observer_object_lost_ptr object_lost;
} alljoyn_observerlistener_callback;


/**
 * Allocate a new alljoyn_observerlistener.
 */
extern AJ_API alljoyn_observerlistener AJ_CALL alljoyn_observerlistener_create(const alljoyn_observerlistener_callback* callback,
                                                                               const void* context);

/**
 * Free an alljoyn_observerlistener.
 */
extern AJ_API void AJ_CALL alljoyn_observerlistener_destroy(alljoyn_observerlistener listener);

/* the observer part */

/** An alljoyn_observer takes care of discovery, session management and
 * ProxyBusObject creation for bus objects that implement a specific set of
 * interfaces.
 *
 * The Observer monitors About announcements, and automatically sets up
 * sessions with all peers that offer objects of interest (i.e. objects that
 * implement at least the set of mandatory interfaces for this Observer). The
 * Observer creates a proxy bus object for each discovered object.
 * alljoyn_observerlistener objects are used to inform the application about
 * the discovery of new objects, and about the disappearance of objects from
 * the bus.
 *
 * Objects are considered lost in the following cases:
 * - they are un-announced via About
 * - the hosting peer has closed the session
 * - the hosting peer stopped responding to Ping requests
 */
typedef struct _alljoyn_observer_handle* alljoyn_observer;

/**
 * Create a new alljoyn_observer.
 *
 * @param bus                    Bus attachment to which the Observer is attached.
 * @param mandatoryInterfaces    Set of interface names that a bus object
 *                               MUST implement to be discoverable by this Observer.
 * @param numMandatoryInterfaces number of elements in the mandatoryInterfaces array.
 *
 * @return the newly created Observer.
 *
 * Some things to take into account:
 *   - the Observer will only discover objects that are announced through About.
 *   - the interface names in mandatoryInterfaces must correspond with
 *     InterfaceDescriptions that have been registered with the bus attachment
 *     before creation of the Observer.
 *   - mandatoryInterfaces must not be empty or NULL
 */
extern AJ_API alljoyn_observer AJ_CALL alljoyn_observer_create(alljoyn_busattachment bus,
                                                               const char* mandatoryInterfaces[],
                                                               size_t numMandatoryInterfaces);

/**
 * Destroy an alljoyn_observer.
 *
 * @param observer the alljoyn_observer to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_observer_destroy(alljoyn_observer observer);

/**
 * Register a listener.
 *
 * @param observer the observer this call is made for
 * @param listener the listener to register
 * @param triggerOnExisting trigger object_discovered callbacks for
 *                          already-discovered objects
 */
extern AJ_API void AJ_CALL alljoyn_observer_registerlistener(alljoyn_observer observer,
                                                             alljoyn_observerlistener listener,
                                                             QCC_BOOL triggerOnExisting);

/**
 * Unregister a listener.
 *
 * @param observer the observer this call is made for
 * @param listener the listener to unregister
 */
extern AJ_API void AJ_CALL alljoyn_observer_unregisterlistener(alljoyn_observer observer,
                                                               alljoyn_observerlistener listener);

/**
 * Unregister all listeners.
 *
 * There is no real need to unregister all listeners before the Observer
 * is destroyed, but it is considered good style to do so.
 *
 * @param observer the observer this call is made for
 */
extern AJ_API void AJ_CALL alljoyn_observer_unregisteralllisteners(alljoyn_observer observer);

/**
 * Get a reference to a proxy object.
 *
 * If the requested object is not tracked by this observer, NULL is returned instead.
 * The reference that is returned belongs to you. You are responsible for decrementing
 * its refcount to avoid memory leaks.
 *
 * @param observer      The observer this call is made for
 * @param uniqueBusName The unique bus name of the peer hosting the object
 *                      you want to retrieve.
 * @param objectPath    The path of the object you want to retrieve.
 * @return an alljoyn_proxybusobject_ref or NULL
 */
extern AJ_API alljoyn_proxybusobject_ref AJ_CALL alljoyn_observer_get(alljoyn_observer observer,
                                                                      const char* uniqueBusName,
                                                                      const char* objectPath);

/**
 * Get a reference to the first proxy object.
 *
 * The getfirst/getnext pair of functions is useful for iterating over all discovered
 * objects. The iteration is over when either call returns NULL.
 *
 * The reference remains valid until you pass it into alljoyn_observer_getnext. If you
 * want to keep it around for longer than that, you have to manually increase the reference
 * count. If you never call alljoyn_observer_getnext with this reference, then it's up to
 * you to decrement the reference count when you're done with it.
 *
 * @param observer the observer this call is made for
 * @return an alljoyn_proxybusobject_ref or NULL
 */
extern AJ_API alljoyn_proxybusobject_ref AJ_CALL alljoyn_observer_getfirst(alljoyn_observer observer);

/**
 * Get a reference to the next proxy object.
 *
 * The getfirst/getnext pair of functions is useful for iterating over all discovered
 * objects. The iteration is over when either call returns NULL.
 *
 * The reference remains valid until you pass it into alljoyn_observer_getnext. If you
 * want to keep it around for longer than that, you have to manually increase the reference
 * count. If you never call alljoyn_observer_getnext with this reference, then it's up to
 * you to decrement the reference count when you're done with it.
 *
 * @param observer the observer this call is made for
 * @param proxyref This method will return the proxy object immediately following this one
 * @return an alljoyn_proxybusobject or NULL
 */
extern AJ_API alljoyn_proxybusobject_ref AJ_CALL alljoyn_observer_getnext(alljoyn_observer observer,
                                                                          alljoyn_proxybusobject_ref proxyref);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //_ALLJOYN_OBSERVER_C_H

