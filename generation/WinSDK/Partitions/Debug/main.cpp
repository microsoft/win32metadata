#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

//#include <ntdef.h>

// Would need to use ntdef.h, but we need windows.h
typedef LONG NTSTATUS;
typedef UCHAR KIRQL;

#include <wct.h>
#include <minidumpapiset.h>
#include <activdbg.h>
#include <activprof.h>
#include <ImageHlp.h>
#include <bugcodes.h>
#include <activaut.h>
#include <activdbg100.h>
#include <dxcore.h>
#include <dxcore_interface.h>
#include <jscript9diag.h>
#include <mindumpdef.h>
#include <objsafe.h>
#include <wheadef.h>
