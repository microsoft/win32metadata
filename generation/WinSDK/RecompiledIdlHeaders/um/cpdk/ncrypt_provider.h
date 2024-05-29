
//
#include <winapifamily.h>
//
//
#pragma once

#ifdef __cplusplus
extern "C" {
#endif


//

//
typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptOpenStorageProviderFn)(
    _Out_   NCRYPT_PROV_HANDLE *phProvider,
    _In_opt_ LPCWSTR pszProviderName,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptEnumAlgorithmsFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    DWORD   dwAlgClass,
    _Out_   DWORD * pdwAlgCount,
    _Outptr_result_buffer_(*pdwAlgCount) NCryptAlgorithmName **ppAlgList,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptIsAlgSupportedFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    LPCWSTR pszAlgId,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptEnumKeysFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_opt_ LPCWSTR pszScope,
    _Outptr_ NCryptKeyName **ppKeyName,
    _Inout_ PVOID * ppEnumState,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptEnumStorageProvidersFn)(
    _Out_   DWORD * pdwProviderCount,
    _Outptr_result_buffer_(*pdwProviderCount) NCryptProviderName **ppProviderList,
    _In_    DWORD   dwFlags);

//
//

typedef SECURITY_STATUS
(WINAPI * NCryptFreeBufferFn)(
    _Pre_notnull_ PVOID   pvInput);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptOpenKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _Out_   NCRYPT_KEY_HANDLE *phKey,
    _In_    LPCWSTR pszKeyName,
    _In_opt_ DWORD  dwLegacyKeySpec,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptCreatePersistedKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _Out_   NCRYPT_KEY_HANDLE *phKey,
    _In_    LPCWSTR pszAlgId,
    _In_opt_ LPCWSTR pszKeyName,
    _In_    DWORD   dwLegacyKeySpec,
    _In_    DWORD   dwFlags);

//
//

typedef struct __NCRYPT_UI_POLICY_BLOB
{
    DWORD   dwVersion;
    DWORD   dwFlags;
    DWORD   cbCreationTitle;
    DWORD   cbFriendlyName;
    DWORD   cbDescription;
    // creation title string
    // friendly name string
    // description string
} NCRYPT_UI_POLICY_BLOB;

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptGetProviderPropertyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    LPCWSTR pszProperty,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptGetKeyPropertyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    LPCWSTR pszProperty,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptSetProviderPropertyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    LPCWSTR pszProperty,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _In_    DWORD   dwFlags);

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptSetKeyPropertyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    LPCWSTR pszProperty,
    _In_reads_bytes_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _In_    DWORD   dwFlags);

//
//
typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptFinalizeKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptEncryptFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_reads_bytes_opt_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _In_opt_    VOID *pPaddingInfo,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptDecryptFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_reads_bytes_opt_(cbInput) PBYTE pbInput,
    _In_    DWORD   cbInput,
    _In_opt_    VOID *pPaddingInfo,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptImportKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hImportKey,
    _In_    LPCWSTR pszBlobType,
    _In_opt_ NCryptBufferDesc *pParameterList,
    _Out_   NCRYPT_KEY_HANDLE *phKey,
    _In_reads_bytes_(cbData) PBYTE pbData,
    _In_    DWORD   cbData,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptExportKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_opt_ NCRYPT_KEY_HANDLE hExportKey,
    _In_    LPCWSTR pszBlobType,
    _In_opt_ NCryptBufferDesc *pParameterList,
    _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PBYTE pbOutput,
    _In_    DWORD   cbOutput,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptSignHashFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_opt_    VOID *pPaddingInfo,
    _In_reads_bytes_(cbHashValue) PBYTE pbHashValue,
    _In_    DWORD   cbHashValue,
    _Out_writes_bytes_to_opt_(cbSignature, *pcbResult) PBYTE pbSignature,
    _In_    DWORD   cbSignature,
    _Out_   DWORD * pcbResult,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptVerifySignatureFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_opt_    VOID *pPaddingInfo,
    _In_reads_bytes_(cbHashValue) PBYTE pbHashValue,
    _In_    DWORD   cbHashValue,
    _In_reads_bytes_(cbSignature) PBYTE pbSignature,
    _In_    DWORD   cbSignature,
    _In_    DWORD   dwFlags);

//
//

typedef SECURITY_STATUS
(WINAPI * NCryptDeleteKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey,
    _In_    DWORD   dwFlags);

//
//

typedef SECURITY_STATUS
(WINAPI * NCryptFreeProviderFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider);

typedef SECURITY_STATUS
(WINAPI * NCryptFreeKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hKey);

typedef SECURITY_STATUS
(WINAPI * NCryptFreeSecretFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_SECRET_HANDLE hSharedSecret);

//
//

typedef SECURITY_STATUS
(WINAPI * NCryptPromptUserFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_opt_ NCRYPT_KEY_HANDLE hKey,
    _In_    LPCWSTR pszOperation,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptNotifyChangeKeyFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _Inout_ HANDLE *phEvent,
    _In_    DWORD   dwFlags);

//
//
_Check_return_
typedef SECURITY_STATUS
(WINAPI * NCryptSecretAgreementFn)(
    _In_    NCRYPT_PROV_HANDLE hProvider,
    _In_    NCRYPT_KEY_HANDLE hPrivKey,
    _In_    NCRYPT_KEY_HANDLE hPubKey,
    _Out_   NCRYPT_SECRET_HANDLE *phAgreedSecret,
    _In_    DWORD   dwFlags);

//
//

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptDeriveKeyFn)(
    _In_        NCRYPT_PROV_HANDLE   hProvider,
    _In_        NCRYPT_SECRET_HANDLE hSharedSecret,
    _In_        LPCWSTR              pwszKDF,
    _In_opt_    NCryptBufferDesc     *pParameterList,
    _Out_writes_bytes_to_opt_(cbDerivedKey, *pcbResult) PBYTE pbDerivedKey,
    _In_        DWORD                cbDerivedKey,
    _Out_       DWORD                *pcbResult,
    _In_        ULONG                dwFlags);

//
//
#if (NTDDI_VERSION >= NTDDI_WIN8)

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptKeyDerivationFn)(
    _In_        NCRYPT_PROV_HANDLE  hProvider,
    _In_        NCRYPT_KEY_HANDLE   hKey,
    _In_opt_    NCryptBufferDesc    *pParameterList,
    _Out_writes_bytes_to_(cbDerivedKey, *pcbResult) PUCHAR pbDerivedKey,
    _In_        DWORD               cbDerivedKey,
    _Out_       DWORD               *pcbResult,
    _In_        ULONG               dwFlags);

#endif  // (NTDDI_VERSION >= NTDDI_WIN8)
//
//
#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptCreateClaimFn)(
    _In_        NCRYPT_PROV_HANDLE  hProv,
    _In_opt_    NCRYPT_KEY_HANDLE   hSubjectKey,
    _In_opt_    NCRYPT_KEY_HANDLE   hAuthorityKey,
    _In_        DWORD               dwClaimType,
    _In_opt_    NCryptBufferDesc    *pParameterList,
    _Out_writes_bytes_to_opt_(cbClaimBlob, *pcbResult) PBYTE pbClaimBlob,
    _In_        DWORD               cbClaimBlob,
    _Out_       DWORD               *pcbResult,
    _In_        DWORD               dwFlags);

#endif  // (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
//
//
#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

typedef _Check_return_ SECURITY_STATUS
(WINAPI * NCryptVerifyClaimFn)(
    _In_        NCRYPT_PROV_HANDLE  hProv,
    _In_        NCRYPT_KEY_HANDLE   hSubjectKey,
    _In_opt_    NCRYPT_KEY_HANDLE   hAuthorityKey,
    _In_        DWORD               dwClaimType,
    _In_opt_    NCryptBufferDesc    *pParameterList,
    _In_reads_bytes_(cbClaimBlob) PBYTE pbClaimBlob,
    _In_        DWORD               cbClaimBlob,
    _Out_       NCryptBufferDesc    *pOutput,
    _In_        DWORD               dwFlags);

#endif  // (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
//
//

typedef struct _NCRYPT_KEY_STORAGE_FUNCTION_TABLE
{
    BCRYPT_INTERFACE_VERSION        Version;

    //
    // NCRYPT_KEY_STORAGE_INTERFACE_VERSION interface
    //

    NCryptOpenStorageProviderFn     OpenProvider;
    NCryptOpenKeyFn                 OpenKey;
    NCryptCreatePersistedKeyFn      CreatePersistedKey;
    NCryptGetProviderPropertyFn     GetProviderProperty;
    NCryptGetKeyPropertyFn          GetKeyProperty;
    NCryptSetProviderPropertyFn     SetProviderProperty;
    NCryptSetKeyPropertyFn          SetKeyProperty;
    NCryptFinalizeKeyFn             FinalizeKey;
    NCryptDeleteKeyFn               DeleteKey;
    NCryptFreeProviderFn            FreeProvider;
    NCryptFreeKeyFn                 FreeKey;
    NCryptFreeBufferFn              FreeBuffer;
    NCryptEncryptFn                 Encrypt;
    NCryptDecryptFn                 Decrypt;
    NCryptIsAlgSupportedFn          IsAlgSupported;
    NCryptEnumAlgorithmsFn          EnumAlgorithms;
    NCryptEnumKeysFn                EnumKeys;
    NCryptImportKeyFn               ImportKey;
    NCryptExportKeyFn               ExportKey;
    NCryptSignHashFn                SignHash;
    NCryptVerifySignatureFn         VerifySignature;
    NCryptPromptUserFn              PromptUser;
    NCryptNotifyChangeKeyFn         NotifyChangeKey;
    NCryptSecretAgreementFn         SecretAgreement;
    NCryptDeriveKeyFn               DeriveKey;
    NCryptFreeSecretFn              FreeSecret;

#if (NTDDI_VERSION >= NTDDI_WIN8)
    // NCRYPT_KEY_STORAGE_INTERFACE_VERSION_2 interface
    NCryptKeyDerivationFn           KeyDerivation;
#endif // (NTDDI_VERSION >= NTDDI_WIN8)

#if (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
    // NCRYPT_KEY_STORAGE_INTERFACE_VERSION_3 interface
    NCryptCreateClaimFn             CreateClaim;
    NCryptVerifyClaimFn             VerifyClaim;
#endif // (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)

} NCRYPT_KEY_STORAGE_FUNCTION_TABLE;

_Check_return_
NTSTATUS
WINAPI
GetKeyStorageInterface(
    _In_   LPCWSTR  pszProviderName,
    _Out_  NCRYPT_KEY_STORAGE_FUNCTION_TABLE **ppFunctionTable,
    _In_   DWORD    dwFlags);

typedef _Check_return_ NTSTATUS
(WINAPI * GetKeyStorageInterfaceFn)(
    _In_    LPCWSTR pszProviderName,
    _Out_   NCRYPT_KEY_STORAGE_FUNCTION_TABLE **ppFunctionTable,
    _In_    ULONG dwFlags);


//

//

#ifdef __cplusplus
} // extern "C"
#endif
//
