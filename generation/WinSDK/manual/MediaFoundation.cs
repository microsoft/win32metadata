using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Media.MediaFoundation
{
    public static unsafe partial class Apis
    {
        public const uint MF_VERSION = (MF_SDK_VERSION << 16 | MF_API_VERSION);
    }

    // Because emits this: MF_Plugin_Type_Other = unchecked((uint)(-1)), and enum is int
    public enum MF_Plugin_Type
    {
        MF_Plugin_Type_MFT = 0,
        MF_Plugin_Type_MediaSource = 1,
        MF_Plugin_Type_MFT_MatchOutputType = 2,
        MF_Plugin_Type_Other = -1,
    }
}
