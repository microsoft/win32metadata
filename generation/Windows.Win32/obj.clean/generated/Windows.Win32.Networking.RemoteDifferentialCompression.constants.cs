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


namespace Windows.Win32.Networking.RemoteDifferentialCompression
{
    public static partial class Apis
    {
        public const uint RDCE_TABLE_FULL = 0x80040001;

        public const uint RDCE_TABLE_CORRUPT = 0x80040002;

        public const uint MSRDC_SIGNATURE_HASHSIZE = 16;

        public const uint SimilarityFileIdMinSize = 4;

        public const uint SimilarityFileIdMaxSize = 32;

    }
}