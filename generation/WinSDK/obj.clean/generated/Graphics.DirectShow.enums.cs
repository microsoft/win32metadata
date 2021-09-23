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


using static Windows.Win32.Graphics.DirectShow.Apis;

namespace Windows.Win32.Graphics.DirectShow
{
    public enum OA_BOOL
    {
        OATRUE = -1,
        OAFALSE = 0,
    }

    [Flags]
    public enum MPEG2VIDEOINFO_FLAGS : uint
    {
        AMMPEG2_DoPanScan = 1,
        AMMPEG2_DVDLine21Field1 = 2,
        AMMPEG2_DVDLine21Field2 = 4,
        AMMPEG2_SourceIsLetterboxed = 8,
        AMMPEG2_FilmCameraMode = 16,
        AMMPEG2_LetterboxAnalogOut = 32,
        AMMPEG2_DSS_UserData = 64,
        AMMPEG2_DVB_UserData = 128,
        AMMPEG2_27MhzTimebase = 256,
        AMMPEG2_WidescreenAnalogOut = 512,
    }

    public enum MPEGLAYER3WAVEFORMAT_FLAGS : uint
    {
        MPEGLAYER3_FLAG_PADDING_ISO = 0,
        MPEGLAYER3_FLAG_PADDING_ON = 1,
        MPEGLAYER3_FLAG_PADDING_OFF = 2,
    }

}
