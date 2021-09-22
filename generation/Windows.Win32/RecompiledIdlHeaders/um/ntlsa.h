/*++ BUILD Version: 0011    // Increment this if a change has global effects

Copyright (c) 1989-1999 Microsoft Corporation

Module Name:

    ntlsa.h

Abstract:

    This module contains the public data structures and API definitions
    needed to utilize Local Security Authority (LSA) services.

Revision History:

--*/

#ifndef _NTLSA_
#define _NTLSA_

#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#include <sdkddkver.h>

// begin_ntsecapi
#include <lsalookup.h>
// end_ntsecapi

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4820) // padding added after data member
#endif

// begin_ntsecapi
#ifndef _NTLSA_IFS_
// begin_ntifs


//
// Security operation mode of the system is held in a control
// longword.
//

typedef ULONG  LSA_OPERATIONAL_MODE, *PLSA_OPERATIONAL_MODE;

// end_ntifs
#endif // _NTLSA_IFS_

//
// The flags in the security operational mode are defined
// as:
//
//    PasswordProtected - Some level of authentication (such as
//        a password) must be provided by users before they are
//        allowed to use the system.  Once set, this value will
//        not be cleared without re-booting the system.
//
//    IndividualAccounts - Each user must identify an account to
//        logon to.  This flag is only meaningful if the
//        PasswordProtected flag is also set.  If this flag is
//        not set and the PasswordProtected flag is set, then all
//        users may logon to the same account.  Once set, this value
//        will not be cleared without re-booting the system.
//
//    MandatoryAccess - Indicates the system is running in a mandatory
//        access control mode (e.g., B-level as defined by the U.S.A's
//        Department of Defense's "Orange Book").  This is not utilized
//        in the current release of NT.  This flag is only meaningful
//        if both the PasswordProtected and IndividualAccounts flags are
//        set.  Once set, this value will not be cleared without
//        re-booting the system.
//
//    LogFull - Indicates the system has been brought up in a mode in
//        which if must perform security auditing, but its audit log
//        is full.  This may (should) restrict the operations that
//        can occur until the audit log is made not-full again.  THIS
//        VALUE MAY BE CLEARED WHILE THE SYSTEM IS RUNNING (I.E., WITHOUT
//        REBOOTING).
//
// If the PasswordProtected flag is not set, then the system is running
// without security, and user interface should be adjusted appropriately.
//

#define LSA_MODE_PASSWORD_PROTECTED     (0x00000001L)
#define LSA_MODE_INDIVIDUAL_ACCOUNTS    (0x00000002L)
#define LSA_MODE_MANDATORY_ACCESS       (0x00000004L)
#define LSA_MODE_LOG_FULL               (0x00000008L)

// end_ntsecapi


/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Widely used LSA defines                                             //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

//
// Defines for Count Limits on LSA API
//

#define LSA_MAXIMUM_SID_COUNT           (0x00000100L)
#define LSA_MAXIMUM_ENUMERATION_LENGTH  (32000)

//
// Flag OR'ed into AuthenticationPackage parameter of LsaLogonUser to
// request that the license server be called upon successful logon.
//

#define LSA_CALL_LICENSE_SERVER 0x80000000


/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Data types used by logon processes                                  //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// begin_ntsecapi
#ifndef _NTLSA_IFS_
// begin_ntifs
//
// Used by a logon process to indicate what type of logon is being
// requested.
//

typedef enum _SECURITY_LOGON_TYPE {
    UndefinedLogonType = 0, // This is used to specify an undefied logon type
    Interactive = 2,      // Interactively logged on (locally or remotely)
    Network,              // Accessing system via network
    Batch,                // Started via a batch queue
    Service,              // Service started by service controller
    Proxy,                // Proxy logon
    Unlock,               // Unlock workstation
    NetworkCleartext,     // Network logon with cleartext credentials
    NewCredentials,       // Clone caller, new default credentials
    //The types below only exist in Windows XP and greater
#if (_WIN32_WINNT >= 0x0501)
    RemoteInteractive,  // Remote, yet interactive. Terminal server
    CachedInteractive,  // Try cached credentials without hitting the net.
    // The types below only exist in Windows Server 2003 and greater
#endif
#if (_WIN32_WINNT >= 0x0502)
    CachedRemoteInteractive, // Same as RemoteInteractive, this is used internally for auditing purpose
    CachedUnlock        // Cached Unlock workstation
#endif
} SECURITY_LOGON_TYPE, *PSECURITY_LOGON_TYPE;

// end_ntifs
#endif // _NTLSA_IFS_

// end_ntsecapi


//
// Security System Access Flags.  These correspond to the enumerated
// type values in SECURITY_LOGON_TYPE.
//
// IF YOU ADD A NEW LOGON TYPE HERE, ALSO ADD IT TO THE POLICY_MODE_xxx
// data definitions.
//

#define SECURITY_ACCESS_INTERACTIVE_LOGON             ((ULONG) 0x00000001L)
#define SECURITY_ACCESS_NETWORK_LOGON                 ((ULONG) 0x00000002L)
#define SECURITY_ACCESS_BATCH_LOGON                   ((ULONG) 0x00000004L)
#define SECURITY_ACCESS_SERVICE_LOGON                 ((ULONG) 0x00000010L)
#define SECURITY_ACCESS_PROXY_LOGON                   ((ULONG) 0x00000020L)
#define SECURITY_ACCESS_DENY_INTERACTIVE_LOGON        ((ULONG) 0x00000040L)
#define SECURITY_ACCESS_DENY_NETWORK_LOGON            ((ULONG) 0x00000080L)
#define SECURITY_ACCESS_DENY_BATCH_LOGON              ((ULONG) 0x00000100L)
#define SECURITY_ACCESS_DENY_SERVICE_LOGON            ((ULONG) 0x00000200L)
#define SECURITY_ACCESS_REMOTE_INTERACTIVE_LOGON      ((ULONG) 0x00000400L)
#define SECURITY_ACCESS_DENY_REMOTE_INTERACTIVE_LOGON ((ULONG) 0x00000800L)

// begin_ntddk begin_ntosp begin_wdm
// begin_ntsecapi
#ifndef _NTLSA_IFS_
// begin_ntifs

//
// All of this stuff (between the Ifndef _NTLSA_AUDIT_ and its endif) were not
// present in NTIFS prior to Windows Server 2003 SP1. All of the definitions however
// exist down to windows 2000 (except for the few exceptions noted in the code).
//

#ifndef _NTLSA_AUDIT_
#define _NTLSA_AUDIT_

/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Data types related to Auditing                                      //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


//
// The following enumerated type is used between the reference monitor and
// LSA in the generation of audit messages.  It is used to indicate the
// type of data being passed as a parameter from the reference monitor
// to LSA.  LSA is responsible for transforming the specified data type
// into a set of unicode strings that are added to the event record in
// the audit log.
//

typedef enum _SE_ADT_PARAMETER_TYPE {

    SeAdtParmTypeNone = 0,          //Produces 1 parameter
                                    //Received value:
                                    //
                                    //  None.
                                    //
                                    //Results in:
                                    //
                                    //  a unicode string containing "-".
                                    //
                                    //Note:  This is typically used to
                                    //       indicate that a parameter value
                                    //       was not available.
                                    //

    SeAdtParmTypeString,            //Produces 1 parameter.
                                    //Received Value:
                                    //
                                    //  Unicode String (variable length)
                                    //
                                    //Results in:
                                    //
                                    //  No transformation.  The string
                                    //  entered into the event record as
                                    //  received.
                                    //
                                    // The Address value of the audit info
                                    // should be a pointer to a UNICODE_STRING
                                    // structure.



    SeAdtParmTypeFileSpec,          //Produces 1 parameter.
                                    //Received value:
                                    //
                                    //  Unicode string containing a file or
                                    //  directory name.
                                    //
                                    //Results in:
                                    //
                                    //  Unicode string with the prefix of the
                                    //  file's path replaced by a drive letter
                                    //  if possible.
                                    //




    SeAdtParmTypeUlong,             //Produces 1 parameter
                                    //Received value:
                                    //
                                    //  Ulong
                                    //
                                    //Results in:
                                    //
                                    //  Unicode string representation of
                                    //  unsigned integer value.


    SeAdtParmTypeSid,               //Produces 1 parameter.
                                    //Received value:
                                    //
                                    //  SID (variable length)
                                    //
                                    //Results in:
                                    //
                                    //  String representation of SID
                                    //




    SeAdtParmTypeLogonId,           //Produces 4 parameters.
                                    //Received Value:
                                    //
                                    //  LUID (fixed length)
                                    //
                                    //Results in:
                                    //
                                    //  param 1: Sid string
                                    //  param 2: Username string
                                    //  param 3: domain name string
                                    //  param 4: Logon ID (Luid) string


    SeAdtParmTypeNoLogonId,         //Produces 3 parameters.
                                    //Received value:
                                    //
                                    //  None.
                                    //
                                    //Results in:
                                    //
                                    //  param 1: "-"
                                    //  param 2: "-"
                                    //  param 3: "-"
                                    //  param 4: "-"
                                    //
                                    //Note:
                                    //
                                    //  This type is used when a logon ID
                                    //  is needed, but one is not available
                                    //  to pass.  For example, if an
                                    //  impersonation logon ID is expected
                                    //  but the subject is not impersonating
                                    //  anyone.
                                    //

    SeAdtParmTypeAccessMask,        //Produces 1 parameter with formatting.
                                    //Received value:
                                    //
                                    //  ACCESS_MASK followed by
                                    //  a Unicode string.  The unicode
                                    //  string contains the name of the
                                    //  type of object the access mask
                                    //  applies to.  The event's source
                                    //  further qualifies the object type.
                                    //
                                    //Results in:
                                    //
                                    //  formatted unicode string built to
                                    //  take advantage of the specified
                                    //  source's parameter message file.
                                    //
                                    //Note:
                                    //
                                    //  An access mask containing three
                                    //  access types for a Widget object
                                    //  type (defined by the Foozle source)
                                    //  might end up looking like:
                                    //
                                    //      %%1062\n\t\t%1066\n\t\t%%601
                                    //
                                    //  The %%numbers are signals to the
                                    //  event viewer to perform parameter
                                    //  substitution before display.
                                    //



    SeAdtParmTypePrivs,             //Produces 1 parameter with formatting.
                                    //Received value:
                                    //
                                    //Results in:
                                    //
                                    //  formatted unicode string similar to
                                    //  that for access types.  Each priv
                                    //  will be formatted to be displayed
                                    //  on its own line.  E.g.,
                                    //
                                    //      %%642\n\t\t%%651\n\t\t%%655
                                    //

    SeAdtParmTypeObjectTypes,       //Produces 10 parameters with formatting.
                                    //Received value:
                                    //
                                    // Produces a list a stringized GUIDS along
                                    // with information similar to that for
                                    // an access mask.

    SeAdtParmTypeHexUlong,          //Produces 1 parameter
                                    //Received value:
                                    //
                                    //  Ulong
                                    //
                                    //Results in:
                                    //
                                    //  Unicode string representation of
                                    //  unsigned integer value in hexadecimal.

// In W2k this value did not exist, it was ParmTypeLUID

    SeAdtParmTypePtr,               //Produces 1 parameter
                                    //Received value:
                                    //
                                    //  pointer
                                    //
                                    //Results in:
                                    //
                                    //  Unicode string representation of
                                    //  unsigned integer value in hexadecimal.

//
// Everything below exists only in Windows XP and greater
//

    SeAdtParmTypeTime,              //Produces 2 parameters
                                    //Received value:
                                    //
                                    //  LARGE_INTEGER
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representation of
                                    // date and time.

                                    //
    SeAdtParmTypeGuid,              //Produces 1 parameter
                                    //Received value:
                                    //
                                    //  GUID pointer
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representation of GUID
                                    // {xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}
                                    //

//
// Everything below exists only in Windows Server 2003 and Greater
//

    SeAdtParmTypeLuid,              //
                                    //Produces 1 parameter
                                    //Received value:
                                    //
                                    // LUID
                                    //
                                    //Results in:
                                    //
                                    // Hex LUID
                                    //

    SeAdtParmTypeHexInt64,          //Produces 1 parameter
                                    //Received value:
                                    //
                                    //  64 bit integer
                                    //
                                    //Results in:
                                    //
                                    //  Unicode string representation of
                                    //  unsigned integer value in hexadecimal.

    SeAdtParmTypeStringList,        //Produces 1 parameter
                                    //Received value:
                                    //
                                    // ptr to LSAP_ADT_STRING_LIST
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representation of
                                    // concatenation of the strings in the list

    SeAdtParmTypeSidList,           //Produces 1 parameter
                                    //Received value:
                                    //
                                    // ptr to LSAP_ADT_SID_LIST
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representation of
                                    // concatenation of the SIDs in the list

    SeAdtParmTypeDuration,          //Produces 1 parameters
                                    //Received value:
                                    //
                                    //  LARGE_INTEGER
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representation of
                                    // a duration.

    SeAdtParmTypeUserAccountControl,//Produces 3 parameters
                                    //Received value:
                                    //
                                    // old and new UserAccountControl values
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representations of
                                    // the flags in UserAccountControl.
                                    // 1 - old value in hex
                                    // 2 - new value in hex
                                    // 3 - difference as strings

    SeAdtParmTypeNoUac,             //Produces 3 parameters
                                    //Received value:
                                    //
                                    // none
                                    //
                                    //Results in:
                                    //
                                    // Three dashes ('-') as unicode strings.

    SeAdtParmTypeMessage,           //Produces 1 Parameter
                                    //Received value:
                                    //
                                    //  ULONG (MessageNo from msobjs.mc)
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representation of
                                    // %%MessageNo which the event viewer
                                    // will replace with the message string
                                    // from msobjs.mc

    SeAdtParmTypeDateTime,          //Produces 1 Parameter
                                    //Received value:
                                    //
                                    //  LARGE_INTEGER
                                    //
                                    //Results in:
                                    //
                                    // Unicode string representation of
                                    // date and time (in _one_ string).

    SeAdtParmTypeSockAddr,          // Produces 2 parameters
                                    //
                                    // Received value:
                                    //
                                    // pointer to SOCKADDR_IN/SOCKADDR_IN6
                                    // structure
                                    //
                                    // Results in:
                                    //
                                    // param 1: IP address string
                                    // param 2: Port number string
                                    //

//
// Everything below this exists only in Windows Server 2008 and greater
//

    SeAdtParmTypeSD,                // Produces 1 parameters
                                    //
                                    // Received value:
                                    //
                                    // pointer to SECURITY_DESCRIPTOR
                                    // structure. This HAS to appear in pairs.
                                    // The first parameter will represent the
                                    // old SD and the second parameter will
                                    // represent the New SD
                                    //
                                    // Results in:
                                    //
                                    // SDDL string representation of SD
                                    //

    SeAdtParmTypeLogonHours,        // Produces 1 parameters
                                    //
                                    // Received value:
                                    //
                                    // pointer to LOGON_HOURS
                                    // structure
                                    //
                                    // Results in:
                                    //
                                    // String representation of allowed logon hours
                                    //

    SeAdtParmTypeLogonIdNoSid,      //Produces 3 parameters.
                                    //Received Value:
                                    //
                                    //  LUID (fixed length)
                                    //
                                    //Results in:
                                    //
                                    //  param 1: Username string
                                    //  param 2: domain name string
                                    //  param 3: Logon ID (Luid) string

    SeAdtParmTypeUlongNoConv,       // Produces 1 parameter.
                                    // Received Value:
                                    // Ulong
                                    //
                                    //Results in:
                                    // Not converted to string
                                    //

    SeAdtParmTypeSockAddrNoPort,    // Produces 1 parameter
                                    //
                                    // Received value:
                                    //
                                    // pointer to SOCKADDR_IN/SOCKADDR_IN6
                                    // structure
                                    //
                                    // Results in:
                                    //
                                    // param 1: IPv4/IPv6 address string
                                    //
//
// Everything below this exists only in Windows Server 2008 and greater
//

    SeAdtParmTypeAccessReason,      // Produces 1 parameters
                                    //
                                    // Received value:
                                    //
                                    // pointer to SE_ADT_ACCESS_REASON structure
                                    //
                                    // Results in:
                                    //
                                    // String representation of the access reason.
                                    //
//
// Everything below this exists only in Windows Server 2012 and greater
//

    SeAdtParmTypeStagingReason,     // Produces 1 parameters
                                    //
                                    // Received value:
                                    //
                                    // pointer to SE_ADT_ACCESS_REASON structure
                                    //
                                    // Results in:
                                    //
                                    // String representation of Staging policy's
                                    // access reason.
                                    //

    SeAdtParmTypeResourceAttribute, // Produces 1 parameters
                                    //
                                    // Received value:
                                    //
                                    // pointer to SECURITY_DESCRIPTOR
                                    // structure
                                    //
                                    // Results in:
                                    //
                                    // SDDL string representation of the
                                    // Resource Attribute ACEs in the SD
                                    //

    SeAdtParmTypeClaims,            // Produces 1 parameters
                                    //
                                    // Received value:
                                    //
                                    // pointer to the structure -
                                    // CLAIM_SECURITY_ATTRIBUTES_INFORMATION
                                    // structure
                                    //
                                    // Results in:
                                    //
                                    // Claims information as attributes, value
                                    // pairs
                                    //

    SeAdtParmTypeLogonIdAsSid,      // Produces 4 parameters.
                                    // Received Value:
                                    //
                                    //  SID  (variable length)
                                    //
                                    //Results in:
                                    //
                                    //  param 1: Sid string (based on SID and not derived from the LUID)
                                    //  param 2: -
                                    //  param 3: -
                                    //  param 4: -

    SeAdtParmTypeMultiSzString,     //Produces 1 parameter
                                    //Received value:
                                    //
                                    // PZZWSTR string
                                    //
                                    //Results in:
                                    //
                                    // Unicode string with each null replaced with /r/n

    SeAdtParmTypeLogonIdEx,         //Produces 4 parameters.
                                    //Received Value:
                                    //
                                    //  LUID (fixed length)
                                    //
                                    //Results in:
                                    //
                                    //  param 1: Sid string
                                    //  param 2: Username string
                                    //  param 3: domain name string
                                    //  param 4: Logon ID (Luid) string

} SE_ADT_PARAMETER_TYPE, *PSE_ADT_PARAMETER_TYPE;

#ifndef GUID_DEFINED
#include <guiddef.h>
#endif /* GUID_DEFINED */

typedef struct _SE_ADT_OBJECT_TYPE {
    GUID ObjectType;
    USHORT Flags;
#define SE_ADT_OBJECT_ONLY 0x1
    USHORT Level;
    ACCESS_MASK AccessMask;
} SE_ADT_OBJECT_TYPE, *PSE_ADT_OBJECT_TYPE;

typedef struct _SE_ADT_PARAMETER_ARRAY_ENTRY {

    SE_ADT_PARAMETER_TYPE Type;
    ULONG Length;
    ULONG_PTR Data[2];
    PVOID Address;

} SE_ADT_PARAMETER_ARRAY_ENTRY, *PSE_ADT_PARAMETER_ARRAY_ENTRY;


typedef struct _SE_ADT_ACCESS_REASON{
    ACCESS_MASK AccessMask;
    ULONG  AccessReasons[32];
    ULONG  ObjectTypeIndex;
    ULONG AccessGranted;
    PSECURITY_DESCRIPTOR SecurityDescriptor;    // multple SDs may be stored here in self-relative way.
} SE_ADT_ACCESS_REASON, *PSE_ADT_ACCESS_REASON;

typedef struct _SE_ADT_CLAIMS {

    ULONG Length;
    PCLAIMS_BLOB Claims; // one claim blob will be stored here in self-relative way

} SE_ADT_CLAIMS, *PSE_ADT_CLAIMS;

//
// Structure that will be passed between the Reference Monitor and LSA
// to transmit auditing information.
//

#define SE_MAX_AUDIT_PARAMETERS 32
#define SE_MAX_GENERIC_AUDIT_PARAMETERS 28

typedef struct _SE_ADT_PARAMETER_ARRAY {

    ULONG CategoryId;
    ULONG AuditId;
    ULONG ParameterCount;
    ULONG Length;
    USHORT FlatSubCategoryId;
    USHORT Type;
    ULONG Flags;
    SE_ADT_PARAMETER_ARRAY_ENTRY Parameters[ SE_MAX_AUDIT_PARAMETERS ];

} SE_ADT_PARAMETER_ARRAY, *PSE_ADT_PARAMETER_ARRAY;

typedef struct _SE_ADT_PARAMETER_ARRAY_EX {

    ULONG CategoryId;
    ULONG AuditId;
    ULONG Version;
    ULONG ParameterCount;
    ULONG Length;
    USHORT FlatSubCategoryId;
    USHORT Type;
    ULONG Flags;
    SE_ADT_PARAMETER_ARRAY_ENTRY Parameters[ SE_MAX_AUDIT_PARAMETERS ];

} SE_ADT_PARAMETER_ARRAY_EX, *PSE_ADT_PARAMETER_ARRAY_EX;


#define SE_ADT_PARAMETERS_SELF_RELATIVE     0x00000001
#define SE_ADT_PARAMETERS_SEND_TO_LSA       0x00000002
#define SE_ADT_PARAMETER_EXTENSIBLE_AUDIT   0x00000004
#define SE_ADT_PARAMETER_GENERIC_AUDIT      0x00000008
#define SE_ADT_PARAMETER_WRITE_SYNCHRONOUS  0x00000010


//
// This macro only existed in Windows Server 2008 and after
//

#define LSAP_SE_ADT_PARAMETER_ARRAY_TRUE_SIZE(AuditParameters)    \
     ( sizeof(SE_ADT_PARAMETER_ARRAY) -                           \
       sizeof(SE_ADT_PARAMETER_ARRAY_ENTRY) *                     \
       (SE_MAX_AUDIT_PARAMETERS - AuditParameters->ParameterCount) )

#endif // _NTLSA_AUDIT_

// end_ntifs
#endif // _NTLSA_IFS_
// end_ntsecapi
// end_ntddk end_ntosp end_wdm

///////////////////////////////////////////////////////////////////////////
//                                                                       //
// Structures describing the complex param type SeAdtParmTypeStringList  //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

typedef struct _LSA_ADT_STRING_LIST_ENTRY
{
    ULONG                       Flags;
    UNICODE_STRING              String;
}
LSA_ADT_STRING_LIST_ENTRY, *PLSA_ADT_STRING_LIST_ENTRY;

typedef struct _LSA_ADT_STRING_LIST
{
    ULONG                       cStrings;
    PLSA_ADT_STRING_LIST_ENTRY  Strings;
}
LSA_ADT_STRING_LIST, *PLSA_ADT_STRING_LIST;


///////////////////////////////////////////////////////////////////////////
//                                                                       //
// Structures describing the complex param type SeAdtParmTypeSidList     //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

typedef struct _LSA_ADT_SID_LIST_ENTRY
{
    ULONG                       Flags;
    PSID                        Sid;
}
LSA_ADT_SID_LIST_ENTRY, *PLSA_ADT_SID_LIST_ENTRY;

typedef struct _LSA_ADT_SID_LIST
{
    ULONG                       cSids;
    PLSA_ADT_SID_LIST_ENTRY     Sids;
}
LSA_ADT_SID_LIST, *PLSA_ADT_SID_LIST;



//
// The security source name
//

#define LSA_ADT_SECURITY_SOURCE_NAME L"Microsoft-Windows-Security-Auditing"

//
// The legacy source name
//

#define LSA_ADT_LEGACY_SECURITY_SOURCE_NAME L"Security"



//
// The count will begin at SE_ADT_POLICY_AUDIT_EVENT_TYPE_EX_BEGIN. This
// allows distinguishing the former categories (represented by
// POLICY_AUDIT_EVENT_TYPE) with the new categories/sub-categories
// audit events information
//

#define SE_ADT_POLICY_AUDIT_EVENT_TYPE_EX_BEGIN         100


//
// Changes to make when adding a new sub-category
// a) Add new sub-category at the end of a category in POLICY_AUDIT_EVENT_TYPE_EX
// b) Define new GUID (next guid ID in sequence) and add it to adtapi.w
// c) Add new sub-category to LsapAdtGuidToIdMapping in adtapi.c. Make sure GUID is added in
//        sequential order
// d) Update per-category count in ntrmlsa.w
// e) Add textual description for the new sub-category to msobjs.mc
// f) Add a task for this subcategory in MsAuditEvtLog.man. The task ID should be the same as the
//    SubCategory ID defined in step a).
// g) Update LSAP_ADT_START_CATEGORY_ID_IN_MSOBJS and/or LSAP_ADT_START_SUB_CATEGORY_ID_IN_MSOBJS
//        if necessary.
// h) Update the subcategory count in base\published\ntseapi_x.w (POLICY_AUDIT_SUBCATEGORY_COUNT). This
//    is necessary because base\wow64 compilation fails if we ask the compiler to compute
//    the count via (((ULONG) AuditSubCategoryMaxType - AuditSubCategoryMinType + 1))
// i) Update AuditSubCategoryMaxType (in ntrmlsa.w) if necessary.
//


//
// Internally, the audit categories and sub-categories are treated
// just as categogies.
// IMPORTANT NOTE: Keep this in sync with the list beginning
// at POLICY_AUDIT_SYSTEM_SUBCATEGORIES in this file. Also update
// the per sub-category counts in ntrmlsa.w
//

typedef enum _POLICY_AUDIT_EVENT_TYPE_EX {

    iSystem_SecurityStateChange = SE_ADT_POLICY_AUDIT_EVENT_TYPE_EX_BEGIN,
    iSystem_SecuritySubsystemExtension,
    iSystem_Integrity,
    iSystem_IPSecDriverEvents,
    iSystem_Others,

    iLogon_Logon,
    iLogon_Logoff,
    iLogon_AccountLockout,
    iLogon_IPSecMainMode,
    iLogon_SpecialLogon,
    iLogon_IPSecQuickMode,
    iLogon_IPSecUsermode,
    iLogon_Others,
    iLogon_NPS,
    iLogon_Claims,
    iLogon_Groups,

    iObjectAccess_FileSystem,
    iObjectAccess_Registry,
    iObjectAccess_Kernel,
    iObjectAccess_Sam,
    iObjectAccess_Other,
    iObjectAccess_CertificationAuthority,
    iObjectAccess_ApplicationGenerated,
    iObjectAccess_HandleBasedAudits,
    iObjectAccess_Share,
    iObjectAccess_FirewallPacketDrops,
    iObjectAccess_FirewallConnection,
    iObjectAccess_DetailedFileShare,
    iObjectAccess_RemovableStorage,
    iObjectAccess_CbacStaging,

    iPrivilegeUse_Sensitive,
    iPrivilegeUse_NonSensitive,
    iPrivilegeUse_Others,

    iDetailedTracking_ProcessCreation,
    iDetailedTracking_ProcessTermination,
    iDetailedTracking_DpapiActivity,
    iDetailedTracking_RpcCall,
    iDetailedTracking_PnpActivity,
    iDetailedTracking_TokenRightAdjusted,

    iPolicyChange_AuditPolicy,
    iPolicyChange_AuthenticationPolicy,
    iPolicyChange_AuthorizationPolicy,
    iPolicyChange_MpsscvRulePolicy,
    iPolicyChange_WfpIPSecPolicy,
    iPolicyChange_Others,

    iAccountManagement_UserAccount,
    iAccountManagement_ComputerAccount,
    iAccountManagement_SecurityGroup,
    iAccountManagement_DistributionGroup,
    iAccountManagement_ApplicationGroup,
    iAccountManagement_Others,

    iDSAccess_DSAccess,
    iDSAccess_AdAuditChanges,
    iDS_Replication,
    iDS_DetailedReplication,

    iAccountLogon_CredentialValidation,
    iAccountLogon_Kerberos,
    iAccountLogon_Others,
    iAccountLogon_KerbCredentialValidation,

    iUnknownSubCategory = 999

} POLICY_AUDIT_EVENT_TYPE_EX, *PPOLICY_AUDIT_EVENT_TYPE_EX;

// begin_ntsecapi

//
// Audit Event Categories
//
// The following are the built-in types or Categories of audit event.
// WARNING!  This structure is subject to expansion.  The user should not
// compute the number of elements of this type directly, but instead
// should obtain the count of elements by calling LsaQueryInformationPolicy()
// for the PolicyAuditEventsInformation class and extracting the count from
// the MaximumAuditEventCount field of the returned structure.
//

typedef enum _POLICY_AUDIT_EVENT_TYPE {

    AuditCategorySystem = 0,
    AuditCategoryLogon,
    AuditCategoryObjectAccess,
    AuditCategoryPrivilegeUse,
    AuditCategoryDetailedTracking,
    AuditCategoryPolicyChange,
    AuditCategoryAccountManagement,
    AuditCategoryDirectoryServiceAccess,
    AuditCategoryAccountLogon

} POLICY_AUDIT_EVENT_TYPE, *PPOLICY_AUDIT_EVENT_TYPE;


//
// The following defines describe the auditing options for each
// event type
//

// Leave options specified for this event unchanged

#define POLICY_AUDIT_EVENT_UNCHANGED       (0x00000000L)

// Audit successful occurrences of events of this type

#define POLICY_AUDIT_EVENT_SUCCESS         (0x00000001L)

// Audit failed attempts to cause an event of this type to occur

#define POLICY_AUDIT_EVENT_FAILURE         (0x00000002L)

#define POLICY_AUDIT_EVENT_NONE            (0x00000004L)

// Mask of valid event auditing options

#define POLICY_AUDIT_EVENT_MASK \
    (POLICY_AUDIT_EVENT_SUCCESS | \
     POLICY_AUDIT_EVENT_FAILURE | \
     POLICY_AUDIT_EVENT_UNCHANGED | \
     POLICY_AUDIT_EVENT_NONE)

#ifndef _NTDEF_
#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif
#endif  // _NTDEF_
// end_ntsecapi

// begin_ntsecapi

//
// Macro for determining whether an API succeeded.
//

#define LSA_SUCCESS(Error) ((LONG)(Error) >= 0)

// end_ntsecapi



/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Services provided for use by logon processes                        //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// begin_ntsecapi
#ifndef _NTLSA_IFS_
// begin_ntifs

_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
LsaRegisterLogonProcess (
    _In_ PLSA_STRING LogonProcessName,
    _Out_ PHANDLE LsaHandle,
    _Out_ PLSA_OPERATIONAL_MODE SecurityMode
    );

//
// The function below did not exist in NTIFS before windows XP
// However, the function has always been there, so it is okay to use
// even on w2k
//
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
LsaLogonUser (
    _In_        HANDLE          LsaHandle,
    _In_        PLSA_STRING     OriginName,
    _In_        SECURITY_LOGON_TYPE LogonType,
    _In_        ULONG           AuthenticationPackage,
    _In_reads_bytes_(AuthenticationInformationLength) PVOID AuthenticationInformation,
    _In_        ULONG           AuthenticationInformationLength,
    _In_opt_    PTOKEN_GROUPS   LocalGroups,
    _In_        PTOKEN_SOURCE   SourceContext,
    _Out_       PVOID           *ProfileBuffer,
    _Out_       PULONG          ProfileBufferLength,
    _Inout_     PLUID           LogonId,
    _Out_       PHANDLE         Token,
    _Out_       PQUOTA_LIMITS   Quotas,
    _Out_       PNTSTATUS       SubStatus
    );

// end_ntifs

_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
LsaLookupAuthenticationPackage (
    _In_ HANDLE LsaHandle,
    _In_ PLSA_STRING PackageName,
    _Out_ PULONG AuthenticationPackage
    );

// begin_ntifs

_IRQL_requires_same_
NTSTATUS
NTAPI
LsaFreeReturnBuffer (
    _In_ PVOID Buffer
    );

// end_ntifs

_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
LsaCallAuthenticationPackage (
    _In_ HANDLE LsaHandle,
    _In_ ULONG AuthenticationPackage,
    _In_reads_bytes_(SubmitBufferLength) PVOID ProtocolSubmitBuffer,
    _In_ ULONG SubmitBufferLength,
    _Outptr_opt_result_buffer_maybenull_(*ReturnBufferLength) PVOID *ProtocolReturnBuffer,
    _Out_opt_ PULONG ReturnBufferLength,
    _Out_opt_ PNTSTATUS ProtocolStatus
    );

_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
LsaDeregisterLogonProcess (
    _In_ HANDLE LsaHandle
    );

_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
LsaConnectUntrusted (
    _Out_ PHANDLE LsaHandle
    );

__drv_sameIRQL
NTSTATUS
LsaInsertProtectedProcessAddress (
    __in PVOID BufferAddress,
    __in ULONG BufferSize
    );

__drv_sameIRQL
NTSTATUS
LsaRemoveProtectedProcessAddress (
    __in PVOID BufferAddress,
    __in ULONG BufferSize
    );

#endif // _NTLSA_IFS_

// end_ntsecapi

typedef NTSTATUS
(NTAPI *PFN_LSA_CALL_AUTH_PKG) (
    _In_ HANDLE LsaHandle,
    _In_ ULONG AuthenticationPackage,
    _In_reads_bytes_(SubmitBufferLength) PVOID ProtocolSubmitBuffer,
    _In_ ULONG SubmitBufferLength,
    _Out_opt_ PVOID *ProtocolReturnBuffer,
    _Out_opt_ PULONG ReturnBufferLength,
    _Out_opt_ PNTSTATUS ProtocolStatus
    );

typedef NTSTATUS
(NTAPI *PFN_LSA_DEREGISTER_PROC) (
    _In_ HANDLE LsaHandle
    );

typedef NTSTATUS
(NTAPI *PFN_LSA_FREE_BUFFER) (
    _In_ PVOID Buffer
    );

typedef NTSTATUS
(NTAPI *PFN_LSA_LOGON_USER) (
    _In_ HANDLE LsaHandle,
    _In_ PLSA_STRING OriginName,
    _In_ SECURITY_LOGON_TYPE LogonType,
    _In_ ULONG AuthenticationPackage,
    _In_reads_bytes_(AuthenticationInformationLength) PVOID AuthenticationInformation,
    _In_ ULONG AuthenticationInformationLength,
    _In_opt_ PTOKEN_GROUPS LocalGroups,
    _In_ PTOKEN_SOURCE SourceContext,
    _Out_ PVOID *ProfileBuffer,
    _Out_ PULONG ProfileBufferLength,
    _Out_ PLUID LogonId,
    _Out_ PHANDLE Token,
    _Out_ PQUOTA_LIMITS Quotas,
    _Out_ PNTSTATUS SubStatus
    );

typedef NTSTATUS
(NTAPI *PFN_LOOKUP_AUTH_PKG) (
    _In_ HANDLE LsaHandle,
    _In_ PLSA_STRING PackageName,
    _Out_ PULONG AuthenticationPackage
    );

typedef NTSTATUS
(NTAPI *PFN_LSA_REGISTER_PROC) (
    _In_ PLSA_STRING LogonProcessName,
    _Out_ PHANDLE LsaHandle,
    _Out_ PLSA_OPERATIONAL_MODE SecurityMode
    );

typedef struct _LSA_AUTH_CALLBACKS {
    PFN_LSA_CALL_AUTH_PKG       LsaCallAuthPkgFn;
    PFN_LSA_DEREGISTER_PROC     LsaDeregisterProcFn;
    PFN_LSA_FREE_BUFFER         LsaFreeReturnBufferFn;
    PFN_LSA_LOGON_USER          LsaLogonUserFn;
    PFN_LOOKUP_AUTH_PKG         LsaLookupAuthPkgFn;
    PFN_LSA_REGISTER_PROC       LsaRegisterProcFn;
} LSA_AUTH_CALLBACKS, *PLSA_AUTH_CALLBACKS;

typedef CONST LSA_AUTH_CALLBACKS *PCLSA_AUTH_CALLBACKS;

// begin_ntsecpkg

/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Data types used by authentication packages                          //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

//
// opaque data type which represents a client request
//

typedef PVOID *PLSA_CLIENT_REQUEST;


//
// When a logon of a user is requested, the authentication package
// is expected to return one of the following structures indicating
// the contents of a user's token.
//

typedef enum _LSA_TOKEN_INFORMATION_TYPE {
    LsaTokenInformationNull,  // Implies LSA_TOKEN_INFORMATION_NULL data type
    LsaTokenInformationV1,    // Implies LSA_TOKEN_INFORMATION_V1 data type
    LsaTokenInformationV2,    // Implies LSA_TOKEN_INFORMATION_V2 data type
    LsaTokenInformationV3     // Implies LSA_TOKEN_INFORMATION_V3 data type
} LSA_TOKEN_INFORMATION_TYPE, *PLSA_TOKEN_INFORMATION_TYPE;


//
// The NULL information is used in cases where a non-authenticated
// system access is needed.  For example, a non-authentication network
// circuit (such as LAN Manager's null session) can be given NULL
// information.  This will result in an anonymous token being generated
// for the logon that gives the user no ability to access protected system
// resources, but does allow access to non-protected system resources.
//

typedef struct _LSA_TOKEN_INFORMATION_NULL {

    //
    // Time at which the security context becomes invalid.
    // Use a value in the distant future if the context
    // never expires.
    //

    LARGE_INTEGER ExpirationTime;

    //
    // The SID(s) of groups the user is to be made a member of.  This should
    // not include WORLD or other system defined and assigned
    // SIDs.  These will be added automatically by LSA.
    //
    // Each SID is expected to be in a separately allocated block
    // of memory.  The TOKEN_GROUPS structure is also expected to
    // be in a separately allocated block of memory.
    //

    PTOKEN_GROUPS Groups;

} LSA_TOKEN_INFORMATION_NULL, *PLSA_TOKEN_INFORMATION_NULL;


//
// The V1 token information structure is superceeded by the V2 token
// information structure.  The V1 strucure should only be used for
// backwards compatability.
// This structure contains information that an authentication package
// can place in a Version 1 NT token object.
//
// Do not make any changes to this structure without also updating
// the V3 structure below.
//

typedef struct _LSA_TOKEN_INFORMATION_V1 {

    //
    // Time at which the security context becomes invalid.
    // Use a value in the distant future if the context
    // never expires.
    //

    LARGE_INTEGER ExpirationTime;

    //
    // The SID of the user logging on.  The SID value is in a
    // separately allocated block of memory.
    //

    TOKEN_USER User;

    //
    // The SID(s) of groups the user is a member of.  This should
    // not include WORLD or other system defined and assigned
    // SIDs.  These will be added automatically by LSA.
    //
    // Each SID is expected to be in a separately allocated block
    // of memory.  The TOKEN_GROUPS structure is also expected to
    // be in a separately allocated block of memory.
    //

    PTOKEN_GROUPS Groups;

    //
    // This field is used to establish the primary group of the user.
    // This value does not have to correspond to one of the SIDs
    // assigned to the user.
    //
    // The SID pointed to by this structure is expected to be in
    // a separately allocated block of memory.
    //
    // This field is mandatory and must be filled in.
    //

    TOKEN_PRIMARY_GROUP PrimaryGroup;

    //
    // The privileges the user is assigned.  This list of privileges
    // will be augmented or over-ridden by any local security policy
    // assigned privileges.
    //
    // Each privilege is expected to be in a separately allocated
    // block of memory.  The TOKEN_PRIVILEGES structure is also
    // expected to be in a separately allocated block of memory.
    //
    // If there are no privileges to assign to the user, this field
    // may be set to NULL.
    //

    PTOKEN_PRIVILEGES Privileges;

    //
    // This field may be used to establish an explicit default
    // owner.  Normally, the user ID is used as the default owner.
    // If another value is desired, it must be specified here.
    //
    // The Owner.Sid field may be set to NULL to indicate there is no
    // alternate default owner value.
    //

    TOKEN_OWNER Owner;

    //
    // This field may be used to establish a default
    // protection for the user.  If no value is provided, then
    // a default protection that grants everyone all access will
    // be established.
    //
    // The DefaultDacl.DefaultDacl field may be set to NULL to indicate
    // there is no default protection.
    //

    TOKEN_DEFAULT_DACL DefaultDacl;

} LSA_TOKEN_INFORMATION_V1, *PLSA_TOKEN_INFORMATION_V1;

//
// The V2 information is used in most cases of logon.  The structure is identical
// to the V1 token information structure, with the exception that the memory allocation
// is handled differently.  The LSA_TOKEN_INFORMATION_V2 structure is intended to be
// allocated monolithiclly, with the privileges, DACL, sids, and group array either part of
// same allocation, or allocated and freed externally.
//

typedef LSA_TOKEN_INFORMATION_V1 LSA_TOKEN_INFORMATION_V2, *PLSA_TOKEN_INFORMATION_V2;

//
// The V3 token information structure adds claims support to the LSA token.  LSA assumes
// that the first fields in this structure are identical to those in LSA_TOKEN_INFORMATION_V1,
// so no changes should be made that are not reflected there as well.
//

typedef struct _LSA_TOKEN_INFORMATION_V3 {

    //
    // Time at which the security context becomes invalid.
    // Use a value in the distant future if the context
    // never expires.
    //

    LARGE_INTEGER ExpirationTime;

    //
    // The SID of the user logging on.  The SID value is in a
    // separately allocated block of memory.
    //

    TOKEN_USER User;

    //
    // The SID(s) of groups the user is a member of.  This should
    // not include WORLD or other system defined and assigned
    // SIDs.  These will be added automatically by LSA.
    //
    // Each SID is expected to be in a separately allocated block
    // of memory.  The TOKEN_GROUPS structure is also expected to
    // be in a separately allocated block of memory.
    //

    PTOKEN_GROUPS Groups;

    //
    // This field is used to establish the primary group of the user.
    // This value does not have to correspond to one of the SIDs
    // assigned to the user.
    //
    // The SID pointed to by this structure is expected to be in
    // a separately allocated block of memory.
    //
    // This field is mandatory and must be filled in.
    //

    TOKEN_PRIMARY_GROUP PrimaryGroup;

    //
    // The privileges the user is assigned.  This list of privileges
    // will be augmented or over-ridden by any local security policy
    // assigned privileges.
    //
    // Each privilege is expected to be in a separately allocated
    // block of memory.  The TOKEN_PRIVILEGES structure is also
    // expected to be in a separately allocated block of memory.
    //
    // If there are no privileges to assign to the user, this field
    // may be set to NULL.
    //

    PTOKEN_PRIVILEGES Privileges;

    //
    // This field may be used to establish an explicit default
    // owner.  Normally, the user ID is used as the default owner.
    // If another value is desired, it must be specified here.
    //
    // The Owner.Sid field may be set to NULL to indicate there is no
    // alternate default owner value.
    //

    TOKEN_OWNER Owner;

    //
    // This field may be used to establish a default
    // protection for the user.  If no value is provided, then
    // a default protection that grants everyone all access will
    // be established.
    //
    // The DefaultDacl.DefaultDacl field may be set to NULL to indicate
    // there is no default protection.
    //

    TOKEN_DEFAULT_DACL DefaultDacl;

    //
    // Note: do not change any fields above this comment without updating
    // the V1 structure as well!
    //

    //
    // This field stores the opaque user claims blob for the token. NULL
    // claims is valid, and indicates no additional user claims are present
    // in the token.  Claims are allow-only entities, and as such omitting
    // claims may restrict access.
    //

    TOKEN_USER_CLAIMS UserClaims;

    //
    // This field stores the opaque device claims blob for the token. Semantics
    // here are identical to user claims above.
    //

    TOKEN_DEVICE_CLAIMS DeviceClaims;

    //
    // The SID(s) of groups the authenticating device is a member of.  As with
    // user groups, this should not include WORLD or other system defined and
    // assigned SIDs.  NULL DeviceGroups is valid, and indicates that no compounding
    // should occur.  If DeviceGroups are present, LSA will add WORLD and other assigned
    // SIDs.
    //
    // Unlike user groups, there is no notion of a primary device group.
    //
    // Each SID is expected to be in a separately allocated block
    // of memory.  The TOKEN_GROUPS structure is also expected to
    // be in a separately allocated block of memory.
    //

    PTOKEN_GROUPS DeviceGroups;

} LSA_TOKEN_INFORMATION_V3, *PLSA_TOKEN_INFORMATION_V3;

/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Interface definitions available for use by authentication packages  //
//                                                                     //
/////////////////////////////////////////////////////////////////////////



typedef NTSTATUS
(NTAPI LSA_CREATE_LOGON_SESSION) (
    _Inout_ PLUID LogonId
    );

typedef NTSTATUS
(NTAPI LSA_DELETE_LOGON_SESSION) (
    _In_ PLUID LogonId
    );

typedef NTSTATUS
(NTAPI LSA_ADD_CREDENTIAL) (
    _In_ PLUID LogonId,
    _In_ ULONG AuthenticationPackage,
    _In_ PLSA_STRING PrimaryKeyValue,
    _In_ PLSA_STRING Credentials
    );

typedef NTSTATUS
(NTAPI LSA_GET_CREDENTIALS) (
    _In_ PLUID LogonId,
    _In_ ULONG AuthenticationPackage,
    _Inout_ PULONG QueryContext,
    _In_ BOOLEAN RetrieveAllCredentials,
    _In_ PLSA_STRING PrimaryKeyValue,
    _Out_ PULONG PrimaryKeyLength,
    _In_ PLSA_STRING Credentials
    );

typedef NTSTATUS
(NTAPI LSA_DELETE_CREDENTIAL) (
    _In_ PLUID LogonId,
    _In_ ULONG AuthenticationPackage,
    _In_ PLSA_STRING PrimaryKeyValue
    );

typedef PVOID
(NTAPI LSA_ALLOCATE_LSA_HEAP) (
    _In_ ULONG Length
    );

typedef VOID
(NTAPI LSA_FREE_LSA_HEAP) (
    _In_ PVOID Base
    );

typedef PVOID
(NTAPI LSA_ALLOCATE_PRIVATE_HEAP) (
    _In_ SIZE_T Length
    );

typedef VOID
(NTAPI LSA_FREE_PRIVATE_HEAP) (
    _In_ PVOID Base
    );

typedef NTSTATUS
(NTAPI LSA_ALLOCATE_CLIENT_BUFFER) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_ ULONG LengthRequired,
    _Outptr_result_bytebuffer_(LengthRequired) PVOID *ClientBaseAddress
    );

typedef NTSTATUS
(NTAPI LSA_FREE_CLIENT_BUFFER) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_ PVOID ClientBaseAddress
    );

typedef NTSTATUS
(NTAPI LSA_COPY_TO_CLIENT_BUFFER) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_ ULONG Length,
    _Out_writes_bytes_(Length) PVOID ClientBaseAddress,
    _In_reads_bytes_(Length) PVOID BufferToCopy
    );

typedef NTSTATUS
(NTAPI LSA_COPY_FROM_CLIENT_BUFFER) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_ ULONG Length,
    _Out_writes_bytes_(Length) PVOID BufferToCopy,
    _In_reads_bytes_(Length) PVOID ClientBaseAddress
    );

typedef LSA_CREATE_LOGON_SESSION * PLSA_CREATE_LOGON_SESSION;
typedef LSA_DELETE_LOGON_SESSION * PLSA_DELETE_LOGON_SESSION;
typedef LSA_ADD_CREDENTIAL * PLSA_ADD_CREDENTIAL;
typedef LSA_GET_CREDENTIALS * PLSA_GET_CREDENTIALS;
typedef LSA_DELETE_CREDENTIAL * PLSA_DELETE_CREDENTIAL;
typedef LSA_ALLOCATE_LSA_HEAP * PLSA_ALLOCATE_LSA_HEAP;
typedef LSA_FREE_LSA_HEAP * PLSA_FREE_LSA_HEAP;
typedef LSA_ALLOCATE_PRIVATE_HEAP * PLSA_ALLOCATE_PRIVATE_HEAP;
typedef LSA_FREE_PRIVATE_HEAP * PLSA_FREE_PRIVATE_HEAP;
typedef LSA_ALLOCATE_CLIENT_BUFFER * PLSA_ALLOCATE_CLIENT_BUFFER;
typedef LSA_FREE_CLIENT_BUFFER * PLSA_FREE_CLIENT_BUFFER;
typedef LSA_COPY_TO_CLIENT_BUFFER * PLSA_COPY_TO_CLIENT_BUFFER;
typedef LSA_COPY_FROM_CLIENT_BUFFER * PLSA_COPY_FROM_CLIENT_BUFFER;

//
// The dispatch table of LSA services which are available to
// authentication packages.
//
typedef struct _LSA_DISPATCH_TABLE {
    PLSA_CREATE_LOGON_SESSION CreateLogonSession;
    PLSA_DELETE_LOGON_SESSION DeleteLogonSession;
    PLSA_ADD_CREDENTIAL AddCredential;
    PLSA_GET_CREDENTIALS GetCredentials;
    PLSA_DELETE_CREDENTIAL DeleteCredential;
    PLSA_ALLOCATE_LSA_HEAP AllocateLsaHeap;
    PLSA_FREE_LSA_HEAP FreeLsaHeap;
    PLSA_ALLOCATE_CLIENT_BUFFER AllocateClientBuffer;
    PLSA_FREE_CLIENT_BUFFER FreeClientBuffer;
    PLSA_COPY_TO_CLIENT_BUFFER CopyToClientBuffer;
    PLSA_COPY_FROM_CLIENT_BUFFER CopyFromClientBuffer;
} LSA_DISPATCH_TABLE, *PLSA_DISPATCH_TABLE;



////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Interface definitions of services provided by authentication packages  //
//                                                                        //
////////////////////////////////////////////////////////////////////////////



//
// Routine names
//
// The routines provided by the DLL must be assigned the following names
// so that their addresses can be retrieved when the DLL is loaded.
//

#define LSA_AP_NAME_INITIALIZE_PACKAGE      "LsaApInitializePackage\0"
#define LSA_AP_NAME_LOGON_USER              "LsaApLogonUser\0"
#define LSA_AP_NAME_LOGON_USER_EX           "LsaApLogonUserEx\0"
#define LSA_AP_NAME_CALL_PACKAGE            "LsaApCallPackage\0"
#define LSA_AP_NAME_LOGON_TERMINATED        "LsaApLogonTerminated\0"
#define LSA_AP_NAME_CALL_PACKAGE_UNTRUSTED  "LsaApCallPackageUntrusted\0"
#define LSA_AP_NAME_CALL_PACKAGE_PASSTHROUGH "LsaApCallPackagePassthrough\0"


//
// Routine templates
//


typedef NTSTATUS
(NTAPI LSA_AP_INITIALIZE_PACKAGE) (
    _In_ ULONG AuthenticationPackageId,
    _In_ PLSA_DISPATCH_TABLE LsaDispatchTable,
    _In_opt_ PLSA_STRING Database,
    _In_opt_ PLSA_STRING Confidentiality,
    _Out_ PLSA_STRING *AuthenticationPackageName
    );

typedef NTSTATUS
(NTAPI LSA_AP_LOGON_USER) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_ SECURITY_LOGON_TYPE LogonType,
    _In_reads_bytes_(AuthenticationInformationLength) PVOID AuthenticationInformation,
    _In_ PVOID ClientAuthenticationBase,
    _In_ ULONG AuthenticationInformationLength,
    _Outptr_result_bytebuffer_(*ProfileBufferLength) PVOID *ProfileBuffer,
    _Out_ PULONG ProfileBufferLength,
    _Out_ PLUID LogonId,
    _Out_ PNTSTATUS SubStatus,
    _Out_ PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
    _Outptr_ PVOID *TokenInformation,
    _Out_ PLSA_UNICODE_STRING *AccountName,
    _Out_ PLSA_UNICODE_STRING *AuthenticatingAuthority
    );

typedef NTSTATUS
(NTAPI LSA_AP_LOGON_USER_EX) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_ SECURITY_LOGON_TYPE LogonType,
    _In_reads_bytes_(AuthenticationInformationLength) PVOID AuthenticationInformation,
    _In_ PVOID ClientAuthenticationBase,
    _In_ ULONG AuthenticationInformationLength,
    _Outptr_result_bytebuffer_(*ProfileBufferLength) PVOID *ProfileBuffer,
    _Out_ PULONG ProfileBufferLength,
    _Out_ PLUID LogonId,
    _Out_ PNTSTATUS SubStatus,
    _Out_ PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
    _Outptr_ PVOID *TokenInformation,
    _Out_ PUNICODE_STRING *AccountName,
    _Out_ PUNICODE_STRING *AuthenticatingAuthority,
    _Out_ PUNICODE_STRING *MachineName
    );

typedef NTSTATUS
(NTAPI LSA_AP_CALL_PACKAGE) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_reads_bytes_(SubmitBufferLength) PVOID ProtocolSubmitBuffer,
    _In_ PVOID ClientBufferBase,
    _In_ ULONG SubmitBufferLength,
    _Outptr_result_bytebuffer_(*ReturnBufferLength) PVOID *ProtocolReturnBuffer,
    _Out_ PULONG ReturnBufferLength,
    _Out_ PNTSTATUS ProtocolStatus
    );

typedef NTSTATUS
(NTAPI LSA_AP_CALL_PACKAGE_PASSTHROUGH) (
    _In_ PLSA_CLIENT_REQUEST ClientRequest,
    _In_reads_bytes_(SubmitBufferLength) PVOID ProtocolSubmitBuffer,
    _In_ PVOID ClientBufferBase,
    _In_ ULONG SubmitBufferLength,
    _Outptr_result_bytebuffer_(*ReturnBufferLength) PVOID *ProtocolReturnBuffer,
    _Out_ PULONG ReturnBufferLength,
    _Out_ PNTSTATUS ProtocolStatus
    );

typedef VOID
(NTAPI LSA_AP_LOGON_TERMINATED) (
    _In_ PLUID LogonId
    );

typedef LSA_AP_CALL_PACKAGE LSA_AP_CALL_PACKAGE_UNTRUSTED;

typedef LSA_AP_INITIALIZE_PACKAGE * PLSA_AP_INITIALIZE_PACKAGE;
typedef LSA_AP_LOGON_USER * PLSA_AP_LOGON_USER;
typedef LSA_AP_LOGON_USER_EX * PLSA_AP_LOGON_USER_EX;
typedef LSA_AP_CALL_PACKAGE * PLSA_AP_CALL_PACKAGE;
typedef LSA_AP_CALL_PACKAGE_PASSTHROUGH * PLSA_AP_CALL_PACKAGE_PASSTHROUGH;
typedef LSA_AP_LOGON_TERMINATED * PLSA_AP_LOGON_TERMINATED;
typedef LSA_AP_CALL_PACKAGE_UNTRUSTED * PLSA_AP_CALL_PACKAGE_UNTRUSTED;

// end_ntsecpkg
// begin_ntsecapi

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Local Security Policy Administration API datatypes and defines         //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

//
// Access types for the Policy object
//

#define POLICY_VIEW_LOCAL_INFORMATION              0x00000001L
#define POLICY_VIEW_AUDIT_INFORMATION              0x00000002L
#define POLICY_GET_PRIVATE_INFORMATION             0x00000004L
#define POLICY_TRUST_ADMIN                         0x00000008L
#define POLICY_CREATE_ACCOUNT                      0x00000010L
#define POLICY_CREATE_SECRET                       0x00000020L
#define POLICY_CREATE_PRIVILEGE                    0x00000040L
#define POLICY_SET_DEFAULT_QUOTA_LIMITS            0x00000080L
#define POLICY_SET_AUDIT_REQUIREMENTS              0x00000100L
#define POLICY_AUDIT_LOG_ADMIN                     0x00000200L
#define POLICY_SERVER_ADMIN                        0x00000400L
#define POLICY_LOOKUP_NAMES                        0x00000800L
#define POLICY_NOTIFICATION                        0x00001000L

#define POLICY_ALL_ACCESS     (STANDARD_RIGHTS_REQUIRED         |\
                               POLICY_VIEW_LOCAL_INFORMATION    |\
                               POLICY_VIEW_AUDIT_INFORMATION    |\
                               POLICY_GET_PRIVATE_INFORMATION   |\
                               POLICY_TRUST_ADMIN               |\
                               POLICY_CREATE_ACCOUNT            |\
                               POLICY_CREATE_SECRET             |\
                               POLICY_CREATE_PRIVILEGE          |\
                               POLICY_SET_DEFAULT_QUOTA_LIMITS  |\
                               POLICY_SET_AUDIT_REQUIREMENTS    |\
                               POLICY_AUDIT_LOG_ADMIN           |\
                               POLICY_SERVER_ADMIN              |\
                               POLICY_LOOKUP_NAMES)


#define POLICY_READ           (STANDARD_RIGHTS_READ             |\
                               POLICY_VIEW_AUDIT_INFORMATION    |\
                               POLICY_GET_PRIVATE_INFORMATION)

#define POLICY_WRITE          (STANDARD_RIGHTS_WRITE            |\
                               POLICY_TRUST_ADMIN               |\
                               POLICY_CREATE_ACCOUNT            |\
                               POLICY_CREATE_SECRET             |\
                               POLICY_CREATE_PRIVILEGE          |\
                               POLICY_SET_DEFAULT_QUOTA_LIMITS  |\
                               POLICY_SET_AUDIT_REQUIREMENTS    |\
                               POLICY_AUDIT_LOG_ADMIN           |\
                               POLICY_SERVER_ADMIN)

#define POLICY_EXECUTE        (STANDARD_RIGHTS_EXECUTE          |\
                               POLICY_VIEW_LOCAL_INFORMATION    |\
                               POLICY_LOOKUP_NAMES)


//
// Legacy policy object specific data types.
//
// The following data type is used in name to SID lookup services to describe
// the domains referenced in the lookup operation.
//

typedef struct _LSA_TRANSLATED_SID {

    SID_NAME_USE Use;
    ULONG RelativeId;
    LONG DomainIndex;

} LSA_TRANSLATED_SID, *PLSA_TRANSLATED_SID;

// where members have the following usage:
//
//     Use - identifies the use of the SID.  If this value is SidUnknown or
//         SidInvalid, then the remainder of the record is not set and
//         should be ignored.
//
//     RelativeId - Contains the relative ID of the translated SID.  The
//         remainder of the SID (the prefix) is obtained using the
//         DomainIndex field.
//
//     DomainIndex - Is the index of an entry in a related
//         LSA_REFERENCED_DOMAIN_LIST data structure describing the
//         domain in which the account was found.
//
//         If there is no corresponding reference domain for an entry, then
//         this field will contain a negative value.
//

// end_ntsecapi

//
// The following data type specifies the ways in which a user or member of
// an alias or group may be allowed to access the system.  An account may
// be granted zero or more of these types of access to the system.
//
// The types of access are:
//
//     Interactive - The user or alias/group member may interactively logon
//         to the system.
//
//     Network - The user or alias/group member may access the system via
//         the network (e.g., through shares).
//
//     Service - The user or alias may be activated as a service on the
//         system.
//

typedef ULONG POLICY_SYSTEM_ACCESS_MODE, *PPOLICY_SYSTEM_ACCESS_MODE;

#define POLICY_MODE_INTERACTIVE             SECURITY_ACCESS_INTERACTIVE_LOGON
#define POLICY_MODE_NETWORK                 SECURITY_ACCESS_NETWORK_LOGON
#define POLICY_MODE_BATCH                   SECURITY_ACCESS_BATCH_LOGON
#define POLICY_MODE_SERVICE                 SECURITY_ACCESS_SERVICE_LOGON
#define POLICY_MODE_PROXY                   SECURITY_ACCESS_PROXY_LOGON
#define POLICY_MODE_DENY_INTERACTIVE        SECURITY_ACCESS_DENY_INTERACTIVE_LOGON
#define POLICY_MODE_DENY_NETWORK            SECURITY_ACCESS_DENY_NETWORK_LOGON
#define POLICY_MODE_DENY_BATCH              SECURITY_ACCESS_DENY_BATCH_LOGON
#define POLICY_MODE_DENY_SERVICE            SECURITY_ACCESS_DENY_SERVICE_LOGON
#define POLICY_MODE_REMOTE_INTERACTIVE      SECURITY_ACCESS_REMOTE_INTERACTIVE_LOGON
#define POLICY_MODE_DENY_REMOTE_INTERACTIVE SECURITY_ACCESS_DENY_REMOTE_INTERACTIVE_LOGON

#define POLICY_MODE_ALL                     (POLICY_MODE_INTERACTIVE            | \
                                             POLICY_MODE_NETWORK                | \
                                             POLICY_MODE_BATCH                  | \
                                             POLICY_MODE_SERVICE                | \
                                             POLICY_MODE_PROXY                  | \
                                             POLICY_MODE_DENY_INTERACTIVE       | \
                                             POLICY_MODE_DENY_NETWORK           | \
                                             SECURITY_ACCESS_DENY_BATCH_LOGON   | \
                                             SECURITY_ACCESS_DENY_SERVICE_LOGON | \
                                             POLICY_MODE_REMOTE_INTERACTIVE     | \
                                             POLICY_MODE_DENY_REMOTE_INTERACTIVE )

//
// The following is the bits allowed in NT4.0
//
#define POLICY_MODE_ALL_NT4                 (POLICY_MODE_INTERACTIVE | \
                                             POLICY_MODE_NETWORK     | \
                                             POLICY_MODE_BATCH       | \
                                             POLICY_MODE_SERVICE     | \
                                             POLICY_MODE_PROXY )


// begin_ntsecapi

//
// The following data type is used to represent the role of the LSA
// server (primary or backup).
//

typedef enum _POLICY_LSA_SERVER_ROLE {

    PolicyServerRoleBackup = 2,
    PolicyServerRolePrimary

} POLICY_LSA_SERVER_ROLE, *PPOLICY_LSA_SERVER_ROLE;

#if (_WIN32_WINNT < 0x0502)
//
// The following data type is used to represent the state of the LSA
// server (enabled or disabled).  Some operations may only be performed on
// an enabled LSA server.
//

typedef enum _POLICY_SERVER_ENABLE_STATE {

    PolicyServerEnabled = 2,
    PolicyServerDisabled

} POLICY_SERVER_ENABLE_STATE, *PPOLICY_SERVER_ENABLE_STATE;
#endif

//
// The following data type is used to specify the auditing options for
// an Audit Event Type.
//

typedef ULONG POLICY_AUDIT_EVENT_OPTIONS, *PPOLICY_AUDIT_EVENT_OPTIONS;

// where the following flags can be set:
//
//     POLICY_AUDIT_EVENT_UNCHANGED - Leave existing auditing options
//         unchanged for events of this type.  This flag is only used for
//         set operations.  If this flag is set, then all other flags
//         are ignored.
//
//     POLICY_AUDIT_EVENT_NONE - Cancel all auditing options for events
//         of this type.  If this flag is set, the success/failure flags
//         are ignored.
//
//     POLICY_AUDIT_EVENT_SUCCESS - When auditing is enabled, audit all
//         successful occurrences of events of the given type.
//
//     POLICY_AUDIT_EVENT_FAILURE - When auditing is enabled, audit all
//         unsuccessful occurrences of events of the given type.
//



// end_ntsecapi

//
// The following data type is used to return information about privileges
// defined on a system.
//

typedef struct _POLICY_PRIVILEGE_DEFINITION {

    LSA_UNICODE_STRING Name;
    LUID LocalValue;

} POLICY_PRIVILEGE_DEFINITION, *PPOLICY_PRIVILEGE_DEFINITION;

//
// where the members have the following usage:
//
//     Name - Is the architected name of the privilege.  This is the
//         primary key of the privilege and the only value that is
//         transportable between systems.
//
//     Luid - is a LUID value assigned locally for efficient representation
//         of the privilege.  Ths value is meaningful only on the system it
//         was assigned on and is not transportable in any way.
//

//
// System Flags for LsaLookupNames2
//

//
// Note the flags start backward so that public values
// don't have gaps.
//

//
// This flag controls LsaLookupNames2 such that isolated names, including
// UPN's are not searched for off the machine.  Composite names
// (domain\username) are still sent off machine if necessary.
//
#define LSA_LOOKUP_ISOLATED_AS_LOCAL  0x80000000


//
// System Flags for LsaLookupSids2
//

//
// Note the flags start backward so that public values
// don't have gaps.
//

//
// This flag controls LsaLookupSids2 such that for internet SIDs 
// from identity providers for connected accounts are disallowed
// connected accounts are those accounts which have a corresponding
// shadow account in the local SAM database connected to
// an online identity provider
// (for example MicrosoftAccount is a connected account)
//
#define LSA_LOOKUP_DISALLOW_CONNECTED_ACCOUNT_INTERNET_SID  0x80000000

// This flag returns the internet names. Otherwise the NT4 style name eg. domain\username
// will be returned. The exception is if the MSA internet SID is specified
// then the internet name will be returned unless LSA_LOOKUP_DISALLOW_NON_WINDOWS_INTERNET_SID  
// is specified
#define LSA_LOOKUP_PREFER_INTERNET_NAMES  0x40000000 

// begin_ntsecapi

//
// The following data type defines the classes of Policy Information
// that may be queried/set.
//

typedef enum _POLICY_INFORMATION_CLASS {

    PolicyAuditLogInformation = 1,
    PolicyAuditEventsInformation,
    PolicyPrimaryDomainInformation,
    PolicyPdAccountInformation,
    PolicyAccountDomainInformation,
    PolicyLsaServerRoleInformation,
    PolicyReplicaSourceInformation,
    PolicyDefaultQuotaInformation,
    PolicyModificationInformation,
    PolicyAuditFullSetInformation,
    PolicyAuditFullQueryInformation,
    PolicyDnsDomainInformation,
    PolicyDnsDomainInformationInt,
    PolicyLocalAccountDomainInformation,
    PolicyMachineAccountInformation,
    PolicyLastEntry

} POLICY_INFORMATION_CLASS, *PPOLICY_INFORMATION_CLASS;


//
// The following data type corresponds to the PolicyAuditLogInformation
// information class.  It is used to represent information relating to
// the Audit Log.
//
// This structure may be used in both query and set operations.  However,
// when used in set operations, some fields are ignored.
//

typedef struct _POLICY_AUDIT_LOG_INFO {

    ULONG AuditLogPercentFull;
    ULONG MaximumLogSize;
    LARGE_INTEGER AuditRetentionPeriod;
    BOOLEAN AuditLogFullShutdownInProgress;
    LARGE_INTEGER TimeToShutdown;
    ULONG NextAuditRecordId;

} POLICY_AUDIT_LOG_INFO, *PPOLICY_AUDIT_LOG_INFO;

// where the members have the following usage:
//
//     AuditLogPercentFull - Indicates the percentage of the Audit Log
//         currently being used.
//
//     MaximumLogSize - Specifies the maximum size of the Audit Log in
//         kilobytes.
//
//     AuditRetentionPeriod - Indicates the length of time that Audit
//         Records are to be retained.  Audit Records are discardable
//         if their timestamp predates the current time minus the
//         retention period.
//
//     AuditLogFullShutdownInProgress - Indicates whether or not a system
//         shutdown is being initiated due to the security Audit Log becoming
//         full.  This condition will only occur if the system is configured
//         to shutdown when the log becomes full.
//
//         TRUE indicates that a shutdown is in progress
//         FALSE indicates that a shutdown is not in progress.
//
//         Once a shutdown has been initiated, this flag will be set to
//         TRUE.  If an administrator is able to currect the situation
//         before the shutdown becomes irreversible, then this flag will
//         be reset to false.
//
//         This field is ignored for set operations.
//
//     TimeToShutdown - If the AuditLogFullShutdownInProgress flag is set,
//         then this field contains the time left before the shutdown
//         becomes irreversible.
//
//         This field is ignored for set operations.
//


//
// The following data type corresponds to the PolicyAuditEventsInformation
// information class.  It is used to represent information relating to
// the audit requirements.
//

typedef struct _POLICY_AUDIT_EVENTS_INFO {

    BOOLEAN AuditingMode;
    PPOLICY_AUDIT_EVENT_OPTIONS EventAuditingOptions;
    ULONG MaximumAuditEventCount;

} POLICY_AUDIT_EVENTS_INFO, *PPOLICY_AUDIT_EVENTS_INFO;

// where the members have the following usage:
//
//     AuditingMode - A Boolean variable specifying the Auditing Mode value.
//         This value is interpreted as follows:
//
//         TRUE - Auditing is to be enabled (set operations) or is enabled
//             (query operations).  Audit Records will be generated according
//             to the Event Auditing Options in effect (see the
//             EventAuditingOptions field.
//
//         FALSE - Auditing is to be disabled (set operations) or is
//             disabled (query operations).  No Audit Records will be
//             generated.  Note that for set operations the Event Auditing
//             Options in effect will still be updated as specified by the
//             EventAuditingOptions field whether Auditing is enabled or
//             disabled.
//
//    EventAuditingOptions - Pointer to an array of Auditing Options
//        indexed by Audit Event Type.
//
//    MaximumAuditEventCount - Specifiesa count of the number of Audit
//        Event Types specified by the EventAuditingOptions parameter.  If
//        this count is less than the number of Audit Event Types supported
//        by the system, the Auditing Options for Event Types with IDs
//        higher than (MaximumAuditEventCount + 1) are left unchanged.
//


//
// The following data type is used to represent information relating to
// the audit requirements.
//

typedef struct _POLICY_AUDIT_SUBCATEGORIES_INFO {

    ULONG MaximumSubCategoryCount;
    PPOLICY_AUDIT_EVENT_OPTIONS EventAuditingOptions;

} POLICY_AUDIT_SUBCATEGORIES_INFO, *PPOLICY_AUDIT_SUBCATEGORIES_INFO;

typedef struct _POLICY_AUDIT_CATEGORIES_INFO {

    ULONG MaximumCategoryCount;
    PPOLICY_AUDIT_SUBCATEGORIES_INFO SubCategoriesInfo;

} POLICY_AUDIT_CATEGORIES_INFO, *PPOLICY_AUDIT_CATEGORIES_INFO;


//
// Valid bits for Per user policy mask.
//

#define PER_USER_POLICY_UNCHANGED               (0x00)
#define PER_USER_AUDIT_SUCCESS_INCLUDE          (0x01)
#define PER_USER_AUDIT_SUCCESS_EXCLUDE          (0x02)
#define PER_USER_AUDIT_FAILURE_INCLUDE          (0x04)
#define PER_USER_AUDIT_FAILURE_EXCLUDE          (0x08)
#define PER_USER_AUDIT_NONE                     (0x10)


#define VALID_PER_USER_AUDIT_POLICY_FLAG (PER_USER_AUDIT_SUCCESS_INCLUDE | \
                                          PER_USER_AUDIT_SUCCESS_EXCLUDE | \
                                          PER_USER_AUDIT_FAILURE_INCLUDE | \
                                          PER_USER_AUDIT_FAILURE_EXCLUDE | \
                                          PER_USER_AUDIT_NONE)


//
// The following structure corresponds to the PolicyPrimaryDomainInformation
// information class.
//

typedef struct _POLICY_PRIMARY_DOMAIN_INFO {

    LSA_UNICODE_STRING Name;
    PSID Sid;

} POLICY_PRIMARY_DOMAIN_INFO, *PPOLICY_PRIMARY_DOMAIN_INFO;

// where the members have the following usage:
//
//     Name - Is the name of the domain
//
//     Sid - Is the Sid of the domain
//


//
// The following structure corresponds to the PolicyPdAccountInformation
// information class.  This structure may be used in Query operations
// only.
//

typedef struct _POLICY_PD_ACCOUNT_INFO {

    LSA_UNICODE_STRING Name;

} POLICY_PD_ACCOUNT_INFO, *PPOLICY_PD_ACCOUNT_INFO;

// where the members have the following usage:
//
//     Name - Is the name of an account in the domain that should be used
//         for authentication and name/ID lookup requests.
//


//
// The following structure corresponds to the PolicyLsaServerRoleInformation
// information class.
//

typedef struct _POLICY_LSA_SERVER_ROLE_INFO {

    POLICY_LSA_SERVER_ROLE LsaServerRole;

} POLICY_LSA_SERVER_ROLE_INFO, *PPOLICY_LSA_SERVER_ROLE_INFO;

// where the fields have the following usage:
//
// TBS
//


//
// The following structure corresponds to the PolicyReplicaSourceInformation
// information class.
//

typedef struct _POLICY_REPLICA_SOURCE_INFO {

    LSA_UNICODE_STRING ReplicaSource;
    LSA_UNICODE_STRING ReplicaAccountName;

} POLICY_REPLICA_SOURCE_INFO, *PPOLICY_REPLICA_SOURCE_INFO;


//
// The following structure corresponds to the PolicyDefaultQuotaInformation
// information class.
//

typedef struct _POLICY_DEFAULT_QUOTA_INFO {

    QUOTA_LIMITS QuotaLimits;

} POLICY_DEFAULT_QUOTA_INFO, *PPOLICY_DEFAULT_QUOTA_INFO;


//
// The following structure corresponds to the PolicyModificationInformation
// information class.
//

typedef struct _POLICY_MODIFICATION_INFO {

    LARGE_INTEGER ModifiedId;
    LARGE_INTEGER DatabaseCreationTime;

} POLICY_MODIFICATION_INFO, *PPOLICY_MODIFICATION_INFO;

// where the members have the following usage:
//
//     ModifiedId - Is a 64-bit unsigned integer that is incremented each
//         time anything in the LSA database is modified.  This value is
//         only modified on Primary Domain Controllers.
//
//     DatabaseCreationTime - Is the date/time that the LSA Database was
//         created.  On Backup Domain Controllers, this value is replicated
//         from the Primary Domain Controller.
//

//
// The following structure type corresponds to the PolicyAuditFullSetInformation
// Information Class.
//

typedef struct _POLICY_AUDIT_FULL_SET_INFO {

    BOOLEAN ShutDownOnFull;

} POLICY_AUDIT_FULL_SET_INFO, *PPOLICY_AUDIT_FULL_SET_INFO;

//
// The following structure type corresponds to the PolicyAuditFullQueryInformation
// Information Class.
//

typedef struct _POLICY_AUDIT_FULL_QUERY_INFO {

    BOOLEAN ShutDownOnFull;
    BOOLEAN LogIsFull;

} POLICY_AUDIT_FULL_QUERY_INFO, *PPOLICY_AUDIT_FULL_QUERY_INFO;

//
// The following data type defines the classes of Policy Information
// that may be queried/set that has domain wide effect.
//

typedef enum _POLICY_DOMAIN_INFORMATION_CLASS {

#if (_WIN32_WINNT <= 0x0500)
    PolicyDomainQualityOfServiceInformation = 1,
#endif
    PolicyDomainEfsInformation = 2,
    PolicyDomainKerberosTicketInformation

} POLICY_DOMAIN_INFORMATION_CLASS, *PPOLICY_DOMAIN_INFORMATION_CLASS;

#if (_WIN32_WINNT < 0x0502)
//
// QualityOfService information.  Corresponds to PolicyDomainQualityOfServiceInformation
//

#define POLICY_QOS_SCHANNEL_REQUIRED            0x00000001
#define POLICY_QOS_OUTBOUND_INTEGRITY           0x00000002
#define POLICY_QOS_OUTBOUND_CONFIDENTIALITY     0x00000004
#define POLICY_QOS_INBOUND_INTEGRITY            0x00000008
#define POLICY_QOS_INBOUND_CONFIDENTIALITY      0x00000010
#define POLICY_QOS_ALLOW_LOCAL_ROOT_CERT_STORE  0x00000020
#define POLICY_QOS_RAS_SERVER_ALLOWED           0x00000040
#define POLICY_QOS_DHCP_SERVER_ALLOWED          0x00000080

//
// Bits 0x00000100 through 0xFFFFFFFF are reserved for future use.
//
#endif

#if (_WIN32_WINNT == 0x0500)
typedef struct _POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO {

    ULONG QualityOfService;

} POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO, *PPOLICY_DOMAIN_QUALITY_OF_SERVICE_INFO;
//
// where the members have the following usage:
//
//  QualityOfService - Determines what specific QOS actions a machine should take
//
#endif

//
// The following structure corresponds to the PolicyEfsInformation
// information class
//

typedef struct _POLICY_DOMAIN_EFS_INFO {

    ULONG   InfoLength;
    PUCHAR  EfsBlob;

} POLICY_DOMAIN_EFS_INFO, *PPOLICY_DOMAIN_EFS_INFO;

//
// where the members have the following usage:
//
//      InfoLength - Length of the EFS Information blob
//
//      EfsBlob - Efs blob data
//


//
// The following structure corresponds to the PolicyDomainKerberosTicketInformation
// information class
//

#define POLICY_KERBEROS_VALIDATE_CLIENT 0x00000080


typedef struct _POLICY_DOMAIN_KERBEROS_TICKET_INFO {

    ULONG AuthenticationOptions;
    LARGE_INTEGER MaxServiceTicketAge;
    LARGE_INTEGER MaxTicketAge;
    LARGE_INTEGER MaxRenewAge;
    LARGE_INTEGER MaxClockSkew;
    LARGE_INTEGER Reserved;
} POLICY_DOMAIN_KERBEROS_TICKET_INFO, *PPOLICY_DOMAIN_KERBEROS_TICKET_INFO;

//
// where the members have the following usage
//
//      AuthenticationOptions -- allowed ticket options (POLICY_KERBEROS_* flags )
//
//      MaxServiceTicketAge   -- Maximum lifetime for a service ticket
//
//      MaxTicketAge -- Maximum lifetime for the initial ticket
//
//      MaxRenewAge -- Maximum cumulative age a renewable ticket can be with
//                     requring authentication
//
//      MaxClockSkew -- Maximum tolerance for synchronization of computer clocks
//
//      Reserved   --  Reserved

//
// The following structure corresponds to the PolicyMachineAccountInformation
// information class.  Only valid when the machine is joined to an AD domain.
// When not joined, will return 0+NULL.
//
// Note, DN is not cached because it may change (if\when the account is
// moved within the domain tree).
//
typedef struct _POLICY_MACHINE_ACCT_INFO {

    ULONG Rid;
    PSID Sid;

} POLICY_MACHINE_ACCT_INFO, *PPOLICY_MACHINE_ACCT_INFO;

//
// The following data type defines the classes of Policy Information / Policy Domain Information
// that may be used to request notification
//

typedef enum _POLICY_NOTIFICATION_INFORMATION_CLASS {

    PolicyNotifyAuditEventsInformation = 1,
    PolicyNotifyAccountDomainInformation,
    PolicyNotifyServerRoleInformation,
    PolicyNotifyDnsDomainInformation,
    PolicyNotifyDomainEfsInformation,
    PolicyNotifyDomainKerberosTicketInformation,
    PolicyNotifyMachineAccountPasswordInformation,
    PolicyNotifyGlobalSaclInformation,
    PolicyNotifyMax // must always be the last entry

} POLICY_NOTIFICATION_INFORMATION_CLASS, *PPOLICY_NOTIFICATION_INFORMATION_CLASS;

// end_ntsecapi

//
// Account object type-specific Access Types
//

#define ACCOUNT_VIEW                          0x00000001L
#define ACCOUNT_ADJUST_PRIVILEGES             0x00000002L
#define ACCOUNT_ADJUST_QUOTAS                 0x00000004L
#define ACCOUNT_ADJUST_SYSTEM_ACCESS          0x00000008L

#define ACCOUNT_ALL_ACCESS    (STANDARD_RIGHTS_REQUIRED         |\
                               ACCOUNT_VIEW                     |\
                               ACCOUNT_ADJUST_PRIVILEGES        |\
                               ACCOUNT_ADJUST_QUOTAS            |\
                               ACCOUNT_ADJUST_SYSTEM_ACCESS)

#define ACCOUNT_READ          (STANDARD_RIGHTS_READ             |\
                               ACCOUNT_VIEW)

#define ACCOUNT_WRITE         (STANDARD_RIGHTS_WRITE            |\
                               ACCOUNT_ADJUST_PRIVILEGES        |\
                               ACCOUNT_ADJUST_QUOTAS            |\
                               ACCOUNT_ADJUST_SYSTEM_ACCESS)

#define ACCOUNT_EXECUTE       (STANDARD_RIGHTS_EXECUTE)

// begin_ntsecapi

//
// LSA RPC Context Handle (Opaque form).  Note that a Context Handle is
// always a pointer type unlike regular handles.
//

typedef PVOID LSA_HANDLE, *PLSA_HANDLE;

// end_ntsecapi

//
// Trusted Domain object specific access types
//

#define TRUSTED_QUERY_DOMAIN_NAME                 0x00000001L
#define TRUSTED_QUERY_CONTROLLERS                 0x00000002L
#define TRUSTED_SET_CONTROLLERS                   0x00000004L
#define TRUSTED_QUERY_POSIX                       0x00000008L
#define TRUSTED_SET_POSIX                         0x00000010L
#define TRUSTED_SET_AUTH                          0x00000020L
#define TRUSTED_QUERY_AUTH                        0x00000040L


#define TRUSTED_ALL_ACCESS     (STANDARD_RIGHTS_REQUIRED     |\
                                TRUSTED_QUERY_DOMAIN_NAME    |\
                                TRUSTED_QUERY_CONTROLLERS    |\
                                TRUSTED_SET_CONTROLLERS      |\
                                TRUSTED_QUERY_POSIX          |\
                                TRUSTED_SET_POSIX            |\
                                TRUSTED_SET_AUTH             |\
                                TRUSTED_QUERY_AUTH)

#define TRUSTED_READ           (STANDARD_RIGHTS_READ         |\
                                TRUSTED_QUERY_DOMAIN_NAME)

#define TRUSTED_WRITE          (STANDARD_RIGHTS_WRITE        |\
                                TRUSTED_SET_CONTROLLERS      |\
                                TRUSTED_SET_POSIX            |\
                                TRUSTED_SET_AUTH )

#define TRUSTED_EXECUTE        (STANDARD_RIGHTS_EXECUTE      |\
                                TRUSTED_QUERY_CONTROLLERS    |\
                                TRUSTED_QUERY_POSIX)



// begin_ntsecapi

//
// Trusted Domain Object specific data types
//

//
// This data type defines the following information classes that may be
// queried or set.
//

typedef enum _TRUSTED_INFORMATION_CLASS {

    TrustedDomainNameInformation = 1,
    TrustedControllersInformation,
    TrustedPosixOffsetInformation,
    TrustedPasswordInformation,
    TrustedDomainInformationBasic,
    TrustedDomainInformationEx,
    TrustedDomainAuthInformation,
    TrustedDomainFullInformation,
    TrustedDomainAuthInformationInternal,
    TrustedDomainFullInformationInternal,
    TrustedDomainInformationEx2Internal,
    TrustedDomainFullInformation2Internal,
    TrustedDomainSupportedEncryptionTypes,
} TRUSTED_INFORMATION_CLASS, *PTRUSTED_INFORMATION_CLASS;

//
// The following data type corresponds to the TrustedDomainNameInformation
// information class.
//

typedef struct _TRUSTED_DOMAIN_NAME_INFO {

    LSA_UNICODE_STRING Name;

} TRUSTED_DOMAIN_NAME_INFO, *PTRUSTED_DOMAIN_NAME_INFO;

// where members have the following meaning:
//
// Name - The name of the Trusted Domain.
//

//
// The following data type corresponds to the TrustedControllersInformation
// information class.
//

typedef struct _TRUSTED_CONTROLLERS_INFO {

    ULONG Entries;
    PLSA_UNICODE_STRING Names;

} TRUSTED_CONTROLLERS_INFO, *PTRUSTED_CONTROLLERS_INFO;

// where members have the following meaning:
//
// Entries - Indicate how mamy entries there are in the Names array.
//
// Names - Pointer to an array of LSA_UNICODE_STRING structures containing the
//     names of domain controllers of the domain.  This information may not
//     be accurate and should be used only as a hint.  The order of this
//     list is considered significant and will be maintained.
//
//     By convention, the first name in this list is assumed to be the
//     Primary Domain Controller of the domain.  If the Primary Domain
//     Controller is not known, the first name should be set to the NULL
//     string.
//


//
// The following data type corresponds to the TrustedPosixOffsetInformation
// information class.
//

typedef struct _TRUSTED_POSIX_OFFSET_INFO {

    ULONG Offset;

} TRUSTED_POSIX_OFFSET_INFO, *PTRUSTED_POSIX_OFFSET_INFO;

// where members have the following meaning:
//
// Offset - Is an offset to use for the generation of Posix user and group
//     IDs from SIDs.  The Posix ID corresponding to any particular SID is
//     generated by adding the RID of that SID to the Offset of the SID's
//     corresponding TrustedDomain object.
//

//
// The following data type corresponds to the TrustedPasswordInformation
// information class.
//

typedef struct _TRUSTED_PASSWORD_INFO {
    LSA_UNICODE_STRING Password;
    LSA_UNICODE_STRING OldPassword;
} TRUSTED_PASSWORD_INFO, *PTRUSTED_PASSWORD_INFO;


typedef  LSA_TRUST_INFORMATION TRUSTED_DOMAIN_INFORMATION_BASIC;

typedef PLSA_TRUST_INFORMATION PTRUSTED_DOMAIN_INFORMATION_BASIC;

//
// Direction of the trust
//
#define TRUST_DIRECTION_DISABLED        0x00000000
#define TRUST_DIRECTION_INBOUND         0x00000001
#define TRUST_DIRECTION_OUTBOUND        0x00000002
#define TRUST_DIRECTION_BIDIRECTIONAL   (TRUST_DIRECTION_INBOUND | TRUST_DIRECTION_OUTBOUND)

#define TRUST_TYPE_DOWNLEVEL            0x00000001  // NT4 and before
#define TRUST_TYPE_UPLEVEL              0x00000002  // NT5
#define TRUST_TYPE_MIT                  0x00000003  // Trust with a MIT Kerberos realm

#if (_WIN32_WINNT < 0x0502)
#define TRUST_TYPE_DCE                  0x00000004  // Trust with a DCE realm
#endif

// Levels 0x5 - 0x000FFFFF reserved for future use
// Provider specific trust levels are from 0x00100000 to 0xFFF00000

#define TRUST_ATTRIBUTE_NON_TRANSITIVE                0x00000001  // Disallow transitivity
#define TRUST_ATTRIBUTE_UPLEVEL_ONLY                  0x00000002  // Trust link only valid for uplevel client
#if (_WIN32_WINNT == 0x0500)
#define TRUST_ATTRIBUTE_TREE_PARENT     0x00400000  // Denotes that we are setting the trust
                                                    // to our parent in the org tree...
#define TRUST_ATTRIBUTE_TREE_ROOT       0x00800000  // Denotes that we are setting the trust
                                                    // to another tree root in a forest...
// Trust attributes 0x00000004 through 0x004FFFFF reserved for future use
// Trust attributes 0x00F00000 through 0x00400000 are reserved for internal use
// Trust attributes 0x01000000 through 0xFF000000 are reserved for user
// defined values
#define TRUST_ATTRIBUTES_VALID  0xFF02FFFF
#endif

#if (_WIN32_WINNT < 0x0502)
#define TRUST_ATTRIBUTE_FILTER_SIDS        0x00000004  // Used to quarantine domains
#else
#define TRUST_ATTRIBUTE_QUARANTINED_DOMAIN            0x00000004  // Used to quarantine domains
#endif

#if (_WIN32_WINNT >= 0x0501)
#define TRUST_ATTRIBUTE_FOREST_TRANSITIVE             0x00000008  // This link may contain forest trust information
#if (_WIN32_WINNT >= 0x0502)
#define TRUST_ATTRIBUTE_CROSS_ORGANIZATION            0x00000010  // This trust is to a domain/forest which is not part of this enterprise
#define TRUST_ATTRIBUTE_WITHIN_FOREST                 0x00000020  // Trust is internal to this forest
#define TRUST_ATTRIBUTE_TREAT_AS_EXTERNAL             0x00000040  // Trust is to be treated as external for trust boundary purposes
#if (_WIN32_WINNT >= 0x0600)
#define TRUST_ATTRIBUTE_TRUST_USES_RC4_ENCRYPTION     0x00000080  // MIT trust with RC4
#define TRUST_ATTRIBUTE_TRUST_USES_AES_KEYS           0x00000100  // Use AES keys to encrypte KRB TGTs
#endif
#if (_WIN32_WINNT >= 0x0602)
#define TRUST_ATTRIBUTE_CROSS_ORGANIZATION_NO_TGT_DELEGATION 0x00000200  // do not forward TGT to the other side of the trust which is not part of this enterprise
#define TRUST_ATTRIBUTE_PIM_TRUST                     0x00000400  // Outgoing trust to a PIM forest.
#endif
#if (_WIN32_WINNT >= 0x0603)
// Forward the TGT to the other side of the trust which is not part of this enterprise
// This flag has the opposite meaning of TRUST_ATTRIBUTE_CROSS_ORGANIZATION_NO_TGT_DELEGATION which is now deprecated.
// Note: setting TRUST_ATTRIBUTE_CROSS_ORGANIZATION_ENABLE_TGT_DELEGATION is not recommended from a security standpoint.
#define TRUST_ATTRIBUTE_CROSS_ORGANIZATION_ENABLE_TGT_DELEGATION 0x00000800
#endif
// Trust attributes 0x00000040 through 0x00200000 are reserved for future use
#else
// Trust attributes 0x00000010 through 0x00200000 are reserved for future use
#endif
// Trust attributes 0x00400000 through 0x00800000 were used previously (up to W2K) and should not be re-used
// Trust attributes 0x01000000 through 0x80000000 are reserved for user
#define TRUST_ATTRIBUTES_VALID          0xFF03FFFF
#endif
#define TRUST_ATTRIBUTES_USER           0xFF000000

typedef struct _TRUSTED_DOMAIN_INFORMATION_EX {

    LSA_UNICODE_STRING Name;
    LSA_UNICODE_STRING FlatName;
    PSID  Sid;
    ULONG TrustDirection;
    ULONG TrustType;
    ULONG TrustAttributes;

} TRUSTED_DOMAIN_INFORMATION_EX, *PTRUSTED_DOMAIN_INFORMATION_EX;

typedef struct _TRUSTED_DOMAIN_INFORMATION_EX2 {

    LSA_UNICODE_STRING Name;
    LSA_UNICODE_STRING FlatName;
    PSID  Sid;
    ULONG TrustDirection;
    ULONG TrustType;
    ULONG TrustAttributes;
    ULONG ForestTrustLength;
#ifdef MIDL_PASS
    [size_is( ForestTrustLength )]
#endif
    PUCHAR ForestTrustInfo;

} TRUSTED_DOMAIN_INFORMATION_EX2, *PTRUSTED_DOMAIN_INFORMATION_EX2;

//
// Type of authentication information
//
#define TRUST_AUTH_TYPE_NONE    0   // Ignore this entry
#define TRUST_AUTH_TYPE_NT4OWF  1   // NT4 OWF password
#define TRUST_AUTH_TYPE_CLEAR   2   // Cleartext password
#define TRUST_AUTH_TYPE_VERSION 3   // Cleartext password version number

typedef struct _LSA_AUTH_INFORMATION {

    LARGE_INTEGER LastUpdateTime;
    ULONG AuthType;
    ULONG AuthInfoLength;
    PUCHAR AuthInfo;
} LSA_AUTH_INFORMATION, *PLSA_AUTH_INFORMATION;

typedef struct _TRUSTED_DOMAIN_AUTH_INFORMATION {

    ULONG IncomingAuthInfos;
    PLSA_AUTH_INFORMATION   IncomingAuthenticationInformation;
    PLSA_AUTH_INFORMATION   IncomingPreviousAuthenticationInformation;
    ULONG OutgoingAuthInfos;
    PLSA_AUTH_INFORMATION   OutgoingAuthenticationInformation;
    PLSA_AUTH_INFORMATION   OutgoingPreviousAuthenticationInformation;

} TRUSTED_DOMAIN_AUTH_INFORMATION, *PTRUSTED_DOMAIN_AUTH_INFORMATION;

typedef struct _TRUSTED_DOMAIN_FULL_INFORMATION {

    TRUSTED_DOMAIN_INFORMATION_EX   Information;
    TRUSTED_POSIX_OFFSET_INFO       PosixOffset;
    TRUSTED_DOMAIN_AUTH_INFORMATION AuthInformation;

} TRUSTED_DOMAIN_FULL_INFORMATION, *PTRUSTED_DOMAIN_FULL_INFORMATION;

typedef struct _TRUSTED_DOMAIN_FULL_INFORMATION2 {

    TRUSTED_DOMAIN_INFORMATION_EX2  Information;
    TRUSTED_POSIX_OFFSET_INFO       PosixOffset;
    TRUSTED_DOMAIN_AUTH_INFORMATION AuthInformation;

} TRUSTED_DOMAIN_FULL_INFORMATION2, *PTRUSTED_DOMAIN_FULL_INFORMATION2;

typedef struct _TRUSTED_DOMAIN_SUPPORTED_ENCRYPTION_TYPES {

    ULONG      SupportedEncryptionTypes;

} TRUSTED_DOMAIN_SUPPORTED_ENCRYPTION_TYPES, *PTRUSTED_DOMAIN_SUPPORTED_ENCRYPTION_TYPES;

typedef enum {

    ForestTrustTopLevelName,
    ForestTrustTopLevelNameEx,
    ForestTrustDomainInfo,
    ForestTrustRecordTypeLast = ForestTrustDomainInfo

} LSA_FOREST_TRUST_RECORD_TYPE;

#if (_WIN32_WINNT < 0x0502)
#define LSA_FOREST_TRUST_RECORD_TYPE_UNRECOGNIZED 0x80000000
#endif

//
// Bottom 16 bits of the flags are reserved for disablement reasons
//

#define LSA_FTRECORD_DISABLED_REASONS            ( 0x0000FFFFL )

//
// Reasons for a top-level name forest trust record to be disabled
//

#define LSA_TLN_DISABLED_NEW                     ( 0x00000001L )
#define LSA_TLN_DISABLED_ADMIN                   ( 0x00000002L )
#define LSA_TLN_DISABLED_CONFLICT                ( 0x00000004L )

//
// Reasons for a domain information forest trust record to be disabled
//

#define LSA_SID_DISABLED_ADMIN                   ( 0x00000001L )
#define LSA_SID_DISABLED_CONFLICT                ( 0x00000002L )
#define LSA_NB_DISABLED_ADMIN                    ( 0x00000004L )
#define LSA_NB_DISABLED_CONFLICT                 ( 0x00000008L )

typedef struct _LSA_FOREST_TRUST_DOMAIN_INFO {

#ifdef MIDL_PASS
    PISID Sid;
#else
    PSID Sid;
#endif
    LSA_UNICODE_STRING DnsName;
    LSA_UNICODE_STRING NetbiosName;

} LSA_FOREST_TRUST_DOMAIN_INFO, *PLSA_FOREST_TRUST_DOMAIN_INFO;


#if (_WIN32_WINNT >= 0x0502)
//
//  To prevent huge data to be passed in, we should put a limit on LSA_FOREST_TRUST_BINARY_DATA.
//      128K is large enough that can't be reached in the near future, and small enough not to
//      cause memory problems.

#define MAX_FOREST_TRUST_BINARY_DATA_SIZE ( 128 * 1024 )
#endif

typedef struct _LSA_FOREST_TRUST_BINARY_DATA {

#ifdef MIDL_PASS
    [range(0, MAX_FOREST_TRUST_BINARY_DATA_SIZE)] ULONG Length;
    [size_is( Length )] PUCHAR Buffer;
#else
    ULONG Length;
    PUCHAR Buffer;
#endif

} LSA_FOREST_TRUST_BINARY_DATA, *PLSA_FOREST_TRUST_BINARY_DATA;

typedef struct _LSA_FOREST_TRUST_RECORD {

    ULONG Flags;
    LSA_FOREST_TRUST_RECORD_TYPE ForestTrustType; // type of record
    LARGE_INTEGER Time;

#ifdef MIDL_PASS
    [switch_type( LSA_FOREST_TRUST_RECORD_TYPE ), switch_is( ForestTrustType )]
#endif

    union {                                       // actual data

#ifdef MIDL_PASS
        [case( ForestTrustTopLevelName,
               ForestTrustTopLevelNameEx )] LSA_UNICODE_STRING TopLevelName;
        [case( ForestTrustDomainInfo )] LSA_FOREST_TRUST_DOMAIN_INFO DomainInfo;
        [default] LSA_FOREST_TRUST_BINARY_DATA Data;
#else
        LSA_UNICODE_STRING TopLevelName;
        LSA_FOREST_TRUST_DOMAIN_INFO DomainInfo;
        LSA_FOREST_TRUST_BINARY_DATA Data;        // used for unrecognized types
#endif
    } ForestTrustData;

} LSA_FOREST_TRUST_RECORD, *PLSA_FOREST_TRUST_RECORD;

#if (_WIN32_WINNT >= 0x0502)
//
// To prevent forest trust blobs of large size, number of records must be
// smaller than MAX_RECORDS_IN_FOREST_TRUST_INFO
//

#define MAX_RECORDS_IN_FOREST_TRUST_INFO 4000
#endif

typedef struct _LSA_FOREST_TRUST_INFORMATION {

#ifdef MIDL_PASS
    [range(0, MAX_RECORDS_IN_FOREST_TRUST_INFO)] ULONG RecordCount;
    [size_is( RecordCount )] PLSA_FOREST_TRUST_RECORD * Entries;
#else
    ULONG RecordCount;
    PLSA_FOREST_TRUST_RECORD * Entries;
#endif

} LSA_FOREST_TRUST_INFORMATION, *PLSA_FOREST_TRUST_INFORMATION;

typedef enum {

    CollisionTdo,
    CollisionXref,
    CollisionOther

} LSA_FOREST_TRUST_COLLISION_RECORD_TYPE;

typedef struct _LSA_FOREST_TRUST_COLLISION_RECORD {

    ULONG Index;
    LSA_FOREST_TRUST_COLLISION_RECORD_TYPE Type;
    ULONG Flags;
    LSA_UNICODE_STRING Name;

} LSA_FOREST_TRUST_COLLISION_RECORD, *PLSA_FOREST_TRUST_COLLISION_RECORD;

typedef struct _LSA_FOREST_TRUST_COLLISION_INFORMATION {

    ULONG RecordCount;
#ifdef MIDL_PASS
    [size_is( RecordCount )]
#endif
    PLSA_FOREST_TRUST_COLLISION_RECORD * Entries;

} LSA_FOREST_TRUST_COLLISION_INFORMATION, *PLSA_FOREST_TRUST_COLLISION_INFORMATION;

// end_ntsecapi

//
// Secret object specific access types
//

#define SECRET_SET_VALUE                          0x00000001L
#define SECRET_QUERY_VALUE                        0x00000002L

#define SECRET_ALL_ACCESS     (STANDARD_RIGHTS_REQUIRED         |\
                               SECRET_SET_VALUE                 |\
                               SECRET_QUERY_VALUE)

#define SECRET_READ           (STANDARD_RIGHTS_READ             |\
                               SECRET_QUERY_VALUE)

#define SECRET_WRITE          (STANDARD_RIGHTS_WRITE            |\
                               SECRET_SET_VALUE)

#define SECRET_EXECUTE        (STANDARD_RIGHTS_EXECUTE)

//
// Global secret object prefix
//

#define LSA_GLOBAL_SECRET_PREFIX            L"G$"
#define LSA_GLOBAL_SECRET_PREFIX_LENGTH     2

#define LSA_LOCAL_SECRET_PREFIX             L"L$"
#define LSA_LOCAL_SECRET_PREFIX_LENGTH      2

#define LSA_MACHINE_SECRET_PREFIX           L"M$"
#define LSA_MACHINE_SECRET_PREFIX_LENGTH                        \
                ( ( sizeof( LSA_MACHINE_SECRET_PREFIX ) - sizeof( WCHAR ) ) / sizeof( WCHAR ) )

//
// Secret object specific data types.
//

//
// Secret object limits
//

#define LSA_SECRET_MAXIMUM_COUNT                  0x00001000L
#define LSA_SECRET_MAXIMUM_LENGTH                 0x00000200L

// begin_ntsecapi

//
// LSA Enumeration Context
//

typedef ULONG LSA_ENUMERATION_HANDLE, *PLSA_ENUMERATION_HANDLE;

//
// LSA Enumeration Information
//

typedef struct _LSA_ENUMERATION_INFORMATION {

    PSID Sid;

} LSA_ENUMERATION_INFORMATION, *PLSA_ENUMERATION_INFORMATION;


////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Local Security Policy - Miscellaneous API function prototypes          //
//                                                                        //
////////////////////////////////////////////////////////////////////////////


NTSTATUS
NTAPI
LsaFreeMemory(
    _In_opt_ PVOID Buffer
    );

NTSTATUS
NTAPI
LsaClose(
    _In_ LSA_HANDLE ObjectHandle
    );

// end_ntsecapi

NTSTATUS
NTAPI
LsaDelete(
    _In_ LSA_HANDLE ObjectHandle
    );

NTSTATUS
NTAPI
LsaQuerySecurityObject(
    _In_ LSA_HANDLE ObjectHandle,
    _In_ SECURITY_INFORMATION SecurityInformation,
    _Out_ PSECURITY_DESCRIPTOR *SecurityDescriptor
    );

NTSTATUS
NTAPI
LsaSetSecurityObject(
    _In_ LSA_HANDLE ObjectHandle,
    _In_ SECURITY_INFORMATION SecurityInformation,
    _In_ PSECURITY_DESCRIPTOR SecurityDescriptor
    );

NTSTATUS
NTAPI
LsaChangePassword(
    _In_ PLSA_UNICODE_STRING ServerName,
    _In_ PLSA_UNICODE_STRING DomainName,
    _In_ PLSA_UNICODE_STRING AccountName,
    _In_ PLSA_UNICODE_STRING OldPassword,
    _In_ PLSA_UNICODE_STRING NewPassword
    );

// begin_ntsecapi

#if (_WIN32_WINNT >= 0x0600)

typedef struct _LSA_LAST_INTER_LOGON_INFO {
    LARGE_INTEGER LastSuccessfulLogon;
    LARGE_INTEGER LastFailedLogon;
    ULONG FailedAttemptCountSinceLastSuccessfulLogon;
} LSA_LAST_INTER_LOGON_INFO, *PLSA_LAST_INTER_LOGON_INFO;

#endif

#if (_WIN32_WINNT >= 0x0501)
typedef struct _SECURITY_LOGON_SESSION_DATA {
    ULONG               Size;
    LUID                LogonId;
    LSA_UNICODE_STRING  UserName;
    LSA_UNICODE_STRING  LogonDomain;
    LSA_UNICODE_STRING  AuthenticationPackage;
    ULONG               LogonType;
    ULONG               Session;
    PSID                Sid;
    LARGE_INTEGER       LogonTime;

    //
    // new for whistler:
    //

    LSA_UNICODE_STRING  LogonServer;
    LSA_UNICODE_STRING  DnsDomainName;
    LSA_UNICODE_STRING  Upn;

#if (_WIN32_WINNT >= 0x0600)

    //
    // new for LH
    //

    ULONG UserFlags;

    LSA_LAST_INTER_LOGON_INFO LastLogonInfo;
    LSA_UNICODE_STRING LogonScript;
    LSA_UNICODE_STRING ProfilePath;
    LSA_UNICODE_STRING HomeDirectory;
    LSA_UNICODE_STRING HomeDirectoryDrive;

    LARGE_INTEGER LogoffTime;
    LARGE_INTEGER KickOffTime;
    LARGE_INTEGER PasswordLastSet;
    LARGE_INTEGER PasswordCanChange;
    LARGE_INTEGER PasswordMustChange;

#endif
} SECURITY_LOGON_SESSION_DATA, * PSECURITY_LOGON_SESSION_DATA;

NTSTATUS
NTAPI
LsaEnumerateLogonSessions(
    _Out_ PULONG  LogonSessionCount,
    _Out_ PLUID * LogonSessionList
    );

NTSTATUS
NTAPI
LsaGetLogonSessionData(
    _In_ PLUID    LogonId,
    _Out_ PSECURITY_LOGON_SESSION_DATA * ppLogonSessionData
    );

#endif
// end_ntsecapi

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Local Security Policy - Policy Object API function prototypes             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// begin_ntsecapi
NTSTATUS
NTAPI
LsaOpenPolicy(
    _In_opt_ PLSA_UNICODE_STRING SystemName,
    _In_ PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE PolicyHandle
    );

// end_ntsecapi

NTSTATUS
NTAPI
LsaOpenPolicySce(
    _In_opt_ PLSA_UNICODE_STRING SystemName,
    _In_ PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE PolicyHandle
    );

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Central Access Policy - Data Structures and function prototypes           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////


// begin_ntsecapi

//
// Keep the following in sync with LSA_MAXIMUM_PER_CAP_CAPE_COUNT
// TBD: Reduce these multiple macros to one
//
#define MAXIMUM_CAPES_PER_CAP 0x7F

//
// The 32-bit flag in CAP are CAPE are segmented as follows
//
//  +----------------+---------------+-----------------+--------------------+
//  | Reserved Flags | Control Flags | Staged Policy's | Effective Policy's |
//  |                |               |       Flags     |        Flags       |
//  +----------------+---------------+-----------------+--------------------+
//  |     8-bits     |     8-bits    |      8-bits     |       8-bits       |
//  +----------------+---------------+-----------------+--------------------+
//
// Only the LSB of Control Flags, Staged and Effective Policy Flags are used
// All other bits are reserved and MUST be zero
//

//
// Effective Policy's Flags
//
#define CENTRAL_ACCESS_POLICY_OWNER_RIGHTS_PRESENT_FLAG         0x00000001

//
// Staging Policy's Flags
//
#define CENTRAL_ACCESS_POLICY_STAGED_OWNER_RIGHTS_PRESENT_FLAG  0x00000100
#define STAGING_FLAG(Effective) ((Effective & 0xF) << 8)

//
// Control Flags
//
#define CENTRAL_ACCESS_POLICY_STAGED_FLAG                       0x00010000

#define CENTRAL_ACCESS_POLICY_VALID_FLAG_MASK                           \
        (                                                               \
            CENTRAL_ACCESS_POLICY_OWNER_RIGHTS_PRESENT_FLAG         |   \
            CENTRAL_ACCESS_POLICY_STAGED_OWNER_RIGHTS_PRESENT_FLAG  |   \
            CENTRAL_ACCESS_POLICY_STAGED_FLAG                           \
        )

//
// LsaSetCAPs Flags
//
#define LSASETCAPS_RELOAD_FLAG                      0x00000001

#define LSASETCAPS_VALID_FLAG_MASK                          \
        (                                                   \
            LSASETCAPS_RELOAD_FLAG                         \
        )

//
// CAPE structure that specifies the access policy and when it is applicable
//
// WARNING !
// Keep the fields of the following struct in sync with LSAPR_CENTRAL_ACCESS_POLICY_ENTRY
// struct in lsarpc.idl
//
//
typedef struct _CENTRAL_ACCESS_POLICY_ENTRY {

    LSA_UNICODE_STRING      Name;           // Unique name as in AD
    LSA_UNICODE_STRING      Description;
    LSA_UNICODE_STRING      ChangeId;
    ULONG                   LengthAppliesTo;
    _Field_size_bytes_(LengthAppliesTo)
    PUCHAR                  AppliesTo;      // Must satisfy to enforce CAPE
    ULONG                   LengthSD;
    _Field_size_bytes_(LengthSD)
    PSECURITY_DESCRIPTOR    SD;             // Effective policy
    ULONG                   LengthStagedSD;
    _Field_size_bytes_(LengthStagedSD)
    PSECURITY_DESCRIPTOR    StagedSD;       // Staged policy
    ULONG                   Flags;          // Reserved
}
CENTRAL_ACCESS_POLICY_ENTRY, *PCENTRAL_ACCESS_POLICY_ENTRY;

typedef const CENTRAL_ACCESS_POLICY_ENTRY *PCCENTRAL_ACCESS_POLICY_ENTRY;

//
// CAP structure that is a collection of CAPEs. Resources that are subject to
// Central Access Policies are associated with a CAP by a CAP ID placed in the SACL
// of the Resource. Applicable CAPEs of a CAP are enforced during access check.
//
// WARNING !
// Keep the fields of the following struct in sync with LSAPR_CENTRAL_ACCESS_POLICY
// struct in lsarpc.idl
//
//

typedef struct _CENTRAL_ACCESS_POLICY {

    PSID                            CAPID;
    LSA_UNICODE_STRING              Name;
    LSA_UNICODE_STRING              Description;
    LSA_UNICODE_STRING              ChangeId;
    ULONG                           Flags;
    ULONG                           CAPECount;
    _Field_size_(CAPECount)
    PCENTRAL_ACCESS_POLICY_ENTRY   *CAPEs;
}
CENTRAL_ACCESS_POLICY, *PCENTRAL_ACCESS_POLICY;

typedef const CENTRAL_ACCESS_POLICY *PCCENTRAL_ACCESS_POLICY;

NTSTATUS
NTAPI
LsaSetCAPs(
    _In_reads_opt_(CAPDNCount) PLSA_UNICODE_STRING CAPDNs,
    _In_ ULONG CAPDNCount,
    _In_ ULONG Flags
    );

NTSTATUS
NTAPI
LsaGetAppliedCAPIDs(
    _In_opt_ PLSA_UNICODE_STRING SystemName,
    _Outptr_result_buffer_(*CAPIDCount) PSID **CAPIDs,
    _Out_ PULONG CAPIDCount
    );

NTSTATUS
NTAPI
LsaQueryCAPs(
    _In_reads_opt_(CAPIDCount) PSID *CAPIDs,
    _In_ ULONG CAPIDCount,
    _Outptr_result_buffer_(*CAPCount) PCENTRAL_ACCESS_POLICY *CAPs,
    _Out_ PULONG CAPCount
    );

// end_ntsecapi

// begin_ntsecapi

NTSTATUS
NTAPI
LsaQueryInformationPolicy(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ POLICY_INFORMATION_CLASS InformationClass,
    _Out_ PVOID *Buffer
    );

NTSTATUS
NTAPI
LsaSetInformationPolicy(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ POLICY_INFORMATION_CLASS InformationClass,
    _In_ PVOID Buffer
    );

NTSTATUS
NTAPI
LsaQueryDomainInformationPolicy(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ POLICY_DOMAIN_INFORMATION_CLASS InformationClass,
    _Out_ PVOID *Buffer
    );

NTSTATUS
NTAPI
LsaSetDomainInformationPolicy(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ POLICY_DOMAIN_INFORMATION_CLASS InformationClass,
    _In_opt_ PVOID Buffer
    );


NTSTATUS
NTAPI
LsaRegisterPolicyChangeNotification(
    _In_ POLICY_NOTIFICATION_INFORMATION_CLASS InformationClass,
    _In_ HANDLE  NotificationEventHandle
    );

NTSTATUS
NTAPI
LsaUnregisterPolicyChangeNotification(
    _In_ POLICY_NOTIFICATION_INFORMATION_CLASS InformationClass,
    _In_ HANDLE  NotificationEventHandle
    );


// end_ntsecapi

NTSTATUS
NTAPI
LsaClearAuditLog(
    _In_ LSA_HANDLE PolicyHandle
    );

NTSTATUS
NTAPI
LsaCreateAccount(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID AccountSid,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE AccountHandle
    );

NTSTATUS
NTAPI
LsaEnumerateAccounts(
    _In_ LSA_HANDLE PolicyHandle,
    _Inout_ PLSA_ENUMERATION_HANDLE EnumerationContext,
    _Out_ PVOID *Buffer,
    _In_ ULONG PreferedMaximumLength,
    _Out_ PULONG CountReturned
    );

NTSTATUS
NTAPI
LsaCreateTrustedDomain(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_TRUST_INFORMATION TrustedDomainInformation,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE TrustedDomainHandle
    );

// begin_ntsecapi

NTSTATUS
NTAPI
LsaEnumerateTrustedDomains(
    _In_ LSA_HANDLE PolicyHandle,
    _Inout_ PLSA_ENUMERATION_HANDLE EnumerationContext,
    _Out_ PVOID *Buffer,
    _In_ ULONG PreferedMaximumLength,
    _Out_ PULONG CountReturned
    );

// end_ntsecapi

NTSTATUS
NTAPI
LsaEnumeratePrivileges(
    _In_ LSA_HANDLE PolicyHandle,
    _Inout_ PLSA_ENUMERATION_HANDLE EnumerationContext,
    _Out_ PVOID *Buffer,
    _In_ ULONG PreferedMaximumLength,
    _Out_ PULONG CountReturned
    );

// begin_ntsecapi

NTSTATUS
NTAPI
LsaLookupNames(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ ULONG Count,
    _In_ PLSA_UNICODE_STRING Names,
    _Out_ PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
    _Out_ PLSA_TRANSLATED_SID *Sids
    );

#if (_WIN32_WINNT >= 0x0501)
NTSTATUS
NTAPI
LsaLookupNames2(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ ULONG Flags, // Reserved
    _In_ ULONG Count,
    _In_ PLSA_UNICODE_STRING Names,
    _Out_ PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
    _Out_ PLSA_TRANSLATED_SID2 *Sids
    );
#endif

NTSTATUS
NTAPI
LsaLookupSids(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ ULONG Count,
    _In_ PSID *Sids,
    _Out_ PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
    _Out_ PLSA_TRANSLATED_NAME *Names
    );

NTSTATUS
NTAPI
LsaLookupSids2(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ ULONG LookupOptions,
    _In_ ULONG Count,
    _In_ PSID *Sids,
    _Out_ PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains,
    _Out_ PLSA_TRANSLATED_NAME *Names
    );

// end_ntsecapi

NTSTATUS
NTAPI
LsaCreateSecret(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING SecretName,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE SecretHandle
    );

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Local Security Policy - Account Object API function prototypes            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

NTSTATUS
NTAPI
LsaOpenAccount(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID AccountSid,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE AccountHandle
    );

NTSTATUS
NTAPI
LsaEnumeratePrivilegesOfAccount(
    _In_ LSA_HANDLE AccountHandle,
    _Out_ PPRIVILEGE_SET *Privileges
    );

NTSTATUS
NTAPI
LsaAddPrivilegesToAccount(
    _In_ LSA_HANDLE AccountHandle,
    _In_ PPRIVILEGE_SET Privileges
    );

NTSTATUS
NTAPI
LsaRemovePrivilegesFromAccount(
    _In_ LSA_HANDLE AccountHandle,
    _In_ BOOLEAN AllPrivileges,
    _In_opt_ PPRIVILEGE_SET Privileges
    );

NTSTATUS
NTAPI
LsaGetQuotasForAccount(
    _In_ LSA_HANDLE AccountHandle,
    _Out_ PQUOTA_LIMITS QuotaLimits
    );

NTSTATUS
NTAPI
LsaSetQuotasForAccount(
    _In_ LSA_HANDLE AccountHandle,
    _In_ PQUOTA_LIMITS QuotaLimits
    );

NTSTATUS
NTAPI
LsaGetSystemAccessAccount(
    _In_ LSA_HANDLE AccountHandle,
    _Out_ PULONG SystemAccess
    );

NTSTATUS
NTAPI
LsaSetSystemAccessAccount(
    _In_ LSA_HANDLE AccountHandle,
    _In_ ULONG SystemAccess
    );

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Local Security Policy - Trusted Domain Object API function prototypes     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

NTSTATUS
NTAPI
LsaOpenTrustedDomain(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID TrustedDomainSid,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE TrustedDomainHandle
    );

NTSTATUS
NTAPI
LsaQueryInfoTrustedDomain(
    _In_ LSA_HANDLE TrustedDomainHandle,
    _In_ TRUSTED_INFORMATION_CLASS InformationClass,
    _Out_ PVOID *Buffer
    );

NTSTATUS
NTAPI
LsaSetInformationTrustedDomain(
    _In_ LSA_HANDLE TrustedDomainHandle,
    _In_ TRUSTED_INFORMATION_CLASS InformationClass,
    _In_ PVOID Buffer
    );

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Local Security Policy - Secret Object API function prototypes             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

NTSTATUS
NTAPI
LsaOpenSecret(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING SecretName,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE SecretHandle
    );

NTSTATUS
NTAPI
LsaSetSecret(
    _In_ LSA_HANDLE SecretHandle,
    _In_opt_ PLSA_UNICODE_STRING CurrentValue,
    _In_opt_ PLSA_UNICODE_STRING OldValue
    );

NTSTATUS
NTAPI
LsaQuerySecret(
    _In_ LSA_HANDLE SecretHandle,
    _Out_opt_ PLSA_UNICODE_STRING *CurrentValue,
    _Out_opt_ PLARGE_INTEGER CurrentValueSetTime,
    _Out_opt_ PLSA_UNICODE_STRING *OldValue,
    _Out_opt_ PLARGE_INTEGER OldValueSetTime
    );


/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Local Security Policy - Privilege Object API Prototypes             //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

NTSTATUS
NTAPI
LsaLookupPrivilegeValue(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING Name,
    _Out_ PLUID Value
    );

NTSTATUS
NTAPI
LsaLookupPrivilegeName(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLUID Value,
    _Out_ PLSA_UNICODE_STRING *Name
    );

NTSTATUS
NTAPI
LsaLookupPrivilegeDisplayName(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING Name,
    _Out_ PLSA_UNICODE_STRING *DisplayName,
    _Out_ PSHORT LanguageReturned
    );


/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Local Security Policy - New APIs for NT 4.0 (SUR release)           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

NTSTATUS
LsaGetUserName(
    _Outptr_ PLSA_UNICODE_STRING * UserName,
    _Outptr_opt_ PLSA_UNICODE_STRING * DomainName
    );

NTSTATUS
LsaGetRemoteUserName(
    _In_opt_ PLSA_UNICODE_STRING SystemName,
    _Outptr_ PLSA_UNICODE_STRING * UserName,
    _Outptr_opt_ PLSA_UNICODE_STRING * DomainName
    );


/////////////////////////////////////////////////////////////////////////
//                                                                     //
// Local Security Policy - New APIs for NT 3.51 (PPC release)          //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// begin_ntsecapi


#define SE_INTERACTIVE_LOGON_NAME           TEXT("SeInteractiveLogonRight")
#define SE_NETWORK_LOGON_NAME               TEXT("SeNetworkLogonRight")
#define SE_BATCH_LOGON_NAME                 TEXT("SeBatchLogonRight")
#define SE_SERVICE_LOGON_NAME               TEXT("SeServiceLogonRight")
#define SE_DENY_INTERACTIVE_LOGON_NAME      TEXT("SeDenyInteractiveLogonRight")
#define SE_DENY_NETWORK_LOGON_NAME          TEXT("SeDenyNetworkLogonRight")
#define SE_DENY_BATCH_LOGON_NAME            TEXT("SeDenyBatchLogonRight")
#define SE_DENY_SERVICE_LOGON_NAME          TEXT("SeDenyServiceLogonRight")
#if (_WIN32_WINNT >= 0x0501)
#define SE_REMOTE_INTERACTIVE_LOGON_NAME    TEXT("SeRemoteInteractiveLogonRight")
#define SE_DENY_REMOTE_INTERACTIVE_LOGON_NAME TEXT("SeDenyRemoteInteractiveLogonRight")
#endif

//
// This new API returns all the accounts with a certain privilege
//

NTSTATUS
NTAPI
LsaEnumerateAccountsWithUserRight(
    _In_ LSA_HANDLE PolicyHandle,
    _In_opt_ PLSA_UNICODE_STRING UserRight,
    _Out_ PVOID *Buffer,
    _Out_ PULONG CountReturned
    );

//
// These new APIs differ by taking a SID instead of requiring the caller
// to open the account first and passing in an account handle
//

NTSTATUS
NTAPI
LsaEnumerateAccountRights(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID AccountSid,
    _Outptr_result_buffer_(*CountOfRights) PLSA_UNICODE_STRING *UserRights,
    _Out_ PULONG CountOfRights
    );

NTSTATUS
NTAPI
LsaAddAccountRights(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID AccountSid,
    _In_reads_(CountOfRights) PLSA_UNICODE_STRING UserRights,
    _In_ ULONG CountOfRights
    );

NTSTATUS
NTAPI
LsaRemoveAccountRights(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID AccountSid,
    _In_ BOOLEAN AllRights,
    _In_reads_opt_(CountOfRights) PLSA_UNICODE_STRING UserRights,
    _In_ ULONG CountOfRights
    );

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Local Security Policy - Trusted Domain Object API function prototypes     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

NTSTATUS
NTAPI
LsaOpenTrustedDomainByName(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING TrustedDomainName,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE TrustedDomainHandle
    );


NTSTATUS
NTAPI
LsaQueryTrustedDomainInfo(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID TrustedDomainSid,
    _In_ TRUSTED_INFORMATION_CLASS InformationClass,
    _Out_ PVOID *Buffer
    );

NTSTATUS
NTAPI
LsaSetTrustedDomainInformation(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID TrustedDomainSid,
    _In_ TRUSTED_INFORMATION_CLASS InformationClass,
    _In_ PVOID Buffer
    );

NTSTATUS
NTAPI
LsaDeleteTrustedDomain(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PSID TrustedDomainSid
    );

NTSTATUS
NTAPI
LsaQueryTrustedDomainInfoByName(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING TrustedDomainName,
    _In_ TRUSTED_INFORMATION_CLASS InformationClass,
    _Out_ PVOID *Buffer
    );

NTSTATUS
NTAPI
LsaSetTrustedDomainInfoByName(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING TrustedDomainName,
    _In_ TRUSTED_INFORMATION_CLASS InformationClass,
    _In_ PVOID Buffer
    );

NTSTATUS
NTAPI
LsaEnumerateTrustedDomainsEx(
    _In_ LSA_HANDLE PolicyHandle,
    _Inout_ PLSA_ENUMERATION_HANDLE EnumerationContext,
    _Out_ PVOID *Buffer,
    _In_ ULONG PreferedMaximumLength,
    _Out_ PULONG CountReturned
    );

NTSTATUS
NTAPI
LsaCreateTrustedDomainEx(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PTRUSTED_DOMAIN_INFORMATION_EX TrustedDomainInformation,
    _In_ PTRUSTED_DOMAIN_AUTH_INFORMATION AuthenticationInformation,
    _In_ ACCESS_MASK DesiredAccess,
    _Out_ PLSA_HANDLE TrustedDomainHandle
    );

#if (_WIN32_WINNT >= 0x0501)
NTSTATUS
NTAPI
LsaQueryForestTrustInformation(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING TrustedDomainName,
    _Out_ PLSA_FOREST_TRUST_INFORMATION * ForestTrustInfo
    );

NTSTATUS
NTAPI
LsaSetForestTrustInformation(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING TrustedDomainName,
    _In_ PLSA_FOREST_TRUST_INFORMATION ForestTrustInfo,
    _In_ BOOLEAN CheckOnly,
    _Out_ PLSA_FOREST_TRUST_COLLISION_INFORMATION * CollisionInfo
    );

// #define TESTING_MATCHING_ROUTINE

#ifdef TESTING_MATCHING_ROUTINE

NTSTATUS
NTAPI
LsaForestTrustFindMatch(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ ULONG Type,
    _In_ PLSA_UNICODE_STRING Name,
    _Out_ PLSA_UNICODE_STRING * Match
    );

#endif
#endif

//
// This API sets the workstation password (equivalent of setting/getting
// the SSI_SECRET_NAME secret)
//

NTSTATUS
NTAPI
LsaStorePrivateData(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING KeyName,
    _In_opt_ PLSA_UNICODE_STRING PrivateData
    );

NTSTATUS
NTAPI
LsaRetrievePrivateData(
    _In_ LSA_HANDLE PolicyHandle,
    _In_ PLSA_UNICODE_STRING KeyName,
    _Out_ PLSA_UNICODE_STRING * PrivateData
    );


ULONG
NTAPI
LsaNtStatusToWinError(
    _In_ NTSTATUS Status
    );


//
// Define a symbol so we can tell if ntifs.h has been included.
//

// begin_ntifs
#ifndef _NTLSA_IFS_
#define _NTLSA_IFS_
#endif
// end_ntifs


//
// SPNEGO package stuff
//

enum NEGOTIATE_MESSAGES {
    NegEnumPackagePrefixes = 0,
    NegGetCallerName = 1,
    NegTransferCredentials = 2,
// end_ntsecapi
#ifdef _NTDEF_
    NegEnumPackageNames = 3,
#else
    NegMsgReserved1 = 3,    // ntsecapi
#endif
// begin_ntsecapi
    NegCallPackageMax
};

#define NEGOTIATE_MAX_PREFIX    32

typedef struct _NEGOTIATE_PACKAGE_PREFIX {
    ULONG_PTR   PackageId;
    PVOID       PackageDataA;
    PVOID       PackageDataW;
    ULONG_PTR   PrefixLen;
    UCHAR       Prefix[ NEGOTIATE_MAX_PREFIX ];
} NEGOTIATE_PACKAGE_PREFIX, * PNEGOTIATE_PACKAGE_PREFIX;

typedef struct _NEGOTIATE_PACKAGE_PREFIXES {
    ULONG       MessageType;
    ULONG       PrefixCount;
    ULONG       Offset;        // Offset to array of _PREFIX above
#if(_WIN32_WINNT >= 0x0502)
    ULONG       Pad;           // Align structure for 64-bit
#endif
} NEGOTIATE_PACKAGE_PREFIXES, *PNEGOTIATE_PACKAGE_PREFIXES;

typedef struct _NEGOTIATE_CALLER_NAME_REQUEST {
    ULONG       MessageType;
    LUID        LogonId;
} NEGOTIATE_CALLER_NAME_REQUEST, *PNEGOTIATE_CALLER_NAME_REQUEST;

typedef struct _NEGOTIATE_CALLER_NAME_RESPONSE {
    ULONG       MessageType;
    PWSTR       CallerName;
} NEGOTIATE_CALLER_NAME_RESPONSE, * PNEGOTIATE_CALLER_NAME_RESPONSE;

// end_ntsecapi

// In-process only.
typedef struct _NEGOTIATE_PACKAGE_NAMES {
    ULONG           NamesCount;
    UNICODE_STRING  Names[1];   // Actually NamesCount in size
} NEGOTIATE_PACKAGE_NAMES, *PNEGOTIATE_PACKAGE_NAMES;

#define NEGOTIATE_ALLOW_NTLM    0x10000000
#define NEGOTIATE_NEG_NTLM      0x20000000



//
// Define parallel structures for WOW64 environment.  These
// *must* stay in sync with their complements above.
//

typedef struct _NEGOTIATE_PACKAGE_PREFIX_WOW {
    ULONG       PackageId;
    ULONG       PackageDataA;
    ULONG       PackageDataW;
    ULONG       PrefixLen;
    UCHAR       Prefix[ NEGOTIATE_MAX_PREFIX ];
} NEGOTIATE_PACKAGE_PREFIX_WOW, * PNEGOTIATE_PACKAGE_PREFIX_WOW;

typedef struct _NEGOTIATE_CALLER_NAME_RESPONSE_WOW {
    ULONG       MessageType;
    ULONG       CallerName;
} NEGOTIATE_CALLER_NAME_RESPONSE_WOW, * PNEGOTIATE_CALLER_NAME_RESPONSE_WOW;

NTSTATUS
NTAPI
LsaSetPolicyReplicationHandle(
    _Inout_ PLSA_HANDLE PolicyHandle
    );

////////////////////////////////////////////////////////////////////////////
//
// Device registration support
//
////////////////////////////////////////////////////////////////////////////
//
// Maximum number of users that can be registered in one device.
//
#define MAX_USER_RECORDS 1000

typedef struct _LSA_USER_REGISTRATION_INFO {
        LSA_UNICODE_STRING Sid;
        LSA_UNICODE_STRING DeviceId;
        LSA_UNICODE_STRING Username;
        LSA_UNICODE_STRING Thumbprint;
        LARGE_INTEGER      RegistrationTime;
} LSA_USER_REGISTRATION_INFO, *PLSA_USER_REGISTRATION_INFO;

typedef struct _LSA_REGISTRATION_INFO {

#ifdef MIDL_PASS
    [range(0, MAX_USER_RECORDS)] ULONG RegisteredCount;
    [size_is( RegisteredCount)] PLSA_USER_REGISTRATION_INFO* UserRegistrationInfo;
#else
    ULONG RegisteredCount;
    PLSA_USER_REGISTRATION_INFO* UserRegistrationInfo;
#endif

} LSA_REGISTRATION_INFO, *PLSA_REGISTRATION_INFO;


NTSTATUS
NTAPI
LsaGetDeviceRegistrationInfo(
    _Out_ PLSA_REGISTRATION_INFO* RegistrationInfo
    );

////////////////////////////////////////////////////////////////////////////
//
// End of Device registration support
//
////////////////////////////////////////////////////////////////////////////

//
// LSA credential keys
//

typedef enum _LSA_CREDENTIAL_KEY_SOURCE_TYPE
{
    eFromPrecomputed = 1,  // used by Kerberos
    eFromClearPassword,
    eFromNtOwf,

} LSA_CREDENTIAL_KEY_SOURCE_TYPE, *PLSA_CREDENTIAL_KEY_SOURCE_TYPE;

//
// check if current user is protected user
//

NTSTATUS
SeciIsProtectedUser(
    __out PBOOLEAN ProtectedUser
    );

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#ifdef __cplusplus
}
#endif

#undef SIZE_IS
#undef SWITCH_IS
#undef SWITCH_TYPE
#undef CASE
#undef RANGE
#undef VAR_SIZE_ARRAY
#undef SID_POINTER
#undef REF


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif // _NTLSA_

