. "$PSScriptRoot\CommonUtils.ps1"

$documentationMappingsRsp = Join-Path $windowsWin32ProjectRoot "documentationMappings.rsp"

Write-Host "Writing to $documentationMappingsRsp..."

$output = [System.Text.StringBuilder]::new()
$output.AppendLine("--memberRemap") | Out-Null

$paths = @(
    (Join-Path $MicrosoftDocsSdkApiPath "sdk-api-src\content")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\AD")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\ADSI")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\Bits")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\Controls")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\dataxchg")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\DevIO")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\DevNotes")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\dlgbox")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\dwm")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\extensible-storage-engine")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\gdi")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\hidpi")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\inputdev")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\inputmsg")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\Intl")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\menurc")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\Multimedia")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\OpenGL")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\Power")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\printdocs")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\RRAS")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecAuthN")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecAuthZ")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecBioMet")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecCertEnroll")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecCNG")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecCNG")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecCrypto")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SecMgmt")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\shell")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\Shutdown")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\SysInfo")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\tablet")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\Tapi")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\TermServ")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\TSF")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\wia")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\wic")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\WinAuto")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\winmsg")
    (Join-Path $MicrosoftDocsWin32Path "desktop-src\wintouch")
)

Get-ChildItem $paths -Include "*.md" -Exclude "index.md", "TOC.md" -Recurse |
ForEach-Object {
    $content = Get-Content $_ -TotalCount 20

    if ($_.FullName.StartsWith($MicrosoftDocsSdkApiPath)) {
        $api = [regex]::Match($content, "title: ([^\s\(]+)").Groups[1].Value -replace "\.", "::"

        $output.AppendLine("$api=[Documentation(""https://docs.microsoft.com/windows/win32/api/$($_.Directory.Name)/$($_.BaseName)"")]") | Out-Null
        
    }
    elseif ($_.FullName.StartsWith($MicrosoftDocsWin32Path)) {
        $match = [regex]::Match($content, "ms.topic: ([^\s]+)")
        if ($match.Success -and $match.Groups[1].Value -eq "reference") {
            $baseApi = [regex]::Match($content, "title: ([^\s\(]+)").Groups[1].Value
            $api_names = $content | Select-String "api_name" -Context 0,3

            if ($api_names -ne $null) {
                $match = [regex]::Matches($api_names, "- ($($baseApi -replace "::", "\.")[\w\.:]*)")

                # If api_names includes variants of the base API, create mappings for each.
                # Example: ext/win32/desktop-src/printdocs/addprinter.md
                if ($match.Count -gt 0 -and $match.Groups[1].Value -eq ($baseApi -replace "::", "\.")) {
                    $apis = $match.Groups | Where-Object { $_.Name -eq "1" } | ForEach-Object { $_.Value -replace "\.", "::"}
                    
                    foreach ($api in $apis) {
                        $output.AppendLine("$api=[Documentation(""https://docs.microsoft.com/windows/win32/$($_.Directory.Name)/$($_.BaseName)"")]") | Out-Null
                    }
                }
                # If api_names doesn't include the base API, create a mapping just for the base API.
                # Example: ext/win32/desktop-src/Controls/em-getfileline.md
                else {
                    $api = $baseApi -replace "\.", "::"
    
                    $output.AppendLine("$api=[Documentation(""https://docs.microsoft.com/windows/win32/$($_.Directory.Name)/$($_.BaseName)"")]") | Out-Null
                }
            }
            else {
                $api = $baseApi -replace "\.", "::"

                $output.AppendLine("$api=[Documentation(""https://docs.microsoft.com/windows/win32/$($_.Directory.Name)/$($_.BaseName)"")]") | Out-Null
            }
        }
    }
}

[System.IO.File]::WriteAllLines($documentationMappingsRsp, $output.ToString())