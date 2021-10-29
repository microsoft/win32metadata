#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <mmsystem.h>

#include <dinput.h>
#include <dinputd.h>
#include <ntddkbd.h>
#include <ntddmou.h>
#include <hidsdi.h>
#include <hidpi.h>
#include <hidclass.h>
#include <hidusage.h>
#include <gpiobuttontypes.h>
