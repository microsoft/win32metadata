#Requires -Version 7.0

[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$ProjectDirectory,
    [Parameter(Mandatory)][string]$IncludeRoot,
    [Parameter(Mandatory)][string]$ToolsDirectory,
    [Parameter(Mandatory)][string]$RuntimeManifest,
    [Parameter(Mandatory)][ValidatePattern('^[0-9A-Fa-f]{64}$')][string]$RuntimeManifestSha256,
    [Parameter(Mandatory)][string]$AnnotationHeader,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [Parameter(Mandatory)][string[]]$Partition,
    [Parameter(Mandatory)][string[]]$NativeIncludeDirectory,
    [string]$AssetsDirectory,
    [string]$SdkTargetsFile,
    [string]$ScriptsDirectory,
    [ValidateSet('Headers', 'Constants', 'Emit')][string]$Stage = 'Headers',
    [ValidateSet('crossarch', 'x86', 'x64', 'arm64')][string]$Architecture = 'crossarch',
    [ValidateRange(1, 64)][int]$MaxProcessors = 2,
    [switch]$UseNormalBuildScheduling
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
. "$PSScriptRoot\PreparedSdkHeaderIncludes.ps1"
if (!$AssetsDirectory) { $AssetsDirectory = Join-Path $ToolsDirectory 'assets' }
if (!$SdkTargetsFile) { $SdkTargetsFile = Join-Path $ToolsDirectory 'assets\scraper.sdk.targets' }
if (!$ScriptsDirectory) { $ScriptsDirectory = Join-Path $ProjectDirectory '..\..\scripts' }
foreach ($name in @('ProjectDirectory', 'IncludeRoot', 'ToolsDirectory', 'AssetsDirectory', 'OutputDirectory',
        'SdkTargetsFile', 'RuntimeManifest', 'AnnotationHeader', 'ScriptsDirectory')) {
    Set-Variable -Name $name -Value ([IO.Path]::GetFullPath((Get-Variable -Name $name -ValueOnly)).TrimEnd('\'))
}
if (Test-Path -LiteralPath $OutputDirectory) {
    throw 'Use a fresh ordinary-output directory, not a frozen or previously generated source tree.'
}
foreach ($inputRoot in @($ProjectDirectory, $IncludeRoot, $ToolsDirectory, $AssetsDirectory)) {
    if (!(Test-Path -LiteralPath $inputRoot -PathType Container)) {
        throw "An explicit ordinary-driver input root is missing: $inputRoot"
    }
    if ($OutputDirectory.StartsWith("$inputRoot\", [StringComparison]::OrdinalIgnoreCase) -or
        $inputRoot.StartsWith("$OutputDirectory\", [StringComparison]::OrdinalIgnoreCase)) {
        throw 'Ordinary output must not overlap source, prepared SDK, private tools or asset inputs.'
    }
}
foreach ($name in @('MetadataTasks.dll', 'MetadataUtils.dll', 'Win32MetadataScraper.dll')) {
    if (!(Test-Path -LiteralPath "$ToolsDirectory\$name" -PathType Leaf)) {
        throw "The coherent external ordinary runtime is missing $name. Ambient bins are not used."
    }
}
if ($Stage -ne 'Headers' -and !(Test-Path -LiteralPath "$ToolsDirectory\ConstantsScraper.dll" -PathType Leaf)) {
    throw 'This runtime supports scrape-only controls, not constants/emission: ConstantsScraper.dll is absent. Use a separately pinned qualified constants composition; do not substitute ambient binaries.'
}
if ($Stage -eq 'Emit' -and !(Test-Path -LiteralPath "$ToolsDirectory\ClangSharpSourceToWinmd.dll" -PathType Leaf)) {
    throw 'The selected coherent external runtime has no emitter.'
}
if ((Get-FileHash -LiteralPath $RuntimeManifest).Hash -ne $RuntimeManifestSha256) {
    throw 'The external runtime manifest does not match its selected immutable hash.'
}
$runtime = Get-Content -LiteralPath $RuntimeManifest -Raw | ConvertFrom-Json
$runtimeFiles = @($runtime.files)
if ($runtimeFiles.Count -eq 0) { throw 'The selected runtime manifest has no file bindings.' }
$runtimePaths = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
foreach ($row in $runtimeFiles) {
    $path = [IO.Path]::GetFullPath((Join-Path $ToolsDirectory $row.path))
    if (!$path.StartsWith("$ToolsDirectory\", [StringComparison]::OrdinalIgnoreCase) -or
        !$runtimePaths.Add($path) -or (Get-FileHash -LiteralPath $path).Hash -ne $row.sha256) {
        throw "An external runtime file is outside the selected root, duplicated or hash-mismatched: $($row.path)"
    }
}
foreach ($name in @('MetadataTasks.dll', 'MetadataUtils.dll', 'Win32MetadataScraper.dll')) {
    if (!$runtimePaths.Contains("$ToolsDirectory\$name")) {
        throw "The selected runtime manifest does not bind $name."
    }
}
$rid = [Runtime.InteropServices.RuntimeInformation]::RuntimeIdentifier
foreach ($candidate in @("$(Split-Path $ToolsDirectory)\net10.0\$rid\Win32MetadataScraper.dll",
        "$ToolsDirectory\$rid\Win32MetadataScraper.dll")) {
    if (Test-Path -LiteralPath $candidate) {
        throw "The normal task would prefer a different scraper layout: $candidate. Use a genuinely isolated tools root."
    }
}
$preparedAnnotationHeader = "$IncludeRoot\shared\win32metadata_annotations.h"
if ((Get-FileHash -LiteralPath $AnnotationHeader).Hash -ne
    (Get-FileHash -LiteralPath $preparedAnnotationHeader).Hash) {
    throw 'The prepared SDK annotation header differs from the explicitly selected standalone header. Prepare the selected input; the driver never replaces prepared files.'
}
foreach ($owner in $Partition) {
    if ($owner -cnotmatch '^[A-Za-z0-9_.]+$' -or
        !(Test-Path -LiteralPath "$ProjectDirectory\Partitions\$owner\main.cpp" -PathType Leaf) -or
        !(Test-Path -LiteralPath "$ProjectDirectory\Partitions\$owner\settings.rsp" -PathType Leaf)) {
        throw "An ordinary owner partition is invalid or missing: $owner"
    }
}
$commonPartitions = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
$schedulingProject = "$ProjectDirectory\Windows.Win32.proj"
if ($UseNormalBuildScheduling) {
    if (!(Test-Path -LiteralPath $schedulingProject -PathType Leaf)) {
        throw "Normal build scheduling requires the selected SDK project: $schedulingProject"
    }
    [xml]$project = [IO.File]::ReadAllText($schedulingProject)
    $settings = @($project.SelectNodes('/Project/PropertyGroup/ExcludeFromCrossarch'))
    if ($settings.Count -ne 1 -or $settings[0].HasAttribute('Condition') -or
        $settings[0].ParentNode.HasAttribute('Condition')) {
        throw 'Normal build scheduling requires one unconditional literal ExcludeFromCrossarch setting.'
    }
    foreach ($name in $settings[0].InnerText.Split(';', [StringSplitOptions]::RemoveEmptyEntries)) {
        if ($name -cnotmatch '^[A-Za-z0-9_.]+$') {
            throw "Normal build scheduling requires literal partition names in ExcludeFromCrossarch: $name"
        }
        [void]$commonPartitions.Add($name)
    }
}
$architectures = if ($Architecture -eq 'crossarch') { @('x86', 'x64', 'arm64') } else { @($Architecture) }
$profiles = @(foreach ($arch in $architectures) {
    foreach ($owner in $Partition) {
        $directory = $arch
        if ($commonPartitions.Contains($owner)) {
            if ($arch -ne 'x86') { continue }
            $directory = 'common'
        }
        [ordered]@{
            partition = $owner; architecture = $arch; directory = $directory
            responseFile = "$OutputDirectory\obj\scratch\$directory\$owner.settings.rsp"
        }
    }
})
if (!$profiles.Count) {
    throw "No selected partitions are scheduled for $Architecture. Common partitions are generated by the x86 scan."
}
$NativeIncludeDirectory = @(Get-PreparedSdkHeaderIncludes $IncludeRoot $NativeIncludeDirectory)
$driver = "$PSScriptRoot\PreparedSdkPartitions.proj"
if (!(Test-Path -LiteralPath $driver) -or !(Test-Path -LiteralPath $SdkTargetsFile)) {
    throw 'The pinned adapter project and existing GeneratorSdk targets are both required.'
}
$target = @{ Headers = 'ScrapeHeaders'; Constants = 'ScrapeConstants'; Emit = 'EmitWinmd' }[$Stage]
$arguments = @('msbuild', $driver, '-nologo', '-m:1', '-verbosity:minimal', "-target:$target",
    "-property:SdkProjectDirectory=$ProjectDirectory", "-property:PreparedIncludeRoot=$IncludeRoot",
    "-property:ExternalToolsDirectory=$ToolsDirectory", "-property:ExternalAssetsDirectory=$AssetsDirectory",
    "-property:ExternalOutputDirectory=$OutputDirectory", "-property:ExternalSdkTargetsFile=$SdkTargetsFile",
    "-property:ExternalScriptsDirectory=$ScriptsDirectory",
    "-property:PartitionFilter=$($Partition -join '%3B')",
    "-property:NativeIncludeDirectories=$($NativeIncludeDirectory -join '%3B')",
    "-property:ScanArch=$Architecture", "-property:MaxProcessors=$MaxProcessors")
if ($UseNormalBuildScheduling) {
    $arguments += "-property:ExcludeFromCrossarch=$($commonPartitions -join '%3B')"
}
[IO.Directory]::CreateDirectory($OutputDirectory) | Out-Null
$pin = {
    param([string]$Path)
    [ordered]@{ path = $Path; sha256 = (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash }
}
$inputs = @(& $pin $PSCommandPath; & $pin "$PSScriptRoot\PreparedSdkHeaderIncludes.ps1";
    & $pin $driver; & $pin $SdkTargetsFile; & $pin $RuntimeManifest;
    & $pin $AnnotationHeader; & $pin $preparedAnnotationHeader)
if ($UseNormalBuildScheduling) { $inputs += & $pin $schedulingProject }
$inputs += @(Get-ChildItem -LiteralPath $ProjectDirectory -File | Where-Object Extension -In '.rsp', '.json', '.txt' |
    ForEach-Object { & $pin $_.FullName })
$inputs += @(foreach ($owner in $Partition) {
    & $pin "$ProjectDirectory\Partitions\$owner\main.cpp"
    if (Test-Path -LiteralPath "$ProjectDirectory\Partitions\$owner\settings.rsp") {
        & $pin "$ProjectDirectory\Partitions\$owner\settings.rsp"
    }
})
$inputs += @(Get-ChildItem -LiteralPath "$AssetsDirectory\scraper" -File |
    Where-Object { $_.Extension -in '.rsp', '.txt' } | ForEach-Object { & $pin $_.FullName })
$inputPath = "$OutputDirectory\ordinary-inputs.json"
[ordered]@{
    stage = $Stage; architecture = $Architecture; partitions = $Partition
    project = $ProjectDirectory; includeRoot = $IncludeRoot; tools = $ToolsDirectory
    annotationHeader = $AnnotationHeader; runtimeManifest = $RuntimeManifest
    runtimeManifestSha256 = $RuntimeManifestSha256; runtimeFiles = $runtimeFiles
    preparedAndNativeIncludeDirectories = $NativeIncludeDirectory
    usesNormalBuildScheduling = [bool]$UseNormalBuildScheduling
    headerProfiles = $profiles
    arguments = $arguments; inputs = $inputs
    generatesNativeEnumCarriersFromLegacyJson = $false
    reusesColdGeneratedSourcesOrAmbientTools = $false
    apiAcceptance = $false
} | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $inputPath -Encoding utf8NoBOM
$started = [DateTime]::UtcNow.ToString('o')
& dotnet @arguments *> "$OutputDirectory\ordinary.log"
$exit = $LASTEXITCODE
$objectDirectory = "$OutputDirectory\obj"
$expectedResponses = @($profiles | ForEach-Object { $_.responseFile })
$responses = if ($exit -eq 0) { $expectedResponses } else {
    @($expectedResponses | Where-Object { Test-Path -LiteralPath $_ -PathType Leaf })
}
$includeValidation = @()
$includeValidationError = $null
try {
    $includeValidation = @(Assert-PreparedSdkHeaderIncludes -IncludeRoot $IncludeRoot `
        -ProjectDirectory $ProjectDirectory -ResponseFile $responses -NativeIncludeDirectory $NativeIncludeDirectory)
} catch {
    $includeValidationError = $_.Exception.Message
}
$outputFiles = if (Test-Path -LiteralPath $objectDirectory -PathType Container) {
    @(Get-ChildItem -LiteralPath $objectDirectory -Recurse -File |
        ForEach-Object { [ordered]@{ path = [IO.Path]::GetRelativePath($OutputDirectory, $_.FullName); sha256 = (Get-FileHash -LiteralPath $_.FullName).Hash } })
} else { @() }
[ordered]@{
    startedUtc = $started; completedUtc = [DateTime]::UtcNow.ToString('o')
    exitCode = $exit; stage = $Stage; apiAcceptance = $false
    usesNormalBuildScheduling = [bool]$UseNormalBuildScheduling
    headerProfiles = $profiles
    inputSha256 = (Get-FileHash -LiteralPath $inputPath).Hash
    logSha256 = (Get-FileHash -LiteralPath "$OutputDirectory\ordinary.log").Hash
    objectDirectoryCreated = Test-Path -LiteralPath $objectDirectory -PathType Container
    preparedHeaderIncludeValidation = [ordered]@{
        expectedResponses = $expectedResponses.Count
        verifiedResponses = $includeValidation.Count
        complete = !$includeValidationError -and $includeValidation.Count -eq $expectedResponses.Count
        error = $includeValidationError
        responseFiles = $includeValidation
    }
    files = @($outputFiles)
} | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath "$OutputDirectory\ordinary-result.json" -Encoding utf8NoBOM
if ($includeValidationError) {
    throw "Prepared SDK include validation failed after ordinary $Stage exit ${exit}: $includeValidationError. Retain all diagnostics in $OutputDirectory."
}
if ($exit -ne 0) {
    throw "The actual ordinary $Stage stage failed; retain $OutputDirectory\ordinary.log and all partial outputs."
}
[pscustomobject]@{
    Result = "$OutputDirectory\ordinary-result.json"
    GeneratedDirectory = "$OutputDirectory\obj\generated"
    ScratchDirectory = "$OutputDirectory\obj\scratch"
    Stage = $Stage
    ApiAccepted = $false
}
