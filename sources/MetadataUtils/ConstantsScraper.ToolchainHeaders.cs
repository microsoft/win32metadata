using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Abstractions;
using System.Linq;
using System.Security.Cryptography;
using System.Text.Json;

namespace MetadataUtils
{
    public static partial class ConstantsScraper
    {
        private sealed record SelectedToolchainHeaderOwnership(
            string Input, Architecture Architecture, string SourceFile, string SourceHash, string SelectedSourceFile,
            string IncludeRoot, string TraversalHeader, string Header, string HeaderHash, string Namespace, int TraversalOrder);

        private sealed class SelectedToolchainHeaderResolver
        {
            private readonly IFileSystem files;
            private readonly string selectionFile;
            private readonly string sdkRoot;
            private readonly KeyValuePair<string, string>[] traversed;
            private NativeConstantHeaderSelection selection;

            public SelectedToolchainHeaderResolver(IFileSystem files, string selectionFile, string sdkRoot,
                Dictionary<string, string> traversed)
            {
                this.files = files;
                this.selectionFile = selectionFile;
                this.sdkRoot = string.IsNullOrEmpty(sdkRoot) ? null : Path.GetFullPath(sdkRoot);
                this.traversed = traversed.ToArray();
            }

            public SelectedToolchainHeaderOwnership Resolve(NativeConstantValues input, string inputPath, string header)
            {
                this.ReadSelection();
                var owners = this.selection.Inputs.Where(owner =>
                    string.Equals(owner.Input, Path.GetFullPath(inputPath), StringComparison.OrdinalIgnoreCase)).ToArray();
                if (owners.Length != 1)
                    throw new InvalidDataException($"Missing or ambiguous selected toolchain input owner for '{inputPath}'.");
                var owner = owners[0];
                if (owner.Architecture != input.Architecture)
                    throw new InvalidDataException($"Conflicting selected toolchain architecture for '{inputPath}' ({input.Architecture}).");
                string source = this.ValidateSource(input, inputPath, owner);
                string full = Rooted(header, "toolchain header");
                var candidates = new List<(string Root, string Selector, string Header, int Order)>();
                foreach (string selector in owner.TraversedHeaders)
                {
                    if (string.IsNullOrWhiteSpace(selector))
                        throw new InvalidDataException($"Missing selected toolchain traversal for '{inputPath}'.");
                    if (Path.IsPathRooted(selector))
                        continue;
                    string relative = selector.Replace(Path.AltDirectorySeparatorChar, Path.DirectorySeparatorChar);
                    if (relative.Split(Path.DirectorySeparatorChar).Any(part => part is "" or "." or "..") ||
                        relative.IndexOfAny(new[] { '*', '?' }) >= 0)
                        throw new InvalidDataException($"Invalid selected toolchain traversal '{selector}' in '{inputPath}'.");
                    int order = Array.FindIndex(this.traversed, pair =>
                        string.Equals(pair.Key, selector, StringComparison.OrdinalIgnoreCase) && pair.Value == owner.Namespace);
                    if (order < 0)
                        continue;
                    foreach (string root in this.selection.IncludeRoots)
                        candidates.Add((root, selector, Rooted(Path.Combine(root, relative), "toolchain traversal"), order));
                }
                if (candidates.Count == 0)
                    throw new InvalidDataException($"Missing selected toolchain traversal owner for '{header}' in '{inputPath}'.");
                var matches = candidates.Where(candidate =>
                    string.Equals(candidate.Header, full, StringComparison.OrdinalIgnoreCase)).ToArray();
                if (matches.Length != 1)
                    throw new InvalidDataException($"Missing or ambiguous selected toolchain root/path identity for '{header}' in '{inputPath}'.");
                var selected = matches[0];
                if (candidates.Count(candidate => string.Equals(candidate.Selector, selected.Selector,
                    StringComparison.OrdinalIgnoreCase) && this.files.File.Exists(candidate.Header)) > 1)
                    throw new InvalidDataException($"Ambiguous selected toolchain traversal '{selected.Selector}' in '{inputPath}'.");
                string expected = this.HashFile(full, "toolchain header");
                var proofs = input.Constants.Select(value => (value.Header, value.HeaderHash))
                    .Concat(input.Constants.Where(value => value.AliasTarget != null)
                        .Select(value => (value.AliasTarget.Header, value.AliasTarget.HeaderHash)))
                    .Concat(input.Groups.SelectMany(group => group.Members).SelectMany(member => member.Bindings)
                        .Select(binding => (binding.Header, binding.HeaderHash)))
                    .Where(value => string.Equals(Rooted(value.Header, "native header proof"), full,
                        StringComparison.OrdinalIgnoreCase))
                    .Select(value => value.HeaderHash).ToArray();
                if (proofs.Length == 0 || proofs.Any(hash => hash != expected))
                    throw new InvalidDataException($"Missing or conflicting native header proof for selected toolchain header '{header}' in '{inputPath}'.");
                return new SelectedToolchainHeaderOwnership(inputPath, input.Architecture, input.SourceFile,
                    input.SourceHash, source, selected.Root, selected.Selector, full, expected, owner.Namespace, selected.Order);
            }

            private string ValidateSource(NativeConstantValues input, string inputPath, NativeConstantInputOwner owner)
            {
                string original = Rooted(input.SourceFile, "native source identity");
                string binding = Rooted(input.BindingSource, "native source identity");
                if (input.SourceHash?.Length != 64 || !input.SourceHash.All(Uri.IsHexDigit))
                    throw new InvalidDataException($"Missing native source identity for '{inputPath}' ({input.Architecture}).");
                string originalDirectory = binding.EndsWith(".cs", StringComparison.OrdinalIgnoreCase)
                    ? Path.GetDirectoryName(binding) : binding;
                string relative = Path.GetRelativePath(originalDirectory, original);
                if (Path.IsPathRooted(relative))
                    throw new InvalidDataException($"Unresolvable native source identity for '{inputPath}' ({input.Architecture}).");
                string source = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(inputPath), relative));
                if (!string.Equals(source, owner.SourceFile, StringComparison.OrdinalIgnoreCase) ||
                    this.HashFile(source, "native source identity") != input.SourceHash)
                    throw new InvalidDataException($"Conflicting native source identity '{source}' for '{inputPath}' ({input.Architecture}).");
                return source;
            }

            private void ReadSelection()
            {
                if (this.selection != null)
                    return;
                if (string.IsNullOrWhiteSpace(this.selectionFile) || !this.files.File.Exists(this.selectionFile))
                    throw new InvalidDataException($"Missing selected toolchain selection '{this.selectionFile}'.");
                NativeConstantHeaderSelection plan;
                try
                {
                    plan = JsonSerializer.Deserialize<NativeConstantHeaderSelection>(this.files.File.ReadAllText(this.selectionFile));
                }
                catch (JsonException error)
                {
                    throw new InvalidDataException($"Malformed selected toolchain selection '{this.selectionFile}'.", error);
                }
                if (plan == null || plan.Version != 1 || plan.IncludeRoots == null || plan.IncludeRoots.Length == 0 ||
                    plan.Inputs == null || plan.Inputs.Any(owner => owner == null || owner.TraversedHeaders == null ||
                        string.IsNullOrWhiteSpace(owner.Namespace)))
                    throw new InvalidDataException($"Invalid selected toolchain selection '{this.selectionFile}'.");
                var roots = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                foreach (string root in plan.IncludeRoots)
                {
                    string full = Path.TrimEndingDirectorySeparator(Rooted(root, "toolchain root"));
                    if (!roots.Add(full) || this.sdkRoot != null &&
                        (Within(full, this.sdkRoot) || Within(this.sdkRoot, full)))
                        throw new InvalidDataException($"Ambiguous or SDK-overlapping selected toolchain root '{root}'.");
                }
                foreach (var owner in plan.Inputs)
                {
                    _ = Rooted(owner.Input, "toolchain input owner");
                    _ = Rooted(owner.SourceFile, "native source identity");
                }
                this.selection = plan with { IncludeRoots = roots.ToArray() };
            }

            private string HashFile(string path, string identity)
            {
                if (!this.files.File.Exists(path))
                    throw new InvalidDataException($"Missing {identity} file '{path}'.");
                using var stream = this.files.File.OpenRead(path);
                return Convert.ToHexString(SHA256.HashData(stream));
            }

            private static string Rooted(string path, string identity)
            {
                if (string.IsNullOrWhiteSpace(path) || !Path.IsPathFullyQualified(path))
                    throw new InvalidDataException($"Missing or unrooted {identity} '{path}'.");
                try
                {
                    return Path.GetFullPath(path);
                }
                catch (ArgumentException error)
                {
                    throw new InvalidDataException($"Invalid {identity} '{path}'.", error);
                }
            }

            private static bool Within(string path, string root) =>
                string.Equals(Path.TrimEndingDirectorySeparator(path), Path.TrimEndingDirectorySeparator(root),
                    StringComparison.OrdinalIgnoreCase) ||
                path.StartsWith(Path.TrimEndingDirectorySeparator(root) + Path.DirectorySeparatorChar,
                    StringComparison.OrdinalIgnoreCase);
        }
    }
}
