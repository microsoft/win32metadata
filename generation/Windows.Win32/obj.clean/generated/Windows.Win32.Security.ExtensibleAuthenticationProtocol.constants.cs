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


namespace Windows.Win32.Security.ExtensibleAuthenticationProtocol
{
    public static partial class Apis
    {
        public const uint FACILITY_EAP_MESSAGE = 0x0842;

        public const int EAP_GROUP_MASK = 0x0000FF00;

        public const int EAP_E_EAPHOST_FIRST = unchecked((int)0x80420000);

        public const int EAP_E_EAPHOST_LAST = unchecked((int)0x804200FF);

        public const int EAP_I_EAPHOST_FIRST = unchecked((int)0x80420000);

        public const int EAP_I_EAPHOST_LAST = unchecked((int)0x804200FF);

        public const uint EAP_E_CERT_STORE_INACCESSIBLE = 0x80420010;

        public const uint EAP_E_EAPHOST_METHOD_NOT_INSTALLED = 0x80420011;

        public const uint EAP_E_EAPHOST_THIRDPARTY_METHOD_HOST_RESET = 0x80420012;

        public const uint EAP_E_EAPHOST_EAPQEC_INACCESSIBLE = 0x80420013;

        public const uint EAP_E_EAPHOST_IDENTITY_UNKNOWN = 0x80420014;

        public const uint EAP_E_AUTHENTICATION_FAILED = 0x80420015;

        public const uint EAP_I_EAPHOST_EAP_NEGOTIATION_FAILED = 0x40420016;

        public const uint EAP_E_EAPHOST_METHOD_INVALID_PACKET = 0x80420017;

        public const uint EAP_E_EAPHOST_REMOTE_INVALID_PACKET = 0x80420018;

        public const uint EAP_E_EAPHOST_XML_MALFORMED = 0x80420019;

        public const uint EAP_E_METHOD_CONFIG_DOES_NOT_SUPPORT_SSO = 0x8042001A;

        public const uint EAP_E_EAPHOST_METHOD_OPERATION_NOT_SUPPORTED = 0x80420020;

        public const int EAP_E_USER_FIRST = unchecked((int)0x80420100);

        public const int EAP_E_USER_LAST = unchecked((int)0x804201FF);

        public const int EAP_I_USER_FIRST = 0x40420100;

        public const int EAP_I_USER_LAST = 0x404201FF;

        public const uint EAP_E_USER_CERT_NOT_FOUND = 0x80420100;

        public const uint EAP_E_USER_CERT_INVALID = 0x80420101;

        public const uint EAP_E_USER_CERT_EXPIRED = 0x80420102;

        public const uint EAP_E_USER_CERT_REVOKED = 0x80420103;

        public const uint EAP_E_USER_CERT_OTHER_ERROR = 0x80420104;

        public const uint EAP_E_USER_CERT_REJECTED = 0x80420105;

        public const uint EAP_I_USER_ACCOUNT_OTHER_ERROR = 0x40420110;

        public const uint EAP_E_USER_CREDENTIALS_REJECTED = 0x80420111;

        public const uint EAP_E_USER_NAME_PASSWORD_REJECTED = 0x80420112;

        public const uint EAP_E_NO_SMART_CARD_READER = 0x80420113;

        public const int EAP_E_SERVER_FIRST = unchecked((int)0x80420200);

        public const int EAP_E_SERVER_LAST = unchecked((int)0x804202FF);

        public const uint EAP_E_SERVER_CERT_NOT_FOUND = 0x80420200;

        public const uint EAP_E_SERVER_CERT_INVALID = 0x80420201;

        public const uint EAP_E_SERVER_CERT_EXPIRED = 0x80420202;

        public const uint EAP_E_SERVER_CERT_REVOKED = 0x80420203;

        public const uint EAP_E_SERVER_CERT_OTHER_ERROR = 0x80420204;

        public const int EAP_E_USER_ROOT_CERT_FIRST = unchecked((int)0x80420300);

        public const int EAP_E_USER_ROOT_CERT_LAST = unchecked((int)0x804203FF);

        public const uint EAP_E_USER_ROOT_CERT_NOT_FOUND = 0x80420300;

        public const uint EAP_E_USER_ROOT_CERT_INVALID = 0x80420301;

        public const uint EAP_E_USER_ROOT_CERT_EXPIRED = 0x80420302;

        public const int EAP_E_SERVER_ROOT_CERT_FIRST = unchecked((int)0x80420400);

        public const int EAP_E_SERVER_ROOT_CERT_LAST = unchecked((int)0x804204FF);

        public const uint EAP_E_SERVER_ROOT_CERT_NOT_FOUND = 0x80420400;

        public const uint EAP_E_SERVER_ROOT_CERT_INVALID = 0x80420401;

        public const uint EAP_E_SERVER_ROOT_CERT_NAME_REQUIRED = 0x80420406;

        public const uint EAP_E_SIM_NOT_VALID = 0x80420500;

        public const uint EAP_PEER_FLAG_GUEST_ACCESS = 0x00000040;

        public const uint EAP_FLAG_Reserved1 = 0x00000001;

        public const uint EAP_FLAG_NON_INTERACTIVE = 0x00000002;

        public const uint EAP_FLAG_LOGON = 0x00000004;

        public const uint EAP_FLAG_PREVIEW = 0x00000008;

        public const uint EAP_FLAG_Reserved2 = 0x00000010;

        public const uint EAP_FLAG_MACHINE_AUTH = 0x00000020;

        public const uint EAP_FLAG_GUEST_ACCESS = 0x00000040;

        public const uint EAP_FLAG_Reserved3 = 0x00000080;

        public const uint EAP_FLAG_Reserved4 = 0x00000100;

        public const uint EAP_FLAG_RESUME_FROM_HIBERNATE = 0x00000200;

        public const uint EAP_FLAG_Reserved5 = 0x00000400;

        public const uint EAP_FLAG_Reserved6 = 0x00000800;

        public const uint EAP_FLAG_FULL_AUTH = 0x00001000;

        public const uint EAP_FLAG_PREFER_ALT_CREDENTIALS = 0x00002000;

        public const uint EAP_FLAG_Reserved7 = 0x00004000;

        public const uint EAP_PEER_FLAG_HEALTH_STATE_CHANGE = 0x00008000;

        public const uint EAP_FLAG_SUPRESS_UI = 0x00010000;

        public const uint EAP_FLAG_PRE_LOGON = 0x00020000;

        public const uint EAP_FLAG_USER_AUTH = 0x00040000;

        public const uint EAP_FLAG_CONFG_READONLY = 0x00080000;

        public const uint EAP_FLAG_Reserved8 = 0x00100000;

        public const uint EAP_FLAG_Reserved9 = 0x00400000;

        public const uint EAP_FLAG_VPN = 0x00800000;

        public const uint EAP_FLAG_ONLY_EAP_TLS = 0x01000000;

        public const uint EAP_CONFIG_INPUT_FIELD_PROPS_DEFAULT = 0X00000000;

        public const uint EAP_CONFIG_INPUT_FIELD_PROPS_NON_DISPLAYABLE = 0X00000001;

        public const uint EAP_CONFIG_INPUT_FIELD_PROPS_NON_PERSIST = 0X00000002;

        public const uint EAP_UI_INPUT_FIELD_PROPS_NON_PERSIST = 0X00000002;

        public const uint EAP_UI_INPUT_FIELD_PROPS_READ_ONLY = 0X00000004;

        public const uint EAP_CREDENTIAL_VERSION = 1;

        public const uint EAP_INTERACTIVE_UI_DATA_VERSION = 1;

        public const uint EAPHOST_PEER_API_VERSION = 1;

        public const uint EAPHOST_METHOD_API_VERSION = 1;

        public const uint MAX_EAP_CONFIG_INPUT_FIELD_LENGTH = 256;

        public const uint MAX_EAP_CONFIG_INPUT_FIELD_VALUE_LENGTH = 1024;

        public const uint CERTIFICATE_HASH_LENGTH = 20;

        public const uint EAP_METHOD_AUTHENTICATOR_CONFIG_IS_IDENTITY_PRIVACY = 0x1;

        public const uint RAS_EAP_ROLE_AUTHENTICATOR = 0x00000001;

        public const uint RAS_EAP_ROLE_AUTHENTICATEE = 0x00000002;

        public const uint RAS_EAP_ROLE_EXCLUDE_IN_EAP = 0x00000004;

        public const uint RAS_EAP_ROLE_EXCLUDE_IN_PEAP = 0x00000008;

        public const uint RAS_EAP_ROLE_EXCLUDE_IN_VPN = 0x00000010;

        public const uint EAPCODE_Request = 1;

        public const uint EAPCODE_Response = 2;

        public const uint EAPCODE_Success = 3;

        public const uint EAPCODE_Failure = 4;

        public const uint MAXEAPCODE = 4;

        public const uint RAS_EAP_FLAG_ROUTER = 0x00000001;

        public const uint RAS_EAP_FLAG_NON_INTERACTIVE = 0x00000002;

        public const uint RAS_EAP_FLAG_LOGON = 0x00000004;

        public const uint RAS_EAP_FLAG_PREVIEW = 0x00000008;

        public const uint RAS_EAP_FLAG_FIRST_LINK = 0x00000010;

        public const uint RAS_EAP_FLAG_MACHINE_AUTH = 0x00000020;

        public const uint RAS_EAP_FLAG_GUEST_ACCESS = 0x00000040;

        public const uint RAS_EAP_FLAG_8021X_AUTH = 0x00000080;

        public const uint RAS_EAP_FLAG_HOSTED_IN_PEAP = 0x00000100;

        public const uint RAS_EAP_FLAG_RESUME_FROM_HIBERNATE = 0x00000200;

        public const uint RAS_EAP_FLAG_PEAP_UPFRONT = 0x00000400;

        public const uint RAS_EAP_FLAG_ALTERNATIVE_USER_DB = 0x00000800;

        public const uint RAS_EAP_FLAG_PEAP_FORCE_FULL_AUTH = 0x00001000;

        public const uint RAS_EAP_FLAG_PRE_LOGON = 0x00020000;

        public const uint RAS_EAP_FLAG_CONFG_READONLY = 0x00080000;

        public const uint RAS_EAP_FLAG_RESERVED = 0x00100000;

        public const uint RAS_EAP_FLAG_SAVE_CREDMAN = 0x00200000;

    }
}
