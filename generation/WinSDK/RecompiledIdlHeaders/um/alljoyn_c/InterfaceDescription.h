/**
 * @file
 * This file defines types for statically describing a message bus interface
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
#ifndef _ALLJOYN_C_INTERFACEDESCRIPTION_H
#define _ALLJOYN_C_INTERFACEDESCRIPTION_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Message.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * alljoyn_interfacedescription is an object for describing message bus interfaces.
 * alljoyn_interfacedescription objects describe the methods,
 * signals and properties of an alljoyn_busobject or an alljoyn_proxybusobject.
 *
 * Calling #alljoyn_proxybusobject_addinterface() adds the AllJoyn interface described by an
 * alljoyn_interfacedescription to a ProxyBusObject instance. After an
 * %alljoyn_interfacedescription has been added, the methods described in the interface
 * can be called. Similarly calling #alljoyn_busobject_addinterface adds the interface
 * and its methods, properties, and signal to an #alljoyn_busobject. After an interface
 * has been added method handlers for the methods described in the interface can be
 * added by calling #alljoyn_busobject_addmethodhandler or #alljoyn_busobject_addmethodhandlers.
 *
 * An alljoyn_interfacedescription can be constructed piecemeal by calling
 * #alljoyn_interfacedescription_addmethod, #alljoyn_interfacedescription_addmember(),
 * #alljoyn_interfacedescription_addsignal and #alljoyn_interfacedescription_addproperty().
 * Alternatively, calling #alljoyn_proxybusobject_parsexml() will create the
 * alljoyn_interfacedescription instances for that proxy object directly from an XML
 * string. Calling #alljoyn_proxybusobject_introspectremoteobject or
 * #alljoyn_proxybusobject_introspectremoteobjectasync also creates the
 * alljoyn_interfacedescription instances from XML but in this case the XML is obtained
 * by making a remote Introspect method call on a bus object.
 */
typedef struct _alljoyn_interfacedescription_handle*        alljoyn_interfacedescription;

/** @name Access type */
// @{
static const uint8_t ALLJOYN_PROP_ACCESS_READ  = 1; /**< Read Access type */
static const uint8_t ALLJOYN_PROP_ACCESS_WRITE = 2; /**< Write Access type */
static const uint8_t ALLJOYN_PROP_ACCESS_RW    = 3; /**< Read-Write Access type */
// @}
/** @name Annotation flags */
// @{
static const uint8_t ALLJOYN_MEMBER_ANNOTATE_NO_REPLY         = 1; /**< No reply annotate flag */
static const uint8_t ALLJOYN_MEMBER_ANNOTATE_DEPRECATED       = 2; /**< Deprecated annotate flag */
static const uint8_t ALLJOYN_MEMBER_ANNOTATE_SESSIONCAST      = 4; /**< Sessioncast annotate flag */
static const uint8_t ALLJOYN_MEMBER_ANNOTATE_SESSIONLESS      = 8; /**< Sessionless annotate flag */
static const uint8_t ALLJOYN_MEMBER_ANNOTATE_UNICAST          = 16; /**< Unicast annotate flag */
static const uint8_t ALLJOYN_MEMBER_ANNOTATE_GLOBAL_BROADCAST = 32; /**< Global broadcast annotate flag */
// @}

/**
 * The interface security policy can be inherit, required, or off. If security is
 * required on an interface, methods on that interface can only be called by an authenticated peer
 * and signals emitted from that interfaces can only be received by an authenticated peer. If
 * security is not specified for an interface the interface inherits the security of the objects
 * that implement it.  If security is not applicable (off) to an interface, authentication is never
 * required even when implemented by a secure object. For example, security does not apply to
 * the Introspection interface otherwise secure objects would not be introspectable.
 */
typedef enum {
    AJ_IFC_SECURITY_INHERIT,       /**< Inherit the security of the object that implements the interface */
    AJ_IFC_SECURITY_REQUIRED,      /**< Security is required for an interface */
    AJ_IFC_SECURITY_OFF            /**< Security does not apply to this interface */
} alljoyn_interfacedescription_securitypolicy;

/**
 * Structure representing the member to be added to the Interface
 */
typedef struct {
    alljoyn_interfacedescription iface;         /**< Interface that this member belongs to */
    alljoyn_messagetype memberType;             /**< %Member type */
    const char* name;                           /**< %Member name */
    const char* signature;                      /**< Method call IN arguments (NULL for signals) */
    const char* returnSignature;                /**< Signal or method call OUT arguments */
    const char* argNames;                       /**< Comma separated list of argument names - can be NULL */

    const void* internal_member;                /**< For internal use only */
} alljoyn_interfacedescription_member;

/**
 * Type for the interface description translation callback.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use language-aware accessors instead
 * (e.g., alljoyn_interfacedescription_setdescriptionforlanguage()).
 *
 * Called by the interface description when the description of a language is requested.
 *
 * @param[in] sourceLanguage The language tag of the text in sourceText. If
 *  sourceLanguage is NULL or empty, then sourceText is simply an id used
 *  for lookup.
 * @param[in] targetLanguage The language tag to translate into
 * @param[in] sourceText The source text to translate or id to look up
 */
typedef const char* (AJ_CALL * alljoyn_interfacedescription_translation_callback_ptr)(const char* sourceLanguage, const char* targetLanguage, const char* sourceText);

/**
 * Get the number of annotations that a member has.
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number of annotations will no longer change.
 *
 * @param[in] member The alljoyn interface description member that we want the
 *                   annotations count from
 * @return the number of annotations
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_member_getannotationscount(alljoyn_interfacedescription_member member);

/**
 * Obtain the name and value for the annotation at the specified index.
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number and order of annotations will no longer change.
 *
 * @param[in] member the alljoyn interface description member that we want to read annotations from
 * @param[in] index  the index of the annotation of interest
 * @param[out] name   the name of the annotation
 * @param[in,out] name_size the size of the name string if name==NULL this will return the size of the name string plus nul character
 * @param[out] value  the value of the annotation
 * @param[in,out] value_size the size of the value string if value == NULL this will return the size of the value string plus nul character
 */
extern AJ_API void AJ_CALL alljoyn_interfacedescription_member_getannotationatindex(alljoyn_interfacedescription_member member,
                                                                                    size_t index,
                                                                                    char* name, size_t* name_size,
                                                                                    char* value, size_t* value_size);

/**
 * Get this member's annotation value return the size of the value string if
 * name is NULL.
 *
 * @param[in] member The alljoyn interface description member that we want the annotation from
 * @param[in] name   Name of the annotation to look for
 * @param[out] value  Value to compare with
 * @param[in,out] value_size size of the value string if value == NULL it will return the size of the value string plus nul character
 * @return    true if annotations[name] == value
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_member_getannotation(alljoyn_interfacedescription_member member, const char* name, char* value, size_t* value_size);

/**
 * Get the number of annotations that a member argument has.
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number of annotations will no longer change.
 *
 * @param[in] member The alljoyn interface description member that we want the annotations count from.
 * @param[in] argName Name of the argument.
 *
 * @return the number of annotations.
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_member_getargannotationscount(alljoyn_interfacedescription_member member, const char* argName);

/**
 * Obtain the name and value for the argument annotation at the specified index.
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number and order of annotations will no longer change.
 *
 * @param[in] member The alljoyn interface description member that we want to read annotations from.
 * @param[in] argName Name of the argument.
 * @param[in] index The index of the annotation of interest.
 * @param[out] name The name of the annotation.
 * @param[in,out] name_size The size of the name string. If name==NULL, this will return the size of the name string plus nul character.
 * @param[out] value The value of the annotation.
 * @param[in,out] value_size The size of the value string. If value == NULL, this will return the size of the value string plus nul character.
 */
extern AJ_API void AJ_CALL alljoyn_interfacedescription_member_getargannotationatindex(alljoyn_interfacedescription_member member,
                                                                                       const char* argName,
                                                                                       size_t index,
                                                                                       char* name,
                                                                                       size_t* name_size,
                                                                                       char* value,
                                                                                       size_t* value_size);

/**
 * Get this member's argument annotation value and return the size of the value string if
 * name is NULL.
 *
 * @param[in] member The alljoyn interface description member that we want the annotation from.
 * @param[in] argName Name of the argument.
 * @param[in] name Name of the annotation to look for.
 * @param[out] value Value of the annotation.
 * @param[in,out] value_size The size of the value string. If value == NULL, it will return the size of the value string plus nul character.
 * @return    true if annotations[name] == value.
 */
extern QCC_BOOL AJ_CALL alljoyn_interfacedescription_member_getargannotation(alljoyn_interfacedescription_member member, const char* argName, const char* name, char* value, size_t* value_size);

/**
 * Structure representing properties of the Interface
 */
typedef struct {
    const char* name;               /**< %Property name */
    const char* signature;          /**< %Property type */
    uint8_t access;                  /**< Access is #ALLJOYN_PROP_ACCESS_READ, #ALLJOYN_PROP_ACCESS_WRITE, or #ALLJOYN_PROP_ACCESS_RW */

    const void* internal_property;  /**< For internal use only */
} alljoyn_interfacedescription_property;

/**
 * Get the number of annotations that a property has.
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number of annotations will no longer change.
 *
 * @param[in] property The alljoyn interface description property that we want the
 *                   annotations count from
 * @return the number of annotations
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_property_getannotationscount(alljoyn_interfacedescription_property property);

/**
 * Obtain the name and value for the annotation at the specified index.
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number and order of annotations will no longer change.
 *
 * @param[in] property the alljoyn interface description property that we want to read annotations from
 * @param[in] index  the index of the annotation of interest
 * @param[out] name   the name of the annotation
 * @param[in,out] name_size the size of the name string if name==NULL this will return the size of the name string plus nul character
 * @param[out] value  the value of the annotation
 * @param[in,out] value_size the size of the value string if value == NULL this will return the size of the value string plus nul character
 */
extern AJ_API void AJ_CALL alljoyn_interfacedescription_property_getannotationatindex(alljoyn_interfacedescription_property property,
                                                                                      size_t index,
                                                                                      char* name, size_t* name_size,
                                                                                      char* value, size_t* value_size);

/**
 * Get this member's annotation value return the size of the value string if
 * name is NULL.
 *
 * @param[in] property The AllJoyn alljoyn_interfacedescription property that we want the annotation from.
 * @param[in] name   Name of the annotation to look for
 * @param[out] value  Value to compare with
 * @param[in,out] value_size size of the value string if value == NULL it will return the size of the value string plus nul character
 * @return    true if annotations[name] == value
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_property_getannotation(alljoyn_interfacedescription_property property, const char* name, char* value, size_t* value_size);

/**
 * Activate this interface. An interface must be activated before it can be used. Activating an
 * interface locks the interface so that is can no longer be modified.
 *
 * @param iface alljoyn_interfacedescription to activate.
 */
extern AJ_API void AJ_CALL alljoyn_interfacedescription_activate(alljoyn_interfacedescription iface);

/**
 * Add an annotation to the interface.
 *
 * @param iface      Interface onto which the annotation will be added
 * @param name       Name of annotation.
 * @param value      Value of the annotation
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_PROPERTY_ALREADY_EXISTS if the property can not be added
 *                                        because it already exists.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addannotation(alljoyn_interfacedescription iface, const char* name, const char* value);

/**
 * Lookup an interface annotation
 *
 * @param       iface   Interface on which to lookup the member
 * @param       name    Name of the annotation to lookup
 * @param[out]  value   The value of the annotation
 * @param[in,out] value_size return the size of the string if value == NULL plus nul character or
 *                           specifies the max size of value if value != NULL.
 *
 * @return QC_FALSE if annotation does not exist, QC_TRUE otherwise.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getannotation(alljoyn_interfacedescription iface, const char* name, char* value, size_t* value_size);


/**
 * Find the number of annotations the alljoyn_interfacedescription has
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number of annotations will no longer change.
 *
 * @param[in] iface The alljoyn_interfacedescription that we want the annotations count from
 *
 * @return the number of annotations
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getannotationscount(alljoyn_interfacedescription iface);

/**
 * Obtain the name and value for the annotation at the specified index.
 *
 * This function must only be used after calling alljoyn_interfacedescription_activate
 * because it guarantees that the number and order of annotations will no longer change.
 *
 * @param[in] iface the alljoyn interface description that we want to read annotations from
 * @param[in] index  the index of the annotation of interest
 * @param[out] name   the name of the annotation
 * @param[in,out] name_size the size of the name string if name==NULL this will return the size of the name string plus nul character
 * @param[out] value  the value of the annotation
 * @param[in,out] value_size the size of the value string if value == NULL this will return the size of the value string plus nul character
 */
extern AJ_API void AJ_CALL alljoyn_interfacedescription_getannotationatindex(alljoyn_interfacedescription iface,
                                                                             size_t index,
                                                                             char* name, size_t* name_size,
                                                                             char* value, size_t* value_size);

/**
 * Lookup a member description by name
 *
 * @param       iface   Interface on which to lookup the member
 * @param       name    Name of the member to lookup
 * @param[out]  member  The description of the member
 *
 * @return QCC_FALSE if member does not exist, QCC_TRUE otherwise.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getmember(const alljoyn_interfacedescription iface, const char* name,
                                                                      alljoyn_interfacedescription_member* member);

/**
 * Add a member to the interface.
 *
 * @param iface       Interface on which to add the member.
 * @param type        Message type.
 * @param name        Name of member.
 * @param inputSig    Signature of input parameters or NULL for none.
 * @param outSig      Signature of output parameters or NULL for none.
 * @param argNames    Comma separated list of input and then output arg names used in annotation XML.
 * @param annotation  Annotation flags.
 *
 * @return
 *      - #ER_OK if successful
 *      - #ER_BUS_MEMBER_ALREADY_EXISTS if member already exists
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addmember(alljoyn_interfacedescription iface, alljoyn_messagetype type,
                                                                     const char* name, const char* inputSig, const char* outSig,
                                                                     const char* argNames, uint8_t annotation);

/**
 * Add an annotation to a member
 *
 * @param iface       Interface on which to add the member.
 * @param member      Name of member.
 * @param name        Name of annotation
 * @param value       Value for the annotation
 *
 * @return
 *      - #ER_OK if successful
 *      - #ER_BUS_MEMBER_ALREADY_EXISTS if member already exists
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addmemberannotation(alljoyn_interfacedescription iface,
                                                                               const char* member,
                                                                               const char* name,
                                                                               const char* value);

/**
 * Add an annotation to a member
 *
 * @param iface       Interface on which to add the member.
 * @param member      Name of member.
 * @param name        Name of annotation
 * @param[out] value  Value for the annotation
 * @param[in,out] value_size The size value.  If value == NULL returns the size
 *                           of the string plus nul character  so a new char* can be allocated.
 *                           If value != NULL specifies the size of value.
 *
 * @return QC_FALSE if annotation does not exist, QC_TRUE otherwise.
 */
AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getmemberannotation(alljoyn_interfacedescription iface,
                                                                         const char* member,
                                                                         const char* name,
                                                                         char* value,
                                                                         size_t* value_size);

/**
 * Get all the members.
 *
 * @param iface       The interface from which to get all members.
 * @param members     A pointer to a Member array to receive the members. Can be NULL in
 *                    which case no members are returned and the return value gives the number
 *                    of members available.
 * @param numMembers  The size of the Member array. If this value is smaller than the total
 *                    number of members only numMembers will be returned.
 *
 * @return  The number of members returned or the total number of members if members is NULL.
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getmembers(const alljoyn_interfacedescription iface,
                                                                     alljoyn_interfacedescription_member* members,
                                                                     size_t numMembers);

/**
 * Check for existence of a member. Optionally check the signature also.
 * @remark
 * if the a signature is not provided this method will only check to see if
 * a member with the given @c name exists.  If a signature is provided a
 * member with the given @c name and @c signature must exist for this to return true.
 *
 * @param iface      Interface to query for a member.
 * @param name       Name of the member to lookup
 * @param inSig      Input parameter signature of the member to lookup
 * @param outSig     Output parameter signature of the member to lookup (leave NULL for signals)
 * @return QCC_TRUE if the member name exists.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_hasmember(alljoyn_interfacedescription iface,
                                                                      const char* name, const char* inSig,
                                                                      const char* outSig);

/**
 * Add a method call member to the interface.
 *
 * @param iface       Interface on which to add the method member.
 * @param name        Name of method call member.
 * @param inputSig    Signature of input parameters or NULL for none.
 * @param outSig      Signature of output parameters or NULL for none.
 * @param argNames    Comma separated list of input and then output arg names used in annotation XML.
 * @param annotation  Annotation flags. Default value 0.
 * @param accessPerms Access permission requirements on this call. Default value 0.
 *
 * @return
 *      - #ER_OK if successful
 *      - #ER_BUS_MEMBER_ALREADY_EXISTS if member already exists
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addmethod(alljoyn_interfacedescription iface, const char* name, const char* inputSig, const char* outSig, const char* argNames, uint8_t annotation, const char* accessPerms);

/**
 * Lookup a member method description by name
 *
 * @param       iface Interface on which to lookup the method.
 * @param       name  Name of the method to lookup
 * @param[out]  member  The description of the member
 * @return
 *      - Pointer to member.
 *      - NULL if does not exist.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getmethod(alljoyn_interfacedescription iface, const char* name, alljoyn_interfacedescription_member* member);

/**
 * Add a signal member to the interface.
 *
 * @param iface       Interface on which to add the signal member.
 * @param name        Name of method call member.
 * @param sig         Signature of parameters or NULL for none.
 * @param argNames    Comma separated list of arg names used in annotation XML.
 * @param annotation  Annotation flags. Default value 0.
 * @param accessPerms Access permission requirements on this call. Default value 0.
 *
 * @return
 *      - #ER_OK if successful
 *      - #ER_BUS_MEMBER_ALREADY_EXISTS if member already exists
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addsignal(alljoyn_interfacedescription iface, const char* name, const char* sig, const char* argNames, uint8_t annotation, const char* accessPerms);

/**
 * Lookup a member signal description by name
 *
 * @param      iface   Interface to query for signal
 * @param      name    Name of the signal to lookup
 * @param[out] member  return a pointer to the signal member or NULL if the
 *                     signal does not exist.
 *
 * @return QCC_TRUE is the signal was found QCC_FALSE otherwise
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getsignal(alljoyn_interfacedescription iface, const char* name, alljoyn_interfacedescription_member* member);

/**
 * Lookup a property description by name
 *
 * @param iface     Interface to query for a property.
 * @param name      Name of the property to lookup
 * @param property  The description of the property
 * @return QCC_TRUE if the property was found, QCC_FALSE otherwise
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getproperty(const alljoyn_interfacedescription iface, const char* name,
                                                                        alljoyn_interfacedescription_property* property);

/**
 * Get all the properties.
 *
 * @param iface     Interface to query for properties.
 * @param props     A pointer to a Property array to receive the properties. Can be NULL in
 *                  which case no properties are returned and the return value gives the number
 *                  of properties available.
 * @param numProps  The size of the Property array. If this value is smaller than the total
 *                  number of properties only numProperties will be returned.
 *
 *
 * @return  The number of properties returned or the total number of properties if props is NULL.
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getproperties(const alljoyn_interfacedescription iface,
                                                                        alljoyn_interfacedescription_property* props,
                                                                        size_t numProps);

/**
 * Add a property to the interface.
 *
 * @param iface      Interface on which to add the property.
 * @param name       Name of property.
 * @param signature  Property type.
 * @param access     #ALLJOYN_PROP_ACCESS_READ, #ALLJOYN_PROP_ACCESS_WRITE or #ALLJOYN_PROP_ACCESS_RW
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_PROPERTY_ALREADY_EXISTS if the property can not be added
 *                                        because it already exists.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addproperty(alljoyn_interfacedescription iface, const char* name,
                                                                       const char* signature, uint8_t access);

/**
 * Add an annotation to an existing property
 * @param iface      Interface on which to add the property annotation.
 * @param property   Name of property.
 * @param name       Name of annotation
 * @param value      value of annotation
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_PROPERTY_ALREADY_EXISTS if the annotation can not be added to the property because it already exists.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addpropertyannotation(alljoyn_interfacedescription iface,
                                                                                 const char* property,
                                                                                 const char* name,
                                                                                 const char* value);
/**
 * Get the annotation value for a property
 * @param         iface     Interface on which to add the property.
 * @param         property  Name of the property
 * @param         name      Name of annotation
 * @param[out]    value     Value for the annotation use NULL to obtain the size of the string in value
 * @param[in,out] str_size  the size of the char* value if value == NULL return the size of the value string plus nul character
 *
 * @code
 * size_t str_size;
 * alljoyn_interfacedescription_getpropertyannotation(iface, "myProperty", "org.freedesktop.DBus.Property.EmitsChangedSignal", NULL, &str_size);
 * char* value = (char*)malloc(sizeof(char) * str_size);
 * QCC_BOOL success = alljoyn_interfacedescription_getpropertyannotation(iface, "myProperty", "org.freedesktop.DBus.Property.EmitsChangedSignal", value, &str_size);
 * if (success == QCC_TRUE) {
 *    \/\/ code that does something with the value
 * }
 * free(value);
 * @endcode
 *
 * @return           QCC_TRUE if found, QCC_FALSE if not found
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getpropertyannotation(alljoyn_interfacedescription iface,
                                                                                  const char* property,
                                                                                  const char* name,
                                                                                  char* value,
                                                                                  size_t* str_size);

/**
 * Check for existence of a property.
 *
 * @param iface      Interface to query.
 * @param name       Name of the property to lookup
 * @return true if the property exists.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_hasproperty(const alljoyn_interfacedescription iface, const char* name);

/**
 * Check for existence of any properties
 *
 * @param iface      Interface to query.
 * @return  true if interface has any properties.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_hasproperties(const alljoyn_interfacedescription iface);

/**
 * Returns the name of the interface
 *
 * @param iface      Interface to query.
 * @return the interface name.
 */
extern AJ_API const char* AJ_CALL alljoyn_interfacedescription_getname(const alljoyn_interfacedescription iface);

/**
 * Returns a description of the interface in introspection XML format
 * @return The interface description in introspection XML format.
 *
 * @param iface      Interface to query
 * @param[out] str   The character string that will hold the XML string
 *                   representation of the interface
 * @param[in]  buf   The size of the char* array that will hold the string
 * @param indent     Number of space chars to use in XML indentation.
 * @return  The number of characters (including the terminating null byte) which
 *          would have been written to the final string if enough space is
 *          available.  Thus returning a value larger than buf means the output
 *          was truncated.
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_introspect(const alljoyn_interfacedescription iface, char* str, size_t buf, size_t indent);

/**
 * Indicates if this interface is secure. Secure interfaces require end-to-end authentication.
 * The arguments for methods calls made to secure interfaces and signals emitted by secure
 * interfaces are encrypted.
 * @param iface      Interface to query.
 * @return true if the interface is secure.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_issecure(const alljoyn_interfacedescription iface);

/**
 * Get the security policy that applies to this interface.
 *
 * @param iface   Interface to query. for its security policy
 *
 * @return Returns the security policy for this interface.
 */
extern AJ_API alljoyn_interfacedescription_securitypolicy AJ_CALL alljoyn_interfacedescription_getsecuritypolicy(const alljoyn_interfacedescription iface);

/**
 * Set the description language to this interface.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use alljoyn_interfacedescription_setdescriptionforlanguage() instead.
 *
 * @param[in] iface Interface on which to set the description language.
 * @param[in] language The language tag.
 */
QCC_DEPRECATED_ON(
    extern AJ_API void AJ_CALL alljoyn_interfacedescription_setdescriptionlanguage(alljoyn_interfacedescription iface, const char* language),
    16.10);

/**
 * Get the description language of this interface
 *
 * @deprecated This function returns languages for descriptions set by the single-language accessors
 * (e.g., alljoyn_interfacedescription_setdescription()) and translated using the translation callback.
 * These accessors are deprecated.
 * To get languages for the new descriptions, set by the multilingual accessors
 * (e.g., alljoyn_interfacedescription_setdescriptionforlanguage()) or annotation setters
 * (e.g., alljoyn_interfacedescription_addannotation()), please use
 * alljoyn_interfacedescription_getdescriptionlanguages2().
 *
 * @param[in] iface Interface to query.
 * @param[out] languages A pointer to a language array to receive the
 *                       languages. Can be NULL in which case no
 *                       languages are returned and the return value gives
 *                       the number of languages available.
 * @param[in] size The size of the language array.
 *
 * @return The number of languages returned or the total number of
 *         language tags if languages is NULL.
 */
QCC_DEPRECATED_ON(
    extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getdescriptionlanguages(const alljoyn_interfacedescription iface, const char** languages, size_t size),
    16.10);

/**
 * Get all the description languages for this interface.
 *
 * If the provided @p languages argument is not a nullptr and the provided @p languagesSize is not 0,
 * the function writes into the @p languages array language tags (as defined in RFC 5646) for the available descriptions:
 * interface description, interface property descriptions, interface member and member argument descriptions.
 * The array is sorted alphabetically and the language tags are delimited with commas, e.g., "de,en,en-US,fr".
 * The array is NULL-terminated.
 * If the @p languages argument is a nullptr or @p languagesSize is 0, the function only calculates the size required
 * for all the available language tags and returns it.
 *
 * @note This function returns languages for descriptions set by the multilingual accessors
 * (e.g., alljoyn_interfacedescription_setdescriptionforlanguage()) or annotation setters
 * (e.g., alljoyn_interfacedescription_addannotation()). It will not return languages set
 * by the deprecated accessors and translators (e.g., alljoyn_interfacedescription_setdescription()).
 *
 * @param[in] iface Interface to query.
 * @param[out] languages A pointer to an array to receive the language tags. The function caller is responsible
 *                       for the allocation of this array. Before the allocation, the function can be called
 *                       with the @p languages argument set to nullptr and/or the @languagesSize set to 0 to determine
 *                       the required size of the array.
 * @param[in] languagesSize The maximum number of bytes to be written to the @languages array.
 *
 * @return The required size of the array or the number of bytes written (depending on the arguments, see above).
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getdescriptionlanguages2(const alljoyn_interfacedescription iface, char* languages, size_t languagesSize);

/**
 * Set the description to this interface.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use alljoyn_interfacedescription_setdescriptionforlanguage() instead.
 *
 * @param[in] iface Interface on which to set the description.
 * @param[in] description The interface description. Call alljoyn_interfacedescription_setdescriptionlanguage() to specify description language.
 */
QCC_DEPRECATED_ON(
    extern AJ_API void AJ_CALL alljoyn_interfacedescription_setdescription(alljoyn_interfacedescription iface, const char* description),
    16.10);

/**
 * Set the introspection description for this interface in the given language.
 *
 * The set description can be retrieved by calling alljoyn_interfacedescription_getdescriptionforlanguage()
 * OR alljoyn_interfacedescription_getannotation() for an "org.alljoyn.Bus.DocString" annotation
 * with the desired language tag (e.g., "org.alljoyn.Bus.DocString.en").
 * For example, a description set by calling
 * alljoyn_interfacedescription_setdescriptionforlanguage(iface, "This is the interface", "en")
 * can be retrieved by calling:
 *      - alljoyn_interfacedescription_getdescriptionforlanguage(iface, description, maxLength, "en") OR
 *      - alljoyn_interfacedescription_getannotation(iface, "org.alljoyn.Bus.DocString.en", description, &size).
 *
 * @param[in] iface Interface on which to set the description.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 * @param[in] description The interface description.
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_INTERFACE_ACTIVATED If the interface has already been activated.
 *      - #ER_BUS_DESCRIPTION_ALREADY_EXISTS If the interface already has a description.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_setdescriptionforlanguage(alljoyn_interfacedescription iface, const char* description, const char* languageTag);

/**
 * Get the introspection description for the interface in the given language.
 *
 * To obtain the description, the method searches for the best match of the given language tag
 * using the lookup algorithm in RFC 4647 section 3.4.
 * For example, if alljoyn_interfacedescription_getdescriptionforlanguage(iface, description, maxLength, "en-US")
 * is called, the method will:
 *       - Search for a description with the same language tag ("en-US"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Search for a description with a less specific language tag ("en"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Write an empty string to the description argument and return 0.
 *
 * The method will also provide descriptions which have been set as description annotations
 * (set by calling alljoyn_interfacedescription_addannotation() with the annotation name set to
 * "org.alljoyn.Bus.DocString" plus the desired language tag, e.g., "org.alljoyn.Bus.DocString.en").
 *
 * @param[in] iface Interface to query.
 * @param[out] description The description.
 * @param[in] maxLanguageLength Maximum number of characters to be written.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 * @return The number of characters written, not including the terminating null-character (0 if no description available).
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getdescriptionforlanguage(alljoyn_interfacedescription iface, char* description, size_t maxLanguageLength, const char* languageTag);

/**
 * Set the description for member of this interface.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use alljoyn_interfacedescription_setmemberdescriptionforlanguage() instead.
 *
 * @param[in] iface Interface on which to set member description.
 * @param[in] member The name of the member.
 * @param[in] description The member description. Call alljoyn_interfacedescription_setdescriptionlanguage() to specify description language.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_INTERFACE_ACTIVATED If the interface has already been activated.
 *      - #ER_BUS_INTERFACE_NO_SUCH_MEMBER If the member was not found.
 */
QCC_DEPRECATED_ON(
    extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_setmemberdescription(alljoyn_interfacedescription iface, const char* member, const char* description),
    16.10);

/**
 * Set the description for the member "member" of this interface in the given language.
 *
 * The set description can be retrieved by calling alljoyn_interfacedescription_getmemberdescriptionforlanguage()
 * OR alljoyn_interfacedescription_getmemberannotation() for an "org.alljoyn.Bus.DocString" annotation
 * with the desired language tag (e.g., "org.alljoyn.Bus.DocString.en").
 * For example, a description set by calling
 * alljoyn_interfacedescription_setmemberdescriptionforlanguage(iface, "MethodName", "This is the method", "en")
 * can be retrieved by calling:
 *      - alljoyn_interfacedescription_getmemberdescriptionforlanguage(iface, "MethodName", description, maxLength, "en") OR
 *      - alljoyn_interfacedescription_getmemberannotation(iface, "MethodName", "org.alljoyn.Bus.DocString.en", description, &size).
 *
 * @param[in] iface Interface on which to set member description.
 * @param[in] member The name of the member.
 * @param[in] description The member description.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_INTERFACE_ACTIVATED If the interface has already been activated.
 *      - #ER_BUS_INTERFACE_NO_SUCH_MEMBER If the member was not found.
 *      - #ER_BUS_DESCRIPTION_ALREADY_EXISTS If the interface member already has a description.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_setmemberdescriptionforlanguage(
    alljoyn_interfacedescription iface, const char* member, const char* description, const char* languageTag);

/**
 * Get the introspection description for the interface member "member" in the given language.
 *
 * To obtain the description, the method searches for the best match of the given language tag
 * using the lookup algorithm in RFC 4647 section 3.4.
 * For example, if alljoyn_interfacedescription_getmemberdescriptionforlanguage(iface, "MethodName", description, maxLength, "en-US")
 * is called, the method will:
 *       - Search for a description with the same language tag ("en-US"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Search for a description with a less specific language tag ("en"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Write an empty string to the description argument and return 0.
 *
 * The method will also provide descriptions which have been set as description annotations
 * (set by calling alljoyn_interfacedescription_addmemberannotation() with the annotation name set to
 * "org.alljoyn.Bus.DocString" plus the desired language tag, e.g., "org.alljoyn.Bus.DocString.en").
 *
 * @param[in] iface Interface to query.
 * @param[in] member The name of the member.
 * @param[out] description The description.
 * @param[in] maxLanguageLength Maximum number of characters to be written.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 * @return The number of characters written, not including the terminating null-character (0 if no description available).
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getmemberdescriptionforlanguage(
    alljoyn_interfacedescription iface, const char* member, char* description, size_t maxLanguageLength, const char* languageTag);

/**
 * Set the description for the argument of the member of this interface.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use alljoyn_interfacedescription_setargdescriptionforlanguage() instead.
 *
 * @param[in] iface Interface on which to set argument description.
 * @param[in] member The name of the member.
 * @param[in] argName The name of the argument.
 * @param[in] description The argument description. Call alljoyn_interfacedescription_setdescriptionlanguage() to specify description language.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_INTERFACE_ACTIVATED If the interface has already been activated.
 *      - #ER_BUS_INTERFACE_NO_SUCH_MEMBER If the member was not found.
 */
QCC_DEPRECATED_ON(
    extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_setargdescription(alljoyn_interfacedescription iface, const char* member, const char* argName, const char* description),
    16.10);

/**
 * Set the description for the argument "arg" of the member "member" of this interface.
 *
 * The set description can be retrieved by calling alljoyn_interfacedescription_getargdescriptionforlanguage()
 * OR alljoyn_interfacedescription_member_getargannotation() for an "org.alljoyn.Bus.DocString" annotation
 * with the desired language tag (e.g., "org.alljoyn.Bus.DocString.en").
 * For example, a description set by calling
 * alljoyn_interfacedescription_setargdescriptionforlanguage(iface, "MethodName", "ArgName", "This is the argument", "en")
 * can be retrieved by calling:
 *      - alljoyn_interfacedescription_getargdescriptionforlanguage(iface, "MethodName", "ArgName", description, maxLength, "en") OR
 *      - alljoyn_interfacedescription_member_getargannotation(member, "ArgName", "org.alljoyn.Bus.DocString.en", description, &size).
 *
 * @param[in] iface Interface on which to set argument description.
 * @param[in] member The name of the member.
 * @param[in] arg The name of the argument.
 * @param[in] description The argument description.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_INTERFACE_ACTIVATED If the interface has already been activated.
 *      - #ER_BUS_INTERFACE_NO_SUCH_MEMBER If the member was not found.
 *      - #ER_BUS_DESCRIPTION_ALREADY_EXISTS If the interface member argument already has a description.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_setargdescriptionforlanguage(
    alljoyn_interfacedescription iface, const char* member, const char* arg, const char* description, const char* languageTag);

/**
 * Get the introspection description for the argument "argname" of the interface member "member" in the given language.
 *
 * To obtain the description, the method searches for the best match of the given language tag
 * using the lookup algorithm in RFC 4647 section 3.4.
 * For example, if alljoyn_interfacedescription_getargdescriptionforlanguage(iface, "MethodName", "ArgName", description, maxLength, "en-US")
 * is called, the method will:
 *       - Search for a description with the same language tag ("en-US"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Search for a description with a less specific language tag ("en"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Write an empty string to the description argument and return 0.
 *
 * The method will also provide descriptions which have been set as description annotations
 * (set by calling alljoyn_interfacedescription_addargannotation() with the annotation name set to
 * "org.alljoyn.Bus.DocString" plus the desired language tag, e.g., "org.alljoyn.Bus.DocString.en").
 *
 * @param[in] iface Interface to query.
 * @param[in] member The name of the member.
 * @param[in] arg The name of the argument.
 * @param[out] description The description.
 * @param[in] maxLanguageLength Maximum number of characters to be written.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 * @return The number of characters written, not including the terminating null-character (0 if no description available).
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getargdescriptionforlanguage(
    alljoyn_interfacedescription iface, const char* member, const char* arg, char* description, size_t maxLanguageLength, const char* languageTag);

/**
 * Set the description for the property of this interface.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use alljoyn_interfacedescription_setpropertydescriptionforlanguage() instead.
 *
 * @param[in] iface Interface on which to set property description.
 * @param[in] name The name of the property.
 * @param[in] description The introspection description. Call alljoyn_interfacedescription_setdescriptionlanguage() to specify description language.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_INTERFACE_ACTIVATED If the interface has already been activated.
 *      - #ER_BUS_NO_SUCH_PROPERTY If the property was not found.
 */
QCC_DEPRECATED_ON(
    extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_setpropertydescription(alljoyn_interfacedescription iface, const char* name, const char* description),
    16.10);

/**
 * Set the description for the property of this interface in the given language.
 *
 * The set description can be retrieved by calling alljoyn_interfacedescription_getpropertydescriptionforlanguage()
 * OR alljoyn_interfacedescription_getpropertyannotation() for an "org.alljoyn.Bus.DocString" annotation
 * with the desired language tag (e.g., "org.alljoyn.Bus.DocString.en").
 * For example, a description set by calling
 * alljoyn_interfacedescription_setpropertydescriptionforlanguage(iface, "PropertyName", "This is the property", "en")
 * can be retrieved by calling:
 *      - alljoyn_interfacedescription_getpropertydescriptionforlanguage(iface, "PropertyName", description, maxLength, "en") OR
 *      - alljoyn_interfacedescription_getpropertyannotation(iface, "PropertyName", "org.alljoyn.Bus.DocString.en", description, &size).
 *
 * @param[in] iface Interface on which to set property description.
 * @param[in] name The name of the property.
 * @param[in] description The introspection description.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_INTERFACE_ACTIVATED If the interface has already been activated.
 *      - #ER_BUS_NO_SUCH_PROPERTY If the property was not found.
 *      - #ER_BUS_DESCRIPTION_ALREADY_EXISTS If the interface property already has a description.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_setpropertydescriptionforlanguage(
    alljoyn_interfacedescription iface, const char* name, const char* description, const char* languageTag);

/**
 * Get the introspection description for the property "property" in the given language.
 *
 * To obtain the description, the method searches for the best match of the given language tag
 * using the lookup algorithm in RFC 4647 section 3.4.
 * For example, if alljoyn_interfacedescription_getpropertydescriptionforlanguage(iface, "PropertyName", description, maxLength, "en-US")
 * is called, the method will:
 *       - Search for a description with the same language tag ("en-US"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Search for a description with a less specific language tag ("en"), write that description
 *         to the description argument and return its length if such a description is found; else:
 *       - Write an empty string to the description argument and return 0.
 *
 * The method will also provide descriptions which have been set as description annotations
 * (set by calling alljoyn_interfacedescription_addpropertyannotation() with the annotation name set to
 * "org.alljoyn.Bus.DocString" plus the desired language tag, e.g., "org.alljoyn.Bus.DocString.en").
 *
 * @param[in] iface Interface to query.
 * @param[in] property The name of the property.
 * @param[out] description The description.
 * @param[in] maxLanguageLength Maximum number of characters to be written.
 * @param[in] languageTag The language of the description (language tag as defined in RFC 5646, e.g., "en-US").
 * @return The number of characters written, not including the terminating null-character (0 if no description available).
 */
extern AJ_API size_t AJ_CALL alljoyn_interfacedescription_getpropertydescriptionforlanguage(
    alljoyn_interfacedescription iface, const char* property, char* description, size_t maxLanguageLength, const char* languageTag);

/**
 * Set the translation callback that provides this interface's description in multiple languages.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use language-aware accessors instead
 * (e.g., alljoyn_interfacedescription_setdescriptionforlanguage()).
 *
 * @param[in] iface Interface on which to set description translation callback.
 * @param[in] translationCallback The translation callback instance.
 */
QCC_DEPRECATED_ON(
    extern AJ_API void AJ_CALL alljoyn_interfacedescription_setdescriptiontranslationcallback(alljoyn_interfacedescription iface, alljoyn_interfacedescription_translation_callback_ptr translationCallback),
    16.10);

/**
 * Get the translation callback that provides this interface's description in multiple languages.
 *
 * @deprecated Using a single description and an optional translator for interface descriptions
 * has been deprecated, please use language-aware accessors instead
 * (e.g., alljoyn_interfacedescription_setdescriptionforlanguage()).
 *
 * @param[in] iface Interface to query.
 *
 * @return The translation callback instance.
 */
QCC_DEPRECATED_ON(
    extern AJ_API alljoyn_interfacedescription_translation_callback_ptr AJ_CALL alljoyn_interfacedescription_getdescriptiontranslationcallback(const alljoyn_interfacedescription iface),
    16.10);

/**
 * Determine whether this interface has at least one description on an element.
 *
 * @param[in] iface Interface to query.
 *
 * @return True if this interface has at least one description.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_hasdescription(const alljoyn_interfacedescription iface);

/**
 * Add an annotation to an existing argument.
 *
 * @param[in] iface Interface on which to add argument annotation.
 * @param[in] member Name of member.
 * @param[in] argName Name of the argument.
 * @param[in] name Name of annotation.
 * @param[in] value Value for the annotation.
 *
 * @return
 *      - #ER_OK if successful.
 *      - #ER_BUS_ANNOTATION_ALREADY_EXISTS if annotation already exists.
 */
extern AJ_API QStatus AJ_CALL alljoyn_interfacedescription_addargannotation(alljoyn_interfacedescription iface, const char* member, const char* argName, const char* name, const char* value);

/**
 * Get annotation from an existing member argument.
 *
 * @param[in] iface Interface to query.
 * @param[in] member Name of member.
 * @param[in] argName Name of the argument.
 * @param[in] name Name of annotation.
 * @param[out] value The value of the annotation.
 * @param[in,out] value_size The size of the value string. If value == NULL, this will return the size of the value string plus nul character.
 * @return
 *      - QCC_TRUE if found.
 *      - QCC_FALSE if annotation not found.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_getmemberargannotation(const alljoyn_interfacedescription iface, const char* member, const char* argName, const char* name, char* value, size_t* value_size);

/**
 * Equality operation.
 *
 * @param one   Interface to compare to other
 * @param other Interface to compare to one
 *
 * @return QCC_TRUE if one == other
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_eql(const alljoyn_interfacedescription one,
                                                                const alljoyn_interfacedescription other);

/**
 * Equality operation.
 *
 * @param one   alljoyn_interfacedescription_member to compare to other
 * @param other alljoyn_interfacedescription_member to compare to one
 *
 * @return QCC_TRUE if one == other
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_member_eql(const alljoyn_interfacedescription_member one,
                                                                       const alljoyn_interfacedescription_member other);

/**
 * Equality operation.
 *
 * @param one   alljoyn_interfacedescription_property to compare to other
 * @param other alljoyn_interfacedescription_property to compare to one
 *
 * @return QCC_TRUE if one == other
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_interfacedescription_property_eql(const alljoyn_interfacedescription_property one,
                                                                         const alljoyn_interfacedescription_property other);

#ifdef __cplusplus
} /* extern "C" */
#endif

#undef QCC_MODULE
#endif
