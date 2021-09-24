#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <natupnp.h>
#include <netcon.h>
#include <netfw.h>
#include <icftypes.h>
//#include <networkisolation.h> // Conflicts with netfw.h and seems to be a superset
