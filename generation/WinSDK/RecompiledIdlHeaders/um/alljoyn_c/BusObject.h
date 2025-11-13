/**
 * @file
 *
 * This file defines the base class for message bus objects that
 * are implemented and registered locally.
 *
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
#ifndef _ALLJOYN_C_LOCALBUSOBJECT_H
#define _ALLJOYN_C_LOCALBUSOBJECT_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/InterfaceDescription.h>
#include <alljoyn_c/MsgArg.h>
#include <alljoyn_c/MessageReceiver.h>
#include <alljoyn_c/Session.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#ifndef _ALLJOYN_OPAQUE_BUSOBJECT_
#define _ALLJOYN_OPAQUE_BUSOBJECT_
/**
 * alljoyn_busobjects are objects that are implemented and registered locally.
 * An alljoyn_busobject can contain multiple interfaces that can be called remotely.
 */
typedef struct _alljoyn_busobject_handle*                   alljoyn_busobject;
#endif

/**
 * Callback for property get method.
 *
 * Handle a bus request to read a property from this object.
 * alljoyn_busobjects that implement properties should provide an implementation
 * of this function.
 * The default version simply returns ER_BUS_NO_SUCH_PROPERTY.
 *
 * @param context   context pointer passed in when creating a new alljoyn_busobject
 * @param ifcName   Identifies the interface that the property is defined on
 * @param propName  Identifies the property to get
 * @param[out] val  Returns the property value. The type of this value is the actual value
 *                  type.
 * @return #ER_BUS_NO_SUCH_PROPERTY (Should be changed to #ER_OK by user implementation of alljoyn_busobject_prop_get_ptr
 *                                   if the request results in successfully reading a property from the object.)
 */
typedef QStatus (AJ_CALL * alljoyn_busobject_prop_get_ptr)(const void* context, const char* ifcName, const char* propName, alljoyn_msgarg val);

/**
 * Callback for property set method.
 *
 * Handle a bus attempt to write a property value to this object.
 * alljoyn_busobjects that implement properties should provide an implementation
 * of this function.
 * This default version just replies with ER_BUS_NO_SUCH_PROPERTY
 *
 * @param context    context pointer passed in when creating a new alljoyn_busobject
 * @param ifcName    Identifies the interface that the property is defined on
 * @param propName   Identifies the property to set
 * @param val        The property value to set. The type of this value is the actual value
 *                   type.
 * @return #ER_BUS_NO_SUCH_PROPERTY (Should be changed to #ER_OK by user implementation of alljoyn_busobject_prop_set_ptr
 *                                   is the set request results in successfully changing the property.)
 */
typedef QStatus (AJ_CALL * alljoyn_busobject_prop_set_ptr)(const void* context, const char* ifcName, const char* propName, alljoyn_msgarg val);

/**
 * Callback for ObjectRegistered and ObjectUnregistered
 *
 * ObjectRegistered is called by the bus when the alljoyn_busobject has been successfully registered
 * ObjectUnregistered is called by the bus when the alljoyn_busobject has been successfully unregistered
 *
 * @param context   context pointer passed in when creating a new alljoyn_busobject
 */
typedef void (AJ_CALL * alljoyn_busobject_object_registration_ptr)(const void* context);

/**
 * a structure containing a collection of function pointers.
 * These functions are call by AllJoyn in response to certain events and requests
 */
typedef struct {
    /**
     * Handle a bus request to read a property from the alljoyn_busobject
     */
    alljoyn_busobject_prop_get_ptr property_get;
    /**
     * Handle a bus request to write a property value to the alljoyn_busobject
     */
    alljoyn_busobject_prop_set_ptr property_set;
    /**
     * Called by the message bus when the object has been successfully registered.
     *
     * The object can perform any initialization such as adding match rules at this time
     */
    alljoyn_busobject_object_registration_ptr object_registered;
    /**
     * Called by the message bus when the object has been successfully unregistered.
     */
    alljoyn_busobject_object_registration_ptr object_unregistered;
} alljoyn_busobject_callbacks;

/**
 * Type used to add mulitple methods at one time.
 * @see AddMethodHandlers()
 */
typedef struct {
    const alljoyn_interfacedescription_member* member;          /**< Pointer to method's member */
    alljoyn_messagereceiver_methodhandler_ptr method_handler;   /**< Method implementation */
} alljoyn_busobject_methodentry;

/**
 * Create an %alljoyn_busobject.
 *
 * @param path           Object path for object.
 * @param isPlaceholder  Place-holder objects are created by the bus itself and serve only
 *                       as parent objects (in the object path sense) to other objects.
 * @param callbacks_in   an alljoyn_busobject_callbacks struct containing pointer to
 *                       callback functions NULL if no callbacks busoject callback functions
 *                       are needed.
 * @param context_in     a context pointer that can be used in the callback functions
 *
 * @return allocated alljoyn_busobject
 */
extern AJ_API alljoyn_busobject AJ_CALL alljoyn_busobject_create(const char* path, QCC_BOOL isPlaceholder,
                                                                 const alljoyn_busobject_callbacks* callbacks_in, const void* context_in);

/**
 * Destroy an alljoyn_busobject
 *
 * @param bus Bus to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_busobject_destroy(alljoyn_busobject bus);

/**
 * Return the path for the object
 *
 * @param bus alljoyn_busobject on which to get the path.
 * @return Object path
 */
extern AJ_API const char* AJ_CALL alljoyn_busobject_getpath(alljoyn_busobject bus);


/**
 * Emit PropertiesChanged to signal the bus that this property has been updated
 *
 * @param bus       alljoyn_busobject with which to emit the signal
 * @param ifcName   The name of the interface
 * @param propName  The name of the property being changed
 * @param val       The new value of the property
 * @param id        ID of the session we broadcast the signal to (0 for all)
 */
extern AJ_API void AJ_CALL alljoyn_busobject_emitpropertychanged(alljoyn_busobject bus,
                                                                 const char* ifcName,
                                                                 const char* propName,
                                                                 alljoyn_msgarg val,
                                                                 alljoyn_sessionid id);

/**
 * Emit PropertiesChanged to signal the bus that this list of properties have been updated
 *
 * @param bus       alljoyn_busobject with which to emit the signal
 * @param ifcName   The name of the interface
 * @param propNames The array of properties being changed
 * @param numProps  The size of the propNames array
 * @param id        ID of the session we broadcast the signal to (0 for all)
 */
extern AJ_API void AJ_CALL alljoyn_busobject_emitpropertieschanged(alljoyn_busobject bus,
                                                                   const char* ifcName,
                                                                   const char** propNames,
                                                                   size_t numProps,
                                                                   alljoyn_sessionid id);

/**
 * Get the name of this object.
 * The name is the last component of the path.
 *
 * If the buffer is NULL or the bufferSz is 0, the length of the name + nul will be returned.
 *
 * @param bus       alljoyn_busobject on which to get the name.
 * @param buffer    A buffer into which to copy the name.
 * @param bufferSz  The size of the buffer provided.
 * @return The size of the name string, if the returned value is > bufferSz, the entire name was not copied into buffer.
 */
extern AJ_API size_t AJ_CALL alljoyn_busobject_getname(alljoyn_busobject bus, char* buffer, size_t bufferSz);

/**
 * Add an unnanounced interface to this object. If the interface has properties this will also add the
 * standard property access interface. An interface must be added before its method handlers can be
 * added. Note that the Peer interface (org.freedesktop.DBus.peer) is implicit on all objects and
 * cannot be explicitly added, and the Properties interface (org.freedesktop,DBus.Properties) is
 * automatically added when needed and cannot be explicitly added.
 *
 * Once an object is registered, it should not add any additional interfaces. Doing so would
 * confuse remote objects that may have already introspected this object.
 *
 * @param bus    The bus on which to add the interface
 * @param iface  The interface to add
 *
 * @return
 *      - #ER_OK if the interface was successfully added.
 *      - #ER_BUS_IFACE_ALREADY_EXISTS if the interface already exists.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_addinterface(alljoyn_busobject bus,
                                                             const alljoyn_interfacedescription iface);

/**
 * Add a method handler to this object. The interface for the method handler must have already
 * been added by calling AddInterface().
 *
 * @param bus      The alljoyn_busobject onto which the method handler will be added.
 * @param member   Interface member implemented by handler.
 * @param handler  Method handler.
 * @param context  An optional context. This is mainly intended for implementing language
 *                 bindings and should normally be NULL.
 *
 * @return
 *      - #ER_OK if the method handler was added.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_addmethodhandler(alljoyn_busobject bus,
                                                                 const alljoyn_interfacedescription_member member,
                                                                 alljoyn_messagereceiver_methodhandler_ptr handler,
                                                                 void* context);

/**
 * Add a set of method handers at once.
 *
 * @param bus          The bus on which to add method handlers.
 * @param entries      Array of alljoyn_busobject_methodentry.
 * @param numEntries   Number of entries in array.
 *
 * @return
 *      - #ER_OK if all the methods were added
 *      - #ER_BUS_NO_SUCH_INTERFACE is method can not be added because interface does not exist.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_addmethodhandlers(alljoyn_busobject bus,
                                                                  const alljoyn_busobject_methodentry* entries,
                                                                  size_t numEntries);

/**
 * Reply to a method call
 *
 * @param bus      The bus on which to reply.
 * @param msg      The method call message
 * @param args     The reply arguments (can be NULL)
 * @param numArgs  The number of arguments
 * @return
 *      - #ER_OK if successful
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_methodreply_args(alljoyn_busobject bus, alljoyn_message msg,
                                                                 const alljoyn_msgarg args, size_t numArgs);
/**
 * Reply to a method call with an error message
 *
 * @param bus              The bus on which to reply.
 * @param msg              The method call message
 * @param error            The name of the error
 * @param errorMessage     An error message string
 * @return
 *      - #ER_OK if successful
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_methodreply_err(alljoyn_busobject bus, alljoyn_message msg,
                                                                const char* error, const char* errorMessage);
/**
 * Reply to a method call with an error message
 *
 * @param bus        The bus on which to reply.
 * @param msg        The method call message
 * @param status     The status code for the error
 * @return
 *      - #ER_OK if successful
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_methodreply_status(alljoyn_busobject bus, alljoyn_message msg, QStatus status);

/**
 * Get a reference to the underlying alljoyn_busattachment
 *
 * There is no need to call alljoyn_busattachment_create or
 * alljoyn_busattachment_destory for the return value.
 * This is handled in the code that registered the alljoyn_busobject with
 * the alljoyn_busattachment.
 *
 * @see alljoyn_busattachment_registerbusobject
 *
 * @param bus   The alljoyn_busobject to obtain the alljoyn_busattachment from
 *
 * @return a reference to the alljoyn_busattachment
 */
extern AJ_API const alljoyn_busattachment AJ_CALL alljoyn_busobject_getbusattachment(alljoyn_busobject bus);
/**
 * Send a signal.
 *
 * @param bus              The bus used to send the signal
 * @param destination      The unique or well-known bus name or the signal recipient (NULL for broadcast signals)
 * @param sessionId        A unique SessionId for this AllJoyn session instance. Use ALLJOYN_SESSION_ID_ALL_HOSTED
 *                         to emit the signal on all sessions hosted by this bus object's bus attachment.
 *                         Use 0 for broadcast and sessionless signals.
 * @param signal           Interface member of signal being emitted.
 * @param args             The arguments for the signal (can be NULL)
 * @param numArgs          The number of arguments
 * @param timeToLive       If non-zero this specifies the useful lifetime for this signal.
 *                         For sessionless signals the units are seconds.
 *                         For all other signals the units are milliseconds.
 *                         If delivery of the signal is delayed beyond the timeToLive due to
 *                         network congestion or other factors the signal may be discarded. There is
 *                         no guarantee that expired signals will not still be delivered.
 * @param flags            Logical OR of the message flags for this signals. The following flags apply to signals:
 *                         - If #ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST is set broadcast signal (null destination) will be forwarded across bus-to-bus connections.
 *                         - If #ALLJOYN_MESSAGE_FLAG_ENCRYPTED is set the message is authenticated and the payload if any is encrypted.
 *                         - IF #ALLJOYN_MESSAGE_FLAG_SESSIONLESS is set the message will be sent using the sessionless signal mechanism.
 * @param[out] msg         If non-null, the sent signal message is returned to the caller.
 * @return
 *      - #ER_OK if successful
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_signal(alljoyn_busobject bus,
                                                       const char* destination,
                                                       alljoyn_sessionid sessionId,
                                                       const alljoyn_interfacedescription_member signal,
                                                       const alljoyn_msgarg args,
                                                       size_t numArgs,
                                                       uint16_t timeToLive,
                                                       uint8_t flags,
                                                       alljoyn_message msg);
/**
 * Remove sessionless message sent from this object from local router's
 * store/forward cache.
 *
 * @param bus             The bus used to send cancel the sessionless message
 * @param serialNumber    Serial number of previously sent sessionless signal.
 * @return   ER_OK if successful.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_cancelsessionlessmessage_serial(alljoyn_busobject bus, uint32_t serialNumber);

/**
 * Remove sessionless message sent from this object from local router's
 * store/forward cache.
 *
 * @param bus    The bus used to send cancel the sessionless message
 * @param msg    Message to be removed.
 * @return   ER_OK if successful.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_cancelsessionlessmessage(alljoyn_busobject bus, const alljoyn_message msg);

/**
 * Indicates if this object is secure.
 *
 * @param bus    The busobject we want to check for security
 *
 * @return Return QCC_TRUE if authentication is required to emit signals or
 *                call methods on this object.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_busobject_issecure(alljoyn_busobject bus);

/**
 * Get a list of the interfaces that are added to this alljoyn_busobject that will be announced.
 *
 * @param[in] bus           The bus which contains the interfaces
 * @param[in] interfaces    the array of interface names
 * @param[in] numInterfaces the number of interface names
 *
 * @return
 *    The total number of interfaces found that are announced.  If this number
 *    is larger than `numInterfaces` then only `numInterfaces` will be returned.
 *
 */
extern AJ_API size_t AJ_CALL alljoyn_busobject_getannouncedinterfacenames(alljoyn_busobject bus,
                                                                          const char** interfaces,
                                                                          size_t numInterfaces);

/**
 * Change the announce flag for an already added interface. Changes in the
 * announce flag are not visible to other devices till Announce is called.
 *
 * @see alljoyn_aboutobj_announce()
 *
 * @param[in] bus         The bus which contains the interface
 * @param[in] iface       alljoyn_interfacedescription for the interface to set
 *                        the announce flag for
 * @param[in] isAnnounced This interface should be part of the Announce signal
 *                        UNANNOUNCED - this interface will not be part of the Announce signal
 *                        ANNOUNCED   - this interface will be part of the Announce signal
 * @return
 *  - #ER_OK if successful
 *  - #ER_BUS_OBJECT_NO_SUCH_INTERFACE if the interface is not part of the bus object.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_setannounceflag(alljoyn_busobject bus,
                                                                const alljoyn_interfacedescription iface,
                                                                alljoyn_about_announceflag isAnnounced);


/**
 * Add an announced interface to this object. If the interface has properties this will also add the
 * standard property access interface. An interface must be added before its method handlers can be
 * added. Note that the Peer interface (org.freedesktop.DBus.peer) is implicit on all objects and
 * cannot be explicitly added, and the Properties interface (org.freedesktop,DBus.Properties) is
 * automatically added when needed and cannot be explicitly added.
 *
 * Once an object is registered, it should not add any additional interfaces. Doing so would
 * confuse remote objects that may have already introspected this object.
 *
 * @param bus         The bus on which to add the interface
 * @param iface       The interface to add
 *
 * @return
 *      - #ER_OK if the interface was successfully added.
 *      - #ER_BUS_IFACE_ALREADY_EXISTS if the interface already exists.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busobject_addinterface_announced(alljoyn_busobject bus,
                                                                       const alljoyn_interfacedescription iface);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
