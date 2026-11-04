using System;
using System.IO;
using System.Diagnostics;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    public interface IReferencedBase { void Base(); }
    public interface IReferencedLeft : IReferencedBase { void Left(); }
    public interface IReferencedRight : IReferencedBase { void Right(); }
    public interface IReferencedDiamond : IReferencedLeft, IReferencedRight { void Own(); }
    public interface IReferencedProperty { int Value { get; set; } event Action Changed; }

    [TestClass]
    public class NamespaceOutputTests
    {
        [DataTestMethod]
        [DataRow("Test=Other.dll")]
        [DataRow("=Other.winmd")]
        [DataRow("Test")]
        [DataRow("Test..Child=Other.winmd")]
        [DataRow("Test=Main.winmd")]
        public void InvalidRoutesAreRejected(string route)
        {
            Assert.ThrowsException<ArgumentException>(() => new NamespaceOutputs("Main.winmd", new[] { route }));
        }

        [TestMethod]
        public void OverlappingRoutesAndConflictingIdentitiesAreRejected()
        {
            Assert.ThrowsException<ArgumentException>(() => new NamespaceOutputs("Main.winmd",
                new[] { "Test=A.winmd", "Test.Child=B.winmd" }));
            Assert.ThrowsException<ArgumentException>(() => new NamespaceOutputs("Main.winmd",
                new[] { "Test=first\\A.winmd", "Other=second\\A.winmd" }));
        }

        [TestMethod]
        public void NamespaceMatchingUsesWholeSegmentsAndIncludesDescendants()
        {
            var routes = new NamespaceOutputs("Main.winmd", new[] { "Test=Other.winmd" });
            Assert.AreEqual(Path.GetFullPath("Other.winmd"), routes.GetOutput("Test"));
            Assert.AreEqual(Path.GetFullPath("Other.winmd"), routes.GetOutput("Test.Child"));
            Assert.AreEqual(routes.PrimaryOutput, routes.GetOutput("Testing"));
            var aliases = new NamespaceOutputs("Main.winmd", new[] { "One=Other.winmd", "Two=OTHER.winmd" });
            Assert.AreEqual(2, aliases.OutputPaths.Count);
            Assert.AreEqual(aliases.GetOutput("One"), aliases.GetOutput("Two"));
        }

        [TestMethod]
        public void ReferencedDiamondInterfacesAreNotMistakenForCycles()
        {
            string directory = Path.Combine(Path.GetTempPath(), "NamespaceOutputReferenceTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Source.manual.cs"), "namespace Shared { public struct Value { public int Field; } }");
                Assert.AreEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", Path.Combine(directory, "Main.winmd"),
                    "--ref", typeof(IReferencedDiamond).Assembly.Location }));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [TestMethod]
        public void ReferencedInterfaceAccessorsRetainInheritedVtableSlots()
        {
            string directory = Path.Combine(Path.GetTempPath(), "NamespaceOutputAccessorTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Source.manual.cs"), @"
using System;
using System.Runtime.InteropServices;
using Shared;
namespace Shared {
    public class NativeInheritanceAttribute : Attribute { public NativeInheritanceAttribute(string name) {} }
}
namespace Routed {
    [NativeInheritance(""IReferencedProperty"")]
    public unsafe struct Derived {
        public void** lpVtbl;
        public ClangSharpSourceToWinmdTests.IReferencedProperty Base;
        public delegate void _Own();
        public int get_Value() { Marshal.GetDelegateForFunctionPointer<_Own>((IntPtr)(lpVtbl[0]))(); return 0; }
        public void set_Value(int value) { Marshal.GetDelegateForFunctionPointer<_Own>((IntPtr)(lpVtbl[1]))(); }
        public void add_Changed(Action value) { Marshal.GetDelegateForFunctionPointer<_Own>((IntPtr)(lpVtbl[2]))(); }
        public void remove_Changed(Action value) { Marshal.GetDelegateForFunctionPointer<_Own>((IntPtr)(lpVtbl[3]))(); }
        public void Own() { Marshal.GetDelegateForFunctionPointer<_Own>((IntPtr)(lpVtbl[4]))(); }
    }
}");
                string main = Path.Combine(directory, "Main.winmd");
                string routed = Path.Combine(directory, "Routed.winmd");
                Assert.AreEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", main,
                    "--namespaceOutput", "Routed=" + routed, "--ref", typeof(IReferencedProperty).Assembly.Location }));
                using var stream = File.OpenRead(routed);
                using var pe = new PEReader(stream);
                var reader = pe.GetMetadataReader();
                var derived = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(t => reader.GetString(t.Name) == "Derived");
                var methods = derived.GetMethods().Select(h => reader.GetString(reader.GetMethodDefinition(h).Name)).ToArray();
                Assert.AreEqual("Own", string.Join(", ", methods));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [TestMethod]
        public void InputReferenceCannotCompeteWithAnOutputIdentity()
        {
            string directory = Path.Combine(Path.GetTempPath(), "NamespaceOutputConflictTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Source.manual.cs"), "namespace D3D { public struct Value { public int Field; } }");
                string existing = Path.Combine(directory, "D3D.winmd");
                Assert.AreEqual(0, Program.Main(new[] { "--sourceDir", directory, "--outputFileName", existing }));
                string main = Path.Combine(directory, "Main.winmd");
                Assert.AreNotEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", main,
                    "--namespaceOutput", "D3D=" + existing, "--ref", existing }));
                Assert.IsFalse(File.Exists(main));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [TestMethod]
        public void ReciprocalReferenceMustMatchConfiguredOutputVersion()
        {
            string directory = Path.Combine(Path.GetTempPath(), "NamespaceOutputVersionTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Source.manual.cs"),
                    "namespace Shared { public struct Consumer { public D3D.Value Value; } } namespace D3D { public struct Value { public int Field; } }");
                string windows = Path.Combine(directory, "Windows.winmd");
                string d3d = Path.Combine(directory, "D3D.winmd");
                Assert.AreEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", windows, "--namespaceOutput", "D3D=" + d3d }));
                string replacement = Path.Combine(directory, "replacement", "D3D.winmd");
                Assert.AreNotEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", replacement,
                    "--ref", windows, "--version", "2.0.0.0" }));
                Assert.IsFalse(File.Exists(replacement));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [TestMethod]
        public void CompleteCompilationRoutesDefinitionsNestedScopesAttributesAndReciprocalValueTypes()
        {
            string directory = Path.Combine(Path.GetTempPath(), "NamespaceOutputTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Source.manual.cs"), @"
using System;
namespace Shared {
    public class MarkerAttribute : Attribute { public MarkerAttribute(int value) {} }
    public struct WindowsValue { public int Value; }
    public struct Consumer { public D3D.Value Value; public D3D.Outer.Nested Nested; public D3D.Kind Kind; }
    public static partial class Apis { public const int WindowsConstant = 2; }
}
namespace D3D {
    public enum Kind { First = 1 }
    [Shared.Marker(3)] public struct Value { public Shared.WindowsValue Data; }
    public struct Outer { public Nested Value; public struct Nested { public int Value; } }
    public static partial class Apis { public const int D3DConstant = 1; }
}
namespace D3D.Child { public struct Descendant { public int Value; } }
namespace D3DExtra { public struct NotRouted { public int Value; } }
");
                string main = Path.Combine(directory, "Windows.winmd");
                string d3d = Path.Combine(directory, "D3D.winmd");
                Assert.AreEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", main,
                    "--namespaceOutput", "D3D=" + d3d }));
                using var mainStream = File.OpenRead(main);
                using var mainPe = new PEReader(mainStream);
                using var d3dStream = File.OpenRead(d3d);
                using var d3dPe = new PEReader(d3dStream);
                var windows = mainPe.GetMetadataReader();
                var routed = d3dPe.GetMetadataReader();
                Assert.IsFalse(windows.TypeDefinitions.Select(windows.GetTypeDefinition).Any(t => windows.GetString(t.Namespace) == "D3D"));
                Assert.IsTrue(windows.TypeDefinitions.Select(windows.GetTypeDefinition).Any(t => windows.GetString(t.Name) == "NotRouted"));
                Assert.IsTrue(routed.TypeDefinitions.Select(routed.GetTypeDefinition).Any(t => routed.GetString(t.Namespace) == "D3D.Child"));
                Assert.IsTrue(routed.TypeDefinitions.Select(routed.GetTypeDefinition).Any(t => routed.GetString(t.Name) == "Nested"));
                AssertScope(windows, "Value", "D3D.winmd");
                AssertScope(windows, "Kind", "D3D.winmd");
                AssertScope(routed, "WindowsValue", "Windows.winmd");
                AssertScope(routed, "MarkerAttribute", "Windows.winmd");
                var nested = windows.TypeReferences.Select(windows.GetTypeReference).Single(t => windows.GetString(t.Name) == "Nested");
                Assert.AreEqual(HandleKind.TypeReference, nested.ResolutionScope.Kind);
                var parent = windows.GetTypeReference((TypeReferenceHandle)nested.ResolutionScope);
                Assert.AreEqual("Outer", windows.GetString(parent.Name));
                Assert.AreEqual("D3D.winmd", windows.GetString(windows.GetAssemblyReference((AssemblyReferenceHandle)parent.ResolutionScope).Name));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [TestMethod]
        public void CombinedDumpMatchesMonolithicAndRejectsMissingOrMismatchedProvider()
        {
            string directory = Path.Combine(Path.GetTempPath(), "NamespaceOutputDumpTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Source.manual.cs"), @"
using System;
namespace Shared {
    public class MarkerAttribute : Attribute { public MarkerAttribute(int value) {} }
    public struct Consumer { public D3D.Value Value; }
}
namespace D3D {
    [Shared.Marker(3)] public unsafe struct Value { public Shared.Consumer* Field; }
    public static class Apis { public const int Constant = 4; }
}");
                string main = Path.Combine(directory, "Windows.winmd");
                string d3d = Path.Combine(directory, "D3D.winmd");
                string monolithic = Path.Combine(directory, "monolithic", "Windows.winmd");
                Assert.AreEqual(0, Program.Main(new[] { "--sourceDir", directory, "--outputFileName", monolithic }));
                Assert.AreEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", main, "--namespaceOutput", "D3D=" + d3d }));
                string monoDump = Path.Combine(directory, "monolithic.txt");
                string splitDump = Path.Combine(directory, "split.txt");
                AssertDump(monolithic, monoDump, 0);
                AssertDump(main, splitDump, 0);
                Assert.AreEqual(File.ReadAllText(monoDump), File.ReadAllText(splitDump));
                Assert.IsTrue(File.ReadAllText(splitDump).Contains("Constant = 4"));
                File.Move(d3d, d3d + ".backup");
                AssertDump(main, splitDump, 1);
                File.Move(d3d + ".backup", d3d);
                Assert.AreEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--outputFileName", d3d, "--version", "2.0.0.0" }));
                AssertDump(main, splitDump, 1);
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        private static void AssertDump(string input, string output, int expectedExitCode)
        {
            using var process = new Process();
            process.StartInfo = new ProcessStartInfo("dotnet")
            {
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            };
            foreach (string argument in new[] {
                Path.Combine(AppContext.BaseDirectory, "WinmdUtils.dll"), "dump", "--winmd", input,
                "--includeReferencedWinmds", "--output", output })
            {
                process.StartInfo.ArgumentList.Add(argument);
            }
            process.Start();
            var error = process.StandardError.ReadToEndAsync();
            string result = process.StandardOutput.ReadToEnd();
            process.WaitForExit();
            Assert.AreEqual(expectedExitCode, process.ExitCode, result + error.GetAwaiter().GetResult());
        }

        private static void AssertScope(MetadataReader reader, string name, string assembly)
        {
            var references = reader.TypeReferences.Select(reader.GetTypeReference).Where(t => reader.GetString(t.Name) == name).ToArray();
            Assert.IsTrue(references.Length > 0);
            foreach (var reference in references)
            {
                Assert.AreEqual(HandleKind.AssemblyReference, reference.ResolutionScope.Kind);
                var scope = reader.GetAssemblyReference((AssemblyReferenceHandle)reference.ResolutionScope);
                Assert.AreEqual(assembly, reader.GetString(scope.Name));
                Assert.AreEqual(new Version(1, 0, 0, 0), scope.Version);
            }

        }

        [TestMethod]
        public void RoutedArchitectureVariantsRetainNamesAndAttributeOwnership()
        {
            string directory = Path.Combine(Path.GetTempPath(), "NamespaceOutputArchTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "Attributes.manual.cs"), @"
using System;
namespace Windows.Win32.Foundation.Metadata {
    [Flags] public enum Architecture { None=0, X86=1, X64=2, Arm64=4, All=7 }
    public class SupportedArchitectureAttribute : Attribute { public SupportedArchitectureAttribute(Architecture architecture) {} }
}");
                foreach (string arch in new[] { "x86", "x64", "arm64" })
                {
                    Directory.CreateDirectory(Path.Combine(directory, arch));
                    File.WriteAllText(Path.Combine(directory, arch, "Source.cs"),
                        "using System; using Windows.Win32.Foundation.Metadata; namespace D3D { public enum Choice { " +
                        arch + " = 1 } public struct Value { public " + (arch == "x64" ? "long" : "int") + " Field; } }");
                }

                string main = Path.Combine(directory, "Windows.winmd");
                string output = Path.Combine(directory, "D3D.winmd");
                Assert.AreEqual(0, Program.Main(new[] {
                    "--sourceDir", directory, "--arch", "crossarch", "--outputFileName", main,
                    "--namespaceOutput", "D3D=" + output }));
                using var stream = File.OpenRead(output);
                using var pe = new PEReader(stream);
                var reader = pe.GetMetadataReader();
                Assert.AreEqual(3, reader.TypeDefinitions.Select(reader.GetTypeDefinition).Count(t => reader.GetString(t.Name) == "Choice"));
                Assert.IsTrue(reader.TypeDefinitions.Select(reader.GetTypeDefinition).All(t => !reader.GetString(t.Name).Contains("____")));
                AssertScope(reader, "SupportedArchitectureAttribute", "Windows.winmd");
                AssertScope(reader, "Architecture", "Windows.winmd");
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }
    }
}
