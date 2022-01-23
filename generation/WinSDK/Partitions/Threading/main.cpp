// #define SECURITY_WIN32 // For sspi.h

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

#include <winnt.h>
#include <avrt.h>

#define MakeProcThreadAttributeConst(value) \
    const DWORD __forceconst__##value = value;

#undef ProcThreadAttributeValue
#define ProcThreadAttributeValue(Number, Thread, Input, Additive) \
    (((DWORD)(Number) & PROC_THREAD_ATTRIBUTE_NUMBER) | \
     ((Thread != FALSE) ? PROC_THREAD_ATTRIBUTE_THREAD : 0) | \
     ((Input != FALSE) ? PROC_THREAD_ATTRIBUTE_INPUT : 0) | \
     ((Additive != FALSE) ? PROC_THREAD_ATTRIBUTE_ADDITIVE : 0))

MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_PARENT_PROCESS)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_HANDLE_LIST)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_PREFERRED_NODE)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_UMS_THREAD)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_PSEUDOCONSOLE)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_MACHINE_TYPE)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_ENABLE_OPTIONAL_XSTATE_FEATURES)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_WIN32K_FILTER)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_JOB_LIST)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_CHILD_PROCESS_POLICY)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_ALL_APPLICATION_PACKAGES_POLICY)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_DESKTOP_APP_POLICY)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_MITIGATION_AUDIT_POLICY)
MakeProcThreadAttributeConst(PROC_THREAD_ATTRIBUTE_COMPONENT_FILTER)
