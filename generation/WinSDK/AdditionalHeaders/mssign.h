#include <wincrypt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define	SIGNER_SUBJECT_FILE		            0x01
#define	SIGNER_SUBJECT_BLOB		            0x02

#define SIGNER_NO_ATTR			            0x00
#define SIGNER_AUTHCODE_ATTR	            0x01

#define	PVK_TYPE_FILE_NAME		            0x01
#define	PVK_TYPE_KEYCONTAINER               0x02

#define	SIGNER_CERT_POLICY_STORE			0x01
#define	SIGNER_CERT_POLICY_CHAIN			0x02
#define	SIGNER_CERT_POLICY_SPC				0x04
#define SIGNER_CERT_POLICY_CHAIN_NO_ROOT	0x08

#define	SIGNER_CERT_SPC_FILE	            0x01
#define	SIGNER_CERT_STORE		            0x02
#define SIGNER_CERT_SPC_CHAIN	            0x03

#define SIGNER_TIMESTAMP_AUTHENTICODE       1
#define SIGNER_TIMESTAMP_RFC3161            2
#define SIG_APPEND                          0x1000

typedef HRESULT (WINAPI *PFN_AUTHENTICODE_DIGEST_SIGN)(
    _In_ PCCERT_CONTEXT pSigningCert,                        
    _In_opt_ PCRYPT_DATA_BLOB pMetadataBlob,                 
    _In_ ALG_ID digestAlgId,                                 
    _In_ PBYTE pbToBeSignedDigest, 
    _In_ DWORD cbToBeSignedDigest,                           
    _Out_ PCRYPT_DATA_BLOB pSignedDigest      
    );

typedef HRESULT (WINAPI *PFN_AUTHENTICODE_DIGEST_SIGN_EX)(
    _In_opt_ PCRYPT_DATA_BLOB pMetadataBlob,         
    _In_ ALG_ID digestAlgId,                                 
    _In_ PBYTE pbToBeSignedDigest, 
    _In_ DWORD cbToBeSignedDigest,                           
    _Out_ PCRYPT_DATA_BLOB pSignedDigest,                    
    _Out_ PCCERT_CONTEXT* ppSignerCert,                      
    _Inout_ HCERTSTORE hCertChainStore  
    );

typedef HRESULT (WINAPI *PFN_AUTHENTICODE_DIGEST_SIGN_EX_WITHFILEHANDLE)(
    _In_opt_ PCRYPT_DATA_BLOB pMetadataBlob,                 
    _In_ ALG_ID digestAlgId,                                 
    _In_ PBYTE pbToBeSignedDigest, 
    _In_ DWORD cbToBeSignedDigest,                           
    _In_ HANDLE hFile,
    _Out_ PCRYPT_DATA_BLOB pSignedDigest,                  
    _Out_ PCCERT_CONTEXT* ppSignerCert,                      
    _Inout_ HCERTSTORE hCertChainStore   
    );

typedef HRESULT (WINAPI *PFN_AUTHENTICODE_DIGEST_SIGN_WITHFILEHANDLE)(
    _In_ PCCERT_CONTEXT pSigningCert,                        
    _In_opt_ PCRYPT_DATA_BLOB pMetadataBlob,                 
    _In_ ALG_ID digestAlgId,                                 
    _In_ PBYTE pbToBeSignedDigest, 
    _In_ DWORD cbToBeSignedDigest,    
    _In_ HANDLE hFile,                   
    _Out_ PCRYPT_DATA_BLOB pSignedDigest 
    );

typedef struct _SIGNER_ATTR_AUTHCODE {
    DWORD   cbSize;
    BOOL    fCommercial;
    BOOL    fIndividual;
    LPCWSTR pwszName;
    LPCWSTR pwszInfo;
} SIGNER_ATTR_AUTHCODE, *PSIGNER_ATTR_AUTHCODE;

typedef struct _SIGNER_BLOB_INFO {
    DWORD   cbSize;
    GUID    *pGuidSubject;
    DWORD   cbBlob;
    BYTE    *pbBlob;
    LPCWSTR pwszDisplayName;
} SIGNER_BLOB_INFO, *PSIGNER_BLOB_INFO;

typedef struct _SIGNER_CERT_STORE_INFO {
    DWORD          cbSize;
    PCCERT_CONTEXT pSigningCert;
    DWORD          dwCertPolicy;
    HCERTSTORE     hCertStore;
} SIGNER_CERT_STORE_INFO, *PSIGNER_CERT_STORE_INFO;

typedef struct _SIGNER_SPC_CHAIN_INFO {
    DWORD      cbSize;
    LPCWSTR    pwszSpcFile;
    DWORD      dwCertPolicy;
    HCERTSTORE hCertStore;
} SIGNER_SPC_CHAIN_INFO, *PSIGNER_SPC_CHAIN_INFO;

typedef struct _SIGNER_CERT {
    DWORD cbSize;
    DWORD dwCertChoice;
    union {
        LPCWSTR                pwszSpcFile;
        SIGNER_CERT_STORE_INFO *pCertStoreInfo;
        SIGNER_SPC_CHAIN_INFO  *pSpcChainInfo;
    };
    HWND  hwnd;
} SIGNER_CERT, *PSIGNER_CERT;

typedef struct _SIGNER_CONTEXT {
    DWORD cbSize;
    DWORD cbBlob;
    BYTE  *pbBlob;
} SIGNER_CONTEXT, *PSIGNER_CONTEXT;

typedef struct _SIGNER_DIGEST_SIGN_INFO {
    DWORD cbSize;                                                
    DWORD dwDigestSignChoice;                                    
    union {
        PFN_AUTHENTICODE_DIGEST_SIGN pfnAuthenticodeDigestSign;                                   
        PFN_AUTHENTICODE_DIGEST_SIGN_WITHFILEHANDLE pfnAuthenticodeDigestSignWithFileHandle;      
        PFN_AUTHENTICODE_DIGEST_SIGN_EX pfnAuthenticodeDigestSignEx;                              
        PFN_AUTHENTICODE_DIGEST_SIGN_EX_WITHFILEHANDLE pfnAuthenticodeDigestSignExWithFileHandle; 
    };
    PCRYPT_DATA_BLOB pMetadataBlob;                              
    DWORD dwReserved;                                            
    DWORD dwReserved2;
    DWORD dwReserved3;
} SIGNER_DIGEST_SIGN_INFO, *PSIGNER_DIGEST_SIGN_INFO;

typedef struct SIGNER_DIGEST_SIGN_INFO_V1 {
    DWORD cbSize;
    PFN_AUTHENTICODE_DIGEST_SIGN pfnAuthenticodeDigestSign;
    PCRYPT_DATA_BLOB pMetadataBlob;
} SIGNER_DIGEST_SIGN_INFO_V1, *PSIGNER_DIGEST_SIGN_INFO_V1;

typedef struct SIGNER_DIGEST_SIGN_INFO_V2 {
    DWORD cbSize;                                                
    PFN_AUTHENTICODE_DIGEST_SIGN pfnAuthenticodeDigestSign;      
    PFN_AUTHENTICODE_DIGEST_SIGN_EX pfnAuthenticodeDigestSignEx; 
    PCRYPT_DATA_BLOB pMetadataBlob;                              
} SIGNER_DIGEST_SIGN_INFO_V2, *PSIGNER_DIGEST_SIGN_INFO_V2;

typedef struct _SIGNER_FILE_INFO {
    DWORD   cbSize;
    LPCWSTR pwszFileName;
    HANDLE  hFile;
} SIGNER_FILE_INFO, *PSIGNER_FILE_INFO;

typedef struct _SIGNER_PROVIDER_INFO {
    DWORD   cbSize;
    LPCWSTR pwszProviderName;
    DWORD   dwProviderType;
    DWORD   dwKeySpec;
    DWORD   dwPvkChoice;
    union {
        LPWSTR pwszPvkFileName;
        LPWSTR pwszKeyContainer;
    };
} SIGNER_PROVIDER_INFO, *PSIGNER_PROVIDER_INFO;

typedef struct _SIGNER_SIGNATURE_INFO {
    DWORD             cbSize;
    ALG_ID            algidHash;
    DWORD             dwAttrChoice;
    union {
        SIGNER_ATTR_AUTHCODE *pAttrAuthcode;
    };
    PCRYPT_ATTRIBUTES psAuthenticated;
    PCRYPT_ATTRIBUTES psUnauthenticated;
} SIGNER_SIGNATURE_INFO, *PSIGNER_SIGNATURE_INFO;

typedef struct _SIGNER_SUBJECT_INFO {
    DWORD cbSize;
    DWORD *pdwIndex;
    DWORD dwSubjectChoice;
    union {
        SIGNER_FILE_INFO *pSignerFileInfo;
        SIGNER_BLOB_INFO *pSignerBlobInfo;
    };
} SIGNER_SUBJECT_INFO, *PSIGNER_SUBJECT_INFO;

HRESULT WINAPI SignError(void);

HRESULT WINAPI SignerFreeSignerContext(
    _In_ SIGNER_CONTEXT *pSignerContext
    );

HRESULT WINAPI SignerSign(
    _In_     SIGNER_SUBJECT_INFO   *pSubjectInfo,
    _In_     SIGNER_CERT           *pSignerCert,
    _In_     SIGNER_SIGNATURE_INFO *pSignatureInfo,
    _In_opt_ SIGNER_PROVIDER_INFO  *pProviderInfo,
    _In_opt_ LPCWSTR               pwszHttpTimeStamp,
    _In_opt_ PCRYPT_ATTRIBUTES     psRequest,
    _In_opt_ LPVOID                pSipData
    );

HRESULT WINAPI SignerSignEx(
    _In_     DWORD                 dwFlags,
    _In_     SIGNER_SUBJECT_INFO   *pSubjectInfo,
    _In_     SIGNER_CERT           *pSignerCert,
    _In_     SIGNER_SIGNATURE_INFO *pSignatureInfo,
    _In_opt_ SIGNER_PROVIDER_INFO  *pProviderInfo,
    _In_opt_ LPCWSTR               pwszHttpTimeStamp,
    _In_opt_ PCRYPT_ATTRIBUTES     psRequest,
    _In_opt_ LPVOID                pSipData,
    _Out_    SIGNER_CONTEXT        **ppSignerContext
    );

HRESULT WINAPI SignerSignEx2(
    _In_       DWORD                  dwFlags,
    _In_       SIGNER_SUBJECT_INFO    *pSubjectInfo,
    _In_       SIGNER_CERT            *pSignerCert,
    _In_       SIGNER_SIGNATURE_INFO  *pSignatureInfo,
    _In_opt_   SIGNER_PROVIDER_INFO   *pProviderInfo,
    _In_opt_   DWORD                  dwTimestampFlags,
    _In_opt_   PCSTR                  pszTimestampAlgorithmOid,
    _In_opt_   PCWSTR                 pwszHttpTimeStamp,
    _In_opt_   PCRYPT_ATTRIBUTES      psRequest,
    _In_opt_   PVOID                  pSipData,
    _Out_      SIGNER_CONTEXT         **ppSignerContext,
    _In_opt_   PCERT_STRONG_SIGN_PARA pCryptoPolicy,
    _Reserved_ PVOID                  pReserved
    );

HRESULT WINAPI SignerSignEx3(
    _In_       DWORD                  dwFlags,
    _In_       SIGNER_SUBJECT_INFO    *pSubjectInfo,
    _In_       SIGNER_CERT            *pSignerCert,
    _In_       SIGNER_SIGNATURE_INFO  *pSignatureInfo,
    _In_opt_   SIGNER_PROVIDER_INFO   *pProviderInfo,
    _In_opt_   DWORD                  dwTimestampFlags,
    _In_opt_   PCSTR                  pszTimestampAlgorithmOid,
    _In_opt_   PCWSTR                 pwszHttpTimeStamp,
    _In_opt_   PCRYPT_ATTRIBUTES      psRequest,
    _In_opt_   PVOID                  pSipData,
    _Out_      SIGNER_CONTEXT         **ppSignerContext,
    _In_opt_   PCERT_STRONG_SIGN_PARA pCryptoPolicy,
    _In_opt_   SIGNER_DIGEST_SIGN_INFO  *pDigestSignInfo,
    _Reserved_ PVOID                  pReserved
    );

HRESULT WINAPI SignerTimeStamp(
    _In_     SIGNER_SUBJECT_INFO *pSubjectInfo,
    _In_     LPCWSTR             pwszHttpTimeStamp,
    _In_opt_ PCRYPT_ATTRIBUTES   psRequest,
    _In_opt_ LPVOID              pSipData
    );

HRESULT WINAPI SignerTimeStampEx(
    _Reserved_ DWORD               dwFlags,
    _In_       SIGNER_SUBJECT_INFO *pSubjectInfo,
    _In_       LPCWSTR             pwszHttpTimeStamp,
    _In_       PCRYPT_ATTRIBUTES   psRequest,
    _In_       LPVOID              pSipData,
    _Out_      SIGNER_CONTEXT      **ppSignerContext 
    );

HRESULT WINAPI SignerTimeStampEx2(
    _Reserved_ DWORD               dwFlags,
    _In_       SIGNER_SUBJECT_INFO *pSubjectInfo,
    _In_       LPCWSTR             pwszHttpTimeStamp,
    _In_       ALG_ID              dwAlgId,
    _In_       PCRYPT_ATTRIBUTES   psRequest,
    _In_       LPVOID              pSipData,
    _Out_      SIGNER_CONTEXT      **ppSignerContext 
    );

HRESULT WINAPI SignerTimeStampEx3(
    _In_       DWORD                  dwFlags,
    _In_       DWORD                  dwIndex,
    _In_       SIGNER_SUBJECT_INFO    *pSubjectInfo,
    _In_       PCWSTR                 pwszHttpTimeStamp,
    _In_       PCWSTR                 pszAlgorithmOid,
    _In_opt_   PCRYPT_ATTRIBUTES      psRequest,
    _In_opt_   PVOID                  pSipData,
    _Out_      SIGNER_CONTEXT         **ppSignerContext,
    _In_opt_   PCERT_STRONG_SIGN_PARA pCryptoPolicy,
    _Reserved_ PVOID                  pReserved
    );

#ifdef __cplusplus
}
#endif