// Win32 Metadata API Surface
// Source: SampleWinmd.winmd

// ═══════════════════════════════════════════════════════════════
// Namespace: Sample.Api
// ═══════════════════════════════════════════════════════════════

using System.Runtime.InteropServices;

namespace Sample.Api;

public sealed class Apis
{
	[DllImport ("", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true, PreserveSig = false)]
	public static extern int SampleAdd ([In] int left, [In] int right);
}

namespace Sample.Api;

public enum SAMPLE_MODE
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

