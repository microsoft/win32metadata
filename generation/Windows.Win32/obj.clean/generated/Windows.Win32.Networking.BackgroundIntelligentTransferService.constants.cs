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


namespace Windows.Win32.Networking.BackgroundIntelligentTransferService
{
    public static partial class Apis
    {
        public const uint BG_NOTIFY_JOB_TRANSFERRED = 0x0001;

        public const uint BG_NOTIFY_JOB_ERROR = 0x0002;

        public const uint BG_NOTIFY_DISABLE = 0x0004;

        public const uint BG_NOTIFY_JOB_MODIFICATION = 0x0008;

        public const uint BG_NOTIFY_FILE_TRANSFERRED = 0x0010;

        public const uint BG_NOTIFY_FILE_RANGES_TRANSFERRED = 0x0020;

        public const uint BG_JOB_ENUM_ALL_USERS = 0x0001;

        public const uint BG_COPY_FILE_OWNER = 1;

        public const uint BG_COPY_FILE_GROUP = 2;

        public const uint BG_COPY_FILE_DACL = 4;

        public const uint BG_COPY_FILE_SACL = 8;

        public const uint BG_COPY_FILE_ALL = 15;

        public const uint BG_SSL_ENABLE_CRL_CHECK = 0x0001;

        public const uint BG_SSL_IGNORE_CERT_CN_INVALID = 0x0002;

        public const uint BG_SSL_IGNORE_CERT_DATE_INVALID = 0x0004;

        public const uint BG_SSL_IGNORE_UNKNOWN_CA = 0x0008;

        public const uint BG_SSL_IGNORE_CERT_WRONG_USAGE = 0x0010;

        public const uint BG_HTTP_REDIRECT_POLICY_MASK = 0x0700;

        public const uint BG_HTTP_REDIRECT_POLICY_ALLOW_SILENT = 0x0000;

        public const uint BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT = 0x0100;

        public const uint BG_HTTP_REDIRECT_POLICY_DISALLOW = 0x0200;

        public const uint BG_HTTP_REDIRECT_POLICY_ALLOW_HTTPS_TO_HTTP = 0x0800;

        public const uint BG_ENABLE_PEERCACHING_CLIENT = 0x0001;

        public const uint BG_ENABLE_PEERCACHING_SERVER = 0x0002;

        public const uint BG_DISABLE_BRANCH_CACHE = 0x0004;

        public const uint BG_JOB_ENABLE_PEERCACHING_CLIENT = 0x0001;

        public const uint BG_JOB_ENABLE_PEERCACHING_SERVER = 0x0002;

        public const uint BG_JOB_DISABLE_BRANCH_CACHE = 0x0004;

        public const uint BITS_COST_STATE_UNRESTRICTED = 0x1;

        public const uint BITS_COST_STATE_CAPPED_USAGE_UNKNOWN = 0x2;

        public const uint BITS_COST_STATE_BELOW_CAP = 0x4;

        public const uint BITS_COST_STATE_NEAR_CAP = 0x8;

        public const uint BITS_COST_STATE_OVERCAP_CHARGED = 0x10;

        public const uint BITS_COST_STATE_OVERCAP_THROTTLED = 0x20;

        public const uint BITS_COST_STATE_USAGE_BASED = 0x40;

        public const uint BITS_COST_STATE_ROAMING = 0x80;

        public const uint BITS_COST_OPTION_IGNORE_CONGESTION = 0x80000000;

        public const uint BITS_COST_STATE_RESERVED = 0x40000000;

        public const uint QM_NOTIFY_FILE_DONE = 0x00000001;

        public const uint QM_NOTIFY_JOB_DONE = 0x00000002;

        public const uint QM_NOTIFY_GROUP_DONE = 0x00000004;

        public const uint QM_NOTIFY_DISABLE_NOTIFY = 0x00000040;

        public const uint QM_NOTIFY_USE_PROGRESSEX = 0x00000080;

        public const uint QM_STATUS_FILE_COMPLETE = 0x00000001;

        public const uint QM_STATUS_FILE_INCOMPLETE = 0x00000002;

        public const uint QM_STATUS_JOB_COMPLETE = 0x00000004;

        public const uint QM_STATUS_JOB_INCOMPLETE = 0x00000008;

        public const uint QM_STATUS_JOB_ERROR = 0x00000010;

        public const uint QM_STATUS_JOB_FOREGROUND = 0x00000020;

        public const uint QM_STATUS_GROUP_COMPLETE = 0x00000040;

        public const uint QM_STATUS_GROUP_INCOMPLETE = 0x00000080;

        public const uint QM_STATUS_GROUP_SUSPENDED = 0x00000100;

        public const uint QM_STATUS_GROUP_ERROR = 0x00000200;

        public const uint QM_STATUS_GROUP_FOREGROUND = 0x00000400;

        public const uint QM_PROTOCOL_HTTP = 1;

        public const uint QM_PROTOCOL_FTP = 2;

        public const uint QM_PROTOCOL_SMB = 3;

        public const uint QM_PROTOCOL_CUSTOM = 4;

        public const uint QM_PROGRESS_PERCENT_DONE = 1;

        public const uint QM_PROGRESS_TIME_DONE = 2;

        public const uint QM_PROGRESS_SIZE_DONE = 3;

        public const uint QM_E_INVALID_STATE = 0x81001001;

        public const uint QM_E_SERVICE_UNAVAILABLE = 0x81001002;

        public const uint QM_E_DOWNLOADER_UNAVAILABLE = 0x81001003;

        public const uint QM_E_ITEM_NOT_FOUND = 0x81001004;

    }
}
