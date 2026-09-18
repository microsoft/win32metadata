using System.Diagnostics;

namespace AnnotationRollout;

internal static class Program
{
    private static Dictionary<string, string> Options(string[] args)
    {
        var options = new Dictionary<string, string>(StringComparer.Ordinal);
        for (int i = 1; i < args.Length; i += 2)
        {
            Data.Require(args[i].StartsWith("--", StringComparison.Ordinal) && i + 1 < args.Length, "Options require --name value.");
            Data.Require(options.TryAdd(args[i][2..], args[i + 1]), "Duplicate option.");
        }
        return options;
    }

    internal static int Main(string[] args)
    {
        try
        {
            if (args.Length == 0) throw new InvalidDataException(
                "Commands: bootstrap, refresh, discover, verify, status, resume, retry, accept, export, self-test. " +
                "All state commands require --state <directory>. Bootstrap also requires --root, --evidence, --tool, --resource.");
            if (args[0] == "self-test") return SelfTests.Run();
            var options = Options(args);
            string Required(string name) => options.TryGetValue(name, out var value) ? value : throw new InvalidDataException($"Missing --{name}.");
            if (args[0] == "self-test-native")
                return SelfTests.RunNative(Required("root"), Required("libclang"), Required("resource"), Required("sdk"), Required("output"));
            using var store = new Store(Required("state"));
            if (args[0] == "bootstrap")
            {
                Data.Require(!store.Exists, "State already exists; never overwrite a prior run. Use a fresh state/evidence directory.");
                var ledger = Census.Bootstrap(Required("root"), Required("evidence"), Required("tool"), Required("resource"),
                    options.GetValueOrDefault("providers"));
                store.Save(ledger, "bootstrap", "canonical-sdk", "Fresh census, no inherited acceptance statuses.");
                Console.WriteLine($"Bootstrapped {ledger.Partitions.Count} partitions, {ledger.Headers.Count} provider/catalog records, " +
                    $"{ledger.Partitions.SelectMany(p => p.Includes).Select(i => i.Header).Where(h => h != null).Distinct().Count()} resolved direct headers. " +
                    $"Next: {ledger.NextItem}. Native symbol denominator remains incomplete.");
                return 0;
            }
            var state = store.Load();
            switch (args[0])
            {
                case "refresh":
                    Data.Require(state.ActiveJob == null, "Cannot refresh while a job is in flight.");
                    var fresh = Census.Bootstrap(state.Repository, Required("evidence"), state.Tool!.Path, state.ResourceDirectory,
                        options.GetValueOrDefault("providers") ?? state.ProviderManifest?.Path);
                    Census.ReuseDiscovery(state, fresh);
                    fresh.Sequence = state.Sequence;
                    fresh.Runlog = state.Runlog;
                    fresh.DraftPr = state.DraftPr;
                    store.Save(fresh, "refresh", "canonical-sdk",
                        "New census; unchanged native dependency captures reused; semantic dispositions require replay, never recompilation for policy-only edits.");
                    Console.WriteLine($"Refreshed; reused {fresh.Partitions.Sum(p => p.Captures.Count)} partition/architecture captures.");
                    break;
                case "status":
                    store.WriteDashboard(state);
                    Console.WriteLine($"Checkpoint {state.Sequence}, next={state.NextItem}, active={state.ActiveJob?.Partition ?? "none"}, " +
                        $"blocked={state.Partitions.Count(p => p.State == "blocked")}, terminalHeaders={state.Headers.Count(h => Vocabulary.Terminal.Contains(h.State))}");
                    break;
                case "verify":
                    bool current = Census.Reconcile(state);
                    if (!current) store.Save(state, "invalidate", "source", "Changed or missing inputs; every dependent success invalidated.");
                    Data.Require(current, "Source fingerprint is stale. Bootstrap a fresh census; old evidence is preserved.");
                    Store.Validate(state, true);
                    Console.WriteLine("Ledger, source fingerprint and recorded evidence verified. This does not declare rollout completion.");
                    break;
                case "resume":
                    if (state.ActiveJob != null)
                    {
                        Data.Require(!Store.IsActive(state.ActiveJob), "Recorded worker is still active; duplicate worker rejected.");
                        var p = state.Partitions.Single(p => p.Id == state.ActiveJob.Partition);
                        p.State = "blocked";
                        p.Blocker = $"Interrupted worker; inspect retained evidence at {state.ActiveJob.EvidenceDirectory} before retry.";
                        p.BlockerOwner = "integration";
                        p.RetryFingerprint = state.ActiveJob.Fingerprint;
                        state.ActiveJob = null;
                        store.Save(state, "recover", p.Id, p.Blocker);
                    }
                    else Console.WriteLine("No interrupted worker; exact checkpoint is ready.");
                    break;
                case "retry":
                    Data.Require(Census.Reconcile(state), "Source census stale; bootstrap first.");
                    var retry = state.Partitions.Single(p => p.Id == Required("partition"));
                    Data.Require(retry.State == "blocked", "Only a recorded blocker can be retried.");
                    var reason = Required("reason");
                    Data.Require(reason.Trim().Length >= 20, "Record a concrete investigation/change before retrying the same fingerprint.");
                    retry.State = "pending";
                    store.Save(state, "authorize-retry", retry.Id, reason);
                    break;
                case "discover":
                    Data.Require(state.ActiveJob == null, "In-flight worker recorded; use resume after checking process state.");
                    if (!Census.Reconcile(state))
                    {
                        store.Save(state, "invalidate", "source", "Source universe changed; discovery refused.");
                        throw new InvalidDataException("Source universe changed; bootstrap a fresh reconciled census.");
                    }
                    Store.Validate(state, true);
                    int limit = options.TryGetValue("limit", out var count) ? int.Parse(count) : 1;
                    Data.Require(limit is >= 1 and <= 16, "Discovery batches must be bounded to 1..16 partitions.");
                    var requestedPartition = options.GetValueOrDefault("partition");
                    Data.Require(requestedPartition == null || limit == 1, "Explicit partition discovery is a single bounded batch.");
                    bool batchBlocked = false;
                    for (int i = 0; i < limit; i++)
                    {
                        var selected = requestedPartition == null ? Store.Select(state) : state.Partitions.Single(p => p.Id == requestedPartition);
                        if (selected == null) { Console.WriteLine("No ready discovery item. Review unresolved semantic/blocked work; rollout remains incomplete."); break; }
                        Data.Require(selected.State is "pending" or "regressed", "Selected partition is not ready; use explicit retry for a recorded blocker.");
                        Data.Require(state.Providers == null || state.Providers.Partition == selected.Id,
                            "Partition has no matching prepared provider closure. Prepare its providers and refresh before discovery.");
                        Discover(store, state, selected);
                        batchBlocked |= selected.State == "blocked";
                    }
                    if (batchBlocked) return 2;
                    break;
                case "accept":
                    Data.Require(Census.Reconcile(state), "Stale source cannot accept dispositions.");
                    var file = Required("disposition");
                    var disposition = Data.Read<Disposition>(file);
                    var header = state.Headers.Single(h => h.Id == disposition.Header);
                    Dispositions.Verify(state, header, disposition);
                    header.State = disposition.Verdict;
                    header.Disposition = FileFact.Capture(file);
                    header.LastVerifiedFingerprint = state.Fingerprint;
                    header.RemainingFamilies = [];
                    store.Save(state, "accept", header.Id, disposition.Verdict);
                    break;
                case "export":
                    Store.Validate(state, true);
                    var destination = Path.GetFullPath(Required("output"));
                    Directory.CreateDirectory(destination);
                    Data.Write(Path.Combine(destination, "manifest.json"), new
                    {
                        state.SchemaVersion,
                        state.Sequence,
                        state.Fingerprint,
                        state.Head,
                        state.Pins,
                        state.EvidenceRoot,
                        checkpoint = store.CurrentCheckpoint,
                        state.Tool,
                        state.Libclang,
                        state.Reference,
                        state.ProviderManifest,
                        state.NextItem,
                        state.ActiveJob,
                        state.DraftPr,
                        state.ReconciliationGaps,
                        partitionCount = state.Partitions.Count,
                        providerCatalogCount = state.Headers.Count,
                        selectedSourceCount = state.Headers.Count(h => h.Selection != "catalog-only"),
                        resolvedDirectHeaderCount = state.Partitions.SelectMany(p => p.Includes).Select(i => i.Header).Where(h => h != null).Distinct().Count(),
                        distinctDirectIncludeSpellings = state.Partitions.SelectMany(p => p.Includes).Select(i => i.Spelling.ToLowerInvariant()).Distinct().Count(),
                        unresolvedDirectIncludes = state.Partitions.SelectMany(p => p.Includes.Where(i => i.Header == null && i.CompilerSource == null).Select(i => new { partition = p.Id, include = i })).ToArray(),
                        complete = false
                    });
                    Data.Write(Path.Combine(destination, "partitions.json"), state.Partitions);
                    var compact = new System.Text.Json.JsonSerializerOptions(Data.Json) { WriteIndented = false };
                    using (var writer = new StreamWriter(Path.Combine(destination, "headers.jsonl")))
                        foreach (var h in state.Headers)
                            writer.WriteLine(System.Text.Json.JsonSerializer.Serialize(new
                            {
                                h.Id,
                                h.Sha256,
                                h.Origin,
                                h.Selection,
                                h.Owner,
                                h.Consumers,
                                h.State,
                                h.Patches,
                                h.Generated,
                                conditionDirectiveCount = h.Conditions.Length,
                                h.LastVerifiedFingerprint,
                                h.Disposition
                            }, compact));
                    Data.Write(Path.Combine(destination, "audit-inputs.json"), state.AuditInputs);
                    Data.Write(Path.Combine(destination, "runlog.json"), state.Runlog);
                    store.WriteDashboard(state);
                    File.Copy(Path.Combine(Required("state"), "dashboard.md"), Path.Combine(destination, "dashboard.md"), true);
                    Console.WriteLine($"Exported nonterminal checkpoint {state.Sequence} to {destination}.");
                    break;
                default: throw new InvalidDataException($"Unknown command: {args[0]}");
            }
            return 0;
        }
        catch (Exception error) when (error is InvalidDataException or IOException or InvalidOperationException or
            ArgumentException or System.Text.Json.JsonException or KeyNotFoundException)
        {
            Console.Error.WriteLine($"ERROR: {error.Message}");
            return 1;
        }
    }

    private static void Discover(Store store, Ledger ledger, Partition partition)
    {
        var directory = Path.Combine(ledger.EvidenceRoot, "discovery", $"{ledger.Sequence + 1:D6}-{partition.Id}");
        var retryFingerprint = Data.Identity(ledger.Fingerprint, partition.Id,
            string.Join("\n", Vocabulary.Architectures.SelectMany(a => NativeInventory.Arguments(ledger, a))));
        Data.Require(partition.RetryFingerprint != retryFingerprint ||
            ledger.Runlog.LastOrDefault(e => e.Item == partition.Id)?.Action == "authorize-retry",
            "Identical retry fingerprint requires recorded investigation, not blind retry.");
        using var process = Process.GetCurrentProcess();
        partition.State = "investigating";
        ledger.ActiveJob = new(partition.Id, process.Id, process.StartTime, retryFingerprint, directory);
        store.Save(ledger, "claim", partition.Id, $"Bounded sequential multiarchitecture discovery: {directory}");
        bool failed = false;
        try
        {
            foreach (var architecture in Vocabulary.Architectures)
            {
                if (partition.Captures.TryGetValue(architecture, out var cached) &&
                    NativeInventory.IsCurrent(ledger, partition, architecture, cached))
                {
                    failed |= cached.HasErrors;
                    store.Save(ledger, "reuse-capture", partition.Id, $"{architecture}: exact TU/compiler/include dependencies unchanged.");
                    continue;
                }
                var capture = NativeInventory.Capture(ledger, partition, architecture, Path.Combine(directory, architecture));
                Data.Require(capture.SymbolCount > 0, "Compiler capture has no source symbols.");
                partition.Captures[architecture] = capture;
                foreach (var id in capture.IncludedHeaders)
                {
                    var header = ledger.Headers.Single(h => h.Id == id);
                    header.Consumers.Add(partition.Id);
                    if (header.Selection == "catalog-only") header.Selection = "transitive";
                }
                Census.AssignOwners(ledger);
                failed |= capture.HasErrors;
                store.Save(ledger, "capture", partition.Id,
                    $"{architecture}: {capture.SymbolCount} source-context rows; {capture.ObligationCount} pending family-screening slots; hasErrors={capture.HasErrors}.");
            }
            partition.State = failed ? "blocked" : "validating";
            partition.Blocker = failed ? $"Native parse/source completeness failed. Retained diagnostics: {directory}" : null;
            partition.BlockerOwner = failed ? "integration-source-triage" : null;
            partition.RetryFingerprint = retryFingerprint;
        }
        catch (Exception error) when (error is IOException or InvalidDataException or InvalidOperationException or System.Runtime.InteropServices.ExternalException)
        {
            partition.State = "blocked";
            partition.Blocker = error.Message;
            partition.BlockerOwner = "integration";
            partition.RetryFingerprint = retryFingerprint;
            Directory.CreateDirectory(directory);
            Data.Write(Path.Combine(directory, "failure.json"), new { error = error.ToString(), retryFingerprint });
            Console.Error.WriteLine($"BLOCKED {partition.Id}: {error.Message}");
        }
        finally
        {
            ledger.ActiveJob = null;
            store.Save(ledger, "checkpoint", partition.Id,
                $"{partition.State}; native discovery never closes semantic obligations; retained evidence={directory}");
        }
        Console.WriteLine($"{partition.Id}: {partition.State}; next={ledger.NextItem}");
    }
}
