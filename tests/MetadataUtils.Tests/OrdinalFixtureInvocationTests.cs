using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.PortableExecutable;
using System.Runtime.InteropServices;
using TestCommon;
using Xunit;

namespace MetadataUtils.Tests
{
    // Calls the synthetic fixture DLL the way generated bindings do, to show why the entry point must be "#ordinal".
    public class OrdinalFixtureInvocationTests
    {
        private const string Library = "OrdinalFixture";

        static OrdinalFixtureInvocationTests()
        {
            NativeLibrary.SetDllImportResolver(typeof(OrdinalFixtureInvocationTests).Assembly, (name, assembly, searchPath) =>
                name == Library
                    ? NativeLibrary.Load(FixtureDllPath)
                    : IntPtr.Zero);
        }

        private static readonly string HostArch = RuntimeInformation.ProcessArchitecture switch
        {
            System.Runtime.InteropServices.Architecture.X64 => "x64",
            System.Runtime.InteropServices.Architecture.Arm64 => "arm64",
            _ => null,
        };

        private static string FixtureDllPath => Path.Combine(TestUtils.GetAssetDir(), HostArch ?? "x64", "ordinalfixture.dll");

        private static bool CanRun => OperatingSystem.IsWindows() && HostArch != null;

        [DllImport(Library, EntryPoint = "FixtureByName", ExactSpelling = true)]
        private static extern int CallByName(int value);

        [DllImport(Library, EntryPoint = "#7", ExactSpelling = true)]
        private static extern int CallByOrdinal(int value);

        [DllImport(Library, EntryPoint = "FixtureByOrdinal", ExactSpelling = true)]
        private static extern int CallOrdinalOnlyExportByName(int value);

        [DllImport(Library, EntryPoint = "FixtureNamedWithOrdinal", ExactSpelling = true)]
        private static extern int CallNamedWithOrdinalByName(int value);

        [DllImport(Library, EntryPoint = "#9", ExactSpelling = true)]
        private static extern int CallNamedWithOrdinalByOrdinal(int value);

        [Fact]
        public void NamedExportWithOrdinal_SucceedsByNameAndByOrdinal()
        {
            if (!CanRun) return;

            Assert.Equal(11, CallNamedWithOrdinalByName(1));
            Assert.Equal(11, CallNamedWithOrdinalByOrdinal(1));
        }

        [Fact]
        public void DllExports_ListsOnlyNamedExports()
        {
            var names = DllExports.GetNamedExports(FixtureDllPath);

            Assert.Contains("FixtureByName", names);
            Assert.Contains("FixtureNamedWithOrdinal", names);
            Assert.DoesNotContain("FixtureByOrdinal", names);
        }

        [Fact]
        public void DllExports_ListsOnlyPopulatedUnnamedOrdinals()
        {
            var ordinals = DllExports.GetOrdinalOnlyExports(FixtureDllPath);

            Assert.Equal(new ushort[] { 7 }, ordinals.OrderBy(ordinal => ordinal));
        }

        [Fact]
        public void DllExports_HandlesExportTableWithoutNames()
        {
            byte[] image = File.ReadAllBytes(FixtureDllPath);
            using var stream = new MemoryStream(image);
            using var pe = new PEReader(stream);
            int rva = pe.PEHeaders.PEHeader!.ExportTableDirectory.RelativeVirtualAddress;
            var section = pe.PEHeaders.SectionHeaders.Single(s => rva >= s.VirtualAddress && rva < s.VirtualAddress + s.VirtualSize);
            int offset = rva - section.VirtualAddress + section.PointerToRawData;
            Array.Clear(image, offset + 24, 4);
            Array.Clear(image, offset + 32, 8);
            string path = Path.Combine(Path.GetTempPath(), $"unnamed-{Guid.NewGuid():N}.dll");
            try
            {
                File.WriteAllBytes(path, image);
                Assert.Empty(DllExports.GetNamedExports(path));
                var ordinals = DllExports.GetOrdinalOnlyExports(path);
                Assert.Equal(3, ordinals.Count);
                Assert.Contains((ushort)7, ordinals);
                Assert.Contains((ushort)9, ordinals);
            }
            finally
            {
                File.Delete(path);
            }
        }

        [Fact]
        public void NamedImport_Succeeds()
        {
            if (!CanRun) return;

            Assert.Equal(2, CallByName(1));
        }

        [Fact]
        public void OrdinalOnlyExport_SucceedsWhenImportedByOrdinal()
        {
            if (!CanRun) return;

            Assert.Equal(101, CallByOrdinal(1));
        }

        [Fact]
        public void OrdinalOnlyExport_FailsWhenImportedByName()
        {
            if (!CanRun) return;

            Assert.Throws<EntryPointNotFoundException>(() => CallOrdinalOnlyExportByName(1));
        }
    }
}
