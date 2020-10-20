@echo OFF
powershell.exe -NoLogo -NoProfile -ExecutionPolicy ByPass -Command "& """%~dp0scripts\BuildCsWin32Projection.ps1""" %*"
exit /B %ERRORLEVEL%
