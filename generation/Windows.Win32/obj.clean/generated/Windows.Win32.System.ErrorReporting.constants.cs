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


namespace Windows.Win32.System.ErrorReporting
{
    public static partial class Apis
    {
        public const uint WER_FAULT_REPORTING_NO_UI = 32;

        public const uint WER_FAULT_REPORTING_FLAG_NO_HEAP_ON_QUEUE = 64;

        public const uint WER_FAULT_REPORTING_DISABLE_SNAPSHOT_CRASH = 128;

        public const uint WER_FAULT_REPORTING_DISABLE_SNAPSHOT_HANG = 256;

        public const uint WER_FAULT_REPORTING_CRITICAL = 512;

        public const uint WER_FAULT_REPORTING_DURABLE = 1024;

        public const uint WER_MAX_TOTAL_PARAM_LENGTH = 1720;

        public const uint WER_MAX_PREFERRED_MODULES = 128;

        public const uint WER_MAX_PREFERRED_MODULES_BUFFER = 256;

        public const uint WER_P0 = 0;

        public const uint WER_P1 = 1;

        public const uint WER_P2 = 2;

        public const uint WER_P3 = 3;

        public const uint WER_P4 = 4;

        public const uint WER_P5 = 5;

        public const uint WER_P6 = 6;

        public const uint WER_P7 = 7;

        public const uint WER_P8 = 8;

        public const uint WER_P9 = 9;

        public const uint WER_FILE_COMPRESSED = 4;

        public const uint WER_SUBMIT_BYPASS_POWER_THROTTLING = 16384;

        public const uint WER_SUBMIT_BYPASS_NETWORK_COST_THROTTLING = 32768;

        public const uint WER_DUMP_MASK_START = 1;

        public const uint WER_DUMP_NOHEAP_ONQUEUE = 1;

        public const uint WER_DUMP_AUXILIARY = 2;

        public const uint WER_MAX_REGISTERED_ENTRIES = 512;

        public const uint WER_MAX_REGISTERED_METADATA = 8;

        public const uint WER_MAX_REGISTERED_DUMPCOLLECTION = 4;

        public const uint WER_METADATA_KEY_MAX_LENGTH = 64;

        public const uint WER_METADATA_VALUE_MAX_LENGTH = 128;

        public const uint WER_MAX_SIGNATURE_NAME_LENGTH = 128;

        public const uint WER_MAX_EVENT_NAME_LENGTH = 64;

        public const uint WER_MAX_PARAM_COUNT = 10;

        public const uint WER_MAX_FRIENDLY_EVENT_NAME_LENGTH = 128;

        public const uint WER_MAX_APPLICATION_NAME_LENGTH = 128;

        public const uint WER_MAX_DESCRIPTION_LENGTH = 512;

        public const uint WER_MAX_LOCAL_DUMP_SUBPATH_LENGTH = 64;

        public const uint WER_MAX_REGISTERED_RUNTIME_EXCEPTION_MODULES = 16;

    }
}
