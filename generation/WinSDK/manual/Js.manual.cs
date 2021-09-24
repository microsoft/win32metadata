using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Js
{
    public enum JsRuntimeVersion
    {
        JsRuntimeVersion10 = 0,
        JsRuntimeVersion11 = 1,
        JsRuntimeVersionEdge = -1,
    }

    public static unsafe partial class Apis
    {
        // We would like this to be a UIntPtr but you can't use those as constants
        const ulong JS_SOURCE_CONTEXT_NONE = ulong.MaxValue;
    }
}
