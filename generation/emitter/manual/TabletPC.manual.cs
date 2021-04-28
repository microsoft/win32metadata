using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.UI.TabletPC
{
    // Because this gets emitted twice from recapis.h
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    [return: NativeTypeName("HRESULT")]
    public unsafe delegate int PfnRecoCallback([NativeTypeName("DWORD")] uint param0, [NativeTypeName("LPBYTE")] byte* param1, [NativeTypeName("HRECOCONTEXT")] IntPtr param2);

    public static unsafe partial class Apis
    {
        [NativeTypeName("const WCHAR [29]")]
        public const string MICROSOFT_URL_EXPERIENCE_PROPERTY = "Microsoft TIP URL Experience";

        [NativeTypeName("const WCHAR [31]")]
        public const string MICROSOFT_TIP_NO_INSERT_BUTTON_PROPERTY = "Microsoft TIP No Insert Option";

        [NativeTypeName("const WCHAR [46]")]
        public const string MICROSOFT_TIP_COMBOBOXLIST_PROPERTY = "Microsoft TIP ComboBox List Window Identifier";

        [NativeTypeName("const WCHAR [24]")]
        public const string MICROSOFT_TIP_OPENING_MSG = "TabletInputPanelOpening";
    }
}
