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


namespace Windows.Win32.System.TaskScheduler
{
    public static partial class Apis
    {
        public const uint TASK_SUNDAY = 0x1;

        public const uint TASK_MONDAY = 0x2;

        public const uint TASK_TUESDAY = 0x4;

        public const uint TASK_WEDNESDAY = 0x8;

        public const uint TASK_THURSDAY = 0x10;

        public const uint TASK_FRIDAY = 0x20;

        public const uint TASK_SATURDAY = 0x40;

        public const uint TASK_FIRST_WEEK = 1;

        public const uint TASK_SECOND_WEEK = 2;

        public const uint TASK_THIRD_WEEK = 3;

        public const uint TASK_FOURTH_WEEK = 4;

        public const uint TASK_LAST_WEEK = 5;

        public const uint TASK_JANUARY = 0x1;

        public const uint TASK_FEBRUARY = 0x2;

        public const uint TASK_MARCH = 0x4;

        public const uint TASK_APRIL = 0x8;

        public const uint TASK_MAY = 0x10;

        public const uint TASK_JUNE = 0x20;

        public const uint TASK_JULY = 0x40;

        public const uint TASK_AUGUST = 0x80;

        public const uint TASK_SEPTEMBER = 0x100;

        public const uint TASK_OCTOBER = 0x200;

        public const uint TASK_NOVEMBER = 0x400;

        public const uint TASK_DECEMBER = 0x800;

        public const uint TASK_FLAG_INTERACTIVE = 0x1;

        public const uint TASK_FLAG_DELETE_WHEN_DONE = 0x2;

        public const uint TASK_FLAG_DISABLED = 0x4;

        public const uint TASK_FLAG_START_ONLY_IF_IDLE = 0x10;

        public const uint TASK_FLAG_KILL_ON_IDLE_END = 0x20;

        public const uint TASK_FLAG_DONT_START_IF_ON_BATTERIES = 0x40;

        public const uint TASK_FLAG_KILL_IF_GOING_ON_BATTERIES = 0x80;

        public const uint TASK_FLAG_RUN_ONLY_IF_DOCKED = 0x100;

        public const uint TASK_FLAG_HIDDEN = 0x200;

        public const uint TASK_FLAG_RUN_IF_CONNECTED_TO_INTERNET = 0x400;

        public const uint TASK_FLAG_RESTART_ON_IDLE_RESUME = 0x800;

        public const uint TASK_FLAG_SYSTEM_REQUIRED = 0x1000;

        public const uint TASK_FLAG_RUN_ONLY_IF_LOGGED_ON = 0x2000;

        public const uint TASK_TRIGGER_FLAG_HAS_END_DATE = 0x1;

        public const uint TASK_TRIGGER_FLAG_KILL_AT_DURATION_END = 0x2;

        public const uint TASK_TRIGGER_FLAG_DISABLED = 0x4;

        public const uint TASK_MAX_RUN_TIMES = 1440;

        public static readonly Guid CLSID_CTask__scanned__ = new Guid(0x148BD520, 0xA2AB, 0x11CE, 0xB1, 0x1F, 0x00, 0xAA, 0x00, 0x53, 0x05, 0x03);

        public static readonly Guid CLSID_CTaskScheduler__scanned__ = new Guid(0x148BD52A, 0xA2AB, 0x11CE, 0xB1, 0x1F, 0x00, 0xAA, 0x00, 0x53, 0x05, 0x03);

    }
}
