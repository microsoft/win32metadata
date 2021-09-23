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


namespace Windows.Win32.Devices.Fax
{
    public static partial class Apis
    {
        public const uint FS_INITIALIZING = 0x20000000;

        public const uint FS_DIALING = 0x20000001;

        public const uint FS_TRANSMITTING = 0x20000002;

        public const uint FS_RECEIVING = 0x20000004;

        public const uint FS_COMPLETED = 0x20000008;

        public const uint FS_HANDLED = 0x20000010;

        public const uint FS_LINE_UNAVAILABLE = 0x20000020;

        public const uint FS_BUSY = 0x20000040;

        public const uint FS_NO_ANSWER = 0x20000080;

        public const uint FS_BAD_ADDRESS = 0x20000100;

        public const uint FS_NO_DIAL_TONE = 0x20000200;

        public const uint FS_DISCONNECTED = 0x20000400;

        public const uint FS_FATAL_ERROR = 0x20000800;

        public const uint FS_NOT_FAX_CALL = 0x20001000;

        public const uint FS_CALL_DELAYED = 0x20002000;

        public const uint FS_CALL_BLACKLISTED = 0x20004000;

        public const uint FS_USER_ABORT = 0x20200000;

        public const uint FS_ANSWERED = 0x20800000;

        public const uint FAXDEVRECEIVE_SIZE = 4096;

        public const uint FAXDEVREPORTSTATUS_SIZE = 4096;

        public const int FAX_ERR_START = 7001;

        public const int FAX_ERR_SRV_OUTOFMEMORY = 7001;

        public const int FAX_ERR_GROUP_NOT_FOUND = 7002;

        public const int FAX_ERR_BAD_GROUP_CONFIGURATION = 7003;

        public const int FAX_ERR_GROUP_IN_USE = 7004;

        public const int FAX_ERR_RULE_NOT_FOUND = 7005;

        public const int FAX_ERR_NOT_NTFS = 7006;

        public const int FAX_ERR_DIRECTORY_IN_USE = 7007;

        public const int FAX_ERR_FILE_ACCESS_DENIED = 7008;

        public const int FAX_ERR_MESSAGE_NOT_FOUND = 7009;

        public const int FAX_ERR_DEVICE_NUM_LIMIT_EXCEEDED = 7010;

        public const int FAX_ERR_NOT_SUPPORTED_ON_THIS_SKU = 7011;

        public const int FAX_ERR_VERSION_MISMATCH = 7012;

        public const int FAX_ERR_RECIPIENTS_LIMIT = 7013;

        public const int FAX_ERR_END = 7013;

        [NativeTypeName("HRESULT")]
        public const int FAX_E_SRV_OUTOFMEMORY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_SRV_OUTOFMEMORY));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_GROUP_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_GROUP_NOT_FOUND));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_BAD_GROUP_CONFIGURATION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_BAD_GROUP_CONFIGURATION));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_GROUP_IN_USE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_GROUP_IN_USE));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_RULE_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_RULE_NOT_FOUND));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_NOT_NTFS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_NOT_NTFS));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_DIRECTORY_IN_USE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_DIRECTORY_IN_USE));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_FILE_ACCESS_DENIED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_FILE_ACCESS_DENIED));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_MESSAGE_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_MESSAGE_NOT_FOUND));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_DEVICE_NUM_LIMIT_EXCEEDED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_DEVICE_NUM_LIMIT_EXCEEDED));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_NOT_SUPPORTED_ON_THIS_SKU = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_NOT_SUPPORTED_ON_THIS_SKU));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_VERSION_MISMATCH = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_VERSION_MISMATCH));

        [NativeTypeName("HRESULT")]
        public const int FAX_E_RECIPIENTS_LIMIT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(FAX_ERR_RECIPIENTS_LIMIT));

        public const uint JT_UNKNOWN = 0;

        public const uint JT_SEND = 1;

        public const uint JT_RECEIVE = 2;

        public const uint JT_ROUTING = 3;

        public const uint JT_FAIL_RECEIVE = 4;

        public const uint JS_PENDING = 0x00000000;

        public const uint JS_INPROGRESS = 0x00000001;

        public const uint JS_DELETING = 0x00000002;

        public const uint JS_FAILED = 0x00000004;

        public const uint JS_PAUSED = 0x00000008;

        public const uint JS_NOLINE = 0x00000010;

        public const uint JS_RETRYING = 0x00000020;

        public const uint JS_RETRIES_EXCEEDED = 0x00000040;

        public const uint FPS_DIALING = 0x20000001;

        public const uint FPS_SENDING = 0x20000002;

        public const uint FPS_RECEIVING = 0x20000004;

        public const uint FPS_COMPLETED = 0x20000008;

        public const uint FPS_HANDLED = 0x20000010;

        public const uint FPS_UNAVAILABLE = 0x20000020;

        public const uint FPS_BUSY = 0x20000040;

        public const uint FPS_NO_ANSWER = 0x20000080;

        public const uint FPS_BAD_ADDRESS = 0x20000100;

        public const uint FPS_NO_DIAL_TONE = 0x20000200;

        public const uint FPS_DISCONNECTED = 0x20000400;

        public const uint FPS_FATAL_ERROR = 0x20000800;

        public const uint FPS_NOT_FAX_CALL = 0x20001000;

        public const uint FPS_CALL_DELAYED = 0x20002000;

        public const uint FPS_CALL_BLACKLISTED = 0x20004000;

        public const uint FPS_INITIALIZING = 0x20008000;

        public const uint FPS_OFFLINE = 0x20010000;

        public const uint FPS_RINGING = 0x20020000;

        public const uint FPS_AVAILABLE = 0x20100000;

        public const uint FPS_ABORTING = 0x20200000;

        public const uint FPS_ROUTING = 0x20400000;

        public const uint FPS_ANSWERED = 0x20800000;

        public const uint FPF_RECEIVE = 0x00000001;

        public const uint FPF_SEND = 0x00000002;

        public const uint FPF_VIRTUAL = 0x00000004;

        public const uint FEI_DIALING = 0x00000001;

        public const uint FEI_SENDING = 0x00000002;

        public const uint FEI_RECEIVING = 0x00000003;

        public const uint FEI_COMPLETED = 0x00000004;

        public const uint FEI_BUSY = 0x00000005;

        public const uint FEI_NO_ANSWER = 0x00000006;

        public const uint FEI_BAD_ADDRESS = 0x00000007;

        public const uint FEI_NO_DIAL_TONE = 0x00000008;

        public const uint FEI_DISCONNECTED = 0x00000009;

        public const uint FEI_FATAL_ERROR = 0x0000000a;

        public const uint FEI_NOT_FAX_CALL = 0x0000000b;

        public const uint FEI_CALL_DELAYED = 0x0000000c;

        public const uint FEI_CALL_BLACKLISTED = 0x0000000d;

        public const uint FEI_RINGING = 0x0000000e;

        public const uint FEI_ABORTING = 0x0000000f;

        public const uint FEI_ROUTING = 0x00000010;

        public const uint FEI_MODEM_POWERED_ON = 0x00000011;

        public const uint FEI_MODEM_POWERED_OFF = 0x00000012;

        public const uint FEI_IDLE = 0x00000013;

        public const uint FEI_FAXSVC_ENDED = 0x00000014;

        public const uint FEI_ANSWERED = 0x00000015;

        public const uint FEI_JOB_QUEUED = 0x00000016;

        public const uint FEI_DELETED = 0x00000017;

        public const uint FEI_INITIALIZING = 0x00000018;

        public const uint FEI_LINE_UNAVAILABLE = 0x00000019;

        public const uint FEI_HANDLED = 0x0000001a;

        public const uint FEI_FAXSVC_STARTED = 0x0000001b;

        public const uint FAX_JOB_SUBMIT = 0x0001;

        public const uint FAX_JOB_QUERY = 0x0002;

        public const uint FAX_CONFIG_QUERY = 0x0004;

        public const uint FAX_CONFIG_SET = 0x0008;

        public const uint FAX_PORT_QUERY = 0x0010;

        public const uint FAX_PORT_SET = 0x0020;

        public const uint FAX_JOB_MANAGE = 0x0040;

    }
}
