@echo OFF
powershell.exe -NoLogo -NoProfile -ExecutionPolicy ByPass -Command "& """%~dp0scripts\CompareBinaryAgainstBaseline.ps1""" %*"
exit /B %ERRORLEVEL%
