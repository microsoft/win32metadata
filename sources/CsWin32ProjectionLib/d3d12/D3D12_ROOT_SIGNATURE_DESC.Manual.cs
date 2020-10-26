// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using static Microsoft.Windows.Win32.D3D12_ROOT_SIGNATURE_FLAGS;

namespace Microsoft.Windows.Win32
{
    public unsafe partial struct D3D12_ROOT_SIGNATURE_DESC
    {
        public D3D12_ROOT_SIGNATURE_DESC([NativeTypeName("UINT")] uint numParameters, [NativeTypeName("const D3D12_ROOT_PARAMETER *")] D3D12_ROOT_PARAMETER* _pParameters, [NativeTypeName("UINT")] uint numStaticSamplers = 0, [NativeTypeName("const D3D12_STATIC_SAMPLER_DESC *")] D3D12_STATIC_SAMPLER_DESC* _pStaticSamplers = null, D3D12_ROOT_SIGNATURE_FLAGS flags = D3D12_ROOT_SIGNATURE_FLAG_NONE)
        {
            Init(out this, numParameters, _pParameters, numStaticSamplers, _pStaticSamplers, flags);
        }

        public static readonly D3D12_ROOT_SIGNATURE_DESC DEFAULT = new D3D12_ROOT_SIGNATURE_DESC(0, null, 0, null, D3D12_ROOT_SIGNATURE_FLAG_NONE);

        public void Init([NativeTypeName("UINT")] uint numParameters, [NativeTypeName("const D3D12_ROOT_PARAMETER *")] D3D12_ROOT_PARAMETER* _pParameters, [NativeTypeName("UINT")] uint numStaticSamplers = 0, [NativeTypeName("const D3D12_STATIC_SAMPLER_DESC *")] D3D12_STATIC_SAMPLER_DESC* _pStaticSamplers = null, D3D12_ROOT_SIGNATURE_FLAGS flags = D3D12_ROOT_SIGNATURE_FLAG_NONE)
        {
            Init(out this, numParameters, _pParameters, numStaticSamplers, _pStaticSamplers, flags);
        }

        public static void Init([NativeTypeName("D3D12_ROOT_SIGNATURE_DESC &")] out D3D12_ROOT_SIGNATURE_DESC desc, [NativeTypeName("UINT")] uint numParameters, [NativeTypeName("const D3D12_ROOT_PARAMETER *")] D3D12_ROOT_PARAMETER* _pParameters, [NativeTypeName("UINT")] uint numStaticSamplers = 0, [NativeTypeName("const D3D12_STATIC_SAMPLER_DESC *")] D3D12_STATIC_SAMPLER_DESC* _pStaticSamplers = null, D3D12_ROOT_SIGNATURE_FLAGS flags = D3D12_ROOT_SIGNATURE_FLAG_NONE)
        {
            desc.NumParameters = numParameters;
            desc.pParameters = _pParameters;
            desc.NumStaticSamplers = numStaticSamplers;
            desc.pStaticSamplers = _pStaticSamplers;
            desc.Flags = flags;
        }
    }
}
