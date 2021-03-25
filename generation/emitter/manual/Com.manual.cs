using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;
using static Windows.Win32.SystemServices.Apis;

namespace Windows.Win32.Com
{
    public static unsafe partial class Apis
    {
        public const int CTL_E_ILLEGALFUNCTIONCALL = unchecked(((int)(((uint)(SEVERITY_ERROR) << 31) | ((uint)(FACILITY_CONTROL) << 16) | ((uint)(5)))));
        public const int CONNECT_E_FIRST = unchecked(((int)(((uint)(SEVERITY_ERROR) << 31) | ((uint)(FACILITY_ITF) << 16) | ((uint)(0x0200)))));
        public const int SELFREG_E_FIRST = unchecked(((int)(((uint)(SEVERITY_ERROR) << 31) | ((uint)(FACILITY_ITF) << 16) | ((uint)(0x0200)))));
        public const int PERPROP_E_FIRST = unchecked(((int)(((uint)(SEVERITY_ERROR) << 31) | ((uint)(FACILITY_ITF) << 16) | ((uint)(0x0200)))));

        [NativeTypeName("HRESULT")]
        public const int OLECMDERR_E_FIRST = OLE_E_LAST + 1;

        [NativeTypeName("HRESULT")]
        public const int OLECMDERR_E_DISABLED = OLECMDERR_E_FIRST + 1;

        [NativeTypeName("HRESULT")]
        public const int OLECMDERR_E_NOHELP = OLECMDERR_E_FIRST + 2;

        [NativeTypeName("HRESULT")]
        public const int OLECMDERR_E_CANCELED = OLECMDERR_E_FIRST + 3;

        [NativeTypeName("HRESULT")]
        public const int OLECMDERR_E_UNKNOWNGROUP = OLECMDERR_E_FIRST + 4;

        [NativeTypeName("HRESULT")]
        public const int CONNECT_E_NOCONNECTION = CONNECT_E_FIRST + 0;

        [NativeTypeName("HRESULT")]
        public const int CONNECT_E_ADVISELIMIT = CONNECT_E_FIRST + 1;

        [NativeTypeName("HRESULT")]
        public const int CONNECT_E_CANNOTCONNECT = CONNECT_E_FIRST + 2;

        [NativeTypeName("HRESULT")]
        public const int CONNECT_E_OVERRIDDEN = CONNECT_E_FIRST + 3;

        [NativeTypeName("HRESULT")]
        public const int SELFREG_E_TYPELIB = SELFREG_E_FIRST + 0;

        [NativeTypeName("HRESULT")]
        public const int SELFREG_E_CLASS = SELFREG_E_FIRST + 1;

        [NativeTypeName("HRESULT")]
        public const int PERPROP_E_NOPAGEAVAILABLE = PERPROP_E_FIRST + 0;
    }
}
