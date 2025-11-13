/**
 * @file BusAttachment.h is the top-level object responsible for connecting to a
 * message bus.
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
#ifndef _ALLJOYN_C_BUSATTACHMENT_H
#define _ALLJOYN_C_BUSATTACHMENT_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/ApplicationStateListener.h>
#include <alljoyn_c/KeyStoreListener.h>
#include <alljoyn_c/AuthListener.h>
#include <alljoyn_c/BusListener.h>
#include <alljoyn_c/BusObject.h>
#include <alljoyn_c/ProxyBusObject.h>
#include <alljoyn_c/PermissionConfigurationListener.h>
#include <alljoyn_c/PermissionConfigurator.h>
#include <alljoyn_c/InterfaceDescription.h>
#include <alljoyn_c/Session.h>
#include <alljoyn_c/SessionListener.h>
#include <alljoyn_c/SessionPortListener.h>
#include <alljoyn_c/AboutListener.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ALLJOYN_OPAQUE_BUSATTACHMENT_
#define _ALLJOYN_OPAQUE_BUSATTACHMENT_
/**
 * alljoyn_busattachment is the top level object responsible for connecting to and
 * managing an AllJoyn message bus
 */
typedef struct _alljoyn_busattachment_handle*               alljoyn_busattachment;
#endif

/**
 * Type for the joinsession callback used with the asynchronous joinsession request.
 */
typedef void (AJ_CALL * alljoyn_busattachment_joinsessioncb_ptr)(QStatus status, alljoyn_sessionid sessionId, const alljoyn_sessionopts opts, void* context);

/**
 * Type for the setlinktimeout callback used with the asynchronous setlinktimeout request.
 *
 *
 * Called when alljoyn_busattachment_setlinktimeoutasync() completes.
 *
 * @param status       ER_OK if successful
 * @param timeout      Timeout value (possibly adjusted from original request).
 * @param context      User defined context which will be passed as-is to callback.
 */
typedef void (AJ_CALL * alljoyn_busattachment_setlinktimeoutcb_ptr)(QStatus status, uint32_t timeout, void* context);

/**
 * Allocate an alljoyn_busattachment.
 *
 * By default this will create an alljoyn_busattachment capable of handling 4 concurrent method and signal handlers.
 * This is the recommended default value.  If for some reason the application must be able to handle a different
 * number of concurrent methods use alljoyn_busattachment_create_concurrency.
 *
 * @note Any alljoyn_busattachment allocated using this function must be freed using alljoyn_busattachment_destroy
 *
 * @see alljoyn_busattachment_create_concurrency
 * @see alljoyn_busattachment_destroy
 *
 * @param applicationName       Name of the application.
 * @param allowRemoteMessages   QCC_TRUE if this attachment is allowed to receive messages from remote devices.
 *
 * @return the allocated alljoyn_busattachment
 */
extern AJ_API alljoyn_busattachment AJ_CALL alljoyn_busattachment_create(const char* applicationName, QCC_BOOL allowRemoteMessages);

/**
 * Allocate an alljoyn_busattachment.
 *
 * This will Allocate an alljoyn_busattachment that is capable of using a different value for concurrency then
 * the default value of 4.
 *
 * @note Any alljoyn_busattachment allocated using this function must be freed using alljoyn_busattachment_destroy
 *
 * @see alljoyn_busattachment_create
 * @see alljoyn_busattachment_destroy
 *
 * @param applicationName       Name of the application.
 * @param allowRemoteMessages   True if this attachment is allowed to receive messages from remote devices.
 * @param concurrency           The maximum number of concurrent method and signal handlers locally executing.
 *
 * @return the allocated alljoyn_busattachment
 */
extern AJ_API alljoyn_busattachment AJ_CALL alljoyn_busattachment_create_concurrency(const char* applicationName, QCC_BOOL allowRemoteMessages, uint32_t concurrency);

/**
 * Free an allocated alljoyn_busattachment.
 *
 * @param bus alljoyn_busattachment to free.
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_destroy(alljoyn_busattachment bus);

/**
 * @brief Start the process of spinning up the independent threads used in
 * the bus attachment, preparing it for action.
 *
 * This function only begins the process of starting the bus. Sending and
 * receiving messages cannot begin until the bus is Connect()ed.
 *
 * There are two ways to determine whether the bus is currently connected:
 *    -# alljoyn_busattachment() returns QCC_TRUE
 *    -# alljoyn_busobject_callback object_registered is called by the bus
 *
 * In most cases, it is not required to understand the threading model of
 * the bus attachment, with one important exception: The bus attachment may
 * send callbacks to registered listeners using its own internal threads.
 * This means that any time a listener of any kind is used in a program, the
 * implication is that a the overall program is multithreaded, irrespective
 * of whether or not threads are explicitly used.  This, in turn, means that
 * any time shared state is accessed in listener callback functions, that state
 * must be protected.
 *
 * As soon as Start() is called, clients of a bus attachment with listeners
 * must be prepared to receive callbacks on those listeners in the context
 * of a thread that will be different from the thread running the main
 * program or any other thread in the client.
 *
 * Although intimate knowledge of the details of the threading model are not
 * required to use a bus attachment (beyond the caveat above) we do provide
 * functions on the bus attachment that help users reason about more complex
 * threading situations.  This will apply to situations where clients of the
 * bus attachment are multithreaded and need to interact with the
 * multithreaded bus attachment.  These functions can be especially useful
 * during shutdown, when the two separate threading systems need to be
 * gracefully brought down together.
 *
 * The alljoyn_busattachment function alljoyn_busattachment_start(),
 * alljoyn_busattachment_stop() and alljoyn_busattachment_join() all work together to
 * manage the autonomous activities that can happen in an alljoyn_busattachment.
 * These activities are carried out by so-called hardware threads.  POSIX
 * defines functions used to control hardware threads, which it calls
 * pthreads.  Many threading packages use similar constructs.
 *
 * In a threading package, a start function asks the underlying system to
 * arrange for the start of thread execution.  Threads are not necessarily
 * running when the start function returns, but they are being *started*.  Some time later,
 * a thread of execution appears in a thread run function, at which point the
 * thread is considered *running*.  At some later time, executing a stop function asks the
 * underlying system to arrange for a thread to end its execution.  The system
 * typically sends a message to the thread to ask it to stop doing what it is doing.
 * The thread is running until it responds to the stop message, at which time the
 * run function exits and the thread is considered *stopping*.
 *
 * Note that neither alljoyn_busattachment_start() nor alljoyn_busattachment_stop()
 * are synchronous in the sense that one has actually accomplished the desired
 * effect upon the return from a call.  Of particular interest is the fact that
 * after a call to alljoyn_busattachment_stop(), threads will still be *running* for
 * some non-deterministic time.
 *
 * In order to wait until all of the threads have actually stopped, a
 * blocking call is required.  In threading packages this is typically
 * called join, and our corresponding function is called alljoyn_busattachment_join().
 *
 * An alljoyn_busattachment_start() function call should be thought of as mapping
 * to a threading package start function.  it causes the activity threads in the
 * alljoyn_busattachment to be spun up and gets the attachment ready to do its main
 * job.  As soon as alljoyn_busattachment_start() is called, the user should be prepared
 * for one or more of these threads of execution to pop out of the bus attachment
 * and into a listener callback.
 *
 * The alljoyn_busattachment_stop() function should be thought of as mapping to a
 * threading package stop function.  It asks the alljoyn_busattachment to begin
 * shutting down its various threads of execution, but does not wait for any
 * threads to exit.
 *
 * A call to the alljoyn_busattachment_join() function should be thought of as mapping
 * to a threading package join function call.  It blocks and waits until all of
 * the threads in the alljoyn_busattachment have in fact exited their Run functions,
 * gone through the stopping state and have returned their status.  When
 * the alljoyn_busattachment_join() function returns, one may be assured that no
 * threads are running in the bus attachment, and therefore there will be no callbacks
 * in progress and no further callbacks will ever come out of a particular
 * instance of a bus attachment.
 *
 * It is important to understand that since alljoyn_busattachment_start(),
 * alljoyn_busattachment_stop() and alljoyn_busattachment_join() map to threads
 * concepts and functions, one should not expect them to clean up any bus
 * attachment state when they are called.  These functions are only present to
 * help in orderly termination of complex threading systems.
 *
 * @see alljoyn_busattachment_stop()
 * @see alljoyn_busattachment_join()
 *
 * @param bus The alljoyn_busattachment to start.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_BUS_ALREADY_STARTED if already started
 *      - Other error status codes indicating a failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_start(alljoyn_busattachment bus);

/**
 * @brief Ask the threading subsystem in the bus attachment to begin the
 * process of ending the execution of its threads.
 *
 * The alljoyn_busattachment_stop() function call on a bus attachment should be
 * thought of as mapping to a threading package stop function.  It asks the
 * alljoyn_busattachment to begin shutting down its various threads of execution, but
 * does not wait for any threads to exit.
 *
 * A call to alljoyn_busattachment_stop() is implied as one of the first steps in
 * the destruction of a bus attachment.
 *
 * @warning There is no guarantee that a listener callback may begin executing
 * after a call to alljoyn_busattachment_stop().  To achieve that effect, the
 * alljoyn_busattachment_stop() must be followed by an alljoyn_busattachment_join().
 *
 * @see alljoyn_busattachment_start()
 * @see alljoyn_busattachment_join()
 *
 * @param bus  alljoyn_busattachment to stop.
 *
 * @return
 *      - #ER_OK if successful.
 *      - An error status if unable to stop the message bus
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_stop(alljoyn_busattachment bus);

/**
 * @brief Wait for all of the threads spawned by the bus attachment to be
 * completely exited.
 *
 * A call to the alljoyn_busattachment_join() function should be thought of as
 * mapping to a threading package join function call.  It blocks and waits
 * until all of the threads in the alljoyn_busattachment have, in fact, exited
 * their Run functions, gone through the stopping state and have returned their
 * status.  When the alljoyn_busattachment_join() function returns, one may be
 * assured that no threads are running in the bus attachment, and therefore
 * there will be no callbacks in progress and no further callbacks will ever
 * come out of the instance of a bus attachment on which
 * alljoyn_busattachment_join() was called.
 *
 * A call to alljoyn_busattachment_join() is implied as one of the first steps
 * in the destruction of a bus attachment.  Thus, when a bus attachment is
 * destroyed, it is guaranteed that before it completes its destruction process,
 * there will be no callbacks in process.
 *
 * @warning If alljoyn_busattachment_join() is called without a previous
 * alljoyn_busattachment_stop() it will result in blocking "forever."
 *
 * @see alljoyn_busattachment_start()
 * @see alljoyn_busattachment_stop()
 *
 * @param bus alljoyn_busattachment to join.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_BUS_ALREADY_STARTED if already started
 *      - Other error status codes indicating a failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_join(alljoyn_busattachment bus);

/**
 * Get the concurrent method and signal handler limit.
 *
 * @param bus    The alljoyn_busattachment on which to get the concurrent method and
 *               signal handler limit.
 *
 * @return The maximum number of concurrent method and signal handlers.
 */
extern AJ_API uint32_t AJ_CALL alljoyn_busattachment_getconcurrency(alljoyn_busattachment bus);

/**
 * Get the connect spec used by the alljoyn_busattachment
 *
 * @param bus    The alljoyn_busattachment to obtain the connect spec from.
 *
 * @return The string representing the connect spec used by the alljoyn_busattachment
 */
extern AJ_API const char* AJ_CALL alljoyn_busattachment_getconnectspec(alljoyn_busattachment bus);

/**
 * Allow the currently executing method/signal handler to enable concurrent callbacks
 * during the scope of the handler's execution.
 *
 * This member function can ONLY be called from within the body of a signal
 * handler, method handler or other AllJoyn callback. It allows AllJoyn to
 * dispatch a single (additional) callback while the current one is still
 * executing. This method is typically used when a method, signal handler or
 * other AllJoyn callback needs to execute for a long period of time or when
 * the callback needs to make any kind of blocking call.
 *
 * This function MUST be called prior to making any non-asynchronous AllJoyn
 * remote procedure calls from within an AllJoyn callback. This includes
 * calls such as alljoyn_busattachment_joinsession(),
 * alljoyn_busattachment_advertisename(),
 * alljoyn_busattachment_canceladvertisename(),
 * alljoyn_busattachment_findadvertisedname(),
 * alljoyn_busattachment_canceladvertisename(),
 * alljoyn_busattachment_setlinktimeout(), etc.
 *
 * alljoyn_busattachment_enableconcurrentcallbacks doesn't take effect when a
 * alljoyn_busattachment is created with just one thread. If the
 * alljoyn_busattachment is created with just one thread,
 * i.e.`alljoyn_busattachment_create_concurrency(appName, true, 1)`, and the
 * application developer attempts to make a blocking method call in a callback
 * after invoking alljoyn_busattachment_enableconcurrentcallbacks(), the
 * application will deadlock.
 *
 * For the same reason that alljoyn_busattachment_enableconcurrentcallbacks
 * cannot be used with just one thread, the maximum number of concurrent
 * callbacks is limited to the value specified when creating the BusAttachment.
 * If no concurrency value was chosen the default is 4. It is the application
 * developers responsibility to make sure the maximum number of concurrent
 * callbacks is not exceeded. If the maximum number is exceeded the application
 * will deadlock.
 *
 * @param bus    The alljoyn_busattachment to enable concurrent callbacks on
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_enableconcurrentcallbacks(alljoyn_busattachment bus);

/**
 * Create an interface description with a given name.
 *
 * Interfaces created using the this function will automatically use
 * AJ_IFC_SCURITY_INHERIT as its security policy. To create an interface that
 * uses a different security policy @see alljoyn_busattachment_createinterface_secure
 *
 * @param bus    The alljoyn_busattachment on which to create an interface.
 * @param name   The requested interface name.
 * @param[out] iface
 *      - Interface description
 *      - NULL if cannot be created.
 *
 * @return
 *      - #ER_OK if creation was successful.
 *      - #ER_BUS_IFACE_ALREADY_EXISTS if requested interface already exists
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_createinterface(alljoyn_busattachment bus, const char* name,
                                                                    alljoyn_interfacedescription* iface);

/**
 * Create an interface description with a given name.
 *
 * @param bus    The alljoyn_busattachment on which to create an interface.
 * @param name   The requested interface name.
 * @param[out] iface
 *      - Interface description
 *      - NULL if cannot be created.
 * @param secPolicy security policy of this interface it can be AJ_IFC_SECURITY_INHERIT,
 *                  AJ_IFC_SECURITY_REQUIRED, or AJ_IFC_SECURITY_OFF
 * @see alljoyn_interfacedescription_securitypolicy
 * @see alljoyn_busattachment_createinterface
 *
 * @return
 *      - #ER_OK if creation was successful.
 *      - #ER_BUS_IFACE_ALREADY_EXISTS if requested interface already exists
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_createinterface_secure(alljoyn_busattachment bus, const char* name,
                                                                           alljoyn_interfacedescription* iface,
                                                                           alljoyn_interfacedescription_securitypolicy secPolicy);

/**
 * Connect to a remote bus address.
 *
 * @param bus          The alljoyn_busattachment to be connected.
 * @param connectSpec  A transport connection spec string of the form:
 *                     @c "<transport>:<param1>=<value1>,<param2>=<value2>...[;]"
 *                     if connectSpec is NULL the bus attachment will attempt to
 *                     connect to the bus using a built in connectSpec.
 *
 * @return
 *      - #ER_OK if successful.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_connect(alljoyn_busattachment bus, const char* connectSpec);

/**
 * Register an object that will receive bus event notifications.
 *
 * @param bus       The alljoyn_busattachment on which to attach an alljoyn_buslistener.
 * @param listener  Object instance that will receive bus event notifications.
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_registerbuslistener(alljoyn_busattachment bus, alljoyn_buslistener listener);

/**
 * Unregister an object that was previously registered with
 * alljoyn_busattachment_registerbuslistener.
 *
 * @param bus       The alljoyn_busattachment from which to detach an alljoyn_buslistener.
 * @param listener  Object instance to un-register as a listener.
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_unregisterbuslistener(alljoyn_busattachment bus, alljoyn_buslistener listener);

/**
 * Register interest in a well-known name prefix for the purpose of discovery over transports included in TRANSPORT_ANY.
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.FindAdvertisedName method call to the local router
 * and interprets the response.
 *
 * @param      bus           The alljoyn_busattachment on which to register interest in the namePrefix.
 * @param[in]  namePrefix    Well-known name prefix that application is interested in receiving
 *                           alljoyn_buslistener_foundadvertisedname notifications about.
 *
 * @return
 *      - #ER_OK iff router response was received and discovery was successfully started.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_findadvertisedname(alljoyn_busattachment bus, const char* namePrefix);

/**
 * Register interest in a well-known name prefix for the purpose of discovery over specified transports.
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.FindAdvertisedNameByTransport method call to the local router
 * and interprets the response.
 *
 * @param      bus           The alljoyn_busattachment on which to register interest in the namePrefix.
 * @param[in]  namePrefix    Well-known name prefix that application is interested in receiving
 *                           alljoyn_buslistener_foundadvertisedname notifications about.
 * @param[in]  transports    Set of transports to use for discovery.
 *
 * @return
 *      - #ER_OK iff router response was received and discovery was successfully started.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_findadvertisednamebytransport(alljoyn_busattachment bus, const char* namePrefix, alljoyn_transportmask transports);

/**
 * Cancel interest in a well-known name prefix that was previously registered
 * with alljoyn_busattachment_findadvertisedname over transports included in TRANSPORT_ANY.
 * This method is a shortcut/helper
 * that issues an org.alljoyn.Bus.CancelFindAdvertisedName method call to the
 * local router and interprets the response.
 *
 * @param      bus           The alljoyn_busattachment from which to remove interest in the namePrefix.
 * @param[in]  namePrefix    Well-known name prefix that application is no longer interested in receiving
 *                           BusListener::FoundAdvertisedName notifications about.
 *
 * @return
 *      - #ER_OK iff router response was received and cancel was successfully completed.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_cancelfindadvertisedname(alljoyn_busattachment bus, const char* namePrefix);

/**
 * Cancel interest in a well-known name prefix that was previously registered
 * with alljoyn_busattachment_findadvertisedname over specified transports.  This method is a shortcut/helper
 * that issues an org.alljoyn.Bus.CancelFindAdvertisedNameByTransport method call to the
 * local router and interprets the response.
 *
 * @param      bus           The alljoyn_busattachment from which to remove interest in the namePrefix.
 * @param[in]  namePrefix    Well-known name prefix that application is no longer interested in receiving
 *                           BusListener::FoundAdvertisedName notifications about.
 * @param[in]  transports    Set of transports to cancel discovery on.
 *
 * @return
 *      - #ER_OK iff router response was received and cancel was successfully completed.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_cancelfindadvertisednamebytransport(alljoyn_busattachment bus, const char* namePrefix, alljoyn_transportmask transports);

/**
 * Advertise the existence of a well-known name to other (possibly disconnected) AllJoyn routers.
 *
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.AdvertisedName method call to the local router
 * and interprets the response.
 *
 * @param[in]  bus           The bus on which to advertise the name.
 * @param[in]  name          the well-known name to advertise. (Must be owned by the caller via RequestName).
 * @param[in]  transports    Set of transports to use for sending advertisment.
 *
 * @return
 *      - #ER_OK iff router response was received and advertise was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_advertisename(alljoyn_busattachment bus, const char* name, alljoyn_transportmask transports);

/**
 * Stop advertising the existence of a well-known name to other AllJoyn routers.
 *
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.CancelAdvertiseName method call to the local router
 * and interprets the response.
 * @param[in]  bus           The bus on which we wish to cancel the name advertisement
 * @param[in]  name          A well-known name that was previously advertised via AdvertiseName.
 * @param[in]  transports    Set of transports whose name advertisment will be cancelled.
 *
 * @return
 *      - #ER_OK iff router response was received and advertisements were sucessfully stopped.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_canceladvertisename(alljoyn_busattachment bus, const char* name, alljoyn_transportmask transports);

/**
 * Retrieve an existing activated alljoyn_interfacedescription.
 *
 * @param bus        The alljoyn_busattachment from which to retrieve the interface.
 * @param name       Interface name.
 *
 * @return
 *      - A pointer to the registered interface
 *      - NULL if interface doesn't exist
 */
extern AJ_API const alljoyn_interfacedescription AJ_CALL alljoyn_busattachment_getinterface(alljoyn_busattachment bus, const char* name);

/**
 * Join a session.
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.JoinSession method call to the local router
 * and interprets the response.
 *
 * @param[in]  bus              alljoyn_busattachment with which to join a session.
 * @param[in]  sessionHost      Bus name of attachment that is hosting the session to be joined.
 * @param[in]  sessionPort      alljoyn_sessionport of sessionHost to be joined.
 * @param[in]  listener         Optional listener called when session related events occur. May be NULL.
 * @param[out] sessionId        Unique identifier for session.
 * @param[in,out] opts          Session options.
 *
 * @return
 *      - #ER_OK iff router response was received and the session was successfully joined.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_joinsession(alljoyn_busattachment bus, const char* sessionHost,
                                                                alljoyn_sessionport sessionPort, alljoyn_sessionlistener listener,
                                                                alljoyn_sessionid* sessionId, alljoyn_sessionopts opts);


/**
 * Join a session.
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.JoinSession method call to the local router
 * and interprets the response.
 *
 * This call executes asynchronously. When the JoinSession response is received, the callback will be called.
 *
 * @param[in]  bus              alljoyn_busattachment with which to join a session.
 * @param[in]  sessionHost      Bus name of attachment that is hosting the session to be joined.
 * @param[in]  sessionPort      alljoyn_sessionport of sessionHost to be joined.
 * @param[in]  listener         Optional listener called when session related events occur. May be NULL.
 * @param[in]  opts             Session options.
 * @param[in]  callback         Called when JoinSession response is received.
 * @param[in]  context          User defined context which will be passed as-is to callback.
 *
 * @return
 *      - #ER_OK iff method call to local router response was was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_joinsessionasync(alljoyn_busattachment bus,
                                                                     const char* sessionHost,
                                                                     alljoyn_sessionport sessionPort,
                                                                     alljoyn_sessionlistener listener,
                                                                     const alljoyn_sessionopts opts,
                                                                     alljoyn_busattachment_joinsessioncb_ptr callback,
                                                                     void* context);

/**
 * Register a BusObject
 *
 * @param bus      The bus on which to register the object.
 * @param obj      BusObject to register.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_BAD_OBJ_PATH for a bad object path
 *      - #ER_BUS_OBJ_ALREADY_EXISTS if an object is already registered at this path
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_registerbusobject(alljoyn_busattachment bus, alljoyn_busobject obj);

/**
 * Register a BusObject. Bus objects registered using this function will require
 * authentication. Unless the interfaces security policy is AJ_IFC_SECURITY_OFF.
 *
 *
 * @param bus      The bus on which to register the object.
 * @param obj      BusObject to register.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_BAD_OBJ_PATH for a bad object path
 *      - #ER_BUS_OBJ_ALREADY_EXISTS if an object is already registered at this path
 *
 * @see alljoyn_busattachment_registerbusobject
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_registerbusobject_secure(alljoyn_busattachment bus, alljoyn_busobject obj);

/**
 * Unregister a BusObject
 *
 * @param bus     The bus from which to unregister the object.
 * @param object  Object to be unregistered.
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_unregisterbusobject(alljoyn_busattachment bus, alljoyn_busobject object);

/**
 * Request a well-known name.
 * This method is a shortcut/helper that issues an org.freedesktop.DBus.RequestName method call to the local router
 * and interprets the response.
 *
 * @param[in]  bus            The bus on which to request the specified name.
 * @param[in]  requestedName  Well-known name being requested.
 * @param[in]  flags          Bitmask of DBUS_NAME_FLAG_* defines (see DBusStdDefines.h)
 *
 * @return
 *      - #ER_OK iff router response was received and request was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_requestname(alljoyn_busattachment bus, const char* requestedName, uint32_t flags);

/**
 * Release a previously requeted well-known name.
 * This method is a shortcut/helper that issues an org.freedesktop.DBus.ReleaseName method call to the local router
 * and interprets the response.
 *
 * @param[in]  bus   The alljoyn_busattachment from which to release the name.
 * @param[in]  name  Well-known name being released.
 *
 * @return
 *      - #ER_OK iff router response was received amd the name was successfully released.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_releasename(alljoyn_busattachment bus, const char* name);

/**
 * Make an alljoyn_sessionport available for external alljoyn_busattachments to join.
 *
 * Each alljoyn_busattachment binds its own set of alljoyn_sessionports. Session joiners use the
 * bound session port along with the name of the attachment to create a persistent logical
 * connection (called a Session) with the original alljoyn_busattachment.
 *
 * An alljoyn_sessionport and bus name form a unique identifier that
 * alljoyn_busattachments use when joining a session.
 *
 * alljoyn_sessionport values can be pre-arranged between AllJoyn services and their clients (well-known
 * alljoyn_sessionports).
 *
 * Once a session is joined using one of the service's well-known alljoyn_sessionports,
 * the service may bind additional alljoyn_sessionports (dynamically) and share
 * these alljoyn_sessionports with the joiner over the original session.
 * The joiner can then create additional sessions with the service by calling
 * JoinSession with these dynamic alljoyn_sessionport ids.
 *
 * @param[in]     bus              The bus on which to make the session port available.
 * @param[in,out] sessionPort      alljoyn_sessionport value to bind or SESSION_PORT_ANY to allow this method
 *                                 to choose an available port. On successful return, this value
 *                                 contains the chosen alljoyn_sessionport.
 *
 * @param[in]     opts             Session options that joiners must agree to in order to
 *                                 successfully join the session.
 *
 * @param[in]     listener  Called by the bus when session related events occur.
 *
 * @return
 *      - #ER_OK iff router response was received and the bind operation was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_bindsessionport(alljoyn_busattachment bus, alljoyn_sessionport* sessionPort,
                                                                    const alljoyn_sessionopts opts, alljoyn_sessionportlistener listener);

/**
 * Cancel an existing port binding.
 *
 * @param[in]   bus            The bus on which to cancel the port binding.
 * @param[in]   sessionPort    Existing session port to be un-bound.
 *
 * @return
 *      - #ER_OK iff router response was received and the bind operation was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_unbindsessionport(alljoyn_busattachment bus, alljoyn_sessionport sessionPort);

/**
 * Enable peer-to-peer security. This function must be called by applications that
 * want to use authentication and encryption. The bus must have been started by calling
 * alljoyn_busattachment_start() before this function is called. If the application
 * is providing its own key store implementation it must have already called
 * alljoyn_busattachment_registerkeystorelistener() before calling this function.
 *
 * Once peer security has been enabled it is not possible to change the authMechanism set without
 * clearing it first (setting authMechanism to NULL). This is true regardless of whether the BusAttachment
 * has been disconnected or not.
 *
 * @param bus              The bus on which to enable security.
 *
 * @param authMechanisms   The authentication mechanism(s) to use for peer-to-peer authentication.
 *                         If this parameter is NULL peer-to-peer authentication is disabled.
 *                         This is a space separated list of any of the following values: ALLJOYN_SRP_LOGON,
 *                         ALLJOYN_SRP_KEYX, ALLJOYN_ECDHE_NULL, ALLJOYN_ECDHE_PSK, ALLJOYN_ECDHE_ECDSA, GSSAPI,
 *                         ALLJOYN_ECDHE_SPEKE. Note that the SRP and PSK mechanisms are deprecated and will be
 *                         removed in a future release.
 *
 * @param listener         Passes password and other authentication related requests to the application.
 *
 * @param keyStoreFileName Optional parameter to specify the filename of the default key store. The
 *                         default value is the applicationName parameter of alljoyn_busattachment_create().
 *                         Note that this parameter is only meaningful when using the default
 *                         key store implementation.
 *
 * @param isShared         This parameter is not used as of 16.04. It is ignored internally (always shared).
 *
 * @remark
 * For Security 2.0 applications, after the application has been claimed, it is recommended that only
 * ALLJOYN_ECDHE_ECDSA be provided in the authMechanisms parameter. If the application is unclaimed but will
 * be claimed locally via the alljoyn_permissionconfigurator_claim call, it is also recommended that only
 * ALLJOYN_ECDHE_ECDSA be provided in the authMechanisms parameter, and that the claim capabilities be left as
 * default, to prevent possible claiming over the network by a rogue security manager.
 *
 * If this application will be claimed over the network, peer security should first be enabled with
 * ALLJOYN_ECDHE_ECDSA and the supported mechanisms for claiming. After it is claimed, and the application
 * received the EndManagement callback, the application should then re-enable peer security with only
 * ALLJOYN_ECDHE_ECDSA.
 *
 * Unless a bus attachment will be used by a security manager to claim other applications, or will interact
 * with applications using Security 1.0, and so will need to negotiate other authentication mechanisms,
 * only ALLJOYN_ECDHE_ECDSA should be enabled while claimed.
 *
 * @return
 *      - #ER_OK if peer security was enabled.
 *      - #ER_BUS_BUS_NOT_STARTED alljoyn_busattachment_start has not been called
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_enablepeersecurity(alljoyn_busattachment bus, const char* authMechanisms,
                                                                       alljoyn_authlistener listener, const char* keyStoreFileName,
                                                                       QCC_BOOL isShared);

/**
 * Enable peer-to-peer security. This function must be called by applications that
 * want to use authentication and encryption. The bus must have been started by calling
 * alljoyn_busattachment_start() before this function is called. If the application
 * is providing its own key store implementation it must have already called
 * alljoyn_busattachment_registerkeystorelistener() before calling this function.
 *
 * Once peer security has been enabled it is not possible to change the authMechanism set without
 * clearing it first (setting authMechanism to NULL). This is true regardless of whether the BusAttachment
 * has been disconnected or not.
 *
 * @param bus                   The bus on which to enable security.
 *
 * @param authMechanisms        The authentication mechanism(s) to use for peer-to-peer authentication.
 *                              If this parameter is NULL peer-to-peer authentication is disabled.
 *                              This is a space separated list of any of the following values: ALLJOYN_SRP_LOGON,
 *                              ALLJOYN_SRP_KEYX, ALLJOYN_ECDHE_NULL, ALLJOYN_ECDHE_PSK, ALLJOYN_ECDHE_ECDSA, GSSAPI,
 *                              ALLJOYN_ECDHE_SPEKE. Note that the SRP and PSK mechanisms are deprecated and will be
 *                              removed in a future release.
 *
 * @param authListener          Passes password and other authentication related requests to the application.
 *
 * @param keyStoreFileName      Optional parameter to specify the filename of the default key store. The
 *                              default value is the applicationName parameter of alljoyn_busattachment_create().
 *                              Note that this parameter is only meaningful when using the default
 *                              key store implementation.
 *
 * @param isShared              Optional parameter that indicates if the key store is shared between multiple
 *                              applications. It is generally harmless to set this to true even when the
 *                              key store is not shared but it adds some unnecessary calls to the key store
 *                              listener to load and store the key store in this case.
 *
 * @param permissionConfigurationListener    Passes security 2.0 callbacks to the application.
 *
 * @return
 *      - #ER_OK if peer security was enabled.
 *      - #ER_BUS_BUS_NOT_STARTED alljoyn_busattachment_start has not been called
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_enablepeersecuritywithpermissionconfigurationlistener(alljoyn_busattachment bus,
                                                                                                          const char* authMechanisms,
                                                                                                          alljoyn_authlistener authListener,
                                                                                                          const char* keyStoreFileName,
                                                                                                          QCC_BOOL isShared,
                                                                                                          alljoyn_permissionconfigurationlistener permissionConfigurationListener);

/**
 * Check is peer security has been enabled for this bus attachment.
 *
 * @param bus The bus on which to query if peer security is enabled.
 *
 * @return   Returns QCC_TRUE if peer security has been enabled, QCC_FALSE otherwise.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_busattachment_ispeersecurityenabled(alljoyn_busattachment bus);

/**
 * Initialize one more interface descriptions from an XML string in DBus introspection format.
 * The root tag of the XML can be a \<node\> or a standalone \<interface\> tag. To initialize more
 * than one interface the interfaces need to be nested in a \<node\> tag.
 *
 * Note that when this method fails during parsing, the return code will be set accordingly.
 * However, any interfaces which were successfully parsed prior to the failure may be registered
 * with the bus.
 *
 * @param bus     The bus on which to create interfaces.
 * @param xml     An XML string in DBus introspection format.
 *
 * @return
 *      - #ER_OK if parsing is completely successful.
 *      - An error status otherwise.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_createinterfacesfromxml(alljoyn_busattachment bus, const char* xml);

/**
 * Returns the existing activated InterfaceDescriptions.
 *
 * @param bus        The bus to obtaining the interfaces from
 * @param ifaces     A pointer to an InterfaceDescription array to receive the interfaces. Can be NULL in
 *                   which case no interfaces are returned and the return value gives the number
 *                   of interfaces available.
 * @param numIfaces  The size of the InterfaceDescription array. If this value is smaller than the total
 *                   number of interfaces only numIfaces will be returned.
 *
 * @return  The number of interfaces returned or the total number of interfaces if ifaces is NULL.
 */
extern AJ_API size_t AJ_CALL alljoyn_busattachment_getinterfaces(const alljoyn_busattachment bus,
                                                                 const alljoyn_interfacedescription* ifaces, size_t numIfaces);

/**
 * Delete an interface description with a given name.
 *
 * Deleting an interface is only allowed if that interface has never been activated.
 *
 * @param bus    The bus from which to delete the interface.
 * @param iface  The un-activated interface to be deleted.
 *
 * @return
 *      - #ER_OK if deletion was successful
 *      - #ER_BUS_NO_SUCH_INTERFACE if interface was not found
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_deleteinterface(alljoyn_busattachment bus, alljoyn_interfacedescription iface);
/**
 * Returns QCC_TRUE if the mesage bus has been started.
 *
 * @param bus The bus to query.
 *
 * @return true if the message bus has been started i.e. alljoyn_busattachment_start() has been called.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_busattachment_isstarted(alljoyn_busattachment bus);

/**
 * Indicates #alljoyn_busattachment_stop() has been called
 *
 * @param bus The bus to query.
 *
 * @return QCC_TRUE if the mesage bus has been requested to stop.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_busattachment_isstopping(alljoyn_busattachment bus);

/**
 * Indicate whether bus is currently connected.
 *
 * Messages can only be sent or received when the bus is connected.
 *
 * @param bus The bus to query.
 * @return true if the bus is connected.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_busattachment_isconnected(const alljoyn_busattachment bus);

/**
 * Disconnect a remote bus address connection.
 *
 * @param bus          The bus to disconnect.
 * @param unused       Deprecated parameter.
 *
 * @return
 *          - #ER_OK if successful
 *          - #ER_BUS_BUS_NOT_STARTED if the bus is not started
 *          - #ER_BUS_NOT_CONNECTED if the %alljoyn_busattachment is not connected to the bus
 *          - Other error status codes indicating a failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_disconnect(alljoyn_busattachment bus, const char* unused);

/**
 * Get the org.freedesktop.DBus proxy object.
 *
 * @param bus The bus from which to get the object.
 *
 * @return org.freedesktop.DBus proxy object
 */
extern AJ_API const alljoyn_proxybusobject AJ_CALL alljoyn_busattachment_getdbusproxyobj(alljoyn_busattachment bus);

/**
 * Get the org.alljoyn.Bus proxy object.
 *
 * @param bus The bus from which to get the object.
 *
 * @return org.alljoyn.Bus proxy object
 */
extern AJ_API const alljoyn_proxybusobject AJ_CALL alljoyn_busattachment_getalljoynproxyobj(alljoyn_busattachment bus);

/**
 * Get the org.alljoyn.Debug proxy object.
 *
 * @param bus The bus from which to get the object.
 *
 * @return org.alljoyn.Debug proxy object
 */
extern AJ_API const alljoyn_proxybusobject AJ_CALL alljoyn_busattachment_getalljoyndebugobj(alljoyn_busattachment bus);

/**
 * Get the unique name of this alljoyn_busattachment.
 *
 * @param bus The bus to query.
 *
 * @return The unique name of this alljoyn_busattachment.
 */
extern AJ_API const char* AJ_CALL alljoyn_busattachment_getuniquename(const alljoyn_busattachment bus);

/**
 * Get the guid of the local router as a string
 *
 * @param bus The bus to query.
 *
 * @return GUID of local AllJoyn router as a string.
 */
extern AJ_API const char* AJ_CALL alljoyn_busattachment_getglobalguidstring(const alljoyn_busattachment bus);


/**
 * Register a signal handler.
 *
 * Signals are forwarded to the signalHandler if sender, interface, member and path
 * qualifiers are ALL met.
 *
 * @param bus             The alljoyn_busattachment to register the signal handler with
 * @param signal_handler  The signal handler method.
 * @param member          The interface/member of the signal.
 * @param srcPath         The object path of the emitter of the signal or NULL for all paths.
 * @return #ER_OK
 */
/*
 * may need to create another registersignalhandler that takes a MessageReceiver
 * type.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_registersignalhandler(alljoyn_busattachment bus,
                                                                          alljoyn_messagereceiver_signalhandler_ptr signal_handler,
                                                                          const alljoyn_interfacedescription_member member,
                                                                          const char* srcPath);

/**
 * Register a signal handler with a filter rule.
 *
 * Signals are forwarded to the signalHandler if sender, interface, member and rule
 * qualifiers are ALL met.
 *
 * @param bus             The alljoyn_busattachment to register the signal handler with
 * @param signal_handler  The signal handler method.
 * @param member          The interface/member of the signal.
 * @param matchRule       The filter rule.
 * @return #ER_OK
 */
/*
 * may need to create another registersignalhandler that takes a MessageReceiver
 * type.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_registersignalhandlerwithrule(alljoyn_busattachment bus,
                                                                                  alljoyn_messagereceiver_signalhandler_ptr signal_handler,
                                                                                  const alljoyn_interfacedescription_member member,
                                                                                  const char* matchRule);

/**
 * Unregister a signal handler.
 *
 * Remove the signal handler that was registered with the given parameters.
 *
 * @param bus             The alljoyn_busattachment to unregister the signal handler with
 * @param signal_handler  The signal handler method.
 * @param member          The interface/member of the signal.
 * @param srcPath         The object path of the emitter of the signal or NULL for all paths.
 * @return #ER_OK
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_unregistersignalhandler(alljoyn_busattachment bus,
                                                                            alljoyn_messagereceiver_signalhandler_ptr signal_handler,
                                                                            const alljoyn_interfacedescription_member member,
                                                                            const char* srcPath);
/**
 * Unregister a signal handler with a filter rule.
 *
 * Remove the signal handler that was registered with the given parameters.
 *
 * @param bus             The alljoyn_busattachment to unregister the signal handler with
 * @param signal_handler  The signal handler method.
 * @param member          The interface/member of the signal.
 * @param matchRule       The filter rule.
 * @return #ER_OK
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_unregistersignalhandlerwithrule(alljoyn_busattachment bus,
                                                                                    alljoyn_messagereceiver_signalhandler_ptr signal_handler,
                                                                                    const alljoyn_interfacedescription_member member,
                                                                                    const char* matchRule);

/**
 * Unregister all signal and reply handlers for the specified alljoyn_busattachment.
 *
 * @param bus  The alljoyn_busattachment to unregister the signal handler with
 * @return ER_OK if successful.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_unregisterallhandlers(alljoyn_busattachment bus);
/**
 * Set a key store listener to listen for key store load and store requests.
 * This overrides the internal key store listener.
 *
 * @param bus       The bus on which to register the key store listener.
 * @param listener  The key store listener to set.
 *
 * @return
 *      - #ER_OK if the key store listener was set
 *      - #ER_BUS_LISTENER_ALREADY_SET if a listener has been set by this function or because
 *         alljoyn_busattachment_enablepeersecurity has been called.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_registerkeystorelistener(alljoyn_busattachment bus, alljoyn_keystorelistener listener);

/**
 * Reloads the key store for this bus attachment. This function would normally only be called in
 * the case where a single key store is shared between multiple bus attachments, possibly by different
 * applications. It is up to the applications to coordinate how and when the shared key store is
 * modified.
 *
 * @param bus The bus on which to reload the key store.
 *
 * @return - ER_OK if the key store was succesfully reloaded
 *         - An error status indicating that the key store reload failed.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_reloadkeystore(alljoyn_busattachment bus);

/**
 * Clears all stored keys from the key store. All store keys and authentication information is
 * deleted and cannot be recovered. Any passwords or other credentials will need to be reentered
 * when establishing secure peer connections.
 *
 * @param bus The bus on which to clear the key store.
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_clearkeystore(alljoyn_busattachment bus);

/**
 * Clear the keys associated with aa specific remote peer as identified by its peer GUID. The
 * peer GUID associated with a bus name can be obtained by calling GetPeerGUID().
 *
 * @param bus   The bus from which to clear specific keys.
 * @param guid  The guid of a remote authenticated peer.
 *
 * @return  - ER_OK if the keys were cleared
 *          - ER_UNKNOWN_GUID if there is no peer with the specified GUID
 *          - Other errors
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_clearkeys(alljoyn_busattachment bus, const char* guid);

/**
 * Set the expiration time on keys associated with a specific remote peer as identified by its
 * peer GUID. The peer GUID associated with a bus name can be obtained by calling GetPeerGUID().
 * If the timeout is 0 this is equivalent to calling ClearKeys().
 *
 * @param bus      The bus on which to set a key expiration.
 * @param guid     The GUID of a remote authenticated peer.
 * @param timeout  The time in seconds relative to the current time to expire the keys.
 *
 * @return  - ER_OK if the expiration time was succesfully set.
 *          - ER_UNKNOWN_GUID if there is no authenticated peer with the specified GUID
 *          - Other errors
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_setkeyexpiration(alljoyn_busattachment bus, const char* guid, uint32_t timeout);

/**
 * Get the expiration time on keys associated with a specific authenticated remote peer as
 * identified by its peer GUID. The peer GUID associated with a bus name can be obtained by
 * calling GetPeerGUID().
 *
 * @param bus      The bus to query.
 * @param guid     The GUID of a remote authenticated peer.
 * @param timeout  The time in seconds relative to the current time when the keys will expire.
 *
 * @return  - ER_OK if the expiration time was succesfully set.
 *          - ER_UNKNOWN_GUID if there is no authenticated peer with the specified GUID
 *          - Other errors
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_getkeyexpiration(alljoyn_busattachment bus, const char* guid, uint32_t* timeout);

/**
 * Adds a logon entry string for the requested authentication mechanism to the key store. This
 * allows an authenticating server to generate offline authentication credentials for securely
 * logging on a remote peer using a user-name and password credentials pair. This only applies
 * to authentication mechanisms that support a user name + password logon functionality.
 *
 * @param bus           The bus on which to add a logon entry.
 * @param authMechanism The authentication mechanism.
 * @param userName      The user name to use for generating the logon entry.
 * @param password      The password to use for generating the logon entry. If the password is
 *                      NULL the logon entry is deleted from the key store.
 *
 * @return
 *      - #ER_OK if the logon entry was generated.
 *      - #ER_BUS_INVALID_AUTH_MECHANISM if the authentication mechanism does not support
 *                                       logon functionality.
 *      - #ER_BAD_ARG_2 indicates a null string was used as the user name.
 *      - #ER_BAD_ARG_3 indicates a null string was used as the password.
 *      - Other error status codes indicating a failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_addlogonentry(alljoyn_busattachment bus, const char* authMechanism,
                                                                  const char* userName, const char* password);

/**
 * Add a DBus match rule.
 * This method is a shortcut/helper that issues an org.freedesktop.DBus.AddMatch method call to the local router.
 *
 * @param[in]  bus   The bus on which to add the match rule.
 * @param[in]  rule  Match rule to be added (see DBus specification for format of this string).
 *
 * @return
 *      - #ER_OK if the AddMatch request was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_addmatch(alljoyn_busattachment bus, const char* rule);

/**
 * Remove a DBus match rule.
 * This method is a shortcut/helper that issues an org.freedesktop.DBus.RemoveMatch method call to the local router.
 *
 * @param[in]  bus   The bus from which to remove the match rule.
 * @param[in]  rule  Match rule to be removed (see DBus specification for format of this string).
 *
 * @return
 *      - #ER_OK if the RemoveMatch request was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_removematch(alljoyn_busattachment bus, const char* rule);

/**
 * Set the SessionListener for an existing sessionId.
 * Calling this method will override the listener set by a previoius call to SetSessionListener or any
 * listener specified in JoinSession.
 *
 * @param bus          The bus on which to assign the SessionListener.
 * @param sessionId    The session id of an existing session.
 * @param listener     The SessionListener to associate with the session. May be NULL to clear previous listener.
 * @return  ER_OK if successful.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_setsessionlistener(alljoyn_busattachment bus, alljoyn_sessionid sessionId,
                                                                       alljoyn_sessionlistener listener);

/**
 * Leave an existing session.
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.LeaveSession method call to the local router
 * and interprets the response.
 *
 * @param[in]  bus           The bus on which to leave the session.
 * @param[in]  sessionId     Session id.
 *
 * @return
 *      - #ER_OK iff router response was received and the leave operation was successfully completed.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_leavesession(alljoyn_busattachment bus, alljoyn_sessionid sessionId);

/**
 * Explicitly secure the connection to the remote peer. Peer-to-peer
 * connections can only be secured if alljoyn_busattachment_enablepeersecurity() was previously called on the bus
 * attachment. If the peer-to-peer connection is already secure this
 * function does nothing. Note that peer-to-peer connections are automatically secured when a
 * method call requiring encryption is sent.
 *
 * This call causes messages to be sent on the bus, therefore it cannot be called within AllJoyn
 * callbacks (method/signal/reply handlers or ObjectRegistered callbacks, etc.)
 *
 * @param[in]  bus        The busattachment on which to secure the connection.
 * @param[in]  name       The unique name of the remote peer or NULL to secure the connections to all peers
 *                        this alljoyn_busattachment is in session with.
 * @param[in]  forceAuth  If true, forces re-authentication even if the peer connection is already
 *                        authenticated.
 *
 * @return
 *          - #ER_OK if the connection was secured or an error status indicating that the
 *            connection could not be secured.
 *          - #ER_BUS_NO_AUTHENTICATION_MECHANISM if alljoyn_busattachment_enablepeersecurity() has not been called.
 *          - #ER_AUTH_FAIL if the attempt(s) to authenticate the peer failed.
 *          - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_secureconnection(alljoyn_busattachment bus, const char* name, QCC_BOOL forceAuth);

/**
 * Asynchronously secure the connection to the remote peer. Peer-to-peer connections can only
 * be secured if alljoyn_busattachment_enablepeersecurity() was previously called on the bus attachment.
 * If the peer-to-peer connection is already secure this function does nothing.
 * Note that peer-to-peer connections are automatically secured when a
 * method call requiring encryption is sent.
 *
 * Notification of success or failure is via the alljoyn_authlistener passed to alljoyn_busattachment_enablepeersecurity().
 *
 * @param[in]  bus        The busattachment on which to secure the connection.
 * @param[in]  name       The unique name of the remote peer or NULL to secure the connections to all peers
 *                        this alljoyn_busattachment is in session with.
 * @param[in]  forceAuth  If true, forces re-authentication even if the peer connection is already
 *                        authenticated.
 * @return
 *          - #ER_OK if securing could begin.
 *          - #ER_BUS_NO_AUTHENTICATION_MECHANISM if alljoyn_busattachment_enablepeersecurity() has not been called.
 *          - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_secureconnectionasync(alljoyn_busattachment bus, const char* name, QCC_BOOL forceAuth);

/**
 * Remove a member from an existing multipoint session.
 * This function may be called by the binder of the session to forcefully remove a member from a session.
 *
 * This method is a shortcut/helper that issues an org.alljoyn.Bus.RemoveSessionMember method call to the local router
 * and interprets the response.
 *
 * @param[in]  bus           The bus which the member is being removed from
 * @param[in]  sessionId     Session id.
 * @param[in]  memberName    Member to remove.
 *
 * @return
 *      - #ER_OK iff router response was received and the remove member operation was successfully completed.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_removesessionmember(alljoyn_busattachment bus, alljoyn_sessionid sessionId, const char* memberName);

/**
 * Set the link timeout for a session.
 *
 * Link timeout is the maximum number of seconds that an unresponsive router-to-router connection
 * will be monitored before declaring the session lost (via SessionLost callback). Link timeout
 * defaults to 0 which indicates that AllJoyn link monitoring is disabled.
 *
 * Each transport type defines a lower bound on link timeout to avoid defeating transport
 * specific power management algorithms.
 *
 * @param bus           The bus containing the link to modify.
 * @param sessionid     Id of session whose link timeout will be modified.
 * @param linkTimeout   [IN/OUT] Max number of seconds that a link can be unresponsive before being
 *                      declared lost. 0 indicates that AllJoyn link monitoring will be disabled. On
 *                      return, this value will be the resulting (possibly upward) adjusted linkTimeout
 *                      value that acceptable to the underlying transport.
 *
 * @return
 *      - #ER_OK if successful
 *      - #ER_ALLJOYN_SETLINKTIMEOUT_REPLY_NOT_SUPPORTED if local router does not support SetLinkTimeout
 *      - #ER_ALLJOYN_SETLINKTIMEOUT_REPLY_NO_DEST_SUPPORT if SetLinkTimeout not supported by destination
 *      - #ER_BUS_NO_SESSION if the Session id is not valid
 *      - #ER_ALLJOYN_SETLINKTIMEOUT_REPLY_FAILED if SetLinkTimeout failed
 *      - #ER_BUS_NOT_CONNECTED if the alljoyn_busattachment is not connected to the router
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_setlinktimeout(alljoyn_busattachment bus, alljoyn_sessionid sessionid, uint32_t* linkTimeout);

/**
 * Set the link timeout for a session.
 *
 * Link timeout is the maximum number of seconds that an unresponsive
 * router-to-router connection will be monitored before declaring the session
 * lost (via SessionLost callback). Link timeout defaults to 0 which indicates
 * that AllJoyn link monitoring is disabled.
 *
 * Each transport type defines a lower bound on link timeout to avoid defeating
 * transport specific power management algorithms.
 *
 * This call executes asynchronously. When the alljoyn_busattachment_setlinktimeoutasync
 * response is received, the callback will be called.
 *
 * @param[in] bus           The bus containing the link to modify.
 * @param[in] sessionid     Id of session whose link timeout will be modified.
 * @param[in] linkTimeout   Max number of seconds that a link can be unresponsive before being
 *                          declared lost. 0 indicates that AllJoyn link monitoring will be disabled. On
 *                          return, this value will be the resulting (possibly upward) adjusted linkTimeout
 *                          value that acceptable to the underlying transport.
 * @param[in]  callback     alljoyn_busattachment_setlinktimeoutcb_ptr function
 *                          Called when alljoyn_busattachment_setlinktimeoutasync
 *                          response is received.
 * @param[in]  context      User defined context which will be passed as-is to callback.
 *
 * @return
 *      - #ER_OK iff method call to local router response was was successful.
 *      - #ER_BUS_NOT_CONNECTED if a connection has not been made with a local bus.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_setlinktimeoutasync(alljoyn_busattachment bus, alljoyn_sessionid sessionid,
                                                                        uint32_t linkTimeout, alljoyn_busattachment_setlinktimeoutcb_ptr callback,
                                                                        void* context);
/**
 * Determine whether a given well-known name exists on the bus.
 * This method is a shortcut/helper that issues an org.freedesktop.DBus.NameHasOwner method call to the router
 * and interprets the response.
 *
 * @param[in]  bus        The bus to query.
 * @param[in]  name       The well known name that the caller is inquiring about.
 * @param[out] hasOwner   If return is ER_OK, indicates whether name exists on the bus.
 *                        If return is not ER_OK, param is not modified.
 * @return
 *      - #ER_OK if name ownership was able to be determined.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_namehasowner(alljoyn_busattachment bus, const char* name, QCC_BOOL* hasOwner);

/**
 * Get the peer GUID for this peer of the local peer or an authenticated remote peer. The bus
 * names of a remote peer can change over time, specifically the unique name is different each
 * time the peer connects to the bus and a peer may use different well-known-names at different
 * times. The peer GUID is the only persistent identity for a peer. Peer GUIDs are used by the
 * authentication mechanisms to uniquely and identify a remote application instance. The peer
 * GUID for a remote peer is only available if the remote peer has been authenticated.
 *
 * @param bus    The bus on which to get the peer GUID.
 * @param name   Name of a remote peer or NULL to get the local (this application's) peer GUID.
 * @param guid   Returns the guid for the local or remote peer depending on the value of name, or NULL to get size.
 * @param guidSz Size of the provided guid buffer, upon exit size of guid string.
 *
 * @return
 *      - #ER_OK if the requested GUID was obtained.
 *      - An error status otherwise.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_getpeerguid(alljoyn_busattachment bus, const char* name, char* guid, size_t* guidSz);

/**
 * This sets the debug level of the local AllJoyn router if that router
 * was built in debug mode.
 *
 * The debug level can be set for individual subsystems or for "ALL"
 * subsystems.  Common subsystems are "ALLJOYN" for core AllJoyn code,
 * "ALLJOYN_OBJ" for the sessions management code and "ALLJOYN_NS"
 * for the TCP name services.  Debug levels for specific subsystems
 * override the setting for "ALL" subsystems.  For example if "ALL" is
 * set to 7, but "ALLJOYN_OBJ" is set to 1, then detailed debug output
 * will be generated for all subsystems expcept for "ALLJOYN_OBJ"
 * which will only generate high level debug output.  "ALL" defaults
 * to 0 which is off, or no debug output.
 *
 * The debug output levels are actually a bit field that controls what
 * output is generated.  Those bit fields are described below:
 *
 *     - 0x1: High level debug prints (these debug printfs are not common)
 *     - 0x2: Normal debug prints (these debug printfs are common)
 *     - 0x4: Function call tracing (these debug printfs are used
 *            sporadically)
 *     - 0x8: Data dump (really only used in the "SOCKET" module - can
 *            generate a *lot* of output)
 *
 * Typically, when enabling debug for a subsystem, the level would be set
 * to 7 which enables High level debug, normal debug, and function call
 * tracing.  Setting the level 0, forces debug output to be off for the
 * specified subsystem.
 *
 * @param bus       bus on which to set debugging.
 * @param module    name of the module to generate debug output
 * @param level     debug level to set for the module
 *
 * @return
 *     - #ER_OK if debug request was successfully sent to the AllJoyn
 *       router.
 *     - #ER_BUS_NO_SUCH_OBJECT if router was not built in debug mode.
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_setdaemondebug(alljoyn_busattachment bus, const char* module, uint32_t level);

/**
 * Returns the current non-absolute real-time clock used internally by AllJoyn. This value can be
 * compared with the timestamps on messages to calculate the time since a timestamped message
 * was sent.
 *
 * @return  The current timestamp in milliseconds.
 */
extern AJ_API uint32_t AJ_CALL alljoyn_busattachment_gettimestamp();

/**
 * Determine if you are able to find a remote connection based on its BusName.
 * The BusName can be the Unique or well-known name.
 *
 * @param bus     alljoyn_busattachment
 * @param name    The unique or well-known name to ping
 * @param timeout Timeout specified in milliseconds to wait for reply
 * @return
 *   - #ER_OK the name is present and responding
 *   - #ER_ALLJOYN_PING_REPLY_UNREACHABLE the name is no longer present
 *   <br>
 *   The following return values indicate that the router cannot determine if the
 *   remote name is present and responding:
 *   - #ER_ALLJOYN_PING_REPLY_TIMEOUT Ping call timed out
 *   - #ER_ALLJOYN_PING_REPLY_UNKNOWN_NAME name not found currently or not part of any known session
 *   - #ER_ALLJOYN_PING_REPLY_INCOMPATIBLE_REMOTE_ROUTING_NODE the remote routing node does not implement Ping
 *   <br>
 *   The following return values indicate an error with the ping call itself:
 *   - #ER_ALLJOYN_PING_FAILED Ping failed
 *   - #ER_BUS_UNEXPECTED_DISPOSITION An unexpected disposition was returned and has been treated as an error
 *   - #ER_BUS_NOT_CONNECTED the BusAttachment is not connected to the bus
 *   - #ER_BUS_BAD_BUS_NAME the name parameter is not a valid bus name
 *   - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_ping(alljoyn_busattachment bus, const char* name, uint32_t timeout);

/**
 * Registers a handler to receive the org.alljoyn.about Announce signal.
 *
 * The handler is only called if a call to alljoyn_busattachment_whoimplements_*
 * has been has been called.
 *
 * Important: the alljoyn_aboutlistener should be registered before calling
 * alljoyn_busattachment_whoimplments_*
 *
 * @param[in] bus           alljoyn_busattachment this call is made for
 * @param[in] aboutListener alljoyn_aboutlistener to be registered
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_registeraboutlistener(alljoyn_busattachment bus,
                                                                       alljoyn_aboutlistener aboutListener);

/**
 * Unregisters the AnnounceHandler from receiving the org.alljoyn.about Announce signal.
 *
 * @param[in] bus           alljoyn_busattachment this call is made for
 * @param[in] aboutListener alljoyn_aboutlistener to be unregistered
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_unregisteraboutlistener(alljoyn_busattachment bus,
                                                                         alljoyn_aboutlistener aboutListener);

/**
 * Unregisters all AboutListeners from receiving any org.alljoyn.about Announce signal
 *
 * @param[in] bus alljoyn_busattachment this call is made for
 */
extern AJ_API void AJ_CALL alljoyn_busattachment_unregisterallaboutlisteners(alljoyn_busattachment bus);

/**
 * List the interfaces the application is interested in.  If a remote device
 * is announcing that interface then all registered listeners for About
 * will be called.
 *
 * It's the About listener's responsibility to parse through the reported
 * interfaces to figure out what should be done in response to the Announce
 * signal.
 *
 * This call is ref counted. If this function is called with the same
 * list of interfaces multiple times then alljoyn_busattachment_cancelwhoimplements_interfaces
 * must also be called multiple times with the same list of interfaces.
 *
 * Note: specifying NULL for the implementsInterfaces parameter could have
 * significant impact on network performance and should be avoided unless
 * all announcements are needed.
 *
 * @param[in] bus                  alljoyn_busattachment this call is made for
 * @param[in] implementsInterfaces a list of interfaces that the Announce signal
 *                                 reports as implemented. NULL to receive all
 *                                 Announce signals regardless of interfaces
 * @param[in] numberInterfaces     the number of interfaces in the
 *                                 implementsInterfaces list
 * @return status
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_whoimplements_interfaces(alljoyn_busattachment bus,
                                                                             const char** implementsInterfaces,
                                                                             size_t numberInterfaces);

/**
 * List an interface the application is interested in.  If a remote device
 * is announcing that interface then all registered listeners for the
 * Announce signal will be called.
 *
 * This is identical to alljoyn_busattachment_whoimplements_interfaces
 * except this is specialized for a single interface not several interfaces.
 *
 * Note: specifying NULL for the interface parameter could have significant
 * impact on network performance and should be avoided unless all
 * announcements are needed.
 *
 * @see alljoyn_busattachment_whoimplements_interfaces(const char**, size_t)
 * @param[in] bus                 alljoyn_busattachment this call is made for
 * @param[in] implementsInterface interface that must be implemented in order
 *                                to receive the announce signal.
 * @return
 *    - #ER_OK on success
 *    - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_whoimplements_interface(alljoyn_busattachment bus,
                                                                            const char* implementsInterface);

/**
 * Stop showing interest in the listed interfaces. Stop receiving announce
 * signals from the devices with the listed interfaces.
 *
 * Note if alljoyn_busattachment_whoimplements_interfaces has been called multiple
 * times the announce signal will still be received for any interfaces that still remain.
 *
 * @param[in] bus                  alljoyn_busattachment this call is made for
 * @param[in] implementsInterfaces a list of interfaces. The list must match the
 *                                 list previously passed to the WhoImplements
 *                                 member function
 * @param[in] numberInterfaces     the number of interfaces in the
 *                                 implementsInterfaces list
 * @return
 *    - #ER_OK on success
 *    - #ER_BUS_MATCH_RULE_NOT_FOUND if interfaces added using the WhoImplements
 *                                   member function were not found.
 *    - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_cancelwhoimplements_interfaces(alljoyn_busattachment bus,
                                                                                   const char** implementsInterfaces,
                                                                                   size_t numberInterfaces);

/**
 * Stop showing interest in the listed interfaces. Stop receiving announce
 * signals from the devices with the listed interfaces.
 *
 * This is identical to alljoyn_busattachment_cancelwhoimplements_interfaces
 * except this is specialized for a single interface not several interfaces.
 *
 * @see alljoyn_busattachment_cancelwhoimplements(const char**, size_t)
 * @param[in] bus                 alljoyn_busattachment this call is made for
 * @param[in] implementsInterface interface that must be implement in order to
 *                                receive the announce signal.
 *
 * @return
 *    - #ER_OK on success
 *    - #ER_BUS_MATCH_RULE_NOT_FOUND if interface added using the WhoImplements
 *                                   member function were not found.
 *    - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_cancelwhoimplements_interface(alljoyn_busattachment bus,
                                                                                  const char* implementsInterface);

/**
 * Retrieves the alljoyn_permissionconfigurator associated with this alljoyn_busattachment.
 *
 * @param[in] bus The alljoyn_busattachment containing the alljoyn_permissionconfigurator.
 *
 * @return
 *      - The alljoyn_permissionconfigurator
 */
extern AJ_API const alljoyn_permissionconfigurator AJ_CALL alljoyn_busattachment_getpermissionconfigurator(alljoyn_busattachment bus);

/**
 * Registers a handler to receive the org.alljoyn.Bus.Application State signal.
 *
 * @param[in] bus       The alljoyn_busattachment which registers the alljoyn_applicationstatelistener.
 * @param[in] listener  Listener instance that will receive state event notifications.
 *
 * @return
 *    - #ER_OK on success
 *    - #ER_APPLICATION_STATE_LISTENER_ALREADY_EXISTS when the same listener has already been registered.
 *    - Different error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_registerapplicationstatelistener(alljoyn_busattachment bus,
                                                                                     alljoyn_applicationstatelistener listener);

/**
 * Unregisters the listener that was registered with alljoyn_busattachment_registerapplicationstatelistener
 *
 * @param[in] bus       The alljoyn_busattachment from which to detach the alljoyn_applicationstatelistener.
 * @param[in] listener  Object instance to unregister as a listener.
 *
 * @return
 *    - #ER_OK on success
 *    - #ER_APPLICATION_STATE_LISTENER_NO_SUCH_LISTENER when this listener has not been registered.
 *    - Different error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_unregisterapplicationstatelistener(alljoyn_busattachment bus,
                                                                                       alljoyn_applicationstatelistener listener);

/*
 * Deletes the key store of the specified application.
 *
 * @note To avoid errors, app should only call this function after all instances of alljoyn_busattachment are destroyed.
 *
 * @param[in] application the application name used when constructing a BusAttachment.
 *
 * @return
 *      - #ER_OK if the key store was not present, or if it has been deleted successfully.
 *      - #ER_OS_ERROR if the OS fails to delete the key store.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_busattachment_deletedefaultkeystore(const char* applicationName);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
