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


namespace Windows.Win32.System.Mmc
{
    public static partial class Apis
    {
        public const uint MMC_VER = 0x0200;

        public const uint MMC_PROP_CHANGEAFFECTSUI = 0x1;

        public const uint MMC_PROP_MODIFIABLE = 0x2;

        public const uint MMC_PROP_REMOVABLE = 0x4;

        public const uint MMC_PROP_PERSIST = 0x8;

        public const int MMCLV_AUTO = -1;

        public const int MMCLV_NOPARAM = -2;

        public const int MMCLV_NOICON = -1;

        public const uint MMCLV_VIEWSTYLE_ICON = 0;

        public const uint MMCLV_VIEWSTYLE_SMALLICON = 0x2;

        public const uint MMCLV_VIEWSTYLE_LIST = 0x3;

        public const uint MMCLV_VIEWSTYLE_REPORT = 0x1;

        public const uint MMCLV_VIEWSTYLE_FILTERED = 0x4;

        public const uint MMCLV_NOPTR = 0;

        public const uint MMCLV_UPDATE_NOINVALIDATEALL = 0x1;

        public const uint MMCLV_UPDATE_NOSCROLL = 0x2;

        public const int MMC_IMAGECALLBACK = -1;

        public const uint RDI_STR = 0x2;

        public const uint RDI_IMAGE = 0x4;

        public const uint RDI_STATE = 0x8;

        public const uint RDI_PARAM = 0x10;

        public const uint RDI_INDEX = 0x20;

        public const uint RDI_INDENT = 0x40;

        public const uint MMC_VIEW_OPTIONS_NONE = 0;

        public const uint MMC_VIEW_OPTIONS_NOLISTVIEWS = 0x1;

        public const uint MMC_VIEW_OPTIONS_MULTISELECT = 0x2;

        public const uint MMC_VIEW_OPTIONS_OWNERDATALIST = 0x4;

        public const uint MMC_VIEW_OPTIONS_FILTERED = 0x8;

        public const uint MMC_VIEW_OPTIONS_CREATENEW = 0x10;

        public const uint MMC_VIEW_OPTIONS_USEFONTLINKING = 0x20;

        public const uint MMC_VIEW_OPTIONS_EXCLUDE_SCOPE_ITEMS_FROM_LIST = 0x40;

        public const uint MMC_VIEW_OPTIONS_LEXICAL_SORT = 0x80;

        public const uint MMC_PSO_NOAPPLYNOW = 0x1;

        public const uint MMC_PSO_HASHELP = 0x2;

        public const uint MMC_PSO_NEWWIZARDTYPE = 0x4;

        public const uint MMC_PSO_NO_PROPTITLE = 0x8;

        public const uint RFI_PARTIAL = 0x1;

        public const uint RFI_WRAP = 0x2;

        public const uint RSI_DESCENDING = 0x1;

        public const uint RSI_NOSORTICON = 0x2;

        public const uint SDI_STR = 0x2;

        public const uint SDI_IMAGE = 0x4;

        public const uint SDI_OPENIMAGE = 0x8;

        public const uint SDI_STATE = 0x10;

        public const uint SDI_PARAM = 0x20;

        public const uint SDI_CHILDREN = 0x40;

        public const uint SDI_PARENT = 0;

        public const uint SDI_PREVIOUS = 0x10000000;

        public const uint SDI_NEXT = 0x20000000;

        public const uint SDI_FIRST = 0x8000000;

        public const int MMC_MULTI_SELECT_COOKIE = -2;

        public const int MMC_WINDOW_COOKIE = -3;

        public const int SPECIAL_COOKIE_MIN = -10;

        public const int SPECIAL_COOKIE_MAX = -1;

        public const uint MMC_NW_OPTION_NONE = 0;

        public const uint MMC_NW_OPTION_NOSCOPEPANE = 0x1;

        public const uint MMC_NW_OPTION_NOTOOLBARS = 0x2;

        public const uint MMC_NW_OPTION_SHORTTITLE = 0x4;

        public const uint MMC_NW_OPTION_CUSTOMTITLE = 0x8;

        public const uint MMC_NW_OPTION_NOPERSIST = 0x10;

        public const uint MMC_NW_OPTION_NOACTIONPANE = 0x20;

        public const uint MMC_NODEID_SLOW_RETRIEVAL = 0x1;

        public const int SPECIAL_DOBJ_MIN = -10;

        public const uint SPECIAL_DOBJ_MAX = 0;

        public const int AUTO_WIDTH = -1;

        public const int HIDE_COLUMN = -4;

        public const uint ILSIF_LEAVE_LARGE_ICON = 0x40000000;

        public const uint ILSIF_LEAVE_SMALL_ICON = 0x20000000;

        public const uint HDI_HIDDEN = 0x1;

        public const uint RDCI_ScopeItem = 0x80000000;

        public const uint RVTI_MISC_OPTIONS_NOLISTVIEWS = 0x1;

        public const uint RVTI_LIST_OPTIONS_NONE = 0;

        public const uint RVTI_LIST_OPTIONS_OWNERDATALIST = 0x2;

        public const uint RVTI_LIST_OPTIONS_MULTISELECT = 0x4;

        public const uint RVTI_LIST_OPTIONS_FILTERED = 0x8;

        public const uint RVTI_LIST_OPTIONS_USEFONTLINKING = 0x20;

        public const uint RVTI_LIST_OPTIONS_EXCLUDE_SCOPE_ITEMS_FROM_LIST = 0x40;

        public const uint RVTI_LIST_OPTIONS_LEXICAL_SORT = 0x80;

        public const uint RVTI_LIST_OPTIONS_ALLOWPASTE = 0x100;

        public const uint RVTI_HTML_OPTIONS_NONE = 0;

        public const uint RVTI_HTML_OPTIONS_NOLISTVIEW = 0x1;

        public const uint RVTI_OCX_OPTIONS_NONE = 0;

        public const uint RVTI_OCX_OPTIONS_NOLISTVIEW = 0x1;

        public const uint RVTI_OCX_OPTIONS_CACHE_OCX = 0x2;

        public const uint MMC_DEFAULT_OPERATION_COPY = 0x1;

        public const uint MMC_ITEM_OVERLAY_STATE_MASK = 0xf00;

        public const uint MMC_ITEM_OVERLAY_STATE_SHIFT = 8;

        public const uint MMC_ITEM_STATE_MASK = 0xff;

    }
}
