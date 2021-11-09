#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

//#include <ntdef.h>

// Would need to use ntdef.h, but we need windows.h
typedef LONG NTSTATUS;
typedef UCHAR KIRQL;

#include <webapplication.h>
