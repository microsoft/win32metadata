#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#define D3D10_NO_HELPERS

#include <d3dcommon.h>
#include <d3d10_1.h>
#include <d3d10.h>
#include <d3d10sdklayers.h>
#include <d3d10shader.h>
#include <d3d10effect.h>
#include <d3d10misc.h>
#include <d3d10_1shader.h>
