// Win32 Metadata API Surface
// Source: SampleWinmd.winmd

// ═══════════════════════════════════════════════════════════════
// Namespace: Sample.Api
// ═══════════════════════════════════════════════════════════════

using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Sample.Api;

public sealed class Apis
{
	public const uint SAMPLE_MODE_EXTERNAL = 3758096385u;

	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	[SupportedOSPlatform ("windows10.0.19041.662")]
	public static extern int SampleAdd ([In] int left, [In] int right);
}

using Windows.Win32.Foundation.Metadata;

namespace Sample.Api;

[AssociatedConstant ("SAMPLE_MODE_EXTERNAL")]
public enum SAMPLE_MODE : uint
{
	SAMPLE_MODE_NONE,
	SAMPLE_MODE_FAST
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

