using System.Diagnostics;
using System.Text;

namespace AnnotationRollout;

internal sealed class Store : IDisposable
{
    private readonly string directory;
    private readonly FileStream lease;

    internal Store(string directory)
    {
        this.directory = Path.GetFullPath(directory);
        Directory.CreateDirectory(this.directory);
        // The OS releases this exclusive lease after a crash. A PID file alone cannot do that.
        lease = new FileStream(Path.Combine(this.directory, "writer.lock"), FileMode.OpenOrCreate,
            FileAccess.ReadWrite, FileShare.None);
    }

    internal bool Exists => File.Exists(Path.Combine(directory, "current.json"));
    internal FileFact CurrentCheckpoint => Data.Read<FileFact>(Path.Combine(directory, "current.json"));

    internal Ledger Load()
    {
        var pointer = Data.Read<FileFact>(Path.Combine(directory, "current.json"));
        Data.Require(Path.GetDirectoryName(pointer.Path) == directory, "Checkpoint escapes state directory.");
        pointer.Verify();
        var ledger = Data.Read<Ledger>(pointer.Path);
        Validate(ledger, false);
        return ledger;
    }

    internal void Save(Ledger ledger, string action, string item, string detail)
    {
        ledger.Sequence++;
        ledger.Runlog.Add(new(ledger.Sequence, DateTimeOffset.UtcNow, action, item, detail));
        ledger.NextItem = Select(ledger)?.Id;
        Validate(ledger, false);
        var snapshot = Path.Combine(directory, $"checkpoint-{ledger.Sequence:D6}-{Guid.NewGuid():N}.json");
        Data.Require(!File.Exists(snapshot), $"Checkpoint already exists: {snapshot}");
        Data.Write(snapshot, ledger);
        Flush(snapshot);
        var temporary = Path.Combine(directory, "current.json.tmp");
        Data.Write(temporary, FileFact.Capture(snapshot));
        Flush(temporary);
        File.Move(temporary, Path.Combine(directory, "current.json"), true);
        WriteDashboard(ledger);
    }

    private static void Flush(string path)
    {
        using var stream = new FileStream(path, FileMode.Open, FileAccess.ReadWrite, FileShare.Read);
        stream.Flush(true);
    }

    internal static Partition? Select(Ledger ledger) =>
        ledger.Partitions.Where(p => p.State is "pending" or "regressed")
            .OrderBy(p => p.Includes.Any(i => i.Spelling.Equals("wmcontainer.h", StringComparison.OrdinalIgnoreCase)) ? 0 :
                p.Id is "Foundation" or "Registry" ? 1 : 2)
            .ThenByDescending(p => p.Includes.Select(i => i.Header).Where(h => h != null)
                .Select(h => ledger.Headers.First(x => x.Id == h).Consumers.Count).DefaultIfEmpty(0).Max())
            .ThenBy(p => p.Id, StringComparer.Ordinal).FirstOrDefault();

    internal static void Validate(Ledger ledger, bool evidence)
    {
        Data.Require(ledger.SchemaVersion == 1 && ledger.Pins?.SchemaVersion == 1, "Unsupported ledger/pin schema.");
        Data.Require(ledger.Partitions.Count > 0 && ledger.Headers.Count > 0 && ledger.Inputs.Count > 0, "Empty inventory.");
        Data.Require(ledger.Pins.Architectures.SequenceEqual(Vocabulary.Architectures), "Missing or reordered architecture.");
        Unique(ledger.Partitions.Select(p => p.Id), "partition");
        Unique(ledger.Headers.Select(h => h.Id), "header");
        Unique(ledger.Inputs.Select(h => h.Id), "input");
        var headers = ledger.Headers.ToDictionary(h => h.Id, StringComparer.Ordinal);
        var partitions = ledger.Partitions.Select(p => p.Id).ToHashSet(StringComparer.Ordinal);
        foreach (var partition in ledger.Partitions)
        {
            Data.Require(Vocabulary.States.Contains(partition.State), $"Unknown partition state: {partition.Id}");
            Data.Require(!Vocabulary.Terminal.Contains(partition.State), "Partition closures must be derived from obligations, not seeded.");
            foreach (var include in partition.Includes.Where(i => i.Header != null))
                Data.Require(headers.ContainsKey(include.Header!), $"Missing header: {include.Header}");
            foreach (var include in partition.Includes.Where(i => i.CompilerSource != null))
                Data.Require(ledger.Inputs.Any(i => i.Role == "compiler-resource" && Census.Key(i.Path) == Census.Key(include.CompilerSource!)),
                    $"Unrecorded external compiler header: {include.CompilerSource}");
            if (partition.State == "blocked")
                Data.Require(!string.IsNullOrWhiteSpace(partition.Blocker) && !string.IsNullOrWhiteSpace(partition.BlockerOwner) &&
                    partition.RetryFingerprint != null, $"Incomplete blocker: {partition.Id}");
            foreach (var (architecture, capture) in partition.Captures)
            {
                Data.Require(Vocabulary.Architectures.Contains(architecture), $"Unknown capture architecture: {architecture}");
                Data.Require(capture.SymbolCount > 0 && capture.ObligationCount >= capture.SymbolCount, "Empty or inconsistent symbol inventory.");
                if (evidence)
                {
                    capture.Manifest.Verify();
                    capture.Symbols.Verify();
                    foreach (var dependency in capture.Dependencies) dependency.Verify();
                    Data.Require(NativeInventory.IsCurrent(ledger, partition, architecture, capture), "Stale native dependency fingerprint.");
                    long symbols = 0, obligations = 0;
                    var identities = new HashSet<string>(StringComparer.Ordinal);
                    foreach (var line in File.ReadLines(capture.Symbols.Path))
                    {
                        var symbol = System.Text.Json.JsonSerializer.Deserialize<NativeSymbol>(line, Data.Json)!;
                        Data.Require(identities.Add(symbol.Id), $"Duplicate native identity: {symbol.Id}");
                        Data.Require(symbol.Architecture == architecture && symbol.Partition == partition.Id &&
                            symbol.Fingerprint == capture.Fingerprint, "Capture identity mismatch.");
                        Data.Require(headers.ContainsKey(symbol.Header), $"Unrecorded source: {symbol.Source}");
                        Data.Require(symbol.Families.Length > 0 && symbol.Families.All(Vocabulary.Families.Contains), "Missing semantic families.");
                        symbols++;
                        obligations += symbol.Families.Length;
                    }
                    Data.Require(symbols == capture.SymbolCount && obligations == capture.ObligationCount, "Symbol/obligation count mismatch.");
                }
            }
        }
        foreach (var header in ledger.Headers)
        {
            Data.Require(new[] { "direct-root", "transitive", "catalog-only" }.Contains(header.Selection), $"Unknown source selection: {header.Id}");
            Data.Require(Vocabulary.States.Contains(header.State), $"Unknown header state: {header.Id}");
            Unique(header.Consumers, $"consumer of {header.Id}");
            Data.Require(header.Consumers.All(partitions.Contains), $"Unknown consumer: {header.Id}");
            Data.Require(header.Owner == "unassigned" ? header.Consumers.Count == 0 : header.Consumers.Contains(header.Owner),
                $"Invalid or duplicate ownership: {header.Id}");
            if (Vocabulary.Terminal.Contains(header.State))
            {
                Data.Require(header.LastVerifiedFingerprint == ledger.Fingerprint && header.Disposition != null &&
                    header.RemainingFamilies.Length == 0, $"Unproven terminal header: {header.Id}");
                if (evidence) Dispositions.Verify(ledger, header, Data.Read<Disposition>(header.Disposition.Path));
            }
        }
        Data.Require(ledger.Runlog.Count == ledger.Sequence &&
            ledger.Runlog.Select(e => e.Sequence).SequenceEqual(Enumerable.Range(1, checked((int)ledger.Sequence)).Select(i => (long)i)),
            "Checkpoint/runlog sequence mismatch.");
        if (evidence)
        {
            foreach (var input in ledger.AuditInputs) input.Evidence.Verify();
            ledger.Tool!.Verify();
            ledger.Libclang!.Verify();
            ledger.Reference!.Verify();
        }
    }

    private static void Unique(IEnumerable<string> values, string kind)
    {
        var seen = new HashSet<string>(StringComparer.Ordinal);
        foreach (var value in values) Data.Require(seen.Add(value), $"Duplicate {kind}: {value}");
    }

    internal static bool IsActive(ActiveJob job)
    {
        try
        {
            using var process = Process.GetProcessById(job.ProcessId);
            return process.StartTime.ToUniversalTime() == job.StartTime.ToUniversalTime() && !process.HasExited;
        }
        catch (ArgumentException) { return false; }
    }

    internal void WriteDashboard(Ledger ledger)
    {
        var text = new StringBuilder("# Full SDK annotation loop\n\n");
        text.AppendLine($"Checkpoint: {ledger.Sequence}; source: `{ledger.Head}`; fingerprint: `{ledger.Fingerprint}`.\n");
        text.AppendLine("**Best-effort sweep incomplete. Discovery is not semantic closure. OPEN residuals are retained for one final review.**\n");
        text.AppendLine($"Partitions: {ledger.Partitions.Count}; provider/catalog records (NOT conversion denominator): {ledger.Headers.Count}; " +
            $"resolved distinct direct headers: {ledger.Partitions.SelectMany(p => p.Includes).Select(i => i.Header).Where(h => h != null).Distinct().Count()}; " +
            $"unresolved direct include occurrences: {ledger.Partitions.SelectMany(p => p.Includes).Count(i => i.Header == null && i.CompilerSource == null)}.\n");
        text.AppendLine($"Discovered symbol-context rows: {ledger.Partitions.Sum(p => p.Captures.Values.Sum(c => c.SymbolCount))}; " +
            $"pending semantic obligations in those rows: {ledger.Partitions.Sum(p => p.Captures.Values.Sum(c => c.ObligationCount))}. " +
            "These are architecture/TU occurrences, not deduplicated SDK symbol coverage.\n");
        text.AppendLine($"Terminal headers: {ledger.Headers.Count(h => Vocabulary.Terminal.Contains(h.State))}; " +
            $"undiscovered partition/architecture contexts: {ledger.Partitions.Sum(p => 3 - p.Captures.Count)}.\n");
        text.AppendLine($"Selected source records: {ledger.Headers.Count(h => h.Selection != "catalog-only")}; " +
            $"catalog-only records outside the current conversion denominator: {ledger.Headers.Count(h => h.Selection == "catalog-only")}.\n");
        text.AppendLine($"Next deterministic discovery batch: `{ledger.NextItem ?? "(none)"}`. Active: `{ledger.ActiveJob?.Partition ?? "(none)"}`.\n");
        text.AppendLine("## Open reconciliation gates\n");
        foreach (var gap in ledger.ReconciliationGaps) text.AppendLine($"- {gap}");
        text.AppendLine("\n## Partition queue\n\n| Partition | State | Architectures captured | Blocker |\n| --- | --- | --- | --- |");
        foreach (var p in ledger.Partitions)
            text.AppendLine($"| {p.Id} | {p.State} | {string.Join(", ", p.Captures.Keys)} | {p.Blocker?.Replace("|", "\\|").Replace("\n", " ")} |");
        text.AppendLine("\n## Recent journal\n");
        foreach (var e in ledger.Runlog.TakeLast(20))
            text.AppendLine($"- {e.Sequence}: {e.Time:O} {e.Action} `{e.Item}`: {e.Detail}");
        File.WriteAllText(Path.Combine(directory, "dashboard.md"), text.ToString(), new UTF8Encoding(false));
    }

    public void Dispose() => lease.Dispose();
}
