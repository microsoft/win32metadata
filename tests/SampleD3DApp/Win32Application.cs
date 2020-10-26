// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from Win32Application.h in https://github.com/Microsoft/DirectX-Graphics-Samples
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Win32;
using static Microsoft.Windows.Win32.Apis;

namespace SampleD3DApp
{
    public static unsafe class Win32Application
    {
        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        private delegate IntPtr WNDPROC(IntPtr param0, uint param1, UIntPtr param2, IntPtr param3);

        private static readonly WNDPROC s_wndProc = (hwnd, message, wParam, lParam) => WindowProc(hwnd, message, wParam, lParam);
        private static readonly IntPtr s_wndProcHandle = Marshal.GetFunctionPointerForDelegate(s_wndProc);

        private static HWND s_hwnd;

        public static HWND Hwnd => s_hwnd;

        public static int Run(DXSample sample, int nCmdShow)
        {
            // Parse the command line parameters
            sample.ParseCommandLineArgs(Environment.GetCommandLineArgs());

            fixed (char* lpszClassName = "DXSampleClass")
            {
                IntPtr hInstance = GetModuleHandleW(null);
                // Initialize the window class.
                var windowClass = new WNDCLASSEXW {
                    cbSize = (uint)sizeof(WNDCLASSEXW),
                    style = CS_HREDRAW | CS_VREDRAW,
                    lpfnWndProc = s_wndProcHandle,
                    hInstance = hInstance,
                    hCursor = LoadCursorW(IntPtr.Zero, (ushort*)IDC_ARROW),
                    lpszClassName = lpszClassName
                };
                _ = RegisterClassExW(&windowClass);

                var windowRect = new RECT {
                    right = unchecked((int)sample.Width),
                    bottom = unchecked((int)sample.Height)
                };
                _ = AdjustWindowRect(ref windowRect, WS_OVERLAPPEDWINDOW, FALSE);

                // Create the window and store a handle to it.
                s_hwnd = CreateWindowExW(
                    0,
                    new string(windowClass.lpszClassName),
                    sample.Title,
                    WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    windowRect.right - windowRect.left,
                    windowRect.bottom - windowRect.top,
                    IntPtr.Zero,                              // We have no parent window.
                    IntPtr.Zero,                             // We aren't using menus.
                    hInstance,
                    ((IntPtr)GCHandle.Alloc(sample)).ToPointer()
                );
            }

            // Initialize the sample. OnInit is defined in each child-implementation of DXSample.
            sample.OnInit();

            _ = ShowWindow(s_hwnd, nCmdShow);

            // Main sample loop.
            MSG msg;

            do
            {
                // Process any messages in the queue.
                if (PeekMessageW(out msg, IntPtr.Zero, 0, 0, PM_REMOVE) != 0)
                {
                    _ = TranslateMessage(&msg);
                    _ = DispatchMessageW(&msg);
                }
            }
            while (msg.message != WM_QUIT);

            sample.OnDestroy();

            // Return this part of the WM_QUIT message to Windows.
            return (int)msg.wParam;
        }

        // Main message handler for the sample
        private static IntPtr WindowProc(HWND hWnd, uint message, UIntPtr wParam, IntPtr lParam)
        {
            var handle = GetWindowLongPtrW(hWnd, GWLP_USERDATA);
            var pSample = (handle != IntPtr.Zero) ? (DXSample)GCHandle.FromIntPtr(handle).Target : null;

            switch (message)
            {
                case WM_CREATE:
                {
                    // Save the DXSample* passed in to CreateWindow.
                    var pCreateStruct = (CREATESTRUCTW*)lParam;
                    _ = SetWindowLongPtrW(hWnd, GWLP_USERDATA, (IntPtr)pCreateStruct->lpCreateParams);
                }
                return IntPtr.Zero;

                case WM_KEYDOWN:
                {
                    pSample?.OnKeyDown((byte)wParam);
                    return IntPtr.Zero;
                }

                case WM_KEYUP:
                {
                    pSample?.OnKeyUp((byte)wParam);
                    return IntPtr.Zero;
                }

                case WM_PAINT:
                {
                    if (pSample != null)
                    {
                        pSample.OnUpdate();
                        pSample.OnRender();
                    }
                    return IntPtr.Zero;
                }

                case WM_DESTROY:
                {
                    PostQuitMessage(0);
                    return IntPtr.Zero;
                }
            }

            // Handle any messages the switch statement didn't.
            return DefWindowProcW(hWnd, message, wParam, lParam);
        }
    }
}
