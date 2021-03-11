@echo OFF

setlocal
call :setESC

@echo %ESC%[36m*** Testing .winmd...%ESC%[0m
powershell.exe -NoLogo -NoProfile -ExecutionPolicy ByPass -Command "& """%~dp0scripts\CompareBinaryAgainstBaseline.ps1""" %*"
if %ERRORLEVEL% neq 0 goto :failed

echo %ESC%[32mSucceeded.%ESC%[0m
exit /B %ERRORLEVEL%

:failed
echo %ESC%[31mFailed.%ESC%[0m
exit /B %ERRORLEVEL%

:setESC
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do rem"') do (
  set ESC=%%b
  exit /B 0
)
exit /B 0
