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


namespace Windows.Win32.NetworkManagement.QoS
{
    public static partial class Apis
    {
        public const uint QOS_MAX_OBJECT_STRING_LENGTH = 256;

        public const uint QOS_TRAFFIC_GENERAL_ID_BASE = 4000;

        public const uint SERVICETYPE_NOTRAFFIC = 0x00000000;

        public const uint SERVICETYPE_BESTEFFORT = 0x00000001;

        public const uint SERVICETYPE_CONTROLLEDLOAD = 0x00000002;

        public const uint SERVICETYPE_GUARANTEED = 0x00000003;

        public const uint SERVICETYPE_NETWORK_UNAVAILABLE = 0x00000004;

        public const uint SERVICETYPE_GENERAL_INFORMATION = 0x00000005;

        public const uint SERVICETYPE_NOCHANGE = 0x00000006;

        public const uint SERVICETYPE_NONCONFORMING = 0x00000009;

        public const uint SERVICETYPE_NETWORK_CONTROL = 0x0000000A;

        public const uint SERVICETYPE_QUALITATIVE = 0x0000000D;

        public const uint SERVICE_BESTEFFORT = 0x80010000;

        public const uint SERVICE_CONTROLLEDLOAD = 0x80020000;

        public const uint SERVICE_GUARANTEED = 0x80040000;

        public const uint SERVICE_QUALITATIVE = 0x80200000;

        public const uint SERVICE_NO_TRAFFIC_CONTROL = 0x81000000;

        public const uint SERVICE_NO_QOS_SIGNALING = 0x40000000;

        public const uint QOS_NOT_SPECIFIED = 0xFFFFFFFF;

        public const uint POSITIVE_INFINITY_RATE = 0xFFFFFFFE;

        public const uint QOS_GENERAL_ID_BASE = 2000;

        public const uint TC_NONCONF_BORROW = 0;

        public const uint TC_NONCONF_SHAPE = 1;

        public const uint TC_NONCONF_DISCARD = 2;

        public const uint TC_NONCONF_BORROW_PLUS = 3;

        public const uint SESSFLG_E_Police = 0x01;

        public const uint Opt_Share_mask = 0x00000018;

        public const uint Opt_Distinct = 0x00000008;

        public const uint Opt_Shared = 0x00000010;

        public const uint Opt_SndSel_mask = 0x00000007;

        public const uint Opt_Wildcard = 0x00000001;

        public const uint Opt_Explicit = 0x00000002;

        public const uint ERROR_SPECF_InPlace = 0x01;

        public const uint ERROR_SPECF_NotGuilty = 0x02;

        public const uint ERR_FORWARD_OK = 0x8000;

        public const uint ERR_Usage_globl = 0x00;

        public const uint ERR_Usage_local = 0x10;

        public const uint ERR_Usage_serv = 0x11;

        public const uint ERR_global_mask = 0x0fff;

        public const uint GENERAL_INFO = 1;

        public const uint GUARANTEED_SERV = 2;

        public const uint PREDICTIVE_SERV = 3;

        public const uint CONTROLLED_DELAY_SERV = 4;

        public const uint CONTROLLED_LOAD_SERV = 5;

        public const uint QUALITATIVE_SERV = 6;

        public const uint INTSERV_VERS_MASK = 0xf0;

        public const uint INTSERV_VERSION0 = 0;

        public const uint ISSH_BREAK_BIT = 0x80;

        public const uint ISPH_FLG_INV = 0x80;

        public const uint RSVP_PATH = 1;

        public const uint RSVP_RESV = 2;

        public const uint RSVP_PATH_ERR = 3;

        public const uint RSVP_RESV_ERR = 4;

        public const uint RSVP_PATH_TEAR = 5;

        public const uint RSVP_RESV_TEAR = 6;

        public const uint RSVP_Err_NONE = 0;

        public const uint RSVP_Erv_Nonev = 0;

        public const uint RSVP_Err_ADMISSION = 1;

        public const uint RSVP_Erv_Other = 0;

        public const uint RSVP_Erv_DelayBnd = 1;

        public const uint RSVP_Erv_Bandwidth = 2;

        public const uint RSVP_Erv_MTU = 3;

        public const uint RSVP_Erv_Flow_Rate = 0x8001;

        public const uint RSVP_Erv_Bucket_szie = 0x8002;

        public const uint RSVP_Erv_Peak_Rate = 0x8003;

        public const uint RSVP_Erv_Min_Policied_size = 0x8004;

        public const uint RSVP_Err_POLICY = 2;

        public const uint POLICY_ERRV_NO_MORE_INFO = 1;

        public const uint POLICY_ERRV_UNSUPPORTED_CREDENTIAL_TYPE = 2;

        public const uint POLICY_ERRV_INSUFFICIENT_PRIVILEGES = 3;

        public const uint POLICY_ERRV_EXPIRED_CREDENTIALS = 4;

        public const uint POLICY_ERRV_IDENTITY_CHANGED = 5;

        public const uint POLICY_ERRV_UNKNOWN = 0;

        public const uint POLICY_ERRV_GLOBAL_DEF_FLOW_COUNT = 1;

        public const uint POLICY_ERRV_GLOBAL_GRP_FLOW_COUNT = 2;

        public const uint POLICY_ERRV_GLOBAL_USER_FLOW_COUNT = 3;

        public const uint POLICY_ERRV_GLOBAL_UNAUTH_USER_FLOW_COUNT = 4;

        public const uint POLICY_ERRV_SUBNET_DEF_FLOW_COUNT = 5;

        public const uint POLICY_ERRV_SUBNET_GRP_FLOW_COUNT = 6;

        public const uint POLICY_ERRV_SUBNET_USER_FLOW_COUNT = 7;

        public const uint POLICY_ERRV_SUBNET_UNAUTH_USER_FLOW_COUNT = 8;

        public const uint POLICY_ERRV_GLOBAL_DEF_FLOW_DURATION = 9;

        public const uint POLICY_ERRV_GLOBAL_GRP_FLOW_DURATION = 10;

        public const uint POLICY_ERRV_GLOBAL_USER_FLOW_DURATION = 11;

        public const uint POLICY_ERRV_GLOBAL_UNAUTH_USER_FLOW_DURATION = 12;

        public const uint POLICY_ERRV_SUBNET_DEF_FLOW_DURATION = 13;

        public const uint POLICY_ERRV_SUBNET_GRP_FLOW_DURATION = 14;

        public const uint POLICY_ERRV_SUBNET_USER_FLOW_DURATION = 15;

        public const uint POLICY_ERRV_SUBNET_UNAUTH_USER_FLOW_DURATION = 16;

        public const uint POLICY_ERRV_GLOBAL_DEF_FLOW_RATE = 17;

        public const uint POLICY_ERRV_GLOBAL_GRP_FLOW_RATE = 18;

        public const uint POLICY_ERRV_GLOBAL_USER_FLOW_RATE = 19;

        public const uint POLICY_ERRV_GLOBAL_UNAUTH_USER_FLOW_RATE = 20;

        public const uint POLICY_ERRV_SUBNET_DEF_FLOW_RATE = 21;

        public const uint POLICY_ERRV_SUBNET_GRP_FLOW_RATE = 22;

        public const uint POLICY_ERRV_SUBNET_USER_FLOW_RATE = 23;

        public const uint POLICY_ERRV_SUBNET_UNAUTH_USER_FLOW_RATE = 24;

        public const uint POLICY_ERRV_GLOBAL_DEF_PEAK_RATE = 25;

        public const uint POLICY_ERRV_GLOBAL_GRP_PEAK_RATE = 26;

        public const uint POLICY_ERRV_GLOBAL_USER_PEAK_RATE = 27;

        public const uint POLICY_ERRV_GLOBAL_UNAUTH_USER_PEAK_RATE = 28;

        public const uint POLICY_ERRV_SUBNET_DEF_PEAK_RATE = 29;

        public const uint POLICY_ERRV_SUBNET_GRP_PEAK_RATE = 30;

        public const uint POLICY_ERRV_SUBNET_USER_PEAK_RATE = 31;

        public const uint POLICY_ERRV_SUBNET_UNAUTH_USER_PEAK_RATE = 32;

        public const uint POLICY_ERRV_GLOBAL_DEF_SUM_FLOW_RATE = 33;

        public const uint POLICY_ERRV_GLOBAL_GRP_SUM_FLOW_RATE = 34;

        public const uint POLICY_ERRV_GLOBAL_USER_SUM_FLOW_RATE = 35;

        public const uint POLICY_ERRV_GLOBAL_UNAUTH_USER_SUM_FLOW_RATE = 36;

        public const uint POLICY_ERRV_SUBNET_DEF_SUM_FLOW_RATE = 37;

        public const uint POLICY_ERRV_SUBNET_GRP_SUM_FLOW_RATE = 38;

        public const uint POLICY_ERRV_SUBNET_USER_SUM_FLOW_RATE = 39;

        public const uint POLICY_ERRV_SUBNET_UNAUTH_USER_SUM_FLOW_RATE = 40;

        public const uint POLICY_ERRV_GLOBAL_DEF_SUM_PEAK_RATE = 41;

        public const uint POLICY_ERRV_GLOBAL_GRP_SUM_PEAK_RATE = 42;

        public const uint POLICY_ERRV_GLOBAL_USER_SUM_PEAK_RATE = 43;

        public const uint POLICY_ERRV_GLOBAL_UNAUTH_USER_SUM_PEAK_RATE = 44;

        public const uint POLICY_ERRV_SUBNET_DEF_SUM_PEAK_RATE = 45;

        public const uint POLICY_ERRV_SUBNET_GRP_SUM_PEAK_RATE = 46;

        public const uint POLICY_ERRV_SUBNET_USER_SUM_PEAK_RATE = 47;

        public const uint POLICY_ERRV_SUBNET_UNAUTH_USER_SUM_PEAK_RATE = 48;

        public const uint POLICY_ERRV_UNKNOWN_USER = 49;

        public const uint POLICY_ERRV_NO_PRIVILEGES = 50;

        public const uint POLICY_ERRV_EXPIRED_USER_TOKEN = 51;

        public const uint POLICY_ERRV_NO_RESOURCES = 52;

        public const uint POLICY_ERRV_PRE_EMPTED = 53;

        public const uint POLICY_ERRV_USER_CHANGED = 54;

        public const uint POLICY_ERRV_NO_ACCEPTS = 55;

        public const uint POLICY_ERRV_NO_MEMORY = 56;

        public const uint POLICY_ERRV_CRAZY_FLOWSPEC = 57;

        public const uint RSVP_Err_NO_PATH = 3;

        public const uint RSVP_Err_NO_SENDER = 4;

        public const uint RSVP_Err_BAD_STYLE = 5;

        public const uint RSVP_Err_UNKNOWN_STYLE = 6;

        public const uint RSVP_Err_BAD_DSTPORT = 7;

        public const uint RSVP_Err_BAD_SNDPORT = 8;

        public const uint RSVP_Err_AMBIG_FILTER = 9;

        public const uint RSVP_Err_PREEMPTED = 12;

        public const uint RSVP_Err_UNKN_OBJ_CLASS = 13;

        public const uint RSVP_Err_UNKNOWN_CTYPE = 14;

        public const uint RSVP_Err_API_ERROR = 20;

        public const uint RSVP_Err_TC_ERROR = 21;

        public const uint RSVP_Erv_Conflict_Serv = 01;

        public const uint RSVP_Erv_No_Serv = 02;

        public const uint RSVP_Erv_Crazy_Flowspec = 03;

        public const uint RSVP_Erv_Crazy_Tspec = 04;

        public const uint RSVP_Err_TC_SYS_ERROR = 22;

        public const uint RSVP_Err_RSVP_SYS_ERROR = 23;

        public const uint RSVP_Erv_MEMORY = 1;

        public const uint RSVP_Erv_API = 2;

        public const uint LPM_PE_USER_IDENTITY = 2;

        public const uint LPM_PE_APP_IDENTITY = 3;

        public const uint ERROR_NO_MORE_INFO = 1;

        public const uint UNSUPPORTED_CREDENTIAL_TYPE = 2;

        public const uint INSUFFICIENT_PRIVILEGES = 3;

        public const uint EXPIRED_CREDENTIAL = 4;

        public const uint IDENTITY_CHANGED = 5;

        public const uint LPM_OK = 0;

        public const uint INV_LPM_HANDLE = 1;

        public const uint LPM_TIME_OUT = 2;

        public const uint INV_REQ_HANDLE = 3;

        public const uint DUP_RESULTS = 4;

        public const uint INV_RESULTS = 5;

        public const uint LPM_PE_ALL_TYPES = 0;

        public const uint LPM_API_VERSION_1 = 1;

        public const uint PCM_VERSION_1 = 1;

        public const uint LPV_RESERVED = 0;

        public const uint LPV_MIN_PRIORITY = 1;

        public const uint LPV_MAX_PRIORITY = 0xFF00;

        public const uint LPV_DROP_MSG = 0xFFFD;

        public const uint LPV_DONT_CARE = 0xFFFE;

        public const uint LPV_REJECT = 0xFFFF;

        public const uint FORCE_IMMEDIATE_REFRESH = 1;

        public const uint LPM_RESULT_READY = 0;

        public const uint LPM_RESULT_DEFER = 1;

        public const uint RCVD_PATH_TEAR = 1;

        public const uint RCVD_RESV_TEAR = 2;

        public const uint ADM_CTRL_FAILED = 3;

        public const uint STATE_TIMEOUT = 4;

        public const uint FLOW_DURATION = 5;

        public const uint RESOURCES_ALLOCATED = 1;

        public const uint RESOURCES_MODIFIED = 2;

        public const uint CURRENT_TCI_VERSION = 0x0002;

        public const uint TC_NOTIFY_IFC_UP = 1;

        public const uint TC_NOTIFY_IFC_CLOSE = 2;

        public const uint TC_NOTIFY_IFC_CHANGE = 3;

        public const uint TC_NOTIFY_PARAM_CHANGED = 4;

        public const uint TC_NOTIFY_FLOW_CLOSE = 5;

        public const uint MAX_STRING_LENGTH = 256;

        public const uint QOS_OUTGOING_DEFAULT_MINIMUM_BANDWIDTH = 0xFFFFFFFF;

        public const uint QOS_QUERYFLOW_FRESH = 0x00000001;

        public const uint QOS_NON_ADAPTIVE_FLOW = 0x00000002;

    }
}
