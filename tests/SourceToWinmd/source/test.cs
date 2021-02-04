// Copyright © Microsoft
using System;
using System.Runtime.InteropServices;

using Windows.Win32.Interop;

namespace Windows.Win32.Test
{
    public enum MyEnum
    {
        A,
        B,
        C
    }

    public struct MyStruct
    {
        public uint X;
    }

    public static unsafe partial class Apis
    {
		public const string NormalConst = "my const value";
		public static readonly Guid CLSID_Guid1 = new Guid(0x2CD90691, 0x12E2, 0x11DC, 0x9F, 0xED, 0x00, 0x11, 0x43, 0xA0, 0x55, 0xF9);
        public static readonly Guid CLSID_Guid2 = new Guid("00000000-0000-0000-C000-000000000046");

        [DllImport("MyDll", ExactSpelling = true, SetLastError = true)]
        public static extern int MyFunc(uint x);
    }
}
