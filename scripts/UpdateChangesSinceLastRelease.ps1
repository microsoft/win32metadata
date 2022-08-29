param
(
    [string]
    $ReasonForAddedDifferences
)

. "$PSScriptRoot\CommonUtils.ps1"

& "$PSScriptRoot\CompareBinToLastRelease.ps1" -SkipInstallTools -UpdateDifferencesWithComment $ReasonForAddedDifferences
