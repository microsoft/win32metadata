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


namespace Windows.Win32.Media.Audio.CoreAudio
{
    public static partial class Apis
    {
        public const uint AUDCLNT_STREAMFLAGS_CROSSPROCESS = 0x00010000;

        public const uint AUDCLNT_STREAMFLAGS_LOOPBACK = 0x00020000;

        public const uint AUDCLNT_STREAMFLAGS_EVENTCALLBACK = 0x00040000;

        public const uint AUDCLNT_STREAMFLAGS_NOPERSIST = 0x00080000;

        public const uint AUDCLNT_STREAMFLAGS_RATEADJUST = 0x00100000;

        public const uint AUDCLNT_STREAMFLAGS_SRC_DEFAULT_QUALITY = 0x08000000;

        public const uint AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM = 0x80000000;

        public const uint AUDCLNT_SESSIONFLAGS_EXPIREWHENUNOWNED = 0x10000000;

        public const uint AUDCLNT_SESSIONFLAGS_DISPLAY_HIDE = 0x20000000;

        public const uint AUDCLNT_SESSIONFLAGS_DISPLAY_HIDEWHENEXPIRED = 0x40000000;

        public const uint WAVE_FORMAT_EXTENSIBLE = 0xFFFE;

        public const uint KSDSOUND_BUFFER_PRIMARY = 0x00000001;

        public const uint KSDSOUND_BUFFER_STATIC = 0x00000002;

        public const uint KSDSOUND_BUFFER_LOCHARDWARE = 0x00000004;

        public const uint KSDSOUND_BUFFER_LOCSOFTWARE = 0x00000008;

        public const uint KSDSOUND_BUFFER_CTRL_3D = 0x00000001;

        public const uint KSDSOUND_BUFFER_CTRL_FREQUENCY = 0x00000002;

        public const uint KSDSOUND_BUFFER_CTRL_PAN = 0x00000004;

        public const uint KSDSOUND_BUFFER_CTRL_VOLUME = 0x00000008;

        public const uint KSDSOUND_BUFFER_CTRL_POSITIONNOTIFY = 0x00000010;

        [PropertyKey(0x13e004d6, 0xb066, 0x43bd, 0x91, 0x3b, 0xa4, 0x15, 0xcd, 0x13, 0xda, 0x87, 2)]
        public static readonly PROPERTYKEY DEVPKEY_KsAudio_PacketSize_Constraints;

        [PropertyKey(0x13e004d6, 0xb066, 0x43bd, 0x91, 0x3b, 0xa4, 0x15, 0xcd, 0x13, 0xda, 0x87, 3)]
        public static readonly PROPERTYKEY DEVPKEY_KsAudio_Controller_DeviceInterface_Path;

        [PropertyKey(0x9404f781, 0x7191, 0x409b, 0x8b, 0xb, 0x80, 0xbf, 0x6e, 0xc2, 0x29, 0xae, 2)]
        public static readonly PROPERTYKEY DEVPKEY_KsAudio_PacketSize_Constraints2;

        public const int KSAUDIO_STEREO_SPEAKER_GEOMETRY_HEADPHONE = -1;

        public const uint KSAUDIO_STEREO_SPEAKER_GEOMETRY_MIN = 5;

        public const uint KSAUDIO_STEREO_SPEAKER_GEOMETRY_NARROW = 10;

        public const uint KSAUDIO_STEREO_SPEAKER_GEOMETRY_WIDE = 20;

        public const uint KSAUDIO_STEREO_SPEAKER_GEOMETRY_MAX = 180;

        public const uint KSDSOUND_3D_MODE_NORMAL = 0x00000000;

        public const uint KSDSOUND_3D_MODE_HEADRELATIVE = 0x00000001;

        public const uint KSDSOUND_3D_MODE_DISABLE = 0x00000002;

        public const uint KSDSOUND_BUFFER_CTRL_HRTF_3D = 0x40000000;

        public const uint KSAUDIO_QUALITY_WORST = 0x0;

        public const uint KSAUDIO_QUALITY_PC = 0x1;

        public const uint KSAUDIO_QUALITY_BASIC = 0x2;

        public const uint KSAUDIO_QUALITY_ADVANCED = 0x3;

        public const uint KSAUDIO_CPU_RESOURCES_NOT_HOST_CPU = 0x00000000;

        public const uint KSAUDIO_CPU_RESOURCES_HOST_CPU = 0x7FFFFFFF;

        public const uint SPEAKER_FRONT_LEFT = 0x1;

        public const uint SPEAKER_FRONT_RIGHT = 0x2;

        public const uint SPEAKER_FRONT_CENTER = 0x4;

        public const uint SPEAKER_LOW_FREQUENCY = 0x8;

        public const uint SPEAKER_BACK_LEFT = 0x10;

        public const uint SPEAKER_BACK_RIGHT = 0x20;

        public const uint SPEAKER_FRONT_LEFT_OF_CENTER = 0x40;

        public const uint SPEAKER_FRONT_RIGHT_OF_CENTER = 0x80;

        public const uint SPEAKER_BACK_CENTER = 0x100;

        public const uint SPEAKER_SIDE_LEFT = 0x200;

        public const uint SPEAKER_SIDE_RIGHT = 0x400;

        public const uint SPEAKER_TOP_CENTER = 0x800;

        public const uint SPEAKER_TOP_FRONT_LEFT = 0x1000;

        public const uint SPEAKER_TOP_FRONT_CENTER = 0x2000;

        public const uint SPEAKER_TOP_FRONT_RIGHT = 0x4000;

        public const uint SPEAKER_TOP_BACK_LEFT = 0x8000;

        public const uint SPEAKER_TOP_BACK_CENTER = 0x10000;

        public const uint SPEAKER_TOP_BACK_RIGHT = 0x20000;

        public const uint SPEAKER_RESERVED = 0x7FFC0000;

        public const uint SPEAKER_ALL = 0x80000000;

        public const uint KSAUDIO_SPEAKER_DIRECTOUT = 0;

        public const uint KSNODEPIN_STANDARD_IN = 1;

        public const uint KSNODEPIN_STANDARD_OUT = 0;

        public const uint KSNODEPIN_SUM_MUX_IN = 1;

        public const uint KSNODEPIN_SUM_MUX_OUT = 0;

        public const uint KSNODEPIN_DEMUX_IN = 0;

        public const uint KSNODEPIN_DEMUX_OUT = 1;

        public const uint KSNODEPIN_AEC_RENDER_IN = 1;

        public const uint KSNODEPIN_AEC_RENDER_OUT = 0;

        public const uint KSNODEPIN_AEC_CAPTURE_IN = 2;

        public const uint KSNODEPIN_AEC_CAPTURE_OUT = 3;

        public const uint AEC_STATUS_FD_HISTORY_UNINITIALIZED = 0x0;

        public const uint AEC_STATUS_FD_HISTORY_CONTINUOUSLY_CONVERGED = 0x1;

        public const uint AEC_STATUS_FD_HISTORY_PREVIOUSLY_DIVERGED = 0x2;

        public const uint AEC_STATUS_FD_CURRENTLY_CONVERGED = 0x8;

        public const uint AEC_MODE_PASS_THROUGH = 0x0;

        public const uint AEC_MODE_HALF_DUPLEX = 0x1;

        public const uint AEC_MODE_FULL_DUPLEX = 0x2;

        public const uint KSPROPERTY_WAVE_QUEUED_POSITION = 0x00000001;

        public const uint KSMETHOD_WAVE_QUEUED_BREAKLOOP = 0x00000001;

        public const uint KSWAVE_COMPATCAPS_INPUT = 0x00000000;

        public const uint KSWAVE_COMPATCAPS_OUTPUT = 0x00000001;

        public const uint KSWAVE_BUFFER_ATTRIBUTEF_LOOPING = 0x00000001;

        public const uint KSWAVE_BUFFER_ATTRIBUTEF_STATIC = 0x00000002;

        public const uint SYSAUDIO_FLAGS_DONT_COMBINE_PINS = 0x00000001;

        public const uint SYSAUDIO_FLAGS_CLEAR_PREFERRED = 0x00000002;

        public const uint KSMPEGVIDMODE_PANSCAN = 0x0001;

        public const uint KSMPEGVIDMODE_LTRBOX = 0x0002;

        public const uint KSMPEGVIDMODE_SCALE = 0x0004;

        public const uint KSAC3_ALTERNATE_AUDIO_1 = 1;

        public const uint KSAC3_ALTERNATE_AUDIO_2 = 2;

        public const uint KSAC3_ALTERNATE_AUDIO_BOTH = 3;

        public const uint KSAC3_SERVICE_MAIN_AUDIO = 0;

        public const uint KSAC3_SERVICE_NO_DIALOG = 1;

        public const uint KSAC3_SERVICE_VISUALLY_IMPAIRED = 2;

        public const uint KSAC3_SERVICE_HEARING_IMPAIRED = 3;

        public const uint KSAC3_SERVICE_DIALOG_ONLY = 4;

        public const uint KSAC3_SERVICE_COMMENTARY = 5;

        public const uint KSAC3_SERVICE_EMERGENCY_FLASH = 6;

        public const uint KSAC3_SERVICE_VOICE_OVER = 7;

        public const uint KSAUDDECOUTMODE_STEREO_ANALOG = 0x0001;

        public const uint KSAUDDECOUTMODE_PCM_51 = 0x0002;

        public const uint KSAUDDECOUTMODE_SPDIFF = 0x0004;

        public const uint KS_DVD_CGMS_RESERVED_MASK = 0x00000078;

        public const uint KS_DVD_CGMS_COPY_PROTECT_MASK = 0x00000018;

        public const uint KS_DVD_CGMS_COPY_PERMITTED = 0x00000000;

        public const uint KS_DVD_CGMS_COPY_ONCE = 0x00000010;

        public const uint KS_DVD_CGMS_NO_COPY = 0x00000018;

        public const uint KS_DVD_COPYRIGHT_MASK = 0x00000040;

        public const uint KS_DVD_NOT_COPYRIGHTED = 0x00000000;

        public const uint KS_DVD_COPYRIGHTED = 0x00000040;

        public const uint KS_DVD_SECTOR_PROTECT_MASK = 0x00000020;

        public const uint KS_DVD_SECTOR_NOT_PROTECTED = 0x00000000;

        public const uint KS_DVD_SECTOR_PROTECTED = 0x00000020;

        public const int KS_BI_RGB = 0;

        public const int KS_BI_RLE8 = 1;

        public const int KS_BI_RLE4 = 2;

        public const int KS_BI_BITFIELDS = 3;

        public const int KS_BI_JPEG = 4;

        public const uint KS_iPALETTE_COLORS = 256;

        public const uint KS_iEGA_COLORS = 16;

        public const uint KS_iMASK_COLORS = 3;

        public const uint KS_iTRUECOLOR = 16;

        public const uint KS_iRED = 0;

        public const uint KS_iGREEN = 1;

        public const uint KS_iBLUE = 2;

        public const uint KS_iPALETTE = 8;

        public const uint KS_iMAXBITS = 8;

        public const int KS_VBIDATARATE_NABTS = 5727272;

        public const int KS_VBIDATARATE_CC = 503493;

        public const int KS_TVTUNER_CHANGE_BEGIN_TUNE = 0x0001;

        public const int KS_TVTUNER_CHANGE_END_TUNE = 0x0002;

        public const uint KS_INTERLACE_IsInterlaced = 0x00000001;

        public const uint KS_INTERLACE_1FieldPerSample = 0x00000002;

        public const uint KS_INTERLACE_Field1First = 0x00000004;

        public const uint KS_INTERLACE_UNUSED = 0x00000008;

        public const uint KS_INTERLACE_FieldPatternMask = 0x00000030;

        public const uint KS_INTERLACE_FieldPatField1Only = 0x00000000;

        public const uint KS_INTERLACE_FieldPatField2Only = 0x00000010;

        public const uint KS_INTERLACE_FieldPatBothRegular = 0x00000020;

        public const uint KS_INTERLACE_FieldPatBothIrregular = 0x00000030;

        public const uint KS_INTERLACE_DisplayModeMask = 0x000000c0;

        public const uint KS_INTERLACE_DisplayModeBobOnly = 0x00000000;

        public const uint KS_INTERLACE_DisplayModeWeaveOnly = 0x00000040;

        public const uint KS_INTERLACE_DisplayModeBobOrWeave = 0x00000080;

        public const uint KS_COPYPROTECT_RestrictDuplication = 0x00000001;

        public const uint KS_MPEG2_DoPanScan = 0x00000001;

        public const uint KS_MPEG2_DVDLine21Field1 = 0x00000002;

        public const uint KS_MPEG2_DVDLine21Field2 = 0x00000004;

        public const uint KS_MPEG2_SourceIsLetterboxed = 0x00000008;

        public const uint KS_MPEG2_FilmCameraMode = 0x00000010;

        public const uint KS_MPEG2_LetterboxAnalogOut = 0x00000020;

        public const uint KS_MPEG2_DSS_UserData = 0x00000040;

        public const uint KS_MPEG2_DVB_UserData = 0x00000080;

        public const uint KS_MPEG2_27MhzTimebase = 0x00000100;

        public const uint KS_MPEG2_WidescreenAnalogOut = 0x00000200;

        public const uint KS_AMCONTROL_USED = 0x00000001;

        public const uint KS_AMCONTROL_PAD_TO_4x3 = 0x00000002;

        public const uint KS_AMCONTROL_PAD_TO_16x9 = 0x00000004;

        public const uint KS_AMCONTROL_COLORINFO_PRESENT = 0x00000080;

        public const uint KS_MAX_SIZE_MPEG1_SEQUENCE_INFO = 140;

        public const uint KS_MPEGAUDIOINFO_27MhzTimebase = 0x00000001;

        public const uint KS_VIDEOSTREAM_PREVIEW = 0x0001;

        public const uint KS_VIDEOSTREAM_CAPTURE = 0x0002;

        public const uint KS_VIDEOSTREAM_VBI = 0x0010;

        public const uint KS_VIDEOSTREAM_NABTS = 0x0020;

        public const uint KS_VIDEOSTREAM_CC = 0x0100;

        public const uint KS_VIDEOSTREAM_EDS = 0x0200;

        public const uint KS_VIDEOSTREAM_TELETEXT = 0x0400;

        public const uint KS_VIDEOSTREAM_STILL = 0x1000;

        public const uint KS_VIDEOSTREAM_IS_VPE = 0x8000;

        public const uint KS_VIDEO_ALLOC_VPE_SYSTEM = 0x0001;

        public const uint KS_VIDEO_ALLOC_VPE_DISPLAY = 0x0002;

        public const uint KS_VIDEO_ALLOC_VPE_AGP = 0x0004;

        public const int KS_VBICAP_PROTECTION_MV_PRESENT = 0x0001;

        public const int KS_VBICAP_PROTECTION_MV_HARDWARE = 0x0002;

        public const int KS_VBICAP_PROTECTION_MV_DETECTED = 0x0004;

        public const uint KS_NABTS_GROUPID_ORIGINAL_CONTENT_BASE = 0x800;

        public const uint KS_NABTS_GROUPID_ORIGINAL_CONTENT_ADVERTISER_BASE = 0x810;

        public const uint KS_NABTS_GROUPID_PRODUCTION_COMPANY_CONTENT_BASE = 0x820;

        public const uint KS_NABTS_GROUPID_PRODUCTION_COMPANY_ADVERTISER_BASE = 0x830;

        public const uint KS_NABTS_GROUPID_SYNDICATED_SHOW_CONTENT_BASE = 0x840;

        public const uint KS_NABTS_GROUPID_SYNDICATED_SHOW_ADVERTISER_BASE = 0x850;

        public const uint KS_NABTS_GROUPID_NETWORK_WIDE_CONTENT_BASE = 0x860;

        public const uint KS_NABTS_GROUPID_NETWORK_WIDE_ADVERTISER_BASE = 0x870;

        public const uint KS_NABTS_GROUPID_TELEVISION_STATION_CONTENT_BASE = 0x880;

        public const uint KS_NABTS_GROUPID_TELEVISION_STATION_ADVERTISER_BASE = 0x890;

        public const uint KS_NABTS_GROUPID_LOCAL_CABLE_SYSTEM_CONTENT_BASE = 0x8A0;

        public const uint KS_NABTS_GROUPID_LOCAL_CABLE_SYSTEM_ADVERTISER_BASE = 0x8B0;

        public const uint KS_NABTS_GROUPID_MICROSOFT_RESERVED_TEST_DATA_BASE = 0x8F0;

        public const uint MAX_NABTS_VBI_LINES_PER_FIELD = 11;

        public const uint NABTS_LINES_PER_BUNDLE = 16;

        public const uint NABTS_PAYLOAD_PER_LINE = 28;

        public const uint NABTS_BYTES_PER_LINE = 36;

        public const int KS_CC_SUBSTREAM_ODD = 0x0001;

        public const int KS_CC_SUBSTREAM_EVEN = 0x0002;

        public const int KS_CC_SUBSTREAM_FIELD1_MASK = 0x00F0;

        public const int KS_CC_SUBSTREAM_SERVICE_CC1 = 0x0010;

        public const int KS_CC_SUBSTREAM_SERVICE_CC2 = 0x0020;

        public const int KS_CC_SUBSTREAM_SERVICE_T1 = 0x0040;

        public const int KS_CC_SUBSTREAM_SERVICE_T2 = 0x0080;

        public const int KS_CC_SUBSTREAM_FIELD2_MASK = 0x1F00;

        public const int KS_CC_SUBSTREAM_SERVICE_CC3 = 0x0100;

        public const int KS_CC_SUBSTREAM_SERVICE_CC4 = 0x0200;

        public const int KS_CC_SUBSTREAM_SERVICE_T3 = 0x0400;

        public const int KS_CC_SUBSTREAM_SERVICE_T4 = 0x0800;

        public const int KS_CC_SUBSTREAM_SERVICE_XDS = 0x1000;

        public const uint CC_MAX_HW_DECODE_LINES = 12;

        public const uint NABTS_BUFFER_PICTURENUMBER_SUPPORT = 1;

        public const int WST_TVTUNER_CHANGE_BEGIN_TUNE = 0x1000;

        public const int WST_TVTUNER_CHANGE_END_TUNE = 0x2000;

        public const uint MAX_WST_VBI_LINES_PER_FIELD = 17;

        public const uint WST_BYTES_PER_LINE = 42;

        public const int KS_VIDEO_FLAG_FIELD_MASK = 0x0003;

        public const int KS_VIDEO_FLAG_FRAME = 0x0000;

        public const int KS_VIDEO_FLAG_FIELD1 = 0x0001;

        public const int KS_VIDEO_FLAG_FIELD2 = 0x0002;

        public const int KS_VIDEO_FLAG_FIELD1FIRST = 0x0004;

        public const int KS_VIDEO_FLAG_WEAVE = 0x0008;

        public const int KS_VIDEO_FLAG_IPB_MASK = 0x0030;

        public const int KS_VIDEO_FLAG_I_FRAME = 0x0000;

        public const int KS_VIDEO_FLAG_P_FRAME = 0x0010;

        public const int KS_VIDEO_FLAG_B_FRAME = 0x0020;

        public const int KS_VIDEO_FLAG_REPEAT_FIELD = 0x0040;

        public const int KS_VBI_FLAG_FRAME = 0x0000;

        public const int KS_VBI_FLAG_FIELD1 = 0x0001;

        public const int KS_VBI_FLAG_FIELD2 = 0x0002;

        public const int KS_VBI_FLAG_MV_PRESENT = 0x0100;

        public const int KS_VBI_FLAG_MV_HARDWARE = 0x0200;

        public const int KS_VBI_FLAG_MV_DETECTED = 0x0400;

        public const int KS_VBI_FLAG_TVTUNER_CHANGE = 0x0010;

        public const int KS_VBI_FLAG_VBIINFOHEADER_CHANGE = 0x0020;

        public const uint KS_AnalogVideo_NTSC_Mask = 0x00000007;

        public const uint KS_AnalogVideo_PAL_Mask = 0x00100FF0;

        public const uint KS_AnalogVideo_SECAM_Mask = 0x000FF000;

        public const int KSPROPERTY_VIDEOPROCAMP_FLAGS_AUTO = 0X0001;

        public const int KSPROPERTY_VIDEOPROCAMP_FLAGS_MANUAL = 0X0002;

        public const int KSPROPERTY_CAMERACONTROL_FLAGS_AUTO = 0X0001;

        public const int KSPROPERTY_CAMERACONTROL_FLAGS_MANUAL = 0X0002;

        public const int KSPROPERTY_CAMERACONTROL_FLAGS_ASYNCHRONOUS = 0X0004;

        public const int KSPROPERTY_CAMERACONTROL_FLAGS_ABSOLUTE = 0X0000;

        public const int KSPROPERTY_CAMERACONTROL_FLAGS_RELATIVE = 0X0010;

        public const int KSPROPERTY_CAMERACONTROL_FLASH_OFF = 0x00000000;

        public const int KSPROPERTY_CAMERACONTROL_FLASH_ON = 0x00000001;

        public const int KSPROPERTY_CAMERACONTROL_FLASH_AUTO = 0x00000002;

        public const int KSPROPERTY_CAMERACONTROL_FLASH_FLAGS_AUTO = 0x00000001;

        public const int KSPROPERTY_CAMERACONTROL_FLASH_FLAGS_MANUAL = 0x00000002;

        public const int KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_OFF = 0x00000000;

        public const int KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_HIGH = 0x00000001;

        public const int KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_MEDIUM = 0x00000002;

        public const int KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_LOW = 0x00000003;

        public const int KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_AUTO = 0x00000004;

        public const int KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_FLAGS_AUTO = 0x00000001;

        public const int KSPROPERTY_CAMERACONTROL_VIDEOSTABILIZATION_MODE_FLAGS_MANUAL = 0x00000002;

        public const int KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_FLAGS_AUTO = 0x00000001;

        public const int KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_FLAGS_MANUAL = 0x00000002;

        public const int KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_FLAGS_ASYNC = unchecked((int)0x80000000);

        public const int KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONFIG_FOCUS = 0x00000100;

        public const int KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONFIG_EXPOSURE = 0x00000200;

        public const int KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONFIG_WB = 0x00000400;

        public const int KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_CONVERGEMODE = 0x40000000;

        public const int KSPROPERTY_CAMERACONTROL_IMAGE_PIN_CAPABILITY_EXCLUSIVE_WITH_RECORD = 0x00000001;

        public const int KSPROPERTY_CAMERACONTROL_IMAGE_PIN_CAPABILITY_SEQUENCE_EXCLUSIVE_WITH_RECORD = 0x00000002;

        public const uint KSCAMERA_EXTENDEDPROP_FILTERSCOPE = 0xFFFFFFFF;

        public const ulong KSCAMERA_EXTENDEDPROP_CAPS_RESERVED = 0xFF00000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_CAPS_ASYNCCONTROL = 0x8000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_CAPS_CANCELLABLE = 0x4000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FLAG_CANCELOPERATION = 0x8000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_CAPS_MASK = 0xFF00000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FLAG_MASK = 0xFF00000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOMODE_NORMAL = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOMODE_SEQUENCE = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_WARMSTART_MODE_DISABLED = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_WARMSTART_MODE_ENABLED = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOTHUMBNAIL_DISABLE = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOTHUMBNAIL_2X = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOTHUMBNAIL_4X = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOTHUMBNAIL_8X = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOTHUMBNAIL_16X = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_AUTO = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_MACRO = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_PORTRAIT = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_SPORT = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_SNOW = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_NIGHT = 0x0000000000000010;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_BEACH = 0x0000000000000020;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_SUNSET = 0x0000000000000040;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_CANDLELIGHT = 0x0000000000000080;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_LANDSCAPE = 0x0000000000000100;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_NIGHTPORTRAIT = 0x0000000000000200;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_BACKLIT = 0x0000000000000400;

        public const ulong KSCAMERA_EXTENDEDPROP_SCENEMODE_MANUAL = 0x0080000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOTORCH_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOTORCH_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOTORCH_ON_ADJUSTABLEPOWER = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_ON_ADJUSTABLEPOWER = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_AUTO = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_AUTO_ADJUSTABLEPOWER = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_REDEYEREDUCTION = 0x0000000000000010;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_SINGLEFLASH = 0x0000000000000020;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_MULTIFLASHSUPPORTED = 0x0000000000000040;

        public const ulong KSCAMERA_EXTENDEDPROP_OPTIMIZATION_PHOTO = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_OPTIMIZATION_VIDEO = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_OPTIMIZATION_DEFAULT = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_OPTIMIZATION_QUALITY = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_OPTIMIZATION_LATENCY = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_OPTIMIZATION_POWER = 0x0000000000000010;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOPROCFLAG_AUTO = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOPROCFLAG_MANUAL = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOPROCFLAG_LOCK = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_CONTINUOUS = 0x0000000000000100;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_RANGE_MACRO = 0x0000000000010000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_RANGE_NORMAL = 0x0000000000020000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_RANGE_FULLRANGE = 0x0000000000040000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_RANGE_INFINITY = 0x0000000000080000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_RANGE_HYPERFOCAL = 0x0000000000100000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_DISTANCE_INFINITY = 0x0000000001000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_DISTANCE_HYPERFOCAL = 0x0000000002000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_DISTANCE_NEAREST = 0x0000000004000000;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_AUTO = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_50 = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_80 = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_100 = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_200 = 0x0000000000000010;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_400 = 0x0000000000000020;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_800 = 0x0000000000000040;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_1600 = 0x0000000000000080;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_3200 = 0x0000000000000100;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_6400 = 0x0000000000000200;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_12800 = 0x0000000000000400;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_25600 = 0x0000000000000800;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_CONTINUOUSLOCK = 0x0000000000000200;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_UNLOCK = 0x0000000000000400;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_DRIVERFALLBACK_OFF = 0x0000000000000800;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUS_REGIONBASED = 0x0000000000001000;

        public const ulong KSCAMERA_EXTENDEDPROP_ISO_MANUAL = 0x0080000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_ASSISTANT_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_ASSISTANT_ON = 0x0000000000000080;

        public const ulong KSCAMERA_EXTENDEDPROP_FLASH_ASSISTANT_AUTO = 0x0000000000000100;

        public const ulong KSCAMERA_EXTENDEDPROP_EVCOMP_SIXTHSTEP = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_EVCOMP_QUARTERSTEP = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_EVCOMP_THIRDSTEP = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_EVCOMP_HALFSTEP = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_EVCOMP_FULLSTEP = 0x0000000000000010;

        public const uint KSCAMERA_EXTENDEDPROP_PHOTOMODE_SEQUENCE_SUB_NONE = 0x00000000;

        public const uint KSCAMERA_EXTENDEDPROP_PHOTOMODE_SEQUENCE_SUB_VARIABLE = 0x00000001;

        public const ulong KSCAMERA_EXTENDEDPROP_METADATA_MEMORYTYPE_MASK = 0x00000000000000FF;

        public const ulong KSCAMERA_EXTENDEDPROP_METADATA_SYSTEMMEMORY = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_METADATA_ALIGNMENTREQUIRED = 0x0000000000000100;

        public const uint KSCAMERA_METADATA_FRAMEILLUMINATION_FLAG_ON = 0x00000001;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_EXPOSURETIME = 0x00000001;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_EXPOSURECOMPENSATION = 0x00000002;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_ISOSPEED = 0x00000004;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_FOCUSSTATE = 0x00000008;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_LENSPOSITION = 0x00000010;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_WHITEBALANCE = 0x00000020;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_FLASH = 0x00000040;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_FLASHPOWER = 0x00000080;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_ZOOMFACTOR = 0x00000100;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_SCENEMODE = 0x00000200;

        public const uint KSCAMERA_METADATA_CAPTURESTATS_FLAG_SENSORFRAMERATE = 0x00000400;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUSPRIORITY_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FOCUSPRIORITY_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOCONFIRMATION_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_PHOTOCONFIRMATION_ON = 0x0000000000000001;

        public const ulong KSCAMERA_PERFRAMESETTING_AUTO = 0x0000000100000000;

        public const ulong KSCAMERA_PERFRAMESETTING_MANUAL = 0x0000000200000000;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOSTABILIZATION_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOSTABILIZATION_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOSTABILIZATION_AUTO = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_VFR_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_VFR_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEDETECTION_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEDETECTION_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEDETECTION_PREVIEW = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEDETECTION_VIDEO = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEDETECTION_PHOTO = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEDETECTION_BLINK = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEDETECTION_SMILE = 0x0000000000000010;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOHDR_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOHDR_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOHDR_AUTO = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_HISTOGRAM_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_HISTOGRAM_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_OIS_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_OIS_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_OIS_AUTO = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_ADVANCEDPHOTO_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_ADVANCEDPHOTO_AUTO = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_ADVANCEDPHOTO_HDR = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_ADVANCEDPHOTO_FNF = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_ADVANCEDPHOTO_ULTRALOWLIGHT = 0x0000000000000008;

        public const ulong KSCAMERA_EXTENDEDPROP_ZOOM_DEFAULT = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_ZOOM_DIRECT = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_ZOOM_SMOOTH = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEAUTH_MODE_DISABLED = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEAUTH_MODE_ALTERNATIVE_FRAME_ILLUMINATION = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_FACEAUTH_MODE_BACKGROUND_SUBTRACTION = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_SECUREMODE_DISABLED = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_SECUREMODE_ENABLED = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOTEMPORALDENOISING_AUTO = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOTEMPORALDENOISING_OFF = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_VIDEOTEMPORALDENOISING_ON = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_IRTORCHMODE_OFF = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_IRTORCHMODE_ALWAYS_ON = 0x0000000000000002;

        public const ulong KSCAMERA_EXTENDEDPROP_IRTORCHMODE_ALTERNATING_FRAME_ILLUMINATION = 0x0000000000000004;

        public const ulong KSCAMERA_EXTENDEDPROP_RELATIVEPANELOPTIMIZATION_OFF = 0x0000000000000000;

        public const ulong KSCAMERA_EXTENDEDPROP_RELATIVEPANELOPTIMIZATION_ON = 0x0000000000000001;

        public const ulong KSCAMERA_EXTENDEDPROP_RELATIVEPANELOPTIMIZATION_DYNAMIC = 0x0000000000000002;

        public const ulong KSCAMERAPROFILE_FLAGS_VIDEOSTABLIZATION = 0x0000000000000001;

        public const ulong KSCAMERAPROFILE_FLAGS_VIDEOHDR = 0x0000000000000002;

        public const ulong KSCAMERAPROFILE_FLAGS_PHOTOHDR = 0x0000000000000004;

        public const ulong KSCAMERAPROFILE_FLAGS_FACEDETECTION = 0x0000000000000008;

        public const ulong KSCAMERAPROFILE_FLAGS_VARIABLEPHOTOSEQUENCE = 0x0000000000000010;

        public const ulong KSCAMERAPROFILE_FLAGS_PREVIEW_RES_MUSTMATCH = 0x0000000000000020;

        public const uint KSDEVICE_PROFILE_TYPE_UNKNOWN = 0x00000000;

        public const uint KSDEVICE_PROFILE_TYPE_CAMERA = 0x00000001;

        public const uint KSCameraProfileSensorType_RGB = 0x0001;

        public const uint KSCameraProfileSensorType_Infrared = 0x0002;

        public const uint KSCameraProfileSensorType_Depth = 0x0004;

        public const uint KSCameraProfileSensorType_PoseTracking = 0x0008;

        public const uint KSCameraProfileSensorType_ImageSegmentation = 0x0010;

        public const uint KSCameraProfileSensorType_Custom = 0x0080;

        public const uint KS_TVAUDIO_MODE_MONO = 0x0001;

        public const uint KS_TVAUDIO_MODE_STEREO = 0x0002;

        public const uint KS_TVAUDIO_MODE_LANG_A = 0x0010;

        public const uint KS_TVAUDIO_MODE_LANG_B = 0x0020;

        public const uint KS_TVAUDIO_MODE_LANG_C = 0x0040;

        public const uint KS_TVAUDIO_PRESET_STEREO = 0x0200;

        public const uint KS_TVAUDIO_PRESET_LANG_A = 0x1000;

        public const uint KS_TVAUDIO_PRESET_LANG_B = 0x2000;

        public const uint KS_TVAUDIO_PRESET_LANG_C = 0x4000;

        public const int DDPF_FOURCC = 0x00000004;

        public const int KS_AM_UseNewCSSKey = 0x0001;

        public const uint MAX_SINK_DESCRIPTION_NAME_LENGTH = 32;

        public const uint JACKDESC2_PRESENCE_DETECT_CAPABILITY = 0x00000001;

        public const uint JACKDESC2_DYNAMIC_FORMAT_CHANGE_CAPABILITY = 0x00000002;

        public const uint KSPROPERTY_AUDIO_BUFFER_DURATION = 1;

        public const uint AUDIOMODULE_MAX_DATA_SIZE = 64000;

        public const uint AUDIOMODULE_MAX_NAME_CCH_SIZE = 128;

        public const uint IOCTL_KS_PROPERTY = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x000) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_KS_ENABLE_EVENT = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x001) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_KS_DISABLE_EVENT = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x002) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_KS_METHOD = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x003) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_KS_WRITE_STREAM = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0x004) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_KS_READ_STREAM = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((0x005) << 2) | (METHOD_NEITHER);

        public const uint IOCTL_KS_RESET_STATE = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x006) << 2) | (METHOD_NEITHER);

        public const uint KSPRIORITY_LOW = 0x00000001;

        public const uint KSPRIORITY_NORMAL = 0x40000000;

        public const uint KSPRIORITY_HIGH = 0x80000000;

        public const uint KSPRIORITY_EXCLUSIVE = 0xFFFFFFFF;

        public const uint KSMETHOD_TYPE_NONE = 0x00000000;

        public const uint KSMETHOD_TYPE_READ = 0x00000001;

        public const uint KSMETHOD_TYPE_WRITE = 0x00000002;

        public const uint KSMETHOD_TYPE_MODIFY = 0x00000003;

        public const uint KSMETHOD_TYPE_SOURCE = 0x00000004;

        public const uint KSMETHOD_TYPE_SEND = 0x00000001;

        public const uint KSMETHOD_TYPE_SETSUPPORT = 0x00000100;

        public const uint KSMETHOD_TYPE_BASICSUPPORT = 0x00000200;

        public const uint KSMETHOD_TYPE_TOPOLOGY = 0x10000000;

        public const uint KSPROPERTY_TYPE_GET = 0x00000001;

        public const uint KSPROPERTY_TYPE_GETPAYLOADSIZE = 0x00000004;

        public const uint KSPROPERTY_TYPE_SET = 0x00000002;

        public const uint KSPROPERTY_TYPE_SETSUPPORT = 0x00000100;

        public const uint KSPROPERTY_TYPE_BASICSUPPORT = 0x00000200;

        public const uint KSPROPERTY_TYPE_RELATIONS = 0x00000400;

        public const uint KSPROPERTY_TYPE_SERIALIZESET = 0x00000800;

        public const uint KSPROPERTY_TYPE_UNSERIALIZESET = 0x00001000;

        public const uint KSPROPERTY_TYPE_SERIALIZERAW = 0x00002000;

        public const uint KSPROPERTY_TYPE_UNSERIALIZERAW = 0x00004000;

        public const uint KSPROPERTY_TYPE_SERIALIZESIZE = 0x00008000;

        public const uint KSPROPERTY_TYPE_DEFAULTVALUES = 0x00010000;

        public const uint KSPROPERTY_TYPE_TOPOLOGY = 0x10000000;

        public const uint KSPROPERTY_TYPE_HIGHPRIORITY = 0x08000000;

        public const uint KSPROPERTY_TYPE_FSFILTERSCOPE = 0x40000000;

        public const uint KSPROPERTY_TYPE_COPYPAYLOAD = 0x80000000;

        public const uint KSPROPERTY_MEMBER_RANGES = 0x00000001;

        public const uint KSPROPERTY_MEMBER_STEPPEDRANGES = 0x00000002;

        public const uint KSPROPERTY_MEMBER_VALUES = 0x00000003;

        public const uint KSPROPERTY_MEMBER_FLAG_DEFAULT = 0x00000001;

        public const uint KSPROPERTY_MEMBER_FLAG_BASICSUPPORT_MULTICHANNEL = 0x00000002;

        public const uint KSPROPERTY_MEMBER_FLAG_BASICSUPPORT_UNIFORM = 0x00000004;

        public const uint KSEVENTF_EVENT_HANDLE = 0x00000001;

        public const uint KSEVENTF_SEMAPHORE_HANDLE = 0x00000002;

        public const uint KSEVENTF_EVENT_OBJECT = 0x00000004;

        public const uint KSEVENTF_SEMAPHORE_OBJECT = 0x00000008;

        public const uint KSEVENTF_DPC = 0x00000010;

        public const uint KSEVENTF_WORKITEM = 0x00000020;

        public const uint KSEVENTF_KSWORKITEM = 0x00000080;

        public const uint KSEVENT_TYPE_ENABLE = 0x00000001;

        public const uint KSEVENT_TYPE_ONESHOT = 0x00000002;

        public const uint KSEVENT_TYPE_ENABLEBUFFERED = 0x00000004;

        public const uint KSEVENT_TYPE_SETSUPPORT = 0x00000100;

        public const uint KSEVENT_TYPE_BASICSUPPORT = 0x00000200;

        public const uint KSEVENT_TYPE_QUERYBUFFER = 0x00000400;

        public const uint KSEVENT_TYPE_TOPOLOGY = 0x10000000;

        public const uint KSRELATIVEEVENT_FLAG_HANDLE = 0x00000001;

        public const uint KSRELATIVEEVENT_FLAG_POINTER = 0x00000002;

        public const uint KSMEDIUM_TYPE_ANYINSTANCE = 0;

        public const uint KSPROPERTY_PIN_FLAGS_ATTRIBUTE_RANGE_AWARE = 0x00000001;

        public const uint KSDATAFORMAT_BIT_TEMPORAL_COMPRESSION = 0;

        public const uint KSDATAFORMAT_BIT_ATTRIBUTES = 1;

        public const uint KSDATARANGE_BIT_ATTRIBUTES = 1;

        public const uint KSDATARANGE_BIT_REQUIRED_ATTRIBUTES = 2;

        public const uint KSATTRIBUTE_REQUIRED = 0x00000001;

        public const uint KSALLOCATOR_REQUIREMENTF_INPLACE_MODIFIER = 0x00000001;

        public const uint KSALLOCATOR_REQUIREMENTF_SYSTEM_MEMORY = 0x00000002;

        public const uint KSALLOCATOR_REQUIREMENTF_FRAME_INTEGRITY = 0x00000004;

        public const uint KSALLOCATOR_REQUIREMENTF_MUST_ALLOCATE = 0x00000008;

        public const uint KSALLOCATOR_REQUIREMENTF_SYSTEM_MEMORY_CUSTOM_ALLOCATION = 0x00000010;

        public const uint KSALLOCATOR_REQUIREMENTF_PREFERENCES_ONLY = 0x80000000;

        public const uint KSALLOCATOR_OPTIONF_COMPATIBLE = 0x00000001;

        public const uint KSALLOCATOR_OPTIONF_SYSTEM_MEMORY = 0x00000002;

        public const uint KSALLOCATOR_OPTIONF_VALID = 0x00000003;

        public const uint KSALLOCATOR_FLAG_PARTIAL_READ_SUPPORT = 0x00000010;

        public const uint KSALLOCATOR_FLAG_DEVICE_SPECIFIC = 0x00000020;

        public const uint KSALLOCATOR_FLAG_CAN_ALLOCATE = 0x00000040;

        public const uint KSALLOCATOR_FLAG_INSIST_ON_FRAMESIZE_RATIO = 0x00000080;

        public const uint KSALLOCATOR_FLAG_NO_FRAME_INTEGRITY = 0x00000100;

        public const uint KSALLOCATOR_FLAG_MULTIPLE_OUTPUT = 0x00000200;

        public const uint KSALLOCATOR_FLAG_CYCLE = 0x00000400;

        public const uint KSALLOCATOR_FLAG_ALLOCATOR_EXISTS = 0x00000800;

        public const uint KSALLOCATOR_FLAG_INDEPENDENT_RANGES = 0x00001000;

        public const uint KSALLOCATOR_FLAG_ATTENTION_STEPPING = 0x00002000;

        public const uint KSALLOCATOR_FLAG_ENABLE_CACHED_MDL = 0x00004000;

        public const uint KSALLOCATOR_FLAG_2D_BUFFER_REQUIRED = 0x00008000;

        public const uint KSSTREAM_HEADER_OPTIONSF_SPLICEPOINT = 0x00000001;

        public const uint KSSTREAM_HEADER_OPTIONSF_PREROLL = 0x00000002;

        public const uint KSSTREAM_HEADER_OPTIONSF_DATADISCONTINUITY = 0x00000004;

        public const uint KSSTREAM_HEADER_OPTIONSF_TYPECHANGED = 0x00000008;

        public const uint KSSTREAM_HEADER_OPTIONSF_TIMEVALID = 0x00000010;

        public const uint KSSTREAM_HEADER_OPTIONSF_TIMEDISCONTINUITY = 0x00000040;

        public const uint KSSTREAM_HEADER_OPTIONSF_FLUSHONPAUSE = 0x00000080;

        public const uint KSSTREAM_HEADER_OPTIONSF_DURATIONVALID = 0x00000100;

        public const uint KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM = 0x00000200;

        public const uint KSSTREAM_HEADER_OPTIONSF_BUFFEREDTRANSFER = 0x00000400;

        public const uint KSSTREAM_HEADER_OPTIONSF_VRAM_DATA_TRANSFER = 0x00000800;

        public const uint KSSTREAM_HEADER_OPTIONSF_METADATA = 0x00001000;

        public const uint KSSTREAM_HEADER_OPTIONSF_ENDOFPHOTOSEQUENCE = 0x00002000;

        public const uint KSSTREAM_HEADER_OPTIONSF_FRAMEINFO = 0x00004000;

        public const uint KSSTREAM_HEADER_OPTIONSF_PERSIST_SAMPLE = 0x00008000;

        public const uint KSSTREAM_HEADER_OPTIONSF_SAMPLE_PERSISTED = 0x00010000;

        public const uint KSSTREAM_HEADER_TRACK_COMPLETION_NUMBERS = 0x00020000;

        public const uint KSSTREAM_HEADER_OPTIONSF_SECUREBUFFERTRANSFER = 0x00040000;

        public const uint KSSTREAM_HEADER_OPTIONSF_LOOPEDDATA = 0x80000000;

        public const uint KSSTREAM_UVC_SECURE_ATTRIBUTE_SIZE = 0x2000;

        public const uint KSFRAMETIME_VARIABLESIZE = 0x00000001;

        public const uint KSRATE_NOPRESENTATIONSTART = 0x00000001;

        public const uint KSRATE_NOPRESENTATIONDURATION = 0x00000002;

        public const uint NANOSECONDS = 10000000;

        public const uint KSPROBE_STREAMREAD = 0x00000000;

        public const uint KSPROBE_STREAMWRITE = 0x00000001;

        public const uint KSPROBE_ALLOCATEMDL = 0x00000010;

        public const uint KSPROBE_PROBEANDLOCK = 0x00000020;

        public const uint KSPROBE_SYSTEMADDRESS = 0x00000040;

        public const uint KSPROBE_MODIFY = 0x00000200;

        public const uint KSPROBE_ALLOWFORMATCHANGE = 0x00000080;

        public const uint KSSTREAM_PAGED_DATA = 0x00000000;

        public const uint KSSTREAM_NONPAGED_DATA = 0x00000100;

        public const uint KSSTREAM_SYNCHRONOUS = 0x00001000;

        public const uint KSSTREAM_FAILUREEXCEPTION = 0x00002000;

        public const uint KSEVENT_ENTRY_DELETED = 1;

        public const uint KSEVENT_ENTRY_ONESHOT = 2;

        public const uint KSEVENT_ENTRY_BUFFERED = 4;

        public const uint KSDISPATCH_FASTIO = 0x80000000;

        public const uint KSCREATE_ITEM_SECURITYCHANGED = 0x00000001;

        public const uint KSCREATE_ITEM_WILDCARD = 0x00000002;

        public const uint KSCREATE_ITEM_NOPARAMETERS = 0x00000004;

        public const uint KSCREATE_ITEM_FREEONSTOP = 0x00000008;

        public const uint BUS_INTERFACE_REFERENCE_VERSION = 0x100;

        public const uint IOCTL_KS_HANDSHAKE = ((FILE_DEVICE_KS) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x007) << 2) | (METHOD_NEITHER);

        public const uint MIN_DEV_VER_FOR_QI = 0x100;

        public const uint KSDEVICE_DESCRIPTOR_VERSION = 0x100;

        public const uint KSDEVICE_DESCRIPTOR_VERSION_2 = 0x110;

        public const uint MIN_DEV_VER_FOR_FLAGS = 0x110;

        public const uint KSDEVICE_FLAG_ENABLE_REMOTE_WAKEUP = 0x00000001;

        public const uint KSDEVICE_FLAG_LOWPOWER_PASSTHROUGH = 0x00000002;

        public const uint KSDEVICE_FLAG_ENABLE_QUERYINTERFACE = 0x00000004;

        public const uint KSFILTER_FLAG_DISPATCH_LEVEL_PROCESSING = 0x00000001;

        public const uint KSFILTER_FLAG_CRITICAL_PROCESSING = 0x00000002;

        public const uint KSFILTER_FLAG_HYPERCRITICAL_PROCESSING = 0x00000004;

        public const uint KSFILTER_FLAG_RECEIVE_ZERO_LENGTH_SAMPLES = 0x00000008;

        public const uint KSFILTER_FLAG_DENY_USERMODE_ACCESS = 0x80000000;

        public const uint KSFILTER_FLAG_PRIORITIZE_REFERENCEGUID = 0x00000010;

        public const uint KSPIN_FLAG_ASYNCHRONOUS_PROCESSING = 0x00000008;

        public const uint KSPIN_FLAG_DO_NOT_INITIATE_PROCESSING = 0x00000010;

        public const uint KSPIN_FLAG_INITIATE_PROCESSING_ON_EVERY_ARRIVAL = 0x00000020;

        public const uint KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING = 0x00000040;

        public const uint KSPIN_FLAG_ENFORCE_FIFO = 0x00000080;

        public const uint KSPIN_FLAG_GENERATE_MAPPINGS = 0x00000100;

        public const uint KSPIN_FLAG_DISTINCT_TRAILING_EDGE = 0x00000200;

        public const uint KSPIN_FLAG_PROCESS_IN_RUN_STATE_ONLY = 0x00010000;

        public const uint KSPIN_FLAG_SPLITTER = 0x00020000;

        public const uint KSPIN_FLAG_USE_STANDARD_TRANSPORT = 0x00040000;

        public const uint KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT = 0x00080000;

        public const uint KSPIN_FLAG_FIXED_FORMAT = 0x00100000;

        public const uint KSPIN_FLAG_GENERATE_EOS_EVENTS = 0x00200000;

        public const uint KSPIN_FLAG_IMPLEMENT_CLOCK = 0x00400000;

        public const uint KSPIN_FLAG_SOME_FRAMES_REQUIRED_FOR_PROCESSING = 0x00800000;

        public const uint KSPIN_FLAG_PROCESS_IF_ANY_IN_RUN_STATE = 0x01000000;

        public const uint KSPIN_FLAG_DENY_USERMODE_ACCESS = 0x80000000;

        public static readonly Guid IID_IKsFastClock__scanned__ = new Guid(0xc9902485, 0xc180, 0x11d2, 0x84, 0x73, 0xd4, 0x23, 0x94, 0x45, 0x9e, 0x5e);

        public static readonly Guid IID_IKsDeviceFunctions__scanned__ = new Guid(0xe234f2e2, 0xbd69, 0x4f8c, 0xb3, 0xf2, 0x7c, 0xd7, 0x9e, 0xd4, 0x66, 0xbd);

        [NativeTypeName("LPCWSTR")]
        public const int RT_STRING = 6;

        [NativeTypeName("LPCWSTR")]
        public const int RT_RCDATA = 10;

        public const uint MCIERR_INVALID_DEVICE_ID = MCIERR_BASE + 1;

        public const uint MCIERR_UNRECOGNIZED_KEYWORD = MCIERR_BASE + 3;

        public const uint MCIERR_UNRECOGNIZED_COMMAND = MCIERR_BASE + 5;

        public const uint MCIERR_HARDWARE = MCIERR_BASE + 6;

        public const uint MCIERR_INVALID_DEVICE_NAME = MCIERR_BASE + 7;

        public const uint MCIERR_OUT_OF_MEMORY = MCIERR_BASE + 8;

        public const uint MCIERR_DEVICE_OPEN = MCIERR_BASE + 9;

        public const uint MCIERR_CANNOT_LOAD_DRIVER = MCIERR_BASE + 10;

        public const uint MCIERR_MISSING_COMMAND_STRING = MCIERR_BASE + 11;

        public const uint MCIERR_PARAM_OVERFLOW = MCIERR_BASE + 12;

        public const uint MCIERR_MISSING_STRING_ARGUMENT = MCIERR_BASE + 13;

        public const uint MCIERR_BAD_INTEGER = MCIERR_BASE + 14;

        public const uint MCIERR_PARSER_INTERNAL = MCIERR_BASE + 15;

        public const uint MCIERR_DRIVER_INTERNAL = MCIERR_BASE + 16;

        public const uint MCIERR_MISSING_PARAMETER = MCIERR_BASE + 17;

        public const uint MCIERR_UNSUPPORTED_FUNCTION = MCIERR_BASE + 18;

        public const uint MCIERR_FILE_NOT_FOUND = MCIERR_BASE + 19;

        public const uint MCIERR_DEVICE_NOT_READY = MCIERR_BASE + 20;

        public const uint MCIERR_INTERNAL = MCIERR_BASE + 21;

        public const uint MCIERR_DRIVER = MCIERR_BASE + 22;

        public const uint MCIERR_CANNOT_USE_ALL = MCIERR_BASE + 23;

        public const uint MCIERR_MULTIPLE = MCIERR_BASE + 24;

        public const uint MCIERR_EXTENSION_NOT_FOUND = MCIERR_BASE + 25;

        public const uint MCIERR_OUTOFRANGE = MCIERR_BASE + 26;

        public const uint MCIERR_FLAGS_NOT_COMPATIBLE = MCIERR_BASE + 28;

        public const uint MCIERR_FILE_NOT_SAVED = MCIERR_BASE + 30;

        public const uint MCIERR_DEVICE_TYPE_REQUIRED = MCIERR_BASE + 31;

        public const uint MCIERR_DEVICE_LOCKED = MCIERR_BASE + 32;

        public const uint MCIERR_DUPLICATE_ALIAS = MCIERR_BASE + 33;

        public const uint MCIERR_BAD_CONSTANT = MCIERR_BASE + 34;

        public const uint MCIERR_MUST_USE_SHAREABLE = MCIERR_BASE + 35;

        public const uint MCIERR_MISSING_DEVICE_NAME = MCIERR_BASE + 36;

        public const uint MCIERR_BAD_TIME_FORMAT = MCIERR_BASE + 37;

        public const uint MCIERR_NO_CLOSING_QUOTE = MCIERR_BASE + 38;

        public const uint MCIERR_DUPLICATE_FLAGS = MCIERR_BASE + 39;

        public const uint MCIERR_INVALID_FILE = MCIERR_BASE + 40;

        public const uint MCIERR_NULL_PARAMETER_BLOCK = MCIERR_BASE + 41;

        public const uint MCIERR_UNNAMED_RESOURCE = MCIERR_BASE + 42;

        public const uint MCIERR_NEW_REQUIRES_ALIAS = MCIERR_BASE + 43;

        public const uint MCIERR_NOTIFY_ON_AUTO_OPEN = MCIERR_BASE + 44;

        public const uint MCIERR_NO_ELEMENT_ALLOWED = MCIERR_BASE + 45;

        public const uint MCIERR_NONAPPLICABLE_FUNCTION = MCIERR_BASE + 46;

        public const uint MCIERR_ILLEGAL_FOR_AUTO_OPEN = MCIERR_BASE + 47;

        public const uint MCIERR_FILENAME_REQUIRED = MCIERR_BASE + 48;

        public const uint MCIERR_EXTRA_CHARACTERS = MCIERR_BASE + 49;

        public const uint MCIERR_DEVICE_NOT_INSTALLED = MCIERR_BASE + 50;

        public const uint MCIERR_GET_CD = MCIERR_BASE + 51;

        public const uint MCIERR_SET_CD = MCIERR_BASE + 52;

        public const uint MCIERR_SET_DRIVE = MCIERR_BASE + 53;

        public const uint MCIERR_DEVICE_LENGTH = MCIERR_BASE + 54;

        public const uint MCIERR_DEVICE_ORD_LENGTH = MCIERR_BASE + 55;

        public const uint MCIERR_NO_INTEGER = MCIERR_BASE + 56;

        public const uint MCIERR_WAVE_OUTPUTSINUSE = MCIERR_BASE + 64;

        public const uint MCIERR_WAVE_SETOUTPUTINUSE = MCIERR_BASE + 65;

        public const uint MCIERR_WAVE_INPUTSINUSE = MCIERR_BASE + 66;

        public const uint MCIERR_WAVE_SETINPUTINUSE = MCIERR_BASE + 67;

        public const uint MCIERR_WAVE_OUTPUTUNSPECIFIED = MCIERR_BASE + 68;

        public const uint MCIERR_WAVE_INPUTUNSPECIFIED = MCIERR_BASE + 69;

        public const uint MCIERR_WAVE_OUTPUTSUNSUITABLE = MCIERR_BASE + 70;

        public const uint MCIERR_WAVE_SETOUTPUTUNSUITABLE = MCIERR_BASE + 71;

        public const uint MCIERR_WAVE_INPUTSUNSUITABLE = MCIERR_BASE + 72;

        public const uint MCIERR_WAVE_SETINPUTUNSUITABLE = MCIERR_BASE + 73;

        public const uint MCIERR_SEQ_DIV_INCOMPATIBLE = MCIERR_BASE + 80;

        public const uint MCIERR_SEQ_PORT_INUSE = MCIERR_BASE + 81;

        public const uint MCIERR_SEQ_PORT_NONEXISTENT = MCIERR_BASE + 82;

        public const uint MCIERR_SEQ_PORT_MAPNODEVICE = MCIERR_BASE + 83;

        public const uint MCIERR_SEQ_PORT_MISCERROR = MCIERR_BASE + 84;

        public const uint MCIERR_SEQ_TIMER = MCIERR_BASE + 85;

        public const uint MCIERR_SEQ_PORTUNSPECIFIED = MCIERR_BASE + 86;

        public const uint MCIERR_SEQ_NOMIDIPRESENT = MCIERR_BASE + 87;

        public const uint MCIERR_NO_WINDOW = MCIERR_BASE + 90;

        public const uint MCIERR_CREATEWINDOW = MCIERR_BASE + 91;

        public const uint MCIERR_FILE_READ = MCIERR_BASE + 92;

        public const uint MCIERR_FILE_WRITE = MCIERR_BASE + 93;

        public const uint MCIERR_NO_IDENTITY = MCIERR_BASE + 94;

        public const uint MCIERR_CUSTOM_DRIVER_BASE = MCIERR_BASE + 256;

        public const uint MCI_OPEN = 0x0803;

        public const uint MCI_CLOSE = 0x0804;

        public const uint MCI_ESCAPE = 0x0805;

        public const uint MCI_PLAY = 0x0806;

        public const uint MCI_SEEK = 0x0807;

        public const uint MCI_STOP = 0x0808;

        public const uint MCI_PAUSE = 0x0809;

        public const uint MCI_INFO = 0x080A;

        public const uint MCI_GETDEVCAPS = 0x080B;

        public const uint MCI_SPIN = 0x080C;

        public const uint MCI_SET = 0x080D;

        public const uint MCI_STEP = 0x080E;

        public const uint MCI_RECORD = 0x080F;

        public const uint MCI_SYSINFO = 0x0810;

        public const uint MCI_BREAK = 0x0811;

        public const uint MCI_SAVE = 0x0813;

        public const uint MCI_STATUS = 0x0814;

        public const uint MCI_CUE = 0x0830;

        public const uint MCI_REALIZE = 0x0840;

        public const uint MCI_WINDOW = 0x0841;

        public const uint MCI_PUT = 0x0842;

        public const uint MCI_WHERE = 0x0843;

        public const uint MCI_FREEZE = 0x0844;

        public const uint MCI_UNFREEZE = 0x0845;

        public const uint MCI_LOAD = 0x0850;

        public const uint MCI_CUT = 0x0851;

        public const uint MCI_COPY = 0x0852;

        public const uint MCI_PASTE = 0x0853;

        public const uint MCI_UPDATE = 0x0854;

        public const uint MCI_RESUME = 0x0855;

        public const uint MCI_DELETE = 0x0856;

        public const uint MCI_USER_MESSAGES = DRV_MCI_FIRST + 0x400;

        public const uint MCI_LAST = 0x0FFF;

        public const uint MCI_DEVTYPE_VCR = 513;

        public const uint MCI_DEVTYPE_VIDEODISC = 514;

        public const uint MCI_DEVTYPE_OVERLAY = 515;

        public const uint MCI_DEVTYPE_CD_AUDIO = 516;

        public const uint MCI_DEVTYPE_DAT = 517;

        public const uint MCI_DEVTYPE_SCANNER = 518;

        public const uint MCI_DEVTYPE_ANIMATION = 519;

        public const uint MCI_DEVTYPE_DIGITAL_VIDEO = 520;

        public const uint MCI_DEVTYPE_OTHER = 521;

        public const uint MCI_DEVTYPE_WAVEFORM_AUDIO = 522;

        public const uint MCI_DEVTYPE_SEQUENCER = 523;

        public const uint MCI_DEVTYPE_FIRST_USER = 0x1000;

        public const uint MCI_MODE_NOT_READY = MCI_STRING_OFFSET + 12;

        public const uint MCI_MODE_STOP = MCI_STRING_OFFSET + 13;

        public const uint MCI_MODE_PLAY = MCI_STRING_OFFSET + 14;

        public const uint MCI_MODE_RECORD = MCI_STRING_OFFSET + 15;

        public const uint MCI_MODE_SEEK = MCI_STRING_OFFSET + 16;

        public const uint MCI_MODE_PAUSE = MCI_STRING_OFFSET + 17;

        public const uint MCI_MODE_OPEN = MCI_STRING_OFFSET + 18;

        public const uint MCI_FORMAT_MILLISECONDS = 0;

        public const uint MCI_FORMAT_HMS = 1;

        public const uint MCI_FORMAT_MSF = 2;

        public const uint MCI_FORMAT_FRAMES = 3;

        public const uint MCI_FORMAT_SMPTE_24 = 4;

        public const uint MCI_FORMAT_SMPTE_25 = 5;

        public const uint MCI_FORMAT_SMPTE_30 = 6;

        public const uint MCI_FORMAT_SMPTE_30DROP = 7;

        public const uint MCI_FORMAT_BYTES = 8;

        public const uint MCI_FORMAT_SAMPLES = 9;

        public const uint MCI_FORMAT_TMSF = 10;

        public const uint MCI_NOTIFY_SUCCESSFUL = 0x0001;

        public const uint MCI_NOTIFY_SUPERSEDED = 0x0002;

        public const uint MCI_NOTIFY_ABORTED = 0x0004;

        public const uint MCI_NOTIFY_FAILURE = 0x0008;

        public const int MCI_NOTIFY = 0x00000001;

        public const int MCI_WAIT = 0x00000002;

        public const int MCI_FROM = 0x00000004;

        public const int MCI_TO = 0x00000008;

        public const int MCI_TRACK = 0x00000010;

        public const int MCI_OPEN_SHAREABLE = 0x00000100;

        public const int MCI_OPEN_ELEMENT = 0x00000200;

        public const int MCI_OPEN_ALIAS = 0x00000400;

        public const int MCI_OPEN_ELEMENT_ID = 0x00000800;

        public const int MCI_OPEN_TYPE_ID = 0x00001000;

        public const int MCI_OPEN_TYPE = 0x00002000;

        public const int MCI_SEEK_TO_START = 0x00000100;

        public const int MCI_SEEK_TO_END = 0x00000200;

        public const int MCI_STATUS_ITEM = 0x00000100;

        public const int MCI_STATUS_START = 0x00000200;

        public const int MCI_STATUS_LENGTH = 0x00000001;

        public const int MCI_STATUS_POSITION = 0x00000002;

        public const int MCI_STATUS_NUMBER_OF_TRACKS = 0x00000003;

        public const int MCI_STATUS_MODE = 0x00000004;

        public const int MCI_STATUS_MEDIA_PRESENT = 0x00000005;

        public const int MCI_STATUS_TIME_FORMAT = 0x00000006;

        public const int MCI_STATUS_READY = 0x00000007;

        public const int MCI_STATUS_CURRENT_TRACK = 0x00000008;

        public const int MCI_INFO_PRODUCT = 0x00000100;

        public const int MCI_INFO_FILE = 0x00000200;

        public const int MCI_INFO_MEDIA_UPC = 0x00000400;

        public const int MCI_INFO_MEDIA_IDENTITY = 0x00000800;

        public const int MCI_INFO_NAME = 0x00001000;

        public const int MCI_INFO_COPYRIGHT = 0x00002000;

        public const int MCI_GETDEVCAPS_ITEM = 0x00000100;

        public const int MCI_GETDEVCAPS_CAN_RECORD = 0x00000001;

        public const int MCI_GETDEVCAPS_HAS_AUDIO = 0x00000002;

        public const int MCI_GETDEVCAPS_HAS_VIDEO = 0x00000003;

        public const int MCI_GETDEVCAPS_DEVICE_TYPE = 0x00000004;

        public const int MCI_GETDEVCAPS_USES_FILES = 0x00000005;

        public const int MCI_GETDEVCAPS_COMPOUND_DEVICE = 0x00000006;

        public const int MCI_GETDEVCAPS_CAN_EJECT = 0x00000007;

        public const int MCI_GETDEVCAPS_CAN_PLAY = 0x00000008;

        public const int MCI_GETDEVCAPS_CAN_SAVE = 0x00000009;

        public const int MCI_SYSINFO_QUANTITY = 0x00000100;

        public const int MCI_SYSINFO_OPEN = 0x00000200;

        public const int MCI_SYSINFO_NAME = 0x00000400;

        public const int MCI_SYSINFO_INSTALLNAME = 0x00000800;

        public const int MCI_SET_DOOR_OPEN = 0x00000100;

        public const int MCI_SET_DOOR_CLOSED = 0x00000200;

        public const int MCI_SET_TIME_FORMAT = 0x00000400;

        public const int MCI_SET_AUDIO = 0x00000800;

        public const int MCI_SET_VIDEO = 0x00001000;

        public const int MCI_SET_ON = 0x00002000;

        public const int MCI_SET_OFF = 0x00004000;

        public const int MCI_SET_AUDIO_ALL = 0x00000000;

        public const int MCI_SET_AUDIO_LEFT = 0x00000001;

        public const int MCI_SET_AUDIO_RIGHT = 0x00000002;

        public const int MCI_BREAK_KEY = 0x00000100;

        public const int MCI_BREAK_HWND = 0x00000200;

        public const int MCI_BREAK_OFF = 0x00000400;

        public const int MCI_RECORD_INSERT = 0x00000100;

        public const int MCI_RECORD_OVERWRITE = 0x00000200;

        public const int MCI_SAVE_FILE = 0x00000100;

        public const int MCI_LOAD_FILE = 0x00000100;

        public const uint MCI_VD_MODE_PARK = MCI_VD_OFFSET + 1;

        public const uint MCI_VD_MEDIA_CLV = MCI_VD_OFFSET + 2;

        public const uint MCI_VD_MEDIA_CAV = MCI_VD_OFFSET + 3;

        public const uint MCI_VD_MEDIA_OTHER = MCI_VD_OFFSET + 4;

        public const uint MCI_VD_FORMAT_TRACK = 0x4001;

        public const int MCI_VD_PLAY_REVERSE = 0x00010000;

        public const int MCI_VD_PLAY_FAST = 0x00020000;

        public const int MCI_VD_PLAY_SPEED = 0x00040000;

        public const int MCI_VD_PLAY_SCAN = 0x00080000;

        public const int MCI_VD_PLAY_SLOW = 0x00100000;

        public const int MCI_VD_SEEK_REVERSE = 0x00010000;

        public const int MCI_VD_STATUS_SPEED = 0x00004002;

        public const int MCI_VD_STATUS_FORWARD = 0x00004003;

        public const int MCI_VD_STATUS_MEDIA_TYPE = 0x00004004;

        public const int MCI_VD_STATUS_SIDE = 0x00004005;

        public const int MCI_VD_STATUS_DISC_SIZE = 0x00004006;

        public const int MCI_VD_GETDEVCAPS_CLV = 0x00010000;

        public const int MCI_VD_GETDEVCAPS_CAV = 0x00020000;

        public const int MCI_VD_SPIN_UP = 0x00010000;

        public const int MCI_VD_SPIN_DOWN = 0x00020000;

        public const int MCI_VD_GETDEVCAPS_CAN_REVERSE = 0x00004002;

        public const int MCI_VD_GETDEVCAPS_FAST_RATE = 0x00004003;

        public const int MCI_VD_GETDEVCAPS_SLOW_RATE = 0x00004004;

        public const int MCI_VD_GETDEVCAPS_NORMAL_RATE = 0x00004005;

        public const int MCI_VD_STEP_FRAMES = 0x00010000;

        public const int MCI_VD_STEP_REVERSE = 0x00020000;

        public const int MCI_VD_ESCAPE_STRING = 0x00000100;

        public const int MCI_CDA_STATUS_TYPE_TRACK = 0x00004001;

        public const uint MCI_CDA_TRACK_AUDIO = MCI_CD_OFFSET + 0;

        public const uint MCI_CDA_TRACK_OTHER = MCI_CD_OFFSET + 1;

        public const uint MCI_WAVE_PCM = MCI_WAVE_OFFSET + 0;

        public const uint MCI_WAVE_MAPPER = MCI_WAVE_OFFSET + 1;

        public const int MCI_WAVE_OPEN_BUFFER = 0x00010000;

        public const int MCI_WAVE_SET_FORMATTAG = 0x00010000;

        public const int MCI_WAVE_SET_CHANNELS = 0x00020000;

        public const int MCI_WAVE_SET_SAMPLESPERSEC = 0x00040000;

        public const int MCI_WAVE_SET_AVGBYTESPERSEC = 0x00080000;

        public const int MCI_WAVE_SET_BLOCKALIGN = 0x00100000;

        public const int MCI_WAVE_SET_BITSPERSAMPLE = 0x00200000;

        public const int MCI_WAVE_INPUT = 0x00400000;

        public const int MCI_WAVE_OUTPUT = 0x00800000;

        public const int MCI_WAVE_STATUS_FORMATTAG = 0x00004001;

        public const int MCI_WAVE_STATUS_CHANNELS = 0x00004002;

        public const int MCI_WAVE_STATUS_SAMPLESPERSEC = 0x00004003;

        public const int MCI_WAVE_STATUS_AVGBYTESPERSEC = 0x00004004;

        public const int MCI_WAVE_STATUS_BLOCKALIGN = 0x00004005;

        public const int MCI_WAVE_STATUS_BITSPERSAMPLE = 0x00004006;

        public const int MCI_WAVE_STATUS_LEVEL = 0x00004007;

        public const int MCI_WAVE_SET_ANYINPUT = 0x04000000;

        public const int MCI_WAVE_SET_ANYOUTPUT = 0x08000000;

        public const int MCI_WAVE_GETDEVCAPS_INPUTS = 0x00004001;

        public const int MCI_WAVE_GETDEVCAPS_OUTPUTS = 0x00004002;

        public const uint MCI_SEQ_FORMAT_SONGPTR = 0x4001;

        public const uint MCI_SEQ_FILE = 0x4002;

        public const uint MCI_SEQ_MIDI = 0x4003;

        public const uint MCI_SEQ_SMPTE = 0x4004;

        public const uint MCI_SEQ_NONE = 65533;

        public const uint MCI_SEQ_MAPPER = 65535;

        public const int MCI_SEQ_STATUS_TEMPO = 0x00004002;

        public const int MCI_SEQ_STATUS_PORT = 0x00004003;

        public const int MCI_SEQ_STATUS_SLAVE = 0x00004007;

        public const int MCI_SEQ_STATUS_MASTER = 0x00004008;

        public const int MCI_SEQ_STATUS_OFFSET = 0x00004009;

        public const int MCI_SEQ_STATUS_DIVTYPE = 0x0000400A;

        public const int MCI_SEQ_STATUS_NAME = 0x0000400B;

        public const int MCI_SEQ_STATUS_COPYRIGHT = 0x0000400C;

        public const int MCI_SEQ_SET_TEMPO = 0x00010000;

        public const int MCI_SEQ_SET_PORT = 0x00020000;

        public const int MCI_SEQ_SET_SLAVE = 0x00040000;

        public const int MCI_SEQ_SET_MASTER = 0x00080000;

        public const int MCI_SEQ_SET_OFFSET = 0x01000000;

        public const int MCI_ANIM_OPEN_WS = 0x00010000;

        public const int MCI_ANIM_OPEN_PARENT = 0x00020000;

        public const int MCI_ANIM_OPEN_NOSTATIC = 0x00040000;

        public const int MCI_ANIM_PLAY_SPEED = 0x00010000;

        public const int MCI_ANIM_PLAY_REVERSE = 0x00020000;

        public const int MCI_ANIM_PLAY_FAST = 0x00040000;

        public const int MCI_ANIM_PLAY_SLOW = 0x00080000;

        public const int MCI_ANIM_PLAY_SCAN = 0x00100000;

        public const int MCI_ANIM_STEP_REVERSE = 0x00010000;

        public const int MCI_ANIM_STEP_FRAMES = 0x00020000;

        public const int MCI_ANIM_STATUS_SPEED = 0x00004001;

        public const int MCI_ANIM_STATUS_FORWARD = 0x00004002;

        public const int MCI_ANIM_STATUS_HWND = 0x00004003;

        public const int MCI_ANIM_STATUS_HPAL = 0x00004004;

        public const int MCI_ANIM_STATUS_STRETCH = 0x00004005;

        public const int MCI_ANIM_INFO_TEXT = 0x00010000;

        public const int MCI_ANIM_GETDEVCAPS_CAN_REVERSE = 0x00004001;

        public const int MCI_ANIM_GETDEVCAPS_FAST_RATE = 0x00004002;

        public const int MCI_ANIM_GETDEVCAPS_SLOW_RATE = 0x00004003;

        public const int MCI_ANIM_GETDEVCAPS_NORMAL_RATE = 0x00004004;

        public const int MCI_ANIM_GETDEVCAPS_PALETTES = 0x00004006;

        public const int MCI_ANIM_GETDEVCAPS_CAN_STRETCH = 0x00004007;

        public const int MCI_ANIM_GETDEVCAPS_MAX_WINDOWS = 0x00004008;

        public const int MCI_ANIM_REALIZE_NORM = 0x00010000;

        public const int MCI_ANIM_REALIZE_BKGD = 0x00020000;

        public const int MCI_ANIM_WINDOW_HWND = 0x00010000;

        public const int MCI_ANIM_WINDOW_STATE = 0x00040000;

        public const int MCI_ANIM_WINDOW_TEXT = 0x00080000;

        public const int MCI_ANIM_WINDOW_ENABLE_STRETCH = 0x00100000;

        public const int MCI_ANIM_WINDOW_DISABLE_STRETCH = 0x00200000;

        public const int MCI_ANIM_WINDOW_DEFAULT = 0x00000000;

        public const int MCI_ANIM_RECT = 0x00010000;

        public const int MCI_ANIM_PUT_SOURCE = 0x00020000;

        public const int MCI_ANIM_PUT_DESTINATION = 0x00040000;

        public const int MCI_ANIM_WHERE_SOURCE = 0x00020000;

        public const int MCI_ANIM_WHERE_DESTINATION = 0x00040000;

        public const int MCI_ANIM_UPDATE_HDC = 0x00020000;

        public const int MCI_OVLY_OPEN_WS = 0x00010000;

        public const int MCI_OVLY_OPEN_PARENT = 0x00020000;

        public const int MCI_OVLY_STATUS_HWND = 0x00004001;

        public const int MCI_OVLY_STATUS_STRETCH = 0x00004002;

        public const int MCI_OVLY_INFO_TEXT = 0x00010000;

        public const int MCI_OVLY_GETDEVCAPS_CAN_STRETCH = 0x00004001;

        public const int MCI_OVLY_GETDEVCAPS_CAN_FREEZE = 0x00004002;

        public const int MCI_OVLY_GETDEVCAPS_MAX_WINDOWS = 0x00004003;

        public const int MCI_OVLY_WINDOW_HWND = 0x00010000;

        public const int MCI_OVLY_WINDOW_STATE = 0x00040000;

        public const int MCI_OVLY_WINDOW_TEXT = 0x00080000;

        public const int MCI_OVLY_WINDOW_ENABLE_STRETCH = 0x00100000;

        public const int MCI_OVLY_WINDOW_DISABLE_STRETCH = 0x00200000;

        public const int MCI_OVLY_WINDOW_DEFAULT = 0x00000000;

        public const int MCI_OVLY_RECT = 0x00010000;

        public const int MCI_OVLY_PUT_SOURCE = 0x00020000;

        public const int MCI_OVLY_PUT_DESTINATION = 0x00040000;

        public const int MCI_OVLY_PUT_FRAME = 0x00080000;

        public const int MCI_OVLY_PUT_VIDEO = 0x00100000;

        public const int MCI_OVLY_WHERE_SOURCE = 0x00020000;

        public const int MCI_OVLY_WHERE_DESTINATION = 0x00040000;

        public const int MCI_OVLY_WHERE_FRAME = 0x00080000;

        public const int MCI_OVLY_WHERE_VIDEO = 0x00100000;

        public const uint ENDPOINT_FORMAT_RESET_MIX_ONLY = 0x00000001;

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_DESTROYED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0100));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_OUT_OF_ORDER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0101));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_RESOURCES_INVALIDATED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0102));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_NO_MORE_OBJECTS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0103));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_PROPERTY_NOT_SUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0104));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_ERRORS_IN_OBJECT_CALLS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0105));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_METADATA_FORMAT_NOT_SUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0106));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_STREAM_NOT_AVAILABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0107));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_INVALID_LICENSE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0108));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_STREAM_NOT_STOPPED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x010a));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_STATIC_OBJECT_NOT_AVAILABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x010b));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_OBJECT_ALREADY_ACTIVE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x010c));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUDCLNT_E_INTERNAL = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x010d));

        public const uint DEVICE_STATE_ACTIVE = 0x00000001;

        public const uint DEVICE_STATE_DISABLED = 0x00000002;

        public const uint DEVICE_STATE_NOTPRESENT = 0x00000004;

        public const uint DEVICE_STATE_UNPLUGGED = 0x00000008;

        public const uint DEVICE_STATEMASK_ALL = 0x0000000f;

        public const uint ENDPOINT_SYSFX_ENABLED = 0x00000000;

        public const uint ENDPOINT_SYSFX_DISABLED = 0x00000001;

        public static readonly Guid DEVINTERFACE_AUDIO_RENDER__scanned__ = new Guid(0xe6327cad, 0xdcec, 0x4949, 0xae, 0x8a, 0x99, 0x1e, 0x97, 0x6a, 0x79, 0xd2);

        public static readonly Guid DEVINTERFACE_AUDIO_CAPTURE__scanned__ = new Guid(0x2eef81be, 0x33fa, 0x4800, 0x96, 0x70, 0x1c, 0xd4, 0x74, 0x97, 0x2c, 0x3f);

        public static readonly Guid DEVINTERFACE_MIDI_OUTPUT__scanned__ = new Guid(0x6dc23320, 0xab33, 0x4ce4, 0x80, 0xd4, 0xbb, 0xb3, 0xeb, 0xbf, 0x28, 0x14);

        public static readonly Guid DEVINTERFACE_MIDI_INPUT__scanned__ = new Guid(0x504be32c, 0xccf6, 0x4d2c, 0xb7, 0x3f, 0x6f, 0x8b, 0x37, 0x47, 0xe2, 0x2b);

        public static readonly Guid EVENTCONTEXT_VOLUMESLIDER__scanned__ = new Guid(0xE2C2E9DE,0x09B1,0x4B04,0x84, 0xE5, 0x07, 0x93, 0x12, 0x25, 0xEE, 0x04);

        public const uint AUDIOCLOCK_CHARACTERISTIC_FIXED_FREQ = 0x00000001;

        public const uint AMBISONICS_PARAM_VERSION_1 = 1;

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_NOT_INITIALIZED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x001));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_ALREADY_INITIALIZED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x002));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_WRONG_ENDPOINT_TYPE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x003));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_DEVICE_INVALIDATED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x004));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_NOT_STOPPED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x005));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_BUFFER_TOO_LARGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x006));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_OUT_OF_ORDER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x007));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_UNSUPPORTED_FORMAT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x008));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_INVALID_SIZE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x009));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_DEVICE_IN_USE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x00a));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_BUFFER_OPERATION_PENDING = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x00b));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_THREAD_NOT_REGISTERED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x00c));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_EXCLUSIVE_MODE_NOT_ALLOWED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x00e));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_ENDPOINT_CREATE_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x00f));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_SERVICE_NOT_RUNNING = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x010));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_EVENTHANDLE_NOT_EXPECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x011));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_EXCLUSIVE_MODE_ONLY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x012));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_BUFDURATION_PERIOD_NOT_EQUAL = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x013));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_EVENTHANDLE_NOT_SET = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x014));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_INCORRECT_BUFFER_SIZE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x015));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_BUFFER_SIZE_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x016));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_CPUUSAGE_EXCEEDED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x017));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_BUFFER_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x018));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x019));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_INVALID_DEVICE_PERIOD = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x020));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_INVALID_STREAM_FLAG = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x021));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_ENDPOINT_OFFLOAD_NOT_CAPABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x022));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_OUT_OF_OFFLOAD_RESOURCES = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x023));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_OFFLOAD_MODE_ONLY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x024));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_NONOFFLOAD_MODE_ONLY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x025));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_RESOURCES_INVALIDATED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x026));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_RAW_MODE_UNSUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x027));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_ENGINE_PERIODICITY_LOCKED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x028));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_ENGINE_FORMAT_LOCKED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x029));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_HEADTRACKING_ENABLED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x030));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_E_HEADTRACKING_UNSUPPORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x040));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_S_BUFFER_EMPTY = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x001));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_S_THREAD_ALREADY_REGISTERED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x002));

        [NativeTypeName("HRESULT")]
        public const int AUDCLNT_S_POSITION_STALLED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x003));

        public const uint ENDPOINT_HARDWARE_SUPPORT_VOLUME = 0x00000001;

        public const uint ENDPOINT_HARDWARE_SUPPORT_MUTE = 0x00000002;

        public const uint ENDPOINT_HARDWARE_SUPPORT_METER = 0x00000004;

        public const uint SPATIAL_AUDIO_STANDARD_COMMANDS_START = 200;

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_COMMAND_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0200));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_OBJECT_NOT_INITIALIZED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0201));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_INVALID_ARGS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0202));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_METADATA_FORMAT_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0203));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_VALUE_BUFFER_INCORRECT_SIZE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0204));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_MEMORY_BOUNDS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0205));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_NO_MORE_COMMANDS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0206));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_BUFFER_ALREADY_ATTACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0207));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_BUFFER_NOT_ATTACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0208));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_FRAMECOUNT_OUT_OF_RANGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0209));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_NO_ITEMS_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0210));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_ITEM_COPY_OVERFLOW = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0211));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0212));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_ITEMS_ALREADY_OPEN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0213));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_ATTACH_FAILED_INTERNAL_BUFFER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0214));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_DETACH_FAILED_INTERNAL_BUFFER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0215));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_NO_BUFFER_ATTACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0216));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_NO_MORE_ITEMS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0217));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_FRAMEOFFSET_OUT_OF_RANGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0218));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_ITEM_MUST_HAVE_COMMANDS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0219));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_NO_ITEMOFFSET_WRITTEN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0220));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_NO_ITEMS_WRITTEN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0221));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_COMMAND_ALREADY_WRITTEN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0222));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_FORMAT_MISMATCH = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0223));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_BUFFER_STILL_ATTACHED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0224));

        [NativeTypeName("HRESULT")]
        public const int SPTLAUD_MD_CLNT_E_ITEMS_LOCKED_FOR_WRITING = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_AUDCLNT)) << 16) | (int)(0x0225));

    }
}
