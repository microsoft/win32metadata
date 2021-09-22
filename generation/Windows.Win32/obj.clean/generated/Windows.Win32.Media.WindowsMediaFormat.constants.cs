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


namespace Windows.Win32.Media.WindowsMediaFormat
{
    public static partial class Apis
    {
        public const uint WMT_VIDEOIMAGE_SAMPLE_INPUT_FRAME = 1;

        public const uint WMT_VIDEOIMAGE_SAMPLE_OUTPUT_FRAME = 2;

        public const uint WMT_VIDEOIMAGE_SAMPLE_USES_CURRENT_INPUT_FRAME = 4;

        public const uint WMT_VIDEOIMAGE_SAMPLE_USES_PREVIOUS_INPUT_FRAME = 8;

        public const uint WMT_VIDEOIMAGE_SAMPLE_MOTION = 1;

        public const uint WMT_VIDEOIMAGE_SAMPLE_ROTATION = 2;

        public const uint WMT_VIDEOIMAGE_SAMPLE_BLENDING = 4;

        public const uint WMT_VIDEOIMAGE_SAMPLE_ADV_BLENDING = 8;

        public const int WMT_VIDEOIMAGE_INTEGER_DENOMINATOR = 65536;

        public const uint WMT_VIDEOIMAGE_MAGIC_NUMBER = 0x1d4a45f2;

        public const uint WMT_VIDEOIMAGE_MAGIC_NUMBER_2 = 0x1d4a45f3;

        public const uint WMT_VIDEOIMAGE_TRANSITION_BOW_TIE = 11;

        public const uint WMT_VIDEOIMAGE_TRANSITION_CIRCLE = 12;

        public const uint WMT_VIDEOIMAGE_TRANSITION_CROSS_FADE = 13;

        public const uint WMT_VIDEOIMAGE_TRANSITION_DIAGONAL = 14;

        public const uint WMT_VIDEOIMAGE_TRANSITION_DIAMOND = 15;

        public const uint WMT_VIDEOIMAGE_TRANSITION_FADE_TO_COLOR = 16;

        public const uint WMT_VIDEOIMAGE_TRANSITION_FILLED_V = 17;

        public const uint WMT_VIDEOIMAGE_TRANSITION_FLIP = 18;

        public const uint WMT_VIDEOIMAGE_TRANSITION_INSET = 19;

        public const uint WMT_VIDEOIMAGE_TRANSITION_IRIS = 20;

        public const uint WMT_VIDEOIMAGE_TRANSITION_PAGE_ROLL = 21;

        public const uint WMT_VIDEOIMAGE_TRANSITION_RECTANGLE = 23;

        public const uint WMT_VIDEOIMAGE_TRANSITION_REVEAL = 24;

        public const uint WMT_VIDEOIMAGE_TRANSITION_SLIDE = 27;

        public const uint WMT_VIDEOIMAGE_TRANSITION_SPLIT = 29;

        public const uint WMT_VIDEOIMAGE_TRANSITION_STAR = 30;

        public const uint WMT_VIDEOIMAGE_TRANSITION_WHEEL = 31;

        public const uint WM_SampleExtension_ContentType_Size = 1;

        public const uint WM_SampleExtension_PixelAspectRatio_Size = 2;

        public const uint WM_SampleExtension_Timecode_Size = 14;

        public const uint WM_SampleExtension_SampleDuration_Size = 2;

        public const uint WM_SampleExtension_ChromaLocation_Size = 1;

        public const uint WM_SampleExtension_ColorSpaceInfo_Size = 3;

        public const uint WM_CT_REPEAT_FIRST_FIELD = 0x10;

        public const uint WM_CT_BOTTOM_FIELD_FIRST = 0x20;

        public const uint WM_CT_TOP_FIELD_FIRST = 0x40;

        public const uint WM_CT_INTERLACED = 0x80;

        public const uint WM_CL_INTERLACED420 = 0;

        public const uint WM_CL_PROGRESSIVE420 = 1;

        public const uint WM_MAX_VIDEO_STREAMS = 0x3f;

        public const uint WM_MAX_STREAMS = 0x3f;

        public const uint WMDRM_IMPORT_INIT_STRUCT_DEFINED = 1;

        public const uint DRM_OPL_TYPES = 1;

    }
}
