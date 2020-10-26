// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from d3dx12.h in DirectX-Graphics-Samples commit a7a87f1853b5540f10920518021d91ae641033fb
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using System;
using static Microsoft.Windows.Win32.D3D12_CPU_PAGE_PROPERTY;
using static Microsoft.Windows.Win32.D3D12_HEAP_TYPE;
using static Microsoft.Windows.Win32.D3D12_MEMORY_POOL;

namespace Microsoft.Windows.Win32
{
    public partial struct D3D12_HEAP_PROPERTIES : IEquatable<D3D12_HEAP_PROPERTIES>
    {
        public D3D12_HEAP_PROPERTIES(D3D12_CPU_PAGE_PROPERTY cpuPageProperty, D3D12_MEMORY_POOL memoryPoolPreference, uint creationNodeMask = 1, uint nodeMask = 1)
        {
            Type = D3D12_HEAP_TYPE_CUSTOM;
            CPUPageProperty = cpuPageProperty;
            MemoryPoolPreference = memoryPoolPreference;
            CreationNodeMask = creationNodeMask;
            VisibleNodeMask = nodeMask;
        }

        public D3D12_HEAP_PROPERTIES(D3D12_HEAP_TYPE type, uint creationNodeMask = 1, uint nodeMask = 1)
        {
            Type = type;
            CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
            MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
            CreationNodeMask = creationNodeMask;
            VisibleNodeMask = nodeMask;
        }

        public bool IsCPUAccessible
        {
            get
            {
                return Type == D3D12_HEAP_TYPE_UPLOAD || Type == D3D12_HEAP_TYPE_READBACK || (Type == D3D12_HEAP_TYPE_CUSTOM && (CPUPageProperty == D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE || CPUPageProperty == D3D12_CPU_PAGE_PROPERTY_WRITE_BACK));
            }
        }

        public static bool operator ==(in D3D12_HEAP_PROPERTIES l, in D3D12_HEAP_PROPERTIES r)
        {
            return l.Type == r.Type && l.CPUPageProperty == r.CPUPageProperty && l.MemoryPoolPreference == r.MemoryPoolPreference && l.CreationNodeMask == r.CreationNodeMask && l.VisibleNodeMask == r.VisibleNodeMask;
        }

        public static bool operator !=(in D3D12_HEAP_PROPERTIES l, in D3D12_HEAP_PROPERTIES r)
        {
            return !(l == r);
        }

        public override bool Equals(object obj) => (obj is D3D12_HEAP_PROPERTIES other) && Equals(other);

        public bool Equals(D3D12_HEAP_PROPERTIES other) => this == other;

        //public override int GetHashCode() => HashCode.Combine(Type, CPUPageProperty, MemoryPoolPreference, CreationNodeMask, VisibleNodeMask);
        public override int GetHashCode() => $"{Type},{CPUPageProperty},{MemoryPoolPreference},{CreationNodeMask},{VisibleNodeMask}".GetHashCode();
    }
}
