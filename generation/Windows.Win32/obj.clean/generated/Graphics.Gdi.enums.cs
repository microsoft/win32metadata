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


using static Windows.Win32.Graphics.Gdi.Apis;

namespace Windows.Win32.Graphics.Gdi
{
    [Flags]
    public enum DRAWEDGE_FLAGS : uint
    {
        BDR_RAISEDOUTER = 0x0001,
        BDR_SUNKENOUTER = 0x0002,
        BDR_RAISEDINNER = 0x0004,
        BDR_SUNKENINNER = 0x0008,
        BDR_OUTER = (BDR_RAISEDOUTER | BDR_SUNKENOUTER),
        BDR_INNER = (BDR_RAISEDINNER | BDR_SUNKENINNER),
        BDR_RAISED = (BDR_RAISEDOUTER | BDR_RAISEDINNER),
        BDR_SUNKEN = (BDR_SUNKENOUTER | BDR_SUNKENINNER),
        EDGE_RAISED = (BDR_RAISEDOUTER | BDR_RAISEDINNER),
        EDGE_SUNKEN = (BDR_SUNKENOUTER | BDR_SUNKENINNER),
        EDGE_ETCHED = (BDR_SUNKENOUTER | BDR_RAISEDINNER),
        EDGE_BUMP = (BDR_RAISEDOUTER | BDR_SUNKENINNER),
    }

    public enum DFC_TYPE : uint
    {
        DFC_CAPTION = 1,
        DFC_MENU = 2,
        DFC_SCROLL = 3,
        DFC_BUTTON = 4,
        DFC_POPUPMENU = 5,
    }

    [Flags]
    public enum DFCS_STATE : uint
    {
        DFCS_CAPTIONCLOSE = 0x0000,
        DFCS_CAPTIONMIN = 0x0001,
        DFCS_CAPTIONMAX = 0x0002,
        DFCS_CAPTIONRESTORE = 0x0003,
        DFCS_CAPTIONHELP = 0x0004,
        DFCS_MENUARROW = 0x0000,
        DFCS_MENUCHECK = 0x0001,
        DFCS_MENUBULLET = 0x0002,
        DFCS_MENUARROWRIGHT = 0x0004,
        DFCS_SCROLLUP = 0x0000,
        DFCS_SCROLLDOWN = 0x0001,
        DFCS_SCROLLLEFT = 0x0002,
        DFCS_SCROLLRIGHT = 0x0003,
        DFCS_SCROLLCOMBOBOX = 0x0005,
        DFCS_SCROLLSIZEGRIP = 0x0008,
        DFCS_SCROLLSIZEGRIPRIGHT = 0x0010,
        DFCS_BUTTONCHECK = 0x0000,
        DFCS_BUTTONRADIOIMAGE = 0x0001,
        DFCS_BUTTONRADIOMASK = 0x0002,
        DFCS_BUTTONRADIO = 0x0004,
        DFCS_BUTTON3STATE = 0x0008,
        DFCS_BUTTONPUSH = 0x0010,
        DFCS_INACTIVE = 0x0100,
        DFCS_PUSHED = 0x0200,
        DFCS_CHECKED = 0x0400,
        DFCS_TRANSPARENT = 0x0800,
        DFCS_HOT = 0x1000,
        DFCS_ADJUSTRECT = 0x2000,
        DFCS_FLAT = 0x4000,
        DFCS_MONO = 0x8000,
    }

    [Flags]
    public enum CDS_TYPE : uint
    {
        CDS_FULLSCREEN = 0x00000004,
        CDS_GLOBAL = 0x00000008,
        CDS_NORESET = 0x10000000,
        CDS_RESET = 0x40000000,
        CDS_SET_PRIMARY = 0x00000010,
        CDS_TEST = 0x00000002,
        CDS_UPDATEREGISTRY = 0x00000001,
        CDS_VIDEOPARAMETERS = 0x00000020,
        CDS_ENABLE_UNSAFE_MODES = 0x00000100,
        CDS_DISABLE_UNSAFE_MODES = 0x00000200,
        CDS_RESET_EX = 0x20000000,
    }

    public enum DISP_CHANGE
    {
        DISP_CHANGE_SUCCESSFUL = 0,
        DISP_CHANGE_RESTART = 1,
        DISP_CHANGE_FAILED = -1,
        DISP_CHANGE_BADMODE = -2,
        DISP_CHANGE_NOTUPDATED = -3,
        DISP_CHANGE_BADFLAGS = -4,
        DISP_CHANGE_BADPARAM = -5,
        DISP_CHANGE_BADDUALVIEW = -6,
    }

    [Flags]
    public enum DRAWSTATE_FLAGS : uint
    {
        DST_COMPLEX = 0x0000,
        DST_TEXT = 0x0001,
        DST_PREFIXTEXT = 0x0002,
        DST_ICON = 0x0003,
        DST_BITMAP = 0x0004,
        DSS_NORMAL = 0x0000,
        DSS_UNION = 0x0010,
        DSS_DISABLED = 0x0020,
        DSS_MONO = 0x0080,
        DSS_HIDEPREFIX = 0x0200,
        DSS_PREFIXONLY = 0x0400,
        DSS_RIGHT = 0x8000,
    }

    [Flags]
    public enum REDRAW_WINDOW_FLAGS : uint
    {
        RDW_INVALIDATE = 0x0001,
        RDW_INTERNALPAINT = 0x0002,
        RDW_ERASE = 0x0004,
        RDW_VALIDATE = 0x0008,
        RDW_NOINTERNALPAINT = 0x0010,
        RDW_NOERASE = 0x0020,
        RDW_NOCHILDREN = 0x0040,
        RDW_ALLCHILDREN = 0x0080,
        RDW_UPDATENOW = 0x0100,
        RDW_ERASENOW = 0x0200,
        RDW_FRAME = 0x0400,
        RDW_NOFRAME = 0x0800,
    }

    public enum ENUM_DISPLAY_SETTINGS_MODE : uint
    {
        ENUM_CURRENT_SETTINGS = unchecked((uint)-1),
        ENUM_REGISTRY_SETTINGS = unchecked((uint)-2),
    }

    [Flags]
    public enum PEN_STYLE : uint
    {
        PS_GEOMETRIC = 0x00010000,
        PS_COSMETIC = 0x00000000,
        PS_SOLID = 0,
        PS_DASH = 1,
        PS_DOT = 2,
        PS_DASHDOT = 3,
        PS_DASHDOTDOT = 4,
        PS_NULL = 5,
        PS_INSIDEFRAME = 6,
        PS_USERSTYLE = 7,
        PS_ALTERNATE = 8,
        PS_STYLE_MASK = 0x0000000F,
        PS_ENDCAP_ROUND = 0x00000000,
        PS_ENDCAP_SQUARE = 0x00000100,
        PS_ENDCAP_FLAT = 0x00000200,
        PS_ENDCAP_MASK = 0x00000F00,
        PS_JOIN_ROUND = 0x00000000,
        PS_JOIN_BEVEL = 0x00001000,
        PS_JOIN_MITER = 0x00002000,
        PS_JOIN_MASK = 0x0000F000,
        PS_TYPE_MASK = 0x000F0000,
    }

    [Flags]
    public enum TTEMBED_FLAGS : uint
    {
        TTEMBED_EMBEDEUDC = 0x00000020,
        TTEMBED_RAW = 0x00000000,
        TTEMBED_SUBSET = 0x00000001,
        TTEMBED_TTCOMPRESSED = 0x00000004,
    }

    [Flags]
    public enum DRAW_TEXT_FORMAT : uint
    {
        DT_BOTTOM = 0x00000008,
        DT_CALCRECT = 0x00000400,
        DT_CENTER = 0x00000001,
        DT_EDITCONTROL = 0x00002000,
        DT_END_ELLIPSIS = 0x00008000,
        DT_EXPANDTABS = 0x00000040,
        DT_EXTERNALLEADING = 0x00000200,
        DT_HIDEPREFIX = 0x00100000,
        DT_INTERNAL = 0x00001000,
        DT_LEFT = 0x00000000,
        DT_MODIFYSTRING = 0x00010000,
        DT_NOCLIP = 0x00000100,
        DT_NOFULLWIDTHCHARBREAK = 0x00080000,
        DT_NOPREFIX = 0x00000800,
        DT_PATH_ELLIPSIS = 0x00004000,
        DT_PREFIXONLY = 0x00200000,
        DT_RIGHT = 0x00000002,
        DT_RTLREADING = 0x00020000,
        DT_SINGLELINE = 0x00000020,
        DT_TABSTOP = 0x00000080,
        DT_TOP = 0x00000000,
        DT_VCENTER = 0x00000004,
        DT_WORDBREAK = 0x00000010,
        DT_WORD_ELLIPSIS = 0x00040000,
    }

    public enum EMBED_FONT_CHARSET : uint
    {
        CHARSET_UNICODE = 1,
        CHARSET_SYMBOL = 2,
    }

    [Flags]
    public enum GET_DCX_FLAGS : uint
    {
        DCX_WINDOW = 0x00000001,
        DCX_CACHE = 0x00000002,
        DCX_PARENTCLIP = 0x00000020,
        DCX_CLIPSIBLINGS = 0x00000010,
        DCX_CLIPCHILDREN = 0x00000008,
        DCX_NORESETATTRS = 0x00000004,
        DCX_LOCKWINDOWUPDATE = 0x00000400,
        DCX_EXCLUDERGN = 0x00000040,
        DCX_INTERSECTRGN = 0x00000080,
        DCX_INTERSECTUPDATE = 0x00000200,
        DCX_VALIDATE = 0x00200000,
    }

    public enum GET_GLYPH_OUTLINE_FORMAT : uint
    {
        GGO_BEZIER = 3,
        GGO_BITMAP = 1,
        GGO_GLYPH_INDEX = 0x0080,
        GGO_GRAY2_BITMAP = 4,
        GGO_GRAY4_BITMAP = 5,
        GGO_GRAY8_BITMAP = 6,
        GGO_METRICS = 0,
        GGO_NATIVE = 2,
        GGO_UNHINTED = 0x0100,
    }

    public enum SET_BOUNDS_RECT_FLAGS : uint
    {
        DCB_ACCUMULATE = 0x0002,
        DCB_DISABLE = 0x0008,
        DCB_ENABLE = 0x0004,
        DCB_RESET = 0x0001,
    }

    public enum GET_STOCK_OBJECT_FLAGS : uint
    {
        BLACK_BRUSH = 4,
        DKGRAY_BRUSH = 3,
        DC_BRUSH = 18,
        GRAY_BRUSH = 2,
        HOLLOW_BRUSH = NULL_BRUSH,
        LTGRAY_BRUSH = 1,
        NULL_BRUSH = 5,
        WHITE_BRUSH = 0,
        BLACK_PEN = 7,
        DC_PEN = 19,
        NULL_PEN = 8,
        WHITE_PEN = 6,
        ANSI_FIXED_FONT = 11,
        ANSI_VAR_FONT = 12,
        DEVICE_DEFAULT_FONT = 14,
        DEFAULT_GUI_FONT = 17,
        OEM_FIXED_FONT = 10,
        SYSTEM_FONT = 13,
        SYSTEM_FIXED_FONT = 16,
        DEFAULT_PALETTE = 15,
    }

    public enum MODIFY_WORLD_TRANSFORM_MODE : uint
    {
        MWT_IDENTITY = 1,
        MWT_LEFTMULTIPLY = 2,
        MWT_RIGHTMULTIPLY = 3,
    }

    [Flags]
    public enum FONT_CLIP_PRECISION : uint
    {
        CLIP_CHARACTER_PRECIS = 1,
        CLIP_DEFAULT_PRECIS = 0,
        CLIP_DFA_DISABLE = 4u<<4,
        CLIP_EMBEDDED = 8u<<4,
        CLIP_LH_ANGLES = 1u<<4,
        CLIP_MASK = 0xf,
        CLIP_STROKE_PRECIS = 2,
        CLIP_TT_ALWAYS = 2u<<4,
    }

    public enum CREATE_POLYGON_RGN_MODE : uint
    {
        ALTERNATE = 1,
        WINDING = 2,
    }

    public enum EMBEDDED_FONT_PRIV_STATUS : uint
    {
        EMBED_PREVIEWPRINT = 1,
        EMBED_EDITABLE = 2,
        EMBED_INSTALLABLE = 3,
        EMBED_NOEMBEDDING = 4,
    }

    public enum MONITOR_FROM_FLAGS : uint
    {
        MONITOR_DEFAULTTONEAREST = 0x00000002,
        MONITOR_DEFAULTTONULL = 0x00000000,
        MONITOR_DEFAULTTOPRIMARY = 0x00000001,
    }

    public enum FONT_RESOURCE_CHARACTERISTICS : uint
    {
        FR_PRIVATE = 0x10,
        FR_NOT_ENUM = 0x20,
    }

    [Flags]
    public enum DC_LAYOUT : uint
    {
        LAYOUT_BITMAPORIENTATIONPRESERVED = 0x00000008,
        LAYOUT_RTL = 0x00000001,
    }

    public enum GET_DEVICE_CAPS_INDEX : uint
    {
        DRIVERVERSION = 0,
    }

    public enum FONT_OUTPUT_PRECISION : uint
    {
        OUT_CHARACTER_PRECIS = 2,
        OUT_DEFAULT_PRECIS = 0,
        OUT_DEVICE_PRECIS = 5,
        OUT_OUTLINE_PRECIS = 8,
        OUT_PS_ONLY_PRECIS = 10,
        OUT_RASTER_PRECIS = 6,
        OUT_STRING_PRECIS = 1,
        OUT_STROKE_PRECIS = 3,
        OUT_TT_ONLY_PRECIS = 7,
        OUT_TT_PRECIS = 4,
    }

    public enum ARC_DIRECTION : uint
    {
        AD_COUNTERCLOCKWISE = 1,
        AD_CLOCKWISE = 2,
    }

    [Flags]
    public enum TTLOAD_EMBEDDED_FONT_STATUS : uint
    {
        TTLOAD_FONT_SUBSETTED = 0x00000001,
        TTLOAD_FONT_IN_SYSSTARTUP = 0x00000002,
    }

    public enum STRETCH_BLT_MODE : uint
    {
        BLACKONWHITE = 1,
        COLORONCOLOR = 3,
        HALFTONE = 4,
        STRETCH_ANDSCANS = BLACKONWHITE,
        STRETCH_DELETESCANS = COLORONCOLOR,
        STRETCH_HALFTONE = HALFTONE,
        STRETCH_ORSCANS = WHITEONBLACK,
        WHITEONBLACK = 2,
    }

    public enum FONT_QUALITY : uint
    {
        ANTIALIASED_QUALITY = 4,
        CLEARTYPE_QUALITY = 5,
        DEFAULT_QUALITY = 0,
        DRAFT_QUALITY = 1,
        NONANTIALIASED_QUALITY = 3,
        PROOF_QUALITY = 2,
    }

    public enum BACKGROUND_MODE : uint
    {
        OPAQUE = 2,
        TRANSPARENT = 1,
    }

    [Flags]
    public enum GET_CHARACTER_PLACEMENT_FLAGS : uint
    {
        GCP_CLASSIN = 0x00080000,
        GCP_DIACRITIC = 0x0100,
        GCP_DISPLAYZWG = 0x00400000,
        GCP_GLYPHSHAPE = 0x0010,
        GCP_JUSTIFY = 0x00010000,
        GCP_KASHIDA = 0x0400,
        GCP_LIGATE = 0x0020,
        GCP_MAXEXTENT = 0x00100000,
        GCP_NEUTRALOVERRIDE = 0x02000000,
        GCP_NUMERICOVERRIDE = 0x01000000,
        GCP_NUMERICSLATIN = 0x04000000,
        GCP_NUMERICSLOCAL = 0x08000000,
        GCP_REORDER = 0x0002,
        GCP_SYMSWAPOFF = 0x00800000,
        GCP_USEKERNING = 0x0008,
    }

    [Flags]
    public enum DRAW_EDGE_FLAGS : uint
    {
        BF_ADJUST = 0x2000,
        BF_BOTTOM = 0x0008,
        BF_BOTTOMLEFT = (BF_BOTTOM | BF_LEFT),
        BF_BOTTOMRIGHT = (BF_BOTTOM | BF_RIGHT),
        BF_DIAGONAL = 0x0010,
        BF_DIAGONAL_ENDBOTTOMLEFT = (BF_DIAGONAL | BF_BOTTOM | BF_LEFT),
        BF_DIAGONAL_ENDBOTTOMRIGHT = (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT),
        BF_DIAGONAL_ENDTOPLEFT = (BF_DIAGONAL | BF_TOP | BF_LEFT),
        BF_DIAGONAL_ENDTOPRIGHT = (BF_DIAGONAL | BF_TOP | BF_RIGHT),
        BF_FLAT = 0x4000,
        BF_LEFT = 0x0001,
        BF_MIDDLE = 0x0800,
        BF_MONO = 0x8000,
        BF_RECT = (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM),
        BF_RIGHT = 0x0004,
        BF_SOFT = 0x1000,
        BF_TOP = 0x0002,
        BF_TOPLEFT = (BF_TOP | BF_LEFT),
        BF_TOPRIGHT = (BF_TOP | BF_RIGHT),
    }

    public enum FONT_LICENSE_PRIVS : uint
    {
        LICENSE_PREVIEWPRINT = 0x0004,
        LICENSE_EDITABLE = 0x0008,
        LICENSE_INSTALLABLE = 0x0000,
        LICENSE_NOEMBEDDING = 0x0002,
        LICENSE_DEFAULT = 0x0000,
    }

    public enum GRADIENT_FILL : uint
    {
        GRADIENT_FILL_RECT_H = 0x00000000,
        GRADIENT_FILL_RECT_V = 0x00000001,
        GRADIENT_FILL_TRIANGLE = 0x00000002,
    }

    public enum CREATE_FONT_PACKAGE_SUBSET_ENCODING : uint
    {
        TTFCFP_STD_MAC_CHAR_SET = 0,
        TTFCFP_SYMBOL_CHAR_SET = 0,
        TTFCFP_UNICODE_CHAR_SET = 1,
    }

    public enum EXT_FLOOD_FILL_TYPE : uint
    {
        FLOODFILLBORDER = 0,
        FLOODFILLSURFACE = 1,
    }

    public enum HATCH_BRUSH_STYLE : uint
    {
        HS_BDIAGONAL = 3,
        HS_CROSS = 4,
        HS_DIAGCROSS = 5,
        HS_FDIAGONAL = 2,
        HS_HORIZONTAL = 0,
        HS_VERTICAL = 1,
    }

    [Flags]
    public enum DRAW_CAPTION_FLAGS : uint
    {
        DC_ACTIVE = 0x0001,
        DC_BUTTONS = 0x1000,
        DC_GRADIENT = 0x0020,
        DC_ICON = 0x0004,
        DC_INBUTTON = 0x0010,
        DC_SMALLCAP = 0x0002,
        DC_TEXT = 0x0008,
    }

    public enum SYSTEM_PALETTE_USE : uint
    {
        SYSPAL_NOSTATIC = 2,
        SYSPAL_NOSTATIC256 = 3,
        SYSPAL_STATIC = 1,
    }

    public enum GRAPHICS_MODE : uint
    {
        GM_COMPATIBLE = 1,
        GM_ADVANCED = 2,
    }

    public enum FONT_PITCH_AND_FAMILY : uint
    {
        FF_DECORATIVE = 5u<<4,
        FF_DONTCARE = 0u<<4,
        FF_MODERN = 3u<<4,
        FF_ROMAN = 1u<<4,
        FF_SCRIPT = 4u<<4,
        FF_SWISS = 2u<<4,
    }

    public enum CREATE_FONT_PACKAGE_SUBSET_PLATFORM : uint
    {
        TTFCFP_UNICODE_PLATFORMID = 0,
        TTFCFP_ISO_PLATFORMID = 2,
    }

    public enum HDC_MAP_MODE : uint
    {
        MM_ANISOTROPIC = 8,
        MM_HIENGLISH = 5,
        MM_HIMETRIC = 3,
        MM_ISOTROPIC = 7,
        MM_LOENGLISH = 4,
        MM_LOMETRIC = 2,
        MM_TEXT = 1,
        MM_TWIPS = 6,
    }

}
