
Write-Output "Name`tHeader`tInclude`tLib`tTechRoot"

foreach ($funcFile in ls "$sdkApiPath\nf-*" -r)
{
    $funcName = ""
    $reqHeader = ""
    $incHeader = ""
    $reqLib = ""
    $techRoot = ""

    foreach ($matchInfo in ($funcFile | Select-String -pattern 'UID: NF:(\w+)\.(\S+)|req.header: (\S+)|req.include-header: (\S+)|req.lib: (\S+)|tech.root: (\S+)'))
    {
        foreach ($match in $matchInfo.Matches)
        {
            foreach ($group in $match.Groups)
            {
                if ($group.Success)
                {
                    switch ($group.Name)
                    {
                        "2" { $funcName = $group.Value }
                        "3" { $reqHeader = $group.Value }
                        "4" { $incHeader = $group.Value }
                        "5" { $reqLib = $group.Value }
                        "6" { $techRoot = $group.Value }
                    }
                }
            }
        }
    }

    Write-Output "$funcName`t$reqHeader`t$incHeader`t$reqLib`t$techRoot"
}
