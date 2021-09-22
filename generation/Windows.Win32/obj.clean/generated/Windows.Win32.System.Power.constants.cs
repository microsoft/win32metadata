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


namespace Windows.Win32.System.Power
{
    public static partial class Apis
    {
        [PropertyKey(0x5724c81d,                  0xd5af,                  0x4c1f,                  0xa1, 0x03, 0xa0, 0x6e, 0x28, 0xf2, 0x04, 0xc6,                  1)]
        public static readonly PROPERTYKEY PROCESSOR_NUMBER_PKEY;

        public static readonly Guid GUID_DEVICE_BATTERY__scanned__ = new Guid(0x72631e54L, 0x78A4, 0x11d0, 0xbc, 0xf7, 0x00, 0xaa, 0x00, 0xb7, 0xb3, 0x2a );

        public static readonly Guid GUID_DEVICE_APPLICATIONLAUNCH_BUTTON__scanned__ = new Guid(0x629758eel, 0x986e, 0x4d9e, 0x8e, 0x47, 0xde, 0x27, 0xf8, 0xab, 0x05, 0x4d );

        public static readonly Guid GUID_DEVICE_SYS_BUTTON__scanned__ = new Guid(0x4AFA3D53L, 0x74A7, 0x11d0, 0xbe, 0x5e, 0x00, 0xA0, 0xC9, 0x06, 0x28, 0x57 );

        public static readonly Guid GUID_DEVICE_LID__scanned__ = new Guid(0x4AFA3D52L, 0x74A7, 0x11d0, 0xbe, 0x5e, 0x00, 0xA0, 0xC9, 0x06, 0x28, 0x57 );

        public static readonly Guid GUID_DEVICE_THERMAL_ZONE__scanned__ = new Guid(0x4AFA3D51L, 0x74A7, 0x11d0, 0xbe, 0x5e, 0x00, 0xA0, 0xC9, 0x06, 0x28, 0x57 );

        public static readonly Guid GUID_DEVICE_FAN__scanned__ = new Guid(0x05ecd13dL, 0x81da, 0x4a2a, 0x8a, 0x4c, 0x52, 0x4f, 0x23, 0xdd, 0x4d, 0xc9 );

        public static readonly Guid GUID_DEVICE_PROCESSOR__scanned__ = new Guid(0x97fadb10L, 0x4e33, 0x40ae, 0x35, 0x9c, 0x8b, 0xef, 0x02, 0x9d, 0xbd, 0xd0 );

        public static readonly Guid GUID_DEVICE_MEMORY__scanned__ = new Guid(0x3fd0f03dL, 0x92e0, 0x45fb, 0xb7, 0x5c, 0x5e, 0xd8, 0xff, 0xb0, 0x10, 0x21 );

        public static readonly Guid GUID_DEVICE_ACPI_TIME__scanned__ = new Guid(0x97f99bf6L, 0x4497, 0x4f18, 0xbb, 0x22, 0x4b, 0x9f, 0xb2, 0xfb, 0xef, 0x9c );

        public static readonly Guid GUID_DEVICE_MESSAGE_INDICATOR__scanned__ = new Guid(0XCD48A365L, 0xfa94, 0x4ce2, 0xa2, 0x32, 0xa1, 0xb7, 0x64, 0xe5, 0xd8, 0xb4 );

        public static readonly Guid GUID_CLASS_INPUT__scanned__ = new Guid(0x4D1E55B2L, 0xF16F, 0x11CF, 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 );

        public static readonly Guid GUID_DEVINTERFACE_THERMAL_COOLING__scanned__ = new Guid(0xdbe4373d, 0x3c81, 0x40cb, 0xac, 0xe4, 0xe0, 0xe5, 0xd0, 0x5f, 0xc, 0x9f);

        public const uint BATTERY_UNKNOWN_CAPACITY = 0xFFFFFFFF;

        public const uint BATTERY_SYSTEM_BATTERY = 0x80000000;

        public const uint BATTERY_CAPACITY_RELATIVE = 0x40000000;

        public const uint BATTERY_IS_SHORT_TERM = 0x20000000;

        public const uint BATTERY_SEALED = 0x10000000;

        public const uint BATTERY_SET_CHARGE_SUPPORTED = 0x00000001;

        public const uint BATTERY_SET_DISCHARGE_SUPPORTED = 0x00000002;

        public const uint BATTERY_SET_CHARGINGSOURCE_SUPPORTED = 0x00000004;

        public const uint BATTERY_SET_CHARGER_ID_SUPPORTED = 0x00000008;

        public const uint BATTERY_UNKNOWN_TIME = 0xFFFFFFFF;

        public const uint BATTERY_UNKNOWN_CURRENT = 0xFFFFFFFF;

        public const uint BATTERY_USB_CHARGER_STATUS_FN_DEFAULT_USB = 0x00000001;

        public const uint BATTERY_USB_CHARGER_STATUS_UCM_PD = 0x00000002;

        public const uint BATTERY_UNKNOWN_VOLTAGE = 0xFFFFFFFF;

        public const uint BATTERY_UNKNOWN_RATE = 0x80000000;

        public const uint BATTERY_POWER_ON_LINE = 0x00000001;

        public const uint BATTERY_DISCHARGING = 0x00000002;

        public const uint BATTERY_CHARGING = 0x00000004;

        public const uint BATTERY_CRITICAL = 0x00000008;

        public const uint MAX_BATTERY_STRING_SIZE = 128;

        public const uint IOCTL_BATTERY_QUERY_TAG = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x10) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_BATTERY_QUERY_INFORMATION = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x11) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_BATTERY_SET_INFORMATION = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x12) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_BATTERY_QUERY_STATUS = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x13) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_BATTERY_CHARGING_SOURCE_CHANGE = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x14) << 2) | (METHOD_BUFFERED);

        public const uint BATTERY_TAG_INVALID = 0;

        public const uint MAX_ACTIVE_COOLING_LEVELS = 10;

        public const uint ACTIVE_COOLING = 0x0;

        public const uint PASSIVE_COOLING = 0x1;

        public const uint TZ_ACTIVATION_REASON_THERMAL = 0x00000001;

        public const uint TZ_ACTIVATION_REASON_CURRENT = 0x00000002;

        public const uint THERMAL_POLICY_VERSION_1 = 1;

        public const uint THERMAL_POLICY_VERSION_2 = 2;

        public const uint IOCTL_THERMAL_QUERY_INFORMATION = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x20) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_THERMAL_SET_COOLING_POLICY = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x21) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_RUN_ACTIVE_COOLING_METHOD = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x22) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_THERMAL_SET_PASSIVE_LIMIT = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x23) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_THERMAL_READ_TEMPERATURE = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x24) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_THERMAL_READ_POLICY = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x25) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_QUERY_LID = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x30) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_NOTIFY_SWITCH_EVENT = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x40) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_GET_SYS_BUTTON_CAPS = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x50) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_GET_SYS_BUTTON_EVENT = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x51) << 2) | (METHOD_BUFFERED);

        public const uint SYS_BUTTON_POWER = 0x00000001;

        public const uint SYS_BUTTON_SLEEP = 0x00000002;

        public const uint SYS_BUTTON_LID = 0x00000004;

        public const uint SYS_BUTTON_WAKE = 0x80000000;

        public const uint SYS_BUTTON_LID_STATE_MASK = 0x00030000;

        public const uint SYS_BUTTON_LID_OPEN = 0x00010000;

        public const uint SYS_BUTTON_LID_CLOSED = 0x00020000;

        public const uint SYS_BUTTON_LID_INITIAL = 0x00040000;

        public const uint SYS_BUTTON_LID_CHANGED = 0x00080000;

        public const uint IOCTL_GET_PROCESSOR_OBJ_INFO = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x60) << 2) | (METHOD_BUFFERED);

        public const uint THERMAL_COOLING_INTERFACE_VERSION = 1;

        public const uint THERMAL_DEVICE_INTERFACE_VERSION = 1;

        public const uint IOCTL_SET_SYS_MESSAGE_INDICATOR = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x70) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SET_WAKE_ALARM_VALUE = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x80) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SET_WAKE_ALARM_POLICY = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x81) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_GET_WAKE_ALARM_VALUE = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x82) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_GET_WAKE_ALARM_POLICY = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x83) << 2) | (METHOD_BUFFERED);

        public const uint ACPI_TIME_ADJUST_DAYLIGHT = 0x01;

        public const uint ACPI_TIME_IN_DAYLIGHT = 0x02;

        public const uint ACPI_TIME_ZONE_UNKNOWN = 0x7FF;

        public const uint IOCTL_ACPI_GET_REAL_TIME = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((0x84) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_ACPI_SET_REAL_TIME = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x85) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_GET_WAKE_ALARM_SYSTEM_POWERSTATE = ((FILE_DEVICE_BATTERY) << 16) | (uint)(((int)(FILE_READ_DATA)) << 14) | ((0x86) << 2) | (METHOD_BUFFERED);

        public const uint EFFECTIVE_POWER_MODE_V1 = 0x00000001;

        public const uint EFFECTIVE_POWER_MODE_V2 = 0x00000002;

        public const uint EnableSysTrayBatteryMeter = 0x01;

        public const uint EnableMultiBatteryDisplay = 0x02;

        public const uint EnablePasswordLogon = 0x04;

        public const uint EnableWakeOnRing = 0x08;

        public const uint EnableVideoDimDisplay = 0x10;

        public const uint POWER_ATTRIBUTE_HIDE = 0x00000001;

        public const uint POWER_ATTRIBUTE_SHOW_AOAC = 0x00000002;

        public const uint DEVICEPOWER_HARDWAREID = 0x80000000;

        public const uint DEVICEPOWER_AND_OPERATION = 0x40000000;

        public const uint DEVICEPOWER_FILTER_DEVICES_PRESENT = 0x20000000;

        public const uint DEVICEPOWER_FILTER_HARDWARE = 0x10000000;

        public const uint DEVICEPOWER_FILTER_WAKEENABLED = 0x08000000;

        public const uint DEVICEPOWER_FILTER_WAKEPROGRAMMABLE = 0x04000000;

        public const uint DEVICEPOWER_FILTER_ON_NAME = 0x02000000;

        public const uint DEVICEPOWER_SET_WAKEENABLED = 0x00000001;

        public const uint DEVICEPOWER_CLEAR_WAKEENABLED = 0x00000002;

        public const uint PDCAP_S0_SUPPORTED = 0x00010000;

        public const uint PDCAP_S1_SUPPORTED = 0x00020000;

        public const uint PDCAP_S2_SUPPORTED = 0x00040000;

        public const uint PDCAP_S3_SUPPORTED = 0x00080000;

        public const uint PDCAP_WAKE_FROM_S0_SUPPORTED = 0x00100000;

        public const uint PDCAP_WAKE_FROM_S1_SUPPORTED = 0x00200000;

        public const uint PDCAP_WAKE_FROM_S2_SUPPORTED = 0x00400000;

        public const uint PDCAP_WAKE_FROM_S3_SUPPORTED = 0x00800000;

        public const uint PDCAP_S4_SUPPORTED = 0x01000000;

        public const uint PDCAP_S5_SUPPORTED = 0x02000000;

        public const uint THERMAL_EVENT_VERSION = 1;

    }
}
