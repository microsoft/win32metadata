using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Sdk;

namespace SampleCsApp
{
    static unsafe class Program
    {
        //NTSYSAPI
        //_Success_(return != 0)
        //WORD  
        //NTAPI
        //RtlCaptureStackBackTrace(
        //    _In_ DWORD FramesToSkip,
        //    _In_ DWORD FramesToCapture,
        //    _Out_writes_to_(FramesToCapture,return) PVOID* BackTrace,
        //    _Out_opt_ PDWORD BackTraceHash
        //    );

        [DllImport("KERNEL32", EntryPoint = "RtlCaptureStackBackTrace", ExactSpelling = true)]
        [return: NativeTypeName("WORD")]
        private static extern ushort Raw_RtlCaptureStackBackTrace(uint FramesToSkip, uint FramesToCapture, [Out][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] void** BackTrace, [Out][Optional]uint* BackTraceHash);

        [DllImport("KERNEL32", EntryPoint = "RtlCaptureStackBackTrace", ExactSpelling = true)]
        [return: NativeTypeName("WORD")]
        private static extern ushort Proj_RtlCaptureStackBackTrace(uint FramesToSkip, uint FramesToCapture, [Out][MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] void*[] BackTrace, [Out][Optional] uint* BackTraceHash);

        public static ushort RtlCaptureStackBackTrace(uint framesToSkip, uint framesToCapture, void*[] backTrace, out uint backTraceHash)
        {
            unsafe
            {
                //fixed (void** pBackTrace = &backTrace[0])
                {
                    uint tempBackTraceHash = 0;
                    uint* pBackTraceHash = &tempBackTraceHash;
                    var ret = Proj_RtlCaptureStackBackTrace(framesToSkip, (uint)framesToCapture, backTrace, pBackTraceHash);
                    backTraceHash = tempBackTraceHash;
                    return ret;
                }
                //fixed (void** pBackTrace = &backTrace[0])
                //{
                //    uint tempBackTraceHash = 0;
                //    uint* pBackTraceHash = &tempBackTraceHash;
                //    var ret = Apis.RtlCaptureStackBackTrace(0, (uint)backTrace.Length, pBackTrace, pBackTraceHash);
                //    backTraceHash = tempBackTraceHash;
                //    return ret;
                //}
            }
        }

        [DllImport("bcrypt", EntryPoint = "BCryptQueryProviderRegistration", ExactSpelling = true)]
        [return: NativeTypeName("NTSTATUS")]
        private static extern int BCryptQueryProviderRegistration([MarshalAs(UnmanagedType.LPWStr)] string pszProvider, uint dwMode, uint dwInterface, uint* pcbBuffer, _CRYPT_PROVIDER_REG** ppBuffer);


        public static ushort RtlCaptureStackBackTrace(uint framesToSkip, uint framesToCapture, void*[] backTrace)
        {
            unsafe
            {
                //fixed (void** pBackTrace = &backTrace[0])
                {
                    return Apis.RtlCaptureStackBackTrace(framesToSkip, framesToCapture, backTrace, null);
                }
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            void*[] frames;
            uint backTraceHash = 0;
            ushort frameCapturedCount;

            // Callling raw version examples
            unsafe
            {
                //fixed (void** pFrames = &frames[0])
                {
                    uint* pBackTraceHash = &backTraceHash;

                    // With non-null pBackTraceHash
                    frames = new void*[10];
                    frameCapturedCount = Apis.RtlCaptureStackBackTrace(0, (uint)frames.Length, frames, pBackTraceHash);

                    // With null pBackTraceHash
                    frames = new void*[10];
                    frameCapturedCount = Apis.RtlCaptureStackBackTrace(0, (uint)frames.Length, frames, null);
                }
            }

            // Callling projected examples

            // With non-null pBackTraceHash
            frames = new void*[10];
            frameCapturedCount = Program.RtlCaptureStackBackTrace(0, (uint)frames.Length, frames, out backTraceHash);

            // With null pBackTraceHash
            frames = new void*[10];
            frameCapturedCount = Program.RtlCaptureStackBackTrace(0, (uint)frames.Length, frames);

            // Another way to ignore out param, but doesn't pass null to Win32 function so not quite the same
            frames = new void*[10];
            frameCapturedCount = Program.RtlCaptureStackBackTrace(0, (uint)frames.Length, frames, out _);
        }
    }
}
