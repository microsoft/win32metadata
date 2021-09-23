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


namespace Windows.Win32.System.Rpc
{
    public static partial class Apis
    {
        public const uint RPC_C_BINDING_INFINITE_TIMEOUT = 10;

        public const uint RPC_C_BINDING_MIN_TIMEOUT = 0;

        public const uint RPC_C_BINDING_DEFAULT_TIMEOUT = 5;

        public const uint RPC_C_BINDING_MAX_TIMEOUT = 9;

        public const int RPC_C_CANCEL_INFINITE_TIMEOUT = -1;

        public const uint RPC_C_LISTEN_MAX_CALLS_DEFAULT = 1234;

        public const uint RPC_C_PROTSEQ_MAX_REQS_DEFAULT = 10;

        public const uint RPC_C_BIND_TO_ALL_NICS = 1;

        public const uint RPC_C_USE_INTERNET_PORT = 0x1;

        public const uint RPC_C_USE_INTRANET_PORT = 0x2;

        public const uint RPC_C_DONT_FAIL = 0x4;

        public const uint RPC_C_RPCHTTP_USE_LOAD_BALANCE = 0x8;

        public const uint RPC_C_MQ_TEMPORARY = 0x0000;

        public const uint RPC_C_MQ_PERMANENT = 0x0001;

        public const uint RPC_C_MQ_CLEAR_ON_OPEN = 0x0002;

        public const uint RPC_C_MQ_USE_EXISTING_SECURITY = 0x0004;

        public const uint RPC_C_MQ_AUTHN_LEVEL_NONE = 0x0000;

        public const uint RPC_C_MQ_AUTHN_LEVEL_PKT_INTEGRITY = 0x0008;

        public const uint RPC_C_MQ_AUTHN_LEVEL_PKT_PRIVACY = 0x0010;

        public const uint RPC_C_MQ_EXPRESS = 0;

        public const uint RPC_C_MQ_RECOVERABLE = 1;

        public const uint RPC_C_MQ_JOURNAL_NONE = 0;

        public const uint RPC_C_MQ_JOURNAL_DEADLETTER = 1;

        public const uint RPC_C_MQ_JOURNAL_ALWAYS = 2;

        public const uint RPC_C_OPT_MQ_DELIVERY = 1;

        public const uint RPC_C_OPT_MQ_PRIORITY = 2;

        public const uint RPC_C_OPT_MQ_JOURNAL = 3;

        public const uint RPC_C_OPT_MQ_ACKNOWLEDGE = 4;

        public const uint RPC_C_OPT_MQ_AUTHN_SERVICE = 5;

        public const uint RPC_C_OPT_MQ_AUTHN_LEVEL = 6;

        public const uint RPC_C_OPT_MQ_TIME_TO_REACH_QUEUE = 7;

        public const uint RPC_C_OPT_MQ_TIME_TO_BE_RECEIVED = 8;

        public const uint RPC_C_OPT_BINDING_NONCAUSAL = 9;

        public const uint RPC_C_OPT_SECURITY_CALLBACK = 10;

        public const uint RPC_C_OPT_UNIQUE_BINDING = 11;

        public const uint RPC_C_OPT_MAX_OPTIONS = 12;

        public const uint RPC_C_OPT_CALL_TIMEOUT = 12;

        public const uint RPC_C_OPT_DONT_LINGER = 13;

        public const uint RPC_C_OPT_TRANS_SEND_BUFFER_SIZE = 5;

        public const uint RPC_C_OPT_TRUST_PEER = 14;

        public const uint RPC_C_OPT_ASYNC_BLOCK = 15;

        public const uint RPC_C_OPT_OPTIMIZE_TIME = 16;

        public const uint RPC_C_FULL_CERT_CHAIN = 0x0001;

        public const uint RPC_C_STATS_CALLS_IN = 0;

        public const uint RPC_C_STATS_CALLS_OUT = 1;

        public const uint RPC_C_STATS_PKTS_IN = 2;

        public const uint RPC_C_STATS_PKTS_OUT = 3;

        public const uint RPC_C_AUTHN_NONE = 0;

        public const uint RPC_C_AUTHN_DCE_PRIVATE = 1;

        public const uint RPC_C_AUTHN_DCE_PUBLIC = 2;

        public const uint RPC_C_AUTHN_DEC_PUBLIC = 4;

        public const uint RPC_C_AUTHN_GSS_NEGOTIATE = 9;

        public const uint RPC_C_AUTHN_WINNT = 10;

        public const uint RPC_C_AUTHN_GSS_SCHANNEL = 14;

        public const uint RPC_C_AUTHN_GSS_KERBEROS = 16;

        public const uint RPC_C_AUTHN_DPA = 17;

        public const uint RPC_C_AUTHN_MSN = 18;

        public const uint RPC_C_AUTHN_DIGEST = 21;

        public const uint RPC_C_AUTHN_KERNEL = 20;

        public const uint RPC_C_AUTHN_NEGO_EXTENDER = 30;

        public const uint RPC_C_AUTHN_PKU2U = 31;

        public const uint RPC_C_AUTHN_LIVE_SSP = 32;

        public const uint RPC_C_AUTHN_LIVEXP_SSP = 35;

        public const uint RPC_C_AUTHN_CLOUD_AP = 36;

        public const uint RPC_C_AUTHN_MSONLINE = 82;

        public const uint RPC_C_AUTHN_MQ = 100;

        public const int RPC_C_AUTHN_DEFAULT = unchecked((int)0xFFFFFFFF);

        public const int RPC_C_SECURITY_QOS_VERSION = 1;

        public const int RPC_C_SECURITY_QOS_VERSION_1 = 1;

        public const int RPC_C_SECURITY_QOS_VERSION_2 = 2;

        public const uint RPC_C_HTTP_AUTHN_SCHEME_BASIC = 0x00000001;

        public const uint RPC_C_HTTP_AUTHN_SCHEME_NTLM = 0x00000002;

        public const uint RPC_C_HTTP_AUTHN_SCHEME_PASSPORT = 0x00000004;

        public const uint RPC_C_HTTP_AUTHN_SCHEME_DIGEST = 0x00000008;

        public const uint RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE = 0x00000010;

        public const uint RPC_C_HTTP_AUTHN_SCHEME_CERT = 0x00010000;

        public const int RPC_C_SECURITY_QOS_VERSION_3 = 3;

        public const int RPC_C_SECURITY_QOS_VERSION_4 = 4;

        public const int RPC_C_SECURITY_QOS_VERSION_5 = 5;

        public const uint RPC_PROTSEQ_TCP = 0x1;

        public const uint RPC_PROTSEQ_NMP = 0x2;

        public const uint RPC_PROTSEQ_LRPC = 0x3;

        public const uint RPC_PROTSEQ_HTTP = 0x4;

        public const uint RPC_BHT_OBJECT_UUID_VALID = 0x1;

        public const uint RPC_BHO_EXCLUSIVE_AND_GUARANTEED = 0x4;

        public const uint RPC_C_AUTHZ_NONE = 0;

        public const uint RPC_C_AUTHZ_NAME = 1;

        public const uint RPC_C_AUTHZ_DCE = 2;

        public const uint RPC_C_AUTHZ_DEFAULT = 0xffffffff;

        public const uint DCE_C_ERROR_STRING_LEN = 256;

        public const uint RPC_C_EP_ALL_ELTS = 0;

        public const uint RPC_C_EP_MATCH_BY_IF = 1;

        public const uint RPC_C_EP_MATCH_BY_OBJ = 2;

        public const uint RPC_C_EP_MATCH_BY_BOTH = 3;

        public const uint RPC_C_VERS_ALL = 1;

        public const uint RPC_C_VERS_COMPATIBLE = 2;

        public const uint RPC_C_VERS_EXACT = 3;

        public const uint RPC_C_VERS_MAJOR_ONLY = 4;

        public const uint RPC_C_VERS_UPTO = 5;

        public const uint RPC_C_MGMT_INQ_IF_IDS = 0;

        public const uint RPC_C_MGMT_INQ_PRINC_NAME = 1;

        public const uint RPC_C_MGMT_INQ_STATS = 2;

        public const uint RPC_C_MGMT_IS_SERVER_LISTEN = 3;

        public const uint RPC_C_MGMT_STOP_SERVER_LISTEN = 4;

        public const uint RPC_C_PARM_MAX_PACKET_LENGTH = 1;

        public const uint RPC_C_PARM_BUFFER_LENGTH = 2;

        public const uint RPC_IF_AUTOLISTEN = 0x0001;

        public const uint RPC_IF_OLE = 0x0002;

        public const uint RPC_IF_ALLOW_UNKNOWN_AUTHORITY = 0x0004;

        public const uint RPC_IF_ALLOW_SECURE_ONLY = 0x0008;

        public const uint RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH = 0x0010;

        public const uint RPC_IF_ALLOW_LOCAL_ONLY = 0x0020;

        public const uint RPC_IF_SEC_NO_CACHE = 0x0040;

        public const uint RPC_IF_SEC_CACHE_PER_PROC = 0x0080;

        public const uint RPC_IF_ASYNC_CALLBACK = 0x0100;

        public const uint RPC_FW_IF_FLAG_DCOM = 0x0001;

        public const uint RPC_C_NOTIFY_ON_SEND_COMPLETE = 0x1;

        public const uint MaxNumberOfEEInfoParams = 4;

        public const uint RPC_EEINFO_VERSION = 1;

        public const uint EEInfoPreviousRecordsMissing = 1;

        public const uint EEInfoNextRecordsMissing = 2;

        public const uint EEInfoUseFileTime = 4;

        public const uint EEInfoGCCOM = 11;

        public const uint EEInfoGCFRS = 12;

        public const uint RPC_CALL_ATTRIBUTES_VERSION = 2;

        public const uint RPC_QUERY_SERVER_PRINCIPAL_NAME = 0x02;

        public const uint RPC_QUERY_CLIENT_PRINCIPAL_NAME = 0x04;

        public const uint RPC_QUERY_CALL_LOCAL_ADDRESS = 0x08;

        public const uint RPC_QUERY_CLIENT_PID = 0x10;

        public const uint RPC_QUERY_IS_CLIENT_LOCAL = 0x20;

        public const uint RPC_QUERY_NO_AUTH_REQUIRED = 0x40;

        public const uint RPC_QUERY_CLIENT_ID = 0x80;

        public const uint RPC_CALL_STATUS_CANCELLED = 0x01;

        public const uint RPC_CALL_STATUS_DISCONNECTED = 0x02;

        public const uint RPC_CONTEXT_HANDLE_DEFAULT_FLAGS = 0x00000000;

        public const uint RPC_CONTEXT_HANDLE_FLAGS = 0x30000000;

        public const uint RPC_CONTEXT_HANDLE_SERIALIZE = 0x10000000;

        public const uint RPC_CONTEXT_HANDLE_DONT_SERIALIZE = 0x20000000;

        public const uint RPC_TYPE_STRICT_CONTEXT_HANDLE = 0x40000000;

        public const uint RPC_TYPE_DISCONNECT_EVENT_CONTEXT_HANDLE = 0x80000000;

        public const uint RPC_NCA_FLAGS_DEFAULT = 0x00000000;

        public const uint RPC_NCA_FLAGS_IDEMPOTENT = 0x00000001;

        public const uint RPC_NCA_FLAGS_BROADCAST = 0x00000002;

        public const uint RPC_NCA_FLAGS_MAYBE = 0x00000004;

        public const uint RPCFLG_HAS_GUARANTEE = 0x00000010;

        public const uint RPCFLG_WINRT_REMOTE_ASYNC = 0x00000020;

        public const uint RPC_BUFFER_COMPLETE = 0x00001000;

        public const uint RPC_BUFFER_PARTIAL = 0x00002000;

        public const uint RPC_BUFFER_EXTRA = 0x00004000;

        public const uint RPC_BUFFER_ASYNC = 0x00008000;

        public const uint RPC_BUFFER_NONOTIFY = 0x00010000;

        public const uint RPCFLG_MESSAGE = 0x01000000;

        public const uint RPCFLG_AUTO_COMPLETE = 0x08000000;

        public const uint RPCFLG_LOCAL_CALL = 0x10000000;

        public const uint RPCFLG_INPUT_SYNCHRONOUS = 0x20000000;

        public const uint RPCFLG_ASYNCHRONOUS = 0x40000000;

        public const uint RPCFLG_NON_NDR = 0x80000000;

        public const uint RPCFLG_HAS_MULTI_SYNTAXES = 0x02000000;

        public const uint RPCFLG_HAS_CALLBACK = 0x04000000;

        public const uint RPCFLG_ACCESSIBILITY_BIT1 = 0x00100000;

        public const uint RPCFLG_ACCESSIBILITY_BIT2 = 0x00200000;

        public const uint RPCFLG_ACCESS_LOCAL = 0x00400000;

        public const uint NDR_CUSTOM_OR_DEFAULT_ALLOCATOR = 0x10000000;

        public const uint NDR_DEFAULT_ALLOCATOR = 0x20000000;

        public const uint RPCFLG_NDR64_CONTAINS_ARM_LAYOUT = 0x04000000;

        public const uint RPCFLG_SENDER_WAITING_FOR_REPLY = 0x00800000;

        public const uint RPC_FLAGS_VALID_BIT = 0x00008000;

        public const uint NT351_INTERFACE_SIZE = 0x40;

        public const uint RPC_INTERFACE_HAS_PIPES = 0x0001;

        public const uint RPC_SYSTEM_HANDLE_FREE_UNRETRIEVED = 1;

        public const uint RPC_SYSTEM_HANDLE_FREE_RETRIEVED = 2;

        public const uint RPC_SYSTEM_HANDLE_FREE_ALL = 3;

        public const uint RPC_SYSTEM_HANDLE_FREE_ERROR_ON_CLOSE = 4;

        public const uint TRANSPORT_TYPE_CN = 0x01;

        public const uint TRANSPORT_TYPE_DG = 0x02;

        public const uint TRANSPORT_TYPE_LPC = 0x04;

        public const uint TRANSPORT_TYPE_WMSG = 0x08;

        public const uint RPC_P_ADDR_FORMAT_TCP_IPV4 = 1;

        public const uint RPC_P_ADDR_FORMAT_TCP_IPV6 = 2;

        public const uint RPC_C_OPT_SESSION_ID = 6;

        public const uint RPC_C_OPT_COOKIE_AUTH = 7;

        public const uint RPC_C_OPT_RESOURCE_TYPE_UUID = 8;

        public const uint RPC_PROXY_CONNECTION_TYPE_IN_PROXY = 0;

        public const uint RPC_PROXY_CONNECTION_TYPE_OUT_PROXY = 1;

        public const uint RPC_C_OPT_PRIVATE_SUPPRESS_WAKE = 1;

        public const uint RPC_C_OPT_PRIVATE_DO_NOT_DISTURB = 2;

        public const uint RPC_C_OPT_PRIVATE_BREAK_ON_SUSPEND = 3;

        public const uint RPC_C_PROFILE_DEFAULT_ELT = 0;

        public const uint RPC_C_PROFILE_ALL_ELT = 1;

        public const uint RPC_C_PROFILE_MATCH_BY_IF = 2;

        public const uint RPC_C_PROFILE_MATCH_BY_MBR = 3;

        public const uint RPC_C_PROFILE_MATCH_BY_BOTH = 4;

        public const int RPC_C_NS_DEFAULT_EXP_AGE = -1;

        public const uint TARGET_IS_NT100_OR_LATER = 1;

        public const uint TARGET_IS_NT63_OR_LATER = 1;

        public const uint TARGET_IS_NT62_OR_LATER = 1;

        public const uint TARGET_IS_NT61_OR_LATER = 1;

        public const uint TARGET_IS_NT60_OR_LATER = 1;

        public const uint TARGET_IS_NT51_OR_LATER = 1;

        public const uint TARGET_IS_NT50_OR_LATER = 1;

        public const uint TARGET_IS_NT40_OR_LATER = 1;

        public const uint TARGET_IS_NT351_OR_WIN95_OR_LATER = 1;

        public const uint USER_CALL_IS_ASYNC = 0x0100;

        public const uint USER_CALL_NEW_CORRELATION_DESC = 0x0200;

        public const uint USER_MARSHAL_FC_BYTE = 1;

        public const uint USER_MARSHAL_FC_CHAR = 2;

        public const uint USER_MARSHAL_FC_SMALL = 3;

        public const uint USER_MARSHAL_FC_USMALL = 4;

        public const uint USER_MARSHAL_FC_WCHAR = 5;

        public const uint USER_MARSHAL_FC_SHORT = 6;

        public const uint USER_MARSHAL_FC_USHORT = 7;

        public const uint USER_MARSHAL_FC_LONG = 8;

        public const uint USER_MARSHAL_FC_ULONG = 9;

        public const uint USER_MARSHAL_FC_FLOAT = 10;

        public const uint USER_MARSHAL_FC_HYPER = 11;

        public const uint USER_MARSHAL_FC_DOUBLE = 12;

    }
}
