
. "$PSScriptRoot\CommonUtils.ps1"

remove-item "$emitterDir\*.generated.rsp"
remove-item "$scraperDir\*.generated.rsp"

Remove-Directory "$emitterDir\obj"
Remove-Directory "$scraperDir\obj"
Remove-Directory $sdkGeneratedSourceDir
Remove-Directory $binDir
