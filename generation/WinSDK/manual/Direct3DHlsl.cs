// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from um/d3d12.h in the Windows SDK for Windows 10.0.19041.0
// Original source is Copyright © Microsoft. All rights reserved.

using System;

namespace Windows.Win32.Graphics.Hlsl
{
    public static unsafe partial class Apis
    {
        public const uint D3DCOMPILE_OPTIMIZATION_LEVEL2 = (1 << 14) | (1 << 15);

        public const uint D3D_COMPILE_STANDARD_FILE_INCLUDE = 1;
    }
}
