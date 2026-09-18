namespace AnnotationRollout;

internal sealed record ProviderRoot(string Id, string Path, string Role);
internal sealed record ProviderManifest(
    int SchemaVersion, string Repository, string Variant, string Partition, string[] IncludeDirectories,
    ProviderRoot[] Roots, FileFact[] PreparationInputs, FileFact[] PreparedFiles, string[]? ClosureArchitectures = null);

internal static class SourceProviders
{
    internal static ProviderManifest Read(string path, string repository)
    {
        var providers = Data.Read<ProviderManifest>(path);
        Validate(providers, repository);
        return providers;
    }

    internal static void Validate(ProviderManifest providers, string repository)
    {
        Data.Require(providers.SchemaVersion == 3, "Unsupported provider manifest schema; prepare current multiarchitecture providers.");
        Data.Require(providers.ClosureArchitectures?.SequenceEqual(Vocabulary.Architectures) == true,
            "Prepared source closure must include x64, x86 and arm64.");
        Data.Require(Census.Key(providers.Repository) == Census.Key(repository), "Prepared providers belong to another worktree.");
        Data.Require(providers.Variant is "control" or "candidate", "Provider variant must be control or candidate.");
        Data.Require(File.Exists(Path.Combine(repository, @"generation\WinSDK\Partitions", providers.Partition, "main.cpp")),
            "Prepared provider partition is not canonical.");
        Data.Require(providers.Roots.Length > 0 && providers.PreparationInputs.Length > 0 && providers.PreparedFiles.Length > 0,
            "Prepared provider provenance cannot be empty.");
        Data.Require(providers.Roots.Select(r => r.Id).Distinct(StringComparer.Ordinal).Count() == providers.Roots.Length,
            "Duplicate provider root identity.");
        Data.Require(providers.Roots.Select(r => Census.Key(r.Path)).Distinct(StringComparer.Ordinal).Count() == providers.Roots.Length,
            "Duplicate provider root path.");
        foreach (var root in providers.Roots)
        {
            Data.Require(root.Id.Length > 0 && root.Id.IndexOfAny(['\\', '/']) < 0, "Provider IDs must be single path segments.");
            Data.Require(root.Role is "prepared-sdk" or "prepared-midl" or "prepared-patch" or "compiler-support", "Unknown provider role.");
            Data.Require(Directory.Exists(root.Path), $"Missing provider root: {root.Path}");
        }
        Data.Require(providers.IncludeDirectories.Length > 0 &&
            providers.IncludeDirectories.Select(Census.Key).Distinct().Count() == providers.IncludeDirectories.Length,
            "Include precedence must be explicit and nonduplicated.");
        var localIncludes = Path.Combine(repository, @"generation\WinSDK\inc");
        Data.Require(Census.Key(providers.IncludeDirectories[0]) == Census.Key(localIncludes),
            "Production SAL include shim must precede prepared SDK providers.");
        foreach (var include in providers.IncludeDirectories)
        {
            Data.Require(Directory.Exists(include), $"Missing prepared include directory: {include}");
            Data.Require(Census.Key(include) == Census.Key(localIncludes) ||
                providers.Roots.Any(r => Within(r.Path, include)), $"Unregistered include provider: {include}");
        }
        var actual = providers.Roots.SelectMany(r => Directory.EnumerateFiles(r.Path, "*", SearchOption.AllDirectories))
            .Select(Census.Key).ToHashSet(StringComparer.Ordinal);
        Data.Require(providers.PreparedFiles.Select(f => Census.Key(f.Path)).Distinct().Count() == providers.PreparedFiles.Length &&
            actual.SetEquals(providers.PreparedFiles.Select(f => Census.Key(f.Path))), "Prepared provider file census differs from its manifest.");
        foreach (var file in providers.PreparationInputs.Concat(providers.PreparedFiles)) file.Verify();
    }

    internal static bool Within(string root, string path)
    {
        var relative = Path.GetRelativePath(Path.GetFullPath(root), Path.GetFullPath(path));
        return !Path.IsPathRooted(relative) && relative != ".." &&
            !relative.StartsWith(".." + Path.DirectorySeparatorChar, StringComparison.Ordinal);
    }
}
