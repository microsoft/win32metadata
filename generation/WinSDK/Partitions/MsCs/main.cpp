#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

// Normally brought in by windows.h
typedef LONG NTSTATUS;
typedef NTSTATUS* PNTSTATUS;

#include <resapi.h>
#include <smbclnt.h>
#include <cluadmex.h>
#include <msclus.h>
