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


namespace Windows.Win32.NetworkManagement.InternetConnectionWizard
{
    public static partial class Apis
    {
        public const uint ICW_MAX_ACCTNAME = 256;

        public const uint ICW_MAX_PASSWORD = 256;

        public const uint ICW_MAX_LOGONNAME = 256;

        public const uint ICW_MAX_SERVERNAME = 64;

        public const uint ICW_MAX_RASNAME = 256;

        public const uint ICW_MAX_EMAILNAME = 64;

        public const uint ICW_MAX_EMAILADDR = 128;

        public const uint ICW_CHECKSTATUS = 0x0001;

        public const uint ICW_LAUNCHFULL = 0x0100;

        public const uint ICW_LAUNCHMANUAL = 0x0200;

        public const uint ICW_USE_SHELLNEXT = 0x0400;

        public const uint ICW_FULL_SMARTSTART = 0x0800;

        public const uint ICW_FULLPRESENT = 0x0001;

        public const uint ICW_MANUALPRESENT = 0x0002;

        public const uint ICW_ALREADYRUN = 0x0004;

        public const uint ICW_LAUNCHEDFULL = 0x0100;

        public const uint ICW_LAUNCHEDMANUAL = 0x0200;

        public const uint ICW_USEDEFAULTS = 0x0001;

    }
}
