/**
 * @file
 *
 * AutoPinger
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
#ifndef _ALLJOYN_AUTOPINGER_C_H
#define _ALLJOYN_AUTOPINGER_C_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/BusAttachment.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* The pinglistener part */

/**
 * Data structure to hold a reference to a pinglistener
 */
typedef struct _alljoyn_pinglistener_handle* alljoyn_pinglistener;

/**
 * Destination Lost: called when the destination becomes unreachable.
 * Called once.
 *
 * @param context     The context pointer that was passed into the
 *                    alljoyn_pinglistener_create function.
 * @param group       The pinging group name.
 * @param destination The unique name of the destination that was pinged.
 */
typedef void (AJ_CALL * alljoyn_autopinger_destination_lost_ptr)(const void* context,
                                                                 const char* group,
                                                                 const char* destination);
/**
 * Destination Found: called when the destination becomes reachable.
 * Called once.
 *
 * @param context     The context pointer that was passed into the
 *                    alljoyn_pinglistener_create function.
 * @param group       The pinging group name.
 * @param destination The unique name of the destination that was pinged.
 */
typedef void (AJ_CALL * alljoyn_autopinger_destination_found_ptr)(const void* context,
                                                                  const char* group,
                                                                  const char* destination);
/**
 * The callbacks used for the creation of an alljoyn_pinglistener.
 */
typedef struct {
    /**
     * A new destination was found.
     */
    alljoyn_autopinger_destination_found_ptr destination_found;
    /**
     * A previously known destination was lost.
     */
    alljoyn_autopinger_destination_lost_ptr destination_lost;
} alljoyn_pinglistener_callback;

/**
 * Allocate a new alljoyn_pinglistener.
 *
 * @param callback The callbacks used by the created listener to notify
 *                 about the (dis)appearance of destinations.
 *
 * The pinglistener returned by this function is owned by the caller and should
 * be deleted using alljoyn_pinglistener_destroy once the ping group(s) that it was
 * used with is/are removed.
 */
extern AJ_API alljoyn_pinglistener AJ_CALL alljoyn_pinglistener_create(const alljoyn_pinglistener_callback* callback,
                                                                       const void* context);
/**
 * Free an alljoyn_pinglistener.
 *
 * @param listener The pinglistener that was previously created by
 *                 alljoyn_pinglistener_create that needs to be deleted.
 */
extern AJ_API void AJ_CALL alljoyn_pinglistener_destroy(alljoyn_pinglistener listener);

/* The autopinger part */

/**
 * An autopinger monitors groups of destinations and notifies the application about
 * their (dis)appearances.
 */
typedef struct _alljoyn_autopinger_handle* alljoyn_autopinger;

/**
 * Create an instance of autopinger
 *
 * @param busAttachment Reference to the bus attachment associated with this
 *                      autopinger.
 *
 */
extern AJ_API alljoyn_autopinger AJ_CALL alljoyn_autopinger_create(alljoyn_busattachment bus);

/**
 * Destructor.
 *
 * @param autopinger   Reference to the autopinger to be destroyed.
 *
 * Do not destroy an autopinger instance from within a pinglistener
 * callback. This will cause a deadlock.
 */
extern AJ_API void AJ_CALL alljoyn_autopinger_destroy(alljoyn_autopinger autopinger);

/**
 * Pause all ping actions.
 *
 * @param autopinger   Reference to the autopinger.
 *
 */
extern AJ_API void AJ_CALL alljoyn_autopinger_pause(alljoyn_autopinger autopinger);

/**
 * Resume ping actions.
 *
 * @param autopinger   Reference to the autopinger.
 *
 */
extern AJ_API void AJ_CALL alljoyn_autopinger_resume(alljoyn_autopinger autopinger);

/**
 * Define new ping group.
 *
 * @param autopinger   Reference to the autopinger.
 * @param group        Ping group name.
 * @param listener     Listener called when a change was detected in the reachability of a
 *                     destination.
 * @param pingInterval Ping interval in seconds.
 */
extern AJ_API void AJ_CALL alljoyn_autopinger_addpinggroup(alljoyn_autopinger autopinger,
                                                           const char* group,
                                                           alljoyn_pinglistener listener,
                                                           uint32_t pinginterval = 5);

/**
 * Remove complete ping group, including all destinations.
 *
 * Do not invoke this method from within a pinglistener callback. This will
 * cause a deadlock.
 *
 * @param autopinger   Reference to the autopinger.
 * @param group        Ping group name.
 */
extern AJ_API void AJ_CALL alljoyn_autopinger_removepinggroup(alljoyn_autopinger autopinger,
                                                              const char* group);

/**
 * Set ping interval of the specified group.
 *
 * @param autopinger   Reference to the autopinger.
 * @param group        Ping group name.
 * @param pingInterval Ping interval in seconds.
 * @return
 *  - #ER_OK: interval updated.
 *  - #ER_BUS_PING_GROUP_NOT_FOUND: group did not exist.
 */
extern AJ_API QStatus AJ_CALL alljoyn_autopinger_setpinginterval(alljoyn_autopinger autopinger,
                                                                 const char* group,
                                                                 uint32_t pinginterval);

/**
 * Add a destination to the specified ping group.
 * Destinations are refcounted and must be removed N times if they were added N times.

 * @param autopinger   Reference to the autopinger.
 * @param group        Ping group name.
 * @param destination  Unique name of the destination to be pinged.
 * @return
 *  - #ER_OK: destination added.
 *  - #ER_BUS_PING_GROUP_NOT_FOUND: group did not exist.
 */
extern AJ_API QStatus AJ_CALL alljoyn_autopinger_adddestination(alljoyn_autopinger autopinger,
                                                                const char* group,
                                                                const char* destination);

/**
 * Remove a destination from the specified ping group.
 * This will lower the refcount by one and only remove the destination when the refcount reaches
 * zero.
 *
 * @param autopinger   Reference to the autopinger.
 * @param group        Ping group name.
 * @param destination  Unique name of the destination to be removed.
 * @param removeAll    Rather than decrementing the refcount by one, set refcount to zero and
 *                     remove.
 * @return
 *  - #ER_OK: destination removed or was not present.
 *  - #ER_BUS_PING_GROUP_NOT_FOUND: group did not exist.
 */
extern AJ_API QStatus AJ_CALL alljoyn_autopinger_removedestination(alljoyn_autopinger autopinger,
                                                                   const char* group,
                                                                   const char* destination,
                                                                   QCC_BOOL removeall = false);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //_ALLJOYN_AUTOPINGER_C_H

