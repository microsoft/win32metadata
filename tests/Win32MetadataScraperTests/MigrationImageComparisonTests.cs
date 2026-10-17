using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class MigrationImageComparisonTests
    {
        [Theory]
        [InlineData(0, "No unknown differences found.", false, "unchanged", 0)]
        [InlineData(-1, "Unknown differences found:\nsource-backed difference one\nsource-backed difference two", false, "required", 2)]
        [InlineData(1, "Error: invalid metadata", true, null, 0)]
        [InlineData(-1, "Unhandled exception: invalid metadata", true, null, 0)]
        [InlineData(0, "", true, null, 0)]
        [InlineData(0, "Unknown differences found:\ninconsistent success", true, null, 0)]
        [InlineData(-1, "Unknown differences found:", true, null, 0)]
        public void RawComparisonPreservesReviewResultsWithoutAcceptingToolFailures(
            int toolExitCode, string toolOutput, bool throws, string reviewStatus, int differenceLines)
        {
            string root = Path.Combine(Path.GetTempPath(), "WinmdComparisonTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(root);
            try
            {
                string[] lines = toolOutput.Length == 0 ? Array.Empty<string>() : toolOutput.Split('\n');
                string data = Convert.ToBase64String(Encoding.UTF8.GetBytes(JsonSerializer.Serialize(new
                {
                    repo = WinHttpMigrationTests.RepositoryRoot,
                    directory = root,
                    toolExitCode,
                    lines,
                })));
                string script = "$data = [Text.Encoding]::UTF8.GetString([Convert]::FromBase64String('" + data + @"')) | ConvertFrom-Json
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$repo = $data.repo
$tokens = $null; $errors = $null
$ast = [Management.Automation.Language.Parser]::ParseFile(
    (Join-Path $repo 'scripts\Build-WinHttpMigrationImage.ps1'), [ref]$tokens, [ref]$errors)
if ($errors.Count) { throw ($errors.Message -join ""`n"") }
$definitions = @($ast.FindAll({
    param($node)
    $node -is [Management.Automation.Language.FunctionDefinitionAst] -and
        $node.Name -in @('Get-Sha256', 'Get-ApiComparison')
}, $true))
if ($definitions.Count -ne 2) { throw 'The actual comparison functions were not found.' }
foreach ($definition in $definitions) { . ([scriptblock]::Create($definition.Extent.Text)) }
$script:actualArguments = @()
function dotnet {
    $script:actualArguments = @($args)
    $data.lines | ForEach-Object { Write-Output $_ }
    $global:LASTEXITCODE = [int]$data.toolExitCode
}
$log = Join-Path $data.directory 'comparison.log'
try {
    $comparison = Get-ApiComparison 'OLD.winmd' 'NEW.winmd' $log 3>$null 6>$null
    $result = [ordered]@{ threw = $false; comparison = $comparison }
}
catch {
    $result = [ordered]@{ threw = $true; error = $_.ToString() }
}
$result.arguments = $script:actualArguments
$result | ConvertTo-Json -Depth 6 -Compress
";
                using var result = RunPowerShell(script);
                Assert.Equal(throws, result.RootElement.GetProperty("threw").GetBoolean());
                string[] arguments = result.RootElement.GetProperty("arguments").EnumerateArray()
                    .Select(value => value.GetString()).ToArray();
                Assert.DoesNotContain("--knownDiffsFile", arguments);
                Assert.Contains("--first", arguments);
                Assert.Contains("--second", arguments);
                Assert.Contains("OLD.winmd", arguments);
                Assert.Contains("NEW.winmd", arguments);
                string log = Path.Combine(root, "comparison.log");
                Assert.Equal(lines, File.ReadAllLines(log));
                if (throws)
                {
                    Assert.Contains("Metadata comparison failed", result.RootElement.GetProperty("error").GetString());
                }
                else
                {
                    var comparison = result.RootElement.GetProperty("comparison");
                    Assert.Equal(toolExitCode, comparison.GetProperty("exitCode").GetInt32());
                    Assert.Equal(reviewStatus, comparison.GetProperty("reviewStatus").GetString());
                    Assert.Equal(differenceLines, comparison.GetProperty("rawDifferenceLines").GetInt32());
                    Assert.Equal(Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(log))),
                        comparison.GetProperty("logSha256").GetString());
                }
            }
            finally
            {
                Directory.Delete(root, recursive: true);
            }
        }

        [Theory]
        [InlineData("main")]
        [InlineData("companions")]
        [InlineData("orphan")]
        [InlineData("missing")]
        [InlineData("repeat-addition")]
        public void SelectedSourceClosureIncludesAndRechecksHeaderTypeCompanions(string scenario)
        {
            string root = Path.Combine(Path.GetTempPath(), "WinmdSourceClosureTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(root);
            try
            {
                string[] files = scenario switch
                {
                    "companions" => new[] { @"x64\WinHttp.cs", @"x64\WinHttp.header-types.cs",
                        @"common\Xinput.cs", @"common\Xinput.header-types.cs", @"common\Unselected.header-types.cs" },
                    "orphan" => new[] { @"x64\WinHttp.header-types.cs" },
                    "missing" => Array.Empty<string>(),
                    _ => new[] { @"x64\WinHttp.cs" },
                };
                foreach (string relative in files.Concat(new[] { "scraper.autoRemaps.generated.rsp", "emitter.autoFnPtr.crossarch.generated.rsp" }))
                {
                    string path = Path.Combine(root, "generated", relative);
                    Directory.CreateDirectory(Path.GetDirectoryName(path));
                    File.WriteAllText(path, relative);
                }
                Directory.CreateDirectory(Path.Combine(root, "scratch"));
                File.WriteAllText(Path.Combine(root, "scratch", "WinHttp.remaps"), "PRESERVE_PTR_LEVEL:fixture");
                string data = Convert.ToBase64String(Encoding.UTF8.GetBytes(JsonSerializer.Serialize(new
                {
                    repo = WinHttpMigrationTests.RepositoryRoot,
                    directory = root,
                    scenario,
                    partitions = scenario == "companions" ? new[] { "WinHttp", "Xinput" } : new[] { "WinHttp" },
                })));
                string script = "$data = [Text.Encoding]::UTF8.GetString([Convert]::FromBase64String('" + data + @"')) | ConvertFrom-Json
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$tokens = $null; $errors = $null
$ast = [Management.Automation.Language.Parser]::ParseFile(
    (Join-Path $data.repo 'scripts\Build-WinHttpMigrationImage.ps1'), [ref]$tokens, [ref]$errors)
if ($errors.Count) { throw ($errors.Message -join ""`n"") }
$definitions = @($ast.FindAll({
    param($node)
    $node -is [Management.Automation.Language.FunctionDefinitionAst] -and
        $node.Name -in @('Get-Sha256', 'Get-SelectedSources', 'Get-SelectedInputs')
}, $true))
if ($definitions.Count -ne 3) { throw 'The actual source-closure functions were not found.' }
foreach ($definition in $definitions) { . ([scriptblock]::Create($definition.Extent.Text)) }
try {
    $sources = @(Get-SelectedSources $data.directory $data.partitions)
    $inputs = @(Get-SelectedInputs $data.directory $sources)
    if ($data.scenario -eq 'repeat-addition') {
        [IO.File]::WriteAllText((Join-Path $data.directory 'generated\x64\WinHttp.header-types.cs'), 'new compiler-projected group')
    }
    $repeated = @(Get-SelectedSources $data.directory $data.partitions)
    $result = [ordered]@{ threw = $false; sources = $sources; inputs = $inputs; repeated = $repeated }
}
catch {
    $result = [ordered]@{ threw = $true; error = $_.ToString() }
}
$result | ConvertTo-Json -Depth 6 -Compress
";
                using var result = RunPowerShell(script);
                bool throws = scenario is "orphan" or "missing";
                Assert.Equal(throws, result.RootElement.GetProperty("threw").GetBoolean());
                if (throws)
                {
                    Assert.Contains(scenario == "orphan" ? "companion has no main source" : "produced no source",
                        result.RootElement.GetProperty("error").GetString());
                }
                else
                {
                    string[] sources = result.RootElement.GetProperty("sources").EnumerateArray()
                        .Select(value => value.GetString()).ToArray();
                    Assert.Equal(files.Where(path => !path.Contains("Unselected", StringComparison.Ordinal)), sources);
                    string[] inputs = result.RootElement.GetProperty("inputs").EnumerateArray()
                        .Select(value => value.GetProperty("path").GetString()).ToArray();
                    Assert.Equal(sources.Length + 3, inputs.Length);
                    Assert.All(sources, source => Assert.Contains(Path.Combine("generated", source), inputs));
                    string[] repeated = result.RootElement.GetProperty("repeated").EnumerateArray()
                        .Select(value => value.GetString()).ToArray();
                    if (scenario == "repeat-addition")
                        Assert.Equal(sources.Concat(new[] { @"x64\WinHttp.header-types.cs" }), repeated);
                    else
                        Assert.Equal(sources, repeated);
                }
            }
            finally
            {
                Directory.Delete(root, recursive: true);
            }
        }

        private static JsonDocument RunPowerShell(string script)
        {
            var start = new ProcessStartInfo("pwsh")
            {
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                WorkingDirectory = WinHttpMigrationTests.RepositoryRoot,
            };
            foreach (string argument in new[] { "-NoProfile", "-NonInteractive", "-EncodedCommand",
                Convert.ToBase64String(Encoding.Unicode.GetBytes(script)) })
                start.ArgumentList.Add(argument);
            using var process = Process.Start(start);
            var output = process.StandardOutput.ReadToEndAsync();
            var error = process.StandardError.ReadToEndAsync();
            if (!process.WaitForExit(60_000))
            {
                process.Kill(entireProcessTree: true);
                throw new TimeoutException("The migration image regression did not finish.");
            }
            Assert.True(process.ExitCode == 0, error.GetAwaiter().GetResult() + output.GetAwaiter().GetResult());
            return JsonDocument.Parse(output.GetAwaiter().GetResult());
        }
    }
}
