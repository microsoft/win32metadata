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
                    throw new TimeoutException("The image comparison regression did not finish.");
                }
                Assert.True(process.ExitCode == 0, error.GetAwaiter().GetResult() + output.GetAwaiter().GetResult());
                using var result = JsonDocument.Parse(output.GetAwaiter().GetResult());
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
    }
}
