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


namespace Windows.Win32.Storage.Xps
{
    public static partial class Apis
    {
        [NativeTypeName("HRESULT")]
        public const int XPS_E_SIGREQUESTID_DUP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(901));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_PACKAGE_NOT_OPENED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(902));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_PACKAGE_ALREADY_OPENED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(903));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_SIGNATUREID_DUP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(904));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MARKUP_COMPATIBILITY_ELEMENTS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(905));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_OBJECT_DETACHED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(906));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_SIGNATUREBLOCK_MARKUP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(907));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_NUMBER_OF_POINTS_IN_CURVE_SEGMENTS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x600));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_ABSOLUTE_REFERENCE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x601));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_NUMBER_OF_COLOR_CHANNELS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x602));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_LANGUAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x000));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_NAME = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x001));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_RESOURCE_KEY = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x002));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_PAGE_SIZE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x003));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_BLEED_BOX = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x004));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_THUMBNAIL_IMAGE_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x005));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_LOOKUP_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x006));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_FLOAT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x007));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_UNEXPECTED_CONTENT_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x008));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_FONT_URI = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x00a));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_CONTENT_BOX = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x00b));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_MARKUP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x00c));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_XML_ENCODING = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x00d));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_CONTENT_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x00e));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INVALID_OBFUSCATED_FONT_URI = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x00f));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_UNEXPECTED_RELATIONSHIP_TYPE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x010));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_UNEXPECTED_RESTRICTED_FONT_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x011));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_NAME = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x100));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_LOOKUP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x101));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_GLYPHS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x102));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_SEGMENT_DATA = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x103));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_COLORPROFILE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x104));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_RELATIONSHIP_TARGET = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x105));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_RESOURCE_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x106));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_FONTURI = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x107));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_DOCUMENTSEQUENCE_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x108));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_DOCUMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x109));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_REFERRED_DOCUMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x10a));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_REFERRED_PAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x10b));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_PAGE_IN_DOCUMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x10c));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_PAGE_IN_PAGEREFERENCE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x10d));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_IMAGE_IN_IMAGEBRUSH = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x10e));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_RESOURCE_KEY = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x10f));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_PART_REFERENCE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x110));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_RESTRICTED_FONT_RELATIONSHIP = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x111));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_DISCARDCONTROL = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x112));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MISSING_PART_STREAM = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x113));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_UNAVAILABLE_PACKAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x114));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_DUPLICATE_RESOURCE_KEYS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x200));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_RESOURCES = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x201));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_DOCUMENTSEQUENCE_RELATIONSHIPS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x202));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_THUMBNAILS_ON_PAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x203));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_THUMBNAILS_ON_PACKAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x204));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_PRINTTICKETS_ON_PAGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x205));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_PRINTTICKETS_ON_DOCUMENT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x206));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_PRINTTICKETS_ON_DOCUMENTSEQUENCE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x207));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MULTIPLE_REFERENCES_TO_PART = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x208));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_DUPLICATE_NAMES = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x209));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_STRING_TOO_LONG = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x300));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_TOO_MANY_INDICES = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x301));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MAPPING_OUT_OF_ORDER = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x302));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MAPPING_OUTSIDE_STRING = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x303));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_MAPPING_OUTSIDE_INDICES = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x304));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_CARET_OUTSIDE_STRING = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x305));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_CARET_OUT_OF_ORDER = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x306));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_ODD_BIDILEVEL = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x307));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_ONE_TO_ONE_MAPPING_EXPECTED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x308));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_RESTRICTED_FONT_NOT_OBFUSCATED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x309));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_NEGATIVE_FLOAT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x30a));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_XKEY_ATTR_PRESENT_OUTSIDE_RES_DICT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x400));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_DICTIONARY_ITEM_NAMED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x401));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_NESTED_REMOTE_DICTIONARY = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x402));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_INDEX_OUT_OF_RANGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x500));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_VISUAL_CIRCULAR_REF = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x501));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_NO_CUSTOM_OBJECTS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x502));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_ALREADY_OWNED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x503));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_RESOURCE_NOT_OWNED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x504));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_UNEXPECTED_COLORPROFILE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x505));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_COLOR_COMPONENT_OUT_OF_RANGE = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x506));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_BOTH_PATHFIGURE_AND_ABBR_SYNTAX_PRESENT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x507));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_BOTH_RESOURCE_AND_SOURCEATTR_PRESENT = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x508));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_BLEED_BOX_PAGE_DIMENSIONS_NOT_IN_SYNC = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x509));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_RELATIONSHIP_EXTERNAL = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x50a));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_NOT_ENOUGH_GRADIENT_STOPS = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x50b));

        [NativeTypeName("HRESULT")]
        public const int XPS_E_PACKAGE_WRITER_NOT_CLOSED = unchecked((int)((1) << 31) | (((int)(FACILITY_XPS)) << 16) | (int)(0x50c));

    }
}
