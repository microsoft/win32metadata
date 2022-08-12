
using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.WindowsProgramming
{
    // Because we can't undef DeleteFile since winbase.h first calls filapi.h and then
    // has this struct. Without this, the field is named DeleteFileA
    public partial struct FILE_DISPOSITION_INFO
    {
        [NativeTypeName("BOOLEAN")]
        public byte DeleteFile;
    }
}
