using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Sdk.Win32Metadata.Interop;

namespace Foobar
{
    public unsafe partial struct EXCEPTION_REGISTRATION_RECORD
    {
        [NativeTypeName("struct _EXCEPTION_REGISTRATION_RECORD *")]
        public EXCEPTION_REGISTRATION_RECORD* Next;

        [NativeTypeName("PEXCEPTION_ROUTINE")]
        public IntPtr* Handler;
    }

    public unsafe partial struct NT_TIB
    {
        [NativeTypeName("struct _EXCEPTION_REGISTRATION_RECORD *")]
        public EXCEPTION_REGISTRATION_RECORD* ExceptionList;

        [NativeTypeName("PVOID")]
        public void* StackBase;

        [NativeTypeName("PVOID")]
        public void* StackLimit;

        [NativeTypeName("PVOID")]
        public void* SubSystemTib;

        [NativeTypeName("_NT_TIB::(anonymous union at D:/repos/win32metadata/artifacts/InstalledPackages/Microsoft.Windows.SDK.CPP.10.0.19041.5/c/Include/10.0.19041.0/um/winnt.h:11490:5)")]
        public _Anonymous_e__Union Anonymous;

        [NativeTypeName("PVOID")]
        public void* ArbitraryUserPointer;

        [NativeTypeName("struct _NT_TIB *")]
        public NT_TIB* Self;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("PVOID")]
            public void* FiberData;

            [FieldOffset(0)]
            [NativeTypeName("DWORD")]
            public uint Version;
        }
    }

    public partial struct D3D11_BLEND_DESC
    {
        [NativeTypeName("BOOL")]
        [NativeTypeInfo(UnmanagedType.Bool)]
        public int AlphaToCoverageEnable;

        [NativeTypeName("BOOL")]
        [NativeTypeInfo(UnmanagedType.Bool)]
        public int IndependentBlendEnable;

        [NativeTypeName("D3D11_RENDER_TARGET_BLEND_DESC [8]")]
        public _RenderTarget_e__FixedBuffer RenderTarget;

        public partial struct D3D11_RENDER_TARGET_BLEND_DESC
        {
            [NativeTypeName("BOOL")]
            [NativeTypeInfo(UnmanagedType.Bool)]
            public int BlendEnable;

            [NativeTypeName("UINT8")]
            public byte RenderTargetWriteMask;
        }

        public partial struct _RenderTarget_e__FixedBuffer
        {
            public D3D11_RENDER_TARGET_BLEND_DESC e0;
            public D3D11_RENDER_TARGET_BLEND_DESC e1;
            public D3D11_RENDER_TARGET_BLEND_DESC e2;
            public D3D11_RENDER_TARGET_BLEND_DESC e3;
            public D3D11_RENDER_TARGET_BLEND_DESC e4;
            public D3D11_RENDER_TARGET_BLEND_DESC e5;
            public D3D11_RENDER_TARGET_BLEND_DESC e6;
            public D3D11_RENDER_TARGET_BLEND_DESC e7;

        }
    }

    public enum Enum1
    {
        A,
        B,
        C
    }

    public struct S2
    {
        int x;
        Sub sub;

        public struct Sub
        {
            int z;
        }
    }

    public struct S1
    {
        S2 s2;
    }

/*
    [Guid("000E0000-0000-0000-C000-000000000046")]
    [NativeTypeName("struct AsyncIUnknown : IUnknown")]
    [NativeInheritance("IUnknown")]
    public unsafe partial struct AsyncIUnknown
    {
        public void** lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(AsyncIUnknown* pThis, [NativeTypeName("const IID &")][Const] Guid* riid, [NativeTypeName("void **")][ComOutPtr] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(AsyncIUnknown* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(AsyncIUnknown* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Begin_QueryInterface(AsyncIUnknown* pThis, [NativeTypeName("const IID &")][Const] Guid* riid);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Finish_QueryInterface(AsyncIUnknown* pThis, [NativeTypeName("void **")][Out] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Begin_AddRef(AsyncIUnknown* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Finish_AddRef(AsyncIUnknown* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Begin_Release(AsyncIUnknown* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Finish_Release(AsyncIUnknown* pThis);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")][Const] Guid* riid, [NativeTypeName("void **")][ComOutPtr] void** ppvObject)
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[0]))(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>((IntPtr)(lpVtbl[1]))(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>((IntPtr)(lpVtbl[2]))(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Begin_QueryInterface([NativeTypeName("const IID &")][Const] Guid* riid)
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Begin_QueryInterface>((IntPtr)(lpVtbl[3]))(pThis, riid);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Finish_QueryInterface([NativeTypeName("void **")][Out] void** ppvObject)
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Finish_QueryInterface>((IntPtr)(lpVtbl[4]))(pThis, ppvObject);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Begin_AddRef()
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Begin_AddRef>((IntPtr)(lpVtbl[5]))(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Finish_AddRef()
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Finish_AddRef>((IntPtr)(lpVtbl[6]))(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Begin_Release()
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Begin_Release>((IntPtr)(lpVtbl[7]))(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Finish_Release()
        {
            fixed (AsyncIUnknown* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Finish_Release>((IntPtr)(lpVtbl[8]))(pThis);
            }
        }
    }

    public static unsafe partial class Apis
    {
        [DllImport("KERNEL32", ExactSpelling = true)]
        [return: NativeTypeName("WORD")]
        [return: NativeTypeInfo(UnmanagedType.Bool)]
        public static extern ushort RtlCaptureStackBackTrace([NativeTypeName("DWORD")][In] uint FramesToSkip, [NativeTypeName("DWORD")][In] uint FramesToCapture, [NativeTypeName("PVOID *")][NativeTypeInfo(UnmanagedType.LPArray, SizeParamIndex = 1)][Out] void** BackTrace, [NativeTypeName("PDWORD")][Out][Optional] uint* BackTraceHash);
    }

    [Guid("00000000-0000-0000-C000-000000000046")]
    public unsafe partial struct TOKEN_BNO_ISOLATION_INFORMATION
    {
        [NativeTypeName("PWSTR")]
        [NativeTypeInfo(UnmanagedType.LPWStr, IsNullTerminated = true)]
        public ushort* IsolationPrefix;

        [NativeTypeName("BOOLEAN")]
        public byte IsolationEnabled;
    }

    public enum MuhEnum
    {
        A = 100,
        B = A + 200,
        C = A + B * 3
    }

    public enum FirstEnum
    {
        Val0,
        Val1,
        Val2 = Val1
    }

    public enum ACCESS_MODE
    {
        NOT_USED_ACCESS = 0,
        GRANT_ACCESS,
        SET_ACCESS,
        DENY_ACCESS,
        REVOKE_ACCESS,
        SET_AUDIT_SUCCESS,
        SET_AUDIT_FAILURE,
    }

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    [return: NativeTypeName("BOOL")]
    public delegate void FooProc([In] IntPtr param0, [In] int param1);

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    [return: NativeTypeName("BOOL")]
    [return: NativeTypeInfo(UnmanagedType.Bool)]
    public delegate int ABORTPROC([NativeTypeName("HDC")][In] IntPtr param0, [In][NativeTypeInfo(UnmanagedType.Bool)] int param1);

    [StructLayout(LayoutKind.Explicit)]
    public partial struct LARGE_INTEGER
    {
        [FieldOffset(0)]
        [NativeTypeName("_LARGE_INTEGER::(anonymous struct at D:/repos/win32metadata/artifacts/InstalledPackages/Microsoft.Windows.SDK.CPP.10.0.19041.5/c/Include/10.0.19041.0/um/winnt.h:851:5)")]
        public _Anonymous_e__Struct Anonymous;

        [FieldOffset(0)]
        [NativeTypeName("struct (anonymous struct at D:/repos/win32metadata/artifacts/InstalledPackages/Microsoft.Windows.SDK.CPP.10.0.19041.5/c/Include/10.0.19041.0/um/winnt.h:855:5)")]
        public _u_e__Struct u;

        [FieldOffset(0)]
        [NativeTypeName("LONGLONG")]
        public long QuadPart;

        public partial struct _Anonymous_e__Struct
        {
            [NativeTypeName("DWORD")]
            public uint LowPart;

            [NativeTypeName("LONG")]
            public int HighPart;
        }

        public partial struct _u_e__Struct
        {
            [NativeTypeName("DWORD")]
            public uint LowPart;

            [NativeTypeName("LONG")]
            public int HighPart;
        }
    }

    [StructLayout(LayoutKind.Sequential, Pack = 2)]
    public unsafe partial struct IMAGE_DOS_HEADER
    {
        [NativeTypeName("WORD")]
        public ushort e_magic;

        [NativeTypeName("WORD")]
        public ushort e_cblp;

        [NativeTypeName("WORD")]
        public ushort e_cp;

        [NativeTypeName("WORD")]
        public ushort e_crlc;

        [NativeTypeName("WORD")]
        public ushort e_cparhdr;

        [NativeTypeName("WORD")]
        public ushort e_minalloc;

        [NativeTypeName("WORD")]
        public ushort e_maxalloc;

        [NativeTypeName("WORD")]
        public ushort e_ss;

        [NativeTypeName("WORD")]
        public ushort e_sp;

        [NativeTypeName("WORD")]
        public ushort e_csum;

        [NativeTypeName("WORD")]
        public ushort e_ip;

        [NativeTypeName("WORD")]
        public ushort e_cs;

        [NativeTypeName("WORD")]
        public ushort e_lfarlc;

        [NativeTypeName("WORD")]
        public ushort e_ovno;

        [NativeTypeName("WORD [4]")]
        public fixed ushort e_res[4];

        [NativeTypeName("WORD")]
        public ushort e_oemid;

        [NativeTypeName("WORD")]
        public ushort e_oeminfo;

        [NativeTypeName("WORD [10]")]
        public fixed ushort e_res2[10];

        [NativeTypeName("LONG")]
        public int e_lfanew;
    }

    public struct M1
    {
        public int M_1;
        public Guid M_G1;

        public struct Nested1
        {
            public int N1_1;

            public struct Nested1Sub
            {
                public int N1S_1;
            }
        }

        public Nested1 M_N1_2;

        public struct Nested2
        {
            public int N2_1;
        }

        public Nested2 M_N2_3;
    }

    public partial struct SCOPE_TABLE_AMD64
    {
        [NativeTypeName("DWORD")]
        public uint Count;

        [NativeTypeName("struct (anonymous struct at D:/repos/win32metadata/artifacts/InstalledPackages/Microsoft.Windows.SDK.CPP.10.0.19041.5/c/Include/10.0.19041.0/um/winnt.h:2678:5) [1]")]
        public _ScopeRecord_e__FixedBuffer ScopeRecord;

        public partial struct _Anonymous_e__Struct
        {
            [NativeTypeName("DWORD")]
            public uint BeginAddress;

            [NativeTypeName("DWORD")]
            public uint EndAddress;

            [NativeTypeName("DWORD")]
            public uint HandlerAddress;

            [NativeTypeName("DWORD")]
            public uint JumpTarget;
        }

        public partial struct _ScopeRecord_e__FixedBuffer
        {
            public _Anonymous_e__Struct e0;

            public unsafe ref _Anonymous_e__Struct this[int index]
            {
                get
                {
                    fixed (_Anonymous_e__Struct* pThis = &e0)
                    {
                        return ref pThis[index];
                    }
                }
            }
        }
    }

    public partial struct SCOPE_TABLE_ARM
    {
        [NativeTypeName("DWORD")]
        public uint Count;

        [NativeTypeName("struct (anonymous struct at D:/repos/win32metadata/artifacts/InstalledPackages/Microsoft.Windows.SDK.CPP.10.0.19041.5/c/Include/10.0.19041.0/um/winnt.h:4189:5) [1]")]
        public _ScopeRecord_e__FixedBuffer ScopeRecord;

        public partial struct _Anonymous_e__Struct
        {
            [NativeTypeName("DWORD")]
            public uint BeginAddress;

            [NativeTypeName("DWORD")]
            public uint EndAddress;

            [NativeTypeName("DWORD")]
            public uint HandlerAddress;

            [NativeTypeName("DWORD")]
            public uint JumpTarget;
        }

        public partial struct _ScopeRecord_e__FixedBuffer
        {
            public _Anonymous_e__Struct e0;

            public unsafe ref _Anonymous_e__Struct this[int index]
            {
                get
                {
                    fixed (_Anonymous_e__Struct* pThis = &e0)
                    {
                        return ref pThis[index];
                    }
                }
            }
        }
    }
*/
}

