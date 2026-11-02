using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    /// <summary>
    /// Writes per-architecture source files to a temporary directory and emits a winmd from them.
    /// Every call to <see cref="Generate"/> builds a fresh compilation and generator.
    /// </summary>
    internal sealed class MetadataFixture : IDisposable
    {
        private readonly string directory = Path.Combine(Path.GetTempPath(), "Win32MetadataTests-" + Guid.NewGuid().ToString("N"));

        public MetadataFixture()
        {
            Directory.CreateDirectory(this.directory);
            File.WriteAllText(Path.Combine(this.directory, "Attributes.manual.cs"), @"
using System;
namespace Windows.Win32.Foundation.Metadata
{
    [Flags]
    public enum Architecture { None = 0, X86 = 1, X64 = 2, Arm64 = 4, All = 7 }
    public class SupportedArchitectureAttribute : Attribute
    {
        public SupportedArchitectureAttribute(Architecture architecture) { }
    }
}");
        }

        public string Generate(string x86, string x64, string arm64, IEnumerable<string>? flags = null)
        {
            foreach (var source in new[] { ("x86", x86), ("x64", x64), ("arm64", arm64) })
            {
                string architectureDirectory = Path.Combine(this.directory, source.Item1);
                Directory.CreateDirectory(architectureDirectory);
                File.WriteAllText(
                    Path.Combine(architectureDirectory, "Test.cs"),
                    "using System; using Windows.Win32.Foundation.Metadata; namespace Test { " + source.Item2 + " }");
            }

            var compilation = ClangSharpSourceCompilation.Create(
                this.directory,
                "crossarch",
                new Dictionary<string, string>(),
                new Dictionary<string, Dictionary<string, string>>(),
                flags ?? Array.Empty<string>(),
                new Dictionary<string, string>(),
                new Dictionary<string, string>(),
                new HashSet<string>(),
                Array.Empty<string>(),
                new Dictionary<string, string>(),
                new Dictionary<string, string>());
            Diagnostic[] errors = compilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));

            string output = Path.Combine(this.directory, "Test.winmd");
            ClangSharpSourceWinmdGenerator generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation,
                new Dictionary<string, string>(),
                new HashSet<string>(),
                new HashSet<string>(),
                new Version(1, 0, 0, 0),
                output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            return output;
        }

        public void Dispose()
        {
            Directory.Delete(this.directory, true);
        }
    }
}
