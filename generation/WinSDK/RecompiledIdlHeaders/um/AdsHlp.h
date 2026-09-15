#include <winapifamily.h>
#include <win32metadata_annotations.h>
//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1996-1999
//
//  File:       oleds.h
//
//  Contents:   Public header file for all oleds client code
//
//----------------------------------------------------------------------------

#ifndef _ADSHLP_
#define _ADSHLP_

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsGetObject(
    LPCWSTR lpszPathName,
    REFIID riid,
    VOID * * ppObject
    );


_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsBuildEnumerator(
    IADsContainer *pADsContainer,
    IEnumVARIANT   **ppEnumVariant
    );

_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsFreeEnumerator(
    IEnumVARIANT *pEnumVariant
    );

_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsEnumerateNext(
    IEnumVARIANT *pEnumVariant,
    ULONG         cElements,
    VARIANT FAR  *pvar,
    ULONG FAR    *pcElementsFetched
    );

_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsBuildVarArrayStr(
    _In_reads_(dwPathNames) LPWSTR * lppPathNames,
    DWORD  dwPathNames,
    VARIANT * pVar
    );

_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsBuildVarArrayInt(
    LPDWORD    lpdwObjectTypes,
    DWORD      dwObjectTypes,
    VARIANT * pVar
    );


_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsOpenObject(
    LPCWSTR lpszPathName,
    LPCWSTR lpszUserName,
    LPCWSTR lpszPassword,
    DWORD  dwReserved,
    REFIID riid,
    void FAR * FAR * ppObject
    );

//
// Helper functions for extended error support
//

_Windows_SupportedOS_WindowsVista_
_Win32_SetLastError_
HRESULT WINAPI
ADsGetLastError(
    OUT     LPDWORD lpError,
    _Out_writes_(dwErrorBufLen)    LPWSTR  lpErrorBuf,
    IN      DWORD   dwErrorBufLen,
    _Out_writes_(dwNameBufLen)     LPWSTR  lpNameBuf,
    IN      DWORD   dwNameBufLen
    );

_Windows_SupportedOS_WindowsVista_
VOID WINAPI
ADsSetLastError(
    IN  DWORD   dwErr,
    IN  LPCWSTR  pszError,
    IN  LPCWSTR  pszProvider
    );


VOID WINAPI
ADsFreeAllErrorRecords(
    VOID);

_Windows_SupportedOS_WindowsVista_
LPVOID WINAPI
AllocADsMem(
    DWORD cb
);

_Windows_SupportedOS_WindowsVista_
BOOL WINAPI
FreeADsMem(
   LPVOID pMem
);

_Windows_SupportedOS_WindowsVista_
LPVOID WINAPI
ReallocADsMem(
   LPVOID pOldMem,
   DWORD cbOld,
   DWORD cbNew
);

_Windows_SupportedOS_WindowsVista_
LPWSTR WINAPI
AllocADsStr(
    LPCWSTR pStr
);

_Windows_SupportedOS_WindowsVista_
BOOL WINAPI
FreeADsStr(
   _In_ LPWSTR pStr
);


_Windows_SupportedOS_WindowsVista_
BOOL WINAPI
ReallocADsStr(
   _Inout_ LPWSTR *ppStr,
   _In_ LPWSTR pStr
);


_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
ADsEncodeBinaryData (
   PBYTE   pbSrcData,
   DWORD   dwSrcLen,
   _Outptr_ LPWSTR  * ppszDestData
   );

HRESULT WINAPI
ADsDecodeBinaryData (
   LPCWSTR szSrcData,
   PBYTE  *ppbDestData,
   ULONG  *pdwDestLen
   );

HRESULT WINAPI
PropVariantToAdsType(
    VARIANT * pVariant,
    DWORD dwNumVariant,
    PADSVALUE *ppAdsValues,
    PDWORD pdwNumValues
    );

HRESULT WINAPI
AdsTypeToPropVariant(
    PADSVALUE pAdsValues,
    DWORD dwNumValues,
    VARIANT * pVariant
    );

void WINAPI
AdsFreeAdsValues(
    PADSVALUE pAdsValues,
    DWORD dwNumValues
    );
    
//
// Helper routines to convert IADsSecurityDescriptor to a binary
// security descriptor and also to convert a binary SD to 
// IADsSecurityDescriptor.
//
_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
BinarySDToSecurityDescriptor(
    PSECURITY_DESCRIPTOR  pSecurityDescriptor,
    VARIANT *pVarsec, 
    LPCWSTR pszServerName,
    LPCWSTR userName,
    LPCWSTR passWord,
    DWORD dwFlags
    );

_Windows_SupportedOS_WindowsVista_
HRESULT WINAPI
SecurityDescriptorToBinarySD(
    VARIANT vVarSecDes,
    PSECURITY_DESCRIPTOR * ppSecurityDescriptor,
    PDWORD pdwSDLength,
    LPCWSTR pszServerName,
    LPCWSTR userName,
    LPCWSTR passWord,
    DWORD dwFlags
    );

#if DBG

extern LIST_ENTRY ADsMemList ;

extern CRITICAL_SECTION ADsMemCritSect ;

VOID InitADsMem(
    VOID
    ) ;

VOID AssertADsMemLeaks(
    VOID
    ) ;


VOID
DumpMemoryTracker();


#else

#define InitADsMem()
#define AssertADsMemLeaks()

#define DumpMemoryTracker()



#endif


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#ifdef __cplusplus
}
#endif

#endif // _ADSHLP_

