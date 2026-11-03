using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;

namespace WinmdUtilsProgram
{
    internal sealed class WinmdReviewBatch
    {
        internal sealed class Options
        {
            public string ComparisonLog { get; set; }
            public string First { get; set; }
            public string Second { get; set; }
            public string OutputDirectory { get; set; }
            public string GeneratedDirectory { get; set; }
            public string[] ScratchDirectories { get; set; } = Array.Empty<string>();
            public string JobBindings { get; set; }
            public string Blockers { get; set; }
            public string Boundary { get; set; }
            public string Purpose { get; set; } = "prototype";
            public int ShardSize { get; set; } = 750;
        }

        internal sealed class Delta
        {
            public string Id { get; set; }
            public int DuplicateOrdinal { get; set; }
            public int RawLineNumber { get; set; }
            public string RawLine { get; set; }
            public string Symbol { get; set; }
            public string Target { get; set; }
            public string Kind { get; set; }
            public string OldText { get; set; }
            public string NewText { get; set; }
            public string Family { get; set; }
            public string[] BlockerIds { get; set; } = Array.Empty<string>();
            public string SourceKey { get; set; }
            public string[] OldMetadataKeys { get; set; }
            public string[] NewMetadataKeys { get; set; }
            public string Shard { get; set; }
            public string ReviewStatus { get; set; } = "unreviewed";
        }

        internal sealed class Blocker
        {
            public string Id { get; set; }
            public string[] Symbols { get; set; }
            public string Reason { get; set; }
            public string EvidencePath { get; set; }
            public string EvidenceSha256 { get; set; }
        }

        private static readonly JsonSerializerOptions JsonOptions = new()
        {
            PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
            PropertyNameCaseInsensitive = true,
            WriteIndented = true,
        };

        internal static string HashFile(string path) => Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path)));

        internal static string HashText(string text) => Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(text)));

        internal static List<Delta> Parse(string text)
        {
            if (text.StartsWith('\uFEFF'))
                text = text.Substring(1);
            string[] lines = Regex.Split(text, "\r\n|\n|\r");
            int length = lines.Length;
            if (length > 0 && lines[length - 1].Length == 0)
                length--;
            if (length == 1 && lines[0] == "No unknown differences found.")
                return new List<Delta>();
            if (length < 2 || lines[0] != "Unknown differences found:")
                throw new InvalidDataException("Expected a complete unsuppressed comparison, not a tool error or known-difference report.");

            var occurrences = new Dictionary<string, int>(StringComparer.Ordinal);
            var result = new List<Delta>(length - 1);
            for (int i = 1; i < length; i++)
            {
                string line = lines[i];
                if (line.Length == 0 || line == "Unknown differences found:" ||
                    line == "No unknown differences found." || line.StartsWith("Items from the known differences", StringComparison.Ordinal))
                    throw new InvalidDataException($"Unexpected comparison record at physical line {i + 1}.");
                occurrences.TryGetValue(line, out int occurrence);
                occurrences[line] = ++occurrence;
                var delta = ParseLine(line);
                delta.RawLine = line;
                delta.RawLineNumber = i + 1;
                delta.DuplicateOrdinal = occurrence;
                delta.Id = "delta-" + HashText(line + "\0" + occurrence.ToString(System.Globalization.CultureInfo.InvariantCulture));
                result.Add(delta);
            }
            return result;
        }

        private static Delta ParseLine(string line)
        {
            var delta = new Delta { Kind = "unparsed", Family = "unclassified" };
            string body = line;
            var value = Regex.Match(line, @"^winmd1: (?<symbol>.+?) = (?<old>.*), winmd2 = (?<new>.*)$");
            if (value.Success)
            {
                delta.Symbol = value.Groups["symbol"].Value;
                delta.OldText = value.Groups["old"].Value;
                delta.NewText = value.Groups["new"].Value;
                delta.Kind = "value";
                delta.Family = "values";
                return delta;
            }
            foreach (string suffix in new[] { " removed", " added" })
            {
                if (body.EndsWith(suffix, StringComparison.Ordinal))
                {
                    delta.Symbol = body.Substring(0, body.Length - suffix.Length);
                    delta.Kind = suffix.Trim();
                    delta.Family = delta.Kind == "removed" ? "removals" : "additions";
                    delta.OldText = delta.Kind == "removed" ? delta.Symbol : null;
                    delta.NewText = delta.Kind == "added" ? delta.Symbol : null;
                    return delta;
                }
            }

            int arrow = body.IndexOf(" => ", StringComparison.Ordinal);
            if (arrow >= 0)
            {
                string left = body.Substring(0, arrow);
                delta.NewText = body.Substring(arrow + 4);
                int separator = left.IndexOf("...", StringComparison.Ordinal);
                if (separator >= 0)
                {
                    delta.Symbol = left.Substring(0, separator);
                    delta.OldText = left.Substring(separator + 3);
                    delta.Kind = "type-or-signature";
                    delta.Family = "type-signature-enum-identity";
                }
                else
                {
                    int attributes = left.LastIndexOf(" : ", StringComparison.Ordinal);
                    if (attributes >= 0)
                    {
                        delta.Symbol = left.Substring(0, attributes);
                        delta.OldText = left.Substring(attributes + 3);
                        delta.Kind = "attributes";
                        string pair = delta.OldText + " " + delta.NewText;
                        delta.Family = pair.Contains("NativeArrayInfo", StringComparison.Ordinal) ||
                            pair.Contains("AssociatedEnum", StringComparison.Ordinal) ||
                            pair.Contains("MemorySize", StringComparison.Ordinal)
                            ? "association-array"
                            : pair.Contains("SupportedOSPlatform", StringComparison.Ordinal) ||
                              pair.Contains("RAIIFree", StringComparison.Ordinal) ||
                              pair.Contains("InvalidHandleValue", StringComparison.Ordinal) ||
                              pair.Contains("DoNotRelease", StringComparison.Ordinal)
                                ? "availability-ownership"
                                : Regex.IsMatch(pair, @"\b(In|Out|Optional|RetVal|NativeConst|ComOutPtr)\b")
                                    ? "direction-sal"
                                    : "other-attributes";
                    }
                    else
                    {
                        delta.Symbol = left;
                        delta.OldText = left;
                        delta.Kind = "identity";
                        delta.Family = "type-signature-enum-identity";
                    }
                }
            }
            else
            {
                var initializerType = Regex.Match(body, @"^(?<symbol>.+) value init changed (?<old>.+)->(?<new>.+)$");
                if (initializerType.Success)
                {
                    delta.Symbol = initializerType.Groups["symbol"].Value;
                    delta.OldText = initializerType.Groups["old"].Value;
                    delta.NewText = initializerType.Groups["new"].Value;
                    delta.Kind = "constant-storage";
                    delta.Family = "type-signature-enum-identity";
                }
                else
                {
                    delta.Symbol = body.StartsWith("winmd1: ", StringComparison.Ordinal) ||
                        body.StartsWith("winmd2: ", StringComparison.Ordinal) ? body.Substring(8) : body;
                }
            }
            int target = delta.Symbol.IndexOf(" : ", StringComparison.Ordinal);
            if (target >= 0)
            {
                delta.Target = delta.Symbol.Substring(target + 3);
                delta.Symbol = delta.Symbol.Substring(0, target);
            }
            return delta;
        }

        internal static string Create(Options options)
        {
            if (options.ShardSize < 500 || options.ShardSize > 1000)
                throw new ArgumentOutOfRangeException(nameof(options.ShardSize), "Use review shards of 500 to 1000 differences.");
            if (options.Purpose != "prototype" && options.Purpose != "conversion-wave")
                throw new ArgumentException("Purpose must be prototype or conversion-wave.");
            string output = Path.GetFullPath(options.OutputDirectory);
            if (Directory.Exists(output) || File.Exists(output))
                throw new IOException("Use a new review directory; existing review evidence must not be overwritten.");
            foreach (string input in new[] { options.ComparisonLog, options.First, options.Second, options.GeneratedDirectory,
                options.JobBindings, options.Blockers, options.Boundary }.Concat(options.ScratchDirectories))
            {
                if (input == null)
                    continue;
                string full = Path.GetFullPath(input);
                if (full.Equals(output, StringComparison.OrdinalIgnoreCase) ||
                    full.StartsWith(output + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase) ||
                    Directory.Exists(full) && output.StartsWith(full + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase))
                    throw new IOException("Review output must not overlap any input.");
            }
            string logHash = HashFile(options.ComparisonLog);
            string firstHash = HashFile(options.First);
            string secondHash = HashFile(options.Second);
            var deltas = Parse(new UTF8Encoding(false, true).GetString(File.ReadAllBytes(options.ComparisonLog)));
            if (options.Purpose == "conversion-wave")
            {
                if (options.Boundary == null)
                    throw new InvalidDataException("A final conversion-wave review requires its actual new producer boundary.");
                using var boundary = JsonDocument.Parse(File.ReadAllText(options.Boundary));
                var root = boundary.RootElement;
                if (root.GetProperty("purpose").GetString() != "conversion-wave" ||
                    root.GetProperty("oldWinmdSha256").GetString() != firstHash ||
                    root.GetProperty("newWinmdSha256").GetString() != secondHash ||
                    root.GetProperty("comparisonLogSha256").GetString() != logHash ||
                    root.GetProperty("producerCompleted").GetBoolean() != true)
                    throw new InvalidDataException("The review boundary does not bind this completed NEW conversion-wave producer and exact comparison.");
            }

            Blocker[] blockers = options.Blockers == null ? Array.Empty<Blocker>() :
                JsonSerializer.Deserialize<Blocker[]>(File.ReadAllText(options.Blockers), JsonOptions);
            if (blockers == null || blockers.Any(b => string.IsNullOrEmpty(b.Id) || b.Symbols == null || b.Symbols.Length == 0 ||
                string.IsNullOrEmpty(b.Reason)) || blockers.Select(b => b.Id).Distinct(StringComparer.Ordinal).Count() != blockers.Length)
                throw new InvalidDataException("Every family blocker requires a unique ID, exact symbol selectors and a reason.");
            foreach (var blocker in blockers)
            {
                if (blocker.EvidencePath != null && HashFile(blocker.EvidencePath) != blocker.EvidenceSha256)
                    throw new InvalidDataException($"Family blocker evidence changed: {blocker.Id}");
            }

            var sources = new WinmdReviewSourceIndex(options);
            using var oldMetadata = new WinmdReviewMetadata(options.First);
            using var newMetadata = new WinmdReviewMetadata(options.Second);
            foreach (var delta in deltas)
            {
                delta.SourceKey = sources.Resolve(delta.Symbol);
                delta.OldMetadataKeys = oldMetadata.Resolve(delta.Symbol);
                delta.NewMetadataKeys = newMetadata.Resolve(delta.Symbol);
                delta.BlockerIds = blockers.Where(b => b.Symbols.Any(symbol =>
                    ContainsSymbol(delta.RawLine, symbol))).Select(b => b.Id).ToArray();
            }

            var ordered = deltas.OrderBy(d => d.BlockerIds.Length == 0 ? 1 : 0)
                .ThenBy(d => d.Family, StringComparer.Ordinal)
                .ThenBy(d => d.Symbol, StringComparer.Ordinal)
                .ThenBy(d => d.Id, StringComparer.Ordinal).ToArray();
            int shardCount = deltas.Count == 0 ? 0 : (int)Math.Ceiling((double)deltas.Count / options.ShardSize);
            while (shardCount > 1 && deltas.Count / shardCount < 500 && (deltas.Count + shardCount - 2) / (shardCount - 1) <= 1000)
                shardCount--;
            var shards = new List<object>();
            var payloads = new List<(string Name, Delta[] Items)>();
            int offset = 0;
            for (int i = 0; i < shardCount; i++)
            {
                int count = deltas.Count / shardCount + (i < deltas.Count % shardCount ? 1 : 0);
                string id = $"shard-{i + 1:D4}";
                var items = ordered.Skip(offset).Take(count).ToArray();
                foreach (var delta in items)
                    delta.Shard = id;
                offset += count;
                payloads.Add((id, items));
                shards.Add(new
                {
                    id,
                    path = Path.Combine("shards", id + ".jsonl"),
                    count,
                    families = items.GroupBy(d => d.Family).Select(g => new { family = g.Key, count = g.Count() }),
                    blockerIds = items.SelectMany(d => d.BlockerIds).Distinct(StringComparer.Ordinal),
                    reviewStatus = "unreviewed",
                });
            }
            if (offset != deltas.Count || ordered.Select(d => d.Id).Distinct(StringComparer.Ordinal).Count() != deltas.Count)
                throw new InvalidDataException("Review sharding lost or duplicated a raw difference.");

            Directory.CreateDirectory(Path.Combine(output, "shards"));
            File.Copy(options.ComparisonLog, Path.Combine(output, "comparison.raw.log"));
            WriteLines(Path.Combine(output, "inventory.jsonl"), deltas);
            WriteLines(Path.Combine(output, "source-index.jsonl"), sources.Entries);
            WriteLines(Path.Combine(output, "metadata-old.jsonl"), oldMetadata.Entries);
            WriteLines(Path.Combine(output, "metadata-new.jsonl"), newMetadata.Entries);
            foreach (var payload in payloads)
                WriteLines(Path.Combine(output, "shards", payload.Name + ".jsonl"), payload.Items);
            WriteJson(Path.Combine(output, "families.json"), deltas.GroupBy(d => d.Family).Select(g => new
            {
                id = g.Key,
                count = g.Count(),
                deltaIds = g.Select(d => d.Id),
                shards = g.Select(d => d.Shard).Distinct(StringComparer.Ordinal),
                reviewStatus = "unreviewed",
                requiredOutcome = "One source-backed systematic fix or explicit per-site dispositions, with exception delta IDs and evidence. Clustering does not accept or remove differences.",
            }));
            WriteJson(Path.Combine(output, "blockers.json"), blockers.Select(b => new
            {
                b.Id, b.Symbols, b.Reason, b.EvidencePath, b.EvidenceSha256,
                deltaIds = deltas.Where(d => d.BlockerIds.Contains(b.Id, StringComparer.Ordinal)).Select(d => d.Id),
                status = "unaccepted",
                absenceIsNotResolution = true,
            }));
            var files = Directory.GetFiles(output, "*", SearchOption.AllDirectories).OrderBy(p => p, StringComparer.Ordinal)
                .Select(p => new { path = Path.GetRelativePath(output, p), sha256 = HashFile(p), bytes = new FileInfo(p).Length }).ToArray();
            string manifest = Path.Combine(output, "manifest.json");
            WriteJson(manifest, new
            {
                schemaVersion = 1,
                purpose = options.Purpose,
                createdUtc = DateTime.UtcNow.ToString("o"),
                comparison = new { path = Path.GetFullPath(options.ComparisonLog), sha256 = logHash },
                oldImage = new { path = Path.GetFullPath(options.First), sha256 = firstHash },
                newImage = new { path = Path.GetFullPath(options.Second), sha256 = secondHash },
                producerBoundary = options.Boundary == null ? null : new { path = Path.GetFullPath(options.Boundary), sha256 = HashFile(options.Boundary) },
                sourceContext = sources.Inputs,
                rawDifferences = deltas.Count,
                uniqueDeltaIds = deltas.Count,
                unparsedDifferences = deltas.Count(d => d.Kind == "unparsed"),
                sourceGaps = sources.Gaps,
                oldMetadataGaps = oldMetadata.Gaps,
                newMetadataGaps = newMetadata.Gaps,
                stableId = "SHA256(exact UTF-8 raw line + NUL + duplicate occurrence ordinal); independent of shard assignment and unrelated line positions",
                requestedShardSize = options.ShardSize,
                shards,
                disjointCompleteCoverage = true,
                acceptedDifferences = 0,
                normalizedOrDroppedDifferences = 0,
                imageAcceptance = false,
                consumerGrade = false,
                sourceAttribution = "Native token/traversal links are candidates, not declarations or historical producer reconstruction. Missing evidence stays explicit.",
                files,
            });
            if (HashFile(options.ComparisonLog) != logHash || HashFile(options.First) != firstHash || HashFile(options.Second) != secondHash)
                throw new IOException("A comparison input changed during review batching.");
            foreach (string path in Directory.GetFiles(output, "*", SearchOption.AllDirectories))
                File.SetAttributes(path, File.GetAttributes(path) | FileAttributes.ReadOnly);
            return manifest;
        }

        private static bool ContainsSymbol(string line, string symbol)
        {
            return Regex.IsMatch(line, @"(?<!\w)" + Regex.Escape(symbol) + @"(?!\w)");
        }

        internal static void WriteJson(string path, object value) =>
            File.WriteAllText(path, JsonSerializer.Serialize(value, JsonOptions), new UTF8Encoding(false));

        private static void WriteLines<T>(string path, IEnumerable<T> values)
        {
            var compact = new JsonSerializerOptions(JsonOptions) { WriteIndented = false };
            using var writer = new StreamWriter(path, false, new UTF8Encoding(false));
            foreach (var value in values)
                writer.WriteLine(JsonSerializer.Serialize(value, compact));
        }
    }
}
