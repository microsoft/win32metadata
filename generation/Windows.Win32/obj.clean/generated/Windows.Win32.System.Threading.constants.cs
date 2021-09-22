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


namespace Windows.Win32.System.Threading
{
    public static partial class Apis
    {
        public const uint PRIVATE_NAMESPACE_FLAG_DESTROY = 0x00000001;

        public const uint PROC_THREAD_ATTRIBUTE_REPLACE_VALUE = 0x00000001;

        public const uint THREAD_POWER_THROTTLING_CURRENT_VERSION = 1;

        public const uint THREAD_POWER_THROTTLING_EXECUTION_SPEED = 0x1;

        public const uint PME_CURRENT_VERSION = 1;

        public const uint PME_FAILFAST_ON_COMMIT_FAIL_DISABLE = 0x0;

        public const uint PME_FAILFAST_ON_COMMIT_FAIL_ENABLE = 0x1;

        public const uint PROCESS_POWER_THROTTLING_CURRENT_VERSION = 1;

        public const uint PROCESS_POWER_THROTTLING_EXECUTION_SPEED = 0x1;

        public const uint PROCESS_LEAP_SECOND_INFO_FLAG_ENABLE_SIXTY_SECOND = 0x1;

        public const uint CREATE_MUTEX_INITIAL_OWNER = 0x00000001;

        public const uint CREATE_WAITABLE_TIMER_MANUAL_RESET = 0x00000001;

        public const uint CREATE_WAITABLE_TIMER_HIGH_RESOLUTION = 0x00000002;

        public const uint SYNCHRONIZATION_BARRIER_FLAGS_SPIN_ONLY = 0x01;

        public const uint SYNCHRONIZATION_BARRIER_FLAGS_BLOCK_ONLY = 0x02;

        public const uint SYNCHRONIZATION_BARRIER_FLAGS_NO_DELETE = 0x04;

    }
}
