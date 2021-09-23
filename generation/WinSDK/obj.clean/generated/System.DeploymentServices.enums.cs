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


using static Windows.Win32.System.DeploymentServices.Apis;

namespace Windows.Win32.System.DeploymentServices
{
    public enum CPU_ARCHITECTURE : uint
    {
        CPU_ARCHITECTURE_AMD64 = 9,
        CPU_ARCHITECTURE_IA64 = 6,
        CPU_ARCHITECTURE_INTEL = 0,
    }

    public enum PFN_WDS_CLI_CALLBACK_MESSAGE_ID : uint
    {
        WDS_CLI_MSG_START = 0,
        WDS_CLI_MSG_COMPLETE = 1,
        WDS_CLI_MSG_PROGRESS = 2,
        WDS_CLI_MSG_TEXT = 3,
    }

    public enum WDS_TRANSPORTCLIENT_REQUEST_AUTH_LEVEL : uint
    {
        WDS_TRANSPORTCLIENT_AUTH = 1,
        WDS_TRANSPORTCLIENT_NO_AUTH = 2,
    }

}
