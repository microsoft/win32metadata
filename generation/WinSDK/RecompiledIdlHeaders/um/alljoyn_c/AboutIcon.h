/**
 * @file
 * alljoyn_abouticon is a container that holds information about an About icon.
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
#ifndef _ALLJOYN_ABOUTICON_C_H
#define _ALLJOYN_ABOUTICON_C_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/MsgArg.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * container to hold information about the Icon
 */
typedef struct _alljoyn_abouticon_handle* alljoyn_abouticon;

/**
 * Allocate a new empty alljoyn_abouticon object.
 * @return The allocated alljoyn_abouticon.
 */
extern AJ_API alljoyn_abouticon AJ_CALL alljoyn_abouticon_create();

/**
 * Free an alljoyn_abouticon object.
 *
 * @param icon the alljoyn_abouticon to be freed.
 */
extern AJ_API void AJ_CALL alljoyn_abouticon_destroy(alljoyn_abouticon icon);

/**
 * Returns a pointer to the icon's internal content data as well as the size of this data.
 *
 * @param[in]   icon  the alljoyn_abouticon object this call is made for
 * @param[out]  data  pointer to the icon content data
 * @param[out]  size  size (in number of bytes) of the icon content data
 */
extern AJ_API void AJ_CALL alljoyn_abouticon_getcontent(alljoyn_abouticon icon,
                                                        const uint8_t** data,
                                                        size_t* size);

/**
 * Set the content for an icon.  The content must fit into a alljoyn_msgarg so the
 * largest size for the icon data is ALLJOYN_MAX_ARRAY_LEN bytes.
 *
 * Note as long as the Media Type matches it is possible to set both icon content
 * and icon URL
 *
 * If an error is returned the icon content will remain unchanged.
 *
 * @param[in] icon     the alljoyn_abouticon object this call is made for
 * @param[in] type     a Media Type indicating the icon image type. Typical
 *                     value will be `image/jpeg` or `image/png`
 * @param[in] data     pointer to an array of bytes that represent an icon
 * @param[in] csize    the number of bytes in data
 * @param[in] ownsData if true the alljoyn_abouticon contain gains ownership of the
 *                     data that data points to.  The alljoyn_abouticon object will
 *                     be responsible for freeing the memory. If false user is
 *                     is responsible for freeing memory pointed to by data.
 * @return
 *  - ER_OK on success
 *  - ER_BUS_BAD_VALUE if the data is to large to be marshaled
 *  - other status indicating failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_abouticon_setcontent(alljoyn_abouticon icon,
                                                           const char* type,
                                                           uint8_t* data,
                                                           size_t csize,
                                                           bool ownsData);

/**
 * Gets the URL that contains the icon for the application.
 *
 * @param[in]  icon  the alljoyn_abouticon object this call is made for
 * @param[out] type  the Media Type indicating the icon image type
 * @param[out] url   the URL that contains the location of the icon
 */
extern AJ_API void AJ_CALL alljoyn_abouticon_geturl(alljoyn_abouticon icon,
                                                    const char** type,
                                                    const char** url);

/**
 * Set a url that contain the icon for the application.
 *
 * Note as long as the Media Type matches it is possible to set both icon content
 * and icon URL
 *
 * @param[in] icon     the alljoyn_abouticon object this call is made for
 * @param[in] type     a Media Type indicating the icon image type. Typical
 *                     value will be `image/jpeg` or `image/png`
 * @param[in] url      a URL that contain the location of the icon hosted in
 *                     the cloud.
 * @return
 *  - #ER_OK on success
 *  - other status indicating failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_abouticon_seturl(alljoyn_abouticon icon,
                                                       const char* type,
                                                       const char* url);

/**
 * Clear the alljoyn_abouticon. This will change all strings to empty strings
 * set the content to NULL and the contentSize to zero.
 *
 * @param[in] icon  the alljoyn_abouticon object this call is made for
 */
extern AJ_API void AJ_CALL alljoyn_abouticon_clear(alljoyn_abouticon icon);

/**
 * Add the IconContent from an alljoyn_msgarg. This will make a local copy of the
 * alljoyn_msgarg passed in and expose the contents as the member variables content
 * and contentSize.
 *
 * @param[in] icon  the alljoyn_abouticon object this call is made for
 * @param[in] arg   the alljoyn_msgarg containing the Icon
 *
 * @return
 *   - ER_OK on success
 *   - status indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_abouticon_setcontent_frommsgarg(alljoyn_abouticon icon,
                                                                      const alljoyn_msgarg arg);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //_ALLJOYN_ABOUTICON_C_H
