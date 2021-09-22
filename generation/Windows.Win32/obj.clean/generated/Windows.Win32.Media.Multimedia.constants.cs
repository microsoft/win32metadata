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


namespace Windows.Win32.Media.Multimedia
{
    public static partial class Apis
    {
        public const int MCI_TEST = 0x00000020;

        public const uint MCI_CAPTURE = 0x0870;

        public const uint MCI_MONITOR = 0x0871;

        public const uint MCI_RESERVE = 0x0872;

        public const uint MCI_SETAUDIO = 0x0873;

        public const uint MCI_SIGNAL = 0x0875;

        public const uint MCI_SETVIDEO = 0x0876;

        public const uint MCI_QUALITY = 0x0877;

        public const uint MCI_LIST = 0x0878;

        public const uint MCI_UNDO = 0x0879;

        public const uint MCI_CONFIGURE = 0x087a;

        public const uint MCI_RESTORE = 0x087b;

        public const uint MCI_ON = 1;

        public const uint MCI_OFF = 0;

        public const uint MCI_DGV_FILE_MODE_SAVING = 0x0001;

        public const uint MCI_DGV_FILE_MODE_LOADING = 0x0002;

        public const uint MCI_DGV_FILE_MODE_EDITING = 0x0003;

        public const uint MCI_DGV_FILE_MODE_IDLE = 0x0004;

        public const int MCI_ON_S = 0x00008000;

        public const int MCI_OFF_S = 0x00008001;

        public const int MCI_DGV_FILE_S = 0x00008002;

        public const int MCI_DGV_INPUT_S = 0x00008003;

        public const int MCI_DGV_FILE_MODE_SAVING_S = 0x00008004;

        public const int MCI_DGV_FILE_MODE_LOADING_S = 0x00008005;

        public const int MCI_DGV_FILE_MODE_EDITING_S = 0x00008006;

        public const int MCI_DGV_FILE_MODE_IDLE_S = 0x00008007;

        public const int MCI_DGV_SETVIDEO_SRC_NTSC_S = 0x00008010;

        public const int MCI_DGV_SETVIDEO_SRC_RGB_S = 0x00008011;

        public const int MCI_DGV_SETVIDEO_SRC_SVIDEO_S = 0x00008012;

        public const int MCI_DGV_SETVIDEO_SRC_PAL_S = 0x00008013;

        public const int MCI_DGV_SETVIDEO_SRC_SECAM_S = 0x00008014;

        public const int MCI_DGV_SETVIDEO_SRC_GENERIC_S = 0x00008015;

        public const int MCI_DGV_SETAUDIO_SRC_LEFT_S = 0x00008020;

        public const int MCI_DGV_SETAUDIO_SRC_RIGHT_S = 0x00008021;

        public const int MCI_DGV_SETAUDIO_SRC_AVERAGE_S = 0x00008022;

        public const int MCI_DGV_SETAUDIO_SRC_STEREO_S = 0x00008023;

        public const uint MM_MCISIGNAL = 0x3CB;

        public const uint MCIERR_DGV_DEVICE_LIMIT = MCIERR_CUSTOM_DRIVER_BASE+0;

        public const uint MCIERR_DGV_IOERR = MCIERR_CUSTOM_DRIVER_BASE+1;

        public const uint MCIERR_DGV_WORKSPACE_EMPTY = MCIERR_CUSTOM_DRIVER_BASE+2;

        public const uint MCIERR_DGV_DISK_FULL = MCIERR_CUSTOM_DRIVER_BASE+3;

        public const uint MCIERR_DGV_DEVICE_MEMORY_FULL = MCIERR_CUSTOM_DRIVER_BASE+4;

        public const uint MCIERR_DGV_BAD_CLIPBOARD_RANGE = MCIERR_CUSTOM_DRIVER_BASE+5;

        public const int MCI_DGV_METHOD_PRE = 0x0000a000;

        public const int MCI_DGV_METHOD_POST = 0x0000a001;

        public const int MCI_DGV_METHOD_DIRECT = 0x0000a002;

        public const int MCI_DGV_FF_AVSS = 0x00004000;

        public const int MCI_DGV_FF_AVI = 0x00004001;

        public const int MCI_DGV_FF_DIB = 0x00004002;

        public const int MCI_DGV_FF_RDIB = 0x00004003;

        public const int MCI_DGV_FF_JPEG = 0x00004004;

        public const int MCI_DGV_FF_RJPEG = 0x00004005;

        public const int MCI_DGV_FF_JFIF = 0x00004006;

        public const int MCI_DGV_FF_MPEG = 0x00004007;

        public const int MCI_DGV_GETDEVCAPS_CAN_LOCK = 0x00004000;

        public const int MCI_DGV_GETDEVCAPS_CAN_STRETCH = 0x00004001;

        public const int MCI_DGV_GETDEVCAPS_CAN_FREEZE = 0x00004002;

        public const int MCI_DGV_GETDEVCAPS_MAX_WINDOWS = 0x00004003;

        public const int MCI_DGV_GETDEVCAPS_CAN_REVERSE = 0x00004004;

        public const int MCI_DGV_GETDEVCAPS_HAS_STILL = 0x00004005;

        public const int MCI_DGV_GETDEVCAPS_PALETTES = 0x00004006;

        public const int MCI_DGV_GETDEVCAPS_CAN_STR_IN = 0x00004008;

        public const int MCI_DGV_GETDEVCAPS_CAN_TEST = 0x00004009;

        public const int MCI_DGV_GETDEVCAPS_MAXIMUM_RATE = 0x0000400a;

        public const int MCI_DGV_GETDEVCAPS_MINIMUM_RATE = 0x0000400b;

        public const int MCI_DGV_CAPTURE_AS = 0x00010000;

        public const int MCI_DGV_CAPTURE_AT = 0x00020000;

        public const int MCI_DGV_COPY_AT = 0x00010000;

        public const int MCI_DGV_COPY_AUDIO_STREAM = 0x00020000;

        public const int MCI_DGV_COPY_VIDEO_STREAM = 0x00040000;

        public const int MCI_DGV_CUE_INPUT = 0x00010000;

        public const int MCI_DGV_CUE_OUTPUT = 0x00020000;

        public const int MCI_DGV_CUE_NOSHOW = 0x00040000;

        public const int MCI_DGV_CUT_AT = 0x00010000;

        public const int MCI_DGV_CUT_AUDIO_STREAM = 0x00020000;

        public const int MCI_DGV_CUT_VIDEO_STREAM = 0x00040000;

        public const int MCI_DGV_DELETE_AT = 0x00010000;

        public const int MCI_DGV_DELETE_AUDIO_STREAM = 0x00020000;

        public const int MCI_DGV_DELETE_VIDEO_STREAM = 0x00040000;

        public const int MCI_DGV_FREEZE_AT = 0x00010000;

        public const int MCI_DGV_FREEZE_OUTSIDE = 0x00020000;

        public const int MCI_DGV_INFO_TEXT = 0x00010000;

        public const int MCI_DGV_INFO_ITEM = 0X00020000;

        public const int MCI_INFO_VERSION = 0x00000400;

        public const int MCI_DGV_INFO_USAGE = 0x00004000;

        public const int MCI_DGV_INFO_AUDIO_QUALITY = 0x00004001;

        public const int MCI_DGV_INFO_STILL_QUALITY = 0x00004002;

        public const int MCI_DGV_INFO_VIDEO_QUALITY = 0x00004003;

        public const int MCI_DGV_INFO_AUDIO_ALG = 0x00004004;

        public const int MCI_DGV_INFO_STILL_ALG = 0x00004005;

        public const int MCI_DGV_INFO_VIDEO_ALG = 0x00004006;

        public const int MCI_DGV_LIST_ITEM = 0x00010000;

        public const int MCI_DGV_LIST_COUNT = 0x00020000;

        public const int MCI_DGV_LIST_NUMBER = 0x00040000;

        public const int MCI_DGV_LIST_ALG = 0x00080000;

        public const int MCI_DGV_LIST_AUDIO_ALG = 0x00004000;

        public const int MCI_DGV_LIST_AUDIO_QUALITY = 0x00004001;

        public const int MCI_DGV_LIST_AUDIO_STREAM = 0x00004002;

        public const int MCI_DGV_LIST_STILL_ALG = 0x00004003;

        public const int MCI_DGV_LIST_STILL_QUALITY = 0x00004004;

        public const int MCI_DGV_LIST_VIDEO_ALG = 0x00004005;

        public const int MCI_DGV_LIST_VIDEO_QUALITY = 0x00004006;

        public const int MCI_DGV_LIST_VIDEO_STREAM = 0x00004007;

        public const int MCI_DGV_LIST_VIDEO_SOURCE = 0x00004008;

        public const int MCI_DGV_MONITOR_METHOD = 0x00010000;

        public const int MCI_DGV_MONITOR_SOURCE = 0x00020000;

        public const int MCI_DGV_MONITOR_INPUT = 0x00004000;

        public const int MCI_DGV_MONITOR_FILE = 0x00004001;

        public const int MCI_DGV_OPEN_WS = 0x00010000;

        public const int MCI_DGV_OPEN_PARENT = 0x00020000;

        public const int MCI_DGV_OPEN_NOSTATIC = 0x00040000;

        public const int MCI_DGV_OPEN_16BIT = 0x00080000;

        public const int MCI_DGV_OPEN_32BIT = 0x00100000;

        public const int MCI_DGV_PASTE_AT = 0x00010000;

        public const int MCI_DGV_PASTE_AUDIO_STREAM = 0x00020000;

        public const int MCI_DGV_PASTE_VIDEO_STREAM = 0x00040000;

        public const int MCI_DGV_PASTE_INSERT = 0x00080000;

        public const int MCI_DGV_PASTE_OVERWRITE = 0x00100000;

        public const int MCI_DGV_PLAY_REPEAT = 0x00010000;

        public const int MCI_DGV_PLAY_REVERSE = 0x00020000;

        public const int MCI_DGV_RECT = 0x00010000;

        public const int MCI_DGV_PUT_SOURCE = 0x00020000;

        public const int MCI_DGV_PUT_DESTINATION = 0x00040000;

        public const int MCI_DGV_PUT_FRAME = 0x00080000;

        public const int MCI_DGV_PUT_VIDEO = 0x00100000;

        public const int MCI_DGV_PUT_WINDOW = 0x00200000;

        public const int MCI_DGV_PUT_CLIENT = 0x00400000;

        public const int MCI_QUALITY_ITEM = 0x00010000;

        public const int MCI_QUALITY_NAME = 0x00020000;

        public const int MCI_QUALITY_ALG = 0x00040000;

        public const int MCI_QUALITY_DIALOG = 0x00080000;

        public const int MCI_QUALITY_HANDLE = 0x00100000;

        public const int MCI_QUALITY_ITEM_AUDIO = 0x00004000;

        public const int MCI_QUALITY_ITEM_STILL = 0x00004001;

        public const int MCI_QUALITY_ITEM_VIDEO = 0x00004002;

        public const int MCI_DGV_REALIZE_NORM = 0x00010000;

        public const int MCI_DGV_REALIZE_BKGD = 0x00020000;

        public const int MCI_DGV_RECORD_HOLD = 0x00020000;

        public const int MCI_DGV_RECORD_AUDIO_STREAM = 0x00040000;

        public const int MCI_DGV_RECORD_VIDEO_STREAM = 0x00080000;

        public const int MCI_DGV_RESERVE_IN = 0x00010000;

        public const int MCI_DGV_RESERVE_SIZE = 0x00020000;

        public const int MCI_DGV_RESTORE_FROM = 0x00010000;

        public const int MCI_DGV_RESTORE_AT = 0x00020000;

        public const int MCI_DGV_SAVE_ABORT = 0x00020000;

        public const int MCI_DGV_SAVE_KEEPRESERVE = 0x00040000;

        public const int MCI_DGV_SET_SEEK_EXACTLY = 0x00010000;

        public const int MCI_DGV_SET_SPEED = 0x00020000;

        public const int MCI_DGV_SET_STILL = 0x00040000;

        public const int MCI_DGV_SET_FILEFORMAT = 0x00080000;

        public const int MCI_DGV_SETAUDIO_OVER = 0x00010000;

        public const int MCI_DGV_SETAUDIO_CLOCKTIME = 0x00020000;

        public const int MCI_DGV_SETAUDIO_ALG = 0x00040000;

        public const int MCI_DGV_SETAUDIO_QUALITY = 0x00080000;

        public const int MCI_DGV_SETAUDIO_RECORD = 0x00100000;

        public const int MCI_DGV_SETAUDIO_LEFT = 0x00200000;

        public const int MCI_DGV_SETAUDIO_RIGHT = 0x00400000;

        public const int MCI_DGV_SETAUDIO_ITEM = 0x00800000;

        public const int MCI_DGV_SETAUDIO_VALUE = 0x01000000;

        public const int MCI_DGV_SETAUDIO_INPUT = 0x02000000;

        public const int MCI_DGV_SETAUDIO_OUTPUT = 0x04000000;

        public const int MCI_DGV_SETAUDIO_TREBLE = 0x00004000;

        public const int MCI_DGV_SETAUDIO_BASS = 0x00004001;

        public const int MCI_DGV_SETAUDIO_VOLUME = 0x00004002;

        public const int MCI_DGV_SETAUDIO_STREAM = 0x00004003;

        public const int MCI_DGV_SETAUDIO_SOURCE = 0x00004004;

        public const int MCI_DGV_SETAUDIO_SAMPLESPERSEC = 0x00004005;

        public const int MCI_DGV_SETAUDIO_AVGBYTESPERSEC = 0x00004006;

        public const int MCI_DGV_SETAUDIO_BLOCKALIGN = 0x00004007;

        public const int MCI_DGV_SETAUDIO_BITSPERSAMPLE = 0x00004008;

        public const int MCI_DGV_SETAUDIO_SOURCE_STEREO = 0x00000000;

        public const int MCI_DGV_SETAUDIO_SOURCE_LEFT = 0x00000001;

        public const int MCI_DGV_SETAUDIO_SOURCE_RIGHT = 0x00000002;

        public const int MCI_DGV_SETAUDIO_SOURCE_AVERAGE = 0x00004000;

        public const int MCI_DGV_SETVIDEO_QUALITY = 0x00010000;

        public const int MCI_DGV_SETVIDEO_ALG = 0x00020000;

        public const int MCI_DGV_SETVIDEO_CLOCKTIME = 0x00040000;

        public const int MCI_DGV_SETVIDEO_SRC_NUMBER = 0x00080000;

        public const int MCI_DGV_SETVIDEO_ITEM = 0x00100000;

        public const int MCI_DGV_SETVIDEO_OVER = 0x00200000;

        public const int MCI_DGV_SETVIDEO_RECORD = 0x00400000;

        public const int MCI_DGV_SETVIDEO_STILL = 0x00800000;

        public const int MCI_DGV_SETVIDEO_VALUE = 0x01000000;

        public const int MCI_DGV_SETVIDEO_INPUT = 0x02000000;

        public const int MCI_DGV_SETVIDEO_OUTPUT = 0x04000000;

        public const int MCI_DGV_SETVIDEO_SRC_NTSC = 0x00004000;

        public const int MCI_DGV_SETVIDEO_SRC_RGB = 0x00004001;

        public const int MCI_DGV_SETVIDEO_SRC_SVIDEO = 0x00004002;

        public const int MCI_DGV_SETVIDEO_SRC_PAL = 0x00004003;

        public const int MCI_DGV_SETVIDEO_SRC_SECAM = 0x00004004;

        public const int MCI_DGV_SETVIDEO_SRC_GENERIC = 0x00004005;

        public const int MCI_DGV_SETVIDEO_BRIGHTNESS = 0x00004000;

        public const int MCI_DGV_SETVIDEO_COLOR = 0x00004001;

        public const int MCI_DGV_SETVIDEO_CONTRAST = 0x00004002;

        public const int MCI_DGV_SETVIDEO_TINT = 0x00004003;

        public const int MCI_DGV_SETVIDEO_SHARPNESS = 0x00004004;

        public const int MCI_DGV_SETVIDEO_GAMMA = 0x00004005;

        public const int MCI_DGV_SETVIDEO_STREAM = 0x00004006;

        public const int MCI_DGV_SETVIDEO_PALHANDLE = 0x00004007;

        public const int MCI_DGV_SETVIDEO_FRAME_RATE = 0x00004008;

        public const int MCI_DGV_SETVIDEO_SOURCE = 0x00004009;

        public const int MCI_DGV_SETVIDEO_KEY_INDEX = 0x0000400a;

        public const int MCI_DGV_SETVIDEO_KEY_COLOR = 0x0000400b;

        public const int MCI_DGV_SETVIDEO_BITSPERPEL = 0x0000400c;

        public const int MCI_DGV_SIGNAL_AT = 0x00010000;

        public const int MCI_DGV_SIGNAL_EVERY = 0x00020000;

        public const int MCI_DGV_SIGNAL_USERVAL = 0x00040000;

        public const int MCI_DGV_SIGNAL_CANCEL = 0x00080000;

        public const int MCI_DGV_SIGNAL_POSITION = 0x00100000;

        public const int MCI_DGV_STATUS_NOMINAL = 0x00020000;

        public const int MCI_DGV_STATUS_REFERENCE = 0x00040000;

        public const int MCI_DGV_STATUS_LEFT = 0x00080000;

        public const int MCI_DGV_STATUS_RIGHT = 0x00100000;

        public const int MCI_DGV_STATUS_DISKSPACE = 0x00200000;

        public const int MCI_DGV_STATUS_INPUT = 0x00400000;

        public const int MCI_DGV_STATUS_OUTPUT = 0x00800000;

        public const int MCI_DGV_STATUS_RECORD = 0x01000000;

        public const int MCI_DGV_STATUS_AUDIO_INPUT = 0x00004000;

        public const int MCI_DGV_STATUS_HWND = 0x00004001;

        public const int MCI_DGV_STATUS_SPEED = 0x00004003;

        public const int MCI_DGV_STATUS_HPAL = 0x00004004;

        public const int MCI_DGV_STATUS_BRIGHTNESS = 0x00004005;

        public const int MCI_DGV_STATUS_COLOR = 0x00004006;

        public const int MCI_DGV_STATUS_CONTRAST = 0x00004007;

        public const int MCI_DGV_STATUS_FILEFORMAT = 0x00004008;

        public const int MCI_DGV_STATUS_AUDIO_SOURCE = 0x00004009;

        public const int MCI_DGV_STATUS_GAMMA = 0x0000400a;

        public const int MCI_DGV_STATUS_MONITOR = 0x0000400b;

        public const int MCI_DGV_STATUS_MONITOR_METHOD = 0x0000400c;

        public const int MCI_DGV_STATUS_FRAME_RATE = 0x0000400e;

        public const int MCI_DGV_STATUS_BASS = 0x0000400f;

        public const int MCI_DGV_STATUS_SIZE = 0x00004010;

        public const int MCI_DGV_STATUS_SEEK_EXACTLY = 0x00004011;

        public const int MCI_DGV_STATUS_SHARPNESS = 0x00004012;

        public const int MCI_DGV_STATUS_SMPTE = 0x00004013;

        public const int MCI_DGV_STATUS_AUDIO = 0x00004014;

        public const int MCI_DGV_STATUS_TINT = 0x00004015;

        public const int MCI_DGV_STATUS_TREBLE = 0x00004016;

        public const int MCI_DGV_STATUS_UNSAVED = 0x00004017;

        public const int MCI_DGV_STATUS_VIDEO = 0x00004018;

        public const int MCI_DGV_STATUS_VOLUME = 0x00004019;

        public const int MCI_DGV_STATUS_AUDIO_RECORD = 0x0000401a;

        public const int MCI_DGV_STATUS_VIDEO_SOURCE = 0x0000401b;

        public const int MCI_DGV_STATUS_VIDEO_RECORD = 0x0000401c;

        public const int MCI_DGV_STATUS_STILL_FILEFORMAT = 0x0000401d;

        public const int MCI_DGV_STATUS_VIDEO_SRC_NUM = 0x0000401e;

        public const int MCI_DGV_STATUS_FILE_MODE = 0x0000401f;

        public const int MCI_DGV_STATUS_FILE_COMPLETION = 0x00004020;

        public const int MCI_DGV_STATUS_WINDOW_VISIBLE = 0x00004021;

        public const int MCI_DGV_STATUS_WINDOW_MINIMIZED = 0x00004022;

        public const int MCI_DGV_STATUS_WINDOW_MAXIMIZED = 0x00004023;

        public const int MCI_DGV_STATUS_KEY_INDEX = 0x00004024;

        public const int MCI_DGV_STATUS_KEY_COLOR = 0x00004025;

        public const int MCI_DGV_STATUS_PAUSE_MODE = 0x00004026;

        public const int MCI_DGV_STATUS_SAMPLESPERSEC = 0x00004027;

        public const int MCI_DGV_STATUS_AVGBYTESPERSEC = 0x00004028;

        public const int MCI_DGV_STATUS_BLOCKALIGN = 0x00004029;

        public const int MCI_DGV_STATUS_BITSPERSAMPLE = 0x0000402a;

        public const int MCI_DGV_STATUS_BITSPERPEL = 0x0000402b;

        public const int MCI_DGV_STATUS_FORWARD = 0x0000402c;

        public const int MCI_DGV_STATUS_AUDIO_STREAM = 0x0000402d;

        public const int MCI_DGV_STATUS_VIDEO_STREAM = 0x0000402e;

        public const int MCI_DGV_STEP_REVERSE = 0x00010000;

        public const int MCI_DGV_STEP_FRAMES = 0x00020000;

        public const int MCI_DGV_STOP_HOLD = 0x00010000;

        public const int MCI_DGV_UPDATE_HDC = 0x00020000;

        public const int MCI_DGV_UPDATE_PAINT = 0x00040000;

        public const int MCI_DGV_WHERE_SOURCE = 0x00020000;

        public const int MCI_DGV_WHERE_DESTINATION = 0x00040000;

        public const int MCI_DGV_WHERE_FRAME = 0x00080000;

        public const int MCI_DGV_WHERE_VIDEO = 0x00100000;

        public const int MCI_DGV_WHERE_WINDOW = 0x00200000;

        public const int MCI_DGV_WHERE_MAX = 0x00400000;

        public const int MCI_DGV_WINDOW_HWND = 0x00010000;

        public const int MCI_DGV_WINDOW_STATE = 0x00040000;

        public const int MCI_DGV_WINDOW_TEXT = 0x00080000;

        public const int MCI_DGV_WINDOW_DEFAULT = 0x00000000;

        public const uint MM_MICROSOFT = 1;

        public const uint MM_CREATIVE = 2;

        public const uint MM_MEDIAVISION = 3;

        public const uint MM_FUJITSU = 4;

        public const uint MM_PRAGMATRAX = 5;

        public const uint MM_CYRIX = 6;

        public const uint MM_PHILIPS_SPEECH_PROCESSING = 7;

        public const uint MM_NETXL = 8;

        public const uint MM_ZYXEL = 9;

        public const uint MM_BECUBED = 10;

        public const uint MM_AARDVARK = 11;

        public const uint MM_BINTEC = 12;

        public const uint MM_HEWLETT_PACKARD = 13;

        public const uint MM_ACULAB = 14;

        public const uint MM_FAITH = 15;

        public const uint MM_MITEL = 16;

        public const uint MM_QUANTUM3D = 17;

        public const uint MM_SNI = 18;

        public const uint MM_EMU = 19;

        public const uint MM_ARTISOFT = 20;

        public const uint MM_TURTLE_BEACH = 21;

        public const uint MM_IBM = 22;

        public const uint MM_VOCALTEC = 23;

        public const uint MM_ROLAND = 24;

        public const uint MM_DSP_SOLUTIONS = 25;

        public const uint MM_NEC = 26;

        public const uint MM_ATI = 27;

        public const uint MM_WANGLABS = 28;

        public const uint MM_TANDY = 29;

        public const uint MM_VOYETRA = 30;

        public const uint MM_ANTEX = 31;

        public const uint MM_ICL_PS = 32;

        public const uint MM_INTEL = 33;

        public const uint MM_GRAVIS = 34;

        public const uint MM_VAL = 35;

        public const uint MM_INTERACTIVE = 36;

        public const uint MM_YAMAHA = 37;

        public const uint MM_EVEREX = 38;

        public const uint MM_ECHO = 39;

        public const uint MM_SIERRA = 40;

        public const uint MM_CAT = 41;

        public const uint MM_APPS = 42;

        public const uint MM_DSP_GROUP = 43;

        public const uint MM_MELABS = 44;

        public const uint MM_COMPUTER_FRIENDS = 45;

        public const uint MM_ESS = 46;

        public const uint MM_AUDIOFILE = 47;

        public const uint MM_MOTOROLA = 48;

        public const uint MM_CANOPUS = 49;

        public const uint MM_EPSON = 50;

        public const uint MM_TRUEVISION = 51;

        public const uint MM_AZTECH = 52;

        public const uint MM_VIDEOLOGIC = 53;

        public const uint MM_SCALACS = 54;

        public const uint MM_KORG = 55;

        public const uint MM_APT = 56;

        public const uint MM_ICS = 57;

        public const uint MM_ITERATEDSYS = 58;

        public const uint MM_METHEUS = 59;

        public const uint MM_LOGITECH = 60;

        public const uint MM_WINNOV = 61;

        public const uint MM_NCR = 62;

        public const uint MM_EXAN = 63;

        public const uint MM_AST = 64;

        public const uint MM_WILLOWPOND = 65;

        public const uint MM_SONICFOUNDRY = 66;

        public const uint MM_VITEC = 67;

        public const uint MM_MOSCOM = 68;

        public const uint MM_SILICONSOFT = 69;

        public const uint MM_TERRATEC = 70;

        public const uint MM_MEDIASONIC = 71;

        public const uint MM_SANYO = 72;

        public const uint MM_SUPERMAC = 73;

        public const uint MM_AUDIOPT = 74;

        public const uint MM_NOGATECH = 75;

        public const uint MM_SPEECHCOMP = 76;

        public const uint MM_AHEAD = 77;

        public const uint MM_DOLBY = 78;

        public const uint MM_OKI = 79;

        public const uint MM_AURAVISION = 80;

        public const uint MM_OLIVETTI = 81;

        public const uint MM_IOMAGIC = 82;

        public const uint MM_MATSUSHITA = 83;

        public const uint MM_CONTROLRES = 84;

        public const uint MM_XEBEC = 85;

        public const uint MM_NEWMEDIA = 86;

        public const uint MM_NMS = 87;

        public const uint MM_LYRRUS = 88;

        public const uint MM_COMPUSIC = 89;

        public const uint MM_OPTI = 90;

        public const uint MM_ADLACC = 91;

        public const uint MM_COMPAQ = 92;

        public const uint MM_DIALOGIC = 93;

        public const uint MM_INSOFT = 94;

        public const uint MM_MPTUS = 95;

        public const uint MM_WEITEK = 96;

        public const uint MM_LERNOUT_AND_HAUSPIE = 97;

        public const uint MM_QCIAR = 98;

        public const uint MM_APPLE = 99;

        public const uint MM_DIGITAL = 100;

        public const uint MM_MOTU = 101;

        public const uint MM_WORKBIT = 102;

        public const uint MM_OSITECH = 103;

        public const uint MM_MIRO = 104;

        public const uint MM_CIRRUSLOGIC = 105;

        public const uint MM_ISOLUTION = 106;

        public const uint MM_HORIZONS = 107;

        public const uint MM_CONCEPTS = 108;

        public const uint MM_VTG = 109;

        public const uint MM_RADIUS = 110;

        public const uint MM_ROCKWELL = 111;

        public const uint MM_XYZ = 112;

        public const uint MM_OPCODE = 113;

        public const uint MM_VOXWARE = 114;

        public const uint MM_NORTHERN_TELECOM = 115;

        public const uint MM_APICOM = 116;

        public const uint MM_GRANDE = 117;

        public const uint MM_ADDX = 118;

        public const uint MM_WILDCAT = 119;

        public const uint MM_RHETOREX = 120;

        public const uint MM_BROOKTREE = 121;

        public const uint MM_ENSONIQ = 125;

        public const uint MM_FAST = 126;

        public const uint MM_NVIDIA = 127;

        public const uint MM_OKSORI = 128;

        public const uint MM_DIACOUSTICS = 129;

        public const uint MM_GULBRANSEN = 130;

        public const uint MM_KAY_ELEMETRICS = 131;

        public const uint MM_CRYSTAL = 132;

        public const uint MM_SPLASH_STUDIOS = 133;

        public const uint MM_QUARTERDECK = 134;

        public const uint MM_TDK = 135;

        public const uint MM_DIGITAL_AUDIO_LABS = 136;

        public const uint MM_SEERSYS = 137;

        public const uint MM_PICTURETEL = 138;

        public const uint MM_ATT_MICROELECTRONICS = 139;

        public const uint MM_OSPREY = 140;

        public const uint MM_MEDIATRIX = 141;

        public const uint MM_SOUNDESIGNS = 142;

        public const uint MM_ALDIGITAL = 143;

        public const uint MM_SPECTRUM_SIGNAL_PROCESSING = 144;

        public const uint MM_ECS = 145;

        public const uint MM_AMD = 146;

        public const uint MM_COREDYNAMICS = 147;

        public const uint MM_CANAM = 148;

        public const uint MM_SOFTSOUND = 149;

        public const uint MM_NORRIS = 150;

        public const uint MM_DDD = 151;

        public const uint MM_EUPHONICS = 152;

        public const uint MM_PRECEPT = 153;

        public const uint MM_CRYSTAL_NET = 154;

        public const uint MM_CHROMATIC = 155;

        public const uint MM_VOICEINFO = 156;

        public const uint MM_VIENNASYS = 157;

        public const uint MM_CONNECTIX = 158;

        public const uint MM_GADGETLABS = 159;

        public const uint MM_FRONTIER = 160;

        public const uint MM_VIONA = 161;

        public const uint MM_CASIO = 162;

        public const uint MM_DIAMONDMM = 163;

        public const uint MM_S3 = 164;

        public const uint MM_DVISION = 165;

        public const uint MM_NETSCAPE = 166;

        public const uint MM_SOUNDSPACE = 167;

        public const uint MM_VANKOEVERING = 168;

        public const uint MM_QTEAM = 169;

        public const uint MM_ZEFIRO = 170;

        public const uint MM_STUDER = 171;

        public const uint MM_FRAUNHOFER_IIS = 172;

        public const uint MM_QUICKNET = 173;

        public const uint MM_ALARIS = 174;

        public const uint MM_SICRESOURCE = 175;

        public const uint MM_NEOMAGIC = 176;

        public const uint MM_MERGING_TECHNOLOGIES = 177;

        public const uint MM_XIRLINK = 178;

        public const uint MM_COLORGRAPH = 179;

        public const uint MM_OTI = 180;

        public const uint MM_AUREAL = 181;

        public const uint MM_VIVO = 182;

        public const uint MM_SHARP = 183;

        public const uint MM_LUCENT = 184;

        public const uint MM_ATT = 185;

        public const uint MM_SUNCOM = 186;

        public const uint MM_SORVIS = 187;

        public const uint MM_INVISION = 188;

        public const uint MM_BERKOM = 189;

        public const uint MM_MARIAN = 190;

        public const uint MM_DPSINC = 191;

        public const uint MM_BCB = 192;

        public const uint MM_MOTIONPIXELS = 193;

        public const uint MM_QDESIGN = 194;

        public const uint MM_NMP = 195;

        public const uint MM_DATAFUSION = 196;

        public const uint MM_DUCK = 197;

        public const uint MM_FTR = 198;

        public const uint MM_BERCOS = 199;

        public const uint MM_ONLIVE = 200;

        public const uint MM_SIEMENS_SBC = 201;

        public const uint MM_TERALOGIC = 202;

        public const uint MM_PHONET = 203;

        public const uint MM_WINBOND = 204;

        public const uint MM_VIRTUALMUSIC = 205;

        public const uint MM_ENET = 206;

        public const uint MM_GUILLEMOT = 207;

        public const uint MM_EMAGIC = 208;

        public const uint MM_MWM = 209;

        public const uint MM_PACIFICRESEARCH = 210;

        public const uint MM_SIPROLAB = 211;

        public const uint MM_LYNX = 212;

        public const uint MM_SPECTRUM_PRODUCTIONS = 213;

        public const uint MM_DICTAPHONE = 214;

        public const uint MM_QUALCOMM = 215;

        public const uint MM_RZS = 216;

        public const uint MM_AUDIOSCIENCE = 217;

        public const uint MM_PINNACLE = 218;

        public const uint MM_EES = 219;

        public const uint MM_HAFTMANN = 220;

        public const uint MM_LUCID = 221;

        public const uint MM_HEADSPACE = 222;

        public const uint MM_UNISYS = 223;

        public const uint MM_LUMINOSITI = 224;

        public const uint MM_ACTIVEVOICE = 225;

        public const uint MM_DTS = 226;

        public const uint MM_DIGIGRAM = 227;

        public const uint MM_SOFTLAB_NSK = 228;

        public const uint MM_FORTEMEDIA = 229;

        public const uint MM_SONORUS = 230;

        public const uint MM_ARRAY = 231;

        public const uint MM_DATARAN = 232;

        public const uint MM_I_LINK = 233;

        public const uint MM_SELSIUS_SYSTEMS = 234;

        public const uint MM_ADMOS = 235;

        public const uint MM_LEXICON = 236;

        public const uint MM_SGI = 237;

        public const uint MM_IPI = 238;

        public const uint MM_ICE = 239;

        public const uint MM_VQST = 240;

        public const uint MM_ETEK = 241;

        public const uint MM_CS = 242;

        public const uint MM_ALESIS = 243;

        public const uint MM_INTERNET = 244;

        public const uint MM_SONY = 245;

        public const uint MM_HYPERACTIVE = 246;

        public const uint MM_UHER_INFORMATIC = 247;

        public const uint MM_SYDEC_NV = 248;

        public const uint MM_FLEXION = 249;

        public const uint MM_VIA = 250;

        public const uint MM_MICRONAS = 251;

        public const uint MM_ANALOGDEVICES = 252;

        public const uint MM_HP = 253;

        public const uint MM_MATROX_DIV = 254;

        public const uint MM_QUICKAUDIO = 255;

        public const uint MM_YOUCOM = 256;

        public const uint MM_RICHMOND = 257;

        public const uint MM_IODD = 258;

        public const uint MM_ICCC = 259;

        public const uint MM_3COM = 260;

        public const uint MM_MALDEN = 261;

        public const uint MM_3DFX = 262;

        public const uint MM_MINDMAKER = 263;

        public const uint MM_TELEKOL = 264;

        public const uint MM_ST_MICROELECTRONICS = 265;

        public const uint MM_ALGOVISION = 266;

        public const uint MM_UNMAPPED = 0xffff;

        public const uint MM_MIDI_MAPPER = 1;

        public const uint MM_WAVE_MAPPER = 2;

        public const uint MM_SNDBLST_MIDIOUT = 3;

        public const uint MM_SNDBLST_MIDIIN = 4;

        public const uint MM_SNDBLST_SYNTH = 5;

        public const uint MM_SNDBLST_WAVEOUT = 6;

        public const uint MM_SNDBLST_WAVEIN = 7;

        public const uint MM_ADLIB = 9;

        public const uint MM_MPU401_MIDIOUT = 10;

        public const uint MM_MPU401_MIDIIN = 11;

        public const uint MM_PC_JOYSTICK = 12;

        public const uint MM_PCSPEAKER_WAVEOUT = 13;

        public const uint MM_MSFT_WSS_WAVEIN = 14;

        public const uint MM_MSFT_WSS_WAVEOUT = 15;

        public const uint MM_MSFT_WSS_FMSYNTH_STEREO = 16;

        public const uint MM_MSFT_WSS_MIXER = 17;

        public const uint MM_MSFT_WSS_OEM_WAVEIN = 18;

        public const uint MM_MSFT_WSS_OEM_WAVEOUT = 19;

        public const uint MM_MSFT_WSS_OEM_FMSYNTH_STEREO = 20;

        public const uint MM_MSFT_WSS_AUX = 21;

        public const uint MM_MSFT_WSS_OEM_AUX = 22;

        public const uint MM_MSFT_GENERIC_WAVEIN = 23;

        public const uint MM_MSFT_GENERIC_WAVEOUT = 24;

        public const uint MM_MSFT_GENERIC_MIDIIN = 25;

        public const uint MM_MSFT_GENERIC_MIDIOUT = 26;

        public const uint MM_MSFT_GENERIC_MIDISYNTH = 27;

        public const uint MM_MSFT_GENERIC_AUX_LINE = 28;

        public const uint MM_MSFT_GENERIC_AUX_MIC = 29;

        public const uint MM_MSFT_GENERIC_AUX_CD = 30;

        public const uint MM_MSFT_WSS_OEM_MIXER = 31;

        public const uint MM_MSFT_MSACM = 32;

        public const uint MM_MSFT_ACM_MSADPCM = 33;

        public const uint MM_MSFT_ACM_IMAADPCM = 34;

        public const uint MM_MSFT_ACM_MSFILTER = 35;

        public const uint MM_MSFT_ACM_GSM610 = 36;

        public const uint MM_MSFT_ACM_G711 = 37;

        public const uint MM_MSFT_ACM_PCM = 38;

        public const uint MM_WSS_SB16_WAVEIN = 39;

        public const uint MM_WSS_SB16_WAVEOUT = 40;

        public const uint MM_WSS_SB16_MIDIIN = 41;

        public const uint MM_WSS_SB16_MIDIOUT = 42;

        public const uint MM_WSS_SB16_SYNTH = 43;

        public const uint MM_WSS_SB16_AUX_LINE = 44;

        public const uint MM_WSS_SB16_AUX_CD = 45;

        public const uint MM_WSS_SB16_MIXER = 46;

        public const uint MM_WSS_SBPRO_WAVEIN = 47;

        public const uint MM_WSS_SBPRO_WAVEOUT = 48;

        public const uint MM_WSS_SBPRO_MIDIIN = 49;

        public const uint MM_WSS_SBPRO_MIDIOUT = 50;

        public const uint MM_WSS_SBPRO_SYNTH = 51;

        public const uint MM_WSS_SBPRO_AUX_LINE = 52;

        public const uint MM_WSS_SBPRO_AUX_CD = 53;

        public const uint MM_WSS_SBPRO_MIXER = 54;

        public const uint MM_MSFT_WSS_NT_WAVEIN = 55;

        public const uint MM_MSFT_WSS_NT_WAVEOUT = 56;

        public const uint MM_MSFT_WSS_NT_FMSYNTH_STEREO = 57;

        public const uint MM_MSFT_WSS_NT_MIXER = 58;

        public const uint MM_MSFT_WSS_NT_AUX = 59;

        public const uint MM_MSFT_SB16_WAVEIN = 60;

        public const uint MM_MSFT_SB16_WAVEOUT = 61;

        public const uint MM_MSFT_SB16_MIDIIN = 62;

        public const uint MM_MSFT_SB16_MIDIOUT = 63;

        public const uint MM_MSFT_SB16_SYNTH = 64;

        public const uint MM_MSFT_SB16_AUX_LINE = 65;

        public const uint MM_MSFT_SB16_AUX_CD = 66;

        public const uint MM_MSFT_SB16_MIXER = 67;

        public const uint MM_MSFT_SBPRO_WAVEIN = 68;

        public const uint MM_MSFT_SBPRO_WAVEOUT = 69;

        public const uint MM_MSFT_SBPRO_MIDIIN = 70;

        public const uint MM_MSFT_SBPRO_MIDIOUT = 71;

        public const uint MM_MSFT_SBPRO_SYNTH = 72;

        public const uint MM_MSFT_SBPRO_AUX_LINE = 73;

        public const uint MM_MSFT_SBPRO_AUX_CD = 74;

        public const uint MM_MSFT_SBPRO_MIXER = 75;

        public const uint MM_MSFT_MSOPL_SYNTH = 76;

        public const uint MM_MSFT_VMDMS_LINE_WAVEIN = 80;

        public const uint MM_MSFT_VMDMS_LINE_WAVEOUT = 81;

        public const uint MM_MSFT_VMDMS_HANDSET_WAVEIN = 82;

        public const uint MM_MSFT_VMDMS_HANDSET_WAVEOUT = 83;

        public const uint MM_MSFT_VMDMW_LINE_WAVEIN = 84;

        public const uint MM_MSFT_VMDMW_LINE_WAVEOUT = 85;

        public const uint MM_MSFT_VMDMW_HANDSET_WAVEIN = 86;

        public const uint MM_MSFT_VMDMW_HANDSET_WAVEOUT = 87;

        public const uint MM_MSFT_VMDMW_MIXER = 88;

        public const uint MM_MSFT_VMDM_GAME_WAVEOUT = 89;

        public const uint MM_MSFT_VMDM_GAME_WAVEIN = 90;

        public const uint MM_MSFT_ACM_MSNAUDIO = 91;

        public const uint MM_MSFT_ACM_MSG723 = 92;

        public const uint MM_MSFT_ACM_MSRT24 = 93;

        public const uint MM_MSFT_WDMAUDIO_WAVEOUT = 100;

        public const uint MM_MSFT_WDMAUDIO_WAVEIN = 101;

        public const uint MM_MSFT_WDMAUDIO_MIDIOUT = 102;

        public const uint MM_MSFT_WDMAUDIO_MIDIIN = 103;

        public const uint MM_MSFT_WDMAUDIO_MIXER = 104;

        public const uint MM_MSFT_WDMAUDIO_AUX = 105;

        public const uint MM_CREATIVE_SB15_WAVEIN = 1;

        public const uint MM_CREATIVE_SB20_WAVEIN = 2;

        public const uint MM_CREATIVE_SBPRO_WAVEIN = 3;

        public const uint MM_CREATIVE_SBP16_WAVEIN = 4;

        public const uint MM_CREATIVE_PHNBLST_WAVEIN = 5;

        public const uint MM_CREATIVE_SB15_WAVEOUT = 101;

        public const uint MM_CREATIVE_SB20_WAVEOUT = 102;

        public const uint MM_CREATIVE_SBPRO_WAVEOUT = 103;

        public const uint MM_CREATIVE_SBP16_WAVEOUT = 104;

        public const uint MM_CREATIVE_PHNBLST_WAVEOUT = 105;

        public const uint MM_CREATIVE_MIDIOUT = 201;

        public const uint MM_CREATIVE_MIDIIN = 202;

        public const uint MM_CREATIVE_FMSYNTH_MONO = 301;

        public const uint MM_CREATIVE_FMSYNTH_STEREO = 302;

        public const uint MM_CREATIVE_MIDI_AWE32 = 303;

        public const uint MM_CREATIVE_AUX_CD = 401;

        public const uint MM_CREATIVE_AUX_LINE = 402;

        public const uint MM_CREATIVE_AUX_MIC = 403;

        public const uint MM_CREATIVE_AUX_MASTER = 404;

        public const uint MM_CREATIVE_AUX_PCSPK = 405;

        public const uint MM_CREATIVE_AUX_WAVE = 406;

        public const uint MM_CREATIVE_AUX_MIDI = 407;

        public const uint MM_CREATIVE_SBPRO_MIXER = 408;

        public const uint MM_CREATIVE_SB16_MIXER = 409;

        public const uint MM_MEDIAVISION_PROAUDIO = 0x10;

        public const uint MM_PROAUD_MIDIOUT = MM_MEDIAVISION_PROAUDIO+1;

        public const uint MM_PROAUD_MIDIIN = MM_MEDIAVISION_PROAUDIO+2;

        public const uint MM_PROAUD_SYNTH = MM_MEDIAVISION_PROAUDIO+3;

        public const uint MM_PROAUD_WAVEOUT = MM_MEDIAVISION_PROAUDIO+4;

        public const uint MM_PROAUD_WAVEIN = MM_MEDIAVISION_PROAUDIO+5;

        public const uint MM_PROAUD_MIXER = MM_MEDIAVISION_PROAUDIO+6;

        public const uint MM_PROAUD_AUX = MM_MEDIAVISION_PROAUDIO+7;

        public const uint MM_MEDIAVISION_THUNDER = 0x20;

        public const uint MM_THUNDER_SYNTH = MM_MEDIAVISION_THUNDER+3;

        public const uint MM_THUNDER_WAVEOUT = MM_MEDIAVISION_THUNDER+4;

        public const uint MM_THUNDER_WAVEIN = MM_MEDIAVISION_THUNDER+5;

        public const uint MM_THUNDER_AUX = MM_MEDIAVISION_THUNDER+7;

        public const uint MM_MEDIAVISION_TPORT = 0x40;

        public const uint MM_TPORT_WAVEOUT = MM_MEDIAVISION_TPORT+1;

        public const uint MM_TPORT_WAVEIN = MM_MEDIAVISION_TPORT+2;

        public const uint MM_TPORT_SYNTH = MM_MEDIAVISION_TPORT+3;

        public const uint MM_MEDIAVISION_PROAUDIO_PLUS = 0x50;

        public const uint MM_PROAUD_PLUS_MIDIOUT = MM_MEDIAVISION_PROAUDIO_PLUS+1;

        public const uint MM_PROAUD_PLUS_MIDIIN = MM_MEDIAVISION_PROAUDIO_PLUS+2;

        public const uint MM_PROAUD_PLUS_SYNTH = MM_MEDIAVISION_PROAUDIO_PLUS+3;

        public const uint MM_PROAUD_PLUS_WAVEOUT = MM_MEDIAVISION_PROAUDIO_PLUS+4;

        public const uint MM_PROAUD_PLUS_WAVEIN = MM_MEDIAVISION_PROAUDIO_PLUS+5;

        public const uint MM_PROAUD_PLUS_MIXER = MM_MEDIAVISION_PROAUDIO_PLUS+6;

        public const uint MM_PROAUD_PLUS_AUX = MM_MEDIAVISION_PROAUDIO_PLUS+7;

        public const uint MM_MEDIAVISION_PROAUDIO_16 = 0x60;

        public const uint MM_PROAUD_16_MIDIOUT = MM_MEDIAVISION_PROAUDIO_16+1;

        public const uint MM_PROAUD_16_MIDIIN = MM_MEDIAVISION_PROAUDIO_16+2;

        public const uint MM_PROAUD_16_SYNTH = MM_MEDIAVISION_PROAUDIO_16+3;

        public const uint MM_PROAUD_16_WAVEOUT = MM_MEDIAVISION_PROAUDIO_16+4;

        public const uint MM_PROAUD_16_WAVEIN = MM_MEDIAVISION_PROAUDIO_16+5;

        public const uint MM_PROAUD_16_MIXER = MM_MEDIAVISION_PROAUDIO_16+6;

        public const uint MM_PROAUD_16_AUX = MM_MEDIAVISION_PROAUDIO_16+7;

        public const uint MM_MEDIAVISION_PROSTUDIO_16 = 0x60;

        public const uint MM_STUDIO_16_MIDIOUT = MM_MEDIAVISION_PROSTUDIO_16+1;

        public const uint MM_STUDIO_16_MIDIIN = MM_MEDIAVISION_PROSTUDIO_16+2;

        public const uint MM_STUDIO_16_SYNTH = MM_MEDIAVISION_PROSTUDIO_16+3;

        public const uint MM_STUDIO_16_WAVEOUT = MM_MEDIAVISION_PROSTUDIO_16+4;

        public const uint MM_STUDIO_16_WAVEIN = MM_MEDIAVISION_PROSTUDIO_16+5;

        public const uint MM_STUDIO_16_MIXER = MM_MEDIAVISION_PROSTUDIO_16+6;

        public const uint MM_STUDIO_16_AUX = MM_MEDIAVISION_PROSTUDIO_16+7;

        public const uint MM_MEDIAVISION_CDPC = 0x70;

        public const uint MM_CDPC_MIDIOUT = MM_MEDIAVISION_CDPC+1;

        public const uint MM_CDPC_MIDIIN = MM_MEDIAVISION_CDPC+2;

        public const uint MM_CDPC_SYNTH = MM_MEDIAVISION_CDPC+3;

        public const uint MM_CDPC_WAVEOUT = MM_MEDIAVISION_CDPC+4;

        public const uint MM_CDPC_WAVEIN = MM_MEDIAVISION_CDPC+5;

        public const uint MM_CDPC_MIXER = MM_MEDIAVISION_CDPC+6;

        public const uint MM_CDPC_AUX = MM_MEDIAVISION_CDPC+7;

        public const uint MM_MEDIAVISION_OPUS1208 = 0x80;

        public const uint MM_OPUS401_MIDIOUT = MM_MEDIAVISION_OPUS1208+1;

        public const uint MM_OPUS401_MIDIIN = MM_MEDIAVISION_OPUS1208+2;

        public const uint MM_OPUS1208_SYNTH = MM_MEDIAVISION_OPUS1208+3;

        public const uint MM_OPUS1208_WAVEOUT = MM_MEDIAVISION_OPUS1208+4;

        public const uint MM_OPUS1208_WAVEIN = MM_MEDIAVISION_OPUS1208+5;

        public const uint MM_OPUS1208_MIXER = MM_MEDIAVISION_OPUS1208+6;

        public const uint MM_OPUS1208_AUX = MM_MEDIAVISION_OPUS1208+7;

        public const uint MM_MEDIAVISION_OPUS1216 = 0x90;

        public const uint MM_OPUS1216_MIDIOUT = MM_MEDIAVISION_OPUS1216+1;

        public const uint MM_OPUS1216_MIDIIN = MM_MEDIAVISION_OPUS1216+2;

        public const uint MM_OPUS1216_SYNTH = MM_MEDIAVISION_OPUS1216+3;

        public const uint MM_OPUS1216_WAVEOUT = MM_MEDIAVISION_OPUS1216+4;

        public const uint MM_OPUS1216_WAVEIN = MM_MEDIAVISION_OPUS1216+5;

        public const uint MM_OPUS1216_MIXER = MM_MEDIAVISION_OPUS1216+6;

        public const uint MM_OPUS1216_AUX = MM_MEDIAVISION_OPUS1216+7;

        public const uint MM_CYRIX_XASYNTH = 1;

        public const uint MM_CYRIX_XAMIDIIN = 2;

        public const uint MM_CYRIX_XAMIDIOUT = 3;

        public const uint MM_CYRIX_XAWAVEIN = 4;

        public const uint MM_CYRIX_XAWAVEOUT = 5;

        public const uint MM_CYRIX_XAAUX = 6;

        public const uint MM_CYRIX_XAMIXER = 7;

        public const uint MM_PHILIPS_ACM_LPCBB = 1;

        public const uint MM_NETXL_XLVIDEO = 1;

        public const uint MM_ZYXEL_ACM_ADPCM = 1;

        public const uint MM_AARDVARK_STUDIO12_WAVEOUT = 1;

        public const uint MM_AARDVARK_STUDIO12_WAVEIN = 2;

        public const uint MM_AARDVARK_STUDIO88_WAVEOUT = 3;

        public const uint MM_AARDVARK_STUDIO88_WAVEIN = 4;

        public const uint MM_BINTEC_TAPI_WAVE = 1;

        public const uint MM_HEWLETT_PACKARD_CU_CODEC = 1;

        public const uint MM_MITEL_TALKTO_LINE_WAVEOUT = 100;

        public const uint MM_MITEL_TALKTO_LINE_WAVEIN = 101;

        public const uint MM_MITEL_TALKTO_HANDSET_WAVEOUT = 102;

        public const uint MM_MITEL_TALKTO_HANDSET_WAVEIN = 103;

        public const uint MM_MITEL_TALKTO_BRIDGED_WAVEOUT = 104;

        public const uint MM_MITEL_TALKTO_BRIDGED_WAVEIN = 105;

        public const uint MM_MITEL_MPA_HANDSET_WAVEOUT = 200;

        public const uint MM_MITEL_MPA_HANDSET_WAVEIN = 201;

        public const uint MM_MITEL_MPA_HANDSFREE_WAVEOUT = 202;

        public const uint MM_MITEL_MPA_HANDSFREE_WAVEIN = 203;

        public const uint MM_MITEL_MPA_LINE1_WAVEOUT = 204;

        public const uint MM_MITEL_MPA_LINE1_WAVEIN = 205;

        public const uint MM_MITEL_MPA_LINE2_WAVEOUT = 206;

        public const uint MM_MITEL_MPA_LINE2_WAVEIN = 207;

        public const uint MM_MITEL_MEDIAPATH_WAVEOUT = 300;

        public const uint MM_MITEL_MEDIAPATH_WAVEIN = 301;

        public const uint MM_SNI_ACM_G721 = 1;

        public const uint MM_EMU_APSSYNTH = 1;

        public const uint MM_EMU_APSMIDIIN = 2;

        public const uint MM_EMU_APSMIDIOUT = 3;

        public const uint MM_EMU_APSWAVEIN = 4;

        public const uint MM_EMU_APSWAVEOUT = 5;

        public const uint MM_ARTISOFT_SBWAVEIN = 1;

        public const uint MM_ARTISOFT_SBWAVEOUT = 2;

        public const uint MM_TBS_TROPEZ_WAVEIN = 37;

        public const uint MM_TBS_TROPEZ_WAVEOUT = 38;

        public const uint MM_TBS_TROPEZ_AUX1 = 39;

        public const uint MM_TBS_TROPEZ_AUX2 = 40;

        public const uint MM_TBS_TROPEZ_LINE = 41;

        public const uint MM_MMOTION_WAVEAUX = 1;

        public const uint MM_MMOTION_WAVEOUT = 2;

        public const uint MM_MMOTION_WAVEIN = 3;

        public const uint MM_IBM_PCMCIA_WAVEIN = 11;

        public const uint MM_IBM_PCMCIA_WAVEOUT = 12;

        public const uint MM_IBM_PCMCIA_SYNTH = 13;

        public const uint MM_IBM_PCMCIA_MIDIIN = 14;

        public const uint MM_IBM_PCMCIA_MIDIOUT = 15;

        public const uint MM_IBM_PCMCIA_AUX = 16;

        public const uint MM_IBM_THINKPAD200 = 17;

        public const uint MM_IBM_MWAVE_WAVEIN = 18;

        public const uint MM_IBM_MWAVE_WAVEOUT = 19;

        public const uint MM_IBM_MWAVE_MIXER = 20;

        public const uint MM_IBM_MWAVE_MIDIIN = 21;

        public const uint MM_IBM_MWAVE_MIDIOUT = 22;

        public const uint MM_IBM_MWAVE_AUX = 23;

        public const uint MM_IBM_WC_MIDIOUT = 30;

        public const uint MM_IBM_WC_WAVEOUT = 31;

        public const uint MM_IBM_WC_MIXEROUT = 33;

        public const uint MM_VOCALTEC_WAVEOUT = 1;

        public const uint MM_VOCALTEC_WAVEIN = 2;

        public const uint MM_ROLAND_RAP10_MIDIOUT = 10;

        public const uint MM_ROLAND_RAP10_MIDIIN = 11;

        public const uint MM_ROLAND_RAP10_SYNTH = 12;

        public const uint MM_ROLAND_RAP10_WAVEOUT = 13;

        public const uint MM_ROLAND_RAP10_WAVEIN = 14;

        public const uint MM_ROLAND_MPU401_MIDIOUT = 15;

        public const uint MM_ROLAND_MPU401_MIDIIN = 16;

        public const uint MM_ROLAND_SMPU_MIDIOUTA = 17;

        public const uint MM_ROLAND_SMPU_MIDIOUTB = 18;

        public const uint MM_ROLAND_SMPU_MIDIINA = 19;

        public const uint MM_ROLAND_SMPU_MIDIINB = 20;

        public const uint MM_ROLAND_SC7_MIDIOUT = 21;

        public const uint MM_ROLAND_SC7_MIDIIN = 22;

        public const uint MM_ROLAND_SERIAL_MIDIOUT = 23;

        public const uint MM_ROLAND_SERIAL_MIDIIN = 24;

        public const uint MM_ROLAND_SCP_MIDIOUT = 38;

        public const uint MM_ROLAND_SCP_MIDIIN = 39;

        public const uint MM_ROLAND_SCP_WAVEOUT = 40;

        public const uint MM_ROLAND_SCP_WAVEIN = 41;

        public const uint MM_ROLAND_SCP_MIXER = 42;

        public const uint MM_ROLAND_SCP_AUX = 48;

        public const uint MM_DSP_SOLUTIONS_WAVEOUT = 1;

        public const uint MM_DSP_SOLUTIONS_WAVEIN = 2;

        public const uint MM_DSP_SOLUTIONS_SYNTH = 3;

        public const uint MM_DSP_SOLUTIONS_AUX = 4;

        public const uint MM_NEC_73_86_SYNTH = 5;

        public const uint MM_NEC_73_86_WAVEOUT = 6;

        public const uint MM_NEC_73_86_WAVEIN = 7;

        public const uint MM_NEC_26_SYNTH = 9;

        public const uint MM_NEC_MPU401_MIDIOUT = 10;

        public const uint MM_NEC_MPU401_MIDIIN = 11;

        public const uint MM_NEC_JOYSTICK = 12;

        public const uint MM_WANGLABS_WAVEIN1 = 1;

        public const uint MM_WANGLABS_WAVEOUT1 = 2;

        public const uint MM_TANDY_VISWAVEIN = 1;

        public const uint MM_TANDY_VISWAVEOUT = 2;

        public const uint MM_TANDY_VISBIOSSYNTH = 3;

        public const uint MM_TANDY_SENS_MMAWAVEIN = 4;

        public const uint MM_TANDY_SENS_MMAWAVEOUT = 5;

        public const uint MM_TANDY_SENS_MMAMIDIIN = 6;

        public const uint MM_TANDY_SENS_MMAMIDIOUT = 7;

        public const uint MM_TANDY_SENS_VISWAVEOUT = 8;

        public const uint MM_TANDY_PSSJWAVEIN = 9;

        public const uint MM_TANDY_PSSJWAVEOUT = 10;

        public const uint MM_ANTEX_SX12_WAVEIN = 1;

        public const uint MM_ANTEX_SX12_WAVEOUT = 2;

        public const uint MM_ANTEX_SX15_WAVEIN = 3;

        public const uint MM_ANTEX_SX15_WAVEOUT = 4;

        public const uint MM_ANTEX_VP625_WAVEIN = 5;

        public const uint MM_ANTEX_VP625_WAVEOUT = 6;

        public const uint MM_ANTEX_AUDIOPORT22_WAVEIN = 7;

        public const uint MM_ANTEX_AUDIOPORT22_WAVEOUT = 8;

        public const uint MM_ANTEX_AUDIOPORT22_FEEDTHRU = 9;

        public const uint MM_INTELOPD_WAVEIN = 1;

        public const uint MM_INTELOPD_WAVEOUT = 101;

        public const uint MM_INTELOPD_AUX = 401;

        public const uint MM_INTEL_NSPMODEMLINEIN = 501;

        public const uint MM_INTEL_NSPMODEMLINEOUT = 502;

        public const uint MM_VAL_MICROKEY_AP_WAVEIN = 1;

        public const uint MM_VAL_MICROKEY_AP_WAVEOUT = 2;

        public const uint MM_INTERACTIVE_WAVEIN = 0x45;

        public const uint MM_INTERACTIVE_WAVEOUT = 0x45;

        public const uint MM_YAMAHA_GSS_SYNTH = 0x01;

        public const uint MM_YAMAHA_GSS_WAVEOUT = 0x02;

        public const uint MM_YAMAHA_GSS_WAVEIN = 0x03;

        public const uint MM_YAMAHA_GSS_MIDIOUT = 0x04;

        public const uint MM_YAMAHA_GSS_MIDIIN = 0x05;

        public const uint MM_YAMAHA_GSS_AUX = 0x06;

        public const uint MM_YAMAHA_SERIAL_MIDIOUT = 0x07;

        public const uint MM_YAMAHA_SERIAL_MIDIIN = 0x08;

        public const uint MM_YAMAHA_OPL3SA_WAVEOUT = 0x10;

        public const uint MM_YAMAHA_OPL3SA_WAVEIN = 0x11;

        public const uint MM_YAMAHA_OPL3SA_FMSYNTH = 0x12;

        public const uint MM_YAMAHA_OPL3SA_YSYNTH = 0x13;

        public const uint MM_YAMAHA_OPL3SA_MIDIOUT = 0x14;

        public const uint MM_YAMAHA_OPL3SA_MIDIIN = 0x15;

        public const uint MM_YAMAHA_OPL3SA_MIXER = 0x17;

        public const uint MM_YAMAHA_OPL3SA_JOYSTICK = 0x18;

        public const uint MM_YAMAHA_YMF724LEG_MIDIOUT = 0x19;

        public const uint MM_YAMAHA_YMF724LEG_MIDIIN = 0x1a;

        public const uint MM_YAMAHA_YMF724_WAVEOUT = 0x1b;

        public const uint MM_YAMAHA_YMF724_WAVEIN = 0x1c;

        public const uint MM_YAMAHA_YMF724_MIDIOUT = 0x1d;

        public const uint MM_YAMAHA_YMF724_AUX = 0x1e;

        public const uint MM_YAMAHA_YMF724_MIXER = 0x1f;

        public const uint MM_YAMAHA_YMF724LEG_FMSYNTH = 0x20;

        public const uint MM_YAMAHA_YMF724LEG_MIXER = 0x21;

        public const uint MM_YAMAHA_SXG_MIDIOUT = 0x22;

        public const uint MM_YAMAHA_SXG_WAVEOUT = 0x23;

        public const uint MM_YAMAHA_SXG_MIXER = 0x24;

        public const uint MM_YAMAHA_ACXG_WAVEIN = 0x25;

        public const uint MM_YAMAHA_ACXG_WAVEOUT = 0x26;

        public const uint MM_YAMAHA_ACXG_MIDIOUT = 0x27;

        public const uint MM_YAMAHA_ACXG_MIXER = 0x28;

        public const uint MM_YAMAHA_ACXG_AUX = 0x29;

        public const uint MM_EVEREX_CARRIER = 1;

        public const uint MM_ECHO_SYNTH = 1;

        public const uint MM_ECHO_WAVEOUT = 2;

        public const uint MM_ECHO_WAVEIN = 3;

        public const uint MM_ECHO_MIDIOUT = 4;

        public const uint MM_ECHO_MIDIIN = 5;

        public const uint MM_ECHO_AUX = 6;

        public const uint MM_SIERRA_ARIA_MIDIOUT = 0x14;

        public const uint MM_SIERRA_ARIA_MIDIIN = 0x15;

        public const uint MM_SIERRA_ARIA_SYNTH = 0x16;

        public const uint MM_SIERRA_ARIA_WAVEOUT = 0x17;

        public const uint MM_SIERRA_ARIA_WAVEIN = 0x18;

        public const uint MM_SIERRA_ARIA_AUX = 0x19;

        public const uint MM_SIERRA_ARIA_AUX2 = 0x20;

        public const uint MM_SIERRA_QUARTET_WAVEIN = 0x50;

        public const uint MM_SIERRA_QUARTET_WAVEOUT = 0x51;

        public const uint MM_SIERRA_QUARTET_MIDIIN = 0x52;

        public const uint MM_SIERRA_QUARTET_MIDIOUT = 0x53;

        public const uint MM_SIERRA_QUARTET_SYNTH = 0x54;

        public const uint MM_SIERRA_QUARTET_AUX_CD = 0x55;

        public const uint MM_SIERRA_QUARTET_AUX_LINE = 0x56;

        public const uint MM_SIERRA_QUARTET_AUX_MODEM = 0x57;

        public const uint MM_SIERRA_QUARTET_MIXER = 0x58;

        public const uint MM_CAT_WAVEOUT = 1;

        public const uint MM_DSP_GROUP_TRUESPEECH = 1;

        public const uint MM_MELABS_MIDI2GO = 1;

        public const uint MM_ESS_AMWAVEOUT = 0x01;

        public const uint MM_ESS_AMWAVEIN = 0x02;

        public const uint MM_ESS_AMAUX = 0x03;

        public const uint MM_ESS_AMSYNTH = 0x04;

        public const uint MM_ESS_AMMIDIOUT = 0x05;

        public const uint MM_ESS_AMMIDIIN = 0x06;

        public const uint MM_ESS_MIXER = 0x07;

        public const uint MM_ESS_AUX_CD = 0x08;

        public const uint MM_ESS_MPU401_MIDIOUT = 0x09;

        public const uint MM_ESS_MPU401_MIDIIN = 0x0A;

        public const uint MM_ESS_ES488_WAVEOUT = 0x10;

        public const uint MM_ESS_ES488_WAVEIN = 0x11;

        public const uint MM_ESS_ES488_MIXER = 0x12;

        public const uint MM_ESS_ES688_WAVEOUT = 0x13;

        public const uint MM_ESS_ES688_WAVEIN = 0x14;

        public const uint MM_ESS_ES688_MIXER = 0x15;

        public const uint MM_ESS_ES1488_WAVEOUT = 0x16;

        public const uint MM_ESS_ES1488_WAVEIN = 0x17;

        public const uint MM_ESS_ES1488_MIXER = 0x18;

        public const uint MM_ESS_ES1688_WAVEOUT = 0x19;

        public const uint MM_ESS_ES1688_WAVEIN = 0x1A;

        public const uint MM_ESS_ES1688_MIXER = 0x1B;

        public const uint MM_ESS_ES1788_WAVEOUT = 0x1C;

        public const uint MM_ESS_ES1788_WAVEIN = 0x1D;

        public const uint MM_ESS_ES1788_MIXER = 0x1E;

        public const uint MM_ESS_ES1888_WAVEOUT = 0x1F;

        public const uint MM_ESS_ES1888_WAVEIN = 0x20;

        public const uint MM_ESS_ES1888_MIXER = 0x21;

        public const uint MM_ESS_ES1868_WAVEOUT = 0x22;

        public const uint MM_ESS_ES1868_WAVEIN = 0x23;

        public const uint MM_ESS_ES1868_MIXER = 0x24;

        public const uint MM_ESS_ES1878_WAVEOUT = 0x25;

        public const uint MM_ESS_ES1878_WAVEIN = 0x26;

        public const uint MM_ESS_ES1878_MIXER = 0x27;

        public const uint MM_CANOPUS_ACM_DVREX = 1;

        public const uint MM_EPS_FMSND = 1;

        public const uint MM_TRUEVISION_WAVEIN1 = 1;

        public const uint MM_TRUEVISION_WAVEOUT1 = 2;

        public const uint MM_AZTECH_MIDIOUT = 3;

        public const uint MM_AZTECH_MIDIIN = 4;

        public const uint MM_AZTECH_WAVEIN = 17;

        public const uint MM_AZTECH_WAVEOUT = 18;

        public const uint MM_AZTECH_FMSYNTH = 20;

        public const uint MM_AZTECH_MIXER = 21;

        public const uint MM_AZTECH_PRO16_WAVEIN = 33;

        public const uint MM_AZTECH_PRO16_WAVEOUT = 34;

        public const uint MM_AZTECH_PRO16_FMSYNTH = 38;

        public const uint MM_AZTECH_DSP16_WAVEIN = 65;

        public const uint MM_AZTECH_DSP16_WAVEOUT = 66;

        public const uint MM_AZTECH_DSP16_FMSYNTH = 68;

        public const uint MM_AZTECH_DSP16_WAVESYNTH = 70;

        public const uint MM_AZTECH_NOVA16_WAVEIN = 71;

        public const uint MM_AZTECH_NOVA16_WAVEOUT = 72;

        public const uint MM_AZTECH_NOVA16_MIXER = 73;

        public const uint MM_AZTECH_WASH16_WAVEIN = 74;

        public const uint MM_AZTECH_WASH16_WAVEOUT = 75;

        public const uint MM_AZTECH_WASH16_MIXER = 76;

        public const uint MM_AZTECH_AUX_CD = 401;

        public const uint MM_AZTECH_AUX_LINE = 402;

        public const uint MM_AZTECH_AUX_MIC = 403;

        public const uint MM_AZTECH_AUX = 404;

        public const uint MM_VIDEOLOGIC_MSWAVEIN = 1;

        public const uint MM_VIDEOLOGIC_MSWAVEOUT = 2;

        public const uint MM_KORG_PCIF_MIDIOUT = 1;

        public const uint MM_KORG_PCIF_MIDIIN = 2;

        public const uint MM_KORG_1212IO_MSWAVEIN = 3;

        public const uint MM_KORG_1212IO_MSWAVEOUT = 4;

        public const uint MM_APT_ACE100CD = 1;

        public const uint MM_ICS_WAVEDECK_WAVEOUT = 1;

        public const uint MM_ICS_WAVEDECK_WAVEIN = 2;

        public const uint MM_ICS_WAVEDECK_MIXER = 3;

        public const uint MM_ICS_WAVEDECK_AUX = 4;

        public const uint MM_ICS_WAVEDECK_SYNTH = 5;

        public const uint MM_ICS_WAVEDEC_SB_WAVEOUT = 6;

        public const uint MM_ICS_WAVEDEC_SB_WAVEIN = 7;

        public const uint MM_ICS_WAVEDEC_SB_FM_MIDIOUT = 8;

        public const uint MM_ICS_WAVEDEC_SB_MPU401_MIDIOUT = 9;

        public const uint MM_ICS_WAVEDEC_SB_MPU401_MIDIIN = 10;

        public const uint MM_ICS_WAVEDEC_SB_MIXER = 11;

        public const uint MM_ICS_WAVEDEC_SB_AUX = 12;

        public const uint MM_ICS_2115_LITE_MIDIOUT = 13;

        public const uint MM_ICS_2120_LITE_MIDIOUT = 14;

        public const uint MM_ITERATEDSYS_FUFCODEC = 1;

        public const uint MM_METHEUS_ZIPPER = 1;

        public const uint MM_WINNOV_CAVIAR_WAVEIN = 1;

        public const uint MM_WINNOV_CAVIAR_WAVEOUT = 2;

        public const uint MM_WINNOV_CAVIAR_VIDC = 3;

        public const uint MM_WINNOV_CAVIAR_CHAMPAGNE = 4;

        public const uint MM_WINNOV_CAVIAR_YUV8 = 5;

        public const uint MM_NCR_BA_WAVEIN = 1;

        public const uint MM_NCR_BA_WAVEOUT = 2;

        public const uint MM_NCR_BA_SYNTH = 3;

        public const uint MM_NCR_BA_AUX = 4;

        public const uint MM_NCR_BA_MIXER = 5;

        public const uint MM_AST_MODEMWAVE_WAVEIN = 13;

        public const uint MM_AST_MODEMWAVE_WAVEOUT = 14;

        public const uint MM_WILLOWPOND_FMSYNTH_STEREO = 20;

        public const uint MM_WILLOWPOND_MPU401 = 21;

        public const uint MM_WILLOWPOND_SNDPORT_WAVEIN = 100;

        public const uint MM_WILLOWPOND_SNDPORT_WAVEOUT = 101;

        public const uint MM_WILLOWPOND_SNDPORT_MIXER = 102;

        public const uint MM_WILLOWPOND_SNDPORT_AUX = 103;

        public const uint MM_WILLOWPOND_PH_WAVEIN = 104;

        public const uint MM_WILLOWPOND_PH_WAVEOUT = 105;

        public const uint MM_WILLOWPOND_PH_MIXER = 106;

        public const uint MM_WILLOWPOND_PH_AUX = 107;

        public const uint MM_WILLOPOND_SNDCOMM_WAVEIN = 108;

        public const uint MM_WILLOWPOND_SNDCOMM_WAVEOUT = 109;

        public const uint MM_WILLOWPOND_SNDCOMM_MIXER = 110;

        public const uint MM_WILLOWPOND_SNDCOMM_AUX = 111;

        public const uint MM_WILLOWPOND_GENERIC_WAVEIN = 112;

        public const uint MM_WILLOWPOND_GENERIC_WAVEOUT = 113;

        public const uint MM_WILLOWPOND_GENERIC_MIXER = 114;

        public const uint MM_WILLOWPOND_GENERIC_AUX = 115;

        public const uint MM_VITEC_VMAKER = 1;

        public const uint MM_VITEC_VMPRO = 2;

        public const uint MM_MOSCOM_VPC2400_IN = 1;

        public const uint MM_MOSCOM_VPC2400_OUT = 2;

        public const uint MM_SILICONSOFT_SC1_WAVEIN = 1;

        public const uint MM_SILICONSOFT_SC1_WAVEOUT = 2;

        public const uint MM_SILICONSOFT_SC2_WAVEIN = 3;

        public const uint MM_SILICONSOFT_SC2_WAVEOUT = 4;

        public const uint MM_SILICONSOFT_SOUNDJR2_WAVEOUT = 5;

        public const uint MM_SILICONSOFT_SOUNDJR2PR_WAVEIN = 6;

        public const uint MM_SILICONSOFT_SOUNDJR2PR_WAVEOUT = 7;

        public const uint MM_SILICONSOFT_SOUNDJR3_WAVEOUT = 8;

        public const uint MM_TTEWS_WAVEIN = 1;

        public const uint MM_TTEWS_WAVEOUT = 2;

        public const uint MM_TTEWS_MIDIIN = 3;

        public const uint MM_TTEWS_MIDIOUT = 4;

        public const uint MM_TTEWS_MIDISYNTH = 5;

        public const uint MM_TTEWS_MIDIMONITOR = 6;

        public const uint MM_TTEWS_VMIDIIN = 7;

        public const uint MM_TTEWS_VMIDIOUT = 8;

        public const uint MM_TTEWS_AUX = 9;

        public const uint MM_TTEWS_MIXER = 10;

        public const uint MM_MEDIASONIC_ACM_G723 = 1;

        public const uint MM_MEDIASONIC_ICOM = 2;

        public const uint MM_ICOM_WAVEIN = 3;

        public const uint MM_ICOM_WAVEOUT = 4;

        public const uint MM_ICOM_MIXER = 5;

        public const uint MM_ICOM_AUX = 6;

        public const uint MM_ICOM_LINE = 7;

        public const uint MM_SANYO_ACM_LD_ADPCM = 1;

        public const uint MM_AHEAD_MULTISOUND = 1;

        public const uint MM_AHEAD_SOUNDBLASTER = 2;

        public const uint MM_AHEAD_PROAUDIO = 3;

        public const uint MM_AHEAD_GENERIC = 4;

        public const uint MM_OLIVETTI_WAVEIN = 1;

        public const uint MM_OLIVETTI_WAVEOUT = 2;

        public const uint MM_OLIVETTI_MIXER = 3;

        public const uint MM_OLIVETTI_AUX = 4;

        public const uint MM_OLIVETTI_MIDIIN = 5;

        public const uint MM_OLIVETTI_MIDIOUT = 6;

        public const uint MM_OLIVETTI_SYNTH = 7;

        public const uint MM_OLIVETTI_JOYSTICK = 8;

        public const uint MM_OLIVETTI_ACM_GSM = 9;

        public const uint MM_OLIVETTI_ACM_ADPCM = 10;

        public const uint MM_OLIVETTI_ACM_CELP = 11;

        public const uint MM_OLIVETTI_ACM_SBC = 12;

        public const uint MM_OLIVETTI_ACM_OPR = 13;

        public const uint MM_IOMAGIC_TEMPO_WAVEOUT = 1;

        public const uint MM_IOMAGIC_TEMPO_WAVEIN = 2;

        public const uint MM_IOMAGIC_TEMPO_SYNTH = 3;

        public const uint MM_IOMAGIC_TEMPO_MIDIOUT = 4;

        public const uint MM_IOMAGIC_TEMPO_MXDOUT = 5;

        public const uint MM_IOMAGIC_TEMPO_AUXOUT = 6;

        public const uint MM_MATSUSHITA_WAVEIN = 1;

        public const uint MM_MATSUSHITA_WAVEOUT = 2;

        public const uint MM_MATSUSHITA_FMSYNTH_STEREO = 3;

        public const uint MM_MATSUSHITA_MIXER = 4;

        public const uint MM_MATSUSHITA_AUX = 5;

        public const uint MM_NEWMEDIA_WAVJAMMER = 1;

        public const uint MM_LYRRUS_BRIDGE_GUITAR = 1;

        public const uint MM_OPTI_M16_FMSYNTH_STEREO = 0x0001;

        public const uint MM_OPTI_M16_MIDIIN = 0x0002;

        public const uint MM_OPTI_M16_MIDIOUT = 0x0003;

        public const uint MM_OPTI_M16_WAVEIN = 0x0004;

        public const uint MM_OPTI_M16_WAVEOUT = 0x0005;

        public const uint MM_OPTI_M16_MIXER = 0x0006;

        public const uint MM_OPTI_M16_AUX = 0x0007;

        public const uint MM_OPTI_P16_FMSYNTH_STEREO = 0x0010;

        public const uint MM_OPTI_P16_MIDIIN = 0x0011;

        public const uint MM_OPTI_P16_MIDIOUT = 0x0012;

        public const uint MM_OPTI_P16_WAVEIN = 0x0013;

        public const uint MM_OPTI_P16_WAVEOUT = 0x0014;

        public const uint MM_OPTI_P16_MIXER = 0x0015;

        public const uint MM_OPTI_P16_AUX = 0x0016;

        public const uint MM_OPTI_M32_WAVEIN = 0x0020;

        public const uint MM_OPTI_M32_WAVEOUT = 0x0021;

        public const uint MM_OPTI_M32_MIDIIN = 0x0022;

        public const uint MM_OPTI_M32_MIDIOUT = 0x0023;

        public const uint MM_OPTI_M32_SYNTH_STEREO = 0x0024;

        public const uint MM_OPTI_M32_MIXER = 0x0025;

        public const uint MM_OPTI_M32_AUX = 0x0026;

        public const uint MM_COMPAQ_BB_WAVEIN = 1;

        public const uint MM_COMPAQ_BB_WAVEOUT = 2;

        public const uint MM_COMPAQ_BB_WAVEAUX = 3;

        public const uint MM_MPTUS_SPWAVEOUT = 1;

        public const uint MM_LERNOUT_ANDHAUSPIE_LHCODECACM = 1;

        public const uint MM_DIGITAL_AV320_WAVEIN = 1;

        public const uint MM_DIGITAL_AV320_WAVEOUT = 2;

        public const uint MM_DIGITAL_ACM_G723 = 3;

        public const uint MM_DIGITAL_ICM_H263 = 4;

        public const uint MM_DIGITAL_ICM_H261 = 5;

        public const uint MM_MOTU_MTP_MIDIOUT_ALL = 100;

        public const uint MM_MOTU_MTP_MIDIIN_1 = 101;

        public const uint MM_MOTU_MTP_MIDIOUT_1 = 101;

        public const uint MM_MOTU_MTP_MIDIIN_2 = 102;

        public const uint MM_MOTU_MTP_MIDIOUT_2 = 102;

        public const uint MM_MOTU_MTP_MIDIIN_3 = 103;

        public const uint MM_MOTU_MTP_MIDIOUT_3 = 103;

        public const uint MM_MOTU_MTP_MIDIIN_4 = 104;

        public const uint MM_MOTU_MTP_MIDIOUT_4 = 104;

        public const uint MM_MOTU_MTP_MIDIIN_5 = 105;

        public const uint MM_MOTU_MTP_MIDIOUT_5 = 105;

        public const uint MM_MOTU_MTP_MIDIIN_6 = 106;

        public const uint MM_MOTU_MTP_MIDIOUT_6 = 106;

        public const uint MM_MOTU_MTP_MIDIIN_7 = 107;

        public const uint MM_MOTU_MTP_MIDIOUT_7 = 107;

        public const uint MM_MOTU_MTP_MIDIIN_8 = 108;

        public const uint MM_MOTU_MTP_MIDIOUT_8 = 108;

        public const uint MM_MOTU_MTPII_MIDIOUT_ALL = 200;

        public const uint MM_MOTU_MTPII_MIDIIN_SYNC = 200;

        public const uint MM_MOTU_MTPII_MIDIIN_1 = 201;

        public const uint MM_MOTU_MTPII_MIDIOUT_1 = 201;

        public const uint MM_MOTU_MTPII_MIDIIN_2 = 202;

        public const uint MM_MOTU_MTPII_MIDIOUT_2 = 202;

        public const uint MM_MOTU_MTPII_MIDIIN_3 = 203;

        public const uint MM_MOTU_MTPII_MIDIOUT_3 = 203;

        public const uint MM_MOTU_MTPII_MIDIIN_4 = 204;

        public const uint MM_MOTU_MTPII_MIDIOUT_4 = 204;

        public const uint MM_MOTU_MTPII_MIDIIN_5 = 205;

        public const uint MM_MOTU_MTPII_MIDIOUT_5 = 205;

        public const uint MM_MOTU_MTPII_MIDIIN_6 = 206;

        public const uint MM_MOTU_MTPII_MIDIOUT_6 = 206;

        public const uint MM_MOTU_MTPII_MIDIIN_7 = 207;

        public const uint MM_MOTU_MTPII_MIDIOUT_7 = 207;

        public const uint MM_MOTU_MTPII_MIDIIN_8 = 208;

        public const uint MM_MOTU_MTPII_MIDIOUT_8 = 208;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_1 = 209;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_1 = 209;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_2 = 210;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_2 = 210;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_3 = 211;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_3 = 211;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_4 = 212;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_4 = 212;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_5 = 213;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_5 = 213;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_6 = 214;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_6 = 214;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_7 = 215;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_7 = 215;

        public const uint MM_MOTU_MTPII_NET_MIDIIN_8 = 216;

        public const uint MM_MOTU_MTPII_NET_MIDIOUT_8 = 216;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIOUT_ALL = 300;

        public const uint MM_MOTU_MXP_MIDIIN_SYNC = 300;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIIN_1 = 301;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIOUT_1 = 301;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIIN_2 = 302;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIOUT_2 = 302;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIIN_3 = 303;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIOUT_3 = 303;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIIN_4 = 304;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIOUT_4 = 304;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIIN_5 = 305;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIOUT_5 = 305;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIIN_6 = 306;

        public const uint MM_MOTU_MXP_MIDIIN_MIDIOUT_6 = 306;

        public const uint MM_MOTU_MXPMPU_MIDIOUT_ALL = 400;

        public const uint MM_MOTU_MXPMPU_MIDIIN_SYNC = 400;

        public const uint MM_MOTU_MXPMPU_MIDIIN_1 = 401;

        public const uint MM_MOTU_MXPMPU_MIDIOUT_1 = 401;

        public const uint MM_MOTU_MXPMPU_MIDIIN_2 = 402;

        public const uint MM_MOTU_MXPMPU_MIDIOUT_2 = 402;

        public const uint MM_MOTU_MXPMPU_MIDIIN_3 = 403;

        public const uint MM_MOTU_MXPMPU_MIDIOUT_3 = 403;

        public const uint MM_MOTU_MXPMPU_MIDIIN_4 = 404;

        public const uint MM_MOTU_MXPMPU_MIDIOUT_4 = 404;

        public const uint MM_MOTU_MXPMPU_MIDIIN_5 = 405;

        public const uint MM_MOTU_MXPMPU_MIDIOUT_5 = 405;

        public const uint MM_MOTU_MXPMPU_MIDIIN_6 = 406;

        public const uint MM_MOTU_MXPMPU_MIDIOUT_6 = 406;

        public const uint MM_MOTU_MXN_MIDIOUT_ALL = 500;

        public const uint MM_MOTU_MXN_MIDIIN_SYNC = 500;

        public const uint MM_MOTU_MXN_MIDIIN_1 = 501;

        public const uint MM_MOTU_MXN_MIDIOUT_1 = 501;

        public const uint MM_MOTU_MXN_MIDIIN_2 = 502;

        public const uint MM_MOTU_MXN_MIDIOUT_2 = 502;

        public const uint MM_MOTU_MXN_MIDIIN_3 = 503;

        public const uint MM_MOTU_MXN_MIDIOUT_3 = 503;

        public const uint MM_MOTU_MXN_MIDIIN_4 = 504;

        public const uint MM_MOTU_MXN_MIDIOUT_4 = 504;

        public const uint MM_MOTU_FLYER_MIDI_IN_SYNC = 600;

        public const uint MM_MOTU_FLYER_MIDI_IN_A = 601;

        public const uint MM_MOTU_FLYER_MIDI_OUT_A = 601;

        public const uint MM_MOTU_FLYER_MIDI_IN_B = 602;

        public const uint MM_MOTU_FLYER_MIDI_OUT_B = 602;

        public const uint MM_MOTU_PKX_MIDI_IN_SYNC = 700;

        public const uint MM_MOTU_PKX_MIDI_IN_A = 701;

        public const uint MM_MOTU_PKX_MIDI_OUT_A = 701;

        public const uint MM_MOTU_PKX_MIDI_IN_B = 702;

        public const uint MM_MOTU_PKX_MIDI_OUT_B = 702;

        public const uint MM_MOTU_DTX_MIDI_IN_SYNC = 800;

        public const uint MM_MOTU_DTX_MIDI_IN_A = 801;

        public const uint MM_MOTU_DTX_MIDI_OUT_A = 801;

        public const uint MM_MOTU_DTX_MIDI_IN_B = 802;

        public const uint MM_MOTU_DTX_MIDI_OUT_B = 802;

        public const uint MM_MOTU_MTPAV_MIDIOUT_ALL = 900;

        public const uint MM_MOTU_MTPAV_MIDIIN_SYNC = 900;

        public const uint MM_MOTU_MTPAV_MIDIIN_1 = 901;

        public const uint MM_MOTU_MTPAV_MIDIOUT_1 = 901;

        public const uint MM_MOTU_MTPAV_MIDIIN_2 = 902;

        public const uint MM_MOTU_MTPAV_MIDIOUT_2 = 902;

        public const uint MM_MOTU_MTPAV_MIDIIN_3 = 903;

        public const uint MM_MOTU_MTPAV_MIDIOUT_3 = 903;

        public const uint MM_MOTU_MTPAV_MIDIIN_4 = 904;

        public const uint MM_MOTU_MTPAV_MIDIOUT_4 = 904;

        public const uint MM_MOTU_MTPAV_MIDIIN_5 = 905;

        public const uint MM_MOTU_MTPAV_MIDIOUT_5 = 905;

        public const uint MM_MOTU_MTPAV_MIDIIN_6 = 906;

        public const uint MM_MOTU_MTPAV_MIDIOUT_6 = 906;

        public const uint MM_MOTU_MTPAV_MIDIIN_7 = 907;

        public const uint MM_MOTU_MTPAV_MIDIOUT_7 = 907;

        public const uint MM_MOTU_MTPAV_MIDIIN_8 = 908;

        public const uint MM_MOTU_MTPAV_MIDIOUT_8 = 908;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_1 = 909;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_1 = 909;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_2 = 910;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_2 = 910;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_3 = 911;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_3 = 911;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_4 = 912;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_4 = 912;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_5 = 913;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_5 = 913;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_6 = 914;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_6 = 914;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_7 = 915;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_7 = 915;

        public const uint MM_MOTU_MTPAV_NET_MIDIIN_8 = 916;

        public const uint MM_MOTU_MTPAV_NET_MIDIOUT_8 = 916;

        public const uint MM_MOTU_MTPAV_MIDIIN_ADAT = 917;

        public const uint MM_MOTU_MTPAV_MIDIOUT_ADAT = 917;

        public const uint MM_MOTU_MXPXT_MIDIIN_SYNC = 1000;

        public const uint MM_MOTU_MXPXT_MIDIOUT_ALL = 1000;

        public const uint MM_MOTU_MXPXT_MIDIIN_1 = 1001;

        public const uint MM_MOTU_MXPXT_MIDIOUT_1 = 1001;

        public const uint MM_MOTU_MXPXT_MIDIOUT_2 = 1002;

        public const uint MM_MOTU_MXPXT_MIDIIN_2 = 1002;

        public const uint MM_MOTU_MXPXT_MIDIIN_3 = 1003;

        public const uint MM_MOTU_MXPXT_MIDIOUT_3 = 1003;

        public const uint MM_MOTU_MXPXT_MIDIIN_4 = 1004;

        public const uint MM_MOTU_MXPXT_MIDIOUT_4 = 1004;

        public const uint MM_MOTU_MXPXT_MIDIIN_5 = 1005;

        public const uint MM_MOTU_MXPXT_MIDIOUT_5 = 1005;

        public const uint MM_MOTU_MXPXT_MIDIOUT_6 = 1006;

        public const uint MM_MOTU_MXPXT_MIDIIN_6 = 1006;

        public const uint MM_MOTU_MXPXT_MIDIOUT_7 = 1007;

        public const uint MM_MOTU_MXPXT_MIDIIN_7 = 1007;

        public const uint MM_MOTU_MXPXT_MIDIOUT_8 = 1008;

        public const uint MM_MOTU_MXPXT_MIDIIN_8 = 1008;

        public const uint MM_WORKBIT_MIXER = 1;

        public const uint MM_WORKBIT_WAVEOUT = 2;

        public const uint MM_WORKBIT_WAVEIN = 3;

        public const uint MM_WORKBIT_MIDIIN = 4;

        public const uint MM_WORKBIT_MIDIOUT = 5;

        public const uint MM_WORKBIT_FMSYNTH = 6;

        public const uint MM_WORKBIT_AUX = 7;

        public const uint MM_WORKBIT_JOYSTICK = 8;

        public const uint MM_OSITECH_TRUMPCARD = 1;

        public const uint MM_MIRO_MOVIEPRO = 1;

        public const uint MM_MIRO_VIDEOD1 = 2;

        public const uint MM_MIRO_VIDEODC1TV = 3;

        public const uint MM_MIRO_VIDEOTD = 4;

        public const uint MM_MIRO_DC30_WAVEOUT = 5;

        public const uint MM_MIRO_DC30_WAVEIN = 6;

        public const uint MM_MIRO_DC30_MIX = 7;

        public const uint MM_ISOLUTION_PASCAL = 1;

        public const uint MM_VOICEMIXER = 1;

        public const uint ROCKWELL_WA1_WAVEIN = 100;

        public const uint ROCKWELL_WA1_WAVEOUT = 101;

        public const uint ROCKWELL_WA1_SYNTH = 102;

        public const uint ROCKWELL_WA1_MIXER = 103;

        public const uint ROCKWELL_WA1_MPU401_IN = 104;

        public const uint ROCKWELL_WA1_MPU401_OUT = 105;

        public const uint ROCKWELL_WA2_WAVEIN = 200;

        public const uint ROCKWELL_WA2_WAVEOUT = 201;

        public const uint ROCKWELL_WA2_SYNTH = 202;

        public const uint ROCKWELL_WA2_MIXER = 203;

        public const uint ROCKWELL_WA2_MPU401_IN = 204;

        public const uint ROCKWELL_WA2_MPU401_OUT = 205;

        public const uint MM_VOXWARE_CODEC = 1;

        public const uint MM_NORTEL_MPXAC_WAVEIN = 1;

        public const uint MM_NORTEL_MPXAC_WAVEOUT = 2;

        public const uint MM_ADDX_PCTV_DIGITALMIX = 1;

        public const uint MM_ADDX_PCTV_WAVEIN = 2;

        public const uint MM_ADDX_PCTV_WAVEOUT = 3;

        public const uint MM_ADDX_PCTV_MIXER = 4;

        public const uint MM_ADDX_PCTV_AUX_CD = 5;

        public const uint MM_ADDX_PCTV_AUX_LINE = 6;

        public const uint MM_WILDCAT_AUTOSCOREMIDIIN = 1;

        public const uint MM_RHETOREX_WAVEIN = 1;

        public const uint MM_RHETOREX_WAVEOUT = 2;

        public const uint MM_BTV_WAVEIN = 1;

        public const uint MM_BTV_WAVEOUT = 2;

        public const uint MM_BTV_MIDIIN = 3;

        public const uint MM_BTV_MIDIOUT = 4;

        public const uint MM_BTV_MIDISYNTH = 5;

        public const uint MM_BTV_AUX_LINE = 6;

        public const uint MM_BTV_AUX_MIC = 7;

        public const uint MM_BTV_AUX_CD = 8;

        public const uint MM_BTV_DIGITALIN = 9;

        public const uint MM_BTV_DIGITALOUT = 10;

        public const uint MM_BTV_MIDIWAVESTREAM = 11;

        public const uint MM_BTV_MIXER = 12;

        public const uint MM_ENSONIQ_SOUNDSCAPE = 0x10;

        public const uint MM_SOUNDSCAPE_WAVEOUT = MM_ENSONIQ_SOUNDSCAPE+1;

        public const uint MM_SOUNDSCAPE_WAVEOUT_AUX = MM_ENSONIQ_SOUNDSCAPE+2;

        public const uint MM_SOUNDSCAPE_WAVEIN = MM_ENSONIQ_SOUNDSCAPE+3;

        public const uint MM_SOUNDSCAPE_MIDIOUT = MM_ENSONIQ_SOUNDSCAPE+4;

        public const uint MM_SOUNDSCAPE_MIDIIN = MM_ENSONIQ_SOUNDSCAPE+5;

        public const uint MM_SOUNDSCAPE_SYNTH = MM_ENSONIQ_SOUNDSCAPE+6;

        public const uint MM_SOUNDSCAPE_MIXER = MM_ENSONIQ_SOUNDSCAPE+7;

        public const uint MM_SOUNDSCAPE_AUX = MM_ENSONIQ_SOUNDSCAPE+8;

        public const uint MM_NVIDIA_WAVEOUT = 1;

        public const uint MM_NVIDIA_WAVEIN = 2;

        public const uint MM_NVIDIA_MIDIOUT = 3;

        public const uint MM_NVIDIA_MIDIIN = 4;

        public const uint MM_NVIDIA_GAMEPORT = 5;

        public const uint MM_NVIDIA_MIXER = 6;

        public const uint MM_NVIDIA_AUX = 7;

        public const uint MM_OKSORI_BASE = 0;

        public const uint MM_OKSORI_OSR8_WAVEOUT = MM_OKSORI_BASE+1;

        public const uint MM_OKSORI_OSR8_WAVEIN = MM_OKSORI_BASE+2;

        public const uint MM_OKSORI_OSR16_WAVEOUT = MM_OKSORI_BASE+3;

        public const uint MM_OKSORI_OSR16_WAVEIN = MM_OKSORI_BASE+4;

        public const uint MM_OKSORI_FM_OPL4 = MM_OKSORI_BASE+5;

        public const uint MM_OKSORI_MIX_MASTER = MM_OKSORI_BASE+6;

        public const uint MM_OKSORI_MIX_WAVE = MM_OKSORI_BASE+7;

        public const uint MM_OKSORI_MIX_FM = MM_OKSORI_BASE+8;

        public const uint MM_OKSORI_MIX_LINE = MM_OKSORI_BASE+9;

        public const uint MM_OKSORI_MIX_CD = MM_OKSORI_BASE+10;

        public const uint MM_OKSORI_MIX_MIC = MM_OKSORI_BASE+11;

        public const uint MM_OKSORI_MIX_ECHO = MM_OKSORI_BASE+12;

        public const uint MM_OKSORI_MIX_AUX1 = MM_OKSORI_BASE+13;

        public const uint MM_OKSORI_MIX_LINE1 = MM_OKSORI_BASE+14;

        public const uint MM_OKSORI_EXT_MIC1 = MM_OKSORI_BASE+15;

        public const uint MM_OKSORI_EXT_MIC2 = MM_OKSORI_BASE+16;

        public const uint MM_OKSORI_MIDIOUT = MM_OKSORI_BASE+17;

        public const uint MM_OKSORI_MIDIIN = MM_OKSORI_BASE+18;

        public const uint MM_OKSORI_MPEG_CDVISION = MM_OKSORI_BASE+19;

        public const uint MM_DIACOUSTICS_DRUM_ACTION = 1;

        public const uint MM_KAY_ELEMETRICS_CSL = 0x4300;

        public const uint MM_KAY_ELEMETRICS_CSL_DAT = 0x4308;

        public const uint MM_KAY_ELEMETRICS_CSL_4CHANNEL = 0x4309;

        public const uint MM_CRYSTAL_CS4232_WAVEIN = 1;

        public const uint MM_CRYSTAL_CS4232_WAVEOUT = 2;

        public const uint MM_CRYSTAL_CS4232_WAVEMIXER = 3;

        public const uint MM_CRYSTAL_CS4232_WAVEAUX_AUX1 = 4;

        public const uint MM_CRYSTAL_CS4232_WAVEAUX_AUX2 = 5;

        public const uint MM_CRYSTAL_CS4232_WAVEAUX_LINE = 6;

        public const uint MM_CRYSTAL_CS4232_WAVEAUX_MONO = 7;

        public const uint MM_CRYSTAL_CS4232_WAVEAUX_MASTER = 8;

        public const uint MM_CRYSTAL_CS4232_MIDIIN = 9;

        public const uint MM_CRYSTAL_CS4232_MIDIOUT = 10;

        public const uint MM_CRYSTAL_CS4232_INPUTGAIN_AUX1 = 13;

        public const uint MM_CRYSTAL_CS4232_INPUTGAIN_LOOP = 14;

        public const uint MM_CRYSTAL_SOUND_FUSION_WAVEIN = 21;

        public const uint MM_CRYSTAL_SOUND_FUSION_WAVEOUT = 22;

        public const uint MM_CRYSTAL_SOUND_FUSION_MIXER = 23;

        public const uint MM_CRYSTAL_SOUND_FUSION_MIDIIN = 24;

        public const uint MM_CRYSTAL_SOUND_FUSION_MIDIOUT = 25;

        public const uint MM_CRYSTAL_SOUND_FUSION_JOYSTICK = 26;

        public const uint MM_QUARTERDECK_LHWAVEIN = 0;

        public const uint MM_QUARTERDECK_LHWAVEOUT = 1;

        public const uint MM_TDK_MW_MIDI_SYNTH = 1;

        public const uint MM_TDK_MW_MIDI_IN = 2;

        public const uint MM_TDK_MW_MIDI_OUT = 3;

        public const uint MM_TDK_MW_WAVE_IN = 4;

        public const uint MM_TDK_MW_WAVE_OUT = 5;

        public const uint MM_TDK_MW_AUX = 6;

        public const uint MM_TDK_MW_MIXER = 10;

        public const uint MM_TDK_MW_AUX_MASTER = 100;

        public const uint MM_TDK_MW_AUX_BASS = 101;

        public const uint MM_TDK_MW_AUX_TREBLE = 102;

        public const uint MM_TDK_MW_AUX_MIDI_VOL = 103;

        public const uint MM_TDK_MW_AUX_WAVE_VOL = 104;

        public const uint MM_TDK_MW_AUX_WAVE_RVB = 105;

        public const uint MM_TDK_MW_AUX_WAVE_CHR = 106;

        public const uint MM_TDK_MW_AUX_VOL = 107;

        public const uint MM_TDK_MW_AUX_RVB = 108;

        public const uint MM_TDK_MW_AUX_CHR = 109;

        public const uint MM_DIGITAL_AUDIO_LABS_TC = 0x01;

        public const uint MM_DIGITAL_AUDIO_LABS_DOC = 0x02;

        public const uint MM_DIGITAL_AUDIO_LABS_V8 = 0x10;

        public const uint MM_DIGITAL_AUDIO_LABS_CPRO = 0x11;

        public const uint MM_DIGITAL_AUDIO_LABS_VP = 0x12;

        public const uint MM_DIGITAL_AUDIO_LABS_CDLX = 0x13;

        public const uint MM_DIGITAL_AUDIO_LABS_CTDIF = 0x14;

        public const uint MM_SEERSYS_SEERSYNTH = 1;

        public const uint MM_SEERSYS_SEERWAVE = 2;

        public const uint MM_SEERSYS_SEERMIX = 3;

        public const uint MM_SEERSYS_WAVESYNTH = 4;

        public const uint MM_SEERSYS_WAVESYNTH_WG = 5;

        public const uint MM_SEERSYS_REALITY = 6;

        public const uint MM_OSPREY_1000WAVEIN = 1;

        public const uint MM_OSPREY_1000WAVEOUT = 2;

        public const uint MM_SOUNDESIGNS_WAVEIN = 1;

        public const uint MM_SOUNDESIGNS_WAVEOUT = 2;

        public const uint MM_SSP_SNDFESWAVEIN = 1;

        public const uint MM_SSP_SNDFESWAVEOUT = 2;

        public const uint MM_SSP_SNDFESMIDIIN = 3;

        public const uint MM_SSP_SNDFESMIDIOUT = 4;

        public const uint MM_SSP_SNDFESSYNTH = 5;

        public const uint MM_SSP_SNDFESMIX = 6;

        public const uint MM_SSP_SNDFESAUX = 7;

        public const uint MM_ECS_AADF_MIDI_IN = 10;

        public const uint MM_ECS_AADF_MIDI_OUT = 11;

        public const uint MM_ECS_AADF_WAVE2MIDI_IN = 12;

        public const uint MM_AMD_INTERWAVE_WAVEIN = 1;

        public const uint MM_AMD_INTERWAVE_WAVEOUT = 2;

        public const uint MM_AMD_INTERWAVE_SYNTH = 3;

        public const uint MM_AMD_INTERWAVE_MIXER1 = 4;

        public const uint MM_AMD_INTERWAVE_MIXER2 = 5;

        public const uint MM_AMD_INTERWAVE_JOYSTICK = 6;

        public const uint MM_AMD_INTERWAVE_EX_CD = 7;

        public const uint MM_AMD_INTERWAVE_MIDIIN = 8;

        public const uint MM_AMD_INTERWAVE_MIDIOUT = 9;

        public const uint MM_AMD_INTERWAVE_AUX1 = 10;

        public const uint MM_AMD_INTERWAVE_AUX2 = 11;

        public const uint MM_AMD_INTERWAVE_AUX_MIC = 12;

        public const uint MM_AMD_INTERWAVE_AUX_CD = 13;

        public const uint MM_AMD_INTERWAVE_MONO_IN = 14;

        public const uint MM_AMD_INTERWAVE_MONO_OUT = 15;

        public const uint MM_AMD_INTERWAVE_EX_TELEPHONY = 16;

        public const uint MM_AMD_INTERWAVE_WAVEOUT_BASE = 17;

        public const uint MM_AMD_INTERWAVE_WAVEOUT_TREBLE = 18;

        public const uint MM_AMD_INTERWAVE_STEREO_ENHANCED = 19;

        public const uint MM_COREDYNAMICS_DYNAMIXHR = 1;

        public const uint MM_COREDYNAMICS_DYNASONIX_SYNTH = 2;

        public const uint MM_COREDYNAMICS_DYNASONIX_MIDI_IN = 3;

        public const uint MM_COREDYNAMICS_DYNASONIX_MIDI_OUT = 4;

        public const uint MM_COREDYNAMICS_DYNASONIX_WAVE_IN = 5;

        public const uint MM_COREDYNAMICS_DYNASONIX_WAVE_OUT = 6;

        public const uint MM_COREDYNAMICS_DYNASONIX_AUDIO_IN = 7;

        public const uint MM_COREDYNAMICS_DYNASONIX_AUDIO_OUT = 8;

        public const uint MM_COREDYNAMICS_DYNAGRAFX_VGA = 9;

        public const uint MM_COREDYNAMICS_DYNAGRAFX_WAVE_IN = 10;

        public const uint MM_COREDYNAMICS_DYNAGRAFX_WAVE_OUT = 11;

        public const uint MM_CANAM_CBXWAVEOUT = 1;

        public const uint MM_CANAM_CBXWAVEIN = 2;

        public const uint MM_SOFTSOUND_CODEC = 1;

        public const uint MM_NORRIS_VOICELINK = 1;

        public const uint MM_DDD_MIDILINK_MIDIIN = 1;

        public const uint MM_DDD_MIDILINK_MIDIOUT = 2;

        public const uint MM_EUPHONICS_AUX_CD = 1;

        public const uint MM_EUPHONICS_AUX_LINE = 2;

        public const uint MM_EUPHONICS_AUX_MASTER = 3;

        public const uint MM_EUPHONICS_AUX_MIC = 4;

        public const uint MM_EUPHONICS_AUX_MIDI = 5;

        public const uint MM_EUPHONICS_AUX_WAVE = 6;

        public const uint MM_EUPHONICS_FMSYNTH_MONO = 7;

        public const uint MM_EUPHONICS_FMSYNTH_STEREO = 8;

        public const uint MM_EUPHONICS_MIDIIN = 9;

        public const uint MM_EUPHONICS_MIDIOUT = 10;

        public const uint MM_EUPHONICS_MIXER = 11;

        public const uint MM_EUPHONICS_WAVEIN = 12;

        public const uint MM_EUPHONICS_WAVEOUT = 13;

        public const uint MM_EUPHONICS_EUSYNTH = 14;

        public const uint CRYSTAL_NET_SFM_CODEC = 1;

        public const uint MM_CHROMATIC_M1 = 0x0001;

        public const uint MM_CHROMATIC_M1_WAVEIN = 0x0002;

        public const uint MM_CHROMATIC_M1_WAVEOUT = 0x0003;

        public const uint MM_CHROMATIC_M1_FMSYNTH = 0x0004;

        public const uint MM_CHROMATIC_M1_MIXER = 0x0005;

        public const uint MM_CHROMATIC_M1_AUX = 0x0006;

        public const uint MM_CHROMATIC_M1_AUX_CD = 0x0007;

        public const uint MM_CHROMATIC_M1_MIDIIN = 0x0008;

        public const uint MM_CHROMATIC_M1_MIDIOUT = 0x0009;

        public const uint MM_CHROMATIC_M1_WTSYNTH = 0x0010;

        public const uint MM_CHROMATIC_M1_MPEGWAVEIN = 0x0011;

        public const uint MM_CHROMATIC_M1_MPEGWAVEOUT = 0x0012;

        public const uint MM_CHROMATIC_M2 = 0x0013;

        public const uint MM_CHROMATIC_M2_WAVEIN = 0x0014;

        public const uint MM_CHROMATIC_M2_WAVEOUT = 0x0015;

        public const uint MM_CHROMATIC_M2_FMSYNTH = 0x0016;

        public const uint MM_CHROMATIC_M2_MIXER = 0x0017;

        public const uint MM_CHROMATIC_M2_AUX = 0x0018;

        public const uint MM_CHROMATIC_M2_AUX_CD = 0x0019;

        public const uint MM_CHROMATIC_M2_MIDIIN = 0x0020;

        public const uint MM_CHROMATIC_M2_MIDIOUT = 0x0021;

        public const uint MM_CHROMATIC_M2_WTSYNTH = 0x0022;

        public const uint MM_CHROMATIC_M2_MPEGWAVEIN = 0x0023;

        public const uint MM_CHROMATIC_M2_MPEGWAVEOUT = 0x0024;

        public const uint MM_VIENNASYS_TSP_WAVE_DRIVER = 1;

        public const uint MM_CONNECTIX_VIDEC_CODEC = 1;

        public const uint MM_GADGETLABS_WAVE44_WAVEIN = 1;

        public const uint MM_GADGETLABS_WAVE44_WAVEOUT = 2;

        public const uint MM_GADGETLABS_WAVE42_WAVEIN = 3;

        public const uint MM_GADGETLABS_WAVE42_WAVEOUT = 4;

        public const uint MM_GADGETLABS_WAVE4_MIDIIN = 5;

        public const uint MM_GADGETLABS_WAVE4_MIDIOUT = 6;

        public const uint MM_FRONTIER_WAVECENTER_MIDIIN = 1;

        public const uint MM_FRONTIER_WAVECENTER_MIDIOUT = 2;

        public const uint MM_FRONTIER_WAVECENTER_WAVEIN = 3;

        public const uint MM_FRONTIER_WAVECENTER_WAVEOUT = 4;

        public const uint MM_VIONA_QVINPCI_MIXER = 1;

        public const uint MM_VIONA_QVINPCI_WAVEIN = 2;

        public const uint MM_VIONAQVINPCI_WAVEOUT = 3;

        public const uint MM_VIONA_BUSTER_MIXER = 4;

        public const uint MM_VIONA_CINEMASTER_MIXER = 5;

        public const uint MM_VIONA_CONCERTO_MIXER = 6;

        public const uint MM_CASIO_WP150_MIDIOUT = 1;

        public const uint MM_CASIO_WP150_MIDIIN = 2;

        public const uint MM_CASIO_LSG_MIDIOUT = 3;

        public const uint MM_DIMD_PLATFORM = 0;

        public const uint MM_DIMD_DIRSOUND = 1;

        public const uint MM_DIMD_VIRTMPU = 2;

        public const uint MM_DIMD_VIRTSB = 3;

        public const uint MM_DIMD_VIRTJOY = 4;

        public const uint MM_DIMD_WAVEIN = 5;

        public const uint MM_DIMD_WAVEOUT = 6;

        public const uint MM_DIMD_MIDIIN = 7;

        public const uint MM_DIMD_MIDIOUT = 8;

        public const uint MM_DIMD_AUX_LINE = 9;

        public const uint MM_DIMD_MIXER = 10;

        public const uint MM_DIMD_WSS_WAVEIN = 14;

        public const uint MM_DIMD_WSS_WAVEOUT = 15;

        public const uint MM_DIMD_WSS_MIXER = 17;

        public const uint MM_DIMD_WSS_AUX = 21;

        public const uint MM_DIMD_WSS_SYNTH = 76;

        public const uint MM_S3_WAVEOUT = 1;

        public const uint MM_S3_WAVEIN = 2;

        public const uint MM_S3_MIDIOUT = 3;

        public const uint MM_S3_MIDIIN = 4;

        public const uint MM_S3_FMSYNTH = 5;

        public const uint MM_S3_MIXER = 6;

        public const uint MM_S3_AUX = 7;

        public const uint MM_VKC_MPU401_MIDIIN = 0x0100;

        public const uint MM_VKC_SERIAL_MIDIIN = 0x0101;

        public const uint MM_VKC_MPU401_MIDIOUT = 0x0200;

        public const uint MM_VKC_SERIAL_MIDIOUT = 0x0201;

        public const uint MM_ZEFIRO_ZA2 = 2;

        public const uint MM_FHGIIS_MPEGLAYER3_DECODE = 9;

        public const uint MM_FHGIIS_MPEGLAYER3 = 10;

        public const uint MM_FHGIIS_MPEGLAYER3_LITE = 10;

        public const uint MM_FHGIIS_MPEGLAYER3_BASIC = 11;

        public const uint MM_FHGIIS_MPEGLAYER3_ADVANCED = 12;

        public const uint MM_FHGIIS_MPEGLAYER3_PROFESSIONAL = 13;

        public const uint MM_FHGIIS_MPEGLAYER3_ADVANCEDPLUS = 14;

        public const uint MM_QUICKNET_PJWAVEIN = 1;

        public const uint MM_QUICKNET_PJWAVEOUT = 2;

        public const uint MM_SICRESOURCE_SSO3D = 2;

        public const uint MM_SICRESOURCE_SSOW3DI = 3;

        public const uint MM_NEOMAGIC_SYNTH = 1;

        public const uint MM_NEOMAGIC_WAVEOUT = 2;

        public const uint MM_NEOMAGIC_WAVEIN = 3;

        public const uint MM_NEOMAGIC_MIDIOUT = 4;

        public const uint MM_NEOMAGIC_MIDIIN = 5;

        public const uint MM_NEOMAGIC_AUX = 6;

        public const uint MM_NEOMAGIC_MW3DX_WAVEOUT = 10;

        public const uint MM_NEOMAGIC_MW3DX_WAVEIN = 11;

        public const uint MM_NEOMAGIC_MW3DX_MIDIOUT = 12;

        public const uint MM_NEOMAGIC_MW3DX_MIDIIN = 13;

        public const uint MM_NEOMAGIC_MW3DX_FMSYNTH = 14;

        public const uint MM_NEOMAGIC_MW3DX_GMSYNTH = 15;

        public const uint MM_NEOMAGIC_MW3DX_MIXER = 16;

        public const uint MM_NEOMAGIC_MW3DX_AUX = 17;

        public const uint MM_NEOMAGIC_MWAVE_WAVEOUT = 20;

        public const uint MM_NEOMAGIC_MWAVE_WAVEIN = 21;

        public const uint MM_NEOMAGIC_MWAVE_MIDIOUT = 22;

        public const uint MM_NEOMAGIC_MWAVE_MIDIIN = 23;

        public const uint MM_NEOMAGIC_MWAVE_MIXER = 24;

        public const uint MM_NEOMAGIC_MWAVE_AUX = 25;

        public const uint MM_MERGING_MPEGL3 = 1;

        public const uint MM_XIRLINK_VISIONLINK = 1;

        public const uint MM_OTI_611WAVEIN = 5;

        public const uint MM_OTI_611WAVEOUT = 6;

        public const uint MM_OTI_611MIXER = 7;

        public const uint MM_OTI_611MIDIN = 0x12;

        public const uint MM_OTI_611MIDIOUT = 0x13;

        public const uint MM_AUREAL_AU8820 = 16;

        public const uint MM_AU8820_SYNTH = 17;

        public const uint MM_AU8820_WAVEOUT = 18;

        public const uint MM_AU8820_WAVEIN = 19;

        public const uint MM_AU8820_MIXER = 20;

        public const uint MM_AU8820_AUX = 21;

        public const uint MM_AU8820_MIDIOUT = 22;

        public const uint MM_AU8820_MIDIIN = 23;

        public const uint MM_AUREAL_AU8830 = 32;

        public const uint MM_AU8830_SYNTH = 33;

        public const uint MM_AU8830_WAVEOUT = 34;

        public const uint MM_AU8830_WAVEIN = 35;

        public const uint MM_AU8830_MIXER = 36;

        public const uint MM_AU8830_AUX = 37;

        public const uint MM_AU8830_MIDIOUT = 38;

        public const uint MM_AU8830_MIDIIN = 39;

        public const uint MM_VIVO_AUDIO_CODEC = 1;

        public const uint MM_SHARP_MDC_MIDI_SYNTH = 1;

        public const uint MM_SHARP_MDC_MIDI_IN = 2;

        public const uint MM_SHARP_MDC_MIDI_OUT = 3;

        public const uint MM_SHARP_MDC_WAVE_IN = 4;

        public const uint MM_SHARP_MDC_WAVE_OUT = 5;

        public const uint MM_SHARP_MDC_AUX = 6;

        public const uint MM_SHARP_MDC_MIXER = 10;

        public const uint MM_SHARP_MDC_AUX_MASTER = 100;

        public const uint MM_SHARP_MDC_AUX_BASS = 101;

        public const uint MM_SHARP_MDC_AUX_TREBLE = 102;

        public const uint MM_SHARP_MDC_AUX_MIDI_VOL = 103;

        public const uint MM_SHARP_MDC_AUX_WAVE_VOL = 104;

        public const uint MM_SHARP_MDC_AUX_WAVE_RVB = 105;

        public const uint MM_SHARP_MDC_AUX_WAVE_CHR = 106;

        public const uint MM_SHARP_MDC_AUX_VOL = 107;

        public const uint MM_SHARP_MDC_AUX_RVB = 108;

        public const uint MM_SHARP_MDC_AUX_CHR = 109;

        public const uint MM_LUCENT_ACM_G723 = 0;

        public const uint MM_ATT_G729A = 1;

        public const uint MM_MARIAN_ARC44WAVEIN = 1;

        public const uint MM_MARIAN_ARC44WAVEOUT = 2;

        public const uint MM_MARIAN_PRODIF24WAVEIN = 3;

        public const uint MM_MARIAN_PRODIF24WAVEOUT = 4;

        public const uint MM_MARIAN_ARC88WAVEIN = 5;

        public const uint MM_MARIAN_ARC88WAVEOUT = 6;

        public const uint MM_BCB_NETBOARD_10 = 1;

        public const uint MM_BCB_TT75_10 = 2;

        public const uint MM_MOTIONPIXELS_MVI2 = 1;

        public const uint MM_QDESIGN_ACM_MPEG = 1;

        public const uint MM_QDESIGN_ACM_QDESIGN_MUSIC = 2;

        public const uint MM_NMP_CCP_WAVEIN = 1;

        public const uint MM_NMP_CCP_WAVEOUT = 2;

        public const uint MM_NMP_ACM_AMR = 10;

        public const uint MM_DF_ACM_G726 = 1;

        public const uint MM_DF_ACM_GSM610 = 2;

        public const uint MM_BERCOS_WAVEIN = 1;

        public const uint MM_BERCOS_MIXER = 2;

        public const uint MM_BERCOS_WAVEOUT = 3;

        public const uint MM_ONLIVE_MPCODEC = 1;

        public const uint MM_PHONET_PP_WAVEOUT = 1;

        public const uint MM_PHONET_PP_WAVEIN = 2;

        public const uint MM_PHONET_PP_MIXER = 3;

        public const uint MM_FTR_ENCODER_WAVEIN = 1;

        public const uint MM_FTR_ACM = 2;

        public const uint MM_ENET_T2000_LINEIN = 1;

        public const uint MM_ENET_T2000_LINEOUT = 2;

        public const uint MM_ENET_T2000_HANDSETIN = 3;

        public const uint MM_ENET_T2000_HANDSETOUT = 4;

        public const uint MM_EMAGIC_UNITOR8 = 1;

        public const uint MM_SIPROLAB_ACELPNET = 1;

        public const uint MM_DICTAPHONE_G726 = 1;

        public const uint MM_RZS_ACM_TUBGSM = 1;

        public const uint MM_EES_PCMIDI14 = 1;

        public const uint MM_EES_PCMIDI14_IN = 2;

        public const uint MM_EES_PCMIDI14_OUT1 = 3;

        public const uint MM_EES_PCMIDI14_OUT2 = 4;

        public const uint MM_EES_PCMIDI14_OUT3 = 5;

        public const uint MM_EES_PCMIDI14_OUT4 = 6;

        public const uint MM_HAFTMANN_LPTDAC2 = 1;

        public const uint MM_LUCID_PCI24WAVEIN = 1;

        public const uint MM_LUCID_PCI24WAVEOUT = 2;

        public const uint MM_HEADSPACE_HAESYNTH = 1;

        public const uint MM_HEADSPACE_HAEWAVEOUT = 2;

        public const uint MM_HEADSPACE_HAEWAVEIN = 3;

        public const uint MM_HEADSPACE_HAEMIXER = 4;

        public const uint MM_UNISYS_ACM_NAP = 1;

        public const uint MM_LUMINOSITI_SCWAVEIN = 1;

        public const uint MM_LUMINOSITI_SCWAVEOUT = 2;

        public const uint MM_LUMINOSITI_SCWAVEMIX = 3;

        public const uint MM_ACTIVEVOICE_ACM_VOXADPCM = 1;

        public const uint MM_DTS_DS = 1;

        public const uint MM_SOFTLAB_NSK_FRW_WAVEIN = 1;

        public const uint MM_SOFTLAB_NSK_FRW_WAVEOUT = 2;

        public const uint MM_SOFTLAB_NSK_FRW_MIXER = 3;

        public const uint MM_SOFTLAB_NSK_FRW_AUX = 4;

        public const uint MM_FORTEMEDIA_WAVEIN = 1;

        public const uint MM_FORTEMEDIA_WAVEOUT = 2;

        public const uint MM_FORTEMEDIA_FMSYNC = 3;

        public const uint MM_FORTEMEDIA_MIXER = 4;

        public const uint MM_FORTEMEDIA_AUX = 5;

        public const uint MM_SONORUS_STUDIO = 1;

        public const uint MM_I_LINK_VOICE_CODER = 1;

        public const uint MM_SELSIUS_SYSTEMS_RTPWAVEOUT = 1;

        public const uint MM_SELSIUS_SYSTEMS_RTPWAVEIN = 2;

        public const uint MM_ADMOS_FM_SYNTH = 1;

        public const uint MM_ADMOS_QS3AMIDIOUT = 2;

        public const uint MM_ADMOS_QS3AMIDIIN = 3;

        public const uint MM_ADMOS_QS3AWAVEOUT = 4;

        public const uint MM_ADMOS_QS3AWAVEIN = 5;

        public const uint MM_LEXICON_STUDIO_WAVE_OUT = 1;

        public const uint MM_LEXICON_STUDIO_WAVE_IN = 2;

        public const uint MM_SGI_320_WAVEIN = 1;

        public const uint MM_SGI_320_WAVEOUT = 2;

        public const uint MM_SGI_320_MIXER = 3;

        public const uint MM_SGI_540_WAVEIN = 4;

        public const uint MM_SGI_540_WAVEOUT = 5;

        public const uint MM_SGI_540_MIXER = 6;

        public const uint MM_SGI_RAD_ADATMONO1_WAVEIN = 7;

        public const uint MM_SGI_RAD_ADATMONO2_WAVEIN = 8;

        public const uint MM_SGI_RAD_ADATMONO3_WAVEIN = 9;

        public const uint MM_SGI_RAD_ADATMONO4_WAVEIN = 10;

        public const uint MM_SGI_RAD_ADATMONO5_WAVEIN = 11;

        public const uint MM_SGI_RAD_ADATMONO6_WAVEIN = 12;

        public const uint MM_SGI_RAD_ADATMONO7_WAVEIN = 13;

        public const uint MM_SGI_RAD_ADATMONO8_WAVEIN = 14;

        public const uint MM_SGI_RAD_ADATSTEREO12_WAVEIN = 15;

        public const uint MM_SGI_RAD_ADATSTEREO34_WAVEIN = 16;

        public const uint MM_SGI_RAD_ADATSTEREO56_WAVEIN = 17;

        public const uint MM_SGI_RAD_ADATSTEREO78_WAVEIN = 18;

        public const uint MM_SGI_RAD_ADAT8CHAN_WAVEIN = 19;

        public const uint MM_SGI_RAD_ADATMONO1_WAVEOUT = 20;

        public const uint MM_SGI_RAD_ADATMONO2_WAVEOUT = 21;

        public const uint MM_SGI_RAD_ADATMONO3_WAVEOUT = 22;

        public const uint MM_SGI_RAD_ADATMONO4_WAVEOUT = 23;

        public const uint MM_SGI_RAD_ADATMONO5_WAVEOUT = 24;

        public const uint MM_SGI_RAD_ADATMONO6_WAVEOUT = 25;

        public const uint MM_SGI_RAD_ADATMONO7_WAVEOUT = 26;

        public const uint MM_SGI_RAD_ADATMONO8_WAVEOUT = 27;

        public const uint MM_SGI_RAD_ADATSTEREO12_WAVEOUT = 28;

        public const uint MM_SGI_RAD_ADATSTEREO32_WAVEOUT = 29;

        public const uint MM_SGI_RAD_ADATSTEREO56_WAVEOUT = 30;

        public const uint MM_SGI_RAD_ADATSTEREO78_WAVEOUT = 31;

        public const uint MM_SGI_RAD_ADAT8CHAN_WAVEOUT = 32;

        public const uint MM_SGI_RAD_AESMONO1_WAVEIN = 33;

        public const uint MM_SGI_RAD_AESMONO2_WAVEIN = 34;

        public const uint MM_SGI_RAD_AESSTEREO_WAVEIN = 35;

        public const uint MM_SGI_RAD_AESMONO1_WAVEOUT = 36;

        public const uint MM_SGI_RAD_AESMONO2_WAVEOUT = 37;

        public const uint MM_SGI_RAD_AESSTEREO_WAVEOUT = 38;

        public const uint MM_IPI_ACM_HSX = 1;

        public const uint MM_IPI_ACM_RPELP = 2;

        public const uint MM_IPI_WF_ASSS = 3;

        public const uint MM_IPI_AT_WAVEOUT = 4;

        public const uint MM_IPI_AT_WAVEIN = 5;

        public const uint MM_IPI_AT_MIXER = 6;

        public const uint MM_ICE_WAVEOUT = 1;

        public const uint MM_ICE_WAVEIN = 2;

        public const uint MM_ICE_MTWAVEOUT = 3;

        public const uint MM_ICE_MTWAVEIN = 4;

        public const uint MM_ICE_MIDIOUT1 = 5;

        public const uint MM_ICE_MIDIIN1 = 6;

        public const uint MM_ICE_MIDIOUT2 = 7;

        public const uint MM_ICE_MIDIIN2 = 8;

        public const uint MM_ICE_SYNTH = 9;

        public const uint MM_ICE_MIXER = 10;

        public const uint MM_ICE_AUX = 11;

        public const uint MM_VQST_VQC1 = 1;

        public const uint MM_VQST_VQC2 = 2;

        public const uint MM_ETEK_KWIKMIDI_MIDIIN = 1;

        public const uint MM_ETEK_KWIKMIDI_MIDIOUT = 2;

        public const uint MM_INTERNET_SSW_MIDIOUT = 10;

        public const uint MM_INTERNET_SSW_MIDIIN = 11;

        public const uint MM_INTERNET_SSW_WAVEOUT = 12;

        public const uint MM_INTERNET_SSW_WAVEIN = 13;

        public const uint MM_SONY_ACM_SCX = 1;

        public const uint MM_UH_ACM_ADPCM = 1;

        public const uint MM_SYDEC_NV_WAVEIN = 1;

        public const uint MM_SYDEC_NV_WAVEOUT = 2;

        public const uint MM_FLEXION_X300_WAVEIN = 1;

        public const uint MM_FLEXION_X300_WAVEOUT = 2;

        public const uint MM_VIA_WAVEOUT = 1;

        public const uint MM_VIA_WAVEIN = 2;

        public const uint MM_VIA_MIXER = 3;

        public const uint MM_VIA_AUX = 4;

        public const uint MM_VIA_MPU401_MIDIOUT = 5;

        public const uint MM_VIA_MPU401_MIDIIN = 6;

        public const uint MM_VIA_SWFM_SYNTH = 7;

        public const uint MM_VIA_WDM_WAVEOUT = 8;

        public const uint MM_VIA_WDM_WAVEIN = 9;

        public const uint MM_VIA_WDM_MIXER = 10;

        public const uint MM_VIA_WDM_MPU401_MIDIOUT = 11;

        public const uint MM_VIA_WDM_MPU401_MIDIIN = 12;

        public const uint MM_MICRONAS_SC4 = 1;

        public const uint MM_MICRONAS_CLP833 = 2;

        public const uint MM_HP_WAVEOUT = 1;

        public const uint MM_HP_WAVEIN = 2;

        public const uint MM_QUICKAUDIO_MINIMIDI = 1;

        public const uint MM_QUICKAUDIO_MAXIMIDI = 2;

        public const uint MM_ICCC_UNA3_WAVEIN = 1;

        public const uint MM_ICCC_UNA3_WAVEOUT = 2;

        public const uint MM_ICCC_UNA3_AUX = 3;

        public const uint MM_ICCC_UNA3_MIXER = 4;

        public const uint MM_3COM_CB_MIXER = 1;

        public const uint MM_3COM_CB_WAVEIN = 2;

        public const uint MM_3COM_CB_WAVEOUT = 3;

        public const uint MM_MINDMAKER_GC_WAVEIN = 1;

        public const uint MM_MINDMAKER_GC_WAVEOUT = 2;

        public const uint MM_MINDMAKER_GC_MIXER = 3;

        public const uint MM_TELEKOL_WAVEOUT = 1;

        public const uint MM_TELEKOL_WAVEIN = 2;

        public const uint MM_ALGOVISION_VB80WAVEOUT = 1;

        public const uint MM_ALGOVISION_VB80WAVEIN = 2;

        public const uint MM_ALGOVISION_VB80MIXER = 3;

        public const uint MM_ALGOVISION_VB80AUX = 4;

        public const uint MM_ALGOVISION_VB80AUX2 = 5;

        public const uint WAVE_FORMAT_UNKNOWN = 0x0000;

        public const uint WAVE_FORMAT_ADPCM = 0x0002;

        public const uint WAVE_FORMAT_IEEE_FLOAT = 0x0003;

        public const uint WAVE_FORMAT_VSELP = 0x0004;

        public const uint WAVE_FORMAT_IBM_CVSD = 0x0005;

        public const uint WAVE_FORMAT_ALAW = 0x0006;

        public const uint WAVE_FORMAT_MULAW = 0x0007;

        public const uint WAVE_FORMAT_DTS = 0x0008;

        public const uint WAVE_FORMAT_DRM = 0x0009;

        public const uint WAVE_FORMAT_WMAVOICE9 = 0x000A;

        public const uint WAVE_FORMAT_WMAVOICE10 = 0x000B;

        public const uint WAVE_FORMAT_OKI_ADPCM = 0x0010;

        public const uint WAVE_FORMAT_DVI_ADPCM = 0x0011;

        public const uint WAVE_FORMAT_MEDIASPACE_ADPCM = 0x0012;

        public const uint WAVE_FORMAT_SIERRA_ADPCM = 0x0013;

        public const uint WAVE_FORMAT_G723_ADPCM = 0x0014;

        public const uint WAVE_FORMAT_DIGISTD = 0x0015;

        public const uint WAVE_FORMAT_DIGIFIX = 0x0016;

        public const uint WAVE_FORMAT_DIALOGIC_OKI_ADPCM = 0x0017;

        public const uint WAVE_FORMAT_MEDIAVISION_ADPCM = 0x0018;

        public const uint WAVE_FORMAT_CU_CODEC = 0x0019;

        public const uint WAVE_FORMAT_HP_DYN_VOICE = 0x001A;

        public const uint WAVE_FORMAT_YAMAHA_ADPCM = 0x0020;

        public const uint WAVE_FORMAT_SONARC = 0x0021;

        public const uint WAVE_FORMAT_DSPGROUP_TRUESPEECH = 0x0022;

        public const uint WAVE_FORMAT_ECHOSC1 = 0x0023;

        public const uint WAVE_FORMAT_AUDIOFILE_AF36 = 0x0024;

        public const uint WAVE_FORMAT_APTX = 0x0025;

        public const uint WAVE_FORMAT_AUDIOFILE_AF10 = 0x0026;

        public const uint WAVE_FORMAT_PROSODY_1612 = 0x0027;

        public const uint WAVE_FORMAT_LRC = 0x0028;

        public const uint WAVE_FORMAT_DOLBY_AC2 = 0x0030;

        public const uint WAVE_FORMAT_GSM610 = 0x0031;

        public const uint WAVE_FORMAT_MSNAUDIO = 0x0032;

        public const uint WAVE_FORMAT_ANTEX_ADPCME = 0x0033;

        public const uint WAVE_FORMAT_CONTROL_RES_VQLPC = 0x0034;

        public const uint WAVE_FORMAT_DIGIREAL = 0x0035;

        public const uint WAVE_FORMAT_DIGIADPCM = 0x0036;

        public const uint WAVE_FORMAT_CONTROL_RES_CR10 = 0x0037;

        public const uint WAVE_FORMAT_NMS_VBXADPCM = 0x0038;

        public const uint WAVE_FORMAT_CS_IMAADPCM = 0x0039;

        public const uint WAVE_FORMAT_ECHOSC3 = 0x003A;

        public const uint WAVE_FORMAT_ROCKWELL_ADPCM = 0x003B;

        public const uint WAVE_FORMAT_ROCKWELL_DIGITALK = 0x003C;

        public const uint WAVE_FORMAT_XEBEC = 0x003D;

        public const uint WAVE_FORMAT_G721_ADPCM = 0x0040;

        public const uint WAVE_FORMAT_G728_CELP = 0x0041;

        public const uint WAVE_FORMAT_MSG723 = 0x0042;

        public const uint WAVE_FORMAT_INTEL_G723_1 = 0x0043;

        public const uint WAVE_FORMAT_INTEL_G729 = 0x0044;

        public const uint WAVE_FORMAT_SHARP_G726 = 0x0045;

        public const uint WAVE_FORMAT_MPEG = 0x0050;

        public const uint WAVE_FORMAT_RT24 = 0x0052;

        public const uint WAVE_FORMAT_PAC = 0x0053;

        public const uint WAVE_FORMAT_MPEGLAYER3 = 0x0055;

        public const uint WAVE_FORMAT_LUCENT_G723 = 0x0059;

        public const uint WAVE_FORMAT_CIRRUS = 0x0060;

        public const uint WAVE_FORMAT_ESPCM = 0x0061;

        public const uint WAVE_FORMAT_VOXWARE = 0x0062;

        public const uint WAVE_FORMAT_CANOPUS_ATRAC = 0x0063;

        public const uint WAVE_FORMAT_G726_ADPCM = 0x0064;

        public const uint WAVE_FORMAT_G722_ADPCM = 0x0065;

        public const uint WAVE_FORMAT_DSAT = 0x0066;

        public const uint WAVE_FORMAT_DSAT_DISPLAY = 0x0067;

        public const uint WAVE_FORMAT_VOXWARE_BYTE_ALIGNED = 0x0069;

        public const uint WAVE_FORMAT_VOXWARE_AC8 = 0x0070;

        public const uint WAVE_FORMAT_VOXWARE_AC10 = 0x0071;

        public const uint WAVE_FORMAT_VOXWARE_AC16 = 0x0072;

        public const uint WAVE_FORMAT_VOXWARE_AC20 = 0x0073;

        public const uint WAVE_FORMAT_VOXWARE_RT24 = 0x0074;

        public const uint WAVE_FORMAT_VOXWARE_RT29 = 0x0075;

        public const uint WAVE_FORMAT_VOXWARE_RT29HW = 0x0076;

        public const uint WAVE_FORMAT_VOXWARE_VR12 = 0x0077;

        public const uint WAVE_FORMAT_VOXWARE_VR18 = 0x0078;

        public const uint WAVE_FORMAT_VOXWARE_TQ40 = 0x0079;

        public const uint WAVE_FORMAT_VOXWARE_SC3 = 0x007A;

        public const uint WAVE_FORMAT_VOXWARE_SC3_1 = 0x007B;

        public const uint WAVE_FORMAT_SOFTSOUND = 0x0080;

        public const uint WAVE_FORMAT_VOXWARE_TQ60 = 0x0081;

        public const uint WAVE_FORMAT_MSRT24 = 0x0082;

        public const uint WAVE_FORMAT_G729A = 0x0083;

        public const uint WAVE_FORMAT_MVI_MVI2 = 0x0084;

        public const uint WAVE_FORMAT_DF_G726 = 0x0085;

        public const uint WAVE_FORMAT_DF_GSM610 = 0x0086;

        public const uint WAVE_FORMAT_ISIAUDIO = 0x0088;

        public const uint WAVE_FORMAT_ONLIVE = 0x0089;

        public const uint WAVE_FORMAT_MULTITUDE_FT_SX20 = 0x008A;

        public const uint WAVE_FORMAT_INFOCOM_ITS_G721_ADPCM = 0x008B;

        public const uint WAVE_FORMAT_CONVEDIA_G729 = 0x008C;

        public const uint WAVE_FORMAT_CONGRUENCY = 0x008D;

        public const uint WAVE_FORMAT_SBC24 = 0x0091;

        public const uint WAVE_FORMAT_DOLBY_AC3_SPDIF = 0x0092;

        public const uint WAVE_FORMAT_MEDIASONIC_G723 = 0x0093;

        public const uint WAVE_FORMAT_PROSODY_8KBPS = 0x0094;

        public const uint WAVE_FORMAT_ZYXEL_ADPCM = 0x0097;

        public const uint WAVE_FORMAT_PHILIPS_LPCBB = 0x0098;

        public const uint WAVE_FORMAT_PACKED = 0x0099;

        public const uint WAVE_FORMAT_MALDEN_PHONYTALK = 0x00A0;

        public const uint WAVE_FORMAT_RACAL_RECORDER_GSM = 0x00A1;

        public const uint WAVE_FORMAT_RACAL_RECORDER_G720_A = 0x00A2;

        public const uint WAVE_FORMAT_RACAL_RECORDER_G723_1 = 0x00A3;

        public const uint WAVE_FORMAT_RACAL_RECORDER_TETRA_ACELP = 0x00A4;

        public const uint WAVE_FORMAT_NEC_AAC = 0x00B0;

        public const uint WAVE_FORMAT_RAW_AAC1 = 0x00FF;

        public const uint WAVE_FORMAT_RHETOREX_ADPCM = 0x0100;

        public const uint WAVE_FORMAT_IRAT = 0x0101;

        public const uint WAVE_FORMAT_VIVO_G723 = 0x0111;

        public const uint WAVE_FORMAT_VIVO_SIREN = 0x0112;

        public const uint WAVE_FORMAT_PHILIPS_CELP = 0x0120;

        public const uint WAVE_FORMAT_PHILIPS_GRUNDIG = 0x0121;

        public const uint WAVE_FORMAT_DIGITAL_G723 = 0x0123;

        public const uint WAVE_FORMAT_SANYO_LD_ADPCM = 0x0125;

        public const uint WAVE_FORMAT_SIPROLAB_ACEPLNET = 0x0130;

        public const uint WAVE_FORMAT_SIPROLAB_ACELP4800 = 0x0131;

        public const uint WAVE_FORMAT_SIPROLAB_ACELP8V3 = 0x0132;

        public const uint WAVE_FORMAT_SIPROLAB_G729 = 0x0133;

        public const uint WAVE_FORMAT_SIPROLAB_G729A = 0x0134;

        public const uint WAVE_FORMAT_SIPROLAB_KELVIN = 0x0135;

        public const uint WAVE_FORMAT_VOICEAGE_AMR = 0x0136;

        public const uint WAVE_FORMAT_G726ADPCM = 0x0140;

        public const uint WAVE_FORMAT_DICTAPHONE_CELP68 = 0x0141;

        public const uint WAVE_FORMAT_DICTAPHONE_CELP54 = 0x0142;

        public const uint WAVE_FORMAT_QUALCOMM_PUREVOICE = 0x0150;

        public const uint WAVE_FORMAT_QUALCOMM_HALFRATE = 0x0151;

        public const uint WAVE_FORMAT_TUBGSM = 0x0155;

        public const uint WAVE_FORMAT_MSAUDIO1 = 0x0160;

        public const uint WAVE_FORMAT_WMAUDIO2 = 0x0161;

        public const uint WAVE_FORMAT_WMAUDIO3 = 0x0162;

        public const uint WAVE_FORMAT_WMAUDIO_LOSSLESS = 0x0163;

        public const uint WAVE_FORMAT_WMASPDIF = 0x0164;

        public const uint WAVE_FORMAT_UNISYS_NAP_ADPCM = 0x0170;

        public const uint WAVE_FORMAT_UNISYS_NAP_ULAW = 0x0171;

        public const uint WAVE_FORMAT_UNISYS_NAP_ALAW = 0x0172;

        public const uint WAVE_FORMAT_UNISYS_NAP_16K = 0x0173;

        public const uint WAVE_FORMAT_SYCOM_ACM_SYC008 = 0x0174;

        public const uint WAVE_FORMAT_SYCOM_ACM_SYC701_G726L = 0x0175;

        public const uint WAVE_FORMAT_SYCOM_ACM_SYC701_CELP54 = 0x0176;

        public const uint WAVE_FORMAT_SYCOM_ACM_SYC701_CELP68 = 0x0177;

        public const uint WAVE_FORMAT_KNOWLEDGE_ADVENTURE_ADPCM = 0x0178;

        public const uint WAVE_FORMAT_FRAUNHOFER_IIS_MPEG2_AAC = 0x0180;

        public const uint WAVE_FORMAT_DTS_DS = 0x0190;

        public const uint WAVE_FORMAT_CREATIVE_ADPCM = 0x0200;

        public const uint WAVE_FORMAT_CREATIVE_FASTSPEECH8 = 0x0202;

        public const uint WAVE_FORMAT_CREATIVE_FASTSPEECH10 = 0x0203;

        public const uint WAVE_FORMAT_UHER_ADPCM = 0x0210;

        public const uint WAVE_FORMAT_ULEAD_DV_AUDIO = 0x0215;

        public const uint WAVE_FORMAT_ULEAD_DV_AUDIO_1 = 0x0216;

        public const uint WAVE_FORMAT_QUARTERDECK = 0x0220;

        public const uint WAVE_FORMAT_ILINK_VC = 0x0230;

        public const uint WAVE_FORMAT_RAW_SPORT = 0x0240;

        public const uint WAVE_FORMAT_ESST_AC3 = 0x0241;

        public const uint WAVE_FORMAT_GENERIC_PASSTHRU = 0x0249;

        public const uint WAVE_FORMAT_IPI_HSX = 0x0250;

        public const uint WAVE_FORMAT_IPI_RPELP = 0x0251;

        public const uint WAVE_FORMAT_CS2 = 0x0260;

        public const uint WAVE_FORMAT_SONY_SCX = 0x0270;

        public const uint WAVE_FORMAT_SONY_SCY = 0x0271;

        public const uint WAVE_FORMAT_SONY_ATRAC3 = 0x0272;

        public const uint WAVE_FORMAT_SONY_SPC = 0x0273;

        public const uint WAVE_FORMAT_TELUM_AUDIO = 0x0280;

        public const uint WAVE_FORMAT_TELUM_IA_AUDIO = 0x0281;

        public const uint WAVE_FORMAT_NORCOM_VOICE_SYSTEMS_ADPCM = 0x0285;

        public const uint WAVE_FORMAT_FM_TOWNS_SND = 0x0300;

        public const uint WAVE_FORMAT_MICRONAS = 0x0350;

        public const uint WAVE_FORMAT_MICRONAS_CELP833 = 0x0351;

        public const uint WAVE_FORMAT_BTV_DIGITAL = 0x0400;

        public const uint WAVE_FORMAT_INTEL_MUSIC_CODER = 0x0401;

        public const uint WAVE_FORMAT_INDEO_AUDIO = 0x0402;

        public const uint WAVE_FORMAT_QDESIGN_MUSIC = 0x0450;

        public const uint WAVE_FORMAT_ON2_VP7_AUDIO = 0x0500;

        public const uint WAVE_FORMAT_ON2_VP6_AUDIO = 0x0501;

        public const uint WAVE_FORMAT_VME_VMPCM = 0x0680;

        public const uint WAVE_FORMAT_TPC = 0x0681;

        public const uint WAVE_FORMAT_LIGHTWAVE_LOSSLESS = 0x08AE;

        public const uint WAVE_FORMAT_OLIGSM = 0x1000;

        public const uint WAVE_FORMAT_OLIADPCM = 0x1001;

        public const uint WAVE_FORMAT_OLICELP = 0x1002;

        public const uint WAVE_FORMAT_OLISBC = 0x1003;

        public const uint WAVE_FORMAT_OLIOPR = 0x1004;

        public const uint WAVE_FORMAT_LH_CODEC = 0x1100;

        public const uint WAVE_FORMAT_LH_CODEC_CELP = 0x1101;

        public const uint WAVE_FORMAT_LH_CODEC_SBC8 = 0x1102;

        public const uint WAVE_FORMAT_LH_CODEC_SBC12 = 0x1103;

        public const uint WAVE_FORMAT_LH_CODEC_SBC16 = 0x1104;

        public const uint WAVE_FORMAT_NORRIS = 0x1400;

        public const uint WAVE_FORMAT_ISIAUDIO_2 = 0x1401;

        public const uint WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS = 0x1500;

        public const uint WAVE_FORMAT_MPEG_ADTS_AAC = 0x1600;

        public const uint WAVE_FORMAT_MPEG_RAW_AAC = 0x1601;

        public const uint WAVE_FORMAT_MPEG_LOAS = 0x1602;

        public const uint WAVE_FORMAT_NOKIA_MPEG_ADTS_AAC = 0x1608;

        public const uint WAVE_FORMAT_NOKIA_MPEG_RAW_AAC = 0x1609;

        public const uint WAVE_FORMAT_VODAFONE_MPEG_ADTS_AAC = 0x160A;

        public const uint WAVE_FORMAT_VODAFONE_MPEG_RAW_AAC = 0x160B;

        public const uint WAVE_FORMAT_MPEG_HEAAC = 0x1610;

        public const uint WAVE_FORMAT_VOXWARE_RT24_SPEECH = 0x181C;

        public const uint WAVE_FORMAT_SONICFOUNDRY_LOSSLESS = 0x1971;

        public const uint WAVE_FORMAT_INNINGS_TELECOM_ADPCM = 0x1979;

        public const uint WAVE_FORMAT_LUCENT_SX8300P = 0x1C07;

        public const uint WAVE_FORMAT_LUCENT_SX5363S = 0x1C0C;

        public const uint WAVE_FORMAT_CUSEEME = 0x1F03;

        public const uint WAVE_FORMAT_NTCSOFT_ALF2CM_ACM = 0x1FC4;

        public const uint WAVE_FORMAT_DVM = 0x2000;

        public const uint WAVE_FORMAT_DTS2 = 0x2001;

        public const uint WAVE_FORMAT_MAKEAVIS = 0x3313;

        public const uint WAVE_FORMAT_DIVIO_MPEG4_AAC = 0x4143;

        public const uint WAVE_FORMAT_NOKIA_ADAPTIVE_MULTIRATE = 0x4201;

        public const uint WAVE_FORMAT_DIVIO_G726 = 0x4243;

        public const uint WAVE_FORMAT_LEAD_SPEECH = 0x434C;

        public const uint WAVE_FORMAT_LEAD_VORBIS = 0x564C;

        public const uint WAVE_FORMAT_WAVPACK_AUDIO = 0x5756;

        public const uint WAVE_FORMAT_ALAC = 0x6C61;

        public const uint WAVE_FORMAT_OGG_VORBIS_MODE_1 = 0x674F;

        public const uint WAVE_FORMAT_OGG_VORBIS_MODE_2 = 0x6750;

        public const uint WAVE_FORMAT_OGG_VORBIS_MODE_3 = 0x6751;

        public const uint WAVE_FORMAT_OGG_VORBIS_MODE_1_PLUS = 0x676F;

        public const uint WAVE_FORMAT_OGG_VORBIS_MODE_2_PLUS = 0x6770;

        public const uint WAVE_FORMAT_OGG_VORBIS_MODE_3_PLUS = 0x6771;

        public const uint WAVE_FORMAT_3COM_NBX = 0x7000;

        public const uint WAVE_FORMAT_OPUS = 0x704F;

        public const uint WAVE_FORMAT_FAAD_AAC = 0x706D;

        public const uint WAVE_FORMAT_AMR_NB = 0x7361;

        public const uint WAVE_FORMAT_AMR_WB = 0x7362;

        public const uint WAVE_FORMAT_AMR_WP = 0x7363;

        public const uint WAVE_FORMAT_GSM_AMR_CBR = 0x7A21;

        public const uint WAVE_FORMAT_GSM_AMR_VBR_SID = 0x7A22;

        public const uint WAVE_FORMAT_COMVERSE_INFOSYS_G723_1 = 0xA100;

        public const uint WAVE_FORMAT_COMVERSE_INFOSYS_AVQSBC = 0xA101;

        public const uint WAVE_FORMAT_COMVERSE_INFOSYS_SBC = 0xA102;

        public const uint WAVE_FORMAT_SYMBOL_G729_A = 0xA103;

        public const uint WAVE_FORMAT_VOICEAGE_AMR_WB = 0xA104;

        public const uint WAVE_FORMAT_INGENIENT_G726 = 0xA105;

        public const uint WAVE_FORMAT_MPEG4_AAC = 0xA106;

        public const uint WAVE_FORMAT_ENCORE_G726 = 0xA107;

        public const uint WAVE_FORMAT_ZOLL_ASAO = 0xA108;

        public const uint WAVE_FORMAT_SPEEX_VOICE = 0xA109;

        public const uint WAVE_FORMAT_VIANIX_MASC = 0xA10A;

        public const uint WAVE_FORMAT_WM9_SPECTRUM_ANALYZER = 0xA10B;

        public const uint WAVE_FORMAT_WMF_SPECTRUM_ANAYZER = 0xA10C;

        public const uint WAVE_FORMAT_GSM_610 = 0xA10D;

        public const uint WAVE_FORMAT_GSM_620 = 0xA10E;

        public const uint WAVE_FORMAT_GSM_660 = 0xA10F;

        public const uint WAVE_FORMAT_GSM_690 = 0xA110;

        public const uint WAVE_FORMAT_GSM_ADAPTIVE_MULTIRATE_WB = 0xA111;

        public const uint WAVE_FORMAT_POLYCOM_G722 = 0xA112;

        public const uint WAVE_FORMAT_POLYCOM_G728 = 0xA113;

        public const uint WAVE_FORMAT_POLYCOM_G729_A = 0xA114;

        public const uint WAVE_FORMAT_POLYCOM_SIREN = 0xA115;

        public const uint WAVE_FORMAT_GLOBAL_IP_ILBC = 0xA116;

        public const uint WAVE_FORMAT_RADIOTIME_TIME_SHIFT_RADIO = 0xA117;

        public const uint WAVE_FORMAT_NICE_ACA = 0xA118;

        public const uint WAVE_FORMAT_NICE_ADPCM = 0xA119;

        public const uint WAVE_FORMAT_VOCORD_G721 = 0xA11A;

        public const uint WAVE_FORMAT_VOCORD_G726 = 0xA11B;

        public const uint WAVE_FORMAT_VOCORD_G722_1 = 0xA11C;

        public const uint WAVE_FORMAT_VOCORD_G728 = 0xA11D;

        public const uint WAVE_FORMAT_VOCORD_G729 = 0xA11E;

        public const uint WAVE_FORMAT_VOCORD_G729_A = 0xA11F;

        public const uint WAVE_FORMAT_VOCORD_G723_1 = 0xA120;

        public const uint WAVE_FORMAT_VOCORD_LBC = 0xA121;

        public const uint WAVE_FORMAT_NICE_G728 = 0xA122;

        public const uint WAVE_FORMAT_FRACE_TELECOM_G729 = 0xA123;

        public const uint WAVE_FORMAT_CODIAN = 0xA124;

        public const uint WAVE_FORMAT_FLAC = 0xF1AC;

        public const uint WAVE_FORMAT_DEVELOPMENT = 0xFFFF;

        public const uint WAVE_FORMAT_PCM = 1;

        public const uint ACM_MPEG_LAYER1 = 0x0001;

        public const uint ACM_MPEG_LAYER2 = 0x0002;

        public const uint ACM_MPEG_LAYER3 = 0x0004;

        public const uint ACM_MPEG_STEREO = 0x0001;

        public const uint ACM_MPEG_JOINTSTEREO = 0x0002;

        public const uint ACM_MPEG_DUALCHANNEL = 0x0004;

        public const uint ACM_MPEG_SINGLECHANNEL = 0x0008;

        public const uint ACM_MPEG_PRIVATEBIT = 0x0001;

        public const uint ACM_MPEG_COPYRIGHT = 0x0002;

        public const uint ACM_MPEG_ORIGINALHOME = 0x0004;

        public const uint ACM_MPEG_PROTECTIONBIT = 0x0008;

        public const uint ACM_MPEG_ID_MPEG1 = 0x0010;

        public const uint MPEGLAYER3_WFX_EXTRA_BYTES = 12;

        public const uint MPEGLAYER3_ID_UNKNOWN = 0;

        public const uint MPEGLAYER3_ID_MPEG = 1;

        public const uint MPEGLAYER3_ID_CONSTANTFRAMESIZE = 2;

        public const uint MM_MSFT_ACM_WMAUDIO = 39;

        public const uint WMAUDIO_BITS_PER_SAMPLE = 16;

        public const uint WMAUDIO_MAX_CHANNELS = 2;

        public const uint MM_MSFT_ACM_MSAUDIO1 = 39;

        public const uint MM_MSFT_ACM_WMAUDIO2 = 101;

        public const uint WAVE_FILTER_UNKNOWN = 0x0000;

        public const uint WAVE_FILTER_DEVELOPMENT = 0xFFFF;

        public const uint WAVE_FILTER_VOLUME = 0x0001;

        public const uint WAVE_FILTER_ECHO = 0x0002;

        public const uint JPEG_PROCESS_BASELINE = 0;

        public const int AVIIF_CONTROLFRAME = 0x00000200;

        public const uint JIFMK_SOF0 = 0xFFC0;

        public const uint JIFMK_SOF1 = 0xFFC1;

        public const uint JIFMK_SOF2 = 0xFFC2;

        public const uint JIFMK_SOF3 = 0xFFC3;

        public const uint JIFMK_SOF5 = 0xFFC5;

        public const uint JIFMK_SOF6 = 0xFFC6;

        public const uint JIFMK_SOF7 = 0xFFC7;

        public const uint JIFMK_JPG = 0xFFC8;

        public const uint JIFMK_SOF9 = 0xFFC9;

        public const uint JIFMK_SOF10 = 0xFFCA;

        public const uint JIFMK_SOF11 = 0xFFCB;

        public const uint JIFMK_SOF13 = 0xFFCD;

        public const uint JIFMK_SOF14 = 0xFFCE;

        public const uint JIFMK_SOF15 = 0xFFCF;

        public const uint JIFMK_DHT = 0xFFC4;

        public const uint JIFMK_DAC = 0xFFCC;

        public const uint JIFMK_RST0 = 0xFFD0;

        public const uint JIFMK_RST1 = 0xFFD1;

        public const uint JIFMK_RST2 = 0xFFD2;

        public const uint JIFMK_RST3 = 0xFFD3;

        public const uint JIFMK_RST4 = 0xFFD4;

        public const uint JIFMK_RST5 = 0xFFD5;

        public const uint JIFMK_RST6 = 0xFFD6;

        public const uint JIFMK_RST7 = 0xFFD7;

        public const uint JIFMK_SOI = 0xFFD8;

        public const uint JIFMK_EOI = 0xFFD9;

        public const uint JIFMK_SOS = 0xFFDA;

        public const uint JIFMK_DQT = 0xFFDB;

        public const uint JIFMK_DNL = 0xFFDC;

        public const uint JIFMK_DRI = 0xFFDD;

        public const uint JIFMK_DHP = 0xFFDE;

        public const uint JIFMK_EXP = 0xFFDF;

        public const uint JIFMK_APP0 = 0xFFE0;

        public const uint JIFMK_APP1 = 0xFFE1;

        public const uint JIFMK_APP2 = 0xFFE2;

        public const uint JIFMK_APP3 = 0xFFE3;

        public const uint JIFMK_APP4 = 0xFFE4;

        public const uint JIFMK_APP5 = 0xFFE5;

        public const uint JIFMK_APP6 = 0xFFE6;

        public const uint JIFMK_APP7 = 0xFFE7;

        public const uint JIFMK_JPG0 = 0xFFF0;

        public const uint JIFMK_JPG1 = 0xFFF1;

        public const uint JIFMK_JPG2 = 0xFFF2;

        public const uint JIFMK_JPG3 = 0xFFF3;

        public const uint JIFMK_JPG4 = 0xFFF4;

        public const uint JIFMK_JPG5 = 0xFFF5;

        public const uint JIFMK_JPG6 = 0xFFF6;

        public const uint JIFMK_JPG7 = 0xFFF7;

        public const uint JIFMK_JPG8 = 0xFFF8;

        public const uint JIFMK_JPG9 = 0xFFF9;

        public const uint JIFMK_JPG10 = 0xFFFA;

        public const uint JIFMK_JPG11 = 0xFFFB;

        public const uint JIFMK_JPG12 = 0xFFFC;

        public const uint JIFMK_JPG13 = 0xFFFD;

        public const uint JIFMK_COM = 0xFFFE;

        public const uint JIFMK_TEM = 0xFF01;

        public const uint JIFMK_RES = 0xFF02;

        public const uint JIFMK_00 = 0xFF00;

        public const uint JIFMK_FF = 0xFFFF;

        public const uint JPEG_Y = 1;

        public const uint JPEG_YCbCr = 2;

        public const uint JPEG_RGB = 3;

        public const uint MIXERCONTROL_CONTROLTYPE_SRS_MTS = MIXERCONTROL_CONTROLTYPE_BOOLEAN + 6;

        public const uint MIXERCONTROL_CONTROLTYPE_SRS_ONOFF = MIXERCONTROL_CONTROLTYPE_BOOLEAN + 7;

        public const uint MIXERCONTROL_CONTROLTYPE_SRS_SYNTHSELECT = MIXERCONTROL_CONTROLTYPE_BOOLEAN + 8;

        public const uint SND_SYNC = 0x0000;

        public const uint SND_ASYNC = 0x0001;

        public const uint SND_NODEFAULT = 0x0002;

        public const uint SND_MEMORY = 0x0004;

        public const uint SND_LOOP = 0x0008;

        public const uint SND_NOSTOP = 0x0010;

        public const int SND_NOWAIT = 0x00002000;

        public const int SND_ALIAS = 0x00010000;

        public const int SND_ALIAS_ID = 0x00110000;

        public const int SND_FILENAME = 0x00020000;

        public const int SND_RESOURCE = 0x00040004;

        public const uint SND_PURGE = 0x0040;

        public const uint SND_APPLICATION = 0x0080;

        public const int SND_SENTRY = 0x00080000;

        public const int SND_RING = 0x00100000;

        public const int SND_SYSTEM = 0x00200000;

        public const uint SND_ALIAS_START = 0;

        public const uint MAXPNAMELEN = 32;

        public const uint MAXERRORLENGTH = 256;

        public const uint TIME_MS = 0x0001;

        public const uint TIME_SAMPLES = 0x0002;

        public const uint TIME_BYTES = 0x0004;

        public const uint TIME_SMPTE = 0x0008;

        public const uint TIME_MIDI = 0x0010;

        public const uint TIME_TICKS = 0x0020;

        public const uint MM_JOY1MOVE = 0x3A0;

        public const uint MM_JOY2MOVE = 0x3A1;

        public const uint MM_JOY1ZMOVE = 0x3A2;

        public const uint MM_JOY2ZMOVE = 0x3A3;

        public const uint MM_JOY1BUTTONDOWN = 0x3B5;

        public const uint MM_JOY2BUTTONDOWN = 0x3B6;

        public const uint MM_JOY1BUTTONUP = 0x3B7;

        public const uint MM_JOY2BUTTONUP = 0x3B8;

        public const uint MM_MCINOTIFY = 0x3B9;

        public const uint MM_WOM_OPEN = 0x3BB;

        public const uint MM_WOM_CLOSE = 0x3BC;

        public const uint MM_WOM_DONE = 0x3BD;

        public const uint MM_WIM_OPEN = 0x3BE;

        public const uint MM_WIM_CLOSE = 0x3BF;

        public const uint MM_WIM_DATA = 0x3C0;

        public const uint MM_MIM_OPEN = 0x3C1;

        public const uint MM_MIM_CLOSE = 0x3C2;

        public const uint MM_MIM_DATA = 0x3C3;

        public const uint MM_MIM_LONGDATA = 0x3C4;

        public const uint MM_MIM_ERROR = 0x3C5;

        public const uint MM_MIM_LONGERROR = 0x3C6;

        public const uint MM_MOM_OPEN = 0x3C7;

        public const uint MM_MOM_CLOSE = 0x3C8;

        public const uint MM_MOM_DONE = 0x3C9;

        public const uint MM_STREAM_OPEN = 0x3D4;

        public const uint MM_STREAM_CLOSE = 0x3D5;

        public const uint MM_STREAM_DONE = 0x3D6;

        public const uint MM_STREAM_ERROR = 0x3D7;

        public const uint MM_MOM_POSITIONCB = 0x3CA;

        public const uint MM_MIM_MOREDATA = 0x3CC;

        public const uint MM_MIXM_LINE_CHANGE = 0x3D0;

        public const uint MM_MIXM_CONTROL_CHANGE = 0x3D1;

        public const uint MMSYSERR_BASE = 0;

        public const uint WAVERR_BASE = 32;

        public const uint MIDIERR_BASE = 64;

        public const uint TIMERR_BASE = 96;

        public const uint JOYERR_BASE = 160;

        public const uint MCIERR_BASE = 256;

        public const uint MIXERR_BASE = 1024;

        public const uint MCI_STRING_OFFSET = 512;

        public const uint MCI_VD_OFFSET = 1024;

        public const uint MCI_CD_OFFSET = 1088;

        public const uint MCI_WAVE_OFFSET = 1152;

        public const uint MCI_SEQ_OFFSET = 1216;

        public const uint MMSYSERR_NOERROR = 0;

        public const uint MMSYSERR_ERROR = MMSYSERR_BASE + 1;

        public const uint MMSYSERR_BADDEVICEID = MMSYSERR_BASE + 2;

        public const uint MMSYSERR_NOTENABLED = MMSYSERR_BASE + 3;

        public const uint MMSYSERR_ALLOCATED = MMSYSERR_BASE + 4;

        public const uint MMSYSERR_INVALHANDLE = MMSYSERR_BASE + 5;

        public const uint MMSYSERR_NODRIVER = MMSYSERR_BASE + 6;

        public const uint MMSYSERR_NOMEM = MMSYSERR_BASE + 7;

        public const uint MMSYSERR_NOTSUPPORTED = MMSYSERR_BASE + 8;

        public const uint MMSYSERR_BADERRNUM = MMSYSERR_BASE + 9;

        public const uint MMSYSERR_INVALFLAG = MMSYSERR_BASE + 10;

        public const uint MMSYSERR_INVALPARAM = MMSYSERR_BASE + 11;

        public const uint MMSYSERR_HANDLEBUSY = MMSYSERR_BASE + 12;

        public const uint MMSYSERR_INVALIDALIAS = MMSYSERR_BASE + 13;

        public const uint MMSYSERR_BADDB = MMSYSERR_BASE + 14;

        public const uint MMSYSERR_KEYNOTFOUND = MMSYSERR_BASE + 15;

        public const uint MMSYSERR_READERROR = MMSYSERR_BASE + 16;

        public const uint MMSYSERR_WRITEERROR = MMSYSERR_BASE + 17;

        public const uint MMSYSERR_DELETEERROR = MMSYSERR_BASE + 18;

        public const uint MMSYSERR_VALNOTFOUND = MMSYSERR_BASE + 19;

        public const uint MMSYSERR_NODRIVERCB = MMSYSERR_BASE + 20;

        public const uint MMSYSERR_MOREDATA = MMSYSERR_BASE + 21;

        public const uint MMSYSERR_LASTERROR = MMSYSERR_BASE + 21;

        public const uint VP_COMMAND_GET = 0x0001;

        public const uint VP_COMMAND_SET = 0x0002;

        public const uint VP_FLAGS_TV_MODE = 0x0001;

        public const uint VP_FLAGS_TV_STANDARD = 0x0002;

        public const uint VP_FLAGS_FLICKER = 0x0004;

        public const uint VP_FLAGS_OVERSCAN = 0x0008;

        public const uint VP_FLAGS_MAX_UNSCALED = 0x0010;

        public const uint VP_FLAGS_POSITION = 0x0020;

        public const uint VP_FLAGS_BRIGHTNESS = 0x0040;

        public const uint VP_FLAGS_CONTRAST = 0x0080;

        public const uint VP_FLAGS_COPYPROTECT = 0x0100;

        public const uint VP_MODE_WIN_GRAPHICS = 0x0001;

        public const uint VP_MODE_TV_PLAYBACK = 0x0002;

        public const uint VP_TV_STANDARD_NTSC_M = 0x0001;

        public const uint VP_TV_STANDARD_NTSC_M_J = 0x0002;

        public const uint VP_TV_STANDARD_PAL_B = 0x0004;

        public const uint VP_TV_STANDARD_PAL_D = 0x0008;

        public const uint VP_TV_STANDARD_PAL_H = 0x0010;

        public const uint VP_TV_STANDARD_PAL_I = 0x0020;

        public const uint VP_TV_STANDARD_PAL_M = 0x0040;

        public const uint VP_TV_STANDARD_PAL_N = 0x0080;

        public const uint VP_TV_STANDARD_SECAM_B = 0x0100;

        public const uint VP_TV_STANDARD_SECAM_D = 0x0200;

        public const uint VP_TV_STANDARD_SECAM_G = 0x0400;

        public const uint VP_TV_STANDARD_SECAM_H = 0x0800;

        public const uint VP_TV_STANDARD_SECAM_K = 0x1000;

        public const uint VP_TV_STANDARD_SECAM_K1 = 0x2000;

        public const uint VP_TV_STANDARD_SECAM_L = 0x4000;

        public const uint VP_TV_STANDARD_WIN_VGA = 0x8000;

        public const uint VP_TV_STANDARD_NTSC_433 = 0x00010000;

        public const uint VP_TV_STANDARD_PAL_G = 0x00020000;

        public const uint VP_TV_STANDARD_PAL_60 = 0x00040000;

        public const uint VP_TV_STANDARD_SECAM_L1 = 0x00080000;

        public const uint VP_CP_TYPE_APS_TRIGGER = 0x0001;

        public const uint VP_CP_TYPE_MACROVISION = 0x0002;

        public const uint VP_CP_CMD_ACTIVATE = 0x0001;

        public const uint VP_CP_CMD_DEACTIVATE = 0x0002;

        public const uint VP_CP_CMD_CHANGE = 0x0004;

        public const uint DRV_MAPPER_PREFERRED_INPUT_GET = DRV_USER + 0;

        public const uint DRV_MAPPER_PREFERRED_OUTPUT_GET = DRV_USER + 2;

        public const uint DRVM_MAPPER = 0x2000;

        public const uint DRVM_MAPPER_STATUS = DRVM_MAPPER+0;

        public const uint WIDM_MAPPER_STATUS = DRVM_MAPPER_STATUS + 0;

        public const uint WAVEIN_MAPPER_STATUS_DEVICE = 0;

        public const uint WAVEIN_MAPPER_STATUS_MAPPED = 1;

        public const uint WAVEIN_MAPPER_STATUS_FORMAT = 2;

        public const uint WODM_MAPPER_STATUS = DRVM_MAPPER_STATUS + 0;

        public const uint WAVEOUT_MAPPER_STATUS_DEVICE = 0;

        public const uint WAVEOUT_MAPPER_STATUS_MAPPED = 1;

        public const uint WAVEOUT_MAPPER_STATUS_FORMAT = 2;

        public const uint ACMERR_BASE = 512;

        public const uint ACMERR_NOTPOSSIBLE = ACMERR_BASE + 0;

        public const uint ACMERR_BUSY = ACMERR_BASE + 1;

        public const uint ACMERR_UNPREPARED = ACMERR_BASE + 2;

        public const uint ACMERR_CANCELED = ACMERR_BASE + 3;

        public const uint ACM_METRIC_COUNT_DRIVERS = 1;

        public const uint ACM_METRIC_COUNT_CODECS = 2;

        public const uint ACM_METRIC_COUNT_CONVERTERS = 3;

        public const uint ACM_METRIC_COUNT_FILTERS = 4;

        public const uint ACM_METRIC_COUNT_DISABLED = 5;

        public const uint ACM_METRIC_COUNT_HARDWARE = 6;

        public const uint ACM_METRIC_COUNT_LOCAL_DRIVERS = 20;

        public const uint ACM_METRIC_COUNT_LOCAL_CODECS = 21;

        public const uint ACM_METRIC_COUNT_LOCAL_CONVERTERS = 22;

        public const uint ACM_METRIC_COUNT_LOCAL_FILTERS = 23;

        public const uint ACM_METRIC_COUNT_LOCAL_DISABLED = 24;

        public const uint ACM_METRIC_HARDWARE_WAVE_INPUT = 30;

        public const uint ACM_METRIC_HARDWARE_WAVE_OUTPUT = 31;

        public const uint ACM_METRIC_MAX_SIZE_FORMAT = 50;

        public const uint ACM_METRIC_MAX_SIZE_FILTER = 51;

        public const uint ACM_METRIC_DRIVER_SUPPORT = 100;

        public const uint ACM_METRIC_DRIVER_PRIORITY = 101;

        public const int ACM_DRIVERENUMF_NOLOCAL = 0x40000000;

        public const int ACM_DRIVERENUMF_DISABLED = unchecked((int)0x80000000);

        public const int ACM_DRIVERADDF_NAME = 0x00000001;

        public const int ACM_DRIVERADDF_FUNCTION = 0x00000003;

        public const int ACM_DRIVERADDF_NOTIFYHWND = 0x00000004;

        public const int ACM_DRIVERADDF_TYPEMASK = 0x00000007;

        public const int ACM_DRIVERADDF_LOCAL = 0x00000000;

        public const int ACM_DRIVERADDF_GLOBAL = 0x00000008;

        public const uint ACMDM_USER = DRV_USER + 0x0000;

        public const uint ACMDM_RESERVED_LOW = DRV_USER + 0x2000;

        public const uint ACMDM_RESERVED_HIGH = DRV_USER + 0x2FFF;

        public const uint ACMDM_DRIVER_ABOUT = ACMDM_BASE + 11;

        public const int ACM_DRIVERPRIORITYF_ENABLE = 0x00000001;

        public const int ACM_DRIVERPRIORITYF_DISABLE = 0x00000002;

        public const int ACM_DRIVERPRIORITYF_ABLEMASK = 0x00000003;

        public const int ACM_DRIVERPRIORITYF_BEGIN = 0x00010000;

        public const int ACM_DRIVERPRIORITYF_END = 0x00020000;

        public const int ACM_DRIVERPRIORITYF_DEFERMASK = 0x00030000;

        public const uint ACMDRIVERDETAILS_SHORTNAME_CHARS = 32;

        public const uint ACMDRIVERDETAILS_LONGNAME_CHARS = 128;

        public const uint ACMDRIVERDETAILS_COPYRIGHT_CHARS = 80;

        public const uint ACMDRIVERDETAILS_LICENSING_CHARS = 128;

        public const uint ACMDRIVERDETAILS_FEATURES_CHARS = 512;

        public const int ACMDRIVERDETAILS_SUPPORTF_CODEC = 0x00000001;

        public const int ACMDRIVERDETAILS_SUPPORTF_CONVERTER = 0x00000002;

        public const int ACMDRIVERDETAILS_SUPPORTF_FILTER = 0x00000004;

        public const int ACMDRIVERDETAILS_SUPPORTF_HARDWARE = 0x00000008;

        public const int ACMDRIVERDETAILS_SUPPORTF_ASYNC = 0x00000010;

        public const int ACMDRIVERDETAILS_SUPPORTF_LOCAL = 0x40000000;

        public const int ACMDRIVERDETAILS_SUPPORTF_DISABLED = unchecked((int)0x80000000);

        public const uint ACMFORMATTAGDETAILS_FORMATTAG_CHARS = 48;

        public const int ACM_FORMATTAGDETAILSF_INDEX = 0x00000000;

        public const int ACM_FORMATTAGDETAILSF_FORMATTAG = 0x00000001;

        public const int ACM_FORMATTAGDETAILSF_LARGESTSIZE = 0x00000002;

        public const int ACM_FORMATTAGDETAILSF_QUERYMASK = 0x0000000F;

        public const uint ACMFORMATDETAILS_FORMAT_CHARS = 128;

        public const int ACM_FORMATDETAILSF_INDEX = 0x00000000;

        public const int ACM_FORMATDETAILSF_FORMAT = 0x00000001;

        public const int ACM_FORMATDETAILSF_QUERYMASK = 0x0000000F;

        public const int ACM_FORMATENUMF_WFORMATTAG = 0x00010000;

        public const int ACM_FORMATENUMF_NCHANNELS = 0x00020000;

        public const int ACM_FORMATENUMF_NSAMPLESPERSEC = 0x00040000;

        public const int ACM_FORMATENUMF_WBITSPERSAMPLE = 0x00080000;

        public const int ACM_FORMATENUMF_CONVERT = 0x00100000;

        public const int ACM_FORMATENUMF_SUGGEST = 0x00200000;

        public const int ACM_FORMATENUMF_HARDWARE = 0x00400000;

        public const int ACM_FORMATENUMF_INPUT = 0x00800000;

        public const int ACM_FORMATENUMF_OUTPUT = 0x01000000;

        public const int ACM_FORMATSUGGESTF_WFORMATTAG = 0x00010000;

        public const int ACM_FORMATSUGGESTF_NCHANNELS = 0x00020000;

        public const int ACM_FORMATSUGGESTF_NSAMPLESPERSEC = 0x00040000;

        public const int ACM_FORMATSUGGESTF_WBITSPERSAMPLE = 0x00080000;

        public const int ACM_FORMATSUGGESTF_TYPEMASK = 0x00FF0000;

        public const uint MM_ACM_FORMATCHOOSE = 0x8000;

        public const uint FORMATCHOOSE_MESSAGE = 0;

        public const uint FORMATCHOOSE_FORMATTAG_VERIFY = FORMATCHOOSE_MESSAGE+0;

        public const uint FORMATCHOOSE_FORMAT_VERIFY = FORMATCHOOSE_MESSAGE+1;

        public const uint FORMATCHOOSE_CUSTOM_VERIFY = FORMATCHOOSE_MESSAGE+2;

        public const int ACMFORMATCHOOSE_STYLEF_SHOWHELP = 0x00000004;

        public const int ACMFORMATCHOOSE_STYLEF_ENABLEHOOK = 0x00000008;

        public const int ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE = 0x00000010;

        public const int ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE = 0x00000020;

        public const int ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT = 0x00000040;

        public const int ACMFORMATCHOOSE_STYLEF_CONTEXTHELP = 0x00000080;

        public const uint ACMFILTERTAGDETAILS_FILTERTAG_CHARS = 48;

        public const int ACM_FILTERTAGDETAILSF_INDEX = 0x00000000;

        public const int ACM_FILTERTAGDETAILSF_FILTERTAG = 0x00000001;

        public const int ACM_FILTERTAGDETAILSF_LARGESTSIZE = 0x00000002;

        public const int ACM_FILTERTAGDETAILSF_QUERYMASK = 0x0000000F;

        public const uint ACMFILTERDETAILS_FILTER_CHARS = 128;

        public const int ACM_FILTERDETAILSF_INDEX = 0x00000000;

        public const int ACM_FILTERDETAILSF_FILTER = 0x00000001;

        public const int ACM_FILTERDETAILSF_QUERYMASK = 0x0000000F;

        public const int ACM_FILTERENUMF_DWFILTERTAG = 0x00010000;

        public const uint MM_ACM_FILTERCHOOSE = 0x8000;

        public const uint FILTERCHOOSE_MESSAGE = 0;

        public const uint FILTERCHOOSE_FILTERTAG_VERIFY = FILTERCHOOSE_MESSAGE+0;

        public const uint FILTERCHOOSE_FILTER_VERIFY = FILTERCHOOSE_MESSAGE+1;

        public const uint FILTERCHOOSE_CUSTOM_VERIFY = FILTERCHOOSE_MESSAGE+2;

        public const int ACMFILTERCHOOSE_STYLEF_SHOWHELP = 0x00000004;

        public const int ACMFILTERCHOOSE_STYLEF_ENABLEHOOK = 0x00000008;

        public const int ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE = 0x00000010;

        public const int ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE = 0x00000020;

        public const int ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT = 0x00000040;

        public const int ACMFILTERCHOOSE_STYLEF_CONTEXTHELP = 0x00000080;

        public const int ACMSTREAMHEADER_STATUSF_DONE = 0x00010000;

        public const int ACMSTREAMHEADER_STATUSF_PREPARED = 0x00020000;

        public const int ACMSTREAMHEADER_STATUSF_INQUEUE = 0x00100000;

        public const uint ACM_STREAMOPENF_QUERY = 0x00000001;

        public const uint ACM_STREAMOPENF_ASYNC = 0x00000002;

        public const uint ACM_STREAMOPENF_NONREALTIME = 0x00000004;

        public const int ACM_STREAMSIZEF_SOURCE = 0x00000000;

        public const int ACM_STREAMSIZEF_DESTINATION = 0x00000001;

        public const int ACM_STREAMSIZEF_QUERYMASK = 0x0000000F;

        public const uint ACM_STREAMCONVERTF_BLOCKALIGN = 0x00000004;

        public const uint ACM_STREAMCONVERTF_START = 0x00000010;

        public const uint ACM_STREAMCONVERTF_END = 0x00000020;

        public const uint WAVERR_BADFORMAT = WAVERR_BASE + 0;

        public const uint WAVERR_STILLPLAYING = WAVERR_BASE + 1;

        public const uint WAVERR_UNPREPARED = WAVERR_BASE + 2;

        public const uint WAVERR_SYNC = WAVERR_BASE + 3;

        public const uint WAVERR_LASTERROR = WAVERR_BASE + 3;

        public const uint WHDR_DONE = 0x00000001;

        public const uint WHDR_PREPARED = 0x00000002;

        public const uint WHDR_BEGINLOOP = 0x00000004;

        public const uint WHDR_ENDLOOP = 0x00000008;

        public const uint WHDR_INQUEUE = 0x00000010;

        public const uint WAVECAPS_PITCH = 0x0001;

        public const uint WAVECAPS_PLAYBACKRATE = 0x0002;

        public const uint WAVECAPS_VOLUME = 0x0004;

        public const uint WAVECAPS_LRVOLUME = 0x0008;

        public const uint WAVECAPS_SYNC = 0x0010;

        public const uint WAVECAPS_SAMPLEACCURATE = 0x0020;

        public const uint WAVE_INVALIDFORMAT = 0x00000000;

        public const uint WAVE_FORMAT_1M08 = 0x00000001;

        public const uint WAVE_FORMAT_1S08 = 0x00000002;

        public const uint WAVE_FORMAT_1M16 = 0x00000004;

        public const uint WAVE_FORMAT_1S16 = 0x00000008;

        public const uint WAVE_FORMAT_2M08 = 0x00000010;

        public const uint WAVE_FORMAT_2S08 = 0x00000020;

        public const uint WAVE_FORMAT_2M16 = 0x00000040;

        public const uint WAVE_FORMAT_2S16 = 0x00000080;

        public const uint WAVE_FORMAT_4M08 = 0x00000100;

        public const uint WAVE_FORMAT_4S08 = 0x00000200;

        public const uint WAVE_FORMAT_4M16 = 0x00000400;

        public const uint WAVE_FORMAT_4S16 = 0x00000800;

        public const uint WAVE_FORMAT_44M08 = 0x00000100;

        public const uint WAVE_FORMAT_44S08 = 0x00000200;

        public const uint WAVE_FORMAT_44M16 = 0x00000400;

        public const uint WAVE_FORMAT_44S16 = 0x00000800;

        public const uint WAVE_FORMAT_48M08 = 0x00001000;

        public const uint WAVE_FORMAT_48S08 = 0x00002000;

        public const uint WAVE_FORMAT_48M16 = 0x00004000;

        public const uint WAVE_FORMAT_48S16 = 0x00008000;

        public const uint WAVE_FORMAT_96M08 = 0x00010000;

        public const uint WAVE_FORMAT_96S08 = 0x00020000;

        public const uint WAVE_FORMAT_96M16 = 0x00040000;

        public const uint WAVE_FORMAT_96S16 = 0x00080000;

        public const uint MIDIERR_UNPREPARED = MIDIERR_BASE + 0;

        public const uint MIDIERR_STILLPLAYING = MIDIERR_BASE + 1;

        public const uint MIDIERR_NOMAP = MIDIERR_BASE + 2;

        public const uint MIDIERR_NOTREADY = MIDIERR_BASE + 3;

        public const uint MIDIERR_NODEVICE = MIDIERR_BASE + 4;

        public const uint MIDIERR_INVALIDSETUP = MIDIERR_BASE + 5;

        public const uint MIDIERR_BADOPENMODE = MIDIERR_BASE + 6;

        public const uint MIDIERR_DONT_CONTINUE = MIDIERR_BASE + 7;

        public const uint MIDIERR_LASTERROR = MIDIERR_BASE + 7;

        public const uint MIDIPATCHSIZE = 128;

        public const uint MIDI_CACHE_ALL = 1;

        public const uint MIDI_CACHE_BESTFIT = 2;

        public const uint MIDI_CACHE_QUERY = 3;

        public const uint MIDI_UNCACHE = 4;

        public const uint MOD_MIDIPORT = 1;

        public const uint MOD_SYNTH = 2;

        public const uint MOD_SQSYNTH = 3;

        public const uint MOD_FMSYNTH = 4;

        public const uint MOD_MAPPER = 5;

        public const uint MOD_WAVETABLE = 6;

        public const uint MOD_SWSYNTH = 7;

        public const uint MIDICAPS_VOLUME = 0x0001;

        public const uint MIDICAPS_LRVOLUME = 0x0002;

        public const uint MIDICAPS_CACHE = 0x0004;

        public const uint MIDICAPS_STREAM = 0x0008;

        public const uint MHDR_DONE = 0x00000001;

        public const uint MHDR_PREPARED = 0x00000002;

        public const uint MHDR_INQUEUE = 0x00000004;

        public const uint MHDR_ISSTRM = 0x00000008;

        public const int MEVT_F_SHORT = 0x00000000;

        public const int MEVT_F_LONG = unchecked((int)0x80000000);

        public const int MEVT_F_CALLBACK = 0x40000000;

        public const int MIDISTRM_ERROR = -2;

        public const int MIDIPROP_SET = unchecked((int)0x80000000);

        public const int MIDIPROP_GET = 0x40000000;

        public const int MIDIPROP_TIMEDIV = 0x00000001;

        public const int MIDIPROP_TEMPO = 0x00000002;

        public const uint AUXCAPS_CDAUDIO = 1;

        public const uint AUXCAPS_AUXIN = 2;

        public const uint AUXCAPS_VOLUME = 0x0001;

        public const uint AUXCAPS_LRVOLUME = 0x0002;

        public const uint MIXER_SHORT_NAME_CHARS = 16;

        public const uint MIXER_LONG_NAME_CHARS = 64;

        public const uint MIXERR_INVALLINE = MIXERR_BASE + 0;

        public const uint MIXERR_INVALCONTROL = MIXERR_BASE + 1;

        public const uint MIXERR_INVALVALUE = MIXERR_BASE + 2;

        public const uint MIXERR_LASTERROR = MIXERR_BASE + 2;

        public const int MIXER_OBJECTF_HANDLE = unchecked((int)0x80000000);

        public const int MIXER_OBJECTF_MIXER = 0x00000000;

        public const int MIXER_OBJECTF_WAVEOUT = 0x10000000;

        public const int MIXER_OBJECTF_WAVEIN = 0x20000000;

        public const int MIXER_OBJECTF_MIDIOUT = 0x30000000;

        public const int MIXER_OBJECTF_MIDIIN = 0x40000000;

        public const int MIXER_OBJECTF_AUX = 0x50000000;

        public const int MIXERLINE_LINEF_ACTIVE = 0x00000001;

        public const int MIXERLINE_LINEF_DISCONNECTED = 0x00008000;

        public const int MIXERLINE_LINEF_SOURCE = unchecked((int)0x80000000);

        public const int MIXERLINE_COMPONENTTYPE_DST_FIRST = 0x00000000;

        public const uint MIXERLINE_COMPONENTTYPE_DST_LAST = MIXERLINE_COMPONENTTYPE_DST_FIRST + 8;

        public const int MIXERLINE_COMPONENTTYPE_SRC_FIRST = 0x00001000;

        public const uint MIXERLINE_COMPONENTTYPE_SRC_LAST = MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10;

        public const uint MIXERLINE_TARGETTYPE_UNDEFINED = 0;

        public const uint MIXERLINE_TARGETTYPE_WAVEOUT = 1;

        public const uint MIXERLINE_TARGETTYPE_WAVEIN = 2;

        public const uint MIXERLINE_TARGETTYPE_MIDIOUT = 3;

        public const uint MIXERLINE_TARGETTYPE_MIDIIN = 4;

        public const uint MIXERLINE_TARGETTYPE_AUX = 5;

        public const int MIXER_GETLINEINFOF_DESTINATION = 0x00000000;

        public const int MIXER_GETLINEINFOF_SOURCE = 0x00000001;

        public const int MIXER_GETLINEINFOF_LINEID = 0x00000002;

        public const int MIXER_GETLINEINFOF_COMPONENTTYPE = 0x00000003;

        public const int MIXER_GETLINEINFOF_TARGETTYPE = 0x00000004;

        public const int MIXER_GETLINEINFOF_QUERYMASK = 0x0000000F;

        public const int MIXERCONTROL_CONTROLF_UNIFORM = 0x00000001;

        public const int MIXERCONTROL_CONTROLF_MULTIPLE = 0x00000002;

        public const int MIXERCONTROL_CONTROLF_DISABLED = unchecked((int)0x80000000);

        public const int MIXERCONTROL_CT_CLASS_MASK = unchecked((int)0xF0000000);

        public const int MIXERCONTROL_CT_CLASS_CUSTOM = 0x00000000;

        public const int MIXERCONTROL_CT_CLASS_METER = 0x10000000;

        public const int MIXERCONTROL_CT_CLASS_SWITCH = 0x20000000;

        public const int MIXERCONTROL_CT_CLASS_NUMBER = 0x30000000;

        public const int MIXERCONTROL_CT_CLASS_SLIDER = 0x40000000;

        public const int MIXERCONTROL_CT_CLASS_FADER = 0x50000000;

        public const int MIXERCONTROL_CT_CLASS_TIME = 0x60000000;

        public const int MIXERCONTROL_CT_CLASS_LIST = 0x70000000;

        public const int MIXERCONTROL_CT_SUBCLASS_MASK = 0x0F000000;

        public const int MIXERCONTROL_CT_SC_SWITCH_BOOLEAN = 0x00000000;

        public const int MIXERCONTROL_CT_SC_SWITCH_BUTTON = 0x01000000;

        public const int MIXERCONTROL_CT_SC_METER_POLLED = 0x00000000;

        public const int MIXERCONTROL_CT_SC_TIME_MICROSECS = 0x00000000;

        public const int MIXERCONTROL_CT_SC_TIME_MILLISECS = 0x01000000;

        public const int MIXERCONTROL_CT_SC_LIST_SINGLE = 0x00000000;

        public const int MIXERCONTROL_CT_SC_LIST_MULTIPLE = 0x01000000;

        public const int MIXERCONTROL_CT_UNITS_MASK = 0x00FF0000;

        public const int MIXERCONTROL_CT_UNITS_CUSTOM = 0x00000000;

        public const int MIXERCONTROL_CT_UNITS_BOOLEAN = 0x00010000;

        public const int MIXERCONTROL_CT_UNITS_SIGNED = 0x00020000;

        public const int MIXERCONTROL_CT_UNITS_UNSIGNED = 0x00030000;

        public const int MIXERCONTROL_CT_UNITS_DECIBELS = 0x00040000;

        public const int MIXERCONTROL_CT_UNITS_PERCENT = 0x00050000;

        public const int MIXER_GETLINECONTROLSF_ALL = 0x00000000;

        public const int MIXER_GETLINECONTROLSF_ONEBYID = 0x00000001;

        public const int MIXER_GETLINECONTROLSF_ONEBYTYPE = 0x00000002;

        public const int MIXER_GETLINECONTROLSF_QUERYMASK = 0x0000000F;

        public const int MIXER_GETCONTROLDETAILSF_VALUE = 0x00000000;

        public const int MIXER_GETCONTROLDETAILSF_LISTTEXT = 0x00000001;

        public const int MIXER_GETCONTROLDETAILSF_QUERYMASK = 0x0000000F;

        public const int MIXER_SETCONTROLDETAILSF_VALUE = 0x00000000;

        public const int MIXER_SETCONTROLDETAILSF_CUSTOM = 0x00000001;

        public const int MIXER_SETCONTROLDETAILSF_QUERYMASK = 0x0000000F;

        public const uint ICVERSION = 0x0104;

        public const uint BI_1632 = 0x32333631;

        public const int ICERR_OK = 0;

        public const int ICERR_DONTDRAW = 1;

        public const int ICERR_NEWPALETTE = 2;

        public const int ICERR_GOTOKEYFRAME = 3;

        public const int ICERR_STOPDRAWING = 4;

        public const int ICERR_UNSUPPORTED = -1;

        public const int ICERR_BADFORMAT = -2;

        public const int ICERR_MEMORY = -3;

        public const int ICERR_INTERNAL = -4;

        public const int ICERR_BADFLAGS = -5;

        public const int ICERR_BADPARAM = -6;

        public const int ICERR_BADSIZE = -7;

        public const int ICERR_BADHANDLE = -8;

        public const int ICERR_CANTUPDATE = -9;

        public const int ICERR_ABORT = -10;

        public const int ICERR_ERROR = -100;

        public const int ICERR_BADBITDEPTH = -200;

        public const int ICERR_BADIMAGESIZE = -201;

        public const int ICERR_CUSTOM = -400;

        public const uint ICMODE_COMPRESS = 1;

        public const uint ICMODE_DECOMPRESS = 2;

        public const uint ICMODE_FASTDECOMPRESS = 3;

        public const uint ICMODE_QUERY = 4;

        public const uint ICMODE_FASTCOMPRESS = 5;

        public const uint ICMODE_DRAW = 8;

        public const uint ICMODE_INTERNALF_FUNCTION32 = 0x8000;

        public const uint ICMODE_INTERNALF_MASK = 0x8000;

        public const int AVIIF_TWOCC = 0x00000002;

        public const uint ICQUALITY_LOW = 0;

        public const uint ICQUALITY_HIGH = 10000;

        public const int ICQUALITY_DEFAULT = -1;

        public const uint ICM_USER = DRV_USER+0x0000;

        public const uint ICM_RESERVED_LOW = DRV_USER+0x1000;

        public const uint ICM_RESERVED_HIGH = DRV_USER+0x2000;

        public const uint ICM_GETSTATE = ICM_RESERVED+0;

        public const uint ICM_SETSTATE = ICM_RESERVED+1;

        public const uint ICM_GETINFO = ICM_RESERVED+2;

        public const uint ICM_CONFIGURE = ICM_RESERVED+10;

        public const uint ICM_ABOUT = ICM_RESERVED+11;

        public const uint ICM_GETERRORTEXT = ICM_RESERVED+12;

        public const uint ICM_GETFORMATNAME = ICM_RESERVED+20;

        public const uint ICM_ENUMFORMATS = ICM_RESERVED+21;

        public const uint ICM_GETDEFAULTQUALITY = ICM_RESERVED+30;

        public const uint ICM_GETQUALITY = ICM_RESERVED+31;

        public const uint ICM_SETQUALITY = ICM_RESERVED+32;

        public const uint ICM_SET = ICM_RESERVED+40;

        public const uint ICM_GET = ICM_RESERVED+41;

        public const uint ICM_COMPRESS_GET_FORMAT = ICM_USER+4;

        public const uint ICM_COMPRESS_GET_SIZE = ICM_USER+5;

        public const uint ICM_COMPRESS_QUERY = ICM_USER+6;

        public const uint ICM_COMPRESS_BEGIN = ICM_USER+7;

        public const uint ICM_COMPRESS = ICM_USER+8;

        public const uint ICM_COMPRESS_END = ICM_USER+9;

        public const uint ICM_DECOMPRESS_GET_FORMAT = ICM_USER+10;

        public const uint ICM_DECOMPRESS_QUERY = ICM_USER+11;

        public const uint ICM_DECOMPRESS_BEGIN = ICM_USER+12;

        public const uint ICM_DECOMPRESS = ICM_USER+13;

        public const uint ICM_DECOMPRESS_END = ICM_USER+14;

        public const uint ICM_DECOMPRESS_SET_PALETTE = ICM_USER+29;

        public const uint ICM_DECOMPRESS_GET_PALETTE = ICM_USER+30;

        public const uint ICM_DRAW_QUERY = ICM_USER+31;

        public const uint ICM_DRAW_BEGIN = ICM_USER+15;

        public const uint ICM_DRAW_GET_PALETTE = ICM_USER+16;

        public const uint ICM_DRAW_UPDATE = ICM_USER+17;

        public const uint ICM_DRAW_START = ICM_USER+18;

        public const uint ICM_DRAW_STOP = ICM_USER+19;

        public const uint ICM_DRAW_BITS = ICM_USER+20;

        public const uint ICM_DRAW_END = ICM_USER+21;

        public const uint ICM_DRAW_GETTIME = ICM_USER+32;

        public const uint ICM_DRAW = ICM_USER+33;

        public const uint ICM_DRAW_WINDOW = ICM_USER+34;

        public const uint ICM_DRAW_SETTIME = ICM_USER+35;

        public const uint ICM_DRAW_REALIZE = ICM_USER+36;

        public const uint ICM_DRAW_FLUSH = ICM_USER+37;

        public const uint ICM_DRAW_RENDERBUFFER = ICM_USER+38;

        public const uint ICM_DRAW_START_PLAY = ICM_USER+39;

        public const uint ICM_DRAW_STOP_PLAY = ICM_USER+40;

        public const uint ICM_DRAW_SUGGESTFORMAT = ICM_USER+50;

        public const uint ICM_DRAW_CHANGEPALETTE = ICM_USER+51;

        public const uint ICM_DRAW_IDLE = ICM_USER+52;

        public const uint ICM_GETBUFFERSWANTED = ICM_USER+41;

        public const uint ICM_GETDEFAULTKEYFRAMERATE = ICM_USER+42;

        public const uint ICM_DECOMPRESSEX_BEGIN = ICM_USER+60;

        public const uint ICM_DECOMPRESSEX_QUERY = ICM_USER+61;

        public const uint ICM_DECOMPRESSEX = ICM_USER+62;

        public const uint ICM_DECOMPRESSEX_END = ICM_USER+63;

        public const uint ICM_COMPRESS_FRAMES_INFO = ICM_USER+70;

        public const uint ICM_COMPRESS_FRAMES = ICM_USER+71;

        public const uint ICM_SET_STATUS_PROC = ICM_USER+72;

        public const uint VIDCF_QUALITY = 0x0001;

        public const uint VIDCF_CRUNCH = 0x0002;

        public const uint VIDCF_TEMPORAL = 0x0004;

        public const uint VIDCF_COMPRESSFRAMES = 0x0008;

        public const uint VIDCF_DRAW = 0x0010;

        public const uint VIDCF_FASTTEMPORALC = 0x0020;

        public const uint VIDCF_FASTTEMPORALD = 0x0080;

        public const int ICCOMPRESS_KEYFRAME = 0x00000001;

        public const uint ICCOMPRESSFRAMES_PADDING = 0x00000001;

        public const int ICDECOMPRESS_HURRYUP = unchecked((int)0x80000000);

        public const int ICDECOMPRESS_UPDATE = 0x40000000;

        public const int ICDECOMPRESS_PREROLL = 0x20000000;

        public const int ICDECOMPRESS_NULLFRAME = 0x10000000;

        public const int ICDECOMPRESS_NOTKEYFRAME = 0x08000000;

        public const int ICDRAW_QUERY = 0x00000001;

        public const int ICDRAW_FULLSCREEN = 0x00000002;

        public const int ICDRAW_HDC = 0x00000004;

        public const int ICDRAW_ANIMATE = 0x00000008;

        public const int ICDRAW_CONTINUE = 0x00000010;

        public const int ICDRAW_MEMORYDC = 0x00000020;

        public const int ICDRAW_UPDATING = 0x00000040;

        public const int ICDRAW_RENDER = 0x00000080;

        public const int ICDRAW_BUFFER = 0x00000100;

        public const int ICDRAW_HURRYUP = unchecked((int)0x80000000);

        public const int ICDRAW_UPDATE = 0x40000000;

        public const int ICDRAW_PREROLL = 0x20000000;

        public const int ICDRAW_NULLFRAME = 0x10000000;

        public const int ICDRAW_NOTKEYFRAME = 0x08000000;

        public const uint ICINSTALL_UNICODE = 0x8000;

        public const uint ICINSTALL_FUNCTION = 0x0001;

        public const uint ICINSTALL_DRIVER = 0x0002;

        public const uint ICINSTALL_HDRV = 0x0004;

        public const uint ICINSTALL_DRIVERW = 0x8002;

        public const uint ICMF_CONFIGURE_QUERY = 0x00000001;

        public const uint ICMF_ABOUT_QUERY = 0x00000001;

        public const uint ICMF_COMPVARS_VALID = 0x00000001;

        public const uint ICMF_CHOOSE_KEYFRAME = 0x0001;

        public const uint ICMF_CHOOSE_DATARATE = 0x0002;

        public const uint ICMF_CHOOSE_PREVIEW = 0x0004;

        public const uint ICMF_CHOOSE_ALLCOMPRESSORS = 0x0008;

        public const uint DDF_0001 = 0x0001;

        public const uint DDF_UPDATE = 0x0002;

        public const uint DDF_SAME_HDC = 0x0004;

        public const uint DDF_SAME_DRAW = 0x0008;

        public const uint DDF_DONTDRAW = 0x0010;

        public const uint DDF_ANIMATE = 0x0020;

        public const uint DDF_BUFFER = 0x0040;

        public const uint DDF_JUSTDRAWIT = 0x0080;

        public const uint DDF_FULLSCREEN = 0x0100;

        public const uint DDF_BACKGROUNDPAL = 0x0200;

        public const uint DDF_NOTKEYFRAME = 0x0400;

        public const uint DDF_HURRYUP = 0x0800;

        public const uint DDF_HALFTONE = 0x1000;

        public const uint DDF_2000 = 0x2000;

        public const uint PD_CAN_DRAW_DIB = 0x0001;

        public const uint PD_CAN_STRETCHDIB = 0x0002;

        public const uint PD_STRETCHDIB_1_1_OK = 0x0004;

        public const uint PD_STRETCHDIB_1_2_OK = 0x0008;

        public const uint PD_STRETCHDIB_1_N_OK = 0x0010;

        public const uint AVIGETFRAMEF_BESTDISPLAYFMT = 1;

        public const uint AVISTREAMINFO_DISABLED = 0x00000001;

        public const uint AVISTREAMINFO_FORMATCHANGES = 0x00010000;

        public const uint AVIFILEINFO_HASINDEX = 0x00000010;

        public const uint AVIFILEINFO_MUSTUSEINDEX = 0x00000020;

        public const uint AVIFILEINFO_ISINTERLEAVED = 0x00000100;

        public const uint AVIFILEINFO_WASCAPTUREFILE = 0x00010000;

        public const uint AVIFILEINFO_COPYRIGHTED = 0x00020000;

        public const uint AVIFILECAPS_CANREAD = 0x00000001;

        public const uint AVIFILECAPS_CANWRITE = 0x00000002;

        public const uint AVIFILECAPS_ALLKEYFRAMES = 0x00000010;

        public const uint AVIFILECAPS_NOCOMPRESSION = 0x00000020;

        public const uint AVICOMPRESSF_INTERLEAVE = 0x00000001;

        public const uint AVICOMPRESSF_DATARATE = 0x00000002;

        public const uint AVICOMPRESSF_KEYFRAMES = 0x00000004;

        public const uint AVICOMPRESSF_VALID = 0x00000008;

        public static readonly Guid IID_IAVIFile__scanned__ = new Guid(0x00020020, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IAVIStream__scanned__ = new Guid(0x00020021, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IAVIStreaming__scanned__ = new Guid(0x00020022, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IGetFrame__scanned__ = new Guid(0x00020023, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IAVIEditStream__scanned__ = new Guid(0x00020024, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IAVIPersistFile__scanned__ = new Guid(0x00020025, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CLSID_AVISimpleUnMarshal__scanned__ = new Guid(0x00020009, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid CLSID_AVIFile__scanned__ = new Guid(0x00020000, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public const uint AVIFILEHANDLER_CANREAD = 0x0001;

        public const uint AVIFILEHANDLER_CANWRITE = 0x0002;

        public const uint AVIFILEHANDLER_CANACCEPTNONRGB = 0x0004;

        public const int AVISTREAMREAD_CONVENIENT = -1;

        public const int FIND_DIR = 0x0000000F;

        public const int FIND_NEXT = 0x00000001;

        public const int FIND_PREV = 0x00000004;

        public const int FIND_FROM_START = 0x00000008;

        public const int FIND_TYPE = 0x000000F0;

        public const int FIND_KEY = 0x00000010;

        public const int FIND_ANY = 0x00000020;

        public const int FIND_FORMAT = 0x00000040;

        public const int FIND_RET = 0x0000F000;

        public const int FIND_POS = 0x00000000;

        public const int FIND_LENGTH = 0x00001000;

        public const int FIND_OFFSET = 0x00002000;

        public const int FIND_SIZE = 0x00003000;

        public const int FIND_INDEX = 0x00004000;

        public const int AVIERR_OK = 0;

        public const uint MCIWNDOPENF_NEW = 0x0001;

        public const uint MCIWNDF_NOAUTOSIZEWINDOW = 0x0001;

        public const uint MCIWNDF_NOPLAYBAR = 0x0002;

        public const uint MCIWNDF_NOAUTOSIZEMOVIE = 0x0004;

        public const uint MCIWNDF_NOMENU = 0x0008;

        public const uint MCIWNDF_SHOWNAME = 0x0010;

        public const uint MCIWNDF_SHOWPOS = 0x0020;

        public const uint MCIWNDF_SHOWMODE = 0x0040;

        public const uint MCIWNDF_SHOWALL = 0x0070;

        public const uint MCIWNDF_NOTIFYMODE = 0x0100;

        public const uint MCIWNDF_NOTIFYPOS = 0x0200;

        public const uint MCIWNDF_NOTIFYSIZE = 0x0400;

        public const uint MCIWNDF_NOTIFYERROR = 0x1000;

        public const uint MCIWNDF_NOTIFYALL = 0x1F00;

        public const uint MCIWNDF_NOTIFYANSI = 0x0080;

        public const uint MCIWNDF_NOTIFYMEDIAA = 0x0880;

        public const uint MCIWNDF_NOTIFYMEDIAW = 0x0800;

        public const uint MCIWNDF_RECORD = 0x2000;

        public const uint MCIWNDF_NOERRORDLG = 0x4000;

        public const uint MCIWNDF_NOOPEN = 0x8000;

        public const uint MCIWNDM_GETDEVICEID = WM_USER + 100;

        public const uint MCIWNDM_GETSTART = WM_USER + 103;

        public const uint MCIWNDM_GETLENGTH = WM_USER + 104;

        public const uint MCIWNDM_GETEND = WM_USER + 105;

        public const uint MCIWNDM_EJECT = WM_USER + 107;

        public const uint MCIWNDM_SETZOOM = WM_USER + 108;

        public const uint MCIWNDM_GETZOOM = WM_USER + 109;

        public const uint MCIWNDM_SETVOLUME = WM_USER + 110;

        public const uint MCIWNDM_GETVOLUME = WM_USER + 111;

        public const uint MCIWNDM_SETSPEED = WM_USER + 112;

        public const uint MCIWNDM_GETSPEED = WM_USER + 113;

        public const uint MCIWNDM_SETREPEAT = WM_USER + 114;

        public const uint MCIWNDM_GETREPEAT = WM_USER + 115;

        public const uint MCIWNDM_REALIZE = WM_USER + 118;

        public const uint MCIWNDM_VALIDATEMEDIA = WM_USER + 121;

        public const uint MCIWNDM_PLAYFROM = WM_USER + 122;

        public const uint MCIWNDM_PLAYTO = WM_USER + 123;

        public const uint MCIWNDM_GETPALETTE = WM_USER + 126;

        public const uint MCIWNDM_SETPALETTE = WM_USER + 127;

        public const uint MCIWNDM_SETTIMERS = WM_USER + 129;

        public const uint MCIWNDM_SETACTIVETIMER = WM_USER + 130;

        public const uint MCIWNDM_SETINACTIVETIMER = WM_USER + 131;

        public const uint MCIWNDM_GETACTIVETIMER = WM_USER + 132;

        public const uint MCIWNDM_GETINACTIVETIMER = WM_USER + 133;

        public const uint MCIWNDM_CHANGESTYLES = WM_USER + 135;

        public const uint MCIWNDM_GETSTYLES = WM_USER + 136;

        public const uint MCIWNDM_GETALIAS = WM_USER + 137;

        public const uint MCIWNDM_PLAYREVERSE = WM_USER + 139;

        public const uint MCIWNDM_GET_SOURCE = WM_USER + 140;

        public const uint MCIWNDM_PUT_SOURCE = WM_USER + 141;

        public const uint MCIWNDM_GET_DEST = WM_USER + 142;

        public const uint MCIWNDM_PUT_DEST = WM_USER + 143;

        public const uint MCIWNDM_CAN_PLAY = WM_USER + 144;

        public const uint MCIWNDM_CAN_WINDOW = WM_USER + 145;

        public const uint MCIWNDM_CAN_RECORD = WM_USER + 146;

        public const uint MCIWNDM_CAN_SAVE = WM_USER + 147;

        public const uint MCIWNDM_CAN_EJECT = WM_USER + 148;

        public const uint MCIWNDM_CAN_CONFIG = WM_USER + 149;

        public const uint MCIWNDM_PALETTEKICK = WM_USER + 150;

        public const uint MCIWNDM_OPENINTERFACE = WM_USER + 151;

        public const uint MCIWNDM_SETOWNER = WM_USER + 152;

        public const uint MCIWNDM_SENDSTRINGA = WM_USER + 101;

        public const uint MCIWNDM_GETPOSITIONA = WM_USER + 102;

        public const uint MCIWNDM_GETMODEA = WM_USER + 106;

        public const uint MCIWNDM_SETTIMEFORMATA = WM_USER + 119;

        public const uint MCIWNDM_GETTIMEFORMATA = WM_USER + 120;

        public const uint MCIWNDM_GETFILENAMEA = WM_USER + 124;

        public const uint MCIWNDM_GETDEVICEA = WM_USER + 125;

        public const uint MCIWNDM_GETERRORA = WM_USER + 128;

        public const uint MCIWNDM_NEWA = WM_USER + 134;

        public const uint MCIWNDM_RETURNSTRINGA = WM_USER + 138;

        public const uint MCIWNDM_OPENA = WM_USER + 153;

        public const uint MCIWNDM_SENDSTRINGW = WM_USER + 201;

        public const uint MCIWNDM_GETPOSITIONW = WM_USER + 202;

        public const uint MCIWNDM_GETMODEW = WM_USER + 206;

        public const uint MCIWNDM_SETTIMEFORMATW = WM_USER + 219;

        public const uint MCIWNDM_GETTIMEFORMATW = WM_USER + 220;

        public const uint MCIWNDM_GETFILENAMEW = WM_USER + 224;

        public const uint MCIWNDM_GETDEVICEW = WM_USER + 225;

        public const uint MCIWNDM_GETERRORW = WM_USER + 228;

        public const uint MCIWNDM_NEWW = WM_USER + 234;

        public const uint MCIWNDM_RETURNSTRINGW = WM_USER + 238;

        public const uint MCIWNDM_OPENW = WM_USER + 252;

        public const uint MCIWNDM_NOTIFYMODE = WM_USER + 200;

        public const uint MCIWNDM_NOTIFYPOS = WM_USER + 201;

        public const uint MCIWNDM_NOTIFYSIZE = WM_USER + 202;

        public const uint MCIWNDM_NOTIFYMEDIA = WM_USER + 203;

        public const uint MCIWNDM_NOTIFYERROR = WM_USER + 205;

        public const int MCIWND_START = -1;

        public const int MCIWND_END = -2;

        public const uint DV_ERR_OK = 0;

        public const uint DV_ERR_BASE = 1;

        public const uint DV_ERR_BADFORMAT = DV_ERR_BASE + 1;

        public const uint DV_ERR_STILLPLAYING = DV_ERR_BASE + 2;

        public const uint DV_ERR_UNPREPARED = DV_ERR_BASE + 3;

        public const uint DV_ERR_SYNC = DV_ERR_BASE + 4;

        public const uint DV_ERR_TOOMANYCHANNELS = DV_ERR_BASE + 5;

        public const uint DV_ERR_NOTDETECTED = DV_ERR_BASE + 6;

        public const uint DV_ERR_BADINSTALL = DV_ERR_BASE + 7;

        public const uint DV_ERR_CREATEPALETTE = DV_ERR_BASE + 8;

        public const uint DV_ERR_SIZEFIELD = DV_ERR_BASE + 9;

        public const uint DV_ERR_PARAM1 = DV_ERR_BASE + 10;

        public const uint DV_ERR_PARAM2 = DV_ERR_BASE + 11;

        public const uint DV_ERR_CONFIG1 = DV_ERR_BASE + 12;

        public const uint DV_ERR_CONFIG2 = DV_ERR_BASE + 13;

        public const uint DV_ERR_FLAGS = DV_ERR_BASE + 14;

        public const uint DV_ERR_13 = DV_ERR_BASE + 15;

        public const uint DV_ERR_NOTSUPPORTED = DV_ERR_BASE + 16;

        public const uint DV_ERR_NOMEM = DV_ERR_BASE + 17;

        public const uint DV_ERR_ALLOCATED = DV_ERR_BASE + 18;

        public const uint DV_ERR_BADDEVICEID = DV_ERR_BASE + 19;

        public const uint DV_ERR_INVALHANDLE = DV_ERR_BASE + 20;

        public const uint DV_ERR_BADERRNUM = DV_ERR_BASE + 21;

        public const uint DV_ERR_NO_BUFFERS = DV_ERR_BASE + 22;

        public const uint DV_ERR_MEM_CONFLICT = DV_ERR_BASE + 23;

        public const uint DV_ERR_IO_CONFLICT = DV_ERR_BASE + 24;

        public const uint DV_ERR_DMA_CONFLICT = DV_ERR_BASE + 25;

        public const uint DV_ERR_INT_CONFLICT = DV_ERR_BASE + 26;

        public const uint DV_ERR_PROTECT_ONLY = DV_ERR_BASE + 27;

        public const uint DV_ERR_LASTERROR = DV_ERR_BASE + 27;

        public const uint DV_ERR_USER_MSG = DV_ERR_BASE + 1000;

        public const uint MM_DRVM_OPEN = 0x3D0;

        public const uint MM_DRVM_CLOSE = 0x3D1;

        public const uint MM_DRVM_DATA = 0x3D2;

        public const uint MM_DRVM_ERROR = 0x3D3;

        public const uint VHDR_DONE = 0x00000001;

        public const uint VHDR_PREPARED = 0x00000002;

        public const uint VHDR_INQUEUE = 0x00000004;

        public const uint VHDR_KEYFRAME = 0x00000008;

        public const uint VHDR_VALID = 0x0000000F;

        public const uint VCAPS_OVERLAY = 0x00000001;

        public const uint VCAPS_SRC_CAN_CLIP = 0x00000002;

        public const uint VCAPS_DST_CAN_CLIP = 0x00000004;

        public const uint VCAPS_CAN_SCALE = 0x00000008;

        public const uint VIDEO_EXTERNALIN = 0x0001;

        public const uint VIDEO_EXTERNALOUT = 0x0002;

        public const uint VIDEO_IN = 0x0004;

        public const uint VIDEO_OUT = 0x0008;

        public const uint VIDEO_DLG_QUERY = 0x0010;

        public const uint VIDEO_CONFIGURE_QUERY = 0x8000;

        public const uint VIDEO_CONFIGURE_SET = 0x1000;

        public const uint VIDEO_CONFIGURE_GET = 0x2000;

        public const uint VIDEO_CONFIGURE_QUERYSIZE = 0x0001;

        public const uint VIDEO_CONFIGURE_CURRENT = 0x0010;

        public const uint VIDEO_CONFIGURE_NOMINAL = 0x0020;

        public const uint VIDEO_CONFIGURE_MIN = 0x0040;

        public const uint VIDEO_CONFIGURE_MAX = 0x0080;

        public const uint DVM_USER = 0X4000;

        public const uint DVM_CONFIGURE_START = 0x1000;

        public const uint DVM_CONFIGURE_END = 0x1FFF;

        public const uint DVM_PALETTE = DVM_CONFIGURE_START + 1;

        public const uint DVM_FORMAT = DVM_CONFIGURE_START + 2;

        public const uint DVM_PALETTERGB555 = DVM_CONFIGURE_START + 3;

        public const uint DVM_SRC_RECT = DVM_CONFIGURE_START + 4;

        public const uint DVM_DST_RECT = DVM_CONFIGURE_START + 5;

        public const uint WM_CAP_UNICODE_START = WM_USER+100;

        public const uint WM_CAP_GET_CAPSTREAMPTR = WM_CAP_START+  1;

        public const uint WM_CAP_SET_CALLBACK_ERRORW = WM_CAP_UNICODE_START+  2;

        public const uint WM_CAP_SET_CALLBACK_STATUSW = WM_CAP_UNICODE_START+  3;

        public const uint WM_CAP_SET_CALLBACK_ERRORA = WM_CAP_START+  2;

        public const uint WM_CAP_SET_CALLBACK_STATUSA = WM_CAP_START+  3;

        public const uint WM_CAP_SET_CALLBACK_YIELD = WM_CAP_START+  4;

        public const uint WM_CAP_SET_CALLBACK_FRAME = WM_CAP_START+  5;

        public const uint WM_CAP_SET_CALLBACK_VIDEOSTREAM = WM_CAP_START+  6;

        public const uint WM_CAP_SET_CALLBACK_WAVESTREAM = WM_CAP_START+  7;

        public const uint WM_CAP_GET_USER_DATA = WM_CAP_START+  8;

        public const uint WM_CAP_SET_USER_DATA = WM_CAP_START+  9;

        public const uint WM_CAP_DRIVER_CONNECT = WM_CAP_START+  10;

        public const uint WM_CAP_DRIVER_DISCONNECT = WM_CAP_START+  11;

        public const uint WM_CAP_DRIVER_GET_NAMEA = WM_CAP_START+  12;

        public const uint WM_CAP_DRIVER_GET_VERSIONA = WM_CAP_START+  13;

        public const uint WM_CAP_DRIVER_GET_NAMEW = WM_CAP_UNICODE_START+  12;

        public const uint WM_CAP_DRIVER_GET_VERSIONW = WM_CAP_UNICODE_START+  13;

        public const uint WM_CAP_DRIVER_GET_CAPS = WM_CAP_START+  14;

        public const uint WM_CAP_FILE_SET_CAPTURE_FILEA = WM_CAP_START+  20;

        public const uint WM_CAP_FILE_GET_CAPTURE_FILEA = WM_CAP_START+  21;

        public const uint WM_CAP_FILE_SAVEASA = WM_CAP_START+  23;

        public const uint WM_CAP_FILE_SAVEDIBA = WM_CAP_START+  25;

        public const uint WM_CAP_FILE_SET_CAPTURE_FILEW = WM_CAP_UNICODE_START+  20;

        public const uint WM_CAP_FILE_GET_CAPTURE_FILEW = WM_CAP_UNICODE_START+  21;

        public const uint WM_CAP_FILE_SAVEASW = WM_CAP_UNICODE_START+  23;

        public const uint WM_CAP_FILE_SAVEDIBW = WM_CAP_UNICODE_START+  25;

        public const uint WM_CAP_FILE_ALLOCATE = WM_CAP_START+  22;

        public const uint WM_CAP_FILE_SET_INFOCHUNK = WM_CAP_START+  24;

        public const uint WM_CAP_EDIT_COPY = WM_CAP_START+  30;

        public const uint WM_CAP_SET_AUDIOFORMAT = WM_CAP_START+  35;

        public const uint WM_CAP_GET_AUDIOFORMAT = WM_CAP_START+  36;

        public const uint WM_CAP_DLG_VIDEOFORMAT = WM_CAP_START+  41;

        public const uint WM_CAP_DLG_VIDEOSOURCE = WM_CAP_START+  42;

        public const uint WM_CAP_DLG_VIDEODISPLAY = WM_CAP_START+  43;

        public const uint WM_CAP_GET_VIDEOFORMAT = WM_CAP_START+  44;

        public const uint WM_CAP_SET_VIDEOFORMAT = WM_CAP_START+  45;

        public const uint WM_CAP_DLG_VIDEOCOMPRESSION = WM_CAP_START+  46;

        public const uint WM_CAP_SET_PREVIEW = WM_CAP_START+  50;

        public const uint WM_CAP_SET_OVERLAY = WM_CAP_START+  51;

        public const uint WM_CAP_SET_PREVIEWRATE = WM_CAP_START+  52;

        public const uint WM_CAP_SET_SCALE = WM_CAP_START+  53;

        public const uint WM_CAP_GET_STATUS = WM_CAP_START+  54;

        public const uint WM_CAP_SET_SCROLL = WM_CAP_START+  55;

        public const uint WM_CAP_GRAB_FRAME = WM_CAP_START+  60;

        public const uint WM_CAP_GRAB_FRAME_NOSTOP = WM_CAP_START+  61;

        public const uint WM_CAP_SEQUENCE = WM_CAP_START+  62;

        public const uint WM_CAP_SEQUENCE_NOFILE = WM_CAP_START+  63;

        public const uint WM_CAP_SET_SEQUENCE_SETUP = WM_CAP_START+  64;

        public const uint WM_CAP_GET_SEQUENCE_SETUP = WM_CAP_START+  65;

        public const uint WM_CAP_SET_MCI_DEVICEA = WM_CAP_START+  66;

        public const uint WM_CAP_GET_MCI_DEVICEA = WM_CAP_START+  67;

        public const uint WM_CAP_SET_MCI_DEVICEW = WM_CAP_UNICODE_START+  66;

        public const uint WM_CAP_GET_MCI_DEVICEW = WM_CAP_UNICODE_START+  67;

        public const uint WM_CAP_STOP = WM_CAP_START+  68;

        public const uint WM_CAP_ABORT = WM_CAP_START+  69;

        public const uint WM_CAP_SINGLE_FRAME_OPEN = WM_CAP_START+  70;

        public const uint WM_CAP_SINGLE_FRAME_CLOSE = WM_CAP_START+  71;

        public const uint WM_CAP_SINGLE_FRAME = WM_CAP_START+  72;

        public const uint WM_CAP_PAL_OPENA = WM_CAP_START+  80;

        public const uint WM_CAP_PAL_SAVEA = WM_CAP_START+  81;

        public const uint WM_CAP_PAL_OPENW = WM_CAP_UNICODE_START+  80;

        public const uint WM_CAP_PAL_SAVEW = WM_CAP_UNICODE_START+  81;

        public const uint WM_CAP_PAL_PASTE = WM_CAP_START+  82;

        public const uint WM_CAP_PAL_AUTOCREATE = WM_CAP_START+  83;

        public const uint WM_CAP_PAL_MANUALCREATE = WM_CAP_START+  84;

        public const uint WM_CAP_SET_CALLBACK_CAPCONTROL = WM_CAP_START+  85;

        public const uint AVSTREAMMASTER_AUDIO = 0;

        public const uint AVSTREAMMASTER_NONE = 1;

        public const uint CONTROLCALLBACK_PREROLL = 1;

        public const uint CONTROLCALLBACK_CAPTURING = 2;

        public const uint IDS_CAP_BEGIN = 300;

        public const uint IDS_CAP_END = 301;

        public const uint IDS_CAP_INFO = 401;

        public const uint IDS_CAP_OUTOFMEM = 402;

        public const uint IDS_CAP_FILEEXISTS = 403;

        public const uint IDS_CAP_ERRORPALOPEN = 404;

        public const uint IDS_CAP_ERRORPALSAVE = 405;

        public const uint IDS_CAP_ERRORDIBSAVE = 406;

        public const uint IDS_CAP_DEFAVIEXT = 407;

        public const uint IDS_CAP_DEFPALEXT = 408;

        public const uint IDS_CAP_CANTOPEN = 409;

        public const uint IDS_CAP_SEQ_MSGSTART = 410;

        public const uint IDS_CAP_SEQ_MSGSTOP = 411;

        public const uint IDS_CAP_VIDEDITERR = 412;

        public const uint IDS_CAP_READONLYFILE = 413;

        public const uint IDS_CAP_WRITEERROR = 414;

        public const uint IDS_CAP_NODISKSPACE = 415;

        public const uint IDS_CAP_SETFILESIZE = 416;

        public const uint IDS_CAP_SAVEASPERCENT = 417;

        public const uint IDS_CAP_DRIVER_ERROR = 418;

        public const uint IDS_CAP_WAVE_OPEN_ERROR = 419;

        public const uint IDS_CAP_WAVE_ALLOC_ERROR = 420;

        public const uint IDS_CAP_WAVE_PREPARE_ERROR = 421;

        public const uint IDS_CAP_WAVE_ADD_ERROR = 422;

        public const uint IDS_CAP_WAVE_SIZE_ERROR = 423;

        public const uint IDS_CAP_VIDEO_OPEN_ERROR = 424;

        public const uint IDS_CAP_VIDEO_ALLOC_ERROR = 425;

        public const uint IDS_CAP_VIDEO_PREPARE_ERROR = 426;

        public const uint IDS_CAP_VIDEO_ADD_ERROR = 427;

        public const uint IDS_CAP_VIDEO_SIZE_ERROR = 428;

        public const uint IDS_CAP_FILE_OPEN_ERROR = 429;

        public const uint IDS_CAP_FILE_WRITE_ERROR = 430;

        public const uint IDS_CAP_RECORDING_ERROR = 431;

        public const uint IDS_CAP_RECORDING_ERROR2 = 432;

        public const uint IDS_CAP_AVI_INIT_ERROR = 433;

        public const uint IDS_CAP_NO_FRAME_CAP_ERROR = 434;

        public const uint IDS_CAP_NO_PALETTE_WARN = 435;

        public const uint IDS_CAP_MCI_CONTROL_ERROR = 436;

        public const uint IDS_CAP_MCI_CANT_STEP_ERROR = 437;

        public const uint IDS_CAP_NO_AUDIO_CAP_ERROR = 438;

        public const uint IDS_CAP_AVI_DRAWDIB_ERROR = 439;

        public const uint IDS_CAP_COMPRESSOR_ERROR = 440;

        public const uint IDS_CAP_AUDIO_DROP_ERROR = 441;

        public const uint IDS_CAP_AUDIO_DROP_COMPERROR = 442;

        public const uint IDS_CAP_STAT_LIVE_MODE = 500;

        public const uint IDS_CAP_STAT_OVERLAY_MODE = 501;

        public const uint IDS_CAP_STAT_CAP_INIT = 502;

        public const uint IDS_CAP_STAT_CAP_FINI = 503;

        public const uint IDS_CAP_STAT_PALETTE_BUILD = 504;

        public const uint IDS_CAP_STAT_OPTPAL_BUILD = 505;

        public const uint IDS_CAP_STAT_I_FRAMES = 506;

        public const uint IDS_CAP_STAT_L_FRAMES = 507;

        public const uint IDS_CAP_STAT_CAP_L_FRAMES = 508;

        public const uint IDS_CAP_STAT_CAP_AUDIO = 509;

        public const uint IDS_CAP_STAT_VIDEOCURRENT = 510;

        public const uint IDS_CAP_STAT_VIDEOAUDIO = 511;

        public const uint IDS_CAP_STAT_VIDEOONLY = 512;

        public const uint IDS_CAP_STAT_FRAMESDROPPED = 513;

        public const uint JOYERR_NOERROR = 0;

        public const uint JOYERR_PARMS = JOYERR_BASE+5;

        public const uint JOYERR_NOCANDO = JOYERR_BASE+6;

        public const uint JOYERR_UNPLUGGED = JOYERR_BASE+7;

        public const uint JOY_BUTTON1 = 0x0001;

        public const uint JOY_BUTTON2 = 0x0002;

        public const uint JOY_BUTTON3 = 0x0004;

        public const uint JOY_BUTTON4 = 0x0008;

        public const uint JOY_BUTTON1CHG = 0x0100;

        public const uint JOY_BUTTON2CHG = 0x0200;

        public const uint JOY_BUTTON3CHG = 0x0400;

        public const uint JOY_BUTTON4CHG = 0x0800;

        public const int JOY_BUTTON5 = 0x00000010;

        public const int JOY_BUTTON6 = 0x00000020;

        public const int JOY_BUTTON7 = 0x00000040;

        public const int JOY_BUTTON8 = 0x00000080;

        public const int JOY_BUTTON9 = 0x00000100;

        public const int JOY_BUTTON10 = 0x00000200;

        public const int JOY_BUTTON11 = 0x00000400;

        public const int JOY_BUTTON12 = 0x00000800;

        public const int JOY_BUTTON13 = 0x00001000;

        public const int JOY_BUTTON14 = 0x00002000;

        public const int JOY_BUTTON15 = 0x00004000;

        public const int JOY_BUTTON16 = 0x00008000;

        public const int JOY_BUTTON17 = 0x00010000;

        public const int JOY_BUTTON18 = 0x00020000;

        public const int JOY_BUTTON19 = 0x00040000;

        public const int JOY_BUTTON20 = 0x00080000;

        public const int JOY_BUTTON21 = 0x00100000;

        public const int JOY_BUTTON22 = 0x00200000;

        public const int JOY_BUTTON23 = 0x00400000;

        public const int JOY_BUTTON24 = 0x00800000;

        public const int JOY_BUTTON25 = 0x01000000;

        public const int JOY_BUTTON26 = 0x02000000;

        public const int JOY_BUTTON27 = 0x04000000;

        public const int JOY_BUTTON28 = 0x08000000;

        public const int JOY_BUTTON29 = 0x10000000;

        public const int JOY_BUTTON30 = 0x20000000;

        public const int JOY_BUTTON31 = 0x40000000;

        public const int JOY_BUTTON32 = unchecked((int)0x80000000);

        public const uint JOY_POVFORWARD = 0;

        public const uint JOY_POVRIGHT = 9000;

        public const uint JOY_POVBACKWARD = 18000;

        public const uint JOY_POVLEFT = 27000;

        public const int JOY_RETURNX = 0x00000001;

        public const int JOY_RETURNY = 0x00000002;

        public const int JOY_RETURNZ = 0x00000004;

        public const int JOY_RETURNR = 0x00000008;

        public const int JOY_RETURNU = 0x00000010;

        public const int JOY_RETURNV = 0x00000020;

        public const int JOY_RETURNPOV = 0x00000040;

        public const int JOY_RETURNBUTTONS = 0x00000080;

        public const int JOY_RETURNRAWDATA = 0x00000100;

        public const int JOY_RETURNPOVCTS = 0x00000200;

        public const int JOY_RETURNCENTERED = 0x00000400;

        public const int JOY_USEDEADZONE = 0x00000800;

        public const int JOY_CAL_READALWAYS = 0x00010000;

        public const int JOY_CAL_READXYONLY = 0x00020000;

        public const int JOY_CAL_READ3 = 0x00040000;

        public const int JOY_CAL_READ4 = 0x00080000;

        public const int JOY_CAL_READXONLY = 0x00100000;

        public const int JOY_CAL_READYONLY = 0x00200000;

        public const int JOY_CAL_READ5 = 0x00400000;

        public const int JOY_CAL_READ6 = 0x00800000;

        public const int JOY_CAL_READZONLY = 0x01000000;

        public const int JOY_CAL_READRONLY = 0x02000000;

        public const int JOY_CAL_READUONLY = 0x04000000;

        public const int JOY_CAL_READVONLY = 0x08000000;

        public const uint JOYSTICKID1 = 0;

        public const uint JOYSTICKID2 = 1;

        public const uint JOYCAPS_HASZ = 0x0001;

        public const uint JOYCAPS_HASR = 0x0002;

        public const uint JOYCAPS_HASU = 0x0004;

        public const uint JOYCAPS_HASV = 0x0008;

        public const uint JOYCAPS_HASPOV = 0x0010;

        public const uint JOYCAPS_POV4DIR = 0x0020;

        public const uint JOYCAPS_POVCTS = 0x0040;

        public const uint DRV_LOAD = 0x0001;

        public const uint DRV_ENABLE = 0x0002;

        public const uint DRV_OPEN = 0x0003;

        public const uint DRV_CLOSE = 0x0004;

        public const uint DRV_DISABLE = 0x0005;

        public const uint DRV_FREE = 0x0006;

        public const uint DRV_CONFIGURE = 0x0007;

        public const uint DRV_QUERYCONFIGURE = 0x0008;

        public const uint DRV_INSTALL = 0x0009;

        public const uint DRV_REMOVE = 0x000A;

        public const uint DRV_RESERVED = 0x0800;

        public const uint DRV_USER = 0x4000;

        public const uint DCB_NOSWITCH = 0x0008;

        public const uint DCB_TYPEMASK = 0x0007;

        public const uint DCB_NULL = 0x0000;

        public const uint DCB_WINDOW = 0x0001;

        public const uint DCB_TASK = 0x0002;

        public const uint DCB_FUNCTION = 0x0003;

        public const uint DCB_EVENT = 0x0005;

        public const uint DRVM_INIT = 100;

        public const uint DRVM_EXIT = 101;

        public const uint DRVM_DISABLE = 102;

        public const uint DRVM_ENABLE = 103;

        public const uint DRVM_INIT_EX = 104;

        public const uint DRVM_USER = 0x4000;

        public const uint DRVM_MAPPER_RECONFIGURE = DRVM_MAPPER+1;

        public const uint DRVM_MAPPER_PREFERRED_GET = DRVM_MAPPER+21;

        public const uint DRVM_MAPPER_CONSOLEVOICECOM_GET = DRVM_MAPPER+23;

        public const uint DRV_QUERYDEVNODE = DRV_RESERVED + 2;

        public const uint DRV_QUERYMAPPABLE = DRV_RESERVED + 5;

        public const uint DRV_QUERYMODULE = DRV_RESERVED + 9;

        public const uint DRV_PNPINSTALL = DRV_RESERVED + 11;

        public const uint DRV_QUERYDEVICEINTERFACE = DRV_RESERVED + 12;

        public const uint DRV_QUERYDEVICEINTERFACESIZE = DRV_RESERVED + 13;

        public const uint DRV_QUERYSTRINGID = DRV_RESERVED + 14;

        public const uint DRV_QUERYSTRINGIDSIZE = DRV_RESERVED + 15;

        public const uint DRV_QUERYIDFROMSTRINGID = DRV_RESERVED + 16;

        public const uint DRV_QUERYFUNCTIONINSTANCEID = DRV_RESERVED + 17;

        public const uint DRV_QUERYFUNCTIONINSTANCEIDSIZE = DRV_RESERVED + 18;

        public const uint DRVM_MAPPER_PREFERRED_FLAGS_PREFERREDONLY = 0x00000001;

        public const uint DRVM_IOCTL = 0x100;

        public const uint DRVM_ADD_THRU = DRVM_IOCTL+1;

        public const uint DRVM_REMOVE_THRU = DRVM_IOCTL+2;

        public const uint DRVM_IOCTL_LAST = DRVM_IOCTL+5;

        public const int DRVM_IOCTL_CMD_USER = 0x00000000;

        public const int DRVM_IOCTL_CMD_SYSTEM = unchecked((int)0x80000000);

        public const uint VADMAD_Device_ID = 0X0444;

        public const uint WODM_GETNUMDEVS = 3;

        public const uint WODM_GETDEVCAPS = 4;

        public const uint WODM_OPEN = 5;

        public const uint WODM_CLOSE = 6;

        public const uint WODM_PREPARE = 7;

        public const uint WODM_UNPREPARE = 8;

        public const uint WODM_WRITE = 9;

        public const uint WODM_PAUSE = 10;

        public const uint WODM_RESTART = 11;

        public const uint WODM_RESET = 12;

        public const uint WODM_GETPOS = 13;

        public const uint WODM_GETPITCH = 14;

        public const uint WODM_SETPITCH = 15;

        public const uint WODM_GETVOLUME = 16;

        public const uint WODM_SETVOLUME = 17;

        public const uint WODM_GETPLAYBACKRATE = 18;

        public const uint WODM_SETPLAYBACKRATE = 19;

        public const uint WODM_BREAKLOOP = 20;

        public const uint WODM_PREFERRED = 21;

        public const uint WODM_BUSY = 21;

        public const uint WIDM_GETNUMDEVS = 50;

        public const uint WIDM_GETDEVCAPS = 51;

        public const uint WIDM_OPEN = 52;

        public const uint WIDM_CLOSE = 53;

        public const uint WIDM_PREPARE = 54;

        public const uint WIDM_UNPREPARE = 55;

        public const uint WIDM_ADDBUFFER = 56;

        public const uint WIDM_START = 57;

        public const uint WIDM_STOP = 58;

        public const uint WIDM_RESET = 59;

        public const uint WIDM_GETPOS = 60;

        public const uint WIDM_PREFERRED = 61;

        public const int MIDI_IO_PACKED = 0x00000000;

        public const int MIDI_IO_COOKED = 0x00000002;

        public const uint MODM_GETNUMDEVS = 1;

        public const uint MODM_GETDEVCAPS = 2;

        public const uint MODM_OPEN = 3;

        public const uint MODM_CLOSE = 4;

        public const uint MODM_PREPARE = 5;

        public const uint MODM_UNPREPARE = 6;

        public const uint MODM_DATA = 7;

        public const uint MODM_LONGDATA = 8;

        public const uint MODM_RESET = 9;

        public const uint MODM_GETVOLUME = 10;

        public const uint MODM_SETVOLUME = 11;

        public const uint MODM_CACHEPATCHES = 12;

        public const uint MODM_CACHEDRUMPATCHES = 13;

        public const uint MODM_STRMDATA = 14;

        public const uint MODM_GETPOS = 17;

        public const uint MODM_PAUSE = 18;

        public const uint MODM_RESTART = 19;

        public const uint MODM_STOP = 20;

        public const uint MODM_PROPERTIES = 21;

        public const uint MODM_PREFERRED = 22;

        public const uint MODM_RECONFIGURE = MODM_USER+0x0768;

        public const uint MIDM_GETNUMDEVS = 53;

        public const uint MIDM_GETDEVCAPS = 54;

        public const uint MIDM_OPEN = 55;

        public const uint MIDM_CLOSE = 56;

        public const uint MIDM_PREPARE = 57;

        public const uint MIDM_UNPREPARE = 58;

        public const uint MIDM_ADDBUFFER = 59;

        public const uint MIDM_START = 60;

        public const uint MIDM_STOP = 61;

        public const uint MIDM_RESET = 62;

        public const uint AUXDM_GETNUMDEVS = 3;

        public const uint AUXDM_GETDEVCAPS = 4;

        public const uint AUXDM_GETVOLUME = 5;

        public const uint AUXDM_SETVOLUME = 6;

        public const uint MXDM_BASE = 1;

        public const uint MXDM_GETNUMDEVS = MXDM_BASE + 0;

        public const uint MXDM_GETDEVCAPS = MXDM_BASE + 1;

        public const uint MXDM_OPEN = MXDM_BASE + 2;

        public const uint MXDM_CLOSE = MXDM_BASE + 3;

        public const uint MXDM_GETLINEINFO = MXDM_BASE + 4;

        public const uint MXDM_GETLINECONTROLS = MXDM_BASE + 5;

        public const uint MXDM_GETCONTROLDETAILS = MXDM_BASE + 6;

        public const uint MXDM_SETCONTROLDETAILS = MXDM_BASE + 7;

        public const uint TDD_KILLTIMEREVENT = DRV_RESERVED+0;

        public const uint TDD_SETTIMEREVENT = DRV_RESERVED+4;

        public const uint TDD_GETSYSTEMTIME = DRV_RESERVED+8;

        public const uint TDD_GETDEVCAPS = DRV_RESERVED+12;

        public const uint TDD_BEGINMINPERIOD = DRV_RESERVED+16;

        public const uint TDD_ENDMINPERIOD = DRV_RESERVED+20;

        public const uint JDD_GETNUMDEVS = DRV_RESERVED + 0x0001;

        public const uint JDD_GETDEVCAPS = DRV_RESERVED + 0x0002;

        public const uint JDD_GETPOS = DRV_RESERVED + 0x0101;

        public const uint JDD_SETCALIBRATION = DRV_RESERVED + 0x0102;

        public const uint JDD_CONFIGCHANGED = DRV_RESERVED + 0x0103;

        public const uint JDD_GETPOSEX = DRV_RESERVED + 0x0104;

        public const uint MCI_OPEN_DRIVER = 0x0801;

        public const uint MCI_CLOSE_DRIVER = 0x0802;

        public const uint MCI_FALSE = MCI_STRING_OFFSET + 19;

        public const uint MCI_TRUE = MCI_STRING_OFFSET + 20;

        public const uint MCI_FORMAT_MILLISECONDS_S = MCI_STRING_OFFSET + 21;

        public const uint MCI_FORMAT_HMS_S = MCI_STRING_OFFSET + 22;

        public const uint MCI_FORMAT_MSF_S = MCI_STRING_OFFSET + 23;

        public const uint MCI_FORMAT_FRAMES_S = MCI_STRING_OFFSET + 24;

        public const uint MCI_FORMAT_SMPTE_24_S = MCI_STRING_OFFSET + 25;

        public const uint MCI_FORMAT_SMPTE_25_S = MCI_STRING_OFFSET + 26;

        public const uint MCI_FORMAT_SMPTE_30_S = MCI_STRING_OFFSET + 27;

        public const uint MCI_FORMAT_SMPTE_30DROP_S = MCI_STRING_OFFSET + 28;

        public const uint MCI_FORMAT_BYTES_S = MCI_STRING_OFFSET + 29;

        public const uint MCI_FORMAT_SAMPLES_S = MCI_STRING_OFFSET + 30;

        public const uint MCI_FORMAT_TMSF_S = MCI_STRING_OFFSET + 31;

        public const uint MCI_VD_FORMAT_TRACK_S = MCI_VD_OFFSET + 5;

        public const uint WAVE_FORMAT_PCM_S = MCI_WAVE_OFFSET + 0;

        public const uint WAVE_MAPPER_S = MCI_WAVE_OFFSET + 1;

        public const uint MCI_SEQ_MAPPER_S = MCI_SEQ_OFFSET + 5;

        public const uint MCI_SEQ_FILE_S = MCI_SEQ_OFFSET + 6;

        public const uint MCI_SEQ_MIDI_S = MCI_SEQ_OFFSET + 7;

        public const uint MCI_SEQ_SMPTE_S = MCI_SEQ_OFFSET + 8;

        public const uint MCI_SEQ_FORMAT_SONGPTR_S = MCI_SEQ_OFFSET + 9;

        public const uint MCI_SEQ_NONE_S = MCI_SEQ_OFFSET + 10;

        public const uint MIDIMAPPER_S = MCI_SEQ_OFFSET + 11;

        public const uint MCI_MAX_DEVICE_TYPE_LENGTH = 80;

        public const uint MCI_RESOURCE_RETURNED = 0x00010000;

        public const uint MCI_COLONIZED3_RETURN = 0x00020000;

        public const uint MCI_COLONIZED4_RETURN = 0x00040000;

        public const uint MCI_INTEGER_RETURNED = 0x00080000;

        public const uint MCI_RESOURCE_DRIVER = 0x00100000;

        public const uint MCI_COMMAND_HEAD = 0;

        public const uint MCI_STRING = 1;

        public const uint MCI_INTEGER = 2;

        public const uint MCI_END_COMMAND = 3;

        public const uint MCI_RETURN = 4;

        public const uint MCI_FLAG = 5;

        public const uint MCI_END_COMMAND_LIST = 6;

        public const uint MCI_RECT = 7;

        public const uint MCI_CONSTANT = 8;

        public const uint MCI_END_CONSTANT = 9;

        public const uint MCI_HWND = 10;

        public const uint MCI_HPAL = 11;

        public const uint MCI_HDC = 12;

        public const uint MCI_INTEGER64 = 13;

        public const uint TASKERR_NOTASKSUPPORT = 1;

        public const uint TASKERR_OUTOFMEMORY = 2;

        public const uint DRV_EXITSESSION = 0x000B;

        public const uint DRV_POWER = 0x000F;

        public const uint DRVCNF_CANCEL = 0x0000;

        public const uint DRVCNF_OK = 0x0001;

        public const uint DRVCNF_RESTART = 0x0002;

        public const uint DRV_MCI_LAST = DRV_RESERVED + 0xFFF;

        public const uint MMIOERR_BASE = 256;

        public const uint MMIOERR_FILENOTFOUND = MMIOERR_BASE + 1;

        public const uint MMIOERR_OUTOFMEMORY = MMIOERR_BASE + 2;

        public const uint MMIOERR_CANNOTOPEN = MMIOERR_BASE + 3;

        public const uint MMIOERR_CANNOTCLOSE = MMIOERR_BASE + 4;

        public const uint MMIOERR_CANNOTREAD = MMIOERR_BASE + 5;

        public const uint MMIOERR_CANNOTWRITE = MMIOERR_BASE + 6;

        public const uint MMIOERR_CANNOTSEEK = MMIOERR_BASE + 7;

        public const uint MMIOERR_CANNOTEXPAND = MMIOERR_BASE + 8;

        public const uint MMIOERR_CHUNKNOTFOUND = MMIOERR_BASE + 9;

        public const uint MMIOERR_UNBUFFERED = MMIOERR_BASE + 10;

        public const uint MMIOERR_PATHNOTFOUND = MMIOERR_BASE + 11;

        public const uint MMIOERR_ACCESSDENIED = MMIOERR_BASE + 12;

        public const uint MMIOERR_SHARINGVIOLATION = MMIOERR_BASE + 13;

        public const uint MMIOERR_NETWORKERROR = MMIOERR_BASE + 14;

        public const uint MMIOERR_TOOMANYOPENFILES = MMIOERR_BASE + 15;

        public const uint MMIOERR_INVALIDFILE = MMIOERR_BASE + 16;

        public const uint MMIO_RWMODE = 0x00000003;

        public const uint MMIO_SHAREMODE = 0x00000070;

        public const uint MMIO_CREATE = 0x00001000;

        public const uint MMIO_PARSE = 0x00000100;

        public const uint MMIO_DELETE = 0x00000200;

        public const uint MMIO_EXIST = 0x00004000;

        public const uint MMIO_ALLOCBUF = 0x00010000;

        public const uint MMIO_GETTEMP = 0x00020000;

        public const uint MMIO_DIRTY = 0x10000000;

        public const uint MMIO_READ = 0x00000000;

        public const uint MMIO_WRITE = 0x00000001;

        public const uint MMIO_READWRITE = 0x00000002;

        public const uint MMIO_COMPAT = 0x00000000;

        public const uint MMIO_EXCLUSIVE = 0x00000010;

        public const uint MMIO_DENYWRITE = 0x00000020;

        public const uint MMIO_DENYREAD = 0x00000030;

        public const uint MMIO_DENYNONE = 0x00000040;

        public const uint MMIO_FHOPEN = 0x0010;

        public const uint MMIO_EMPTYBUF = 0x0010;

        public const uint MMIO_TOUPPER = 0x0010;

        public const uint MMIO_INSTALLPROC = 0x00010000;

        public const uint MMIO_GLOBALPROC = 0x10000000;

        public const uint MMIO_REMOVEPROC = 0x00020000;

        public const uint MMIO_UNICODEPROC = 0x01000000;

        public const uint MMIO_FINDPROC = 0x00040000;

        public const uint MMIO_FINDCHUNK = 0x0010;

        public const uint MMIO_FINDRIFF = 0x0020;

        public const uint MMIO_FINDLIST = 0x0040;

        public const uint MMIO_CREATERIFF = 0x0020;

        public const uint MMIO_CREATELIST = 0x0040;

        public const uint MMIOM_SEEK = 2;

        public const uint MMIOM_OPEN = 3;

        public const uint MMIOM_CLOSE = 4;

        public const uint MMIOM_WRITEFLUSH = 5;

        public const uint MMIOM_RENAME = 6;

        public const uint MMIOM_USER = 0x8000;

        public const uint SEEK_SET = 0;

        public const uint SEEK_CUR = 1;

        public const uint SEEK_END = 2;

        public const uint MMIO_DEFAULTBUFFER = 8192;

        public const uint TIMERR_NOERROR = 0;

        public const uint TIMERR_NOCANDO = TIMERR_BASE+1;

        public const uint TIMERR_STRUCT = TIMERR_BASE+33;

    }
}
