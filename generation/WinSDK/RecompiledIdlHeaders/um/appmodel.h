/***************************************************
*                                                  *
*   Copyright (C) Microsoft. All rights reserved.  *
*                                                  *
***************************************************/
//
// API Set Contract:
//
//    api-ms-win-appmodel-runtime-l1
//
// Abstract:
//
//    This header file provides API function signatures and
//    corollary type declarations for the Windows AppModel
//    Runtime component.
//
////

#if defined(_MSC_VER)
#if _MSC_VER > 1000
#pragma once
#endif
#endif // defined(_MSC_VER)

#ifndef _APPMODEL_H_
#define _APPMODEL_H_

#if defined(_CONTRACT_GEN)
#include <nt.h>
#include <ntrtl.h>
#include <nturtl.h>
#include <windows.h>
#endif // defined(_CONTRACT_GEN)

#if defined(_MSC_VER)
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201) /* nonstandard extension used : nameless struct/union */
#endif // defined(_MSC_VER)

#include <minappmodel.h>

#if defined(__cplusplus)
extern "C" {
#endif

#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

// Identity Types
#include <pshpack4.h>

typedef struct PACKAGE_VERSION {
    union {
        UINT64 Version;
        struct {
            USHORT Revision;
            USHORT Build;
            USHORT Minor;
            USHORT Major;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
} PACKAGE_VERSION;

typedef struct PACKAGE_ID {
    UINT32          reserved;
    UINT32          processorArchitecture;
    PACKAGE_VERSION version;
    PWSTR           name;
    PWSTR           publisher;
    PWSTR           resourceId;
    PWSTR           publisherId;
} PACKAGE_ID;

#include <poppack.h>

// Identity Functions

WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentPackageId(
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentPackageFullName(
    _Inout_ UINT32* packageFullNameLength,
    _Out_writes_opt_(*packageFullNameLength) PWSTR packageFullName
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentPackageFamilyName(
    _Inout_ UINT32* packageFamilyNameLength,
    _Out_writes_opt_(*packageFamilyNameLength) PWSTR packageFamilyName
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentPackagePath(
    _Inout_ UINT32* pathLength,
    _Out_writes_opt_(*pathLength) PWSTR path
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageId(
    _In_ HANDLE hProcess,
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageFullName(
    _In_ HANDLE hProcess,
    _Inout_ UINT32* packageFullNameLength,
    _Out_writes_opt_(*packageFullNameLength) PWSTR packageFullName
    );


//TODO:8645770 Change 0x0101 to 0x0102 once THRESHOLD constants are available
WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageFullNameFromToken(
    _In_ HANDLE token,
    _Inout_ UINT32* packageFullNameLength,
    _Out_writes_opt_(*packageFullNameLength) PWSTR packageFullName
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageFamilyName(
    _In_ HANDLE hProcess,
    _Inout_ UINT32* packageFamilyNameLength,
    _Out_writes_opt_(*packageFamilyNameLength) PWSTR packageFamilyName
    );


//TODO:8645770 Change 0x0101 to 0x0102 once THRESHOLD constants are available
WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageFamilyNameFromToken(
    _In_ HANDLE token,
    _Inout_ UINT32* packageFamilyNameLength,
    _Out_writes_opt_(*packageFamilyNameLength) PWSTR packageFamilyName
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackagePath(
    _In_ const PACKAGE_ID* packageId,
    _Reserved_ const UINT32 reserved,
    _Inout_ UINT32* pathLength,
    _Out_writes_opt_(*pathLength) PWSTR path
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackagePathByFullName(
    _In_ PCWSTR packageFullName,
    _Inout_ UINT32* pathLength,
    _Out_writes_opt_(*pathLength) PWSTR path
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetStagedPackagePathByFullName(
    _In_ PCWSTR packageFullName,
    _Inout_ UINT32* pathLength,
    _Out_writes_opt_(*pathLength) PWSTR path
    );


#if NTDDI_VERSION >= NTDDI_WIN10_19H1
typedef enum PackagePathType
{
    PackagePathType_Install = 0,
    PackagePathType_Mutable = 1,
    PackagePathType_Effective = 2,

#if NTDDI_VERSION >= NTDDI_WIN10_VB
    PackagePathType_MachineExternal = 3,
    PackagePathType_UserExternal = 4,
    PackagePathType_EffectiveExternal = 5
#endif
} PackagePathType;

WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackagePathByFullName2(
    _In_ PCWSTR packageFullName,
    _In_ PackagePathType packagePathType,
    _Inout_ UINT32* pathLength,
    _Out_writes_opt_(*pathLength) PWSTR path
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetStagedPackagePathByFullName2(
    _In_ PCWSTR packageFullName,
    _In_ PackagePathType packagePathType,
    _Inout_ UINT32* pathLength,
    _Out_writes_opt_(*pathLength) PWSTR path
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentPackageInfo2(
    _In_ const UINT32 flags,
    _In_ PackagePathType packagePathType,
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer,
    _Out_opt_ UINT32* count
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentPackagePath2(
    _In_ PackagePathType packagePathType,
    _Inout_ UINT32* pathLength,
    _Out_writes_opt_(*pathLength) PWSTR path
    );

#endif // NTDDI_VERSION >= NTDDI_WIN10_19H1

/* ---------------------------------------------------------------- */

// Application Identity Functions

WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentApplicationUserModelId(
    _Inout_ UINT32* applicationUserModelIdLength,
    _Out_writes_opt_(*applicationUserModelIdLength) PWSTR applicationUserModelId
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetApplicationUserModelId(
    _In_ HANDLE hProcess,
    _Inout_ UINT32* applicationUserModelIdLength,
    _Out_writes_opt_(*applicationUserModelIdLength) PWSTR applicationUserModelId
    );


//TODO:8645770 Change 0x0101 to 0x0102 once THRESHOLD constants are available
WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetApplicationUserModelIdFromToken(
    _In_ HANDLE token,
    _Inout_ UINT32* applicationUserModelIdLength,
    _Out_writes_opt_(*applicationUserModelIdLength) PWSTR applicationUserModelId
    );


/* ---------------------------------------------------------------- */

// Verification Functions

//TODO:8645770 Change 0x0101 to 0x0102 once THRESHOLD constants are available
WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
VerifyPackageFullName(
    _In_ PCWSTR packageFullName
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
VerifyPackageFamilyName(
    _In_ PCWSTR packageFamilyName
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
VerifyPackageId(
    _In_ const PACKAGE_ID* packageId
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
VerifyApplicationUserModelId(
    _In_ PCWSTR applicationUserModelId
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
VerifyPackageRelativeApplicationId(
    _In_ PCWSTR packageRelativeApplicationId
    );


/* ---------------------------------------------------------------- */

// Conversion Functions

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
PackageIdFromFullName(
    _In_ PCWSTR packageFullName,
    _In_ const UINT32 flags,
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
PackageFullNameFromId(
    _In_ const PACKAGE_ID* packageId,
    _Inout_ UINT32* packageFullNameLength,
    _Out_writes_opt_(*packageFullNameLength) PWSTR packageFullName
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
PackageFamilyNameFromId(
    _In_ const PACKAGE_ID* packageId,
    _Inout_ UINT32* packageFamilyNameLength,
    _Out_writes_opt_(*packageFamilyNameLength) PWSTR packageFamilyName
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
PackageFamilyNameFromFullName(
    _In_ PCWSTR packageFullName,
    _Inout_ UINT32* packageFamilyNameLength,
    _Out_writes_opt_(*packageFamilyNameLength) PWSTR packageFamilyName
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
PackageNameAndPublisherIdFromFamilyName(
    _In_ PCWSTR packageFamilyName,
    _Inout_ UINT32* packageNameLength,
    _Out_writes_opt_(*packageNameLength) PWSTR packageName,
    _Inout_ UINT32* packagePublisherIdLength,
    _Out_writes_opt_(*packagePublisherIdLength) PWSTR packagePublisherId
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
FormatApplicationUserModelId(
    _In_ PCWSTR packageFamilyName,
    _In_ PCWSTR packageRelativeApplicationId,
    _Inout_ UINT32* applicationUserModelIdLength,
    _Out_writes_opt_(*applicationUserModelIdLength) PWSTR applicationUserModelId
    );


WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
ParseApplicationUserModelId(
    _In_ PCWSTR applicationUserModelId,
    _Inout_ UINT32* packageFamilyNameLength,
    _Out_writes_opt_(*packageFamilyNameLength) PWSTR packageFamilyName,
    _Inout_ UINT32* packageRelativeApplicationIdLength,
    _Out_writes_opt_(*packageRelativeApplicationIdLength) PWSTR packageRelativeApplicationId
    );


/* ---------------------------------------------------------------- */

// Lookup Functions

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
_On_failure_(_Unchanged_(*count))
_On_failure_(_Unchanged_(*bufferLength))
LONG
WINAPI
GetPackagesByPackageFamily(
    _In_ PCWSTR packageFamilyName,
    _Inout_ UINT32* count,
    _Out_writes_opt_(*count) PWSTR* packageFullNames,
    _Inout_ UINT32* bufferLength,
    _Out_writes_opt_(*bufferLength) WCHAR* buffer
    );


/* Any combination of PACKAGE_FILTER_* */WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
_On_failure_(_Unchanged_(*count))
_On_failure_(_Unchanged_(*bufferLength))
LONG
WINAPI
FindPackagesByPackageFamily(
    _In_ PCWSTR packageFamilyName,
    _In_ UINT32 packageFilters,
    _Inout_ UINT32* count,
    _Out_writes_opt_(*count) PWSTR* packageFullNames,
    _Inout_ UINT32* bufferLength,
    _Out_writes_opt_(*bufferLength) WCHAR* buffer,
    _Out_writes_opt_(*count) UINT32* packageProperties
    );


typedef enum PackageOrigin
{
    PackageOrigin_Unknown           = 0,
    PackageOrigin_Unsigned          = 1,
    PackageOrigin_Inbox             = 2,
    PackageOrigin_Store             = 3,
    PackageOrigin_DeveloperUnsigned = 4,
    PackageOrigin_DeveloperSigned   = 5,
    PackageOrigin_LineOfBusiness    = 6
} PackageOrigin;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetStagedPackageOrigin(
    _In_ PCWSTR packageFullName,
    _Out_ PackageOrigin* origin
    );


/* ---------------------------------------------------------------- */

// Package Constants

#define PACKAGE_PROPERTY_FRAMEWORK          0x00000001
#define PACKAGE_PROPERTY_RESOURCE           0x00000002
#define PACKAGE_PROPERTY_BUNDLE             0x00000004
#define PACKAGE_PROPERTY_OPTIONAL           0x00000008
#define PACKAGE_FILTER_HEAD                 0x00000010
#define PACKAGE_FILTER_DIRECT               0x00000020
#define PACKAGE_FILTER_RESOURCE             0x00000040
#define PACKAGE_FILTER_BUNDLE               0x00000080
#define PACKAGE_INFORMATION_BASIC           0x00000000
#define PACKAGE_INFORMATION_FULL            0x00000100
#define PACKAGE_PROPERTY_DEVELOPMENT_MODE   0x00010000
#define PACKAGE_FILTER_OPTIONAL             0x00020000
#define PACKAGE_PROPERTY_IS_IN_RELATED_SET  0x00040000
#define PACKAGE_FILTER_IS_IN_RELATED_SET    PACKAGE_PROPERTY_IS_IN_RELATED_SET
#define PACKAGE_PROPERTY_STATIC             0x00080000
#define PACKAGE_FILTER_STATIC               PACKAGE_PROPERTY_STATIC
#define PACKAGE_PROPERTY_DYNAMIC            0x00100000
#define PACKAGE_FILTER_DYNAMIC              PACKAGE_PROPERTY_DYNAMIC

#if defined(NTDDI_VERSION) && (NTDDI_VERSION >= NTDDI_WINBLUE)
#pragma deprecated("PACKAGE_FILTER_ALL_LOADED")
#endif
// Use PACKAGE_FILTER_HEAD|PACKAGE_FILTER_DIRECT instead of PACKAGE_FILTER_ALL_LOADED
#define PACKAGE_FILTER_ALL_LOADED   0

// Dependency Types

typedef struct _PACKAGE_INFO_REFERENCE {
    void * reserved;
} * PACKAGE_INFO_REFERENCE;

#include <pshpack4.h>

typedef struct PACKAGE_INFO {
    UINT32     reserved;
    UINT32     flags;
    PWSTR      path;
    PWSTR      packageFullName;
    PWSTR      packageFamilyName;
    PACKAGE_ID packageId;
} PACKAGE_INFO;

#include <poppack.h>

// Dependency Functions

WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetCurrentPackageInfo(
    _In_ const UINT32 flags,
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer,
    _Out_opt_ UINT32* count
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
OpenPackageInfoByFullName(
    _In_ PCWSTR packageFullName,
    _Reserved_ const UINT32 reserved,
    _Out_ PACKAGE_INFO_REFERENCE* packageInfoReference
    );


//TODO:8645770 Change 0x0101 to 0x0102 once THRESHOLD constants are available
WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
OpenPackageInfoByFullNameForUser(
    _In_opt_ PSID userSid,
    _In_ PCWSTR packageFullName,
    _Reserved_ const UINT32 reserved,
    _Out_ PACKAGE_INFO_REFERENCE* packageInfoReference
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
ClosePackageInfo(
    _In_ PACKAGE_INFO_REFERENCE packageInfoReference
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageInfo(
    _In_ PACKAGE_INFO_REFERENCE packageInfoReference,
    _In_ const UINT32 flags,
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer,
    _Out_opt_ UINT32* count
    );


WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageApplicationIds(
    _In_ PACKAGE_INFO_REFERENCE packageInfoReference,
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer,
    _Out_opt_ UINT32* count
    );


typedef enum AppPolicyLifecycleManagement
{
    AppPolicyLifecycleManagement_Unmanaged = 0,
    AppPolicyLifecycleManagement_Managed = 1
} AppPolicyLifecycleManagement;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetLifecycleManagement(
    _In_ HANDLE processToken,
    _Out_ AppPolicyLifecycleManagement* policy
    );


typedef enum AppPolicyWindowingModel
{
    AppPolicyWindowingModel_None = 0,
    AppPolicyWindowingModel_Universal = 1,
    AppPolicyWindowingModel_ClassicDesktop = 2,
    AppPolicyWindowingModel_ClassicPhone = 3
} AppPolicyWindowingModel;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetWindowingModel(
    _In_ HANDLE processToken,
    _Out_ AppPolicyWindowingModel* policy
    );


typedef enum AppPolicyMediaFoundationCodecLoading
{
    AppPolicyMediaFoundationCodecLoading_All = 0,
    AppPolicyMediaFoundationCodecLoading_InboxOnly = 1
} AppPolicyMediaFoundationCodecLoading;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetMediaFoundationCodecLoading(
    _In_ HANDLE processToken,
    _Out_ AppPolicyMediaFoundationCodecLoading* policy
    );


typedef enum AppPolicyClrCompat
{
    AppPolicyClrCompat_Other = 0,
    AppPolicyClrCompat_ClassicDesktop = 1,
    AppPolicyClrCompat_Universal = 2,
    AppPolicyClrCompat_PackagedDesktop = 3
} AppPolicyClrCompat;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetClrCompat(
    _In_ HANDLE processToken,
    _Out_ AppPolicyClrCompat* policy
    );


typedef enum AppPolicyThreadInitializationType
{
    AppPolicyThreadInitializationType_None = 0,
    AppPolicyThreadInitializationType_InitializeWinRT = 1,
} AppPolicyThreadInitializationType;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetThreadInitializationType(
    _In_ HANDLE processToken,
    _Out_ AppPolicyThreadInitializationType* policy
    );


typedef enum AppPolicyShowDeveloperDiagnostic
{
    AppPolicyShowDeveloperDiagnostic_None = 0,
    AppPolicyShowDeveloperDiagnostic_ShowUI = 1,
} AppPolicyShowDeveloperDiagnostic;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetShowDeveloperDiagnostic(
    _In_ HANDLE processToken,
    _Out_ AppPolicyShowDeveloperDiagnostic* policy
    );


typedef enum AppPolicyProcessTerminationMethod
{
    AppPolicyProcessTerminationMethod_ExitProcess = 0,
    AppPolicyProcessTerminationMethod_TerminateProcess = 1,
} AppPolicyProcessTerminationMethod;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetProcessTerminationMethod(
    _In_ HANDLE processToken,
    _Out_ AppPolicyProcessTerminationMethod* policy
    );


typedef enum AppPolicyCreateFileAccess
{
    AppPolicyCreateFileAccess_Full = 0,
    AppPolicyCreateFileAccess_Limited = 1,
} AppPolicyCreateFileAccess;

WINBASEAPI
_Check_return_
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
AppPolicyGetCreateFileAccess(
    _In_ HANDLE processToken,
    _Out_ AppPolicyCreateFileAccess* policy
    );


#if NTDDI_VERSION >= NTDDI_WIN10_19H1
WINBASEAPI
_Success_(return == ERROR_SUCCESS)
LONG
WINAPI
GetPackageInfo2(
    _In_ PACKAGE_INFO_REFERENCE packageInfoReference,
    _In_ const UINT32 flags,
    _In_ PackagePathType packagePathType,
    _Inout_ UINT32* bufferLength,
    _Out_writes_bytes_opt_(*bufferLength) BYTE* buffer,
    _Out_opt_ UINT32* count
    );

#endif // NTDDI_VERSION >= NTDDI_WIN10_19H1

#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#pragma endregion

#if defined(__cplusplus)
} // end extern "C"
#endif // defined(__cplusplus)

#if defined(_MSC_VER)
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif
#endif // defined(_MSC_VER)

#endif
