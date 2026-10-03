// Win32 Metadata API Surface
// Source: SampleWinmd.winmd

// ═══════════════════════════════════════════════════════════════
// Namespace: Sample.Api
// ═══════════════════════════════════════════════════════════════

namespace Sample.Api;

using System;
using System.Runtime.InteropServices;
using Sample.Api;
using Windows.Win32;
using Windows.Win32.Foundation.Metadata;

public sealed class Apis
{
	public const int SAMPLE_FEATURE_ENABLED = 1;

	public const int SAMPLE_INCLUDE_ORDER_TOKEN = 41;

	public const SAMPLE_HANDLE SAMPLE_INVALID_HANDLE = -1;

	[NativeEncoding ("ansi")]
	public const string SAMPLE_MACRO_HEADER = "MacroExpanded.h";

	public const uint SAMPLE_MODE_EXTERNAL = 3758096385u;

	[DllImport ("sampleapi.dll", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false, SetLastError = true)]
	[SupportedOSPlatform ("windows10.0.19041.662")]
	public static extern int SampleAdd ([In] int left, [In] int right);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public unsafe static extern void SampleBuffers ([In][NativeArrayInfo (CountParamIndex = 1)] int* values, [In] uint elementCount, [In][MemorySize (BytesParamIndex = 3)] void* bytes, [In] uint byteCount, [In] PCSTR terminated, [In][NotNullTerminated] sbyte* raw, [In][NotNullTerminated][NullNullTerminated] sbyte* multistring);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public unsafe static extern int SampleCreateDirectValue ([Out][RetVal] int* value);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public unsafe static extern int SampleCreateHandle ([Out][RAIIFree ("SampleCloseHandle")][InvalidHandleValue (-1L)][InvalidHandleValue (0L)] SAMPLE_HANDLE* result);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public unsafe static extern int SampleCreateValue ([Out][RetVal] int* value);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[return: AssociatedEnum ("SAMPLE_MODE")]
	public static extern uint SampleGetMode ([In][AssociatedEnum ("SAMPLE_MODE")] uint fallback);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public unsafe static extern void SampleLegacyBuffers ([Optional][Out][MemorySize (BytesParamIndex = 1)] void* buffer, [In] uint capacity, [Out] uint* written, [In][NativeArrayInfo (CountParamIndex = 4)] PCSTR input, [In] uint characterCount, [Out] sbyte** output);

	[DllImport ("samplemerged.dll", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false, SetLastError = true)]
	[SupportedOSPlatform ("windows6.1")]
	public unsafe static extern int SampleMergedContract ([Out] void* buffer, [In] uint length);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[return: RAIIFree ("SampleCloseHandle")]
	[return: InvalidHandleValue (-1L)]
	[return: InvalidHandleValue (0L)]
	public static extern SAMPLE_HANDLE SampleOpenHandle ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public unsafe static extern void SampleOutputBuffers ([Out] uint* elementCount, [Out][NativeArrayInfo (CountParamIndex = 0)] int** values, [Out] uint* byteCount, [Out][MemorySize (BytesParamIndex = 2)] void** bytes);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
	public static extern Exception SamplePreservedResult ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windowsserver2000")]
	public static extern int SampleServer2000 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windowsserver2003")]
	public static extern int SampleServer2003 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windowsserver2008")]
	public static extern int SampleServer2008 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windowsserver2012")]
	public static extern int SampleServer2012 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windowsserver2016")]
	public static extern int SampleServer2016 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public static extern void SampleUseHandle ([In][Retained] SAMPLE_HANDLE handle);

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedArchitecture (6)]
	public static extern long SampleWideOnly ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.10240")]
	public static extern int SampleWindows10_10240 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.10586")]
	public static extern int SampleWindows10_10586 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.14393")]
	public static extern int SampleWindows10_14393 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.15063")]
	public static extern int SampleWindows10_15063 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.16299")]
	public static extern int SampleWindows10_16299 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.17134")]
	public static extern int SampleWindows10_17134 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.17763")]
	public static extern int SampleWindows10_17763 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.18362")]
	public static extern int SampleWindows10_18362 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.19041.662")]
	public static extern int SampleWindows10_19041_662 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.19041")]
	public static extern int SampleWindows10_19041 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.20348")]
	public static extern int SampleWindows10_20348 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.22631")]
	public static extern int SampleWindows10_22631 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.26100")]
	public static extern int SampleWindows10_26100 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows5.0")]
	public static extern int SampleWindows2000 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows6.1")]
	public static extern int SampleWindows7 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows8.1")]
	public static extern int SampleWindows81 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows8.0")]
	public static extern int SampleWindows8 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows6.0.6001")]
	public static extern int SampleWindowsVistaSP1 ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows6.0.6000")]
	public static extern int SampleWindowsVista ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows5.1.2600")]
	public static extern int SampleWindowsXP ();

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedArchitecture (1)]
	public static extern int SampleX86Only ();
}

namespace Sample.Api;

using System;
using System.Runtime.InteropServices;
using Windows.Foundation.Metadata;
using Windows.Win32.Foundation.Metadata;

[Guid (305419896u, 4660, 4660, 18, 52, 18, 52, 86, 120, 154, 188)]
public interface ISampleFactory
{
	unsafe Exception Create ([Out][RetVal][ComOutPtr] void** value);

	[PreserveSig]
	unsafe Exception TryCreate ([Out][ComOutPtr] void** value);
}

namespace Sample.Api;

using System.Runtime.InteropServices;

[UnmanagedFunctionPointer (/*Could not decode attribute arguments.*/)]
public delegate int PSAMPLE_CALLBACK ([In] int code);

namespace Sample.Api;

using Windows.Win32.Foundation.Metadata;

[SupportedArchitecture (6)]
public struct SAMPLE_ARCH_VALUE
{
	public long value;
}

namespace Sample.Api;

using Windows.Win32.Foundation.Metadata;

[SupportedArchitecture (1)]
public struct SAMPLE_ARCH_VALUE
{
	public int value;
}

namespace Sample.Api;

public struct SAMPLE_ARRAYS
{
	public byte[] bytes;

	public int[] values;
}

namespace Sample.Api;

using System.Runtime.InteropServices;

[UnmanagedFunctionPointer (/*Could not decode attribute arguments.*/)]
public delegate int SAMPLE_CALLBACK ([In] int code);

namespace Sample.Api;

using Sample.Api;

public struct SAMPLE_CALLBACKS
{
	public PSAMPLE_CALLBACK chained;

	public unsafe PSAMPLE_CALLBACK* pointer;

	public SAMPLE_CALLBACKS_anonymous anonymous;
}

namespace Sample.Api;

using System.Runtime.InteropServices;

[UnmanagedFunctionPointer (/*Could not decode attribute arguments.*/)]
public delegate int SAMPLE_CALLBACKS_anonymous ([In] int arg0);

namespace Sample.Api;

using System.Runtime.InteropServices;

[UnmanagedFunctionPointer (/*Could not decode attribute arguments.*/)]
public delegate int SAMPLE_CALLBACKS_anonymous_2 ([In] int arg0);

namespace Sample.Api;

using Sample.Api;
using Windows.Win32.Foundation.Metadata;

[NativeTypedef]
[AlsoUsableFor ("SAMPLE_HANDLE")]
public struct SAMPLE_COMPAT_HANDLE
{
	public SAMPLE_RESOURCE_HANDLE Value;
}

namespace Sample.Api;

public struct SAMPLE_DIRECT_DECLARATION
{
	public int value;
}

namespace Sample.Api;

public struct SAMPLE_FEATURE_MACRO
{
	public int value;
}

namespace Sample.Api;

using Windows.Win32.Foundation.Metadata;

[NativeTypedef]
public struct SAMPLE_HANDLE
{
	public unsafe void* Value;
}

namespace Sample.Api;

public struct SAMPLE_MACRO_EXPANDED_INCLUDE
{
	public int value;
}

namespace Sample.Api;

using Windows.Win32.Foundation.Metadata;

[AssociatedConstant ("SAMPLE_MODE_EXTERNAL")]
public enum SAMPLE_MODE : uint
{
	SAMPLE_MODE_NONE,
	SAMPLE_MODE_FAST
}

namespace Sample.Api;

public struct SAMPLE_ORDERED_INCLUDE
{
	public int value;
}

namespace Sample.Api;

using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

[StructLayout (LayoutKind.Sequential, Pack = 2)]
[Alignment (8)]
public struct SAMPLE_PACKED
{
	public sbyte tag;

	public int value;
}

namespace Sample.Api;

public struct SAMPLE_POINT
{
	public int x;

	public int y;
}

namespace Sample.Api;

public struct SAMPLE_PROPERTY
{
	public uint id;

	public unsafe void* value;
}

namespace Sample.Api;

using Sample.Api;
using Windows.Win32.Foundation.Metadata;

[NativeTypedef]
[RAIIFree ("SampleCloseHandle")]
[InvalidHandleValue (-1L)]
[InvalidHandleValue (0L)]
public struct SAMPLE_RESOURCE_HANDLE
{
	public SAMPLE_HANDLE Value;
}

