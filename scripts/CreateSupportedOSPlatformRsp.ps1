
. "$PSScriptRoot\CommonUtils.ps1"

$outputFileName = "$scraperDir\supportedOS.rsp"

# https://gaijin.at/en/infos/windows-version-numbers
$versionMap = @{
    "2000" = "windows5.0"
    "XP" = "windows5.1.2600"
    "XP with SP1" = "windows5.1.2600"
    "XP with SP2, Windows Vista" = "windows5.1.2600"
    "XP with SP2" = "windows5.1.2600"
    "7" = "windows6.1"
    "8" = "windows8.0"
    "8.1" = "windows8.1"
    "Vista" = "windows6.0.6000"
    "10" = "windows10.0.10240"
    "10.20H2" = "windows10.0.19042"
    "10.2004" = "windows10.0.19041"
    "10.1909" = "windows10.0.18363"
    "10.1903" = "windows10.0.18362"
    "10.1809" = "windows10.0.17763"
    "10.1803" = "windows10.0.17134"
    "10.1709" = "windows10.0.16299"
    "10.1703" = "windows10.0.15063"
    "10.1607" = "windows10.0.14393"
    "10.1511" = "windows10.0.10586"
    "10.1507" = "windows10.0.10240"
    "Server2000" = "windowsServer2000"
    "Server2008" = "windowsServer2008"
    "Server2003" = "windowsServer2003"
    "Server2012" = "windowsServer2012"
    "Server2016" = "windowsServer2016"
    "Server2019" = "windowsServer2019"
}

$writtenItems = @{}

$windowsVersionPattern = [Regex]::new('^Windows(?:\s|\xA0)(XP with SP1|XP with SP2(?:, Windows(?:\s|\xA0)Vista)?|XP|Vista|7|8.1|8|2000|10)(?:(?:,?\sversion)?\s(\d+)?)?')
$windowsServerVersionPattern = [Regex]::new('^Windows(?:\s|\xA0)Server(?:\s|\xA0)(\d+)|^Windows(?:\s|\xA0)(\d+)(?:\s|\xA0)Server')
$versionPrefixStripPattern = [Regex]::new('^(?:Windows Installer 5\.0 on |Available in Microsoft |Available in starting with |Available in |Available starting with Microsoft |Available starting with |Supported in |Microsoft |This function is available in |starting with )(.+)')
$lastChancePattern = [Regex]::new('(Windows(?:\s|\xA0)7)|(Windows(?:\s|\xA0)2000)|(Windows(?:\s|\xA0)Vista)|(Windows(?:\s|\xA0)8)')

function Remove-Prefix
{
    Param ([string] $text)

    $match = $versionPrefixStripPattern.Match($text)
    if ($match.Success)
    {
        return $match.Groups[1].Value
    }
    else
    {
        return $text
    }
}

try
{
    $stream = [System.IO.StreamWriter] $outputFileName
    $stream.WriteLine("--with-attribute")

    foreach ($funcFile in Get-ChildItem "$sdkApiPath\n*.md" -r)
    {
        $name = ""
        $version = ""
        $serverVersion = ""

        $fileName = [System.IO.Path]::GetFileName($funcFile.FullName)
        if ($fileName -eq "nf-ktmw32-committransaction.md")
        {
            $name = ""
        }

        # Dig out the name, client version info and server version info
        foreach ($matchInfo in ($funcFile | Select-String -pattern '^UID: N[F|N]:(\w+)\.(\S+)|^req.target-min-winverclnt: (.+)|^req.target-min-winversvr: (.+)'))
        {
            foreach ($match in $matchInfo.Matches)
            {
                if ($match.Groups[2].Success)
                {
                    $name = $match.Groups[2].Value
                }
                elseif ($match.Groups[3].Success)
                {
                    $version = $match.Groups[3].Value
                    if ($version -eq "None supported")
                    {
                        $version = ""
                    }
                }
                elseif ($match.Groups[4].Success)
                {
                    $serverVersion = $match.Groups[4].Value
                }
            }
        }

        # If we didn't find either the client version or server version, go to next one
        if ([string]::IsNullOrEmpty($version) -and [string]::IsNullOrEmpty($serverVersion))
        {
            continue
        }

        if (![string]::IsNullOrEmpty($name) -and !$name.Contains("."))
        {
            $fixedVersion = ""
            if (![string]::IsNullOrEmpty($version))
            {
                $version = Remove-Prefix $version
                $match = $windowsVersionPattern.Match($version)
                if ($match.Success)
                {
                    $versionName = $match.Groups[1].Value
                    if ($match.Groups[2].Success)
                    {
                        $versionName += "." + $match.Groups[2]
                    }

                    if ($versionMap.ContainsKey($versionName))
                    {
                        $fixedVersion = $versionMap[$versionName]
                    }
                    else
                    {
                        Write-Error "Failed to lookup windows version: $version"
                    }
                }
                else
                {
                    $lowestIndex = 1000
                    foreach ($match in $lastChancePattern.Matches($version))
                    {
                        foreach ($group in $match.Groups)
                        {
                            if ($group.Success -and $group.Index -lt $lowestIndex)
                            {
                                $lowestIndex = $group.Index
                                $fixedVersion = $group.Value
                            }
                        }
                    }

                    if ([string]::IsNullOrEmpty($fixedVersion))
                    {
                        Write-Host "Warning: regex failed to decode '$version' for $name found in $($funcFile.FullName)"
                    }
                }
            }
            else
            {
                $serverVersion = Remove-Prefix $serverVersion

                $match = $windowsServerVersionPattern.Match($serverVersion)
                if ($match.Success)
                {
                    if ($match.Groups[1].Success)
                    {
                        $versionName = "Server" + $match.Groups[1].Value
                    }
                    elseif ($match.Groups[2].Success)
                    {
                        $versionName = "Server" + $match.Groups[2].Value
                    }

                    if ($versionMap.ContainsKey($versionName))
                    {
                        $fixedVersion = $versionMap[$versionName]
                    }
                    else
                    {
                        Write-Error "Failed to lookup windows server version: $serverVersion"
                    }
                }
                else
                {
                    Write-Host "Warning: regex failed to decode server '$serverVersion' for $name found in $($funcFile.FullName)"
                }
            }

            if (![string]::IsNullOrEmpty($fixedVersion))
            {
                if ($writtenItems.ContainsKey($name))
                {
                    $oldValue = $writtenItems[$name]
                    if ($oldValue -ne $fixedVersion)
                    {
                        Write-Host "Duplicate, differing versions for $name - $oldValue vs. $fixedVersion"
                    }
                }
                else
                {
                    $stream.WriteLine("$name=SupportedOSPlatform(`"$fixedVersion`")")
                    $writtenItems[$name] = $fixedVersion
                }
            }
        }
    }
}
finally
{
    $stream.Close()
}
