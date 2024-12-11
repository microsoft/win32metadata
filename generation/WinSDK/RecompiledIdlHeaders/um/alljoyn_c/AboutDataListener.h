/*
 * @file
 * alljoyn_aboutdatalistener provides a Listener implemented by AllJoyn apps and called
 * by AllJoyn. The Listener is responsible for providing a well formed alljoyn_msgarg
 * dictionary of type a{sv} that contain the fields specified in the About interface.
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

#ifndef _ALLJOYN_ABOUTDATALISTENER_C_H
#define _ALLJOYN_ABOUTDATALISTENER_C_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/MsgArg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _alljoyn_aboutdatalistener_handle* alljoyn_aboutdatalistener;

/**
 * Type for the GetAboutData callback.
 *
 * This callback is invoked to create the alljoyn_msgarg that is returned when
 * a user calls org.alljoyn.About.GetAboutData. The returned alljoyn_msgarg contains
 * the AboutData dictionary for the specified language.
 *
 * The alljoyn_msgarg must contain the signature `a{sv}`.
 *
 * Custom fields are allowed. Since the proxy object only receives the field
 * name and the alljoyn_msgarg containing the contents of that for that field
 * the default assumption is that user defined fields are:
 * - not required
 * - not announced
 * - localized if the alljoyn_msgarg contains a String (not localized otherwise)
 *
 * Important: All implementations of GetAboutData should handle language
 * specified as an empty string or NULL. In the case that the language is
 * not specified the GetAboutData is expected to return the default language.
 *
 * If the language tag given is not supported return the QStatus
 * #ER_LANGUAGE_NOT_SUPPORTED. If the user has not provided ALL of the
 * required fields return the QStatus #ER_ABOUT_ABOUTDATA_MISSING_REQUIRED_FIELD
 *
 * @param[in]  context  the context pointer that was passed into the
 *                      alljoyn_aboutdatalistener_create function
 * @param[out] msgArg   dictionary containing all of the AboutData fields for
 *                      the specified language.  If language is not specified the default
 *                      language will be returned
 * @param[in] language  IETF language tags specified by RFC 5646 if the string
 *                      is NULL or an empty string the MsgArg for the default
 *                      language will be returned
 *
 * @return
 *  - #ER_OK on successful
 *  - #ER_LANGUAGE_NOT_SUPPORTED if language is not supported
 *  - #ER_ABOUT_ABOUTDATA_MISSING_REQUIRED_FIELD if a required field is missing
 *  - other error indicating failure
 */
typedef QStatus (AJ_CALL * alljoyn_aboutdatalistener_getaboutdata_ptr)(const void* context,
                                                                       alljoyn_msgarg msgArg,
                                                                       const char* language);

/**
 * Type for the GetAnnouncedAboutData callback.
 *
 * This callback is invoked to return an alljoyn_msgarg object containing
 * a dictionary with the Announce portion of the AboutData.
 *
 * The Announced values must use the default language and must only contain
 * the fields that are announced.
 *
 * The fields required to be part of the announced alljoyn_msgarg are:
 *  - AppId
 *  - DefaultLanguage
 *  - DeviceName (Optional since v14.12)
 *  - DeviceId
 *  - AppName
 *  - Manufacture
 *  - ModelNumber
 *
 * To read other fields or get the localized value of a field use the
 * org.alljoyn.About.GetAboutData method. This method is available using the
 * AboutProxy class.
 *
 * @param[in]  context  the context pointer that was passed into the
 *                      alljoyn_aboutdatalistener_create function
 * @param[out] msgArg   an alljoyn_msgarg dictionary with the a{sv} that contains
 *                      the Announce data
 * @return ER_OK if successful
 */
typedef QStatus (AJ_CALL * alljoyn_aboutdatalistener_getannouncedaboutdata_ptr)(const void* context,
                                                                                alljoyn_msgarg msgArg);

/**
 * Struct containing callbacks used for creation of an alljoyn_aboutdatalistener.
 */
typedef struct {
    /**
     * Handler to get the complete alljoyn_aboutdata for a given language
     */
    alljoyn_aboutdatalistener_getaboutdata_ptr about_datalistener_getaboutdata;
    /**
     * Handler to get the announced alljoyn_aboutdata for the default language
     */
    alljoyn_aboutdatalistener_getannouncedaboutdata_ptr about_datalistener_getannouncedaboutdata;
} alljoyn_aboutdatalistener_callbacks;


/**
 * Create a new alljoyn_aboutdatalistener object.
 * This object will invoke the provided callbacks passing in the provided context.
 * @return The allocated alljoyn_aboutdatalistener.
 */
extern AJ_API alljoyn_aboutdatalistener AJ_CALL alljoyn_aboutdatalistener_create(const alljoyn_aboutdatalistener_callbacks* callbacks,
                                                                                 const void* context);

/**
 * Free an alljoyn_aboutdatalistener object.
 *
 * @param listener The alljoyn_aboutdatalistener to be freed.
 */
extern AJ_API void AJ_CALL alljoyn_aboutdatalistener_destroy(alljoyn_aboutdatalistener listener);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _ALLJOYN_ABOUTDATALISTENER_C_H */
