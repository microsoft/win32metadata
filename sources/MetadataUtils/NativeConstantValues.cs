using System;
using System.Collections.Generic;
using System.IO;

namespace MetadataUtils
{
    public sealed class NativeConstantValues
    {
        public Architecture Architecture { get; set; }
        public string BindingSource { get; set; }
        public string SourceFile { get; set; }
        public string SourceHash { get; set; }
        public string Namespace { get; set; }
        public string[] Headers { get; set; } = Array.Empty<string>();
        public List<NativeConstantValue> Constants { get; set; } = new();
        public List<NativeConstantIssue> Issues { get; set; } = new();
        public List<NativeConstantGroup> Groups { get; set; } = new();

        public static bool IsGeneratedSource(string path) =>
            Path.GetFileName(path).StartsWith("NativeConstants.", StringComparison.Ordinal) &&
            path.EndsWith(".header-types.cs", StringComparison.Ordinal);
    }

    public sealed record NativeConstantValue(
        string NativeName, string Name, string Header, uint Line, string NativeType, string StorageType, string Value)
    {
        public uint Column { get; init; }
        public string HeaderHash { get; init; }
        public NativeConstantBinding AliasTarget { get; init; }
    }

    public sealed record NativeConstantIssue(string Name, string Header, string Reason, string[] Diagnostics);

    public sealed class ConstantSelectionOptions
    {
        public string SdkRoot { get; init; }
        public IReadOnlyList<string> HeaderPriority { get; init; } = Array.Empty<string>();
        public IReadOnlyList<string> NativeInputs { get; init; } = Array.Empty<string>();
    }
}
