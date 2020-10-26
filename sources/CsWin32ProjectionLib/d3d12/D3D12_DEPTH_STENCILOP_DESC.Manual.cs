// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using static Microsoft.Windows.Win32.D3D12_COMPARISON_FUNC;
using static Microsoft.Windows.Win32.D3D12_STENCIL_OP;

namespace Microsoft.Windows.Win32
{
    public partial struct D3D12_DEPTH_STENCILOP_DESC
    {
        public static readonly D3D12_DEPTH_STENCILOP_DESC DEFAULT = new D3D12_DEPTH_STENCILOP_DESC {
            StencilFailOp = D3D12_STENCIL_OP_KEEP,
            StencilDepthFailOp = D3D12_STENCIL_OP_KEEP,
            StencilPassOp = D3D12_STENCIL_OP_KEEP,
            StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS
        };
    }
}
