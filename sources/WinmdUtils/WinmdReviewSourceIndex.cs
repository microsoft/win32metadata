using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace WinmdUtilsProgram
{
    internal sealed class WinmdReviewSourceIndex
    {
        private sealed record Source(string Identity, string Path, string Sha256, int Line, string Partition, string[] NativeNames);
        private sealed record Header(string Path, string OriginalPath, string Sha256, bool Available, string Settings, string SettingsSha256);
        private readonly Dictionary<string, List<Source>> declarations = new(StringComparer.Ordinal);
        private readonly Dictionary<string, List<Source>> shortNames = new(StringComparer.Ordinal);
        private readonly Dictionary<string, List<Header>> headers = new(StringComparer.Ordinal);
        private readonly Dictionary<string, object> entries = new(StringComparer.Ordinal);
        private readonly HashSet<string> gaps = new(StringComparer.Ordinal);
        private readonly List<object> inputs = new();
        private readonly Dictionary<string, string> headerHashes = new(StringComparer.OrdinalIgnoreCase);

        internal WinmdReviewSourceIndex(WinmdReviewBatch.Options options)
        {
            if (options.GeneratedDirectory != null)
            {
                if (!Directory.Exists(options.GeneratedDirectory))
                    throw new DirectoryNotFoundException(options.GeneratedDirectory);
                foreach (string path in Directory.EnumerateFiles(options.GeneratedDirectory, "*.cs", SearchOption.AllDirectories).OrderBy(p => p, StringComparer.Ordinal))
                    this.IndexSource(path);
            }
            var settings = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (string scratch in options.ScratchDirectories)
            {
                foreach (string path in Directory.EnumerateFiles(scratch, "*.settings.rsp", SearchOption.AllDirectories))
                    settings.Add(path);
            }
            if (options.JobBindings != null)
            {
                using var document = JsonDocument.Parse(File.ReadAllText(options.JobBindings));
                this.inputs.Add(new { kind = "actual-job-bindings", path = Path.GetFullPath(options.JobBindings), sha256 = WinmdReviewBatch.HashFile(options.JobBindings) });
                foreach (var job in document.RootElement.GetProperty("actualJobBindings").EnumerateArray())
                {
                    string path = job.GetProperty("settings").GetString();
                    if (WinmdReviewBatch.HashFile(path) != job.GetProperty("settingsSha256").GetString())
                        throw new InvalidDataException("An actual native-job settings binding changed: " + path);
                    settings.Add(path);
                }
            }
            foreach (string path in settings.OrderBy(p => p, StringComparer.Ordinal))
                this.IndexSettings(path);
        }

        internal IEnumerable<object> Entries => this.entries.Values;
        internal IEnumerable<object> Inputs => this.inputs;
        internal IEnumerable<string> Gaps => this.gaps.OrderBy(p => p, StringComparer.Ordinal);

        private void IndexSource(string path)
        {
            string hash = WinmdReviewBatch.HashFile(path);
            this.inputs.Add(new { kind = "actual-generated-source", path = Path.GetFullPath(path), sha256 = hash });
            var root = CSharpSyntaxTree.ParseText(File.ReadAllText(path)).GetRoot();
            string partition = Path.GetFileNameWithoutExtension(path);
            if (partition.EndsWith(".header-types", StringComparison.Ordinal))
                partition = partition.Substring(0, partition.Length - ".header-types".Length);
            foreach (var node in root.DescendantNodes().OfType<MemberDeclarationSyntax>())
            {
                string[] names = node switch
                {
                    BaseTypeDeclarationSyntax type => new[] { type.Identifier.ValueText },
                    DelegateDeclarationSyntax type => new[] { type.Identifier.ValueText, type.Identifier.ValueText + ".Invoke" },
                    MethodDeclarationSyntax method => new[] { method.Identifier.ValueText },
                    EnumMemberDeclarationSyntax member => new[] { member.Identifier.ValueText },
                    FieldDeclarationSyntax field => field.Declaration.Variables.Select(v => v.Identifier.ValueText).ToArray(),
                    _ => Array.Empty<string>(),
                };
                foreach (string name in names)
                {
                    var scope = node.Ancestors().Reverse().Select(parent => parent switch
                    {
                        BaseNamespaceDeclarationSyntax ns => ns.Name.ToString(),
                        BaseTypeDeclarationSyntax type => type.Identifier.ValueText,
                        _ => null,
                    }).Where(p => p != null);
                    string identity = string.Join(".", scope.Append(name));
                    string[] nativeNames = node.Ancestors().OfType<BaseTypeDeclarationSyntax>()
                        .Select(t => t.Identifier.ValueText).Where(n => n != "Apis").Prepend(name.Split('.')[0])
                        .Distinct(StringComparer.Ordinal).ToArray();
                    var source = new Source(identity, Path.GetFullPath(path), hash,
                        node.GetLocation().GetLineSpan().StartLinePosition.Line + 1, partition, nativeNames);
                    Add(this.declarations, identity, source);
                    Add(this.shortNames, name, source);
                }
            }
        }

        private void IndexSettings(string path)
        {
            string hash = WinmdReviewBatch.HashFile(path);
            this.inputs.Add(new { kind = "actual-native-job-settings", path = Path.GetFullPath(path), sha256 = hash });
            string partition = Path.GetFileName(path).Substring(0, Path.GetFileName(path).Length - ".settings.rsp".Length);
            string option = null;
            foreach (string line in File.ReadLines(path))
            {
                if (line.StartsWith("--", StringComparison.Ordinal))
                {
                    option = line;
                    continue;
                }
                if (option != "--traverse" || string.IsNullOrWhiteSpace(line))
                    continue;
                string full = Path.GetFullPath(line.Replace('/', Path.DirectorySeparatorChar));
                bool available = File.Exists(full);
                if (available && !this.headerHashes.ContainsKey(full))
                    this.headerHashes.Add(full, WinmdReviewBatch.HashFile(full));
                Add(this.headers, partition, new Header(full, line, available ? this.headerHashes[full] : null,
                    available, Path.GetFullPath(path), hash));
            }
        }

        internal string Resolve(string symbol)
        {
            string lookup = WinmdReviewMetadata.LookupName(symbol);
            if (this.entries.ContainsKey(lookup))
                return lookup;
            bool exact = this.declarations.TryGetValue(lookup, out var sources);
            if (!exact)
                this.shortNames.TryGetValue(lookup.Substring(lookup.LastIndexOf('.') + 1), out sources);
            sources = sources ?? new List<Source>();
            var partitions = sources.Select(s => s.Partition).Distinct(StringComparer.Ordinal).ToArray();
            var native = partitions.Where(this.headers.ContainsKey).SelectMany(p => this.headers[p])
                .Distinct().ToArray();
            if (sources.Count == 0 || native.Length == 0)
                this.gaps.Add(lookup);
            this.entries.Add(lookup, new
            {
                key = lookup,
                generatedResolution = sources.Count == 0 ? "missing" : exact ? "exact-syntax-identity" : "short-name-candidates-not-proven-ownership",
                generatedDeclarations = sources.Select(s => new { s.Identity, s.Path, s.Sha256, s.Line, s.Partition }),
                partitions,
                nativeResolution = native.Length == 0 ? "missing" : "actual-job-traversal-candidates-not-declaration-proof",
                nativeHeaderCandidates = native,
                nativeSearchSymbols = sources.SelectMany(s => s.NativeNames).Distinct(StringComparer.Ordinal),
                missingHistoricalNativeOrProducerEvidenceIsNotInferred = true,
            });
            return lookup;
        }

        private static void Add<T>(Dictionary<string, List<T>> dictionary, string name, T item)
        {
            if (!dictionary.TryGetValue(name, out var values))
                dictionary.Add(name, values = new List<T>());
            values.Add(item);
        }
    }
}
