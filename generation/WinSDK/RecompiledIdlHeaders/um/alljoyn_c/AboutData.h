/**
 * @file
 * alljoyn_aboutdata is responsible for storing data for the org.alljoyn.About interface.
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
#ifndef _ALLJOYN_ABOUTDATA_C_H
#define _ALLJOYN_ABOUTDATA_C_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/MsgArg.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_aboutdata is responsible for holding the org.alljoyn.about interface
 * Data fields
 */
typedef struct _alljoyn_aboutdata_handle* alljoyn_aboutdata;

/**
 * Allocate a new empty alljoyn_aboutdata object. The default language is not set.
 * Set the language using either one of the following functions:
 * - alljoyn_about_setdefaultlanguage
 * - alljoyn_about_createfrommsgarg
 * - alljoyn_about_createfromxml
 *
 * The default language should be specified before any tag that requires
 * localization. These tags are the following:
 * - DeviceName
 * - AppName
 * - Manufacturer
 * - Description
 *
 * @return The allocated alljoyn_aboutdata.
 */
extern AJ_API alljoyn_aboutdata AJ_CALL alljoyn_aboutdata_create_empty();

/**
 * Allocate a new alljoyn_aboutdata object setting the default language.
 *
 * @param defaultLanguage the default RFC 5646 language tag for the About data fields
 *
 * @return The allocated alljoyn_aboutdata.
 */
extern AJ_API alljoyn_aboutdata AJ_CALL alljoyn_aboutdata_create(const char* defaultLanguage);

/**
 * Allocate a new alljoyn_aboutdata object filling in the fields of the About data
 * using an alljoyn_msgarg. The provided alljoyn_msgarg must contain a dictionary
 * with signature a{sv} with About data fields.
 *
 * If the passed in alljoyn_msgarg is an ill formed About data alljoyn_msgarg
 * this call fails silently. If the alljoyn_msgarg does not come from an About
 * Announce signal it is best to create an empty alljoyn_aboutdata object
 * and use the alljoyn_about_createfrommsgarg function to fill in the About data.
 *
 * @param arg      alljoyn_msgarg with signature a{sv}containing About data fields.
 * @param language the language of the arg alljoyn_msgarg. Use NULL for default language
 *
 * @return The allocated alljoyn_aboutdata.
 */
extern AJ_API alljoyn_aboutdata AJ_CALL alljoyn_aboutdata_create_full(const alljoyn_msgarg arg,
                                                                      const char* language);

/**
 * Free an alljoyn_aboutdata object.
 *
 * @param data The alljoyn_aboutdata to be freed.
 */
extern AJ_API void AJ_CALL alljoyn_aboutdata_destroy(alljoyn_aboutdata data);

/**
 * Initialize the About data held by the specified alljoyn_aboutdata object
 * from a character string containing the XML representation of the About data
 * specified as an \<About data\> element containing \<AppId\>, \<DeviceName\>, etc.
 *
 * The AllJoyn software version (AJSoftwareVersion) is automatically set to
 * the version of Alljoyn that is being used. The SupportedLanguages tag is
 * automatically implied from the DefaultLanguage tag and the lang annotation
 * from tags that are localizable.
 *
 * @param[in] data         alljoyn_aboutdata object this call is made for
 * @param[in] aboutDataXml a string that contains an XML representation of
 *                         the About data fields.
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_createfromxml(alljoyn_aboutdata data,
                                                              const char* aboutDataXml);

/**
 * Validate if the About data has all of the required fields. If a language
 * field is given this will return if all required fields are listed for the
 * given language. If no language is given default language will be checked.
 *
 * @param[in] data     alljoyn_aboutdata object this call is made for
 * @param[in] language IETF language tag specified by RFC 5646
 *
 * @return true if all required field are listed for the given language
 */
extern AJ_API bool AJ_CALL alljoyn_aboutdata_isvalid(alljoyn_aboutdata data,
                                                     const char* language);

/**
 * Fill in the About Data fields from the given alljoyn_msgarg. This alljoyn_msgarg
 * must contain a dictionary of type a{sv} and is expected to be either obtained
 * from an Announce signal or from the GetAboutData method of the org.alljoyn.about
 * interface.
 *
 * @param data     alljoyn_aboutdata object this call is made for
 * @param arg      alljoyn_msgarg contain About data dictionary
 * @param language the language for the alljoyn_msgarg About data
 *                 If NULL the default language is used
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_createfrommsgarg(alljoyn_aboutdata data,
                                                                 const alljoyn_msgarg arg,
                                                                 const char* language);

/**
 * Set the AppId for the About data
 *
 * AppId (the appId argument) must be a 128-bit UUID as specified by RFC 4122
 *
 * AppId IS required
 * AppId IS part of the Announce signal
 * AppId CAN NOT be localized for other languages
 *
 * @param[in] data  alljoyn_aboutdata object this call is made for
 * @param[in] appId the a globally unique array of bytes used as an Id for the application
 * @param[in] num   the number of bytes in the appId array
 *
 * @return
 * - ER_OK on success
 * - #ER_ABOUT_INVALID_ABOUTDATA_FIELD_VALUE if appId is not 128-bits (16 bytes) in size
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setappid(alljoyn_aboutdata data,
                                                         const uint8_t* appId,
                                                         const size_t num);

/**
 * Set the AppId for the About data using a character string.
 *
 * The string must be a ether a 32-character hex digit string
 * (for example "4a354637564945188a48323c158bc02d") or a UUID string as
 * specified in RFC 4122 (for example: "4a354637-5649-4518-8a48-323c158bc02d").
 * The AppId contained by this string must be a 128-bit UUID as specified by RFC 4122.
 *
 * AppId IS required
 * AppId IS part of the Announce signal
 * AppId CAN NOT be localized for other languages
 *
 * @param[in] data  alljoyn_aboutdata object this call is made for
 * @param[in] appId the a globally unique string of characters used as an Id for the application
 *
 * @return
 *  - #ER_OK on success
 *  - #ER_ABOUT_INVALID_ABOUTDATA_FIELD_VALUE if the AppId is not a 128-bits (16 bytes) in size
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setappid_fromstring(alljoyn_aboutdata data,
                                                                    const char* appId);

/**
 * Get the AppId from the About data
 *
 * AppId IS required
 * AppId IS part of the Announce signal
 * AppId CAN NOT be localized for other languages
 *
 * @param[in]  data  alljoyn_aboutdata object this call is made for
 * @param[out] appId a pointer to an array of bytes used as a globally unique ID for an application
 * @param[out] num   the size of the appId array
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getappid(alljoyn_aboutdata data,
                                                         uint8_t** appId,
                                                         size_t* num);

/**
 * The given language is automatically added to the SupportedLanguage list.
 * The language tag should be an IETF language tag specified by RFC 5646.
 *
 * DefaultLanguage is Required
 * DefaultLanguage is part of the Announce signal
 *
 * @param[in] data alljoyn_aboutdata object this call is made for
 * @param[in] defaultLanguage the IETF language tag
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setdefaultlanguage(alljoyn_aboutdata data,
                                                                   const char* defaultLanguage);

/**
 * Get the DefaultLanguage from the About data
 *
 * @param[in]  data            alljoyn_aboutdata object this call is made for
 * @param[out] defaultLanguage a pointer to the default language tag
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getdefaultlanguage(alljoyn_aboutdata data,
                                                                   char** defaultLanguage);
/**
 * Set the DeviceName to the About data
 *
 * DeviceName is not required
 * DeviceName is part of the Announce signal
 * DeviceName can be localized for other languages
 *
 * @param[in] data       alljoyn_aboutdata object this call is made for
 * @param[in] deviceName the deviceName (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in] language   the IETF language tag specified by RFC 5646
 *                       If language is NULL the DeviceName will be set for the default language
 *
 * @return
 *  - #ER_OK on success
 *  - #ER_ABOUT_DEFAULT_LANGUAGE_NOT_SPECIFIED if language tag was not specified
 *                                             and the default language is also
 *                                             not found.
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setdevicename(alljoyn_aboutdata data,
                                                              const char* deviceName,
                                                              const char* language);

/**
 * Get the DeviceName from the About data
 *
 * DeviceName is not required
 * DeviceName is part of the Announce signal
 * DeviceName can be localized for other languages
 *
 * @param[in]  data alljoyn_aboutdata object this call is made for
 * @param[out] deviceName the deviceName found in the About data (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in]  language the IETF language tag specified by RFC 5646
 *             If language is NULL the DeviceName for the default language will be returned
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getdevicename(alljoyn_aboutdata data,
                                                              char** deviceName,
                                                              const char* language);

/**
 * Set the DeviceId from the About data
 *
 * DeviceId IS required
 * DeviceId IS part of the announce signal
 * DeviceId CAN NOT be localized for other languages
 *
 * @param[in] data     alljoyn_aboutdata object this call is made for
 * @param[in] deviceId is a string with a value generated using platform specific means
 *
 * @return ER_OK on success
 */

extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setdeviceid(alljoyn_aboutdata data,
                                                            const char* deviceId);

/**
 * Get the DeviceId from the About data
 *
 * DeviceId IS required
 * DeviceId IS part of the announce signal
 * DeviceId CAN NOT be localized for other languages
 *
 * @param[in]  data     alljoyn_aboutdata object this call is made for
 * @param[out] deviceId UTF-8 string with a value generated using platform specific means
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getdeviceid(alljoyn_aboutdata data,
                                                            char** deviceId);

/**
 * Set the AppName to the About data
 *
 * AppName is required
 * AppName is part of the announce signal
 * AppName can be localized for other languages
 *
 * @param[in] data     alljoyn_aboutdata object this call is made for
 * @param[in] appName  the AppName (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in] language the IETF language tag specified by RFC 5646
 *                     If language is NULL the AppName will be set for the default language.
 *
 * @return
 *  - #ER_OK on success
 *  - #ER_ABOUT_DEFAULT_LANGUAGE_NOT_SPECIFIED if language tag was not specified
 *                                             and the default language is also
 *                                             not found.
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setappname(alljoyn_aboutdata data,
                                                           const char* appName,
                                                           const char* language);

/**
 * Get the AppName from the About data
 *
 * AppName is required
 * AppName is part of the announce signal
 * AppName can be localized for other languages
 *
 * @param[in]  data     alljoyn_aboutdata object this call is made for
 * @param[out] appName  the AppName found in the About data (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in]  language the IETF language tag specified by RFC 5646
 *                      If language is NULL the AppName for the default language will be returned.
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getappname(alljoyn_aboutdata data,
                                                           char** appName,
                                                           const char* language);

/**
 * Set the Manufacturer to the About data
 *
 * Manufacturer is required
 * Manufacturer is part of the announce signal
 * Manufacturer can be localized for other languages
 *
 * @param[in] data         alljoyn_aboutdata object this call is made for
 * @param[in] manufacturer the Manufacturer (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in] language     the IETF language tag specified by RFC 5646
 *                         If language is NULL the Manufacture will be set for the default language.
 *
 * @return
 *  - #ER_OK on success
 *  - #ER_ABOUT_DEFAULT_LANGUAGE_NOT_SPECIFIED if language tag was not specified
 *                                             and the default language is also
 *                                             not found.
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setmanufacturer(alljoyn_aboutdata data,
                                                                const char* manufacturer,
                                                                const char* language);

/**
 * Get the Manufacturer from the About data
 *
 * Manufacturer is required
 * Manufacturer is part of the announce signal
 * Manufacturer can be localized for other languages
 *
 * @param[in]  data         alljoyn_aboutdata object this call is made for
 * @param[out] manufacturer the Manufacturer found in the About data (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in]  language     the IETF language tag specified by RFC 5646
 *                          If language is NULL the Manufacturer for the default language will be returned.
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getmanufacturer(alljoyn_aboutdata data,
                                                                char** manufacturer,
                                                                const char* language);

/**
 * Set the ModelNumber to the About data
 *
 * ModelNumber is required
 * ModelNumber is part of the announce signal
 * ModelNumber can not be localized for other languages
 *
 * @param[in] data        alljoyn_aboutdata object this call is made for
 * @param[in] modelNumber the application model number
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setmodelnumber(alljoyn_aboutdata data,
                                                               const char* modelNumber);

/**
 * Get the ModelNumber from the About data
 *
 * ModelNumber IS required
 * ModelNumber IS part of the announce signal
 * ModelNumber CAN NOT be localized for other languages
 *
 * @param[in]  data        alljoyn_aboutdata object this call is made for
 * @param[out] modelNumber the application model number
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getmodelnumber(alljoyn_aboutdata data,
                                                               char** modelNumber);

/**
 * Set a supported language.
 *
 * This is a string representing the a single language. The language is
 * specified using IETF language tags specified by the RFC 5646.
 *
 * If the language tag has already been added ER_OK will be returned with no
 * additional changes being made.
 *
 * @param[in] data     alljoyn_aboutdata object this call is made for
 * @param[in] language the IETF language tag
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setsupportedlanguage(alljoyn_aboutdata data,
                                                                     const char* language);

/**
 * Get an array of supported languages
 *
 * @param data         alljoyn_aboutdata object this call is made for
 * @param languageTags a pointer to a languageTags array to receive the
 *                     language tags. Can be NULL in which case no
 *                     language tags are returned and the return value gives
 *                     the number of language tags available.
 * @param num          the size of the languageTags array.
 *
 * @return The number of languageTags returned or the total number of
 *         language tags if languageTags is NULL.
 */
extern AJ_API size_t AJ_CALL alljoyn_aboutdata_getsupportedlanguages(alljoyn_aboutdata data,
                                                                     const char** languageTags,
                                                                     size_t num);

/**
 * Set the Description to the About data
 *
 * Description IS required
 * Description IS NOT part of the announce signal
 * Description CAN BE localized for other languages
 *
 * @param[in] data         alljoyn_aboutdata object this call is made for
 * @param[in] description  the Description (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in] language     the IETF language tag specified by RFC 5646
 *                         If language is NULL the Description will be set for the default language.
 *
 * @return
 *  - #ER_OK on success
 *  - #ER_ABOUT_DEFAULT_LANGUAGE_NOT_SPECIFIED if language tag was not specified and
 *                                             the default language is also not found.
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setdescription(alljoyn_aboutdata data,
                                                               const char* description,
                                                               const char* language);

/**
 * Get the Description from the About data
 *
 * Description IS required
 * Description IS NOT part of the announce signal
 * Description CAN BE localized for other languages
 *
 * @param[in]  data        alljoyn_aboutdata object this call is made for
 * @param[out] description the Description found in the About data (alljoyn_aboutdata data, UTF-8 encoded string)
 * @param[in]  language    the IETF language tag specified by RFC 5646
 *                         If language is NULL the Description for the default language will be returned.
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getdescription(alljoyn_aboutdata data,
                                                               char** description,
                                                               const char* language);

/**
 * Set the DateOfManufacture to the About data
 *
 * The date of manufacture using the format YYYY-MM-DD.  Known as XML
 * DateTime format.
 *
 * DateOfManufacture IS NOT required
 * DateOfManufacture IS NOT part of the announce signal
 * DateOfManufacture CAN NOT be localized for other languages
 *
 * @param[in] data              alljoyn_aboutdata object this call is made for
 * @param[in] dateOfManufacture the date of manufacture using YYYY-MM-DD format
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setdateofmanufacture(alljoyn_aboutdata data,
                                                                     const char* dateOfManufacture);

/**
 * Get the DateOfManufacture from the About data
 *
 * The date of manufacture using the format YYYY-MM-DD.  Known as XML
 * DateTime format.
 *
 * DateOfManufacture IS NOT required
 * DateOfManufacture IS NOT part of the announce signal
 * DateOfManufacture CAN NOT be localized for other languages
 *
 * @param[in]  data              alljoyn_aboutdata object this call is made for
 * @param[out] dateOfManufacture the date of manufacture using YYYY-MM-DD format
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getdateofmanufacture(alljoyn_aboutdata data,
                                                                     char** dateOfManufacture);

/**
 * Set the SoftwareVersion to the About data
 *
 * SoftwareVersion IS required
 * SoftwareVersion IS NOT part of the announce signal
 * SoftwareVersion CAN NOT be localized for other languages
 *
 * @param[in] data            alljoyn_aboutdata object this call is made for
 * @param[in] softwareVersion the software version for the OEM software
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setsoftwareversion(alljoyn_aboutdata data,
                                                                   const char* softwareVersion);

/**
 * Get the SoftwareVersion from the About data
 *
 * SoftwareVersion IS required
 * SoftwareVersion IS NOT part of the announce signal
 * SoftwareVersion CAN NOT be localized for other languages
 *
 * @param[in]  data            alljoyn_aboutdata object this call is made for
 * @param[out] softwareVersion the software version for the OEM software
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getsoftwareversion(alljoyn_aboutdata data,
                                                                   char** softwareVersion);

/**
 * Get the AJSoftwareVersion from the About data
 *
 * The AJSoftwareVersion is automatically set when the About data is created
 * or when it is read from remote device.
 *
 * AJSoftwareVersion IS required
 * AJSoftwareVersion IS NOT part of the announce signal
 * AJSoftwareVersion CAN NOT be localized for other languages
 *
 * @param[in]  data              alljoyn_aboutdata object this call is made for
 * @param[out] ajSoftwareVersion the current version of AllJoyn SDK utilized
 *                               by the application
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getajsoftwareversion(alljoyn_aboutdata data,
                                                                     char** ajSoftwareVersion);

/**
 * Set the HardwareVersion to the About data
 *
 * HardwareVersion IS NOT required
 * HardwareVersion IS NOT part of the announce signal
 * HardwareVersion CAN NOT be localized for other languages
 *
 * @param[in] data            alljoyn_aboutdata object this call is made for
 * @param[in] hardwareVersion the device hardware version
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_sethardwareversion(alljoyn_aboutdata data,
                                                                   const char* hardwareVersion);

/**
 * Get the HardwareVersion from the About data
 *
 * HardwareVersion IS NOT required
 * HardwareVersion IS NOT part of the announce signal
 * HardwareVersion CAN NOT be localized for other languages
 *
 * @param[in]  data            alljoyn_aboutdata object this call is made for
 * @param[out] hardwareVersion the device hardware version
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_gethardwareversion(alljoyn_aboutdata data,
                                                                   char** hardwareVersion);

/**
 * Set the SupportUrl to the About data
 *
 * SupportUrl IS NOT required
 * SupportUrl IS NOT part of the announce signal
 * SupportUrl CAN NOT be localized for other languages
 *
 * @param[in] data       alljoyn_aboutdata object this call is made for
 * @param[in] supportUrl the support URL to be populated by OEM
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setsupporturl(alljoyn_aboutdata data,
                                                              const char* supportUrl);

/**
 * Get the SupportUrl from the About data
 *
 * SupportUrl IS NOT required
 * SupportUrl IS NOT part of the announce signal
 * SupportUrl CAN NOT be localized for other languages
 *
 * @param[in]  data       alljoyn_aboutdata object this call is made for
 * @param[out] supportUrl the support URL
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getsupporturl(alljoyn_aboutdata data,
                                                              char** supportUrl);

/**
 * Generic way to set a new field.  Everything could be done this way.
 *
 * Unless the generic field is one of the pre-defined fields when they are
 * set they will have the following specifications
 *   NOT required
 *   NOT part of the announce signal
 *   CAN be localized
 *
 * Since every field can be localized even if the field is not localized it
 * must be set for every language.
 *
 * @param[in] data     alljoyn_aboutdata object this call is made for
 * @param[in] name     the name of the field to set
 * @param[in] value    a alljoyn_msgarg that contains the value that is set for the field
 * @param[in] language the IETF language tag specified by RFC 5646
 *                     if language is NULL the default language will be used.  Only
 *                     used for fields that are marked as localizable.
 *
 * @return
 *  - #ER_OK on success
 *  - #ER_ABOUT_DEFAULT_LANGUAGE_NOT_SPECIFIED if language tag was not specified
 *                                             and the default language is also
 *                                             not found.
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_setfield(alljoyn_aboutdata data,
                                                         const char* name,
                                                         alljoyn_msgarg value,
                                                         const char* language);

/**
 * Generic way to get a field.
 *
 * @param[in]  data     alljoyn_aboutdata object this call is made for
 * @param[in]  name     the name of the field to get
 * @param[out] value    alljoyn_msgarg holding a variant value that represents the field
 * @param[in]  language the IETF language tag specified by RFC 5646
 *                      If language is NULL the field for the default language will be returned.
 *
 * @return ER_OK on success
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getfield(alljoyn_aboutdata data,
                                                         const char* name,
                                                         alljoyn_msgarg* value,
                                                         const char* language);

/**
 * Get a list of the fields contained in this alljoyn_aboutdata object.
 * This is required if the About data comes from a remote source. User defined fields
 * are permitted. Use the GetFields method to get a list of all fields
 * currently found known by the alljoyn_aboutdata.
 *
 * @param[in]  data       alljoyn_aboutdata object this call is made for
 * @param[out] fields     an array of const char* that will contain all the strings
 * @param[in]  num_fields the size of the array
 *
 * @return
 *  The number of fields returned or the total number of fields if the fields parameter is NULL
 */
extern AJ_API size_t AJ_CALL alljoyn_aboutdata_getfields(alljoyn_aboutdata data,
                                                         const char** fields,
                                                         size_t num_fields);

/**
 * @param[in]  data alljoyn_aboutdata object this call is made for
 * @param[out] msgArg  the dictionary containing all of the About data fields for
 *                     the specified language.  If language is not specified the default
 *                     language will be returned
 * @param[in] language IETF language tag specified by RFC 5646 if the string
 *                     is NULL or an empty string for the default language
 *
 * @return
 *  - ER_OK on success
 *  - ER_LANGUAGE_NOT_SUPPORTED if language is not supported
 *  - ER_ABOUT_ABOUTDATA_MISSING_REQUIRED_FIELD if a required field is missing
 *  - other error indicating failure
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getaboutdata(alljoyn_aboutdata data,
                                                             alljoyn_msgarg msgArg,
                                                             const char* language);

/**
 * Return a alljoyn_msgarg pointer containing dictionary containing the About data that
 * is announced with the org.alljoyn.About.announce signal.
 * This will always be the default language and will only contain the fields
 * that are announced.
 *
 * The fields that will be part of the announced alljoyn_msgarg are:
 *  - AppId
 *  - DefaultLanguage
 *  - DeviceName
 *  - DeviceId
 *  - AppName
 *  - Manufacture
 *  - ModelNumber
 *
 * If you require other fields or need the localized About data the
 * org.alljoyn.About.GetAboutData method can be used.
 *
 * @param[in]  data   alljoyn_aboutdata object this call is made for
 * @param[out] msgArg a alljoyn_msgarg dictionary with the a{sv} that contains the Announce
 *                    data.
 * @return ER_OK if successful
 */
extern AJ_API QStatus AJ_CALL alljoyn_aboutdata_getannouncedaboutdata(alljoyn_aboutdata data,
                                                                      alljoyn_msgarg msgArg);

/**
 * Is the given field name required to make an About announcement
 *
 * @param[in] data      alljoyn_aboutdata object this call is made for
 * @param[in] fieldName the name of the field
 *
 * @return
 *  - true if the field is required to make an About announcement
 *  - false otherwise.  If the fieldName is unknown false will be returned
 */
extern AJ_API bool AJ_CALL alljoyn_aboutdata_isfieldrequired(alljoyn_aboutdata data,
                                                             const char* fieldName);

/**
 * Is the given field part of the announce signal
 *
 * @param[in] data      alljoyn_aboutdata object this call is made for
 * @param[in] fieldName the name of the field
 *
 * @return
 *  - true if the field is part of the announce signal
 *  - false otherwise.  If the fieldName is unknown false will be returned
 */
extern AJ_API bool AJ_CALL alljoyn_aboutdata_isfieldannounced(alljoyn_aboutdata data,
                                                              const char* fieldName);

/**
 * Is the given field a localized field.
 *
 * Localized fields should be provided for every supported language
 *
 * @param[in] data      alljoyn_aboutdata object this call is made for
 * @param[in] fieldName the name of the field
 *
 * @return
 *  - true if the field is a localizable value
 *  - false otherwise. If the fieldName is unknown false will be returned.
 */
extern AJ_API bool AJ_CALL alljoyn_aboutdata_isfieldlocalized(alljoyn_aboutdata data,
                                                              const char* fieldName);

/**
 * Get the signature for the given field.
 *
 * @param[in] data      alljoyn_aboutdata object this call is made for
 * @param[in] fieldName the name of the field
 *
 * @return
 *  - the signature of the field
 *  - NULL is field is unknown
 */
extern AJ_API const char* AJ_CALL alljoyn_aboutdata_getfieldsignature(alljoyn_aboutdata data,
                                                                      const char* fieldName);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
