using System;
using System.IO;
using System.Reflection;
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

