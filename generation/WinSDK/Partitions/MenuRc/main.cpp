#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS
#define OEMRESOURCE

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <winbase.h>
#include <winnt.h>
#include <winuser.h>
#include <menutemplate.h>
#include <resourceindexer.h>
#include <strsafe.h>
#include <mrmresourceindexer.h>
#include <dbt.h>
#include <ioevent.h>
#include <iswindowarranged.h>
