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


namespace Windows.Win32.Storage.Xps.Printing
{
    public static partial class Apis
    {
        public static readonly Guid ID_DOCUMENTPACKAGETARGET_MSXPS__scanned__ = new Guid(0x9cae40a8, 0xded1, 0x41c9, 0xa9, 0xfd, 0xd7, 0x35, 0xef, 0x33, 0xae, 0xda);

        public static readonly Guid ID_DOCUMENTPACKAGETARGET_OPENXPS__scanned__ = new Guid(0x0056bb72, 0x8c9c, 0x4612, 0xbd, 0x0f, 0x93, 0x01, 0x2a, 0x87, 0x09, 0x9d);

        public static readonly Guid ID_DOCUMENTPACKAGETARGET_OPENXPS_WITH_3D__scanned__ = new Guid(0x63dbd720, 0x8b14, 0x4577, 0xb0, 0x74, 0x7b, 0xb1, 0x1b, 0x59, 0x6d, 0x28);

    }
}
