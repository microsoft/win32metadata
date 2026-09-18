using System.Text.Json;

namespace AnnotationRollout;

internal static class SelfTests
{
    internal static int Run()
    {
        string directory = Path.Combine(Path.GetTempPath(), "win32metadata-rollout-tests-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(directory);
        int checks = 0;
        void Check(bool value, string name)
        {
            Data.Require(value, "TEST FAILED: " + name);
            checks++;
        }
        void Reject(Action action, string name)
        {
            try { action(); }
            catch (Exception error) when (error is InvalidDataException or IOException or JsonException)
            { checks++; return; }
            throw new InvalidDataException("TEST FAILED (accepted invalid state): " + name);
        }
        var file = Path.Combine(directory, "header.h");
        File.WriteAllText(file, "typedef unsigned long EXAMPLE;\n");
        var fact = FileFact.Capture(file);
        var pins = new Pins(1, "pilot", "tooling", "windows", "tool", "sdk", "include", "clang", "sha", "reference",
            "sha", "legacy", Vocabulary.Architectures, "base", null, []);
        Ledger Fixture() => new()
        {
            Pins = pins,
            Fingerprint = "current",
            Repository = directory,
            EvidenceRoot = directory,
            Tool = fact,
            Libclang = fact,
            Reference = fact,
            Inputs = [new("sdk\\header.h", file, fact.Sha256, "selected-sdk")],
            Partitions = [
                new("Z", file, fact.Sha256, [new(1, "header.h", false, "", "sdk\\header.h")]),
                new("Foundation", file, fact.Sha256, [new(1, "header.h", false, "", "sdk\\header.h")]),
                new("Mf", file, fact.Sha256, [new(1, "wmcontainer.h", false, "", "sdk\\header.h")])
            ],
            Headers = [new("sdk\\header.h", file, fact.Sha256, "selected-sdk") { Owner = "Foundation", Consumers = ["Z", "Foundation", "Mf"] }]
        };
        try
        {
            var ledger = Fixture();
            Store.Validate(ledger, true);
            checks++;
            Check(Store.Select(ledger)!.Id == "Mf", "unsafe donor first");
            ledger.Partitions[2].State = "blocked";
            ledger.Partitions[2].Blocker = "native mismatch";
            ledger.Partitions[2].BlockerOwner = "integration";
            ledger.Partitions[2].RetryFingerprint = "abc";
            Check(Store.Select(ledger)!.Id == "Foundation", "skip blocked and prioritize shared");
            ledger.Partitions[1].State = "validating";
            Check(Store.Select(ledger)!.Id == "Z", "no completed discovery starvation");
            var empty = Fixture(); empty.Headers.Clear();
            Reject(() => Store.Validate(empty, false), "empty universe");
            var duplicate = Fixture(); duplicate.Headers.Add(duplicate.Headers[0]);
            Reject(() => Store.Validate(duplicate, false), "duplicate owner/header");
            var unknown = Fixture(); unknown.Headers[0].Consumers.Add("missing");
            Reject(() => Store.Validate(unknown, false), "unknown consumer");
            var missingHeader = Fixture();
            missingHeader.Partitions[0] = missingHeader.Partitions[0] with { Includes = [new(1, "absent.h", false, "", "absent")] };
            Reject(() => Store.Validate(missingHeader, false), "missing header identity");
            var wrongOwner = Fixture(); wrongOwner.Headers[0].Owner = "not-a-consumer";
            Reject(() => Store.Validate(wrongOwner, false), "wrong owner");
            var state = Fixture(); state.Headers[0].State = "success";
            Reject(() => Store.Validate(state, false), "unknown state");
            var terminal = Fixture(); terminal.Headers[0].State = "equivalent";
            Reject(() => Store.Validate(terminal, false), "evidence-free acceptance");
            var noArch = Fixture(); noArch.Pins = pins with { Architectures = ["x64", "x86"] };
            Reject(() => Store.Validate(noArch, false), "missing architecture");
            var blocker = Fixture(); blocker.Partitions[0].State = "blocked";
            Reject(() => Store.Validate(blocker, false), "unowned blocker");
            var journal = Fixture(); journal.Sequence = 1;
            Reject(() => Store.Validate(journal, false), "journal/checkpoint mismatch");
            var partitionSuccess = Fixture(); partitionSuccess.Partitions[0].State = "equivalent";
            Reject(() => Store.Validate(partitionSuccess, false), "blanket partition acceptance");
            var source = "/* #include <wrong.h> */\n// #include <wrong2.h>\n#if FOO\n#include <one.h>\n#else\n#include \"two.h\"\n#endif\n";
            var includes = Census.ReadIncludes(source).ToArray();
            Check(includes.Length == 2 && includes[0].Spelling == "one.h" && includes[1].Quoted, "comment and include lexer");
            Check(includes[0].Line == 4 && includes[1].Line == 6, "exact include source lines");
            Check(includes[1].Condition.Contains("else", StringComparison.Ordinal), "conditional include ownership");
            Reject(() => Census.ReadIncludes("#if NEVER\n#include <x.h>").ToArray(), "truncated source conditions");
            Check(Census.Fingerprint(Fixture().Inputs) == Census.Fingerprint(Fixture().Inputs.AsEnumerable().Reverse()), "stable fingerprint ordering");
            var changed = Fixture(); changed.Inputs[0] = changed.Inputs[0] with { Sha256 = "changed" };
            Check(Census.Fingerprint(changed.Inputs) != Census.Fingerprint(Fixture().Inputs), "changed source fingerprint");
            string stateDirectory = Path.Combine(directory, "state");
            using (var store = new Store(stateDirectory))
            {
                store.Save(Fixture(), "bootstrap", "test", "test");
                var loaded = store.Load();
                Check(loaded.Sequence == 1 && loaded.NextItem == "Mf", "atomic checkpoint round trip");
                Reject(() => { using var duplicateWriter = new Store(stateDirectory); }, "duplicate writer");
                File.WriteAllText(Path.Combine(stateDirectory, "current.json.tmp"), "{interrupted");
                Check(store.Load().Sequence == 1, "interrupted pointer temp ignored");
                File.WriteAllText(Path.Combine(stateDirectory, "checkpoint-000002.json"), "{orphan");
                Check(store.Load().Sequence == 1, "unpublished snapshot ignored");
                store.Save(loaded, "resume", "test", "Orphan snapshot does not prevent progress.");
                Check(store.Load().Sequence == 2, "resumption past orphan snapshot");
                var checkpoint = Data.Read<FileFact>(Path.Combine(stateDirectory, "current.json"));
                File.AppendAllText(checkpoint.Path, "corrupt");
                Reject(() => store.Load(), "corrupt committed checkpoint");
            }
            var disposition = new Disposition(1, "sdk\\header.h", "current", "equivalent", [], [], [], null);
            Reject(() => Dispositions.Verify(Fixture(), Fixture().Headers[0], disposition), "empty/partial native captures");
            Reject(() => Dispositions.Verify(Fixture(), Fixture().Headers[0], disposition with { Fingerprint = "stale" }), "stale disposition");
            var staleEvidence = FileFact.Capture(file);
            File.AppendAllText(file, "// mutation\n");
            Reject(staleEvidence.Verify, "mutated evidence");
            File.Delete(file);
            Reject(staleEvidence.Verify, "missing evidence");
            var json = Path.Combine(directory, "unknown.json");
            File.WriteAllText(json, "{\"schemaVersion\":1,\"injected\":true}");
            Reject(() => Data.Read<Ledger>(json), "unknown schema field");
            Console.WriteLine($"PASS: {checks} rollout controller checks.");
            return 0;
        }
        finally
        {
            // This path is a newly created, uniquely named test directory, never a user workspace.
            Directory.Delete(directory, true);
        }
    }

    internal static int RunNative(string root, string library, string resource, string sdk, string directory)
    {
        Data.Require(!Directory.Exists(directory), "Native regression evidence directory already exists.");
        Directory.CreateDirectory(directory);
        var header = Path.Combine(directory, "fixture.h");
        var main = Path.Combine(directory, "main.cpp");
        File.WriteAllText(header, """
                #define FIXTURE_CONSTANT 42
                typedef unsigned long FLAGS;
                enum MODE { MODE_ONE = 1, MODE_TWO = 2 };
                struct VALUE { const wchar_t* text; unsigned int count; unsigned int bits : 3; };
                typedef int (__stdcall *CALLBACK)(const wchar_t* text, unsigned int length);
                struct __declspec(uuid("01234567-89ab-cdef-0123-456789abcdef")) IFixture {
                    virtual unsigned long __stdcall Run(VALUE* value) = 0;
                };
                extern "C" unsigned long __stdcall Function(FLAGS flags, VALUE* value);
                #if defined(_WIN64)
                #define CONDITIONAL_CONSTANT 64
                #else
                #define CONDITIONAL_CONSTANT 32
                #endif
                """);
        File.WriteAllText(main, "#include \"fixture.h\"\n");
        var partition = new Partition("Fixture", main, Data.Hash(main), [new(1, "fixture.h", true, "", "fixture.h")]);
        var ledger = new Ledger
        {
            Repository = root,
            SdkRoot = sdk,
            ResourceDirectory = resource,
            Libclang = FileFact.Capture(library),
            Headers = [new("fixture.h", header, Data.Hash(header), "test")],
            Fingerprint = "native-regression"
        };
        int checks = 0;
        void Check(bool condition, string description)
        {
            Data.Require(condition, "Native regression failed: " + description);
            checks++;
        }
        foreach (var arch in Vocabulary.Architectures)
        {
            var result = NativeInventory.Capture(ledger, partition, arch, Path.Combine(directory, arch));
            Check(!result.HasErrors, $"clean {arch} compiler capture");
            result.Manifest.Verify();
            result.Symbols.Verify();
            var symbols = File.ReadLines(result.Symbols.Path).Select(l => JsonSerializer.Deserialize<NativeSymbol>(l, Data.Json)!).ToArray();
            foreach (var kind in new[] { "FunctionDecl", "CXXMethod", "TypedefDecl", "StructDecl", "FieldDecl", "EnumDecl", "EnumConstantDecl", "ParmDecl", "Return", "macro definition" })
                Check(symbols.Any(s => s.Kind == kind), $"{arch}/{kind} inventory");
            Check(symbols.Select(s => s.Id).Distinct().Count() == symbols.Length, "unique declaration identities");
            Check(symbols.Any(s => s.Name == "CALLBACK" && s.Facts.ContainsKey("underlyingType")), "callback signature");
            var field = symbols.Single(s => s.Name == "text" && s.Kind == "FieldDecl");
            var facts = (JsonElement)field.Facts["type"];
            Check(facts.GetProperty("size").GetInt64() == (arch == "x86" ? 4 : 8), "architecture-specific pointer width");
            Check(facts.GetProperty("pointee").GetProperty("const").GetBoolean(), "native pointee const retained");
            Check(NativeInventory.IsCurrent(ledger, partition, arch, result), "exact dependency cache hit");
            File.AppendAllText(header, "\n// real dependency mutation\n");
            Check(!NativeInventory.IsCurrent(ledger, partition, arch, result), "changed dependency cache miss");
            File.WriteAllText(header, File.ReadAllText(header).Replace("\n// real dependency mutation\n", "", StringComparison.Ordinal));
            Check(NativeInventory.IsCurrent(ledger, partition, arch, result), "restored dependency cache hit");
        }
        Data.Write(Path.Combine(directory, "result.json"), new { passed = checks, architectures = Vocabulary.Architectures, complete = true });
        Console.WriteLine($"PASS: {checks} actual libclang native inventory/cache checks; evidence={directory}");
        return 0;
    }
}
