// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

using Microsoft.Windows.Win32;
using static Microsoft.Windows.Win32.Apis;
using static Microsoft.Windows.Win32.D3D_FEATURE_LEVEL;

namespace SampleD3DApp
{
    public abstract unsafe class DX12Sample : DXSample
    {
        protected DX12Sample(uint width, uint height, string name) : base(width, height, name)
        {
        }

        protected override unsafe bool SupportsRequiredDirect3DVersion(IDXGIAdapter1* adapter)
        {
            var iid = IID_ID3D12Device;
            return SUCCEEDED(D3D12CreateDevice((IUnknown*)adapter, D3D_FEATURE_LEVEL_11_0, &iid, null));
        }
    }
}
