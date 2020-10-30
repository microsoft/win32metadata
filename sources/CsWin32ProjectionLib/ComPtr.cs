using System;
using System.Security.Permissions;
using Microsoft.Win32.SafeHandles;

namespace Microsoft.Windows.Win32
{
    [SecurityPermission(SecurityAction.InheritanceDemand, UnmanagedCode = true)]
    [SecurityPermission(SecurityAction.Demand, UnmanagedCode = true)]
    public unsafe class ComPtr<T> : SafeHandleZeroOrMinusOneIsInvalid where T : unmanaged
    {
        public ComPtr(void* pData) : base(true)
        {
            this.handle = new IntPtr(pData);
        }

        public ComPtr() : base(true)
        {
        }

        public T* Get() { return (T*)this.handle.ToPointer(); }

        public T* Detach()
        {
            T* ret = Get();
            this.handle = IntPtr.Zero;
            return ret;
        }

        public static implicit operator T*(ComPtr<T> p) => p.Get();

        public void Attach(IntPtr other)
        {
            this.ReleaseHandle();
            this.handle = other;
        }

        public void Attach(T* other)
        {
            this.Attach(new IntPtr(other));
        }

        protected override bool ReleaseHandle()
        {
            if (this.handle != IntPtr.Zero)
            {
                IUnknown* pUnk = (IUnknown*)this.handle.ToPointer();
                pUnk->Release();
                this.handle = IntPtr.Zero;
            }

            return true;
        }
    }
}
