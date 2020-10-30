// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using System;
using System.Diagnostics;
using static Microsoft.Windows.Win32.D3D_ROOT_SIGNATURE_VERSION;
using static Microsoft.Windows.Win32.D3D12_FEATURE;
using static Microsoft.Windows.Win32.D3D12_RESOURCE_DIMENSION;
using static Microsoft.Windows.Win32.D3D12_ROOT_PARAMETER_TYPE;
using static Microsoft.Windows.Win32.D3D12_TEXTURE_LAYOUT;
using static Microsoft.Windows.Win32.Apis;

namespace Microsoft.Windows.Win32
{
    public static unsafe partial class Apis
    {
        public const uint DefaultSampleMask = uint.MaxValue;

        public static readonly DXGI_SAMPLE_DESC DefaultSampleDesc = new DXGI_SAMPLE_DESC {
            Count = 1,
            Quality = 0,
        };

        public static uint D3D12CalcSubresource(uint MipSlice, uint ArraySlice, uint PlaneSlice, uint MipLevels, uint ArraySize)
        {
            return MipSlice + ArraySlice * MipLevels + PlaneSlice * MipLevels * ArraySize;
        }

        public static void D3D12DecomposeSubresource(uint Subresource, uint MipLevels, uint ArraySize, out uint MipSlice, out uint ArraySlice, out uint PlaneSlice)
        {
            MipSlice = Subresource % MipLevels;
            ArraySlice = (Subresource / MipLevels) % ArraySize;
            PlaneSlice = Subresource / (MipLevels * ArraySize);
        }

        public static byte D3D12GetFormatPlaneCount(ID3D12Device* pDevice, DXGI_FORMAT Format)
        {
            D3D12_FEATURE_DATA_FORMAT_INFO formatInfo = new D3D12_FEATURE_DATA_FORMAT_INFO
            {
                Format = Format,
                PlaneCount = 0,
            };

            if (FAILED(pDevice->CheckFeatureSupport(D3D12_FEATURE_FORMAT_INFO, &formatInfo, (uint)sizeof(D3D12_FEATURE_DATA_FORMAT_INFO))))
            {
                return 0;
            }

            return formatInfo.PlaneCount;
        }

        public static void MemcpySubresource(D3D12_MEMCPY_DEST* pDest, D3D12_SUBRESOURCE_DATA* pSrc, uint RowSizeInBytes, uint NumRows, uint NumSlices)
        {
            for (var z = 0u; z < NumSlices; ++z)
            {
                var pDestSlice = (byte*)pDest->pData + pDest->SlicePitch.ToUInt32() * z;
                var pSrcSlice = (byte*)pSrc->pData + pSrc->SlicePitch.ToInt32() * (int)z;

                for (var y = 0u; y < NumRows; ++y)
                {
                    Buffer.MemoryCopy(
                        pSrcSlice + pSrc->RowPitch.ToInt32() * (int)y,
                        pDestSlice + pDest->RowPitch.ToUInt32() * y,
                        (ulong)RowSizeInBytes,
                        (ulong)RowSizeInBytes
                    );
                }
            }
        }

        public static ulong GetRequiredIntermediateSize(ID3D12Resource* pDestinationResource, uint FirstSubresource, uint NumSubresources)
        {
            var Desc = pDestinationResource->GetDesc();
            ulong RequiredSize = 0;

            ComPtr<ID3D12Device> pDevice;
            var iid = IID_ID3D12Device;

            pDestinationResource->GetDevice(&iid, out pDevice);
            pDevice.Get()->GetCopyableFootprints(&Desc, FirstSubresource, NumSubresources, 0, null, null, null, &RequiredSize);
            pDevice.Dispose();
            return RequiredSize;
        }

        public static ulong UpdateSubresources(ID3D12GraphicsCommandList* pCmdList, ID3D12Resource* pDestinationResource, ID3D12Resource* pIntermediate, uint FirstSubresource, uint NumSubresources, ulong RequiredSize, D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts, uint* pNumRows, ulong* pRowSizesInBytes, D3D12_SUBRESOURCE_DATA* pSrcData)
        {
            var IntermediateDesc = pIntermediate->GetDesc();
            var DestinationDesc = pDestinationResource->GetDesc();

            if (IntermediateDesc.Dimension != D3D12_RESOURCE_DIMENSION_BUFFER || IntermediateDesc.Width < RequiredSize + pLayouts[0].Offset || RequiredSize > unchecked((ulong)(-1)) || (DestinationDesc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER && (FirstSubresource != 0 || NumSubresources != 1)))
            {
                return 0;
            }

            byte* pData;
            int hr = pIntermediate->Map(0, null, (void**)&pData);

            if (FAILED(hr))
            {
                return 0;
            }

            for (var i = 0u; i < NumSubresources; ++i)
            {
                if (pRowSizesInBytes[i] > unchecked((ulong)(-1)))
                    return 0;

                D3D12_MEMCPY_DEST DestData = new D3D12_MEMCPY_DEST
                {
                    pData = pData + pLayouts[i].Offset,
                    RowPitch = new UIntPtr(pLayouts[i].Footprint.RowPitch),
                    SlicePitch = new UIntPtr(pLayouts[i].Footprint.RowPitch * pNumRows[i])
                };

                MemcpySubresource(&DestData, &pSrcData[i], (uint)pRowSizesInBytes[i], pNumRows[i], pLayouts[i].Footprint.Depth);
            }
            pIntermediate->Unmap(0, null);

            if (DestinationDesc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
            {
                pCmdList->CopyBufferRegion(pDestinationResource, 0, pIntermediate, pLayouts[0].Offset, pLayouts[0].Footprint.Width);
            }
            else
            {
                for (var i = 0u; i < NumSubresources; ++i)
                {
                    D3D12_TEXTURE_COPY_LOCATION Dst = new D3D12_TEXTURE_COPY_LOCATION(pDestinationResource, i + FirstSubresource);
                    D3D12_TEXTURE_COPY_LOCATION Src = new D3D12_TEXTURE_COPY_LOCATION(pIntermediate, pLayouts[i]);
                    pCmdList->CopyTextureRegion(&Dst, 0, 0, 0, &Src, null);
                }
            }
            return RequiredSize;
        }

#if FixMe
        // 
        public static ulong UpdateSubresources([NativeTypeName("ID3D12GraphicsCommandList *")] ID3D12GraphicsCommandList* pCmdList, [NativeTypeName("ID3D12Resource *")] ID3D12Resource* pDestinationResource, [NativeTypeName("ID3D12Resource *")] ID3D12Resource* pIntermediate, [NativeTypeName("UINT64")] ulong IntermediateOffset, [NativeTypeName("UINT")] uint FirstSubresource, [NativeTypeName("UINT")] uint NumSubresources, [NativeTypeName("D3D12_SUBRESOURCE_DATA *")] D3D12_SUBRESOURCE_DATA* pSrcData)
        {
            ulong RequiredSize = 0;
            ulong MemToAlloc = (ulong)(sizeof(D3D12_PLACED_SUBRESOURCE_FOOTPRINT) + sizeof(uint) + sizeof(ulong)) * NumSubresources;

            if (MemToAlloc > unchecked((ulong)(-1)))
            {
                return 0;
            }

            var pMem = HeapAlloc(GetProcessHeap(), 0, new UIntPtr(MemToAlloc));

            if (pMem == null)
            {
                return 0;
            }

            var pLayouts = (D3D12_PLACED_SUBRESOURCE_FOOTPRINT*)pMem;
            ulong* pRowSizesInBytes = (ulong*)(pLayouts + NumSubresources);
            uint* pNumRows = (uint*)(pRowSizesInBytes + NumSubresources);

            var Desc = pDestinationResource->GetDesc();

            ID3D12Device* pDevice = null;
            var iid = IID_ID3D12Device;

            pDestinationResource->GetDevice(&iid, (void**)&pDevice);
            pDevice->GetCopyableFootprints(&Desc, FirstSubresource, NumSubresources, IntermediateOffset, pLayouts, pNumRows, pRowSizesInBytes, &RequiredSize);
            pDevice->Release();

            ulong Result = UpdateSubresources(pCmdList, pDestinationResource, pIntermediate, FirstSubresource, NumSubresources, RequiredSize, pLayouts, pNumRows, pRowSizesInBytes, pSrcData);
            HeapFree(GetProcessHeap(), 0, pMem);
            return Result;
        }

        public static ulong UpdateSubresources([NativeTypeName("UINT")] uint MaxSubresources, [NativeTypeName("ID3D12GraphicsCommandList *")] ID3D12GraphicsCommandList* pCmdList, [NativeTypeName("ID3D12Resource *")] ID3D12Resource* pDestinationResource, [NativeTypeName("ID3D12Resource *")] ID3D12Resource* pIntermediate, [NativeTypeName("UINT64")] ulong IntermediateOffset, [NativeTypeName("UINT")] uint FirstSubresource, [NativeTypeName("UINT")] uint NumSubresources, [NativeTypeName("D3D12_SUBRESOURCE_DATA *")] D3D12_SUBRESOURCE_DATA* pSrcData)
        {
            ulong RequiredSize = 0;
            D3D12_PLACED_SUBRESOURCE_FOOTPRINT* Layouts = stackalloc D3D12_PLACED_SUBRESOURCE_FOOTPRINT[(int)MaxSubresources];
            uint* NumRows = stackalloc uint[(int)MaxSubresources];
            ulong* RowSizesInBytes = stackalloc ulong[(int)MaxSubresources];

            var Desc = pDestinationResource->GetDesc();

            ID3D12Device* pDevice = null;
            var iid = IID_ID3D12Device;

            pDestinationResource->GetDevice(&iid, (void**)&pDevice);
            pDevice->GetCopyableFootprints(&Desc, FirstSubresource, NumSubresources, IntermediateOffset, Layouts, NumRows, RowSizesInBytes, &RequiredSize);
            pDevice->Release();

            return UpdateSubresources(pCmdList, pDestinationResource, pIntermediate, FirstSubresource, NumSubresources, RequiredSize, Layouts, NumRows, RowSizesInBytes, pSrcData);
        }
#endif

        public static bool D3D12IsLayoutOpaque(D3D12_TEXTURE_LAYOUT Layout)
        {
            return Layout == D3D12_TEXTURE_LAYOUT_UNKNOWN || Layout == D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE;
        }

        [return: NativeTypeName("ID3D12CommandList * const *")]
        public static ID3D12CommandList** CommandListCast([NativeTypeName("ID3D12GraphicsCommandList * const *")] ID3D12GraphicsCommandList** pp)
        {
            return (ID3D12CommandList**)pp;
        }

        [return: NativeTypeName("HRESULT")]
        public static int D3D12SerializeVersionedRootSignature([NativeTypeName("const D3D12_VERSIONED_ROOT_SIGNATURE_DESC *")] D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION MaxVersion, [NativeTypeName("ID3DBlob **")] out ID3DBlob* ppBlob, [NativeTypeName("ID3DBlob **")] ID3DBlob** ppErrorBlob)
        {
            if (ppErrorBlob != null)
            {
                *ppErrorBlob = null;
            }

            ppBlob = null;
            switch (MaxVersion)
            {
                case D3D_ROOT_SIGNATURE_VERSION_1_0:
                    switch (pRootSignatureDesc->Version)
                    {
                        case D3D_ROOT_SIGNATURE_VERSION_1_0:
                            return D3D12SerializeRootSignature(&pRootSignatureDesc->Anonymous.Desc_1_0, D3D_ROOT_SIGNATURE_VERSION_1, out ppBlob, ppErrorBlob);

                        case D3D_ROOT_SIGNATURE_VERSION_1_1:
                        {
                            int hr = S_OK;
                            ref readonly D3D12_ROOT_SIGNATURE_DESC1 desc_1_1 = ref pRootSignatureDesc->Anonymous.Desc_1_1;

                            uint ParametersSize = (uint)sizeof(D3D12_ROOT_PARAMETER) * desc_1_1.NumParameters;
                            void* pParameters = ((ulong)ParametersSize > 0) ? HeapAlloc(GetProcessHeap(), 0, new UIntPtr(ParametersSize)) : null;

                            if ((ulong)ParametersSize > 0 && pParameters == null)
                            {
                                hr = E_OUTOFMEMORY;
                            }

                            var pParameters_1_0 = (D3D12_ROOT_PARAMETER*)pParameters;

                            if (SUCCEEDED(hr))
                            {
                                for (uint n = 0; n < desc_1_1.NumParameters; n++)
                                {
                                    Debug.Assert((long)ParametersSize == (sizeof(D3D12_ROOT_PARAMETER) * desc_1_1.NumParameters));

                                    pParameters_1_0[n].ParameterType = desc_1_1.pParameters[n].ParameterType;
                                    pParameters_1_0[n].ShaderVisibility = desc_1_1.pParameters[n].ShaderVisibility;

                                    switch (desc_1_1.pParameters[n].ParameterType)
                                    {
                                        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
                                            pParameters_1_0[n].Anonymous.Constants.Num32BitValues = desc_1_1.pParameters[n].Anonymous.Constants.Num32BitValues;
                                            pParameters_1_0[n].Anonymous.Constants.RegisterSpace = desc_1_1.pParameters[n].Anonymous.Constants.RegisterSpace;
                                            pParameters_1_0[n].Anonymous.Constants.ShaderRegister = desc_1_1.pParameters[n].Anonymous.Constants.ShaderRegister;
                                            break;

                                        case D3D12_ROOT_PARAMETER_TYPE_CBV:
                                        case D3D12_ROOT_PARAMETER_TYPE_SRV:
                                        case D3D12_ROOT_PARAMETER_TYPE_UAV:
                                            pParameters_1_0[n].Anonymous.Descriptor.RegisterSpace = desc_1_1.pParameters[n].Anonymous.Descriptor.RegisterSpace;
                                            pParameters_1_0[n].Anonymous.Descriptor.ShaderRegister = desc_1_1.pParameters[n].Anonymous.Descriptor.ShaderRegister;
                                            break;

                                        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
                                            ref readonly D3D12_ROOT_DESCRIPTOR_TABLE1 table_1_1 = ref desc_1_1.pParameters[n].Anonymous.DescriptorTable;

                                            uint DescriptorRangesSize = (uint)sizeof(D3D12_DESCRIPTOR_RANGE) * table_1_1.NumDescriptorRanges;
                                            void* pDescriptorRanges = ((ulong)DescriptorRangesSize > 0 && SUCCEEDED(hr)) ? HeapAlloc(GetProcessHeap(), 0, new UIntPtr(DescriptorRangesSize)) : null;

                                            if ((ulong)DescriptorRangesSize > 0 && pDescriptorRanges == null)
                                            {
                                                hr = E_OUTOFMEMORY;
                                            }

                                            var pDescriptorRanges_1_0 = (D3D12_DESCRIPTOR_RANGE*)pDescriptorRanges;

                                            if (SUCCEEDED(hr))
                                            {
                                                for (uint x = 0; x < table_1_1.NumDescriptorRanges; x++)
                                                {
                                                    Debug.Assert((long)DescriptorRangesSize == (sizeof(D3D12_DESCRIPTOR_RANGE) * table_1_1.NumDescriptorRanges));

                                                    pDescriptorRanges_1_0[x].BaseShaderRegister = table_1_1.pDescriptorRanges[x].BaseShaderRegister;
                                                    pDescriptorRanges_1_0[x].NumDescriptors = table_1_1.pDescriptorRanges[x].NumDescriptors;
                                                    pDescriptorRanges_1_0[x].OffsetInDescriptorsFromTableStart = table_1_1.pDescriptorRanges[x].OffsetInDescriptorsFromTableStart;
                                                    pDescriptorRanges_1_0[x].RangeType = table_1_1.pDescriptorRanges[x].RangeType;
                                                    pDescriptorRanges_1_0[x].RegisterSpace = table_1_1.pDescriptorRanges[x].RegisterSpace;
                                                }
                                            }

                                            ref D3D12_ROOT_DESCRIPTOR_TABLE table_1_0 = ref pParameters_1_0[n].Anonymous.DescriptorTable;
                                            table_1_0.NumDescriptorRanges = table_1_1.NumDescriptorRanges;
                                            table_1_0.pDescriptorRanges = pDescriptorRanges_1_0;
                                            break;
                                    }
                                }
                            }

                            if (SUCCEEDED(hr))
                            {
                                D3D12_ROOT_SIGNATURE_DESC desc_1_0 = new D3D12_ROOT_SIGNATURE_DESC(desc_1_1.NumParameters, pParameters_1_0, desc_1_1.NumStaticSamplers, desc_1_1.pStaticSamplers, desc_1_1.Flags);
                                hr = D3D12SerializeRootSignature(&desc_1_0, D3D_ROOT_SIGNATURE_VERSION_1, out ppBlob, ppErrorBlob);
                            }

                            if (pParameters != null)
                            {
                                for (uint n = 0; n < desc_1_1.NumParameters; n++)
                                {
                                    if (desc_1_1.pParameters[n].ParameterType == D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE)
                                    {
                                        HeapFree(GetProcessHeap(), 0, (void*)pParameters_1_0[n].Anonymous.DescriptorTable.pDescriptorRanges);
                                    }
                                }

                                HeapFree(GetProcessHeap(), 0, pParameters);
                            }

                            return hr;
                        }
                    }
                    break;

                case D3D_ROOT_SIGNATURE_VERSION_1_1:
                    return Apis.D3D12SerializeVersionedRootSignature(pRootSignatureDesc, out ppBlob, ppErrorBlob);
            }

            return E_INVALIDARG;
        }
    }
}
