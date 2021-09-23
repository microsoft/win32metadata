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


namespace Windows.Win32.Graphics.Dwm
{
    public static partial class Apis
    {
        public const uint DWM_BB_ENABLE = 0x00000001;

        public const uint DWM_BB_BLURREGION = 0x00000002;

        public const uint DWM_BB_TRANSITIONONMAXIMIZED = 0x00000004;

        public const uint DWM_CLOAKED_APP = 0x00000001;

        public const uint DWM_CLOAKED_SHELL = 0x00000002;

        public const uint DWM_CLOAKED_INHERITED = 0x00000004;

        public const uint DWM_TNP_RECTDESTINATION = 0x00000001;

        public const uint DWM_TNP_RECTSOURCE = 0x00000002;

        public const uint DWM_TNP_OPACITY = 0x00000004;

        public const uint DWM_TNP_VISIBLE = 0x00000008;

        public const uint DWM_TNP_SOURCECLIENTAREAONLY = 0x00000010;

        public const int DWM_FRAME_DURATION_DEFAULT = -1;

        public const uint DWM_EC_DISABLECOMPOSITION = 0;

        public const uint DWM_EC_ENABLECOMPOSITION = 1;

        public const uint DWM_SIT_DISPLAYFRAME = 0x00000001;

    }
}
