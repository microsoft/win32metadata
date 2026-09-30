param(
    [switch]$UpdateGolden
)

$ErrorActionPreference = "Stop"
$root = Resolve-Path (Join-Path $PSScriptRoot "..")
$sample = Join-Path $root "tests\GeneratorSdkPackageTests\sample"
$expected = Join-Path $root "tests\GeneratorSdkPackageTests\expected\SampleWinmd.apidump.cs"
$actual = Join-Path $root "obj\GeneratorSdkPackageTests\SampleWinmd.apidump.cs"
$packages = Join-Path $root "obj\GeneratorSdkPackageTests\packages"

dotnet pack (Join-Path $root "sources\GeneratorSdk\nuget\BuildSdk.proj") -c Release
if ($LASTEXITCODE -ne 0) {
    throw "Failed to pack Microsoft.Windows.WinmdGenerator."
}

$nupkg = Get-ChildItem (Join-Path $root "bin\Packages\Release\NuGet\Microsoft.Windows.WinmdGenerator.*.nupkg") |
    Sort-Object LastWriteTimeUtc -Descending |
    Select-Object -First 1
if (!$nupkg) {
    throw "The Microsoft.Windows.WinmdGenerator package was not produced."
}

$version = $nupkg.BaseName.Substring("Microsoft.Windows.WinmdGenerator.".Length)
$globalJson = @{
    "msbuild-sdks" = @{
        "Microsoft.Windows.WinmdGenerator" = $version
    }
} | ConvertTo-Json -Depth 4
[System.IO.File]::WriteAllText((Join-Path $sample "global.json"), $globalJson)

if (Test-Path $packages) {
    Remove-Item $packages -Recurse -Force
}
$env:NUGET_PACKAGES = $packages

dotnet build (Join-Path $sample "SampleWinmd.proj") -c Release "-p:RestoreConfigFile=$(Join-Path $sample 'NuGet.config')"
if ($LASTEXITCODE -ne 0) {
    throw "The consuming WinmdGenerator project failed."
}

foreach ($header in @("win32metadata_annotations.h", "win32metadata_sal.h")) {
    $packagedHeader = Join-Path $packages "microsoft.windows.winmdgenerator\$version\tools\assets\WinSDK\inc\$header"
    $sourceHeader = Join-Path $root "generation\WinSDK\AdditionalHeaders\$header"
    if (!(Test-Path $packagedHeader)) {
        throw "The package did not contain $header."
    }
    if ((Get-FileHash $packagedHeader).Hash -cne (Get-FileHash $sourceHeader).Hash) {
        throw "The packaged $header differs from the repository source."
    }
}

dotnet build (Join-Path $root "sources\WinmdUtils\WinmdUtils.csproj") -c Release
if ($LASTEXITCODE -ne 0) {
    throw "Failed to build WinmdUtils."
}

New-Item -ItemType Directory -Force -Path (Split-Path $actual) | Out-Null
$winmd = Join-Path $sample "bin\SampleWinmd.winmd"
$assembly = [System.Reflection.AssemblyName]::GetAssemblyName($winmd)
if ($assembly.Name -ne "Sample.Metadata" -or $assembly.Version.ToString() -ne "1.2.3.4") {
    throw "Generated assembly identity was '$($assembly.Name), $($assembly.Version)'."
}

$winmdUtils = Join-Path $root "bin\Release\net10.0\WinmdUtils.dll"
dotnet $winmdUtils dump --winmd $winmd --output $actual
if ($LASTEXITCODE -ne 0) {
    throw "Failed to dump the generated WinMD."
}

$actualText = [System.IO.File]::ReadAllText($actual).Replace("`r`n", "`n")
$actualText = [System.Text.RegularExpressions.Regex]::Replace(
    $actualText,
    "(?s)\n// [^\r\n]+\n// Namespace: Windows\.Win32\.Foundation\.Metadata.*$",
    ""
)
[System.IO.File]::WriteAllText($actual, $actualText)

function Assert-InvalidAnnotation {
    param(
        [string]$Name,
        [string]$ExpectedError
    )

    $invalidRoot = Join-Path $sample "invalid"
    $partition = Join-Path $invalidRoot "$Name.cpp"
    $work = Join-Path $root "obj\GeneratorSdkPackageTests\invalid\$Name"
    $output = Join-Path $work "$Name.winmd"
    New-Item -ItemType Directory -Force -Path $work | Out-Null

    $messages = @(& (Join-Path $packages "microsoft.windows.winmdgenerator\$version\tools\win-x64\win32metadata-tools.exe") scrape `
        --partition $partition `
        --include $invalidRoot `
        --include (Join-Path $packages "microsoft.windows.winmdgenerator\$version\tools\assets\WinSDK\inc") `
        --arch x64 `
        --scope-header $Name `
        --namespace "Sample.Invalid" `
        --obj $work `
        --output $output 2>&1 | ForEach-Object { $_.ToString() })
    if ($LASTEXITCODE -eq 0) {
        throw "Invalid annotation case '$Name' unexpectedly generated a WinMD."
    }
    $messageText = $messages -join "`n"
    if ($messageText -match "(?i)failed to find \.rdl files") {
        throw "Invalid annotation case '$Name' failed before validating its annotation."
    }
    if ($messageText -notmatch $ExpectedError) {
        throw "Invalid annotation case '$Name' did not report the expected annotation error:`n$messageText"
    }
}

$packageToolDirectory = Join-Path $packages "microsoft.windows.winmdgenerator\$version\tools\win-x64"
$previousLibClangPath = $env:LIBCLANG_PATH
try {
    $env:LIBCLANG_PATH = $packageToolDirectory
    Assert-InvalidAnnotation "UnknownAnnotation" "(?i)(unknown_contract|unknown annotation)"
    Assert-InvalidAnnotation "MissingAnnotationValue" "(?i)(import_library|missing|required).*(value|argument)"
    Assert-InvalidAnnotation "EmptyAnnotationValue" "(?i)(import_library|empty|required).*(value|argument)"
    Assert-InvalidAnnotation "UnexpectedAnnotationValue" "(?i)(set_last_error|unexpected|accept).*(value|argument)"
    Assert-InvalidAnnotation "InvalidAnnotationTarget" "(?i)(associated_constant|invalid target|enum)"
    Assert-InvalidAnnotation "MisplacedAnnotation" "(?i)(retained|not valid|invalid target)"
    Assert-InvalidAnnotation "UnresolvedAnnotation" "(?i)(invalid-handle|sentinel|MISSING_INVALID_HANDLE)"
    Assert-InvalidAnnotation "ConflictingAnnotation" "(?i)(conflicting|raii_free)"
}
finally {
    $env:LIBCLANG_PATH = $previousLibClangPath
}

function Assert-MatchCount {
    param(
        [string]$Pattern,
        [int]$Expected,
        [string]$Description
    )

    $count = [System.Text.RegularExpressions.Regex]::Matches($actualText, $Pattern).Count
    if ($count -ne $Expected) {
        throw "$Description count was $count; expected $Expected."
    }
}

Assert-MatchCount 'public const uint SAMPLE_MODE_EXTERNAL\b' 1 "Associated constant"
Assert-MatchCount 'public struct SAMPLE_POINT\b' 1 "Duplicate type"
Assert-MatchCount 'public static extern int SampleAdd\b' 1 "Duplicate import"
Assert-MatchCount 'public delegate int PSAMPLE_CALLBACK\b' 1 "Duplicate delegate"

if ($actualText -notmatch "public const uint SAMPLE_MODE_EXTERNAL\s*=\s*3758096385u?;") {
    throw "The source-associated dependency constant was not emitted."
}
if ($actualText -notmatch '\[AssociatedConstant\s*\(\s*"SAMPLE_MODE_EXTERNAL"\s*\)\]\s*public enum SAMPLE_MODE : uint') {
    throw "The source association was not preserved on SAMPLE_MODE."
}
if ($actualText -notmatch '\[SupportedOSPlatform\s*\(\s*"windows10\.0\.19041\.662"\s*\)\][\s\S]*?SampleAdd') {
    throw "The fixed Windows 10 build availability was not emitted on SampleAdd."
}
if ($actualText -notmatch '\[DllImport\s*\(\s*"sampleapi\.dll"[\s\S]*?SetLastError\s*=\s*true[\s\S]*?SampleAdd') {
    throw "The import library or SetLastError contract was not emitted on SampleAdd."
}
if ($actualText -notmatch '\[DllImport\s*\(\s*""\s*,\s*CallingConvention\s*=\s*CallingConvention\.Cdecl\s*,\s*ExactSpelling\s*=\s*true\s*\)\]\s*public static extern Exception SamplePreservedResult') {
    throw "HRESULT PreserveResult was not emitted."
}
if ($actualText -notmatch 'public interface ISampleFactory[\s\S]*?Exception Create[\s\S]*?\[PreserveSig\][\s\S]*?Exception TryCreate') {
    throw "HRESULT interface methods were not projected with the PreserveResult distinction."
}
$resourceHandleAttributes = [System.Text.RegularExpressions.Regex]::Match(
    $actualText,
    '(?s)((?:\[[^\r\n]+\]\s*)+)public struct SAMPLE_RESOURCE_HANDLE'
).Groups[1].Value
if ($resourceHandleAttributes -notmatch '\[InvalidHandleValue\s*\(\s*-1L?\s*\)\]' -or
    $resourceHandleAttributes -notmatch '\[InvalidHandleValue\s*\(\s*0L?\s*\)\]' -or
    $resourceHandleAttributes -notmatch '\[RAIIFree\s*\(\s*"SampleCloseHandle"\s*\)\]') {
    throw "The typedef RAII and invalid-handle contract was not emitted."
}
if ($actualText -notmatch '\[AlsoUsableFor\s*\(\s*"SAMPLE_HANDLE"\s*\)\][\s\S]*?SAMPLE_COMPAT_HANDLE') {
    throw "The AlsoUsableFor contract was not emitted."
}
if ($actualText -notmatch '\[return:\s*AssociatedEnum\s*\(\s*"SAMPLE_MODE"\s*\)\][\s\S]*?SampleGetMode') {
    throw "The return AssociatedEnum contract was not emitted."
}
if ($actualText -notmatch 'SampleGetMode\s*\(\s*\[In\]\s*\[AssociatedEnum\s*\(\s*"SAMPLE_MODE"\s*\)\]') {
    throw "The parameter AssociatedEnum contract was not emitted."
}
$openHandleAttributes = [System.Text.RegularExpressions.Regex]::Match(
    $actualText,
    '(?s)(\[DllImport[^\r\n]+\]\s*(?:\[return:[^\r\n]+\]\s*)*)public static extern SAMPLE_HANDLE SampleOpenHandle'
).Groups[1].Value
if ($openHandleAttributes -notmatch '\[return:\s*InvalidHandleValue\s*\(\s*-1L?\s*\)\]' -or
    $openHandleAttributes -notmatch '\[return:\s*InvalidHandleValue\s*\(\s*0L?\s*\)\]' -or
    $openHandleAttributes -notmatch '\[return:\s*RAIIFree\s*\(\s*"SampleCloseHandle"\s*\)\]') {
    throw "The return RAII contract was not emitted."
}
if ($actualText -notmatch 'SampleCreateHandle\s*\(\s*\[Out\]\s*\[RAIIFree\s*\(\s*"SampleCloseHandle"\s*\)\]\s*\[InvalidHandleValue\s*\(\s*-1L?\s*\)\]\s*\[InvalidHandleValue\s*\(\s*0L?\s*\)\]') {
    throw "The output RAII contract was not emitted."
}
if ($actualText -notmatch 'SampleCreateValue\s*\(\s*\[Out\]\s*\[RetVal\]') {
    throw "The generic retval contract was not emitted."
}
if ($actualText -notmatch 'SampleCreateDirectValue\s*\(\s*\[Out\]\s*\[RetVal\]') {
    throw "The direct Win32 retval contract was not emitted."
}
if ($actualText -notmatch 'SampleUseHandle\s*\(\s*\[In\]\s*\[Retained\]') {
    throw "The Retained contract was not emitted."
}
if ($actualText -notmatch 'ISampleFactory[\s\S]*?Create\s*\(\s*\[Out\]\s*\[RetVal\]\s*\[ComOutPtr\]') {
    throw "The COM retval contract was not emitted."
}
if ($actualText -notmatch 'SampleBuffers[\s\S]*?NativeArrayInfo[\s\S]*?MemorySize[\s\S]*?NotNullTerminated[\s\S]*?NullNullTerminated') {
    throw "The buffer and termination contracts were not emitted."
}
if ($actualText -notmatch 'SampleOutputBuffers[\s\S]*?NativeArrayInfo[\s\S]*?MemorySize') {
    throw "The output-pointer buffer contracts were not emitted."
}
if ($actualText -notmatch 'SampleLegacyBuffers[\s\S]*?MemorySize[\s\S]*?NativeArrayInfo') {
    throw "Legacy buffer-size and terminated-string contracts were not emitted."
}
if ($actualText -notmatch '\[DllImport\s*\(\s*"samplemerged\.dll"[\s\S]*?SetLastError\s*=\s*true[\s\S]*?\[SupportedOSPlatform\s*\(\s*"windows6\.1"\s*\)\][\s\S]*?SampleMergedContract') {
    throw "Compatible redeclarations did not merge import, SetLastError, and availability metadata."
}
if ($actualText -notmatch '\[SupportedArchitecture\s*\(\s*1\s*\)\][\s\S]*?struct SAMPLE_ARCH_VALUE[\s\S]*?public int value;' -or
    $actualText -notmatch '\[SupportedArchitecture\s*\(\s*6\s*\)\][\s\S]*?struct SAMPLE_ARCH_VALUE[\s\S]*?public long value;') {
    throw "Architecture-varying type declarations were not preserved."
}
if ($actualText -notmatch '\[SupportedArchitecture\s*\(\s*1\s*\)\][\s\S]*?SampleX86Only' -or
    $actualText -notmatch '\[SupportedArchitecture\s*\(\s*6\s*\)\][\s\S]*?SampleWideOnly') {
    throw "Architecture-varying function declarations were not preserved."
}
if ($actualText -notmatch 'struct SAMPLE_ARRAYS[\s\S]*?public byte\[\] bytes;[\s\S]*?public int\[\] values;') {
    throw "Const array fields were not preserved."
}
if ($actualText -notmatch 'delegate int PSAMPLE_CALLBACK[\s\S]*?struct SAMPLE_CALLBACKS[\s\S]*?public PSAMPLE_CALLBACK chained;[\s\S]*?PSAMPLE_CALLBACK\* pointer;' -or
    $actualText -match 'struct SAMPLE_CALLBACKS[\s\S]*?byte\* anonymous;') {
    throw "Chained, pointer, or anonymous callback fields were not preserved."
}
if ($actualText -notmatch '\[Alignment\s*\(\s*8\s*\)\]\s*public struct SAMPLE_PACKED') {
    throw "Explicit alignment was not preserved."
}

Add-Type -AssemblyName System.Reflection.Metadata
$winmdStream = [System.IO.File]::OpenRead($winmd)
try {
    $peReader = [System.Reflection.PortableExecutable.PEReader]::new($winmdStream)
    $metadataReader = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($peReader)
    $packedLayout = $null
    foreach ($typeHandle in $metadataReader.TypeDefinitions) {
        $type = $metadataReader.GetTypeDefinition($typeHandle)
        if ($metadataReader.GetString($type.Name) -eq "SAMPLE_PACKED") {
            $packedLayout = $type.GetLayout()
            break
        }
    }
    if ($null -eq $packedLayout -or $packedLayout.IsDefault -or $packedLayout.PackingSize -ne 2) {
        throw "Packing size 2 was not preserved on SAMPLE_PACKED."
    }
}
finally {
    if ($peReader) {
        $peReader.Dispose()
    }
    $winmdStream.Dispose()
}

$supportedOs = [ordered]@{
    SampleWindows2000 = "windows5.0"
    SampleWindowsXP = "windows5.1.2600"
    SampleWindowsVista = "windows6.0.6000"
    SampleWindowsVistaSP1 = "windows6.0.6001"
    SampleWindows7 = "windows6.1"
    SampleWindows8 = "windows8.0"
    SampleWindows81 = "windows8.1"
    SampleWindows10_10240 = "windows10.0.10240"
    SampleWindows10_10586 = "windows10.0.10586"
    SampleWindows10_14393 = "windows10.0.14393"
    SampleWindows10_15063 = "windows10.0.15063"
    SampleWindows10_16299 = "windows10.0.16299"
    SampleWindows10_17134 = "windows10.0.17134"
    SampleWindows10_17763 = "windows10.0.17763"
    SampleWindows10_18362 = "windows10.0.18362"
    SampleWindows10_19041 = "windows10.0.19041"
    SampleWindows10_19041_662 = "windows10.0.19041.662"
    SampleWindows10_20348 = "windows10.0.20348"
    SampleWindows10_22631 = "windows10.0.22631"
    SampleWindows10_26100 = "windows10.0.26100"
    SampleServer2000 = "windowsserver2000"
    SampleServer2003 = "windowsserver2003"
    SampleServer2008 = "windowsserver2008"
    SampleServer2012 = "windowsserver2012"
    SampleServer2016 = "windowsserver2016"
}
foreach ($entry in $supportedOs.GetEnumerator()) {
    $pattern = '\[SupportedOSPlatform\s*\(\s*"' + [regex]::Escape($entry.Value) + '"\s*\)\][\s\S]*?' + [regex]::Escape($entry.Key)
    if ($actualText -notmatch $pattern) {
        throw "SupportedOS '$($entry.Value)' was not emitted on $($entry.Key)."
    }
}

if ($actualText -match "SAMPLE_MODE_EXTERNAL_VALUE|DEPENDENCY_NOISE|DependencyShouldNotEmit|CLEANUP_DEPENDENCY_NOISE|CleanupDependencyShouldNotEmit|static extern int SampleCloseHandle") {
    throw "Unrelated dependency declarations were emitted."
}

if ($UpdateGolden) {
    New-Item -ItemType Directory -Force -Path (Split-Path $expected) | Out-Null
    [System.IO.File]::WriteAllText($expected, $actualText, [System.Text.UTF8Encoding]::new($true))
    Write-Host "Updated $expected"
    exit 0
}

if (!(Test-Path $expected)) {
    throw "Golden file is missing. Run with -UpdateGolden after reviewing the generated dump."
}
$expectedText = [System.IO.File]::ReadAllText($expected).Replace("`r`n", "`n")
if ($expectedText -cne $actualText) {
    git --no-pager diff --no-index -- $expected $actual
    throw "Generated WinMD API dump does not match the golden file."
}

Write-Host "WinmdGenerator package integration test passed."
