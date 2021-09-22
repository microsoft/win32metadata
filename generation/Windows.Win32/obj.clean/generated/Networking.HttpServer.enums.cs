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


using static Windows.Win32.Networking.HttpServer.Apis;

namespace Windows.Win32.Networking.HttpServer
{
    public enum HTTP_RECEIVE_HTTP_REQUEST_FLAGS : uint
    {
        HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY = 0x00000001,
        HTTP_RECEIVE_REQUEST_FLAG_FLUSH_BODY = 0x00000002,
    }

    [Flags]
    public enum HTTP_INITIALIZE : uint
    {
        HTTP_INITIALIZE_CONFIG = 0x00000002,
        HTTP_INITIALIZE_SERVER = 0x00000001,
    }

}
