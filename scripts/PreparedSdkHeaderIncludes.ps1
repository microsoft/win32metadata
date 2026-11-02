function Get-PreparedSdkHeaderIncludes {
    param(
        [Parameter(Mandatory)][string]$IncludeRoot,
        [AllowEmptyCollection()][string[]]$NativeIncludeDirectory = @()
    )

    $root = [IO.Path]::GetFullPath($IncludeRoot).TrimEnd('\')
    $directories = [Collections.Generic.List[string]]::new()
    $seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    foreach ($name in @('shared', 'um', 'ucrt', 'winrt')) {
        $path = "$root\$name"
        if (!(Test-Path -LiteralPath $path -PathType Container)) {
            throw "A canonical prepared SDK include directory is missing: $path"
        }
        [void]$seen.Add($path)
        $directories.Add($path)
    }
    foreach ($include in $NativeIncludeDirectory) {
        $path = [IO.Path]::GetFullPath($include).TrimEnd('\')
        if (!(Test-Path -LiteralPath $path -PathType Container)) {
            throw "An explicitly selected native include directory is missing: $path"
        }
        if ($seen.Contains($path)) { continue }
        $name = [IO.Path]::GetFileName($path)
        $msvc = $name -ieq 'include' -and (Test-Path -LiteralPath "$path\vcruntime.h" -PathType Leaf)
        $ucrt = $name -ieq 'ucrt' -and (Test-Path -LiteralPath "$path\corecrt.h" -PathType Leaf)
        if (!$msvc -and !$ucrt) {
            throw "Only selected MSVC/UCRT fallback include directories are allowed: $path. SDK shared/um/winrt headers must come from the canonical prepared root."
        }
        if ($seen.Add($path)) { $directories.Add($path) }
    }
    $directories.ToArray()
}

function Assert-PreparedSdkHeaderIncludes {
    param(
        [Parameter(Mandatory)][string]$IncludeRoot,
        [Parameter(Mandatory)][string]$ProjectDirectory,
        [Parameter(Mandatory)][AllowEmptyCollection()][string[]]$ResponseFile,
        [AllowEmptyCollection()][string[]]$NativeIncludeDirectory = @()
    )

    $root = [IO.Path]::GetFullPath($IncludeRoot).TrimEnd('\')
    $projectIncludes = [IO.Path]::GetFullPath("$ProjectDirectory\inc").TrimEnd('\')
    $selected = @(Get-PreparedSdkHeaderIncludes $root $NativeIncludeDirectory)
    $canonical = @($selected | Select-Object -First 4)
    $fallbacks = [Collections.Generic.HashSet[string]]::new(
        [string[]]@($selected | Select-Object -Skip 4), [StringComparer]::OrdinalIgnoreCase)
    if (!$ResponseFile.Count) { throw 'No emitted header response files were available for prepared SDK include validation.' }
    foreach ($file in $ResponseFile) {
        $includes = [Collections.Generic.List[string]]::new()
        $traverseDirectories = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
        $section = ''
        foreach ($rawLine in [IO.File]::ReadAllLines($file)) {
            $line = $rawLine.Trim()
            if (!$line) { continue }
            if ($line.StartsWith('--', [StringComparison]::Ordinal)) {
                $section = $line
                continue
            }
            if ($section -notin @('--include-directory', '--traverse')) { continue }
            if (![IO.Path]::IsPathFullyQualified($line)) {
                throw "An emitted header include/traverse path is not absolute: $file : $line"
            }
            if ($section -eq '--include-directory') {
                $includes.Add([IO.Path]::GetFullPath($line).TrimEnd('\'))
            } else {
                [void]$traverseDirectories.Add([IO.Path]::GetDirectoryName([IO.Path]::GetFullPath($line)))
            }
        }
        $lastPrepared = -1
        foreach ($directory in $canonical) {
            $index = $includes.FindIndex([Predicate[string]]{
                param($path)
                $path.Equals($directory, [StringComparison]::OrdinalIgnoreCase)
            })
            if ($index -lt 0) { throw "An emitted response file omits a canonical prepared SDK include root: $file : $directory" }
            $lastPrepared = [Math]::Max($lastPrepared, $index)
        }
        for ($index = 0; $index -lt $includes.Count; $index++) {
            $directory = $includes[$index]
            if ($directory.Equals($projectIncludes, [StringComparison]::OrdinalIgnoreCase) -or
                $directory.StartsWith("$root\", [StringComparison]::OrdinalIgnoreCase)) {
                continue
            }
            if ($fallbacks.Contains($directory)) {
                if ($index -lt $lastPrepared) {
                    throw "Canonical prepared SDK include roots must precede every native fallback: $file : $directory"
                }
                continue
            }
            $name = [IO.Path]::GetFileName($directory)
            if ($name -notin @('shared', 'um', 'ucrt', 'winrt') -and $traverseDirectories.Contains($directory)) {
                continue
            }
            throw "An emitted response file contains an unselected native or unprepared SDK include directory: $file : $directory"
        }
        [pscustomobject]@{
            responseFile = [IO.Path]::GetFullPath($file)
            sha256 = (Get-FileHash -LiteralPath $file -Algorithm SHA256).Hash
            includeDirectories = $includes.ToArray()
        }
    }
}
