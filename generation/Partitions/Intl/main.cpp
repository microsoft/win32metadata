#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include <windows.h>
#include <sdkddkver.h>

#include <winbase.h>
#include <winnt.h>
#include <winuser.h>
#include <wingdi.h>
#include <libloaderapi.h>
#include <elscore.h>
#include <winnls.h>
#include <stringapiset.h>
#include <datetimeapi.h>
#include <spellcheckprovider.h>
#include <spellcheck.h>
#include <msime.h>
#include <imm.h>
#include <immdev.h>
#include <imepad.h>
#include <msimeapi.h>
#include <usp10.h>
#include <muiload.h>
#include <gb18030.h>
