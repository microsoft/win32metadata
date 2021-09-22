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


using static Windows.Win32.Security.Apis;

namespace Windows.Win32.Security
{
    [Flags]
    public enum TOKEN_PRIVILEGES_ATTRIBUTES : uint
    {
        SE_PRIVILEGE_ENABLED = 0x00000002,
        SE_PRIVILEGE_ENABLED_BY_DEFAULT = 0x00000001,
        SE_PRIVILEGE_REMOVED = 0X00000004,
        SE_PRIVILEGE_USED_FOR_ACCESS = 0x80000000,
    }

    public enum LOGON32_PROVIDER : uint
    {
        LOGON32_PROVIDER_DEFAULT = 0,
        LOGON32_PROVIDER_WINNT50 = 3,
        LOGON32_PROVIDER_WINNT40 = 2,
    }

    public enum SCE_LOG_ERR_LEVEL : uint
    {
        SCE_LOG_LEVEL_ALWAYS = 0,
        SCE_LOG_LEVEL_ERROR = 1,
        SCE_LOG_LEVEL_DETAIL = 2,
        SCE_LOG_LEVEL_DEBUG = 3,
    }

    [Flags]
    public enum CREATE_RESTRICTED_TOKEN_FLAGS : uint
    {
        DISABLE_MAX_PRIVILEGE = 1,
        SANDBOX_INERT = 2,
        LUA_TOKEN = 4,
        WRITE_RESTRICTED = 8,
    }

    public enum LOGON32_LOGON : uint
    {
        LOGON32_LOGON_BATCH = 4,
        LOGON32_LOGON_INTERACTIVE = 2,
        LOGON32_LOGON_NETWORK = 3,
        LOGON32_LOGON_NETWORK_CLEARTEXT = 8,
        LOGON32_LOGON_NEW_CREDENTIALS = 9,
        LOGON32_LOGON_SERVICE = 5,
        LOGON32_LOGON_UNLOCK = 7,
    }

    [Flags]
    public enum ACE_FLAGS : uint
    {
        CONTAINER_INHERIT_ACE = 2,
        FAILED_ACCESS_ACE_FLAG = 0x80,
        INHERIT_ONLY_ACE = 8,
        INHERITED_ACE = 16,
        NO_PROPAGATE_INHERIT_ACE = 4,
        OBJECT_INHERIT_ACE = 1,
        SUCCESSFUL_ACCESS_ACE_FLAG = 0x40,
        SUB_CONTAINERS_AND_OBJECTS_INHERIT = 3,
        SUB_CONTAINERS_ONLY_INHERIT = 2,
        SUB_OBJECTS_ONLY_INHERIT = 1,
        INHERIT_NO_PROPAGATE = 0x4,
        INHERIT_ONLY = 0x8,
        NO_INHERITANCE = 0x0,
        INHERIT_ONLY_ACE_ = 8,
    }

    [Flags]
    public enum SECURITY_AUTO_INHERIT_FLAGS : uint
    {
        SEF_AVOID_OWNER_CHECK = 16,
        SEF_AVOID_OWNER_RESTRICTION = 4096,
        SEF_AVOID_PRIVILEGE_CHECK = 8,
        SEF_DACL_AUTO_INHERIT = 1,
        SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT = 4,
        SEF_DEFAULT_GROUP_FROM_PARENT = 64,
        SEF_DEFAULT_OWNER_FROM_PARENT = 32,
        SEF_MACL_NO_EXECUTE_UP = 1024,
        SEF_MACL_NO_READ_UP = 512,
        SEF_MACL_NO_WRITE_UP = 256,
        SEF_SACL_AUTO_INHERIT = 2,
    }

    [Flags]
    public enum SAFER_COMPUTE_TOKEN_FROM_LEVEL_FLAGS : uint
    {
        SAFER_TOKEN_NULL_IF_EQUAL = 0x00000001,
        SAFER_TOKEN_COMPARE_ONLY = 0x00000002,
        SAFER_TOKEN_MAKE_INERT = 0x00000004,
        SAFER_TOKEN_WANT_FLAGS = 0x00000008,
    }

    public enum WINTRUST_GET_DEFAULT_FOR_USAGE_ACTION : uint
    {
        DWACTION_ALLOCANDFILL = 1,
        DWACTION_FREE = 2,
    }

    public enum ACE_REVISION : uint
    {
        ACL_REVISION = 2,
        ACL_REVISION_DS = 4,
    }

    [Flags]
    public enum WINTRUST_POLICY_FLAGS : uint
    {
        WTPF_TRUSTTEST = 0x00000020,
        WTPF_TESTCANBEVALID = 0x00000080,
        WTPF_IGNOREEXPIRATION = 0x00000100,
        WTPF_IGNOREREVOKATION = 0x00000200,
        WTPF_OFFLINEOK_IND = 0x00000400,
        WTPF_OFFLINEOK_COM = 0x00000800,
        WTPF_OFFLINEOKNBU_IND = 0x00001000,
        WTPF_OFFLINEOKNBU_COM = 0x00002000,
        WTPF_VERIFY_V1_OFF = 0x00010000,
        WTPF_IGNOREREVOCATIONONTS = 0x00020000,
        WTPF_ALLOWONLYPERTRUST = 0x00040000,
    }

    public enum WLX_SHUTDOWN_TYPE : uint
    {
        WLX_SAS_ACTION_SHUTDOWN = 5,
        WLX_SAS_ACTION_SHUTDOWN_REBOOT = 11,
        WLX_SAS_ACTION_SHUTDOWN_POWER_OFF = 10,
    }

    public enum CRYPTCAT_VERSION : uint
    {
        CRYPTCAT_VERSION_1 = 256,
        CRYPTCAT_VERSION_2 = 512,
    }

    [Flags]
    public enum CRYPTCAT_OPEN_FLAGS : uint
    {
        CRYPTCAT_OPEN_ALWAYS = 0x00000002,
        CRYPTCAT_OPEN_CREATENEW = 0x00000001,
        CRYPTCAT_OPEN_EXISTING = 0x00000004,
        CRYPTCAT_OPEN_EXCLUDE_PAGE_HASHES = 65536,
        CRYPTCAT_OPEN_INCLUDE_PAGE_HASHES = 131072,
        CRYPTCAT_OPEN_VERIFYSIGHASH = 268435456,
        CRYPTCAT_OPEN_NO_CONTENT_HCRYPTMSG = 536870912,
        CRYPTCAT_OPEN_SORTED = 1073741824,
        CRYPTCAT_OPEN_FLAGS_MASK = 4294901760,
    }

    public enum TOKEN_MANDATORY_POLICY_ID : uint
    {
        TOKEN_MANDATORY_POLICY_OFF = 0,
        TOKEN_MANDATORY_POLICY_NO_WRITE_UP = 1,
        TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN = 2,
        TOKEN_MANDATORY_POLICY_VALID_MASK = 3,
    }

    [Flags]
    public enum SYSTEM_AUDIT_OBJECT_ACE_FLAGS : uint
    {
        ACE_OBJECT_TYPE_PRESENT = 1,
        ACE_INHERITED_OBJECT_TYPE_PRESENT = 2,
    }

    [Flags]
    public enum CLAIM_SECURITY_ATTRIBUTE_FLAGS : uint
    {
        CLAIM_SECURITY_ATTRIBUTE_NON_INHERITABLE = 1,
        CLAIM_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE = 2,
        CLAIM_SECURITY_ATTRIBUTE_USE_FOR_DENY_ONLY = 4,
        CLAIM_SECURITY_ATTRIBUTE_DISABLED_BY_DEFAULT = 8,
        CLAIM_SECURITY_ATTRIBUTE_DISABLED = 16,
        CLAIM_SECURITY_ATTRIBUTE_MANDATORY = 32,
    }

    public enum WINTRUST_DATA_UICHOICE : uint
    {
        WTD_UI_ALL = 1,
        WTD_UI_NONE = 2,
        WTD_UI_NOBAD = 3,
        WTD_UI_NOGOOD = 4,
    }

    public enum WINTRUST_SIGNATURE_SETTINGS_FLAGS : uint
    {
        WSS_VERIFY_SPECIFIC = 1,
        WSS_GET_SECONDARY_SIG_COUNT = 2,
    }

    public enum WINTRUST_DATA_STATE_ACTION : uint
    {
        WTD_STATEACTION_IGNORE = 0,
        WTD_STATEACTION_VERIFY = 1,
        WTD_STATEACTION_CLOSE = 2,
        WTD_STATEACTION_AUTO_CACHE = 3,
        WTD_STATEACTION_AUTO_CACHE_FLUSH = 4,
    }

    public enum CLAIM_SECURITY_ATTRIBUTE_VALUE_TYPE : ushort
    {
        CLAIM_SECURITY_ATTRIBUTE_TYPE_INT64 = 1,
        CLAIM_SECURITY_ATTRIBUTE_TYPE_UINT64 = 2,
        CLAIM_SECURITY_ATTRIBUTE_TYPE_STRING = 3,
        CLAIM_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING = 16,
        CLAIM_SECURITY_ATTRIBUTE_TYPE_FQBN = 4,
        CLAIM_SECURITY_ATTRIBUTE_TYPE_SID = 5,
        CLAIM_SECURITY_ATTRIBUTE_TYPE_BOOLEAN = 6,
    }

    public enum WINTRUST_DATA_UNION_CHOICE : uint
    {
        WTD_CHOICE_FILE = 1,
        WTD_CHOICE_CATALOG = 2,
        WTD_CHOICE_BLOB = 3,
        WTD_CHOICE_SIGNER = 4,
        WTD_CHOICE_CERT = 5,
    }

    public enum WINTRUST_DATA_REVOCATION_CHECKS : uint
    {
        WTD_REVOKE_NONE = 0,
        WTD_REVOKE_WHOLECHAIN = 1,
    }

    public enum WINTRUST_DATA_UICONTEXT : uint
    {
        WTD_UICONTEXT_EXECUTE = 0,
        WTD_UICONTEXT_INSTALL = 1,
    }

}
