param
(
    [Parameter(Mandatory=$true)]
    [string]
    $apiCsvFileName
)

if (!(Test-Path -path $apiCsvFileName))
{
    Write-Error "Couldn't find csv file $apiCsvFileName."
    exit -1
}

. "$PSScriptRoot\CommonUtils.ps1"
$baseRemapRsp = "$PSScriptRoot\..\generation\baseRemap.rsp"
$exitingRemaps = Import-Csv $baseRemapRsp -Delimiter '=' -Header @('From', 'To')
[hashtable]$existingRemaps = @{}
foreach ($item in $exitingRemaps)
{
    if ($null -eq $item.To)
    {
        continue
    }

    $existingRemaps[$item.From] = $item.To
}

$sb = [System.Text.StringBuilder]::new()

$apiData = Import-Csv $apiCsvFileName -Delimiter ','
foreach ($item in $apiData)
{
    [string]$name = $item.Name
    [string]$title = $item.Title

    if (![string]::IsNullOrEmpty($name) -and ($name -ne $title) -and !$name.StartsWith("__unnamed") -and !$existingRemaps.Contains($name))
    {
        [void]$sb.AppendLine("$name=$title")
    }
}

Add-Content -Path $baseRemapRsp -Value $sb.ToString()
