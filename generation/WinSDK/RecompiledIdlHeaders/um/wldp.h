/*

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    wldp.h

Abstract:

    Interface for the Windows Lockdown Policy APIs.

*/

#ifndef _WLDP_H_INCLUDED_
#define _WLDP_H_INCLUDED_

#if defined (_MSC_VER)
#pragma once
#endif
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define WLDP_DLL                           L"WLDP.DLL"
#define WLDP_GETLOCKDOWNPOLICY_FN           "WldpGetLockdownPolicy"
#define WLDP_ISCLASSINAPPROVEDLIST_FN       "WldpIsClassInApprovedList"
#define WLDP_SETDYNAMICCODETRUST_FN         "WldpSetDynamicCodeTrust"
#define WLDP_ISDYNAMICCODEPOLICYENABLED_FN  "WldpIsDynamicCodePolicyEnabled"
#define WLDP_QUERYDANAMICCODETRUST_FN       "WldpQueryDynamicCodeTrust"
#define WLDP_QUERYDYNAMICCODETRUST_FN       "WldpQueryDynamicCodeTrust"
#define WLDP_QUERYWINDOWSLOCKDOWNMODE_FN    "WldpQueryWindowsLockdownMode"
#define WLDP_SETWINDOWSLOCKDOWNRESTRICTION_FN "WldpSetWindowsLockdownRestriction"
#define WLDP_QUERYDEVICESECURITYINFORMATION_FN "WldpQueryDeviceSecurityInformation"
#define WLDP_QUERYWINDOWSLOCKDOWNRESTRICTION_FN "WldpQueryWindowsLockdownRestriction"
#define WLDP_ISAPPAPPROVEDBYPOLICY_FN       "WldpIsAppApprovedByPolicy"
#define WLDP_QUERYPOLICYSETTINGENABLED_FN   "WldpQueryPolicySettingEnabled"
#define WLDP_QUERYPOLICYSETTINGENABLED2_FN   "WldpQueryPolicySettingEnabled2"
#define WLDP_ISWCOSPRODUCTIONCONFIGURATION_FN     "WldpIsWcosProductionConfiguration"
#define WLDP_RESETWCOSPRODUCTIONCONFIGURATION_FN     "WldpResetWcosProductionConfiguration"
#define WLDP_ISPRODUCTIONCONFIGURATION_FN   "WldpIsProductionConfiguration"
#define WLDP_RESETPRODUCTIONCONFIGURATION_FN   "WldpResetProductionConfiguration"

//
//  Policy state bits.
//

/*
 Policy  | UMCI | Audit | Exclusion || Definition |
 State   |  On  |  On   |   On      ||            |
 --------|------|-------|-----------||------------|
 Off     |   0  |   *   |     *     ||   0 0 0    |
 Debug   |   1  |   *   |     1     ||   1 0 1    |
 Audit   |   1  |   1   |     *     ||   1 1 0    |
 Enforce |   1  |   0   |     0     ||   1 0 0    |
*/

//
// Flags for WLDP_LOCKDOWN_VALUE.
//

#define WLDP_LOCKDOWN_UNDEFINED            (0x00000000)
#define WLDP_LOCKDOWN_DEFINED_FLAG         (0x80000000)
#define WLDP_LOCKDOWN_CONFIG_CI_FLAG       (0x00000001)
#define WLDP_LOCKDOWN_CONFIG_CI_AUDIT_FLAG (0x00000002) // == CODEINTEGRITYPOLICY_OPTION_AUDIT_ENABLED
#define WLDP_LOCKDOWN_UMCIENFORCE_FLAG     (0x00000004) // == CODEINTEGRITY_OPTION_UMCI_ENABLED
#define WLDP_LOCKDOWN_AUDIT_FLAG           (0x00000008) // == CODEINTEGRITY_OPTION_UMCI_AUDITMODE_ENABLED
#define WLDP_LOCKDOWN_EXCLUSION_FLAG       (0x00000010) // == CODEINTEGRITY_OPTION_UMCI_EXCLUSIONPATHS_ENABLED
#define WLDP_LOCKDOWN_ALL_FLAGS            (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG | \
                                            WLDP_LOCKDOWN_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_EXCLUSION_FLAG)
//
// These are the only recornized policy status flag combinations of this feature.
// All other combinations will be reverted to WLDP_LOCKDOWN_DEFAULT.
//

#define WLDP_LOCKDOWN_OFF                  (WLDP_LOCKDOWN_DEFINED_FLAG)
#define WLDP_LOCKDOWN_DEBUG                (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG | \
                                            WLDP_LOCKDOWN_EXCLUSION_FLAG)
#define WLDP_LOCKDOWN_AUDIT                (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG | \
                                            WLDP_LOCKDOWN_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_EXCLUSION_FLAG)
#define WLDP_LOCKDOWN_ENFORCE              (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG)
#define WLDP_LOCKDOWN_CONFIG_CI            (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG)
#define WLDP_LOCKDOWN_CONFIG_CI_AUDIT      (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG)
//
// State comparison masks. These masks are used to strip off wild card bits.
//

#define WLDP_LOCKDOWN_OFF_MASK             (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG)
#define WLDP_LOCKDOWN_DEBUG_MASK           (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG | \
                                            WLDP_LOCKDOWN_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_EXCLUSION_FLAG)
#define WLDP_LOCKDOWN_AUDIT_MASK           (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG | \
                                            WLDP_LOCKDOWN_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_EXCLUSION_FLAG)
#define WLDP_LOCKDOWN_ENFORCE_MASK         (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG | \
                                            WLDP_LOCKDOWN_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_EXCLUSION_FLAG)
#define WLDP_LOCKDOWN_CONFIG_CI_MASK       (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG)
#define WLDP_LOCKDOWN_CONFIG_CI_AUDIT_MASK (WLDP_LOCKDOWN_DEFINED_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_FLAG | \
                                            WLDP_LOCKDOWN_CONFIG_CI_AUDIT_FLAG | \
                                            WLDP_LOCKDOWN_UMCIENFORCE_FLAG)
//
// Policy state checking macros.
//

#define WLDP_LOCKDOWN_IS_OFF(_PolicyState)          ((_PolicyState & WLDP_LOCKDOWN_OFF_MASK) == WLDP_LOCKDOWN_OFF)
#define WLDP_LOCKDOWN_IS_DEBUG(_PolicyState)        ((_PolicyState & WLDP_LOCKDOWN_DEBUG_MASK) == WLDP_LOCKDOWN_DEBUG)
#define WLDP_LOCKDOWN_IS_AUDIT(_PolicyState)        ((_PolicyState & WLDP_LOCKDOWN_AUDIT_MASK) == WLDP_LOCKDOWN_AUDIT)
#define WLDP_LOCKDOWN_IS_ENFORCE(_PolicyState)      ((_PolicyState & WLDP_LOCKDOWN_ENFORCE_MASK) == WLDP_LOCKDOWN_ENFORCE)
#define WLDP_LOCKDOWN_IS_CONFIG_CI(_PolicyState)    ((_PolicyState & WLDP_LOCKDOWN_CONFIG_CI_MASK) == WLDP_LOCKDOWN_CONFIG_CI)
#define WLDP_LOCKDOWN_IS_CONFIG_CI_AUDIT(_PolicyState) ((_PolicyState & WLDP_LOCKDOWN_CONFIG_CI_AUDIT_MASK) == WLDP_LOCKDOWN_CONFIG_CI_AUDIT)
#define WLDP_LOCKDOWN_IS_UMCIENFORCE(_PolicyState)  ((_PolicyState & WLDP_LOCKDOWN_UMCIENFORCE_FLAG) == WLDP_LOCKDOWN_UMCIENFORCE_FLAG)


//
//  Host types.
//

typedef enum WLDP_HOST
{
    WLDP_HOST_RUNDLL32 = 0,
    WLDP_HOST_SVCHOST,
    WLDP_HOST_MAX
} WLDP_HOST;

//
//  Host ID types.
//

typedef enum WLDP_HOST_ID
{
    WLDP_HOST_ID_UNKNOWN = 0,
    WLDP_HOST_ID_GLOBAL,
    WLDP_HOST_ID_VBA,
    WLDP_HOST_ID_WSH,
    WLDP_HOST_ID_POWERSHELL,
    WLDP_HOST_ID_IE,
    WLDP_HOST_ID_MSI,
    WLDP_HOST_ID_ALL,
    WLDP_HOST_ID_MAX
} WLDP_HOST_ID;

//
// Secure Setting Decision Location names for telemetry
// 

typedef enum DECISION_LOCATION
{
    DECISION_LOCATION_REFRESH_GLOBAL_DATA = 0,
    DECISION_LOCATION_PARAMETER_VALIDATION,
    DECISION_LOCATION_AUDIT,
    DECISION_LOCATION_FAILED_CONVERT_GUID,
    DECISION_LOCATION_ENTERPRISE_DEFINED_CLASS_ID,
    DECISION_LOCATION_GLOBAL_BUILT_IN_LIST,
    DECISION_LOCATION_PROVIDER_BUILT_IN_LIST,
    DECISION_LOCATION_ENFORCE_STATE_LIST,
    DECISION_LOCATION_NOT_FOUND,
    DECISION_LOCATION_UNKNOWN
} DECISION_LOCATION;

//
// Secure Setting Key values
//

typedef enum WLDP_KEY
{
    KEY_UNKNOWN = 0,
    KEY_OVERRIDE,
    KEY_ALL_KEYS
} WLDP_KEY;

//
// Secure Setting ValueName values
//

typedef enum VALUENAME
{
    VALUENAME_UNKNOWN = 0,
    VALUENAME_ENTERPRISE_DEFINED_CLASS_ID,
    VALUENAME_BUILT_IN_LIST
} VALUENAME;

//
//  Windows Lockdown mode.
//

typedef enum WLDP_WINDOWS_LOCKDOWN_MODE
{
    WLDP_WINDOWS_LOCKDOWN_MODE_UNLOCKED = 0,
    WLDP_WINDOWS_LOCKDOWN_MODE_TRIAL,
    WLDP_WINDOWS_LOCKDOWN_MODE_LOCKED,
    WLDP_WINDOWS_LOCKDOWN_MODE_MAX,
} WLDP_WINDOWS_LOCKDOWN_MODE, *PWLDP_WINDOWS_LOCKDOWN_MODE;

typedef enum WLDP_WINDOWS_LOCKDOWN_RESTRICTION
{
    WLDP_WINDOWS_LOCKDOWN_RESTRICTION_NONE = 0,
    WLDP_WINDOWS_LOCKDOWN_RESTRICTION_NOUNLOCK,
    WLDP_WINDOWS_LOCKDOWN_RESTRICTION_NOUNLOCK_PERMANENT,
    WLDP_WINDOWS_LOCKDOWN_RESTRICTION_MAX,
} WLDP_WINDOWS_LOCKDOWN_RESTRICTION, *PWLDP_WINDOWS_LOCKDOWN_RESTRICTION;

//
// WldpQueryPolicySettingEnabled Setting Enum
//

typedef enum WLDP_POLICY_SETTING
{
    WLDP_POLICY_SETTING_AV_PERF_MODE = 1000,
} WLDP_POLICY_SETTING, *PWLDP_POLICY_SETTING;

//
//  WLDP_HOST_INFORMATION Version.
//

#define WLDP_HOST_INFORMATION_REVISION              (0x00000001)

//
//  Host information structure.
//

typedef struct WLDP_HOST_INFORMATION
{
    DWORD dwRevision;      // Has to be WLDP_HOST_INFORMATION_REVISION.
    WLDP_HOST_ID dwHostId; // Enum value from WLDP_HOST_ID.
    PCWSTR szSource;       // Full path and script name with extension. NULL for WLDP_HOST_ID_GLOBAL or manual script execution.
    HANDLE hSource;        // Additionally to the name, the caller may specify a handle to the file that is used for validation.
} WLDP_HOST_INFORMATION, *PWLDP_HOST_INFORMATION;

//
//  Device Security Information.
//

typedef struct WLDP_DEVICE_SECURITY_INFORMATION
{
    DWORD UnlockIdSize; // UnlockId size in byte
    PBYTE UnlockId; // Device specific UnlockId if exists
    DWORD ManufacturerIDLength; // ManufacturerId string size in byte
    PWSTR _Field_size_bytes_(ManufacturerIDLength) ManufacturerID; // ManufacturerID on device if exists
} WLDP_DEVICE_SECURITY_INFORMATION, *PWLDP_DEVICE_SECURITY_INFORMATION;

//
// Call the library to get the lockdown state relative to the host and script/msi to be used.
// When called with WLDP_HOST_INFORMATION.szSource = NULL, the generic policy for the host is returned.
// When called with WLDP_HOST_INFORMATION.dwHostId = WLDP_HOST_ID_GLOBAL, WLDP_HOST_INFORMATION.szSource
// has to be NULL and the function will return the global system policy.
// The dwFlag WLDP_FLAGS_SKIPSIGNATUREVALIDATION may be used to skip the SaferIdentifyLevel() validation
// which is going to ignore then if a script is signed
//

//
// Possible values for dwFlags for WldpGetLockdownPolicy API.
//

#define WLDP_FLAGS_SKIPSIGNATUREVALIDATION          (0x00000100)

#if NTDDI_VERSION >= NTDDI_WIN8

STDAPI
WldpGetLockdownPolicy(
    _In_opt_ PWLDP_HOST_INFORMATION hostInformation,
    _Out_ PDWORD lockdownState,
    _In_ DWORD lockdownFlags
    );

//
// Call the library to validate if a particular CLSID is safe to be called.
//

STDAPI
WldpIsClassInApprovedList(
    _In_ REFCLSID classID,
    _In_ PWLDP_HOST_INFORMATION hostInformation,
    _Out_ PBOOL isApproved,
    _In_ DWORD optionalFlags
    );

#endif /* NTDDI_VERSION >= NTDDI_WIN8 */

#if NTDDI_VERSION >= NTDDI_WIN10_RS4

//
// This routine sets trust claim for a dynamic code file.
// Caller should make the file exclusive access before calling the API.
//

STDAPI
WldpSetDynamicCodeTrust(
    _In_ HANDLE fileHandle
    );

typedef HRESULT(WINAPI *PWLDP_SETDYNAMICCODETRUST_API)(_In_ HANDLE hFileHandle);

//
// This routine gets dynamic code security policy enforcement status.
//

STDAPI
WldpIsDynamicCodePolicyEnabled(
    _Out_ PBOOL isEnabled
    );

typedef HRESULT(WINAPI *PWLDP_ISDYNAMICCODEPOLICYENABLED_API)(_Out_ PBOOL pbEnabled);

//
// This routine queries if in-memory or on-disk dynamic code is trusted 
// or not.
// 

STDAPI
WldpQueryDynamicCodeTrust(
    _When_(baseImage != NULL, _In_opt_)
    _When_(baseImage == NULL, _In_)
    HANDLE fileHandle,
    _When_(fileHandle == NULL, _In_reads_bytes_opt_(imageSize))
    _When_(fileHandle != NULL, _In_reads_bytes_(imageSize))
    PVOID baseImage,
    _In_ ULONG imageSize
    );

typedef HRESULT(WINAPI *PWLDP_QUERYDYNAMICODETRUST_API)(
    _When_(baseImage == NULL, _In_)
    HANDLE fileHandle,
    _When_(fileHandle == NULL, _In_reads_bytes_opt_(imageSize))
    _When_(fileHandle != NULL, _In_reads_bytes_(imageSize))
    PVOID baseImage,
    _In_ ULONG imageSize
    );

//
// This routine queries Windows Lockdown mode.
// 

HRESULT
WINAPI
WldpQueryWindowsLockdownMode(
    _Out_ PWLDP_WINDOWS_LOCKDOWN_MODE lockdownMode
    );

typedef HRESULT(WINAPI *PWLDP_QUERYWINDOWSLOCKDOWNMODE_API)(
    _Out_ PWLDP_WINDOWS_LOCKDOWN_MODE lockdownMode);

//
// This routine queries Device Security Information
//


STDAPI
WldpQueryDeviceSecurityInformation(
    _Out_writes_to_opt_(informationLength, *returnLength) PWLDP_DEVICE_SECURITY_INFORMATION information,
    _In_ DWORD informationLength,
    _Out_ DWORD* returnLength
    );

typedef HRESULT(WINAPI* PWLDP_QUERYDEVICESECURITYINFORMATION_API)(
    _Out_writes_to_opt_(informationLength, *returnLength) PWLDP_DEVICE_SECURITY_INFORMATION information,
    _In_ DWORD informationLength,
    _Out_ DWORD* returnLength);

//
// This routine queries CI lock down restriction. 
//

HRESULT
WINAPI
WldpQueryWindowsLockdownRestriction(
    _Out_ PWLDP_WINDOWS_LOCKDOWN_RESTRICTION LockdownRestriction
);

typedef HRESULT(WINAPI *PWLDP_QUERYWINDOWSLOCKDOWNRESTRICTION_API)(
    _Out_ PWLDP_WINDOWS_LOCKDOWN_RESTRICTION LockdownRestriction);

//
// This routine sets CI lock down restriction.
//

HRESULT
WINAPI
WldpSetWindowsLockdownRestriction(
    _In_ WLDP_WINDOWS_LOCKDOWN_RESTRICTION LockdownRestriction
    );

typedef HRESULT(WINAPI *PWLDP_SETWINDOWSLOCKDOWNRESTRICTION_API)(
    _In_ WLDP_WINDOWS_LOCKDOWN_RESTRICTION LockdownRestriction);

#endif /* NTDDI_VERSION >= NTDDI_WIN10_RS4 */

#if NTDDI_VERSION >= NTDDI_WIN10_RS5

//
// This routine queries if a particular PackageFamilyName would pass the currently installed CIPolicy
//
HRESULT
WINAPI
WldpIsAppApprovedByPolicy(
    _In_ PCWSTR PackageFamilyName,
    _In_ ULONGLONG PackageVersion
);

typedef HRESULT(WINAPI *PWLDP_ISAPPAPPROVEDBYPOLICY_API)(
    _In_ PCWSTR PackageFamilyName,
    _In_ ULONGLONG PackageVersion
    );

#endif /* NTDDI_VERSION >= NTDDI_WIN10_RS5 */

#if NTDDI_VERSION >= NTDDI_WIN10_MN

HRESULT
WINAPI
WldpQueryPolicySettingEnabled(
    _In_ WLDP_POLICY_SETTING Setting,
    _Out_ PBOOL Enabled
);

typedef HRESULT(WINAPI *PWLDP_QUERYPOLICYSETTINGENABLED_API)(
    _In_ WLDP_POLICY_SETTING Setting,
    _Out_ PBOOL Enabled
    );

HRESULT
WINAPI
WldpQueryPolicySettingEnabled2(
    _In_ PCWSTR SettingString,
    _Out_ PBOOL Enabled
);

typedef HRESULT(WINAPI *PWLDP_QUERYPOLICYSETTINGENABLED2_API)(
    _In_ PCWSTR Setting,
    _Out_ PBOOL Enabled
    );

//
//    This function checks the security watermark state of 10x system
//
HRESULT
WINAPI
WldpIsWcosProductionConfiguration(
    _Out_ PBOOL IsProductionConfiguration
);

typedef HRESULT(WINAPI *PWLDP_ISWCOSPRODUCTIONCONFIGURATION_API)(_Out_ PBOOL IsProductionConfiguration);

HRESULT
WINAPI
WldpResetWcosProductionConfiguration();

typedef HRESULT(WINAPI *PWLDP_RESETWCOSPRODUCTIONCONFIGURATION_API)();

//
//    This function checks the security configuration state of the non-10x system
//
HRESULT
WINAPI
WldpIsProductionConfiguration(
    _Out_ PBOOL IsProductionConfiguration
);

typedef HRESULT(WINAPI *PWLDP_ISPRODUCTIONCONFIGURATION_API)(_Out_ PBOOL IsProductionConfiguration);

HRESULT
WINAPI
WldpResetProductionConfiguration(VOID);

typedef HRESULT(WINAPI *PWLDP_RESETPRODUCTIONCONFIGURATION_API)(VOID);

#endif /* NTDDI_VERSION >= NTDDI_WIN10_MN */

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif /* !_WLDP_H_INCLUDED_ */

