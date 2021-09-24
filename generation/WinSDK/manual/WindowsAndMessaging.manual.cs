using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.UI.WindowsAndMessaging
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_CALLBACK = -1;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_SYSTEM = 1;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_RESTORE    = 2;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_MINIMIZE   = 3;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_CLOSE      = 5;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_CLOSE_D    = 6;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_MBAR_MINIMIZE_D = 7;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_CLOSE     = 8;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_RESTORE   = 9;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_MAXIMIZE  = 10;

        [NativeTypeName("HBITMAP")]
        public const int HBMMENU_POPUP_MINIMIZE = 11;

        public const int CW_USEDEFAULT = unchecked((int)0x80000000);

        public const int LBS_STANDARD = (LBS_NOTIFY | LBS_SORT | (int)WINDOW_STYLE.WS_VSCROLL | (int)WINDOW_STYLE.WS_BORDER);
    }

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int WINSTAENUMPROCA([NativeTypeName("LPSTR")] sbyte* param0, [NativeTypeName("LPARAM")] IntPtr param1);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int WINSTAENUMPROCW([NativeTypeName("LPWSTR")] ushort* param0, [NativeTypeName("LPARAM")] IntPtr param1);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int DESKTOPENUMPROCA([NativeTypeName("LPSTR")] sbyte* param0, [NativeTypeName("LPARAM")] IntPtr param1);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int DESKTOPENUMPROCW([NativeTypeName("LPWSTR")] ushort* param0, [NativeTypeName("LPARAM")] IntPtr param1);

    [Flags]
    public enum DI_FLAGS : uint
    {
        DI_MASK = 0x0001,
        DI_IMAGE = 0x0002,
        DI_NORMAL = 0x0003,
        DI_COMPAT = 0x0004,
        DI_DEFAULTSIZE = 0x0008,
        DI_NOMIRROR = 0x0010,
    }
}
