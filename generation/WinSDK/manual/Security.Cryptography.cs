using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.Security.Cryptography
{
    public static unsafe partial class Apis
    {
        // Manually defined due to missing header definitions
        // https://github.com/microsoft/win32metadata/issues/1605

        [DllImport("BCryptPrimitives.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = true)]
        [return: NativeTypeName("BOOL")]
        public static extern int SystemPrng([NativeTypeName("PUCHAR")][MemorySize(BytesParamIndex=1)][Out] byte* pbRandomData, [NativeTypeName("SIZE_T")] nuint cbRandomData);

        [DllImport("BCryptPrimitives.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = true)]
        [return: NativeTypeName("BOOL")]
        public static extern int ProcessPrng([NativeTypeName("PBYTE")][MemorySize(BytesParamIndex=1)][Out] byte* pbData, [NativeTypeName("SIZE_T")] nuint cbData);

        // Manually defined due to missing unsafe modifier during codegen pass
        // https://github.com/microsoft/win32metadata/issues/1914

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return:NativeTypeName("SECURITY_STATUS")]
        public delegate HRESULT SslGetCipherSuitePRFHashAlgorithmFn([NativeTypeName("NCRYPT_PROV_HANDLE")][In]UIntPtr hSslProvider, [NativeTypeName("DWORD")][In]uint dwProtocol, [NativeTypeName("DWORD")][In]uint dwCipherSuite, [NativeTypeName("DWORD")][In]uint dwKeyType, [NativeTypeName("WCHAR[64]")][NativeArrayInfo(CountConst = 64),Out]ushort* szPRFHash, [NativeTypeName("DWORD")][In]uint dwFlags);
    }
}
