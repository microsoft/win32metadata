#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include <windows.h>
#include <sdkddkver.h>

#include <winternl.h>

#define _NTDEF_
#define SECURITY_WIN32
#include <NTSecAPI.h>
#include <sspi.h>
#include <NTSecPKG.h>
#include <schannel.h>

typedef struct _OLD_LARGE_INTEGER {
    ULONG LowPart;
    LONG HighPart;
} OLD_LARGE_INTEGER, *POLD_LARGE_INTEGER;


#include <winbase.h>
#include <winnt.h>
#include <accctrl.h>
#include <winuser.h>
#include <processthreadsapi.h>
#include <lmaccess.h>
#include <winreg.h>
#include <securitybaseapi.h>
#include <namedpipeapi.h>
#include <mmcobj.h>
#include <winwlx.h>
#include <tpmvscmgr.h>
#include <sspi.h>
#include <keycredmgr.h>
#include <wincred.h>
//#include <credssp.h>
#include <identitycommon.h>
#include <npapi.h>
//#include <ntlsa.h>
#include <winscard.h>
#include <subauth.h>
#include <certpoleng.h>
#include <sas.h>
#include <identityprovider.h>
#include <identitystore.h>
//#include <lsalookup.h>
#include <winnetwk.h>
#include <winsmcrd.h>
#include <adtgen.h>
#include <authz.h>
#include <azroles.h>
#include <aclui.h>
#include <aclapi.h>
#include <sddl.h>
#include <dssec.h>
#include <securityappcontainer.h>
#include <winsvc.h>
#include <certenroll.h>
#include <certpol.h>
#include <bcrypt.h>
#include <ncryptprotect.h>
#include <ncrypt.h>
#include <tokenbinding.h>
#include <wincrypt.h>
#include <cryptxml.h>
#include <casetup.h>
#include <certsrv.h>
#include <celib.h>
#include <certcli.h>
#include <cryptdlg.h>
#include <cryptuiapi.h>
#include <certbcli.h>
#include <mscat.h>
#include <dpapi.h>
#include <mssip.h>
#include <wintrust.h>
#include <xenroll.h>
#include <certadm.h>
#include <certenc.h>
#include <certexit.h>
#include <certmod.h>
#include <certif.h>
#include <certview.h>
#include <iads.h>
#include <scesvc.h>
#include <winsafer.h>
#include <slpublic.h>
#include <diagnosticdataquery.h>
#include <diagnosticdataquerytypes.h>
