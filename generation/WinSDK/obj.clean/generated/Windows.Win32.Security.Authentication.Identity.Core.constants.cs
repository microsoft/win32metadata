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


namespace Windows.Win32.Security.Authentication.Identity.Core
{
    public static partial class Apis
    {
        public const uint ISSP_LEVEL = 32;

        public const uint ISSP_MODE = 1;

        public const uint SECPKG_FLAG_INTEGRITY = 0x00000001;

        public const uint SECPKG_FLAG_PRIVACY = 0x00000002;

        public const uint SECPKG_FLAG_TOKEN_ONLY = 0x00000004;

        public const uint SECPKG_FLAG_DATAGRAM = 0x00000008;

        public const uint SECPKG_FLAG_CONNECTION = 0x00000010;

        public const uint SECPKG_FLAG_MULTI_REQUIRED = 0x00000020;

        public const uint SECPKG_FLAG_CLIENT_ONLY = 0x00000040;

        public const uint SECPKG_FLAG_EXTENDED_ERROR = 0x00000080;

        public const uint SECPKG_FLAG_IMPERSONATION = 0x00000100;

        public const uint SECPKG_FLAG_ACCEPT_WIN32_NAME = 0x00000200;

        public const uint SECPKG_FLAG_STREAM = 0x00000400;

        public const uint SECPKG_FLAG_NEGOTIABLE = 0x00000800;

        public const uint SECPKG_FLAG_GSS_COMPATIBLE = 0x00001000;

        public const uint SECPKG_FLAG_LOGON = 0x00002000;

        public const uint SECPKG_FLAG_ASCII_BUFFERS = 0x00004000;

        public const uint SECPKG_FLAG_FRAGMENT = 0x00008000;

        public const uint SECPKG_FLAG_MUTUAL_AUTH = 0x00010000;

        public const uint SECPKG_FLAG_DELEGATION = 0x00020000;

        public const uint SECPKG_FLAG_READONLY_WITH_CHECKSUM = 0x00040000;

        public const uint SECPKG_FLAG_RESTRICTED_TOKENS = 0x00080000;

        public const uint SECPKG_FLAG_NEGO_EXTENDER = 0x00100000;

        public const uint SECPKG_FLAG_NEGOTIABLE2 = 0x00200000;

        public const uint SECPKG_FLAG_APPCONTAINER_PASSTHROUGH = 0x00400000;

        public const uint SECPKG_FLAG_APPCONTAINER_CHECKS = 0x00800000;

        public const uint SECPKG_FLAG_CREDENTIAL_ISOLATION_ENABLED = 0x01000000;

        public const uint SECPKG_FLAG_APPLY_LOOPBACK = 0x02000000;

        public const uint SECPKG_ID_NONE = 0xFFFF;

        public const uint SECPKG_CALLFLAGS_APPCONTAINER = 0x00000001;

        public const uint SECPKG_CALLFLAGS_APPCONTAINER_AUTHCAPABLE = 0x00000002;

        public const uint SECPKG_CALLFLAGS_FORCE_SUPPLIED = 0x00000004;

        public const uint SECPKG_CALLFLAGS_APPCONTAINER_UPNCAPABLE = 0x00000008;

        public const uint SECBUFFER_VERSION = 0;

        public const uint SECBUFFER_EMPTY = 0;

        public const uint SECBUFFER_DATA = 1;

        public const uint SECBUFFER_TOKEN = 2;

        public const uint SECBUFFER_PKG_PARAMS = 3;

        public const uint SECBUFFER_MISSING = 4;

        public const uint SECBUFFER_EXTRA = 5;

        public const uint SECBUFFER_STREAM_TRAILER = 6;

        public const uint SECBUFFER_STREAM_HEADER = 7;

        public const uint SECBUFFER_NEGOTIATION_INFO = 8;

        public const uint SECBUFFER_PADDING = 9;

        public const uint SECBUFFER_STREAM = 10;

        public const uint SECBUFFER_MECHLIST = 11;

        public const uint SECBUFFER_MECHLIST_SIGNATURE = 12;

        public const uint SECBUFFER_TARGET = 13;

        public const uint SECBUFFER_CHANNEL_BINDINGS = 14;

        public const uint SECBUFFER_CHANGE_PASS_RESPONSE = 15;

        public const uint SECBUFFER_TARGET_HOST = 16;

        public const uint SECBUFFER_ALERT = 17;

        public const uint SECBUFFER_APPLICATION_PROTOCOLS = 18;

        public const uint SECBUFFER_SRTP_PROTECTION_PROFILES = 19;

        public const uint SECBUFFER_SRTP_MASTER_KEY_IDENTIFIER = 20;

        public const uint SECBUFFER_TOKEN_BINDING = 21;

        public const uint SECBUFFER_PRESHARED_KEY = 22;

        public const uint SECBUFFER_PRESHARED_KEY_IDENTITY = 23;

        public const uint SECBUFFER_DTLS_MTU = 24;

        public const uint SECBUFFER_SEND_GENERIC_TLS_EXTENSION = 25;

        public const uint SECBUFFER_SUBSCRIBE_GENERIC_TLS_EXTENSION = 26;

        public const uint SECBUFFER_FLAGS = 27;

        public const uint SECBUFFER_TRAFFIC_SECRETS = 28;

        public const uint SECBUFFER_ATTRMASK = 0xF0000000;

        public const uint SECBUFFER_READONLY = 0x80000000;

        public const uint SECBUFFER_READONLY_WITH_CHECKSUM = 0x10000000;

        public const uint SECBUFFER_RESERVED = 0x60000000;

        public const uint SZ_ALG_MAX_SIZE = 64;

        public const uint SECURITY_NATIVE_DREP = 0x00000010;

        public const uint SECURITY_NETWORK_DREP = 0x00000000;

        public const uint SECPKG_CRED_BOTH = 0x00000003;

        public const uint SECPKG_CRED_DEFAULT = 0x00000004;

        public const uint SECPKG_CRED_RESERVED = 0xF0000000;

        public const uint SECPKG_CRED_AUTOLOGON_RESTRICTED = 0x00000010;

        public const uint SECPKG_CRED_PROCESS_POLICY_ONLY = 0x00000020;

        public const uint ISC_REQ_DELEGATE = 0x00000001;

        public const uint ISC_REQ_MUTUAL_AUTH = 0x00000002;

        public const uint ISC_REQ_REPLAY_DETECT = 0x00000004;

        public const uint ISC_REQ_SEQUENCE_DETECT = 0x00000008;

        public const uint ISC_REQ_CONFIDENTIALITY = 0x00000010;

        public const uint ISC_REQ_USE_SESSION_KEY = 0x00000020;

        public const uint ISC_REQ_PROMPT_FOR_CREDS = 0x00000040;

        public const uint ISC_REQ_USE_SUPPLIED_CREDS = 0x00000080;

        public const uint ISC_REQ_ALLOCATE_MEMORY = 0x00000100;

        public const uint ISC_REQ_USE_DCE_STYLE = 0x00000200;

        public const uint ISC_REQ_DATAGRAM = 0x00000400;

        public const uint ISC_REQ_CONNECTION = 0x00000800;

        public const uint ISC_REQ_CALL_LEVEL = 0x00001000;

        public const uint ISC_REQ_FRAGMENT_SUPPLIED = 0x00002000;

        public const uint ISC_REQ_EXTENDED_ERROR = 0x00004000;

        public const uint ISC_REQ_STREAM = 0x00008000;

        public const uint ISC_REQ_INTEGRITY = 0x00010000;

        public const uint ISC_REQ_IDENTIFY = 0x00020000;

        public const uint ISC_REQ_NULL_SESSION = 0x00040000;

        public const uint ISC_REQ_MANUAL_CRED_VALIDATION = 0x00080000;

        public const uint ISC_REQ_RESERVED1 = 0x00100000;

        public const uint ISC_REQ_FRAGMENT_TO_FIT = 0x00200000;

        public const uint ISC_REQ_FORWARD_CREDENTIALS = 0x00400000;

        public const uint ISC_REQ_NO_INTEGRITY = 0x00800000;

        public const uint ISC_REQ_USE_HTTP_STYLE = 0x01000000;

        public const uint ISC_REQ_UNVERIFIED_TARGET_NAME = 0x20000000;

        public const uint ISC_REQ_CONFIDENTIALITY_ONLY = 0x40000000;

        public const ulong ISC_REQ_MESSAGES = 0x0000000100000000;

        public const uint ISC_RET_DELEGATE = 0x00000001;

        public const uint ISC_RET_MUTUAL_AUTH = 0x00000002;

        public const uint ISC_RET_REPLAY_DETECT = 0x00000004;

        public const uint ISC_RET_SEQUENCE_DETECT = 0x00000008;

        public const uint ISC_RET_CONFIDENTIALITY = 0x00000010;

        public const uint ISC_RET_USE_SESSION_KEY = 0x00000020;

        public const uint ISC_RET_USED_COLLECTED_CREDS = 0x00000040;

        public const uint ISC_RET_USED_SUPPLIED_CREDS = 0x00000080;

        public const uint ISC_RET_ALLOCATED_MEMORY = 0x00000100;

        public const uint ISC_RET_USED_DCE_STYLE = 0x00000200;

        public const uint ISC_RET_DATAGRAM = 0x00000400;

        public const uint ISC_RET_CONNECTION = 0x00000800;

        public const uint ISC_RET_INTERMEDIATE_RETURN = 0x00001000;

        public const uint ISC_RET_CALL_LEVEL = 0x00002000;

        public const uint ISC_RET_EXTENDED_ERROR = 0x00004000;

        public const uint ISC_RET_STREAM = 0x00008000;

        public const uint ISC_RET_INTEGRITY = 0x00010000;

        public const uint ISC_RET_IDENTIFY = 0x00020000;

        public const uint ISC_RET_NULL_SESSION = 0x00040000;

        public const uint ISC_RET_MANUAL_CRED_VALIDATION = 0x00080000;

        public const uint ISC_RET_RESERVED1 = 0x00100000;

        public const uint ISC_RET_FRAGMENT_ONLY = 0x00200000;

        public const uint ISC_RET_FORWARD_CREDENTIALS = 0x00400000;

        public const uint ISC_RET_USED_HTTP_STYLE = 0x01000000;

        public const uint ISC_RET_NO_ADDITIONAL_TOKEN = 0x02000000;

        public const uint ISC_RET_REAUTHENTICATION = 0x08000000;

        public const uint ISC_RET_CONFIDENTIALITY_ONLY = 0x40000000;

        public const ulong ISC_RET_MESSAGES = 0x0000000100000000;

        public const uint ASC_REQ_MUTUAL_AUTH = 0x00000002;

        public const uint ASC_REQ_CONFIDENTIALITY = 0x00000010;

        public const uint ASC_REQ_USE_SESSION_KEY = 0x00000020;

        public const uint ASC_REQ_SESSION_TICKET = 0x00000040;

        public const uint ASC_REQ_USE_DCE_STYLE = 0x00000200;

        public const uint ASC_REQ_DATAGRAM = 0x00000400;

        public const uint ASC_REQ_CALL_LEVEL = 0x00001000;

        public const uint ASC_REQ_FRAGMENT_SUPPLIED = 0x00002000;

        public const uint ASC_REQ_INTEGRITY = 0x00020000;

        public const uint ASC_REQ_LICENSING = 0x00040000;

        public const uint ASC_REQ_IDENTIFY = 0x00080000;

        public const uint ASC_REQ_ALLOW_NULL_SESSION = 0x00100000;

        public const uint ASC_REQ_ALLOW_NON_USER_LOGONS = 0x00200000;

        public const uint ASC_REQ_ALLOW_CONTEXT_REPLAY = 0x00400000;

        public const uint ASC_REQ_FRAGMENT_TO_FIT = 0x00800000;

        public const uint ASC_REQ_NO_TOKEN = 0x01000000;

        public const uint ASC_REQ_PROXY_BINDINGS = 0x04000000;

        public const uint ASC_REQ_ALLOW_MISSING_BINDINGS = 0x10000000;

        public const ulong ASC_REQ_MESSAGES = 0x0000000100000000;

        public const uint ASC_RET_DELEGATE = 0x00000001;

        public const uint ASC_RET_MUTUAL_AUTH = 0x00000002;

        public const uint ASC_RET_REPLAY_DETECT = 0x00000004;

        public const uint ASC_RET_SEQUENCE_DETECT = 0x00000008;

        public const uint ASC_RET_CONFIDENTIALITY = 0x00000010;

        public const uint ASC_RET_USE_SESSION_KEY = 0x00000020;

        public const uint ASC_RET_SESSION_TICKET = 0x00000040;

        public const uint ASC_RET_ALLOCATED_MEMORY = 0x00000100;

        public const uint ASC_RET_USED_DCE_STYLE = 0x00000200;

        public const uint ASC_RET_DATAGRAM = 0x00000400;

        public const uint ASC_RET_CONNECTION = 0x00000800;

        public const uint ASC_RET_CALL_LEVEL = 0x00002000;

        public const uint ASC_RET_THIRD_LEG_FAILED = 0x00004000;

        public const uint ASC_RET_EXTENDED_ERROR = 0x00008000;

        public const uint ASC_RET_STREAM = 0x00010000;

        public const uint ASC_RET_INTEGRITY = 0x00020000;

        public const uint ASC_RET_LICENSING = 0x00040000;

        public const uint ASC_RET_IDENTIFY = 0x00080000;

        public const uint ASC_RET_NULL_SESSION = 0x00100000;

        public const uint ASC_RET_ALLOW_NON_USER_LOGONS = 0x00200000;

        public const uint ASC_RET_ALLOW_CONTEXT_REPLAY = 0x00400000;

        public const uint ASC_RET_FRAGMENT_ONLY = 0x00800000;

        public const uint ASC_RET_NO_TOKEN = 0x01000000;

        public const uint ASC_RET_NO_ADDITIONAL_TOKEN = 0x02000000;

        public const ulong ASC_RET_MESSAGES = 0x0000000100000000;

        public const uint SECPKG_CRED_ATTR_NAMES = 1;

        public const uint SECPKG_CRED_ATTR_SSI_PROVIDER = 2;

        public const uint SECPKG_CRED_ATTR_KDC_PROXY_SETTINGS = 3;

        public const uint SECPKG_CRED_ATTR_CERT = 4;

        public const uint SECPKG_CRED_ATTR_PAC_BYPASS = 5;

        public const uint KDC_PROXY_SETTINGS_V1 = 1;

        public const uint KDC_PROXY_SETTINGS_FLAGS_FORCEPROXY = 0x1;

        public const uint SECPKG_ATTR_PROTO_INFO = 7;

        public const uint SECPKG_ATTR_USER_FLAGS = 11;

        public const uint SECPKG_ATTR_USE_VALIDATED = 15;

        public const uint SECPKG_ATTR_CREDENTIAL_NAME = 16;

        public const uint SECPKG_ATTR_TARGET = 19;

        public const uint SECPKG_ATTR_AUTHENTICATION_ID = 20;

        public const uint SECPKG_ATTR_LOGOFF_TIME = 21;

        public const uint SECPKG_ATTR_NEGO_KEYS = 22;

        public const uint SECPKG_ATTR_PROMPTING_NEEDED = 24;

        public const uint SECPKG_ATTR_NEGO_PKG_INFO = 31;

        public const uint SECPKG_ATTR_NEGO_STATUS = 32;

        public const uint SECPKG_ATTR_CONTEXT_DELETED = 33;

        public const uint SECPKG_ATTR_APPLICATION_PROTOCOL = 35;

        public const uint SECPKG_ATTR_NEGOTIATED_TLS_EXTENSIONS = 36;

        public const uint SECPKG_ATTR_IS_LOOPBACK = 37;

        public const uint SECPKG_ATTR_NEGO_INFO_FLAG_NO_KERBEROS = 0x1;

        public const uint SECPKG_ATTR_NEGO_INFO_FLAG_NO_NTLM = 0x2;

        public const uint SECPKG_NEGOTIATION_COMPLETE = 0;

        public const uint SECPKG_NEGOTIATION_OPTIMISTIC = 1;

        public const uint SECPKG_NEGOTIATION_IN_PROGRESS = 2;

        public const uint SECPKG_NEGOTIATION_DIRECT = 3;

        public const uint SECPKG_NEGOTIATION_TRY_MULTICRED = 4;

        public const uint MAX_PROTOCOL_ID_SIZE = 0xff;

        public const uint SECQOP_WRAP_NO_ENCRYPT = 0x80000001;

        public const uint SECQOP_WRAP_OOB_DATA = 0x40000000;

        public const uint SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION = 1;

        public const uint SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_2 = 2;

        public const uint SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_3 = 3;

        public const uint SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_4 = 4;

        public const uint SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_5 = 5;

        public const uint SASL_OPTION_SEND_SIZE = 1;

        public const uint SASL_OPTION_RECV_SIZE = 2;

        public const uint SASL_OPTION_AUTHZ_STRING = 3;

        public const uint SASL_OPTION_AUTHZ_PROCESSING = 4;

        public const uint SEC_WINNT_AUTH_IDENTITY_VERSION_2 = 0x201;

        public const uint SEC_WINNT_AUTH_IDENTITY_VERSION = 0x200;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_PROCESS_ENCRYPTED = 0x10;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_SYSTEM_PROTECTED = 0x20;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_USER_PROTECTED = 0x40;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_SYSTEM_ENCRYPTED = 0x80;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_RESERVED = 0x10000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_USER = 0x20000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_DOMAIN = 0x40000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_ID_PROVIDER = 0x80000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_USE_MASK = 0xFF000000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_CREDPROV_DO_NOT_SAVE = 0x80000000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_CHECKED = 0x40000000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_NO_CHECKBOX = 0x20000000;

        public const uint SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_CREDPROV_DO_NOT_LOAD = 0x10000000;

        public const uint SSPIPFC_CREDPROV_DO_NOT_SAVE = 0x00000001;

        public const uint SSPIPFC_NO_CHECKBOX = 0x00000002;

        public const uint SSPIPFC_CREDPROV_DO_NOT_LOAD = 0x00000004;

        public const uint SSPIPFC_USE_CREDUIBROKER = 0x00000008;

        public const uint NGC_DATA_FLAG_KERB_CERTIFICATE_LOGON_FLAG_CHECK_DUPLICATES = 0x1;

        public const uint NGC_DATA_FLAG_KERB_CERTIFICATE_LOGON_FLAG_USE_CERTIFICATE_INFO = 0x2;

        public const uint NGC_DATA_FLAG_IS_SMARTCARD_DATA = 0x4;

        public const uint SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON = 0x1;

        public const uint SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_PROCESS = 0x2;

        public const uint SEC_WINNT_AUTH_IDENTITY_ENCRYPT_FOR_SYSTEM = 0x4;

        public const uint SEC_WINNT_AUTH_IDENTITY_MARSHALLED = 0x4;

        public const uint SEC_WINNT_AUTH_IDENTITY_ONLY = 0x8;

        public const uint SECPKG_OPTIONS_PERMANENT = 0x00000001;

        public const uint LOOKUP_VIEW_LOCAL_INFORMATION = 0x00000001;

        public const uint LOOKUP_TRANSLATE_NAMES = 0x00000800;

        public const uint SECPKG_ATTR_ISSUER_LIST = 0x50;

        public const uint SECPKG_ATTR_REMOTE_CRED = 0x51;

        public const uint SECPKG_ATTR_SUPPORTED_ALGS = 0x56;

        public const uint SECPKG_ATTR_CIPHER_STRENGTHS = 0x57;

        public const uint SECPKG_ATTR_SUPPORTED_PROTOCOLS = 0x58;

        public const uint SECPKG_ATTR_MAPPED_CRED_ATTR = 0x5c;

        public const uint SECPKG_ATTR_REMOTE_CERTIFICATES = 0x5F;

        public const uint SECPKG_ATTR_CLIENT_CERT_POLICY = 0x60;

        public const uint SECPKG_ATTR_CC_POLICY_RESULT = 0x61;

        public const uint SECPKG_ATTR_USE_NCRYPT = 0x62;

        public const uint SECPKG_ATTR_LOCAL_CERT_INFO = 0x63;

        public const uint SECPKG_ATTR_CIPHER_INFO = 0x64;

        public const uint SECPKG_ATTR_REMOTE_CERT_CHAIN = 0x67;

        public const uint SECPKG_ATTR_UI_INFO = 0x68;

        public const uint SECPKG_ATTR_KEYING_MATERIAL = 0x6b;

        public const uint SECPKG_ATTR_SRTP_PARAMETERS = 0x6c;

        public const uint SECPKG_ATTR_TOKEN_BINDING = 0x6d;

        public const uint SECPKG_ATTR_CONNECTION_INFO_EX = 0x6e;

        public const uint SECPKG_ATTR_KEYING_MATERIAL_TOKEN_BINDING = 0x6f;

        public const uint SECPKG_ATTR_KEYING_MATERIAL_INPROC = 0x70;

        public const int LSA_MODE_PASSWORD_PROTECTED = 0x00000001;

        public const int LSA_MODE_INDIVIDUAL_ACCOUNTS = 0x00000002;

        public const int LSA_MODE_MANDATORY_ACCESS = 0x00000004;

        public const int LSA_MODE_LOG_FULL = 0x00000008;

        public const int LSA_MAXIMUM_SID_COUNT = 0x00000100;

        public const uint LSA_MAXIMUM_ENUMERATION_LENGTH = 32000;

        public const uint LSA_CALL_LICENSE_SERVER = 0x80000000;

        public const uint SE_ADT_OBJECT_ONLY = 0x1;

        public const uint SE_MAX_AUDIT_PARAMETERS = 32;

        public const uint SE_MAX_GENERIC_AUDIT_PARAMETERS = 28;

        public const uint SE_ADT_PARAMETERS_SELF_RELATIVE = 0x00000001;

        public const uint SE_ADT_PARAMETERS_SEND_TO_LSA = 0x00000002;

        public const uint SE_ADT_PARAMETER_EXTENSIBLE_AUDIT = 0x00000004;

        public const uint SE_ADT_PARAMETER_GENERIC_AUDIT = 0x00000008;

        public const uint SE_ADT_PARAMETER_WRITE_SYNCHRONOUS = 0x00000010;

        public const uint SE_ADT_POLICY_AUDIT_EVENT_TYPE_EX_BEGIN = 100;

        public const int POLICY_AUDIT_EVENT_UNCHANGED = 0x00000000;

        public const int POLICY_AUDIT_EVENT_SUCCESS = 0x00000001;

        public const int POLICY_AUDIT_EVENT_FAILURE = 0x00000002;

        public const int POLICY_AUDIT_EVENT_NONE = 0x00000004;

        public const int POLICY_VIEW_LOCAL_INFORMATION = 0x00000001;

        public const int POLICY_VIEW_AUDIT_INFORMATION = 0x00000002;

        public const int POLICY_GET_PRIVATE_INFORMATION = 0x00000004;

        public const int POLICY_TRUST_ADMIN = 0x00000008;

        public const int POLICY_CREATE_ACCOUNT = 0x00000010;

        public const int POLICY_CREATE_SECRET = 0x00000020;

        public const int POLICY_CREATE_PRIVILEGE = 0x00000040;

        public const int POLICY_SET_DEFAULT_QUOTA_LIMITS = 0x00000080;

        public const int POLICY_SET_AUDIT_REQUIREMENTS = 0x00000100;

        public const int POLICY_AUDIT_LOG_ADMIN = 0x00000200;

        public const int POLICY_SERVER_ADMIN = 0x00000400;

        public const int POLICY_LOOKUP_NAMES = 0x00000800;

        public const int POLICY_NOTIFICATION = 0x00001000;

        public const uint LSA_LOOKUP_ISOLATED_AS_LOCAL = 0x80000000;

        public const uint LSA_LOOKUP_DISALLOW_CONNECTED_ACCOUNT_INTERNET_SID = 0x80000000;

        public const uint LSA_LOOKUP_PREFER_INTERNET_NAMES = 0x40000000;

        public const uint PER_USER_POLICY_UNCHANGED = 0x00;

        public const uint PER_USER_AUDIT_SUCCESS_INCLUDE = 0x01;

        public const uint PER_USER_AUDIT_SUCCESS_EXCLUDE = 0x02;

        public const uint PER_USER_AUDIT_FAILURE_INCLUDE = 0x04;

        public const uint PER_USER_AUDIT_FAILURE_EXCLUDE = 0x08;

        public const uint PER_USER_AUDIT_NONE = 0x10;

        public const uint POLICY_QOS_SCHANNEL_REQUIRED = 0x00000001;

        public const uint POLICY_QOS_OUTBOUND_INTEGRITY = 0x00000002;

        public const uint POLICY_QOS_OUTBOUND_CONFIDENTIALITY = 0x00000004;

        public const uint POLICY_QOS_INBOUND_INTEGRITY = 0x00000008;

        public const uint POLICY_QOS_INBOUND_CONFIDENTIALITY = 0x00000010;

        public const uint POLICY_QOS_ALLOW_LOCAL_ROOT_CERT_STORE = 0x00000020;

        public const uint POLICY_QOS_RAS_SERVER_ALLOWED = 0x00000040;

        public const uint POLICY_QOS_DHCP_SERVER_ALLOWED = 0x00000080;

        public const uint POLICY_KERBEROS_VALIDATE_CLIENT = 0x00000080;

        public const int ACCOUNT_VIEW = 0x00000001;

        public const int ACCOUNT_ADJUST_PRIVILEGES = 0x00000002;

        public const int ACCOUNT_ADJUST_QUOTAS = 0x00000004;

        public const int ACCOUNT_ADJUST_SYSTEM_ACCESS = 0x00000008;

        public const int TRUSTED_QUERY_DOMAIN_NAME = 0x00000001;

        public const int TRUSTED_QUERY_CONTROLLERS = 0x00000002;

        public const int TRUSTED_SET_CONTROLLERS = 0x00000004;

        public const int TRUSTED_QUERY_POSIX = 0x00000008;

        public const int TRUSTED_SET_POSIX = 0x00000010;

        public const int TRUSTED_SET_AUTH = 0x00000020;

        public const int TRUSTED_QUERY_AUTH = 0x00000040;

        public const uint TRUST_ATTRIBUTE_TREE_PARENT = 0x00400000;

        public const uint TRUST_ATTRIBUTE_TREE_ROOT = 0x00800000;

        public const uint TRUST_ATTRIBUTES_VALID = 0xFF02FFFF;

        public const uint TRUST_ATTRIBUTE_QUARANTINED_DOMAIN = 0x00000004;

        public const uint TRUST_ATTRIBUTE_TRUST_USES_RC4_ENCRYPTION = 0x00000080;

        public const uint TRUST_ATTRIBUTE_TRUST_USES_AES_KEYS = 0x00000100;

        public const uint TRUST_ATTRIBUTE_CROSS_ORGANIZATION_NO_TGT_DELEGATION = 0x00000200;

        public const uint TRUST_ATTRIBUTE_PIM_TRUST = 0x00000400;

        public const uint TRUST_ATTRIBUTE_CROSS_ORGANIZATION_ENABLE_TGT_DELEGATION = 0x00000800;

        public const uint TRUST_ATTRIBUTES_USER = 0xFF000000;

        public const uint LSA_FOREST_TRUST_RECORD_TYPE_UNRECOGNIZED = 0x80000000;

        public const int LSA_FTRECORD_DISABLED_REASONS = 0x0000FFFF;

        public const int LSA_TLN_DISABLED_NEW = 0x00000001;

        public const int LSA_TLN_DISABLED_ADMIN = 0x00000002;

        public const int LSA_TLN_DISABLED_CONFLICT = 0x00000004;

        public const int LSA_SID_DISABLED_ADMIN = 0x00000001;

        public const int LSA_SID_DISABLED_CONFLICT = 0x00000002;

        public const int LSA_NB_DISABLED_ADMIN = 0x00000004;

        public const int LSA_NB_DISABLED_CONFLICT = 0x00000008;

        public const uint MAX_RECORDS_IN_FOREST_TRUST_INFO = 4000;

        public const int SECRET_SET_VALUE = 0x00000001;

        public const int SECRET_QUERY_VALUE = 0x00000002;

        public const uint LSA_GLOBAL_SECRET_PREFIX_LENGTH = 2;

        public const uint LSA_LOCAL_SECRET_PREFIX_LENGTH = 2;

        public const int LSA_SECRET_MAXIMUM_COUNT = 0x00001000;

        public const int LSA_SECRET_MAXIMUM_LENGTH = 0x00000200;

        public const uint MAXIMUM_CAPES_PER_CAP = 0x7F;

        public const uint CENTRAL_ACCESS_POLICY_OWNER_RIGHTS_PRESENT_FLAG = 0x00000001;

        public const uint CENTRAL_ACCESS_POLICY_STAGED_OWNER_RIGHTS_PRESENT_FLAG = 0x00000100;

        public const uint CENTRAL_ACCESS_POLICY_STAGED_FLAG = 0x00010000;

        public const uint LSASETCAPS_RELOAD_FLAG = 0x00000001;

        public const uint NEGOTIATE_MAX_PREFIX = 32;

        public const uint NEGOTIATE_ALLOW_NTLM = 0x10000000;

        public const uint NEGOTIATE_NEG_NTLM = 0x20000000;

        public const uint MAX_USER_RECORDS = 1000;

        public static readonly Guid Audit_System_SecurityStateChange__scanned__ = new Guid(0x0cce9210,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_System_SecuritySubsystemExtension__scanned__ = new Guid(0x0cce9211,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_System_Integrity__scanned__ = new Guid(0x0cce9212,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_System_IPSecDriverEvents__scanned__ = new Guid(0x0cce9213,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_System_Others__scanned__ = new Guid(0x0cce9214,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_Logon__scanned__ = new Guid(0x0cce9215,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_Logoff__scanned__ = new Guid(0x0cce9216,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_AccountLockout__scanned__ = new Guid(0x0cce9217,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_IPSecMainMode__scanned__ = new Guid(0x0cce9218,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_IPSecQuickMode__scanned__ = new Guid(0x0cce9219,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_IPSecUserMode__scanned__ = new Guid(0x0cce921a,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_SpecialLogon__scanned__ = new Guid(0x0cce921b,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_Others__scanned__ = new Guid(0x0cce921c,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_FileSystem__scanned__ = new Guid(0x0cce921d,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_Registry__scanned__ = new Guid(0x0cce921e,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_Kernel__scanned__ = new Guid(0x0cce921f,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_Sam__scanned__ = new Guid(0x0cce9220,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_CertificationServices__scanned__ = new Guid(0x0cce9221,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_ApplicationGenerated__scanned__ = new Guid(0x0cce9222,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_Handle__scanned__ = new Guid(0x0cce9223,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_Share__scanned__ = new Guid(0x0cce9224,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_FirewallPacketDrops__scanned__ = new Guid(0x0cce9225,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_FirewallConnection__scanned__ = new Guid(0x0cce9226,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_Other__scanned__ = new Guid(0x0cce9227,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PrivilegeUse_Sensitive__scanned__ = new Guid(0x0cce9228,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PrivilegeUse_NonSensitive__scanned__ = new Guid(0x0cce9229,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PrivilegeUse_Others__scanned__ = new Guid(0x0cce922a,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DetailedTracking_ProcessCreation__scanned__ = new Guid(0x0cce922b,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DetailedTracking_ProcessTermination__scanned__ = new Guid(0x0cce922c,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DetailedTracking_DpapiActivity__scanned__ = new Guid(0x0cce922d,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DetailedTracking_RpcCall__scanned__ = new Guid(0x0cce922e,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PolicyChange_AuditPolicy__scanned__ = new Guid(0x0cce922f,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PolicyChange_AuthenticationPolicy__scanned__ = new Guid(0x0cce9230,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PolicyChange_AuthorizationPolicy__scanned__ = new Guid(0x0cce9231,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PolicyChange_MpsscvRulePolicy__scanned__ = new Guid(0x0cce9232,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PolicyChange_WfpIPSecPolicy__scanned__ = new Guid(0x0cce9233,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PolicyChange_Others__scanned__ = new Guid(0x0cce9234,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountManagement_UserAccount__scanned__ = new Guid(0x0cce9235,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountManagement_ComputerAccount__scanned__ = new Guid(0x0cce9236,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountManagement_SecurityGroup__scanned__ = new Guid(0x0cce9237,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountManagement_DistributionGroup__scanned__ = new Guid(0x0cce9238,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountManagement_ApplicationGroup__scanned__ = new Guid(0x0cce9239,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountManagement_Others__scanned__ = new Guid(0x0cce923a,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DSAccess_DSAccess__scanned__ = new Guid(0x0cce923b,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DsAccess_AdAuditChanges__scanned__ = new Guid(0x0cce923c,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Ds_Replication__scanned__ = new Guid(0x0cce923d,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Ds_DetailedReplication__scanned__ = new Guid(0x0cce923e,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountLogon_CredentialValidation__scanned__ = new Guid(0x0cce923f,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountLogon_Kerberos__scanned__ = new Guid(0x0cce9240,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountLogon_Others__scanned__ = new Guid(0x0cce9241,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountLogon_KerbCredentialValidation__scanned__ = new Guid(0x0cce9242,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_NPS__scanned__ = new Guid(0x0cce9243,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_DetailedFileShare__scanned__ = new Guid(0x0cce9244,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_RemovableStorage__scanned__ = new Guid(0x0cce9245,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess_CbacStaging__scanned__ = new Guid(0x0cce9246,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_Claims__scanned__ = new Guid(0x0cce9247,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DetailedTracking_PnpActivity__scanned__ = new Guid(0x0cce9248,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon_Groups__scanned__ = new Guid(0x0cce9249,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DetailedTracking_TokenRightAdjusted__scanned__ = new Guid(0x0cce924a,        0x69ae, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_System__scanned__ = new Guid(0x69979848,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_Logon__scanned__ = new Guid(0x69979849,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_ObjectAccess__scanned__ = new Guid(0x6997984a,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PrivilegeUse__scanned__ = new Guid(0x6997984b,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DetailedTracking__scanned__ = new Guid(0x6997984c,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_PolicyChange__scanned__ = new Guid(0x6997984d,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountManagement__scanned__ = new Guid(0x6997984e,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_DirectoryServiceAccess__scanned__ = new Guid(0x6997984f,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public static readonly Guid Audit_AccountLogon__scanned__ = new Guid(0x69979850,        0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30        );

        public const int DOMAIN_NO_LM_OWF_CHANGE = 0x00000040;

        public const uint MSV1_0_CHALLENGE_LENGTH = 8;

        public const uint MSV1_0_USER_SESSION_KEY_LENGTH = 16;

        public const uint MSV1_0_LANMAN_SESSION_KEY_LENGTH = 8;

        public const uint MSV1_0_USE_CLIENT_CHALLENGE = 0x80;

        public const uint MSV1_0_DISABLE_PERSONAL_FALLBACK = 0x00001000;

        public const uint MSV1_0_ALLOW_FORCE_GUEST = 0x00002000;

        public const uint MSV1_0_CLEARTEXT_PASSWORD_SUPPLIED = 0x00004000;

        public const uint MSV1_0_USE_DOMAIN_FOR_ROUTING_ONLY = 0x00008000;

        public const uint MSV1_0_SUBAUTHENTICATION_DLL_EX = 0x00100000;

        public const uint MSV1_0_ALLOW_MSVCHAPV2 = 0x00010000;

        public const uint MSV1_0_S4U2SELF = 0x00020000;

        public const uint MSV1_0_CHECK_LOGONHOURS_FOR_S4U = 0x00040000;

        public const uint MSV1_0_INTERNET_DOMAIN = 0x00080000;

        public const uint MSV1_0_SUBAUTHENTICATION_DLL = 0xFF000000;

        public const uint MSV1_0_SUBAUTHENTICATION_DLL_SHIFT = 24;

        public const uint MSV1_0_MNS_LOGON = 0x01000000;

        public const uint MSV1_0_SUBAUTHENTICATION_DLL_RAS = 2;

        public const uint MSV1_0_SUBAUTHENTICATION_DLL_IIS = 132;

        public const uint MSV1_0_S4U_LOGON_FLAG_CHECK_LOGONHOURS = 0x2;

        public const uint LOGON_NTLMV2_ENABLED = 0x100;

        public const uint LOGON_NT_V2 = 0x800;

        public const uint LOGON_LM_V2 = 0x1000;

        public const uint LOGON_NTLM_V2 = 0x2000;

        public const uint LOGON_OPTIMIZED = 0x4000;

        public const uint LOGON_WINLOGON = 0x8000;

        public const uint LOGON_PKINIT = 0x10000;

        public const uint LOGON_NO_OPTIMIZED = 0x20000;

        public const uint LOGON_NO_ELEVATION = 0x40000;

        public const uint LOGON_MANAGED_SERVICE = 0x80000;

        public const uint MSV1_0_SUBAUTHENTICATION_FLAGS = 0xFF000000;

        public const uint LOGON_GRACE_LOGON = 0x01000000;

        public const uint MSV1_0_OWF_PASSWORD_LENGTH = 16;

        public const uint MSV1_0_SHA_PASSWORD_LENGTH = 20;

        public const uint MSV1_0_CREDENTIAL_KEY_LENGTH = 20;

        public const uint MSV1_0_CRED_REMOVED = 0x0004;

        public const uint MSV1_0_CRED_CREDKEY_PRESENT = 0x0008;

        public const uint MSV1_0_CRED_SHA_PRESENT = 0x0010;

        public const uint MSV1_0_CRED_VERSION_V2 = 2;

        public const uint MSV1_0_CRED_VERSION_V3 = 4;

        public const uint MSV1_0_CRED_VERSION_IUM = 0xffff0001;

        public const uint MSV1_0_CRED_VERSION_REMOTE = 0xffff0002;

        public const uint MSV1_0_CRED_VERSION_ARSO = 0xffff0003;

        public const uint MSV1_0_CRED_VERSION_RESERVED_1 = 0xfffffffe;

        public const uint MSV1_0_CRED_VERSION_INVALID = 0xffffffff;

        public const uint MSV1_0_NTLM3_RESPONSE_LENGTH = 16;

        public const uint MSV1_0_NTLM3_OWF_LENGTH = 16;

        public const uint MSV1_0_MAX_NTLM3_LIFE = 1800;

        public const uint MSV1_0_MAX_AVL_SIZE = 64000;

        public const uint MSV1_0_AV_FLAG_FORCE_GUEST = 0x00000001;

        public const uint MSV1_0_AV_FLAG_MIC_HANDSHAKE_MESSAGES = 0x00000002;

        public const uint MSV1_0_AV_FLAG_UNVERIFIED_TARGET = 0x00000004;

        public const uint RTL_ENCRYPT_MEMORY_SIZE = 8;

        public const uint RTL_ENCRYPT_OPTION_CROSS_PROCESS = 0x01;

        public const uint RTL_ENCRYPT_OPTION_SAME_LOGON = 0x02;

        public const uint RTL_ENCRYPT_OPTION_FOR_SYSTEM = 0x04;

        public const uint KERBEROS_VERSION = 5;

        public const uint KERBEROS_REVISION = 6;

        public const uint KERB_ETYPE_AES128_CTS_HMAC_SHA1_96 = 17;

        public const uint KERB_ETYPE_AES256_CTS_HMAC_SHA1_96 = 18;

        public const int KERB_ETYPE_RC4_PLAIN2 = -129;

        public const int KERB_ETYPE_RC4_LM = -130;

        public const int KERB_ETYPE_RC4_SHA = -131;

        public const int KERB_ETYPE_DES_PLAIN = -132;

        public const int KERB_ETYPE_RC4_HMAC_OLD = -133;

        public const int KERB_ETYPE_RC4_PLAIN_OLD = -134;

        public const int KERB_ETYPE_RC4_HMAC_OLD_EXP = -135;

        public const int KERB_ETYPE_RC4_PLAIN_OLD_EXP = -136;

        public const int KERB_ETYPE_RC4_PLAIN = -140;

        public const int KERB_ETYPE_RC4_PLAIN_EXP = -141;

        public const int KERB_ETYPE_AES128_CTS_HMAC_SHA1_96_PLAIN = -148;

        public const int KERB_ETYPE_AES256_CTS_HMAC_SHA1_96_PLAIN = -149;

        public const uint KERB_ETYPE_DSA_SHA1_CMS = 9;

        public const uint KERB_ETYPE_RSA_MD5_CMS = 10;

        public const uint KERB_ETYPE_RSA_SHA1_CMS = 11;

        public const uint KERB_ETYPE_RC2_CBC_ENV = 12;

        public const uint KERB_ETYPE_RSA_ENV = 13;

        public const uint KERB_ETYPE_RSA_ES_OEAP_ENV = 14;

        public const uint KERB_ETYPE_DES_EDE3_CBC_ENV = 15;

        public const uint KERB_ETYPE_DSA_SIGN = 8;

        public const uint KERB_ETYPE_RSA_PRIV = 9;

        public const uint KERB_ETYPE_RSA_PUB = 10;

        public const uint KERB_ETYPE_RSA_PUB_MD5 = 11;

        public const uint KERB_ETYPE_RSA_PUB_SHA1 = 12;

        public const uint KERB_ETYPE_PKCS7_PUB = 13;

        public const uint KERB_ETYPE_DES3_CBC_MD5 = 5;

        public const uint KERB_ETYPE_DES3_CBC_SHA1 = 7;

        public const uint KERB_ETYPE_DES3_CBC_SHA1_KD = 16;

        public const uint KERB_ETYPE_DES_CBC_MD5_NT = 20;

        public const uint KERB_ETYPE_RC4_HMAC_NT_EXP = 24;

        public const uint KERB_CHECKSUM_NONE = 0;

        public const uint KERB_CHECKSUM_CRC32 = 1;

        public const uint KERB_CHECKSUM_MD4 = 2;

        public const uint KERB_CHECKSUM_KRB_DES_MAC = 4;

        public const uint KERB_CHECKSUM_KRB_DES_MAC_K = 5;

        public const uint KERB_CHECKSUM_MD5 = 7;

        public const uint KERB_CHECKSUM_MD5_DES = 8;

        public const uint KERB_CHECKSUM_SHA1_NEW = 14;

        public const uint KERB_CHECKSUM_HMAC_SHA1_96_AES128 = 15;

        public const uint KERB_CHECKSUM_HMAC_SHA1_96_AES256 = 16;

        public const int KERB_CHECKSUM_LM = -130;

        public const int KERB_CHECKSUM_SHA1 = -131;

        public const int KERB_CHECKSUM_REAL_CRC32 = -132;

        public const int KERB_CHECKSUM_DES_MAC = -133;

        public const int KERB_CHECKSUM_DES_MAC_MD5 = -134;

        public const int KERB_CHECKSUM_MD25 = -135;

        public const int KERB_CHECKSUM_RC4_MD5 = -136;

        public const int KERB_CHECKSUM_MD5_HMAC = -137;

        public const int KERB_CHECKSUM_HMAC_MD5 = -138;

        public const int KERB_CHECKSUM_HMAC_SHA1_96_AES128_Ki = -150;

        public const int KERB_CHECKSUM_HMAC_SHA1_96_AES256_Ki = -151;

        public const uint AUTH_REQ_ALLOW_FORWARDABLE = 0x00000001;

        public const uint AUTH_REQ_ALLOW_PROXIABLE = 0x00000002;

        public const uint AUTH_REQ_ALLOW_POSTDATE = 0x00000004;

        public const uint AUTH_REQ_ALLOW_RENEWABLE = 0x00000008;

        public const uint AUTH_REQ_ALLOW_NOADDRESS = 0x00000010;

        public const uint AUTH_REQ_ALLOW_ENC_TKT_IN_SKEY = 0x00000020;

        public const uint AUTH_REQ_ALLOW_VALIDATE = 0x00000040;

        public const uint AUTH_REQ_VALIDATE_CLIENT = 0x00000080;

        public const uint AUTH_REQ_OK_AS_DELEGATE = 0x00000100;

        public const uint AUTH_REQ_PREAUTH_REQUIRED = 0x00000200;

        public const uint AUTH_REQ_TRANSITIVE_TRUST = 0x00000400;

        public const uint AUTH_REQ_ALLOW_S4U_DELEGATE = 0x00000800;

        public const uint KERB_TICKET_FLAGS_name_canonicalize = 0x00010000;

        public const uint KERB_TICKET_FLAGS_cname_in_pa_data = 0x00040000;

        public const uint KERB_TICKET_FLAGS_enc_pa_rep = 0x00010000;

        public const uint KRB_NT_UNKNOWN = 0;

        public const uint KRB_NT_PRINCIPAL = 1;

        public const int KRB_NT_PRINCIPAL_AND_ID = -131;

        public const uint KRB_NT_SRV_INST = 2;

        public const int KRB_NT_SRV_INST_AND_ID = -132;

        public const uint KRB_NT_SRV_HST = 3;

        public const uint KRB_NT_SRV_XHST = 4;

        public const uint KRB_NT_UID = 5;

        public const uint KRB_NT_ENTERPRISE_PRINCIPAL = 10;

        public const uint KRB_NT_WELLKNOWN = 11;

        public const int KRB_NT_ENT_PRINCIPAL_AND_ID = -130;

        public const int KRB_NT_MS_PRINCIPAL = -128;

        public const int KRB_NT_MS_PRINCIPAL_AND_ID = -129;

        public const int KRB_NT_MS_BRANCH_ID = -133;

        public const uint KRB_NT_X500_PRINCIPAL = 6;

        public const uint KERB_WRAP_NO_ENCRYPT = 0x80000001;

        public const uint KERB_CERTIFICATE_LOGON_FLAG_CHECK_DUPLICATES = 0x1;

        public const uint KERB_CERTIFICATE_LOGON_FLAG_USE_CERTIFICATE_INFO = 0x2;

        public const uint KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_DUPLICATES = 0x1;

        public const uint KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_LOGONHOURS = 0x2;

        public const uint KERB_CERTIFICATE_S4U_LOGON_FLAG_FAIL_IF_NT_AUTH_POLICY_REQUIRED = 0x4;

        public const uint KERB_CERTIFICATE_S4U_LOGON_FLAG_IDENTIFY = 0x8;

        public const uint KERB_LOGON_FLAG_ALLOW_EXPIRED_TICKET = 0x1;

        public const uint KERB_LOGON_FLAG_REDIRECTED = 0x2;

        public const uint KERB_S4U_LOGON_FLAG_CHECK_LOGONHOURS = 0x2;

        public const uint KERB_S4U_LOGON_FLAG_IDENTIFY = 0x8;

        public const uint KERB_USE_DEFAULT_TICKET_FLAGS = 0x0;

        public const uint KERB_RETRIEVE_TICKET_DEFAULT = 0x0;

        public const uint KERB_RETRIEVE_TICKET_DONT_USE_CACHE = 0x1;

        public const uint KERB_RETRIEVE_TICKET_USE_CACHE_ONLY = 0x2;

        public const uint KERB_RETRIEVE_TICKET_USE_CREDHANDLE = 0x4;

        public const uint KERB_RETRIEVE_TICKET_AS_KERB_CRED = 0x8;

        public const uint KERB_RETRIEVE_TICKET_WITH_SEC_CRED = 0x10;

        public const uint KERB_RETRIEVE_TICKET_CACHE_TICKET = 0x20;

        public const uint KERB_RETRIEVE_TICKET_MAX_LIFETIME = 0x40;

        public const uint KERB_ETYPE_DEFAULT = 0x0;

        public const uint KERB_PURGE_ALL_TICKETS = 1;

        public const uint KERB_S4U2PROXY_CACHE_ENTRY_INFO_FLAG_NEGATIVE = 0x1;

        public const uint KERB_S4U2PROXY_CRED_FLAG_NEGATIVE = 0x1;

        public const uint DS_UNKNOWN_ADDRESS_TYPE = 0;

        public const uint KERB_SETPASS_USE_LOGONID = 1;

        public const uint KERB_SETPASS_USE_CREDHANDLE = 2;

        public const uint KERB_DECRYPT_FLAG_DEFAULT_KEY = 0x00000001;

        public const uint KERB_REFRESH_SCCRED_RELEASE = 0x0;

        public const uint KERB_REFRESH_SCCRED_GETTGT = 0x1;

        public const uint KERB_TRANSFER_CRED_WITH_TICKETS = 0x1;

        public const uint KERB_TRANSFER_CRED_CLEANUP_CREDENTIALS = 0x2;

        public const uint KERB_QUERY_DOMAIN_EXTENDED_POLICIES_RESPONSE_FLAG_DAC_DISABLED = 0x1;

        public const uint AUDIT_SET_SYSTEM_POLICY = 0x0001;

        public const uint AUDIT_QUERY_SYSTEM_POLICY = 0x0002;

        public const uint AUDIT_SET_USER_POLICY = 0x0004;

        public const uint AUDIT_QUERY_USER_POLICY = 0x0008;

        public const uint AUDIT_ENUMERATE_USERS = 0x0010;

        public const uint AUDIT_SET_MISC_POLICY = 0x0020;

        public const uint AUDIT_QUERY_MISC_POLICY = 0x0040;

        public const uint SECPKG_CLIENT_PROCESS_TERMINATED = 0x01;

        public const uint SECPKG_CLIENT_THREAD_TERMINATED = 0x02;

        public const uint SECPKG_CALL_KERNEL_MODE = 0x00000001;

        public const uint SECPKG_CALL_ANSI = 0x00000002;

        public const uint SECPKG_CALL_URGENT = 0x00000004;

        public const uint SECPKG_CALL_RECURSIVE = 0x00000008;

        public const uint SECPKG_CALL_IN_PROC = 0x00000010;

        public const uint SECPKG_CALL_CLEANUP = 0x00000020;

        public const uint SECPKG_CALL_WOWCLIENT = 0x00000040;

        public const uint SECPKG_CALL_THREAD_TERM = 0x00000080;

        public const uint SECPKG_CALL_PROCESS_TERM = 0x00000100;

        public const uint SECPKG_CALL_IS_TCB = 0x00000200;

        public const uint SECPKG_CALL_NETWORK_ONLY = 0x00000400;

        public const uint SECPKG_CALL_WINLOGON = 0x00000800;

        public const uint SECPKG_CALL_ASYNC_UPDATE = 0x00001000;

        public const uint SECPKG_CALL_SYSTEM_PROC = 0x00002000;

        public const uint SECPKG_CALL_NEGO = 0x00004000;

        public const uint SECPKG_CALL_NEGO_EXTENDER = 0x00008000;

        public const uint SECPKG_CALL_BUFFER_MARSHAL = 0x00010000;

        public const uint SECPKG_CALL_UNLOCK = 0x00020000;

        public const uint SECPKG_CALL_CLOUDAP_CONNECT = 0x00040000;

        public const uint SECPKG_CALL_WOWX86 = 0x00000040;

        public const uint SECPKG_CALL_WOWA32 = 0x00040000;

        public const uint SECPKG_CREDENTIAL_VERSION = 201;

        public const uint SECPKG_CREDENTIAL_FLAGS_CALLER_HAS_TCB = 0x1;

        public const uint SECPKG_CREDENTIAL_FLAGS_CREDMAN_CRED = 0x2;

        public const uint SECPKG_SURROGATE_LOGON_VERSION_1 = 1;

        public const uint SECBUFFER_UNMAPPED = 0x40000000;

        public const uint SECBUFFER_KERNEL_MAP = 0x20000000;

        public const uint PRIMARY_CRED_CLEAR_PASSWORD = 0x1;

        public const uint PRIMARY_CRED_OWF_PASSWORD = 0x2;

        public const uint PRIMARY_CRED_UPDATE = 0x4;

        public const uint PRIMARY_CRED_CACHED_LOGON = 0x8;

        public const uint PRIMARY_CRED_LOGON_NO_TCB = 0x10;

        public const uint PRIMARY_CRED_LOGON_LUA = 0x20;

        public const uint PRIMARY_CRED_INTERACTIVE_SMARTCARD_LOGON = 0x40;

        public const uint PRIMARY_CRED_REFRESH_NEEDED = 0x80;

        public const uint PRIMARY_CRED_INTERNET_USER = 0x100;

        public const uint PRIMARY_CRED_AUTH_ID = 0x200;

        public const uint PRIMARY_CRED_DO_NOT_SPLIT = 0x400;

        public const uint PRIMARY_CRED_PROTECTED_USER = 0x800;

        public const uint PRIMARY_CRED_EX = 0x1000;

        public const uint PRIMARY_CRED_TRANSFER = 0x2000;

        public const uint PRIMARY_CRED_RESTRICTED_TS = 0x4000;

        public const uint PRIMARY_CRED_PACKED_CREDS = 0x8000;

        public const uint PRIMARY_CRED_ENTERPRISE_INTERNET_USER = 0x00010000;

        public const uint PRIMARY_CRED_ENCRYPTED_CREDGUARD_PASSWORD = 0x00020000;

        public const uint PRIMARY_CRED_CACHED_INTERACTIVE_LOGON = 0x00040000;

        public const uint PRIMARY_CRED_INTERACTIVE_NGC_LOGON = 0x00080000;

        public const uint PRIMARY_CRED_INTERACTIVE_FIDO_LOGON = 0x00100000;

        public const uint PRIMARY_CRED_ARSO_LOGON = 0x00200000;

        public const uint PRIMARY_CRED_LOGON_PACKAGE_SHIFT = 24;

        public const uint PRIMARY_CRED_PACKAGE_MASK = 0xff000000;

        public const uint MAX_CRED_SIZE = 1024;

        public const uint SECPKG_STATE_ENCRYPTION_PERMITTED = 0x01;

        public const uint SECPKG_STATE_STRONG_ENCRYPTION_PERMITTED = 0x02;

        public const uint SECPKG_STATE_DOMAIN_CONTROLLER = 0x04;

        public const uint SECPKG_STATE_WORKSTATION = 0x08;

        public const uint SECPKG_STATE_STANDALONE = 0x10;

        public const uint SECPKG_STATE_CRED_ISOLATION_ENABLED = 0x20;

        public const uint SECPKG_STATE_RESERVED_1 = 0x80000000;

        public const uint SECPKG_MAX_OID_LENGTH = 32;

        public const uint SECPKG_ATTR_SASL_CONTEXT = 0x00010000;

        public const uint SECPKG_ATTR_THUNK_ALL = 0x00010000;

        public const uint UNDERSTANDS_LONG_NAMES = 1;

        public const uint NO_LONG_NAMES = 2;

        public const uint SECPKG_CALL_PACKAGE_TRANSFER_CRED_REQUEST_FLAG_OPTIMISTIC_LOGON = 0x1;

        public const uint SECPKG_CALL_PACKAGE_TRANSFER_CRED_REQUEST_FLAG_CLEANUP_CREDENTIALS = 0x2;

        public const uint SECPKG_CALL_PACKAGE_TRANSFER_CRED_REQUEST_FLAG_TO_SSO_SESSION = 0x4;

        public const uint NOTIFIER_FLAG_NEW_THREAD = 0x00000001;

        public const uint NOTIFIER_FLAG_ONE_SHOT = 0x00000002;

        public const uint NOTIFIER_FLAG_SECONDS = 0x80000000;

        public const uint NOTIFIER_TYPE_INTERVAL = 1;

        public const uint NOTIFIER_TYPE_HANDLE_WAIT = 2;

        public const uint NOTIFIER_TYPE_STATE_CHANGE = 3;

        public const uint NOTIFIER_TYPE_NOTIFY_EVENT = 4;

        public const uint NOTIFIER_TYPE_IMMEDIATE = 16;

        public const uint NOTIFY_CLASS_PACKAGE_CHANGE = 1;

        public const uint NOTIFY_CLASS_ROLE_CHANGE = 2;

        public const uint NOTIFY_CLASS_DOMAIN_CHANGE = 3;

        public const uint NOTIFY_CLASS_REGISTRY_CHANGE = 4;

        public const uint LSA_QUERY_CLIENT_PRELOGON_SESSION_ID = 1;

        public const uint CREDP_FLAGS_IN_PROCESS = 0x01;

        public const uint CREDP_FLAGS_USE_MIDL_HEAP = 0x02;

        public const uint CREDP_FLAGS_DONT_CACHE_TI = 0x04;

        public const uint CREDP_FLAGS_CLEAR_PASSWORD = 0x08;

        public const uint CREDP_FLAGS_USER_ENCRYPTED_PASSWORD = 0x10;

        public const uint CREDP_FLAGS_TRUSTED_CALLER = 0x20;

        public const uint CREDP_FLAGS_VALIDATE_PROXY_TARGET = 0x40;

        public const uint CRED_MARSHALED_TI_SIZE_SIZE = 12;

        public const uint SECPKG_INTERFACE_VERSION = 0x00010000;

        public const uint SECPKG_INTERFACE_VERSION_2 = 0x00020000;

        public const uint SECPKG_INTERFACE_VERSION_3 = 0x00040000;

        public const uint SECPKG_INTERFACE_VERSION_4 = 0x00080000;

        public const uint SECPKG_INTERFACE_VERSION_5 = 0x00100000;

        public const uint SECPKG_INTERFACE_VERSION_6 = 0x00200000;

        public const uint SECPKG_INTERFACE_VERSION_7 = 0x00400000;

        public const uint SECPKG_INTERFACE_VERSION_8 = 0x00800000;

        public const uint SECPKG_INTERFACE_VERSION_9 = 0x01000000;

        public const uint SECPKG_INTERFACE_VERSION_10 = 0x02000000;

        public const uint UNISP_RPC_ID = 14;

        public const uint RCRED_STATUS_NOCRED = 0x00000000;

        public const uint RCRED_CRED_EXISTS = 0x00000001;

        public const uint RCRED_STATUS_UNKNOWN_ISSUER = 0x00000002;

        public const uint LCRED_STATUS_NOCRED = 0x00000000;

        public const uint LCRED_CRED_EXISTS = 0x00000001;

        public const uint LCRED_STATUS_UNKNOWN_ISSUER = 0x00000002;

        public const uint SECPKGCONTEXT_CONNECTION_INFO_EX_V1 = 1;

        public const uint SECPKGCONTEXT_CIPHERINFO_V1 = 1;

        public const uint SSL_SESSION_RECONNECT = 1;

        public const uint KERN_CONTEXT_CERT_INFO_V1 = 0x00000000;

        public const uint ENABLE_TLS_CLIENT_EARLY_START = 0x00000001;

        public const uint SCH_CRED_V1 = 0x00000001;

        public const uint SCH_CRED_V2 = 0x00000002;

        public const uint SCH_CRED_VERSION = 0x00000002;

        public const uint SCH_CRED_V3 = 0x00000003;

        public const uint SCHANNEL_CRED_VERSION = 0x00000004;

        public const uint SCH_CREDENTIALS_VERSION = 0x00000005;

        public const uint TLS_PARAMS_OPTIONAL = 0x00000001;

        public const uint SCH_CRED_MAX_SUPPORTED_PARAMETERS = 16;

        public const uint SCH_CRED_MAX_SUPPORTED_ALPN_IDS = 16;

        public const uint SCH_CRED_MAX_SUPPORTED_CRYPTO_SETTINGS = 16;

        public const uint SCH_CRED_MAX_SUPPORTED_CHAINING_MODES = 16;

        public const uint SCH_MAX_EXT_SUBSCRIPTIONS = 2;

        public const uint SCH_CRED_FORMAT_CERT_CONTEXT = 0x00000000;

        public const uint SCH_CRED_FORMAT_CERT_HASH = 0x00000001;

        public const uint SCH_CRED_FORMAT_CERT_HASH_STORE = 0x00000002;

        public const uint SCH_CRED_MAX_STORE_NAME_SIZE = 128;

        public const uint SCH_CRED_MAX_SUPPORTED_ALGS = 256;

        public const uint SCH_CRED_MAX_SUPPORTED_CERTS = 100;

        public const uint SCH_MACHINE_CERT_HASH = 0x00000001;

        public const uint SCH_CRED_DISABLE_RECONNECTS = 0x00000080;

        public const uint SCH_CRED_RESTRICTED_ROOTS = 0x00002000;

        public const uint SCH_CRED_REVOCATION_CHECK_CACHE_ONLY = 0x00004000;

        public const uint SCH_CRED_CACHE_ONLY_URL_RETRIEVAL = 0x00008000;

        public const uint SCH_CRED_MEMORY_STORE_CERT = 0x00010000;

        public const uint SCH_CRED_SNI_CREDENTIAL = 0x00080000;

        public const uint SCH_CRED_SNI_ENABLE_OCSP = 0x00100000;

        public const uint SCH_USE_DTLS_ONLY = 0x01000000;

        public const uint SCH_ALLOW_NULL_ENCRYPTION = 0x02000000;

        public const uint SCHANNEL_RENEGOTIATE = 0;

        public const uint SCHANNEL_SHUTDOWN = 1;

        public const uint SCHANNEL_ALERT = 2;

        public const uint SCHANNEL_SESSION = 3;

        public const uint TLS1_ALERT_CLOSE_NOTIFY = 0;

        public const uint TLS1_ALERT_UNEXPECTED_MESSAGE = 10;

        public const uint TLS1_ALERT_BAD_RECORD_MAC = 20;

        public const uint TLS1_ALERT_DECRYPTION_FAILED = 21;

        public const uint TLS1_ALERT_RECORD_OVERFLOW = 22;

        public const uint TLS1_ALERT_DECOMPRESSION_FAIL = 30;

        public const uint TLS1_ALERT_HANDSHAKE_FAILURE = 40;

        public const uint TLS1_ALERT_BAD_CERTIFICATE = 42;

        public const uint TLS1_ALERT_UNSUPPORTED_CERT = 43;

        public const uint TLS1_ALERT_CERTIFICATE_REVOKED = 44;

        public const uint TLS1_ALERT_CERTIFICATE_EXPIRED = 45;

        public const uint TLS1_ALERT_CERTIFICATE_UNKNOWN = 46;

        public const uint TLS1_ALERT_ILLEGAL_PARAMETER = 47;

        public const uint TLS1_ALERT_UNKNOWN_CA = 48;

        public const uint TLS1_ALERT_ACCESS_DENIED = 49;

        public const uint TLS1_ALERT_DECODE_ERROR = 50;

        public const uint TLS1_ALERT_DECRYPT_ERROR = 51;

        public const uint TLS1_ALERT_EXPORT_RESTRICTION = 60;

        public const uint TLS1_ALERT_PROTOCOL_VERSION = 70;

        public const uint TLS1_ALERT_INSUFFIENT_SECURITY = 71;

        public const uint TLS1_ALERT_INTERNAL_ERROR = 80;

        public const uint TLS1_ALERT_USER_CANCELED = 90;

        public const uint TLS1_ALERT_NO_RENEGOTIATION = 100;

        public const uint TLS1_ALERT_UNSUPPORTED_EXT = 110;

        public const uint TLS1_ALERT_UNKNOWN_PSK_IDENTITY = 115;

        public const uint TLS1_ALERT_NO_APP_PROTOCOL = 120;

        public const uint SP_PROT_PCT1_SERVER = 0x00000001;

        public const uint SP_PROT_PCT1_CLIENT = 0x00000002;

        public const uint SP_PROT_SSL2_SERVER = 0x00000004;

        public const uint SP_PROT_SSL2_CLIENT = 0x00000008;

        public const uint SP_PROT_SSL3_SERVER = 0x00000010;

        public const uint SP_PROT_SSL3_CLIENT = 0x00000020;

        public const uint SP_PROT_TLS1_SERVER = 0x00000040;

        public const uint SP_PROT_TLS1_CLIENT = 0x00000080;

        public const uint SP_PROT_UNI_SERVER = 0x40000000;

        public const uint SP_PROT_UNI_CLIENT = 0x80000000;

        public const uint SP_PROT_ALL = 0xffffffff;

        public const uint SP_PROT_NONE = 0;

        public const uint SP_PROT_TLS1_1_SERVER = 0x00000100;

        public const uint SP_PROT_TLS1_1_CLIENT = 0x00000200;

        public const uint SP_PROT_TLS1_2_SERVER = 0x00000400;

        public const uint SP_PROT_TLS1_2_CLIENT = 0x00000800;

        public const uint SP_PROT_TLS1_3_SERVER = 0x00001000;

        public const uint SP_PROT_TLS1_3_CLIENT = 0x00002000;

        public const uint SP_PROT_DTLS_SERVER = 0x00010000;

        public const uint SP_PROT_DTLS_CLIENT = 0x00020000;

        public const uint SP_PROT_DTLS1_2_SERVER = 0x00040000;

        public const uint SP_PROT_DTLS1_2_CLIENT = 0x00080000;

        public const uint SCHANNEL_SECRET_TYPE_CAPI = 0x00000001;

        public const uint SCHANNEL_SECRET_PRIVKEY = 0x00000002;

        public const uint SCH_CRED_X509_CERTCHAIN = 0x00000001;

        public const uint SCH_CRED_X509_CAPI = 0x00000002;

        public const uint SCH_CRED_CERT_CONTEXT = 0x00000003;

        public const uint SL_SYSTEM_STATE_REBOOT_POLICY_FOUND = 0x00000001;

        public const uint SL_SYSTEM_STATE_TAMPERED = 0x00000002;

        public const uint SL_REARM_REBOOT_REQUIRED = 0x00000001;

        public const uint SPP_MIGRATION_GATHER_MIGRATABLE_APPS = 0x00000001;

        public const uint SPP_MIGRATION_GATHER_ACTIVATED_WINDOWS_STATE = 0x00000002;

        public const uint SPP_MIGRATION_GATHER_ALL = 0xFFFFFFFF;

        public const uint USER_ACCOUNT_DISABLED = 0x00000001;

        public const uint USER_HOME_DIRECTORY_REQUIRED = 0x00000002;

        public const uint USER_PASSWORD_NOT_REQUIRED = 0x00000004;

        public const uint USER_TEMP_DUPLICATE_ACCOUNT = 0x00000008;

        public const uint USER_NORMAL_ACCOUNT = 0x00000010;

        public const uint USER_MNS_LOGON_ACCOUNT = 0x00000020;

        public const uint USER_INTERDOMAIN_TRUST_ACCOUNT = 0x00000040;

        public const uint USER_WORKSTATION_TRUST_ACCOUNT = 0x00000080;

        public const uint USER_SERVER_TRUST_ACCOUNT = 0x00000100;

        public const uint USER_DONT_EXPIRE_PASSWORD = 0x00000200;

        public const uint USER_ACCOUNT_AUTO_LOCKED = 0x00000400;

        public const uint USER_ENCRYPTED_TEXT_PASSWORD_ALLOWED = 0x00000800;

        public const uint USER_SMARTCARD_REQUIRED = 0x00001000;

        public const uint USER_TRUSTED_FOR_DELEGATION = 0x00002000;

        public const uint USER_NOT_DELEGATED = 0x00004000;

        public const uint USER_USE_DES_KEY_ONLY = 0x00008000;

        public const uint USER_DONT_REQUIRE_PREAUTH = 0x00010000;

        public const uint USER_PASSWORD_EXPIRED = 0x00020000;

        public const uint USER_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = 0x00040000;

        public const uint USER_NO_AUTH_DATA_REQUIRED = 0x00080000;

        public const uint USER_PARTIAL_SECRETS_ACCOUNT = 0x00100000;

        public const uint USER_USE_AES_KEYS = 0x00200000;

        public const uint SAM_DAYS_PER_WEEK = 7;

        public const uint USER_ALL_PARAMETERS = 0x00200000;

        public const uint CLEAR_BLOCK_LENGTH = 8;

        public const uint CYPHER_BLOCK_LENGTH = 8;

        public const uint MSV1_0_VALIDATION_LOGOFF_TIME = 0x00000001;

        public const uint MSV1_0_VALIDATION_KICKOFF_TIME = 0x00000002;

        public const uint MSV1_0_VALIDATION_LOGON_SERVER = 0x00000004;

        public const uint MSV1_0_VALIDATION_LOGON_DOMAIN = 0x00000008;

        public const uint MSV1_0_VALIDATION_SESSION_KEY = 0x00000010;

        public const uint MSV1_0_VALIDATION_USER_FLAGS = 0x00000020;

        public const uint MSV1_0_VALIDATION_USER_ID = 0x00000040;

        public const uint MSV1_0_SUBAUTH_ACCOUNT_DISABLED = 0x00000001;

        public const uint MSV1_0_SUBAUTH_PASSWORD = 0x00000002;

        public const uint MSV1_0_SUBAUTH_WORKSTATIONS = 0x00000004;

        public const uint MSV1_0_SUBAUTH_LOGON_HOURS = 0x00000008;

        public const uint MSV1_0_SUBAUTH_ACCOUNT_EXPIRY = 0x00000010;

        public const uint MSV1_0_SUBAUTH_PASSWORD_EXPIRY = 0x00000020;

        public const uint MSV1_0_SUBAUTH_ACCOUNT_TYPE = 0x00000040;

        public const uint MSV1_0_SUBAUTH_LOCKOUT = 0x00000080;

    }
}
