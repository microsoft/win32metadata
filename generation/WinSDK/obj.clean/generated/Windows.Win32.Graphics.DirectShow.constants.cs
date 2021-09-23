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


namespace Windows.Win32.Graphics.DirectShow
{
    public static partial class Apis
    {
        public const uint EC_SND_DEVICE_ERROR_BASE = 0x0200;

        public const uint EC_SNDDEV_IN_ERROR = EC_SND_DEVICE_ERROR_BASE + 0x00;

        public const uint EC_SNDDEV_OUT_ERROR = EC_SND_DEVICE_ERROR_BASE + 0x01;

        public const uint EC_SYSTEMBASE = 0x00;

        public const uint EC_USER = 0x8000;

        public const uint EC_COMPLETE = 0x01;

        public const uint EC_USERABORT = 0x02;

        public const uint EC_ERRORABORT = 0x03;

        public const uint EC_TIME = 0x04;

        public const uint EC_REPAINT = 0x05;

        public const uint EC_STREAM_ERROR_STOPPED = 0x06;

        public const uint EC_STREAM_ERROR_STILLPLAYING = 0x07;

        public const uint EC_ERROR_STILLPLAYING = 0x08;

        public const uint EC_PALETTE_CHANGED = 0x09;

        public const uint EC_VIDEO_SIZE_CHANGED = 0x0A;

        public const uint EC_QUALITY_CHANGE = 0x0B;

        public const uint EC_SHUTTING_DOWN = 0x0C;

        public const uint EC_CLOCK_CHANGED = 0x0D;

        public const uint EC_PAUSED = 0x0E;

        public const uint EC_OPENING_FILE = 0x10;

        public const uint EC_BUFFERING_DATA = 0x11;

        public const uint EC_FULLSCREEN_LOST = 0x12;

        public const uint EC_ACTIVATE = 0x13;

        public const uint EC_NEED_RESTART = 0x14;

        public const uint EC_WINDOW_DESTROYED = 0x15;

        public const uint EC_DISPLAY_CHANGED = 0x16;

        public const uint EC_STARVATION = 0x17;

        public const uint EC_OLE_EVENT = 0x18;

        public const uint EC_NOTIFY_WINDOW = 0x19;

        public const uint EC_STREAM_CONTROL_STOPPED = 0x1A;

        public const uint EC_STREAM_CONTROL_STARTED = 0x1B;

        public const uint EC_END_OF_SEGMENT = 0x1C;

        public const uint EC_SEGMENT_STARTED = 0x1D;

        public const uint EC_LENGTH_CHANGED = 0x1E;

        public const uint EC_DEVICE_LOST = 0x1f;

        public const uint EC_SAMPLE_NEEDED = 0x20;

        public const uint EC_PROCESSING_LATENCY = 0x21;

        public const uint EC_SAMPLE_LATENCY = 0x22;

        public const uint EC_SCRUB_TIME = 0x23;

        public const uint EC_STEP_COMPLETE = 0x24;

        public const uint EC_TIMECODE_AVAILABLE = 0x30;

        public const uint EC_EXTDEVICE_MODE_CHANGE = 0x31;

        public const uint EC_STATE_CHANGE = 0x32;

        public const uint EC_GRAPH_CHANGED = 0x50;

        public const uint EC_CLOCK_UNSET = 0x51;

        public const uint EC_VMR_RENDERDEVICE_SET = 0x53;

        public const uint VMR_RENDER_DEVICE_OVERLAY = 0x01;

        public const uint VMR_RENDER_DEVICE_VIDMEM = 0x02;

        public const uint VMR_RENDER_DEVICE_SYSMEM = 0x04;

        public const uint EC_VMR_SURFACE_FLIPPED = 0x54;

        public const uint EC_VMR_RECONNECTION_FAILED = 0x55;

        public const uint EC_PREPROCESS_COMPLETE = 0x56;

        public const uint EC_CODECAPI_EVENT = 0x57;

        public const uint EC_WMT_EVENT_BASE = 0x0251;

        public const uint EC_WMT_EVENT = EC_WMT_EVENT_BASE+1;

        public const uint EC_BUILT = 0x300;

        public const uint EC_UNBUILT = 0x301;

        public const uint EC_SKIP_FRAMES = 0x25;

        public const uint EC_PLEASE_REOPEN = 0x40;

        public const uint EC_STATUS = 0x41;

        public const uint EC_MARKER_HIT = 0x42;

        public const uint EC_LOADSTATUS = 0x43;

        public const uint EC_FILE_CLOSED = 0x44;

        public const uint EC_ERRORABORTEX = 0x45;

        public const uint AM_LOADSTATUS_CLOSED = 0x0000;

        public const uint AM_LOADSTATUS_LOADINGDESCR = 0x0001;

        public const uint AM_LOADSTATUS_LOADINGMCAST = 0x0002;

        public const uint AM_LOADSTATUS_LOCATING = 0x0003;

        public const uint AM_LOADSTATUS_CONNECTING = 0x0004;

        public const uint AM_LOADSTATUS_OPENING = 0x0005;

        public const uint AM_LOADSTATUS_OPEN = 0x0006;

        public const uint EC_NEW_PIN = 0x20;

        public const uint EC_RENDER_FINISHED = 0x21;

        public const uint EC_EOS_SOON = 0x046;

        public const uint EC_CONTENTPROPERTY_CHANGED = 0x47;

        public const uint AM_CONTENTPROPERTY_TITLE = 0x0001;

        public const uint AM_CONTENTPROPERTY_AUTHOR = 0x0002;

        public const uint AM_CONTENTPROPERTY_COPYRIGHT = 0x0004;

        public const uint AM_CONTENTPROPERTY_DESCRIPTION = 0x0008;

        public const uint EC_BANDWIDTHCHANGE = 0x48;

        public const uint EC_VIDEOFRAMEREADY = 0x49;

        public const uint EC_DVDBASE = 0x0100;

        public const uint EC_DVD_DOMAIN_CHANGE = EC_DVDBASE + 0x01;

        public const uint EC_DVD_TITLE_CHANGE = EC_DVDBASE + 0x02;

        public const uint EC_DVD_CHAPTER_START = EC_DVDBASE + 0x03;

        public const uint EC_DVD_AUDIO_STREAM_CHANGE = EC_DVDBASE + 0x04;

        public const uint EC_DVD_SUBPICTURE_STREAM_CHANGE = EC_DVDBASE + 0x05;

        public const uint EC_DVD_ANGLE_CHANGE = EC_DVDBASE + 0x06;

        public const uint EC_DVD_BUTTON_CHANGE = EC_DVDBASE + 0x07;

        public const uint EC_DVD_VALID_UOPS_CHANGE = EC_DVDBASE + 0x08;

        public const uint EC_DVD_STILL_ON = EC_DVDBASE + 0x09;

        public const uint EC_DVD_STILL_OFF = EC_DVDBASE + 0x0a;

        public const uint EC_DVD_CURRENT_TIME = EC_DVDBASE + 0x0b;

        public const uint EC_DVD_ERROR = EC_DVDBASE + 0x0c;

        public const uint EC_DVD_WARNING = EC_DVDBASE + 0x0d;

        public const uint EC_DVD_CHAPTER_AUTOSTOP = EC_DVDBASE + 0x0e;

        public const uint EC_DVD_NO_FP_PGC = EC_DVDBASE + 0x0f;

        public const uint EC_DVD_PLAYBACK_RATE_CHANGE = EC_DVDBASE + 0x10;

        public const uint EC_DVD_PARENTAL_LEVEL_CHANGE = EC_DVDBASE + 0x11;

        public const uint EC_DVD_PLAYBACK_STOPPED = EC_DVDBASE + 0x12;

        public const uint EC_DVD_ANGLES_AVAILABLE = EC_DVDBASE + 0x13;

        public const uint EC_DVD_PLAYPERIOD_AUTOSTOP = EC_DVDBASE + 0x14;

        public const uint EC_DVD_BUTTON_AUTO_ACTIVATED = EC_DVDBASE + 0x15;

        public const uint EC_DVD_CMD_START = EC_DVDBASE + 0x16;

        public const uint EC_DVD_CMD_END = EC_DVDBASE + 0x17;

        public const uint EC_DVD_DISC_EJECTED = EC_DVDBASE + 0x18;

        public const uint EC_DVD_DISC_INSERTED = EC_DVDBASE + 0x19;

        public const uint EC_DVD_CURRENT_HMSF_TIME = EC_DVDBASE + 0x1a;

        public const uint EC_DVD_KARAOKE_MODE = EC_DVDBASE + 0x1b;

        public const uint EC_DVD_PROGRAM_CELL_CHANGE = EC_DVDBASE + 0x1c;

        public const uint EC_DVD_TITLE_SET_CHANGE = EC_DVDBASE + 0x1d;

        public const uint EC_DVD_PROGRAM_CHAIN_CHANGE = EC_DVDBASE + 0x1e;

        public const uint EC_DVD_VOBU_Offset = EC_DVDBASE + 0x1f;

        public const uint EC_DVD_VOBU_Timestamp = EC_DVDBASE + 0x20;

        public const uint EC_DVD_GPRM_Change = EC_DVDBASE + 0x21;

        public const uint EC_DVD_SPRM_Change = EC_DVDBASE + 0x22;

        public const uint EC_DVD_BeginNavigationCommands = EC_DVDBASE + 0x23;

        public const uint EC_DVD_NavigationCommand = EC_DVDBASE + 0x24;

        public const uint AM_AC3_ALTERNATE_AUDIO_1 = 1;

        public const uint AM_AC3_ALTERNATE_AUDIO_2 = 2;

        public const uint AM_AC3_ALTERNATE_AUDIO_BOTH = 3;

        public const uint AM_AC3_SERVICE_MAIN_AUDIO = 0;

        public const uint AM_AC3_SERVICE_NO_DIALOG = 1;

        public const uint AM_AC3_SERVICE_VISUALLY_IMPAIRED = 2;

        public const uint AM_AC3_SERVICE_HEARING_IMPAIRED = 3;

        public const uint AM_AC3_SERVICE_DIALOG_ONLY = 4;

        public const uint AM_AC3_SERVICE_COMMENTARY = 5;

        public const uint AM_AC3_SERVICE_EMERGENCY_FLASH = 6;

        public const uint AM_AC3_SERVICE_VOICE_OVER = 7;

        public const uint AM_UseNewCSSKey = 0x1;

        public const uint AM_ReverseBlockStart = 0x2;

        public const uint AM_ReverseBlockEnd = 0x4;

        public const uint AM_DVD_CGMS_RESERVED_MASK = 0x00000078;

        public const uint AM_DVD_CGMS_COPY_PROTECT_MASK = 0x00000018;

        public const uint AM_DVD_CGMS_COPY_PERMITTED = 0x00000000;

        public const uint AM_DVD_CGMS_COPY_ONCE = 0x00000010;

        public const uint AM_DVD_CGMS_NO_COPY = 0x00000018;

        public const uint AM_DVD_COPYRIGHT_MASK = 0x00000040;

        public const uint AM_DVD_NOT_COPYRIGHTED = 0x00000000;

        public const uint AM_DVD_COPYRIGHTED = 0x00000040;

        public const uint AM_DVD_SECTOR_PROTECT_MASK = 0x00000020;

        public const uint AM_DVD_SECTOR_NOT_PROTECTED = 0x00000000;

        public const uint AM_DVD_SECTOR_PROTECTED = 0x00000020;

        public const uint AMINTERLACE_IsInterlaced = 0x00000001;

        public const uint AMINTERLACE_1FieldPerSample = 0x00000002;

        public const uint AMINTERLACE_Field1First = 0x00000004;

        public const uint AMINTERLACE_UNUSED = 0x00000008;

        public const uint AMINTERLACE_FieldPatternMask = 0x00000030;

        public const uint AMINTERLACE_FieldPatField1Only = 0x00000000;

        public const uint AMINTERLACE_FieldPatField2Only = 0x00000010;

        public const uint AMINTERLACE_FieldPatBothRegular = 0x00000020;

        public const uint AMINTERLACE_FieldPatBothIrregular = 0x00000030;

        public const uint AMINTERLACE_DisplayModeMask = 0x000000c0;

        public const uint AMINTERLACE_DisplayModeBobOnly = 0x00000000;

        public const uint AMINTERLACE_DisplayModeWeaveOnly = 0x00000040;

        public const uint AMINTERLACE_DisplayModeBobOrWeave = 0x00000080;

        public const uint AMCOPYPROTECT_RestrictDuplication = 0x00000001;

        public const uint AMCONTROL_USED = 0x00000001;

        public const uint AMCONTROL_PAD_TO_4x3 = 0x00000002;

        public const uint AMCONTROL_PAD_TO_16x9 = 0x00000004;

        public const uint AMCONTROL_COLORINFO_PRESENT = 0x00000080;

        public const int AM_VIDEO_FLAG_FIELD_MASK = 0x0003;

        public const int AM_VIDEO_FLAG_INTERLEAVED_FRAME = 0x0000;

        public const int AM_VIDEO_FLAG_FIELD1 = 0x0001;

        public const int AM_VIDEO_FLAG_FIELD2 = 0x0002;

        public const int AM_VIDEO_FLAG_FIELD1FIRST = 0x0004;

        public const int AM_VIDEO_FLAG_WEAVE = 0x0008;

        public const int AM_VIDEO_FLAG_IPB_MASK = 0x0030;

        public const int AM_VIDEO_FLAG_I_SAMPLE = 0x0000;

        public const int AM_VIDEO_FLAG_P_SAMPLE = 0x0010;

        public const int AM_VIDEO_FLAG_B_SAMPLE = 0x0020;

        public const int AM_VIDEO_FLAG_REPEAT_FIELD = 0x0040;

        public const uint AVIF_HASINDEX = 0x00000010;

        public const uint AVIF_MUSTUSEINDEX = 0x00000020;

        public const uint AVIF_ISINTERLEAVED = 0x00000100;

        public const uint AVIF_TRUSTCKTYPE = 0x00000800;

        public const uint AVIF_WASCAPTUREFILE = 0x00010000;

        public const uint AVIF_COPYRIGHTED = 0x00020000;

        public const uint AVI_HEADERSIZE = 2048;

        public const uint AVISF_DISABLED = 0x00000001;

        public const uint AVISF_VIDEO_PALCHANGES = 0x00010000;

        public const int AVIIF_LIST = 0x00000001;

        public const int AVIIF_KEYFRAME = 0x00000010;

        public const int AVIIF_FIRSTPART = 0x00000020;

        public const int AVIIF_LASTPART = 0x00000040;

        public const int AVIIF_NOTIME = 0x00000100;

        public const int AVIIF_COMPUSE = 0x0FFF0000;

        public const uint TIMECODE_RATE_30DROP = 0;

        public const uint TIMECODE_SMPTE_BINARY_GROUP = 0x07;

        public const uint TIMECODE_SMPTE_COLOR_FRAME = 0x08;

        public const uint AVI_INDEX_OF_INDEXES = 0x00;

        public const uint AVI_INDEX_OF_CHUNKS = 0x01;

        public const uint AVI_INDEX_OF_TIMED_CHUNKS = 0x02;

        public const uint AVI_INDEX_OF_SUB_2FIELD = 0x03;

        public const uint AVI_INDEX_IS_DATA = 0x80;

        public const uint AVI_INDEX_SUB_DEFAULT = 0x00;

        public const uint AVI_INDEX_SUB_2FIELD = 0x01;

        public const uint STDINDEXSIZE = 0x4000;

        public const uint AVISTDINDEX_DELTAFRAME = 0x80000000;

        public const uint AllocatorStrategy_DontCare = 0;

        public const uint AllocatorStrategy_MinimizeNumberOfFrames = 0x00000001;

        public const uint AllocatorStrategy_MinimizeFrameSize = 0x00000002;

        public const uint AllocatorStrategy_MinimizeNumberOfAllocators = 0x00000004;

        public const uint AllocatorStrategy_MaximizeSpeed = 0x00000008;

        public const uint PipeFactor_None = 0;

        public const uint PipeFactor_UserModeUpstream = 0x00000001;

        public const uint PipeFactor_UserModeDownstream = 0x00000002;

        public const uint PipeFactor_MemoryTypes = 0x00000004;

        public const uint PipeFactor_Flags = 0x00000008;

        public const uint PipeFactor_PhysicalRanges = 0x00000010;

        public const uint PipeFactor_OptimalRanges = 0x00000020;

        public const uint PipeFactor_FixedCompression = 0x00000040;

        public const uint PipeFactor_UnknownCompression = 0x00000080;

        public const uint PipeFactor_Buffers = 0x00000100;

        public const uint PipeFactor_Align = 0x00000200;

        public const uint PipeFactor_PhysicalEnd = 0x00000400;

        public const uint PipeFactor_LogicalEnd = 0x00000800;

        public static readonly Guid CLSID_Proxy__scanned__ = new Guid(STATIC_CLSID_Proxy);

        public const uint AMVA_TYPEINDEX_OUTPUTFRAME = 0xFFFFFFFF;

        public const uint AMVA_QUERYRENDERSTATUSF_READ = 0x00000001;

        public const uint MIN_DIMENSION = 1;

        public const int BDA_PLP_ID_NOT_SET = -1;

        public const uint CDEF_CLASS_DEFAULT = 0x0001;

        public const uint CDEF_BYPASS_CLASS_MANAGER = 0x0002;

        public const uint CDEF_MERIT_ABOVE_DO_NOT_USE = 0x0008;

        public const uint CDEF_DEVMON_CMGR_DEVICE = 0x0010;

        public const uint CDEF_DEVMON_DMO = 0x0020;

        public const uint CDEF_DEVMON_PNP_DEVICE = 0x0040;

        public const uint CDEF_DEVMON_FILTER = 0x0080;

        public const uint CDEF_DEVMON_SELECTIVE_MASK = 0x00f0;

        public const uint CHARS_IN_GUID = 39;

        public const uint MAX_PIN_NAME = 128;

        public const uint MAX_FILTER_NAME = 128;

        public const uint AM_GBF_PREVFRAMESKIPPED = 1;

        public const uint AM_GBF_NOTASYNCPOINT = 2;

        public const uint AM_GBF_NOWAIT = 4;

        public const uint AM_GBF_NODDSURFACELOCK = 8;

        public const double AMF_AUTOMATICGAIN = -1.0;

        public const uint AnalogVideo_NTSC_Mask = 0x00000007;

        public const uint AnalogVideo_PAL_Mask = 0x00100FF0;

        public const uint AnalogVideo_SECAM_Mask = 0x000FF000;

        public const uint MPEG2_PROGRAM_STREAM_MAP = 0x00000000;

        public const uint MPEG2_PROGRAM_ELEMENTARY_STREAM = 0x00000001;

        public const uint MPEG2_PROGRAM_DIRECTORY_PES_PACKET = 0x00000002;

        public const uint MPEG2_PROGRAM_PACK_HEADER = 0x00000003;

        public const uint MPEG2_PROGRAM_PES_STREAM = 0x00000004;

        public const uint MPEG2_PROGRAM_SYSTEM_HEADER = 0x00000005;

        public const uint SUBSTREAM_FILTER_VAL_NONE = 0x10000000;

        public const uint AM_GETDECODERCAP_QUERY_VMR_SUPPORT = 0x00000001;

        public const uint VMR_NOTSUPPORTED = 0x00000000;

        public const uint VMR_SUPPORTED = 0x00000001;

        public const uint AM_QUERY_DECODER_VMR_SUPPORT = 0x00000001;

        public const uint AM_QUERY_DECODER_DXVA_1_SUPPORT = 0x00000002;

        public const uint AM_QUERY_DECODER_DVD_SUPPORT = 0x00000003;

        public const uint AM_QUERY_DECODER_ATSC_SD_SUPPORT = 0x00000004;

        public const uint AM_QUERY_DECODER_ATSC_HD_SUPPORT = 0x00000005;

        public const uint AM_GETDECODERCAP_QUERY_VMR9_SUPPORT = 0x00000006;

        public const uint AM_GETDECODERCAP_QUERY_EVR_SUPPORT = 0x00000007;

        public const uint DECODER_CAP_NOTSUPPORTED = 0x00000000;

        public const uint DECODER_CAP_SUPPORTED = 0x00000001;

        public const uint VMRBITMAP_DISABLE = 0x00000001;

        public const uint VMRBITMAP_HDC = 0x00000002;

        public const uint VMRBITMAP_ENTIREDDS = 0x00000004;

        public const uint VMRBITMAP_SRCCOLORKEY = 0x00000008;

        public const uint VMRBITMAP_SRCRECT = 0x00000010;

        public const uint DVD_TITLE_MENU = 0x000;

        public const uint DVD_STREAM_DATA_CURRENT = 0x800;

        public const uint DVD_STREAM_DATA_VMGM = 0x400;

        public const uint DVD_STREAM_DATA_VTSM = 0x401;

        public const uint DVD_DEFAULT_AUDIO_STREAM = 0x0f;

        public const uint DVD_AUDIO_CAPS_AC3 = 0x00000001;

        public const uint DVD_AUDIO_CAPS_MPEG2 = 0x00000002;

        public const uint DVD_AUDIO_CAPS_LPCM = 0x00000004;

        public const uint DVD_AUDIO_CAPS_DTS = 0x00000008;

        public const uint DVD_AUDIO_CAPS_SDDS = 0x00000010;

        public static readonly Guid MEDIATYPE_CONTROL__scanned__ = new Guid(0xe06d8021, 0xdb46, 0x11cf, 0xb4, 0xd1, 0x00, 0x80, 0x05f, 0x6c, 0xbb, 0xea);

        public static readonly Guid PBDA_AUX_CONNECTOR_TYPE_SVideo__scanned__ = new Guid(0xa0e905f4,0x24c9,0x4a54, 0xb7, 0x61, 0x21, 0x33, 0x55, 0xef, 0xc1, 0x3A);

        public static readonly Guid PBDA_AUX_CONNECTOR_TYPE_Composite__scanned__ = new Guid(0xf6298b4c,0xc725,0x4d42, 0x84, 0x9b, 0x41, 0x0b, 0xbb, 0x14, 0xea, 0x62);

        public static readonly Guid CLSID_PBDA_AUX_DATA_TYPE__scanned__ = new Guid(0xfd456373, 0x3323, 0x4090, 0xad, 0xca, 0x8e, 0xd4, 0x5f, 0x55, 0xcf, 0x10);

        public static readonly Guid CLSID_PBDA_Encoder_DATA_TYPE__scanned__ = new Guid(0x728fd6bc, 0x5546, 0x4716, 0xb1, 0x03, 0xf8, 0x99, 0xf5, 0xa1, 0xfa, 0x68);

        public const uint PBDA_Encoder_Audio_AlgorithmType_MPEG1LayerII = 0x00000000;

        public const uint PBDA_Encoder_Audio_AlgorithmType_AC3 = 0x00000001;

        public const uint PBDA_Encoder_Video_MPEG2PartII = 0x00000000;

        public const uint PBDA_Encoder_Video_MPEG4Part10 = 0x00000001;

        public const uint PBDA_Encoder_Video_AVC = 0x00000001;

        public const uint PBDA_Encoder_Video_H264 = 0x00000001;

        public const uint PBDA_Encoder_BitrateMode_Constant = 0x00000001;

        public const uint PBDA_Encoder_BitrateMode_Variable = 0x00000002;

        public const uint PBDA_Encoder_BitrateMode_Average = 0x00000003;

        public static readonly Guid CLSID_PBDA_FDC_DATA_TYPE__scanned__ = new Guid(0xe7dbf9a0, 0x22ab, 0x4047, 0x8e, 0x67, 0xef, 0x9a, 0xd5, 0x4, 0xe7, 0x29);

        public static readonly Guid CLSID_PBDA_GDDS_DATA_TYPE__scanned__ = new Guid(0xC80C0DF3, 0x6052, 0x4c16, 0x9F, 0x56, 0xC4, 0x4C, 0x21, 0xF7, 0x3C, 0x45);

        public static readonly Guid CLSID_BroadcastEventService__scanned__ = new Guid(0x0B3FFB92, 0x0919, 0x4934, 0x9D, 0x5B, 0x61, 0x9C, 0x71, 0x9D, 0x02, 0x02);

        public static readonly Guid LIBID_QuartzNetTypeLib__scanned__ = new Guid(0x56A868B1L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

        public static readonly Guid IID_IAMNetShowConfig__scanned__ = new Guid(0xFA2AA8F1L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

        public static readonly Guid IID_IAMChannelInfo__scanned__ = new Guid(0xFA2AA8F2L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

        public static readonly Guid IID_IAMNetworkStatus__scanned__ = new Guid(0xFA2AA8F3L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

        public static readonly Guid IID_IAMExtendedSeeking__scanned__ = new Guid(0xFA2AA8F9L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

        public static readonly Guid IID_IAMNetShowExProps__scanned__ = new Guid(0xFA2AA8F5L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

        public static readonly Guid IID_IAMExtendedErrorInfo__scanned__ = new Guid(0xFA2AA8F6L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

        public static readonly Guid IID_IAMMediaContent__scanned__ = new Guid(0xFA2AA8F4L,0x8B62,0x11D0,0xA5,0x20,0x00,0x00,0x00,0x00,0x00,0x00);

        public static readonly Guid IID_IAMMediaContent2__scanned__ = new Guid(0xCE8F78C1L,0x74D9,0x11D2,0xB0,0x9D,0x00,0xA0,0xC9,0xA8,0x11,0x17);

        public static readonly Guid IID_IAMNetShowPreroll__scanned__ = new Guid(0xAAE7E4E2L,0x6388,0x11D1,0x8D,0x93,0x00,0x60,0x97,0xC9,0xA2,0xB2);

        public static readonly Guid IID_IDShowPlugin__scanned__ = new Guid(0x4746B7C8L,0x700E,0x11D1,0xBE,0xCC,0x00,0xC0,0x4F,0xB6,0xE9,0x37);

        public static readonly Guid IID_IAMParse__scanned__ = new Guid(0xc47a3420, 0x005c, 0x11d2, 0x90, 0x38, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x98);

        public static readonly Guid LIBID_QuartzTypeLib__scanned__ = new Guid(0x56a868b0,0x0ad4,0x11ce,0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70);

        public static readonly Guid CLSID_FilgraphManager__scanned__ = new Guid(0xe436ebb3,0x524f,0x11ce,0x9f,0x53,0x00,0x20,0xaf,0x0b,0xa7,0x70);

        public static readonly Guid CLSID_AMMultiMediaStream__scanned__ = new Guid(0x49c47ce5, 0x9ba4, 0x11d0, 0x82, 0x12, 0x00, 0xc0, 0x4f, 0xc3, 0x2c, 0x45);

        public static readonly Guid CLSID_AMDirectDrawStream__scanned__ = new Guid(0x49c47ce4, 0x9ba4, 0x11d0, 0x82, 0x12, 0x00, 0xc0, 0x4f, 0xc3, 0x2c, 0x45);

        public static readonly Guid CLSID_AMAudioStream__scanned__ = new Guid(0x8496e040, 0xaf4c, 0x11d0, 0x82, 0x12, 0x00, 0xc0, 0x4f, 0xc3, 0x2c, 0x45);

        public static readonly Guid CLSID_AMAudioData__scanned__ = new Guid(0xf2468580, 0xaf8a, 0x11d0, 0x82, 0x12, 0x00, 0xc0, 0x4f, 0xc3, 0x2c, 0x45);

        public static readonly Guid CLSID_AMMediaTypeStream__scanned__ = new Guid(0xcf0f2f7c, 0xf7bf, 0x11d0, 0x90, 0xd, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0x9d);

        public const uint AMDDS_NONE = 0x00;

        public const uint AMDDS_DCIPS = 0x01;

        public const uint AMDDS_PS = 0x02;

        public const uint AMDDS_RGBOVR = 0x04;

        public const uint AMDDS_YUVOVR = 0x08;

        public const uint AMDDS_RGBOFF = 0x10;

        public const uint AMDDS_YUVOFF = 0x20;

        public const uint AMDDS_RGBFLP = 0x40;

        public const uint AMDDS_YUVFLP = 0x80;

        public const uint AMDDS_ALL = 0xFF;

        public const uint MAX_SIZE_MPEG1_SEQUENCE_INFO = 140;

        public static readonly Guid CLSID_DMOWrapperFilter__scanned__ = new Guid(0x94297043,0xbd82,0x4dfd,0xb0,0xde,0x81,0x77,0x73,0x9c,0x6d,0x20);

        public static readonly Guid CLSID_DMOFilterCategory__scanned__ = new Guid(0xbcd5796c,0xbd52,0x4d30,0xab,0x76,0x70,0xf9,0x75,0xb8,0x91,0x99);

        public const uint AM_MPEG_AUDIO_DUAL_MERGE = 0;

        public const uint AM_MPEG_AUDIO_DUAL_LEFT = 1;

        public const uint AM_MPEG_AUDIO_DUAL_RIGHT = 2;

        public static readonly Guid IID_IXMLGraphBuilder__scanned__ = new Guid(0x1bb05960, 0x5fbf, 0x11d2, 0xa5, 0x21, 0x44, 0xdf, 0x7, 0xc1, 0x0, 0x0);

        public static readonly Guid CLSID_XMLGraphBuilder__scanned__ = new Guid(0x1bb05961, 0x5fbf, 0x11d2, 0xa5, 0x21, 0x44, 0xdf, 0x7, 0xc1, 0x0, 0x0);

        public const uint VFW_FIRST_CODE = 0x200;

        public const uint MAX_ERROR_TEXT_LEN = 160;

        public const uint MPBOOL_TRUE = 1;

        public const uint MPBOOL_FALSE = 0;

        public const int DWORD_ALLPARAMS = -1;

        public static readonly Guid GUID_TIME_REFERENCE__scanned__ = new Guid(0x93ad712b, 0xdaa0, 0x4ffe, 0xbc, 0x81, 0xb0, 0xce, 0x50, 0xf, 0xcd, 0xd9);

        public static readonly Guid GUID_TIME_MUSIC__scanned__ = new Guid(0x574c49d, 0x5b04, 0x4b15, 0xa5, 0x42, 0xae, 0x28, 0x20, 0x30, 0x11, 0x7b);

        public static readonly Guid GUID_TIME_SAMPLES__scanned__ = new Guid(0xa8593d05, 0xc43, 0x4984, 0x9a, 0x63, 0x97, 0xaf, 0x9e, 0x2, 0xc4, 0xc0);

        public const uint MPF_ENVLP_STANDARD = 0;

        public const uint MPF_ENVLP_BEGIN_CURRENTVAL = 0x1;

        public const uint MPF_ENVLP_BEGIN_NEUTRALVAL = 0x2;

        public const uint MPF_PUNCHIN_REFTIME = 0;

        public const uint MPF_PUNCHIN_NOW = 0x1;

        public const uint MPF_PUNCHIN_STOPPED = 0x2;

        public static readonly Guid DMOCATEGORY_AUDIO_DECODER__scanned__ = new Guid(0x57f2db8b,0xe6bb,0x4513,0x9d,0x43,0xdc,0xd2,0xa6,0x59,0x31,0x25);

        public static readonly Guid DMOCATEGORY_AUDIO_ENCODER__scanned__ = new Guid(0x33D9A761,0x90C8,0x11d0,0xBD,0x43,0x00,0xA0,0xC9,0x11,0xCE,0x86);

        public static readonly Guid DMOCATEGORY_VIDEO_DECODER__scanned__ = new Guid(0x4a69b442,0x28be,0x4991,0x96,0x9c,0xb5,0x00,0xad,0xf5,0xd8,0xa8);

        public static readonly Guid DMOCATEGORY_VIDEO_ENCODER__scanned__ = new Guid(0x33D9A760,0x90C8,0x11d0,0xBD,0x43,0x00,0xA0,0xC9,0x11,0xCE,0x86);

        public static readonly Guid DMOCATEGORY_AUDIO_EFFECT__scanned__ = new Guid(0xf3602b3f,0x0592,0x48df,0xa4,0xcd,0x67,0x47,0x21,0xe7,0xeb,0xeb);

        public static readonly Guid DMOCATEGORY_VIDEO_EFFECT__scanned__ = new Guid(0xd990ee14,0x776c,0x4723,0xbe,0x46,0x3d,0xa2,0xf5,0x6f,0x10,0xb9);

        public static readonly Guid DMOCATEGORY_AUDIO_CAPTURE_EFFECT__scanned__ = new Guid(0xf665aaba,0x3e09,0x4920,0xaa,0x5f,0x21,0x98,0x11,0x14,0x8f,0x09);

        public static readonly Guid DMOCATEGORY_ACOUSTIC_ECHO_CANCEL__scanned__ = new Guid(0xBF963D80L, 0xC559, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1);

        public static readonly Guid DMOCATEGORY_AUDIO_NOISE_SUPPRESS__scanned__ = new Guid(0xe07f903f, 0x62fd, 0x4e60, 0x8c, 0xdd, 0xde, 0xa7, 0x23, 0x66, 0x65, 0xb5);

        public static readonly Guid DMOCATEGORY_AGC__scanned__ = new Guid(0xE88C9BA0L, 0xC557, 0x11D0, 0x8A, 0x2B, 0x00, 0xA0, 0xC9, 0x25, 0x5A, 0xC1);

        public static readonly Guid MSPID_PrimaryVideo__scanned__ = new Guid(0xa35ff56a, 0x9fda, 0x11d0, 0x8f, 0xdf, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0x9d);

        public static readonly Guid MSPID_PrimaryAudio__scanned__ = new Guid(0xa35ff56b, 0x9fda, 0x11d0, 0x8f, 0xdf, 0x0, 0xc0, 0x4f, 0xd9, 0x18, 0x9d);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALIDMEDIATYPE = unchecked((int)0x80040200);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALIDSUBTYPE = unchecked((int)0x80040201);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NEED_OWNER = unchecked((int)0x80040202);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_ENUM_OUT_OF_SYNC = unchecked((int)0x80040203);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_ALREADY_CONNECTED = unchecked((int)0x80040204);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_FILTER_ACTIVE = unchecked((int)0x80040205);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_TYPES = unchecked((int)0x80040206);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_ACCEPTABLE_TYPES = unchecked((int)0x80040207);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALID_DIRECTION = unchecked((int)0x80040208);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_CONNECTED = unchecked((int)0x80040209);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_ALLOCATOR = unchecked((int)0x8004020A);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_RUNTIME_ERROR = unchecked((int)0x8004020B);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_BUFFER_NOTSET = unchecked((int)0x8004020C);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_BUFFER_OVERFLOW = unchecked((int)0x8004020D);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_BADALIGN = unchecked((int)0x8004020E);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_ALREADY_COMMITTED = unchecked((int)0x8004020F);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_BUFFERS_OUTSTANDING = unchecked((int)0x80040210);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_COMMITTED = unchecked((int)0x80040211);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_SIZENOTSET = unchecked((int)0x80040212);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_CLOCK = unchecked((int)0x80040213);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_SINK = unchecked((int)0x80040214);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_INTERFACE = unchecked((int)0x80040215);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_FOUND = unchecked((int)0x80040216);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CANNOT_CONNECT = unchecked((int)0x80040217);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CANNOT_RENDER = unchecked((int)0x80040218);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CHANGING_FORMAT = unchecked((int)0x80040219);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_COLOR_KEY_SET = unchecked((int)0x8004021A);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_OVERLAY_CONNECTION = unchecked((int)0x8004021B);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_SAMPLE_CONNECTION = unchecked((int)0x8004021C);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_PALETTE_SET = unchecked((int)0x8004021D);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_COLOR_KEY_SET = unchecked((int)0x8004021E);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_COLOR_KEY_FOUND = unchecked((int)0x8004021F);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_PALETTE_AVAILABLE = unchecked((int)0x80040220);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_DISPLAY_PALETTE = unchecked((int)0x80040221);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_TOO_MANY_COLORS = unchecked((int)0x80040222);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_STATE_CHANGED = unchecked((int)0x80040223);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_STOPPED = unchecked((int)0x80040224);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_PAUSED = unchecked((int)0x80040225);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_RUNNING = unchecked((int)0x80040226);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_WRONG_STATE = unchecked((int)0x80040227);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_START_TIME_AFTER_END = unchecked((int)0x80040228);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALID_RECT = unchecked((int)0x80040229);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_TYPE_NOT_ACCEPTED = unchecked((int)0x8004022A);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_SAMPLE_REJECTED = unchecked((int)0x8004022B);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_SAMPLE_REJECTED_EOS = unchecked((int)0x8004022C);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DUPLICATE_NAME = unchecked((int)0x8004022D);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_DUPLICATE_NAME = 0x0004022D;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_TIMEOUT = unchecked((int)0x8004022E);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALID_FILE_FORMAT = unchecked((int)0x8004022F);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_ENUM_OUT_OF_RANGE = unchecked((int)0x80040230);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CIRCULAR_GRAPH = unchecked((int)0x80040231);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_ALLOWED_TO_SAVE = unchecked((int)0x80040232);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_TIME_ALREADY_PASSED = unchecked((int)0x80040233);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_ALREADY_CANCELLED = unchecked((int)0x80040234);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CORRUPT_GRAPH_FILE = unchecked((int)0x80040235);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_ADVISE_ALREADY_SET = unchecked((int)0x80040236);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_STATE_INTERMEDIATE = 0x00040237;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_MODEX_AVAILABLE = unchecked((int)0x80040238);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_ADVISE_SET = unchecked((int)0x80040239);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_FULLSCREEN = unchecked((int)0x8004023A);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_IN_FULLSCREEN_MODE = unchecked((int)0x8004023B);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_UNKNOWN_FILE_TYPE = unchecked((int)0x80040240);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CANNOT_LOAD_SOURCE_FILTER = unchecked((int)0x80040241);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_PARTIAL_RENDER = 0x00040242;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_FILE_TOO_SHORT = unchecked((int)0x80040243);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALID_FILE_VERSION = unchecked((int)0x80040244);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_SOME_DATA_IGNORED = 0x00040245;

        [NativeTypeName("HRESULT")]
        public const int VFW_S_CONNECTIONS_DEFERRED = 0x00040246;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALID_CLSID = unchecked((int)0x80040247);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_INVALID_MEDIA_TYPE = unchecked((int)0x80040248);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_BAD_KEY = unchecked((int)0x800403F2);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_NO_MORE_ITEMS = 0x00040103;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_SAMPLE_TIME_NOT_SET = unchecked((int)0x80040249);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_RESOURCE_NOT_NEEDED = 0x00040250;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_MEDIA_TIME_NOT_SET = unchecked((int)0x80040251);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_TIME_FORMAT_SET = unchecked((int)0x80040252);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_MONO_AUDIO_HW = unchecked((int)0x80040253);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_MEDIA_TYPE_IGNORED = 0x00040254;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_DECOMPRESSOR = unchecked((int)0x80040255);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_AUDIO_HARDWARE = unchecked((int)0x80040256);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_VIDEO_NOT_RENDERED = 0x00040257;

        [NativeTypeName("HRESULT")]
        public const int VFW_S_AUDIO_NOT_RENDERED = 0x00040258;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_RPZA = unchecked((int)0x80040259);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_RPZA = 0x0004025A;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_PROCESSOR_NOT_SUITABLE = unchecked((int)0x8004025B);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_UNSUPPORTED_AUDIO = unchecked((int)0x8004025C);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_UNSUPPORTED_VIDEO = unchecked((int)0x8004025D);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_MPEG_NOT_CONSTRAINED = unchecked((int)0x8004025E);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NOT_IN_GRAPH = unchecked((int)0x8004025F);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_ESTIMATED = 0x00040260;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_TIME_FORMAT = unchecked((int)0x80040261);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_READ_ONLY = unchecked((int)0x80040262);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_RESERVED = 0x00040263;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_BUFFER_UNDERFLOW = unchecked((int)0x80040264);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_UNSUPPORTED_STREAM = unchecked((int)0x80040265);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_TRANSPORT = unchecked((int)0x80040266);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_STREAM_OFF = 0x00040267;

        [NativeTypeName("HRESULT")]
        public const int VFW_S_CANT_CUE = 0x00040268;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_BAD_VIDEOCD = unchecked((int)0x80040269);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_NO_STOP_TIME = 0x00040270;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_OUT_OF_VIDEO_MEMORY = unchecked((int)0x80040271);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_VP_NEGOTIATION_FAILED = unchecked((int)0x80040272);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DDRAW_CAPS_NOT_SUITABLE = unchecked((int)0x80040273);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_VP_HARDWARE = unchecked((int)0x80040274);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_CAPTURE_HARDWARE = unchecked((int)0x80040275);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_OPERATION_INHIBITED = unchecked((int)0x80040276);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_INVALIDDOMAIN = unchecked((int)0x80040277);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_NO_BUTTON = unchecked((int)0x80040278);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_GRAPHNOTREADY = unchecked((int)0x80040279);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_RENDERFAIL = unchecked((int)0x8004027A);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_DECNOTENOUGH = unchecked((int)0x8004027B);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DDRAW_VERSION_NOT_SUITABLE = unchecked((int)0x8004027C);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_COPYPROT_FAILED = unchecked((int)0x8004027D);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_NOPREVIEWPIN = 0x0004027E;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_TIME_EXPIRED = unchecked((int)0x8004027F);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_DVD_NON_ONE_SEQUENTIAL = 0x00040280;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_WRONG_SPEED = unchecked((int)0x80040281);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_MENU_DOES_NOT_EXIST = unchecked((int)0x80040282);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_CMD_CANCELLED = unchecked((int)0x80040283);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_STATE_WRONG_VERSION = unchecked((int)0x80040284);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_STATE_CORRUPT = unchecked((int)0x80040285);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_STATE_WRONG_DISC = unchecked((int)0x80040286);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_INCOMPATIBLE_REGION = unchecked((int)0x80040287);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_NO_ATTRIBUTES = unchecked((int)0x80040288);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_NO_GOUP_PGC = unchecked((int)0x80040289);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_LOW_PARENTAL_LEVEL = unchecked((int)0x8004028A);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_NOT_IN_KARAOKE_MODE = unchecked((int)0x8004028B);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_DVD_CHANNEL_CONTENTS_NOT_AVAILABLE = 0x0004028C;

        [NativeTypeName("HRESULT")]
        public const int VFW_S_DVD_NOT_ACCURATE = 0x0004028D;

        [NativeTypeName("HRESULT")]
        public const int VFW_E_FRAME_STEP_UNSUPPORTED = unchecked((int)0x8004028E);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_STREAM_DISABLED = unchecked((int)0x8004028F);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_TITLE_UNKNOWN = unchecked((int)0x80040290);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_INVALID_DISC = unchecked((int)0x80040291);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_NO_RESUME_INFORMATION = unchecked((int)0x80040292);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD = unchecked((int)0x80040293);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_PIN_ALREADY_BLOCKED = unchecked((int)0x80040294);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CERTIFICATION_FAILURE = unchecked((int)0x80040295);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_VMR_NOT_IN_MIXER_MODE = unchecked((int)0x80040296);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_VMR_NO_AP_SUPPLIED = unchecked((int)0x80040297);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_VMR_NO_DEINTERLACE_HW = unchecked((int)0x80040298);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_VMR_NO_PROCAMP_HW = unchecked((int)0x80040299);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_VMR9_INCOMPATIBLEDEC = unchecked((int)0x8004029A);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_NO_COPP_HW = unchecked((int)0x8004029B);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_NONBLOCKING = unchecked((int)0x8004029C);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_TOO_MANY_RENDERERS_IN_FILTER_GRAPH = unchecked((int)0x8004029D);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_NON_EVR_RENDERER_IN_FILTER_GRAPH = unchecked((int)0x8004029E);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_RESOLUTION_ERROR = unchecked((int)0x8004029F);

        [NativeTypeName("HRESULT")]
        public const int E_PROP_SET_UNSUPPORTED = unchecked((int)0x80070492);

        [NativeTypeName("HRESULT")]
        public const int E_PROP_ID_UNSUPPORTED = unchecked((int)0x80070490);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CODECAPI_LINEAR_RANGE = unchecked((int)0x80040310);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CODECAPI_ENUMERATED = unchecked((int)0x80040311);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CODECAPI_NO_DEFAULT = unchecked((int)0x80040313);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_CODECAPI_NO_CURRENT_VALUE = unchecked((int)0x80040314);

        [NativeTypeName("HRESULT")]
        public const int VFW_E_DVD_CHAPTER_DOES_NOT_EXIST = unchecked((int)0x80040315);

        [NativeTypeName("HRESULT")]
        public const int VFW_S_DVD_RENDER_STATUS = 0x00040320;

        public const uint DTV_CardStatus_Inserted = 0;

        public const uint DTV_CardStatus_Removed = 1;

        public const uint DTV_CardStatus_Error = 2;

        public const uint DTV_CardStatus_FirmwareDownload = 3;

        public const uint OCUR_PAIRING_PROTOCOL_VERSION = 2;

        public const uint PBDA_PAIRING_PROTOCOL_VERSION = 3;

        public const uint DTV_MMIMessage_Open = 0;

        public const uint DTV_MMIMessage_Close = 1;

        public const uint DTV_Entitlement_CanDecrypt = 0;

        public const uint DTV_Entitlement_NotEntitled = 1;

        public const uint DTV_Entitlement_TechnicalFailure = 2;

        public const uint AudioType_Standard = 0;

        public const uint AudioType_Music_And_Effects = 1;

        public const uint AudioType_Visually_Impaired = 2;

        public const uint AudioType_Hearing_Impaired = 3;

        public const uint AudioType_Dialogue = 4;

        public const uint AudioType_Commentary = 5;

        public const uint AudioType_Emergency = 6;

        public const uint AudioType_Voiceover = 7;

        public const int AudioType_Reserved = -1;

        public const uint MAX_COUNTRY_CODE_STRING = 3;

        public const uint PARENTAL_CONTROL_TIME_RANGE = 0x00000001;

        public const uint REQUIRED_PARENTAL_CONTROL_TIME_RANGE = 0x00000002;

        public const uint PARENTAL_CONTROL_CONTENT_RATING = 0x00000100;

        public const uint PARENTAL_CONTROL_ATTRIB_VIOLENCE = 0x00000200;

        public const uint PARENTAL_CONTROL_ATTRIB_LANGUAGE = 0x00000201;

        public const uint PARENTAL_CONTROL_ATTRIB_SEXUAL = 0x00000202;

        public const uint PARENTAL_CONTROL_ATTRIB_DIALOGUE = 0x00000203;

        public const uint PARENTAL_CONTROL_ATTRIB_FANTASY = 0x00000204;

        public const uint PARENTAL_CONTROL_VALUE_UNDEFINED = 0;

        public const uint MPEG2_FILTER_VERSION_1_SIZE = 124;

        public const uint MPEG2_FILTER_VERSION_2_SIZE = 133;

        public static readonly Guid SID_MSVidCtl_CurrentAudioEndpoint__scanned__ = new Guid(0xcf9a88f4, 0xabcf, 0x4ed8, 0x9b, 0x74, 0x7d, 0xb3, 0x34, 0x45, 0x45, 0x9e);

        public const uint STREAMBUFFER_EC_BASE = 0x0326;

        public static readonly Guid EVENTID_SBE2RecControlStarted__scanned__ = new Guid(0x8966a89e, 0xf83e, 0x4c0e, 0xbc, 0x3b, 0xbf, 0xa7, 0x64, 0x9e, 0x4, 0xcb);

        public static readonly Guid EVENTID_SBE2RecControlStopped__scanned__ = new Guid(0x454b1ec8, 0xc9b, 0x4caa, 0xb1, 0xa1, 0x1e, 0x7a, 0x26, 0x66, 0xf6, 0xc3);

        public static readonly Guid SBE2_STREAM_DESC_EVENT__scanned__ = new Guid(0x2313a4ed, 0xbf2d, 0x454f, 0xad, 0x8a, 0xd9, 0x5b, 0xa7, 0xf9, 0x1f, 0xee);

        public static readonly Guid SBE2_V1_STREAMS_CREATION_EVENT__scanned__ = new Guid(0xfcf09, 0x97f5, 0x46ac, 0x97, 0x69, 0x7a, 0x83, 0xb3, 0x53, 0x84, 0xfb);

        public static readonly Guid SBE2_V2_STREAMS_CREATION_EVENT__scanned__ = new Guid(0xa72530a3, 0x344, 0x4cab, 0xa2, 0xd0, 0xfe, 0x93, 0x7d, 0xbd, 0xca, 0xb3);

        public const uint SBE2_STREAM_DESC_VERSION = 1;

        public static readonly Guid SID_DRMSecureServiceChannel__scanned__ = new Guid(0xC4C4C4C4, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid CLSID_ETFilterEncProperties__scanned__ = new Guid(0xC4C4C481, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid CLSID_ETFilterTagProperties__scanned__ = new Guid(0xC4C4C491, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid CLSID_PTFilter__scanned__ = new Guid(0x9cd31617, 0xb303, 0x4f96, 0x83, 0x30, 0x2e, 0xb1, 0x73, 0xea, 0x4d, 0xc6);

        public static readonly Guid CLSID_DTFilterEncProperties__scanned__ = new Guid(0xC4C4C482, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid CLSID_DTFilterTagProperties__scanned__ = new Guid(0xC4C4C492, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid CLSID_XDSCodecProperties__scanned__ = new Guid(0xC4C4C483, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid CLSID_XDSCodecTagProperties__scanned__ = new Guid(0xC4C4C493, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid CLSID_CPCAFiltersCategory__scanned__ = new Guid(0xC4C4C4FC, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_XDSCodecNewXDSRating__scanned__ = new Guid(0xC4C4C4E0, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_XDSCodecDuplicateXDSRating__scanned__ = new Guid(0xC4C4C4DF, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_XDSCodecNewXDSPacket__scanned__ = new Guid(0xC4C4C4E1, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterRatingChange__scanned__ = new Guid(0xC4C4C4E2, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterRatingsBlock__scanned__ = new Guid(0xC4C4C4E3, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterRatingsUnblock__scanned__ = new Guid(0xC4C4C4E4, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterXDSPacket__scanned__ = new Guid(0xC4C4C4E5, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_ETFilterEncryptionOn__scanned__ = new Guid(0xC4C4C4E6, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_ETFilterEncryptionOff__scanned__ = new Guid(0xC4C4C4E7, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterCOPPUnblock__scanned__ = new Guid(0xC4C4C4E8, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_EncDecFilterError__scanned__ = new Guid(0xC4C4C4E9, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterCOPPBlock__scanned__ = new Guid(0xC4C4C4EA, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_ETFilterCopyOnce__scanned__ = new Guid(0xC4C4C4EB, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_ETFilterCopyNever__scanned__ = new Guid(0xC4C4C4F0, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterDataFormatOK__scanned__ = new Guid(0xC4C4C4EC, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_DTFilterDataFormatFailure__scanned__ = new Guid(0xC4C4C4ED, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_ETDTFilterLicenseOK__scanned__ = new Guid(0xC4C4C4EE, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid EVENTID_ETDTFilterLicenseFailure__scanned__ = new Guid(0xC4C4C4EF, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid MEDIASUBTYPE_ETDTFilter_Tagged__scanned__ = new Guid(0xC4C4C4D0, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid FORMATTYPE_ETDTFilter_Tagged__scanned__ = new Guid(0xC4C4C4D1, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);

        public static readonly Guid MEDIASUBTYPE_CPFilters_Processed__scanned__ = new Guid(0x46adbd28, 0x6fd0, 0x4796, 0x93, 0xb2, 0x15, 0x5c, 0x51, 0xdc, 0x4, 0x8d );

        public static readonly Guid FORMATTYPE_CPFilters_Processed__scanned__ = new Guid(0x6739b36f, 0x1d5f, 0x4ac2, 0x81, 0x92, 0x28, 0xbb, 0xe, 0x73, 0xd1, 0x6a );

        public static readonly Guid EVENTID_EncDecFilterEvent__scanned__ = new Guid(0x4a1b465b, 0xfb9, 0x4159, 0xaf, 0xbd, 0xe3, 0x30, 0x6, 0xa0, 0xf9, 0xf4);

        public static readonly Guid EVENTID_FormatNotSupportedEvent__scanned__ = new Guid(0x24b2280a, 0xb2aa, 0x4777, 0xbf, 0x65, 0x63, 0xf3, 0x5e, 0x7b, 0x2, 0x4a);

        public static readonly Guid EVENTID_DemultiplexerFilterDiscontinuity__scanned__ = new Guid(0x16155770, 0xaed5, 0x475c, 0xbb, 0x98, 0x95, 0xa3, 0x30, 0x70, 0xdf, 0xc);

        public static readonly Guid DSATTRIB_WMDRMProtectionInfo__scanned__ = new Guid(0x40749583, 0x6b9d, 0x4eec, 0xb4, 0x3c, 0x67, 0xa1, 0x80, 0x1e, 0x1a, 0x9b );

        public static readonly Guid DSATTRIB_BadSampleInfo__scanned__ = new Guid(0xe4846dda, 0x5838, 0x42b4, 0xb8, 0x97, 0x6f, 0x7e, 0x5f, 0xaa, 0x2f, 0x2f );

        public const uint MPEG_PAT_PID = 0x0000;

        public const uint MPEG_PAT_TID = 0x00;

        public const uint MPEG_CAT_PID = 0x0001;

        public const uint MPEG_CAT_TID = 0x01;

        public const uint MPEG_PMT_TID = 0x02;

        public const uint MPEG_TSDT_PID = 0x0002;

        public const uint MPEG_TSDT_TID = 0x03;

        public const uint ATSC_MGT_PID = 0x1FFB;

        public const uint ATSC_MGT_TID = 0xC7;

        public const uint ATSC_VCT_PID = 0x1FFB;

        public const uint ATSC_VCT_TERR_TID = 0xC8;

        public const uint ATSC_VCT_CABL_TID = 0xC9;

        public const uint ATSC_EIT_TID = 0xCB;

        public const uint ATSC_ETT_TID = 0xCC;

        public const uint ATSC_RRT_TID = 0xCA;

        public const uint ATSC_RRT_PID = 0x1FFB;

        public const uint ATSC_STT_PID = 0x1FFB;

        public const uint ATSC_STT_TID = 0xCD;

        public const uint ATSC_PIT_TID = 0xD0;

        public const uint DVB_NIT_PID = 0x0010;

        public const uint DVB_NIT_ACTUAL_TID = 0x40;

        public const uint DVB_NIT_OTHER_TID = 0x41;

        public const uint DVB_SDT_PID = 0x0011;

        public const uint DVB_SDT_ACTUAL_TID = 0x42;

        public const uint DVB_SDT_OTHER_TID = 0x46;

        public const uint DVB_BAT_PID = 0x0011;

        public const uint DVB_BAT_TID = 0x4A;

        public const uint DVB_EIT_PID = 0x0012;

        public const uint DVB_EIT_ACTUAL_TID = 0x4E;

        public const uint DVB_EIT_OTHER_TID = 0x4F;

        public const uint DVB_RST_PID = 0x0013;

        public const uint DVB_RST_TID = 0x71;

        public const uint DVB_TDT_PID = 0x0014;

        public const uint DVB_TDT_TID = 0x70;

        public const uint DVB_ST_PID_16 = 0x0010;

        public const uint DVB_ST_PID_17 = 0x0011;

        public const uint DVB_ST_PID_18 = 0x0012;

        public const uint DVB_ST_PID_19 = 0x0013;

        public const uint DVB_ST_PID_20 = 0x0014;

        public const uint DVB_ST_TID = 0x72;

        public const uint ISDB_ST_TID = 0x72;

        public const uint DVB_TOT_PID = 0x0014;

        public const uint DVB_TOT_TID = 0x73;

        public const uint DVB_DIT_PID = 0x001E;

        public const uint DVB_DIT_TID = 0x7E;

        public const uint DVB_SIT_PID = 0x001F;

        public const uint DVB_SIT_TID = 0x7F;

        public const uint ISDB_EMM_TID = 0x85;

        public const uint ISDB_BIT_PID = 0x0024;

        public const uint ISDB_BIT_TID = 0xC4;

        public const uint ISDB_NBIT_PID = 0x0025;

        public const uint ISDB_NBIT_MSG_TID = 0xC5;

        public const uint ISDB_NBIT_REF_TID = 0xC6;

        public const uint ISDB_LDT_PID = 0x0025;

        public const uint ISDB_LDT_TID = 0xC7;

        public const uint ISDB_SDTT_PID = 0x0023;

        public const uint ISDB_SDTT_ALT_PID = 0x0028;

        public const uint ISDB_SDTT_TID = 0xC3;

        public const uint ISDB_CDT_PID = 0x0029;

        public const uint ISDB_CDT_TID = 0xC8;

        public const uint SCTE_EAS_TID = 0xD8;

        public const uint SCTE_EAS_IB_PID = 0x1FFB;

        public const uint SCTE_EAS_OOB_PID = 0x1FFC;

        public static readonly Guid CLSID_Mpeg2TableFilter__scanned__ = new Guid(0x752845f1, 0x758f, 0x4c83, 0xa0, 0x43, 0x42, 0x70, 0xc5, 0x93, 0x30, 0x8e);

        public const uint ATSC_ETM_LOCATION_NOT_PRESENT = 0x00;

        public const uint ATSC_ETM_LOCATION_IN_PTC_FOR_PSIP = 0x01;

        public const uint ATSC_ETM_LOCATION_IN_PTC_FOR_EVENT = 0x02;

        public const uint ATSC_ETM_LOCATION_RESERVED = 0x03;

        public const uint SAMPLE_SEQ_SEQUENCE_HEADER = 1;

        public const uint SAMPLE_SEQ_GOP_HEADER = 2;

        public const uint SAMPLE_SEQ_PICTURE_HEADER = 3;

        public const uint SAMPLE_SEQ_CONTENT_UNKNOWN = 0;

        public const uint SAMPLE_SEQ_CONTENT_I_FRAME = 1;

        public const uint SAMPLE_SEQ_CONTENT_P_FRAME = 2;

        public const uint SAMPLE_SEQ_CONTENT_B_FRAME = 3;

        public const uint COMPONENT_TAG_CAPTION_MIN = 0x30;

        public const uint COMPONENT_TAG_CAPTION_MAX = 0x37;

        public const uint COMPONENT_TAG_SUPERIMPOSE_MIN = 0x38;

        public const uint COMPONENT_TAG_SUPERIMPOSE_MAX = 0x3F;

    }
}
