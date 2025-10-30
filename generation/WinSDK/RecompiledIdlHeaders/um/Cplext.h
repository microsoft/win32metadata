///////////////////////////////////////////////////////////////////////////////
//
// CPLEXT.H  --  defines for property sheet extensions to system control panels
//
// Version 4.00
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef _INC_CPLEXT
#define _INC_CPLEXT


#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

///////////////////////////////////////////////////////////////////////////////
//  Below are constants for pages which can be replaced in the standard control
// panel applets.  To extend an applet, you must define an object which
// supports the IShellPropSheetExt interface and register it's in-process
// server in a subkey under the applet's registry key.  Registry paths for the
// applets are defined in the header file REGSTR.H
//  Generally, when an IShellPropSheetExt is loaded, it's AddPages method
// will be called once, while it's ReplacePage method may be called zero or
// more times.  ReplacePage is only called in context.
///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// Mouse Control Panel Extensions
// The following constants MAY be passed in IShellPropSheetExt::ReplacePage's
// uPageID parameter for servers registered under
//                                  ( REGSTR_PATH_CONTROLSFOLDER "\\Mouse" )
//-----------------------------------------------------------------------------

#define CPLPAGE_MOUSE_BUTTONS       1
#define CPLPAGE_MOUSE_PTRMOTION     2
#define CPLPAGE_MOUSE_WHEEL         3


//-----------------------------------------------------------------------------
// Keyboard Control Panel Extensions
// The following constants MAY be passed in IShellPropSheetExt::ReplacePage's
// uPageID parameter for servers registered under
//                                  ( REGSTR_PATH_CONTROLSFOLDER "\\Keyboard" )
//-----------------------------------------------------------------------------

#define CPLPAGE_KEYBOARD_SPEED      1


//-----------------------------------------------------------------------------
// Display Control Panel Extensions
// The following constants MAY be passed in IShellPropSheetExt::ReplacePage's
// uPageID parameter for servers registered under
//                                  ( REGSTR_PATH_CONTROLSFOLDER "\\Display" )
//-----------------------------------------------------------------------------

#define CPLPAGE_DISPLAY_BACKGROUND  1


///////////////////////////////////////////////////////////////////////////////


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif
