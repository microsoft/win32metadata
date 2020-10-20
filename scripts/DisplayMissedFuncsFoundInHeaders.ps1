
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $includePath,

    [Parameter(Mandatory=$true)]
    [string]
    $missedFuncsFile
)

foreach ($func in Get-Content -path $missedFuncsFile)
{
    if ($sb.Length -ne 0)
    {
        [void]$sb.Append("|")
    }

    $func = $func.Replace("?", "\?");

    Write-Output "Looking for $func..."
    Get-ChildItem -Path "$includePath\*" -Recurse | Select-String -Pattern "$func\("
}

