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


namespace Windows.Win32.Devices.Pwm
{
    public static partial class Apis
    {
        public static readonly Guid GUID_DEVINTERFACE_PWM_CONTROLLER__scanned__ = new Guid(0x60824b4c, 0xeed1, 0x4c9c, 0xb4, 0x9c, 0x1b, 0x96, 0x14, 0x61, 0xa8, 0x19);

        public const uint IOCTL_PWM_CONTROLLER_GET_INFO = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((PWM_IOCTL_ID_CONTROLLER_GET_INFO) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PWM_CONTROLLER_GET_ACTUAL_PERIOD = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((PWM_IOCTL_ID_CONTROLLER_GET_ACTUAL_PERIOD) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PWM_CONTROLLER_SET_DESIRED_PERIOD = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((PWM_IOCTL_ID_CONTROLLER_SET_DESIRED_PERIOD) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PWM_PIN_GET_ACTIVE_DUTY_CYCLE_PERCENTAGE = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((PWM_IOCTL_ID_PIN_GET_ACTIVE_DUTY_CYCLE_PERCENTAGE) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PWM_PIN_SET_ACTIVE_DUTY_CYCLE_PERCENTAGE = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((PWM_IOCTL_ID_PIN_SET_ACTIVE_DUTY_CYCLE_PERCENTAGE) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PWM_PIN_GET_POLARITY = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((PWM_IOCTL_ID_PIN_GET_POLARITY) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PWM_PIN_SET_POLARITY = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((PWM_IOCTL_ID_PIN_SET_POLARITY) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PWM_PIN_START = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((PWM_IOCTL_ID_PIN_START) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_PWM_PIN_STOP = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_WRITE_DATA)) << 14) | ((PWM_IOCTL_ID_PIN_STOP) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_PWM_PIN_IS_STARTED = ((FILE_DEVICE_CONTROLLER) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((PWM_IOCTL_ID_PIN_IS_STARTED) << 2) | (METHOD_BUFFERED);

    }
}
