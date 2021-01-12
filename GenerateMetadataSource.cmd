@echo OFF
pwsh.exe -NoLogo -NoProfile -ExecutionPolicy ByPass -Command "& """%~dp0scripts\GenerateMetadataSource.ps1""" %*"
exit /B %ERRORLEVEL%
