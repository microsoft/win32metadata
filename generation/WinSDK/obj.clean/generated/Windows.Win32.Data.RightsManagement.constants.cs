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


namespace Windows.Win32.Data.RightsManagement
{
    public static partial class Apis
    {
        public const uint DRMHANDLE_INVALID = 0;

        public const uint DRMENVHANDLE_INVALID = 0;

        public const uint DRMQUERYHANDLE_INVALID = 0;

        public const uint DRMHSESSION_INVALID = 0;

        public const uint DRMPUBHANDLE_INVALID = 0;

        public const uint DRM_AL_NONSILENT = 0x01;

        public const uint DRM_AL_NOPERSIST = 0x02;

        public const uint DRM_AL_CANCEL = 0x04;

        public const uint DRM_AL_FETCHNOADVISORY = 0x08;

        public const uint DRM_AL_NOUI = 0x10;

        public const uint DRM_ACTIVATE_MACHINE = 0x01;

        public const uint DRM_ACTIVATE_GROUPIDENTITY = 0x02;

        public const uint DRM_ACTIVATE_TEMPORARY = 0x04;

        public const uint DRM_ACTIVATE_CANCEL = 0x08;

        public const uint DRM_ACTIVATE_SILENT = 0x10;

        public const uint DRM_ACTIVATE_SHARED_GROUPIDENTITY = 0x20;

        public const uint DRM_ACTIVATE_DELAYED = 0x40;

        public const uint DRM_EL_MACHINE = 0x0001;

        public const uint DRM_EL_GROUPIDENTITY = 0x0002;

        public const uint DRM_EL_GROUPIDENTITY_NAME = 0x0004;

        public const uint DRM_EL_GROUPIDENTITY_LID = 0x0008;

        public const uint DRM_EL_SPECIFIED_GROUPIDENTITY = 0x0010;

        public const uint DRM_EL_EUL = 0x0020;

        public const uint DRM_EL_EUL_LID = 0x0040;

        public const uint DRM_EL_CLIENTLICENSOR = 0x0080;

        public const uint DRM_EL_CLIENTLICENSOR_LID = 0x0100;

        public const uint DRM_EL_SPECIFIED_CLIENTLICENSOR = 0x0200;

        public const uint DRM_EL_REVOCATIONLIST = 0x0400;

        public const uint DRM_EL_REVOCATIONLIST_LID = 0x0800;

        public const uint DRM_EL_EXPIRED = 0x1000;

        public const uint DRM_EL_ISSUERNAME = 0x2000;

        public const uint DRM_EL_ISSUANCELICENSE_TEMPLATE = 0x4000;

        public const uint DRM_EL_ISSUANCELICENSE_TEMPLATE_LID = 0x8000;

        public const uint DRM_ADD_LICENSE_NOPERSIST = 0x00;

        public const uint DRM_ADD_LICENSE_PERSIST = 0x01;

        public const uint DRM_SERVICE_TYPE_ACTIVATION = 0x01;

        public const uint DRM_SERVICE_TYPE_CERTIFICATION = 0x02;

        public const uint DRM_SERVICE_TYPE_PUBLISHING = 0x04;

        public const uint DRM_SERVICE_TYPE_CLIENTLICENSOR = 0x08;

        public const uint DRM_SERVICE_TYPE_SILENT = 0x10;

        public const uint DRM_SERVICE_LOCATION_INTERNET = 0x01;

        public const uint DRM_SERVICE_LOCATION_ENTERPRISE = 0x02;

        public const uint DRM_SIGN_ONLINE = 0x01;

        public const uint DRM_SIGN_OFFLINE = 0x02;

        public const uint DRM_SIGN_CANCEL = 0x04;

        public const uint DRM_SERVER_ISSUANCELICENSE = 0x08;

        public const uint DRM_AUTO_GENERATE_KEY = 0x10;

        public const uint DRM_OWNER_LICENSE_NOPERSIST = 0x20;

        public const uint DRM_REUSE_KEY = 0x40;

        public const uint DRM_LOCKBOXTYPE_NONE = 0x00;

        public const uint DRM_LOCKBOXTYPE_WHITEBOX = 0x01;

        public const uint DRM_LOCKBOXTYPE_BLACKBOX = 0x02;

        public const uint DRM_AILT_NONSILENT = 0x01;

        public const uint DRM_AILT_OBTAIN_ALL = 0x02;

        public const uint DRM_AILT_CANCEL = 0x04;

    }
}
