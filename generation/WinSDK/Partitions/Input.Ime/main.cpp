#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <winbase.h>
#include <winnt.h>
#include <winuser.h>

#include <msime.h>
#include <imm.h>
#include <immdev.h>
#include <imepad.h>
#include <msimeapi.h>
#include <ime_cmodes.h>

#define _DDKIMM_H_ // Keeps INPUTCONTEXT and IMEINFO from coming in again
#include <dimm.h>

