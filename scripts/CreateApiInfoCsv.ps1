Write-Host "Name,Title,Header,TechRoot"

foreach ($funcFile in Get-ChildItem "$sdkApiPath\n*.md" -r)
{
    $funcName = ""
    $reqHeader = ""
    $techRoot = ""
    $title = ""

    foreach ($matchInfo in ($funcFile | Select-String -pattern 'UID: N[F|S|E|N]:(\w+)\.(\S+)|req.header: (\S+)|tech.root: (\S+)|title: (\S+)'))
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
                        "4" { $techRoot = $group.Value }
                        "5" { $title = $group.Value }
                    }
                }
            }
        }
    }

    if (!$funcName.Contains("."))
    {
        Write-Host "$funcName,$title,$reqHeader,$techRoot"
    }
}
