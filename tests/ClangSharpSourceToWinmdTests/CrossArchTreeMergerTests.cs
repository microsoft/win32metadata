using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.Formatting;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class CrossArchTreeMergerTests
    {
        [TestMethod]
        public void ProcessTree_MapContainsArchNativeStructs_StructsMergedAndAnnotated()
        {
            // Arrange
            using var workspace = new AdhocWorkspace();

            var x86Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    public struct LEGACY_STRUCT
                    {
                        public byte reserved;
                    }
                }
            ", path: @"C:\NUL\generated\crossarch\x86\System.cs");

            var x64Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    public struct CURRENT_STRUCT
                    {
                        public byte reserved;
                    }
                }
            ", path: @"C:\NUL\generated\crossarch\x64\System.cs");

            var arm64Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    public struct CURRENT_STRUCT
                    {
                        public byte reserved;
                    }
                }
            ", path: @"C:\NUL\generated\crossarch\arm64\System.cs");

            var map = new CrossArchSyntaxMap();
            map.AddTree(x86Tree);
            map.AddTree(x64Tree);
            map.AddTree(arm64Tree);

            var merger = new CrossArchTreeMerger(map);

            var expectedX86Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    [SupportedArchitecture(Windows.Win32.Foundation.Metadata.Architecture.X86)]
                    public struct LEGACY_STRUCT
                    {
                        public byte reserved;
                    }
                }
            ");

            var expectedX64Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    [SupportedArchitecture(Windows.Win32.Foundation.Metadata.Architecture.X64 | Windows.Win32.Foundation.Metadata.Architecture.Arm64)]
                    public struct CURRENT_STRUCT
                    {
                        public byte reserved;
                    }
                }
            ");

            // Act
            var processedX86Tree = merger.ProcessTree(x86Tree, out _);
            var processedX64Tree = merger.ProcessTree(x64Tree, out _);
            var processedArm64Tree = merger.ProcessTree(arm64Tree, out _);

            // Assert
            Assert.AreEqual(
                Formatter.Format(expectedX86Tree.GetRoot(), workspace).ToFullString(),
                Formatter.Format(processedX86Tree.GetRoot(), workspace).ToFullString()
            );

            Assert.AreEqual(
                Formatter.Format(expectedX64Tree.GetRoot(), workspace).ToFullString(),
                Formatter.Format(processedX64Tree.GetRoot(), workspace).ToFullString()
            );
        }

        [TestMethod]
        public void ProcessTree_MapContainsArchNativeEnums_EnumsMergedAndAnnotated()
        {
            // Arrange
            using var workspace = new AdhocWorkspace();

            var x86Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    public enum LEGACY_ENUM
                    {
                        A = 1
                    }
                }
            ", path: @"C:\NUL\generated\crossarch\x86\System.cs");

            var x64Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    public enum CURRENT_ENUM
                    {
                        B = 2
                    }
                }
            ", path: @"C:\NUL\generated\crossarch\x64\System.cs");

            var arm64Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    public enum CURRENT_ENUM
                    {
                        B = 2
                    }
                }
            ", path: @"C:\NUL\generated\crossarch\arm64\System.cs");

            var map = new CrossArchSyntaxMap();
            map.AddTree(x86Tree);
            map.AddTree(x64Tree);
            map.AddTree(arm64Tree);

            var merger = new CrossArchTreeMerger(map);

            var expectedX86Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    [SupportedArchitecture(Windows.Win32.Foundation.Metadata.Architecture.X86)]
                    public enum LEGACY_ENUM
                    {
                        A = 1
                    }
                }
            ");

            var expectedX64Tree = CSharpSyntaxTree.ParseText(@"
                using System;
                using Windows.Win32.Foundation.Metadata;
                using System.Runtime.InteropServices;

                namespace Windows
                {
                    [SupportedArchitecture(Windows.Win32.Foundation.Metadata.Architecture.X64 | Windows.Win32.Foundation.Metadata.Architecture.Arm64)]
                    public enum CURRENT_ENUM
                    {
                        B = 2
                    }
                }
            ");

            // Act
            var processedX86Tree = merger.ProcessTree(x86Tree, out _);
            var processedX64Tree = merger.ProcessTree(x64Tree, out _);
            var processedArm64Tree = merger.ProcessTree(arm64Tree, out _);

            // Assert
            Assert.AreEqual(
                Formatter.Format(expectedX86Tree.GetRoot(), workspace).ToFullString(),
                Formatter.Format(processedX86Tree.GetRoot(), workspace).ToFullString()
            );

            Assert.AreEqual(
                Formatter.Format(expectedX64Tree.GetRoot(), workspace).ToFullString(),
                Formatter.Format(processedX64Tree.GetRoot(), workspace).ToFullString()
            );
        }
    }
}
