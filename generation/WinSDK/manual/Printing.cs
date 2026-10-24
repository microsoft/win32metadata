using System;
using System.Runtime.InteropServices;
using Windows.Win32.Devices.Communication;
using Windows.Win32.Foundation;
using Windows.Win32.Foundation.Metadata;
using Windows.Win32.System.Power;

namespace Windows.Win32.Graphics.Printing
{
    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ENUMPORTS([NativeTypeName("LPWSTR"), In, Optional] ushort* param0, [In] uint param1, [Out, Optional] byte* param2, [In] uint param3, [Out] uint* param4, [Out] uint* param5);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_OPENPORT([NativeTypeName("LPWSTR"), In] ushort* param0, [NativeTypeName("PHANDLE"), Out] HANDLE* param1);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_OPENPORTEX([NativeTypeName("HANDLE"), In] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [NativeTypeName("LPWSTR"), In] ushort* param2, [NativeTypeName("PHANDLE"), Out] HANDLE* param3, [In] MONITOR2* param4);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_STARTDOCPORT([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [In] uint param2, [In] uint param3, [In] byte* param4);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_WRITEPORT([NativeTypeName("HANDLE")] IntPtr param0, [In] byte* param1, [In] uint param2, [Out] uint* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_READPORT([NativeTypeName("HANDLE")] IntPtr param0, [Out, Optional] byte* param1, [In] uint param2, [Out] uint* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ENDDOCPORT([NativeTypeName("HANDLE")] IntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_CLOSEPORT([NativeTypeName("HANDLE")] IntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ADDPORT([NativeTypeName("LPWSTR"), In] ushort* param0, [NativeTypeName("HWND"), In] IntPtr param1, [NativeTypeName("LPWSTR"), In] ushort* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ADDPORTEX([NativeTypeName("LPWSTR"), In] ushort* param0, [In] uint param1, [In] byte* param2, [NativeTypeName("LPWSTR"), In] ushort* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_CONFIGUREPORT([NativeTypeName("LPWSTR"), In] ushort* param0, [NativeTypeName("HWND"), In] IntPtr param1, [NativeTypeName("LPWSTR"), In] ushort* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_DELETEPORT([NativeTypeName("LPWSTR"), In] ushort* param0, [NativeTypeName("HWND"), In] IntPtr param1, [NativeTypeName("LPWSTR"), In] ushort* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_GETPRINTERDATAFROMPORT([NativeTypeName("HANDLE")] IntPtr param0, [In] uint param1, [NativeTypeName("LPWSTR"), In] ushort* param2, [NativeTypeName("LPWSTR"), In] ushort* param3, [In] uint param4, [NativeTypeName("LPWSTR"), Out, Optional] ushort* param5, [In] uint param6, [Out] uint* param7);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_SETPORTTIMEOUTS([NativeTypeName("HANDLE")] IntPtr param0, [In] COMMTIMEOUTS* param1, [In, Reserved] uint param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_XCVOPENPORT([NativeTypeName("LPCWSTR"), Const, In] ushort* param0, [In] uint param1, [NativeTypeName("PHANDLE"), Out] HANDLE* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint PFN_PRINTING_XCVDATAPORT([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPCWSTR"), Const, In] ushort* param1, [In] byte* param2, [In] uint param3, [Out, Optional] byte* param4, [In] uint param5, [Out] uint* param6);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_XCVCLOSEPORT([NativeTypeName("HANDLE")] IntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ENUMPORTS2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In, Optional] ushort* param1, [In] uint param2, [Out, Optional] byte* param3, [In] uint param4, [Out] uint* param5, [Out] uint* param6);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_OPENPORT2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [NativeTypeName("PHANDLE"), Out] HANDLE* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_OPENPORTEX2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("HANDLE"), In] IntPtr param1, [NativeTypeName("LPWSTR"), In] ushort* param2, [NativeTypeName("LPWSTR"), In] ushort* param3, [NativeTypeName("PHANDLE"), Out] HANDLE* param4, [In] MONITOR2* param5);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_STARTDOCPORT2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [In] uint param2, [In] uint param3, [In] byte* param4);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_WRITEPORT2([NativeTypeName("HANDLE")] IntPtr param0, [In] byte* param1, [In] uint param2, [Out] uint* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_READPORT2([NativeTypeName("HANDLE")] IntPtr param0, [Out, Optional] byte* param1, [In] uint param2, [Out] uint* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ENDDOCPORT2([NativeTypeName("HANDLE")] IntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_CLOSEPORT2([NativeTypeName("HANDLE")] IntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ADDPORT2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [NativeTypeName("HWND"), In] IntPtr param2, [NativeTypeName("LPWSTR"), In] ushort* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_ADDPORTEX2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [In] uint param2, [In] byte* param3, [NativeTypeName("LPWSTR"), In] ushort* param4);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_CONFIGUREPORT2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [NativeTypeName("HWND"), In] IntPtr param2, [NativeTypeName("LPWSTR"), In] ushort* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_DELETEPORT2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPWSTR"), In] ushort* param1, [NativeTypeName("HWND"), In] IntPtr param2, [NativeTypeName("LPWSTR"), In] ushort* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_GETPRINTERDATAFROMPORT2([NativeTypeName("HANDLE")] IntPtr param0, [In] uint param1, [NativeTypeName("LPWSTR"), In] ushort* param2, [NativeTypeName("LPWSTR"), In] ushort* param3, [In] uint param4, [NativeTypeName("LPWSTR"), Out, Optional] ushort* param5, [In] uint param6, [Out] uint* param7);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_SETPORTTIMEOUTS2([NativeTypeName("HANDLE")] IntPtr param0, [In] COMMTIMEOUTS* param1, [In, Reserved] uint param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_XCVOPENPORT2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPCWSTR"), Const, In] ushort* param1, [In] uint param2, [NativeTypeName("PHANDLE"), Out] HANDLE* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint PFN_PRINTING_XCVDATAPORT2([NativeTypeName("HANDLE")] IntPtr param0, [NativeTypeName("LPCWSTR"), Const, In] ushort* param1, [In] byte* param2, [In] uint param3, [Out, Optional] byte* param4, [In] uint param5, [Out] uint* param6);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_PRINTING_XCVCLOSEPORT2([NativeTypeName("HANDLE")] IntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("void")]
    public unsafe delegate void PFN_PRINTING_SHUTDOWN2([NativeTypeName("HANDLE")] IntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint PFN_PRINTING_SENDRECVBIDIDATAFROMPORT2([NativeTypeName("HANDLE")] IntPtr param0, [In] uint param1, [NativeTypeName("LPCWSTR"), Const, In] ushort* param2, [In] BIDI_REQUEST_CONTAINER* param3, [Out] BIDI_RESPONSE_CONTAINER** param4);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint PFN_PRINTING_NOTIFYUSEDPORTS2([NativeTypeName("HANDLE")] IntPtr param0, [In] uint param1, [NativeTypeName("PCWSTR"), Const, In] ushort* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint PFN_PRINTING_NOTIFYUNUSEDPORTS2([NativeTypeName("HANDLE")] IntPtr param0, [In] uint param1, [NativeTypeName("PCWSTR"), Const, In] ushort* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint PFN_PRINTING_POWEREVENT2([NativeTypeName("HANDLE")] IntPtr param0, [In] uint param1, [In, Optional] POWERBROADCAST_SETTING* param2);
}