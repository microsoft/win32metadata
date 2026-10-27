using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using MetadataUtils;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    public class CollectGenerationDiagnostics : Task
    {
        [Required]
        public string GeneratedDir { get; set; }

        [Required]
        public string FailedStage { get; set; }

        public ITaskItem[] AdditionalReports { get; set; }

        public override bool Execute()
        {
            var validation = new GenerationValidation();
            var reports = new List<string>();
            string primaryName = this.FailedStage switch
            {
                "PrepSettingsForAutoTypes" => "auto-types-preparation-diagnostics.json",
                "PrepSettingsForFunctionPointerFixups" => "function-pointer-preparation-diagnostics.json",
                "ScrapeHeaders" => "scrape-diagnostics.json",
                "ScrapeConstants" => "native-constant-conflicts.json",
                "PrepareWithLibsRsp" => "library-input-diagnostics.json",
                "EmitWinmd" => "generation-diagnostics.json",
                _ => null,
            };
            var primaryReports = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            if (primaryName != null)
                primaryReports.Add(Path.Combine(this.GeneratedDir, primaryName));
            if (this.FailedStage == "ScrapeConstants")
                primaryReports.Add(Path.Combine(this.GeneratedDir, "constants-task-diagnostics.json"));
            if (this.FailedStage == "CompileIdls")
                primaryReports.UnionWith((this.AdditionalReports ?? Array.Empty<ITaskItem>()).Select(item => item.ItemSpec));
            bool primaryFailureRetained = false;
            var names = new List<string>();
            if (this.FailedStage != "EmitWinmd")
                names.AddRange(new[] { "auto-types-preparation-diagnostics.json", "function-pointer-preparation-diagnostics.json" });
            if (this.FailedStage == "ScrapeHeaders")
                names.Add("scrape-diagnostics.json");
            if (this.FailedStage == "ScrapeConstants")
                names.Add("native-constant-conflicts.json");
            if (this.FailedStage == "PrepareWithLibsRsp")
                names.Add("library-input-diagnostics.json");
            if (this.FailedStage != "EmitWinmd")
                names.AddRange(new[] { "constants-task-diagnostics.json", "constants-preflight-diagnostics.json" });
            names.Add(this.FailedStage == "EmitWinmd" ? "generation-diagnostics.json" : "emitter-preflight-diagnostics.json");
            var paths = names.Select(name => Path.Combine(this.GeneratedDir, name)).ToList();
            if (this.FailedStage == "CompileIdls")
                paths.AddRange((this.AdditionalReports ?? Array.Empty<ITaskItem>()).Select(item => item.ItemSpec));
            for (int index = 0; index < paths.Count; index++)
            {
                string path = paths[index];
                if (!File.Exists(path))
                    continue;
                reports.Add(path);
                try
                {
                    using var report = JsonDocument.Parse(File.ReadAllText(path));
                    var root = report.RootElement;
                    ValidateReport(root);
                    if (root.GetProperty("Status").GetString() == "completed")
                        continue;
                    if (root.TryGetProperty("Reports", out var references))
                        foreach (var reference in references.EnumerateArray())
                            if (reference.GetString() is string retained && !paths.Contains(retained, StringComparer.OrdinalIgnoreCase))
                                paths.Add(retained);
                    if (root.TryGetProperty("Errors", out var errors))
                    {
                        primaryFailureRetained |= primaryReports.Contains(path) && errors.GetArrayLength() > 0;
                        foreach (var error in errors.EnumerateArray())
                            validation.Add(error.Deserialize<GenerationValidationError>() ??
                                throw new JsonException("Null generation diagnostic."));
                    }
                    if (root.TryGetProperty("BlockedStages", out var blockedStages))
                        foreach (var blocked in blockedStages.EnumerateArray())
                        {
                            var stage = blocked.Deserialize<BlockedGenerationStage>() ??
                                throw new JsonException("Null blocked-stage diagnostic.");
                            validation.Block(stage.Stage, stage.Dependency);
                        }
                }
                catch (JsonException error)
                {
                    validation.Add(error, "WMG999", "generation.diagnostic-report", path,
                        identityCategory: "invalid-diagnostic-report");
                }
            }
            if (!primaryFailureRetained)
                validation.Add(new InvalidDataException(
                    $"Stage '{this.FailedStage}' failed without a recoverable validation receipt. See its original build output."),
                    "WMG999", this.FailedStage, identityCategory: "infrastructure-or-unreported-failure");
            validation.Block("EmitWinmd;default tests", "successful " + this.FailedStage);
            string output = Path.Combine(this.GeneratedDir, "generation-failures.json");
            validation.WriteReport(output, reports);
            this.Log.LogError($"Generation rejected: {validation.Errors.Count} retained diagnostics. " +
                $"Full census: {output}. WinMD publication and default tests are blocked.");
            return false;
        }

        private static void ValidateReport(JsonElement root)
        {
            if (root.ValueKind != JsonValueKind.Object)
                throw new JsonException("Generation diagnostic report must be an object.");
            if (!root.TryGetProperty("Version", out var version) || version.ValueKind != JsonValueKind.Number ||
                !version.TryGetInt32(out int number) || number != 1)
                throw new JsonException("Generation diagnostic report requires Version 1.");
            RequireString(root, "Status");
            string status = root.GetProperty("Status").GetString();
            if (status is not ("completed" or "rejected" or "blocked"))
                throw new JsonException($"Invalid generation diagnostic Status '{status}'.");
            JsonElement errors = RequireArray(root, "Errors");
            JsonElement blocked = RequireArray(root, "BlockedStages");
            foreach (var error in errors.EnumerateArray())
            {
                if (error.ValueKind != JsonValueKind.Object)
                    throw new JsonException("Generation diagnostic Errors entries must be objects.");
                foreach (string field in new[] { "Code", "Stage", "Message", "Cause" })
                    RequireString(error, field);
                foreach (string field in new[] { "Input", "Symbol", "Header", "Architecture",
                    "Partition", "SelectedSdkRoot", "IdentityCategory" })
                    if (error.TryGetProperty(field, out var value) &&
                        value.ValueKind is not (JsonValueKind.String or JsonValueKind.Null))
                        throw new JsonException($"Generation diagnostic '{field}' must be a string or null.");
                if (error.TryGetProperty("Line", out var line) && line.ValueKind != JsonValueKind.Null &&
                    (line.ValueKind != JsonValueKind.Number || !line.TryGetInt32(out _)))
                    throw new JsonException("Generation diagnostic Line must be an integer or null.");
            }
            foreach (var stage in blocked.EnumerateArray())
            {
                if (stage.ValueKind != JsonValueKind.Object)
                    throw new JsonException("Generation diagnostic BlockedStages entries must be objects.");
                RequireString(stage, "Stage");
                RequireString(stage, "Dependency");
            }
            if (root.TryGetProperty("Reports", out var reports))
            {
                if (reports.ValueKind != JsonValueKind.Array)
                    throw new JsonException("Generation diagnostic Reports must be an array.");
                foreach (var report in reports.EnumerateArray())
                    if (report.ValueKind != JsonValueKind.String || string.IsNullOrEmpty(report.GetString()))
                        throw new JsonException("Generation diagnostic Reports entries must be nonempty paths.");
            }
            if (status == "completed" && (errors.GetArrayLength() > 0 || blocked.GetArrayLength() > 0))
                throw new JsonException("Completed generation diagnostic report cannot contain errors or blocked stages.");

            static JsonElement RequireArray(JsonElement value, string name)
            {
                if (!value.TryGetProperty(name, out var property) || property.ValueKind != JsonValueKind.Array)
                    throw new JsonException($"Generation diagnostic '{name}' must be an array.");
                return property;
            }

            static void RequireString(JsonElement value, string name)
            {
                if (!value.TryGetProperty(name, out var property) || property.ValueKind != JsonValueKind.String)
                    throw new JsonException($"Generation diagnostic '{name}' must be a string.");
            }
        }
    }
}
