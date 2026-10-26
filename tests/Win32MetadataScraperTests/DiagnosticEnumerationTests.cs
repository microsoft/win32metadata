using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Text;
using ClangSharp.Interop;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class DiagnosticEnumerationTests
    {
        private const int DiagnosticCount = 128;
        private static readonly Dictionary<short, OpCode> opcodes = typeof(OpCodes).GetFields()
            .Where(field => field.FieldType == typeof(OpCode))
            .Select(field => (OpCode)field.GetValue(null)).ToDictionary(opcode => opcode.Value);

        [Fact]
        public void ImmutableTranslationUnitsCountDiagnosticsOnceOutsideEnumerationLoops()
        {
            Assert.True(CountsOnceOutsideLoops(Control(nameof(CachedCount))));
            Assert.False(CountsOnceOutsideLoops(Control(nameof(RepeatedCount))));
            Assert.False(CountsOnceOutsideLoops(Control(nameof(TwoCounts))));

            var readers = typeof(RemapDiscovery).Assembly.GetTypes().SelectMany(type =>
                    type.GetMethods(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static |
                        BindingFlags.Instance | BindingFlags.DeclaredOnly))
                .Where(method => ReadInstructions(method).Any(instruction => IsDiagnosticCount(instruction.CalledMethod)))
                .ToArray();
            Assert.Single(readers);
            Assert.Contains(readers, method => method.DeclaringType.Name == "Program" && method.Name == "ParseTranslationUnit");
            foreach (var method in readers)
                Assert.True(CountsOnceOutsideLoops(method),
                    $"{method.DeclaringType.FullName}.{method.Name} must snapshot the immutable TU count once, outside every loop.");
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NoteRichOriginalParsePreservesEveryDiagnosticAndPreventsOutput(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, NoteRichDeclarations(),
                annotationsEnabled: false, extraSettings: "--additional\n-ferror-limit=0\n");
            var expected = ReadNativeDiagnostics(fixture, target);
            AssertNoteRichErrors(expected);
            Assert.Equal(-1, fixture.Run());
            Assert.Equal(expected.Select(diagnostic => diagnostic.Text), NativeMessages(fixture));
            Assert.Contains("Skipping", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".native-constants.json")));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NoteRichProbeRejectionsPreserveEveryOrderedNativeFact(string architecture, string target)
        {
            string[] names = Enumerable.Range(0, DiagnosticCount).Select(index => $"DIAGNOSTIC_BAD_{index:D4}")
                .Append("DIAGNOSTIC_OK").ToArray();
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                "int runtime_value;\n" + string.Join("\n", names.Select(name =>
                    $"#define {name} {(name == "DIAGNOSTIC_OK" ? "7U" : "runtime_value")}")),
                annotationsEnabled: false, extraSettings: "--config\nnative-constants-only\n");
            string path = Path.Combine(fixture.DirectoryPath, "test.cpp");
            var source = new StringBuilder(File.ReadAllText(path)).AppendLine().AppendLine();
            for (int index = 0; index < DiagnosticCount; index++)
                source.Append("#if defined(").Append(names[index]).AppendLine(")")
                    .Append("constexpr auto __Win32MetadataConstant_").Append(index)
                    .Append(" = __builtin_choose_expr(1, (").Append(names[index]).AppendLine("), 0);")
                    .AppendLine("#endif");
            var expected = ReadNativeDiagnostics(fixture, target, source.ToString(), include: location =>
            {
                location.GetFileLocation(out var file, out _, out _, out _);
                return file.ToString() == path;
            });
            AssertNoteRichErrors(expected, inHeader: false);
            Assert.Equal(0, fixture.Run());
            var values = NativeConstantExtractionTests.Read(fixture);
            var accepted = Assert.Single(values.Constants);
            Assert.Equal("DIAGNOSTIC_OK", accepted.NativeName);
            Assert.Equal("7U", accepted.Value);
            Assert.Equal(DiagnosticCount, values.Issues.Count);
            Assert.Equal(names.Take(DiagnosticCount), values.Issues.Select(issue => issue.Name));
            Assert.All(values.Issues, issue =>
            {
                Assert.Equal(fixture.Header, issue.Header);
                Assert.Equal("native diagnostic", issue.Reason);
                Assert.Single(issue.Diagnostics);
            });
            Assert.Equal(expected.Select(diagnostic => diagnostic.Text), values.Issues.SelectMany(issue => issue.Diagnostics));
            Assert.Empty(NativeMessages(fixture));
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeWarningsStayDeduplicatedAcrossDeclarationProbeAndCompanionParses(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                string.Join("\n", Enumerable.Range(0, 16).Select(index =>
                    $"__attribute__((annotate(\"NativeSAL\"))) struct IGNORED_{index:D2} {{ int value; }};")) + @"
#define DIAGNOSTIC_VALUE 7U
[[nodiscard]] int DiagnosticProbe();
#ifndef UNICODE
extern ""C"" int DiagnosticAnsi(char* text);
#endif
", extraSettings: "--config\nnative-constant-values\n--additional\n-DUNICODE\n" +
                    "--with-librarypath\nDiagnosticAnsi=scan.dll\n");
            var expected = ReadNativeDiagnostics(fixture, target, extraArguments: new[] { "-DUNICODE" });
            Assert.Equal(16, expected.Length);
            Assert.All(expected, diagnostic => Assert.Equal(CXDiagnosticSeverity.CXDiagnostic_Warning, diagnostic.Severity));
            Assert.Equal(new[] { 1U }.Concat(Enumerable.Repeat(0U, 15)), expected.Select(diagnostic => diagnostic.ChildNotes));
            fixture.AssertSuccess("WarnUnusedResult");
            Assert.Equal(expected.Select(diagnostic => diagnostic.Text), NativeMessages(fixture));
            Assert.Equal(1, fixture.Diagnostics.Split("Diagnostics for '", StringSplitOptions.None).Length - 1);
            Assert.Contains("DiagnosticProbe", fixture.ReadSource());
            Assert.Contains("DiagnosticAnsi", fixture.ReadSource());
            var value = Assert.Single(NativeConstantExtractionTests.Read(fixture).Constants);
            Assert.Equal("DIAGNOSTIC_VALUE", value.NativeName);
            Assert.Equal("7U", value.Value);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NoteRichCompanionFailureKeepsEveryDiagnosticAndFailsProjection(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
int DiagnosticProbe();
#ifndef UNICODE
extern ""C"" int DiagnosticAnsi(char* text);
" + NoteRichDeclarations() + "\n#endif\n",
                extraSettings: "--additional\n-DUNICODE\n-ferror-limit=0\n" +
                    "--with-librarypath\nDiagnosticAnsi=scan.dll\n");
            var expected = ReadNativeDiagnostics(fixture, target, extraArguments: new[] { "-UUNICODE" });
            AssertNoteRichErrors(expected);
            Assert.Equal(-1, fixture.Run());
            Assert.Equal(expected.Select(diagnostic => diagnostic.Text), NativeMessages(fixture));
            Assert.Contains("Native conditional companion parsing failed", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".header-types.cs")));
        }

        private static string NoteRichDeclarations() => "int runtime_value;\n" +
            string.Join("\n", Enumerable.Range(0, DiagnosticCount).Select(index =>
                $"constexpr auto DIAGNOSTIC_NOTE_{index:D4} = runtime_value;"));

        private static void AssertNoteRichErrors(NativeDiagnostic[] diagnostics, bool inHeader = true)
        {
            Assert.Equal(DiagnosticCount, diagnostics.Length);
            Assert.All(diagnostics, diagnostic => Assert.Equal(CXDiagnosticSeverity.CXDiagnostic_Error, diagnostic.Severity));
            Assert.Equal(Enumerable.Range(0, DiagnosticCount).Select(index => inHeader && index == 0 ? 3U : 2U),
                diagnostics.Select(diagnostic => diagnostic.ChildNotes));
        }

        private static string[] NativeMessages(HeaderAnnotationTests.NativeFixture fixture) =>
            fixture.Diagnostics.Split(new[] { "\r\n", "\n" }, StringSplitOptions.RemoveEmptyEntries)
                .Where(line => line.StartsWith("    " + fixture.DirectoryPath, StringComparison.Ordinal))
                .Select(line => line.Substring(4)).ToArray();

        private static NativeDiagnostic[] ReadNativeDiagnostics(HeaderAnnotationTests.NativeFixture fixture,
            string target, string source = null, string[] extraArguments = null,
            Func<CXSourceLocation, bool> include = null)
        {
            string path = Path.Combine(fixture.DirectoryPath, "test.cpp");
            string[] arguments = new[] { "--language=c++", "--std=c++17", "--target=" + target,
                "--include-directory=" + Path.Combine(AppContext.BaseDirectory, "assets"),
                "-D_USE_DECLSPECS_FOR_SAL=1", "-D_PREFAST_=1", "-Wno-pragma-once-outside-header", "-ferror-limit=0" }
                .Concat(extraArguments ?? Array.Empty<string>()).ToArray();
            using var index = CXIndex.Create(excludeDeclarationsFromPch: false, displayDiagnostics: false);
            using var unsaved = CXUnsavedFile.Create(path, source ?? File.ReadAllText(path));
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, path, arguments,
                new[] { unsaved }, CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord |
                CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes |
                CXTranslationUnit_Flags.CXTranslationUnit_VisitImplicitAttributes, out var unit));
            using (unit)
            {
                uint count = unit.NumDiagnostics;
                var diagnostics = new List<NativeDiagnostic>();
                for (uint indexInUnit = 0; indexInUnit < count; indexInUnit++)
                {
                    using var diagnostic = unit.GetDiagnostic(indexInUnit);
                    if (include != null && !include(diagnostic.Location))
                        continue;
                    using var formatted = diagnostic.Format(CXDiagnostic.DefaultDisplayOptions);
                    diagnostics.Add(new NativeDiagnostic(formatted.ToString(),
                        diagnostic.Severity, diagnostic.ChildDiagnostics.NumDiagnostics));
                }
                return diagnostics.ToArray();
            }
        }

        private static MethodInfo Control(string name) => typeof(DiagnosticEnumerationTests)
            .GetMethod(name, BindingFlags.NonPublic | BindingFlags.Static);

        private static uint CachedCount(CXTranslationUnit unit)
        {
            uint count = unit.NumDiagnostics;
            uint visited = 0;
            for (uint index = 0; index < count; index++)
                visited++;
            return visited;
        }

        private static uint RepeatedCount(CXTranslationUnit unit)
        {
            uint visited = 0;
            for (uint index = 0; index < unit.NumDiagnostics; index++)
                visited++;
            return visited;
        }

        private static uint TwoCounts(CXTranslationUnit unit) => unit.NumDiagnostics + unit.NumDiagnostics;

        private static bool IsDiagnosticCount(MethodBase method) =>
            method?.DeclaringType == typeof(CXTranslationUnit) && method.Name == "get_NumDiagnostics";

        private static bool CountsOnceOutsideLoops(MethodInfo method)
        {
            var instructions = ReadInstructions(method);
            var counts = instructions.Where(instruction => IsDiagnosticCount(instruction.CalledMethod)).ToArray();
            if (counts.Length != 1)
                return false;
            var byOffset = instructions.ToDictionary(instruction => instruction.Offset);
            var pending = new Stack<int>(counts[0].Successors);
            var visited = new HashSet<int>();
            while (pending.TryPop(out int offset))
            {
                if (offset == counts[0].Offset)
                    return false;
                if (visited.Add(offset) && byOffset.TryGetValue(offset, out var instruction))
                    foreach (int successor in instruction.Successors)
                        pending.Push(successor);
            }
            return true;
        }

        private static Instruction[] ReadInstructions(MethodInfo method)
        {
            byte[] bytes = method.GetMethodBody()?.GetILAsByteArray();
            if (bytes == null)
                return Array.Empty<Instruction>();
            var result = new List<Instruction>();
            for (int position = 0; position < bytes.Length;)
            {
                int offset = position;
                short value = bytes[position++];
                if (value == 0xfe)
                    value = (short)(0xfe00 | bytes[position++]);
                OpCode opcode = opcodes[value];
                int size = opcode.OperandType switch
                {
                    OperandType.InlineNone => 0,
                    OperandType.ShortInlineBrTarget or OperandType.ShortInlineI or OperandType.ShortInlineVar => 1,
                    OperandType.InlineVar => 2,
                    OperandType.InlineI8 or OperandType.InlineR => 8,
                    OperandType.InlineSwitch => 4 + 4 * BitConverter.ToInt32(bytes, position),
                    _ => 4,
                };
                int next = position + size;
                var successors = new List<int>();
                if (opcode.OperandType == OperandType.InlineBrTarget)
                    successors.Add(next + BitConverter.ToInt32(bytes, position));
                else if (opcode.OperandType == OperandType.ShortInlineBrTarget)
                    successors.Add(next + (sbyte)bytes[position]);
                else if (opcode.OperandType == OperandType.InlineSwitch)
                    for (int index = position + 4; index < next; index += 4)
                        successors.Add(next + BitConverter.ToInt32(bytes, index));
                if (opcode.FlowControl is not FlowControl.Branch and not FlowControl.Return and not FlowControl.Throw)
                    successors.Add(next);
                MethodBase called = opcode.OperandType == OperandType.InlineMethod
                    ? method.Module.ResolveMethod(BitConverter.ToInt32(bytes, position),
                        method.DeclaringType.GetGenericArguments(), method.GetGenericArguments()) : null;
                result.Add(new Instruction(offset, called, successors.ToArray()));
                position = next;
            }
            return result.ToArray();
        }

        private sealed record NativeDiagnostic(string Text, CXDiagnosticSeverity Severity, uint ChildNotes);
        private sealed record Instruction(int Offset, MethodBase CalledMethod, int[] Successors);
    }
}
