using System;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;
using Windows.Win32.System.PropertiesSystem; // For PROPERTYKEY
using Windows.Win32.System.SystemServices;
using static Windows.Win32.Foundation.Apis; // Various constants
using static Windows.Win32.System.Diagnostics.Debug.WIN32_ERROR;
using static Windows.Win32.System.SystemServices.Apis; // Various constants
using static Windows.Win32.Media.Multimedia.Apis; // Various constants
using static Windows.Win32.Media.Audio.CoreAudio.Apis; // Various constants
using static Windows.Win32.Graphics.DirectShow.Apis; // Various constants
using static Windows.Win32.UI.WindowsAndMessaging.Apis; // For WM_USER
using static Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS; // For FILE_* constants
using static Windows.Win32.System.Diagnostics.Debug.FACILITY_CODE; // For MAKE_HRESULT constants


using static Windows.Win32.Security.Authorization.Apis;

namespace Windows.Win32.Security.Authorization
{
    [Flags]
    public enum AUTHZ_RESOURCE_MANAGER_FLAGS : uint
    {
        AUTHZ_RM_FLAG_NO_AUDIT = 1,
        AUTHZ_RM_FLAG_INITIALIZE_UNDER_IMPERSONATION = 2,
        AUTHZ_RM_FLAG_NO_CENTRAL_ACCESS_POLICIES = 4,
    }

    [Flags]
    public enum OBJECT_SECURITY_INFORMATION : uint
    {
        ATTRIBUTE_SECURITY_INFORMATION = 0x00000020,
        BACKUP_SECURITY_INFORMATION = 0x00010000,
        DACL_SECURITY_INFORMATION = 0x00000004,
        GROUP_SECURITY_INFORMATION = 0x00000002,
        LABEL_SECURITY_INFORMATION = 0x00000010,
        OWNER_SECURITY_INFORMATION = 0x00000001,
        PROTECTED_DACL_SECURITY_INFORMATION = 0x80000000,
        PROTECTED_SACL_SECURITY_INFORMATION = 0x40000000,
        SACL_SECURITY_INFORMATION = 0x00000008,
        SCOPE_SECURITY_INFORMATION = 0x00000040,
        UNPROTECTED_DACL_SECURITY_INFORMATION = 0x20000000,
        UNPROTECTED_SACL_SECURITY_INFORMATION = 0x10000000,
    }

    [Flags]
    public enum SECURITY_INFO_PAGE_FLAGS : uint
    {
        SI_ADVANCED = 0x00000010,
        SI_EDIT_AUDITS = 0x00000002,
        SI_EDIT_PROPERTIES = 0x00000080,
    }

    public enum AUTHZ_ACCESS_CHECK_FLAGS : uint
    {
        AUTHZ_ACCESS_CHECK_NO_DEEP_COPY_SD = 1,
    }

    public enum AUTHZ_INITIALIZE_OBJECT_ACCESS_AUDIT_EVENT_FLAGS : uint
    {
        AUTHZ_NO_SUCCESS_AUDIT = 0x00000001,
        AUTHZ_NO_FAILURE_AUDIT = 0x00000002,
        AUTHZ_NO_ALLOC_STRINGS = 0x00000004,
    }

    public enum TREE_SEC_INFO : uint
    {
        TREE_SEC_INFO_SET = 1,
        TREE_SEC_INFO_RESET = 2,
        TREE_SEC_INFO_RESET_KEEP_EXPLICIT = 3,
    }

    public enum AUTHZ_GENERATE_RESULTS : uint
    {
        AUTHZ_GENERATE_SUCCESS_AUDIT = 1,
        AUTHZ_GENERATE_FAILURE_AUDIT = 2,
    }

    [Flags]
    public enum SI_OBJECT_INFO_FLAGS : uint
    {
        SI_AUDITS_ELEVATION_REQUIRED = 0x02000000,
        SI_DISABLE_DENY_ACE = 0x80000000,
        SI_EDIT_EFFECTIVE = 0x00020000,
        SI_ENABLE_CENTRAL_POLICY = 0x40000000,
        SI_ENABLE_EDIT_ATTRIBUTE_CONDITION = 0x20000000,
        SI_MAY_WRITE = 0x10000000,
        SI_NO_ADDITIONAL_PERMISSION = 0x00200000,
        SI_OWNER_ELEVATION_REQUIRED = 0x04000000,
        SI_PERMS_ELEVATION_REQUIRED = 0x01000000,
        SI_RESET_DACL = 0x00040000,
        SI_RESET_OWNER = 0x00100000,
        SI_RESET_SACL = 0x00080000,
        SI_SCOPE_ELEVATION_REQUIRED = 0x08000000,
        SI_VIEW_ONLY = 0x00400000,
    }

    public enum ACTRL_ACCESS_ENTRY_ACCESS_FLAGS : uint
    {
        ACTRL_ACCESS_ALLOWED = 1,
        ACTRL_ACCESS_DENIED = 2,
        ACTRL_AUDIT_SUCCESS = 4,
        ACTRL_AUDIT_FAILURE = 8,
    }

    [Flags]
    public enum AUTHZ_SECURITY_ATTRIBUTE_FLAGS : uint
    {
        AUTHZ_SECURITY_ATTRIBUTE_NON_INHERITABLE = 1,
        AUTHZ_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE = 2,
    }

}
