using System;
using System.Runtime.InteropServices;
using static Microsoft.Windows.Win32.Apis;

namespace Microsoft.Windows.Win32
{
    public struct HRESULT : IEquatable<HRESULT>
    {
        private int _value;

        public HRESULT(int value)
        {
            _value = value;
        }

        public bool FAILED => FAILED(_value);

        public bool SUCCEEDED => SUCCEEDED(_value);

        public static bool operator ==(HRESULT l, HRESULT r) => l._value == r._value;

        public static bool operator !=(HRESULT l, HRESULT r) => !(l == r);

        public static implicit operator HRESULT(int value) => new HRESULT(value);

        public static implicit operator int(HRESULT value) => value._value;

        public override bool Equals(object obj) => (obj is HRESULT other) && Equals(other);

        public bool Equals(HRESULT other) => this == other;

        public override int GetHashCode() => _value.GetHashCode();
    }

    public static partial class Apis
    {
        public static bool SUCCEEDED(int hr)
        {
            return hr >= 0;
        }

        public static bool FAILED(int hr)
        {
            return hr < 0;
        }

        public static bool IS_ERROR(int Status)
        {
            return ((uint)Status >> 31) == SEVERITY_ERROR;
        }

        public static int HRESULT_CODE(int hr)
        {
            return hr & 0xFFFF;
        }

        public static int SCODE_CODE(int sc)
        {
            return sc & 0xFFFF;
        }

        public static int HRESULT_FACILITY(int hr)
        {
            return (hr >> 16) & 0x1FFF;
        }

        public static int SCODE_FACILITY(int sc)
        {
            return (sc >> 16) & 0x1FFF;
        }

        public static int HRESULT_SEVERITY(int hr)
        {
            return (hr >> 31) & 0x1;
        }

        public static int SCODE_SEVERITY(int sc)
        {
            return (sc >> 31) & 0x1;
        }

        public static int MAKE_HRESULT(int sev, int fac, int code)
        {
            return (int)(((uint)sev << 31) | ((uint)fac << 16) | (uint)code);
        }

        public static int MAKE_SCODE(int sev, int fac, int code)
        {
            return (int)(((uint)sev << 31) | ((uint)fac << 16) | (uint)code);
        }

        public static int __HRESULT_FROM_WIN32(int x)
        {
            return (x <= 0) ? x : ((x & 0x0000FFFF) | (FACILITY_WIN32 << 16) | unchecked((int)0x80000000));
        }

        public static int HRESULT_FROM_WIN32(int x)
        {
            return __HRESULT_FROM_WIN32(x);
        }

        public static void ThrowIfFailed(string methodName, HRESULT hr)
        {
            if (FAILED(hr))
            {
                Marshal.ThrowExceptionForHR(hr);
            }
        }
    }
}
