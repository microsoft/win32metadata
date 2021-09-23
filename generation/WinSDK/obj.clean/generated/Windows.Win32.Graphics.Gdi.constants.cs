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


namespace Windows.Win32.Graphics.Gdi
{
    public static partial class Apis
    {
        public const int GDI_ERROR = unchecked((int)0xFFFFFFFF);

        public const uint ERROR = 0;

        public const uint NULLREGION = 1;

        public const uint SIMPLEREGION = 2;

        public const uint COMPLEXREGION = 3;

        public const uint MAXSTRETCHBLTMODE = 4;

        public const uint POLYFILL_LAST = 2;

        public const uint LAYOUT_BTT = 0x00000002;

        public const uint LAYOUT_VBH = 0x00000004;

        public const uint ASPECT_FILTERING = 0x0001;

        public const uint META_SETBKCOLOR = 0x0201;

        public const uint META_SETBKMODE = 0x0102;

        public const uint META_SETMAPMODE = 0x0103;

        public const uint META_SETROP2 = 0x0104;

        public const uint META_SETRELABS = 0x0105;

        public const uint META_SETPOLYFILLMODE = 0x0106;

        public const uint META_SETSTRETCHBLTMODE = 0x0107;

        public const uint META_SETTEXTCHAREXTRA = 0x0108;

        public const uint META_SETTEXTCOLOR = 0x0209;

        public const uint META_SETTEXTJUSTIFICATION = 0x020A;

        public const uint META_SETWINDOWORG = 0x020B;

        public const uint META_SETWINDOWEXT = 0x020C;

        public const uint META_SETVIEWPORTORG = 0x020D;

        public const uint META_SETVIEWPORTEXT = 0x020E;

        public const uint META_OFFSETWINDOWORG = 0x020F;

        public const uint META_SCALEWINDOWEXT = 0x0410;

        public const uint META_OFFSETVIEWPORTORG = 0x0211;

        public const uint META_SCALEVIEWPORTEXT = 0x0412;

        public const uint META_LINETO = 0x0213;

        public const uint META_MOVETO = 0x0214;

        public const uint META_EXCLUDECLIPRECT = 0x0415;

        public const uint META_INTERSECTCLIPRECT = 0x0416;

        public const uint META_ARC = 0x0817;

        public const uint META_ELLIPSE = 0x0418;

        public const uint META_FLOODFILL = 0x0419;

        public const uint META_PIE = 0x081A;

        public const uint META_RECTANGLE = 0x041B;

        public const uint META_ROUNDRECT = 0x061C;

        public const uint META_PATBLT = 0x061D;

        public const uint META_SAVEDC = 0x001E;

        public const uint META_SETPIXEL = 0x041F;

        public const uint META_OFFSETCLIPRGN = 0x0220;

        public const uint META_TEXTOUT = 0x0521;

        public const uint META_BITBLT = 0x0922;

        public const uint META_STRETCHBLT = 0x0B23;

        public const uint META_POLYGON = 0x0324;

        public const uint META_POLYLINE = 0x0325;

        public const uint META_ESCAPE = 0x0626;

        public const uint META_RESTOREDC = 0x0127;

        public const uint META_FILLREGION = 0x0228;

        public const uint META_FRAMEREGION = 0x0429;

        public const uint META_INVERTREGION = 0x012A;

        public const uint META_PAINTREGION = 0x012B;

        public const uint META_SELECTCLIPREGION = 0x012C;

        public const uint META_SELECTOBJECT = 0x012D;

        public const uint META_SETTEXTALIGN = 0x012E;

        public const uint META_CHORD = 0x0830;

        public const uint META_SETMAPPERFLAGS = 0x0231;

        public const uint META_EXTTEXTOUT = 0x0a32;

        public const uint META_SETDIBTODEV = 0x0d33;

        public const uint META_SELECTPALETTE = 0x0234;

        public const uint META_REALIZEPALETTE = 0x0035;

        public const uint META_ANIMATEPALETTE = 0x0436;

        public const uint META_SETPALENTRIES = 0x0037;

        public const uint META_POLYPOLYGON = 0x0538;

        public const uint META_RESIZEPALETTE = 0x0139;

        public const uint META_DIBBITBLT = 0x0940;

        public const uint META_DIBSTRETCHBLT = 0x0b41;

        public const uint META_DIBCREATEPATTERNBRUSH = 0x0142;

        public const uint META_STRETCHDIB = 0x0f43;

        public const uint META_EXTFLOODFILL = 0x0548;

        public const uint META_SETLAYOUT = 0x0149;

        public const uint META_DELETEOBJECT = 0x01f0;

        public const uint META_CREATEPALETTE = 0x00f7;

        public const uint META_CREATEPATTERNBRUSH = 0x01F9;

        public const uint META_CREATEPENINDIRECT = 0x02FA;

        public const uint META_CREATEFONTINDIRECT = 0x02FB;

        public const uint META_CREATEBRUSHINDIRECT = 0x02FC;

        public const uint META_CREATEREGION = 0x06FF;

        public const uint NEWFRAME = 1;

        public const uint ABORTDOC = 2;

        public const uint NEXTBAND = 3;

        public const uint SETCOLORTABLE = 4;

        public const uint GETCOLORTABLE = 5;

        public const uint FLUSHOUTPUT = 6;

        public const uint DRAFTMODE = 7;

        public const uint QUERYESCSUPPORT = 8;

        public const uint SETABORTPROC = 9;

        public const uint STARTDOC = 10;

        public const uint ENDDOC = 11;

        public const uint GETPHYSPAGESIZE = 12;

        public const uint GETPRINTINGOFFSET = 13;

        public const uint GETSCALINGFACTOR = 14;

        public const uint MFCOMMENT = 15;

        public const uint GETPENWIDTH = 16;

        public const uint SETCOPYCOUNT = 17;

        public const uint SELECTPAPERSOURCE = 18;

        public const uint DEVICEDATA = 19;

        public const uint PASSTHROUGH = 19;

        public const uint GETTECHNOLGY = 20;

        public const uint GETTECHNOLOGY = 20;

        public const uint SETLINECAP = 21;

        public const uint SETLINEJOIN = 22;

        public const uint SETMITERLIMIT = 23;

        public const uint BANDINFO = 24;

        public const uint DRAWPATTERNRECT = 25;

        public const uint GETVECTORPENSIZE = 26;

        public const uint GETVECTORBRUSHSIZE = 27;

        public const uint ENABLEDUPLEX = 28;

        public const uint GETSETPAPERBINS = 29;

        public const uint GETSETPRINTORIENT = 30;

        public const uint ENUMPAPERBINS = 31;

        public const uint SETDIBSCALING = 32;

        public const uint EPSPRINTING = 33;

        public const uint ENUMPAPERMETRICS = 34;

        public const uint GETSETPAPERMETRICS = 35;

        public const uint POSTSCRIPT_DATA = 37;

        public const uint POSTSCRIPT_IGNORE = 38;

        public const uint MOUSETRAILS = 39;

        public const uint GETDEVICEUNITS = 42;

        public const uint GETEXTENDEDTEXTMETRICS = 256;

        public const uint GETEXTENTTABLE = 257;

        public const uint GETPAIRKERNTABLE = 258;

        public const uint GETTRACKKERNTABLE = 259;

        public const uint EXTTEXTOUT = 512;

        public const uint GETFACENAME = 513;

        public const uint DOWNLOADFACE = 514;

        public const uint ENABLERELATIVEWIDTHS = 768;

        public const uint ENABLEPAIRKERNING = 769;

        public const uint SETKERNTRACK = 770;

        public const uint SETALLJUSTVALUES = 771;

        public const uint SETCHARSET = 772;

        public const uint STRETCHBLT = 2048;

        public const uint METAFILE_DRIVER = 2049;

        public const uint GETSETSCREENPARAMS = 3072;

        public const uint QUERYDIBSUPPORT = 3073;

        public const uint BEGIN_PATH = 4096;

        public const uint CLIP_TO_PATH = 4097;

        public const uint END_PATH = 4098;

        public const uint EXT_DEVICE_CAPS = 4099;

        public const uint RESTORE_CTM = 4100;

        public const uint SAVE_CTM = 4101;

        public const uint SET_ARC_DIRECTION = 4102;

        public const uint SET_BACKGROUND_COLOR = 4103;

        public const uint SET_POLY_MODE = 4104;

        public const uint SET_SCREEN_ANGLE = 4105;

        public const uint SET_SPREAD = 4106;

        public const uint TRANSFORM_CTM = 4107;

        public const uint SET_CLIP_BOX = 4108;

        public const uint SET_BOUNDS = 4109;

        public const uint SET_MIRROR_MODE = 4110;

        public const uint OPENCHANNEL = 4110;

        public const uint DOWNLOADHEADER = 4111;

        public const uint CLOSECHANNEL = 4112;

        public const uint POSTSCRIPT_PASSTHROUGH = 4115;

        public const uint ENCAPSULATED_POSTSCRIPT = 4116;

        public const uint POSTSCRIPT_IDENTIFY = 4117;

        public const uint POSTSCRIPT_INJECTION = 4118;

        public const uint CHECKJPEGFORMAT = 4119;

        public const uint CHECKPNGFORMAT = 4120;

        public const uint GET_PS_FEATURESETTING = 4121;

        public const uint GDIPLUS_TS_QUERYVER = 4122;

        public const uint GDIPLUS_TS_RECORD = 4123;

        public const uint MILCORE_TS_QUERYVER_RESULT_FALSE = 0x0;

        public const uint MILCORE_TS_QUERYVER_RESULT_TRUE = 0x7FFFFFFF;

        public const uint SPCLPASSTHROUGH2 = 4568;

        public const uint PSIDENT_GDICENTRIC = 0;

        public const uint PSIDENT_PSCENTRIC = 1;

        public const uint PSINJECT_DLFONT = 0xdddddddd;

        public const uint FEATURESETTING_NUP = 0;

        public const uint FEATURESETTING_OUTPUT = 1;

        public const uint FEATURESETTING_PSLEVEL = 2;

        public const uint FEATURESETTING_CUSTPAPER = 3;

        public const uint FEATURESETTING_MIRROR = 4;

        public const uint FEATURESETTING_NEGATIVE = 5;

        public const uint FEATURESETTING_PROTOCOL = 6;

        public const uint FEATURESETTING_PRIVATE_BEGIN = 0x1000;

        public const uint FEATURESETTING_PRIVATE_END = 0x1FFF;

        public const uint PSPROTOCOL_ASCII = 0;

        public const uint PSPROTOCOL_BCP = 1;

        public const uint PSPROTOCOL_TBCP = 2;

        public const uint PSPROTOCOL_BINARY = 3;

        public const uint QDI_SETDIBITS = 1;

        public const uint QDI_GETDIBITS = 2;

        public const uint QDI_DIBTOSCREEN = 4;

        public const uint QDI_STRETCHDIB = 8;

        public const uint SP_NOTREPORTED = 0x4000;

        public const int SP_ERROR = -1;

        public const int SP_APPABORT = -2;

        public const int SP_USERABORT = -3;

        public const int SP_OUTOFDISK = -4;

        public const int SP_OUTOFMEMORY = -5;

        public const uint PR_JOBSTATUS = 0x0000;

        public const int LCS_CALIBRATED_RGB = 0x00000000;

        public const int LCS_GM_BUSINESS = 0x00000001;

        public const int LCS_GM_GRAPHICS = 0x00000002;

        public const int LCS_GM_IMAGES = 0x00000004;

        public const int LCS_GM_ABS_COLORIMETRIC = 0x00000008;

        public const uint CM_OUT_OF_GAMUT = 255;

        public const uint CM_IN_GAMUT = 0;

        public const int BI_RGB = 0;

        public const int BI_RLE8 = 1;

        public const int BI_RLE4 = 2;

        public const int BI_BITFIELDS = 3;

        public const int BI_JPEG = 4;

        public const int BI_PNG = 5;

        public const uint TMPF_FIXED_PITCH = 0x01;

        public const uint TMPF_VECTOR = 0x02;

        public const uint TMPF_DEVICE = 0x08;

        public const uint TMPF_TRUETYPE = 0x04;

        public const int NTM_REGULAR = 0x00000040;

        public const int NTM_BOLD = 0x00000020;

        public const int NTM_ITALIC = 0x00000001;

        public const uint NTM_NONNEGATIVE_AC = 0x00010000;

        public const uint NTM_PS_OPENTYPE = 0x00020000;

        public const uint NTM_TT_OPENTYPE = 0x00040000;

        public const uint NTM_MULTIPLEMASTER = 0x00080000;

        public const uint NTM_TYPE1 = 0x00100000;

        public const uint NTM_DSIG = 0x00200000;

        public const uint LF_FACESIZE = 32;

        public const uint LF_FULLFACESIZE = 64;

        public const uint OUT_SCREEN_OUTLINE_PRECIS = 9;

        public const uint CLEARTYPE_NATURAL_QUALITY = 6;

        public const uint DEFAULT_PITCH = 0;

        public const uint FIXED_PITCH = 1;

        public const uint VARIABLE_PITCH = 2;

        public const uint MONO_FONT = 8;

        public const uint ANSI_CHARSET = 0;

        public const uint DEFAULT_CHARSET = 1;

        public const uint SYMBOL_CHARSET = 2;

        public const uint SHIFTJIS_CHARSET = 128;

        public const uint HANGEUL_CHARSET = 129;

        public const uint HANGUL_CHARSET = 129;

        public const uint GB2312_CHARSET = 134;

        public const uint CHINESEBIG5_CHARSET = 136;

        public const uint OEM_CHARSET = 255;

        public const uint JOHAB_CHARSET = 130;

        public const uint HEBREW_CHARSET = 177;

        public const uint ARABIC_CHARSET = 178;

        public const uint GREEK_CHARSET = 161;

        public const uint TURKISH_CHARSET = 162;

        public const uint VIETNAMESE_CHARSET = 163;

        public const uint THAI_CHARSET = 222;

        public const uint EASTEUROPE_CHARSET = 238;

        public const uint RUSSIAN_CHARSET = 204;

        public const uint MAC_CHARSET = 77;

        public const uint BALTIC_CHARSET = 186;

        public const int FS_LATIN1 = 0x00000001;

        public const int FS_LATIN2 = 0x00000002;

        public const int FS_CYRILLIC = 0x00000004;

        public const int FS_GREEK = 0x00000008;

        public const int FS_TURKISH = 0x00000010;

        public const int FS_HEBREW = 0x00000020;

        public const int FS_ARABIC = 0x00000040;

        public const int FS_BALTIC = 0x00000080;

        public const int FS_VIETNAMESE = 0x00000100;

        public const int FS_THAI = 0x00010000;

        public const int FS_JISJAPAN = 0x00020000;

        public const int FS_CHINESESIMP = 0x00040000;

        public const int FS_WANSUNG = 0x00080000;

        public const int FS_CHINESETRAD = 0x00100000;

        public const int FS_JOHAB = 0x00200000;

        public const int FS_SYMBOL = unchecked((int)0x80000000);

        public const uint FW_DONTCARE = 0;

        public const uint FW_THIN = 100;

        public const uint FW_EXTRALIGHT = 200;

        public const uint FW_LIGHT = 300;

        public const uint FW_NORMAL = 400;

        public const uint FW_MEDIUM = 500;

        public const uint FW_SEMIBOLD = 600;

        public const uint FW_BOLD = 700;

        public const uint FW_EXTRABOLD = 800;

        public const uint FW_HEAVY = 900;

        public const uint PANOSE_COUNT = 10;

        public const uint PAN_FAMILYTYPE_INDEX = 0;

        public const uint PAN_SERIFSTYLE_INDEX = 1;

        public const uint PAN_WEIGHT_INDEX = 2;

        public const uint PAN_PROPORTION_INDEX = 3;

        public const uint PAN_CONTRAST_INDEX = 4;

        public const uint PAN_STROKEVARIATION_INDEX = 5;

        public const uint PAN_ARMSTYLE_INDEX = 6;

        public const uint PAN_LETTERFORM_INDEX = 7;

        public const uint PAN_MIDLINE_INDEX = 8;

        public const uint PAN_XHEIGHT_INDEX = 9;

        public const uint PAN_CULTURE_LATIN = 0;

        public const uint PAN_ANY = 0;

        public const uint PAN_NO_FIT = 1;

        public const uint PAN_FAMILY_TEXT_DISPLAY = 2;

        public const uint PAN_FAMILY_SCRIPT = 3;

        public const uint PAN_FAMILY_DECORATIVE = 4;

        public const uint PAN_FAMILY_PICTORIAL = 5;

        public const uint PAN_SERIF_COVE = 2;

        public const uint PAN_SERIF_OBTUSE_COVE = 3;

        public const uint PAN_SERIF_SQUARE_COVE = 4;

        public const uint PAN_SERIF_OBTUSE_SQUARE_COVE = 5;

        public const uint PAN_SERIF_SQUARE = 6;

        public const uint PAN_SERIF_THIN = 7;

        public const uint PAN_SERIF_BONE = 8;

        public const uint PAN_SERIF_EXAGGERATED = 9;

        public const uint PAN_SERIF_TRIANGLE = 10;

        public const uint PAN_SERIF_NORMAL_SANS = 11;

        public const uint PAN_SERIF_OBTUSE_SANS = 12;

        public const uint PAN_SERIF_PERP_SANS = 13;

        public const uint PAN_SERIF_FLARED = 14;

        public const uint PAN_SERIF_ROUNDED = 15;

        public const uint PAN_WEIGHT_VERY_LIGHT = 2;

        public const uint PAN_WEIGHT_LIGHT = 3;

        public const uint PAN_WEIGHT_THIN = 4;

        public const uint PAN_WEIGHT_BOOK = 5;

        public const uint PAN_WEIGHT_MEDIUM = 6;

        public const uint PAN_WEIGHT_DEMI = 7;

        public const uint PAN_WEIGHT_BOLD = 8;

        public const uint PAN_WEIGHT_HEAVY = 9;

        public const uint PAN_WEIGHT_BLACK = 10;

        public const uint PAN_WEIGHT_NORD = 11;

        public const uint PAN_PROP_OLD_STYLE = 2;

        public const uint PAN_PROP_MODERN = 3;

        public const uint PAN_PROP_EVEN_WIDTH = 4;

        public const uint PAN_PROP_EXPANDED = 5;

        public const uint PAN_PROP_CONDENSED = 6;

        public const uint PAN_PROP_VERY_EXPANDED = 7;

        public const uint PAN_PROP_VERY_CONDENSED = 8;

        public const uint PAN_PROP_MONOSPACED = 9;

        public const uint PAN_CONTRAST_NONE = 2;

        public const uint PAN_CONTRAST_VERY_LOW = 3;

        public const uint PAN_CONTRAST_LOW = 4;

        public const uint PAN_CONTRAST_MEDIUM_LOW = 5;

        public const uint PAN_CONTRAST_MEDIUM = 6;

        public const uint PAN_CONTRAST_MEDIUM_HIGH = 7;

        public const uint PAN_CONTRAST_HIGH = 8;

        public const uint PAN_CONTRAST_VERY_HIGH = 9;

        public const uint PAN_STROKE_GRADUAL_DIAG = 2;

        public const uint PAN_STROKE_GRADUAL_TRAN = 3;

        public const uint PAN_STROKE_GRADUAL_VERT = 4;

        public const uint PAN_STROKE_GRADUAL_HORZ = 5;

        public const uint PAN_STROKE_RAPID_VERT = 6;

        public const uint PAN_STROKE_RAPID_HORZ = 7;

        public const uint PAN_STROKE_INSTANT_VERT = 8;

        public const uint PAN_STRAIGHT_ARMS_HORZ = 2;

        public const uint PAN_STRAIGHT_ARMS_WEDGE = 3;

        public const uint PAN_STRAIGHT_ARMS_VERT = 4;

        public const uint PAN_STRAIGHT_ARMS_SINGLE_SERIF = 5;

        public const uint PAN_STRAIGHT_ARMS_DOUBLE_SERIF = 6;

        public const uint PAN_BENT_ARMS_HORZ = 7;

        public const uint PAN_BENT_ARMS_WEDGE = 8;

        public const uint PAN_BENT_ARMS_VERT = 9;

        public const uint PAN_BENT_ARMS_SINGLE_SERIF = 10;

        public const uint PAN_BENT_ARMS_DOUBLE_SERIF = 11;

        public const uint PAN_LETT_NORMAL_CONTACT = 2;

        public const uint PAN_LETT_NORMAL_WEIGHTED = 3;

        public const uint PAN_LETT_NORMAL_BOXED = 4;

        public const uint PAN_LETT_NORMAL_FLATTENED = 5;

        public const uint PAN_LETT_NORMAL_ROUNDED = 6;

        public const uint PAN_LETT_NORMAL_OFF_CENTER = 7;

        public const uint PAN_LETT_NORMAL_SQUARE = 8;

        public const uint PAN_LETT_OBLIQUE_CONTACT = 9;

        public const uint PAN_LETT_OBLIQUE_WEIGHTED = 10;

        public const uint PAN_LETT_OBLIQUE_BOXED = 11;

        public const uint PAN_LETT_OBLIQUE_FLATTENED = 12;

        public const uint PAN_LETT_OBLIQUE_ROUNDED = 13;

        public const uint PAN_LETT_OBLIQUE_OFF_CENTER = 14;

        public const uint PAN_LETT_OBLIQUE_SQUARE = 15;

        public const uint PAN_MIDLINE_STANDARD_TRIMMED = 2;

        public const uint PAN_MIDLINE_STANDARD_POINTED = 3;

        public const uint PAN_MIDLINE_STANDARD_SERIFED = 4;

        public const uint PAN_MIDLINE_HIGH_TRIMMED = 5;

        public const uint PAN_MIDLINE_HIGH_POINTED = 6;

        public const uint PAN_MIDLINE_HIGH_SERIFED = 7;

        public const uint PAN_MIDLINE_CONSTANT_TRIMMED = 8;

        public const uint PAN_MIDLINE_CONSTANT_POINTED = 9;

        public const uint PAN_MIDLINE_CONSTANT_SERIFED = 10;

        public const uint PAN_MIDLINE_LOW_TRIMMED = 11;

        public const uint PAN_MIDLINE_LOW_POINTED = 12;

        public const uint PAN_MIDLINE_LOW_SERIFED = 13;

        public const uint PAN_XHEIGHT_CONSTANT_SMALL = 2;

        public const uint PAN_XHEIGHT_CONSTANT_STD = 3;

        public const uint PAN_XHEIGHT_CONSTANT_LARGE = 4;

        public const uint PAN_XHEIGHT_DUCKING_SMALL = 5;

        public const uint PAN_XHEIGHT_DUCKING_STD = 6;

        public const uint PAN_XHEIGHT_DUCKING_LARGE = 7;

        public const uint ELF_VENDOR_SIZE = 4;

        public const uint ELF_VERSION = 0;

        public const uint ELF_CULTURE_LATIN = 0;

        public const uint RASTER_FONTTYPE = 0x0001;

        public const uint DEVICE_FONTTYPE = 0x0002;

        public const uint TRUETYPE_FONTTYPE = 0x0004;

        public const uint PC_RESERVED = 0x01;

        public const uint PC_EXPLICIT = 0x02;

        public const uint PC_NOCOLLAPSE = 0x04;

        public const uint BKMODE_LAST = 2;

        public const uint GM_LAST = 2;

        public const uint PT_CLOSEFIGURE = 0x01;

        public const uint PT_LINETO = 0x02;

        public const uint PT_BEZIERTO = 0x04;

        public const uint PT_MOVETO = 0x06;

        public const uint ABSOLUTE = 1;

        public const uint RELATIVE = 2;

        public const uint STOCK_LAST = 19;

        public const uint CLR_INVALID = 0xFFFFFFFF;

        public const uint BS_SOLID = 0;

        public const uint BS_NULL = 1;

        public const uint BS_HATCHED = 2;

        public const uint BS_PATTERN = 3;

        public const uint BS_INDEXED = 4;

        public const uint BS_DIBPATTERN = 5;

        public const uint BS_DIBPATTERNPT = 6;

        public const uint BS_PATTERN8X8 = 7;

        public const uint BS_DIBPATTERN8X8 = 8;

        public const uint BS_MONOPATTERN = 9;

        public const uint HS_API_MAX = 12;

        public const uint TECHNOLOGY = 2;

        public const uint HORZSIZE = 4;

        public const uint VERTSIZE = 6;

        public const uint HORZRES = 8;

        public const uint VERTRES = 10;

        public const uint BITSPIXEL = 12;

        public const uint PLANES = 14;

        public const uint NUMBRUSHES = 16;

        public const uint NUMPENS = 18;

        public const uint NUMMARKERS = 20;

        public const uint NUMFONTS = 22;

        public const uint NUMCOLORS = 24;

        public const uint PDEVICESIZE = 26;

        public const uint CURVECAPS = 28;

        public const uint LINECAPS = 30;

        public const uint POLYGONALCAPS = 32;

        public const uint TEXTCAPS = 34;

        public const uint CLIPCAPS = 36;

        public const uint RASTERCAPS = 38;

        public const uint ASPECTX = 40;

        public const uint ASPECTY = 42;

        public const uint ASPECTXY = 44;

        public const uint LOGPIXELSX = 88;

        public const uint LOGPIXELSY = 90;

        public const uint SIZEPALETTE = 104;

        public const uint NUMRESERVED = 106;

        public const uint COLORRES = 108;

        public const uint PHYSICALWIDTH = 110;

        public const uint PHYSICALHEIGHT = 111;

        public const uint PHYSICALOFFSETX = 112;

        public const uint PHYSICALOFFSETY = 113;

        public const uint SCALINGFACTORX = 114;

        public const uint SCALINGFACTORY = 115;

        public const uint VREFRESH = 116;

        public const uint DESKTOPVERTRES = 117;

        public const uint DESKTOPHORZRES = 118;

        public const uint BLTALIGNMENT = 119;

        public const uint SHADEBLENDCAPS = 120;

        public const uint COLORMGMTCAPS = 121;

        public const uint DT_PLOTTER = 0;

        public const uint DT_RASDISPLAY = 1;

        public const uint DT_RASPRINTER = 2;

        public const uint DT_RASCAMERA = 3;

        public const uint DT_CHARSTREAM = 4;

        public const uint DT_METAFILE = 5;

        public const uint DT_DISPFILE = 6;

        public const uint CC_NONE = 0;

        public const uint CC_CIRCLES = 1;

        public const uint CC_PIE = 2;

        public const uint CC_CHORD = 4;

        public const uint CC_ELLIPSES = 8;

        public const uint CC_WIDE = 16;

        public const uint CC_STYLED = 32;

        public const uint CC_WIDESTYLED = 64;

        public const uint CC_INTERIORS = 128;

        public const uint CC_ROUNDRECT = 256;

        public const uint LC_NONE = 0;

        public const uint LC_POLYLINE = 2;

        public const uint LC_MARKER = 4;

        public const uint LC_POLYMARKER = 8;

        public const uint LC_WIDE = 16;

        public const uint LC_STYLED = 32;

        public const uint LC_WIDESTYLED = 64;

        public const uint LC_INTERIORS = 128;

        public const uint PC_NONE = 0;

        public const uint PC_POLYGON = 1;

        public const uint PC_RECTANGLE = 2;

        public const uint PC_WINDPOLYGON = 4;

        public const uint PC_TRAPEZOID = 4;

        public const uint PC_SCANLINE = 8;

        public const uint PC_WIDE = 16;

        public const uint PC_STYLED = 32;

        public const uint PC_WIDESTYLED = 64;

        public const uint PC_INTERIORS = 128;

        public const uint PC_POLYPOLYGON = 256;

        public const uint PC_PATHS = 512;

        public const uint CP_NONE = 0;

        public const uint CP_RECTANGLE = 1;

        public const uint CP_REGION = 2;

        public const uint TC_OP_CHARACTER = 0x00000001;

        public const uint TC_OP_STROKE = 0x00000002;

        public const uint TC_CP_STROKE = 0x00000004;

        public const uint TC_CR_90 = 0x00000008;

        public const uint TC_CR_ANY = 0x00000010;

        public const uint TC_SF_X_YINDEP = 0x00000020;

        public const uint TC_SA_DOUBLE = 0x00000040;

        public const uint TC_SA_INTEGER = 0x00000080;

        public const uint TC_SA_CONTIN = 0x00000100;

        public const uint TC_EA_DOUBLE = 0x00000200;

        public const uint TC_IA_ABLE = 0x00000400;

        public const uint TC_UA_ABLE = 0x00000800;

        public const uint TC_SO_ABLE = 0x00001000;

        public const uint TC_RA_ABLE = 0x00002000;

        public const uint TC_VA_ABLE = 0x00004000;

        public const uint TC_RESERVED = 0x00008000;

        public const uint TC_SCROLLBLT = 0x00010000;

        public const uint RC_BITBLT = 1;

        public const uint RC_BANDING = 2;

        public const uint RC_SCALING = 4;

        public const uint RC_BITMAP64 = 8;

        public const uint RC_GDI20_OUTPUT = 0x0010;

        public const uint RC_GDI20_STATE = 0x0020;

        public const uint RC_SAVEBITMAP = 0x0040;

        public const uint RC_DI_BITMAP = 0x0080;

        public const uint RC_PALETTE = 0x0100;

        public const uint RC_DIBTODEV = 0x0200;

        public const uint RC_BIGFONT = 0x0400;

        public const uint RC_STRETCHBLT = 0x0800;

        public const uint RC_FLOODFILL = 0x1000;

        public const uint RC_STRETCHDIB = 0x2000;

        public const uint RC_OP_DX_OUTPUT = 0x4000;

        public const uint RC_DEVBITS = 0x8000;

        public const uint SB_NONE = 0x00000000;

        public const uint SB_CONST_ALPHA = 0x00000001;

        public const uint SB_PIXEL_ALPHA = 0x00000002;

        public const uint SB_PREMULT_ALPHA = 0x00000004;

        public const uint SB_GRAD_RECT = 0x00000010;

        public const uint SB_GRAD_TRI = 0x00000020;

        public const uint CM_NONE = 0x00000000;

        public const uint CM_DEVICE_ICM = 0x00000001;

        public const uint CM_GAMMA_RAMP = 0x00000002;

        public const uint CM_CMYK_COLOR = 0x00000004;

        public const uint SYSPAL_ERROR = 0;

        public const int CBM_INIT = 0x04;

        public const uint CCHFORMNAME = 32;

        public const uint DM_SPECVERSION = 0x0401;

        public const int DM_ORIENTATION = 0x00000001;

        public const int DM_PAPERSIZE = 0x00000002;

        public const int DM_PAPERLENGTH = 0x00000004;

        public const int DM_PAPERWIDTH = 0x00000008;

        public const int DM_SCALE = 0x00000010;

        public const int DM_POSITION = 0x00000020;

        public const int DM_NUP = 0x00000040;

        public const int DM_DISPLAYORIENTATION = 0x00000080;

        public const int DM_COPIES = 0x00000100;

        public const int DM_DEFAULTSOURCE = 0x00000200;

        public const int DM_PRINTQUALITY = 0x00000400;

        public const int DM_COLOR = 0x00000800;

        public const int DM_DUPLEX = 0x00001000;

        public const int DM_YRESOLUTION = 0x00002000;

        public const int DM_TTOPTION = 0x00004000;

        public const int DM_COLLATE = 0x00008000;

        public const int DM_FORMNAME = 0x00010000;

        public const int DM_LOGPIXELS = 0x00020000;

        public const int DM_BITSPERPEL = 0x00040000;

        public const int DM_PELSWIDTH = 0x00080000;

        public const int DM_PELSHEIGHT = 0x00100000;

        public const int DM_DISPLAYFLAGS = 0x00200000;

        public const int DM_DISPLAYFREQUENCY = 0x00400000;

        public const int DM_ICMMETHOD = 0x00800000;

        public const int DM_ICMINTENT = 0x01000000;

        public const int DM_MEDIATYPE = 0x02000000;

        public const int DM_DITHERTYPE = 0x04000000;

        public const int DM_PANNINGWIDTH = 0x08000000;

        public const int DM_PANNINGHEIGHT = 0x10000000;

        public const int DM_DISPLAYFIXEDOUTPUT = 0x20000000;

        public const uint DMORIENT_PORTRAIT = 1;

        public const uint DMORIENT_LANDSCAPE = 2;

        public const uint DMPAPER_LETTER = 1;

        public const uint DMPAPER_LETTERSMALL = 2;

        public const uint DMPAPER_TABLOID = 3;

        public const uint DMPAPER_LEDGER = 4;

        public const uint DMPAPER_LEGAL = 5;

        public const uint DMPAPER_STATEMENT = 6;

        public const uint DMPAPER_EXECUTIVE = 7;

        public const uint DMPAPER_A3 = 8;

        public const uint DMPAPER_A4 = 9;

        public const uint DMPAPER_A4SMALL = 10;

        public const uint DMPAPER_A5 = 11;

        public const uint DMPAPER_B4 = 12;

        public const uint DMPAPER_B5 = 13;

        public const uint DMPAPER_FOLIO = 14;

        public const uint DMPAPER_QUARTO = 15;

        public const uint DMPAPER_10X14 = 16;

        public const uint DMPAPER_11X17 = 17;

        public const uint DMPAPER_NOTE = 18;

        public const uint DMPAPER_ENV_9 = 19;

        public const uint DMPAPER_ENV_10 = 20;

        public const uint DMPAPER_ENV_11 = 21;

        public const uint DMPAPER_ENV_12 = 22;

        public const uint DMPAPER_ENV_14 = 23;

        public const uint DMPAPER_CSHEET = 24;

        public const uint DMPAPER_DSHEET = 25;

        public const uint DMPAPER_ESHEET = 26;

        public const uint DMPAPER_ENV_DL = 27;

        public const uint DMPAPER_ENV_C5 = 28;

        public const uint DMPAPER_ENV_C3 = 29;

        public const uint DMPAPER_ENV_C4 = 30;

        public const uint DMPAPER_ENV_C6 = 31;

        public const uint DMPAPER_ENV_C65 = 32;

        public const uint DMPAPER_ENV_B4 = 33;

        public const uint DMPAPER_ENV_B5 = 34;

        public const uint DMPAPER_ENV_B6 = 35;

        public const uint DMPAPER_ENV_ITALY = 36;

        public const uint DMPAPER_ENV_MONARCH = 37;

        public const uint DMPAPER_ENV_PERSONAL = 38;

        public const uint DMPAPER_FANFOLD_US = 39;

        public const uint DMPAPER_FANFOLD_STD_GERMAN = 40;

        public const uint DMPAPER_FANFOLD_LGL_GERMAN = 41;

        public const uint DMPAPER_ISO_B4 = 42;

        public const uint DMPAPER_JAPANESE_POSTCARD = 43;

        public const uint DMPAPER_9X11 = 44;

        public const uint DMPAPER_10X11 = 45;

        public const uint DMPAPER_15X11 = 46;

        public const uint DMPAPER_ENV_INVITE = 47;

        public const uint DMPAPER_RESERVED_48 = 48;

        public const uint DMPAPER_RESERVED_49 = 49;

        public const uint DMPAPER_LETTER_EXTRA = 50;

        public const uint DMPAPER_LEGAL_EXTRA = 51;

        public const uint DMPAPER_TABLOID_EXTRA = 52;

        public const uint DMPAPER_A4_EXTRA = 53;

        public const uint DMPAPER_LETTER_TRANSVERSE = 54;

        public const uint DMPAPER_A4_TRANSVERSE = 55;

        public const uint DMPAPER_LETTER_EXTRA_TRANSVERSE = 56;

        public const uint DMPAPER_A_PLUS = 57;

        public const uint DMPAPER_B_PLUS = 58;

        public const uint DMPAPER_LETTER_PLUS = 59;

        public const uint DMPAPER_A4_PLUS = 60;

        public const uint DMPAPER_A5_TRANSVERSE = 61;

        public const uint DMPAPER_B5_TRANSVERSE = 62;

        public const uint DMPAPER_A3_EXTRA = 63;

        public const uint DMPAPER_A5_EXTRA = 64;

        public const uint DMPAPER_B5_EXTRA = 65;

        public const uint DMPAPER_A2 = 66;

        public const uint DMPAPER_A3_TRANSVERSE = 67;

        public const uint DMPAPER_A3_EXTRA_TRANSVERSE = 68;

        public const uint DMPAPER_DBL_JAPANESE_POSTCARD = 69;

        public const uint DMPAPER_A6 = 70;

        public const uint DMPAPER_JENV_KAKU2 = 71;

        public const uint DMPAPER_JENV_KAKU3 = 72;

        public const uint DMPAPER_JENV_CHOU3 = 73;

        public const uint DMPAPER_JENV_CHOU4 = 74;

        public const uint DMPAPER_LETTER_ROTATED = 75;

        public const uint DMPAPER_A3_ROTATED = 76;

        public const uint DMPAPER_A4_ROTATED = 77;

        public const uint DMPAPER_A5_ROTATED = 78;

        public const uint DMPAPER_B4_JIS_ROTATED = 79;

        public const uint DMPAPER_B5_JIS_ROTATED = 80;

        public const uint DMPAPER_JAPANESE_POSTCARD_ROTATED = 81;

        public const uint DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED = 82;

        public const uint DMPAPER_A6_ROTATED = 83;

        public const uint DMPAPER_JENV_KAKU2_ROTATED = 84;

        public const uint DMPAPER_JENV_KAKU3_ROTATED = 85;

        public const uint DMPAPER_JENV_CHOU3_ROTATED = 86;

        public const uint DMPAPER_JENV_CHOU4_ROTATED = 87;

        public const uint DMPAPER_B6_JIS = 88;

        public const uint DMPAPER_B6_JIS_ROTATED = 89;

        public const uint DMPAPER_12X11 = 90;

        public const uint DMPAPER_JENV_YOU4 = 91;

        public const uint DMPAPER_JENV_YOU4_ROTATED = 92;

        public const uint DMPAPER_P16K = 93;

        public const uint DMPAPER_P32K = 94;

        public const uint DMPAPER_P32KBIG = 95;

        public const uint DMPAPER_PENV_1 = 96;

        public const uint DMPAPER_PENV_2 = 97;

        public const uint DMPAPER_PENV_3 = 98;

        public const uint DMPAPER_PENV_4 = 99;

        public const uint DMPAPER_PENV_5 = 100;

        public const uint DMPAPER_PENV_6 = 101;

        public const uint DMPAPER_PENV_7 = 102;

        public const uint DMPAPER_PENV_8 = 103;

        public const uint DMPAPER_PENV_9 = 104;

        public const uint DMPAPER_PENV_10 = 105;

        public const uint DMPAPER_P16K_ROTATED = 106;

        public const uint DMPAPER_P32K_ROTATED = 107;

        public const uint DMPAPER_P32KBIG_ROTATED = 108;

        public const uint DMPAPER_PENV_1_ROTATED = 109;

        public const uint DMPAPER_PENV_2_ROTATED = 110;

        public const uint DMPAPER_PENV_3_ROTATED = 111;

        public const uint DMPAPER_PENV_4_ROTATED = 112;

        public const uint DMPAPER_PENV_5_ROTATED = 113;

        public const uint DMPAPER_PENV_6_ROTATED = 114;

        public const uint DMPAPER_PENV_7_ROTATED = 115;

        public const uint DMPAPER_PENV_8_ROTATED = 116;

        public const uint DMPAPER_PENV_9_ROTATED = 117;

        public const uint DMPAPER_PENV_10_ROTATED = 118;

        public const uint DMPAPER_USER = 256;

        public const uint DMBIN_UPPER = 1;

        public const uint DMBIN_ONLYONE = 1;

        public const uint DMBIN_LOWER = 2;

        public const uint DMBIN_MIDDLE = 3;

        public const uint DMBIN_MANUAL = 4;

        public const uint DMBIN_ENVELOPE = 5;

        public const uint DMBIN_ENVMANUAL = 6;

        public const uint DMBIN_AUTO = 7;

        public const uint DMBIN_TRACTOR = 8;

        public const uint DMBIN_SMALLFMT = 9;

        public const uint DMBIN_LARGEFMT = 10;

        public const uint DMBIN_LARGECAPACITY = 11;

        public const uint DMBIN_CASSETTE = 14;

        public const uint DMBIN_FORMSOURCE = 15;

        public const uint DMBIN_USER = 256;

        public const int DMRES_DRAFT = -1;

        public const int DMRES_LOW = -2;

        public const int DMRES_MEDIUM = -3;

        public const int DMRES_HIGH = -4;

        public const uint DMCOLOR_MONOCHROME = 1;

        public const uint DMCOLOR_COLOR = 2;

        public const uint DMDUP_SIMPLEX = 1;

        public const uint DMDUP_VERTICAL = 2;

        public const uint DMDUP_HORIZONTAL = 3;

        public const uint DMTT_BITMAP = 1;

        public const uint DMTT_DOWNLOAD = 2;

        public const uint DMTT_SUBDEV = 3;

        public const uint DMTT_DOWNLOAD_OUTLINE = 4;

        public const uint DMCOLLATE_FALSE = 0;

        public const uint DMCOLLATE_TRUE = 1;

        public const uint DMDO_DEFAULT = 0;

        public const uint DMDO_90 = 1;

        public const uint DMDO_180 = 2;

        public const uint DMDO_270 = 3;

        public const uint DMDFO_DEFAULT = 0;

        public const uint DMDFO_STRETCH = 1;

        public const uint DMDFO_CENTER = 2;

        public const uint DM_INTERLACED = 0x00000002;

        public const uint DMDISPLAYFLAGS_TEXTMODE = 0x00000004;

        public const uint DMNUP_SYSTEM = 1;

        public const uint DMNUP_ONEUP = 2;

        public const uint DMICMMETHOD_NONE = 1;

        public const uint DMICMMETHOD_SYSTEM = 2;

        public const uint DMICMMETHOD_DRIVER = 3;

        public const uint DMICMMETHOD_DEVICE = 4;

        public const uint DMICMMETHOD_USER = 256;

        public const uint DMICM_SATURATE = 1;

        public const uint DMICM_CONTRAST = 2;

        public const uint DMICM_COLORIMETRIC = 3;

        public const uint DMICM_ABS_COLORIMETRIC = 4;

        public const uint DMICM_USER = 256;

        public const uint DMMEDIA_STANDARD = 1;

        public const uint DMMEDIA_TRANSPARENCY = 2;

        public const uint DMMEDIA_GLOSSY = 3;

        public const uint DMMEDIA_USER = 256;

        public const uint DMDITHER_NONE = 1;

        public const uint DMDITHER_COARSE = 2;

        public const uint DMDITHER_FINE = 3;

        public const uint DMDITHER_LINEART = 4;

        public const uint DMDITHER_ERRORDIFFUSION = 5;

        public const uint DMDITHER_RESERVED6 = 6;

        public const uint DMDITHER_RESERVED7 = 7;

        public const uint DMDITHER_RESERVED8 = 8;

        public const uint DMDITHER_RESERVED9 = 9;

        public const uint DMDITHER_GRAYSCALE = 10;

        public const uint DMDITHER_USER = 256;

        public const uint DISPLAY_DEVICE_ATTACHED_TO_DESKTOP = 0x00000001;

        public const uint DISPLAY_DEVICE_MULTI_DRIVER = 0x00000002;

        public const uint DISPLAY_DEVICE_PRIMARY_DEVICE = 0x00000004;

        public const uint DISPLAY_DEVICE_MIRRORING_DRIVER = 0x00000008;

        public const uint DISPLAY_DEVICE_VGA_COMPATIBLE = 0x00000010;

        public const uint DISPLAY_DEVICE_REMOVABLE = 0x00000020;

        public const uint DISPLAY_DEVICE_ACC_DRIVER = 0x00000040;

        public const uint DISPLAY_DEVICE_MODESPRUNED = 0x08000000;

        public const uint DISPLAY_DEVICE_RDPUDD = 0x01000000;

        public const uint DISPLAY_DEVICE_REMOTE = 0x04000000;

        public const uint DISPLAY_DEVICE_DISCONNECT = 0x02000000;

        public const uint DISPLAY_DEVICE_TS_COMPATIBLE = 0x00200000;

        public const uint DISPLAY_DEVICE_UNSAFE_MODES_ON = 0x00080000;

        public const uint DISPLAY_DEVICE_ACTIVE = 0x00000001;

        public const uint DISPLAY_DEVICE_ATTACHED = 0x00000002;

        public const uint DISPLAYCONFIG_MAXPATH = 1024;

        public const uint DISPLAYCONFIG_PATH_MODE_IDX_INVALID = 0xffffffff;

        public const uint DISPLAYCONFIG_PATH_TARGET_MODE_IDX_INVALID = 0xffff;

        public const uint DISPLAYCONFIG_PATH_DESKTOP_IMAGE_IDX_INVALID = 0xffff;

        public const uint DISPLAYCONFIG_PATH_SOURCE_MODE_IDX_INVALID = 0xffff;

        public const uint DISPLAYCONFIG_PATH_CLONE_GROUP_INVALID = 0xffff;

        public const uint DISPLAYCONFIG_SOURCE_IN_USE = 0x00000001;

        public const uint DISPLAYCONFIG_TARGET_IN_USE = 0x00000001;

        public const uint DISPLAYCONFIG_TARGET_FORCIBLE = 0x00000002;

        public const uint DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT = 0x00000004;

        public const uint DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH = 0x00000008;

        public const uint DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM = 0x00000010;

        public const uint DISPLAYCONFIG_TARGET_IS_HMD = 0x00000020;

        public const uint DISPLAYCONFIG_PATH_ACTIVE = 0x00000001;

        public const uint DISPLAYCONFIG_PATH_PREFERRED_UNSCALED = 0x00000004;

        public const uint DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE = 0x00000008;

        public const uint DISPLAYCONFIG_PATH_VALID_FLAGS = 0x0000000D;

        public const uint QDC_ALL_PATHS = 0x00000001;

        public const uint QDC_ONLY_ACTIVE_PATHS = 0x00000002;

        public const uint QDC_DATABASE_CURRENT = 0x00000004;

        public const uint QDC_VIRTUAL_MODE_AWARE = 0x00000010;

        public const uint QDC_INCLUDE_HMD = 0x00000020;

        public const uint SDC_TOPOLOGY_INTERNAL = 0x00000001;

        public const uint SDC_TOPOLOGY_CLONE = 0x00000002;

        public const uint SDC_TOPOLOGY_EXTEND = 0x00000004;

        public const uint SDC_TOPOLOGY_EXTERNAL = 0x00000008;

        public const uint SDC_TOPOLOGY_SUPPLIED = 0x00000010;

        public const uint SDC_USE_SUPPLIED_DISPLAY_CONFIG = 0x00000020;

        public const uint SDC_VALIDATE = 0x00000040;

        public const uint SDC_APPLY = 0x00000080;

        public const uint SDC_NO_OPTIMIZATION = 0x00000100;

        public const uint SDC_SAVE_TO_DATABASE = 0x00000200;

        public const uint SDC_ALLOW_CHANGES = 0x00000400;

        public const uint SDC_PATH_PERSIST_IF_REQUIRED = 0x00000800;

        public const uint SDC_FORCE_MODE_ENUMERATION = 0x00001000;

        public const uint SDC_ALLOW_PATH_ORDER_CHANGES = 0x00002000;

        public const uint SDC_VIRTUAL_MODE_AWARE = 0x00008000;

        public const uint RDH_RECTANGLES = 1;

        public const uint SYSRGN = 4;

        public const uint TT_POLYGON_TYPE = 24;

        public const uint TT_PRIM_LINE = 1;

        public const uint TT_PRIM_QSPLINE = 2;

        public const uint TT_PRIM_CSPLINE = 3;

        public const uint GCP_DBCS = 0x0001;

        public const uint GCP_ERROR = 0x8000;

        public const uint FLI_MASK = 0x103B;

        public const int FLI_GLYPHS = 0x00040000;

        public const int GCP_JUSTIFYIN = 0x00200000;

        public const uint GCPCLASS_LATIN = 1;

        public const uint GCPCLASS_HEBREW = 2;

        public const uint GCPCLASS_ARABIC = 2;

        public const uint GCPCLASS_NEUTRAL = 3;

        public const uint GCPCLASS_LOCALNUMBER = 4;

        public const uint GCPCLASS_LATINNUMBER = 5;

        public const uint GCPCLASS_LATINNUMERICTERMINATOR = 6;

        public const uint GCPCLASS_LATINNUMERICSEPARATOR = 7;

        public const uint GCPCLASS_NUMERICSEPARATOR = 8;

        public const uint GCPCLASS_PREBOUNDLTR = 0x80;

        public const uint GCPCLASS_PREBOUNDRTL = 0x40;

        public const uint GCPCLASS_POSTBOUNDLTR = 0x20;

        public const uint GCPCLASS_POSTBOUNDRTL = 0x10;

        public const uint GCPGLYPH_LINKBEFORE = 0x8000;

        public const uint GCPGLYPH_LINKAFTER = 0x4000;

        public const uint TT_AVAILABLE = 0x0001;

        public const uint TT_ENABLED = 0x0002;

        public const uint PFD_TYPE_RGBA = 0;

        public const uint PFD_TYPE_COLORINDEX = 1;

        public const uint PFD_MAIN_PLANE = 0;

        public const uint PFD_OVERLAY_PLANE = 1;

        public const int PFD_UNDERLAY_PLANE = -1;

        public const uint PFD_DOUBLEBUFFER = 0x00000001;

        public const uint PFD_STEREO = 0x00000002;

        public const uint PFD_DRAW_TO_WINDOW = 0x00000004;

        public const uint PFD_DRAW_TO_BITMAP = 0x00000008;

        public const uint PFD_SUPPORT_GDI = 0x00000010;

        public const uint PFD_SUPPORT_OPENGL = 0x00000020;

        public const uint PFD_GENERIC_FORMAT = 0x00000040;

        public const uint PFD_NEED_PALETTE = 0x00000080;

        public const uint PFD_NEED_SYSTEM_PALETTE = 0x00000100;

        public const uint PFD_SWAP_EXCHANGE = 0x00000200;

        public const uint PFD_SWAP_COPY = 0x00000400;

        public const uint PFD_SWAP_LAYER_BUFFERS = 0x00000800;

        public const uint PFD_GENERIC_ACCELERATED = 0x00001000;

        public const uint PFD_SUPPORT_DIRECTDRAW = 0x00002000;

        public const uint PFD_DIRECT3D_ACCELERATED = 0x00004000;

        public const uint PFD_SUPPORT_COMPOSITION = 0x00008000;

        public const uint PFD_DEPTH_DONTCARE = 0x20000000;

        public const uint PFD_DOUBLEBUFFER_DONTCARE = 0x40000000;

        public const uint PFD_STEREO_DONTCARE = 0x80000000;

        public const uint DC_BINADJUST = 19;

        public const uint DC_EMF_COMPLIANT = 20;

        public const uint DC_DATATYPE_PRODUCED = 21;

        public const uint DC_MANUFACTURER = 23;

        public const uint DC_MODEL = 24;

        public const uint PRINTRATEUNIT_PPM = 1;

        public const uint PRINTRATEUNIT_CPS = 2;

        public const uint PRINTRATEUNIT_LPM = 3;

        public const uint PRINTRATEUNIT_IPM = 4;

        public const int DCTT_BITMAP = 0x0000001;

        public const int DCTT_DOWNLOAD = 0x0000002;

        public const int DCTT_SUBDEV = 0x0000004;

        public const int DCTT_DOWNLOAD_OUTLINE = 0x0000008;

        public const uint DCBA_FACEUPNONE = 0x0000;

        public const uint DCBA_FACEUPCENTER = 0x0001;

        public const uint DCBA_FACEUPLEFT = 0x0002;

        public const uint DCBA_FACEUPRIGHT = 0x0003;

        public const uint DCBA_FACEDOWNNONE = 0x0100;

        public const uint DCBA_FACEDOWNCENTER = 0x0101;

        public const uint DCBA_FACEDOWNLEFT = 0x0102;

        public const uint DCBA_FACEDOWNRIGHT = 0x0103;

        public const uint GS_8BIT_INDICES = 0x00000001;

        public const uint GGI_MARK_NONEXISTING_GLYPHS = 0X0001;

        public const uint MM_MAX_NUMAXES = 16;

        public const uint MM_MAX_AXES_NAMELEN = 16;

        public const uint GDIREGISTERDDRAWPACKETVERSION = 0x1;

        public const uint AC_SRC_OVER = 0x00;

        public const uint AC_SRC_ALPHA = 0x01;

        public const uint GRADIENT_FILL_OP_FLAG = 0x000000ff;

        public const uint CA_NEGATIVE = 0x0001;

        public const uint CA_LOG_FILTER = 0x0002;

        public const uint ILLUMINANT_DEVICE_DEFAULT = 0;

        public const uint ILLUMINANT_A = 1;

        public const uint ILLUMINANT_B = 2;

        public const uint ILLUMINANT_C = 3;

        public const uint ILLUMINANT_D50 = 4;

        public const uint ILLUMINANT_D55 = 5;

        public const uint ILLUMINANT_D65 = 6;

        public const uint ILLUMINANT_D75 = 7;

        public const uint ILLUMINANT_F2 = 8;

        public const uint DI_APPBANDING = 0x00000001;

        public const uint DI_ROPS_READ_DESTINATION = 0x00000002;

        public const uint FONTMAPPER_MAX = 10;

        public const uint ICM_OFF = 1;

        public const uint ICM_ON = 2;

        public const uint ICM_QUERY = 3;

        public const uint ICM_DONE_OUTSIDEDC = 4;

        public const uint ENHMETA_SIGNATURE = 0x464D4520;

        public const uint ENHMETA_STOCK_OBJECT = 0x80000000;

        public const uint EMR_HEADER = 1;

        public const uint EMR_POLYBEZIER = 2;

        public const uint EMR_POLYGON = 3;

        public const uint EMR_POLYLINE = 4;

        public const uint EMR_POLYBEZIERTO = 5;

        public const uint EMR_POLYLINETO = 6;

        public const uint EMR_POLYPOLYLINE = 7;

        public const uint EMR_POLYPOLYGON = 8;

        public const uint EMR_SETWINDOWEXTEX = 9;

        public const uint EMR_SETWINDOWORGEX = 10;

        public const uint EMR_SETVIEWPORTEXTEX = 11;

        public const uint EMR_SETVIEWPORTORGEX = 12;

        public const uint EMR_SETBRUSHORGEX = 13;

        public const uint EMR_EOF = 14;

        public const uint EMR_SETPIXELV = 15;

        public const uint EMR_SETMAPPERFLAGS = 16;

        public const uint EMR_SETMAPMODE = 17;

        public const uint EMR_SETBKMODE = 18;

        public const uint EMR_SETPOLYFILLMODE = 19;

        public const uint EMR_SETROP2 = 20;

        public const uint EMR_SETSTRETCHBLTMODE = 21;

        public const uint EMR_SETTEXTALIGN = 22;

        public const uint EMR_SETCOLORADJUSTMENT = 23;

        public const uint EMR_SETTEXTCOLOR = 24;

        public const uint EMR_SETBKCOLOR = 25;

        public const uint EMR_OFFSETCLIPRGN = 26;

        public const uint EMR_MOVETOEX = 27;

        public const uint EMR_SETMETARGN = 28;

        public const uint EMR_EXCLUDECLIPRECT = 29;

        public const uint EMR_INTERSECTCLIPRECT = 30;

        public const uint EMR_SCALEVIEWPORTEXTEX = 31;

        public const uint EMR_SCALEWINDOWEXTEX = 32;

        public const uint EMR_SAVEDC = 33;

        public const uint EMR_RESTOREDC = 34;

        public const uint EMR_SETWORLDTRANSFORM = 35;

        public const uint EMR_MODIFYWORLDTRANSFORM = 36;

        public const uint EMR_SELECTOBJECT = 37;

        public const uint EMR_CREATEPEN = 38;

        public const uint EMR_CREATEBRUSHINDIRECT = 39;

        public const uint EMR_DELETEOBJECT = 40;

        public const uint EMR_ANGLEARC = 41;

        public const uint EMR_ELLIPSE = 42;

        public const uint EMR_RECTANGLE = 43;

        public const uint EMR_ROUNDRECT = 44;

        public const uint EMR_ARC = 45;

        public const uint EMR_CHORD = 46;

        public const uint EMR_PIE = 47;

        public const uint EMR_SELECTPALETTE = 48;

        public const uint EMR_CREATEPALETTE = 49;

        public const uint EMR_SETPALETTEENTRIES = 50;

        public const uint EMR_RESIZEPALETTE = 51;

        public const uint EMR_REALIZEPALETTE = 52;

        public const uint EMR_EXTFLOODFILL = 53;

        public const uint EMR_LINETO = 54;

        public const uint EMR_ARCTO = 55;

        public const uint EMR_POLYDRAW = 56;

        public const uint EMR_SETARCDIRECTION = 57;

        public const uint EMR_SETMITERLIMIT = 58;

        public const uint EMR_BEGINPATH = 59;

        public const uint EMR_ENDPATH = 60;

        public const uint EMR_CLOSEFIGURE = 61;

        public const uint EMR_FILLPATH = 62;

        public const uint EMR_STROKEANDFILLPATH = 63;

        public const uint EMR_STROKEPATH = 64;

        public const uint EMR_FLATTENPATH = 65;

        public const uint EMR_WIDENPATH = 66;

        public const uint EMR_SELECTCLIPPATH = 67;

        public const uint EMR_ABORTPATH = 68;

        public const uint EMR_GDICOMMENT = 70;

        public const uint EMR_FILLRGN = 71;

        public const uint EMR_FRAMERGN = 72;

        public const uint EMR_INVERTRGN = 73;

        public const uint EMR_PAINTRGN = 74;

        public const uint EMR_EXTSELECTCLIPRGN = 75;

        public const uint EMR_BITBLT = 76;

        public const uint EMR_STRETCHBLT = 77;

        public const uint EMR_MASKBLT = 78;

        public const uint EMR_PLGBLT = 79;

        public const uint EMR_SETDIBITSTODEVICE = 80;

        public const uint EMR_STRETCHDIBITS = 81;

        public const uint EMR_EXTCREATEFONTINDIRECTW = 82;

        public const uint EMR_EXTTEXTOUTA = 83;

        public const uint EMR_EXTTEXTOUTW = 84;

        public const uint EMR_POLYBEZIER16 = 85;

        public const uint EMR_POLYGON16 = 86;

        public const uint EMR_POLYLINE16 = 87;

        public const uint EMR_POLYBEZIERTO16 = 88;

        public const uint EMR_POLYLINETO16 = 89;

        public const uint EMR_POLYPOLYLINE16 = 90;

        public const uint EMR_POLYPOLYGON16 = 91;

        public const uint EMR_POLYDRAW16 = 92;

        public const uint EMR_CREATEMONOBRUSH = 93;

        public const uint EMR_CREATEDIBPATTERNBRUSHPT = 94;

        public const uint EMR_EXTCREATEPEN = 95;

        public const uint EMR_POLYTEXTOUTA = 96;

        public const uint EMR_POLYTEXTOUTW = 97;

        public const uint EMR_SETICMMODE = 98;

        public const uint EMR_CREATECOLORSPACE = 99;

        public const uint EMR_SETCOLORSPACE = 100;

        public const uint EMR_DELETECOLORSPACE = 101;

        public const uint EMR_GLSRECORD = 102;

        public const uint EMR_GLSBOUNDEDRECORD = 103;

        public const uint EMR_PIXELFORMAT = 104;

        public const uint EMR_RESERVED_105 = 105;

        public const uint EMR_RESERVED_106 = 106;

        public const uint EMR_RESERVED_107 = 107;

        public const uint EMR_RESERVED_108 = 108;

        public const uint EMR_RESERVED_109 = 109;

        public const uint EMR_RESERVED_110 = 110;

        public const uint EMR_COLORCORRECTPALETTE = 111;

        public const uint EMR_SETICMPROFILEA = 112;

        public const uint EMR_SETICMPROFILEW = 113;

        public const uint EMR_ALPHABLEND = 114;

        public const uint EMR_SETLAYOUT = 115;

        public const uint EMR_TRANSPARENTBLT = 116;

        public const uint EMR_RESERVED_117 = 117;

        public const uint EMR_GRADIENTFILL = 118;

        public const uint EMR_RESERVED_119 = 119;

        public const uint EMR_RESERVED_120 = 120;

        public const uint EMR_COLORMATCHTOTARGETW = 121;

        public const uint EMR_CREATECOLORSPACEW = 122;

        public const uint EMR_MIN = 1;

        public const uint EMR_MAX = 122;

        public const uint SETICMPROFILE_EMBEDED = 0x00000001;

        public const uint CREATECOLORSPACE_EMBEDED = 0x00000001;

        public const uint COLORMATCHTOTARGET_EMBEDED = 0x00000001;

        public const uint GDICOMMENT_IDENTIFIER = 0x43494447;

        public const uint GDICOMMENT_WINDOWS_METAFILE = 0x80000001;

        public const uint GDICOMMENT_BEGINGROUP = 0x00000002;

        public const uint GDICOMMENT_ENDGROUP = 0x00000003;

        public const uint GDICOMMENT_MULTIFORMATS = 0x40000004;

        public const uint EPS_SIGNATURE = 0x46535045;

        public const uint GDICOMMENT_UNICODE_STRING = 0x00000040;

        public const uint GDICOMMENT_UNICODE_END = 0x00000080;

        public const uint WGL_FONT_LINES = 0;

        public const uint WGL_FONT_POLYGONS = 1;

        public const uint LPD_DOUBLEBUFFER = 0x00000001;

        public const uint LPD_STEREO = 0x00000002;

        public const uint LPD_SUPPORT_GDI = 0x00000010;

        public const uint LPD_SUPPORT_OPENGL = 0x00000020;

        public const uint LPD_SHARE_DEPTH = 0x00000040;

        public const uint LPD_SHARE_STENCIL = 0x00000080;

        public const uint LPD_SHARE_ACCUM = 0x00000100;

        public const uint LPD_SWAP_EXCHANGE = 0x00000200;

        public const uint LPD_SWAP_COPY = 0x00000400;

        public const uint LPD_TRANSPARENT = 0x00001000;

        public const uint LPD_TYPE_RGBA = 0;

        public const uint LPD_TYPE_COLORINDEX = 1;

        public const uint WGL_SWAP_MAIN_PLANE = 0x00000001;

        public const uint WGL_SWAP_OVERLAY1 = 0x00000002;

        public const uint WGL_SWAP_OVERLAY2 = 0x00000004;

        public const uint WGL_SWAP_OVERLAY3 = 0x00000008;

        public const uint WGL_SWAP_OVERLAY4 = 0x00000010;

        public const uint WGL_SWAP_OVERLAY5 = 0x00000020;

        public const uint WGL_SWAP_OVERLAY6 = 0x00000040;

        public const uint WGL_SWAP_OVERLAY7 = 0x00000080;

        public const uint WGL_SWAP_OVERLAY8 = 0x00000100;

        public const uint WGL_SWAP_OVERLAY9 = 0x00000200;

        public const uint WGL_SWAP_OVERLAY10 = 0x00000400;

        public const uint WGL_SWAP_OVERLAY11 = 0x00000800;

        public const uint WGL_SWAP_OVERLAY12 = 0x00001000;

        public const uint WGL_SWAP_OVERLAY13 = 0x00002000;

        public const uint WGL_SWAP_OVERLAY14 = 0x00004000;

        public const uint WGL_SWAP_OVERLAY15 = 0x00008000;

        public const uint WGL_SWAP_UNDERLAY1 = 0x00010000;

        public const uint WGL_SWAP_UNDERLAY2 = 0x00020000;

        public const uint WGL_SWAP_UNDERLAY3 = 0x00040000;

        public const uint WGL_SWAP_UNDERLAY4 = 0x00080000;

        public const uint WGL_SWAP_UNDERLAY5 = 0x00100000;

        public const uint WGL_SWAP_UNDERLAY6 = 0x00200000;

        public const uint WGL_SWAP_UNDERLAY7 = 0x00400000;

        public const uint WGL_SWAP_UNDERLAY8 = 0x00800000;

        public const uint WGL_SWAP_UNDERLAY9 = 0x01000000;

        public const uint WGL_SWAP_UNDERLAY10 = 0x02000000;

        public const uint WGL_SWAP_UNDERLAY11 = 0x04000000;

        public const uint WGL_SWAP_UNDERLAY12 = 0x08000000;

        public const uint WGL_SWAP_UNDERLAY13 = 0x10000000;

        public const uint WGL_SWAP_UNDERLAY14 = 0x20000000;

        public const uint WGL_SWAP_UNDERLAY15 = 0x40000000;

        public const uint WGL_SWAPMULTIPLE_MAX = 16;

        public const uint SELECTDIB = 41;

        public const uint TTFCFP_SUBSET = 0;

        public const uint TTFCFP_SUBSET1 = 1;

        public const uint TTFCFP_DELTA = 2;

        public const uint TTFCFP_APPLE_PLATFORMID = 1;

        public const uint TTFCFP_MS_PLATFORMID = 3;

        public const uint TTFCFP_DONT_CARE = 0xFFFF;

        public const uint TTFCFP_LANG_KEEP_ALL = 0;

        public const uint TTFCFP_FLAGS_SUBSET = 0x0001;

        public const uint TTFCFP_FLAGS_COMPRESS = 0x0002;

        public const uint TTFCFP_FLAGS_TTC = 0x0004;

        public const uint TTFCFP_FLAGS_GLYPHLIST = 0x0008;

        public const uint TTFMFP_SUBSET = 0;

        public const uint TTFMFP_SUBSET1 = 1;

        public const uint TTFMFP_DELTA = 2;

        public const uint ERR_GENERIC = 1000;

        public const uint ERR_READOUTOFBOUNDS = 1001;

        public const uint ERR_WRITEOUTOFBOUNDS = 1002;

        public const uint ERR_READCONTROL = 1003;

        public const uint ERR_WRITECONTROL = 1004;

        public const uint ERR_MEM = 1005;

        public const uint ERR_FORMAT = 1006;

        public const uint ERR_WOULD_GROW = 1007;

        public const uint ERR_VERSION = 1008;

        public const uint ERR_NO_GLYPHS = 1009;

        public const uint ERR_INVALID_MERGE_FORMATS = 1010;

        public const uint ERR_INVALID_MERGE_CHECKSUMS = 1011;

        public const uint ERR_INVALID_MERGE_NUMGLYPHS = 1012;

        public const uint ERR_INVALID_DELTA_FORMAT = 1013;

        public const uint ERR_NOT_TTC = 1014;

        public const uint ERR_INVALID_TTC_INDEX = 1015;

        public const uint ERR_MISSING_CMAP = 1030;

        public const uint ERR_MISSING_GLYF = 1031;

        public const uint ERR_MISSING_HEAD = 1032;

        public const uint ERR_MISSING_HHEA = 1033;

        public const uint ERR_MISSING_HMTX = 1034;

        public const uint ERR_MISSING_LOCA = 1035;

        public const uint ERR_MISSING_MAXP = 1036;

        public const uint ERR_MISSING_NAME = 1037;

        public const uint ERR_MISSING_POST = 1038;

        public const uint ERR_MISSING_OS2 = 1039;

        public const uint ERR_MISSING_VHEA = 1040;

        public const uint ERR_MISSING_VMTX = 1041;

        public const uint ERR_MISSING_HHEA_OR_VHEA = 1042;

        public const uint ERR_MISSING_HMTX_OR_VMTX = 1043;

        public const uint ERR_MISSING_EBDT = 1044;

        public const uint ERR_INVALID_CMAP = 1060;

        public const uint ERR_INVALID_GLYF = 1061;

        public const uint ERR_INVALID_HEAD = 1062;

        public const uint ERR_INVALID_HHEA = 1063;

        public const uint ERR_INVALID_HMTX = 1064;

        public const uint ERR_INVALID_LOCA = 1065;

        public const uint ERR_INVALID_MAXP = 1066;

        public const uint ERR_INVALID_NAME = 1067;

        public const uint ERR_INVALID_POST = 1068;

        public const uint ERR_INVALID_OS2 = 1069;

        public const uint ERR_INVALID_VHEA = 1070;

        public const uint ERR_INVALID_VMTX = 1071;

        public const uint ERR_INVALID_HHEA_OR_VHEA = 1072;

        public const uint ERR_INVALID_HMTX_OR_VMTX = 1073;

        public const uint ERR_INVALID_TTO = 1080;

        public const uint ERR_INVALID_GSUB = 1081;

        public const uint ERR_INVALID_GPOS = 1082;

        public const uint ERR_INVALID_GDEF = 1083;

        public const uint ERR_INVALID_JSTF = 1084;

        public const uint ERR_INVALID_BASE = 1085;

        public const uint ERR_INVALID_EBLC = 1086;

        public const uint ERR_INVALID_LTSH = 1087;

        public const uint ERR_INVALID_VDMX = 1088;

        public const uint ERR_INVALID_HDMX = 1089;

        public const uint ERR_PARAMETER0 = 1100;

        public const uint ERR_PARAMETER1 = 1101;

        public const uint ERR_PARAMETER2 = 1102;

        public const uint ERR_PARAMETER3 = 1103;

        public const uint ERR_PARAMETER4 = 1104;

        public const uint ERR_PARAMETER5 = 1105;

        public const uint ERR_PARAMETER6 = 1106;

        public const uint ERR_PARAMETER7 = 1107;

        public const uint ERR_PARAMETER8 = 1108;

        public const uint ERR_PARAMETER9 = 1109;

        public const uint ERR_PARAMETER10 = 1110;

        public const uint ERR_PARAMETER11 = 1111;

        public const uint ERR_PARAMETER12 = 1112;

        public const uint ERR_PARAMETER13 = 1113;

        public const uint ERR_PARAMETER14 = 1114;

        public const uint ERR_PARAMETER15 = 1115;

        public const uint ERR_PARAMETER16 = 1116;

        public const uint CHARSET_DEFAULT = 1;

        public const uint CHARSET_GLYPHIDX = 3;

        public const uint TTEMBED_FAILIFVARIATIONSIMULATED = 0x00000010;

        public const uint TTEMBED_WEBOBJECT = 0x00000080;

        public const uint TTEMBED_XORENCRYPTDATA = 0x10000000;

        public const uint TTEMBED_VARIATIONSIMULATED = 0x00000001;

        public const uint TTEMBED_EUDCEMBEDDED = 0x00000002;

        public const uint TTEMBED_SUBSETCANCEL = 0x00000004;

        public const uint TTLOAD_PRIVATE = 0x00000001;

        public const uint TTLOAD_EUDC_OVERWRITE = 0x00000002;

        public const uint TTLOAD_EUDC_SET = 0x00000004;

        public const uint TTDELETE_DONTREMOVEFONT = 0x00000001;

        public const int E_NONE = 0x0000;

        public const int E_API_NOTIMPL = 0x0001;

        public const int E_CHARCODECOUNTINVALID = 0x0002;

        public const int E_CHARCODESETINVALID = 0x0003;

        public const int E_DEVICETRUETYPEFONT = 0x0004;

        public const int E_HDCINVALID = 0x0006;

        public const int E_NOFREEMEMORY = 0x0007;

        public const int E_FONTREFERENCEINVALID = 0x0008;

        public const int E_NOTATRUETYPEFONT = 0x000A;

        public const int E_ERRORACCESSINGFONTDATA = 0x000C;

        public const int E_ERRORACCESSINGFACENAME = 0x000D;

        public const int E_ERRORUNICODECONVERSION = 0x0011;

        public const int E_ERRORCONVERTINGCHARS = 0x0012;

        public const int E_EXCEPTION = 0x0013;

        public const int E_RESERVEDPARAMNOTNULL = 0x0014;

        public const int E_CHARSETINVALID = 0x0015;

        public const int E_FILE_NOT_FOUND = 0x0017;

        public const int E_TTC_INDEX_OUT_OF_RANGE = 0x0018;

        public const int E_INPUTPARAMINVALID = 0x0019;

        public const int E_ERRORCOMPRESSINGFONTDATA = 0x0100;

        public const int E_FONTDATAINVALID = 0x0102;

        public const int E_NAMECHANGEFAILED = 0x0103;

        public const int E_FONTNOTEMBEDDABLE = 0x0104;

        public const int E_PRIVSINVALID = 0x0105;

        public const int E_SUBSETTINGFAILED = 0x0106;

        public const int E_READFROMSTREAMFAILED = 0x0107;

        public const int E_SAVETOSTREAMFAILED = 0x0108;

        public const int E_NOOS2 = 0x0109;

        public const int E_T2NOFREEMEMORY = 0x010A;

        public const int E_ERRORREADINGFONTDATA = 0x010B;

        public const int E_FLAGSINVALID = 0x010C;

        public const int E_ERRORCREATINGFONTFILE = 0x010D;

        public const int E_FONTALREADYEXISTS = 0x010E;

        public const int E_FONTNAMEALREADYEXISTS = 0x010F;

        public const int E_FONTINSTALLFAILED = 0x0110;

        public const int E_ERRORDECOMPRESSINGFONTDATA = 0x0111;

        public const int E_ERRORACCESSINGEXCLUDELIST = 0x0112;

        public const int E_FACENAMEINVALID = 0x0113;

        public const int E_STREAMINVALID = 0x0114;

        public const int E_STATUSINVALID = 0x0115;

        public const int E_PRIVSTATUSINVALID = 0x0116;

        public const int E_PERMISSIONSINVALID = 0x0117;

        public const int E_PBENABLEDINVALID = 0x0118;

        public const int E_SUBSETTINGEXCEPTION = 0x0119;

        public const int E_SUBSTRING_TEST_FAIL = 0x011A;

        public const int E_FONTVARIATIONSIMULATED = 0x011B;

        public const int E_FONTFAMILYNAMENOTINFULL = 0x011D;

        public const int E_ADDFONTFAILED = 0x0200;

        public const int E_COULDNTCREATETEMPFILE = 0x0201;

        public const int E_FONTFILECREATEFAILED = 0x0203;

        public const int E_WINDOWSAPI = 0x0204;

        public const int E_FONTFILENOTFOUND = 0x0205;

        public const int E_RESOURCEFILECREATEFAILED = 0x0206;

        public const int E_ERROREXPANDINGFONTDATA = 0x0207;

        public const int E_ERRORGETTINGDC = 0x0208;

        public const int E_EXCEPTIONINDECOMPRESSION = 0x0209;

        public const int E_EXCEPTIONINCOMPRESSION = 0x020A;

    }
}
