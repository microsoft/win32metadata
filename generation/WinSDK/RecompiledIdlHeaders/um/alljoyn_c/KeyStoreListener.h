/**
 * @file
 * The alljoyn_keystorelistener handles requests to load or store the key store.
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
#ifndef _ALLJOYN_C_KEYSTORE_LISTENER_H
#define _ALLJOYN_C_KEYSTORE_LISTENER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The alljoyn_keystore manages storing and loading of key blobs from
 * external storage.
 */
typedef struct _alljoyn_keystore_handle*                    alljoyn_keystore;

/**
 * An application can provide a key store listener to override the default key store
 * load request and store request behavior.  If an alljoyn_keystorelistener is provided it will
 * override the default key store behavior.
 */
typedef struct _alljoyn_keystorelistener_handle*            alljoyn_keystorelistener;

/**
 * Type for the LoadRequest callback.
 *
 * This function is called when a key store needs to be loaded.
 * @remark The application must call <tt>#alljoyn_keystorelistener_putkeys</tt> to put the new key store data into the
 * internal key store.
 *
 * @param context    The context pointer passed into the alljoyn_keystorelistener_create function.
 * @param listener   The listener that is responsible for the LoadRequest callback.
 *                   This listener should be used when calling the @c alljoyn_keystorelistener_putkeys
 *                   function.
 * @param keyStore   Reference to the alljoyn_keystore to be loaded.
 *
 * @return
 *      - #ER_OK if the load request was satisfied
 *      - An error status otherwise
 *
 */
typedef QStatus (AJ_CALL * alljoyn_keystorelistener_loadrequest_ptr)(const void* context, alljoyn_keystorelistener listener, alljoyn_keystore keyStore);

/**
 * Type for the StoreRequest callback.
 *
 * This function is called when a key store needs to be stored.
 * @remark The application must call <tt>#alljoyn_keystorelistener_getkeys</tt> to obtain the key data to be stored.
 *
 * @param context    The context pointer passed into the alljoyn_keystorelistener_create function.
 * @param listener   The listener that is responsible for the StoreRequest callback.
 *                   This listener should be used when calling the @c alljoyn_keystorelistener_getkeys
 *                   function.
 * @param keyStore   Reference to the @c alljoyn_keystore to be stored.
 *
 * @return
 *      - #ER_OK if the store request was satisfied
 *      - An error status otherwise
 */
typedef QStatus (AJ_CALL * alljoyn_keystorelistener_storerequest_ptr)(const void* context, alljoyn_keystorelistener listener, alljoyn_keystore keyStore);

/**
 * Type for the AcquireExclusiveLock callback.
 *
 * This function is called when a key store acquires an exclusive lock (e.g., file lock).
 *
 * @param context    The context pointer passed into the alljoyn_keystorelistener_with_synchronization_create function.
 * @param listener   The listener that is responsible for the AcquireExclusiveLock callback.
 *
 * @return
 *      - #ER_OK if the store request was satisfied
 *      - An error status otherwise
 */
typedef QStatus (AJ_CALL * alljoyn_keystorelistener_acquireexclusivelock_ptr)(const void* context, alljoyn_keystorelistener listener);

/**
 * Type for the ReleaseExclusiveLock callback.
 *
 * This function is called when a key store releases an exclusive lock (e.g., file lock).
 *
 * @param context    The context pointer passed into the alljoyn_keystorelistener_with_synchronization_create function.
 * @param listener   The listener that is responsible for the ReleaseExclusiveLock callback.
 */
typedef void (AJ_CALL * alljoyn_keystorelistener_releaseexclusivelock_ptr)(const void* context, alljoyn_keystorelistener listener);

/**
 * Structure used during alljoyn_keystorelistener_create to provide callbacks into C.
 * An implementation must provide both
 *     alljoyn_keystorelistener_loadrequest_ptr
 *     alljoyn_keystorelistener_storerequest_ptr
 */
typedef struct {
    /**
     * This function is called when a key store needs to be loaded.
     */
    alljoyn_keystorelistener_loadrequest_ptr load_request;
    /**
     * This function is called when a key store needs to be stored.
     */
    alljoyn_keystorelistener_storerequest_ptr store_request;
} alljoyn_keystorelistener_callbacks;

/**
 * Structure used during alljoyn_keystorelistener_with_synchronization_create to provide callbacks into C.
 * An implementation must provide all
 *     alljoyn_keystorelistener_loadrequest_ptr
 *     alljoyn_keystorelistener_storerequest_ptr
 *     alljoyn_keystorelistener_acquireexclusivelock_ptr
 *     alljoyn_keystorelistener_releaseexclusivelock_ptr
 */
typedef struct {
    /**
     * This function is called when a key store needs to be loaded.
     */
    alljoyn_keystorelistener_loadrequest_ptr load_request;
    /**
     * This function is called when a key store needs to be stored.
     */
    alljoyn_keystorelistener_storerequest_ptr store_request;
    /**
     * This function is called when a key store acquires an exclusive lock.
     */
    alljoyn_keystorelistener_acquireexclusivelock_ptr acquire_exclusive_lock;
    /**
     * This function is called when a key store releases an exclusive lock.
     */
    alljoyn_keystorelistener_releaseexclusivelock_ptr release_exclusive_lock;
} alljoyn_keystorelistener_with_synchronization_callbacks;

/**
 * Create an alljoyn_keystorelistener
 *
 * @param callbacks  Callbacks to trigger for associated events.
 * @param context    Context to pass along to callback functions.
 *
 * @return an allocated alljoyn_keystorelistener
 */
extern AJ_API alljoyn_keystorelistener AJ_CALL alljoyn_keystorelistener_create(const alljoyn_keystorelistener_callbacks* callbacks,
                                                                               const void* context);

/**
 * Create an alljoyn_keystorelistener with synchronization callbacks
 *
 * @param callbacks  Callbacks to trigger for associated events.
 * @param context    Context to pass along to callback functions.
 *
 * @return an allocated alljoyn_keystorelistener
 */
extern AJ_API alljoyn_keystorelistener AJ_CALL alljoyn_keystorelistener_with_synchronization_create(const alljoyn_keystorelistener_with_synchronization_callbacks* callbacks,
                                                                                                    void* context);
/**
 * Destroy an alljoyn_keystorelistener
 *
 * @param listener The alljoyn_keystorelistener to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_keystorelistener_destroy(alljoyn_keystorelistener listener);

/**
 * Put keys into the key store from an encrypted byte string.
 *
 * @param listener  The alljoyn_keystorelistener into which to put the keys.
 * @param keyStore  The keyStore to put to. This is the keystore indicated in the LoadRequest call.
 * @param source    The byte string containing the encrypted key store contents.
 * @param password  The password required to decrypt the key data
 *
 * @return
 *      - #ER_OK if successful
 *      - An error status otherwise
 *
 */
extern AJ_API QStatus AJ_CALL alljoyn_keystorelistener_putkeys(alljoyn_keystorelistener listener, alljoyn_keystore keyStore,
                                                               const char* source, const char* password);

/**
 * Get the current keys from the key store as an encrypted byte string.
 *
 * @code
 * QStatus status;
 * char* sink;
 * size_t sink_sz;
 * alljoyn_keystorelistener_getkeys(listener, keyStore, NULL, &sink_sz);
 * sink = (char*) malloc(sizeof(char) * sink_sz);
 * status = alljoyn_keystorelistener_getkeys(listener, keyStore, sink, &sink_sz);
 * QCC_ASSERT(status == ER_OK);
 * @endcode
 *
 * @param listener  The alljoyn_keystorelistener from which to get the keys.
 * @param keyStore  The keyStore to get from. This is the keystore indicated in
 *                  the StoreRequest call.
 * @param sink      The byte string to write the keys to. If sink is NULL then the
 *                  sink_sz parameter will return the size of the sink plus the
 *                  terminating nul character.
 * @param[in,out] sink_sz   The size of the byte string provided. This will return
 *                          the actual size of the sink plus the terminating nul
 *                          character. If the sink_sz out should be larger than or
 *                          equal to the sink_sz in.
 * @return
 *      - #ER_OK if successful
 *      - #ER_BUFFER_TOO_SMALL if the specified sink_sz is is not large enough
 *        to hold the sink
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_keystorelistener_getkeys(alljoyn_keystorelistener listener, alljoyn_keystore keyStore,
                                                               char* sink, size_t* sink_sz);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
