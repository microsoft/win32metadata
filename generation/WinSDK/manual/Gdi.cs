using System;
using System.Runtime.InteropServices;

using Windows.Win32.Interop;

namespace Windows.Win32.Graphics.Gdi
{
    public enum R2_MODE
    {
        R2_BLACK = 1,
        R2_NOTMERGEPEN = 2,
        R2_MASKNOTPEN = 3,
        R2_NOTCOPYPEN = 4,
        R2_MASKPENNOT = 5,
        R2_NOT = 6,
        R2_XORPEN = 7,
        R2_NOTMASKPEN = 8,
        R2_MASKPEN = 9,
        R2_NOTXORPEN = 10,
        R2_NOP = 11,
        R2_MERGENOTPEN = 12,
        R2_COPYPEN = 13,
        R2_MERGEPENNOT = 14,
        R2_MERGEPEN = 15,
        R2_WHITE = 16,
        R2_LAST = 16
    }

    public enum RGN_COMBINE_MODE
    {
        RGN_AND = 1,
        RGN_OR = 2,
        RGN_XOR = 3,
        RGN_DIFF = 4,
        RGN_COPY = 5,
        RGN_MIN = RGN_AND,
        RGN_MAX = RGN_COPY
    }

    [Flags]
    public enum ETO_OPTIONS : uint
    {
        ETO_OPAQUE = 0x0002,
        ETO_CLIPPED = 0x0004,
        ETO_GLYPH_INDEX = 0x0010,
        ETO_RTLREADING = 0x0080,
        ETO_NUMERICSLOCAL = 0x0400,
        ETO_NUMERICSLATIN = 0x0800,
        ETO_IGNORELANGUAGE = 0x1000,
        ETO_PDY = 0x2000,
        ETO_REVERSE_INDEX_MAP = 0x10000,
    }

    public enum OBJ_TYPE
    {
        OBJ_PEN = 1,
        OBJ_BRUSH = 2,
        OBJ_DC = 3,
        OBJ_METADC = 4,
        OBJ_PAL = 5,
        OBJ_FONT = 6,
        OBJ_BITMAP = 7,
        OBJ_REGION = 8,
        OBJ_METAFILE = 9,
        OBJ_MEMDC = 10,
        OBJ_EXTPEN = 11,
        OBJ_ENHMETADC = 12,
        OBJ_ENHMETAFILE = 13,
        OBJ_COLORSPACE = 14
    }

    public enum DIB_USAGE : uint
    {
        DIB_RGB_COLORS = 0,
        DIB_PAL_COLORS = 1
    }
    
    [NativeTypeName("struct tagMONITORINFOEXA : tagMONITORINFO")]
    [NativeInheritance("tagMONITORINFO")]
    public unsafe partial struct MONITORINFOEXA
    {
        public MONITORINFO monitorInfo;

        [NativeTypeName("CHAR [32]")]
        public fixed sbyte szDevice[32];
    }

    [NativeTypeName("struct tagMONITORINFOEXW : tagMONITORINFO")]
    [NativeInheritance("tagMONITORINFO")]
    public unsafe partial struct MONITORINFOEXW
    {
        public MONITORINFO monitorInfo;

        [NativeTypeName("WCHAR [32]")]
        public fixed ushort szDevice[32];
    }

    public static unsafe partial class Apis
    {
        // We need to add this manually because in baseRemap.rsp we are fixing GetObjectA to go back to GetObject.
        // Otherwise lots of other COM functions that are defined as GetObject turn into GetObjectA
        [DllImport("GDI32.dll", ExactSpelling = true)]
        public static extern int GetObjectA([NativeTypeName("HANDLE")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] IntPtr h, [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] int c, [NativeTypeName("LPVOID")][CppAttributeList("Name=SAL_name; p1=\"_Out_writes_bytes_opt_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_opt_bytecap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__maybe^Name=SAL_writableTo; p1=byteCount(c)^Name=SAL_end^Name=SAL_post^Name=SAL_valid")] void* pv);
    }
}
