#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <Mshtml.h>
#include <docobjectservice.h>
#include <downloadmgr.h>
#include <exdispid.h>
#include <extensionvalidation.h>
#include <homepagesetting.h>
#include <htiframe.h>
#include <htiface.h>
#include <ie12plugin.h>
#include <ieautomation.h>
#include <ieobj.h>
#include <iepmapi.h>
// #include <ieprocess.h> -- Won't scan: Error (Line 165, Column 34 in D:/repos/win32metadata/generation/WinSDK/RecompiledIdlHeaders/um/ieprocess.h): Unsupported callee declaration: 'CX_DeclKind_Var'. Generated bindings may be incomplete.
#include <iewebdriver.h>
#include <iextag.h>
#include <inetreg.h>
#include <inetsdk.h>
#include <mshtmcid.h>
#include <idispids.h>
#include <mshtmdid.h>
#include <mshtmhst.h>
#include <mshtmlc.h>
#include <mshtmldiagnostics.h>
#include <msiehost.h>
//#include <msoav.h> -- doesn't compile - no MSOAPI_ defined
#include <openservice.h>
#include <perhist.h>
#include <ratings.h>
#include <urlhist.h>
#include <webevnts.h>
#include <ocmm.h>
#include <imgutil.h>
