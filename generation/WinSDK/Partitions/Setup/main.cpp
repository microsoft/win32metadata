#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <photoacquire.h>
#include <setupapi.h>
#include <winbase.h>
#include <winnt.h>
#include <evalcom2.h>
#include <mergemod.h>
#include <msi.h>
#include <msiquery.h>
#include <winsxs.h>
#include <sfc.h>
#include <msidefs.h>
#include <msiltcfg.h>
#include <pacmanclientapi.h>
#include <patchapi.h>
#include <patchwiz.h>
#include <msdelta.h>
