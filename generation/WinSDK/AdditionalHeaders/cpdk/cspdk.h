/*++

Copyright (C) Microsoft Corporation, 2000

Module Name:

    cspdk

Abstract:

    This header file contains the definitions and references that every CSP
    needs to know.

Author:

    Doug Barlow (dbarlow) 1/27/2000

--*/

#ifndef _CSPDK_H_
#define _CSPDK_H_
#ifdef __cplusplus
extern "C" {
#endif

#define CRYPT_PROVSTRUC_VERSION_V3           3
#define CRYPT_MAX_PROVIDER_ID              999
#define CRYPT_SIG_RESOURCE_VERSION  0x00000100
#define CRYPT_EXTERNAL_SIGNATURE_LENGTH    136
#define CRYPT_SIG_RESOURCE_NUMBER        0x29A
#define CRYPT_SIG_RESOURCE        TEXT("#666")
#define CRYPT_MAC_RESOURCE_NUMBER        0x29B
#define CRYPT_MAC_RESOURCE        TEXT("#667")

// Exponentiation Offload Reg Location
#define EXPO_OFFLOAD_REG_VALUE "ExpoOffload"
#define EXPO_OFFLOAD_FUNC_NAME "OffloadModExpo"

//
// Exponentiation Offload Entry Point Prototype
//

typedef struct _OFFLOAD_PRIVATE_KEY
{
    DWORD dwVersion;            
    DWORD cbPrime1;             
    DWORD cbPrime2;             
    PBYTE pbPrime1;             // "p"
    PBYTE pbPrime2;             // "q"
} OFFLOAD_PRIVATE_KEY, *POFFLOAD_PRIVATE_KEY;

#define CUR_OFFLOAD_VERSION             1

typedef BOOL (WINAPI *PFN_OFFLOAD_MOD_EXPO)(
    IN              PBYTE pbBase,
    IN              PBYTE pbExponent,
    IN              DWORD cbExponent,
    IN              PBYTE pbModulus,
    IN              DWORD cbModulus,
    OUT             PBYTE pbResult,
    IN  OPTIONAL    PVOID pvOffloadPrivateKey,
    IN              DWORD dwFlags);

//
// Callback prototypes
//

typedef BOOL (WINAPI *CRYPT_VERIFY_IMAGE_A)(LPCSTR  szImage, CONST BYTE *pbSigData);
typedef BOOL (WINAPI *CRYPT_VERIFY_IMAGE_W)(LPCWSTR szImage, CONST BYTE *pbSigData);
typedef void (WINAPI *CRYPT_RETURN_HWND)(HWND *phWnd);


//
// Structures for CSPs
//

typedef struct _VTableProvStruc {
    DWORD                Version;
    CRYPT_VERIFY_IMAGE_A FuncVerifyImage;
    CRYPT_RETURN_HWND    FuncReturnhWnd;
    DWORD                dwProvType;
    BYTE                *pbContextInfo;
    DWORD                cbContextInfo;
    LPSTR                pszProvName;
} VTableProvStruc,      *PVTableProvStruc;

typedef struct _VTableProvStrucW {
    DWORD                Version;
    CRYPT_VERIFY_IMAGE_W FuncVerifyImage;
    CRYPT_RETURN_HWND    FuncReturnhWnd;
    DWORD                dwProvType;
    BYTE                *pbContextInfo;
    DWORD                cbContextInfo;
    LPWSTR               pszProvName;
} VTableProvStrucW,     *PVTableProvStrucW;

typedef struct {
    DWORD dwVersion;
    DWORD dwCrcOffset;
    BYTE rgbSignature[88];  // 1024-bit key, plus 2 DWORDs of padding.
} InFileSignatureResource;


//
// ===========================================================================
// CSP Entry points.
// ===========================================================================
//

/*
 -  CPAcquireContext
 -
 *  Purpose:
 *               The CPAcquireContext function is used to acquire a context
 *               handle to a cryptographic service provider (CSP).
 *
 *
 *  Parameters:
 *               OUT phProv         -  Handle to a CSP
 *               IN  szContainer    -  Pointer to a string which is the
 *                                     identity of the logged on user
 *               IN  dwFlags        -  Flags values
 *               IN  pVTable        -  Pointer to table of function pointers
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPAcquireContext(
    __out HCRYPTPROV *phProv,
    __in LPCSTR szContainer,
    __in DWORD dwFlags,
    __in PVTableProvStruc pVTable);


/*
 -  CPAcquireContextW
 -
 *  Purpose:
 *               The CPAcquireContextW function is used to acquire a context
 *               handle to a cryptographic service provider (CSP). using
 *               UNICODE strings.  This is an optional entry point for a CSP.
 *               It is not used prior to Whistler.  There it is used if
 *               exported by the CSP image, otherwise any string conversions
 *               are done, and CPAcquireContext is called.
 *
 *
 *  Parameters:
 *               OUT phProv         -  Handle to a CSP
 *               IN  szContainer    -  Pointer to a string which is the
 *                                     identity of the logged on user
 *               IN  dwFlags        -  Flags values
 *               IN  pVTable        -  Pointer to table of function pointers
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPAcquireContextW(
    OUT HCRYPTPROV *phProv,
    IN  LPCWSTR szContainer,
    IN  DWORD dwFlags,
    IN  PVTableProvStrucW pVTable);


/*
 -      CPReleaseContext
 -
 *      Purpose:
 *               The CPReleaseContext function is used to release a
 *               context created by CryptAcquireContext.
 *
 *     Parameters:
 *               IN  phProv        -  Handle to a CSP
 *               IN  dwFlags       -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPReleaseContext(
    __in  HCRYPTPROV hProv,
    __in  DWORD dwFlags);


/*
 -  CPGenKey
 -
 *  Purpose:
 *                Generate cryptographic keys
 *
 *
 *  Parameters:
 *               IN      hProv   -  Handle to a CSP
 *               IN      Algid   -  Algorithm identifier
 *               IN      dwFlags -  Flags values
 *               OUT     phKey   -  Handle to a generated key
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPGenKey(
    __in IN  HCRYPTPROV hProv,
    __in IN  ALG_ID Algid,
    __in IN  DWORD dwFlags,
    __out OUT HCRYPTKEY *phKey);


/*
 -  CPDeriveKey
 -
 *  Purpose:
 *                Derive cryptographic keys from base data
 *
 *
 *  Parameters:
 *               IN      hProv      -  Handle to a CSP
 *               IN      Algid      -  Algorithm identifier
 *               IN      hBaseData -   Handle to base data
 *               IN      dwFlags    -  Flags values
 *               OUT     phKey      -  Handle to a generated key
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPDeriveKey(
    __in HCRYPTPROV hProv,
    __in ALG_ID Algid,
    __in HCRYPTHASH hHash,
    __in DWORD dwFlags,
    __inout HCRYPTKEY *phKey);


/*
 -  CPDestroyKey
 -
 *  Purpose:
 *                Destroys the cryptographic key that is being referenced
 *                with the hKey parameter
 *
 *
 *  Parameters:
 *               IN      hProv  -  Handle to a CSP
 *               IN      hKey   -  Handle to a key
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPDestroyKey(
    __in  HCRYPTPROV hProv,
    __in  HCRYPTKEY hKey);


/*
 -  CPSetKeyParam
 -
 *  Purpose:
 *                Allows applications to customize various aspects of the
 *                operations of a key
 *
 *  Parameters:
 *               IN      hProv   -  Handle to a CSP
 *               IN      hKey    -  Handle to a key
 *               IN      dwParam -  Parameter number
 *               IN      pbData  -  Pointer to data
 *               IN      dwFlags -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPSetKeyParam(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTKEY hKey,
    __in IN  DWORD dwParam,
    __in IN  CONST BYTE *pbData,
    __in IN  DWORD dwFlags);


/*
 -  CPGetKeyParam
 -
 *  Purpose:
 *                Allows applications to get various aspects of the
 *                operations of a key
 *
 *  Parameters:
 *               IN      hProv      -  Handle to a CSP
 *               IN      hKey       -  Handle to a key
 *               IN      dwParam    -  Parameter number
 *               OUT     pbData     -  Pointer to data
 *               IN      pdwDataLen -  Length of parameter data
 *               IN      dwFlags    -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPGetKeyParam(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTKEY hKey,
    __in IN  DWORD dwParam,
    __out_bcount_part_opt(*pcbDataLen, *pcbDataLen) OUT LPBYTE pbData,
    __inout IN OUT LPDWORD pcbDataLen,
    __in IN  DWORD dwFlags);


/*
 -  CPSetProvParam
 -
 *  Purpose:
 *                Allows applications to customize various aspects of the
 *                operations of a provider
 *
 *  Parameters:
 *               IN      hProv   -  Handle to a CSP
 *               IN      dwParam -  Parameter number
 *               IN      pbData  -  Pointer to data
 *               IN      dwFlags -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPSetProvParam(
    __in HCRYPTPROV hProv,
    __in DWORD dwParam,
    _When_(dwFlags == PP_KEYSET_SEC_DESCR, _At_((PSECURITY_DESCRIPTOR)pbData, __in))
    _When_(dwFlags == PP_UI_PROMPT, _At_((LPWSTR)pbData, __in))
    _When_(dwFlags == PP_DELETEKEY, _At_((DWORD *)pbData, __in))
    __in CONST BYTE *pbData,
    __in DWORD dwFlags);


/*
 -  CPGetProvParam
 -
 *  Purpose:
 *                Allows applications to get various aspects of the
 *                operations of a provider
 *
 *  Parameters:
 *               IN      hProv      -  Handle to a CSP
 *               IN      dwParam    -  Parameter number
 *               OUT     pbData     -  Pointer to data
 *               IN OUT  pdwDataLen -  Length of parameter data
 *               IN      dwFlags    -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPGetProvParam(
    __in IN  HCRYPTPROV hProv,
    __in IN  DWORD dwParam,
    __out_bcount_part_opt(*pcbDataLen, *pcbDataLen) OUT LPBYTE pbData,
    __inout IN OUT LPDWORD pcbDataLen,
    __in IN  DWORD dwFlags);


/*
 -  CPSetHashParam
 -
 *  Purpose:
 *                Allows applications to customize various aspects of the
 *                operations of a hash
 *
 *  Parameters:
 *               IN      hProv   -  Handle to a CSP
 *               IN      hHash   -  Handle to a hash
 *               IN      dwParam -  Parameter number
 *               IN      pbData  -  Pointer to data
 *               IN      dwFlags -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPSetHashParam(
    __in HCRYPTPROV hProv,
    __in HCRYPTHASH hHash,
    __in DWORD dwParam,
    __in CONST BYTE *pbData,
    __in DWORD dwFlags);


/*
 -  CPGetHashParam
 -
 *  Purpose:
 *                Allows applications to get various aspects of the
 *                operations of a hash
 *
 *  Parameters:
 *               IN      hProv      -  Handle to a CSP
 *               IN      hHash      -  Handle to a hash
 *               IN      dwParam    -  Parameter number
 *               OUT     pbData     -  Pointer to data
 *               IN      pdwDataLen -  Length of parameter data
 *               IN      dwFlags    -  Flags values
 *
 *  Returns:
 */

// Former WIN8MQ Suppression(s), see https://osgwiki.com/wiki/REQUIRES_WIN8MQ_CODE_FIX: 
// BEGIN_REQUIRES_WIN8MQ_CODE_FIX(28285, "Commented range annotation should apply "
// "but MAX_HASH_SIZE is not in scope, and a simple copy won't work because "
// "scp and dss share this declaration but the bodies (and values for "
// "MAX_HASH_SIZE) differ.")
__success(return != FALSE)
extern BOOL WINAPI
CPGetHashParam(
    __in                                            HCRYPTPROV hProv,
    __in                                            HCRYPTHASH hHash,
    __in                                            DWORD dwParam,
    __out_bcount_part_opt(*pwDataLen, *pwDataLen)   LPBYTE pbData,
    __inout /* __deref_out_range(16, MAX_HASH_SIZE) */   DWORD   *pwDataLen,
    __in                                            DWORD dwFlags);
// END_REQUIRES_WIN8MQ_CODE_FIX

/*
 -  CPExportKey
 -
 *  Purpose:
 *                Export cryptographic keys out of a CSP in a secure manner
 *
 *
 *  Parameters:
 *               IN  hProv         - Handle to the CSP user
 *               IN  hKey          - Handle to the key to export
 *               IN  hPubKey       - Handle to exchange public key value of
 *                                   the destination user
 *               IN  dwBlobType    - Type of key blob to be exported
 *               IN  dwFlags       - Flags values
 *               OUT pbData        -     Key blob data
 *               IN OUT pdwDataLen - Length of key blob in bytes
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPExportKey(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTKEY hKey,
    __in IN  HCRYPTKEY hPubKey,
    __in IN  DWORD dwBlobType,
    __in IN  DWORD dwFlags,
    __out_bcount_part_opt(*pcbDataLen, *pcbDataLen) OUT LPBYTE pbData,
    __inout IN OUT LPDWORD pcbDataLen);


/*
 -  CPImportKey
 -
 *  Purpose:
 *                Import cryptographic keys
 *
 *
 *  Parameters:
 *               IN  hProv     -  Handle to the CSP user
 *               IN  pbData    -  Key blob data
 *               IN  dwDataLen -  Length of the key blob data
 *               IN  hPubKey   -  Handle to the exchange public key value of
 *                                the destination user
 *               IN  dwFlags   -  Flags values
 *               OUT phKey     -  Pointer to the handle to the key which was
 *                                Imported
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPImportKey(
    __in IN  HCRYPTPROV hProv,
    __in_bcount(cbDataLen) IN  CONST BYTE *pbData,
    __in IN  DWORD cbDataLen,
    __in IN  HCRYPTKEY hPubKey,
    __in IN  DWORD dwFlags,
    __out OUT HCRYPTKEY *phKey);


/*
 -  CPEncrypt
 -
 *  Purpose:
 *                Encrypt data
 *
 *
 *  Parameters:
 *               IN  hProv         -  Handle to the CSP user
 *               IN  hKey          -  Handle to the key
 *               IN  hHash         -  Optional handle to a hash
 *               IN  Final         -  Boolean indicating if this is the final
 *                                    block of plaintext
 *               IN  dwFlags       -  Flags values
 *               IN OUT pbData     -  Data to be encrypted
 *               IN OUT pdwDataLen -  Pointer to the length of the data to be
 *                                    encrypted
 *               IN dwBufLen       -  Size of Data buffer
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPEncrypt(
    __in HCRYPTPROV hProv,
    __in HCRYPTKEY hKey,
    __in HCRYPTHASH hHash,
    __in BOOL fFinal,
    __in DWORD dwFlags,
    __inout_bcount_part_opt(cbBufLen, *pcbDataLen) IN OUT LPBYTE pbData,
    __inout LPDWORD pcbDataLen,
    __in DWORD cbBufLen);


/*
 -  CPDecrypt
 -
 *  Purpose:
 *                Decrypt data
 *
 *
 *  Parameters:
 *               IN  hProv         -  Handle to the CSP user
 *               IN  hKey          -  Handle to the key
 *               IN  hHash         -  Optional handle to a hash
 *               IN  Final         -  Boolean indicating if this is the final
 *                                    block of ciphertext
 *               IN  dwFlags       -  Flags values
 *               IN OUT pbData     -  Data to be decrypted
 *               IN OUT pdwDataLen -  Pointer to the length of the data to be
 *                                    decrypted
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPDecrypt(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTKEY hKey,
    __in IN  HCRYPTHASH hHash,
    __in IN  BOOL fFinal,
    __in IN  DWORD dwFlags,
    __inout_bcount_part_opt(*pcbDataLen, *pcbDataLen) IN OUT LPBYTE pbData,
    __inout IN OUT LPDWORD pcbDataLen);


/*
 -  CPCreateHash
 -
 *  Purpose:
 *                initate the hashing of a stream of data
 *
 *
 *  Parameters:
 *               IN  hUID    -  Handle to the user identifcation
 *               IN  Algid   -  Algorithm identifier of the hash algorithm
 *                              to be used
 *               IN  hKey   -   Optional handle to a key
 *               IN  dwFlags -  Flags values
 *               OUT pHash   -  Handle to hash object
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPCreateHash(
    __in IN  HCRYPTPROV hProv,
    __in IN  ALG_ID Algid,
    __in IN  HCRYPTKEY hKey,
    __in IN  DWORD dwFlags,
    __out OUT HCRYPTHASH *phHash);


/*
 -  CPHashData
 -
 *  Purpose:
 *                Compute the cryptograghic hash on a stream of data
 *
 *
 *  Parameters:
 *               IN  hProv     -  Handle to the user identifcation
 *               IN  hHash     -  Handle to hash object
 *               IN  pbData    -  Pointer to data to be hashed
 *               IN  dwDataLen -  Length of the data to be hashed
 *               IN  dwFlags   -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPHashData(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTHASH hHash,
    __in_bcount(cbDataLen) IN  CONST BYTE *pbData,
    __in IN  DWORD cbDataLen,
    __in IN  DWORD dwFlags);


/*
 -  CPHashSessionKey
 -
 *  Purpose:
 *                Compute the cryptograghic hash on a key object.
 *
 *
 *  Parameters:
 *               IN  hProv     -  Handle to the user identifcation
 *               IN  hHash     -  Handle to hash object
 *               IN  hKey      -  Handle to a key object
 *               IN  dwFlags   -  Flags values
 *
 *  Returns:
 *               CRYPT_FAILED
 *               CRYPT_SUCCEED
 */

__success(return != FALSE)
extern BOOL WINAPI
CPHashSessionKey(
    __in  HCRYPTPROV hProv,
    __in  HCRYPTHASH hHash,
    __in  HCRYPTKEY hKey,
    __in  DWORD dwFlags);


/*
 -  CPSignHash
 -
 *  Purpose:
 *                Create a digital signature from a hash
 *
 *
 *  Parameters:
 *               IN  hProv        -  Handle to the user identifcation
 *               IN  hHash        -  Handle to hash object
 *               IN  dwKeySpec    -  Key pair to that is used to sign with
 *               IN  sDescription -  Description of data to be signed
 *               IN  dwFlags      -  Flags values
 *               OUT pbSignature  -  Pointer to signature data
 *               IN OUT dwHashLen -  Pointer to the len of the signature data
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPSignHash(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTHASH hHash,
    __in IN  DWORD dwKeySpec,
    __in IN  LPCWSTR szDescription,
    __in IN  DWORD dwFlags,
    __out_bcount_part_opt(*pcbSigLen, *pcbSigLen) OUT LPBYTE pbSignature,
    __inout IN OUT LPDWORD pcbSigLen);


/*
 -  CPDestroyHash
 -
 *  Purpose:
 *                Destroy the hash object
 *
 *
 *  Parameters:
 *               IN  hProv     -  Handle to the user identifcation
 *               IN  hHash     -  Handle to hash object
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPDestroyHash(
    __in  HCRYPTPROV hProv,
    __in  HCRYPTHASH hHash);


/*
 -  CPVerifySignature
 -
 *  Purpose:
 *                Used to verify a signature against a hash object
 *
 *
 *  Parameters:
 *               IN  hProv        -  Handle to the user identifcation
 *               IN  hHash        -  Handle to hash object
 *               IN  pbSignture   -  Pointer to signature data
 *               IN  dwSigLen     -  Length of the signature data
 *               IN  hPubKey      -  Handle to the public key for verifying
 *                                   the signature
 *               IN  sDescription -  String describing the signed data
 *               IN  dwFlags      -  Flags values
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPVerifySignature(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTHASH hHash,
    __in_bcount(cbSigLen) IN  CONST BYTE *pbSignature,
    __in IN  DWORD cbSigLen,
    __in IN  HCRYPTKEY hPubKey,
    __in IN  LPCWSTR szDescription,
    __in IN  DWORD dwFlags);


/*
 -  CPGenRandom
 -
 *  Purpose:
 *                Used to fill a buffer with random bytes
 *
 *
 *  Parameters:
 *               IN  hProv         -  Handle to the user identifcation
 *               IN  dwLen         -  Number of bytes of random data requested
 *               IN OUT pbBuffer   -  Pointer to the buffer where the random
 *                                    bytes are to be placed
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPGenRandom(
    __in IN  HCRYPTPROV hProv,
    __in IN  DWORD cbLen,
    __out_bcount_full(cbLen) OUT LPBYTE pbBuffer);


/*
 -  CPGetUserKey
 -
 *  Purpose:
 *                Gets a handle to a permanent user key
 *
 *
 *  Parameters:
 *               IN  hProv      -  Handle to the user identifcation
 *               IN  dwKeySpec  -  Specification of the key to retrieve
 *               OUT phUserKey  -  Pointer to key handle of retrieved key
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPGetUserKey(
    __in IN  HCRYPTPROV hProv,
    __in IN  DWORD dwKeySpec,
    __out OUT HCRYPTKEY *phUserKey);


/*
 -  CPDuplicateHash
 -
 *  Purpose:
 *                Duplicates the state of a hash and returns a handle to it.
 *                This is an optional entry.  Typically it only occurs in
 *                SChannel related CSPs.
 *
 *  Parameters:
 *               IN      hUID           -  Handle to a CSP
 *               IN      hHash          -  Handle to a hash
 *               IN      pdwReserved    -  Reserved
 *               IN      dwFlags        -  Flags
 *               IN      phHash         -  Handle to the new hash
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPDuplicateHash(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTHASH hHash,
    __reserved IN  LPDWORD pdwReserved,
    __in IN  DWORD dwFlags,
    __out OUT HCRYPTHASH *phHash);


/*
 -  CPDuplicateKey
 -
 *  Purpose:
 *                Duplicates the state of a key and returns a handle to it.
 *                This is an optional entry.  Typically it only occurs in
 *                SChannel related CSPs.
 *
 *  Parameters:
 *               IN      hUID           -  Handle to a CSP
 *               IN      hKey           -  Handle to a key
 *               IN      pdwReserved    -  Reserved
 *               IN      dwFlags        -  Flags
 *               IN      phKey          -  Handle to the new key
 *
 *  Returns:
 */

__success(return != FALSE)
extern BOOL WINAPI
CPDuplicateKey(
    __in IN  HCRYPTPROV hProv,
    __in IN  HCRYPTKEY hKey,
    __reserved IN  LPDWORD pdwReserved,
    __in IN  DWORD dwFlags,
    __out OUT HCRYPTKEY *phKey);

#ifdef __cplusplus
}
#endif
#endif // _CSPDK_H_

