using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace AnnotationRollout;

internal static class Data
{
    internal static readonly JsonSerializerOptions Json = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        WriteIndented = true,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow,
        RespectRequiredConstructorParameters = true,
        RespectNullableAnnotations = true
    };

    internal static T Read<T>(string path) =>
        JsonSerializer.Deserialize<T>(File.ReadAllText(path), Json) ??
        throw new InvalidDataException($"Empty JSON: {path}");

    internal static string Hash(string path)
    {
        using var file = File.OpenRead(path);
        return Convert.ToHexString(SHA256.HashData(file));
    }

    internal static string Digest(string text) =>
        Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(text)));

    internal static string Identity(params string[] values) =>
        Digest(JsonSerializer.Serialize(values, Json));

    internal static void Write(string path, object value)
    {
        Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(path))!);
        File.WriteAllText(path, JsonSerializer.Serialize(value, Json) + "\n", new UTF8Encoding(false));
    }

    internal static void Require([System.Diagnostics.CodeAnalysis.DoesNotReturnIf(false)] bool valid, string error)
    {
        if (!valid) throw new InvalidDataException(error);
    }
}

internal sealed record Pins(
    int SchemaVersion, string PilotCommit, string ToolingCommit, string WindowsRsCommit,
    string ToolSha256, string SdkVersion, string SdkIncludeVersion, string LibclangVersion,
    string LibclangSha256, string ReferenceVersion, string ReferenceSha256, string LegacyCommit,
    string[] Architectures, string PublicationBase, string? PolicyCommit, string[] PolicyRules);

internal sealed record FileFact(string Path, string Sha256, long Bytes)
{
    internal static FileFact Capture(string path)
    {
        path = System.IO.Path.GetFullPath(path);
        return new(path, Data.Hash(path), new FileInfo(path).Length);
    }

    internal void Verify() =>
        Data.Require(File.Exists(Path) && Data.Hash(Path) == Sha256, $"Missing or changed evidence/input: {Path}");
}

internal sealed record InputFile(string Id, string Path, string Sha256, string Role);
internal sealed record IncludeFact(int Line, string Spelling, bool Quoted, string Condition, string? Header, string? CompilerSource = null);
internal sealed record Partition(string Id, string Path, string Sha256, IncludeFact[] Includes)
{
    public string State { get; set; } = "pending";
    public string? Blocker { get; set; }
    public string? BlockerOwner { get; set; }
    public string? RetryFingerprint { get; set; }
    public Dictionary<string, CaptureFact> Captures { get; set; } = new(StringComparer.Ordinal);
}

internal sealed record Header(string Id, string Path, string Sha256, string Origin)
{
    public string Selection { get; set; } = "catalog-only";
    public List<string> Consumers { get; set; } = [];
    public string Owner { get; set; } = "unassigned";
    public string State { get; set; } = "pending";
    public string[] Patches { get; set; } = [];
    public string[] Conditions { get; set; } = [];
    public bool Generated { get; set; }
    public string[] RemainingFamilies { get; set; } = [.. Vocabulary.Families];
    public string? LastVerifiedFingerprint { get; set; }
    public FileFact? Disposition { get; set; }
}

internal sealed record CaptureFact(
    FileFact Manifest, FileFact Symbols, long SymbolCount, long ObligationCount,
    string Fingerprint, bool HasErrors, string[] IncludedHeaders, FileFact[] Dependencies);

internal sealed record AuditInput(string Id, FileFact Evidence, string State, string Reason);
internal sealed record RunEvent(long Sequence, DateTimeOffset Time, string Action, string Item, string Detail);
internal sealed record ActiveJob(string Partition, int ProcessId, DateTime StartTime, string Fingerprint, string EvidenceDirectory);

internal sealed class Ledger
{
    public int SchemaVersion { get; set; } = 1;
    public long Sequence { get; set; }
    public string Fingerprint { get; set; } = "";
    public string Head { get; set; } = "";
    public string Repository { get; set; } = "";
    public string EvidenceRoot { get; set; } = "";
    public string SdkRoot { get; set; } = "";
    public string ResourceDirectory { get; set; } = "";
    public FileFact? Tool { get; set; }
    public FileFact? Libclang { get; set; }
    public FileFact? Reference { get; set; }
    public FileFact? ProviderManifest { get; set; }
    public ProviderManifest? Providers { get; set; }
    public Pins? Pins { get; set; }
    public List<InputFile> Inputs { get; set; } = [];
    public List<Partition> Partitions { get; set; } = [];
    public List<Header> Headers { get; set; } = [];
    public List<AuditInput> AuditInputs { get; set; } = [];
    public List<RunEvent> Runlog { get; set; } = [];
    public List<string> ReconciliationGaps { get; set; } = [];
    public ActiveJob? ActiveJob { get; set; }
    public string? NextItem { get; set; }
    public string? DraftPr { get; set; }
}

internal static class Vocabulary
{
    internal static readonly string[] Architectures = ["x64", "x86", "arm64"];
    internal static readonly string[] States = [
        "pending", "investigating", "patched", "validating", "equivalent",
        "expected-improvement", "already-native", "approved-sdk-exclusion", "blocked", "regressed"
    ];
    internal static readonly string[] Terminal = [
        "equivalent", "expected-improvement", "already-native", "approved-sdk-exclusion"
    ];
    internal static readonly string[] Families = [
        "native-identity-abi", "source-coverage", "metadata-presence", "reference-integrity",
        "namespace-ownership", "calling-convention-import", "direction-optionality",
        "buffer-count-termination", "const-pointer-level", "enum-association",
        "macro-value-storage-grouping", "record-layout-union-bitfield", "callback-com-vtable",
        "ownership-closer-invalid-value", "availability-condition", "error-contract",
        "guid-propertykey", "alias-projection", "legacy-reconciliation", "source-addition"
    ];

    internal static string[] FamiliesFor(string kind) => kind switch
    {
        "macro definition" => ["source-coverage", "metadata-presence", "macro-value-storage-grouping", "availability-condition", "legacy-reconciliation"],
        "ParmDecl" or "Return" => ["native-identity-abi", "direction-optionality", "buffer-count-termination",
            "const-pointer-level", "enum-association", "ownership-closer-invalid-value", "alias-projection"],
        _ => Families
    };
}
