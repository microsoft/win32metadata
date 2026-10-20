using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class PreparedSdkHeaderIncludesTests
    {
        [Theory]
        [InlineData("valid", false)]
        [InlineData("duplicate", false)]
        [InlineData("shared", true)]
        [InlineData("um", true)]
        [InlineData("winrt", true)]
        [InlineData("unrecognized", true)]
        public void PreflightSelectsCanonicalRootsBeforeOnlyExplicitCompilerFallbacks(string scenario, bool throws)
        {
            using var result = Run(scenario, response: false);
            Assert.Equal(throws, result.RootElement.GetProperty("threw").GetBoolean());
            if (throws)
            {
                Assert.Contains("Only selected MSVC/UCRT fallback", result.RootElement.GetProperty("error").GetString());
            }
            else
            {
                string[] includes = result.RootElement.GetProperty("includes").EnumerateArray()
                    .Select(value => value.GetString()).ToArray();
                Assert.Equal(6, includes.Length);
                Assert.Equal(new[] { "shared", "um", "ucrt", "winrt", "include", "ucrt" },
                    includes.Select(Path.GetFileName));
                Assert.All(includes.Take(4), path => Assert.Contains(Path.Combine("prepared", "headers"), path));
                Assert.Contains(Path.Combine("compiler", "include"), includes[4]);
                Assert.Contains(Path.Combine("selected-sdk", "ucrt"), includes[5]);
            }
        }

        [Theory]
        [InlineData("valid", false)]
        [InlineData("duplicates-after-fallback", false)]
        [InlineData("selected-traverse", false)]
        [InlineData("fallback-first", true)]
        [InlineData("ucrt-first", true)]
        [InlineData("missing-shared", true)]
        [InlineData("missing-um", true)]
        [InlineData("missing-ucrt", true)]
        [InlineData("missing-winrt", true)]
        [InlineData("unprepared-sdk-first", true)]
        [InlineData("unprepared-sdk-last", true)]
        [InlineData("unprepared-sdk-traverse", true)]
        [InlineData("different-sdk-ucrt", true)]
        [InlineData("relative", true)]
        [InlineData("no-responses", true)]
        [InlineData("missing-response", true)]
        public void ActualResponseFilesMustPreservePreparedPrecedenceAndSelectedSdkRoots(string scenario, bool throws)
        {
            using var result = Run(scenario, response: true);
            Assert.Equal(throws, result.RootElement.GetProperty("threw").GetBoolean());
            if (throws)
            {
                Assert.False(string.IsNullOrEmpty(result.RootElement.GetProperty("error").GetString()));
            }
            else
            {
                var record = Assert.Single(result.RootElement.GetProperty("records").EnumerateArray());
                Assert.Equal(result.RootElement.GetProperty("responseSha256").GetString(),
                    record.GetProperty("sha256").GetString());
                Assert.EndsWith("Owner.settings.rsp", record.GetProperty("responseFile").GetString());
                Assert.True(record.GetProperty("includeDirectories").GetArrayLength() >= 7);
            }
        }

        [Theory]
        [InlineData("valid", false, true)]
        [InlineData("invalid-fallback", true, false)]
        [InlineData("rsp-fallback-first", true, true)]
        [InlineData("rsp-unprepared-sdk", true, true)]
        [InlineData("missing-response", true, true)]
        public void OrdinaryDriverRejectsUnsafeInputsAndDoesNotAcceptUnsafeEmittedResponses(
            string scenario, bool throws, bool producerCalled)
        {
            using var result = Run(scenario, response: true, driver: true);
            Assert.Equal(throws, result.RootElement.GetProperty("threw").GetBoolean());
            Assert.Equal(producerCalled, result.RootElement.GetProperty("producerCalled").GetBoolean());
            Assert.Equal(producerCalled, result.RootElement.GetProperty("outputCreated").GetBoolean());
            if (producerCalled)
            {
                var ordinary = result.RootElement.GetProperty("ordinary");
                Assert.Equal(0, ordinary.GetProperty("exitCode").GetInt32());
                Assert.Equal(!throws, ordinary.GetProperty("preparedHeaderIncludeValidation").GetProperty("complete").GetBoolean());
                Assert.Contains(result.RootElement.GetProperty("pins").EnumerateArray(),
                    pin => pin.GetProperty("path").GetString().EndsWith("PreparedSdkHeaderIncludes.ps1"));
                if (!throws)
                {
                    string[] includes = result.RootElement.GetProperty("selectedIncludes").EnumerateArray()
                        .Select(value => value.GetString()).ToArray();
                    Assert.Equal(6, includes.Length);
                    Assert.Equal(new[] { "shared", "um", "ucrt", "winrt" }, includes.Take(4).Select(Path.GetFileName));
                }
            }
        }

        private static JsonDocument Run(string scenario, bool response, bool driver = false)
        {
            string root = Path.Combine(Path.GetTempPath(), "PreparedIncludeTests-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(root);
            try
            {
                string data = Convert.ToBase64String(Encoding.UTF8.GetBytes(JsonSerializer.Serialize(new
                {
                    repo = WinHttpMigrationTests.RepositoryRoot,
                    root,
                    scenario,
                    response,
                    driver,
                })));
                string script = "$data = [Text.Encoding]::UTF8.GetString([Convert]::FromBase64String('" + data + @"')) | ConvertFrom-Json
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
. (Join-Path $data.repo 'scripts\PreparedSdkHeaderIncludes.ps1')
$prepared = Join-Path $data.root 'prepared\headers'
$canonical = @('shared', 'um', 'ucrt', 'winrt' | ForEach-Object { Join-Path $prepared $_ })
$project = Join-Path $data.root 'project'
$msvc = Join-Path $data.root 'compiler\include'
$ucrt = Join-Path $data.root 'selected-sdk\ucrt'
$foreign = Join-Path $data.root 'unprepared-sdk\um'
$otherUcrt = Join-Path $data.root 'other-sdk\ucrt'
$selectedSource = Join-Path $data.root 'selected-source\inc'
foreach ($directory in @($canonical) + @(($project + '\inc'), $msvc, $ucrt, $foreign, $otherUcrt, $selectedSource)) {
    [IO.Directory]::CreateDirectory($directory) | Out-Null
}
[IO.File]::WriteAllText((Join-Path $msvc 'vcruntime.h'), '')
[IO.File]::WriteAllText((Join-Path $ucrt 'corecrt.h'), '')
[IO.File]::WriteAllText((Join-Path $otherUcrt 'corecrt.h'), '')
$fallbacks = @($msvc, $ucrt)
$result = [ordered]@{}
if ($data.driver) {
    $tools = Join-Path $data.root 'tools'
    $assets = Join-Path $tools 'assets'
    [IO.Directory]::CreateDirectory((Join-Path $assets 'scraper')) | Out-Null
    $files = @(foreach ($name in @('MetadataTasks.dll', 'MetadataUtils.dll', 'Win32MetadataScraper.dll')) {
        $file = Join-Path $tools $name
        [IO.File]::WriteAllText($file, 'fixture runtime')
        [ordered]@{ path = $name; sha256 = (Get-FileHash -LiteralPath $file).Hash }
    })
    [IO.File]::WriteAllText((Join-Path $assets 'scraper.sdk.targets'), '<Project />')
    $manifest = Join-Path $data.root 'runtime.json'
    [IO.File]::WriteAllText($manifest, (@{ files = $files } | ConvertTo-Json -Depth 4))
    $annotation = Join-Path $data.root 'standalone.h'
    [IO.File]::WriteAllText($annotation, 'fixture annotation header')
    [IO.File]::WriteAllText((Join-Path $prepared 'shared\win32metadata_annotations.h'), 'fixture annotation header')
    $partition = Join-Path $project 'Partitions\Owner'
    [IO.Directory]::CreateDirectory($partition) | Out-Null
    [IO.File]::WriteAllText((Join-Path $partition 'main.cpp'), '#include <sample.h>')
    [IO.File]::WriteAllText((Join-Path $partition 'settings.rsp'), '--config')
    $output = Join-Path $data.root 'ordinary'
    $global:guardProducerCalled = $false
    $global:guardContext = @{
        output = $output; prepared = $prepared; project = $project; canonical = $canonical
        fallbacks = $fallbacks; foreign = $foreign; scenario = $data.scenario
    }
    function global:dotnet {
        $global:guardProducerCalled = $true
        $global:LASTEXITCODE = 0
        $ctx = $global:guardContext
        $scratch = Join-Path $ctx.output 'obj\scratch\x64'
        [IO.Directory]::CreateDirectory($scratch) | Out-Null
        if ($ctx.scenario -eq 'missing-response') { return }
        $includes = @($ctx.project + '\inc') + $ctx.canonical + $ctx.fallbacks
        if ($ctx.scenario -eq 'rsp-fallback-first') { $includes = @($ctx.project + '\inc') + $ctx.fallbacks + $ctx.canonical }
        if ($ctx.scenario -eq 'rsp-unprepared-sdk') { $includes += $ctx.foreign }
        [IO.File]::WriteAllLines((Join-Path $scratch 'Owner.settings.rsp'),
            @('--include-directory') + $includes + @('--traverse', ($ctx.prepared + '\um\sample.h')))
    }
    $native = $fallbacks
    if ($data.scenario -eq 'invalid-fallback') { $native += $foreign }
    try {
        $null = & (Join-Path $data.repo 'scripts\Invoke-PreparedSdkPartitions.ps1') `
            -ProjectDirectory $project -IncludeRoot $prepared -ToolsDirectory $tools `
            -RuntimeManifest $manifest -RuntimeManifestSha256 (Get-FileHash -LiteralPath $manifest).Hash `
            -AnnotationHeader $annotation -OutputDirectory $output -Partition Owner `
            -NativeIncludeDirectory $native -Architecture x64
        $result.threw = $false
    } catch { $result.threw = $true; $result.error = $_.ToString() }
    $result.producerCalled = $global:guardProducerCalled
    $result.outputCreated = Test-Path -LiteralPath $output
    if (Test-Path -LiteralPath (Join-Path $output 'ordinary-result.json')) {
        $result.ordinary = Get-Content -LiteralPath (Join-Path $output 'ordinary-result.json') -Raw | ConvertFrom-Json
        $inputs = Get-Content -LiteralPath (Join-Path $output 'ordinary-inputs.json') -Raw | ConvertFrom-Json
        $result.pins = @($inputs.inputs)
        $result.selectedIncludes = @($inputs.preparedAndNativeIncludeDirectories)
    }
} elseif (!$data.response) {
    $native = $fallbacks
    if ($data.scenario -eq 'duplicate') { $native = @($canonical[1], $msvc, $ucrt, $canonical[0], $msvc.ToUpperInvariant()) }
    if ($data.scenario -in @('shared', 'um', 'winrt', 'unrecognized')) {
        $native += Join-Path $data.root ('unprepared-sdk\' + $data.scenario)
        [IO.Directory]::CreateDirectory($native[-1]) | Out-Null
    }
    try { $result.includes = @(Get-PreparedSdkHeaderIncludes $prepared $native); $result.threw = $false }
    catch { $result.threw = $true; $result.error = $_.ToString() }
} else {
    $includes = @($project + '\inc') + $canonical + $fallbacks
    $traverse = @($prepared + '\um\sample.h')
    switch ($data.scenario) {
        'duplicates-after-fallback' { $includes += $canonical }
        'selected-traverse' { $includes = @(($project + '\inc'), $selectedSource) + $canonical + $fallbacks; $traverse += $selectedSource + '\selected.h' }
        'fallback-first' { $includes = @($project + '\inc') + $fallbacks + $canonical }
        'ucrt-first' { $includes = @(($project + '\inc'), $ucrt) + $canonical + @($msvc) }
        'unprepared-sdk-first' { $includes = @(($project + '\inc'), $foreign) + $canonical + $fallbacks }
        'unprepared-sdk-last' { $includes += $foreign }
        'unprepared-sdk-traverse' { $includes += $foreign; $traverse += $foreign + '\sample.h' }
        'different-sdk-ucrt' { $includes += $otherUcrt }
        'relative' { $includes += '.\um' }
    }
    if ($data.scenario.StartsWith('missing-') -and $data.scenario -ne 'missing-response') {
        $missing = Join-Path $prepared $data.scenario.Substring(8)
        $includes = @($includes | Where-Object { $_ -ne $missing })
    }
    $rsp = Join-Path $data.root 'Owner.settings.rsp'
    [IO.File]::WriteAllLines($rsp, @('--include-directory') + $includes + @('--traverse') + $traverse + @('--namespace', 'Windows.Win32'))
    $result.responseSha256 = (Get-FileHash -LiteralPath $rsp).Hash
    $responses = @($rsp)
    if ($data.scenario -eq 'no-responses') { $responses = @() }
    if ($data.scenario -eq 'missing-response') { $responses += Join-Path $data.root 'Missing.settings.rsp' }
    try {
        $result.records = @(Assert-PreparedSdkHeaderIncludes -IncludeRoot $prepared -ProjectDirectory $project -ResponseFile $responses -NativeIncludeDirectory $fallbacks)
        $result.threw = $false
    } catch { $result.threw = $true; $result.error = $_.ToString() }
}
$result | ConvertTo-Json -Depth 7 -Compress
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
                    throw new TimeoutException("The prepared include regression did not finish.");
                }
                Assert.True(process.ExitCode == 0, error.GetAwaiter().GetResult() + output.GetAwaiter().GetResult());
                return JsonDocument.Parse(output.GetAwaiter().GetResult());
            }
            finally
            {
                Directory.Delete(root, recursive: true);
            }
        }
    }
}
