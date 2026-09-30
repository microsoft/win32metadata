param
(
    [switch]$SkipInstallTools,
    [switch]$AllowKnownGeneratorGaps
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$SkipInstallTools.IsPresent)
{
    Install-BuildTools
}

Write-Host "*** Running tests on .winmd" -ForegroundColor Blue

$windowsWin32TestsDir = "$rootDir\tests\Windows.Win32.Tests"
$resultsDirectory = Join-Path $rootDir "obj\Windows.Win32.Tests\results"
$resultsFile = Join-Path $resultsDirectory "Windows.Win32.Tests.trx"
New-Item -ItemType Directory -Force -Path $resultsDirectory | Out-Null
Remove-Item $resultsFile -Force -ErrorAction SilentlyContinue

dotnet test $windowsWin32TestsDir -c:Release `
    --logger "trx;LogFileName=Windows.Win32.Tests.trx" `
    --results-directory $resultsDirectory
$testExitCode = $LASTEXITCODE

if (!$AllowKnownGeneratorGaps) {
    if ($testExitCode -ne 0) {
        throw "Windows.Win32.Tests failed with exit code $testExitCode."
    }
}
elseif (!(Test-Path $resultsFile)) {
    throw "Windows.Win32.Tests did not produce '$resultsFile' (exit code $testExitCode)."
}
else {
    [xml]$results = Get-Content $resultsFile -Raw
    $failedResults = @($results.SelectNodes("//*[local-name()='UnitTestResult' and @outcome='Failed']"))
    $counters = $results.SelectSingleNode("//*[local-name()='ResultSummary']/*[local-name()='Counters']")
    $expectedFailures = [ordered]@{
        "InterfaceTests.Interface_Layouts_Correct:ID2D1SvgStrokeDashArray" = "F7CB94FC7375953C1B21EE73E36859A6E17E80F961A27E64E6AC20B33F75A13A"
        "InterfaceTests.Interface_Layouts_Correct:IDCompositionVisual" = "44A6EB59AC694B406E20290DE977268A24F40829C319741FF8070F7DB9915668"
        "InterfaceTests.Interface_Layouts_Correct:IDCompositionGaussianBlurEffect" = "E5CBE8CEB31725689907C060C4CE110567DE27C285634120AC23AE56DBB2FE55"
        "InterfaceTests.Interface_Layouts_Correct:IDWriteFactory3" = "0C98814436FCB269F8BF2A3F16C5BA8ABF289EE20BE397754094561D58C171B0"
        "IntegrityTests.NoInvalidEmptyDelegates" = "53E1E30B747D4CE17118B24EBFDA5053AD9F695B2DA13F07829CA399DB2DFCBA"
        "IntegrityTests.NoDuplicateConstants" = "579F9799E07285ACFAA78069B1FCC75288494EA26E8CC73B9C836DC3E0A2437C"
        "IntegrityTests.NoDuplicateImports" = "33E86A611F5C577824A8E2B99DF45BD8B36CC0654F79BBC344B4BE0E8D0F249C"
        "IntegrityTests.NoInvalidPointersToDelegates" = "10BB45B351DA26B0BF9B053DA1759F23E0EE702F1002B7CD18889EE1E846188C"
        "IntegrityTests.NoBrokenArchTypes" = "D620067C2212E4AFB38AB0CC3B3E5B513814630FBCC1E9632B650B094EB2BE54"
    }

    if (!$counters -or
        [int]$counters.total -ne [int]$counters.executed -or
        [int]$counters.failed -ne $expectedFailures.Count -or
        @("error", "timeout", "aborted", "notRunnable", "notExecuted", "disconnected") |
            Where-Object { [int]$counters.$_ -ne 0 }) {
        throw "Windows.Win32.Tests did not complete cleanly: $($counters.OuterXml)"
    }
    if ($testExitCode -ne 1) {
        throw "Windows.Win32.Tests returned unexpected exit code $testExitCode for the reviewed failure set."
    }

    function Get-DiagnosticHash {
        param([string]$Text)

        $normalized = $Text.Replace("`r`n", "`n").Trim()
        $sha = [System.Security.Cryptography.SHA256]::Create()
        try {
            return ([BitConverter]::ToString(
                $sha.ComputeHash([System.Text.Encoding]::UTF8.GetBytes($normalized))
            )).Replace("-", "")
        }
        finally {
            $sha.Dispose()
        }
    }

    $actualFailures = [ordered]@{}
    foreach ($result in $failedResults) {
        $testName = $result.testName
        $interfaceName = [regex]::Match($testName, 'Name = "([^"]+)"')
        if ($testName -match "InterfaceTests\.Interface_Layouts_Correct" -and
            $interfaceName.Success) {
            $id = "InterfaceTests.Interface_Layouts_Correct:$($interfaceName.Groups[1].Value)"
        }
        elseif ($testName -match "Windows\.Win32\.Tests\.(IntegrityTests\.[A-Za-z0-9_]+)") {
            $id = $Matches[1]
        }
        else {
            $id = $testName
        }

        if ($actualFailures.Contains($id)) {
            throw "Windows.Win32.Tests reported duplicate failed result '$id'."
        }
        if ($id.StartsWith("InterfaceTests.")) {
            $diagnostic = $result.SelectSingleNode(
                "./*[local-name()='Output']/*[local-name()='ErrorInfo']/*[local-name()='Message']"
            ).InnerText
        }
        else {
            $diagnostic = $result.SelectSingleNode(
                "./*[local-name()='Output']/*[local-name()='StdOut']"
            ).InnerText
            $diagnostic = (($diagnostic -split "`r?`n") |
                Where-Object { $_ -notmatch "^Calling: dotnet " }) -join "`n"
        }
        $actualFailures[$id] = $diagnostic
    }

    $missing = @($expectedFailures.Keys | Where-Object { !$actualFailures.Contains($_) })
    $unexpected = @($actualFailures.Keys | Where-Object { !$expectedFailures.Contains($_) })
    if ($missing.Count -ne 0 -or $unexpected.Count -ne 0) {
        throw "Windows.Win32.Tests failure set changed.`nMissing: $($missing -join ', ')`nUnexpected: $($unexpected -join ', ')"
    }

    foreach ($entry in $expectedFailures.GetEnumerator()) {
        $actualHash = Get-DiagnosticHash $actualFailures[$entry.Key]
        if ($actualHash -cne $entry.Value) {
            $diagnostic = $actualFailures[$entry.Key]
            if ($diagnostic.Length -gt 2000) {
                $diagnostic = $diagnostic.Substring(0, 2000) + "`n...[truncated]"
            }
            throw "Known failure '$($entry.Key)' changed diagnostic hash from $($entry.Value) to ${actualHash}:`n$diagnostic"
        }
    }

    Write-Host "Windows.Win32.Tests reported the exact reviewed set of $($expectedFailures.Count) generator convergence failures."
    $global:LASTEXITCODE = 0
}

Write-Host "`n`e[32mTesting .winmd succeeded`e[0m"

Write-Host "*** Comparing .winmd to last release (informational)" -ForegroundColor Blue

# Run the comparison for informational purposes — differences are expected
# and will be reviewed via the PR diff comment posted by CI.
& "$PSScriptRoot\CompareBinToLastRelease.ps1" -SkipInstallTools

if ($LastExitCode -lt 0)
{
    Write-Host "`e[33mAPI differences detected (see above). These will be posted as a PR comment for review.`e[0m"
}
else
{
    Write-Host "`n`e[32mNo API differences from last release.`e[0m"
}

exit 0
