//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright 1995-1998 Microsoft Corporation. All Rights Reserved.
//
//  File: idispids.h
//
//--------------------------------------------------------------------------

#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define DISPID_READYSTATE                             (-525)
#define DISPID_READYSTATECHANGE                       (-609)
#define DISPID_AMBIENT_TRANSFERPRIORITY               (-728)
#define DISPID_AMBIENT_OFFLINEIFNOTCONNECTED          (-5501)
#define DISPID_AMBIENT_SILENT                         (-5502)

// Until these appear in OLECTL.H
#ifndef DISPID_AMBIENT_CODEPAGE
#define DISPID_AMBIENT_CODEPAGE         (-725)
#define DISPID_AMBIENT_CHARSET          (-727)
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

