// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from shared/windef.h in the Windows SDK for Windows 10.0.19041.0
// Original source is Copyright © Microsoft. All rights reserved.

using System;

namespace Microsoft.Windows.Win32
{
    public unsafe struct HWND : IEquatable<HWND>
    {
        public static readonly HWND NULL = default;

        private void* _value;

        public HWND(IntPtr value) : this(value.ToPointer())
        {
        }

        public HWND(void* value)
        {
            _value = value;
        }

        public static bool operator ==(HWND l, HWND r) => l._value == r._value;

        public static bool operator !=(HWND l, HWND r) => !(l == r);

        public static implicit operator HWND(IntPtr value) => new HWND(value);

        public static implicit operator HWND(void* value) => new HWND(value);

        public static implicit operator IntPtr(HWND value) => new IntPtr(value._value);

        public static implicit operator void*(HWND value) => value._value;

        public override bool Equals(object obj) => (obj is HWND other) && Equals(other);

        public bool Equals(HWND other) => this == other;

        public override int GetHashCode() => ((IntPtr)_value).GetHashCode();
    }
}
