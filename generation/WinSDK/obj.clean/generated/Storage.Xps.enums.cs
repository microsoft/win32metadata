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


using static Windows.Win32.Storage.Xps.Apis;

namespace Windows.Win32.Storage.Xps
{
    public enum PRINT_WINDOW_FLAGS : uint
    {
        PW_CLIENTONLY = 0x00000001,
    }

    public enum DEVICE_CAPABILITIES : uint
    {
        DC_BINNAMES = 12,
        DC_BINS = 6,
        DC_COLLATE = 22,
        DC_COLORDEVICE = 32,
        DC_COPIES = 18,
        DC_DRIVER = 11,
        DC_DUPLEX = 7,
        DC_ENUMRESOLUTIONS = 13,
        DC_EXTRA = 9,
        DC_FIELDS = 1,
        DC_FILEDEPENDENCIES = 14,
        DC_MAXEXTENT = 5,
        DC_MEDIAREADY = 29,
        DC_MEDIATYPENAMES = 34,
        DC_MEDIATYPES = 35,
        DC_MINEXTENT = 4,
        DC_ORIENTATION = 17,
        DC_NUP = 33,
        DC_PAPERNAMES = 16,
        DC_PAPERS = 2,
        DC_PAPERSIZE = 3,
        DC_PERSONALITY = 25,
        DC_PRINTERMEM = 28,
        DC_PRINTRATE = 26,
        DC_PRINTRATEPPM = 31,
        DC_PRINTRATEUNIT = 27,
        DC_SIZE = 8,
        DC_STAPLE = 30,
        DC_TRUETYPE = 15,
        DC_VERSION = 10,
    }

}
