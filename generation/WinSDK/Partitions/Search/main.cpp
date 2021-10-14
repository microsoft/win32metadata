#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#define QUERY_H_RESTRICTION_PERMISSIVE 1

#include <filter.h>
#include <indexsrv.h>
#include <ocidl.h>
#include <searchapi.h>
#include <shobjidl_core.h>
#include <structuredquerycondition.h>
#include <structuredquery.h>
#include <filtereg.h>
#include <search.h>
#include <subsmgr.h>
#include <msdadc.h>
#include <msdaguid.h>
#include <msdaora.h>
#include <msdaosp.h>
#include <msdasc.h>
#include <msdasql_interfaces.h>
#include <msdasql.h>
#include <msdatsrc.h>
#include <msdshape.h>
#include <odbcinst.h>
#include <odbcss.h>
#include <oledbdep.h>
#include <oledberr.h>
//#include <oledbguid.h> -- clashes with oledb.h
#include <persist.h>
#include <query.h>
#include <simpdata.h>
#include <sql.h>
#include <sqlext.h>
#include <sqloledb.h>
#include <sqlspi.h>
#include <sqltypes.h>
#include <sqlucode.h>
#include <stgprop.h>
#include <windowssearcherrors.h>
