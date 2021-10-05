#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <combaseapi.h>

#ifdef _EXPORTING
#define DLL_DECLSPEC    EXTERN_C __declspec(dllexport)
#else
#define DLL_DECLSPEC    EXTERN_C __declspec(dllimport)
#endif
