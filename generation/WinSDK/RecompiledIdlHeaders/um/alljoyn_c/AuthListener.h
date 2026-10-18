/**
 * @file
 * This file defines the alljoyn_authlistener and related functions that provides
 * the interface between authentication mechansisms and applications.
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
#ifndef _ALLJOYN_C_AUTHLISTENER_H
#define _ALLJOYN_C_AUTHLISTENER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Message.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * alljoyn_authlistener allows authentication mechanisms to interact with the user or application.
 */
typedef struct _alljoyn_authlistener_handle*                alljoyn_authlistener;
/**
 * Generic struct for describing different authentication credentials.
 */
typedef struct _alljoyn_credentials_handle*                 alljoyn_credentials;

/**
 * @name Credential indication Bitmasks
 *  Bitmasks used to indicated what type of credentials are being used.
 */
// @{
static const uint16_t ALLJOYN_CRED_PASSWORD     = 0x0001; /**< Bit 0 indicates credentials include a password */
static const uint16_t ALLJOYN_CRED_USER_NAME    = 0x0002; /**< Bit 1 indicates credentials include a user name */
static const uint16_t ALLJOYN_CRED_CERT_CHAIN   = 0x0004; /**< Bit 2 indicates credentials include a chain of PEM-encoded X509 certificates */
static const uint16_t ALLJOYN_CRED_PRIVATE_KEY  = 0x0008; /**< Bit 3 indicates credentials include a PEM-encoded private key */
static const uint16_t ALLJOYN_CRED_LOGON_ENTRY  = 0x0010; /**< Bit 4 indicates credentials include a logon entry that can be used to logon a remote user */
static const uint16_t ALLJOYN_CRED_EXPIRATION   = 0x0020; /**< Bit 5 indicates credentials include an expiration time */
// @}
/**
 * @name Credential request values
 * These values are only used in a credential request
 */
// @{
static const uint16_t ALLJOYN_CRED_NEW_PASSWORD = 0x1001; /**< Indicates the credential request is for a newly created password */
static const uint16_t ALLJOYN_CRED_ONE_TIME_PWD = 0x2001; /**< Indicates the credential request is for a one time use password */
// @}

/**
 * Type for the RequestCredentials callback.
 *
 * Authentication mechanism requests user credentials. If the user name is not an empty string
 * the request is for credentials for that specific user. A count allows the listener to decide
 * whether to allow or reject multiple authentication attempts to the same peer.
 *
 * An implementation must provide an alljoyn_authlistener_callbacks or
 * an alljoyn_authlistenerasync_callbacks but not both.
 *
 * @param context        The context pointer passed into the alljoyn_authlistener_create function
 * @param authMechanism  The name of the authentication mechanism issuing the request.
 * @param peerName       The name of the remote peer being authenticated.  On the initiating
 *                       side this will be a well-known-name for the remote peer. On the
 *                       accepting side this will be the unique bus name for the remote peer.
 * @param authCount      Count (starting at 1) of the number of authentication request attempts made.
 * @param userName       The user name for the credentials being requested.
 * @param credMask       A bit mask identifying the credentials being requested. The application
 *                       may return none, some or all of the requested credentials.
 * @param[out] credentials    The credentials returned.
 *
 * @return  The caller should return true if the request is being accepted or false if the
 *          requests is being rejected. If the request is rejected the authentication is
 *          complete.
 */
typedef QCC_BOOL (AJ_CALL * alljoyn_authlistener_requestcredentials_ptr)(const void* context, const char* authMechanism, const char* peerName, uint16_t authCount,
                                                                         const char* userName, uint16_t credMask, alljoyn_credentials credentials);

/**
 * Authentication mechanism asynchronous request for credentials. If the user name is not an empty string
 * the request is for credentials for that specific user. A count allows the listener to decide
 * whether to allow or reject multiple authentication attempts to the same peer.
 *
 * An implementation must provide an alljoyn_authlistener_callbacks or
 * an alljoyn_authlistenerasync_callbacks but not both.
 *
 * @param context        The context pointer passed into the alljoyn_authlistenerasync_create function
 * @param listener       The alljoyn_authlistener used to call this function pointer this should be used
 *                       when calling alljoyn_authlistener_requestcredentialsresponse.
 * @param authMechanism  The name of the authentication mechanism issuing the request.
 * @param peerName       The name of the remote peer being authenticated.  On the initiating
 *                       side this will be a well-known-name for the remote peer. On the
 *                       accepting side this will be the unique bus name for the remote peer.
 * @param authCount      Count (starting at 1) of the number of authentication request attempts made.
 * @param userName       The user name for the credentials being requested.
 * @param credMask       A bit mask identifying the credentials being requested.
 * @param authContext    Callback context for associating the request with the returned credentials.
 *
 * @return  Return
 *      - ER_OK if the request is handled.
 *      - ER_NOT_IMPLEMENTED if implementation not found (default)
 */
typedef QStatus (AJ_CALL * alljoyn_authlistener_requestcredentialsasync_ptr)(const void* context, alljoyn_authlistener listener,
                                                                             const char* authMechanism, const char* peerName, uint16_t authCount,
                                                                             const char* userName, uint16_t credMask, void* authContext);

/**
 * Respond to a call to alljoyn_authlistener_requestcredentialsasync_ptr.
 *
 * @param listener      The alljoyn_authlistener responding to the authlistener_requestcredentialsasync
 * @param authContext    Context that was passed in the call out to alljoyn_authlistener_requestcredentialsasync_ptr.
 * @param accept         Returns true to accept the credentials request or false to reject it.
 * @param credentials    The credentials being returned if accept is true.
 *
 * @return   Returns ER_OK if the credential verification response was expected. Returns an error status if
 *           the credentials verification response was not expected.
 */
extern AJ_API QStatus AJ_CALL alljoyn_authlistener_requestcredentialsresponse(alljoyn_authlistener listener, void* authContext, QCC_BOOL accept, alljoyn_credentials credentials);

/**
 * Type for the VerifyCredentials callback.
 *
 * Authentication mechanism requests verification of credentials from a remote peer.
 *
 * @param context        The context pointer passed into the alljoyn_authlistener_create function
 * @param authMechanism  The name of the authentication mechanism issuing the request.
 * @param peerName       The name of the remote peer being authenticated.  On the initiating
 *                       side this will be a well-known-name for the remote peer. On the
 *                       accepting side this will be the unique bus name for the remote peer.
 * @param credentials    The credentials to be verified.
 *
 * @return  The listener should return true if the credentials are acceptable or false if the
 *          credentials are being rejected.
 */
typedef QCC_BOOL (AJ_CALL * alljoyn_authlistener_verifycredentials_ptr)(const void* context, const char* authMechanism, const char* peerName,
                                                                        const alljoyn_credentials credentials);

/**
 * Authentication mechanism asynchronous request for verification of credentials from a remote peer.
 *
 * @param context        The context pointer passed into the alljoyn_authlistenerasync_create function.
 * @param listener       The alljoyn_authlistener used to call this function pointer this should be used
 *                       when calling alljoyn_authlistener_verifycredentialsresponse.
 * @param authMechanism  The name of the authentication mechanism issuing the request.
 * @param peerName       The name of the remote peer being authenticated.  On the initiating
 *                       side this will be a well-known-name for the remote peer. On the
 *                       accepting side this will be the unique bus name for the remote peer.
 * @param credentials    The credentials to be verified.
 * @param authContext    Callback context for associating the request with the verification response.
 *
 * @return  Return
 *  - ER_OK if the request is handled.
 *  - ER_NOT_IMPLEMENTED (default)
 */
typedef QStatus (AJ_CALL * alljoyn_authlistener_verifycredentialsasync_ptr)(const void* context, alljoyn_authlistener listener,
                                                                            const char* authMechanism, const char* peerName, const alljoyn_credentials credentials, void* authContext);

/**
 * Respond to a call to alljoyn_authlistener_verifycredentialsasync_ptr.
 *
 * @param listener      The alljoyn_authlistener responding to the authlistener_verifycredentialsasync.
 * @param authContext    Context that was passed in the call out to alljoyn_authlistener_verifycredentialsasync_ptr.
 * @param accept         Returns true to accept the credentials or false to reject it.
 *
 * @return   Returns ER_OK if the credential verification response was expected. Returns an error status if
 *           the credentials verification response was not expected.
 */
extern AJ_API QStatus AJ_CALL alljoyn_authlistener_verifycredentialsresponse(alljoyn_authlistener listener, void* authContext, QCC_BOOL accept);
/**
 * Type for the SecurityViolation callback.
 *
 * Optional function that if implemented allows an application to monitor security violations. This
 * function is called when an attempt to decrypt an encrypted messages failed or when an unencrypted
 * message was received on an interface that requires encryption. The message contains only
 * header information.
 *
 * @param context  The context pointer passed into the alljoyn_authlistener_create function
 * @param status   A status code indicating the type of security violation.
 * @param msg      The message that cause the security violation.
 */
typedef void (AJ_CALL * alljoyn_authlistener_securityviolation_ptr)(const void* context, QStatus status, const alljoyn_message msg);

/**
 * Type for the AuthenticationComplete callback.
 *
 * Reports successful or unsuccessful completion of authentication.
 *
 * @param authMechanism  The name of the authentication mechanism that was used or an empty
 *                       string if the authentication failed.
 * @param peerName       The name of the remote peer being authenticated.  On the initiating
 *                       side this will be a well-known-name for the remote peer. On the
 *                       accepting side this will be the unique bus name for the remote peer.
 * @param success        true if the authentication was successful, otherwise false.
 */
typedef void (AJ_CALL * alljoyn_authlistener_authenticationcomplete_ptr)(const void* context, const char* authMechanism, const char* peerName, QCC_BOOL success);

/**
 * Structure used during alljoyn_authlistener_create to provide callbacks into C.
 * An implementation must provide alljoyn_authlistener_requestcredentials_ptr
 * and alljoyn_authlistener_authenticationcomplete_ptr. Other values can be set
 * to NULL if they are not needed.
 */
typedef struct {
    /**
     * Authentication mechanism requests user credentials.
     */
    alljoyn_authlistener_requestcredentials_ptr request_credentials;
    /**
     * Authentication mechanism requests verification of credentials from a remote peer.
     */
    alljoyn_authlistener_verifycredentials_ptr verify_credentials;
    /**
     * Optional function that if implemented allows an application to monitor security violations.
     */
    alljoyn_authlistener_securityviolation_ptr security_violation;
    /**
     * Reports successful or unsuccessful completion of authentication.
     */
    alljoyn_authlistener_authenticationcomplete_ptr authentication_complete;
} alljoyn_authlistener_callbacks;

/**
 * Structure used during alljoyn_authlistenerasync_create to provide callbacks into C.
 * An implementation must provide alljoyn_authlistener_requestcredentialsasync_ptr
 * and alljoyn_authlistener_authenticationcomplete_ptr. Other values can be set
 * to NULL if they are not needed.
 */
typedef struct {
    /**
     * Authentication mechanism asynchronous request for credentials.
     */
    alljoyn_authlistener_requestcredentialsasync_ptr request_credentials;
    /**
     * Authentication mechanism asynchronous request for verification of credentials from a remote peer
     */
    alljoyn_authlistener_verifycredentialsasync_ptr verify_credentials;
    /**
     * Optional function that if implemented allows an application to monitor security violations.
     */
    alljoyn_authlistener_securityviolation_ptr security_violation;
    /**
     * Reports successful or unsuccessful completion of authentication.
     */
    alljoyn_authlistener_authenticationcomplete_ptr authentication_complete;

} alljoyn_authlistenerasync_callbacks;

/**
 * Create an alljoyn_authlistener which will trigger the provided callbacks, passing along the context.
 * If a callback is not provided the listener will default to the below behavior.
 *
 * NOTE: The default request_credentials behavior should NOT be used for ECDHE_ECDSA authentication
 * for an application in CLAIMABLE state, as it does not provide any credentials to verify and always
 * returns true.
 *
 * The callbacks' default behavior:
 *   request_credentials - depends on the authentication method:
 *     - ECDHE_NULL  - The callback returns true.
 *     - ECDHE_SPEKE - Provides the password set using alljoyn_authlistener_setpassword and returns true,
 *                     unless the number of authentication attempts is greater than 10.
 *                     For no set password returns false.
 *     - ECDHE_ECDSA - The callback returns true without providing any credential.
 *   verify_credentials - Returns true.
 *   security_violation - No operation.
 *   authentication_complete - No operation.
 *
 * @param callbacks Callbacks to trigger for associated events.
 * @param context   Context to pass to callback functions
 *
 * @return Handle to newly allocated alljoyn_authlistener.
 */
extern AJ_API alljoyn_authlistener AJ_CALL alljoyn_authlistener_create(const alljoyn_authlistener_callbacks* callbacks, const void* context);

/**
 * Create an alljoyn_authlistener which will trigger the provided callbacks, passing along the provided context.
 *
 * @param callbacks Callbacks to trigger for associated events.
 * @param context   Context to pass to callback functions
 *
 * @return Handle to newly allocated alljoyn_authlistener.
 */
extern AJ_API alljoyn_authlistener AJ_CALL alljoyn_authlistenerasync_create(const alljoyn_authlistenerasync_callbacks* callbacks, const void* context);

/**
 * Destroy an alljoyn_authlistener.
 *
 * @param listener alljoyn_authlistener to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_authlistener_destroy(alljoyn_authlistener listener);

/**
 * Destroy an alljoyn_authlistener.
 *
 * @param listener alljoyn_authlistener to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_authlistenerasync_destroy(alljoyn_authlistener listener);

/**
 * Sets a shared secret to be returned by the listener during ECDHE_SPEKE authentication.
 *
 * @param listener          alljoyn_authlistener for which the secret should be set.
 * @param sharedSecret      An array containing the shared secret. Must be at least 4 bytes long.
 * @param sharedSecretSize  The shared secret's size in bytes.
 *
 * @return true
 *          - #ER_OK        If successful.
 *          - #ER_BAD_ARG_2 If the secret is shorter than 4 bytes.
 */
extern AJ_API QStatus AJ_CALL alljoyn_authlistener_setsharedsecret(alljoyn_authlistener listener, const uint8_t* sharedSecret, size_t sharedSecretSize);

/**
 * Create credentials
 *
 * @return Newly created credentials.
 */
extern AJ_API alljoyn_credentials AJ_CALL alljoyn_credentials_create();

/**
 * Destroy credentials
 *
 * @param cred Credentials to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_destroy(alljoyn_credentials cred);

/**
 * Tests if one or more credentials are set.
 *
 * @param cred   The credentials to test.
 * @param creds  A logical or of the credential bit values.
 * @return true if the credentials are set.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_credentials_isset(const alljoyn_credentials cred, uint16_t creds);

/**
 * Sets a requested password.
 *
 * @param cred The credentials to set.
 * @param pwd  The password to set.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_setpassword(alljoyn_credentials cred, const char* pwd);

/**
 * Sets a requested user name.
 *
 * @param cred      The credentials to set.
 * @param userName  The user name to set.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_setusername(alljoyn_credentials cred, const char* userName);

/**
 * Sets a requested public key certificate chain. The certificates must be PEM encoded.
 *
 * @param cred       The credentials to set.
 * @param certChain  The certificate chain to set.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_setcertchain(alljoyn_credentials cred, const char* certChain);

/**
 * Sets a requested private key. The private key must be PEM encoded and may be encrypted. If
 * the private key is encrypted the passphrase required to decrypt it must also be supplied.
 *
 * @param cred The credentials to set.
 * @param pk   The private key to set.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_setprivatekey(alljoyn_credentials cred, const char* pk);

/**
 * Sets a logon entry. For example for the Secure Remote Password protocol in RFC 5054, a
 * logon entry encodes the N,g, s and v parameters. An SRP logon entry string has the form
 * N:g:s:v where N,g,s, and v are ASCII encoded hexadecimal strings and are separated by
 * colons.
 *
 * @param cred        The credentials to set.
 * @param logonEntry  The logon entry to set.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_setlogonentry(alljoyn_credentials cred, const char* logonEntry);

/**
 * Sets an expiration time in seconds relative to the current time for the credentials. This value is optional and
 * can be set on any response to a credentials request. After the specified expiration time has elapsed any secret
 * keys based on the provided credentials are invalidated and a new authentication exchange will be required. If an
 * expiration is not set the default expiration time for the requested authentication mechanism is used.
 *
 * @param cred        The credentials to set.
 * @param expiration  The expiration time in seconds.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_setexpiration(alljoyn_credentials cred, uint32_t expiration);

/**
 * Gets the password from this credentials instance.
 *
 * @param cred The credentials to query.
 * @return A password or an empty string.
 */
extern AJ_API const char* AJ_CALL alljoyn_credentials_getpassword(const alljoyn_credentials cred);

/**
 * Gets the user name from this credentials instance.
 *
 * @param cred The credentials to query.
 * @return A user name or an empty string.
 */
extern AJ_API const char* AJ_CALL alljoyn_credentials_getusername(const alljoyn_credentials cred);

/**
 * Gets the PEM encoded X509 certificate chain from this credentials instance.
 *
 * @param cred The credentials to query.
 * @return An X509 certificate chain or an empty string.
 */
extern AJ_API const char* AJ_CALL alljoyn_credentials_getcertchain(const alljoyn_credentials cred);

/**
 * Gets the PEM encoded private key from this credentials instance.
 *
 * @param cred The credentials to query.
 * @return An PEM encode private key or an empty string.
 */
extern AJ_API const char* AJ_CALL alljoyn_credentials_getprivateKey(const alljoyn_credentials cred);

/**
 * Gets a logon entry.
 *
 * @param cred The credentials to query.
 * @return An encoded logon entry or an empty string.
 */
extern AJ_API const char* AJ_CALL alljoyn_credentials_getlogonentry(const alljoyn_credentials cred);

/**
 * Get the expiration time in seconds if it is set.
 *
 * @param cred The credentials to query.
 * @return The expiration or the max 32 bit unsigned value if it was not set.
 */
extern AJ_API uint32_t AJ_CALL alljoyn_credentials_getexpiration(const alljoyn_credentials cred);

/**
 * Clear the credentials.
 *
 * @param cred The credentials to clear.
 */
extern AJ_API void AJ_CALL alljoyn_credentials_clear(alljoyn_credentials cred);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
