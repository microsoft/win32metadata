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


namespace Windows.Win32.Security.Authorization
{
    public static partial class Apis
    {
        public const uint SDDL_REVISION_1 = 1;

        public const uint SDDL_ALIAS_SIZE = 2;

        public const uint INHERITED_ACCESS_ENTRY = 0x10;

        public const uint INHERITED_PARENT = 0x10000000;

        public const uint INHERITED_GRANDPARENT = 0x20000000;

        public const int TRUSTEE_ACCESS_ALLOWED = 0x00000001;

        public const int TRUSTEE_ACCESS_READ = 0x00000002;

        public const int TRUSTEE_ACCESS_WRITE = 0x00000004;

        public const int TRUSTEE_ACCESS_EXPLICIT = 0x00000001;

        public const int TRUSTEE_ACCESS_ALL = unchecked((int)0xFFFFFFFF);

        public const uint ACTRL_RESERVED = 0x00000000;

        public const uint ACTRL_PERM_1 = 0x00000001;

        public const uint ACTRL_PERM_2 = 0x00000002;

        public const uint ACTRL_PERM_3 = 0x00000004;

        public const uint ACTRL_PERM_4 = 0x00000008;

        public const uint ACTRL_PERM_5 = 0x00000010;

        public const uint ACTRL_PERM_6 = 0x00000020;

        public const uint ACTRL_PERM_7 = 0x00000040;

        public const uint ACTRL_PERM_8 = 0x00000080;

        public const uint ACTRL_PERM_9 = 0x00000100;

        public const uint ACTRL_PERM_10 = 0x00000200;

        public const uint ACTRL_PERM_11 = 0x00000400;

        public const uint ACTRL_PERM_12 = 0x00000800;

        public const uint ACTRL_PERM_13 = 0x00001000;

        public const uint ACTRL_PERM_14 = 0x00002000;

        public const uint ACTRL_PERM_15 = 0x00004000;

        public const uint ACTRL_PERM_16 = 0x00008000;

        public const uint ACTRL_PERM_17 = 0x00010000;

        public const uint ACTRL_PERM_18 = 0x00020000;

        public const uint ACTRL_PERM_19 = 0x00040000;

        public const uint ACTRL_PERM_20 = 0x00080000;

        public const uint ACTRL_ACCESS_PROTECTED = 0x00000001;

        public const uint ACTRL_SYSTEM_ACCESS = 0x04000000;

        public const uint ACTRL_DELETE = 0x08000000;

        public const uint ACTRL_READ_CONTROL = 0x10000000;

        public const uint ACTRL_CHANGE_ACCESS = 0x20000000;

        public const uint ACTRL_CHANGE_OWNER = 0x40000000;

        public const uint ACTRL_SYNCHRONIZE = 0x80000000;

        public const uint ACTRL_STD_RIGHTS_ALL = 0xf8000000;

        public const uint ACTRL_ACCESS_NO_OPTIONS = 0x00000000;

        public const uint ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES = 0x00000001;

        public const int SI_EDIT_PERMS = 0x00000000;

        public const int SI_EDIT_OWNER = 0x00000001;

        public const int SI_CONTAINER = 0x00000004;

        public const int SI_READONLY = 0x00000008;

        public const int SI_RESET = 0x00000020;

        public const int SI_OWNER_READONLY = 0x00000040;

        public const int SI_OWNER_RECURSE = 0x00000100;

        public const int SI_NO_ACL_PROTECT = 0x00000200;

        public const int SI_NO_TREE_APPLY = 0x00000400;

        public const int SI_PAGE_TITLE = 0x00000800;

        public const int SI_SERVER_IS_DC = 0x00001000;

        public const int SI_RESET_DACL_TREE = 0x00004000;

        public const int SI_RESET_SACL_TREE = 0x00008000;

        public const int SI_OBJECT_GUID = 0x00010000;

        public const int SI_ACCESS_SPECIFIC = 0x00010000;

        public const int SI_ACCESS_GENERAL = 0x00020000;

        public const int SI_ACCESS_CONTAINER = 0x00040000;

        public const int SI_ACCESS_PROPERTY = 0x00080000;

        public const int DOBJ_RES_CONT = 0x00000001;

        public const int DOBJ_RES_ROOT = 0x00000002;

        public const int DOBJ_VOL_NTACLS = 0x00000004;

        public const int DOBJ_COND_NTACLS = 0x00000008;

        public const int DOBJ_RIBBON_LAUNCH = 0x00000010;

        public const uint SECURITY_OBJECT_ID_OBJECT_SD = 1;

        public const uint SECURITY_OBJECT_ID_SHARE = 2;

        public const uint SECURITY_OBJECT_ID_CENTRAL_POLICY = 3;

        public const uint SECURITY_OBJECT_ID_CENTRAL_ACCESS_RULE = 4;

        public const uint AUDIT_TYPE_LEGACY = 1;

        public const uint AUDIT_TYPE_WMI = 2;

        public const uint AP_ParamTypeBits = 8;

        public const int AP_ParamTypeMask = 0x000000ff;

        public const uint _AUTHZ_SS_MAXSIZE = 128;

        public const uint APF_AuditFailure = 0x00000000;

        public const uint APF_AuditSuccess = 0x00000001;

        public const uint AUTHZP_WPD_EVENT = 0x10;

        public const uint AUTHZ_ALLOW_MULTIPLE_SOURCE_INSTANCES = 0x1;

        public const uint AUTHZ_MIGRATED_LEGACY_PUBLISHER = 0x2;

        public const uint AUTHZ_AUDIT_INSTANCE_INFORMATION = 0x2;

        public const uint AUTHZ_SKIP_TOKEN_GROUPS = 0x2;

        public const uint AUTHZ_REQUIRE_S4U_LOGON = 0x4;

        public const uint AUTHZ_COMPUTE_PRIVILEGES = 0x8;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_INVALID = 0x00;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_INT64 = 0x01;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_UINT64 = 0x02;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_STRING = 0x03;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_FQBN = 0x04;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_SID = 0x05;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_BOOLEAN = 0x06;

        public const uint AUTHZ_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING = 0x10;

        public const uint AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1 = 1;

        public const uint AUTHZ_RPC_INIT_INFO_CLIENT_VERSION_V1 = 1;

        public const uint AUTHZ_INIT_INFO_VERSION_V1 = 1;

        public const uint AUTHZ_WPD_CATEGORY_FLAG = 0x00000010;

        public const uint AUTHZ_FLAG_ALLOW_MULTIPLE_SOURCE_INSTANCES = 0x1;

        public static readonly Guid CLSID_AzAuthorizationStore__scanned__ = new Guid(0xb2bcff59, 0xa757, 0x4b0b, 0xa1, 0xbc, 0xea, 0x69, 0x98, 0x1d, 0xa6, 0x9e);

        public static readonly Guid CLSID_AzBizRuleContext__scanned__ = new Guid(0x5c2dc96f, 0x8d51, 0x434b, 0xb3, 0x3c, 0x37, 0x9b, 0xcc, 0xae, 0x77, 0xc3);

        public static readonly Guid CLSID_AzPrincipalLocator__scanned__ = new Guid(0x483afb5d, 0x70df, 0x4e16, 0xab, 0xdc, 0xa1, 0xde, 0x4d, 0x01, 0x5a, 0x3e);

        [NativeTypeName("HRESULT")]
        public const int OLESCRIPT_E_SYNTAX = unchecked((int)0x80020101);

    }
}
