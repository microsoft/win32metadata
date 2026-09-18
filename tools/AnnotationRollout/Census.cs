using System.Diagnostics;
using System.Text.RegularExpressions;
using System.Xml.Linq;

namespace AnnotationRollout;

internal static class Commands
{
    internal static string Run(string executable, IEnumerable<string> arguments, string directory, string? log = null)
    {
        var start = new ProcessStartInfo(executable)
        {
            WorkingDirectory = directory,
            UseShellExecute = false,
            RedirectStandardOutput = true,
            RedirectStandardError = true
        };
        foreach (var argument in arguments) start.ArgumentList.Add(argument);
        using var process = Process.Start(start) ?? throw new IOException($"Cannot start {executable}");
        var stdout = process.StandardOutput.ReadToEndAsync();
        var stderr = process.StandardError.ReadToEndAsync();
        process.WaitForExit();
        Task.WaitAll(stdout, stderr);
        if (log != null)
        {
            Data.Write(log + ".command.json", new
            {
                executable,
                arguments = start.ArgumentList.ToArray(),
                workingDirectory = directory,
                exitCode = process.ExitCode
            });
            File.WriteAllText(log, stdout.Result);
            File.WriteAllText(log + ".stderr", stderr.Result);
        }
        if (process.ExitCode != 0)
            throw new IOException($"{executable} exited {process.ExitCode}: {stderr.Result.Trim()} (log: {log})");
        return stdout.Result.TrimEnd();
    }
}

internal static partial class Census
{
    [GeneratedRegex(@"(?m)^[ \t]*#[ \t]*(include|if|ifdef|ifndef|elif|else|endif)\b([^\r\n]*)")]
    private static partial Regex Directives();
    [GeneratedRegex(@"/\*.*?\*/", RegexOptions.Singleline)]
    private static partial Regex BlockComments();
    [GeneratedRegex("""^\s*([<"])([^>"]+)[>"]""")]
    private static partial Regex Include();

    internal static IEnumerable<IncludeFact> ReadIncludes(string text)
    {
        text = BlockComments().Replace(text, m => new string('\n', m.Value.Count(c => c == '\n')));
        var conditions = new List<string>();
        foreach (Match match in Directives().Matches(text))
        {
            var verb = match.Groups[1].Value;
            var tail = match.Groups[2].Value.Split("//", 2)[0].Trim();
            if (verb is "if" or "ifdef" or "ifndef") conditions.Add($"{verb} {tail}");
            else if (verb == "endif")
            {
                Data.Require(conditions.Count > 0, "Unbalanced #endif.");
                conditions.RemoveAt(conditions.Count - 1);
            }
            else if (verb is "else" or "elif")
            {
                Data.Require(conditions.Count > 0, $"Unbalanced #{verb}.");
                conditions[^1] += $" / {verb} {tail}";
            }
            else if (verb == "include")
            {
                var include = Include().Match(tail);
                yield return new(1 + text.AsSpan(0, match.Index).Count('\n'),
                    include.Success ? include.Groups[2].Value : tail,
                    include.Success && include.Groups[1].Value == "\"", string.Join(" && ", conditions), null);
            }
        }
        Data.Require(conditions.Count == 0, "Unbalanced conditional directives.");
    }

    internal static string[] Conditions(string path) =>
        Directives().Matches(BlockComments().Replace(File.ReadAllText(path), ""))
            .Where(m => m.Groups[1].Value != "include")
            .Select(m => m.Value.Trim()).ToArray();

    internal static string Key(string path) => Path.GetFullPath(path).ToUpperInvariant();
    internal static string Relative(string root, string path) => Path.GetRelativePath(root, path).Replace('/', '\\');

    internal static string[] IncludeDirectories(Ledger ledger) =>
        [Path.Combine(ledger.Repository, @"generation\WinSDK\inc"),
         Path.Combine(ledger.Repository, @"generation\WinSDK\AdditionalHeaders"),
         .. new[] { "shared", "um", "ucrt", "winrt" }.Select(p => Path.Combine(ledger.SdkRoot, p))];

    internal static Ledger Bootstrap(string root, string evidence, string tool, string resource)
    {
        root = Path.GetFullPath(root);
        evidence = Path.GetFullPath(evidence);
        resource = Path.GetFullPath(resource);
        var pins = Data.Read<Pins>(Path.Combine(root, @"generation\WinSDK\rollout\pins.json"));
        Data.Require(pins.Architectures.SequenceEqual(Vocabulary.Architectures), "Architecture pins incomplete.");
        foreach (var commit in new[] { pins.PilotCommit, pins.ToolingCommit })
            Commands.Run("git", ["merge-base", "--is-ancestor", commit, "HEAD"], root);
        Data.Require(Commands.Run("git", ["diff", pins.ToolingCommit, "--", "tools/rust"], root).Length == 0,
            "Tooling source changed relative to immutable pin.");
        var cargo = File.ReadAllText(Path.Combine(root, @"tools\rust\Cargo.toml"));
        Data.Require(Regex.Matches(cargo, "rev = \"([a-f0-9]+)\"").All(m => m.Groups[1].Value == pins.WindowsRsCommit),
            "windows-rs revision mismatch.");
        var projectPath = Path.Combine(root, @"generation\WinSDK\Windows.Win32.proj");
        var project = XDocument.Load(projectPath);
        Data.Require(project.Descendants("Partition").Single().Attribute("Include")?.Value == @"Partitions\**\main.cpp",
            "Unsupported canonical Partition glob; update census explicitly.");
        Data.Require(project.Descendants("PackageReference").Any(e => e.Attribute("Include")?.Value == "Microsoft.Windows.SDK.CPP.x64" &&
            e.Attribute("Version")?.Value == pins.SdkVersion), "Project SDK pin mismatch.");
        var packages = Environment.GetEnvironmentVariable("NUGET_PACKAGES") ??
            Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), @".nuget\packages");
        var sdk = Path.Combine(packages, "microsoft.windows.sdk.cpp", pins.SdkVersion, "c", "Include", pins.SdkIncludeVersion);
        var libclang = Path.Combine(packages, "libclang.runtime.win-x64", pins.LibclangVersion, @"runtimes\win-x64\native\libclang.dll");
        var reference = Path.Combine(packages, "microsoft.windows.sdk.win32metadata", pins.ReferenceVersion, "Windows.Win32.winmd");
        Data.Require(Directory.Exists(resource) && Directory.GetFiles(resource, "*.h").Length > 0, "Missing clang resource headers.");
        var ledger = new Ledger
        {
            Repository = root,
            EvidenceRoot = evidence,
            SdkRoot = sdk,
            ResourceDirectory = resource,
            Pins = pins,
            Head = Commands.Run("git", ["rev-parse", "HEAD"], root),
            Tool = FileFact.Capture(tool),
            Libclang = FileFact.Capture(libclang),
            Reference = FileFact.Capture(reference)
        };
        Data.Require(ledger.Tool.Sha256 == pins.ToolSha256 && ledger.Libclang.Sha256 == pins.LibclangSha256 &&
            ledger.Reference.Sha256 == pins.ReferenceSha256, "Binary/compiler/reference hash pin mismatch.");
        Directory.CreateDirectory(evidence);
        var roots = new (string Id, string Path, string Role)[]
        {
            ("sdk", sdk, "selected-sdk"),
            ("recompiled", Path.Combine(root, @"generation\WinSDK\RecompiledIdlHeaders"), "repository-midl-or-compatibility"),
            ("additional", Path.Combine(root, @"generation\WinSDK\AdditionalHeaders"), "additional"),
            ("inc", Path.Combine(root, @"generation\WinSDK\inc"), "include"),
            ("partition", Path.Combine(root, @"generation\WinSDK\Partitions"), "partition"),
            ("patch", Path.Combine(root, @"generation\WinSDK\patches"), "patch"),
            ("resource", resource, "compiler-resource"),
            ("controller", Path.Combine(root, @"tools\AnnotationRollout"), "controller"),
            ("pins", Path.Combine(root, @"generation\WinSDK\rollout"), "configuration"),
            ("consumer", Path.Combine(root, @"tools\rust\src"), "consumer")
        };
        var patches = Directory.EnumerateFiles(Path.Combine(root, @"generation\WinSDK\patches"), "*", SearchOption.AllDirectories)
            .ToLookup(Path.GetFileName, StringComparer.OrdinalIgnoreCase);
        foreach (var (id, path, role) in roots)
        {
            Data.Require(Directory.Exists(path), $"Missing source root: {path}");
            foreach (var file in Directory.EnumerateFiles(path, "*", SearchOption.AllDirectories).Order(StringComparer.Ordinal))
            {
                if (id == "pins" && Path.GetFileName(file) != "pins.json") continue;
                var relative = Relative(path, file);
                if (relative.Split('\\').Any(p => p is "obj" or "bin")) continue;
                var input = new InputFile(id + "\\" + relative, Path.GetFullPath(file), Data.Hash(file), role);
                ledger.Inputs.Add(input);
                if ((id is "sdk" or "recompiled" or "additional" or "inc" or "partition") &&
                    new[] { ".h", ".hpp", ".inl", ".idl" }.Contains(Path.GetExtension(file), StringComparer.OrdinalIgnoreCase))
                {
                    var text = File.ReadAllText(file);
                    ledger.Headers.Add(new(input.Id, input.Path, input.Sha256, id == "partition" ? "partition-local" : role)
                    {
                        Conditions = Conditions(file),
                        Generated = text.Contains("MIDL compiler", StringComparison.OrdinalIgnoreCase),
                        Patches = patches[Path.GetFileName(file) + ".win32metadata.patch"]
                            .Select(p => Relative(root, p)).Order(StringComparer.Ordinal).ToArray()
                    });
                }
            }
        }
        foreach (var path in new[] { projectPath, Path.Combine(root, @"tools\rust\Cargo.toml"),
            Path.Combine(root, @"tools\rust\Cargo.lock"), Path.Combine(root, @"scripts\RecompileIdlFilesForScraping.ps1") }
            .Concat(Directory.EnumerateFiles(Path.Combine(root, "scripts"), "Compare-*Improvements.ps1")))
            ledger.Inputs.Add(new("repo\\" + Relative(root, path), path, Data.Hash(path), "pipeline"));
        var headerPaths = ledger.Headers.ToDictionary(h => Key(h.Path), h => h.Id);
        var includes = IncludeDirectories(ledger).Concat([resource]).ToArray();
        foreach (var main in Directory.EnumerateFiles(Path.Combine(root, @"generation\WinSDK\Partitions"), "main.cpp", SearchOption.AllDirectories)
            .Order(StringComparer.Ordinal))
        {
            var partition = new Partition(Relative(Path.Combine(root, @"generation\WinSDK\Partitions"), Path.GetDirectoryName(main)!),
                main, Data.Hash(main), ReadIncludes(File.ReadAllText(main)).Select(i =>
                {
                    var candidates = (i.Quoted ? new[] { Path.GetDirectoryName(main)! }.Concat(includes) : includes)
                        .Select(d => Path.Combine(d, i.Spelling.Replace('/', '\\')));
                    var resolved = candidates.FirstOrDefault(File.Exists);
                    bool publicHeader = resolved != null && headerPaths.TryGetValue(Key(resolved), out _);
                    return i with
                    {
                        Header = publicHeader ? headerPaths[Key(resolved!)] : null,
                        CompilerSource = resolved != null && !publicHeader ? resolved : null
                    };
                }).ToArray());
            ledger.Partitions.Add(partition);
            foreach (var header in partition.Includes.Select(i => i.Header).Where(h => h != null).Distinct())
            {
                var selected = ledger.Headers.Single(h => h.Id == header);
                selected.Consumers.Add(partition.Id);
                selected.Selection = "direct-root";
            }
        }
        AssignOwners(ledger);
        ledger.Fingerprint = Fingerprint(ledger.Inputs);
        CaptureAuditInputs(ledger);
        ledger.ReconciliationGaps = [
            "Native symbol denominator is incomplete until every canonical partition/architecture is captured without errors.",
            "Unresolved direct includes and selected-SDK versus compatibility/MIDL alternatives need explicit source ownership decisions.",
            "Unreached SDK/CRT/WinRT/provider files are catalog-only, NOT additional conversion obligations. Relevant reference/legacy omissions remain explicit reconciliation gaps.",
            "Compiler captures cover active canonical conditions only. Skipped branches, IDL/MIDL facts and alternative macro configurations remain pending.",
            "Published reference declarations and all legacy semantic records are audit inputs only; their per-symbol reconciliation remains pending.",
            "Shared Foundation WIN32_ERROR and Registry REG_SAM_FLAGS pilot bridges are not shipped-header migrations.",
            "No generic full-SDK metadata/native/negative-control or consumer gate has closed any header.",
            "Powrprof source additions, callback constructors, macro placement, exact availability, shared lifetime and invalid values remain open."
        ];
        return ledger;
    }

    internal static void AssignOwners(Ledger ledger)
    {
        foreach (var h in ledger.Headers)
        {
            h.Consumers = h.Consumers.Distinct(StringComparer.Ordinal).Order(StringComparer.Ordinal).ToList();
            h.Owner = h.Consumers.Contains("Foundation") ? "Foundation" :
                h.Consumers.Contains("Registry") && Path.GetFileName(h.Path).Equals("winreg.h", StringComparison.OrdinalIgnoreCase) ? "Registry" :
                h.Consumers.FirstOrDefault() ?? "unassigned";
        }
    }

    private static void CaptureAuditInputs(Ledger ledger)
    {
        var directory = Path.Combine(ledger.EvidenceRoot, "audit-inputs");
        Data.Require(!Directory.Exists(directory), "Audit input directory exists; use a fresh bootstrap evidence root.");
        Directory.CreateDirectory(directory);
        var paths = Commands.Run("git", ["ls-tree", "-r", "--name-only", ledger.Pins!.LegacyCommit, "--", "generation/WinSDK"], ledger.Repository)
            .Split('\n').Where(p => p.EndsWith(".rsp") || p.EndsWith(".json") || p.Contains("/manual/")).Order(StringComparer.Ordinal);
        foreach (var path in paths)
        {
            var file = Path.Combine(directory, path.Replace('/', '\\'));
            Directory.CreateDirectory(Path.GetDirectoryName(file)!);
            var content = Commands.Run("git", ["show", ledger.Pins.LegacyCommit + ":" + path], ledger.Repository);
            File.WriteAllText(file, content);
            ledger.AuditInputs.Add(new(path, FileFact.Capture(file), "pending",
                "Pinned legacy audit input; must reconcile every semantic entry; never read by production generation."));
        }
        ledger.AuditInputs.Add(new("published-reference", ledger.Reference!, "pending", "Decode and reconcile every declaration, member and contract."));
    }

    internal static string Fingerprint(IEnumerable<InputFile> inputs) =>
        Data.Digest(string.Join("\n", inputs.OrderBy(i => i.Id, StringComparer.Ordinal).Select(i => $"{i.Id}\t{i.Sha256}")));

    internal static bool Reconcile(Ledger ledger)
    {
        bool changed = false;
        foreach (var input in ledger.Inputs.ToArray())
        {
            var hash = File.Exists(input.Path) ? Data.Hash(input.Path) : "MISSING";
            if (hash == input.Sha256) continue;
            changed = true;
        }
        // Adding a partition/header is as significant as editing one. Git also catches new controller/patch files.
        var currentPartitions = Directory.GetFiles(Path.Combine(ledger.Repository, @"generation\WinSDK\Partitions"), "main.cpp", SearchOption.AllDirectories)
            .Select(Key).ToHashSet(StringComparer.Ordinal);
        changed |= !currentPartitions.SetEquals(ledger.Partitions.Select(p => Key(p.Path)));
        var currentSdk = Directory.GetFiles(ledger.SdkRoot, "*", SearchOption.AllDirectories).Select(Key).ToHashSet(StringComparer.Ordinal);
        changed |= !currentSdk.SetEquals(ledger.Inputs.Where(i => i.Role == "selected-sdk").Select(i => Key(i.Path)));
        foreach (var (role, path) in new[] {
            ("repository-midl-or-compatibility", @"generation\WinSDK\RecompiledIdlHeaders"),
            ("additional", @"generation\WinSDK\AdditionalHeaders"), ("include", @"generation\WinSDK\inc"),
            ("patch", @"generation\WinSDK\patches"), ("controller", @"tools\AnnotationRollout"),
            ("consumer", @"tools\rust\src") })
        {
            var paths = Directory.GetFiles(Path.Combine(ledger.Repository, path), "*", SearchOption.AllDirectories)
                .Where(p => !Relative(Path.Combine(ledger.Repository, path), p).Split('\\').Any(s => s is "obj" or "bin"))
                .Select(Key).ToHashSet(StringComparer.Ordinal);
            changed |= !paths.SetEquals(ledger.Inputs.Where(i => i.Role == role).Select(i => Key(i.Path)));
        }
        if (changed)
        {
            foreach (var p in ledger.Partitions) { p.State = "regressed"; p.Blocker = "Source universe changed; bootstrap a fresh reconciled census."; }
            foreach (var h in ledger.Headers)
            {
                if (Vocabulary.Terminal.Contains(h.State)) h.State = "regressed";
                h.LastVerifiedFingerprint = null;
            }
            if (!ledger.ReconciliationGaps.Contains("STALE INPUTS: a fresh bootstrap census is required."))
                ledger.ReconciliationGaps.Add("STALE INPUTS: a fresh bootstrap census is required.");
        }
        return !changed;
    }

    internal static void ReuseDiscovery(Ledger previous, Ledger fresh)
    {
        foreach (var partition in fresh.Partitions)
        {
            var old = previous.Partitions.SingleOrDefault(p => p.Id == partition.Id);
            if (old == null) continue;
            foreach (var (architecture, capture) in old.Captures)
            {
                if (!NativeInventory.IsCurrent(fresh, partition, architecture, capture)) continue;
                capture.Manifest.Verify();
                capture.Symbols.Verify();
                partition.Captures.Add(architecture, capture);
                foreach (var header in capture.IncludedHeaders)
                {
                    var found = fresh.Headers.SingleOrDefault(h => h.Id == header);
                    Data.Require(found != null, $"Cached header is absent from new census: {header}");
                    found.Consumers.Add(partition.Id);
                    if (found.Selection == "catalog-only") found.Selection = "transitive";
                }
            }
            if (partition.Captures.Count == 3)
            {
                partition.State = partition.Captures.Values.Any(c => c.HasErrors) ? "blocked" : "validating";
                partition.Blocker = partition.State == "blocked" ? old.Blocker : null;
                partition.BlockerOwner = partition.State == "blocked" ? old.BlockerOwner : null;
                partition.RetryFingerprint = old.RetryFingerprint;
            }
        }
        AssignOwners(fresh);
    }
}
