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


namespace Windows.Win32.Security
{
    public static partial class Apis
    {
        public const uint CVT_SECONDS = 1;

        public const uint CRYPTPROTECT_PROMPT_ON_UNPROTECT = 0x1;

        public const uint CRYPTPROTECT_PROMPT_ON_PROTECT = 0x2;

        public const uint CRYPTPROTECT_PROMPT_RESERVED = 0x04;

        public const uint CRYPTPROTECT_PROMPT_STRONG = 0x08;

        public const uint CRYPTPROTECT_PROMPT_REQUIRE_STRONG = 0x10;

        public const uint CRYPTPROTECT_UI_FORBIDDEN = 0x1;

        public const uint CRYPTPROTECT_LOCAL_MACHINE = 0x4;

        public const uint CRYPTPROTECT_CRED_SYNC = 0x8;

        public const uint CRYPTPROTECT_AUDIT = 0x10;

        public const uint CRYPTPROTECT_NO_RECOVERY = 0x20;

        public const uint CRYPTPROTECT_VERIFY_PROTECTION = 0x40;

        public const uint CRYPTPROTECT_CRED_REGENERATE = 0x80;

        public const uint CRYPTPROTECT_FIRST_RESERVED_FLAGVAL = 0x0FFFFFFF;

        public const uint CRYPTPROTECT_LAST_RESERVED_FLAGVAL = 0xFFFFFFFF;

        public const uint CRYPTPROTECTMEMORY_BLOCK_SIZE = 16;

        public const uint CRYPTPROTECTMEMORY_SAME_PROCESS = 0x00;

        public const uint CRYPTPROTECTMEMORY_CROSS_PROCESS = 0x01;

        public const uint CRYPTPROTECTMEMORY_SAME_LOGON = 0x02;

        public const uint DSSI_READ_ONLY = 0x00000001;

        public const uint DSSI_NO_ACCESS_CHECK = 0x00000002;

        public const uint DSSI_NO_EDIT_SACL = 0x00000004;

        public const uint DSSI_NO_EDIT_OWNER = 0x00000008;

        public const uint DSSI_IS_ROOT = 0x00000010;

        public const uint DSSI_NO_FILTER = 0x00000020;

        public const uint DSSI_NO_READONLY_MESSAGE = 0x00000040;

        public const uint CRYPTCAT_MAX_MEMBERTAG = 64;

        public const uint CRYPTCAT_MEMBER_SORTED = 0x40000000;

        public const uint CRYPTCAT_ATTR_AUTHENTICATED = 0x10000000;

        public const uint CRYPTCAT_ATTR_UNAUTHENTICATED = 0x20000000;

        public const uint CRYPTCAT_ATTR_NAMEASCII = 0x00000001;

        public const uint CRYPTCAT_ATTR_NAMEOBJID = 0x00000002;

        public const uint CRYPTCAT_ATTR_DATAASCII = 0x00010000;

        public const uint CRYPTCAT_ATTR_DATABASE64 = 0x00020000;

        public const uint CRYPTCAT_ATTR_DATAREPLACE = 0x00040000;

        public const uint CRYPTCAT_ATTR_NO_AUTO_COMPAT_ENTRY = 0x01000000;

        public const uint CRYPTCAT_E_AREA_HEADER = 0x00000000;

        public const uint CRYPTCAT_E_AREA_MEMBER = 0x00010000;

        public const uint CRYPTCAT_E_AREA_ATTRIBUTE = 0x00020000;

        public const uint CRYPTCAT_E_CDF_UNSUPPORTED = 0x00000001;

        public const uint CRYPTCAT_E_CDF_DUPLICATE = 0x00000002;

        public const uint CRYPTCAT_E_CDF_TAGNOTFOUND = 0x00000004;

        public const uint CRYPTCAT_E_CDF_MEMBER_FILE_PATH = 0x00010001;

        public const uint CRYPTCAT_E_CDF_MEMBER_INDIRECTDATA = 0x00010002;

        public const uint CRYPTCAT_E_CDF_MEMBER_FILENOTFOUND = 0x00010004;

        public const uint CRYPTCAT_E_CDF_BAD_GUID_CONV = 0x00020001;

        public const uint CRYPTCAT_E_CDF_ATTR_TOOFEWVALUES = 0x00020002;

        public const uint CRYPTCAT_E_CDF_ATTR_TYPECOMBO = 0x00020004;

        public const uint CRYPTCAT_ADDCATALOG_NONE = 0x00000000;

        public const uint CRYPTCAT_ADDCATALOG_HARDLINK = 0x00000001;

        public const uint MSSIP_FLAGS_PROHIBIT_RESIZE_ON_CREATE = 0x00010000;

        public const uint MSSIP_FLAGS_USE_CATALOG = 0x00020000;

        public const uint MSSIP_FLAGS_MULTI_HASH = 0x00040000;

        public const uint SPC_INC_PE_RESOURCES_FLAG = 0x80;

        public const uint SPC_INC_PE_DEBUG_INFO_FLAG = 0x40;

        public const uint SPC_INC_PE_IMPORT_ADDR_TABLE_FLAG = 0x20;

        public const uint SPC_EXC_PE_PAGE_HASHES_FLAG = 0x10;

        public const uint SPC_INC_PE_PAGE_HASHES_FLAG = 0x100;

        public const uint SPC_DIGEST_GENERATE_FLAG = 0x200;

        public const uint SPC_DIGEST_SIGN_FLAG = 0x400;

        public const uint SPC_DIGEST_SIGN_EX_FLAG = 0x4000;

        public const uint SPC_RELAXED_PE_MARKER_CHECK = 0x800;

        public const uint SPC_MARKER_CHECK_SKIP_SIP_INDIRECT_DATA_FLAG = 0x00000001;

        public const uint SIP_CAP_SET_VERSION_2 = 2;

        public const uint SIP_CAP_SET_VERSION_3 = 3;

        public const uint SIP_CAP_SET_CUR_VER = 3;

        public const uint SIP_CAP_FLAG_SEALING = 0x00000001;

        public const uint SIP_MAX_MAGIC_NUMBER = 4;

        public static readonly Guid cNodetypeSceTemplateServices__scanned__ = new Guid(0x24a7f717, 0x1f0c, 0x11d1, 0xaf, 0xfb, 0x0, 0xc0, 0x4f, 0xb9, 0x84, 0xf9);

        public static readonly Guid cNodetypeSceAnalysisServices__scanned__ = new Guid(0x678050c7, 0x1ff8, 0x11d1, 0xaf, 0xfb, 0x0, 0xc0, 0x4f, 0xb9, 0x84, 0xf9);

        public static readonly Guid cNodetypeSceEventLog__scanned__ = new Guid(0x2ce06698, 0x4bf3, 0x11d1, 0x8c, 0x30, 0x0, 0xc0, 0x4f, 0xb9, 0x84, 0xf9);

        public const int SCESTATUS_SUCCESS = 0;

        public const int SCESTATUS_INVALID_PARAMETER = 1;

        public const int SCESTATUS_RECORD_NOT_FOUND = 2;

        public const int SCESTATUS_INVALID_DATA = 3;

        public const int SCESTATUS_OBJECT_EXIST = 4;

        public const int SCESTATUS_BUFFER_TOO_SMALL = 5;

        public const int SCESTATUS_PROFILE_NOT_FOUND = 6;

        public const int SCESTATUS_BAD_FORMAT = 7;

        public const int SCESTATUS_NOT_ENOUGH_RESOURCE = 8;

        public const int SCESTATUS_ACCESS_DENIED = 9;

        public const int SCESTATUS_CANT_DELETE = 10;

        public const int SCESTATUS_PREFIX_OVERFLOW = 11;

        public const int SCESTATUS_OTHER_ERROR = 12;

        public const int SCESTATUS_ALREADY_RUNNING = 13;

        public const int SCESTATUS_SERVICE_NOT_SUPPORT = 14;

        public const int SCESTATUS_MOD_NOT_FOUND = 15;

        public const int SCESTATUS_EXCEPTION_IN_SERVER = 16;

        public const int SCESTATUS_NO_TEMPLATE_GIVEN = 17;

        public const int SCESTATUS_NO_MAPPING = 18;

        public const int SCESTATUS_TRUST_FAIL = 19;

        public const int SCESVC_ENUMERATION_MAX = 100;

        public const uint TPMVSC_DEFAULT_ADMIN_ALGORITHM_ID = 0x82;

        public const uint SAFER_SCOPEID_MACHINE = 1;

        public const uint SAFER_SCOPEID_USER = 2;

        public const uint SAFER_LEVELID_FULLYTRUSTED = 0x40000;

        public const uint SAFER_LEVELID_NORMALUSER = 0x20000;

        public const uint SAFER_LEVELID_CONSTRAINED = 0x10000;

        public const uint SAFER_LEVELID_UNTRUSTED = 0x01000;

        public const uint SAFER_LEVELID_DISALLOWED = 0x00000;

        public const uint SAFER_LEVEL_OPEN = 1;

        public const uint SAFER_MAX_FRIENDLYNAME_SIZE = 256;

        public const uint SAFER_MAX_DESCRIPTION_SIZE = 256;

        public const uint SAFER_MAX_HASH_SIZE = 64;

        public const uint SAFER_CRITERIA_IMAGEPATH = 0x00001;

        public const uint SAFER_CRITERIA_NOSIGNEDHASH = 0x00002;

        public const uint SAFER_CRITERIA_IMAGEHASH = 0x00004;

        public const uint SAFER_CRITERIA_AUTHENTICODE = 0x00008;

        public const uint SAFER_CRITERIA_URLZONE = 0x00010;

        public const uint SAFER_CRITERIA_APPX_PACKAGE = 0x00020;

        public const uint SAFER_CRITERIA_IMAGEPATH_NT = 0x01000;

        public const uint SAFER_POLICY_JOBID_MASK = 0xFF000000;

        public const uint SAFER_POLICY_JOBID_CONSTRAINED = 0x04000000;

        public const uint SAFER_POLICY_JOBID_UNTRUSTED = 0x03000000;

        public const uint SAFER_POLICY_ONLY_EXES = 0x00010000;

        public const uint SAFER_POLICY_SANDBOX_INERT = 0x00020000;

        public const uint SAFER_POLICY_HASH_DUPLICATE = 0x00040000;

        public const uint SAFER_POLICY_ONLY_AUDIT = 0x00001000;

        public const uint SAFER_POLICY_BLOCK_CLIENT_UI = 0x00002000;

        public const uint SAFER_POLICY_UIFLAGS_MASK = 0x000000FF;

        public const uint SAFER_POLICY_UIFLAGS_INFORMATION_PROMPT = 0x00000001;

        public const uint SAFER_POLICY_UIFLAGS_OPTION_PROMPT = 0x00000002;

        public const uint SAFER_POLICY_UIFLAGS_HIDDEN = 0x00000004;

        public const uint WINTRUST_MAX_HEADER_BYTES_TO_MAP_DEFAULT = 0x00A00000;

        public const uint WINTRUST_MAX_HASH_BYTES_TO_MAP_DEFAULT = 0x00100000;

        public const uint WSS_VERIFY_SEALING = 0x00000004;

        public const uint WSS_INPUT_FLAG_MASK = 0x00000007;

        public const uint WSS_OUT_SEALING_STATUS_VERIFIED = 0x80000000;

        public const uint WSS_OUT_HAS_SEALING_INTENT = 0x40000000;

        public const uint WSS_OUT_FILE_SUPPORTS_SEAL = 0x20000000;

        public const uint WSS_OUTPUT_FLAG_MASK = 0xe0000000;

        public const uint TRUSTERROR_STEP_WVTPARAMS = 0;

        public const uint TRUSTERROR_STEP_FILEIO = 2;

        public const uint TRUSTERROR_STEP_SIP = 3;

        public const uint TRUSTERROR_STEP_SIPSUBJINFO = 5;

        public const uint TRUSTERROR_STEP_CATALOGFILE = 6;

        public const uint TRUSTERROR_STEP_CERTSTORE = 7;

        public const uint TRUSTERROR_STEP_MESSAGE = 8;

        public const uint TRUSTERROR_STEP_MSG_SIGNERCOUNT = 9;

        public const uint TRUSTERROR_STEP_MSG_INNERCNTTYPE = 10;

        public const uint TRUSTERROR_STEP_MSG_INNERCNT = 11;

        public const uint TRUSTERROR_STEP_MSG_STORE = 12;

        public const uint TRUSTERROR_STEP_MSG_SIGNERINFO = 13;

        public const uint TRUSTERROR_STEP_MSG_SIGNERCERT = 14;

        public const uint TRUSTERROR_STEP_MSG_CERTCHAIN = 15;

        public const uint TRUSTERROR_STEP_MSG_COUNTERSIGINFO = 16;

        public const uint TRUSTERROR_STEP_MSG_COUNTERSIGCERT = 17;

        public const uint TRUSTERROR_STEP_VERIFY_MSGHASH = 18;

        public const uint TRUSTERROR_STEP_VERIFY_MSGINDIRECTDATA = 19;

        public const uint TRUSTERROR_STEP_FINAL_WVTINIT = 30;

        public const uint TRUSTERROR_STEP_FINAL_INITPROV = 31;

        public const uint TRUSTERROR_STEP_FINAL_OBJPROV = 32;

        public const uint TRUSTERROR_STEP_FINAL_SIGPROV = 33;

        public const uint TRUSTERROR_STEP_FINAL_CERTPROV = 34;

        public const uint TRUSTERROR_STEP_FINAL_CERTCHKPROV = 35;

        public const uint TRUSTERROR_STEP_FINAL_POLICYPROV = 36;

        public const uint TRUSTERROR_STEP_FINAL_UIPROV = 37;

        public const uint TRUSTERROR_MAX_STEPS = 38;

        public const uint WSS_OBJTRUST_SUPPORT = 0x00000001;

        public const uint WSS_SIGTRUST_SUPPORT = 0x00000002;

        public const uint WSS_CERTTRUST_SUPPORT = 0x00000004;

        public const uint WT_CURRENT_VERSION = 0x00000200;

        public const uint WT_ADD_ACTION_ID_RET_RESULT_FLAG = 0x1;

        public const uint SPC_UUID_LENGTH = 16;

        public const uint WIN_CERT_REVISION_1_0 = 0x0100;

        public const uint WIN_CERT_REVISION_2_0 = 0x0200;

        public const uint WIN_CERT_TYPE_X509 = 0x0001;

        public const uint WIN_CERT_TYPE_PKCS_SIGNED_DATA = 0x0002;

        public const uint WIN_CERT_TYPE_RESERVED_1 = 0x0003;

        public const uint WIN_CERT_TYPE_TS_STACK_SIGNED = 0x0004;

        public const uint WT_TRUSTDBDIALOG_NO_UI_FLAG = 0x00000001;

        public const uint WT_TRUSTDBDIALOG_ONLY_PUB_TAB_FLAG = 0x00000002;

        public const uint WT_TRUSTDBDIALOG_WRITE_LEGACY_REG_FLAG = 0x00000100;

        public const uint WT_TRUSTDBDIALOG_WRITE_IEAK_STORE_FLAG = 0x00000200;

        public const uint WLX_VERSION_1_0 = 0X00010000;

        public const uint WLX_VERSION_1_1 = 0X00010001;

        public const uint WLX_VERSION_1_2 = 0X00010002;

        public const uint WLX_VERSION_1_3 = 0X00010003;

        public const uint WLX_VERSION_1_4 = 0X00010004;

        public const uint WLX_SAS_TYPE_TIMEOUT = 0;

        public const uint WLX_SAS_TYPE_CTRL_ALT_DEL = 1;

        public const uint WLX_SAS_TYPE_SCRNSVR_TIMEOUT = 2;

        public const uint WLX_SAS_TYPE_SCRNSVR_ACTIVITY = 3;

        public const uint WLX_SAS_TYPE_USER_LOGOFF = 4;

        public const uint WLX_SAS_TYPE_SC_INSERT = 5;

        public const uint WLX_SAS_TYPE_SC_REMOVE = 6;

        public const uint WLX_SAS_TYPE_AUTHENTICATED = 7;

        public const uint WLX_SAS_TYPE_SC_FIRST_READER_ARRIVED = 8;

        public const uint WLX_SAS_TYPE_SC_LAST_READER_REMOVED = 9;

        public const uint WLX_SAS_TYPE_SWITCHUSER = 10;

        public const uint WLX_SAS_TYPE_MAX_MSFT_VALUE = 127;

        public const uint WLX_LOGON_OPT_NO_PROFILE = 0x00000001;

        public const uint WLX_PROFILE_TYPE_V1_0 = 1;

        public const uint WLX_PROFILE_TYPE_V2_0 = 2;

        public const uint WLX_SAS_ACTION_LOGON = 1;

        public const uint WLX_SAS_ACTION_NONE = 2;

        public const uint WLX_SAS_ACTION_LOCK_WKSTA = 3;

        public const uint WLX_SAS_ACTION_LOGOFF = 4;

        public const uint WLX_SAS_ACTION_PWD_CHANGED = 6;

        public const uint WLX_SAS_ACTION_TASKLIST = 7;

        public const uint WLX_SAS_ACTION_UNLOCK_WKSTA = 8;

        public const uint WLX_SAS_ACTION_FORCE_LOGOFF = 9;

        public const uint WLX_SAS_ACTION_SHUTDOWN_SLEEP = 12;

        public const uint WLX_SAS_ACTION_SHUTDOWN_SLEEP2 = 13;

        public const uint WLX_SAS_ACTION_SHUTDOWN_HIBERNATE = 14;

        public const uint WLX_SAS_ACTION_RECONNECTED = 15;

        public const uint WLX_SAS_ACTION_DELAYED_FORCE_LOGOFF = 16;

        public const uint WLX_SAS_ACTION_SWITCH_CONSOLE = 17;

        public const uint WLX_WM_SAS = WM_USER + 601;

        public const uint WLX_DLG_SAS = 101;

        public const uint WLX_DLG_INPUT_TIMEOUT = 102;

        public const uint WLX_DLG_SCREEN_SAVER_TIMEOUT = 103;

        public const uint WLX_DLG_USER_LOGOFF = 104;

        public const uint WLX_DIRECTORY_LENGTH = 256;

        public const uint WLX_CREDENTIAL_TYPE_V1_0 = 1;

        public const uint WLX_CREDENTIAL_TYPE_V2_0 = 2;

        public const uint WLX_CONSOLESWITCHCREDENTIAL_TYPE_V1_0 = 1;

        public const uint STATUSMSG_OPTION_NOANIMATION = 0x00000001;

        public const uint STATUSMSG_OPTION_SETFOREGROUND = 0x00000002;

        public const uint WLX_DESKTOP_NAME = 0x00000001;

        public const uint WLX_DESKTOP_HANDLE = 0x00000002;

        public const uint WLX_CREATE_INSTANCE_ONLY = 0x00000001;

        public const uint WLX_CREATE_USER = 0x00000002;

        public const uint WLX_OPTION_USE_CTRL_ALT_DEL = 0x00000001;

        public const uint WLX_OPTION_CONTEXT_POINTER = 0x00000002;

        public const uint WLX_OPTION_USE_SMART_CARD = 0x00000003;

        public const uint WLX_OPTION_FORCE_LOGOFF_TIME = 0x00000004;

        public const uint WLX_OPTION_IGNORE_AUTO_LOGON = 0x00000008;

        public const uint WLX_OPTION_NO_SWITCH_ON_SAS = 0x00000009;

        public const uint WLX_OPTION_SMART_CARD_PRESENT = 0x00010001;

        public const uint WLX_OPTION_SMART_CARD_INFO = 0x00010002;

        public const uint WLX_OPTION_DISPATCH_TABLE_SIZE = 0x00010003;

    }
}
