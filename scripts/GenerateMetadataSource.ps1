
param
(
    [string]
    $sdkVer = "19041"
)

function Create-Directory([string[]] $Path) 
{
    if (!(Test-Path -Path $Path)) 
    {
        New-Item -Path $Path -Force -ItemType "Directory" | Out-Null
    }
}

$artifactsDir = Join-Path -Path $PSScriptRoot -ChildPath "..\artifacts"
Create-Directory $artifactsDir

$libMappingOutputFileName = Join-Path -Path $artifactsDir -ChildPath "libMappings.$sdkVer.rsp"

Write-Host "Creating lib mapping file: $libMappingOutputFileName"
& $PSScriptRoot\CreateProcLibMapping.ps1 -sdkVer $sdkVer -outputFileName $libMappingOutputFileName


$generateDir = Join-Path -Path $PSScriptRoot -ChildPath "..\generation"

$generatorOutput = Join-Path -Path $artifactsDir -ChildPath "generation.output.txt"

Write-Host "Creating metdata .cs file. Log output: $generatorOutput"
Write-Host "Calling: $PSScriptRoot\..\tools\ClangSharpPInvokeGenerator.exe @$generateDir\remap.rsp @$generateDir\settings.rsp @$libMappingOutputFileName"

& $PSScriptRoot\..\tools\ClangSharpPInvokeGenerator.exe "@$generateDir\remap.rsp" "@$generateDir\settings.rsp" "@$libMappingOutputFileName" > $generatorOutput

$missedFuncsOutput = Join-Path -Path $artifactsDir -ChildPath "missedfuncs.output.txt"
& $PSScriptRoot\CheckMissedFuncs.ps1 -generatorResults  $generatorOutput -mappingFile $libMappingOutputFileName -missedFuncsFile $missedFuncsOutput

