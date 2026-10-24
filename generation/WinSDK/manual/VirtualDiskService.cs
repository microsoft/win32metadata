using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.Storage.VirtualDiskService
{
    [Guid("11F3CD41-B7E8-48FF-9472-9DFF018AA292")]
    [NativeTypeName("struct IVdsProviderPrivate : IUnknown")]
    [NativeInheritance("IUnknown")]
    [SupportedOSPlatform("windows6.0.6000")]
    public unsafe partial struct IVdsProviderPrivate
    {
        public void** lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IVdsProviderPrivate* pThis, [NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IVdsProviderPrivate* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IVdsProviderPrivate* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        [SupportedOSPlatform("windows5.0")]
        public delegate int _GetObject(IVdsProviderPrivate* pThis, [NativeTypeName("VDS_OBJECT_ID")] Guid ObjectId, VDS_OBJECT_TYPE type, [CppAttributeList("Name=SAL_name; p1=\"__RPC__deref_out_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__deref_out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_end^Name=SAL_end")] IUnknown** ppObjectUnk);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _OnLoad(IVdsProviderPrivate* pThis, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszMachineName, [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Maybenull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__maybe^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end")] IUnknown* pCallbackObject);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _OnUnload(IVdsProviderPrivate* pThis, [NativeTypeName("BOOL")] int bForceUnload);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject)
        {
            fixed (IVdsProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[0]))(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IVdsProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>((IntPtr)(lpVtbl[1]))(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IVdsProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>((IntPtr)(lpVtbl[2]))(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        [SupportedOSPlatform("windows5.0")]
        public int GetObject([NativeTypeName("VDS_OBJECT_ID")] Guid ObjectId, VDS_OBJECT_TYPE type, [CppAttributeList("Name=SAL_name; p1=\"__RPC__deref_out_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__deref_out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_end^Name=SAL_end")] IUnknown** ppObjectUnk)
        {
            fixed (IVdsProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetObject>((IntPtr)(lpVtbl[3]))(pThis, ObjectId, type, ppObjectUnk);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int OnLoad([NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszMachineName, [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Maybenull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__maybe^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end")] IUnknown* pCallbackObject)
        {
            fixed (IVdsProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_OnLoad>((IntPtr)(lpVtbl[4]))(pThis, pwszMachineName, pCallbackObject);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int OnUnload([NativeTypeName("BOOL")] int bForceUnload)
        {
            fixed (IVdsProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_OnUnload>((IntPtr)(lpVtbl[5]))(pThis, bForceUnload);
            }
        }
    }

    [Guid("98F17BF3-9F33-4F12-8714-8B4075092C2E")]
    [NativeTypeName("struct IVdsHwProviderPrivate : IUnknown")]
    [NativeInheritance("IUnknown")]
    [SupportedOSPlatform("windows6.0.6000")]
    public unsafe partial struct IVdsHwProviderPrivate
    {
        public void** lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IVdsHwProviderPrivate* pThis, [NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IVdsHwProviderPrivate* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IVdsHwProviderPrivate* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryIfCreatedLun(IVdsHwProviderPrivate* pThis, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszDevicePath, [CppAttributeList("Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end")] VDS_LUN_INFORMATION* pVdsLunInformation, [NativeTypeName("VDS_OBJECT_ID *")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end^Name=SAL_end")] Guid* pLunId);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject)
        {
            fixed (IVdsHwProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[0]))(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IVdsHwProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>((IntPtr)(lpVtbl[1]))(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IVdsHwProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>((IntPtr)(lpVtbl[2]))(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int QueryIfCreatedLun([NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszDevicePath, [CppAttributeList("Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end")] VDS_LUN_INFORMATION* pVdsLunInformation, [NativeTypeName("VDS_OBJECT_ID *")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end^Name=SAL_end")] Guid* pLunId)
        {
            fixed (IVdsHwProviderPrivate* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryIfCreatedLun>((IntPtr)(lpVtbl[3]))(pThis, pwszDevicePath, pVdsLunInformation, pLunId);
            }
        }
    }

    [Guid("310A7715-AC2B-4C6F-9827-3D742F351676")]
    [NativeTypeName("struct IVdsHwProviderPrivateMpio : IUnknown")]
    [NativeInheritance("IUnknown")]
    [SupportedOSPlatform("windows6.0.6000")]
    public unsafe partial struct IVdsHwProviderPrivateMpio
    {
        public void** lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IVdsHwProviderPrivateMpio* pThis, [NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IVdsHwProviderPrivateMpio* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IVdsHwProviderPrivateMpio* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SetAllPathStatusesFromHbaPort(IVdsHwProviderPrivateMpio* pThis, VDS_HBAPORT_PROP hbaPortProp, VDS_PATH_STATUS status);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject)
        {
            fixed (IVdsHwProviderPrivateMpio* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[0]))(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IVdsHwProviderPrivateMpio* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>((IntPtr)(lpVtbl[1]))(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IVdsHwProviderPrivateMpio* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>((IntPtr)(lpVtbl[2]))(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SetAllPathStatusesFromHbaPort(VDS_HBAPORT_PROP hbaPortProp, VDS_PATH_STATUS status)
        {
            fixed (IVdsHwProviderPrivateMpio* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SetAllPathStatusesFromHbaPort>((IntPtr)(lpVtbl[3]))(pThis, hbaPortProp, status);
            }
        }
    }

    [Guid("D188E97D-85AA-4D33-ABC6-26299A10FFC1")]
    [NativeTypeName("struct IVdsAdmin : IUnknown")]
    [NativeInheritance("IUnknown")]
    [SupportedOSPlatform("windows6.0.6000")]
    public unsafe partial struct IVdsAdmin
    {
        public void** lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IVdsAdmin* pThis, [NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IVdsAdmin* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IVdsAdmin* pThis);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _RegisterProvider(IVdsAdmin* pThis, [NativeTypeName("VDS_OBJECT_ID")] Guid providerId, [NativeTypeName("CLSID")] Guid providerClsid, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_ecount_full_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_full\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_name; p1=\"_Pre_readable_size_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_readableTo; p1=elementCount(( 200 + 1 ))^Name=SAL_pre^Name=SAL_valid^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszName, VDS_PROVIDER_TYPE type, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_ecount_full_opt_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_full_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Maybenull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__maybe^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_name; p1=\"_Pre_readable_size_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_readableTo; p1=elementCount(( ( 15 - 1 ) + 1 ))^Name=SAL_pre^Name=SAL_valid^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszMachineName, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_ecount_full_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_full\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_name; p1=\"_Pre_readable_size_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_readableTo; p1=elementCount(( 16 + 1 ))^Name=SAL_pre^Name=SAL_valid^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszVersion, Guid guidVersionId);

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _UnregisterProvider(IVdsAdmin* pThis, [NativeTypeName("VDS_OBJECT_ID")] Guid providerId);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [CppAttributeList("Name=SAL_name; p1=\"_COM_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_notref^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end^Name=SAL_context; p1=SAL_failed^Name=SAL_begin^Name=SAL_post^Name=SAL_begin^Name=SAL_name; p1=\"_Deref_post_null_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_post^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_null; p1=__yes^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_end")] void** ppvObject)
        {
            fixed (IVdsAdmin* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>((IntPtr)(lpVtbl[0]))(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IVdsAdmin* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>((IntPtr)(lpVtbl[1]))(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IVdsAdmin* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>((IntPtr)(lpVtbl[2]))(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int RegisterProvider([NativeTypeName("VDS_OBJECT_ID")] Guid providerId, [NativeTypeName("CLSID")] Guid providerClsid, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_ecount_full_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_full\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_name; p1=\"_Pre_readable_size_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_readableTo; p1=elementCount(( 200 + 1 ))^Name=SAL_pre^Name=SAL_valid^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszName, VDS_PROVIDER_TYPE type, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_ecount_full_opt_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_full_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Maybenull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__maybe^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_name; p1=\"_Pre_readable_size_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_readableTo; p1=elementCount(( ( 15 - 1 ) + 1 ))^Name=SAL_pre^Name=SAL_valid^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszMachineName, [NativeTypeName("LPWSTR")] [CppAttributeList("Name=SAL_name; p1=\"__RPC__in_ecount_full_string\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount_full\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in_ecount\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__in\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_name; p1=\"_Notnull_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_null; p1=__no^Name=SAL_end^Name=SAL_pre^Name=SAL_valid; p1=__yes^Name=SAL_end^Name=SAL_name; p1=\"_Pre_readable_size_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_readableTo; p1=elementCount(( 16 + 1 ))^Name=SAL_pre^Name=SAL_valid^Name=SAL_end^Name=SAL_end^Name=SAL_end^Name=SAL_pre^Name=SAL_name; p1=\"_Null_terminated_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_nullTerminated; p1=__yes^Name=SAL_end^Name=SAL_end")] ushort* pwszVersion, Guid guidVersionId)
        {
            fixed (IVdsAdmin* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_RegisterProvider>((IntPtr)(lpVtbl[3]))(pThis, providerId, providerClsid, pwszName, type, pwszMachineName, pwszVersion, guidVersionId);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int UnregisterProvider([NativeTypeName("VDS_OBJECT_ID")] Guid providerId)
        {
            fixed (IVdsAdmin* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_UnregisterProvider>((IntPtr)(lpVtbl[4]))(pThis, providerId);
            }
        }
    }
}
