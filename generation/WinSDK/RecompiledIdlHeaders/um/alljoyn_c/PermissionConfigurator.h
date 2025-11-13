/**
 * @file
 * This file defines the alljoyn_permissionconfigurator and related functions.
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

#ifndef _ALLJOYN_C_PERMISSIONCONFIGURATOR_H
#define _ALLJOYN_C_PERMISSIONCONFIGURATOR_H

#include <alljoyn_c/AjAPI.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * alljoyn_permissionconfigurator is a handle which exposes Security 2.0 permission
 * management capabilities to the application.
 */
typedef struct _alljoyn_permissionconfigurator_handle* alljoyn_permissionconfigurator;

/**
 *  Enum defining the application's current state.
 */
typedef enum {
    NOT_CLAIMABLE,      /**< The application is not claimed and not accepting claim requests. */
    CLAIMABLE,          /**< The application is not claimed and is accepting claim requests. */
    CLAIMED,            /**< The application is claimed and can be configured. */
    NEED_UPDATE         /**< The application is claimed, but requires a configuration update (after a software upgrade). */
} alljoyn_applicationstate;

/**
 *  Bitmasks used to indicate possible ways to claim the app.
 */
typedef uint16_t alljoyn_claimcapabilities;
typedef enum {
    CAPABLE_ECDHE_NULL = 0x0001,
    CAPABLE_ECDHE_ECDSA = 0x0004,
    CAPABLE_ECDHE_SPEKE = 0x0008
} alljoyn_claimcapability_masks;

/**
 *  Bitmasks used to indicate password source.
 */
typedef uint16_t alljoyn_claimcapabilitiesadditionalinfo;
typedef enum {
    PASSWORD_GENERATED_BY_SECURITY_MANAGER = 0x0001,
    PASSWORD_GENERATED_BY_APPLICATION = 0x0002
} alljoyn_claimcapabilityadditionalinfo_masks;

/**
 * Get the default claim capabilities bitmask.
 *
 * @return alljoyn_claimcapabilities containing the default capability set.
 */
AJ_API alljoyn_claimcapabilities AJ_CALL alljoyn_permissionconfigurator_getdefaultclaimcapabilities();

/**
 * Struct used to return identifying information about a certificate.
 */
typedef struct {
    uint8_t* serial;                        /**< The certificate's serial number. */
    size_t serialLen;                       /**< The certificate's serial number length. */
    AJ_PSTR issuerPublicKey;                /**< The certificate issuer's public key in PEM format. */
    uint8_t* issuerAki;                     /**< The certificate issuer's AKI. */
    size_t issuerAkiLen;                    /**< The certificate issuer's AKI length. */
} alljoyn_certificateid;

/**
 * Struct used to return an array of alljoyn_certificateid.
 */
typedef struct {
    size_t count;                           /**< The number of elements in the certficateIds array. */
    alljoyn_certificateid* ids;             /**< An array of alljoyn_certificateid. */
} alljoyn_certificateidarray;

/**
 * Struct used to return an array of manifest XMLs.
 */
typedef struct {
    size_t count;                           /**< The number of elements in the xmls array. */
    AJ_PSTR* xmls;                          /**< An array of strings, each containing a signed manifest XML. */
} alljoyn_manifestarray;

/**
 * Retrieves the current application state.
 *
 * @param[in]   configurator    The queried alljoyn_permissionconfigurator.
 * @param[out]  state           Returned state.
 *
 * @return
 *          #ER_OK if successful.
 *          Other error status codes indicating a failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getapplicationstate(const alljoyn_permissionconfigurator configurator, alljoyn_applicationstate* state);

/**
 * Set the application state.  The state cannot be changed from CLAIMED to CLAIMABLE.
 *
 * @param[in]   configurator    The queried alljoyn_permissionconfigurator.
 * @param[in]   state           New state.
 *
 * @return
 *          #ER_OK if action is allowed.
 *          #ER_INVALID_APPLICATION_STATE if the state can't be changed.
 *          Other error status codes indicating a failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_setapplicationstate(alljoyn_permissionconfigurator configurator, alljoyn_applicationstate state);

/**
 * Get the application's public key.
 *
 * @param[in]   configurator        The queried alljoyn_permissionconfigurator.
 * @param[out]  publicKey           Pointer to receive the null-terminated C string with the PEM-encoded representation
 *                                  of the application's public key. On success, this string must be freed with a call
 *                                  to alljoyn_permissionconfigurator_publickey_destroy.
 *
 * @return
 *         #ER_OK if successful.
 *         Other error status codes indicating a failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getpublickey(alljoyn_permissionconfigurator configurator, AJ_PSTR* publicKey);

/**
 * Destroy a string returned by a call to alljoyn_permissionconfigurator_getpublickey.
 *
 * @param[in]   publicKey           String received from the call to alljoyn_permissionconfigurator_getpublickey.
 */
AJ_API void AJ_CALL alljoyn_permissionconfigurator_publickey_destroy(AJ_PSTR publicKey);

/**
 * Get the application's manifest template as XML.
 *
 * @param[in]   configurator        The queried alljoyn_permissionconfigurator.
 * @param[out]  manifestTemplateXml Pointer to receive null-terminated C string containing manifest template
 *                                  as XML. On success, this string must be freed using
 *                                  alljoyn_permissionconfigurator_manifesttemplate_destroy.
 *
 * @return
 *          #ER_OK if successful.
 *          Other error status codes indicating a failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getmanifesttemplate(alljoyn_permissionconfigurator configurator, AJ_PSTR* manifestTemplateXml);

/**
 * Destroy a string received from a call to alljoyn_permissionconfigurator_getmanifesttemplate.
 *
 * @param[in]   manifestTemplateXml String received from the call.
 *
 */
AJ_API void AJ_CALL alljoyn_permissionconfigurator_manifesttemplate_destroy(AJ_PSTR manifestTemplateXml);

/**
 * Set the application's manifest template from an XML.
 *
 * @param[in]   configurator        The queried alljoyn_permissionconfigurator.
 * @param[in]   manifestTemplateXml String containing the XML version of the manifest template.
 *
 * @return
 *          #ER_OK if successful.
 *          #ER_XML_MALFORMED if the XML is not in a valid manifest template format.
 *          Other error status codes indicating a failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_setmanifesttemplatefromxml(alljoyn_permissionconfigurator configurator, AJ_PCSTR manifestTemplateXml);

/**
 * Get the authentication mechanisms the application supports for the
 * claim process.
 *
 * @param[in]   configurator        The queried alljoyn_permissionconfigurator.
 * @param[out]  claimCapabilities   The authentication mechanisms the application supports.
 *
 * @return
 *          #ER_OK if successful.
 *          An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getclaimcapabilities(const alljoyn_permissionconfigurator configurator, alljoyn_claimcapabilities* claimCapabilities);

/**
 * Set the authentication mechanisms the application supports for the
 * claim process. It is a bit mask created by the bitwise OR of the
 * alljoyn_claimcapability_masks constants.
 *
 * @param[in]   configurator        The queried alljoyn_permissionconfigurator.
 * @param[in]   claimCapabilities   The authentication mechanisms the application supports.
 *
 * @return
 *          #ER_OK if successful.
 *          An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_setclaimcapabilities(alljoyn_permissionconfigurator configurator, alljoyn_claimcapabilities claimCapabilities);

/**
 * Get the additional information on the claim capabilities.
 *
 * @param[in]   configurator    The queried alljoyn_permissionconfigurator.
 * @param[out]  additionalInfo  The additional claim info.
 *
 * @return
 *          #ER_OK if successful.
 *          An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getclaimcapabilitiesadditionalinfo(const alljoyn_permissionconfigurator configurator, alljoyn_claimcapabilitiesadditionalinfo* additionalInfo);

/**
 * Set the additional information on the claim capabilities.
 * It is a bit mask, created by the bitwise OR of the
 * alljoyn_claimcapabilityadditionalinfo_masks constants.
 *
 * @param[in]   configurator    The queried alljoyn_permissionconfigurator.
 * @param[in]   additionalInfo  The additional info.
 *
 * @return
 *          #ER_OK if successful.
 *          An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_setclaimcapabilitiesadditionalinfo(alljoyn_permissionconfigurator configurator, alljoyn_claimcapabilitiesadditionalinfo additionalInfo);

/**
 * Reset the permission settings by removing the manifest all the
 * trust anchors, installed policy and certificates.
 *
 * @param[in]   configurator    The alljoyn_permissionconfigurator performing the reset.
 *
 * @return
 *          #ER_OK if successful.
 *          An error code otherwise.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_reset(alljoyn_permissionconfigurator configurator);

/**
 * Claims the application. The application is provided an identity certificate chain with
 * its own cert as the leaf. The application automatically installs the policy to
 * allow all communication from the provided admin group.
 * The application's manifests are installed as well. Peer security must first be enabled on the bus attachment.
 *
 * To prevent a potential security-critical race condition, before claiming a bus attachment with this method,
 * it is recommended to call alljoyn_busattachment_enablepersecurity on an unclaimed bus attachment with
 * "ALLJOYN_ECDHE_ECDSA" only in the authMechanisms parameter. The default claim capabilities do not allow
 * ALLJOYN_ECDHE_ECDSA for claiming, and this will guarantee a rogue security manager on the same bus can't
 * claim this bus attachment before this function is called. Do not set claim capabilities on a bus attachment
 * that will be claimed with this function.
 *
 * After the bus attachment is claimed, alljoyn_busattachment_enablepeersecurity can be called again if any of
 * ALLJOYN_ECDHE_NULL, ALLJOYN_ECDHE_PSK, or ALLJOYN_ECDHE_SPEKE are required; this will usually only be required
 * if the bus attachment will be used by a security manager to claim other apps over the bus. See the documentation
 * for alljoyn_busattachment_enablepeersecurity for details on changing authentication mechanisms.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[in]    caKey                      Null-terminated C string representing the CA's PEM-encoded public key.
 * @param[in]    identityCertificateChain   Null-terminated C string representing PEM-encoded identity certificates
 *                                          with the app's certificate being the leaf. The leaf is listed first
 *                                          followed by each intermediate Certificate Authority's certificate, ending
 *                                          in the trusted root's certificate.
 * @param[in]    groupId                    Byte array representing the admin group GUID.
 * @param[in]    groupSize                  Size of "groupId" array. It must be equal to 16.
 * @param[in]    groupAuthority             Null-terminated C string containing the PEM-encoded public key of the
 *                                          security group authority.
 * @param[in]    manifestsXmls              An array of null-terminated C strings containing the application's
 *                                          signed manifests in XML format. The signed manifest's XSD is located under
 *                                          alljoyn_core/docs/manifest.xsd.
 * @param[in]    manifestsCount             Count of "manifestsXmls" array elements.
 *
 * @return
 *          - #ER_OK If successful.
 *          - Other error status codes indicating a failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_claim(alljoyn_permissionconfigurator configurator,
                                                            AJ_PCSTR caKey,
                                                            AJ_PCSTR identityCertificateChain,
                                                            const uint8_t* groupId,
                                                            size_t groupSize,
                                                            AJ_PCSTR groupAuthority,
                                                            AJ_PCSTR* manifestsXmls,
                                                            size_t manifestsCount);

/**
 * This method allows the application to update its identity certificate and manifests.
 * All old manifests will be overwritten by the new set.
 *
 * After having a new identity certificate installed, the target bus clears
 * out all of its peer's secret and session keys, so the next call will get
 * security violation. After calling alljoyn_permissionconfigurator_updateidentity,
 * alljoyn_busattachment_secureconnectionasync(true) should be called to force
 * the peers to create a new set of secret and session keys.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[in]    identityCertificateChain   Null-terminated C string representing PEM-encoded identity certificate chain
 *                                          with the application's certificate being the leaf. The leaf is listed first
 *                                          followed by each intermediate Certificate Authority's certificate, ending
 *                                          in the trusted root's certificate.
 * @param[in]    manifestsXmls              An array of null-terminated C strings containing the application's
 *                                          signed manifests in XML format.
 * @param[in]    manifestsCount             Count of "manifestsXmls" array elements.
 *
 * @return
 *          - #ER_OK                        If successful.
 *          - #ER_INVALID_CERTIFICATE       Error raised when the identity certificate chain is not valid.
 *          - #ER_INVALID_CERTIFICATE_USAGE Error raised when the Extended Key Usage is not AllJoyn specific.
 *          - #ER_DIGEST_MISMATCH           Error raised when none of the provided signed manifests are
 *                                          valid for the given identity certificate.
 *          - #ER_XML_MALFORMED             Error raised the manifest is not compliant with the required format.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_updateidentity(alljoyn_permissionconfigurator configurator,
                                                                     AJ_PCSTR identityCertificateChain,
                                                                     AJ_PCSTR* manifestsXmls, size_t manifestsCount);

/**
 * This method allows the application to retrieve its identity certificate chain.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[out]   identityCertificateChain   Null-terminated C string representing PEM-encoded identity certificate chain
 *                                          with the application's certificate being the leaf. The leaf is listed first
 *                                          followed by each intermediate Certificate Authority's certificate, ending in
 *                                          the trusted root's certificate. This string must be freed with
 *                                          alljoyn_permissionconfigurator_certificatechain_destroy.
 *
 * @return
 *          - #ER_OK                        If successful.
 *          - #ER_CERTIFICATE_NOT_FOUND     Error raised when no identity certificate chain is installed.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getidentity(alljoyn_permissionconfigurator configurator,
                                                                  AJ_PSTR* identityCertificateChain);

/**
 * This method deallocates a string of PEM-encoded certificates returned by alljoyn_permissionconfigurator_getidentity.
 *
 * @param[in]   certificateChain            String returned by a call to alljoyn_permissionconfigurator_getidentity.
 */
AJ_API void AJ_CALL alljoyn_permissionconfigurator_certificatechain_destroy(AJ_PSTR certificateChain);

/**
 * This method allows the application to retrieve its signed manifests.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[out]   manifestArray              Pointer to an alljoyn_manifestarray to receive manifests in
 *                                          XML format. This array must be freed with
 *                                          alljoyn_permissionconfigurator_manifestarray_cleanup.
 *
 * @return
 *          - #ER_OK                        If successful.
 *          - #ER_MANIFEST_NOT_FOUND        Error raised when no manifests are installed.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getmanifests(alljoyn_permissionconfigurator configurator,
                                                                   alljoyn_manifestarray* manifestArray);

/**
 * This method deallocates an array of strings containing manifests returned by alljoyn_permissionconfigurator_getmanifests.
 *
 * @param[in]    manifestArray              Pointer to alljoyn_manifestarray populated by a call to
 *                                          alljoyn_permissionconfigurator_getmanifests.
 */
AJ_API void AJ_CALL alljoyn_permissionconfigurator_manifestarray_cleanup(alljoyn_manifestarray* manifestArray);

/**
 * This method allows the application to install signed manifests to itself. This method only verifies that manifests
 * have a signature; it does not verify that the signature is valid.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[in]    manifestsXmls              Array of null-terminated C strings, each of which is a signed manifest in
 *                                          XML format.
 * @param[in]    manifestsCount             The number of elements in the manifests array.
 * @param[in]    append                     QCC_TRUE to append to the currently installed manifests; QCC_FALSE to clear
 *                                          currently installed manifests first
 *
 * @return
 *          - #ER_OK                        If successful.
 *          - #ER_DIGEST_MISMATCH           Error raised if no manifests can be installed because none are signed.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_installmanifests(alljoyn_permissionconfigurator configurator,
                                                                       AJ_PCSTR* manifestsXmls,
                                                                       size_t manifestsCount,
                                                                       QCC_BOOL append);

/**
 * This method retrieves the application's identity certificate information.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[out]   certificateId              Pointer to receive the alljoyn_certificateid structure containing the
 *                                          serial number and issuer public key of the identity certificate. The
 *                                          issuerAki field is not returned by this function and will be NULL.
 *                                          This must be freed by the caller using alljoyn_permissionconfigurator_certificateid_cleanup.
 *
 * @return
 *          - #ER_OK                        If successful.
 *          - #ER_CERTIFICATE_NOT_FOUND     Error raised when no identity certificate chain is installed.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getidentitycertificateid(alljoyn_permissionconfigurator configurator,
                                                                               alljoyn_certificateid* certificateId);

/**
 * This method deallocates strings returned by a call to alljoyn_permissionconfigurator_getidentitycertificateid.
 *
 * @param[in]    certificateIdString        Pointer to alljoyn_certificateid struct returned by a call to
 *                                          alljoyn_permissionconfigurator_getidentitycertificateid.
 */
AJ_API void AJ_CALL alljoyn_permissionconfigurator_certificateid_cleanup(alljoyn_certificateid* certificateId);

/**
 * This method allows the app to install the permission policy to itself.
 * Any existing policy will be replaced; the caller is responsible for first getting
 * the policy and checking the version number if the caller only wishes to replace
 * the policy with a newer version.
 *
 * Until ASACORE-2755 is fixed the caller must include all default policies
 * (containing information about the trust anchors) with each call, so they
 * would not be removed.
 *
 * After having a new policy installed, the target bus clears out all of
 * its peer's secret and session keys, so so any existing secure session will
 * need to be re-established: alljoyn_busattachment_secureconnectionasync(true)
 * should be called to force the peers to create a new set of secret and session keys.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[in]    policyXml                  The new policy in XML format. For the policy XSD refer to
 *                                          alljoyn_core/docs/policy.xsd.
 *
 * @return
 *          - #ER_OK                If successful.
 *          - #ER_XML_MALFORMED     Error raised when the provided XML is not in supported policy format.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_updatepolicy(alljoyn_permissionconfigurator configurator,
                                                                   AJ_PCSTR policyXml);

/**
 * This method allows the app to retrieve its active policy.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[out]   policyXml                  The active policy in XML format. This string must be freed using
 *                                          alljoyn_permissionconfigurator_policy_destroy.
 * @return
 *          - #ER_OK                If successful.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getpolicy(alljoyn_permissionconfigurator configurator,
                                                                AJ_PSTR* policyXml);

/**
 * This method allows the app to retrieve its default policy.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[out]   policyXml                  The default policy in XML format. This string must be freed using
 *                                          alljoyn_permissionconfigurator_policy_destroy.
 * @return
 *          - #ER_OK                If successful.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getdefaultpolicy(alljoyn_permissionconfigurator configurator,
                                                                       AJ_PSTR* policyXml);

/**
 * This method deallocates strings returned by a call to alljoyn_permissionconfigurator_getdefaultpolicy
 * and alljoyn_permissionconfigurator_getpolicy.
 *
 * @param[in]    policyXml                  A string containing a policy in XML format returned by a call to either
 *                                          alljoyn_permissionconfigurator_getpolicy or
 *                                          alljoyn_permissionconfigurator_getdefaultpolicy.
 */
AJ_API void AJ_CALL alljoyn_permissionconfigurator_policy_destroy(AJ_PSTR policyXml);

/**
 * This method allows an app to remove the currently installed policy. The
 * application reverts back to the default policy generated during the claiming
 * process.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 *
 * @return
 *          - #ER_OK                If successful.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_resetpolicy(alljoyn_permissionconfigurator configurator);

/**
 * This method allows an app to retrieve its membership certificate summaries.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[out]   certificateIds             Pointer to receive an alljoyn_certificateidarray struct containing the
 *                                          serial number, issuer public key, and issuer AKI for each membership certificate.
 *                                          This array must be freed by the caller with alljoyn_certificateids_destroy.
 *
 * @remarks If no membership certificates are installed, this function will return ER_OK, but certificateIds->count
 *          will be zero.
 *
 * @return
 *          - #ER_OK                If successful.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_getmembershipsummaries(alljoyn_permissionconfigurator configurator,
                                                                             alljoyn_certificateidarray* certificateIds);

/**
 * This method deallocates strings returned by a call to alljoyn_permissionconfigurator_getidentitycertificateid.
 *
 * @param[in]    certificateIdArray   Pointer to an alljoyn_certificateidarray returned from a call to
 *                                    alljoyn_permissionconfigurator_getmembershipsummaries.
 */
AJ_API void AJ_CALL alljoyn_permissionconfigurator_certificateidarray_cleanup(alljoyn_certificateidarray* certificateIdArray);

/**
 * This method allows the app to install a membership cert chain to itself.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[in]    membershipCertificateChain Null-terminated C string representing PEM encoded membership certificates
 *                                          with the app's certificate being listed first followed by each intermediate
 *                                          Certificate Authority's certificate, ending in the trusted root's certificate.
 *
 * @return
 *          - #ER_OK                    If successful.
 *          - #ER_DUPLICATE_CERTIFICATE Error raised when the membership certificate
 *                                      is already installed.
 *          - #ER_INVALID_CERTIFICATE   Error raised when the membership certificate is not valid.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_installmembership(alljoyn_permissionconfigurator configurator,
                                                                        AJ_PCSTR membershipCertificateChain);

/**
 * This method allows the app to remove a membership certificate chain from itself.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 * @param[in]    serial                     Certificate's serial number.
 * @param[in]    serialLen                  Certificate's serial number length.
 * @param[in]    issuerPublicKey            PEM-encoded public key of the certificate's issuer.
 * @param[in]    issuerAki                  Certificate issuer's AKI.
 * @param[in]    issuerAkiLen               Certificate issuer's AKI length.
 *
 * @return
 *          - #ER_OK                    If successful.
 *          - #ER_CERTIFICATE_NOT_FOUND Error raised when the membership certificate is not found.
 *          - An error status indicating failure.
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_removemembership(alljoyn_permissionconfigurator configurator,
                                                                       const uint8_t* serial,
                                                                       size_t serialLen,
                                                                       AJ_PCSTR issuerPublicKey,
                                                                       const uint8_t* issuerAki,
                                                                       size_t issuerAkiLen);

/**
 * This method allows the app to signal itself that management is starting.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 *
 * @return
 *          - #ER_OK                         If successful.
 *          - #ER_MANAGEMENT_ALREADY_STARTED if the app is already in this state
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_startmanagement(alljoyn_permissionconfigurator configurator);

/**
 * This method allows the app to signal itself that management is ending.
 *
 * @param[in]    configurator               The alljoyn_permissionconfigurator for the application's bus attachment.
 *
 * @return
 *          - #ER_OK                         If successful.
 *          - #ER_MANAGEMENT_NOT_STARTED     if the app was not in the management state
 */
AJ_API QStatus AJ_CALL alljoyn_permissionconfigurator_endmanagement(alljoyn_permissionconfigurator configurator);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif