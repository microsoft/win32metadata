// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from DXSampleHelper.h in https://github.com/Microsoft/DirectX-Graphics-Samples
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using Microsoft.Windows.Win32;
using static Microsoft.Windows.Win32.Apis;

namespace SampleD3DApp
{
    public static unsafe class DXSampleHelper
    {
        public static string GetAssetsPath()
        {
            var entryAssembly = Assembly.GetEntryAssembly();
            return Path.GetDirectoryName(entryAssembly.Location);
        }

        public static byte[] ReadDataFromFile(string filename)
        {
            return File.ReadAllBytes(filename);
        }

        [Conditional("DEBUG")]
        public static void SetName(ID3D12Object* pObject, string name)
        {
            pObject->SetName(name);
        }

        [Conditional("DEBUG")]
        public static void SetNameIndexed(ID3D12Object* pObject, string name, uint index)
        {
            var fullName = $"{name}[{index}]";
            SetName(pObject, fullName);
        }
    }
}
