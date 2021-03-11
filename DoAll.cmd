@echo off

call GenerateMetadataSource.cmd
if %ERRORLEVEL% neq 0 exit /B %ERRORLEVEL%

call BuildMetadataBin.cmd
if %ERRORLEVEL% neq 0 exit /B %ERRORLEVEL%

call TestMetadataBin.cmd
if %ERRORLEVEL% neq 0 exit /B %ERRORLEVEL%

exit 0
