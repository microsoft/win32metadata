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


namespace Windows.Win32.Security.Credentials
{
    public static partial class Apis
    {
        public static readonly Guid GUID_DEVINTERFACE_SMARTCARD_READER__scanned__ = new Guid(0x50DD5230, 0xBA8A, 0x11D1, 0xBF, 0x5D, 0x00, 0x00, 0xF8, 0x05, 0xF5, 0x30);

        public const uint SCARD_ATR_LENGTH = 33;

        public const uint SCARD_PROTOCOL_UNDEFINED = 0x00000000;

        public const uint SCARD_PROTOCOL_T0 = 0x00000001;

        public const uint SCARD_PROTOCOL_T1 = 0x00000002;

        public const uint SCARD_PROTOCOL_RAW = 0x00010000;

        public const uint SCARD_PROTOCOL_DEFAULT = 0x80000000;

        public const uint SCARD_PROTOCOL_OPTIMAL = 0x00000000;

        public const uint SCARD_POWER_DOWN = 0;

        public const uint SCARD_COLD_RESET = 1;

        public const uint SCARD_WARM_RESET = 2;

        public const uint MAXIMUM_ATTR_STRING_LENGTH = 32;

        public const uint MAXIMUM_SMARTCARD_READERS = 10;

        public const uint SCARD_CLASS_VENDOR_INFO = 1;

        public const uint SCARD_CLASS_COMMUNICATIONS = 2;

        public const uint SCARD_CLASS_PROTOCOL = 3;

        public const uint SCARD_CLASS_POWER_MGMT = 4;

        public const uint SCARD_CLASS_SECURITY = 5;

        public const uint SCARD_CLASS_MECHANICAL = 6;

        public const uint SCARD_CLASS_VENDOR_DEFINED = 7;

        public const uint SCARD_CLASS_IFD_PROTOCOL = 8;

        public const uint SCARD_CLASS_ICC_STATE = 9;

        public const uint SCARD_CLASS_PERF = 0x7ffe;

        public const uint SCARD_CLASS_SYSTEM = 0x7fff;

        public const uint SCARD_T0_HEADER_LENGTH = 7;

        public const uint SCARD_T0_CMD_LENGTH = 5;

        public const uint SCARD_T1_PROLOGUE_LENGTH = 3;

        public const uint SCARD_T1_EPILOGUE_LENGTH = 2;

        public const uint SCARD_T1_EPILOGUE_LENGTH_LRC = 1;

        public const uint SCARD_T1_MAX_IFS = 254;

        public const uint SCARD_UNKNOWN = 0;

        public const uint SCARD_ABSENT = 1;

        public const uint SCARD_PRESENT = 2;

        public const uint SCARD_SWALLOWED = 3;

        public const uint SCARD_POWERED = 4;

        public const uint SCARD_NEGOTIABLE = 5;

        public const uint SCARD_SPECIFIC = 6;

        public const uint SCARD_READER_SWALLOWS = 0x00000001;

        public const uint SCARD_READER_EJECTS = 0x00000002;

        public const uint SCARD_READER_CONFISCATES = 0x00000004;

        public const uint SCARD_READER_CONTACTLESS = 0x00000008;

        public const uint SCARD_READER_TYPE_SERIAL = 0x01;

        public const uint SCARD_READER_TYPE_PARALELL = 0x02;

        public const uint SCARD_READER_TYPE_KEYBOARD = 0x04;

        public const uint SCARD_READER_TYPE_SCSI = 0x08;

        public const uint SCARD_READER_TYPE_IDE = 0x10;

        public const uint SCARD_READER_TYPE_USB = 0x20;

        public const uint SCARD_READER_TYPE_PCMCIA = 0x40;

        public const uint SCARD_READER_TYPE_TPM = 0x80;

        public const uint SCARD_READER_TYPE_NFC = 0x100;

        public const uint SCARD_READER_TYPE_UICC = 0x200;

        public const uint SCARD_READER_TYPE_NGC = 0x400;

        public const uint SCARD_READER_TYPE_EMBEDDEDSE = 0x800;

        public const uint SCARD_READER_TYPE_VENDOR = 0xF0;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGON_FAILURE = unchecked((int)0xC000006D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WRONG_PASSWORD = unchecked((int)0xC000006A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PASSWORD_EXPIRED = unchecked((int)0xC0000071);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PASSWORD_MUST_CHANGE = unchecked((int)0xC0000224);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_DENIED = unchecked((int)0xC0000022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DOWNGRADE_DETECTED = unchecked((int)0xC0000388);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AUTHENTICATION_FIREWALL_FAILED = unchecked((int)0xC0000413);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCOUNT_DISABLED = unchecked((int)0xC0000072);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCOUNT_RESTRICTION = unchecked((int)0xC000006E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCOUNT_LOCKED_OUT = unchecked((int)0xC0000234);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCOUNT_EXPIRED = unchecked((int)0xC0000193);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGON_TYPE_NOT_GRANTED = unchecked((int)0xC000015B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_LOGON_SESSION = unchecked((int)0xC000005F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_USER = unchecked((int)0xC0000064);

        public const uint CRED_MAX_STRING_LENGTH = 256;

        public const uint CRED_MAX_GENERIC_TARGET_NAME_LENGTH = 32767;

        public const uint CRED_MAX_TARGETNAME_NAMESPACE_LENGTH = 256;

        public const uint CRED_MAX_TARGETNAME_ATTRIBUTE_LENGTH = 256;

        public const uint CRED_MAX_VALUE_SIZE = 256;

        public const uint CRED_MAX_ATTRIBUTES = 64;

        public const uint CRED_LOGON_TYPES_MASK = 0xF000;

        public const uint CRED_TI_SERVER_FORMAT_UNKNOWN = 0x0001;

        public const uint CRED_TI_DOMAIN_FORMAT_UNKNOWN = 0x0002;

        public const uint CRED_TI_ONLY_PASSWORD_REQUIRED = 0x0004;

        public const uint CRED_TI_USERNAME_TARGET = 0x0008;

        public const uint CRED_TI_CREATE_EXPLICIT_CRED = 0x0010;

        public const uint CRED_TI_WORKGROUP_MEMBER = 0x0020;

        public const uint CRED_TI_DNSTREE_IS_DFS_SERVER = 0x0040;

        public const uint CRED_TI_VALID_FLAGS = 0xF07F;

        public const uint CERT_HASH_LENGTH = 20;

        public const uint CREDUI_MAX_MESSAGE_LENGTH = 1024;

        public const uint CREDUI_MAX_CAPTION_LENGTH = 128;

        public const uint CRED_PRESERVE_CREDENTIAL_BLOB = 0x1;

        public const uint CRED_CACHE_TARGET_INFORMATION = 0x1;

        public const uint CRED_ALLOW_NAME_RESOLUTION = 0x1;

        public const uint CRED_PROTECT_AS_SELF = 0x1;

        public const uint CRED_PROTECT_TO_SYSTEM = 0x2;

        public const uint CRED_UNPROTECT_AS_SELF = 0x1;

        public const uint CRED_UNPROTECT_ALLOW_TO_SYSTEM = 0x2;

        public const uint SCARD_SCOPE_TERMINAL = 1;

        public const uint SCARD_PROVIDER_PRIMARY = 1;

        public const uint SCARD_PROVIDER_CSP = 2;

        public const uint SCARD_PROVIDER_KSP = 3;

        public const uint SCARD_STATE_UNPOWERED = 0x00000400;

        public const uint SCARD_SHARE_EXCLUSIVE = 1;

        public const uint SCARD_SHARE_SHARED = 2;

        public const uint SCARD_SHARE_DIRECT = 3;

        public const uint SCARD_LEAVE_CARD = 0;

        public const uint SCARD_RESET_CARD = 1;

        public const uint SCARD_UNPOWER_CARD = 2;

        public const uint SCARD_EJECT_CARD = 3;

        public const uint SC_DLG_MINIMAL_UI = 0x01;

        public const uint SC_DLG_NO_UI = 0x02;

        public const uint SC_DLG_FORCE_UI = 0x04;

        public const uint SCERR_NOCARDNAME = 0x4000;

        public const uint SCERR_NOGUIDS = 0x8000;

        public const uint SCARD_AUDIT_CHV_FAILURE = 0x0;

        public const uint SCARD_AUDIT_CHV_SUCCESS = 0x1;

    }
}
