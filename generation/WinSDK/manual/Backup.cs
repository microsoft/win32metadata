using Windows.Win32.Interop;

namespace Windows.Win32.System.SystemServices
{
    // Because of ClangSharp: https://github.com/dotnet/ClangSharp/issues/366
    // If this gets fixed we could remove this class
    public unsafe partial struct ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION
    {
        [NativeTypeName("DWORD")]
        public uint ElementCount;

        [NativeTypeName("COMPATIBILITY_CONTEXT_ELEMENT[]")]
        public COMPATIBILITY_CONTEXT_ELEMENT* Elements;
    }
}
