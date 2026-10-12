# Regenerates the synthetic ordinal fixture import libraries (all architectures) and the x64 DLL.
# Requires a Visual Studio developer environment for x64 (cl.exe, link.exe, lib.exe).
$ErrorActionPreference = 'Stop'
Push-Location $PSScriptRoot
try {
    foreach ($arch in 'x64', 'x86', 'arm64') {
        New-Item -ItemType Directory -Force "..\$arch" | Out-Null
        lib /nologo /def:ordinalfixture.def /machine:$arch /out:"..\$arch\ordinalfixture.lib"
        Remove-Item "..\$arch\ordinalfixture.exp" -ErrorAction SilentlyContinue
    }

    cl /nologo /LD /Fe:..\x64\ordinalfixture.dll ordinalfixture.c /link /DEF:ordinalfixture.def
    Remove-Item *.obj, ..\x64\ordinalfixture.exp, ..\x64\ordinalfixture.lib.tmp -ErrorAction SilentlyContinue
}
finally { Pop-Location }

