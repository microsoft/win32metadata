using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace Microsoft.Windows.Win32
{
    public static unsafe partial class Apis
    {
        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "GetWindowLongPtrA", ExactSpelling = true)]
        private static extern IntPtr _GetWindowLongPtrA(IntPtr hWnd, int nIndex);

        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "GetWindowLongPtrW", ExactSpelling = true)]
        static extern IntPtr _GetWindowLongPtrW(IntPtr hWnd, int nIndex);

        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "SetWindowLongPtrA", ExactSpelling = true)]
        static extern IntPtr _SetWindowLongPtrA(IntPtr hWnd, int nIndex, IntPtr dwNewLong);

        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "SetWindowLongPtrW", ExactSpelling = true)]
        static extern IntPtr _SetWindowLongPtrW(IntPtr hWnd, int nIndex, IntPtr dwNewLong);


        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "GetClassLongPtrA", ExactSpelling = true)]
        static extern UIntPtr _GetClassLongPtrA(IntPtr hWnd, int nIndex);

        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "GetClassLongPtrW", ExactSpelling = true)]
        static extern UIntPtr _GetClassLongPtrW(IntPtr hWnd, int nIndex);

        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "SetClassLongPtrA", ExactSpelling = true)]
        static extern UIntPtr _SetClassLongPtrA(IntPtr hWnd, int nIndex, IntPtr dwNewLong);

        [DllImport("user32", CallingConvention = CallingConvention.Winapi, EntryPoint = "SetClassLongPtrW", ExactSpelling = true)]
        static extern UIntPtr _SetClassLongPtrW(IntPtr hWnd, int nIndex, IntPtr dwNewLong);

        // We need this because we need to be able to pass in raw pointers
        [DllImport("USER32", ExactSpelling = true)]
        public static extern IntPtr LoadCursorW([In][Optional] IntPtr hInstance, [In] ushort* lpCursorName);

        public static IntPtr GetWindowLongPtrA(IntPtr hWnd, int nIndex)
        {
            if (sizeof(IntPtr) == 4)
            {
                return new IntPtr(GetWindowLongA(hWnd, nIndex));
            }
            else
            {
                return _GetWindowLongPtrA(hWnd, nIndex);
            }
        }

        public static IntPtr GetWindowLongPtrW(IntPtr hWnd, int nIndex)
        {
            if (sizeof(IntPtr) == 4)
            {
                return new IntPtr(GetWindowLongW(hWnd, nIndex));
            }
            else
            {
                return _GetWindowLongPtrW(hWnd, nIndex);
            }
        }

        public static IntPtr SetWindowLongPtrA(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
        {
            if (sizeof(IntPtr) == 4)
            {
                return new IntPtr(SetWindowLongA(hWnd, nIndex, (int)dwNewLong));
            }
            else
            {
                return _SetWindowLongPtrA(hWnd, nIndex, dwNewLong);
            }
        }

        public static IntPtr SetWindowLongPtrW(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
        {
            if (sizeof(IntPtr) == 4)
            {
                return new IntPtr(SetWindowLongW(hWnd, nIndex, dwNewLong.ToInt32()));
            }
            else
            {
                return _SetWindowLongPtrW(hWnd, nIndex, dwNewLong);
            }
        }

        public static UIntPtr GetClassLongPtrA(IntPtr hWnd, int nIndex)
        {
            if (sizeof(UIntPtr) == 4)
            {
                return (UIntPtr)GetClassLongA(hWnd, nIndex);
            }
            else
            {
                return _GetClassLongPtrA(hWnd, nIndex);
            }
        }

        public static UIntPtr GetClassLongPtrW(IntPtr hWnd, int nIndex)
        {
            if (sizeof(UIntPtr) == 4)
            {
                return (UIntPtr)GetClassLongW(hWnd, nIndex);
            }
            else
            {
                return _GetClassLongPtrW(hWnd, nIndex);
            }
        }

        public static UIntPtr SetClassLongPtrA(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
        {
            if (sizeof(UIntPtr) == 4)
            {
                return (UIntPtr)SetClassLongA(hWnd, nIndex, (int)dwNewLong);
            }
            else
            {
                return _SetClassLongPtrA(hWnd, nIndex, dwNewLong);
            }
        }

        public static UIntPtr SetClassLongPtrW(IntPtr hWnd, int nIndex, IntPtr dwNewLong)
        {
            if (sizeof(UIntPtr) == 4)
            {
                return (UIntPtr)SetClassLongW(hWnd, nIndex, (int)dwNewLong);
            }
            else
            {
                return _SetClassLongPtrW(hWnd, nIndex, dwNewLong);
            }
        }
    }
}
