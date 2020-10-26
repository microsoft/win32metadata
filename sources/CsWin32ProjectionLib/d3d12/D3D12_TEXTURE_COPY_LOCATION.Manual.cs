// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using static Microsoft.Windows.Win32.D3D12_TEXTURE_COPY_TYPE;

namespace Microsoft.Windows.Win32
{
    public unsafe partial struct D3D12_TEXTURE_COPY_LOCATION
    {
        public D3D12_TEXTURE_COPY_LOCATION([NativeTypeName("ID3D12Resource *")] ID3D12Resource* pRes)
        {
            this = default;

            pResource = pRes;
            Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
            Anonymous.PlacedFootprint = new D3D12_PLACED_SUBRESOURCE_FOOTPRINT();
        }

        public D3D12_TEXTURE_COPY_LOCATION([NativeTypeName("ID3D12Resource *")] ID3D12Resource* pRes, [NativeTypeName("D3D12_PLACED_SUBRESOURCE_FOOTPRINT const &")] in D3D12_PLACED_SUBRESOURCE_FOOTPRINT Footprint)
        {
            this = default;

            pResource = pRes;
            Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
            Anonymous.PlacedFootprint = Footprint;
        }
        public D3D12_TEXTURE_COPY_LOCATION([NativeTypeName("ID3D12Resource *")] ID3D12Resource* pRes, uint Sub)
        {
            this = default;

            pResource = pRes;
            Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
            Anonymous.PlacedFootprint = new D3D12_PLACED_SUBRESOURCE_FOOTPRINT();
            Anonymous.SubresourceIndex = Sub;
        }
    }
}
