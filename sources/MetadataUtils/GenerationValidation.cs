using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;

namespace MetadataUtils
{
    public sealed record GenerationValidationError(string Code, string Stage, string Message)
    {
        public string Input { get; init; }
        public string Symbol { get; init; }
        public string Header { get; init; }
        public int? Line { get; init; }
        public string Architecture { get; init; }
        public string Partition { get; init; }
        public string SelectedSdkRoot { get; init; }
        public string IdentityCategory { get; init; }
        public string Cause { get; init; }

        public override string ToString() =>
            $"error {this.Code}: {this.Message} [stage: {this.Stage}; input: {this.Input}; " +
            $"symbol: {this.Symbol}; header: {this.Header}; line: {this.Line}; " +
            $"partition: {this.Partition}; architecture: {this.Architecture}; " +
            $"SDK root: {this.SelectedSdkRoot}; identity: {this.IdentityCategory}]";
    }

    public sealed record BlockedGenerationStage(string Stage, string Dependency);

    // Validation only: callers choose a safe declaration/input boundary and the exact exception to collect.
    public sealed class GenerationValidation
    {
        private readonly List<GenerationValidationError> errors = new();
        private readonly List<BlockedGenerationStage> blockedStages = new();
        private Exception firstError;
        private const string ValidationFailureKey = "Win32Metadata.GenerationValidation";

        public IReadOnlyList<GenerationValidationError> Errors => this.errors;
        public IReadOnlyList<BlockedGenerationStage> BlockedStages => this.blockedStages;
        public bool HasErrors => this.errors.Count != 0;
        public string Status => this.HasErrors ? "rejected" : this.blockedStages.Count != 0 ? "blocked" : "completed";
        public static bool IsValidationFailure(Exception error) => error.Data.Contains(ValidationFailureKey);

        public void Add(Exception error, string code, string stage, string input = null, string symbol = null,
            string header = null, int? line = null, string architecture = null, string partition = null,
            string selectedSdkRoot = null, string identityCategory = null)
        {
            lock (this.errors)
            {
                this.firstError ??= error;
                this.errors.Add(new GenerationValidationError(code, stage, error.Message)
                {
                    Input = input, Symbol = symbol, Header = header, Line = line,
                    Architecture = architecture, Partition = partition, Cause = error.ToString(),
                    SelectedSdkRoot = selectedSdkRoot, IdentityCategory = identityCategory,
                });
            }
        }

        public void Add(GenerationValidationError error)
        {
            lock (this.errors)
                this.errors.Add(error);
        }

        public void Block(string stage, string dependency)
        {
            lock (this.blockedStages)
                foreach (string name in stage.Split(';', StringSplitOptions.RemoveEmptyEntries))
                {
                    var blocked = new BlockedGenerationStage(name, dependency);
                    if (!this.blockedStages.Contains(blocked))
                        this.blockedStages.Add(blocked);
                }
        }

        public string Format() => string.Join(Environment.NewLine,
            this.errors.Select(error => error.ToString()).Concat(this.blockedStages.Select(blocked =>
                $"error WMG002: Blocked stage '{blocked.Stage}': requires valid {blocked.Dependency}.")));

        public void WriteReport(string path, IEnumerable<string> reports = null)
        {
            File.WriteAllText(path, JsonSerializer.Serialize(new
            {
                Version = 1, Status = this.Status,
                Errors = this.Errors, BlockedStages = this.BlockedStages,
                Reports = reports ?? Array.Empty<string>(),
            }, new JsonSerializerOptions { WriteIndented = true }));
        }

        public void ThrowIfAny(string report = null)
        {
            if (!this.HasErrors)
                return;
            string message = this.Format() + (report == null ? "" : Environment.NewLine + "Full diagnostics: " + report);
            Exception failure = this.firstError is InvalidDataException
                ? new InvalidDataException(message, this.firstError)
                : new InvalidOperationException(message, this.firstError);
            failure.Data[ValidationFailureKey] = true;
            throw failure;
        }
    }
}
