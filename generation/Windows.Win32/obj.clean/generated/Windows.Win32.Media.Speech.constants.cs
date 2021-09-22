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


namespace Windows.Win32.Media.Speech
{
    public static partial class Apis
    {
        public const int SP_LOW_CONFIDENCE = -1;

        public const uint SP_NORMAL_CONFIDENCE = 0;

        public const uint DEFAULT_WEIGHT = 1;

        public const uint SP_MAX_WORD_LENGTH = 128;

        public const uint SP_MAX_PRON_LENGTH = 384;

        public const uint SP_EMULATE_RESULT = 0x40000000;

        public const uint SP_STREAMPOS_ASAP = 0;

        public const int SP_STREAMPOS_REALTIME = -1;

        public const uint SPRP_NORMAL = 0;

        public const uint SP_MAX_LANGIDS = 20;

    }
}
