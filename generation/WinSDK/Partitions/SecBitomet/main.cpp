#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"

// From ntdef.h, but using ntdef.h doesn't get us all the types we need. Same for winminbase.h
#define ARGUMENT_PRESENT(ArgumentPointer)    (\
    (CHAR *)((ULONG_PTR)(ArgumentPointer)) != (CHAR *)(NULL) )

#include <winbio.h>
#include <winbio_types.h>
#include <winbio_err.h>
#include <winbio_adapter.h>
#include <winbio_ioctl.h>
