using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Win32;
using static Microsoft.Windows.Win32.Apis;

namespace SampleCsWin32App
{
    public enum MuhEnum
    {
        A = 100,
        B = A + 200,
        C = A + B * 3
    }

    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IFoobar
    {
        int HiThere(int x, int z);
        void BazMe();
    }

    public unsafe class Program
    {
        public static void Main(string[] args)
        {
            ShowWindowTitles();
            Console.WriteLine();

            ShowProcessNames();
            Console.WriteLine();

            int result;
            var hkeyUser = new IntPtr(0x80000001);
            result = RegCreateKeyW(hkeyUser, @"SOFTWARE\Microsoft\Clipboard", out var openedKey);
            uint value = 0;
            uint size = sizeof(int);
            uint* pValue = &value;
            uint* pSize = &size;            
            result = RegGetValueW(openedKey.DangerousGetHandle(), null, "ShellHotKeyUsed", 0x0000ffff, null, pValue, pSize);
        }

        private static void ShowWindowTitles()
        {
            Console.WriteLine("Windows:");
            Apis.EnumWindows(WndEnumProc, IntPtr.Zero);
        }

        private static unsafe int WndEnumProc(IntPtr hwnd, IntPtr lParam)
        {
            int textLen = Microsoft.Windows.Win32.Apis.GetWindowTextLengthW(hwnd);
            char[] textBuffer = new char[textLen + 1];
            Apis.GetWindowTextW(hwnd, textBuffer, textBuffer.Length);
            string windowText = new string(textBuffer, 0, textLen);

            Console.WriteLine($"hwnd: {hwnd:x} - {windowText}");

            return 1;
        }

        private static void ShowProcessNames()
        {
            Console.WriteLine("Processes:");
            uint[] processes = new uint[1024];
            if (Apis.K32EnumProcesses(processes, (uint)processes.Length, out uint cbNeeded) == 0)
            {
                Console.WriteLine("Failed to enum processes.");
            }

            uint processCount = cbNeeded / sizeof(uint);
            for (uint i = 0; i < processCount; i++)
            {
                PrintProcessNameAndId(processes[i]);
            }
        }

        private static void PrintProcessNameAndId(uint pid)
        {
            using (var proc =
                Apis.OpenProcess(
                    ProcessAccessRights.QueryInformation | ProcessAccessRights.VmRead,
                    0,
                    pid))
            {
                string procName = "<unknown>";
                if (!proc.IsInvalid)
                {
                    IntPtr[] hModules = new IntPtr[1];
                    if (Apis.K32EnumProcessModules(proc.DangerousGetHandle(), hModules, 1, out _) != 0)
                    {
                        char[] moduleFileName = new char[512];
                        uint len = Apis.K32GetModuleBaseNameW(proc.DangerousGetHandle(), hModules[0], moduleFileName, (uint)moduleFileName.Length);
                        procName = new string(moduleFileName, 0, (int)len);
                    }
                }

                Console.WriteLine($"pid: {pid} - {procName}");
            }
        }
    }
}
