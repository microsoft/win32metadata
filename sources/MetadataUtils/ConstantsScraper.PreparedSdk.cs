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
        private sealed class PreparedSdkHeaderResolver
        {
            private readonly IFileSystem files;
            private readonly string output;
            private readonly string sdkRoot;
            private readonly Dictionary<string, Manifest> manifests = new(StringComparer.OrdinalIgnoreCase);
            private readonly Dictionary<(string Input, string Header), string> resolved = new();
            private readonly Dictionary<NativeConstantValues, ILookup<string, string>> proofs = new();
            private readonly HashSet<string> validatedSources = new(StringComparer.OrdinalIgnoreCase);
            private readonly Dictionary<string, string> actualHashes = new(StringComparer.OrdinalIgnoreCase);

            public PreparedSdkHeaderResolver(IFileSystem files, string output, string sdkRoot)
            {
                this.files = files;
                this.output = output;
                this.sdkRoot = string.IsNullOrEmpty(sdkRoot) ? null : Path.TrimEndingDirectorySeparator(Path.GetFullPath(sdkRoot));
            }

            public string Resolve(NativeConstantValues input, string inputPath, string header)
            {
                if (this.resolved.TryGetValue((inputPath, header), out string result))
                    return result;
                string root = PreparedRoot(header);
                if (root == null)
                    return null;
                string relative = Path.GetRelativePath(root, header);
                string destination = this.sdkRoot == null ? null : Path.GetFullPath(Path.Combine(this.sdkRoot, relative));
                string producerKey = Path.GetFileName(Path.GetDirectoryName(root));
                string selectedKey = this.sdkRoot == null ? null : Path.GetFileName(Path.GetDirectoryName(this.sdkRoot));
                if (this.sdkRoot == null || !string.Equals(Path.GetFileName(this.sdkRoot), "headers", StringComparison.OrdinalIgnoreCase) ||
                    !IsHash(selectedKey))
                    throw new InvalidDataException($"Missing selected prepared SDK identity for native input '{inputPath}'.");
                string producerPath = Path.Combine(Path.GetDirectoryName(this.output), "prepared-sdk-provenance",
                    input.Architecture.ToString().ToLowerInvariant(), producerKey, "manifest.json");
                if (!this.files.File.Exists(producerPath))
                    producerPath = Path.Combine(Path.GetDirectoryName(this.output), "prepared-sdk-provenance",
                        "crossarch", producerKey, "manifest.json");
                var producer = this.ReadManifest(producerPath, producerKey);
                var selected = this.ReadManifest(Path.Combine(Path.GetDirectoryName(this.sdkRoot), "manifest.json"), selectedKey);
                if ((producer.SdkPackageVersion, producer.SourceStage, producer.SourceGitTree, producer.SourceSha256,
                    producer.RecipeSha256, producer.PreparationSha256, producer.PreparedSha256) !=
                    (selected.SdkPackageVersion, selected.SourceStage, selected.SourceGitTree, selected.SourceSha256,
                    selected.RecipeSha256, selected.PreparationSha256, selected.PreparedSha256))
                    throw new InvalidDataException($"Conflicting prepared SDK identity for native input '{inputPath}' " +
                        $"({input.Architecture}): '{producerKey}' and '{selectedKey}'.");
                this.ValidateSource(input, inputPath, root, producer, selected);
                if (!producer.HeaderHashes.TryGetValue(relative, out string expected) ||
                    !selected.HeaderHashes.TryGetValue(relative, out string current) || current != expected)
                    throw new InvalidDataException($"Missing or conflicting prepared SDK header identity '{relative}' " +
                        $"for native input '{inputPath}' ({input.Architecture}).");
                if (this.HashFile(destination) != expected)
                    throw new InvalidDataException($"Conflicting prepared SDK header hash for '{destination}' " +
                        $"in native input '{inputPath}' ({input.Architecture}).");
                if (!this.proofs.TryGetValue(input, out var bindings))
                {
                    bindings = input.Constants.Select(value => (value.Header, value.HeaderHash))
                        .Concat(input.Constants.Where(value => value.AliasTarget != null)
                            .Select(value => (value.AliasTarget.Header, value.AliasTarget.HeaderHash)))
                        .Concat(input.Groups.SelectMany(group => group.Members).SelectMany(member => member.Bindings)
                            .Select(binding => (binding.Header, binding.HeaderHash)))
                        .ToLookup(value => Path.GetFullPath(value.Header), value => value.HeaderHash, StringComparer.OrdinalIgnoreCase);
                    this.proofs.Add(input, bindings);
                }
                if (bindings[header].Any(hash => hash != expected))
                    throw new InvalidDataException($"Conflicting native header proof for '{header}' " +
                        $"in native input '{inputPath}' ({input.Architecture}).");
                this.resolved.Add((inputPath, header), destination);
                return destination;
            }

            private void ValidateSource(NativeConstantValues input, string inputPath, string root,
                Manifest producer, Manifest selected)
            {
                if (this.validatedSources.Contains(inputPath))
                    return;
                if (string.IsNullOrEmpty(input.SourceFile) || !Path.IsPathRooted(input.SourceFile) ||
                    string.IsNullOrEmpty(input.BindingSource) || !Path.IsPathRooted(input.BindingSource) || !IsHash(input.SourceHash))
                    throw new InvalidDataException($"Missing native source identity for input '{inputPath}' ({input.Architecture}).");
                string source;
                string sourceRoot = PreparedRoot(input.SourceFile);
                if (sourceRoot != null)
                {
                    string relative = Path.GetRelativePath(sourceRoot, input.SourceFile);
                    if (!string.Equals(sourceRoot, root, StringComparison.OrdinalIgnoreCase) ||
                        !producer.HeaderHashes.TryGetValue(relative, out string expected) || expected != input.SourceHash ||
                        !selected.HeaderHashes.TryGetValue(relative, out string current) || current != input.SourceHash)
                        throw new InvalidDataException($"Conflicting native source identity for input '{inputPath}' ({input.Architecture}).");
                    source = Path.GetFullPath(Path.Combine(this.sdkRoot, relative));
                }
                else
                {
                    string originalDirectory = input.BindingSource.EndsWith(".cs", StringComparison.OrdinalIgnoreCase)
                        ? Path.GetDirectoryName(input.BindingSource) : input.BindingSource;
                    string relative = Path.GetRelativePath(originalDirectory, input.SourceFile);
                    if (Path.IsPathRooted(relative))
                        throw new InvalidDataException($"Unresolvable native source identity for input '{inputPath}' ({input.Architecture}).");
                    source = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(inputPath), relative));
                }
                if (!this.files.File.Exists(source) || this.HashFile(source) != input.SourceHash)
                    throw new InvalidDataException($"Conflicting native source identity '{source}' " +
                        $"for input '{inputPath}' ({input.Architecture}).");
                this.validatedSources.Add(inputPath);
            }

            private Manifest ReadManifest(string path, string identity)
            {
                if (this.manifests.TryGetValue(path, out var result))
                    return result;
                if (!this.files.File.Exists(path))
                    throw new InvalidDataException($"Missing prepared SDK identity manifest '{path}'.");
                try
                {
                    result = JsonSerializer.Deserialize<Manifest>(this.files.File.ReadAllText(path),
                        new JsonSerializerOptions { PropertyNameCaseInsensitive = true });
                }
                catch (JsonException error)
                {
                    throw new InvalidDataException($"Malformed prepared SDK identity manifest '{path}'.", error);
                }
                if (result == null || result.SchemaVersion != 1 ||
                    !string.Equals(result.Identity, identity, StringComparison.OrdinalIgnoreCase) ||
                    string.IsNullOrEmpty(result.SdkPackageVersion) || result.SourceStage != "post-midl" ||
                    !IsHash(result.SourceSha256) || !IsHash(result.RecipeSha256) ||
                    !IsHash(result.PreparationSha256) || !IsHash(result.PreparedSha256) || result.Files == null)
                    throw new InvalidDataException($"Invalid prepared SDK identity manifest '{path}'.");
                foreach (var file in result.Files)
                {
                    string relative = file?.Path?.Replace(Path.AltDirectorySeparatorChar, Path.DirectorySeparatorChar);
                    if (string.IsNullOrEmpty(relative) || Path.IsPathRooted(relative) ||
                        relative.Split(Path.DirectorySeparatorChar).Any(part => part is "" or "." or "..") ||
                        !IsHash(file.Sha256) || !result.HeaderHashes.TryAdd(relative, file.Sha256))
                        throw new InvalidDataException($"Invalid prepared SDK header identity in manifest '{path}'.");
                }
                this.manifests.Add(path, result);
                return result;
            }

            private string HashFile(string path)
            {
                if (!this.actualHashes.TryGetValue(path, out string hash))
                {
                    if (!this.files.File.Exists(path))
                        throw new InvalidDataException($"Missing prepared SDK header hash input '{path}'.");
                    using var stream = this.files.File.OpenRead(path);
                    hash = Convert.ToHexString(SHA256.HashData(stream));
                    this.actualHashes.Add(path, hash);
                }
                return hash;
            }

            private static bool IsHash(string value) => value?.Length == 64 && value.All(Uri.IsHexDigit);

            private static string PreparedRoot(string header)
            {
                string root = Path.GetDirectoryName(header);
                while (root != null && !(string.Equals(Path.GetFileName(root), "headers", StringComparison.OrdinalIgnoreCase) &&
                    IsHash(Path.GetFileName(Path.GetDirectoryName(root)))))
                    root = Path.GetDirectoryName(root);
                return root;
            }

            private sealed record Manifest(
                int SchemaVersion, string Identity, string SdkPackageVersion, string SourceStage, string SourceGitTree,
                string SourceSha256, string RecipeSha256, string PreparationSha256, string PreparedSha256, Header[] Files)
            {
                public Dictionary<string, string> HeaderHashes { get; } = new(StringComparer.OrdinalIgnoreCase);
            }

            private sealed record Header(string Path, string Sha256);
        }
    }
}
