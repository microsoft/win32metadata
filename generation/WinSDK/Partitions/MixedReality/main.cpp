#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

//#include <perceptiondevice.h> -- won't scan - Error (Line 64, Column 29 in D:/repos/win32metadata/generation/WinSDK/RecompiledIdlHeaders/um/perceptiondevice.h): Unsupported return type for abstract method: 'CX_TypeClass_LValueReference'. Generated bindings may be incomplete.
#include <perceptiondevicecore.h>
