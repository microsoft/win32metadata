using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;
using static Windows.Win32.System.SystemServices.Apis;

namespace Windows.Win32.Graphics.DirectWrite
{
    public static unsafe partial class Apis
    {
        public static uint DWRITE_MAKE_OPENTYPE_TAG(byte a, byte b, byte c, byte d) => ((uint)d << 24) | ((uint)c << 16) | ((uint)b << 8) | a;

        public static DWRITE_FONT_AXIS_TAG DWRITE_MAKE_FONT_AXIS_TAG(byte a, byte b, byte c, byte d) => (DWRITE_FONT_AXIS_TAG)DWRITE_MAKE_OPENTYPE_TAG(a, b, c, d);
    }

    public enum DWRITE_FONT_AXIS_TAG : uint
    {
        DWRITE_FONT_AXIS_TAG_WEIGHT = (((uint)((byte)('t')) << 24) | ((uint)((byte)('h')) << 16) | ((uint)((byte)('g')) << 8) | (uint)((byte)('w'))),
        DWRITE_FONT_AXIS_TAG_WIDTH = (((uint)((byte)('h')) << 24) | ((uint)((byte)('t')) << 16) | ((uint)((byte)('d')) << 8) | (uint)((byte)('w'))),
        DWRITE_FONT_AXIS_TAG_SLANT = (((uint)((byte)('t')) << 24) | ((uint)((byte)('n')) << 16) | ((uint)((byte)('l')) << 8) | (uint)((byte)('s'))),
        DWRITE_FONT_AXIS_TAG_OPTICAL_SIZE = (((uint)((byte)('z')) << 24) | ((uint)((byte)('s')) << 16) | ((uint)((byte)('p')) << 8) | (uint)((byte)('o'))),
        DWRITE_FONT_AXIS_TAG_ITALIC = (((uint)((byte)('l')) << 24) | ((uint)((byte)('a')) << 16) | ((uint)((byte)('t')) << 8) | (uint)((byte)('i'))),
    }

    public partial struct DWRITE_COLOR_F
    {
        public float r;

        public float g;

        public float b;

        public float a;
    }
}
