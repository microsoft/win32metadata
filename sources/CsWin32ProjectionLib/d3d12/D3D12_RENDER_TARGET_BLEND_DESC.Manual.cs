// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using static Microsoft.Windows.Win32.D3D12_BLEND;
using static Microsoft.Windows.Win32.D3D12_BLEND_OP;
using static Microsoft.Windows.Win32.D3D12_COLOR_WRITE_ENABLE;
using static Microsoft.Windows.Win32.D3D12_LOGIC_OP;
using static Microsoft.Windows.Win32.Apis;

namespace Microsoft.Windows.Win32
{
    public unsafe partial struct D3D12_RENDER_TARGET_BLEND_DESC
    {
        public static readonly D3D12_RENDER_TARGET_BLEND_DESC DEFAULT = new D3D12_RENDER_TARGET_BLEND_DESC() {
            BlendEnable = FALSE,
            LogicOpEnable = FALSE,
            SrcBlend = D3D12_BLEND_ONE,
            DestBlend = D3D12_BLEND_ZERO,
            BlendOp = D3D12_BLEND_OP_ADD,
            SrcBlendAlpha = D3D12_BLEND_ONE,
            DestBlendAlpha = D3D12_BLEND_ZERO,
            BlendOpAlpha = D3D12_BLEND_OP_ADD,
            LogicOp = D3D12_LOGIC_OP_NOOP,
            RenderTargetWriteMask = (byte)D3D12_COLOR_WRITE_ENABLE_ALL
        };
    }
}
