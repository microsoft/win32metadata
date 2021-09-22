/**
 * @file
 * This file defines a class for parsing and generating message bus messages
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
#ifndef _ALLJOYN_C_MESSAGE_H
#define _ALLJOYN_C_MESSAGE_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/MsgArg.h>
#include <alljoyn_c/Session.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_message for parsing and generating message bus messages
 */
typedef struct _alljoyn_message_handle*                     alljoyn_message;
/// @cond ALLJOYN_DEV
#ifndef _ALLJOYN_OPAQUE_BUSATTACHMENT_
#define _ALLJOYN_OPAQUE_BUSATTACHMENT_
/// @endcond
/**
 * alljoyn_busattachment is the top level object responsible for connecting to and
 * managing an AllJoyn message bus
 */
typedef struct _alljoyn_busattachment_handle*               alljoyn_busattachment;
/// @cond ALLJOYN_DEV
#endif
/// @endcond

/** @name Endianness indicators */
// @{
/** indicates the bus is little endian */
static const uint8_t ALLJOYN_LITTLE_ENDIAN = 'l';
/** indicates the bus is big endian */
static const uint8_t ALLJOYN_BIG_ENDIAN    = 'B';
// @}

/** @name Flag types */
/* @{ */
/** No reply is expected */
#define ALLJOYN_MESSAGE_FLAG_NO_REPLY_EXPECTED  0x01
/** Auto start the service */
#define ALLJOYN_MESSAGE_FLAG_AUTO_START         0x02
/** Allow messages from remote hosts (valid only in Hello message) */
#define ALLJOYN_MESSAGE_FLAG_ALLOW_REMOTE_MSG   0x04
/** Sessionless message */
#define ALLJOYN_MESSAGE_FLAG_SESSIONLESS        0x10
/** Global (bus-to-bus) broadcast */
#define ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST   0x20
/**
 * Header is compressed
 *
 * @deprecated March 2015 for 15.04 release
 */
#define ALLJOYN_MESSAGE_FLAG_COMPRESSED         (attempted_use_of_deprecated_definition = 0x40)
/** Body is encrypted */
#define ALLJOYN_MESSAGE_FLAG_ENCRYPTED          0x80
/* @} */

/**
 * The default timeout for method calls
 */
static const uint32_t ALLJOYN_MESSAGE_DEFAULT_TIMEOUT       = 25000;

/** Message types */
typedef enum {
    ALLJOYN_MESSAGE_INVALID     = 0, ///< an invalid message type
    ALLJOYN_MESSAGE_METHOD_CALL = 1, ///< a method call message type
    ALLJOYN_MESSAGE_METHOD_RET  = 2, ///< a method return message type
    ALLJOYN_MESSAGE_ERROR       = 3, ///< an error message type
    ALLJOYN_MESSAGE_SIGNAL      = 4  ///< a signal message type
} alljoyn_messagetype;

/**
 * Create an alljoyn_message object.
 *
 * @param bus  The alljoyn_busattachment that this alljoyn_message is sent or received on.
 *
 * @return the allocated alljoyn_message
 */
extern AJ_API alljoyn_message AJ_CALL alljoyn_message_create(alljoyn_busattachment bus);

/**
 * Destroy an alljoyn_message object.
 *
 * @param msg The alljoyn_message to destroy
 */
extern AJ_API void AJ_CALL alljoyn_message_destroy(alljoyn_message msg);

/**
 * Determine if message is a broadcast signal.
 *
 * @param msg  alljoyn_message we wish to determine if it is a broadcast signal.
 *
 * @return  Return true if this is a broadcast signal.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_message_isbroadcastsignal(alljoyn_message msg);

/**
 * Messages broadcast to all devices are global broadcast messages.
 *
 * @param msg  alljoyn_message we wish to determine if it is a global broadcast signal.
 *
 * @return  Return true if this is a global broadcast message.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_message_isglobalbroadcast(alljoyn_message msg);

/**
 * Messages sent without sessions are sessionless.
 *
 * @param msg  alljoyn_message we wish to determine if it is a sessionless signal.
 *
 * @return  Return true if this is a sessionless message.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_message_issessionless(alljoyn_message msg);

/**
 * Returns the flags for the message.
 *
 * @param msg  alljoyn_message we wish to get the flags from.
 *
 * @return flags for the message
 *
 * @see flag types in Message.h file
 */
extern AJ_API uint8_t AJ_CALL alljoyn_message_getflags(alljoyn_message msg);

/**
 * Return true if message's TTL header indicates that it is expired
 *
 * @param msg  alljoyn_message we are checking the TTL header for expiration.
 *
 * @param[out] tillExpireMS  Written with number of milliseconds before message expires if non-null
 *                           If message never expires value is set to the maximum uint32_t value.
 *
 * @return Returns true if the message's TTL header indicates that is has expired.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_message_isexpired(alljoyn_message msg, uint32_t* tillExpireMS);

/**
 * Determine if the message is marked as unreliable. Unreliable messages have a non-zero
 * time-to-live and may be silently discarded.
 *
 * @param msg alljoyn_message being checked to see if it is marked as unrliable
 *
 * @return  Returns true if the message is unreliable, that is, has a non-zero time-to-live.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_message_isunreliable(alljoyn_message msg);

/**
 * Determine if the message was encrypted.
 *
 * @param msg alljoyn_message being checked to see if it was encrypted
 *
 * @return  Returns true if the message was encrypted.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_message_isencrypted(alljoyn_message msg);

/**
 * Get the name of the authentication mechanism that was used to generate the encryption key if
 * the message is encrypted.
 *
 * @param msg alljoyn_message the authentication mechanism is being obtained from
 *
 * @return  the name of an authentication mechanism or an empty string.
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getauthmechanism(alljoyn_message msg);

/**
 * Return the type of the message
 *
 * @param msg alljoyn_message being read for its alljoyn_messagetype
 *
 * @return message type
 */
extern AJ_API alljoyn_messagetype AJ_CALL alljoyn_message_gettype(alljoyn_message msg);

/**
 * Return the arguments for this message.
 *
 * @param[in]  msg     The alljoyn_message from which to extract the arguments.
 * @param[out] numArgs The number of arguments
 * @param[out] args    Returns the arguments
 */
extern AJ_API void AJ_CALL alljoyn_message_getargs(alljoyn_message msg, size_t* numArgs, alljoyn_msgarg* args);

/**
 * Return a specific argument.
 *
 * @param msg   The alljoyn_message from which to extract an argument.
 * @param argN  The index of the argument to get.
 *
 * @return
 *      - The argument
 *      - NULL if unmarshal failed or there is not such argument.
 */
extern AJ_API const alljoyn_msgarg AJ_CALL alljoyn_message_getarg(alljoyn_message msg, size_t argN);

/**
 * Unpack and return the arguments for this message. This function uses the
 * functionality from alljoyn_msgarg_get() see MsgArg.h for documentation.
 *
 * @param[in]  msg     The alljoyn_message from which to extract the arguments.
 * @param[in]  signature  The signature to match against the message arguments.
 * @param[out] ...        Pointers to return references to the unpacked values.
 * @return  ER_OK if successful.
 */
extern AJ_API QStatus CDECL_CALL alljoyn_message_parseargs(alljoyn_message msg, const char* signature, ...);

/**
 * Accessor function to get serial number for the message. Usually only important for
 * #ALLJOYN_MESSAGE_METHOD_CALL for matching up the reply to the call.
 *
 * @param[in]  msg     The alljoyn_message from which to extract the serial.
 *
 * @return the serial number of the %Message
 */
extern AJ_API uint32_t AJ_CALL alljoyn_message_getcallserial(alljoyn_message msg);

/**
 * Accessor function to get the signature for this message
 *
 * @param[in] msg  The alljoyn_message from which to extract the signature.
 *
 * @return
 *      - The AllJoyn SIGNATURE string stored in the AllJoyn header field
 *      - An empty string if unable to find the AllJoyn signature
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getsignature(alljoyn_message msg);

/**
 * Accessor function to get the object path for this message
 *
 * @param[in] msg  The alljoyn_message from which to extract the object path.
 *
 * @return
 *      - The AllJoyn object path string stored in the AllJoyn header field
 *      - An empty string if unable to find the AllJoyn object path
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getobjectpath(alljoyn_message msg);

/**
 * Accessor function to get the interface for this message
 *
 * @param[in] msg  The alljoyn_message from which to extract the interface name.
 *
 * @return
 *      - The AllJoyn interface string stored in the AllJoyn header field
 *      - An empty string if unable to find the interface
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getinterface(alljoyn_message msg);

/**
 * Accessor function to get the member (method/signal) name for this message
 *
 * @param[in] msg  The alljoyn_message from which to extract the member name.
 *
 * @return
 *      - The AllJoyn member (method/signal) name string stored in the AllJoyn header field
 *      - An empty string if unable to find the member name
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getmembername(alljoyn_message msg);

/**
 * Accessor function to get the reply serial number for the message. Only meaningful for #ALLJOYN_MESSAGE_METHOD_RET
 *
 * @param[in] msg  The alljoyn_message from which to extract the reply serial.
 *
 * @return
 *      - The serial number for the message stored in the AllJoyn header field
 *      - Zero if unable to find the serial number. Note that 0 is an invalid serial number.
 */
extern AJ_API uint32_t AJ_CALL alljoyn_message_getreplyserial(alljoyn_message msg);

/**
 * Accessor function to get the sender for this message.
 *
 * @param[in] msg  The alljoyn_message from which to extract the sender information.
 *
 * @return
 *      - The senders well-known name string stored in the AllJoyn header field.
 *      - An empty string if the message did not specify a sender.
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getsender(alljoyn_message msg);

/**
 * Get the unique name of the endpoint that the message was received on.
 *
 * @param[in] msg  The alljoyn_message from which to extract the endpoint information.
 *
 * @return
 *     - The unique name of the endpoint that the message was received on.
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getreceiveendpointname(alljoyn_message msg);

/**
 * Accessor function to get the destination for this message
 *
 * @param[in] msg  The alljoyn_message from which to extract the destination information.
 *
 * @return
 *      - The message destination string stored in the AllJoyn header field.
 *      - An empty string if unable to find the message destination.
 */
extern AJ_API const char* AJ_CALL alljoyn_message_getdestination(alljoyn_message msg);

/**
 * Accessor function to get the compression token for the message.
 *
 * @param[in] msg  The alljoyn_message from which to extract the compression token information.
 *
 * @return
 *      - 0 'zero' if there is no compression token.
 *
 * @deprecated Header compression was deprecated in March 2015 for 15.04
 * release
 */
QCC_DEPRECATED(extern AJ_API uint32_t AJ_CALL alljoyn_message_getcompressiontoken(alljoyn_message msg));

/**
 * Accessor function to get the session id for the message.
 *
 * @param[in] msg  The alljoyn_message from which to extract the session id information.
 * @return
 *      - Session id for the message
 *      - 0 'zero' if sender did not specify a session
 */
extern AJ_API alljoyn_sessionid AJ_CALL alljoyn_message_getsessionid(alljoyn_message msg);

/**
 * If the message is an error message returns the error name and optionally the error message string
 *
 * @param[in] msg  The alljoyn_message from which to extract the error name information.
 * @param[out] errorMessage
 *                      - Return the error message string stored
 *                      - leave errorMessage unchanged if error message string not found
 * @param[in,out] errorMessage_size size of the errorMessage string (including the terminating nul byte)
 *                                  if errorMessage == NULL this will be changed to the
 *                                  size of the string so a buffer can be allocated to
 *                                  hold the string.
 *
 * @return
 *      - If error detected return error name stored in the AllJoyn header field
 *      - NULL if error not detected
 */
extern AJ_API const char* AJ_CALL alljoyn_message_geterrorname(alljoyn_message msg, char* errorMessage, size_t* errorMessage_size);

/**
 * Returns an XML string representation of the message
 *
 * @param[in]  msg  The alljoyn_message which to return an XML representation of.
 * @param[out] str  The character string that will hold the XML string
 *                  representation of the alljoyn_message
 * @param[in]  buf  The size of the char* array that will hold the string
 *
 * @return  The number of characters (including the terminating nul byte) which
 *          would have been written to the final string if enough space
 *          available.  Thus returning a value of buf or larger means the output
 *          was truncated.
 *
 */
extern AJ_API size_t AJ_CALL alljoyn_message_tostring(alljoyn_message msg, char* str, size_t buf);

/**
 * Returns a string that provides a brief description of the message
 *
 * @param[in] msg  The alljoyn_message which to return an XML representation of.
 * @param[out] str The character string that will hold the description of the
 *                 message
 * @param[in]  buf  The size of the char* array that will hold the string
 *
 * @return  The number of characters (including the terminating nul byte) which
 *          would have been written to the final string if enough space
 *          available.  Thus returning a value of buf or larger means the output
 *          was truncated.
 */
extern AJ_API size_t AJ_CALL alljoyn_message_description(alljoyn_message msg, char* str, size_t buf);

/**
 * Returns the timestamp (in milliseconds) for this message. If the message header contained a
 * timestamp this is the estimated timestamp for when the message was sent by the remote device,
 * otherwise it is the timestamp for when the message was unmarshaled. Note that the timestamp
 * is always relative to local time.
 *
 * @param[in] msg  The alljoyn_message from which to extract the timestamp information.
 *
 * @return The timestamp for this message.
 */
extern AJ_API uint32_t AJ_CALL alljoyn_message_gettimestamp(alljoyn_message msg);

/**
 * Equality operation.
 *
 * @param one   alljoyn_interfacedescription_member to compare to other
 * @param other alljoyn_interfacedescription_member to compare to one
 *
 * @return QCC_TRUE if one == other
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_message_eql(const alljoyn_message one, const alljoyn_message other);

/**
 * Set the endianness for outgoing messages. This is mainly for testing purposes.
 *
 * @param endian  Either ALLJOYN_LITTLE_ENDIAN or ALLJOYN_BIG_ENDIAN. Any other value
 *                sets the endianness to the native endianness for this platform.
 *
 *
 */
extern AJ_API void AJ_CALL alljoyn_message_setendianess(const char endian);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif //_ALLJOYN_C_MESSAGE_H
