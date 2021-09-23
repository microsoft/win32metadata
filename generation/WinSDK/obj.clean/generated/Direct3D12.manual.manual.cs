// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from um/d3d12.h in the Windows SDK for Windows 10.0.19041.0
// Original source is Copyright © Microsoft. All rights reserved.

using System;
using static Windows.Win32.Graphics.Direct3D12.D3D12_FILTER_REDUCTION_TYPE;
using static Windows.Win32.Graphics.Direct3D12.D3D12_FILTER_TYPE;

namespace Windows.Win32.Graphics.Direct3D12
{
    public static unsafe partial class Apis
    {
        public const uint D3D12_SHADER_COMPONENT_MAPPING_ALWAYS_SET_BIT_AVOIDING_ZEROMEM_MISTAKES = 1 << (unchecked((int)D3D12_SHADER_COMPONENT_MAPPING_SHIFT) * 4);

        public const uint D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING = 0x1688;
    }
}
