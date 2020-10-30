// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from DXSample.h in https://github.com/Microsoft/DirectX-Graphics-Samples
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using System;
using System.IO;
using Microsoft.Windows.Win32;
using static Microsoft.Windows.Win32.Apis;

namespace SampleD3DApp
{
    public abstract unsafe class DXSample : IDisposable
    {
        protected DXSample(uint width, uint height, string name)
        {
            this.Width = width;
            this.Height = height;
            this.Title = name;
            this.AssetsPath = DXSampleHelper.GetAssetsPath();
        }

        ~DXSample()
        {
            Dispose(isDisposing: false);
        }

        public uint Width { get; private set; }

        public uint Height { get; private set; }

        public float AspectRatio => (float)this.Width / (float)this.Height;

        public bool UseWarpDevice { get; private set; }

        public string AssetsPath { get; }

        public string Title { get; private set; }

        public void Dispose()
        {
            Dispose(isDisposing: true);
            GC.SuppressFinalize(this);
        }

        public virtual void OnResize(uint width, uint height)
        {
            this.Width = width;
            this.Height = height;
        }

        public abstract void OnInit();

        public abstract void OnUpdate();

        public abstract void OnRender();

        public abstract void OnDestroy();

        // Samples override the event handlers to handle specific messages
        public virtual void OnKeyDown(byte key)
        {
        }

        public virtual void OnKeyUp(byte key)
        {
        }

        // Helper function for parsing any supplied command line args.
        public void ParseCommandLineArgs(string[] args)
        {
            foreach (var arg in args)
            {
                if (Program.Matches(arg, "warp"))
                {
                    this.UseWarpDevice = true;
                    this.Title += " (WARP)";
                }
            }
        }

        protected virtual void Dispose(bool isDisposing)
        {
        }

        // Helper function for resolving the full path of assets
        protected string GetAssetFullPath(string assetName) => Path.Combine(AssetsPath, assetName);

        // Helper function for acquiring the first available hardware adapter that supports the required Direct3D version.
        // If no such adapter can be found, returns null.
        protected ComPtr<IUnknown> GetHardwareAdapter(IDXGIFactory1* pFactory)
        {
            ComPtr<IDXGIAdapter1> adapter;

            for (var adapterIndex = 0u; DXGI_ERROR_NOT_FOUND != pFactory->EnumAdapters1(adapterIndex, out adapter); ++adapterIndex)
            {
                DXGI_ADAPTER_DESC1 desc;
                _ = adapter.Get()->GetDesc1(out desc);

                if ((desc.Flags & (uint)DXGI_ADAPTER_FLAG.DXGI_ADAPTER_FLAG_SOFTWARE) != 0)
                {
                    // Don't select the Basic Render Driver adapter.
                    // If you want a software adapter, pass in "/warp" on the command line.
                    continue;
                }

                // Check to see if the adapter supports the required Direct3D version, but don't create the
                // actual device yet.
                if (SupportsRequiredDirect3DVersion(adapter))
                {
                    break;
                }

                adapter.Dispose();
            }

            return new ComPtr<IUnknown>(adapter.Detach());
        }

        protected abstract bool SupportsRequiredDirect3DVersion(IDXGIAdapter1* adapter);

        // Helper function for setting the window's title text.
        protected void SetCustomWindowText(string text)
        {
            string windowText = $"{this.Title}: {text}";
            
            _ = SetWindowTextW(Win32Application.Hwnd, windowText);
        }
    }
}
