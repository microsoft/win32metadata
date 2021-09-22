using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Rpc
{
    // Because this emits with an anonymous name
    public unsafe partial struct NDR_SCONTEXT_1
    {
        [NativeTypeName("void *[2]")]
        public _pad_e__FixedBuffer pad;

        [NativeTypeName("void *")]
        public void* userContext;

        public unsafe partial struct _pad_e__FixedBuffer
        {
            public void* e0;
            public void* e1;

            public ref void* this[int index]
            {
                get
                {
                    fixed (void** pThis = &e0)
                    {
                        return ref pThis[index];
                    }
                }
            }
        }
    }
}
