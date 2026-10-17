using System;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using System.CommandLine.IO;
using Xunit;

namespace MetadataUtils.Tests
{
    public class WinmdComparisonTests
    {
        private const string Source = @"
using System;
using System.Runtime.InteropServices;
namespace Fixture
{
    [AttributeUsage(AttributeTargets.ReturnValue, AllowMultiple = true)]
    public sealed class InvalidHandleValueAttribute : Attribute
    {
        public InvalidHandleValueAttribute(long value) { }
    }
    [StructLayout(LayoutKind.Sequential)]
    public struct Record { public int first; public short second; }
    [StructLayout(LayoutKind.Explicit, Size = 16)]
    public struct ExplicitRecord
    {
        [FieldOffset(0)] public int first;
        [FieldOffset(8)] public short second;
    }
    public interface IContract { void First(int value); void Second(short value); }
    public interface IAlternate { void First(int value); void Second(short value); }
    public interface IDerived : IContract { }
    public static unsafe class Apis
    {
        public const int VALUE = 1;
        [DllImport(""fixture.dll"", EntryPoint = ""NativeCompute"", CallingConvention = CallingConvention.StdCall, SetLastError = true)]
        [return: InvalidHandleValue(-1), InvalidHandleValue(0)]
        public static extern int* Compute([In] int* left, [Out] short* right);
        [DllImport(""fixture.dll"")]
        public static extern void NamespaceIdentity(Alpha.Same value);
    }
}
namespace Alpha { public struct Same { public int value; } }
namespace Beta { public struct Same { public int value; } }
";

        [Theory]
        [InlineData("Compute([In] int* left, [Out] short* right)", "Compute([Out] short* right, [In] int* left)", "parameter 1")]
        [InlineData("Compute([In] int* left", "Compute([In] uint* left", "UInt32")]
        [InlineData("extern int* Compute", "extern int** Compute", "Int32**")]
        [InlineData("Compute([In] int* left", "Compute([Out] int* left", "Out")]
        [InlineData("NamespaceIdentity(Alpha.Same value)", "NamespaceIdentity(Beta.Same value)", "Beta.Same")]
        [InlineData("public int first; public short second;", "public short second; public int first;", "instance field order")]
        [InlineData("[FieldOffset(8)] public short second", "[FieldOffset(4)] public short second", "FieldOffset")]
        [InlineData("LayoutKind.Explicit, Size = 16", "LayoutKind.Explicit, Size = 32", "Size")]
        [InlineData("void First(int value); void Second(short value);", "void Second(short value); void First(int value);", "interface method order")]
        [InlineData("interface IDerived : IContract", "interface IDerived : IAlternate", "base types")]
        [InlineData("const int VALUE = 1", "const int VALUE = 2", "VALUE")]
        [InlineData("DllImport(\"fixture.dll\"", "DllImport(\"other.dll\"", "other.dll")]
        [InlineData("InvalidHandleValue(-1), InvalidHandleValue(0)", "InvalidHandleValue(-1), InvalidHandleValue(-1)", "InvalidHandleValue")]
        public void CompareDetectsMetadataChange(string original, string replacement, string expected)
        {
            Assert.Contains(original, Source);
            using var fixture = new ComparisonFixture();
            var first = fixture.Emit("old", Source);
            var second = fixture.Emit("new", Source.Replace(original, replacement));
            var console = new TestConsole();

            int result = WinmdUtilsProgram.Program.CompareWinmds(first, second, null, null, console);

            Assert.NotEqual(0, result);
            Assert.Contains(expected, console.Out.ToString());
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompareAcceptsIdentityAndReorderedRepeatableAttributes(bool reorder)
        {
            using var fixture = new ComparisonFixture();
            var first = fixture.Emit("old", Source);
            var second = fixture.Emit("new", reorder
                ? Source.Replace("InvalidHandleValue(-1), InvalidHandleValue(0)", "InvalidHandleValue(0), InvalidHandleValue(-1)")
                : Source);
            var console = new TestConsole();

            Assert.Equal(0, WinmdUtilsProgram.Program.CompareWinmds(first, second, null, null, console));
        }

        [Theory]
        [InlineData("SCHEME_HTTP=Alpha.NativeScheme,Beta.NativeScheme", false, 0)]
        [InlineData("SCHEME_HTTP=Alpha.NativeScheme,Beta.Other", false, -1)]
        [InlineData("SCHEME_HTTP=Alpha.NativeScheme,Beta.NativeScheme", true, -1)]
        [InlineData("SCHEME_HTTP", false, 0)]
        [InlineData("", false, -1)]
        public void DuplicateConstantExceptionsBindTheExactOwnerSet(string allowed, bool thirdOwner, int expected)
        {
            using var fixture = new ComparisonFixture();
            const string source = @"
namespace Alpha { public enum NativeScheme { SCHEME_HTTP = 1 } }
namespace Beta { public enum NativeScheme { SCHEME_HTTP = 3 } }";
            var image = fixture.Emit("duplicates", source + (thirdOwner
                ? "namespace Gamma { public enum NativeScheme { SCHEME_HTTP = 9 } }"
                : ""));
            var console = new TestConsole();
            Assert.Equal(expected, WinmdUtilsProgram.Program.ShowDuplicateConstants(image, new[] { allowed }, console));
            if (expected != 0)
                Assert.Contains("SCHEME_HTTP", console.Out.ToString());
        }

        [Theory]
        [InlineData("SCHEME_HTTP=Alpha.Apis,Beta.NativeScheme", false, 0)]
        [InlineData("SCHEME_HTTP=Alpha.NativeScheme,Beta.NativeScheme", false, -1)]
        [InlineData("SCHEME_HTTP=Alpha.Apis,Beta.NativeScheme", true, -1)]
        public void NativeConstantExceptionsDoNotAdmitTheOldLogicalEnumOwner(string allowed, bool thirdOwner, int expected)
        {
            using var fixture = new ComparisonFixture();
            const string source = @"
namespace Alpha { public static class Apis { public const uint SCHEME_HTTP = 1; } }
namespace Beta { public enum NativeScheme { SCHEME_HTTP = 3 } }";
            var image = fixture.Emit("native-duplicates", source + (thirdOwner
                ? "namespace Gamma { public enum NativeScheme { SCHEME_HTTP = 9 } }"
                : ""));
            var console = new TestConsole();
            Assert.Equal(expected, WinmdUtilsProgram.Program.ShowDuplicateConstants(image, new[] { allowed }, console));
            if (expected != 0)
                Assert.Contains("SCHEME_HTTP", console.Out.ToString());
        }

        private sealed class ComparisonFixture : IDisposable
        {
            private readonly string directory = Path.Combine(Path.GetTempPath(), "WinmdComparisonTests-" + Guid.NewGuid().ToString("N"));

            public ComparisonFixture()
            {
                Directory.CreateDirectory(this.directory);
            }

            public FileInfo Emit(string name, string source)
            {
                var paths = (string)AppContext.GetData("TRUSTED_PLATFORM_ASSEMBLIES")
                    ?? throw new InvalidOperationException("Runtime assembly references are unavailable.");
                var references = paths.Split(Path.PathSeparator).Select(path => MetadataReference.CreateFromFile(path));
                var compilation = CSharpCompilation.Create(
                    "WinmdComparisonFixture",
                    new[] { CSharpSyntaxTree.ParseText(source) },
                    references,
                    new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
                var file = new FileInfo(Path.Combine(this.directory, name + ".dll"));
                using var output = file.OpenWrite();
                var result = compilation.Emit(output);
                Assert.True(result.Success, string.Join(Environment.NewLine, result.Diagnostics));
                return file;
            }

            public void Dispose()
            {
                Directory.Delete(this.directory, recursive: true);
            }
        }
    }
}
