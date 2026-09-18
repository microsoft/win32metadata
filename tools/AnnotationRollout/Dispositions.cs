using System.Text.Json;

namespace AnnotationRollout;

internal sealed record ObligationResult(
    string Symbol, string Family, string Verdict, JsonElement Expected, JsonElement Actual,
    string[] Rules, string[] ExplainedPaths, string[] RawDifferencePaths, FileFact[] Evidence);
internal sealed record Gate(string Name, string Architecture, string Fingerprint, string Header,
    string[] Command, int ExitCode, FileFact Log, FileFact Result);
internal sealed record NegativeControl(string Mutation, string Architecture, string Fingerprint,
    bool Compiled, bool Rejected, string[] RejectedPaths, FileFact MutatedSource, FileFact DecodedResult, FileFact Log);
internal sealed record Disposition(
    int SchemaVersion, string Header, string Fingerprint, string Verdict, ObligationResult[] Obligations,
    Gate[] Gates, NegativeControl[] NegativeControls, FileFact? Approval);

internal static class Dispositions
{
    internal static readonly string[] Gates = [
        "source-inventory", "native-abi", "metadata-contract", "reference-integrity", "baseline-reconciliation",
        "legacy-reconciliation", "condition-coverage", "consumer-ownership", "patch-roundtrip"
    ];
    internal static readonly string[] Mutations = [
        "missing-header", "missing-symbol", "missing-architecture", "wrong-native-type",
        "removed-annotation", "wrong-count", "wrong-closer", "missing-reference"
    ];

    internal static void Verify(Ledger ledger, Header header, Disposition result)
    {
        Data.Require(result.SchemaVersion == 1 && result.Header == header.Id && result.Fingerprint == ledger.Fingerprint,
            "Disposition has wrong header/source fingerprint/schema.");
        Data.Require(Vocabulary.Terminal.Contains(result.Verdict), "Disposition is not terminal.");
        Data.Require(header.Consumers.Count > 0, "Unreconciled source has no validated consumer.");
        var expected = new HashSet<string>(StringComparer.Ordinal);
        foreach (var consumer in header.Consumers)
        {
            var partition = ledger.Partitions.Single(p => p.Id == consumer);
            foreach (var architecture in Vocabulary.Architectures)
            {
                Data.Require(partition.Captures.TryGetValue(architecture, out var capture) &&
                    NativeInventory.IsCurrent(ledger, partition, architecture, capture) && !capture.HasErrors, $"Missing/stale/error discovery: {consumer}/{architecture}");
                capture!.Symbols.Verify();
                foreach (var line in File.ReadLines(capture.Symbols.Path))
                {
                    var symbol = JsonSerializer.Deserialize<NativeSymbol>(line, Data.Json)!;
                    if (symbol.Header != header.Id) continue;
                    foreach (var family in symbol.Families) expected.Add(Data.Identity(symbol.Id, family));
                }
            }
        }
        Data.Require(expected.Count > 0, "An empty discovered inventory cannot close a header.");
        var actual = new HashSet<string>(StringComparer.Ordinal);
        foreach (var obligation in result.Obligations)
        {
            Data.Require(actual.Add(Data.Identity(obligation.Symbol, obligation.Family)), "Duplicate obligation disposition.");
            VerifyContract(ledger.Pins!, obligation);
        }
        Data.Require(actual.SetEquals(expected), "Missing or extra symbol/family dispositions.");
        var gateKeys = new HashSet<string>();
        foreach (var gate in result.Gates)
        {
            Data.Require(gateKeys.Add(gate.Name + "/" + gate.Architecture), "Duplicate gate.");
            Data.Require(Gates.Contains(gate.Name) && Vocabulary.Architectures.Append("merged").Contains(gate.Architecture),
                "Unknown gate/architecture.");
            Data.Require(gate.Fingerprint == ledger.Fingerprint && gate.Header == header.Id &&
                gate.ExitCode == 0 && gate.Command.Length > 0, "Stale/failed/commandless gate.");
            gate.Log.Verify();
            gate.Result.Verify();
        }
        foreach (var name in Gates)
            foreach (var architecture in Vocabulary.Architectures.Append("merged"))
                Data.Require(gateKeys.Contains(name + "/" + architecture), $"Missing gate: {name}/{architecture}");
        foreach (var mutation in Mutations)
        {
            var controls = result.NegativeControls.Where(n => n.Mutation == mutation).ToArray();
            Data.Require(controls.Length > 0, $"Missing real mutation negative control: {mutation}");
            foreach (var control in controls)
            {
                Data.Require(control.Fingerprint == ledger.Fingerprint && control.Rejected && control.RejectedPaths.Length > 0 &&
                    Vocabulary.Architectures.Append("merged").Contains(control.Architecture), "Stale/ineffective negative control.");
                if (mutation is "wrong-native-type" or "removed-annotation" or "wrong-count" or "wrong-closer")
                    Data.Require(control.Compiled, "Semantic negative control did not reach compiled comparison.");
                control.MutatedSource.Verify();
                control.DecodedResult.Verify();
                control.Log.Verify();
            }
        }
        if (result.Verdict == "approved-sdk-exclusion" || result.Obligations.Any(o => o.Verdict == "approved-sdk-exclusion"))
        {
            Data.Require(result.Approval != null, "SDK exclusion requires explicit retained approval.");
            result.Approval.Verify();
        }
    }

    internal static void VerifyContract(Pins pins, ObligationResult obligation)
    {
        Data.Require(Vocabulary.Terminal.Contains(obligation.Verdict) && obligation.Evidence.Length > 0, "Missing obligation verdict/evidence.");
        Data.Require(obligation.Expected.ValueKind is not (JsonValueKind.Null or JsonValueKind.Undefined) &&
            obligation.Actual.ValueKind is not (JsonValueKind.Null or JsonValueKind.Undefined), "Missing expected/actual contract.");
        var differences = Differences(obligation.Expected, obligation.Actual).Order(StringComparer.Ordinal).ToArray();
        Data.Require(differences.SequenceEqual(obligation.RawDifferencePaths.Order(StringComparer.Ordinal)),
            "Declared raw diff omits or invents actual expected/actual contract differences.");
        Data.Require(obligation.Rules.All(pins.PolicyRules.Contains), "Unrecorded/unapproved comparison rule.");
        Data.Require(obligation.ExplainedPaths.All(obligation.RawDifferencePaths.Contains), "Explained path is absent from raw diff.");
        Data.Require(obligation.RawDifferencePaths.Length == 0 ||
            (obligation.Rules.Length > 0 && obligation.RawDifferencePaths.Order().SequenceEqual(obligation.ExplainedPaths.Order())),
            "Unexplained raw difference.");
        if (obligation.Verdict == "expected-improvement")
            Data.Require(obligation.Rules.Length > 0 && obligation.RawDifferencePaths.Length > 0, "Improvement has no bounded rule/delta.");
        foreach (var fact in obligation.Evidence) fact.Verify();
    }

    internal static IEnumerable<string> Differences(JsonElement expected, JsonElement actual, string path = "")
    {
        if (JsonElement.DeepEquals(expected, actual)) yield break;
        if (expected.ValueKind == JsonValueKind.Object && actual.ValueKind == JsonValueKind.Object)
        {
            var left = expected.EnumerateObject().ToDictionary(p => p.Name, p => p.Value, StringComparer.Ordinal);
            var right = actual.EnumerateObject().ToDictionary(p => p.Name, p => p.Value, StringComparer.Ordinal);
            foreach (var name in left.Keys.Union(right.Keys).Order(StringComparer.Ordinal))
            {
                var child = path + "/" + name.Replace("~", "~0", StringComparison.Ordinal).Replace("/", "~1", StringComparison.Ordinal);
                if (!left.TryGetValue(name, out var a) || !right.TryGetValue(name, out var b)) yield return child;
                else foreach (var difference in Differences(a, b, child)) yield return difference;
            }
        }
        else if (expected.ValueKind == JsonValueKind.Array && actual.ValueKind == JsonValueKind.Array)
        {
            for (int i = 0; i < Math.Max(expected.GetArrayLength(), actual.GetArrayLength()); i++)
            {
                var child = path + "/" + i;
                if (i >= expected.GetArrayLength() || i >= actual.GetArrayLength()) yield return child;
                else foreach (var difference in Differences(expected[i], actual[i], child)) yield return difference;
            }
        }
        else yield return path;
    }
}
