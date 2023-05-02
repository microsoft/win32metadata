. "$PSScriptRoot\CommonUtils.ps1"

$documentationMappingsRsp = Join-Path $windowsWin32ProjectRoot "documentationMappings.rsp"

Write-Host "Writing to $documentationMappingsRsp..."

$output = [System.Text.StringBuilder]::new()
$output.AppendLine("--memberRemap") | Out-Null

Get-ChildItem $sdkApiPath -Include "*.md" -Exclude "index.md", "TOC.md" -Recurse |
ForEach-Object {
    $match = [regex]::Match($_.Name, "(n.-([^-]+)-([^-]*)(-[^-]*)?).md")
    if ($match.Success) {
        $page = $match.Groups[1].Value
        $header = $match.Groups[2].Value
    
        $match = [regex]::Match((Get-Content $_ -TotalCount 5), "title: ([^\s\(]+)")
        $api = $match.Groups[1].Value

        $output.AppendLine("$api=[Documentation(""https://docs.microsoft.com/windows/win32/api/$header/$page"")]") | Out-Null
    }
}

[System.IO.File]::WriteAllLines($documentationMappingsRsp, $output.ToString())