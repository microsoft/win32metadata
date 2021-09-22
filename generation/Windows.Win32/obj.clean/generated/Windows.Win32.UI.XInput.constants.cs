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


namespace Windows.Win32.UI.XInput
{
    public static partial class Apis
    {
        public const uint XINPUT_DEVTYPE_GAMEPAD = 0x01;

        public const uint XINPUT_DEVSUBTYPE_GAMEPAD = 0x01;

        public const uint XINPUT_DEVSUBTYPE_UNKNOWN = 0x00;

        public const uint XINPUT_DEVSUBTYPE_WHEEL = 0x02;

        public const uint XINPUT_DEVSUBTYPE_ARCADE_STICK = 0x03;

        public const uint XINPUT_DEVSUBTYPE_FLIGHT_STICK = 0x04;

        public const uint XINPUT_DEVSUBTYPE_DANCE_PAD = 0x05;

        public const uint XINPUT_DEVSUBTYPE_GUITAR = 0x06;

        public const uint XINPUT_DEVSUBTYPE_GUITAR_ALTERNATE = 0x07;

        public const uint XINPUT_DEVSUBTYPE_DRUM_KIT = 0x08;

        public const uint XINPUT_DEVSUBTYPE_GUITAR_BASS = 0x0B;

        public const uint XINPUT_DEVSUBTYPE_ARCADE_PAD = 0x13;

        public const uint XINPUT_CAPS_VOICE_SUPPORTED = 0x0004;

        public const uint XINPUT_CAPS_FFB_SUPPORTED = 0x0001;

        public const uint XINPUT_CAPS_WIRELESS = 0x0002;

        public const uint XINPUT_CAPS_PMD_SUPPORTED = 0x0008;

        public const uint XINPUT_CAPS_NO_NAVIGATION = 0x0010;

        public const uint XINPUT_GAMEPAD_DPAD_UP = 0x0001;

        public const uint XINPUT_GAMEPAD_DPAD_DOWN = 0x0002;

        public const uint XINPUT_GAMEPAD_DPAD_LEFT = 0x0004;

        public const uint XINPUT_GAMEPAD_DPAD_RIGHT = 0x0008;

        public const uint XINPUT_GAMEPAD_START = 0x0010;

        public const uint XINPUT_GAMEPAD_BACK = 0x0020;

        public const uint XINPUT_GAMEPAD_LEFT_THUMB = 0x0040;

        public const uint XINPUT_GAMEPAD_RIGHT_THUMB = 0x0080;

        public const uint XINPUT_GAMEPAD_LEFT_SHOULDER = 0x0100;

        public const uint XINPUT_GAMEPAD_RIGHT_SHOULDER = 0x0200;

        public const uint XINPUT_GAMEPAD_A = 0x1000;

        public const uint XINPUT_GAMEPAD_B = 0x2000;

        public const uint XINPUT_GAMEPAD_X = 0x4000;

        public const uint XINPUT_GAMEPAD_Y = 0x8000;

        public const uint XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE = 7849;

        public const uint XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE = 8689;

        public const uint XINPUT_GAMEPAD_TRIGGER_THRESHOLD = 30;

        public const uint XINPUT_FLAG_GAMEPAD = 0x00000001;

        public const uint BATTERY_DEVTYPE_GAMEPAD = 0x00;

        public const uint BATTERY_DEVTYPE_HEADSET = 0x01;

        public const uint BATTERY_TYPE_DISCONNECTED = 0x00;

        public const uint BATTERY_TYPE_WIRED = 0x01;

        public const uint BATTERY_TYPE_ALKALINE = 0x02;

        public const uint BATTERY_TYPE_NIMH = 0x03;

        public const uint BATTERY_TYPE_UNKNOWN = 0xFF;

        public const uint BATTERY_LEVEL_EMPTY = 0x00;

        public const uint BATTERY_LEVEL_LOW = 0x01;

        public const uint BATTERY_LEVEL_MEDIUM = 0x02;

        public const uint BATTERY_LEVEL_FULL = 0x03;

        public const uint XUSER_MAX_COUNT = 4;

        public const uint XUSER_INDEX_ANY = 0x000000FF;

        public const uint XINPUT_KEYSTROKE_KEYDOWN = 0x0001;

        public const uint XINPUT_KEYSTROKE_KEYUP = 0x0002;

        public const uint XINPUT_KEYSTROKE_REPEAT = 0x0004;

    }
}
