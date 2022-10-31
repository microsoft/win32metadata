#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#define IN _In_
#define OUT _Out_

#include <accctrl.h>
#include <adtgen.h>
#include <authz.h>
#include <azroles.h>
#include <aclui.h>
#include <aclapi.h>
#include <sddl.h>