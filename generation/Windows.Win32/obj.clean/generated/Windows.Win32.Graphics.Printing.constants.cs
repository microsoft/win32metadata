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


namespace Windows.Win32.Graphics.Printing
{
    public static partial class Apis
    {
        public const uint USB_PRINTER_INTERFACE_CLASSIC = 1;

        public const uint USB_PRINTER_INTERFACE_IPP = 2;

        public const uint USB_PRINTER_INTERFACE_DUAL = 3;

        public const uint USBPRINT_IOCTL_INDEX = 0x0000;

        public const uint IOCTL_USBPRINT_GET_LPT_STATUS = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+12) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_USBPRINT_GET_1284_ID = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+13) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_USBPRINT_VENDOR_SET_COMMAND = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+14) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_USBPRINT_VENDOR_GET_COMMAND = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+15) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_USBPRINT_SOFT_RESET = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+16) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_USBPRINT_GET_PROTOCOL = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+17) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_USBPRINT_SET_PROTOCOL = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+18) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_USBPRINT_GET_INTERFACE_TYPE = ((FILE_DEVICE_UNKNOWN) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((USBPRINT_IOCTL_INDEX+19) << 2) | (METHOD_BUFFERED);

        public const uint TVOT_2STATES = 0;

        public const uint TVOT_3STATES = 1;

        public const uint TVOT_UDARROW = 2;

        public const uint TVOT_TRACKBAR = 3;

        public const uint TVOT_SCROLLBAR = 4;

        public const uint TVOT_LISTBOX = 5;

        public const uint TVOT_COMBOBOX = 6;

        public const uint TVOT_EDITBOX = 7;

        public const uint TVOT_PUSHBUTTON = 8;

        public const uint TVOT_CHKBOX = 9;

        public const uint TVOT_NSTATES_EX = 10;

        public const uint CHKBOXS_FALSE_TRUE = 0;

        public const uint CHKBOXS_NO_YES = 1;

        public const uint CHKBOXS_OFF_ON = 2;

        public const uint CHKBOXS_FALSE_PDATA = 3;

        public const uint CHKBOXS_NO_PDATA = 4;

        public const uint CHKBOXS_OFF_PDATA = 5;

        public const uint CHKBOXS_NONE_PDATA = 6;

        public const uint PUSHBUTTON_TYPE_DLGPROC = 0;

        public const uint PUSHBUTTON_TYPE_CALLBACK = 1;

        public const uint PUSHBUTTON_TYPE_HTCLRADJ = 2;

        public const uint PUSHBUTTON_TYPE_HTSETUP = 3;

        public const uint MAX_RES_STR_CHARS = 160;

        public const uint OPTPF_HIDE = 0x01;

        public const uint OPTPF_DISABLED = 0x02;

        public const uint OPTPF_ICONID_AS_HICON = 0x04;

        public const uint OPTPF_OVERLAY_WARNING_ICON = 0x08;

        public const uint OPTPF_OVERLAY_STOP_ICON = 0x10;

        public const uint OPTPF_OVERLAY_NO_ICON = 0x20;

        public const uint OPTPF_USE_HDLGTEMPLATE = 0x40;

        public const uint OPTPF_MASK = 0x7f;

        public const uint OPTCF_HIDE = 0x01;

        public const uint OPTCF_MASK = 0x01;

        public const uint OPTTF_TYPE_DISABLED = 0x01;

        public const uint OPTTF_NOSPACE_BEFORE_POSTFIX = 0x02;

        public const uint OPTTF_MASK = 0x03;

        public const uint OTS_LBCB_SORT = 0x0001;

        public const uint OTS_LBCB_PROPPAGE_LBUSECB = 0x0002;

        public const uint OTS_LBCB_PROPPAGE_CBUSELB = 0x0004;

        public const uint OTS_LBCB_INCL_ITEM_NONE = 0x0008;

        public const uint OTS_LBCB_NO_ICON16_IN_ITEM = 0x0010;

        public const uint OTS_PUSH_INCL_SETUP_TITLE = 0x0020;

        public const uint OTS_PUSH_NO_DOT_DOT_DOT = 0x0040;

        public const uint OTS_PUSH_ENABLE_ALWAYS = 0x0080;

        public const uint OTS_MASK = 0x00ff;

        public const uint EPF_PUSH_TYPE_DLGPROC = 0x0001;

        public const uint EPF_INCL_SETUP_TITLE = 0x0002;

        public const uint EPF_NO_DOT_DOT_DOT = 0x0004;

        public const uint EPF_ICONID_AS_HICON = 0x0008;

        public const uint EPF_OVERLAY_WARNING_ICON = 0x0010;

        public const uint EPF_OVERLAY_STOP_ICON = 0x0020;

        public const uint EPF_OVERLAY_NO_ICON = 0x0040;

        public const uint EPF_USE_HDLGTEMPLATE = 0x0080;

        public const uint EPF_MASK = 0x00ff;

        public const uint ECBF_CHECKNAME_AT_FRONT = 0x0001;

        public const uint ECBF_CHECKNAME_ONLY_ENABLED = 0x0002;

        public const uint ECBF_ICONID_AS_HICON = 0x0004;

        public const uint ECBF_OVERLAY_WARNING_ICON = 0x0008;

        public const uint ECBF_OVERLAY_ECBICON_IF_CHECKED = 0x0010;

        public const uint ECBF_OVERLAY_STOP_ICON = 0x0020;

        public const uint ECBF_OVERLAY_NO_ICON = 0x0040;

        public const uint ECBF_CHECKNAME_ONLY = 0x0080;

        public const uint ECBF_MASK = 0x00ff;

        public const int OPTIF_COLLAPSE = 0x00000001;

        public const int OPTIF_HIDE = 0x00000002;

        public const int OPTIF_CALLBACK = 0x00000004;

        public const int OPTIF_CHANGED = 0x00000008;

        public const int OPTIF_CHANGEONCE = 0x00000010;

        public const int OPTIF_DISABLED = 0x00000020;

        public const int OPTIF_ECB_CHECKED = 0x00000040;

        public const int OPTIF_EXT_HIDE = 0x00000080;

        public const int OPTIF_EXT_DISABLED = 0x00000100;

        public const int OPTIF_SEL_AS_HICON = 0x00000200;

        public const int OPTIF_EXT_IS_EXTPUSH = 0x00000400;

        public const int OPTIF_NO_GROUPBOX_NAME = 0x00000800;

        public const int OPTIF_OVERLAY_WARNING_ICON = 0x00001000;

        public const int OPTIF_OVERLAY_STOP_ICON = 0x00002000;

        public const int OPTIF_OVERLAY_NO_ICON = 0x00004000;

        public const int OPTIF_INITIAL_TVITEM = 0x00008000;

        public const int OPTIF_HAS_POIEXT = 0x00010000;

        public const int OPTIF_MASK = 0x0001ffff;

        public const uint DMPUB_NONE = 0;

        public const uint DMPUB_FIRST = 1;

        public const uint DMPUB_ORIENTATION = 1;

        public const uint DMPUB_SCALE = 2;

        public const uint DMPUB_COPIES_COLLATE = 3;

        public const uint DMPUB_DEFSOURCE = 4;

        public const uint DMPUB_PRINTQUALITY = 5;

        public const uint DMPUB_COLOR = 6;

        public const uint DMPUB_DUPLEX = 7;

        public const uint DMPUB_TTOPTION = 8;

        public const uint DMPUB_FORMNAME = 9;

        public const uint DMPUB_ICMMETHOD = 10;

        public const uint DMPUB_ICMINTENT = 11;

        public const uint DMPUB_MEDIATYPE = 12;

        public const uint DMPUB_DITHERTYPE = 13;

        public const uint DMPUB_OUTPUTBIN = 14;

        public const uint DMPUB_QUALITY = 15;

        public const uint DMPUB_NUP = 16;

        public const uint DMPUB_PAGEORDER = 17;

        public const uint DMPUB_NUP_DIRECTION = 18;

        public const uint DMPUB_MANUAL_DUPLEX = 19;

        public const uint DMPUB_STAPLE = 20;

        public const uint DMPUB_BOOKLET_EDGE = 21;

        public const uint DMPUB_LAST = 21;

        public const uint DMPUB_OEM_PAPER_ITEM = 97;

        public const uint DMPUB_OEM_GRAPHIC_ITEM = 98;

        public const uint DMPUB_OEM_ROOT_ITEM = 99;

        public const uint DMPUB_USER = 100;

        public const uint OIEXTF_ANSI_STRING = 0x0001;

        public const uint CPSUICB_REASON_SEL_CHANGED = 0;

        public const uint CPSUICB_REASON_PUSHBUTTON = 1;

        public const uint CPSUICB_REASON_ECB_CHANGED = 2;

        public const uint CPSUICB_REASON_DLGPROC = 3;

        public const uint CPSUICB_REASON_UNDO_CHANGES = 4;

        public const uint CPSUICB_REASON_EXTPUSH = 5;

        public const uint CPSUICB_REASON_APPLYNOW = 6;

        public const uint CPSUICB_REASON_OPTITEM_SETFOCUS = 7;

        public const uint CPSUICB_REASON_ITEMS_REVERTED = 8;

        public const uint CPSUICB_REASON_ABOUT = 9;

        public const uint CPSUICB_REASON_SETACTIVE = 10;

        public const uint CPSUICB_REASON_KILLACTIVE = 11;

        public const uint CPSUICB_ACTION_NONE = 0;

        public const uint CPSUICB_ACTION_OPTIF_CHANGED = 1;

        public const uint CPSUICB_ACTION_REINIT_ITEMS = 2;

        public const uint CPSUICB_ACTION_NO_APPLY_EXIT = 3;

        public const uint CPSUICB_ACTION_ITEMS_APPLIED = 4;

        public const uint DP_STD_TREEVIEWPAGE = 0xFFFF;

        public const uint DP_STD_DOCPROPPAGE2 = 0xFFFE;

        public const uint DP_STD_DOCPROPPAGE1 = 0XFFFD;

        public const uint DP_STD_RESERVED_START = 0xFFF0;

        public const uint MAX_DLGPAGE_COUNT = 64;

        public const uint DPF_ICONID_AS_HICON = 0x0001;

        public const uint DPF_USE_HDLGTEMPLATE = 0x0002;

        public const uint CPSUIF_UPDATE_PERMISSION = 0x0001;

        public const uint CPSUIF_ICONID_AS_HICON = 0x0002;

        public const uint CPSUIF_ABOUT_CALLBACK = 0x0004;

        public const uint CPSFUNC_ADD_HPROPSHEETPAGE = 0;

        public const uint CPSFUNC_ADD_PROPSHEETPAGEW = 1;

        public const uint CPSFUNC_ADD_PCOMPROPSHEETUIA = 2;

        public const uint CPSFUNC_ADD_PCOMPROPSHEETUIW = 3;

        public const uint CPSFUNC_ADD_PFNPROPSHEETUIA = 4;

        public const uint CPSFUNC_ADD_PFNPROPSHEETUIW = 5;

        public const uint CPSFUNC_DELETE_HCOMPROPSHEET = 6;

        public const uint CPSFUNC_SET_HSTARTPAGE = 7;

        public const uint CPSFUNC_GET_PAGECOUNT = 8;

        public const uint CPSFUNC_SET_RESULT = 9;

        public const uint CPSFUNC_GET_HPSUIPAGES = 10;

        public const uint CPSFUNC_LOAD_CPSUI_STRINGA = 11;

        public const uint CPSFUNC_LOAD_CPSUI_STRINGW = 12;

        public const uint CPSFUNC_LOAD_CPSUI_ICON = 13;

        public const uint CPSFUNC_GET_PFNPROPSHEETUI_ICON = 14;

        public const uint CPSFUNC_ADD_PROPSHEETPAGEA = 15;

        public const uint CPSFUNC_INSERT_PSUIPAGEA = 16;

        public const uint CPSFUNC_INSERT_PSUIPAGEW = 17;

        public const uint CPSFUNC_SET_PSUIPAGE_TITLEA = 18;

        public const uint CPSFUNC_SET_PSUIPAGE_TITLEW = 19;

        public const uint CPSFUNC_SET_PSUIPAGE_ICON = 20;

        public const uint CPSFUNC_SET_DATABLOCK = 21;

        public const uint CPSFUNC_QUERY_DATABLOCK = 22;

        public const uint CPSFUNC_SET_DMPUB_HIDEBITS = 23;

        public const uint CPSFUNC_IGNORE_CPSUI_PSN_APPLY = 24;

        public const uint CPSFUNC_DO_APPLY_CPSUI = 25;

        public const uint CPSFUNC_SET_FUSION_CONTEXT = 26;

        public const uint MAX_CPSFUNC_INDEX = 26;

        public const uint SR_OWNER = 0;

        public const uint SR_OWNER_PARENT = 1;

        public const uint PSUIPAGEINSERT_GROUP_PARENT = 0;

        public const uint PSUIPAGEINSERT_PCOMPROPSHEETUI = 1;

        public const uint PSUIPAGEINSERT_PFNPROPSHEETUI = 2;

        public const uint PSUIPAGEINSERT_PROPSHEETPAGE = 3;

        public const uint PSUIPAGEINSERT_HPROPSHEETPAGE = 4;

        public const uint PSUIPAGEINSERT_DLL = 5;

        public const uint MAX_PSUIPAGEINSERT_INDEX = 5;

        public const uint INSPSUIPAGE_MODE_BEFORE = 0;

        public const uint INSPSUIPAGE_MODE_AFTER = 1;

        public const uint INSPSUIPAGE_MODE_FIRST_CHILD = 2;

        public const uint INSPSUIPAGE_MODE_LAST_CHILD = 3;

        public const uint INSPSUIPAGE_MODE_INDEX = 4;

        public const uint SSP_TVPAGE = 10000;

        public const uint SSP_STDPAGE1 = 10001;

        public const uint SSP_STDPAGE2 = 10002;

        public const uint APPLYCPSUI_NO_NEWDEF = 0x00000001;

        public const uint APPLYCPSUI_OK_CANCEL_BUTTON = 0x00000002;

        public const uint PROPSHEETUI_REASON_INIT = 0;

        public const uint PROPSHEETUI_REASON_GET_INFO_HEADER = 1;

        public const uint PROPSHEETUI_REASON_DESTROY = 2;

        public const uint PROPSHEETUI_REASON_SET_RESULT = 3;

        public const uint PROPSHEETUI_REASON_GET_ICON = 4;

        public const uint PROPSHEETUI_REASON_BEFORE_INIT = 5;

        public const uint MAX_PROPSHEETUI_REASON_INDEX = 5;

        public const uint PROPSHEETUI_INFO_VERSION = 0x0100;

        public const uint PSUIINFO_UNICODE = 0x0001;

        public const uint PSUIHDRF_OBSOLETE = 0x0001;

        public const uint PSUIHDRF_NOAPPLYNOW = 0x0002;

        public const uint PSUIHDRF_PROPTITLE = 0x0004;

        public const uint PSUIHDRF_USEHICON = 0x0008;

        public const uint PSUIHDRF_DEFTITLE = 0x0010;

        public const uint PSUIHDRF_EXACT_PTITLE = 0x0020;

        public const uint CPSUI_CANCEL = 0;

        public const uint CPSUI_OK = 1;

        public const uint CPSUI_RESTARTWINDOWS = 2;

        public const uint CPSUI_REBOOTSYSTEM = 3;

        public const int ERR_CPSUI_GETLASTERROR = -1;

        public const int ERR_CPSUI_ALLOCMEM_FAILED = -2;

        public const int ERR_CPSUI_INVALID_PDATA = -3;

        public const int ERR_CPSUI_INVALID_LPARAM = -4;

        public const int ERR_CPSUI_NULL_HINST = -5;

        public const int ERR_CPSUI_NULL_CALLERNAME = -6;

        public const int ERR_CPSUI_NULL_OPTITEMNAME = -7;

        public const int ERR_CPSUI_NO_PROPSHEETPAGE = -8;

        public const int ERR_CPSUI_TOO_MANY_PROPSHEETPAGES = -9;

        public const int ERR_CPSUI_CREATEPROPPAGE_FAILED = -10;

        public const int ERR_CPSUI_MORE_THAN_ONE_TVPAGE = -11;

        public const int ERR_CPSUI_MORE_THAN_ONE_STDPAGE = -12;

        public const int ERR_CPSUI_INVALID_PDLGPAGE = -13;

        public const int ERR_CPSUI_INVALID_DLGPAGE_CBSIZE = -14;

        public const int ERR_CPSUI_TOO_MANY_DLGPAGES = -15;

        public const int ERR_CPSUI_INVALID_DLGPAGEIDX = -16;

        public const int ERR_CPSUI_SUBITEM_DIFF_DLGPAGEIDX = -17;

        public const int ERR_CPSUI_NULL_POPTITEM = -18;

        public const int ERR_CPSUI_INVALID_OPTITEM_CBSIZE = -19;

        public const int ERR_CPSUI_INVALID_OPTTYPE_CBSIZE = -20;

        public const int ERR_CPSUI_INVALID_OPTTYPE_COUNT = -21;

        public const int ERR_CPSUI_NULL_POPTPARAM = -22;

        public const int ERR_CPSUI_INVALID_OPTPARAM_CBSIZE = -23;

        public const int ERR_CPSUI_INVALID_EDITBOX_PSEL = -24;

        public const int ERR_CPSUI_INVALID_EDITBOX_BUF_SIZE = -25;

        public const int ERR_CPSUI_INVALID_ECB_CBSIZE = -26;

        public const int ERR_CPSUI_NULL_ECB_PTITLE = -27;

        public const int ERR_CPSUI_NULL_ECB_PCHECKEDNAME = -28;

        public const int ERR_CPSUI_INVALID_DMPUBID = -29;

        public const int ERR_CPSUI_INVALID_DMPUB_TVOT = -30;

        public const int ERR_CPSUI_CREATE_TRACKBAR_FAILED = -31;

        public const int ERR_CPSUI_CREATE_UDARROW_FAILED = -32;

        public const int ERR_CPSUI_CREATE_IMAGELIST_FAILED = -33;

        public const int ERR_CPSUI_INVALID_TVOT_TYPE = -34;

        public const int ERR_CPSUI_INVALID_LBCB_TYPE = -35;

        public const int ERR_CPSUI_SUBITEM_DIFF_OPTIF_HIDE = -36;

        public const int ERR_CPSUI_INVALID_PUSHBUTTON_TYPE = -38;

        public const int ERR_CPSUI_INVALID_EXTPUSH_CBSIZE = -39;

        public const int ERR_CPSUI_NULL_EXTPUSH_DLGPROC = -40;

        public const int ERR_CPSUI_NO_EXTPUSH_DLGTEMPLATEID = -41;

        public const int ERR_CPSUI_NULL_EXTPUSH_CALLBACK = -42;

        public const int ERR_CPSUI_DMCOPIES_USE_EXTPUSH = -43;

        public const int ERR_CPSUI_ZERO_OPTITEM = -44;

        public const int ERR_CPSUI_FUNCTION_NOT_IMPLEMENTED = -9999;

        public const int ERR_CPSUI_INTERNAL_ERROR = -10000;

        public const uint IDI_CPSUI_ICONID_FIRST = 64000;

        public const uint IDI_CPSUI_EMPTY = 64000;

        public const uint IDI_CPSUI_SEL_NONE = 64001;

        public const uint IDI_CPSUI_WARNING = 64002;

        public const uint IDI_CPSUI_NO = 64003;

        public const uint IDI_CPSUI_YES = 64004;

        public const uint IDI_CPSUI_FALSE = 64005;

        public const uint IDI_CPSUI_TRUE = 64006;

        public const uint IDI_CPSUI_OFF = 64007;

        public const uint IDI_CPSUI_ON = 64008;

        public const uint IDI_CPSUI_PAPER_OUTPUT = 64009;

        public const uint IDI_CPSUI_ENVELOPE = 64010;

        public const uint IDI_CPSUI_MEM = 64011;

        public const uint IDI_CPSUI_FONTCARTHDR = 64012;

        public const uint IDI_CPSUI_FONTCART = 64013;

        public const uint IDI_CPSUI_STAPLER_ON = 64014;

        public const uint IDI_CPSUI_STAPLER_OFF = 64015;

        public const uint IDI_CPSUI_HT_HOST = 64016;

        public const uint IDI_CPSUI_HT_DEVICE = 64017;

        public const uint IDI_CPSUI_TT_PRINTASGRAPHIC = 64018;

        public const uint IDI_CPSUI_TT_DOWNLOADSOFT = 64019;

        public const uint IDI_CPSUI_TT_DOWNLOADVECT = 64020;

        public const uint IDI_CPSUI_TT_SUBDEV = 64021;

        public const uint IDI_CPSUI_PORTRAIT = 64022;

        public const uint IDI_CPSUI_LANDSCAPE = 64023;

        public const uint IDI_CPSUI_ROT_LAND = 64024;

        public const uint IDI_CPSUI_AUTOSEL = 64025;

        public const uint IDI_CPSUI_PAPER_TRAY = 64026;

        public const uint IDI_CPSUI_PAPER_TRAY2 = 64027;

        public const uint IDI_CPSUI_PAPER_TRAY3 = 64028;

        public const uint IDI_CPSUI_TRANSPARENT = 64029;

        public const uint IDI_CPSUI_COLLATE = 64030;

        public const uint IDI_CPSUI_DUPLEX_NONE = 64031;

        public const uint IDI_CPSUI_DUPLEX_HORZ = 64032;

        public const uint IDI_CPSUI_DUPLEX_VERT = 64033;

        public const uint IDI_CPSUI_RES_DRAFT = 64034;

        public const uint IDI_CPSUI_RES_LOW = 64035;

        public const uint IDI_CPSUI_RES_MEDIUM = 64036;

        public const uint IDI_CPSUI_RES_HIGH = 64037;

        public const uint IDI_CPSUI_RES_PRESENTATION = 64038;

        public const uint IDI_CPSUI_MONO = 64039;

        public const uint IDI_CPSUI_COLOR = 64040;

        public const uint IDI_CPSUI_DITHER_NONE = 64041;

        public const uint IDI_CPSUI_DITHER_COARSE = 64042;

        public const uint IDI_CPSUI_DITHER_FINE = 64043;

        public const uint IDI_CPSUI_DITHER_LINEART = 64044;

        public const uint IDI_CPSUI_SCALING = 64045;

        public const uint IDI_CPSUI_COPY = 64046;

        public const uint IDI_CPSUI_HTCLRADJ = 64047;

        public const uint IDI_CPSUI_HALFTONE_SETUP = 64048;

        public const uint IDI_CPSUI_WATERMARK = 64049;

        public const uint IDI_CPSUI_ERROR = 64050;

        public const uint IDI_CPSUI_ICM_OPTION = 64051;

        public const uint IDI_CPSUI_ICM_METHOD = 64052;

        public const uint IDI_CPSUI_ICM_INTENT = 64053;

        public const uint IDI_CPSUI_STD_FORM = 64054;

        public const uint IDI_CPSUI_OUTBIN = 64055;

        public const uint IDI_CPSUI_OUTPUT = 64056;

        public const uint IDI_CPSUI_GRAPHIC = 64057;

        public const uint IDI_CPSUI_ADVANCE = 64058;

        public const uint IDI_CPSUI_DOCUMENT = 64059;

        public const uint IDI_CPSUI_DEVICE = 64060;

        public const uint IDI_CPSUI_DEVICE2 = 64061;

        public const uint IDI_CPSUI_PRINTER = 64062;

        public const uint IDI_CPSUI_PRINTER2 = 64063;

        public const uint IDI_CPSUI_PRINTER3 = 64064;

        public const uint IDI_CPSUI_PRINTER4 = 64065;

        public const uint IDI_CPSUI_OPTION = 64066;

        public const uint IDI_CPSUI_OPTION2 = 64067;

        public const uint IDI_CPSUI_STOP = 64068;

        public const uint IDI_CPSUI_NOTINSTALLED = 64069;

        public const uint IDI_CPSUI_WARNING_OVERLAY = 64070;

        public const uint IDI_CPSUI_STOP_WARNING_OVERLAY = 64071;

        public const uint IDI_CPSUI_GENERIC_OPTION = 64072;

        public const uint IDI_CPSUI_GENERIC_ITEM = 64073;

        public const uint IDI_CPSUI_RUN_DIALOG = 64074;

        public const uint IDI_CPSUI_QUESTION = 64075;

        public const uint IDI_CPSUI_FORMTRAYASSIGN = 64076;

        public const uint IDI_CPSUI_PRINTER_FOLDER = 64077;

        public const uint IDI_CPSUI_INSTALLABLE_OPTION = 64078;

        public const uint IDI_CPSUI_PRINTER_FEATURE = 64079;

        public const uint IDI_CPSUI_DEVICE_FEATURE = 64080;

        public const uint IDI_CPSUI_FONTSUB = 64081;

        public const uint IDI_CPSUI_POSTSCRIPT = 64082;

        public const uint IDI_CPSUI_TELEPHONE = 64083;

        public const uint IDI_CPSUI_DUPLEX_NONE_L = 64084;

        public const uint IDI_CPSUI_DUPLEX_HORZ_L = 64085;

        public const uint IDI_CPSUI_DUPLEX_VERT_L = 64086;

        public const uint IDI_CPSUI_LF_PEN_PLOTTER = 64087;

        public const uint IDI_CPSUI_SF_PEN_PLOTTER = 64088;

        public const uint IDI_CPSUI_LF_RASTER_PLOTTER = 64089;

        public const uint IDI_CPSUI_SF_RASTER_PLOTTER = 64090;

        public const uint IDI_CPSUI_ROLL_PAPER = 64091;

        public const uint IDI_CPSUI_PEN_CARROUSEL = 64092;

        public const uint IDI_CPSUI_PLOTTER_PEN = 64093;

        public const uint IDI_CPSUI_MANUAL_FEED = 64094;

        public const uint IDI_CPSUI_FAX = 64095;

        public const uint IDI_CPSUI_PAGE_PROTECT = 64096;

        public const uint IDI_CPSUI_ENVELOPE_FEED = 64097;

        public const uint IDI_CPSUI_FONTCART_SLOT = 64098;

        public const uint IDI_CPSUI_LAYOUT_BMP_PORTRAIT = 64099;

        public const uint IDI_CPSUI_LAYOUT_BMP_ARROWL = 64100;

        public const uint IDI_CPSUI_LAYOUT_BMP_ARROWS = 64101;

        public const uint IDI_CPSUI_LAYOUT_BMP_BOOKLETL = 64102;

        public const uint IDI_CPSUI_LAYOUT_BMP_BOOKLETP = 64103;

        public const uint IDI_CPSUI_LAYOUT_BMP_ARROWLR = 64104;

        public const uint IDI_CPSUI_LAYOUT_BMP_ROT_PORT = 64105;

        public const uint IDI_CPSUI_LAYOUT_BMP_BOOKLETL_NB = 64106;

        public const uint IDI_CPSUI_LAYOUT_BMP_BOOKLETP_NB = 64107;

        public const uint IDI_CPSUI_ROT_PORT = 64110;

        public const uint IDI_CPSUI_NUP_BORDER = 64111;

        public const uint IDI_CPSUI_ICONID_LAST = 64111;

        public const uint IDS_CPSUI_STRID_FIRST = 64700;

        public const uint IDS_CPSUI_SETUP = 64700;

        public const uint IDS_CPSUI_MORE = 64701;

        public const uint IDS_CPSUI_CHANGE = 64702;

        public const uint IDS_CPSUI_OPTION = 64703;

        public const uint IDS_CPSUI_OF = 64704;

        public const uint IDS_CPSUI_RANGE_FROM = 64705;

        public const uint IDS_CPSUI_TO = 64706;

        public const uint IDS_CPSUI_COLON_SEP = 64707;

        public const uint IDS_CPSUI_LEFT_ANGLE = 64708;

        public const uint IDS_CPSUI_RIGHT_ANGLE = 64709;

        public const uint IDS_CPSUI_SLASH_SEP = 64710;

        public const uint IDS_CPSUI_PERCENT = 64711;

        public const uint IDS_CPSUI_LBCB_NOSEL = 64712;

        public const uint IDS_CPSUI_PROPERTIES = 64713;

        public const uint IDS_CPSUI_DEFAULTDOCUMENT = 64714;

        public const uint IDS_CPSUI_DOCUMENT = 64715;

        public const uint IDS_CPSUI_ADVANCEDOCUMENT = 64716;

        public const uint IDS_CPSUI_PRINTER = 64717;

        public const uint IDS_CPSUI_AUTOSELECT = 64718;

        public const uint IDS_CPSUI_PAPER_OUTPUT = 64719;

        public const uint IDS_CPSUI_GRAPHIC = 64720;

        public const uint IDS_CPSUI_OPTIONS = 64721;

        public const uint IDS_CPSUI_ADVANCED = 64722;

        public const uint IDS_CPSUI_STDDOCPROPTAB = 64723;

        public const uint IDS_CPSUI_STDDOCPROPTVTAB = 64724;

        public const uint IDS_CPSUI_DEVICEOPTIONS = 64725;

        public const uint IDS_CPSUI_FALSE = 64726;

        public const uint IDS_CPSUI_TRUE = 64727;

        public const uint IDS_CPSUI_NO = 64728;

        public const uint IDS_CPSUI_YES = 64729;

        public const uint IDS_CPSUI_OFF = 64730;

        public const uint IDS_CPSUI_ON = 64731;

        public const uint IDS_CPSUI_DEFAULT = 64732;

        public const uint IDS_CPSUI_ERROR = 64733;

        public const uint IDS_CPSUI_NONE = 64734;

        public const uint IDS_CPSUI_NOT = 64735;

        public const uint IDS_CPSUI_EXIST = 64736;

        public const uint IDS_CPSUI_NOTINSTALLED = 64737;

        public const uint IDS_CPSUI_ORIENTATION = 64738;

        public const uint IDS_CPSUI_SCALING = 64739;

        public const uint IDS_CPSUI_NUM_OF_COPIES = 64740;

        public const uint IDS_CPSUI_SOURCE = 64741;

        public const uint IDS_CPSUI_PRINTQUALITY = 64742;

        public const uint IDS_CPSUI_RESOLUTION = 64743;

        public const uint IDS_CPSUI_COLOR_APPERANCE = 64744;

        public const uint IDS_CPSUI_DUPLEX = 64745;

        public const uint IDS_CPSUI_TTOPTION = 64746;

        public const uint IDS_CPSUI_FORMNAME = 64747;

        public const uint IDS_CPSUI_ICM = 64748;

        public const uint IDS_CPSUI_ICMMETHOD = 64749;

        public const uint IDS_CPSUI_ICMINTENT = 64750;

        public const uint IDS_CPSUI_MEDIA = 64751;

        public const uint IDS_CPSUI_DITHERING = 64752;

        public const uint IDS_CPSUI_PORTRAIT = 64753;

        public const uint IDS_CPSUI_LANDSCAPE = 64754;

        public const uint IDS_CPSUI_ROT_LAND = 64755;

        public const uint IDS_CPSUI_COLLATE = 64756;

        public const uint IDS_CPSUI_COLLATED = 64757;

        public const uint IDS_CPSUI_PRINTFLDSETTING = 64758;

        public const uint IDS_CPSUI_DRAFT = 64759;

        public const uint IDS_CPSUI_LOW = 64760;

        public const uint IDS_CPSUI_MEDIUM = 64761;

        public const uint IDS_CPSUI_HIGH = 64762;

        public const uint IDS_CPSUI_PRESENTATION = 64763;

        public const uint IDS_CPSUI_COLOR = 64764;

        public const uint IDS_CPSUI_GRAYSCALE = 64765;

        public const uint IDS_CPSUI_MONOCHROME = 64766;

        public const uint IDS_CPSUI_SIMPLEX = 64767;

        public const uint IDS_CPSUI_HORIZONTAL = 64768;

        public const uint IDS_CPSUI_VERTICAL = 64769;

        public const uint IDS_CPSUI_LONG_SIDE = 64770;

        public const uint IDS_CPSUI_SHORT_SIDE = 64771;

        public const uint IDS_CPSUI_TT_PRINTASGRAPHIC = 64772;

        public const uint IDS_CPSUI_TT_DOWNLOADSOFT = 64773;

        public const uint IDS_CPSUI_TT_DOWNLOADVECT = 64774;

        public const uint IDS_CPSUI_TT_SUBDEV = 64775;

        public const uint IDS_CPSUI_ICM_BLACKWHITE = 64776;

        public const uint IDS_CPSUI_ICM_NO = 64777;

        public const uint IDS_CPSUI_ICM_YES = 64778;

        public const uint IDS_CPSUI_ICM_SATURATION = 64779;

        public const uint IDS_CPSUI_ICM_CONTRAST = 64780;

        public const uint IDS_CPSUI_ICM_COLORMETRIC = 64781;

        public const uint IDS_CPSUI_STANDARD = 64782;

        public const uint IDS_CPSUI_GLOSSY = 64783;

        public const uint IDS_CPSUI_TRANSPARENCY = 64784;

        public const uint IDS_CPSUI_REGULAR = 64785;

        public const uint IDS_CPSUI_BOND = 64786;

        public const uint IDS_CPSUI_COARSE = 64787;

        public const uint IDS_CPSUI_FINE = 64788;

        public const uint IDS_CPSUI_LINEART = 64789;

        public const uint IDS_CPSUI_ERRDIFFUSE = 64790;

        public const uint IDS_CPSUI_HALFTONE = 64791;

        public const uint IDS_CPSUI_HTCLRADJ = 64792;

        public const uint IDS_CPSUI_USE_HOST_HT = 64793;

        public const uint IDS_CPSUI_USE_DEVICE_HT = 64794;

        public const uint IDS_CPSUI_USE_PRINTER_HT = 64795;

        public const uint IDS_CPSUI_OUTBINASSIGN = 64796;

        public const uint IDS_CPSUI_WATERMARK = 64797;

        public const uint IDS_CPSUI_FORMTRAYASSIGN = 64798;

        public const uint IDS_CPSUI_UPPER_TRAY = 64799;

        public const uint IDS_CPSUI_ONLYONE = 64800;

        public const uint IDS_CPSUI_LOWER_TRAY = 64801;

        public const uint IDS_CPSUI_MIDDLE_TRAY = 64802;

        public const uint IDS_CPSUI_MANUAL_TRAY = 64803;

        public const uint IDS_CPSUI_ENVELOPE_TRAY = 64804;

        public const uint IDS_CPSUI_ENVMANUAL_TRAY = 64805;

        public const uint IDS_CPSUI_TRACTOR_TRAY = 64806;

        public const uint IDS_CPSUI_SMALLFMT_TRAY = 64807;

        public const uint IDS_CPSUI_LARGEFMT_TRAY = 64808;

        public const uint IDS_CPSUI_LARGECAP_TRAY = 64809;

        public const uint IDS_CPSUI_CASSETTE_TRAY = 64810;

        public const uint IDS_CPSUI_DEFAULT_TRAY = 64811;

        public const uint IDS_CPSUI_FORMSOURCE = 64812;

        public const uint IDS_CPSUI_MANUALFEED = 64813;

        public const uint IDS_CPSUI_PRINTERMEM_KB = 64814;

        public const uint IDS_CPSUI_PRINTERMEM_MB = 64815;

        public const uint IDS_CPSUI_PAGEPROTECT = 64816;

        public const uint IDS_CPSUI_HALFTONE_SETUP = 64817;

        public const uint IDS_CPSUI_INSTFONTCART = 64818;

        public const uint IDS_CPSUI_SLOT1 = 64819;

        public const uint IDS_CPSUI_SLOT2 = 64820;

        public const uint IDS_CPSUI_SLOT3 = 64821;

        public const uint IDS_CPSUI_SLOT4 = 64822;

        public const uint IDS_CPSUI_LEFT_SLOT = 64823;

        public const uint IDS_CPSUI_RIGHT_SLOT = 64824;

        public const uint IDS_CPSUI_STAPLER = 64825;

        public const uint IDS_CPSUI_STAPLER_ON = 64826;

        public const uint IDS_CPSUI_STAPLER_OFF = 64827;

        public const uint IDS_CPSUI_STACKER = 64828;

        public const uint IDS_CPSUI_MAILBOX = 64829;

        public const uint IDS_CPSUI_COPY = 64830;

        public const uint IDS_CPSUI_COPIES = 64831;

        public const uint IDS_CPSUI_TOTAL = 64832;

        public const uint IDS_CPSUI_MAKE = 64833;

        public const uint IDS_CPSUI_PRINT = 64834;

        public const uint IDS_CPSUI_FAX = 64835;

        public const uint IDS_CPSUI_PLOT = 64836;

        public const uint IDS_CPSUI_SLOW = 64837;

        public const uint IDS_CPSUI_FAST = 64838;

        public const uint IDS_CPSUI_ROTATED = 64839;

        public const uint IDS_CPSUI_RESET = 64840;

        public const uint IDS_CPSUI_ALL = 64841;

        public const uint IDS_CPSUI_DEVICE = 64842;

        public const uint IDS_CPSUI_SETTINGS = 64843;

        public const uint IDS_CPSUI_REVERT = 64844;

        public const uint IDS_CPSUI_CHANGES = 64845;

        public const uint IDS_CPSUI_CHANGED = 64846;

        public const uint IDS_CPSUI_WARNING = 64847;

        public const uint IDS_CPSUI_ABOUT = 64848;

        public const uint IDS_CPSUI_VERSION = 64849;

        public const uint IDS_CPSUI_NO_NAME = 64850;

        public const uint IDS_CPSUI_SETTING = 64851;

        public const uint IDS_CPSUI_DEVICE_SETTINGS = 64852;

        public const uint IDS_CPSUI_STDDOCPROPTAB1 = 64853;

        public const uint IDS_CPSUI_STDDOCPROPTAB2 = 64854;

        public const uint IDS_CPSUI_PAGEORDER = 64855;

        public const uint IDS_CPSUI_FRONTTOBACK = 64856;

        public const uint IDS_CPSUI_BACKTOFRONT = 64857;

        public const uint IDS_CPSUI_QUALITY_SETTINGS = 64858;

        public const uint IDS_CPSUI_QUALITY_DRAFT = 64859;

        public const uint IDS_CPSUI_QUALITY_BETTER = 64860;

        public const uint IDS_CPSUI_QUALITY_BEST = 64861;

        public const uint IDS_CPSUI_QUALITY_CUSTOM = 64862;

        public const uint IDS_CPSUI_OUTPUTBIN = 64863;

        public const uint IDS_CPSUI_NUP = 64864;

        public const uint IDS_CPSUI_NUP_NORMAL = 64865;

        public const uint IDS_CPSUI_NUP_TWOUP = 64866;

        public const uint IDS_CPSUI_NUP_FOURUP = 64867;

        public const uint IDS_CPSUI_NUP_SIXUP = 64868;

        public const uint IDS_CPSUI_NUP_NINEUP = 64869;

        public const uint IDS_CPSUI_NUP_SIXTEENUP = 64870;

        public const uint IDS_CPSUI_SIDE1 = 64871;

        public const uint IDS_CPSUI_SIDE2 = 64872;

        public const uint IDS_CPSUI_BOOKLET = 64873;

        public const uint IDS_CPSUI_POSTER = 64874;

        public const uint IDS_CPSUI_POSTER_2x2 = 64875;

        public const uint IDS_CPSUI_POSTER_3x3 = 64876;

        public const uint IDS_CPSUI_POSTER_4x4 = 64877;

        public const uint IDS_CPSUI_NUP_DIRECTION = 64878;

        public const uint IDS_CPSUI_RIGHT_THEN_DOWN = 64879;

        public const uint IDS_CPSUI_DOWN_THEN_RIGHT = 64880;

        public const uint IDS_CPSUI_LEFT_THEN_DOWN = 64881;

        public const uint IDS_CPSUI_DOWN_THEN_LEFT = 64882;

        public const uint IDS_CPSUI_MANUAL_DUPLEX = 64883;

        public const uint IDS_CPSUI_MANUAL_DUPLEX_ON = 64884;

        public const uint IDS_CPSUI_MANUAL_DUPLEX_OFF = 64885;

        public const uint IDS_CPSUI_ROT_PORT = 64886;

        public const uint IDS_CPSUI_STAPLE = 64887;

        public const uint IDS_CPSUI_BOOKLET_EDGE = 64888;

        public const uint IDS_CPSUI_BOOKLET_EDGE_LEFT = 64889;

        public const uint IDS_CPSUI_BOOKLET_EDGE_RIGHT = 64890;

        public const uint IDS_CPSUI_NUP_BORDER = 64891;

        public const uint IDS_CPSUI_NUP_BORDERED = 64892;

        public const uint IDS_CPSUI_STRID_LAST = 64892;

        public const uint MXDC_ESCAPE = 4122;

        public const uint MXDCOP_GET_FILENAME = 14;

        public const uint MXDCOP_PRINTTICKET_FIXED_DOC_SEQ = 22;

        public const uint MXDCOP_PRINTTICKET_FIXED_DOC = 24;

        public const uint MXDCOP_PRINTTICKET_FIXED_PAGE = 26;

        public const uint MXDCOP_SET_S0PAGE = 28;

        public const uint MXDCOP_SET_S0PAGE_RESOURCE = 30;

        public const uint MXDCOP_SET_XPSPASSTHRU_MODE = 32;

        public static readonly Guid CLSID_OEMRENDER__scanned__ = new Guid(0x6d6abf26, 0x9f38, 0x11d1, 0x88, 0x2a, 0x00, 0xc0, 0x4f, 0xb9, 0x61, 0xec);

        public static readonly Guid CLSID_OEMUI__scanned__ = new Guid(0xabce80d7, 0x9f46, 0x11d1, 0x88, 0x2a, 0x00, 0xc0, 0x4f, 0xb9, 0x61, 0xec);

        public static readonly Guid CLSID_OEMUIMXDC__scanned__ = new Guid(0x4e144300, 0x5b43, 0x4288, 0x93, 0x2a, 0x5e, 0x4d, 0xd6, 0xd8, 0x2b, 0xed);

        public static readonly Guid CLSID_OEMPTPROVIDER__scanned__ = new Guid(0x91723892, 0x45d2, 0x48e2, 0x9e, 0xc9, 0x56, 0x23, 0x79, 0xda, 0xf9, 0x92);

        public static readonly Guid IID_IPrintCoreHelper__scanned__ = new Guid(0xa89ec53e, 0x3905, 0x49c6, 0x9c, 0x1a, 0xc0, 0xa8, 0x81, 0x17, 0xfd, 0xb6);

        public static readonly Guid IID_IPrintCoreHelperUni__scanned__ = new Guid(0x7e8e51d6, 0xe5ee, 0x4426, 0x81, 0x7b, 0x95, 0x8b, 0x94, 0x44, 0xeb, 0x79);

        public static readonly Guid IID_IPrintCoreHelperPS__scanned__ = new Guid(0xc2c14f6f, 0x95d3, 0x4d63, 0x96, 0xcf, 0x6b, 0xd9, 0xe6, 0xc9, 0x7, 0xc2);

        public static readonly Guid IID_IPrintCoreHelperUni2__scanned__ = new Guid(0x6c8afdfc, 0xead0, 0x4d2d, 0x80, 0x71, 0x9b, 0xf0, 0x17, 0x5a, 0x6c, 0x3a);

        public static readonly Guid IID_IPrintOemCommon__scanned__ = new Guid(0x7f42285e, 0x91d5, 0x11d1, 0x88, 0x20, 0x00, 0xc0, 0x4f, 0xb9, 0x61, 0xec);

        public static readonly Guid IID_IPrintOemEngine__scanned__ = new Guid(0x63d17590, 0x91d8, 0x11d1, 0x88, 0x20, 0x00, 0xc0, 0x4f, 0xb9, 0x61, 0xec);

        public static readonly Guid IID_IPrintOemUI__scanned__ = new Guid(0xc6a7a9d0, 0x774c, 0x11d1, 0x94, 0x7f, 0x0, 0xa0, 0xc9, 0x6, 0x40, 0xb8);

        public static readonly Guid IID_IPrintOemUI2__scanned__ = new Guid(0x292515f9, 0xb54b, 0x489b, 0x92, 0x75, 0xba, 0xb5, 0x68, 0x21, 0x39, 0x5e);

        public static readonly Guid IID_IPrintOemUIMXDC__scanned__ = new Guid(0x7349d725, 0xe2c1, 0x4dca, 0xaf, 0xb5, 0xc1, 0x3e, 0x91, 0xbc, 0x93, 0x6);

        public static readonly Guid IID_IPrintOemDriverUI__scanned__ = new Guid(0x92b05d50, 0x78bc, 0x11d1, 0x94, 0x80, 0x0, 0xa0, 0xc9, 0x6, 0x40, 0xb8);

        public static readonly Guid IID_IPrintCoreUI2__scanned__ = new Guid(0x85ccfca, 0x3adf, 0x4c9e, 0xb4, 0x91, 0xd8, 0x51, 0xa6, 0xed, 0xc9, 0x97);

        public static readonly Guid IID_IPrintOemPS__scanned__ = new Guid(0x688342b5, 0x8e1a, 0x11d1, 0x88, 0x1f, 0x00, 0xc0, 0x4f, 0xb9, 0x61, 0xec);

        public static readonly Guid IID_IPrintOemPS2__scanned__ = new Guid(0xbecf7f34, 0x51b3, 0x46c9, 0x8a, 0x1c, 0x18, 0x67, 0x9b, 0xd2, 0x1f, 0x36);

        public static readonly Guid IID_IPrintOemDriverPS__scanned__ = new Guid(0xd90060c7, 0x8e1a, 0x11d1, 0x88, 0x1f, 0x00, 0xc0, 0x4f, 0xb9, 0x61, 0xec);

        public static readonly Guid IID_IPrintCorePS2__scanned__ = new Guid(0xcdbb0b0b, 0xa917, 0x40d7, 0x9f, 0xbf, 0x48, 0x3b, 0x3b, 0xe7, 0xef, 0x22);

        public static readonly Guid IID_IPrintOemUni__scanned__ = new Guid(0xd67ebbf0, 0x78bf, 0x11d1, 0x94, 0x80, 0x0, 0xa0, 0xc9, 0x6, 0x40, 0xb8);

        public static readonly Guid IID_IPrintOemUni2__scanned__ = new Guid(0xb91220ac, 0x15cc, 0x4e7a, 0xa2, 0x1e, 0x95, 0x91, 0xf3, 0x4d, 0x6f, 0x6c);

        public static readonly Guid IID_IPrintOemUni3__scanned__ = new Guid(0x4e4a7747, 0xbc76, 0x4aed, 0xac, 0xc8, 0xc7, 0x6a, 0xf2, 0x2a, 0xad, 0x43);

        public static readonly Guid IID_IPrintOemDriverUni__scanned__ = new Guid(0xd67ebbf1, 0x78bf, 0x11d1, 0x94, 0x80, 0x0, 0xa0, 0xc9, 0x6, 0x40, 0xb8);

        public static readonly Guid IID_IPrintOemPrintTicketProvider__scanned__ = new Guid(0xbcf5e011, 0xf60a, 0x49ff, 0xab, 0x2f, 0xe0, 0x6f, 0x4a, 0xbd, 0xf2, 0x81);

        [NativeTypeName("HRESULT")]
        public const int S_DEVCAP_OUTPUT_FULL_REPLACEMENT = 0x0004DC01;

        public static readonly Guid CLSID_PTPROVIDER__scanned__ = new Guid(0x46ac151b, 0x8490, 0x4531, 0x96, 0xcc, 0x55, 0xbf, 0x2b, 0xf1, 0x9e, 0x11);

        public const uint E_VERSION_NOT_SUPPORTED = 0x80040001;

        public const uint S_NO_CONFLICT = 0x00040001;

        public const uint S_CONFLICT_RESOLVED = 0x00040002;

        public static readonly Guid PRINTER_EXTENSION_DETAILEDREASON_PRINTER_STATUS__scanned__ = new Guid(0x5d5a1704, 0xdfd1, 0x4181, 0x8e, 0xee, 0x81, 0x5c, 0x86, 0xed, 0xad, 0x31);

        public static readonly Guid PRINTER_EXTENSION_REASON_PRINT_PREFERENCES__scanned__ = new Guid(0xec8f261f, 0x267c, 0x469f, 0xb5, 0xd6, 0x39, 0x33, 0x02, 0x3c, 0x29, 0xcc);

        public static readonly Guid PRINTER_EXTENSION_REASON_DRIVER_EVENT__scanned__ = new Guid(0x23bb1328, 0x63de, 0x4293, 0x91, 0x5b, 0xa6, 0xa2, 0x3d, 0x92, 0x9a, 0xcb);

        public static readonly Guid FMTID_PrinterPropertyBag__scanned__ = new Guid(0x75f9adca, 0x097d, 0x45c3, 0xa6, 0xe4, 0xba, 0xb2, 0x9e, 0x27, 0x6f, 0x3e);

        public const uint PRINTER_OEMINTF_VERSION = 0x00010000;

        public const uint OEM_MODE_PUBLISHER = 0x00000001;

        public const uint OEMGI_GETSIGNATURE = 1;

        public const uint OEMGI_GETINTERFACEVERSION = 2;

        public const uint OEMGI_GETVERSION = 3;

        public const uint OEMGI_GETPUBLISHERINFO = 4;

        public const uint OEMGI_GETREQUESTEDHELPERINTERFACES = 5;

        public const uint OEMPUBLISH_DEFAULT = 0;

        public const uint OEMPUBLISH_IPRINTCOREHELPER = 1u<<0;

        public const uint OEMDM_SIZE = 1;

        public const uint OEMDM_DEFAULT = 2;

        public const uint OEMDM_CONVERT = 3;

        public const uint OEMDM_MERGE = 4;

        public const uint OEMGDS_MIN_DOCSTICKY = 1;

        public const uint OEMGDS_PSDM_FLAGS = 1;

        public const uint OEMGDS_PSDM_DIALECT = 2;

        public const uint OEMGDS_PSDM_TTDLFMT = 3;

        public const uint OEMGDS_PSDM_NUP = 4;

        public const uint OEMGDS_PSDM_PSLEVEL = 5;

        public const uint OEMGDS_PSDM_CUSTOMSIZE = 6;

        public const uint OEMGDS_UNIDM_GPDVER = 0x4000;

        public const uint OEMGDS_UNIDM_FLAGS = 0x4001;

        public const uint OEMGDS_MIN_PRINTERSTICKY = 0x8000;

        public const uint OEMGDS_PRINTFLAGS = 0x8000;

        public const uint OEMGDS_FREEMEM = 0x8001;

        public const uint OEMGDS_JOBTIMEOUT = 0x8002;

        public const uint OEMGDS_WAITTIMEOUT = 0x8003;

        public const uint OEMGDS_PROTOCOL = 0x8004;

        public const uint OEMGDS_MINOUTLINE = 0x8005;

        public const uint OEMGDS_MAXBITMAP = 0x8006;

        public const uint OEMGDS_MAX = 0x10000;

        public const uint GPD_OEMCUSTOMDATA = 1;

        public const uint MV_UPDATE = 0x0001;

        public const uint MV_RELATIVE = 0x0002;

        public const uint MV_GRAPHICS = 0x0004;

        public const uint MV_PHYSICAL = 0x0008;

        public const uint MV_SENDXMOVECMD = 0x0010;

        public const uint MV_SENDYMOVECMD = 0x0020;

        public const uint OEMTTY_INFO_MARGINS = 1;

        public const uint OEMTTY_INFO_CODEPAGE = 2;

        public const uint OEMTTY_INFO_NUM_UFMS = 3;

        public const uint OEMTTY_INFO_UFM_IDS = 4;

        public const uint UFOFLAG_TTFONT = 0x00000001;

        public const uint UFOFLAG_TTDOWNLOAD_BITMAP = 0x00000002;

        public const uint UFOFLAG_TTDOWNLOAD_TTOUTLINE = 0x00000004;

        public const uint UFOFLAG_TTOUTLINE_BOLD_SIM = 0x00000008;

        public const uint UFOFLAG_TTOUTLINE_ITALIC_SIM = 0x00000010;

        public const uint UFOFLAG_TTOUTLINE_VERTICAL = 0x00000020;

        public const uint UFOFLAG_TTSUBSTITUTED = 0x00000040;

        public const uint UFO_GETINFO_FONTOBJ = 1;

        public const uint UFO_GETINFO_GLYPHSTRING = 2;

        public const uint UFO_GETINFO_GLYPHBITMAP = 3;

        public const uint UFO_GETINFO_GLYPHWIDTH = 4;

        public const uint UFO_GETINFO_MEMORY = 5;

        public const uint UFO_GETINFO_STDVARIABLE = 6;

        public const uint FNT_INFO_PRINTDIRINCCDEGREES = 0;

        public const uint FNT_INFO_GRAYPERCENTAGE = 1;

        public const uint FNT_INFO_NEXTFONTID = 2;

        public const uint FNT_INFO_NEXTGLYPH = 3;

        public const uint FNT_INFO_FONTHEIGHT = 4;

        public const uint FNT_INFO_FONTWIDTH = 5;

        public const uint FNT_INFO_FONTBOLD = 6;

        public const uint FNT_INFO_FONTITALIC = 7;

        public const uint FNT_INFO_FONTUNDERLINE = 8;

        public const uint FNT_INFO_FONTSTRIKETHRU = 9;

        public const uint FNT_INFO_CURRENTFONTID = 10;

        public const uint FNT_INFO_TEXTYRES = 11;

        public const uint FNT_INFO_TEXTXRES = 12;

        public const uint FNT_INFO_FONTMAXWIDTH = 13;

        public const uint FNT_INFO_MAX = 14;

        public const uint TTDOWNLOAD_DONTCARE = 0;

        public const uint TTDOWNLOAD_GRAPHICS = 1;

        public const uint TTDOWNLOAD_BITMAP = 2;

        public const uint TTDOWNLOAD_TTOUTLINE = 3;

        public const uint TYPE_UNICODE = 1;

        public const uint TYPE_TRANSDATA = 2;

        public const uint TYPE_GLYPHHANDLE = 3;

        public const uint TYPE_GLYPHID = 4;

        public const uint PDEV_ADJUST_PAPER_MARGIN_TYPE = 1;

        public const uint PDEV_HOSTFONT_ENABLED_TYPE = 2;

        public const uint PDEV_USE_TRUE_COLOR_TYPE = 3;

        public const uint OEMCUIP_DOCPROP = 1;

        public const uint OEMCUIP_PRNPROP = 2;

        public const uint CUSTOMPARAM_WIDTH = 0;

        public const uint CUSTOMPARAM_HEIGHT = 1;

        public const uint CUSTOMPARAM_WIDTHOFFSET = 2;

        public const uint CUSTOMPARAM_HEIGHTOFFSET = 3;

        public const uint CUSTOMPARAM_ORIENTATION = 4;

        public const uint CUSTOMPARAM_MAX = 5;

        public const uint SETOPTIONS_FLAG_RESOLVE_CONFLICT = 0x00000001;

        public const uint SETOPTIONS_FLAG_KEEP_CONFLICT = 0x00000002;

        public const uint SETOPTIONS_RESULT_NO_CONFLICT = 0;

        public const uint SETOPTIONS_RESULT_CONFLICT_RESOLVED = 1;

        public const uint SETOPTIONS_RESULT_CONFLICT_REMAINED = 2;

        public const uint UNIFM_VERSION_1_0 = 0x00010000;

        public const uint UFM_SOFT = 0x00000001;

        public const uint UFM_CART = 0x00000002;

        public const uint UFM_SCALABLE = 0x00000004;

        public const uint DF_TYPE_HPINTELLIFONT = 0;

        public const uint DF_TYPE_TRUETYPE = 1;

        public const uint DF_TYPE_PST1 = 2;

        public const uint DF_TYPE_CAPSL = 3;

        public const uint DF_TYPE_OEM1 = 4;

        public const uint DF_TYPE_OEM2 = 5;

        public const uint DF_NOITALIC = 0x0001;

        public const uint DF_NOUNDER = 0x0002;

        public const uint DF_XM_CR = 0x0004;

        public const uint DF_NO_BOLD = 0x0008;

        public const uint DF_NO_DOUBLE_UNDERLINE = 0x0010;

        public const uint DF_NO_STRIKETHRU = 0x0020;

        public const uint DF_BKSP_OK = 0x0040;

        public const uint UNI_GLYPHSETDATA_VERSION_1_0 = 0x00010000;

        public const uint MTYPE_FORMAT_MASK = 0x07;

        public const uint MTYPE_COMPOSE = 0x01;

        public const uint MTYPE_DIRECT = 0x02;

        public const uint MTYPE_PAIRED = 0x04;

        public const uint MTYPE_DOUBLEBYTECHAR_MASK = 0x18;

        public const uint MTYPE_SINGLE = 0x08;

        public const uint MTYPE_DOUBLE = 0x10;

        public const uint MTYPE_PREDEFIN_MASK = 0xe0;

        public const uint MTYPE_REPLACE = 0x20;

        public const uint MTYPE_ADD = 0x40;

        public const uint MTYPE_DISABLE = 0x80;

        public const uint CC_NOPRECNV = 0x0000FFFF;

        public const uint CC_DEFAULT = 0;

        public const int CC_CP437 = -1;

        public const int CC_CP850 = -2;

        public const int CC_CP863 = -3;

        public const int CC_BIG5 = -10;

        public const int CC_ISC = -11;

        public const int CC_JIS = -12;

        public const int CC_JIS_ANK = -13;

        public const int CC_NS86 = -14;

        public const int CC_TCA = -15;

        public const int CC_GB2312 = -16;

        public const int CC_SJIS = -17;

        public const int CC_WANSUNG = -18;

        public const uint UFF_VERSION_NUMBER = 0x00010001;

        public const uint FONT_DIR_SORTED = 0x00000001;

        public const uint FONT_FL_UFM = 0x0001;

        public const uint FONT_FL_IFI = 0x0002;

        public const uint FONT_FL_SOFTFONT = 0x0004;

        public const uint FONT_FL_PERMANENT_SF = 0x0008;

        public const uint FONT_FL_DEVICEFONT = 0x0010;

        public const uint FONT_FL_GLYPHSET_GTT = 0x0020;

        public const uint FONT_FL_GLYPHSET_RLE = 0x0040;

        public const uint FONT_FL_RESERVED = 0x8000;

        public const uint FG_CANCHANGE = 0x00080;

        public const uint WM_FI_FILENAME = 900;

        public const uint RAWTCP = 1;

        public const uint LPR = 2;

        public const uint MAX_PORTNAME_LEN = 63 +1;

        public const uint MAX_NETWORKNAME_LEN = 48 +1;

        public const uint MAX_NETWORKNAME2_LEN = 128;

        public const uint MAX_SNMP_COMMUNITY_STR_LEN = 32 +1;

        public const uint MAX_QUEUENAME_LEN = 32 +1;

        public const uint MAX_IPADDR_STR_LEN = 15 +1;

        public const uint MAX_ADDRESS_STR_LEN = 12 +1;

        public const uint MAX_DEVICEDESCRIPTION_STR_LEN = 256+1;

        public const uint DPS_NOPERMISSION = 0x0001;

        public const uint DM_ADVANCED = 0x10;

        public const uint DM_NOPERMISSION = 0x20;

        public const uint DM_USER_DEFAULT = 0x40;

        public const uint DM_PROMPT_NON_MODAL = 0x40000000;

        public const uint DM_INVALIDATE_DRIVER_CACHE = 0x20000000;

        public const uint DM_RESERVED = 0x80000000;

        public const uint CDM_CONVERT = 0x01;

        public const uint CDM_CONVERT351 = 0x02;

        public const uint CDM_DRIVER_DEFAULT = 0x04;

        public const uint DOCUMENTEVENT_FIRST = 1;

        public const uint DOCUMENTEVENT_CREATEDCPRE = 1;

        public const uint DOCUMENTEVENT_CREATEDCPOST = 2;

        public const uint DOCUMENTEVENT_RESETDCPRE = 3;

        public const uint DOCUMENTEVENT_RESETDCPOST = 4;

        public const uint DOCUMENTEVENT_STARTDOC = 5;

        public const uint DOCUMENTEVENT_STARTDOCPRE = 5;

        public const uint DOCUMENTEVENT_STARTPAGE = 6;

        public const uint DOCUMENTEVENT_ENDPAGE = 7;

        public const uint DOCUMENTEVENT_ENDDOC = 8;

        public const uint DOCUMENTEVENT_ENDDOCPRE = 8;

        public const uint DOCUMENTEVENT_ABORTDOC = 9;

        public const uint DOCUMENTEVENT_DELETEDC = 10;

        public const uint DOCUMENTEVENT_ESCAPE = 11;

        public const uint DOCUMENTEVENT_ENDDOCPOST = 12;

        public const uint DOCUMENTEVENT_STARTDOCPOST = 13;

        public const uint DOCUMENTEVENT_QUERYFILTER = 14;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTSEQUENCEPRE = 1;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTPRE = 2;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDPAGEEPRE = 3;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDPAGEPOST = 4;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTPOST = 5;

        public const uint DOCUMENTEVENT_XPS_CANCELJOB = 6;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTSEQUENCEPRINTTICKETPRE = 7;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTPRINTTICKETPRE = 8;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDPAGEPRINTTICKETPRE = 9;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDPAGEPRINTTICKETPOST = 10;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTPRINTTICKETPOST = 11;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTSEQUENCEPRINTTICKETPOST = 12;

        public const uint DOCUMENTEVENT_XPS_ADDFIXEDDOCUMENTSEQUENCEPOST = 13;

        public const uint DOCUMENTEVENT_LAST = 15;

        public const uint DOCUMENTEVENT_SPOOLED = 0x10000;

        public const uint DOCUMENTEVENT_SUCCESS = 1;

        public const uint DOCUMENTEVENT_UNSUPPORTED = 0;

        public const int DOCUMENTEVENT_FAILURE = -1;

        public const uint PRINTER_EVENT_CONFIGURATION_CHANGE = 0;

        public const uint PRINTER_EVENT_ADD_CONNECTION = 1;

        public const uint PRINTER_EVENT_DELETE_CONNECTION = 2;

        public const uint PRINTER_EVENT_INITIALIZE = 3;

        public const uint PRINTER_EVENT_DELETE = 4;

        public const uint PRINTER_EVENT_CACHE_REFRESH = 5;

        public const uint PRINTER_EVENT_CACHE_DELETE = 6;

        public const uint PRINTER_EVENT_ATTRIBUTES_CHANGED = 7;

        public const uint PRINTER_EVENT_CONFIGURATION_UPDATE = 8;

        public const uint PRINTER_EVENT_ADD_CONNECTION_NO_UI = 9;

        public const uint PRINTER_EVENT_DELETE_CONNECTION_NO_UI = 10;

        public const uint PRINTER_EVENT_FLAG_NO_UI = 0x00000001;

        public const uint DRIVER_EVENT_INITIALIZE = 0x00000001;

        public const uint DRIVER_EVENT_DELETE = 0x00000002;

        public const uint BORDER_PRINT = 0x00000000;

        public const uint NO_BORDER_PRINT = 0x00000001;

        public const uint NORMAL_PRINT = 0x00000000;

        public const uint REVERSE_PRINT = 0x00000001;

        public const uint BOOKLET_PRINT = 0x00000002;

        public const uint NO_COLOR_OPTIMIZATION = 0x00000000;

        public const uint COLOR_OPTIMIZATION = 0x00000001;

        public const uint QCP_DEVICEPROFILE = 0x0000;

        public const uint QCP_SOURCEPROFILE = 0x0001;

        public const uint QCP_PROFILEMEMORY = 0x0001;

        public const uint QCP_PROFILEDISK = 0x0002;

        public const uint EMF_PP_COLOR_OPTIMIZATION = 0x01;

        public const uint PRINTER_NOTIFY_STATUS_ENDPOINT = 1;

        public const uint PRINTER_NOTIFY_STATUS_POLL = 2;

        public const uint PRINTER_NOTIFY_STATUS_INFO = 4;

        public const uint ROUTER_UNKNOWN = 0;

        public const uint ROUTER_SUCCESS = 1;

        public const uint ROUTER_STOP_ROUTING = 2;

        public const uint PRINTER_NOTIFY_INFO_DATA_COMPACT = 1;

        public const uint COPYFILE_EVENT_SET_PRINTER_DATAEX = 1;

        public const uint COPYFILE_EVENT_DELETE_PRINTER = 2;

        public const uint COPYFILE_EVENT_ADD_PRINTER_CONNECTION = 3;

        public const uint COPYFILE_EVENT_DELETE_PRINTER_CONNECTION = 4;

        public const uint COPYFILE_EVENT_FILES_CHANGED = 5;

        public const uint COPYFILE_FLAG_CLIENT_SPOOLER = 0x00000001;

        public const uint COPYFILE_FLAG_SERVER_SPOOLER = 0x00000002;

        public const uint DSPRINT_PUBLISH = 0x00000001;

        public const uint DSPRINT_UPDATE = 0x00000002;

        public const uint DSPRINT_UNPUBLISH = 0x00000004;

        public const uint DSPRINT_REPUBLISH = 0x00000008;

        public const uint DSPRINT_PENDING = 0x80000000;

        public const uint PRINTER_CONTROL_PAUSE = 1;

        public const uint PRINTER_CONTROL_RESUME = 2;

        public const uint PRINTER_CONTROL_PURGE = 3;

        public const uint PRINTER_CONTROL_SET_STATUS = 4;

        public const uint PRINTER_STATUS_PAUSED = 0x00000001;

        public const uint PRINTER_STATUS_ERROR = 0x00000002;

        public const uint PRINTER_STATUS_PENDING_DELETION = 0x00000004;

        public const uint PRINTER_STATUS_PAPER_JAM = 0x00000008;

        public const uint PRINTER_STATUS_PAPER_OUT = 0x00000010;

        public const uint PRINTER_STATUS_MANUAL_FEED = 0x00000020;

        public const uint PRINTER_STATUS_PAPER_PROBLEM = 0x00000040;

        public const uint PRINTER_STATUS_OFFLINE = 0x00000080;

        public const uint PRINTER_STATUS_IO_ACTIVE = 0x00000100;

        public const uint PRINTER_STATUS_BUSY = 0x00000200;

        public const uint PRINTER_STATUS_PRINTING = 0x00000400;

        public const uint PRINTER_STATUS_OUTPUT_BIN_FULL = 0x00000800;

        public const uint PRINTER_STATUS_NOT_AVAILABLE = 0x00001000;

        public const uint PRINTER_STATUS_WAITING = 0x00002000;

        public const uint PRINTER_STATUS_PROCESSING = 0x00004000;

        public const uint PRINTER_STATUS_INITIALIZING = 0x00008000;

        public const uint PRINTER_STATUS_WARMING_UP = 0x00010000;

        public const uint PRINTER_STATUS_TONER_LOW = 0x00020000;

        public const uint PRINTER_STATUS_NO_TONER = 0x00040000;

        public const uint PRINTER_STATUS_PAGE_PUNT = 0x00080000;

        public const uint PRINTER_STATUS_USER_INTERVENTION = 0x00100000;

        public const uint PRINTER_STATUS_OUT_OF_MEMORY = 0x00200000;

        public const uint PRINTER_STATUS_DOOR_OPEN = 0x00400000;

        public const uint PRINTER_STATUS_SERVER_UNKNOWN = 0x00800000;

        public const uint PRINTER_STATUS_POWER_SAVE = 0x01000000;

        public const uint PRINTER_STATUS_SERVER_OFFLINE = 0x02000000;

        public const uint PRINTER_STATUS_DRIVER_UPDATE_NEEDED = 0x04000000;

        public const uint PRINTER_ATTRIBUTE_QUEUED = 0x00000001;

        public const uint PRINTER_ATTRIBUTE_DIRECT = 0x00000002;

        public const uint PRINTER_ATTRIBUTE_DEFAULT = 0x00000004;

        public const uint PRINTER_ATTRIBUTE_SHARED = 0x00000008;

        public const uint PRINTER_ATTRIBUTE_NETWORK = 0x00000010;

        public const uint PRINTER_ATTRIBUTE_HIDDEN = 0x00000020;

        public const uint PRINTER_ATTRIBUTE_LOCAL = 0x00000040;

        public const uint PRINTER_ATTRIBUTE_ENABLE_DEVQ = 0x00000080;

        public const uint PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS = 0x00000100;

        public const uint PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST = 0x00000200;

        public const uint PRINTER_ATTRIBUTE_WORK_OFFLINE = 0x00000400;

        public const uint PRINTER_ATTRIBUTE_ENABLE_BIDI = 0x00000800;

        public const uint PRINTER_ATTRIBUTE_RAW_ONLY = 0x00001000;

        public const uint PRINTER_ATTRIBUTE_PUBLISHED = 0x00002000;

        public const uint NO_PRIORITY = 0;

        public const uint MAX_PRIORITY = 99;

        public const uint MIN_PRIORITY = 1;

        public const uint DEF_PRIORITY = 1;

        public const uint JOB_CONTROL_PAUSE = 1;

        public const uint JOB_CONTROL_RESUME = 2;

        public const uint JOB_CONTROL_CANCEL = 3;

        public const uint JOB_CONTROL_RESTART = 4;

        public const uint JOB_CONTROL_DELETE = 5;

        public const uint JOB_CONTROL_SENT_TO_PRINTER = 6;

        public const uint JOB_CONTROL_LAST_PAGE_EJECTED = 7;

        public const uint JOB_STATUS_PAUSED = 0x00000001;

        public const uint JOB_STATUS_ERROR = 0x00000002;

        public const uint JOB_STATUS_DELETING = 0x00000004;

        public const uint JOB_STATUS_SPOOLING = 0x00000008;

        public const uint JOB_STATUS_PRINTING = 0x00000010;

        public const uint JOB_STATUS_OFFLINE = 0x00000020;

        public const uint JOB_STATUS_PAPEROUT = 0x00000040;

        public const uint JOB_STATUS_PRINTED = 0x00000080;

        public const uint JOB_STATUS_DELETED = 0x00000100;

        public const uint JOB_STATUS_BLOCKED_DEVQ = 0x00000200;

        public const uint JOB_STATUS_USER_INTERVENTION = 0x00000400;

        public const uint JOB_STATUS_RESTART = 0x00000800;

        public const uint JOB_POSITION_UNSPECIFIED = 0;

        public const uint PRINTER_DRIVER_PACKAGE_AWARE = 0x00000001;

        public const uint PRINTER_DRIVER_XPS = 0x00000002;

        public const uint PRINTER_DRIVER_SANDBOX_ENABLED = 0x00000004;

        public const uint PRINTER_DRIVER_CLASS = 0x00000008;

        public const uint PRINTER_DRIVER_DERIVED = 0x00000010;

        public const uint PRINTER_DRIVER_NOT_SHAREABLE = 0x00000020;

        public const uint PRINTER_DRIVER_CATEGORY_FAX = 0x00000040;

        public const uint PRINTER_DRIVER_CATEGORY_FILE = 0x00000080;

        public const uint PRINTER_DRIVER_CATEGORY_VIRTUAL = 0x00000100;

        public const uint PRINTER_DRIVER_CATEGORY_SERVICE = 0x00000200;

        public const uint PRINTER_DRIVER_SOFT_RESET_REQUIRED = 0x00000400;

        public const uint PRINTER_DRIVER_SANDBOX_DISABLED = 0x00000800;

        public const uint PRINTER_DRIVER_CATEGORY_3D = 0x00001000;

        public const uint PRINTER_DRIVER_CATEGORY_CLOUD = 0x00002000;

        public const uint DRIVER_KERNELMODE = 0x00000001;

        public const uint DRIVER_USERMODE = 0x00000002;

        public const uint DPD_DELETE_UNUSED_FILES = 0x00000001;

        public const uint DPD_DELETE_SPECIFIC_VERSION = 0x00000002;

        public const uint DPD_DELETE_ALL_FILES = 0x00000004;

        public const uint APD_STRICT_UPGRADE = 0x00000001;

        public const uint APD_STRICT_DOWNGRADE = 0x00000002;

        public const uint APD_COPY_ALL_FILES = 0x00000004;

        public const uint APD_COPY_NEW_FILES = 0x00000008;

        public const uint DI_CHANNEL = 1;

        public const uint DI_READ_SPOOL_JOB = 3;

        public const uint DI_MEMORYMAP_WRITE = 0x00000001;

        public const uint FORM_USER = 0x00000000;

        public const uint FORM_BUILTIN = 0x00000001;

        public const uint FORM_PRINTER = 0x00000002;

        public const uint PORT_TYPE_WRITE = 0x0001;

        public const uint PORT_TYPE_READ = 0x0002;

        public const uint PORT_TYPE_REDIRECTED = 0x0004;

        public const uint PORT_TYPE_NET_ATTACHED = 0x0008;

        public const uint PORT_STATUS_TYPE_ERROR = 1;

        public const uint PORT_STATUS_TYPE_WARNING = 2;

        public const uint PORT_STATUS_TYPE_INFO = 3;

        public const uint PORT_STATUS_OFFLINE = 1;

        public const uint PORT_STATUS_PAPER_JAM = 2;

        public const uint PORT_STATUS_PAPER_OUT = 3;

        public const uint PORT_STATUS_OUTPUT_BIN_FULL = 4;

        public const uint PORT_STATUS_PAPER_PROBLEM = 5;

        public const uint PORT_STATUS_NO_TONER = 6;

        public const uint PORT_STATUS_DOOR_OPEN = 7;

        public const uint PORT_STATUS_USER_INTERVENTION = 8;

        public const uint PORT_STATUS_OUT_OF_MEMORY = 9;

        public const uint PORT_STATUS_TONER_LOW = 10;

        public const uint PORT_STATUS_WARMING_UP = 11;

        public const uint PORT_STATUS_POWER_SAVE = 12;

        public const uint PRINTER_ENUM_DEFAULT = 0x00000001;

        public const uint PRINTER_ENUM_LOCAL = 0x00000002;

        public const uint PRINTER_ENUM_CONNECTIONS = 0x00000004;

        public const uint PRINTER_ENUM_FAVORITE = 0x00000004;

        public const uint PRINTER_ENUM_NAME = 0x00000008;

        public const uint PRINTER_ENUM_REMOTE = 0x00000010;

        public const uint PRINTER_ENUM_SHARED = 0x00000020;

        public const uint PRINTER_ENUM_NETWORK = 0x00000040;

        public const uint PRINTER_ENUM_EXPAND = 0x00004000;

        public const uint PRINTER_ENUM_CONTAINER = 0x00008000;

        public const uint PRINTER_ENUM_ICONMASK = 0x00ff0000;

        public const uint PRINTER_ENUM_ICON1 = 0x00010000;

        public const uint PRINTER_ENUM_ICON2 = 0x00020000;

        public const uint PRINTER_ENUM_ICON3 = 0x00040000;

        public const uint PRINTER_ENUM_ICON4 = 0x00080000;

        public const uint PRINTER_ENUM_ICON5 = 0x00100000;

        public const uint PRINTER_ENUM_ICON6 = 0x00200000;

        public const uint PRINTER_ENUM_ICON7 = 0x00400000;

        public const uint PRINTER_ENUM_ICON8 = 0x00800000;

        public const uint PRINTER_ENUM_HIDE = 0x01000000;

        public const uint PRINTER_ENUM_CATEGORY_ALL = 0x02000000;

        public const uint PRINTER_ENUM_CATEGORY_3D = 0x04000000;

        public const uint SPOOL_FILE_PERSISTENT = 0x00000001;

        public const uint SPOOL_FILE_TEMPORARY = 0x00000002;

        public const uint PRINTER_NOTIFY_TYPE = 0x00;

        public const uint JOB_NOTIFY_TYPE = 0x01;

        public const uint SERVER_NOTIFY_TYPE = 0x02;

        public const uint PRINTER_NOTIFY_FIELD_SERVER_NAME = 0x00;

        public const uint PRINTER_NOTIFY_FIELD_PRINTER_NAME = 0x01;

        public const uint PRINTER_NOTIFY_FIELD_SHARE_NAME = 0x02;

        public const uint PRINTER_NOTIFY_FIELD_PORT_NAME = 0x03;

        public const uint PRINTER_NOTIFY_FIELD_DRIVER_NAME = 0x04;

        public const uint PRINTER_NOTIFY_FIELD_COMMENT = 0x05;

        public const uint PRINTER_NOTIFY_FIELD_LOCATION = 0x06;

        public const uint PRINTER_NOTIFY_FIELD_DEVMODE = 0x07;

        public const uint PRINTER_NOTIFY_FIELD_SEPFILE = 0x08;

        public const uint PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR = 0x09;

        public const uint PRINTER_NOTIFY_FIELD_PARAMETERS = 0x0A;

        public const uint PRINTER_NOTIFY_FIELD_DATATYPE = 0x0B;

        public const uint PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR = 0x0C;

        public const uint PRINTER_NOTIFY_FIELD_ATTRIBUTES = 0x0D;

        public const uint PRINTER_NOTIFY_FIELD_PRIORITY = 0x0E;

        public const uint PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY = 0x0F;

        public const uint PRINTER_NOTIFY_FIELD_START_TIME = 0x10;

        public const uint PRINTER_NOTIFY_FIELD_UNTIL_TIME = 0x11;

        public const uint PRINTER_NOTIFY_FIELD_STATUS = 0x12;

        public const uint PRINTER_NOTIFY_FIELD_STATUS_STRING = 0x13;

        public const uint PRINTER_NOTIFY_FIELD_CJOBS = 0x14;

        public const uint PRINTER_NOTIFY_FIELD_AVERAGE_PPM = 0x15;

        public const uint PRINTER_NOTIFY_FIELD_TOTAL_PAGES = 0x16;

        public const uint PRINTER_NOTIFY_FIELD_PAGES_PRINTED = 0x17;

        public const uint PRINTER_NOTIFY_FIELD_TOTAL_BYTES = 0x18;

        public const uint PRINTER_NOTIFY_FIELD_BYTES_PRINTED = 0x19;

        public const uint PRINTER_NOTIFY_FIELD_OBJECT_GUID = 0x1A;

        public const uint JOB_NOTIFY_FIELD_PRINTER_NAME = 0x00;

        public const uint JOB_NOTIFY_FIELD_MACHINE_NAME = 0x01;

        public const uint JOB_NOTIFY_FIELD_PORT_NAME = 0x02;

        public const uint JOB_NOTIFY_FIELD_USER_NAME = 0x03;

        public const uint JOB_NOTIFY_FIELD_NOTIFY_NAME = 0x04;

        public const uint JOB_NOTIFY_FIELD_DATATYPE = 0x05;

        public const uint JOB_NOTIFY_FIELD_PRINT_PROCESSOR = 0x06;

        public const uint JOB_NOTIFY_FIELD_PARAMETERS = 0x07;

        public const uint JOB_NOTIFY_FIELD_DRIVER_NAME = 0x08;

        public const uint JOB_NOTIFY_FIELD_DEVMODE = 0x09;

        public const uint JOB_NOTIFY_FIELD_STATUS = 0x0A;

        public const uint JOB_NOTIFY_FIELD_STATUS_STRING = 0x0B;

        public const uint JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR = 0x0C;

        public const uint JOB_NOTIFY_FIELD_DOCUMENT = 0x0D;

        public const uint JOB_NOTIFY_FIELD_PRIORITY = 0x0E;

        public const uint JOB_NOTIFY_FIELD_POSITION = 0x0F;

        public const uint JOB_NOTIFY_FIELD_SUBMITTED = 0x10;

        public const uint JOB_NOTIFY_FIELD_START_TIME = 0x11;

        public const uint JOB_NOTIFY_FIELD_UNTIL_TIME = 0x12;

        public const uint JOB_NOTIFY_FIELD_TIME = 0x13;

        public const uint JOB_NOTIFY_FIELD_TOTAL_PAGES = 0x14;

        public const uint JOB_NOTIFY_FIELD_PAGES_PRINTED = 0x15;

        public const uint JOB_NOTIFY_FIELD_TOTAL_BYTES = 0x16;

        public const uint JOB_NOTIFY_FIELD_BYTES_PRINTED = 0x17;

        public const uint JOB_NOTIFY_FIELD_REMOTE_JOB_ID = 0x18;

        public const uint PRINTER_NOTIFY_OPTIONS_REFRESH = 0x01;

        public const uint PRINTER_NOTIFY_INFO_DISCARDED = 0x01;

        public const uint PRINTER_CHANGE_ADD_PRINTER = 0x00000001;

        public const uint PRINTER_CHANGE_SET_PRINTER = 0x00000002;

        public const uint PRINTER_CHANGE_DELETE_PRINTER = 0x00000004;

        public const uint PRINTER_CHANGE_FAILED_CONNECTION_PRINTER = 0x00000008;

        public const uint PRINTER_CHANGE_PRINTER = 0x000000FF;

        public const uint PRINTER_CHANGE_ADD_JOB = 0x00000100;

        public const uint PRINTER_CHANGE_SET_JOB = 0x00000200;

        public const uint PRINTER_CHANGE_DELETE_JOB = 0x00000400;

        public const uint PRINTER_CHANGE_WRITE_JOB = 0x00000800;

        public const uint PRINTER_CHANGE_JOB = 0x0000FF00;

        public const uint PRINTER_CHANGE_ADD_FORM = 0x00010000;

        public const uint PRINTER_CHANGE_SET_FORM = 0x00020000;

        public const uint PRINTER_CHANGE_DELETE_FORM = 0x00040000;

        public const uint PRINTER_CHANGE_FORM = 0x00070000;

        public const uint PRINTER_CHANGE_ADD_PORT = 0x00100000;

        public const uint PRINTER_CHANGE_CONFIGURE_PORT = 0x00200000;

        public const uint PRINTER_CHANGE_DELETE_PORT = 0x00400000;

        public const uint PRINTER_CHANGE_PORT = 0x00700000;

        public const uint PRINTER_CHANGE_ADD_PRINT_PROCESSOR = 0x01000000;

        public const uint PRINTER_CHANGE_DELETE_PRINT_PROCESSOR = 0x04000000;

        public const uint PRINTER_CHANGE_PRINT_PROCESSOR = 0x07000000;

        public const uint PRINTER_CHANGE_SERVER = 0x08000000;

        public const uint PRINTER_CHANGE_ADD_PRINTER_DRIVER = 0x10000000;

        public const uint PRINTER_CHANGE_SET_PRINTER_DRIVER = 0x20000000;

        public const uint PRINTER_CHANGE_DELETE_PRINTER_DRIVER = 0x40000000;

        public const uint PRINTER_CHANGE_PRINTER_DRIVER = 0x70000000;

        public const uint PRINTER_CHANGE_TIMEOUT = 0x80000000;

        public const uint PRINTER_CHANGE_ALL = 0x7F77FFFF;

        public const uint PRINTER_ERROR_INFORMATION = 0x80000000;

        public const uint PRINTER_ERROR_WARNING = 0x40000000;

        public const uint PRINTER_ERROR_SEVERE = 0x20000000;

        public const uint PRINTER_ERROR_OUTOFPAPER = 0x00000001;

        public const uint PRINTER_ERROR_JAM = 0x00000002;

        public const uint PRINTER_ERROR_OUTOFTONER = 0x00000004;

        public const uint SERVER_ACCESS_ADMINISTER = 0x00000001;

        public const uint SERVER_ACCESS_ENUMERATE = 0x00000002;

        public const uint PRINTER_ACCESS_ADMINISTER = 0x00000004;

        public const uint PRINTER_ACCESS_USE = 0x00000008;

        public const uint JOB_ACCESS_ADMINISTER = 0x00000010;

        public const uint PRINTER_ACCESS_MANAGE_LIMITED = 0x00000040;

        public const uint IPDFP_COPY_ALL_FILES = 0x00000001;

        public const uint UPDP_SILENT_UPLOAD = 0x00000001;

        public const uint UPDP_UPLOAD_ALWAYS = 0x00000002;

        public const uint UPDP_CHECK_DRIVERSTORE = 0x00000004;

    }
}
