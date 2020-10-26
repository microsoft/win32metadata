// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using static Microsoft.Windows.Win32.D3D12_CULL_MODE;
using static Microsoft.Windows.Win32.D3D12_FILL_MODE;
using static Microsoft.Windows.Win32.D3D12_CONSERVATIVE_RASTERIZATION_MODE;
using static Microsoft.Windows.Win32.Apis;

namespace Microsoft.Windows.Win32
{
    public partial struct D3D12_RASTERIZER_DESC
    {
        public static readonly D3D12_RASTERIZER_DESC DEFAULT = new D3D12_RASTERIZER_DESC {
            FillMode = D3D12_FILL_MODE_SOLID,
            CullMode = D3D12_CULL_MODE_BACK,
            FrontCounterClockwise = FALSE,
            DepthBias = D3D12_DEFAULT_DEPTH_BIAS,
            DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP,
            SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS,
            DepthClipEnable = TRUE,
            MultisampleEnable = FALSE,
            AntialiasedLineEnable = FALSE,
            ForcedSampleCount = 0,
            ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF,
        };

        public D3D12_RASTERIZER_DESC(D3D12_FILL_MODE fillMode, D3D12_CULL_MODE cullMode, int frontCounterClockwise, int depthBias, float depthBiasClamp, float slopeScaledDepthBias, int depthClipEnable, int multisampleEnable, int antialiasedLineEnable, uint forcedSampleCount, D3D12_CONSERVATIVE_RASTERIZATION_MODE conservativeRaster)
        {
            FillMode = fillMode;
            CullMode = cullMode;
            FrontCounterClockwise = frontCounterClockwise;
            DepthBias = depthBias;
            DepthBiasClamp = depthBiasClamp;
            SlopeScaledDepthBias = slopeScaledDepthBias;
            DepthClipEnable = depthClipEnable;
            MultisampleEnable = multisampleEnable;
            AntialiasedLineEnable = antialiasedLineEnable;
            ForcedSampleCount = forcedSampleCount;
            ConservativeRaster = conservativeRaster;
        }
    }
}
