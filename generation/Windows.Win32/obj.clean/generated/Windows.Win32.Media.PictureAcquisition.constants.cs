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


namespace Windows.Win32.Media.PictureAcquisition
{
    public static partial class Apis
    {
        public const int PROGRESS_INDETERMINATE = -1;

        [NativeTypeName("HRESULT")]
        public const int PHOTOACQ_ERROR_RESTART_REQUIRED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA001));

        public const uint PHOTOACQ_RUN_DEFAULT = 0x00000000;

        public const uint PHOTOACQ_NO_GALLERY_LAUNCH = 0x00000001;

        public const uint PHOTOACQ_DISABLE_AUTO_ROTATE = 0x00000002;

        public const uint PHOTOACQ_DISABLE_PLUGINS = 0x00000004;

        public const uint PHOTOACQ_DISABLE_GROUP_TAG_PROMPT = 0x00000008;

        public const uint PHOTOACQ_DISABLE_DB_INTEGRATION = 0x00000010;

        public const uint PHOTOACQ_DELETE_AFTER_ACQUIRE = 0x00000020;

        public const uint PHOTOACQ_DISABLE_DUPLICATE_DETECTION = 0x00000040;

        public const uint PHOTOACQ_ENABLE_THUMBNAIL_CACHING = 0x00000080;

        public const uint PHOTOACQ_DISABLE_METADATA_WRITE = 0x00000100;

        public const uint PHOTOACQ_DISABLE_THUMBNAIL_PROGRESS = 0x00000200;

        public const uint PHOTOACQ_DISABLE_SETTINGS_LINK = 0x00000400;

        public const uint PHOTOACQ_ABORT_ON_SETTINGS_UPDATE = 0x00000800;

        public const uint PHOTOACQ_IMPORT_VIDEO_AS_MULTIPLE_FILES = 0x00001000;

        public const uint DSF_WPD_DEVICES = 0x00000001;

        public const uint DSF_WIA_CAMERAS = 0x00000002;

        public const uint DSF_WIA_SCANNERS = 0x00000004;

        public const uint DSF_STI_DEVICES = 0x00000008;

        public const uint DSF_TWAIN_DEVICES = 0x00000010;

        public const uint DSF_FS_DEVICES = 0x00000020;

        public const uint DSF_DV_DEVICES = 0x00000040;

        public const uint DSF_ALL_DEVICES = 0x0000FFFF;

        public const uint DSF_CPL_MODE = 0x00010000;

        public const uint DSF_SHOW_OFFLINE = 0x00020000;

        public const uint PAPS_PRESAVE = 0x00000000;

        public const uint PAPS_POSTSAVE = 0x00000001;

        public const uint PAPS_CLEANUP = 0x00000002;

    }
}
