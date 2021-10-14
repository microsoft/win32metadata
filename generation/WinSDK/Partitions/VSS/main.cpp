#define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

// Headers needed for COM
#include <objbase.h>
#include <ObjIdl.h>
#include <combaseapi.h>
#include <vdssys.h>

//
// Begin of area needing to be close to COM headers

#include <vss.h>
#include <vswriter.h>
#include <vsmgmt.h>
//#include <vsbackup.h> This contains C++ classes instead of COM interfaces
#include <vsadmin.h>
#include <vsprov.h>
#include <vsserror.h>

// End of area needing to be close to COM headers
//
