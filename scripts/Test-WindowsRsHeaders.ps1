param([switch]$EntryPointArgumentsOnly)

$ErrorActionPreference = "Stop"
$PSNativeCommandUseErrorActionPreference = $false
$repo = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$prepare = Join-Path $PSScriptRoot "Prepare-WindowsRsHeaders.ps1"
$fixture = Join-Path $repo "obj\WindowsRsHeadersTests\fixture with spaces-$([Guid]::NewGuid().ToString('N'))"
$mirror = Join-Path $fixture "RecompiledIdlHeaders\um"
$patches = Join-Path $fixture "patches\post-midl"
$prepared = Join-Path $fixture "obj\RecompiledIdlHeaders"
$manifest = Join-Path $fixture "obj\windows-rs-headers.json"
$header = Join-Path $mirror "fixture.h"
$preparedHeader = Join-Path $prepared "um\fixture.h"
$toolDir = Join-Path $repo "bin\GeneratorSdk\tools\win-x64"
$tool = Join-Path $toolDir "win32metadata-tools.exe"
$utils = Join-Path $repo "bin\Release\net10.0\WinmdUtils.dll"
$job = $null

function Assert {
    param([bool]$Condition, [string]$Message)
    if (!$Condition) { throw $Message }
}

function Write-Patch {
    param([string]$Name, [int]$Before, [int]$After)
    @"
diff --git a/generation/WinSDK/RecompiledIdlHeaders/um/fixture.h b/generation/WinSDK/RecompiledIdlHeaders/um/fixture.h
--- a/generation/WinSDK/RecompiledIdlHeaders/um/fixture.h
+++ b/generation/WinSDK/RecompiledIdlHeaders/um/fixture.h
@@ -1 +1 @@
-enum PREPARATION_VALUE { PREPARATION_MARKER = $Before };
+enum PREPARATION_VALUE { PREPARATION_MARKER = $After };

"@ | Set-Content -LiteralPath (Join-Path $patches $Name) -Encoding utf8NoBOM -NoNewline
}

function Invoke-Preparation {
    & $prepare -WinSdkRoot $fixture
    Assert ((Get-Content $header -Raw).Contains("= 1")) "Preparation changed the pristine mirror."
}

function Assert-NativeFailure {
    param([scriptblock]$Command, [int]$Code, [string]$Diagnostic)
    $messages = & $Command 2>&1 | Out-String
    Assert ($LASTEXITCODE -eq $Code) "Expected exit $Code, got $LASTEXITCODE`: $messages"
    Assert ($messages.Contains($Diagnostic)) "Missing diagnostic '$Diagnostic': $messages"
    $global:LASTEXITCODE = 0
}

function Get-ProjectEvaluation {
    param([switch]$Raw)
    $arguments = @("msbuild", (Join-Path $repo "generation\WinSDK\Windows.Win32.proj"),
        "-nologo", "-getProperty:OutputWinmd,TargetArchitectures,WinmdArchitectureJobs,WinmdNativeJobs,WinmdUseOriginalCompilation,WinmdUsePartitionAuthority,Win32MetadataToolsCommand",
        "-getItem:WinmdIncludeDir,WinmdPartitionPolicyRoot,WinmdNamespaceRoutes")
    if ($Raw) { $arguments += "-p:WinmdUsePartitionAuthority=false" }
    $text = & dotnet @arguments | Out-String
    Assert ($LASTEXITCODE -eq 0) "Project evaluation failed: $text"
    $text | ConvertFrom-Json
}

function Test-GenerateEntryPointArguments {
    $entryRoot = Join-Path $fixture "entrypoint"
    $entryScripts = Join-Path $entryRoot "scripts"
    $entryToolDir = Join-Path $entryRoot "bin\GeneratorSdk\tools\win-x64"
    foreach ($directory in @($entryScripts, $entryToolDir,
        (Join-Path $entryRoot "obj\BuildTools.proj"),
        (Join-Path $entryRoot "sdk\c\include\fixture"),
        (Join-Path $entryRoot "generation\WinSDK\Partitions\Foundation"))) {
        New-Item -ItemType Directory -Path $directory -Force | Out-Null
    }
    Set-Content -LiteralPath (Join-Path $entryRoot "obj\BuildTools.proj\BuildTools.proj.nuget.g.props") -Value ""
    Set-Content -LiteralPath (Join-Path $entryRoot "generation\WinSDK\Partitions\Foundation\main.cpp") -Value ""
    Copy-Item -LiteralPath (Join-Path $PSScriptRoot "WindowsRsGenerationProvenance.ps1") -Destination $entryScripts
    $source = Get-Content (Join-Path $PSScriptRoot "Generate-WindowsRsWinmd.ps1") -Raw
    # Only the test relay's file extension changes; argument construction executes unchanged.
    Set-Content -LiteralPath (Join-Path $entryScripts "Generate.ps1") -Value $source.Replace("win32metadata-tools.exe", "win32metadata-tools.ps1")
    @'
$rootDir = [IO.Path]::GetFullPath("$PSScriptRoot\..")
$windowsWin32ProjectRoot = Join-Path $rootDir "generation\WinSDK"
$recompiledIdlHeadersDir = Join-Path $windowsWin32ProjectRoot "obj\RecompiledIdlHeaders"
function Get-WinSdkCppPkgPath { Join-Path $rootDir "sdk" }
function Get-WinSdkCppX64PkgPath { Join-Path $rootDir "sdk" }
function Get-WinSdkHeaderVersion { "fixture" }
function nbgv { "1.0.0.0" }
function ThrowOnNativeProcessError {}
'@ | Set-Content -LiteralPath (Join-Path $entryScripts "CommonUtils.ps1")
    @'
param([string]$ToolPath, [string[]]$ToolArguments)
$ToolArguments | ConvertTo-Json | Set-Content -LiteralPath "$PSScriptRoot\..\arguments.json"
if ($ToolArguments -contains "--output" -and $ToolArguments -contains "--partition-policy-root") {
    $position = [Array]::IndexOf($ToolArguments, "--output")
    $output = [IO.Path]::GetFullPath($ToolArguments[$position + 1])
    New-Item -ItemType Directory -Force -Path (Split-Path $output) | Out-Null
    '{"schema":1,"partial":false,"omissionCount":0,"architectures":[{"arch":"x64","partial":false,"omissionCount":0,"omissions":[]},{"arch":"x86","partial":false,"omissionCount":0,"omissions":[]},{"arch":"arm64","partial":false,"omissionCount":0,"omissions":[]}]}' |
        Set-Content -LiteralPath "$output.enum-diagnostics.json"
}
'@ | Set-Content -LiteralPath (Join-Path $entryScripts "Prepare-WindowsRsHeaders.ps1")
    @'
$args | ConvertTo-Json | Set-Content -LiteralPath "$PSScriptRoot\..\..\..\..\arguments.json"
'@ | Set-Content -LiteralPath (Join-Path $entryToolDir "win32metadata-tools.ps1")
    $entry = Join-Path $entryScripts "Generate.ps1"
    foreach ($case in @(
        @{ arguments = @(); jobs = "1"; original = $false; policy = $true; focused = $false },
        @{ arguments = @("-UseOriginalCompilation", "-NativeJobs", "4", "-ArchitectureJobs", "1"); jobs = "4"; original = $true; policy = $true; focused = $false },
        @{ arguments = @("-Partition", "Foundation", "-NativeJobs", "2"); jobs = "2"; original = $false; policy = $false; focused = $true },
        @{ arguments = @("-RawSdk"); jobs = "1"; original = $false; policy = $false; focused = $false },
        @{ arguments = @("-UsePartitionAuthority:`$false", "-NativeJobs", "2"); jobs = "2"; original = $false; policy = $false; focused = $false }
    )) {
        $messages = & pwsh -NoProfile -File $entry -SkipBuild @($case.arguments) 2>&1 | Out-String
        Assert ($LASTEXITCODE -eq 0) "Generation argument fixture failed: $messages"
        $received = @(Get-Content (Join-Path $entryRoot "arguments.json") -Raw | ConvertFrom-Json)
        $jobs = [Array]::IndexOf([string[]]$received, "--native-jobs")
        Assert ($jobs -ge 0 -and $received[$jobs + 1] -ceq $case.jobs) "Native job argument changed."
        $architectureJobs = [Array]::IndexOf([string[]]$received, "--architecture-jobs")
        $expectedArchitectureJobs = if ($case.original) { "1" } else { "3" }
        Assert ($architectureJobs -ge 0 -and $received[$architectureJobs + 1] -ceq $expectedArchitectureJobs) "Architecture worker settings changed."
        Assert (($received -contains "--original-compilation") -eq $case.original) "Original opt-in changed."
        Assert (!($received -contains "--candidate-compilation")) "Entrypoint acquired candidate grouping."
        Assert (($received -contains "--partition-policy-root") -eq $case.policy) "Partition-policy selection changed."
        Assert (($received -contains "--partition") -eq $case.focused) "Selected partition behavior changed."
        $architectures = @($received | Where-Object { $_ -in @("x64", "x86", "arm64") })
        Assert (($architectures -join ",") -ceq "x64,x86,arm64") "Default architecture selection changed."
        Assert ($received -contains "--output" -and $received -contains "--obj") "Output/provenance inputs changed."
        if ($case.policy) {
            Assert ($messages.Contains("Generated complete SDK WinMD:") -and
                $messages.Contains("Enum omission entries: 0; full report:")) "SDK completeness summary was lost."
        }
    }
    foreach ($arguments in @(
        @("-NativeJobs", "0"),
        @("-UseOriginalCompilation", "-RawSdk"),
        @("-UseOriginalCompilation", "-Partition", "Foundation"),
        @("-UseOriginalCompilation", "-UsePartitionAuthority:`$false")
    )) {
        $messages = & pwsh -NoProfile -File $entry -SkipBuild @arguments 2>&1 | Out-String
        Assert ($LASTEXITCODE -eq 1 -and $messages -match "NativeJobs|requires partition authority") "Invalid generation mode was accepted: $messages"
    }
    $global:LASTEXITCODE = 0
    Write-Host "Generation entrypoint default/original/focused/raw/native-job argument controls passed without SDK execution."
}

function Test-EnumDiagnosticsReporting {
    . (Join-Path $PSScriptRoot "WindowsRsGenerationProvenance.ps1")
    $reportRoot = Join-Path $fixture "enum-report"
    New-Item -ItemType Directory -Path $reportRoot -Force | Out-Null
    $output = Join-Path $reportRoot "Windows.Win32.winmd"
    $reportPath = "$output.enum-diagnostics.json"
    $preparation = Join-Path $reportRoot "preparation.json"
    $fakeTool = Join-Path $reportRoot "tool.txt"
    Set-Content -LiteralPath $output -Value "portable output-binding fixture, not a WinMD"
    Set-Content -LiteralPath $preparation -Value "{}"
    Set-Content -LiteralPath $fakeTool -Value "portable tool-binding fixture"
    $reportJson = @'
{"schema":1,"partial":true,"omissionCount":1,"architectures":[{"arch":"x64","partial":true,"omissionCount":1,"omissions":[{"declaration":{"origin":{"tu":"original.cpp","local":17},"kind":null,"name":"Interface","source":{"file":"C:\\sdk\\header.h","offset":42},"namespace":"Windows.Win32.Test","methods":["First","Second\"Method"]},"cause":"ExcludedDependency","reason":"required excluded enum\n","dependencyChain":[{"origin":{"tu":"original.cpp","local":17},"kind":null,"name":"Interface","source":{"file":"C:\\sdk\\header.h","offset":42},"namespace":"Windows.Win32.Test","methods":["First","Second\"Method"]},{"origin":{"tu":"original.cpp","local":16},"kind":"Enum","name":"RequiredEnum","source":{"file":"C:\\sdk\\header.h","offset":12},"namespace":"Windows.Win32.Test","methods":[]}]}]}]}
'@
    Set-Content -LiteralPath $reportPath -Value $reportJson
    $diagnostics = Get-WindowsRsEnumDiagnostics -OutputPath $output -Architectures @("x64")
    Assert ($diagnostics.partial -and $diagnostics.omissionCount -eq 1 -and
        $diagnostics.sha256 -ceq (Get-FileHash -LiteralPath $reportPath).Hash) "Partial report was not fully validated and hash-bound."
    $receipt = [ordered]@{
        schema = 1
        output = $output
        outputSha256 = (Get-FileHash -LiteralPath $output).Hash
        tool = $fakeTool
        toolSha256 = (Get-FileHash -LiteralPath $fakeTool).Hash
        preparation = $preparation
        preparationSha256 = (Get-FileHash -LiteralPath $preparation).Hash
        arguments = @("scrape", "--win32-sdk", "--partition-policy-root", $reportRoot,
            "--include", $reportRoot, "--arch", "x64")
        enumDiagnostics = $diagnostics
        metadataStatus = "partial"
    }
    $receipt | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath "$output.provenance.json"
    $verified = Get-WindowsRsGenerationProvenance -OutputPath $output -PreparationPath $preparation -PreparedRoot $reportRoot
    Assert ($verified.metadataStatus -ceq "partial") "Provenance lost explicit partial status."

    $enumOnly = $reportJson | ConvertFrom-Json
    $enumOmission = $enumOnly.architectures[0].omissions[0]
    $enumOmission.declaration = $enumOmission.dependencyChain[-1]
    $enumOmission.cause = "ConflictingDeclarations"
    $enumOmission.dependencyChain = @($enumOmission.declaration)
    $enumOnly | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath $reportPath
    $enumDiagnostics = Get-WindowsRsEnumDiagnostics -OutputPath $output -Architectures @("x64")
    Assert ($enumDiagnostics.partial -and $enumDiagnostics.omissionCount -eq 1) "One-entry conflicting enum chain was rejected."

    foreach ($mutation in @("empty", "truncated", "first", "terminal", "methods")) {
        $changed = $reportJson | ConvertFrom-Json
        $chain = $changed.architectures[0].omissions[0].dependencyChain
        if ($mutation -ceq "empty") { $changed.architectures[0].omissions[0].dependencyChain = @() }
        if ($mutation -ceq "truncated") { $changed.architectures[0].omissions[0].dependencyChain = @($chain[0]) }
        if ($mutation -ceq "first") { $chain[0].origin.local = 18 }
        if ($mutation -ceq "terminal") { $chain[-1].kind = "Typedef" }
        if ($mutation -ceq "methods") { $chain[0].methods = @("Second`"Method", "First") }
        $changed | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath $reportPath
        $rejected = $false
        try { Get-WindowsRsEnumDiagnostics -OutputPath $output -Architectures @("x64") | Out-Null }
        catch { $rejected = $true }
        Assert $rejected "Invalid $mutation dependency chain was accepted."
    }

    $invalidJson = @(
        $reportJson.Replace('"schema":1', '"schema":"1"'),
        $reportJson.Replace('"partial":true', '"partial":false'),
        $reportJson.Replace('"omissionCount":1', '"omissionCount":2'),
        $reportJson.Replace('"arch":"x64"', '"arch":"x86"'),
        $reportJson.Replace('"kind":null,', ''),
        $reportJson.Replace('"local":17', '"local":-1'),
        $reportJson.Replace('"offset":42', '"offset":"42"'),
        $reportJson.Replace('["First","Second\"Method"]', '[17]'),
        $reportJson.Replace('"ExcludedDependency"', '"UnknownCause"'),
        $reportJson.Replace('"dependencyChain":[', '"dependencyChain":null,"lostChain":['),
        $reportJson.Replace('"name":"RequiredEnum"', '"name":null'),
        '{"schema":1'
    )
    foreach ($invalid in $invalidJson) {
        Set-Content -LiteralPath $reportPath -Value $invalid
        $rejected = $false
        try { Get-WindowsRsEnumDiagnostics -OutputPath $output -Architectures @("x64") | Out-Null }
        catch { $rejected = $true }
        Assert $rejected "Malformed, incomplete or mismatched report was accepted: $invalid"
    }
    Set-Content -LiteralPath $reportPath -Value $reportJson
    foreach ($mutation in @("hash", "status", "image")) {
        $changed = Get-Content -LiteralPath "$output.provenance.json" -Raw | ConvertFrom-Json
        if ($mutation -ceq "hash") { $changed.enumDiagnostics.sha256 = "wrong" }
        if ($mutation -ceq "status") { $changed.metadataStatus = "complete" }
        if ($mutation -ceq "image") { $changed.outputSha256 = "wrong" }
        $changed | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath "$output.provenance.json"
        $rejected = $false
        try { Get-WindowsRsGenerationProvenance -OutputPath $output -PreparationPath $preparation -PreparedRoot $reportRoot | Out-Null }
        catch { $rejected = $true }
        Assert $rejected "Provenance accepted mismatched $mutation binding."
        $receipt | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath "$output.provenance.json"
    }
    Remove-Item -LiteralPath $reportPath
    $rejected = $false
    try { Get-WindowsRsEnumDiagnostics -OutputPath $output -Architectures @("x64") | Out-Null }
    catch { $rejected = $true }
    Assert $rejected "Missing diagnostic report was treated as zero omissions."
    '{"schema":1,"partial":false,"omissionCount":0,"architectures":[{"arch":"x64","partial":false,"omissionCount":0,"omissions":[]}]}' |
        Set-Content -LiteralPath $reportPath
    $complete = Get-WindowsRsEnumDiagnostics -OutputPath $output -Architectures @("x64")
    Assert (!$complete.partial -and $complete.omissionCount -eq 0) "Zero-omission report was rejected."
    Write-Host "Portable SDK enum report shape/count/status/provenance negative controls passed without native execution."
}

try {
    $buildPositionals = @((Get-Command (Join-Path $PSScriptRoot "BuildMetadataBin.ps1")).ParameterSets.Parameters |
        Where-Object Position -ge 0 | Sort-Object Position | ForEach-Object Name)
    Assert (($buildPositionals -join ",") -ceq "arch,ArchitectureJobs,NativeJobs") "BuildMetadataBin changed existing positional parameter bindings."
    $generatePositionals = @((Get-Command (Join-Path $PSScriptRoot "Generate-WindowsRsWinmd.ps1")).ParameterSets.Parameters |
        Where-Object Position -ge 0 | Sort-Object Position | ForEach-Object Name)
    Assert (($generatePositionals -join ",") -ceq "Partition,Architecture,ExtractionCoverage,OutputWinmd,Namespace,ArchitectureJobs,NativeJobs") "Generate-WindowsRsWinmd changed existing positional parameter bindings."
    Test-GenerateEntryPointArguments
    Test-EnumDiagnosticsReporting
    if ($EntryPointArgumentsOnly) { return }

    New-Item -ItemType Directory -Path $mirror -Force | Out-Null
    Set-Content -LiteralPath $header -Value "enum PREPARATION_VALUE { PREPARATION_MARKER = 1 };" -Encoding ascii
    Invoke-Preparation
    Assert ((Get-Content $manifest -Raw | ConvertFrom-Json).patchCount -eq 0) "Zero-patch preparation was not recorded."
    $timestamp = (Get-Item $preparedHeader).LastWriteTimeUtc
    Invoke-Preparation
    Assert ((Get-Item $preparedHeader).LastWriteTimeUtc -eq $timestamp) "Unchanged inputs were unnecessarily copied."

    New-Item -ItemType Directory -Path $patches -Force | Out-Null
    Write-Patch "b.patch" 2 3
    Write-Patch "a.patch" 1 2
    Invoke-Preparation
    Assert ((Get-Content $preparedHeader -Raw).Contains("= 3")) "Sorted patches were not applied exactly once."
    $manifestHash = (Get-FileHash $manifest).Hash
    Invoke-Preparation
    Assert ((Get-FileHash $manifest).Hash -ceq $manifestHash) "Repeated preparation changed the manifest."
    Set-Content -LiteralPath $preparedHeader -Value "stale header"
    Set-Content -LiteralPath (Join-Path $prepared "stale.h") -Value "stale file"
    $outside = Join-Path $fixture "obj\preserve-me.txt"
    Set-Content -LiteralPath $outside -Value "user file"
    Invoke-Preparation
    Assert ((Get-Content $preparedHeader -Raw).Contains("= 3")) "Mutated output was not replaced."
    Assert (!(Test-Path (Join-Path $prepared "stale.h"))) "Unexpected generated file survived preparation."
    Assert ((Get-Content $outside -Raw).Trim() -ceq "user file") "Preparation modified an unrelated obj file."
    Write-Patch "b.patch" 2 4
    Invoke-Preparation
    Assert ((Get-Content $preparedHeader -Raw).Contains("= 4")) "Changed patch was ignored."
    Remove-Item -LiteralPath (Join-Path $patches "b.patch")
    Invoke-Preparation
    Assert ((Get-Content $preparedHeader -Raw).Contains("= 2")) "Removed patch survived preparation."

    Write-Patch "b.patch" 99 4
    Assert-NativeFailure { & pwsh -NoProfile -File $prepare -WinSdkRoot $fixture } 1 "post-midl patches failed"
    Assert (!(Test-Path $manifest)) "Failed preparation left a reusable success manifest."
    Remove-Item -LiteralPath (Join-Path $patches "b.patch")
    Invoke-Preparation

    # Relay tests exercise native argument/stream/exit handling independently of Clang.
    $relaySource = Join-Path $fixture "relay-source"
    New-Item -ItemType Directory -Path $relaySource | Out-Null
    $relay = Join-Path $fixture "relay-bin\Relay.exe"
    @'
using System;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading;
class Relay
{
    static int Main(string[] args)
    {
        string root = Path.GetDirectoryName(Path.GetDirectoryName(Environment.ProcessPath));
        File.WriteAllText(Path.Combine(root, "arguments.json"), JsonSerializer.Serialize(args));
        Console.Out.WriteLine("relay stdout");
        Console.Error.WriteLine("relay stderr");
        if (args.Contains("--fail")) return 37;
        if (args.Contains("--hold"))
        {
            File.WriteAllText(Path.Combine(root, "reader.pid"), Environment.ProcessId.ToString());
            File.WriteAllText(Path.Combine(root, "ready"), "ready");
            while (!File.Exists(Path.Combine(root, "release"))) Thread.Sleep(100);
        }
        return 0;
    }
}
'@ | Set-Content -LiteralPath (Join-Path $relaySource "Relay.cs") -Encoding ascii
    @'
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>net10.0</TargetFramework>
    <OutputPath>..\relay-bin</OutputPath>
    <AppendTargetFrameworkToOutputPath>false</AppendTargetFrameworkToOutputPath>
  </PropertyGroup>
</Project>
'@ | Set-Content -LiteralPath (Join-Path $relaySource "Relay.csproj") -Encoding ascii
    & dotnet build (Join-Path $relaySource "Relay.csproj") -p:ImportDirectoryBuildProps=false --verbosity quiet
    Assert ($LASTEXITCODE -eq 0) "Could not build the native argument/exit relay."
    $relayArgs = @("scrape", "--include", $prepared, "--label", 'value with "quotes" and spaces')
    $stdout = Join-Path $fixture "relay.stdout"
    $stderr = Join-Path $fixture "relay.stderr"
    & pwsh -NoProfile -File $prepare -WinSdkRoot $fixture -ToolPath $relay @relayArgs 1> $stdout 2> $stderr
    Assert ($LASTEXITCODE -eq 0) "Relay failed: $(Get-Content $stderr -Raw)"
    $received = @(Get-Content (Join-Path $fixture "arguments.json") -Raw | ConvertFrom-Json)
    Assert (($received | ConvertTo-Json -Compress) -ceq ($relayArgs | ConvertTo-Json -Compress)) "Native arguments changed: $($received -join ', ')"
    Assert ((Get-Content $stdout -Raw).Contains("relay stdout") -and
        (Get-Content $stderr -Raw).Contains("relay stderr")) "Native output streams were lost."
    Assert-NativeFailure { & pwsh -NoProfile -File $prepare -WinSdkRoot $fixture -ToolPath $relay @relayArgs --fail } 37 "relay stderr"
    Invoke-Preparation

    $job = Start-Job -ScriptBlock {
        param($Prepare, $Fixture, $Relay, $Prepared)
        & $Prepare -WinSdkRoot $Fixture -ToolPath $Relay -ToolArguments @("scrape", "--include", $Prepared, "--hold")
    } -ArgumentList $prepare, $fixture, $relay, $prepared
    $timer = [System.Diagnostics.Stopwatch]::StartNew()
    while (!(Test-Path (Join-Path $fixture "ready")) -and $timer.Elapsed.TotalSeconds -lt 30) {
        if ($job.State -in @("Completed", "Failed", "Stopped")) { break }
        Start-Sleep -Milliseconds 100
    }
    if (!(Test-Path (Join-Path $fixture "ready"))) {
        throw "Reader did not start: $(Receive-Job $job -ErrorAction Continue 2>&1 | Out-String)"
    }
    $activeHash = (Get-FileHash $preparedHeader).Hash
    Write-Patch "b.patch" 2 5
    Assert-NativeFailure { & pwsh -NoProfile -File $prepare -WinSdkRoot $fixture -LockTimeoutSeconds 0 } 1 "Timed out"
    Assert-NativeFailure {
        & pwsh -NoProfile -File $prepare -WinSdkRoot $fixture -LockTimeoutSeconds 0 -Clean `
            -CleanObjectDirectory (Join-Path $fixture "obj\winmd") -CleanOutput (Join-Path $fixture "bin\Fixture.winmd")
    } 1 "Timed out"
    Assert ((Get-FileHash $preparedHeader).Hash -ceq $activeHash) "A concurrent preparation replaced an active reader's tree."
    Stop-Job $job
    $readerPid = [int](Get-Content (Join-Path $fixture "reader.pid"))
    Assert (!(Get-Process -Id $readerPid -ErrorAction SilentlyContinue)) "Cancellation left the native reader running."
    Remove-Job $job
    $job = $null
    Invoke-Preparation
    Assert ((Get-Content $preparedHeader -Raw).Contains("= 5")) "Cancellation did not release the preparation lock."

    $normal = Get-ProjectEvaluation
    Assert ($normal.Properties.WinmdUsePartitionAuthority -ceq "true") "Normal build did not select authority."
    Assert ($normal.Properties.OutputWinmd -ieq (Join-Path $repo "bin\Windows.Win32.winmd")) "Direct project output is not repo-root bin."
    Assert ($normal.Properties.TargetArchitectures -ceq "x64;x86;arm64") "Normal architecture scope changed."
    Assert ($normal.Properties.WinmdArchitectureJobs -ceq "3") "Normal build changed default architecture concurrency."
    Assert ($normal.Properties.WinmdNativeJobs -ceq "1") "Normal build changed default native concurrency."
    Assert ($normal.Properties.WinmdUseOriginalCompilation -ceq "false") "Normal build opted into original compilation."
    Assert ($normal.Items.WinmdIncludeDir.Count -eq 6) "Normal build did not retain exactly six include positions."
    Assert ($normal.Items.WinmdIncludeDir[0].FullPath -ieq (Join-Path $repo "generation\WinSDK\obj\RecompiledIdlHeaders")) "Normal build does not consume prepared headers first."
    Assert ($normal.Items.WinmdPartitionPolicyRoot.Count -eq 1 -and $normal.Items.WinmdNamespaceRoutes.Count -eq 1) "Normal authority inputs changed."
    $raw = Get-ProjectEvaluation -Raw
    Assert ($raw.Properties.WinmdArchitectureJobs -ceq "3") "Raw build changed default architecture concurrency."
    Assert ($raw.Properties.WinmdNativeJobs -ceq "1" -and $raw.Properties.WinmdUseOriginalCompilation -ceq "false") "Raw build changed native/default compilation settings."
    Assert (!$raw.Properties.Win32MetadataToolsCommand -and !$raw.Items.WinmdPartitionPolicyRoot.Count -and
        !($raw.Items.WinmdIncludeDir.FullPath -contains $normal.Items.WinmdIncludeDir[0].FullPath)) "Raw mode acquired prepared inputs/authority."
    foreach ($entrypoint in @("BuildMetadataBin.ps1", "Generate-WindowsRsWinmd.ps1")) {
        Assert-NativeFailure {
            & pwsh -NoProfile -File (Join-Path $PSScriptRoot $entrypoint) -ArchitectureJobs 0
        } 1 "ArchitectureJobs"
    }
    Assert-NativeFailure {
        & pwsh -NoProfile -File (Join-Path $PSScriptRoot "BuildMetadataBin.ps1") -NativeJobs 0
    } 1 "NativeJobs"
    Assert-NativeFailure {
        & pwsh -NoProfile -File (Join-Path $PSScriptRoot "BuildMetadataBin.ps1") -RawSdk -UseOriginalCompilation
    } 1 "cannot be combined"

    Assert (Test-Path $tool) "Build the native tool before running header-generation tests."
    if (!(Test-Path $utils)) {
        & dotnet build (Join-Path $repo "sources\WinmdUtils\WinmdUtils.csproj") -c Release --verbosity quiet
        Assert ($LASTEXITCODE -eq 0) "WinmdUtils build failed."
    }
    $project = Join-Path $fixture "Fixture.proj"
    $winmd = Join-Path $fixture "bin\Fixture.winmd"
    $dump = Join-Path $fixture "Fixture.apidump.cs"
    Set-Content -LiteralPath (Join-Path $fixture "main.cpp") -Value '#include <fixture.h>' -Encoding ascii
    @"
<Project>
  <PropertyGroup>
    <Win32MetadataToolsDir>$toolDir</Win32MetadataToolsDir>
    <Win32MetadataToolsCommand>pwsh -NoProfile -File &quot;$prepare&quot; -WinSdkRoot &quot;$fixture&quot; -ToolPath &quot;$tool&quot;</Win32MetadataToolsCommand>
    <UseWinSDKAssets>false</UseWinSDKAssets>
    <TargetArchitectures>x64;x86;arm64</TargetArchitectures>
  </PropertyGroup>
  <Import Project="$repo\sources\GeneratorSdk\sdk\sdk.props"/>
  <ItemGroup>
    <Partition Include="main.cpp"/>
    <WinmdIncludeDir Include="obj\RecompiledIdlHeaders"/>
    <WinmdIncludeDir Include="$repo\generation\WinSDK\AdditionalHeaders"/>
    <WinmdScopeHeader Include="fixture.h"/>
  </ItemGroup>
  <Import Project="$repo\sources\GeneratorSdk\sdk\sdk.targets"/>
</Project>
"@ | Set-Content -LiteralPath $project -Encoding utf8
    foreach ($expected in @(5, 6)) {
        Write-Patch "b.patch" 2 $expected
        & dotnet msbuild $project -nologo -t:EmitWinmd -verbosity:minimal
        Assert ($LASTEXITCODE -eq 0) "Fixture generation failed."
        & $prepare -WinSdkRoot $fixture -VerifyOutput $winmd
        $receipt = Get-Content "$winmd.provenance.json" -Raw | ConvertFrom-Json
        $jobOption = [Array]::IndexOf([string[]]$receipt.arguments, "--architecture-jobs")
        Assert ($jobOption -ge 0 -and $receipt.arguments[$jobOption + 1] -ceq "3") "Default worker bound is missing from provenance."
        $nativeOption = [Array]::IndexOf([string[]]$receipt.arguments, "--native-jobs")
        Assert ($nativeOption -ge 0 -and $receipt.arguments[$nativeOption + 1] -ceq "1") "Default native bound is missing from provenance."
        & dotnet $utils dump --winmd $winmd --output $dump
        Assert ($LASTEXITCODE -eq 0) "Fixture WinMD readback failed."
        Assert ((Get-Content $dump -Raw) -match "PREPARATION_MARKER\s*=\s*$expected\b") "Normal MSBuild generation ignored the changed patch."
    }
    $parallelHash = (Get-FileHash $winmd).Hash
    Assert-NativeFailure {
        & dotnet msbuild $project -nologo -t:EmitWinmd -p:WinmdArchitectureJobs=0 -verbosity:minimal
    } 1 "expected a positive integer"
    Assert-NativeFailure {
        & dotnet msbuild $project -nologo -t:EmitWinmd -p:WinmdNativeJobs=0 -verbosity:minimal
    } 1 "expected a positive integer"
    & dotnet msbuild $project -nologo -t:EmitWinmd -p:WinmdArchitectureJobs=1 -p:WinmdNativeJobs=2 -verbosity:minimal
    Assert ($LASTEXITCODE -eq 0) "Sequential fixture generation failed."
    & $prepare -WinSdkRoot $fixture -VerifyOutput $winmd
    $receipt = Get-Content "$winmd.provenance.json" -Raw | ConvertFrom-Json
    $jobOption = [Array]::IndexOf([string[]]$receipt.arguments, "--architecture-jobs")
    Assert ($jobOption -ge 0 -and $receipt.arguments[$jobOption + 1] -ceq "1") "Sequential override is missing from provenance."
    $nativeOption = [Array]::IndexOf([string[]]$receipt.arguments, "--native-jobs")
    Assert ($nativeOption -ge 0 -and $receipt.arguments[$nativeOption + 1] -ceq "2") "Native worker override is missing from provenance."
    Assert ((Get-FileHash $winmd).Hash -ceq $parallelHash) "Architecture worker count changed the normal output."
    Add-Content -LiteralPath $preparedHeader -Value "// unexpected modification"
    Assert-NativeFailure { & pwsh -NoProfile -File $prepare -WinSdkRoot $fixture -VerifyOutput $winmd } 1 "provenance is missing or stale"
    & $prepare -WinSdkRoot $fixture -Clean -CleanObjectDirectory (Join-Path $fixture "obj\winmd") -CleanOutput $winmd
    Assert (!(Test-Path $prepared) -and !(Test-Path $winmd) -and (Test-Path $outside)) "Clean did not preserve its directory boundaries."
    Write-Host "Header preparation, locking, raw/default properties and real multiarchitecture patched generation passed."
}
finally {
    if ($job) { Stop-Job $job; Remove-Job $job }
    $pidFile = Join-Path $fixture "reader.pid"
    if (Test-Path $pidFile) {
        $reader = Get-Process -Id ([int](Get-Content $pidFile)) -ErrorAction SilentlyContinue
        if ($reader -and $reader.Path -ieq $relay) { Stop-Process -Id $reader.Id }
    }
    if (Test-Path -LiteralPath $fixture) { Remove-Item -LiteralPath $fixture -Recurse -Force }
}
