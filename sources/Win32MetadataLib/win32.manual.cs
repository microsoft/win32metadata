using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Microsoft.Windows.Sdk
{
    public partial struct WSAPOLLDATA
    {
        public int result;

        [NativeTypeName("ULONG")]
        public uint fds;

        [NativeTypeName("INT")]
        public int timeout;

        //[NativeTypeName("WSAPOLLFD [0]")]
        //public WSAPOLLFD* fdArray;

        //public partial struct _fdArray_e__FixedBuffer
        //{

        //    public unsafe ref pollfd this[int index]
        //    {
        //        get
        //        {
        //            fixed (pollfd* pThis = &fdArray)
        //            {
        //                return ref pThis[index];
        //            }
        //        }
        //    }
        //}
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public partial struct CABINETSTATE
    {
        [NativeTypeName("WORD")]
        public ushort cLength;

        [NativeTypeName("WORD")]
        public ushort nVersion;

        internal int _bitfield;

        [NativeTypeName("BOOL : 1")]
        public int fFullPathTitle
        {
            get
            {
                return _bitfield & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~0x1) | (value & 0x1);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fSaveLocalView
        {
            get
            {
                return (_bitfield >> 1) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 1)) | ((value & 0x1) << 1);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fNotShell
        {
            get
            {
                return (_bitfield >> 2) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 2)) | ((value & 0x1) << 2);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fSimpleDefault
        {
            get
            {
                return (_bitfield >> 3) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 3)) | ((value & 0x1) << 3);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fDontShowDescBar
        {
            get
            {
                return (_bitfield >> 4) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 4)) | ((value & 0x1) << 4);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fNewWindowMode
        {
            get
            {
                return (_bitfield >> 5) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 5)) | ((value & 0x1) << 5);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fShowCompColor
        {
            get
            {
                return (_bitfield >> 6) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 6)) | ((value & 0x1) << 6);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fDontPrettyNames
        {
            get
            {
                return (_bitfield >> 7) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 7)) | ((value & 0x1) << 7);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fAdminsCreateCommonGroups
        {
            get
            {
                return (_bitfield >> 8) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 8)) | ((value & 0x1) << 8);
            }
        }

        [NativeTypeName("UINT : 7")]
        public uint fUnusedFlags
        {
            get
            {
                return (uint)(_bitfield >> 9) & 0x7Fu;
            }

            set
            {
                uint val = ((uint)_bitfield & ~(0x7Fu << 9)) | ((value & 0x7Fu) << 9);
                _bitfield = (int)val;
            }
        }

        [NativeTypeName("UINT")]
        public uint fMenuEnumFilter;
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public partial struct SHELLFLAGSTATE
    {
        internal int _bitfield;

        [NativeTypeName("BOOL : 1")]
        public int fShowAllObjects
        {
            get
            {
                return _bitfield & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~0x1) | (value & 0x1);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fShowExtensions
        {
            get
            {
                return (_bitfield >> 1) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 1)) | ((value & 0x1) << 1);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fNoConfirmRecycle
        {
            get
            {
                return (_bitfield >> 2) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 2)) | ((value & 0x1) << 2);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fShowSysFiles
        {
            get
            {
                return (_bitfield >> 3) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 3)) | ((value & 0x1) << 3);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fShowCompColor
        {
            get
            {
                return (_bitfield >> 4) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 4)) | ((value & 0x1) << 4);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fDoubleClickInWebView
        {
            get
            {
                return (_bitfield >> 5) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 5)) | ((value & 0x1) << 5);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fDesktopHTML
        {
            get
            {
                return (_bitfield >> 6) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 6)) | ((value & 0x1) << 6);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fWin95Classic
        {
            get
            {
                return (_bitfield >> 7) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 7)) | ((value & 0x1) << 7);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fDontPrettyPath
        {
            get
            {
                return (_bitfield >> 8) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 8)) | ((value & 0x1) << 8);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fShowAttribCol
        {
            get
            {
                return (_bitfield >> 9) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 9)) | ((value & 0x1) << 9);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fMapNetDrvBtn
        {
            get
            {
                return (_bitfield >> 10) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 10)) | ((value & 0x1) << 10);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fShowInfoTip
        {
            get
            {
                return (_bitfield >> 11) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 11)) | ((value & 0x1) << 11);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fHideIcons
        {
            get
            {
                return (_bitfield >> 12) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 12)) | ((value & 0x1) << 12);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fAutoCheckSelect
        {
            get
            {
                return (_bitfield >> 13) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 13)) | ((value & 0x1) << 13);
            }
        }

        [NativeTypeName("BOOL : 1")]
        public int fIconsOnly
        {
            get
            {
                return (_bitfield >> 14) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 14)) | ((value & 0x1) << 14);
            }
        }

        [NativeTypeName("UINT : 1")]
        public uint fRestFlags
        {
            get
            {
                return (uint)(_bitfield >> 15) & 0x1u;
            }

            set
            {
                uint val = ((uint)_bitfield & ~(0x1u << 15)) | ((value & 0x1u) << 15);
                _bitfield = (int)val;
            }
        }
    }

    public partial struct _DEV_QUERY_RESULT_ACTION_DATA
    {
        [NativeTypeName("DEV_QUERY_RESULT_ACTION")]
        public _DEV_QUERY_RESULT_ACTION Action;

        [NativeTypeName("union _DEV_QUERY_RESULT_UPDATE_PAYLOAD")]
        public _DEV_QUERY_RESULT_UPDATE_PAYLOAD Data;

        [StructLayout(LayoutKind.Explicit)]
        public partial struct _DEV_QUERY_RESULT_UPDATE_PAYLOAD
        {
            [FieldOffset(0)]
            [NativeTypeName("DEV_QUERY_STATE")]
            public _DEV_QUERY_STATE State;

            [FieldOffset(0)]
            [NativeTypeName("DEV_OBJECT")]
            public _DEV_OBJECT DeviceObject;
        }
    }

    public unsafe partial struct _DNS_CONNECTION_PROXY_INFO
    {
        [NativeTypeName("DWORD")]
        public uint Version;

        [NativeTypeName("WCHAR *")]
        public ushort* pwszFriendlyName;

        [NativeTypeName("DWORD")]
        public uint Flags;

        [NativeTypeName("DNS_CONNECTION_PROXY_INFO_SWITCH")]
        public _DNS_CONNECTION_PROXY_INFO_SWITCH Switch;

        [NativeTypeName("_DNS_CONNECTION_PROXY_INFO::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/windns.h:2556:5)")]
        public _Anonymous_e__Union Anonymous;

        [StructLayout(LayoutKind.Explicit)]
        public partial struct _Anonymous_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("struct _DNS_CONNECTION_PROXY_INFO_CONFIG")]
            public _DNS_CONNECTION_PROXY_INFO_CONFIG Config;

            [FieldOffset(0)]
            [NativeTypeName("struct _DNS_CONNECTION_PROXY_INFO_SCRIPT")]
            public _DNS_CONNECTION_PROXY_INFO_SCRIPT Script;

            public unsafe partial struct _DNS_CONNECTION_PROXY_INFO_CONFIG
            {
                [NativeTypeName("WCHAR *")]
                public ushort* pwszServer;

                [NativeTypeName("WCHAR *")]
                public ushort* pwszUsername;

                [NativeTypeName("WCHAR *")]
                public ushort* pwszPassword;

                [NativeTypeName("WCHAR *")]
                public ushort* pwszException;

                [NativeTypeName("WCHAR *")]
                public ushort* pwszExtraInfo;

                [NativeTypeName("WORD")]
                public ushort Port;
            }

            public unsafe partial struct _DNS_CONNECTION_PROXY_INFO_SCRIPT
            {
                [NativeTypeName("WCHAR *")]
                public ushort* pwszScript;

                [NativeTypeName("WCHAR *")]
                public ushort* pwszUsername;

                [NativeTypeName("WCHAR *")]
                public ushort* pwszPassword;
            }
        }
    }

    public partial struct EVENT_PROPERTY_INFO
    {
        [NativeTypeName("PROPERTY_FLAGS")]
        public _PROPERTY_FLAGS Flags;

        [NativeTypeName("ULONG")]
        public uint NameOffset;

        [NativeTypeName("_EVENT_PROPERTY_INFO::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/tdh.h:469:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_EVENT_PROPERTY_INFO::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/tdh.h:496:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("_EVENT_PROPERTY_INFO::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/tdh.h:500:5)")]
        public _Anonymous3_e__Union Anonymous3;

        [NativeTypeName("_EVENT_PROPERTY_INFO::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/tdh.h:504:5)")]
        public _Anonymous4_e__Union Anonymous4;

        [StructLayout(LayoutKind.Explicit)]
        public partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("struct _nonStructType")]
            public _nonStructType nonStructType;

            [FieldOffset(0)]
            [NativeTypeName("struct _structType")]
            public _structType structType;

            [FieldOffset(0)]
            [NativeTypeName("struct _customSchemaType")]
            public _customSchemaType customSchemaType;

            public partial struct _nonStructType
            {
                [NativeTypeName("USHORT")]
                public ushort InType;

                [NativeTypeName("USHORT")]
                public ushort OutType;

                [NativeTypeName("ULONG")]
                public uint MapNameOffset;
            }

            public partial struct _structType
            {
                [NativeTypeName("USHORT")]
                public ushort StructStartIndex;

                [NativeTypeName("USHORT")]
                public ushort NumOfStructMembers;

                [NativeTypeName("ULONG")]
                public uint padding;
            }

            public partial struct _customSchemaType
            {
                [NativeTypeName("USHORT")]
                public ushort InType;

                [NativeTypeName("USHORT")]
                public ushort OutType;

                [NativeTypeName("ULONG")]
                public uint CustomSchemaOffset;
            }
        }

        [StructLayout(LayoutKind.Explicit)]
        public partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("USHORT")]
            public ushort count;

            [FieldOffset(0)]
            [NativeTypeName("USHORT")]
            public ushort countPropertyIndex;
        }

        [StructLayout(LayoutKind.Explicit)]
        public partial struct _Anonymous3_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("USHORT")]
            public ushort length;

            [FieldOffset(0)]
            [NativeTypeName("USHORT")]
            public ushort lengthPropertyIndex;
        }

        [StructLayout(LayoutKind.Explicit)]
        public partial struct _Anonymous4_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("ULONG")]
            public uint Reserved;

            [FieldOffset(0)]
            [NativeTypeName("_EVENT_PROPERTY_INFO::(anonymous struct at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/tdh.h:506:9)")]
            public _Anonymous_e__Struct Anonymous;

            public partial struct _Anonymous_e__Struct
            {
                internal uint _bitfield;

                [NativeTypeName("ULONG : 28")]
                public uint Tags
                {
                    get
                    {
                        return _bitfield & 0xFFFFFFFu;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~0xFFFFFFFu) | (value & 0xFFFFFFFu);
                    }
                }
            }
        }
    }

    public unsafe partial struct MIDL_STUB_MESSAGE
    {
        [NativeTypeName("PRPC_MESSAGE")]
        public _RPC_MESSAGE* RpcMsg;

        [NativeTypeName("unsigned char *")]
        public byte* Buffer;

        [NativeTypeName("unsigned char *")]
        public byte* BufferStart;

        [NativeTypeName("unsigned char *")]
        public byte* BufferEnd;

        [NativeTypeName("unsigned char *")]
        public byte* BufferMark;

        [NativeTypeName("unsigned long")]
        public uint BufferLength;

        [NativeTypeName("unsigned long")]
        public uint MemorySize;

        [NativeTypeName("unsigned char *")]
        public byte* Memory;

        [NativeTypeName("unsigned char")]
        public byte IsClient;

        [NativeTypeName("unsigned char")]
        public byte Pad;

        [NativeTypeName("unsigned short")]
        public ushort uFlags2;

        public int ReuseBuffer;

        [NativeTypeName("struct NDR_ALLOC_ALL_NODES_CONTEXT *")]
        public NDR_ALLOC_ALL_NODES_CONTEXT* pAllocAllNodesContext;

        [NativeTypeName("struct NDR_POINTER_QUEUE_STATE *")]
        public NDR_POINTER_QUEUE_STATE* pPointerQueueState;

        public int IgnoreEmbeddedPointers;

        [NativeTypeName("unsigned char *")]
        public byte* PointerBufferMark;

        [NativeTypeName("unsigned char")]
        public byte CorrDespIncrement;

        [NativeTypeName("unsigned char")]
        public byte uFlags;

        [NativeTypeName("unsigned short")]
        public ushort UniquePtrCount;

        [NativeTypeName("ULONG_PTR")]
        public UIntPtr MaxCount;

        [NativeTypeName("unsigned long")]
        public uint Offset;

        [NativeTypeName("unsigned long")]
        public uint ActualCount;

        [NativeTypeName("void *(*)(size_t) __attribute__((stdcall))")]
        public IntPtr pfnAllocate;

        [NativeTypeName("void (*)(void *) __attribute__((stdcall))")]
        public IntPtr pfnFree;

        [NativeTypeName("unsigned char *")]
        public byte* StackTop;

        [NativeTypeName("unsigned char *")]
        public byte* pPresentedType;

        [NativeTypeName("unsigned char *")]
        public byte* pTransmitType;

        [NativeTypeName("handle_t")]
        public void* SavedHandle;

        [NativeTypeName("const struct _MIDL_STUB_DESC *")]
        public _MIDL_STUB_DESC* StubDesc;

        [NativeTypeName("struct _FULL_PTR_XLAT_TABLES *")]
        public _FULL_PTR_XLAT_TABLES* FullPtrXlatTables;

        [NativeTypeName("unsigned long")]
        public uint FullPtrRefId;

        [NativeTypeName("unsigned long")]
        public uint PointerLength;

        internal int _bitfield;

        [NativeTypeName("int : 1")]
        public int fInDontFree
        {
            get
            {
                return _bitfield & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~0x1) | (value & 0x1);
            }
        }

        [NativeTypeName("int : 1")]
        public int fDontCallFreeInst
        {
            get
            {
                return (_bitfield >> 1) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 1)) | ((value & 0x1) << 1);
            }
        }

        [NativeTypeName("int : 1")]
        public int fUnused1
        {
            get
            {
                return (_bitfield >> 2) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 2)) | ((value & 0x1) << 2);
            }
        }

        [NativeTypeName("int : 1")]
        public int fHasReturn
        {
            get
            {
                return (_bitfield >> 3) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 3)) | ((value & 0x1) << 3);
            }
        }

        [NativeTypeName("int : 1")]
        public int fHasExtensions
        {
            get
            {
                return (_bitfield >> 4) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 4)) | ((value & 0x1) << 4);
            }
        }

        [NativeTypeName("int : 1")]
        public int fHasNewCorrDesc
        {
            get
            {
                return (_bitfield >> 5) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 5)) | ((value & 0x1) << 5);
            }
        }

        [NativeTypeName("int : 1")]
        public int fIsIn
        {
            get
            {
                return (_bitfield >> 6) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 6)) | ((value & 0x1) << 6);
            }
        }

        [NativeTypeName("int : 1")]
        public int fIsOut
        {
            get
            {
                return (_bitfield >> 7) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 7)) | ((value & 0x1) << 7);
            }
        }

        [NativeTypeName("int : 1")]
        public int fIsOicf
        {
            get
            {
                return (_bitfield >> 8) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 8)) | ((value & 0x1) << 8);
            }
        }

        [NativeTypeName("int : 1")]
        public int fBufferValid
        {
            get
            {
                return (_bitfield >> 9) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 9)) | ((value & 0x1) << 9);
            }
        }

        [NativeTypeName("int : 1")]
        public int fHasMemoryValidateCallback
        {
            get
            {
                return (_bitfield >> 10) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 10)) | ((value & 0x1) << 10);
            }
        }

        [NativeTypeName("int : 1")]
        public int fInFree
        {
            get
            {
                return (_bitfield >> 11) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 11)) | ((value & 0x1) << 11);
            }
        }

        [NativeTypeName("int : 1")]
        public int fNeedMCCP
        {
            get
            {
                return (_bitfield >> 12) & 0x1;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x1 << 12)) | ((value & 0x1) << 12);
            }
        }

        [NativeTypeName("int : 3")]
        public int fUnused2
        {
            get
            {
                return (_bitfield >> 13) & 0x7;
            }

            set
            {
                _bitfield = (_bitfield & ~(0x7 << 13)) | ((value & 0x7) << 13);
            }
        }

        [NativeTypeName("int : 16")]
        public int fUnused3
        {
            get
            {
                return (_bitfield >> 16) & 0xFFFF;
            }

            set
            {
                _bitfield = (_bitfield & ~(0xFFFF << 16)) | ((value & 0xFFFF) << 16);
            }
        }

        [NativeTypeName("unsigned long")]
        public uint dwDestContext;

        [NativeTypeName("void *")]
        public void* pvDestContext;

        [NativeTypeName("NDR_SCONTEXT *")]
        //public _SavedContextHandles_e__Struct SavedContextHandles;
        public IntPtr SavedContextHandles;

        [NativeTypeName("long")]
        public int ParamNumber;

        [NativeTypeName("struct IRpcChannelBuffer *")]
        public IRpcChannelBuffer* pRpcChannelBuffer;

        [NativeTypeName("PARRAY_INFO")]
        public ARRAY_INFO* pArrayInfo;

        [NativeTypeName("unsigned long *")]
        public uint* SizePtrCountArray;

        [NativeTypeName("unsigned long *")]
        public uint* SizePtrOffsetArray;

        [NativeTypeName("unsigned long *")]
        public uint* SizePtrLengthArray;

        [NativeTypeName("void *")]
        public void* pArgQueue;

        [NativeTypeName("unsigned long")]
        public uint dwStubPhase;

        [NativeTypeName("void *")]
        public void* LowStackMark;

        [NativeTypeName("PNDR_ASYNC_MESSAGE")]
        public _NDR_ASYNC_MESSAGE* pAsyncMsg;

        [NativeTypeName("PNDR_CORRELATION_INFO")]
        public _NDR_CORRELATION_INFO* pCorrInfo;

        [NativeTypeName("unsigned char *")]
        public byte* pCorrMemory;

        [NativeTypeName("void *")]
        public void* pMemoryList;

        [NativeTypeName("INT_PTR")]
        public IntPtr pCSInfo;

        [NativeTypeName("unsigned char *")]
        public byte* ConformanceMark;

        [NativeTypeName("unsigned char *")]
        public byte* VarianceMark;

        [NativeTypeName("INT_PTR")]
        public IntPtr Unused;

        [NativeTypeName("struct _NDR_PROC_CONTEXT *")]
        public _NDR_PROC_CONTEXT* pContext;

        [NativeTypeName("void *")]
        public void* ContextHandleHash;

        [NativeTypeName("void *")]
        public void* pUserMarshalList;

        [NativeTypeName("INT_PTR")]
        public IntPtr Reserved51_3;

        [NativeTypeName("INT_PTR")]
        public IntPtr Reserved51_4;

        [NativeTypeName("INT_PTR")]
        public IntPtr Reserved51_5;
    }

    public unsafe partial struct PROPSHEETPAGEA
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEA::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:225:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEA::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:225:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKA")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszHeaderTitle;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszHeaderSubTitle;

        [NativeTypeName("HANDLE")]
        public IntPtr hActCtx;

        [NativeTypeName("_PROPSHEETPAGEA::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:232:5)")]
        public _Anonymous3_e__Union Anonymous3;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszIcon;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous3_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HBITMAP")]
            public IntPtr hbmHeader;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszbmHeader;
        }
    }

    public unsafe partial struct PROPSHEETPAGEA_V1
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEA_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:198:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEA_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:198:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKA")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszIcon;
        }
    }

    public unsafe partial struct PROPSHEETPAGEA_V2
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEA_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:204:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEA_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:204:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKA")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszHeaderTitle;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszHeaderSubTitle;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszIcon;
        }
    }

    public unsafe partial struct PROPSHEETPAGEA_V3
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEA_V3::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:213:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEA_V3::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:213:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKA")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszHeaderTitle;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszHeaderSubTitle;

        [NativeTypeName("HANDLE")]
        public IntPtr hActCtx;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszIcon;
        }
    }

    public unsafe partial struct PROPSHEETPAGEW
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEW::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:271:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEW::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:271:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKW")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszHeaderTitle;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszHeaderSubTitle;

        [NativeTypeName("HANDLE")]
        public IntPtr hActCtx;

        [NativeTypeName("_PROPSHEETPAGEW::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:278:5)")]
        public _Anonymous3_e__Union Anonymous3;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszIcon;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous3_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HBITMAP")]
            public IntPtr hbmHeader;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszbmHeader;
        }
    }

    public unsafe partial struct PROPSHEETPAGEW_V1
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEW_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:244:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEW_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:244:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKW")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszIcon;
        }
    }

    public unsafe partial struct PROPSHEETPAGEW_V2
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEW_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:250:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEW_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:250:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKW")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszHeaderTitle;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszHeaderSubTitle;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszIcon;
        }
    }

    public unsafe partial struct PROPSHEETPAGEW_V3
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETPAGEW_V3::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:259:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("_PROPSHEETPAGEW_V3::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:259:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszTitle;

        [NativeTypeName("DLGPROC")]
        public IntPtr pfnDlgProc;

        [NativeTypeName("LPARAM")]
        public IntPtr lParam;

        [NativeTypeName("LPFNPSPCALLBACKW")]
        public IntPtr pfnCallback;

        [NativeTypeName("UINT *")]
        public uint* pcRefParent;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszHeaderTitle;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszHeaderSubTitle;

        [NativeTypeName("HANDLE")]
        public IntPtr hActCtx;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszTemplate;

            [FieldOffset(0)]
            [NativeTypeName("PROPSHEETPAGE_RESOURCE")]
            public DLGTEMPLATE* pResource;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszIcon;
        }
    }

    public unsafe partial struct PROPSHEETHEADERA_V1
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HWND")]
        public IntPtr hwndParent;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETHEADERA_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:473:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszCaption;

        [NativeTypeName("UINT")]
        public uint nPages;

        [NativeTypeName("_PROPSHEETHEADERA_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:473:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("_PROPSHEETHEADERA_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:473:5)")]
        public _Anonymous3_e__Union Anonymous3;

        [NativeTypeName("PFNPROPSHEETCALLBACK")]
        public IntPtr pfnCallback;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszIcon;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("UINT")]
            public uint nStartPage;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pStartPage;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous3_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCPROPSHEETPAGEA")]
            public PROPSHEETPAGEA* ppsp;

            [FieldOffset(0)]
            [NativeTypeName("HPROPSHEETPAGE *")]
            public IntPtr* phpage;
        }
    }

    public unsafe partial struct PROPSHEETHEADERA_V2
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HWND")]
        public IntPtr hwndParent;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETHEADERA_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:479:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("LPCSTR")]
        public sbyte* pszCaption;

        [NativeTypeName("UINT")]
        public uint nPages;

        [NativeTypeName("_PROPSHEETHEADERA_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:479:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("_PROPSHEETHEADERA_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:479:5)")]
        public _Anonymous3_e__Union Anonymous3;

        [NativeTypeName("PFNPROPSHEETCALLBACK")]
        public IntPtr pfnCallback;

        [NativeTypeName("_PROPSHEETHEADERA_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:480:5)")]
        public _Anonymous4_e__Union Anonymous4;

        [NativeTypeName("HPALETTE")]
        public IntPtr hplWatermark;

        [NativeTypeName("_PROPSHEETHEADERA_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:486:5)")]
        public _Anonymous5_e__Union Anonymous5;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszIcon;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("UINT")]
            public uint nStartPage;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pStartPage;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous3_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCPROPSHEETPAGEA")]
            public PROPSHEETPAGEA* ppsp;

            [FieldOffset(0)]
            [NativeTypeName("HPROPSHEETPAGE *")]
            public IntPtr* phpage;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous4_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HBITMAP")]
            public IntPtr hbmWatermark;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszbmWatermark;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous5_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HBITMAP")]
            public IntPtr hbmHeader;

            [FieldOffset(0)]
            [NativeTypeName("LPCSTR")]
            public sbyte* pszbmHeader;
        }
    }

    public unsafe partial struct PROPSHEETHEADERW_V1
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HWND")]
        public IntPtr hwndParent;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETHEADERW_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:520:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszCaption;

        [NativeTypeName("UINT")]
        public uint nPages;

        [NativeTypeName("_PROPSHEETHEADERW_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:520:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("_PROPSHEETHEADERW_V1::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:520:5)")]
        public _Anonymous3_e__Union Anonymous3;

        [NativeTypeName("PFNPROPSHEETCALLBACK")]
        public IntPtr pfnCallback;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszIcon;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("UINT")]
            public uint nStartPage;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pStartPage;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous3_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCPROPSHEETPAGEW")]
            public PROPSHEETPAGEW* ppsp;

            [FieldOffset(0)]
            [NativeTypeName("HPROPSHEETPAGE *")]
            public IntPtr* phpage;
        }
    }

    public unsafe partial struct PROPSHEETHEADERW_V2
    {
        [NativeTypeName("DWORD")]
        public uint dwSize;

        [NativeTypeName("DWORD")]
        public uint dwFlags;

        [NativeTypeName("HWND")]
        public IntPtr hwndParent;

        [NativeTypeName("HINSTANCE")]
        public IntPtr hInstance;

        [NativeTypeName("_PROPSHEETHEADERW_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:526:5)")]
        public _Anonymous1_e__Union Anonymous1;

        [NativeTypeName("LPCWSTR")]
        public ushort* pszCaption;

        [NativeTypeName("UINT")]
        public uint nPages;

        [NativeTypeName("_PROPSHEETHEADERW_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:526:5)")]
        public _Anonymous2_e__Union Anonymous2;

        [NativeTypeName("_PROPSHEETHEADERW_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:526:5)")]
        public _Anonymous3_e__Union Anonymous3;

        [NativeTypeName("PFNPROPSHEETCALLBACK")]
        public IntPtr pfnCallback;

        [NativeTypeName("_PROPSHEETHEADERW_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:527:5)")]
        public _Anonymous4_e__Union Anonymous4;

        [NativeTypeName("HPALETTE")]
        public IntPtr hplWatermark;

        [NativeTypeName("_PROPSHEETHEADERW_V2::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/prsht.h:533:5)")]
        public _Anonymous5_e__Union Anonymous5;

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous1_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HICON")]
            public IntPtr hIcon;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszIcon;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous2_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("UINT")]
            public uint nStartPage;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pStartPage;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous3_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("LPCPROPSHEETPAGEW")]
            public PROPSHEETPAGEW* ppsp;

            [FieldOffset(0)]
            [NativeTypeName("HPROPSHEETPAGE *")]
            public IntPtr* phpage;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous4_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HBITMAP")]
            public IntPtr hbmWatermark;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszbmWatermark;
        }

        [StructLayout(LayoutKind.Explicit)]
        public unsafe partial struct _Anonymous5_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("HBITMAP")]
            public IntPtr hbmHeader;

            [FieldOffset(0)]
            [NativeTypeName("LPCWSTR")]
            public ushort* pszbmHeader;
        }
    }

    public enum EXCEPTION_DISPOSITION
    {
        ExceptionContinueExecution,
        ExceptionContinueSearch,
        ExceptionNestedException,
        ExceptionCollidedUnwind
    }

    public enum SF_TYPE
    {
        SF_ERROR = VARENUM.VT_ERROR,
        SF_I1 = VARENUM.VT_I1,
        SF_I2 = VARENUM.VT_I2,
        SF_I4 = VARENUM.VT_I4,
        SF_I8 = VARENUM.VT_I8,
        SF_BSTR = VARENUM.VT_BSTR,
        SF_UNKNOWN = VARENUM.VT_UNKNOWN,
        SF_DISPATCH = VARENUM.VT_DISPATCH,
        SF_VARIANT = VARENUM.VT_VARIANT,
        SF_RECORD = VARENUM.VT_RECORD,
        SF_HAVEIID = (VARENUM.VT_UNKNOWN | VARENUM.VT_RESERVED),
    }

    public enum COINIT
    {
        COINIT_APARTMENTTHREADED = 0x2,
        COINIT_MULTITHREADED = COINITBASE.COINITBASE_MULTITHREADED,
        COINIT_DISABLE_OLE1DDE = 0x4,
        COINIT_SPEED_OVER_MEMORY = 0x8,
    }

    public unsafe partial struct IActiveDesktopP
    {
        public Vtbl* lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IActiveDesktopP* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IActiveDesktopP* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IActiveDesktopP* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface1(IActiveDesktopP* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppv);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef1(IActiveDesktopP* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release1(IActiveDesktopP* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SetSafeMode(IActiveDesktopP* pThis, [NativeTypeName("DWORD")] uint dwFlags);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _EnsureUpdateHTML(IActiveDesktopP* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SetScheme(IActiveDesktopP* pThis, [NativeTypeName("PCWSTR")] ushort* pwszSchemeName, [NativeTypeName("DWORD")] uint dwFlags);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetScheme(IActiveDesktopP* pThis, [NativeTypeName("PWSTR")] ushort* pwszSchemeName, [NativeTypeName("DWORD *")] uint* pdwcchBuffer, [NativeTypeName("DWORD")] uint dwFlags);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject)
        {
            fixed (IActiveDesktopP* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>(lpVtbl->QueryInterface)(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IActiveDesktopP* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>(lpVtbl->AddRef)(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IActiveDesktopP* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>(lpVtbl->Release)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SetSafeMode([NativeTypeName("DWORD")] uint dwFlags)
        {
            fixed (IActiveDesktopP* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SetSafeMode>(lpVtbl->SetSafeMode)(pThis, dwFlags);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int EnsureUpdateHTML()
        {
            fixed (IActiveDesktopP* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_EnsureUpdateHTML>(lpVtbl->EnsureUpdateHTML)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SetScheme([NativeTypeName("PCWSTR")] ushort* pwszSchemeName, [NativeTypeName("DWORD")] uint dwFlags)
        {
            fixed (IActiveDesktopP* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SetScheme>(lpVtbl->SetScheme)(pThis, pwszSchemeName, dwFlags);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetScheme([NativeTypeName("PWSTR")] ushort* pwszSchemeName, [NativeTypeName("DWORD *")] uint* pdwcchBuffer, [NativeTypeName("DWORD")] uint dwFlags)
        {
            fixed (IActiveDesktopP* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetScheme>(lpVtbl->GetScheme)(pThis, pwszSchemeName, pdwcchBuffer, dwFlags);
            }
        }

        public partial struct Vtbl
        {
            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((stdcall))")]
            public IntPtr QueryInterface;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr AddRef;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr Release;

            [NativeTypeName("HRESULT (DWORD) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr SetSafeMode;

            [NativeTypeName("HRESULT () __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr EnsureUpdateHTML;

            [NativeTypeName("HRESULT (PCWSTR, DWORD) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr SetScheme;

            [NativeTypeName("HRESULT (PWSTR, DWORD *, DWORD) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetScheme;
        }
    }

    public unsafe partial struct IADesktopP2
    {
        public Vtbl* lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IADesktopP2* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IADesktopP2* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IADesktopP2* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _ReReadWallpaper(IADesktopP2* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetADObjectFlags(IADesktopP2* pThis, [NativeTypeName("DWORD *")] uint* pdwFlags, [NativeTypeName("DWORD")] uint dwMask);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _UpdateAllDesktopSubscriptions(IADesktopP2* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _MakeDynamicChanges(IADesktopP2* pThis, [NativeTypeName("IOleObject *")] IOleObject* pOleObj);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject)
        {
            fixed (IADesktopP2* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>(lpVtbl->QueryInterface)(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IADesktopP2* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>(lpVtbl->AddRef)(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IADesktopP2* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>(lpVtbl->Release)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int ReReadWallpaper()
        {
            fixed (IADesktopP2* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_ReReadWallpaper>(lpVtbl->ReReadWallpaper)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetADObjectFlags([NativeTypeName("DWORD *")] uint* pdwFlags, [NativeTypeName("DWORD")] uint dwMask)
        {
            fixed (IADesktopP2* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetADObjectFlags>(lpVtbl->GetADObjectFlags)(pThis, pdwFlags, dwMask);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int UpdateAllDesktopSubscriptions()
        {
            fixed (IADesktopP2* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_UpdateAllDesktopSubscriptions>(lpVtbl->UpdateAllDesktopSubscriptions)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int MakeDynamicChanges([NativeTypeName("IOleObject *")] IOleObject* pOleObj)
        {
            fixed (IADesktopP2* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_MakeDynamicChanges>(lpVtbl->MakeDynamicChanges)(pThis, pOleObj);
            }
        }

        public partial struct Vtbl
        {
            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((stdcall))")]
            public IntPtr QueryInterface;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr AddRef;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr Release;

            [NativeTypeName("HRESULT () __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr ReReadWallpaper;

            [NativeTypeName("HRESULT (DWORD *, DWORD) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetADObjectFlags;

            [NativeTypeName("HRESULT () __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr UpdateAllDesktopSubscriptions;

            [NativeTypeName("HRESULT (IOleObject *) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr MakeDynamicChanges;
        }
    }

    public unsafe partial struct INewShortcutHookA
    {
        public Vtbl* lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(INewShortcutHookA* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(INewShortcutHookA* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(INewShortcutHookA* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface1(INewShortcutHookA* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppv);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef1(INewShortcutHookA* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release1(INewShortcutHookA* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SetReferent(INewShortcutHookA* pThis, [NativeTypeName("PCSTR")] sbyte* pcszReferent, [NativeTypeName("HWND")] IntPtr hwnd);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetReferent(INewShortcutHookA* pThis, [NativeTypeName("PSTR")] sbyte* pszReferent, int cchReferent);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SetFolder(INewShortcutHookA* pThis, [NativeTypeName("PCSTR")] sbyte* pcszFolder);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetFolder(INewShortcutHookA* pThis, [NativeTypeName("PSTR")] sbyte* pszFolder, int cchFolder);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetName(INewShortcutHookA* pThis, [NativeTypeName("PSTR")] sbyte* pszName, int cchName);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetExtension(INewShortcutHookA* pThis, [NativeTypeName("PSTR")] sbyte* pszExtension, int cchExtension);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject)
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>(lpVtbl->QueryInterface)(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>(lpVtbl->AddRef)(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>(lpVtbl->Release)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SetReferent([NativeTypeName("PCSTR")] sbyte* pcszReferent, [NativeTypeName("HWND")] IntPtr hwnd)
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SetReferent>(lpVtbl->SetReferent)(pThis, pcszReferent, hwnd);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetReferent([NativeTypeName("PSTR")] sbyte* pszReferent, int cchReferent)
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetReferent>(lpVtbl->GetReferent)(pThis, pszReferent, cchReferent);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SetFolder([NativeTypeName("PCSTR")] sbyte* pcszFolder)
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SetFolder>(lpVtbl->SetFolder)(pThis, pcszFolder);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetFolder([NativeTypeName("PSTR")] sbyte* pszFolder, int cchFolder)
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetFolder>(lpVtbl->GetFolder)(pThis, pszFolder, cchFolder);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetName([NativeTypeName("PSTR")] sbyte* pszName, int cchName)
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetName>(lpVtbl->GetName)(pThis, pszName, cchName);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetExtension([NativeTypeName("PSTR")] sbyte* pszExtension, int cchExtension)
        {
            fixed (INewShortcutHookA* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetExtension>(lpVtbl->GetExtension)(pThis, pszExtension, cchExtension);
            }
        }

        public partial struct Vtbl
        {
            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((stdcall))")]
            public IntPtr QueryInterface;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr AddRef;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr Release;

            [NativeTypeName("HRESULT (PCSTR, HWND) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr SetReferent;

            [NativeTypeName("HRESULT (PSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetReferent;

            [NativeTypeName("HRESULT (PCSTR) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr SetFolder;

            [NativeTypeName("HRESULT (PSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetFolder;

            [NativeTypeName("HRESULT (PSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetName;

            [NativeTypeName("HRESULT (PSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetExtension;
        }
    }

    public unsafe partial struct INewShortcutHookW
    {
        public Vtbl* lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(INewShortcutHookW* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(INewShortcutHookW* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(INewShortcutHookW* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SetReferent(INewShortcutHookW* pThis, [NativeTypeName("PCWSTR")] ushort* pcszReferent, [NativeTypeName("HWND")] IntPtr hwnd);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetReferent(INewShortcutHookW* pThis, [NativeTypeName("PWSTR")] ushort* pszReferent, int cchReferent);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SetFolder(INewShortcutHookW* pThis, [NativeTypeName("PCWSTR")] ushort* pcszFolder);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetFolder(INewShortcutHookW* pThis, [NativeTypeName("PWSTR")] ushort* pszFolder, int cchFolder);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetName(INewShortcutHookW* pThis, [NativeTypeName("PWSTR")] ushort* pszName, int cchName);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetExtension(INewShortcutHookW* pThis, [NativeTypeName("PWSTR")] ushort* pszExtension, int cchExtension);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject)
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>(lpVtbl->QueryInterface)(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>(lpVtbl->AddRef)(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>(lpVtbl->Release)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SetReferent([NativeTypeName("PCWSTR")] ushort* pcszReferent, [NativeTypeName("HWND")] IntPtr hwnd)
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SetReferent>(lpVtbl->SetReferent)(pThis, pcszReferent, hwnd);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetReferent([NativeTypeName("PWSTR")] ushort* pszReferent, int cchReferent)
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetReferent>(lpVtbl->GetReferent)(pThis, pszReferent, cchReferent);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SetFolder([NativeTypeName("PCWSTR")] ushort* pcszFolder)
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SetFolder>(lpVtbl->SetFolder)(pThis, pcszFolder);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetFolder([NativeTypeName("PWSTR")] ushort* pszFolder, int cchFolder)
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetFolder>(lpVtbl->GetFolder)(pThis, pszFolder, cchFolder);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetName([NativeTypeName("PWSTR")] ushort* pszName, int cchName)
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetName>(lpVtbl->GetName)(pThis, pszName, cchName);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetExtension([NativeTypeName("PWSTR")] ushort* pszExtension, int cchExtension)
        {
            fixed (INewShortcutHookW* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetExtension>(lpVtbl->GetExtension)(pThis, pszExtension, cchExtension);
            }
        }

        public partial struct Vtbl
        {
            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((stdcall))")]
            public IntPtr QueryInterface;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr AddRef;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr Release;

            [NativeTypeName("HRESULT (PCWSTR, HWND) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr SetReferent;

            [NativeTypeName("HRESULT (PWSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetReferent;

            [NativeTypeName("HRESULT (PCWSTR) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr SetFolder;

            [NativeTypeName("HRESULT (PWSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetFolder;

            [NativeTypeName("HRESULT (PWSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetName;

            [NativeTypeName("HRESULT (PWSTR, int) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetExtension;
        }
    }

    public unsafe partial struct IColumnProvider
    {
        public Vtbl* lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IColumnProvider* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IColumnProvider* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IColumnProvider* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface1(IColumnProvider* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppv);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef1(IColumnProvider* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release1(IColumnProvider* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Initialize(IColumnProvider* pThis, [NativeTypeName("LPCSHCOLUMNINIT")] SHCOLUMNINIT* psci);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetColumnInfo(IColumnProvider* pThis, [NativeTypeName("DWORD")] uint dwIndex, [NativeTypeName("SHCOLUMNINFO *")] SHCOLUMNINFO* psci);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetItemData(IColumnProvider* pThis, [NativeTypeName("LPCSHCOLUMNID")] PROPERTYKEY* pscid, [NativeTypeName("LPCSHCOLUMNDATA")] SHCOLUMNDATA* pscd, [NativeTypeName("VARIANT *")] VARIANT* pvarData);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject)
        {
            fixed (IColumnProvider* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>(lpVtbl->QueryInterface)(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IColumnProvider* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>(lpVtbl->AddRef)(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IColumnProvider* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>(lpVtbl->Release)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Initialize([NativeTypeName("LPCSHCOLUMNINIT")] SHCOLUMNINIT* psci)
        {
            fixed (IColumnProvider* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Initialize>(lpVtbl->Initialize)(pThis, psci);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetColumnInfo([NativeTypeName("DWORD")] uint dwIndex, [NativeTypeName("SHCOLUMNINFO *")] SHCOLUMNINFO* psci)
        {
            fixed (IColumnProvider* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetColumnInfo>(lpVtbl->GetColumnInfo)(pThis, dwIndex, psci);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetItemData([NativeTypeName("LPCSHCOLUMNID")] PROPERTYKEY* pscid, [NativeTypeName("LPCSHCOLUMNDATA")] SHCOLUMNDATA* pscd, [NativeTypeName("VARIANT *")] VARIANT* pvarData)
        {
            fixed (IColumnProvider* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetItemData>(lpVtbl->GetItemData)(pThis, pscid, pscd, pvarData);
            }
        }

        public partial struct Vtbl
        {
            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((stdcall))")]
            public IntPtr QueryInterface;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr AddRef;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr Release;

            [NativeTypeName("HRESULT (LPCSHCOLUMNINIT) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr Initialize;

            [NativeTypeName("HRESULT (DWORD, SHCOLUMNINFO *) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetColumnInfo;

            [NativeTypeName("HRESULT (LPCSHCOLUMNID, LPCSHCOLUMNDATA, VARIANT *) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetItemData;
        }
    }

    public unsafe partial struct IPrintDialogCallback
    {
        public Vtbl* lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IPrintDialogCallback* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IPrintDialogCallback* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IPrintDialogCallback* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface1(IPrintDialogCallback* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObj);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef1(IPrintDialogCallback* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release1(IPrintDialogCallback* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _InitDone(IPrintDialogCallback* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _SelectionChange(IPrintDialogCallback* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _HandleMessage(IPrintDialogCallback* pThis, [NativeTypeName("HWND")] IntPtr hDlg, [NativeTypeName("UINT")] uint uMsg, [NativeTypeName("WPARAM")] UIntPtr wParam, [NativeTypeName("LPARAM")] IntPtr lParam, [NativeTypeName("LRESULT *")] IntPtr* pResult);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject)
        {
            fixed (IPrintDialogCallback* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>(lpVtbl->QueryInterface)(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IPrintDialogCallback* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>(lpVtbl->AddRef)(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IPrintDialogCallback* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>(lpVtbl->Release)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int InitDone()
        {
            fixed (IPrintDialogCallback* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_InitDone>(lpVtbl->InitDone)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int SelectionChange()
        {
            fixed (IPrintDialogCallback* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_SelectionChange>(lpVtbl->SelectionChange)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int HandleMessage([NativeTypeName("HWND")] IntPtr hDlg, [NativeTypeName("UINT")] uint uMsg, [NativeTypeName("WPARAM")] UIntPtr wParam, [NativeTypeName("LPARAM")] IntPtr lParam, [NativeTypeName("LRESULT *")] IntPtr* pResult)
        {
            fixed (IPrintDialogCallback* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_HandleMessage>(lpVtbl->HandleMessage)(pThis, hDlg, uMsg, wParam, lParam, pResult);
            }
        }

        public partial struct Vtbl
        {
            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((stdcall))")]
            public IntPtr QueryInterface;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr AddRef;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr Release;

            [NativeTypeName("HRESULT () __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr InitDone;

            [NativeTypeName("HRESULT () __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr SelectionChange;

            [NativeTypeName("HRESULT (HWND, UINT, WPARAM, LPARAM, LRESULT *) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr HandleMessage;
        }
    }

    public unsafe partial struct IPrintDialogServices
    {
        public Vtbl* lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _QueryInterface(IPrintDialogServices* pThis, [NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _AddRef(IPrintDialogServices* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("ULONG")]
        public delegate uint _Release(IPrintDialogServices* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetCurrentDevMode(IPrintDialogServices* pThis, [NativeTypeName("LPDEVMODE")] DEVMODEA* pDevMode, [NativeTypeName("UINT *")] uint* pcbSize);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetCurrentPrinterName(IPrintDialogServices* pThis, [NativeTypeName("LPWSTR")] ushort* pPrinterName, [NativeTypeName("UINT *")] uint* pcchSize);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetCurrentPortName(IPrintDialogServices* pThis, [NativeTypeName("LPWSTR")] ushort* pPortName, [NativeTypeName("UINT *")] uint* pcchSize);

        [return: NativeTypeName("HRESULT")]
        public int QueryInterface([NativeTypeName("const IID &")] Guid* riid, [NativeTypeName("void **")] void** ppvObject)
        {
            fixed (IPrintDialogServices* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_QueryInterface>(lpVtbl->QueryInterface)(pThis, riid, ppvObject);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint AddRef()
        {
            fixed (IPrintDialogServices* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_AddRef>(lpVtbl->AddRef)(pThis);
            }
        }

        [return: NativeTypeName("ULONG")]
        public uint Release()
        {
            fixed (IPrintDialogServices* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Release>(lpVtbl->Release)(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetCurrentDevMode([NativeTypeName("LPDEVMODE")] DEVMODEA* pDevMode, [NativeTypeName("UINT *")] uint* pcbSize)
        {
            fixed (IPrintDialogServices* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetCurrentDevMode>(lpVtbl->GetCurrentDevMode)(pThis, pDevMode, pcbSize);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetCurrentPrinterName([NativeTypeName("LPWSTR")] ushort* pPrinterName, [NativeTypeName("UINT *")] uint* pcchSize)
        {
            fixed (IPrintDialogServices* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetCurrentPrinterName>(lpVtbl->GetCurrentPrinterName)(pThis, pPrinterName, pcchSize);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetCurrentPortName([NativeTypeName("LPWSTR")] ushort* pPortName, [NativeTypeName("UINT *")] uint* pcchSize)
        {
            fixed (IPrintDialogServices* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetCurrentPortName>(lpVtbl->GetCurrentPortName)(pThis, pPortName, pcchSize);
            }
        }

        public partial struct Vtbl
        {
            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((stdcall))")]
            public IntPtr QueryInterface;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr AddRef;

            [NativeTypeName("ULONG () __attribute__((stdcall))")]
            public IntPtr Release;

            [NativeTypeName("HRESULT (const IID &, void **) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr QueryInterface1;

            [NativeTypeName("ULONG () __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr AddRef1;

            [NativeTypeName("ULONG () __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr Release1;

            [NativeTypeName("HRESULT (LPDEVMODE, UINT *) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetCurrentDevMode;

            [NativeTypeName("HRESULT (LPWSTR, UINT *) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetCurrentPrinterName;

            [NativeTypeName("HRESULT (LPWSTR, UINT *) __attribute__((nothrow)) __attribute__((stdcall))")]
            public IntPtr GetCurrentPortName;
        }
    }

    [StructLayout(LayoutKind.Explicit)]
    public partial struct PSAPI_WORKING_SET_BLOCK
    {
        [FieldOffset(0)]
        [NativeTypeName("ULONG_PTR")]
        public ulong Flags;

        [FieldOffset(0)]
        [NativeTypeName("_PSAPI_WORKING_SET_BLOCK::(anonymous struct at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/Psapi.h:276:5)")]
        public _Anonymous_e__Struct Anonymous;

        public partial struct _Anonymous_e__Struct
        {
            internal ulong _bitfield;

            [NativeTypeName("ULONG_PTR : 5")]
            public ulong Protection
            {
                get
                {
                    return _bitfield & 0x1Fu;
                }

                set
                {
                    _bitfield = (_bitfield & ~0x1Fu) | (value & 0x1Fu);
                }
            }

            [NativeTypeName("ULONG_PTR : 3")]
            public ulong ShareCount
            {
                get
                {
                    return (_bitfield >> 5) & 0x7u;
                }

                set
                {
                    _bitfield = (_bitfield & ~(0x7u << 5)) | ((value & 0x7u) << 5);
                }
            }

            [NativeTypeName("ULONG_PTR : 1")]
            public ulong Shared
            {
                get
                {
                    return (_bitfield >> 8) & 0x1u;
                }

                set
                {
                    _bitfield = (_bitfield & ~(0x1u << 8)) | ((value & 0x1u) << 8);
                }
            }

            [NativeTypeName("ULONG_PTR : 3")]
            public ulong Reserved
            {
                get
                {
                    return (_bitfield >> 9) & 0x7u;
                }

                set
                {
                    _bitfield = (_bitfield & ~(0x7u << 9)) | ((value & 0x7u) << 9);
                }
            }

            [NativeTypeName("ULONG_PTR : 20")]
            public ulong VirtualPage
            {
                get
                {
                    return (_bitfield >> 12) & 0xFFFFFu;
                }

                set
                {
                    _bitfield = (_bitfield & ~(0xFFFFFu << 12)) | ((value & 0xFFFFFu) << 12);
                }
            }
        }
    }


    [StructLayout(LayoutKind.Explicit)]
    public partial struct PSAPI_WORKING_SET_EX_BLOCK
    {
        [FieldOffset(0)]
        [NativeTypeName("ULONG_PTR")]
        public ulong Flags;

        [FieldOffset(0)]
        [NativeTypeName("_PSAPI_WORKING_SET_EX_BLOCK::(anonymous union at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/Psapi.h:296:5)")]
        public _Anonymous_e__Union Anonymous;

        [StructLayout(LayoutKind.Explicit)]
        public partial struct _Anonymous_e__Union
        {
            [FieldOffset(0)]
            [NativeTypeName("_PSAPI_WORKING_SET_EX_BLOCK::(anonymous struct at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/Psapi.h:297:9)")]
            public _Anonymous_e__Struct Anonymous;

            [FieldOffset(0)]
            [NativeTypeName("struct (anonymous struct at C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/Psapi.h:312:9)")]
            public _Invalid_e__Struct Invalid;

            public partial struct _Anonymous_e__Struct
            {
                internal ulong _bitfield;

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong Valid
                {
                    get
                    {
                        return _bitfield & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~0x1u) | (value & 0x1u);
                    }
                }

                [NativeTypeName("ULONG_PTR : 3")]
                public ulong ShareCount
                {
                    get
                    {
                        return (_bitfield >> 1) & 0x7u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x7u << 1)) | ((value & 0x7u) << 1);
                    }
                }

                [NativeTypeName("ULONG_PTR : 11")]
                public ulong Win32Protection
                {
                    get
                    {
                        return (_bitfield >> 4) & 0x7FFu;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x7FFu << 4)) | ((value & 0x7FFu) << 4);
                    }
                }

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong Shared
                {
                    get
                    {
                        return (_bitfield >> 15) & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x1u << 15)) | ((value & 0x1u) << 15);
                    }
                }

                [NativeTypeName("ULONG_PTR : 6")]
                public ulong Node
                {
                    get
                    {
                        return (_bitfield >> 16) & 0x3Fu;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x3Fu << 16)) | ((value & 0x3Fu) << 16);
                    }
                }

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong Locked
                {
                    get
                    {
                        return (_bitfield >> 22) & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x1u << 22)) | ((value & 0x1u) << 22);
                    }
                }

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong LargePage
                {
                    get
                    {
                        return (_bitfield >> 23) & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x1u << 23)) | ((value & 0x1u) << 23);
                    }
                }

                [NativeTypeName("ULONG_PTR : 7")]
                public ulong Reserved
                {
                    get
                    {
                        return (_bitfield >> 24) & 0x7Fu;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x7Fu << 24)) | ((value & 0x7Fu) << 24);
                    }
                }

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong Bad
                {
                    get
                    {
                        return (_bitfield >> 31) & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x1u << 31)) | ((value & 0x1u) << 31);
                    }
                }
            }

            public partial struct _Invalid_e__Struct
            {
                internal ulong _bitfield;

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong Valid
                {
                    get
                    {
                        return _bitfield & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~0x1u) | (value & 0x1u);
                    }
                }

                [NativeTypeName("ULONG_PTR : 14")]
                public ulong Reserved0
                {
                    get
                    {
                        return (_bitfield >> 1) & 0x3FFFu;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x3FFFu << 1)) | ((value & 0x3FFFu) << 1);
                    }
                }

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong Shared
                {
                    get
                    {
                        return (_bitfield >> 15) & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x1u << 15)) | ((value & 0x1u) << 15);
                    }
                }

                [NativeTypeName("ULONG_PTR : 15")]
                public ulong Reserved1
                {
                    get
                    {
                        return (_bitfield >> 16) & 0x7FFFu;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x7FFFu << 16)) | ((value & 0x7FFFu) << 16);
                    }
                }

                [NativeTypeName("ULONG_PTR : 1")]
                public ulong Bad
                {
                    get
                    {
                        return (_bitfield >> 31) & 0x1u;
                    }

                    set
                    {
                        _bitfield = (_bitfield & ~(0x1u << 31)) | ((value & 0x1u) << 31);
                    }
                }
            }
        }
    }
}
