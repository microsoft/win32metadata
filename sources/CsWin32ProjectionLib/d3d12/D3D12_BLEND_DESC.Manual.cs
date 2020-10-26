// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using static Microsoft.Windows.Win32.Apis;

namespace Microsoft.Windows.Win32
{
    public unsafe partial struct D3D12_BLEND_DESC
    {
        public static readonly D3D12_BLEND_DESC DEFAULT = new D3D12_BLEND_DESC {
            AlphaToCoverageEnable = FALSE,
            IndependentBlendEnable = FALSE,
            RenderTarget = new _RenderTarget_e__FixedBuffer() {
                e0 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT,
                e1 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT,
                e2 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT,
                e3 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT,
                e4 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT,
                e5 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT,
                e6 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT,
                e7 = D3D12_RENDER_TARGET_BLEND_DESC.DEFAULT
            }
        };
    }
}
