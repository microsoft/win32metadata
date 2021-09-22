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


namespace Windows.Win32.Devices.ImageAcquisition
{
    public static partial class Apis
    {
        public const uint WIA_DIP_DEV_ID = 2;

        public const uint WIA_DIP_VEND_DESC = 3;

        public const uint WIA_DIP_DEV_DESC = 4;

        public const uint WIA_DIP_DEV_TYPE = 5;

        public const uint WIA_DIP_PORT_NAME = 6;

        public const uint WIA_DIP_DEV_NAME = 7;

        public const uint WIA_DIP_SERVER_NAME = 8;

        public const uint WIA_DIP_REMOTE_DEV_ID = 9;

        public const uint WIA_DIP_UI_CLSID = 10;

        public const uint WIA_DIP_HW_CONFIG = 11;

        public const uint WIA_DIP_BAUDRATE = 12;

        public const uint WIA_DIP_STI_GEN_CAPABILITIES = 13;

        public const uint WIA_DIP_WIA_VERSION = 14;

        public const uint WIA_DIP_DRIVER_VERSION = 15;

        public const uint WIA_DIP_PNP_ID = 16;

        public const uint WIA_DIP_STI_DRIVER_VERSION = 17;

        public const uint WIA_DPA_FIRMWARE_VERSION = 1026;

        public const uint WIA_DPA_CONNECT_STATUS = 1027;

        public const uint WIA_DPA_DEVICE_TIME = 1028;

        public const uint WIA_DPC_PICTURES_TAKEN = 2050;

        public const uint WIA_DPC_PICTURES_REMAINING = 2051;

        public const uint WIA_DPC_EXPOSURE_MODE = 2052;

        public const uint WIA_DPC_EXPOSURE_COMP = 2053;

        public const uint WIA_DPC_EXPOSURE_TIME = 2054;

        public const uint WIA_DPC_FNUMBER = 2055;

        public const uint WIA_DPC_FLASH_MODE = 2056;

        public const uint WIA_DPC_FOCUS_MODE = 2057;

        public const uint WIA_DPC_FOCUS_MANUAL_DIST = 2058;

        public const uint WIA_DPC_ZOOM_POSITION = 2059;

        public const uint WIA_DPC_PAN_POSITION = 2060;

        public const uint WIA_DPC_TILT_POSITION = 2061;

        public const uint WIA_DPC_TIMER_MODE = 2062;

        public const uint WIA_DPC_TIMER_VALUE = 2063;

        public const uint WIA_DPC_POWER_MODE = 2064;

        public const uint WIA_DPC_BATTERY_STATUS = 2065;

        public const uint WIA_DPC_THUMB_WIDTH = 2066;

        public const uint WIA_DPC_THUMB_HEIGHT = 2067;

        public const uint WIA_DPC_PICT_WIDTH = 2068;

        public const uint WIA_DPC_PICT_HEIGHT = 2069;

        public const uint WIA_DPC_DIMENSION = 2070;

        public const uint WIA_DPC_COMPRESSION_SETTING = 2071;

        public const uint WIA_DPC_FOCUS_METERING = 2072;

        public const uint WIA_DPC_TIMELAPSE_INTERVAL = 2073;

        public const uint WIA_DPC_TIMELAPSE_NUMBER = 2074;

        public const uint WIA_DPC_BURST_INTERVAL = 2075;

        public const uint WIA_DPC_BURST_NUMBER = 2076;

        public const uint WIA_DPC_EFFECT_MODE = 2077;

        public const uint WIA_DPC_DIGITAL_ZOOM = 2078;

        public const uint WIA_DPC_SHARPNESS = 2079;

        public const uint WIA_DPC_CONTRAST = 2080;

        public const uint WIA_DPC_CAPTURE_MODE = 2081;

        public const uint WIA_DPC_CAPTURE_DELAY = 2082;

        public const uint WIA_DPC_EXPOSURE_INDEX = 2083;

        public const uint WIA_DPC_EXPOSURE_METERING_MODE = 2084;

        public const uint WIA_DPC_FOCUS_METERING_MODE = 2085;

        public const uint WIA_DPC_FOCUS_DISTANCE = 2086;

        public const uint WIA_DPC_FOCAL_LENGTH = 2087;

        public const uint WIA_DPC_RGB_GAIN = 2088;

        public const uint WIA_DPC_WHITE_BALANCE = 2089;

        public const uint WIA_DPC_UPLOAD_URL = 2090;

        public const uint WIA_DPC_ARTIST = 2091;

        public const uint WIA_DPC_COPYRIGHT_INFO = 2092;

        public const uint WIA_DPS_HORIZONTAL_BED_SIZE = 3074;

        public const uint WIA_DPS_VERTICAL_BED_SIZE = 3075;

        public const uint WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE = 3076;

        public const uint WIA_DPS_VERTICAL_SHEET_FEED_SIZE = 3077;

        public const uint WIA_DPS_SHEET_FEEDER_REGISTRATION = 3078;

        public const uint WIA_DPS_HORIZONTAL_BED_REGISTRATION = 3079;

        public const uint WIA_DPS_VERTICAL_BED_REGISTRATION = 3080;

        public const uint WIA_DPS_PLATEN_COLOR = 3081;

        public const uint WIA_DPS_PAD_COLOR = 3082;

        public const uint WIA_DPS_FILTER_SELECT = 3083;

        public const uint WIA_DPS_DITHER_SELECT = 3084;

        public const uint WIA_DPS_DITHER_PATTERN_DATA = 3085;

        public const uint WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES = 3086;

        public const uint WIA_DPS_DOCUMENT_HANDLING_STATUS = 3087;

        public const uint WIA_DPS_DOCUMENT_HANDLING_SELECT = 3088;

        public const uint WIA_DPS_DOCUMENT_HANDLING_CAPACITY = 3089;

        public const uint WIA_DPS_OPTICAL_XRES = 3090;

        public const uint WIA_DPS_OPTICAL_YRES = 3091;

        public const uint WIA_DPS_ENDORSER_CHARACTERS = 3092;

        public const uint WIA_DPS_ENDORSER_STRING = 3093;

        public const uint WIA_DPS_SCAN_AHEAD_PAGES = 3094;

        public const uint WIA_DPS_MAX_SCAN_TIME = 3095;

        public const uint WIA_DPS_PAGES = 3096;

        public const uint WIA_DPS_PAGE_SIZE = 3097;

        public const uint WIA_DPS_PAGE_WIDTH = 3098;

        public const uint WIA_DPS_PAGE_HEIGHT = 3099;

        public const uint WIA_DPS_PREVIEW = 3100;

        public const uint WIA_DPS_TRANSPARENCY = 3101;

        public const uint WIA_DPS_TRANSPARENCY_SELECT = 3102;

        public const uint WIA_DPS_SHOW_PREVIEW_CONTROL = 3103;

        public const uint WIA_DPS_MIN_HORIZONTAL_SHEET_FEED_SIZE = 3104;

        public const uint WIA_DPS_MIN_VERTICAL_SHEET_FEED_SIZE = 3105;

        public const uint WIA_DPS_TRANSPARENCY_CAPABILITIES = 3106;

        public const uint WIA_DPS_TRANSPARENCY_STATUS = 3107;

        public const uint WIA_DPF_MOUNT_POINT = 3330;

        public const uint WIA_DPV_LAST_PICTURE_TAKEN = 3586;

        public const uint WIA_DPV_IMAGES_DIRECTORY = 3587;

        public const uint WIA_DPV_DSHOW_DEVICE_PATH = 3588;

        public const uint WIA_IPA_ITEM_NAME = 4098;

        public const uint WIA_IPA_FULL_ITEM_NAME = 4099;

        public const uint WIA_IPA_ITEM_TIME = 4100;

        public const uint WIA_IPA_ITEM_FLAGS = 4101;

        public const uint WIA_IPA_ACCESS_RIGHTS = 4102;

        public const uint WIA_IPA_DATATYPE = 4103;

        public const uint WIA_IPA_DEPTH = 4104;

        public const uint WIA_IPA_PREFERRED_FORMAT = 4105;

        public const uint WIA_IPA_FORMAT = 4106;

        public const uint WIA_IPA_COMPRESSION = 4107;

        public const uint WIA_IPA_TYMED = 4108;

        public const uint WIA_IPA_CHANNELS_PER_PIXEL = 4109;

        public const uint WIA_IPA_BITS_PER_CHANNEL = 4110;

        public const uint WIA_IPA_PLANAR = 4111;

        public const uint WIA_IPA_PIXELS_PER_LINE = 4112;

        public const uint WIA_IPA_BYTES_PER_LINE = 4113;

        public const uint WIA_IPA_NUMBER_OF_LINES = 4114;

        public const uint WIA_IPA_GAMMA_CURVES = 4115;

        public const uint WIA_IPA_ITEM_SIZE = 4116;

        public const uint WIA_IPA_COLOR_PROFILE = 4117;

        public const uint WIA_IPA_MIN_BUFFER_SIZE = 4118;

        public const uint WIA_IPA_BUFFER_SIZE = 4118;

        public const uint WIA_IPA_REGION_TYPE = 4119;

        public const uint WIA_IPA_ICM_PROFILE_NAME = 4120;

        public const uint WIA_IPA_APP_COLOR_MAPPING = 4121;

        public const uint WIA_IPA_PROP_STREAM_COMPAT_ID = 4122;

        public const uint WIA_IPA_FILENAME_EXTENSION = 4123;

        public const uint WIA_IPA_SUPPRESS_PROPERTY_PAGE = 4124;

        public const uint WIA_IPC_THUMBNAIL = 5122;

        public const uint WIA_IPC_THUMB_WIDTH = 5123;

        public const uint WIA_IPC_THUMB_HEIGHT = 5124;

        public const uint WIA_IPC_AUDIO_AVAILABLE = 5125;

        public const uint WIA_IPC_AUDIO_DATA_FORMAT = 5126;

        public const uint WIA_IPC_AUDIO_DATA = 5127;

        public const uint WIA_IPC_NUM_PICT_PER_ROW = 5128;

        public const uint WIA_IPC_SEQUENCE = 5129;

        public const uint WIA_IPC_TIMEDELAY = 5130;

        public const uint WIA_IPS_CUR_INTENT = 6146;

        public const uint WIA_IPS_XRES = 6147;

        public const uint WIA_IPS_YRES = 6148;

        public const uint WIA_IPS_XPOS = 6149;

        public const uint WIA_IPS_YPOS = 6150;

        public const uint WIA_IPS_XEXTENT = 6151;

        public const uint WIA_IPS_YEXTENT = 6152;

        public const uint WIA_IPS_PHOTOMETRIC_INTERP = 6153;

        public const uint WIA_IPS_BRIGHTNESS = 6154;

        public const uint WIA_IPS_CONTRAST = 6155;

        public const uint WIA_IPS_ORIENTATION = 6156;

        public const uint WIA_IPS_ROTATION = 6157;

        public const uint WIA_IPS_MIRROR = 6158;

        public const uint WIA_IPS_THRESHOLD = 6159;

        public const uint WIA_IPS_INVERT = 6160;

        public const uint WIA_IPS_WARM_UP_TIME = 6161;

        public const uint WIA_DPS_USER_NAME = 3112;

        public const uint WIA_DPS_SERVICE_ID = 3113;

        public const uint WIA_DPS_DEVICE_ID = 3114;

        public const uint WIA_DPS_GLOBAL_IDENTITY = 3115;

        public const uint WIA_DPS_SCAN_AVAILABLE_ITEM = 3116;

        public const uint WIA_IPS_DESKEW_X = 6162;

        public const uint WIA_IPS_DESKEW_Y = 6163;

        public const uint WIA_IPS_SEGMENTATION = 6164;

        public const uint WIA_IPS_MAX_HORIZONTAL_SIZE = 6165;

        public const uint WIA_IPS_MAX_VERTICAL_SIZE = 6166;

        public const uint WIA_IPS_MIN_HORIZONTAL_SIZE = 6167;

        public const uint WIA_IPS_MIN_VERTICAL_SIZE = 6168;

        public const uint WIA_IPS_TRANSFER_CAPABILITIES = 6169;

        public const uint WIA_IPS_SHEET_FEEDER_REGISTRATION = 3078;

        public const uint WIA_IPS_DOCUMENT_HANDLING_SELECT = 3088;

        public const uint WIA_IPS_OPTICAL_XRES = 3090;

        public const uint WIA_IPS_OPTICAL_YRES = 3091;

        public const uint WIA_IPS_PAGES = 3096;

        public const uint WIA_IPS_PAGE_SIZE = 3097;

        public const uint WIA_IPS_PAGE_WIDTH = 3098;

        public const uint WIA_IPS_PAGE_HEIGHT = 3099;

        public const uint WIA_IPS_PREVIEW = 3100;

        public const uint WIA_IPS_SHOW_PREVIEW_CONTROL = 3103;

        public const uint WIA_IPS_FILM_SCAN_MODE = 3104;

        public const uint WIA_IPS_LAMP = 3105;

        public const uint WIA_IPS_LAMP_AUTO_OFF = 3106;

        public const uint WIA_IPS_AUTO_DESKEW = 3107;

        public const uint WIA_IPS_SUPPORTS_CHILD_ITEM_CREATION = 3108;

        public const uint WIA_IPS_XSCALING = 3109;

        public const uint WIA_IPS_YSCALING = 3110;

        public const uint WIA_IPS_PREVIEW_TYPE = 3111;

        public const uint WIA_IPA_ITEM_CATEGORY = 4125;

        public const uint WIA_IPA_UPLOAD_ITEM_SIZE = 4126;

        public const uint WIA_IPA_ITEMS_STORED = 4127;

        public const uint WIA_IPA_RAW_BITS_PER_CHANNEL = 4128;

        public const uint WIA_IPS_FILM_NODE_NAME = 4129;

        public const uint WIA_IPS_PRINTER_ENDORSER = 4130;

        public const uint WIA_IPS_PRINTER_ENDORSER_ORDER = 4131;

        public const uint WIA_IPS_PRINTER_ENDORSER_COUNTER = 4132;

        public const uint WIA_IPS_PRINTER_ENDORSER_STEP = 4133;

        public const uint WIA_IPS_PRINTER_ENDORSER_XOFFSET = 4134;

        public const uint WIA_IPS_PRINTER_ENDORSER_YOFFSET = 4135;

        public const uint WIA_IPS_PRINTER_ENDORSER_NUM_LINES = 4136;

        public const uint WIA_IPS_PRINTER_ENDORSER_STRING = 4137;

        public const uint WIA_IPS_PRINTER_ENDORSER_VALID_CHARACTERS = 4138;

        public const uint WIA_IPS_PRINTER_ENDORSER_VALID_FORMAT_SPECIFIERS = 4139;

        public const uint WIA_IPS_PRINTER_ENDORSER_TEXT_UPLOAD = 4140;

        public const uint WIA_IPS_PRINTER_ENDORSER_TEXT_DOWNLOAD = 4141;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS = 4142;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS_POSITION = 4143;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS_MIN_WIDTH = 4144;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS_MAX_WIDTH = 4145;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS_MIN_HEIGHT = 4146;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS_MAX_HEIGHT = 4147;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS_UPLOAD = 4148;

        public const uint WIA_IPS_PRINTER_ENDORSER_GRAPHICS_DOWNLOAD = 4149;

        public const uint WIA_IPS_BARCODE_READER = 4150;

        public const uint WIA_IPS_MAXIMUM_BARCODES_PER_PAGE = 4151;

        public const uint WIA_IPS_BARCODE_SEARCH_DIRECTION = 4152;

        public const uint WIA_IPS_MAXIMUM_BARCODE_SEARCH_RETRIES = 4153;

        public const uint WIA_IPS_BARCODE_SEARCH_TIMEOUT = 4154;

        public const uint WIA_IPS_SUPPORTED_BARCODE_TYPES = 4155;

        public const uint WIA_IPS_ENABLED_BARCODE_TYPES = 4156;

        public const uint WIA_IPS_PATCH_CODE_READER = 4157;

        public const uint WIA_IPS_SUPPORTED_PATCH_CODE_TYPES = 4162;

        public const uint WIA_IPS_ENABLED_PATCH_CODE_TYPES = 4163;

        public const uint WIA_IPS_MICR_READER = 4164;

        public const uint WIA_IPS_JOB_SEPARATORS = 4165;

        public const uint WIA_IPS_LONG_DOCUMENT = 4166;

        public const uint WIA_IPS_BLANK_PAGES = 4167;

        public const uint WIA_IPS_MULTI_FEED = 4168;

        public const uint WIA_IPS_MULTI_FEED_SENSITIVITY = 4169;

        public const uint WIA_IPS_AUTO_CROP = 4170;

        public const uint WIA_IPS_OVER_SCAN = 4171;

        public const uint WIA_IPS_OVER_SCAN_LEFT = 4172;

        public const uint WIA_IPS_OVER_SCAN_RIGHT = 4173;

        public const uint WIA_IPS_OVER_SCAN_TOP = 4174;

        public const uint WIA_IPS_OVER_SCAN_BOTTOM = 4175;

        public const uint WIA_IPS_COLOR_DROP = 4176;

        public const uint WIA_IPS_COLOR_DROP_RED = 4177;

        public const uint WIA_IPS_COLOR_DROP_GREEN = 4178;

        public const uint WIA_IPS_COLOR_DROP_BLUE = 4179;

        public const uint WIA_IPS_SCAN_AHEAD = 4180;

        public const uint WIA_IPS_SCAN_AHEAD_CAPACITY = 4181;

        public const uint WIA_IPS_FEEDER_CONTROL = 4182;

        public const uint WIA_IPS_PRINTER_ENDORSER_PADDING = 4183;

        public const uint WIA_IPS_PRINTER_ENDORSER_FONT_TYPE = 4184;

        public const uint WIA_IPS_ALARM = 4185;

        public const uint WIA_IPS_PRINTER_ENDORSER_INK = 4186;

        public const uint WIA_IPS_PRINTER_ENDORSER_CHARACTER_ROTATION = 4187;

        public const uint WIA_IPS_PRINTER_ENDORSER_MAX_CHARACTERS = 4188;

        public const uint WIA_IPS_PRINTER_ENDORSER_MAX_GRAPHICS = 4189;

        public const uint WIA_IPS_PRINTER_ENDORSER_COUNTER_DIGITS = 4190;

        public const uint WIA_IPS_COLOR_DROP_MULTI = 4191;

        public const uint WIA_IPS_BLANK_PAGES_SENSITIVITY = 4192;

        public const uint WIA_IPS_MULTI_FEED_DETECT_METHOD = 4193;

        public static readonly Guid WIA_CATEGORY_FINISHED_FILE__scanned__ = new Guid(0xff2b77ca, 0xcf84, 0x432b, 0xa7, 0x35, 0x3a, 0x13, 0x0d, 0xde, 0x2a, 0x88);

        public static readonly Guid WIA_CATEGORY_FLATBED__scanned__ = new Guid(0xfb607b1f, 0x43f3, 0x488b, 0x85, 0x5b, 0xfb, 0x70, 0x3e, 0xc3, 0x42, 0xa6);

        public static readonly Guid WIA_CATEGORY_FEEDER__scanned__ = new Guid(0xfe131934, 0xf84c, 0x42ad, 0x8d, 0xa4, 0x61, 0x29, 0xcd, 0xdd, 0x72, 0x88);

        public static readonly Guid WIA_CATEGORY_FILM__scanned__ = new Guid(0xfcf65be7, 0x3ce3, 0x4473, 0xaf, 0x85, 0xf5, 0xd3, 0x7d, 0x21, 0xb6, 0x8a);

        public static readonly Guid WIA_CATEGORY_ROOT__scanned__ = new Guid(0xf193526f, 0x59b8, 0x4a26, 0x98, 0x88, 0xe1, 0x6e, 0x4f, 0x97, 0xce, 0x10);

        public static readonly Guid WIA_CATEGORY_FOLDER__scanned__ = new Guid(0xc692a446, 0x6f5a, 0x481d, 0x85, 0xbb, 0x92, 0xe2, 0xe8, 0x6f, 0xd3, 0xa);

        public static readonly Guid WIA_CATEGORY_FEEDER_FRONT__scanned__ = new Guid(0x4823175c, 0x3b28, 0x487b, 0xa7, 0xe6, 0xee, 0xbc, 0x17, 0x61, 0x4f, 0xd1);

        public static readonly Guid WIA_CATEGORY_FEEDER_BACK__scanned__ = new Guid(0x61ca74d4, 0x39db, 0x42aa, 0x89, 0xb1, 0x8c, 0x19, 0xc9, 0xcd, 0x4c, 0x23);

        public static readonly Guid WIA_CATEGORY_AUTO__scanned__ = new Guid(0xdefe5fd8, 0x6c97, 0x4dde, 0xb1, 0x1e, 0xcb, 0x50, 0x9b, 0x27, 0x0e, 0x11);

        public static readonly Guid WIA_CATEGORY_IMPRINTER__scanned__ = new Guid(0xfc65016d, 0x9202, 0x43dd, 0x91, 0xa7, 0x64, 0xc2, 0x95, 0x4c, 0xfb, 0x8b);

        public static readonly Guid WIA_CATEGORY_ENDORSER__scanned__ = new Guid(0x47102cc3, 0x127f, 0x4771, 0xad, 0xfc, 0x99, 0x1a, 0xb8, 0xee, 0x1e, 0x97);

        public static readonly Guid WIA_CATEGORY_BARCODE_READER__scanned__ = new Guid(0x36e178a0, 0x473f, 0x494b, 0xaf, 0x8f, 0x6c, 0x3f, 0x6d, 0x74, 0x86, 0xfc);

        public static readonly Guid WIA_CATEGORY_PATCH_CODE_READER__scanned__ = new Guid(0x8faa1a6d, 0x9c8a, 0x42cd, 0x98, 0xb3, 0xee, 0x97, 0x00, 0xcb, 0xc7, 0x4f);

        public static readonly Guid WIA_CATEGORY_MICR_READER__scanned__ = new Guid(0x3b86c1ec, 0x71bc, 0x4645, 0xb4, 0xd5, 0x1b, 0x19, 0xda, 0x2b, 0xe9, 0x78);

        public static readonly Guid CLSID_WiaDefaultSegFilter__scanned__ = new Guid(0xD4F4D30B, 0x0B29, 0x4508, 0x89, 0x22, 0x0C, 0x57, 0x97, 0xD4, 0x27, 0x65);

        public const uint WIA_TRANSFER_CHILDREN_SINGLE_SCAN = 0x00000001;

        public const uint WIA_USE_SEGMENTATION_FILTER = 0;

        public const uint WIA_DONT_USE_SEGMENTATION_FILTER = 1;

        public const uint WIA_FILM_COLOR_SLIDE = 0;

        public const uint WIA_FILM_COLOR_NEGATIVE = 1;

        public const uint WIA_FILM_BW_NEGATIVE = 2;

        public const uint WIA_LAMP_ON = 0;

        public const uint WIA_LAMP_OFF = 1;

        public const uint WIA_AUTO_DESKEW_ON = 0;

        public const uint WIA_AUTO_DESKEW_OFF = 1;

        public const uint WIA_ADVANCED_PREVIEW = 0;

        public const uint WIA_BASIC_PREVIEW = 1;

        public const uint WIA_PRINTER_ENDORSER_DISABLED = 0;

        public const uint WIA_PRINTER_ENDORSER_AUTO = 1;

        public const uint WIA_PRINTER_ENDORSER_FLATBED = 2;

        public const uint WIA_PRINTER_ENDORSER_FEEDER_FRONT = 3;

        public const uint WIA_PRINTER_ENDORSER_FEEDER_BACK = 4;

        public const uint WIA_PRINTER_ENDORSER_FEEDER_DUPLEX = 5;

        public const uint WIA_PRINTER_ENDORSER_DIGITAL = 6;

        public const uint WIA_PRINTER_ENDORSER_BEFORE_SCAN = 0;

        public const uint WIA_PRINTER_ENDORSER_AFTER_SCAN = 1;

        public const uint WIA_PRINT_DATE = 0;

        public const uint WIA_PRINT_YEAR = 1;

        public const uint WIA_PRINT_MONTH = 2;

        public const uint WIA_PRINT_DAY = 3;

        public const uint WIA_PRINT_WEEK_DAY = 4;

        public const uint WIA_PRINT_TIME_24H = 5;

        public const uint WIA_PRINT_TIME_12H = 6;

        public const uint WIA_PRINT_HOUR_24H = 7;

        public const uint WIA_PRINT_HOUR_12H = 8;

        public const uint WIA_PRINT_AM_PM = 9;

        public const uint WIA_PRINT_MINUTE = 10;

        public const uint WIA_PRINT_SECOND = 11;

        public const uint WIA_PRINT_PAGE_COUNT = 12;

        public const uint WIA_PRINT_IMAGE = 13;

        public const uint WIA_PRINT_MILLISECOND = 14;

        public const uint WIA_PRINT_MONTH_NAME = 15;

        public const uint WIA_PRINT_MONTH_SHORT = 16;

        public const uint WIA_PRINT_WEEK_DAY_SHORT = 17;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_LEFT = 0;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_RIGHT = 1;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_TOP = 2;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_BOTTOM = 3;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_TOP_LEFT = 4;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_TOP_RIGHT = 5;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_BOTTOM_LEFT = 6;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_BOTTOM_RIGHT = 7;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_BACKGROUND = 8;

        public const uint WIA_PRINTER_ENDORSER_GRAPHICS_DEVICE_DEFAULT = 9;

        public const uint WIA_BARCODE_READER_DISABLED = 0;

        public const uint WIA_BARCODE_READER_AUTO = 1;

        public const uint WIA_BARCODE_READER_FLATBED = 2;

        public const uint WIA_BARCODE_READER_FEEDER_FRONT = 3;

        public const uint WIA_BARCODE_READER_FEEDER_BACK = 4;

        public const uint WIA_BARCODE_READER_FEEDER_DUPLEX = 5;

        public const uint WIA_BARCODE_HORIZONTAL_SEARCH = 0;

        public const uint WIA_BARCODE_VERTICAL_SEARCH = 1;

        public const uint WIA_BARCODE_HORIZONTAL_VERTICAL_SEARCH = 2;

        public const uint WIA_BARCODE_VERTICAL_HORIZONTAL_SEARCH = 3;

        public const uint WIA_BARCODE_AUTO_SEARCH = 4;

        public const uint WIA_BARCODE_UPCA = 0;

        public const uint WIA_BARCODE_UPCE = 1;

        public const uint WIA_BARCODE_CODABAR = 2;

        public const uint WIA_BARCODE_NONINTERLEAVED_2OF5 = 3;

        public const uint WIA_BARCODE_INTERLEAVED_2OF5 = 4;

        public const uint WIA_BARCODE_CODE39 = 5;

        public const uint WIA_BARCODE_CODE39_MOD43 = 6;

        public const uint WIA_BARCODE_CODE39_FULLASCII = 7;

        public const uint WIA_BARCODE_CODE93 = 8;

        public const uint WIA_BARCODE_CODE128 = 9;

        public const uint WIA_BARCODE_CODE128A = 10;

        public const uint WIA_BARCODE_CODE128B = 11;

        public const uint WIA_BARCODE_CODE128C = 12;

        public const uint WIA_BARCODE_GS1128 = 13;

        public const uint WIA_BARCODE_GS1DATABAR = 14;

        public const uint WIA_BARCODE_ITF14 = 15;

        public const uint WIA_BARCODE_EAN8 = 16;

        public const uint WIA_BARCODE_EAN13 = 17;

        public const uint WIA_BARCODE_POSTNETA = 18;

        public const uint WIA_BARCODE_POSTNETB = 19;

        public const uint WIA_BARCODE_POSTNETC = 20;

        public const uint WIA_BARCODE_POSTNET_DPBC = 21;

        public const uint WIA_BARCODE_PLANET = 22;

        public const uint WIA_BARCODE_INTELLIGENT_MAIL = 23;

        public const uint WIA_BARCODE_POSTBAR = 24;

        public const uint WIA_BARCODE_RM4SCC = 25;

        public const uint WIA_BARCODE_HIGH_CAPACITY_COLOR = 26;

        public const uint WIA_BARCODE_MAXICODE = 27;

        public const uint WIA_BARCODE_PDF417 = 28;

        public const uint WIA_BARCODE_CPCBINARY = 29;

        public const uint WIA_BARCODE_FIM = 30;

        public const uint WIA_BARCODE_PHARMACODE = 31;

        public const uint WIA_BARCODE_PLESSEY = 32;

        public const uint WIA_BARCODE_MSI = 33;

        public const uint WIA_BARCODE_JAN = 34;

        public const uint WIA_BARCODE_TELEPEN = 35;

        public const uint WIA_BARCODE_AZTEC = 36;

        public const uint WIA_BARCODE_SMALLAZTEC = 37;

        public const uint WIA_BARCODE_DATAMATRIX = 38;

        public const uint WIA_BARCODE_DATASTRIP = 39;

        public const uint WIA_BARCODE_EZCODE = 40;

        public const uint WIA_BARCODE_QRCODE = 41;

        public const uint WIA_BARCODE_SHOTCODE = 42;

        public const uint WIA_BARCODE_SPARQCODE = 43;

        public const uint WIA_BARCODE_CUSTOMBASE = 0x8000;

        public const uint WIA_PATCH_CODE_READER_DISABLED = 0;

        public const uint WIA_PATCH_CODE_READER_AUTO = 1;

        public const uint WIA_PATCH_CODE_READER_FLATBED = 2;

        public const uint WIA_PATCH_CODE_READER_FEEDER_FRONT = 3;

        public const uint WIA_PATCH_CODE_READER_FEEDER_BACK = 4;

        public const uint WIA_PATCH_CODE_READER_FEEDER_DUPLEX = 5;

        public const uint WIA_PATCH_CODE_UNKNOWN = 0;

        public const uint WIA_PATCH_CODE_1 = 1;

        public const uint WIA_PATCH_CODE_2 = 2;

        public const uint WIA_PATCH_CODE_3 = 3;

        public const uint WIA_PATCH_CODE_4 = 4;

        public const uint WIA_PATCH_CODE_T = 5;

        public const uint WIA_PATCH_CODE_6 = 6;

        public const uint WIA_PATCH_CODE_7 = 7;

        public const uint WIA_PATCH_CODE_8 = 8;

        public const uint WIA_PATCH_CODE_9 = 9;

        public const uint WIA_PATCH_CODE_10 = 10;

        public const uint WIA_PATCH_CODE_11 = 11;

        public const uint WIA_PATCH_CODE_12 = 12;

        public const uint WIA_PATCH_CODE_13 = 13;

        public const uint WIA_PATCH_CODE_14 = 14;

        public const uint WIA_PATCH_CODE_CUSTOM_BASE = 0x8000;

        public const uint WIA_MICR_READER_DISABLED = 0;

        public const uint WIA_MICR_READER_AUTO = 1;

        public const uint WIA_MICR_READER_FLATBED = 2;

        public const uint WIA_MICR_READER_FEEDER_FRONT = 3;

        public const uint WIA_MICR_READER_FEEDER_BACK = 4;

        public const uint WIA_MICR_READER_FEEDER_DUPLEX = 5;

        public const uint WIA_SEPARATOR_DISABLED = 0;

        public const uint WIA_SEPARATOR_DETECT_SCAN_CONTINUE = 1;

        public const uint WIA_SEPARATOR_DETECT_SCAN_STOP = 2;

        public const uint WIA_SEPARATOR_DETECT_NOSCAN_CONTINUE = 3;

        public const uint WIA_SEPARATOR_DETECT_NOSCAN_STOP = 4;

        public const uint WIA_LONG_DOCUMENT_DISABLED = 0;

        public const uint WIA_LONG_DOCUMENT_ENABLED = 1;

        public const uint WIA_LONG_DOCUMENT_SPLIT = 2;

        public const uint WIA_BLANK_PAGE_DETECTION_DISABLED = 0;

        public const uint WIA_BLANK_PAGE_DISCARD = 1;

        public const uint WIA_BLANK_PAGE_JOB_SEPARATOR = 2;

        public const uint WIA_MULTI_FEED_DETECT_DISABLED = 0;

        public const uint WIA_MULTI_FEED_DETECT_STOP_ERROR = 1;

        public const uint WIA_MULTI_FEED_DETECT_STOP_SUCCESS = 2;

        public const uint WIA_MULTI_FEED_DETECT_CONTINUE = 3;

        public const uint WIA_MULTI_FEED_DETECT_METHOD_LENGTH = 0;

        public const uint WIA_MULTI_FEED_DETECT_METHOD_OVERLAP = 1;

        public const uint WIA_AUTO_CROP_DISABLED = 0;

        public const uint WIA_AUTO_CROP_SINGLE = 1;

        public const uint WIA_AUTO_CROP_MULTI = 2;

        public const uint WIA_OVER_SCAN_DISABLED = 0;

        public const uint WIA_OVER_SCAN_TOP_BOTTOM = 1;

        public const uint WIA_OVER_SCAN_LEFT_RIGHT = 2;

        public const uint WIA_OVER_SCAN_ALL = 3;

        public const uint WIA_COLOR_DROP_DISABLED = 0;

        public const uint WIA_COLOR_DROP_RED = 1;

        public const uint WIA_COLOR_DROP_GREEN = 2;

        public const uint WIA_COLOR_DROP_BLUE = 3;

        public const uint WIA_COLOR_DROP_RGB = 4;

        public const uint WIA_SCAN_AHEAD_DISABLED = 0;

        public const uint WIA_SCAN_AHEAD_ENABLED = 1;

        public const uint WIA_FEEDER_CONTROL_AUTO = 0;

        public const uint WIA_FEEDER_CONTROL_MANUAL = 1;

        public const uint WIA_PRINT_PADDING_NONE = 0;

        public const uint WIA_PRINT_PADDING_ZERO = 1;

        public const uint WIA_PRINT_PADDING_BLANK = 2;

        public const uint WIA_PRINT_FONT_NORMAL = 0;

        public const uint WIA_PRINT_FONT_BOLD = 1;

        public const uint WIA_PRINT_FONT_EXTRA_BOLD = 2;

        public const uint WIA_PRINT_FONT_ITALIC_BOLD = 3;

        public const uint WIA_PRINT_FONT_ITALIC_EXTRA_BOLD = 4;

        public const uint WIA_PRINT_FONT_ITALIC = 5;

        public const uint WIA_PRINT_FONT_SMALL = 6;

        public const uint WIA_PRINT_FONT_SMALL_BOLD = 7;

        public const uint WIA_PRINT_FONT_SMALL_EXTRA_BOLD = 8;

        public const uint WIA_PRINT_FONT_SMALL_ITALIC_BOLD = 9;

        public const uint WIA_PRINT_FONT_SMALL_ITALIC_EXTRA_BOLD = 10;

        public const uint WIA_PRINT_FONT_SMALL_ITALIC = 11;

        public const uint WIA_PRINT_FONT_LARGE = 12;

        public const uint WIA_PRINT_FONT_LARGE_BOLD = 13;

        public const uint WIA_PRINT_FONT_LARGE_EXTRA_BOLD = 14;

        public const uint WIA_PRINT_FONT_LARGE_ITALIC_BOLD = 15;

        public const uint WIA_PRINT_FONT_LARGE_ITALIC_EXTRA_BOLD = 16;

        public const uint WIA_PRINT_FONT_LARGE_ITALIC = 17;

        public const uint WIA_ALARM_NONE = 0;

        public const uint WIA_ALARM_BEEP1 = 1;

        public const uint WIA_ALARM_BEEP2 = 2;

        public const uint WIA_ALARM_BEEP3 = 3;

        public const uint WIA_ALARM_BEEP4 = 4;

        public const uint WIA_ALARM_BEEP5 = 5;

        public const uint WIA_ALARM_BEEP6 = 6;

        public const uint WIA_ALARM_BEEP7 = 7;

        public const uint WIA_ALARM_BEEP8 = 8;

        public const uint WIA_ALARM_BEEP9 = 9;

        public const uint WIA_ALARM_BEEP10 = 10;

        public const uint WIA_PRIVATE_DEVPROP = 38914;

        public const uint WIA_PRIVATE_ITEMPROP = 71682;

        public static readonly Guid WiaImgFmt_UNDEFINED__scanned__ = new Guid(0xb96b3ca9, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_RAWRGB__scanned__ = new Guid(0xbca48b55, 0xf272, 0x4371, 0xb0, 0xf1, 0x4a, 0x15, 0x0d, 0x05, 0x7b, 0xb4);

        public static readonly Guid WiaImgFmt_MEMORYBMP__scanned__ = new Guid(0xb96b3caa, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_BMP__scanned__ = new Guid(0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_EMF__scanned__ = new Guid(0xb96b3cac, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_WMF__scanned__ = new Guid(0xb96b3cad, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_JPEG__scanned__ = new Guid(0xb96b3cae, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_PNG__scanned__ = new Guid(0xb96b3caf, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_GIF__scanned__ = new Guid(0xb96b3cb0, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_TIFF__scanned__ = new Guid(0xb96b3cb1, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_EXIF__scanned__ = new Guid(0xb96b3cb2, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_PHOTOCD__scanned__ = new Guid(0xb96b3cb3, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_FLASHPIX__scanned__ = new Guid(0xb96b3cb4, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_ICO__scanned__ = new Guid(0xb96b3cb5, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

        public static readonly Guid WiaImgFmt_CIFF__scanned__ = new Guid(0x9821a8ab, 0x3a7e, 0x4215, 0x94, 0xe0, 0xd2, 0x7a, 0x46, 0x0c, 0x03, 0xb2);

        public static readonly Guid WiaImgFmt_PICT__scanned__ = new Guid(0xa6bc85d8, 0x6b3e, 0x40ee, 0xa9, 0x5c, 0x25, 0xd4, 0x82, 0xe4, 0x1a, 0xdc);

        public static readonly Guid WiaImgFmt_JPEG2K__scanned__ = new Guid(0x344ee2b2, 0x39db, 0x4dde, 0x81, 0x73, 0xc4, 0xb7, 0x5f, 0x8f, 0x1e, 0x49);

        public static readonly Guid WiaImgFmt_JPEG2KX__scanned__ = new Guid(0x43e14614, 0xc80a, 0x4850, 0xba, 0xf3, 0x4b, 0x15, 0x2d, 0xc8, 0xda, 0x27);

        public static readonly Guid WiaImgFmt_RAW__scanned__ = new Guid(0x6f120719, 0xf1a8, 0x4e07, 0x9a, 0xde, 0x9b, 0x64, 0xc6, 0x3a, 0x3d, 0xcc);

        public static readonly Guid WiaImgFmt_JBIG__scanned__ = new Guid(0x41e8dd92, 0x2f0a, 0x43d4, 0x86, 0x36, 0xf1, 0x61, 0x4b, 0xa1, 0x1e, 0x46);

        public static readonly Guid WiaImgFmt_JBIG2__scanned__ = new Guid(0xbb8e7e67, 0x283c, 0x4235, 0x9e, 0x59, 0x0b, 0x9b, 0xf9, 0x4c, 0xa6, 0x87);

        public static readonly Guid WiaImgFmt_RTF__scanned__ = new Guid(0x573dd6a3, 0x4834, 0x432d, 0xa9, 0xb5, 0xe1, 0x98, 0xdd, 0x9e, 0x89, 0x0d);

        public static readonly Guid WiaImgFmt_XML__scanned__ = new Guid(0xb9171457, 0xdac8, 0x4884, 0xb3, 0x93, 0x15, 0xb4, 0x71, 0xd5, 0xf0, 0x7e);

        public static readonly Guid WiaImgFmt_HTML__scanned__ = new Guid(0xc99a4e62, 0x99de, 0x4a94, 0xac, 0xca, 0x71, 0x95, 0x6a, 0xc2, 0x97, 0x7d);

        public static readonly Guid WiaImgFmt_TXT__scanned__ = new Guid(0xfafd4d82, 0x723f, 0x421f, 0x93, 0x18, 0x30, 0x50, 0x1a, 0xc4, 0x4b, 0x59);

        public static readonly Guid WiaImgFmt_PDFA__scanned__ = new Guid(0x9980bd5b, 0x3463, 0x43c7, 0xbd, 0xca, 0x3c, 0xaa, 0x14, 0x6f, 0x22, 0x9f);

        public static readonly Guid WiaImgFmt_XPS__scanned__ = new Guid(0x700b4a0f, 0x2011, 0x411c, 0xb4, 0x30, 0xd1, 0xe0, 0xb2, 0xe1, 0x0b, 0x28);

        public static readonly Guid WiaImgFmt_OXPS__scanned__ = new Guid(0x2c7b1240, 0xc14d, 0x4109, 0x97, 0x55, 0x04, 0xb8, 0x90, 0x25, 0x15, 0x3a);

        public static readonly Guid WiaImgFmt_CSV__scanned__ = new Guid(0x355bda24, 0x5a9f, 0x4494, 0x80, 0xdc, 0xbe, 0x75, 0x2c, 0xec, 0xbc, 0x8c);

        public static readonly Guid WiaImgFmt_MPG__scanned__ = new Guid(0xecd757e4, 0xd2ec, 0x4f57, 0x95, 0x5d, 0xbc, 0xf8, 0xa9, 0x7c, 0x4e, 0x52);

        public static readonly Guid WiaImgFmt_AVI__scanned__ = new Guid(0x32f8ca14, 0x087c, 0x4908, 0xb7, 0xc4, 0x67, 0x57, 0xfe, 0x7e, 0x90, 0xab);

        public static readonly Guid WiaAudFmt_WAV__scanned__ = new Guid(0xf818e146, 0x07af, 0x40ff, 0xae, 0x55, 0xbe, 0x8f, 0x2c, 0x06, 0x5d, 0xbe);

        public static readonly Guid WiaAudFmt_MP3__scanned__ = new Guid(0x0fbc71fb, 0x43bf, 0x49f2, 0x91, 0x90, 0xe6, 0xfe, 0xcf, 0xf3, 0x7e, 0x54);

        public static readonly Guid WiaAudFmt_AIFF__scanned__ = new Guid(0x66e2bf4f, 0xb6fc, 0x443f, 0x94, 0xc8, 0x2f, 0x33, 0xc8, 0xa6, 0x5a, 0xaf);

        public static readonly Guid WiaAudFmt_WMA__scanned__ = new Guid(0xd61d6413, 0x8bc2, 0x438f, 0x93, 0xad, 0x21, 0xbd, 0x48, 0x4d, 0xb6, 0xa1);

        public static readonly Guid WiaImgFmt_ASF__scanned__ = new Guid(0x8d948ee9, 0xd0aa, 0x4a12, 0x9d, 0x9a, 0x9c, 0xc5, 0xde, 0x36, 0x19, 0x9b);

        public static readonly Guid WiaImgFmt_SCRIPT__scanned__ = new Guid(0xfe7d6c53, 0x2dac, 0x446a, 0xb0, 0xbd, 0xd7, 0x3e, 0x21, 0xe9, 0x24, 0xc9);

        public static readonly Guid WiaImgFmt_EXEC__scanned__ = new Guid(0x485da097, 0x141e, 0x4aa5, 0xbb, 0x3b, 0xa5, 0x61, 0x8d, 0x95, 0xd0, 0x2b);

        public static readonly Guid WiaImgFmt_UNICODE16__scanned__ = new Guid(0x1b7639b6, 0x6357, 0x47d1, 0x9a, 0x07, 0x12, 0x45, 0x2d, 0xc0, 0x73, 0xe9);

        public static readonly Guid WiaImgFmt_DPOF__scanned__ = new Guid(0x369eeeab, 0xa0e8, 0x45ca, 0x86, 0xa6, 0xa8, 0x3c, 0xe5, 0x69, 0x7e, 0x28);

        public static readonly Guid WiaImgFmt_XMLBAR__scanned__ = new Guid(0x6235701c, 0x3a98, 0x484c, 0xb2, 0xa8, 0xfd, 0xff, 0xd8, 0x7e, 0x6b, 0x16);

        public static readonly Guid WiaImgFmt_RAWBAR__scanned__ = new Guid(0xda63f833, 0xd26e, 0x451e, 0x90, 0xd2, 0xea, 0x55, 0xa1, 0x36, 0x5d, 0x62);

        public static readonly Guid WiaImgFmt_XMLPAT__scanned__ = new Guid(0xf8986f55, 0xf052, 0x460d, 0x95, 0x23, 0x3a, 0x7d, 0xfe, 0xdb, 0xb3, 0x3c);

        public static readonly Guid WiaImgFmt_RAWPAT__scanned__ = new Guid(0x7760507c, 0x5064, 0x400c, 0x9a, 0x17, 0x57, 0x56, 0x24, 0xd8, 0x82, 0x4b);

        public static readonly Guid WiaImgFmt_XMLMIC__scanned__ = new Guid(0x2d164c61, 0xb9ae, 0x4b23, 0x89, 0x73, 0xc7, 0x06, 0x7e, 0x1f, 0xbd, 0x31);

        public static readonly Guid WiaImgFmt_RAWMIC__scanned__ = new Guid(0x22c4f058, 0x0d88, 0x409c, 0xac, 0x1c, 0xee, 0xc1, 0x2b, 0x0e, 0xa6, 0x80);

        public static readonly Guid WIA_EVENT_DEVICE_DISCONNECTED__scanned__ = new Guid(0x143e4e83, 0x6497, 0x11d2, 0xa2, 0x31, 0x00, 0xc0, 0x4f, 0xa3, 0x18, 0x09);

        public static readonly Guid WIA_EVENT_DEVICE_CONNECTED__scanned__ = new Guid(0xa28bbade, 0x64b6, 0x11d2, 0xa2, 0x31, 0x00, 0xc0, 0x4f, 0xa3, 0x18, 0x09);

        public static readonly Guid WIA_EVENT_ITEM_DELETED__scanned__ = new Guid(0x1d22a559, 0xe14f, 0x11d2, 0xb3, 0x26, 0x00, 0xc0, 0x4f, 0x68, 0xce, 0x61);

        public static readonly Guid WIA_EVENT_ITEM_CREATED__scanned__ = new Guid(0x4c8f4ef5, 0xe14f, 0x11d2, 0xb3, 0x26, 0x00, 0xc0, 0x4f, 0x68, 0xce, 0x61);

        public static readonly Guid WIA_EVENT_TREE_UPDATED__scanned__ = new Guid(0xc9859b91, 0x4ab2, 0x4cd6, 0xa1, 0xfc, 0x58, 0x2e, 0xec, 0x55, 0xe5, 0x85);

        public static readonly Guid WIA_EVENT_VOLUME_INSERT__scanned__ = new Guid(0x9638bbfd, 0xd1bd, 0x11d2, 0xb3, 0x1f, 0x00, 0xc0, 0x4f, 0x68, 0xce, 0x61);

        public static readonly Guid WIA_EVENT_SCAN_IMAGE__scanned__ = new Guid(0xa6c5a715, 0x8c6e, 0x11d2, 0x97, 0x7a, 0x00, 0x00, 0xf8, 0x7a, 0x92, 0x6f);

        public static readonly Guid WIA_EVENT_SCAN_PRINT_IMAGE__scanned__ = new Guid(0xb441f425, 0x8c6e, 0x11d2, 0x97, 0x7a, 0x00, 0x00, 0xf8, 0x7a, 0x92, 0x6f);

        public static readonly Guid WIA_EVENT_SCAN_FAX_IMAGE__scanned__ = new Guid(0xc00eb793, 0x8c6e, 0x11d2, 0x97, 0x7a, 0x00, 0x00, 0xf8, 0x7a, 0x92, 0x6f);

        public static readonly Guid WIA_EVENT_SCAN_OCR_IMAGE__scanned__ = new Guid(0x9d095b89, 0x37d6, 0x4877, 0xaf, 0xed, 0x62, 0xa2, 0x97, 0xdc, 0x6d, 0xbe);

        public static readonly Guid WIA_EVENT_SCAN_EMAIL_IMAGE__scanned__ = new Guid(0xc686dcee, 0x54f2, 0x419e, 0x9a, 0x27, 0x2f, 0xc7, 0xf2, 0xe9, 0x8f, 0x9e);

        public static readonly Guid WIA_EVENT_SCAN_FILM_IMAGE__scanned__ = new Guid(0x9b2b662c, 0x6185, 0x438c, 0xb6, 0x8b, 0xe3, 0x9e, 0xe2, 0x5e, 0x71, 0xcb);

        public static readonly Guid WIA_EVENT_SCAN_IMAGE2__scanned__ = new Guid(0xfc4767c1, 0xc8b3, 0x48a2, 0x9c, 0xfa, 0x2e, 0x90, 0xcb, 0x3d, 0x35, 0x90);

        public static readonly Guid WIA_EVENT_SCAN_IMAGE3__scanned__ = new Guid(0x154e27be, 0xb617, 0x4653, 0xac, 0xc5, 0x0f, 0xd7, 0xbd, 0x4c, 0x65, 0xce);

        public static readonly Guid WIA_EVENT_SCAN_IMAGE4__scanned__ = new Guid(0xa65b704a, 0x7f3c, 0x4447, 0xa7, 0x5d, 0x8a, 0x26, 0xdf, 0xca, 0x1f, 0xdf);

        public static readonly Guid WIA_EVENT_STORAGE_CREATED__scanned__ = new Guid(0x353308b2, 0xfe73, 0x46c8, 0x89, 0x5e, 0xfa, 0x45, 0x51, 0xcc, 0xc8, 0x5a);

        public static readonly Guid WIA_EVENT_STORAGE_DELETED__scanned__ = new Guid(0x5e41e75e, 0x9390, 0x44c5, 0x9a, 0x51, 0xe4, 0x70, 0x19, 0xe3, 0x90, 0xcf);

        public static readonly Guid WIA_EVENT_STI_PROXY__scanned__ = new Guid(0xd711f81f, 0x1f0d, 0x422d, 0x86, 0x41, 0x92, 0x7d, 0x1b, 0x93, 0xe5, 0xe5);

        public static readonly Guid WIA_EVENT_CANCEL_IO__scanned__ = new Guid(0xc860f7b8, 0x9ccd, 0x41ea, 0xbb, 0xbf, 0x4d, 0xd0, 0x9c, 0x5b, 0x17, 0x95);

        public static readonly Guid WIA_EVENT_POWER_SUSPEND__scanned__ = new Guid(0xa0922ff9, 0xc3b4, 0x411c, 0x9e, 0x29, 0x03, 0xa6, 0x69, 0x93, 0xd2, 0xbe);

        public static readonly Guid WIA_EVENT_POWER_RESUME__scanned__ = new Guid(0x618f153e, 0xf686, 0x4350, 0x96, 0x34, 0x41, 0x15, 0xa3, 0x04, 0x83, 0x0c);

        public static readonly Guid WIA_EVENT_HANDLER_NO_ACTION__scanned__ = new Guid(0xe0372b7d, 0xe115, 0x4525, 0xbc, 0x55, 0xb6, 0x29, 0xe6, 0x8c, 0x74, 0x5a);

        public static readonly Guid WIA_EVENT_HANDLER_PROMPT__scanned__ = new Guid(0x5f4baad0, 0x4d59, 0x4fcd, 0xb2, 0x13, 0x78, 0x3c, 0xe7, 0xa9, 0x2f, 0x22);

        public static readonly Guid WIA_EVENT_DEVICE_NOT_READY__scanned__ = new Guid(0xd8962d7e, 0xe4dc, 0x4b4d, 0xba, 0x29, 0x66, 0x8a, 0x87, 0xf4, 0x2e, 0x6f);

        public static readonly Guid WIA_EVENT_DEVICE_READY__scanned__ = new Guid(0x7523ec6c, 0x988b, 0x419e, 0x9a, 0x0a, 0x42, 0x5a, 0xc3, 0x1b, 0x37, 0xdc);

        public static readonly Guid WIA_EVENT_FLATBED_LID_OPEN__scanned__ = new Guid(0xba0a0623, 0x437d, 0x4f03, 0xa9, 0x7d, 0x77, 0x93, 0xb1, 0x23, 0x11, 0x3c);

        public static readonly Guid WIA_EVENT_FLATBED_LID_CLOSED__scanned__ = new Guid(0xf879af0f, 0x9b29, 0x4283, 0xad, 0x95, 0xd4, 0x12, 0x16, 0x4d, 0x39, 0xa9);

        public static readonly Guid WIA_EVENT_FEEDER_LOADED__scanned__ = new Guid(0xcc8d701e, 0x9aba, 0x481d, 0xbf, 0x74, 0x78, 0xf7, 0x63, 0xdc, 0x34, 0x2a);

        public static readonly Guid WIA_EVENT_FEEDER_EMPTIED__scanned__ = new Guid(0xe70b4b82, 0x6dda, 0x46bb, 0x8f, 0xf9, 0x53, 0xce, 0xb1, 0xa0, 0x3e, 0x35);

        public static readonly Guid WIA_EVENT_COVER_OPEN__scanned__ = new Guid(0x19a12136, 0xfa1c, 0x4f66, 0x90, 0x0f, 0x8f, 0x91, 0x4e, 0xc7, 0x4e, 0xc9);

        public static readonly Guid WIA_EVENT_COVER_CLOSED__scanned__ = new Guid(0x6714a1e6, 0xe285, 0x468c, 0x9b, 0x8c, 0xda, 0x7d, 0xc4, 0xcb, 0xaa, 0x05);

        public static readonly Guid WIA_CMD_SYNCHRONIZE__scanned__ = new Guid(0x9b26b7b2, 0xacad, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

        public static readonly Guid WIA_CMD_TAKE_PICTURE__scanned__ = new Guid(0xaf933cac, 0xacad, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

        public static readonly Guid WIA_CMD_DELETE_ALL_ITEMS__scanned__ = new Guid(0xe208c170, 0xacad, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

        public static readonly Guid WIA_CMD_CHANGE_DOCUMENT__scanned__ = new Guid(0x04e725b0, 0xacae, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

        public static readonly Guid WIA_CMD_UNLOAD_DOCUMENT__scanned__ = new Guid(0x1f3b3d8e, 0xacae, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

        public static readonly Guid WIA_CMD_DIAGNOSTIC__scanned__ = new Guid(0x10ff52f5, 0xde04, 0x4cf0, 0xa5, 0xad, 0x69, 0x1f, 0x8d, 0xce, 0x01, 0x41);

        public static readonly Guid WIA_CMD_FORMAT__scanned__ = new Guid(0xc3a693aa, 0xf788, 0x4d34, 0xa5, 0xb0, 0xbe, 0x71, 0x90, 0x75, 0x9a, 0x24);

        public static readonly Guid WIA_CMD_DELETE_DEVICE_TREE__scanned__ = new Guid(0x73815942, 0xdbea, 0x11d2, 0x84, 0x16, 0x00, 0xc0, 0x4f, 0xa3, 0x61, 0x45);

        public static readonly Guid WIA_CMD_BUILD_DEVICE_TREE__scanned__ = new Guid(0x9cba5ce0, 0xdbea, 0x11d2, 0x84, 0x16, 0x00, 0xc0, 0x4f, 0xa3, 0x61, 0x45);

        public static readonly Guid WIA_CMD_START_FEEDER__scanned__ = new Guid(0x5a9df6c9, 0x5f2d, 0x4a39, 0x9d, 0x6c, 0x00, 0x45, 0x6d, 0x04, 0x7f, 0x00);

        public static readonly Guid WIA_CMD_STOP_FEEDER__scanned__ = new Guid(0xd847b06d, 0x3905, 0x459c, 0x95, 0x09, 0x9b, 0x29, 0xcd, 0xb6, 0x91, 0xe7);

        public static readonly Guid WIA_CMD_PAUSE_FEEDER__scanned__ = new Guid(0x50985e4d, 0xa5b2, 0x4b71, 0x9c, 0x95, 0x6d, 0x7d, 0x7c, 0x46, 0x9a, 0x43);

        public const uint BASE_VAL_WIA_ERROR = 0x00000000;

        public const uint BASE_VAL_WIA_SUCCESS = 0x00000000;

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_GENERAL_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(1));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_PAPER_JAM = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(2));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_PAPER_EMPTY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(3));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_PAPER_PROBLEM = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(4));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_OFFLINE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(5));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_BUSY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(6));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_WARMING_UP = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(7));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_USER_INTERVENTION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(8));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_ITEM_DELETED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(9));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_DEVICE_COMMUNICATION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(10));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_INVALID_COMMAND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(11));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_INCORRECT_HARDWARE_SETTING = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(12));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_DEVICE_LOCKED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(13));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_EXCEPTION_IN_DRIVER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(14));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_INVALID_DRIVER_RESPONSE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(15));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_COVER_OPEN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(16));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_LAMP_OFF = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(17));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_DESTINATION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(18));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_NETWORK_RESERVATION_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(19));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_MULTI_FEED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(20));

        [NativeTypeName("HRESULT")]
        public const int WIA_ERROR_MAXIMUM_PRINTER_ENDORSER_COUNTER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(21));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_END_OF_MEDIA = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(1));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_WARMING_UP = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(2));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_CALIBRATING = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(3));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_RESERVING_NETWORK_DEVICE = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(6));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_NETWORK_DEVICE_RESERVED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(7));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_CLEAR = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(8));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_SKIP_ITEM = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(9));

        [NativeTypeName("HRESULT")]
        public const int WIA_STATUS_NOT_HANDLED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(10));

        [NativeTypeName("HRESULT")]
        public const int WIA_S_CHANGE_DEVICE = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(11));

        [NativeTypeName("HRESULT")]
        public const int WIA_S_NO_DEVICE_AVAILABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIA)) << 16) | (int)(21));

        public const uint WIA_SELECT_DEVICE_NODEFAULT = 0x00000001;

        public const uint WIA_DEVICE_DIALOG_SINGLE_IMAGE = 0x00000002;

        public const uint WIA_DEVICE_DIALOG_USE_COMMON_UI = 0x00000004;

        public const uint WIA_REGISTER_EVENT_CALLBACK = 0x00000001;

        public const uint WIA_UNREGISTER_EVENT_CALLBACK = 0x00000002;

        public const uint WIA_SET_DEFAULT_HANDLER = 0x00000004;

        public const uint WIA_NOTIFICATION_EVENT = 0x00000001;

        public const uint WIA_ACTION_EVENT = 0x00000002;

        public const uint WIA_LINE_ORDER_TOP_TO_BOTTOM = 0x00000001;

        public const uint WIA_LINE_ORDER_BOTTOM_TO_TOP = 0x00000002;

        public const uint WIA_IS_DEFAULT_HANDLER = 0x00000001;

        public const uint TYMED_CALLBACK = 128;

        public const uint TYMED_MULTIPAGE_FILE = 256;

        public const uint TYMED_MULTIPAGE_CALLBACK = 512;

        public const uint IT_MSG_DATA_HEADER = 0x0001;

        public const uint IT_MSG_DATA = 0x0002;

        public const uint IT_MSG_STATUS = 0x0003;

        public const uint IT_MSG_TERMINATION = 0x0004;

        public const uint IT_MSG_NEW_PAGE = 0x0005;

        public const uint IT_MSG_FILE_PREVIEW_DATA = 0x0006;

        public const uint IT_MSG_FILE_PREVIEW_DATA_HEADER = 0x0007;

        public const uint IT_STATUS_TRANSFER_FROM_DEVICE = 0x0001;

        public const uint IT_STATUS_PROCESSING_DATA = 0x0002;

        public const uint IT_STATUS_TRANSFER_TO_CLIENT = 0x0004;

        public const uint IT_STATUS_MASK = 0x0007;

        public const uint WIA_TRANSFER_ACQUIRE_CHILDREN = 0x0001;

        public const uint WIA_TRANSFER_MSG_STATUS = 0x00001;

        public const uint WIA_TRANSFER_MSG_END_OF_STREAM = 0x00002;

        public const uint WIA_TRANSFER_MSG_END_OF_TRANSFER = 0x00003;

        public const uint WIA_TRANSFER_MSG_DEVICE_STATUS = 0x00005;

        public const uint WIA_TRANSFER_MSG_NEW_PAGE = 0x00006;

        public const uint WIA_MAJOR_EVENT_DEVICE_CONNECT = 0x01;

        public const uint WIA_MAJOR_EVENT_DEVICE_DISCONNECT = 0x02;

        public const uint WIA_MAJOR_EVENT_PICTURE_TAKEN = 0x03;

        public const uint WIA_MAJOR_EVENT_PICTURE_DELETED = 0x04;

        public const uint WIA_DEVICE_NOT_CONNECTED = 0;

        public const uint WIA_DEVICE_CONNECTED = 1;

        public const uint WIA_DEVICE_COMMANDS = 1;

        public const uint WIA_DEVICE_EVENTS = 2;

        public const uint WIA_DEVINFO_ENUM_ALL = 0x0000000F;

        public const uint WIA_DEVINFO_ENUM_LOCAL = 0x00000010;

        public const uint WiaItemTypeFree = 0x00000000;

        public const uint WiaItemTypeImage = 0x00000001;

        public const uint WiaItemTypeFile = 0x00000002;

        public const uint WiaItemTypeFolder = 0x00000004;

        public const uint WiaItemTypeRoot = 0x00000008;

        public const uint WiaItemTypeAnalyze = 0x00000010;

        public const uint WiaItemTypeAudio = 0x00000020;

        public const uint WiaItemTypeDevice = 0x00000040;

        public const uint WiaItemTypeDeleted = 0x00000080;

        public const uint WiaItemTypeDisconnected = 0x00000100;

        public const uint WiaItemTypeHPanorama = 0x00000200;

        public const uint WiaItemTypeVPanorama = 0x00000400;

        public const uint WiaItemTypeBurst = 0x00000800;

        public const uint WiaItemTypeStorage = 0x00001000;

        public const uint WiaItemTypeTransfer = 0x00002000;

        public const uint WiaItemTypeGenerated = 0x00004000;

        public const uint WiaItemTypeHasAttachments = 0x00008000;

        public const uint WiaItemTypeVideo = 0x00010000;

        public const uint WiaItemTypeRemoved = 0x80000000;

        public const uint WiaItemTypeDocument = 0x00040000;

        public const uint WiaItemTypeProgrammableDataSource = 0x00080000;

        public const uint WiaItemTypeMask = 0x800FFFFF;

        public const uint WIA_MAX_CTX_SIZE = 0x01000000;

        public const uint WIA_PROP_READ = 0x01;

        public const uint WIA_PROP_WRITE = 0x02;

        public const uint WIA_PROP_SYNC_REQUIRED = 0x04;

        public const uint WIA_PROP_NONE = 0x08;

        public const uint WIA_PROP_RANGE = 0x10;

        public const uint WIA_PROP_LIST = 0x20;

        public const uint WIA_PROP_FLAG = 0x40;

        public const uint WIA_PROP_CACHEABLE = 0x10000;

        public const uint COPY_PARENT_PROPERTY_VALUES = 0x40000000;

        public const uint WIA_ITEM_CAN_BE_DELETED = 0x80;

        public const uint WIA_RANGE_MIN = 0;

        public const uint WIA_RANGE_NOM = 1;

        public const uint WIA_RANGE_MAX = 2;

        public const uint WIA_RANGE_STEP = 3;

        public const uint WIA_RANGE_NUM_ELEMS = 4;

        public const uint WIA_LIST_COUNT = 0;

        public const uint WIA_LIST_NOM = 1;

        public const uint WIA_LIST_VALUES = 2;

        public const uint WIA_LIST_NUM_ELEMS = 2;

        public const uint WIA_FLAG_NOM = 0;

        public const uint WIA_FLAG_VALUES = 1;

        public const uint WIA_FLAG_NUM_ELEMS = 2;

        public const uint WIA_DIP_FIRST = 2;

        public const uint WIA_IPA_FIRST = 4098;

        public const uint WIA_DPF_FIRST = 3330;

        public const uint WIA_IPS_FIRST = 6146;

        public const uint WIA_DPS_FIRST = 3074;

        public const uint WIA_IPC_FIRST = 5122;

        public const uint WIA_NUM_IPC = 9;

        public const uint WIA_RESERVED_FOR_NEW_PROPS = 1024;

        public const uint WHITEBALANCE_MANUAL = 1;

        public const uint WHITEBALANCE_AUTO = 2;

        public const uint WHITEBALANCE_ONEPUSH_AUTO = 3;

        public const uint WHITEBALANCE_DAYLIGHT = 4;

        public const uint WHITEBALANCE_FLORESCENT = 5;

        public const uint WHITEBALANCE_TUNGSTEN = 6;

        public const uint WHITEBALANCE_FLASH = 7;

        public const uint FOCUSMODE_MANUAL = 1;

        public const uint FOCUSMODE_AUTO = 2;

        public const uint FOCUSMODE_MACROAUTO = 3;

        public const uint EXPOSUREMETERING_AVERAGE = 1;

        public const uint EXPOSUREMETERING_CENTERWEIGHT = 2;

        public const uint EXPOSUREMETERING_MULTISPOT = 3;

        public const uint EXPOSUREMETERING_CENTERSPOT = 4;

        public const uint FLASHMODE_AUTO = 1;

        public const uint FLASHMODE_OFF = 2;

        public const uint FLASHMODE_FILL = 3;

        public const uint FLASHMODE_REDEYE_AUTO = 4;

        public const uint FLASHMODE_REDEYE_FILL = 5;

        public const uint FLASHMODE_EXTERNALSYNC = 6;

        public const uint EXPOSUREMODE_MANUAL = 1;

        public const uint EXPOSUREMODE_AUTO = 2;

        public const uint EXPOSUREMODE_APERTURE_PRIORITY = 3;

        public const uint EXPOSUREMODE_SHUTTER_PRIORITY = 4;

        public const uint EXPOSUREMODE_PROGRAM_CREATIVE = 5;

        public const uint EXPOSUREMODE_PROGRAM_ACTION = 6;

        public const uint EXPOSUREMODE_PORTRAIT = 7;

        public const uint CAPTUREMODE_NORMAL = 1;

        public const uint CAPTUREMODE_BURST = 2;

        public const uint CAPTUREMODE_TIMELAPSE = 3;

        public const uint EFFECTMODE_STANDARD = 1;

        public const uint EFFECTMODE_BW = 2;

        public const uint EFFECTMODE_SEPIA = 3;

        public const uint FOCUSMETERING_CENTERSPOT = 1;

        public const uint FOCUSMETERING_MULTISPOT = 2;

        public const uint POWERMODE_LINE = 1;

        public const uint POWERMODE_BATTERY = 2;

        public const uint LEFT_JUSTIFIED = 0;

        public const uint CENTERED = 1;

        public const uint RIGHT_JUSTIFIED = 2;

        public const uint TOP_JUSTIFIED = 0;

        public const uint BOTTOM_JUSTIFIED = 2;

        public const uint PORTRAIT = 0;

        public const uint LANSCAPE = 1;

        public const uint ROT180 = 2;

        public const uint ROT270 = 3;

        public const uint MIRRORED = 0x01;

        public const uint FEED = 0x01;

        public const uint FLAT = 0x02;

        public const uint DUP = 0x04;

        public const uint DETECT_FLAT = 0x08;

        public const uint DETECT_SCAN = 0x10;

        public const uint DETECT_FEED = 0x20;

        public const uint DETECT_DUP = 0x40;

        public const uint DETECT_FEED_AVAIL = 0x80;

        public const uint DETECT_DUP_AVAIL = 0x100;

        public const uint FILM_TPA = 0x200;

        public const uint DETECT_FILM_TPA = 0x400;

        public const uint STOR = 0x800;

        public const uint DETECT_STOR = 0x1000;

        public const uint ADVANCED_DUP = 0x2000;

        public const uint AUTO_SOURCE = 0x8000;

        public const uint IMPRINTER = 0x10000;

        public const uint ENDORSER = 0x20000;

        public const uint BARCODE_READER = 0x40000;

        public const uint PATCH_CODE_READER = 0x80000;

        public const uint MICR_READER = 0x100000;

        public const uint FEED_READY = 0x01;

        public const uint FLAT_READY = 0x02;

        public const uint DUP_READY = 0x04;

        public const uint FLAT_COVER_UP = 0x08;

        public const uint PATH_COVER_UP = 0x10;

        public const uint PAPER_JAM = 0x20;

        public const uint FILM_TPA_READY = 0x40;

        public const uint STORAGE_READY = 0x80;

        public const uint STORAGE_FULL = 0x100;

        public const uint MULTIPLE_FEED = 0x200;

        public const uint DEVICE_ATTENTION = 0x400;

        public const uint LAMP_ERR = 0x800;

        public const uint IMPRINTER_READY = 0x1000;

        public const uint ENDORSER_READY = 0x2000;

        public const uint BARCODE_READER_READY = 0x4000;

        public const uint PATCH_CODE_READER_READY = 0x8000;

        public const uint MICR_READER_READY = 0x10000;

        public const uint FEEDER = 0x001;

        public const uint FLATBED = 0x002;

        public const uint DUPLEX = 0x004;

        public const uint FRONT_FIRST = 0x008;

        public const uint BACK_FIRST = 0x010;

        public const uint FRONT_ONLY = 0x020;

        public const uint BACK_ONLY = 0x040;

        public const uint NEXT_PAGE = 0x080;

        public const uint PREFEED = 0x100;

        public const uint AUTO_ADVANCE = 0x200;

        public const uint ADVANCED_DUPLEX = 0x400;

        public const uint LIGHT_SOURCE_PRESENT_DETECT = 0x01;

        public const uint LIGHT_SOURCE_PRESENT = 0x02;

        public const uint LIGHT_SOURCE_DETECT_READY = 0x04;

        public const uint LIGHT_SOURCE_READY = 0x08;

        public const uint TRANSPARENCY_DYNAMIC_FRAME_SUPPORT = 0x01;

        public const uint TRANSPARENCY_STATIC_FRAME_SUPPORT = 0x02;

        public const uint LIGHT_SOURCE_SELECT = 0x001;

        public const uint LIGHT_SOURCE_POSITIVE = 0x002;

        public const uint LIGHT_SOURCE_NEGATIVE = 0x004;

        public const uint WIA_SCAN_AHEAD_ALL = 0;

        public const uint ALL_PAGES = 0;

        public const uint WIA_FINAL_SCAN = 0;

        public const uint WIA_PREVIEW_SCAN = 1;

        public const uint WIA_SHOW_PREVIEW_CONTROL = 0;

        public const uint WIA_DONT_SHOW_PREVIEW_CONTROL = 1;

        public const uint WIA_PAGE_A4 = 0;

        public const uint WIA_PAGE_LETTER = 1;

        public const uint WIA_PAGE_CUSTOM = 2;

        public const uint WIA_PAGE_USLEGAL = 3;

        public const uint WIA_PAGE_USLEDGER = 4;

        public const uint WIA_PAGE_USSTATEMENT = 5;

        public const uint WIA_PAGE_BUSINESSCARD = 6;

        public const uint WIA_PAGE_ISO_A0 = 7;

        public const uint WIA_PAGE_ISO_A1 = 8;

        public const uint WIA_PAGE_ISO_A2 = 9;

        public const uint WIA_PAGE_ISO_A3 = 10;

        public const uint WIA_PAGE_ISO_A5 = 11;

        public const uint WIA_PAGE_ISO_A6 = 12;

        public const uint WIA_PAGE_ISO_A7 = 13;

        public const uint WIA_PAGE_ISO_A8 = 14;

        public const uint WIA_PAGE_ISO_A9 = 15;

        public const uint WIA_PAGE_ISO_A10 = 16;

        public const uint WIA_PAGE_ISO_B0 = 17;

        public const uint WIA_PAGE_ISO_B1 = 18;

        public const uint WIA_PAGE_ISO_B2 = 19;

        public const uint WIA_PAGE_ISO_B3 = 20;

        public const uint WIA_PAGE_ISO_B4 = 21;

        public const uint WIA_PAGE_ISO_B5 = 22;

        public const uint WIA_PAGE_ISO_B6 = 23;

        public const uint WIA_PAGE_ISO_B7 = 24;

        public const uint WIA_PAGE_ISO_B8 = 25;

        public const uint WIA_PAGE_ISO_B9 = 26;

        public const uint WIA_PAGE_ISO_B10 = 27;

        public const uint WIA_PAGE_ISO_C0 = 28;

        public const uint WIA_PAGE_ISO_C1 = 29;

        public const uint WIA_PAGE_ISO_C2 = 30;

        public const uint WIA_PAGE_ISO_C3 = 31;

        public const uint WIA_PAGE_ISO_C4 = 32;

        public const uint WIA_PAGE_ISO_C5 = 33;

        public const uint WIA_PAGE_ISO_C6 = 34;

        public const uint WIA_PAGE_ISO_C7 = 35;

        public const uint WIA_PAGE_ISO_C8 = 36;

        public const uint WIA_PAGE_ISO_C9 = 37;

        public const uint WIA_PAGE_ISO_C10 = 38;

        public const uint WIA_PAGE_JIS_B0 = 39;

        public const uint WIA_PAGE_JIS_B1 = 40;

        public const uint WIA_PAGE_JIS_B2 = 41;

        public const uint WIA_PAGE_JIS_B3 = 42;

        public const uint WIA_PAGE_JIS_B4 = 43;

        public const uint WIA_PAGE_JIS_B5 = 44;

        public const uint WIA_PAGE_JIS_B6 = 45;

        public const uint WIA_PAGE_JIS_B7 = 46;

        public const uint WIA_PAGE_JIS_B8 = 47;

        public const uint WIA_PAGE_JIS_B9 = 48;

        public const uint WIA_PAGE_JIS_B10 = 49;

        public const uint WIA_PAGE_JIS_2A = 50;

        public const uint WIA_PAGE_JIS_4A = 51;

        public const uint WIA_PAGE_DIN_2B = 52;

        public const uint WIA_PAGE_DIN_4B = 53;

        public const uint WIA_PAGE_AUTO = 100;

        public const uint WIA_PAGE_CUSTOM_BASE = 0x8000;

        public const uint WIA_COMPRESSION_NONE = 0;

        public const uint WIA_COMPRESSION_BI_RLE4 = 1;

        public const uint WIA_COMPRESSION_BI_RLE8 = 2;

        public const uint WIA_COMPRESSION_G3 = 3;

        public const uint WIA_COMPRESSION_G4 = 4;

        public const uint WIA_COMPRESSION_JPEG = 5;

        public const uint WIA_COMPRESSION_JBIG = 6;

        public const uint WIA_COMPRESSION_JPEG2K = 7;

        public const uint WIA_COMPRESSION_PNG = 8;

        public const uint WIA_COMPRESSION_AUTO = 100;

        public const uint WIA_PACKED_PIXEL = 0;

        public const uint WIA_PLANAR = 1;

        public const uint WIA_DATA_THRESHOLD = 0;

        public const uint WIA_DATA_DITHER = 1;

        public const uint WIA_DATA_GRAYSCALE = 2;

        public const uint WIA_DATA_COLOR = 3;

        public const uint WIA_DATA_COLOR_THRESHOLD = 4;

        public const uint WIA_DATA_COLOR_DITHER = 5;

        public const uint WIA_DATA_RAW_RGB = 6;

        public const uint WIA_DATA_RAW_BGR = 7;

        public const uint WIA_DATA_RAW_YUV = 8;

        public const uint WIA_DATA_RAW_YUVK = 9;

        public const uint WIA_DATA_RAW_CMY = 10;

        public const uint WIA_DATA_RAW_CMYK = 11;

        public const uint WIA_DATA_AUTO = 100;

        public const uint WIA_DEPTH_AUTO = 0;

        public const uint WIA_PHOTO_WHITE_1 = 0;

        public const uint WIA_PHOTO_WHITE_0 = 1;

        public const uint WIA_PROPPAGE_SCANNER_ITEM_GENERAL = 0x00000001;

        public const uint WIA_PROPPAGE_CAMERA_ITEM_GENERAL = 0x00000002;

        public const uint WIA_PROPPAGE_DEVICE_GENERAL = 0x00000004;

        public const uint WIA_INTENT_NONE = 0x00000000;

        public const uint WIA_INTENT_IMAGE_TYPE_COLOR = 0x00000001;

        public const uint WIA_INTENT_IMAGE_TYPE_GRAYSCALE = 0x00000002;

        public const uint WIA_INTENT_IMAGE_TYPE_TEXT = 0x00000004;

        public const uint WIA_INTENT_IMAGE_TYPE_MASK = 0x0000000F;

        public const uint WIA_INTENT_MINIMIZE_SIZE = 0x00010000;

        public const uint WIA_INTENT_MAXIMIZE_QUALITY = 0x00020000;

        public const uint WIA_INTENT_BEST_PREVIEW = 0x00040000;

        public const uint WIA_INTENT_SIZE_MASK = 0x000F0000;

        public const uint WIA_NUM_DIP = 16;

    }
}
