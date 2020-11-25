
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $libName
)

. "$PSScriptRoot\CommonUtils.ps1"

ls "$sdkApiPath\nf-*" -r | sls "req.lib: $libName" | select -u -exp Path | Get-ChildItem | sls -pattern "req.header:" | %{$_.line.split(' ')[1]} | Sort-Object -Unique
