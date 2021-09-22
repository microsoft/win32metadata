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


using static Windows.Win32.NetworkManagement.NetManagement.Apis;

namespace Windows.Win32.NetworkManagement.NetManagement
{
    [Flags]
    public enum NET_REQUEST_PROVISION_OPTIONS : uint
    {
        NETSETUP_PROVISION_ONLINE_CALLER = 1073741824,
    }

    [Flags]
    public enum NET_JOIN_DOMAIN_JOIN_OPTIONS : uint
    {
        NETSETUP_JOIN_DOMAIN = 1,
        NETSETUP_ACCT_CREATE = 2,
        NETSETUP_WIN9X_UPGRADE = 16,
        NETSETUP_DOMAIN_JOIN_IF_JOINED = 32,
        NETSETUP_JOIN_UNSECURE = 64,
        NETSETUP_MACHINE_PWD_PASSED = 128,
        NETSETUP_DEFER_SPN_SET = 256,
        NETSETUP_JOIN_DC_ACCOUNT = 512,
        NETSETUP_JOIN_WITH_NEW_NAME = 1024,
        NETSETUP_JOIN_READONLY = 2048,
        NETSETUP_AMBIGUOUS_DC = 4096,
        NETSETUP_NO_NETLOGON_CACHE = 8192,
        NETSETUP_DONT_CONTROL_SERVICES = 16384,
        NETSETUP_SET_MACHINE_NAME = 32768,
        NETSETUP_FORCE_SPN_SET = 65536,
        NETSETUP_NO_ACCT_REUSE = 131072,
        NETSETUP_IGNORE_UNSUPPORTED_FLAGS = 268435456,
    }

    public enum NET_REMOTE_COMPUTER_SUPPORTS_OPTIONS
    {
        SUPPORTS_REMOTE_ADMIN_PROTOCOL = 0x00000002,
        SUPPORTS_RPC = 0x00000004,
        SUPPORTS_SAM_PROTOCOL = 0x00000008,
        SUPPORTS_UNICODE = 0x00000010,
        SUPPORTS_LOCAL = 0x00000020,
    }

    public enum FORCE_LEVEL_FLAGS : uint
    {
        USE_NOFORCE = 0,
        USE_FORCE = 1,
        USE_LOTS_OF_FORCE = 2,
    }

    [Flags]
    public enum NET_SERVER_TYPE : uint
    {
        SV_TYPE_WORKSTATION = 1,
        SV_TYPE_SERVER = 2,
        SV_TYPE_SQLSERVER = 4,
        SV_TYPE_DOMAIN_CTRL = 8,
        SV_TYPE_DOMAIN_BAKCTRL = 16,
        SV_TYPE_TIME_SOURCE = 32,
        SV_TYPE_AFP = 64,
        SV_TYPE_NOVELL = 128,
        SV_TYPE_DOMAIN_MEMBER = 256,
        SV_TYPE_PRINTQ_SERVER = 512,
        SV_TYPE_DIALIN_SERVER = 1024,
        SV_TYPE_XENIX_SERVER = 2048,
        SV_TYPE_SERVER_UNIX = 2048,
        SV_TYPE_NT = 4096,
        SV_TYPE_WFW = 8192,
        SV_TYPE_SERVER_MFPN = 16384,
        SV_TYPE_SERVER_NT = 32768,
        SV_TYPE_POTENTIAL_BROWSER = 65536,
        SV_TYPE_BACKUP_BROWSER = 131072,
        SV_TYPE_MASTER_BROWSER = 262144,
        SV_TYPE_DOMAIN_MASTER = 524288,
        SV_TYPE_SERVER_OSF = 1048576,
        SV_TYPE_SERVER_VMS = 2097152,
        SV_TYPE_WINDOWS = 4194304,
        SV_TYPE_DFS = 8388608,
        SV_TYPE_CLUSTER_NT = 16777216,
        SV_TYPE_TERMINALSERVER = 33554432,
        SV_TYPE_CLUSTER_VS_NT = 67108864,
        SV_TYPE_DCE = 268435456,
        SV_TYPE_ALTERNATE_XPORT = 536870912,
        SV_TYPE_LOCAL_LIST_ONLY = 1073741824,
        SV_TYPE_DOMAIN_ENUM = 2147483648,
        SV_TYPE_ALL = 4294967295,
    }

    [Flags]
    public enum NET_USER_ENUM_FILTER_FLAGS : uint
    {
        FILTER_TEMP_DUPLICATE_ACCOUNT = 0x0001,
        FILTER_NORMAL_ACCOUNT = 0x0002,
        FILTER_INTERDOMAIN_TRUST_ACCOUNT = 0x0008,
        FILTER_WORKSTATION_TRUST_ACCOUNT = 0x0010,
        FILTER_SERVER_TRUST_ACCOUNT = 0x0020,
    }

    [Flags]
    public enum NETSETUP_PROVISION : uint
    {
        NETSETUP_PROVISION_DOWNLEVEL_PRIV_SUPPORT = 1,
        NETSETUP_PROVISION_REUSE_ACCOUNT = 2,
        NETSETUP_PROVISION_USE_DEFAULT_PASSWORD = 4,
        NETSETUP_PROVISION_SKIP_ACCOUNT_SEARCH = 8,
        NETSETUP_PROVISION_ROOT_CA_CERTS = 16,
    }

    [Flags]
    public enum USER_ACCOUNT_FLAGS : uint
    {
        UF_SCRIPT = 0x0001,
        UF_ACCOUNTDISABLE = 0x0002,
        UF_HOMEDIR_REQUIRED = 0x0008,
        UF_PASSWD_NOTREQD = 0x0020,
        UF_PASSWD_CANT_CHANGE = 0x0040,
        UF_LOCKOUT = 0x0010,
        UF_DONT_EXPIRE_PASSWD = 0x10000,
        UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED = 0x0080,
        UF_NOT_DELEGATED = 0x100000,
        UF_SMARTCARD_REQUIRED = 0x40000,
        UF_USE_DES_KEY_ONLY = 0x200000,
        UF_DONT_REQUIRE_PREAUTH = 0x400000,
        UF_TRUSTED_FOR_DELEGATION = 0x80000,
        UF_PASSWORD_EXPIRED = 0x800000,
        UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = 0x1000000,
    }

    [Flags]
    public enum AF_OP : uint
    {
        AF_OP_PRINT = 0x1,
        AF_OP_COMM = 0x2,
        AF_OP_SERVER = 0x4,
        AF_OP_ACCOUNTS = 0x8,
    }

    public enum SERVER_INFO_SECURITY : uint
    {
        SV_SHARESECURITY = 0,
        SV_USERSECURITY = 1,
    }

    public enum USER_PRIV : uint
    {
        USER_PRIV_GUEST = 0,
        USER_PRIV_USER = 1,
        USER_PRIV_ADMIN = 2,
    }

    public enum USE_INFO_ASG_TYPE : uint
    {
        USE_WILDCARD = 0xFFFFFFFF,
        USE_DISKDEV = 0,
        USE_SPOOLDEV = 1,
        USE_IPC = 3,
    }

    public enum SERVER_INFO_HIDDEN : uint
    {
        SV_VISIBLE = 0,
        SV_HIDDEN = 1,
    }

    public enum USER_MODALS_ROLES : uint
    {
        UAS_ROLE_STANDALONE = 0,
        UAS_ROLE_MEMBER = 1,
        UAS_ROLE_BACKUP = 2,
        UAS_ROLE_PRIMARY = 3,
    }

}
