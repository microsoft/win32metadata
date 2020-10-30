@echo OFF
powershell.exe -NoLogo -NoProfile -ExecutionPolicy ByPass -Command "& """%~dp0scripts\BuildSamples.ps1""" %*"
exit /B %ERRORLEVEL%
