using System;
using System.Collections.Generic;
using System.Text;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.System.WinRT
{
    public struct EventRegistrationToken
    {
        public long value;
    }

    public struct HSTRING_HEADER
    {
        public uint flags;
        public uint length;
        public uint padding1;
        public uint padding2;
        public IntPtr data;
    }
}
