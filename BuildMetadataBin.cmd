@echo OFF
powershell.exe -NoLogo -NoProfile -ExecutionPolicy ByPass -Command "& """%~dp0scripts\BuildMetadataBin.ps1""" %*"
exit /B %ERRORLEVEL%
