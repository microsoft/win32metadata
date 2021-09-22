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


namespace Windows.Win32.System.AddressBook
{
    public static partial class Apis
    {
        public const uint PROP_ID_SECURE_MIN = 0x67F0;

        public const uint PROP_ID_SECURE_MAX = 0x67FF;

        public const uint MAPI_DIM = 1;

        public const uint MAPI_P1 = 0x10000000;

        public const uint MAPI_SUBMITTED = 0x80000000;

        public const uint MAPI_SHORTTERM = 0x80;

        public const uint MAPI_NOTRECIP = 0x40;

        public const uint MAPI_THISSESSION = 0x20;

        public const uint MAPI_NOW = 0x10;

        public const uint MAPI_NOTRESERVED = 0x08;

        public const uint MAPI_COMPOUND = 0x80;

        public const uint MV_FLAG = 0x1000;

        public const uint PROP_ID_NULL = 0;

        public const uint PROP_ID_INVALID = 0xFFFF;

        public const uint MV_INSTANCE = 0x2000;

        public const uint TABLE_CHANGED = 1;

        public const uint TABLE_ERROR = 2;

        public const uint TABLE_ROW_ADDED = 3;

        public const uint TABLE_ROW_DELETED = 4;

        public const uint TABLE_ROW_MODIFIED = 5;

        public const uint TABLE_SORT_DONE = 6;

        public const uint TABLE_RESTRICT_DONE = 7;

        public const uint TABLE_SETCOL_DONE = 8;

        public const uint TABLE_RELOAD = 9;

        public const int MAPI_ERROR_VERSION = 0x00000000;

        public const uint MAPI_USE_DEFAULT = 0x00000040;

        public const uint MNID_ID = 0;

        public const uint MNID_STRING = 1;

        public const uint WAB_LOCAL_CONTAINERS = 0x00100000;

        public const uint WAB_PROFILE_CONTENTS = 0x00200000;

        public const uint WAB_IGNORE_PROFILES = 0x00800000;

        public const uint MAPI_ONE_OFF_NO_RICH_INFO = 0x0001;

        public const uint UI_SERVICE = 0x00000002;

        public const uint SERVICE_UI_ALWAYS = 0x00000002;

        public const uint SERVICE_UI_ALLOWED = 0x00000010;

        public const uint UI_CURRENT_PROVIDER_FIRST = 0x00000004;

        public const uint WABOBJECT_LDAPURL_RETURN_MAILUSER = 0x00000001;

        public const uint WABOBJECT_ME_NEW = 0x00000001;

        public const uint WABOBJECT_ME_NOCREATE = 0x00000002;

        public const uint WAB_VCARD_FILE = 0x00000000;

        public const uint WAB_VCARD_STREAM = 0x00000001;

        public const uint WAB_USE_OE_SENDMAIL = 0x00000001;

        public const uint WAB_ENABLE_PROFILES = 0x00400000;

        public const uint WAB_DISPLAY_LDAPURL = 0x00000001;

        public const uint WAB_CONTEXT_ADRLIST = 0x00000002;

        public const uint WAB_DISPLAY_ISNTDS = 0x00000004;

        public static readonly Guid IID_IWABExtInit__scanned__ = new Guid(0xea22ebf0, 0x87a4, 0x11d1, 0x9a, 0xcf, 0x0, 0xa0, 0xc9, 0x1f, 0x9c, 0x8b);

    }
}
