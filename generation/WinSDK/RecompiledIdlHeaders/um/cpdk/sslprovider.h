/*++

Copyright (c) 2004  Microsoft Corporation

Module Name:

    sslprovider.h

Abstract:

    SSL protocol provider API prototypes and definitions 

Author:

    John Banes (jbanes)     October 6, 2004

Revision History:

--*/

#ifndef __SSL_PROVIDER_H__
#define __SSL_PROVIDER_H__

#include <wincrypt.h>

#ifdef __cplusplus
extern "C" 
{
#endif

//
// Microsoft built-in providers.
//

#define MS_SCHANNEL_PROVIDER            L"Microsoft SSL Protocol Provider"


#define NCRYPT_SSL_CLIENT_FLAG  0x00000001
#define NCRYPT_SSL_SERVER_FLAG  0x00000002


//
// SSL Protocols and Cipher Suites
//

// Protocols
#define SSL2_PROTOCOL_VERSION       0x0002
#define SSL3_PROTOCOL_VERSION       0x0300
#define TLS1_PROTOCOL_VERSION       0x0301

#define TLS1_0_PROTOCOL_VERSION     TLS1_PROTOCOL_VERSION
#if (NTDDI_VERSION >= NTDDI_WIN7)
#define TLS1_1_PROTOCOL_VERSION     0x0302
#define TLS1_2_PROTOCOL_VERSION     0x0303
#endif //(NTDDI_VERSION >= NTDDI_WIN7)
#if (NTDDI_VERSION >= NTDDI_WIN10_RS2)
#define TLS1_3_PROTOCOL_VERSION     0x0304
#endif

#if (NTDDI_VERSION >= NTDDI_WIN8)
#define DTLS1_0_PROTOCOL_VERSION    0xfeff
#endif
#if (NTDDI_VERSION >= NTDDI_WIN10_RS1)
#define DTLS1_2_PROTOCOL_VERSION    0xfefd
#endif

// Cipher suites
#define TLS_RSA_WITH_NULL_MD5                       0x0001
#define TLS_RSA_WITH_NULL_SHA                       0x0002
#define TLS_RSA_EXPORT_WITH_RC4_40_MD5              0x0003
#define TLS_RSA_WITH_RC4_128_MD5                    0x0004
#define TLS_RSA_WITH_RC4_128_SHA                    0x0005
#define TLS_RSA_WITH_DES_CBC_SHA                    0x0009
#define TLS_RSA_WITH_3DES_EDE_CBC_SHA               0x000A
#define TLS_DHE_DSS_WITH_DES_CBC_SHA                0x0012
#define TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA           0x0013
#define TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA           0x0016
#define TLS_RSA_WITH_AES_128_CBC_SHA                0x002F
#define TLS_DHE_DSS_WITH_AES_128_CBC_SHA            0x0032
#define TLS_DHE_RSA_WITH_AES_128_CBC_SHA            0x0033
#define TLS_RSA_WITH_AES_256_CBC_SHA                0x0035
#define TLS_DHE_DSS_WITH_AES_256_CBC_SHA            0x0038
#define TLS_DHE_RSA_WITH_AES_256_CBC_SHA            0x0039
#define TLS_RSA_EXPORT1024_WITH_DES_CBC_SHA         0x0062
#define TLS_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA     0x0063
#define TLS_RSA_EXPORT1024_WITH_RC4_56_SHA          0x0064

// Following were added for TLS 1.2
#define TLS_RSA_WITH_NULL_SHA256                    0x003B
#define TLS_RSA_WITH_AES_128_CBC_SHA256             0x003C
#define TLS_RSA_WITH_AES_256_CBC_SHA256             0x003D
#define TLS_DHE_DSS_WITH_AES_128_CBC_SHA256         0x0040
#define TLS_DHE_DSS_WITH_AES_256_CBC_SHA256         0x006A
#define TLS_RSA_WITH_AES_128_GCM_SHA256             0x009C
#define TLS_RSA_WITH_AES_256_GCM_SHA384             0x009D
#define TLS_DHE_RSA_WITH_AES_128_GCM_SHA256         0x009E
#define TLS_DHE_RSA_WITH_AES_256_GCM_SHA384         0x009F


// PSK cipher suites
#define TLS_PSK_WITH_AES_128_GCM_SHA256             0x00A8
#define TLS_PSK_WITH_AES_256_GCM_SHA384             0x00A9
#define TLS_PSK_WITH_AES_128_CBC_SHA256             0x00AE
#define TLS_PSK_WITH_AES_256_CBC_SHA384             0x00AF
#define TLS_PSK_WITH_NULL_SHA256                    0x00B0
#define TLS_PSK_WITH_NULL_SHA384                    0x00B1


#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA        0xc009
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA          0xc013
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA        0xc00a
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA          0xc014

// Following were added for TLS 1.2
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256     0xC023
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384     0xC024
#define TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256     0xC02B
#define TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384     0xC02C
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256       0xC027
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384       0xC028
#define TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256       0xC02F
#define TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384       0xC030

// The following were added for TLS 1.3
#define TLS_AES_128_GCM_SHA256                      0x1301
#define TLS_AES_256_GCM_SHA384                      0x1302

// SSL2 cipher suites
#define SSL_CK_RC4_128_WITH_MD5                     0x010080
#define SSL_CK_RC4_128_EXPORT40_WITH_MD5            0x020080
#define SSL_CK_RC2_128_CBC_WITH_MD5                 0x030080
#define SSL_CK_RC2_128_CBC_EXPORT40_WITH_MD5        0x040080
#define SSL_CK_IDEA_128_CBC_WITH_MD5                0x050080
#define SSL_CK_DES_64_CBC_WITH_MD5                  0x060040
#define SSL_CK_DES_192_EDE3_CBC_WITH_MD5            0x0700C0

// Key Types
// ECC curve types
#define TLS_ECC_P256_CURVE_KEY_TYPE                 23
#define TLS_ECC_P384_CURVE_KEY_TYPE                 24
#define TLS_ECC_P521_CURVE_KEY_TYPE                 25

// Use BCRYPT_ECDSA_ALGORITHM instead!!
#define SSL_ECDSA_ALGORITHM                    L"ECDSA"

// definition for szExchange field for PSK cipher suites
#define TLS_PSK_EXCHANGE                       L"PSK"
#define TLS_RSA_PSK_EXCHANGE                   L"RSA_PSK"

#define NCRYPT_SSL_MAX_NAME_SIZE            64


typedef struct _NCRYPT_SSL_CIPHER_SUITE
{
    DWORD dwProtocol;
    DWORD dwCipherSuite;
    DWORD dwBaseCipherSuite;
    WCHAR szCipherSuite[NCRYPT_SSL_MAX_NAME_SIZE];
    WCHAR szCipher[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwCipherLen;
    DWORD dwCipherBlockLen;    // in bytes
    WCHAR szHash[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwHashLen;
    WCHAR szExchange[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwMinExchangeLen;
    DWORD dwMaxExchangeLen;
    WCHAR szCertificate[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwKeyType;
} NCRYPT_SSL_CIPHER_SUITE;

#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
typedef struct _NCRYPT_SSL_CIPHER_SUITE_EX
{
    DWORD dwVersion;
    DWORD dwProtocol;
    DWORD dwCipherSuite;
    DWORD dwBaseCipherSuite;
    WCHAR szCipherSuite[NCRYPT_SSL_MAX_NAME_SIZE];
    WCHAR szCipher[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwCipherLen;
    DWORD dwCipherBlockLen;    // in bytes
    WCHAR szHash[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwHashLen;
    WCHAR szExchange[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwMinExchangeLen;
    DWORD dwMaxExchangeLen;
    WCHAR szCertificate[NCRYPT_SSL_MAX_NAME_SIZE];
    DWORD dwKeyType;
    WCHAR szCipherMode[NCRYPT_SSL_MAX_NAME_SIZE];
} NCRYPT_SSL_CIPHER_SUITE_EX;

#define NCRYPT_SSL_CIPHER_SUITE_EX_VERSION 1
#endif

#if (NTDDI_VERSION >= NTDDI_WIN7)

typedef struct _NCRYPT_SSL_CIPHER_LENGTHS
{
    DWORD cbLength;
    DWORD dwHeaderLen;
    DWORD dwFixedTrailerLen;
    DWORD dwMaxVariableTrailerLen;
    DWORD dwFlags;
} NCRYPT_SSL_CIPHER_LENGTHS;

#define NCRYPT_SSL_CIPHER_LENGTHS_BLOCK_PADDING 0x00000001

#endif //(NTDDI_VERSION >= NTDDI_WIN7)


#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

#define MSCRYPT_ECC_MAX_OID_LENGTH                      255
#define MSCRYPT_ECC_MAX_CURVE_NAME_LENGTH               255

typedef struct _NCRYPT_SSL_ECC_CURVE
{
    WCHAR   szCurveName[MSCRYPT_ECC_MAX_CURVE_NAME_LENGTH];
    CHAR    szOID[MSCRYPT_ECC_MAX_OID_LENGTH];
    DWORD   dwPublicKeyLength;
    DWORD   dwCurveType; // IANA NamedCurve
    DWORD   dwFlags;
} NCRYPT_SSL_ECC_CURVE, *PNCRYPT_SSL_ECC_CURVE;

#endif //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)


//+-------------------------------------------------------------------------
// SslChangeNotify
//
// This function is used to register for changes to the SSL protocol 
// provider configuration settings. 
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslChangeNotify(
    IN     HANDLE   hEvent,
    IN     DWORD    dwFlags);


//+-------------------------------------------------------------------------
// SslComputeClientAuthHash
//
// Computes the hashes that are sent in the CertificateVerify handshake 
// message. 
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslComputeClientAuthHash(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    NCRYPT_HASH_HANDLE hHandshakeHash,
    _In_    LPCWSTR pszAlgId,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslComputeClientAuthHashFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    NCRYPT_HASH_HANDLE hHandshakeHash,
    _In_    LPCWSTR pszAlgId,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

//+-------------------------------------------------------------------------
// SslComputeEapKeyBlock
//
// Computes the key block used by EAP
//     pbRandoms must be client_random + server_random (client random
//     concatenated with the server random).
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslComputeEapKeyBlock(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_reads_bytes_(cbRandoms) PBYTE pbRandoms,
    _In_    DWORD   cbRandoms,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslComputeEapKeyBlockFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_reads_bytes_(cbRandoms) PBYTE pbRandoms,
    _In_    DWORD   cbRandoms,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

//
//  SslComputeEapKeyBlock flags
//

#define NCRYPT_SSL_EAP_PRF_FIELD    0x000000ff
#define NCRYPT_SSL_EAP_ID           0x00000000
#define NCRYPT_SSL_EAP_TTLSV0_ID    0x00000001
#define NCRYPT_SSL_EAP_TTLSV0_CHLNG_ID  0x00000002
#define NCRYPT_SSL_EAP_FAST_ID      0x00000003

//+-------------------------------------------------------------------------
// SslComputeFinishedHash
//
// Computes the hashes that are sent in the Finished handshake message. 
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslComputeFinishedHash(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    NCRYPT_HASH_HANDLE hHandshakeHash,
    _Out_writes_bytes_all_(cbOutput) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslComputeFinishedHashFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    NCRYPT_HASH_HANDLE hHandshakeHash,
    _Out_writes_bytes_all_(cbOutput) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _In_    DWORD   dwFlags);

//+-------------------------------------------------------------------------
// SslCreateEphemeralKey
//
// Creates an ephemeral key. 
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslCreateEphemeralKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_KEY_HANDLE *phEphemeralKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    DWORD   dwKeyType,
    _In_    DWORD   dwKeyBitLen,
    _In_reads_bytes_opt_(cbParams) PBYTE pbParams,
    _In_    DWORD   cbParams,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslCreateEphemeralKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_KEY_HANDLE *phEphemeralKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    DWORD   dwKeyType,
    _In_    DWORD   dwKeyBitLen,
    _In_reads_bytes_(cbParams) PBYTE pbParams,
    _In_    DWORD   cbParams,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslCreateHandshakeHash
//
// Creates a compound hash object used to hash handshake messages. 
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslCreateHandshakeHash(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_HASH_HANDLE *phHandshakeHash,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslCreateHandshakeHashFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_HASH_HANDLE *phHandshakeHash,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    DWORD   dwFlags);





//+-------------------------------------------------------------------------
// SslDecryptPacket
//
// Decrypts a single SSL packet.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslDecryptPacket(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Inout_ NCRYPT_KEY_HANDLE hKey,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    ULONGLONG SequenceNumber,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslDecryptPacketFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Inout_ NCRYPT_KEY_HANDLE hKey,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    ULONGLONG SequenceNumber,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslEncryptPacket
//
// Encrypts a single SSL packet.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslEncryptPacket(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Inout_ NCRYPT_KEY_HANDLE hKey,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    ULONGLONG SequenceNumber,
    _In_    DWORD   dwContentType, 
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslEncryptPacketFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Inout_ NCRYPT_KEY_HANDLE hKey,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    ULONGLONG SequenceNumber,
    _In_    DWORD   dwContentType, 
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslEnumCipherSuites
//
// This function is used to enumerate the list of cipher suites supported 
// by an SSL protocol provider. If a private key handle is specified, then
// this function will only return cipher suites that are compatible with
// the private key.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslEnumCipherSuites(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPrivateKey,
    _Outptr_ NCRYPT_SSL_CIPHER_SUITE **ppCipherSuite,
    _Inout_ PVOID * ppEnumState,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslEnumCipherSuitesFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPrivateKey,
    _Outptr_ NCRYPT_SSL_CIPHER_SUITE **ppCipherSuite,
    _Inout_ PVOID * ppEnumState,
    _In_    DWORD   dwFlags);


#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
//+-------------------------------------------------------------------------
// SslEnumCipherSuitesEx
//
// This function is used to enumerate the list of cipher suites supported 
// by an SSL protocol provider. If a private key handle is specified, then
// this function will only return cipher suites that are compatible with
// the private key.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslEnumCipherSuitesEx(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPrivateKey,
    _Outptr_ NCRYPT_SSL_CIPHER_SUITE_EX **ppCipherSuite,
    _Inout_ PVOID * ppEnumState,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslEnumCipherSuitesExFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPrivateKey,
    _Outptr_ NCRYPT_SSL_CIPHER_SUITE_EX **ppCipherSuite,
    _Inout_ PVOID * ppEnumState,
    _In_    DWORD   dwFlags);
#endif

#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

//+-------------------------------------------------------------------------
// SslEnumEccCurves
//
// This function is used to enumerate the list of ECC Curves supported
// by an SSL protocol provider.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslEnumEccCurves(
    _In_        NCRYPT_PROV_HANDLE      hSslProvider,
    _Out_       DWORD                  *pEccCurveCount,
    _Outptr_result_buffer_all_(*pEccCurveCount)
                NCRYPT_SSL_ECC_CURVE  **ppEccCurve,
    _In_        DWORD                   dwFlags
    );

typedef SECURITY_STATUS
(WINAPI * SslEnumEccCurvesFn)(
    _In_        NCRYPT_PROV_HANDLE      hSslProvider,
    _Out_       DWORD                  *pEccCurveCount,
    _Outptr_result_buffer_all_(*pEccCurveCount)
                NCRYPT_SSL_ECC_CURVE  **ppEccCurve,
    _In_        DWORD                   dwFlags
    );

#endif //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

//+-------------------------------------------------------------------------
// SslEnumProtocolProviders
//
// Returns a list of all the SSL protocol providers that are currently 
// installed on the system.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslEnumProtocolProviders(
    _Out_   DWORD * pdwProviderCount,
    _Outptr_ NCryptProviderName **ppProviderList,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslExportKey
// 
// Exports an SSL session key into a serialized blob.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExportKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    LPCWSTR pszBlobType,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExportKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    LPCWSTR pszBlobType,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslFreeBuffer
//
// Frees a memory buffer that was allocated by one of the other SSL protocol
// provider functions.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslFreeBuffer(
    PVOID   pvInput);

typedef SECURITY_STATUS
(WINAPI * SslFreeBufferFn)(
    PVOID   pvInput);


//+-------------------------------------------------------------------------
// SslFreeObject
//
// Frees a key, hash, or provider object that was created using one of the
// other SSL protocol provider functions.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslFreeObject(
    _Inout_ NCRYPT_HANDLE hObject,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslFreeObjectFn)(
    _Inout_ NCRYPT_HANDLE hObject,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslGenerateMasterKey
//
// Perform an SSL key exchange operations. This function computes the SSL
// master secret, and returns a handle to this object to the caller. This 
// master key can then be used to derive the SSL session keys and finish
// the SSL handshake.
//
// When RSA key exchange is being performed, the client-side of schannel
// calls SslGenerateMasterKey and the server-side of schannel calls 
// SslImportMasterKey. When DH key exchange is being performed, schannel
// calls SslGenerateMasterKey on both the client-side and the server-side.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslGenerateMasterKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPrivateKey,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _Out_   NCRYPT_KEY_HANDLE *phMasterKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    PNCryptBufferDesc pParameterList,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslGenerateMasterKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPrivateKey,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _Out_   NCRYPT_KEY_HANDLE *phMasterKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    PNCryptBufferDesc pParameterList,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslGenerateSessionKeys
//
// Generates a set of session keys, based on a supplied master secret and
// one or more additional parameters.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslGenerateSessionKeys(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _Out_   NCRYPT_KEY_HANDLE *phReadKey,
    _Out_   NCRYPT_KEY_HANDLE *phWriteKey,
    _In_    PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslGenerateSessionKeysFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _Out_   NCRYPT_KEY_HANDLE *phReadKey,
    _Out_   NCRYPT_KEY_HANDLE *phWriteKey,
    _In_    PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

// SSL provider property names.
#define SSL_KEY_TYPE_PROPERTY                L"KEYTYPE"

//+-------------------------------------------------------------------------
// SslGetKeyProperty
//
// Queries information from the key.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslGetKeyProperty(
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    LPCWSTR pszProperty,
    _Outptr_result_bytebuffer_(*pcbOutput) PBYTE *ppbOutput,
    _Out_   DWORD * pcbOutput,
    _In_    DWORD   dwFlags);
    
typedef SECURITY_STATUS
(WINAPI * SslGetKeyPropertyFn)(
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    LPCWSTR pszProperty,
    _Outptr_result_bytebuffer_(*pcbOutput) PBYTE *ppbOutput,
    _Out_   DWORD * pcbOutput,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslGetProviderProperty
//
// Queries information from the protocol provider.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslGetProviderProperty(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    LPCWSTR pszProperty,
    _Outptr_result_bytebuffer_(*pcbOutput) PBYTE *ppbOutput,
    _Out_   DWORD * pcbOutput,
    _Inout_opt_ PVOID *ppEnumState,
    _In_    DWORD   dwFlags);
    
typedef SECURITY_STATUS
(WINAPI * SslGetProviderPropertyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    LPCWSTR pszProperty,
    _Outptr_result_bytebuffer_(*pcbOutput) PBYTE *ppbOutput,
    _Out_   DWORD * pcbOutput,
    _Inout_opt_ PVOID *ppEnumState,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslHashHandshake
//
// Adds a handshake message to the cumulative handshake hash object. This
// handshake hash is used when generating or processing Finished and 
// CertificateVerify messages.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslHashHandshake(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Inout_ NCRYPT_HASH_HANDLE hHandshakeHash,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslHashHandshakeFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Inout_ NCRYPT_HASH_HANDLE hHandshakeHash,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslImportKey
//
// Imports a public key into the protocol provider, as part of a key 
// exchange operation. This function is also used to import session keys, 
// when transferring them from one process to another.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslImportKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_KEY_HANDLE *phKey,
    _In_    LPCWSTR pszBlobType,
    _In_reads_bytes_(cbKeyBlob) PBYTE pbKeyBlob,
    _In_    DWORD   cbKeyBlob,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslImportKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_KEY_HANDLE *phKey,
    _In_    LPCWSTR pszBlobType,
    _In_reads_bytes_(cbKeyBlob) PBYTE pbKeyBlob,
    _In_    DWORD   cbKeyBlob,
    _In_    DWORD   dwFlags);


//+-------------------------------------------------------------------------
// SslImportMasterKey
//
// This function is used when performing a server-side SSL key exchange 
// operation. This function decrypts the pre-master secret, computes the 
// SSL master secret, and returns a handle to this object to the caller. 
// This master key can then be used to derive the SSL session keys, and 
// finish the SSL handshake.
//
// Note that this function is only used when the RSA key exchange algorithm
// is being used. When DH is used, then the server-side of schannel calls 
// SslGenerateMasterKey instead.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslImportMasterKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPrivateKey,
    _Out_   NCRYPT_KEY_HANDLE *phMasterKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    NCryptBufferDesc *pParameterList,
    _In_reads_bytes_(cbEncryptedKey) PBYTE pbEncryptedKey,
    _In_    DWORD   cbEncryptedKey,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslImportMasterKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPrivateKey,
    _Out_   NCRYPT_KEY_HANDLE *phMasterKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    NCryptBufferDesc *pParameterList,
    _In_reads_bytes_(cbEncryptedKey) PBYTE pbEncryptedKey,
    _In_    DWORD   cbEncryptedKey,
    _In_    DWORD   dwFlags);

//+-------------------------------------------------------------------------
// SslLookupCipherSuiteInfo
//
// Looks up cipher suite information given the suite number and a key type.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslLookupCipherSuiteInfo(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    DWORD dwProtocol,
    _In_    DWORD dwCipherSuite,
    _In_    DWORD dwKeyType,
    _Out_   NCRYPT_SSL_CIPHER_SUITE *pCipherSuite,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslLookupCipherSuiteInfoFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    DWORD dwProtocol,
    _In_    DWORD dwCipherSuite,
    _In_    DWORD dwKeyType,
    _Out_   NCRYPT_SSL_CIPHER_SUITE *pCipherSuite,
    _In_    DWORD   dwFlags);

//+-------------------------------------------------------------------------
// SslOpenPrivateKey
//
// This function is used to obtain a handle to the private key that 
// corresponds to the passed in server certificate. This handle will be used
// by the server-side of Schannel when performing key exchange operations.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslOpenPrivateKey(
    _In_   NCRYPT_PROV_HANDLE hSslProvider,
    _Out_  NCRYPT_KEY_HANDLE *phPrivateKey,
    _In_   PCCERT_CONTEXT pCertContext,
    _In_   DWORD dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslOpenPrivateKeyFn)(
    _In_   NCRYPT_PROV_HANDLE hSslProvider,
    _Out_  NCRYPT_KEY_HANDLE *phPrivateKey,
    _In_   PCCERT_CONTEXT pCertContext,
    _In_   DWORD dwFlags);

//+-------------------------------------------------------------------------
// SslOpenProvider
//
// Returns a handle to the specified protocol provider.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslOpenProvider(
    _Out_   NCRYPT_PROV_HANDLE *phSslProvider,
    _In_    LPCWSTR pszProviderName,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslOpenProviderFn)(
    _Out_   NCRYPT_PROV_HANDLE *phSslProvider,
    _In_    LPCWSTR pszProviderName,
    _In_    DWORD   dwFlags);

//+-------------------------------------------------------------------------
// SslSignHash
//
// Signs the passed in hash with the private key specified by the passed
// in key handle.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslSignHash(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPrivateKey,
    _In_reads_bytes_(cbHashValue) PBYTE pbHashValue,
    _In_    DWORD   cbHashValue,
    _Out_writes_bytes_to_opt_(cbSignature, *pcbResult) PBYTE pbSignature,
    _In_    DWORD   cbSignature,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslSignHashFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPrivateKey,
    _In_reads_bytes_(cbHashValue) PBYTE pbHashValue,
    _In_    DWORD   cbHashValue,
    _Out_writes_bytes_to_opt_(cbSignature, *pcbResult) PBYTE pbSignature,
    _In_    DWORD   cbSignature,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);


//
// The following flag is set to include the hash OID in an RSASSA-PKCS1-v1_5
// signature according to the TLS 1.2 RFC. The null-terminated
// Unicode string that identifies the cryptographic algorithm to use to create
// the BCRYPT PKCS1 padding is passed at the start of the pbHashValue
// parameter. The hash bytes immediately follow the Unicode NULL terminator
// character (L'\0'). The cbHashValue includes the byte length of this
// Unicode string.
//
// This flag is only applicable to TLS 1.2 RSA signatures and MUST NOT be set
// for other protocols, such as, TLS 1.0 or other signature types like
// DSA or ECDSA.
//

#define NCRYPT_SSL_SIGN_INCLUDE_HASHOID 0x00000001
#define NCRYPT_SSL_SIGN_USE_PSS_PADDING 0x00000002

//+-------------------------------------------------------------------------
// SslVerifySignature
//
// Verifies the passed in signature with the passed in hash and the
// passed in public key.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslVerifySignature(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _In_reads_bytes_(cbHashValue) PBYTE pbHashValue,
    _In_    DWORD   cbHashValue,
    _In_reads_bytes_(cbSignature) PBYTE pbSignature,
    _In_    DWORD   cbSignature,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslVerifySignatureFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _In_reads_bytes_(cbHashValue) PBYTE pbHashValue,
    _In_    DWORD   cbHashValue,
    _In_reads_bytes_(cbSignature) PBYTE pbSignature,
    _In_    DWORD   cbSignature,
    _In_    DWORD   dwFlags);


#if (NTDDI_VERSION >= NTDDI_WIN7)
//+-------------------------------------------------------------------------
// SslCreateClientAuthHash
//
// Creates the hash object used to hash TLS 1.2 handshake messages for
// client authentication
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslLookupCipherLengths(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    DWORD dwProtocol,
    _In_    DWORD dwCipherSuite,
    _In_    DWORD dwKeyType,
    _Out_writes_bytes_(cbCipherLengths) NCRYPT_SSL_CIPHER_LENGTHS *pCipherLengths,
    _In_    DWORD cbCipherLengths,
    _In_    DWORD dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslLookupCipherLengthsFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    DWORD dwProtocol,
    _In_    DWORD dwCipherSuite,
    _In_    DWORD dwKeyType,
    _Out_writes_bytes_(cbCipherLengths) NCRYPT_SSL_CIPHER_LENGTHS *pCipherLengths,
    _In_    DWORD cbCipherLengths,
    _In_    DWORD dwFlags);


SECURITY_STATUS
WINAPI
SslCreateClientAuthHash(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_HASH_HANDLE *phHandshakeHash,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    LPCWSTR pszHashAlgId,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslCreateClientAuthHashFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _Out_   NCRYPT_HASH_HANDLE *phHandshakeHash,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    LPCWSTR pszHashAlgId,
    _In_    DWORD   dwFlags);

SECURITY_STATUS
WINAPI
SslGetCipherSuitePRFHashAlgorithm(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    DWORD dwProtocol,
    _In_    DWORD dwCipherSuite,
    _In_    DWORD dwKeyType,
    _Out_writes_(NCRYPT_SSL_MAX_NAME_SIZE) 
            WCHAR szPRFHash[NCRYPT_SSL_MAX_NAME_SIZE],
    _In_    DWORD dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslGetCipherSuitePRFHashAlgorithmFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    DWORD dwProtocol,
    _In_    DWORD dwCipherSuite,
    _In_    DWORD dwKeyType,
    _Out_writes_(NCRYPT_SSL_MAX_NAME_SIZE) 
            WCHAR szPRFHash[NCRYPT_SSL_MAX_NAME_SIZE],
    _In_    DWORD dwFlags);


#endif //(NTDDI_VERSION >= NTDDI_WIN7)


#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
//+-------------------------------------------------------------------------
// SslComputeSessionHash
//
// Computes the hashes that are used as input to the extended master secret 
// computation.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslComputeSessionHash(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_HASH_HANDLE hHandshakeHash,
    _In_    DWORD   dwProtocol,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslComputeSessionHashFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_HASH_HANDLE hHandshakeHash,
    _In_    DWORD   dwProtocol,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)


#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
//+-------------------------------------------------------------------------
// SslGeneratePreMasterKey
//
// This function computes the SSL premaster secret, and returns a handle to 
// this object to the caller. This premaster secret can then be used to 
// produce the master secret by calling SslGenerateMasterKey.
//
// This function also encrypts the generated premaster secret using the 
// server's public key. Encrypted premaster secret is sent to the server in 
// the ClientKeyExchange message.
//
// When RSA key exchange is being performed, the client side of schannel 
// first calls SslGeneratePreMasterKey to generate the ClientKeyExchange 
// message, and then calls SslGenerateMasterKey to produce the master 
// secret.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslGeneratePreMasterKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _Out_   NCRYPT_KEY_HANDLE *phPreMasterKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    PNCryptBufferDesc pParameterList,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslGeneratePreMasterKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _Out_   NCRYPT_KEY_HANDLE *phPreMasterKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_    PNCryptBufferDesc pParameterList,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)


#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
//+-------------------------------------------------------------------------
// SslExportKeyingMaterial
//
// Exports keying material per RFC 5705.
//
// For TLS 1.2 and lower versions, this function uses the TLS PRF to 
// produce cbOutput bytes of keying material from the master secret, 
// disambiguating ASCII label, client and server randoms and an optional 
// application context.
//     pbRandoms must be client_random + server_random (client random
//     concatenated with the server random).
//
// For TLS 1.3, this function uses HKDF to produce cbOutput bytes of keying
// material from the early exporter master secret or exporter master secret,
// disambiguating ASCII label and an optional application context.

// Unlike TLS 1.2 and lower versions, TLS 1.3 specifies that if NULL
// context is provided by the caller, a zero-length context is used,
// resulting in the same exported keying material for empty and NULL
// contexts. It is an error to supply randoms when exporting keying material
// in TLS 1.3.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExportKeyingMaterial(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    PCHAR   sLabel,
    _In_reads_bytes_opt_(cbRandoms) PBYTE pbRandoms,
    _In_    DWORD   cbRandoms,
    _In_reads_bytes_opt_(cbContextValue) PBYTE pbContextValue,
    _In_    WORD    cbContextValue,
    _Out_writes_bytes_(cbOutput) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExportKeyingMaterialFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    PCHAR   sLabel,
    _In_reads_bytes_opt_(cbRandoms) PBYTE pbRandoms,
    _In_    DWORD   cbRandoms,
    _In_reads_bytes_opt_(cbContextValue) PBYTE pbContextValue,
    _In_    WORD    cbContextValue,
    _Out_writes_bytes_(cbOutput) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)


#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
//+-------------------------------------------------------------------------
// SslExtractEarlyKey
//
// This function computes the TLS 1.3 early secret:
// 1. If the caller does not provide a preshared key, generates the 0-value 
//    consisting of a string of Hash.length zero bytes;
// 2. Calls HKDF-Extract with the preshared key and the 0-value salt;
// 3. Returns a handle to the resulting early secret.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExtractEarlyKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPreSharedKey,
    _Out_   NCRYPT_KEY_HANDLE *phEarlyKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExtractEarlyKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hPreSharedKey,
    _Out_   NCRYPT_KEY_HANDLE *phEarlyKey,
    _In_    DWORD   dwProtocol,
    _In_    DWORD   dwCipherSuite,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_RS5)


#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
//+-------------------------------------------------------------------------
// SslExtractHandshakeKey
//
// This function computes the TLS 1.3 handshake secret:
// 1. Computes a shared secret by performing ECDHE key agreement using the 
//    caller-specified private and public keys;
// 2. Derives a salt value from the caller-specified early secret;
// 3. Calls HKDF-Extract with the shared secret and salt value;
// 4. Returns a handle to the resulting handshake secret.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExtractHandshakeKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPrivateKey,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _In_    NCRYPT_KEY_HANDLE hEarlyKey,
    _Out_   NCRYPT_KEY_HANDLE *phHandshakeKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExtractHandshakeKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hPrivateKey,
    _In_    NCRYPT_KEY_HANDLE hPublicKey,
    _In_    NCRYPT_KEY_HANDLE hEarlyKey,
    _Out_   NCRYPT_KEY_HANDLE *phHandshakeKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_RS5)


#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
//+-------------------------------------------------------------------------
// SslExtractMasterKey
//
// This function computes the TLS 1.3 master secret:
// 1. Derives a salt value from the caller-specified handshake secret;
// 2. Calls HKDF-Extract with the 0-value secret and the derived salt value;
// 3. Returns a handle to the resulting master secret.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExtractMasterKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hHandshakeKey,
    _Out_   NCRYPT_KEY_HANDLE *phMasterKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExtractMasterKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hHandshakeKey,
    _Out_   NCRYPT_KEY_HANDLE *phMasterKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_RS5)


#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
//+-------------------------------------------------------------------------
// SslExpandTrafficKeys
//
// This function computes the TLS 1.3 client and/or server traffic keys: 
// 1. Constructs the TLS 1.3 HkdfLabel struct using the caller-specified 
//    context hash;
// 2. Calls HKDF-Expand with the caller-specified base key, the constructed 
//    HkdfLabel and the cipher suite hash length;
// 3. Returns handles to the resulting client and/or server traffic key 
//    objects.
//
// Early, handshake or master secret can be used as the base key to produce 
// 0-RTT, handshake or application data client traffic key, respectively.
// Handshake or master secret can be used as the base key to produce 
// handshake or application data server traffic key, respectively.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExpandTrafficKeys(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hBaseKey,
    _In_    NCRYPT_HASH_HANDLE hHashValue,
    _Out_opt_ NCRYPT_KEY_HANDLE *phClientTrafficKey,
    _Out_opt_ NCRYPT_KEY_HANDLE *phServerTrafficKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExpandTrafficKeysFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hBaseKey,
    _In_    NCRYPT_HASH_HANDLE hHashValue,
    _Out_opt_ NCRYPT_KEY_HANDLE *phClientTrafficKey,
    _Out_opt_ NCRYPT_KEY_HANDLE *phServerTrafficKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_RS5)


#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
//+-------------------------------------------------------------------------
// SslExpandWriteKey
//
// This function computes the TLS 1.3 client or server write key: 
// 1. Constructs the TLS 1.3 HkdfLabel struct using the appropriate labels;
// 2. Calls HKDF-Expand with the caller-specified base key, the constructed 
//    HkdfLabel and the cipher suite key and IV length;
// 3. Returns handle to the resulting client or server write key object.
//
// Early, handshake or application traffic secret can be used as the base
// key to produce 0-RTT, handshake or application data client write key,
// respectively.
// Handshake or application traffic secret can be used as the base key to
// produce handshake or application data server write key, respectively.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExpandWriteKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hBaseTrafficKey,
    _Out_   NCRYPT_KEY_HANDLE *phWriteKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExpandWriteKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hBaseTrafficKey,
    _Out_   NCRYPT_KEY_HANDLE *phWriteKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_RS5)


#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
//+-------------------------------------------------------------------------
// SslExpandExporterMasterKey
//
// This function computes the TLS 1.3 early exporter master key or exporter
// master key:
// 1. Constructs the TLS 1.3 HkdfLabel struct using the caller-specified 
//    context hash;
// 2. Calls HKDF-Expand with the caller-specified base key, the constructed 
//    HkdfLabel and the cipher suite hash length;
// 3. Returns handle to the resulting early exporter master key or exporter
//    master key objects.
//
// Early secret or master secret can be used as the base key to produce 
// early exporter master key or exporter master key, respectively.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExpandExporterMasterKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hBaseKey,
    _In_    NCRYPT_HASH_HANDLE hHashValue,
    _Out_   NCRYPT_KEY_HANDLE *phExporterMasterKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExpandExporterMasterKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hBaseKey,
    _In_    NCRYPT_HASH_HANDLE hHashValue,
    _Out_   NCRYPT_KEY_HANDLE *phExporterMasterKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_RS5)

#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
//+-------------------------------------------------------------------------
// SslExpandResumptionMasterKey
//
// This function computes the TLS 1.3 resumption master key:
// 1. Constructs the TLS 1.3 HkdfLabel struct using the caller-specified 
//    context hash;
// 2. Calls HKDF-Expand with the caller-specified master secret, the
//    constructed HkdfLabel and the cipher suite hash length;
// 3. Returns handle to the resulting resumption master key object.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExpandResumptionMasterKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    NCRYPT_HASH_HANDLE hHashValue,
    _Out_   NCRYPT_KEY_HANDLE *phResumptionMasterKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExpandResumptionMasterKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hMasterKey,
    _In_    NCRYPT_HASH_HANDLE hHashValue,
    _Out_   NCRYPT_KEY_HANDLE *phResumptionMasterKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_VB)

#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
//+-------------------------------------------------------------------------
// SslDuplicateTranscriptHash
//
// This function duplicates the TLS 1.3 transcript hash.
// Useful for post-handshake authentication transcript operations.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslDuplicateTranscriptHash(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_HASH_HANDLE hTranscriptHash,
    _Out_   NCRYPT_HASH_HANDLE *phTranscriptHash,
    _In_    DWORD   dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslDuplicateTranscriptHashFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_HASH_HANDLE hTranscriptHash,
    _Out_   NCRYPT_HASH_HANDLE *phDuplicateTranscriptHash,
    _In_    DWORD   dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_VB)

#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
#define NCRYPT_SSL_EXTERNAL_PSK_FLAG    0x00000001
#define NCRYPT_SSL_RESUMPTION_PSK_FLAG  0x00000002

//+-------------------------------------------------------------------------
// SslExpandBinderKey
//
// This function computes the TLS 1.3 binder key:
// 1. Constructs the TLS 1.3 HkdfLabel struct using the external or
//    resumption binder label, depending on the caller-specified dwFlags
//    (NCRYPT_SSL_EXTERNAL_PSK_FLAG or NCRYPT_SSL_RESUMPTION_PSK_FLAG);
// 2. Calls HKDF-Expand with the caller-specified early secret, the
//    constructed HkdfLabel and the cipher suite hash length;
// 3. Returns handle to the resulting binder key object.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExpandBinderKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hEarlyKey,
    _Out_   NCRYPT_KEY_HANDLE *phBinderKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExpandBinderKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hEarlyKey,
    _Out_   NCRYPT_KEY_HANDLE *phBinderKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_VB)

#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
//+-------------------------------------------------------------------------
// SslExpandPreSharedKey
//
// This function computes the TLS 1.3 preshared key: 
// 1. Constructs the TLS 1.3 HkdfLabel struct using the resumption label and
//    the caller-specified ticket nonce;
// 2. Calls HKDF-Expand with the caller-specified resumption master key, the
//    constructed HkdfLabel and the cipher suite hash length;
// 3. Returns handle to the resulting preshared key object.
//--------------------------------------------------------------------------
SECURITY_STATUS
WINAPI
SslExpandPreSharedKey(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hResumptionMasterKey,
    _In_reads_bytes_opt_(cbTicketNonce) PBYTE pbTicketNonce,
    _In_    DWORD cbTicketNonce,
    _Out_   NCRYPT_KEY_HANDLE *phPreSharedKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslExpandPreSharedKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hSslProvider,
    _In_    NCRYPT_KEY_HANDLE hResumptionMasterKey,
    _In_reads_bytes_opt_(cbTicketNonce) PBYTE pbTicketNonce,
    _In_    DWORD cbTicketNonce,
    _Out_   NCRYPT_KEY_HANDLE *phPreSharedKey,
    _In_opt_ PNCryptBufferDesc pParameterList,
    _In_    DWORD dwFlags);
#endif  //(NTDDI_VERSION >= NTDDI_WIN10_VB)


//+-------------------------------------------------------------------------
// SslInitializeInterface
//
// This function is implemented by the SSL protocol provider, and provides
// the protocol router with a dispatch table of functions implemented by 
// the provider. 
//--------------------------------------------------------------------------

#define NCRYPT_SSL_INTERFACE_VERSION_1  BCRYPT_MAKE_INTERFACE_VERSION(1,0)
#define NCRYPT_SSL_INTERFACE_VERSION    NCRYPT_SSL_INTERFACE_VERSION_1

#if (NTDDI_VERSION >= NTDDI_WIN7)
#define NCRYPT_SSL_INTERFACE_VERSION_2  BCRYPT_MAKE_INTERFACE_VERSION(2,0)
#endif //(NTDDI_VERSION >= NTDDI_WIN7)

#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
#define NCRYPT_SSL_INTERFACE_VERSION_3  BCRYPT_MAKE_INTERFACE_VERSION(3,0)
#endif //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
#define NCRYPT_SSL_INTERFACE_VERSION_4  BCRYPT_MAKE_INTERFACE_VERSION(4,0)
#endif //(NTDDI_VERSION >= NTDDI_WIN10_RS5)

#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
#define NCRYPT_SSL_INTERFACE_VERSION_5  BCRYPT_MAKE_INTERFACE_VERSION(5,0)
#endif //(NTDDI_VERSION >= NTDDI_WIN10_VB)

typedef struct _NCRYPT_SSL_FUNCTION_TABLE 
{
    BCRYPT_INTERFACE_VERSION    Version;
    SslComputeClientAuthHashFn  ComputeClientAuthHash;
    SslComputeEapKeyBlockFn     ComputeEapKeyBlock;
    SslComputeFinishedHashFn    ComputeFinishedHash;
    SslCreateEphemeralKeyFn     CreateEphemeralKey;
    SslCreateHandshakeHashFn    CreateHandshakeHash;
    SslDecryptPacketFn          DecryptPacket;
    SslEncryptPacketFn          EncryptPacket;
    SslEnumCipherSuitesFn       EnumCipherSuites;
    SslExportKeyFn              ExportKey;
    SslFreeBufferFn             FreeBuffer;
    SslFreeObjectFn             FreeObject;
    SslGenerateMasterKeyFn      GenerateMasterKey;
    SslGenerateSessionKeysFn    GenerateSessionKeys;
    SslGetKeyPropertyFn         GetKeyProperty;
    SslGetProviderPropertyFn    GetProviderProperty;
    SslHashHandshakeFn          HashHandshake;
    SslImportMasterKeyFn        ImportMasterKey;
    SslImportKeyFn              ImportKey;
    SslLookupCipherSuiteInfoFn  LookupCipherSuiteInfo;
    SslOpenPrivateKeyFn         OpenPrivateKey;
    SslOpenProviderFn           OpenProvider;
    SslSignHashFn               SignHash;
    SslVerifySignatureFn        VerifySignature;
// End of entries in NCRYPT_SSL_INTERFACE_VERSION_1

#if (NTDDI_VERSION >= NTDDI_WIN7)
    SslLookupCipherLengthsFn    LookupCipherLengths;
    SslCreateClientAuthHashFn   CreateClientAuthHash;
    SslGetCipherSuitePRFHashAlgorithmFn GetCipherSuitePRFHashAlgorithm;
// End of entries in NCRYPT_SSL_INTERFACE_VERSION_2
#endif //(NTDDI_VERSION >= NTDDI_WIN7)

#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
    SslComputeSessionHashFn     ComputeSessionHash;
    SslGeneratePreMasterKeyFn   GeneratePreMasterKey;
    SslEnumEccCurvesFn          EnumEccCurves;
    SslExportKeyingMaterialFn   ExportKeyingMaterial;
// End of entries in NCRYPT_SSL_INTERFACE_VERSION_3
#endif //(NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
    SslExtractEarlyKeyFn        ExtractEarlyKey;
    SslExtractHandshakeKeyFn    ExtractHandshakeKey;
    SslExtractMasterKeyFn       ExtractMasterKey;
    SslExpandTrafficKeysFn      ExpandTrafficKeys;
    SslExpandWriteKeyFn         ExpandWriteKey;
    SslExpandExporterMasterKeyFn ExpandExporterMasterKey;
    SslEnumCipherSuitesExFn     EnumCipherSuitesEx;
// End of entries in NCRYPT_SSL_INTERFACE_VERSION_4
#endif //(NTDDI_VERSION >= NTDDI_WIN10_RS5)

#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
    SslExpandResumptionMasterKeyFn ExpandResumptionMasterKey;
    SslDuplicateTranscriptHashFn DuplicateTranscriptHash;
    SslExpandBinderKeyFn        ExpandBinderKey;
    SslExpandPreSharedKeyFn     ExpandPreSharedKey;
// End of entries in NCRYPT_SSL_INTERFACE_VERSION_5
#endif //(NTDDI_VERSION >= NTDDI_WIN10_VB)
} NCRYPT_SSL_FUNCTION_TABLE;

NTSTATUS
WINAPI
GetSChannelInterface(
    _In_   LPCWSTR pszProviderName,
    _Out_  NCRYPT_SSL_FUNCTION_TABLE **ppFunctionTable,
    _In_   DWORD dwFlags);

typedef NTSTATUS
(WINAPI * GetSChannelInterfaceFn)(
    _In_    LPCWSTR pszProviderName,
    _Out_   NCRYPT_SSL_FUNCTION_TABLE **ppFunctionTable,
    _In_    ULONG dwFlags);

#ifdef KERNEL_MODE_CNG
#define CRYPT_PROVIDER_IOCTL__GET_SCHANNEL_INTERFACE \
    CTL_CODE(FILE_DEVICE_CRYPT_PROVIDER, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS)
#endif

SECURITY_STATUS
WINAPI
SslInitializeInterface(
    _In_    LPCWSTR pszProviderName,
    _Out_   NCRYPT_SSL_FUNCTION_TABLE *pFunctionTable,
    _In_    DWORD    dwFlags);

typedef SECURITY_STATUS
(WINAPI * SslInitializeInterfaceFn)(
    _In_    LPCWSTR pszProviderName,
    _Out_   NCRYPT_SSL_FUNCTION_TABLE *pFunctionTable,
    _In_    DWORD    dwFlags);


SECURITY_STATUS
WINAPI
SslIncrementProviderReferenceCount(
    _In_    NCRYPT_PROV_HANDLE hSslProvider);
    
SECURITY_STATUS
WINAPI
SslDecrementProviderReferenceCount(
    _In_    NCRYPT_PROV_HANDLE hSslProvider);

#ifdef __cplusplus
}       // Balance extern "C" above
#endif

#endif // __SSL_PROVIDER_H__

