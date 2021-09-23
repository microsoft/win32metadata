/*++

    Copyright (c) Microsoft Corporation. All rights reserved.

Abstract:

    Isolated Windows Environment Public Utilities.

Author:

    Tushar Sugandhi (TusharSu) 4/10/2019

--*/
#pragma once

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#if (NTDDI_VERSION >= NTDDI_WIN10_VB)

STDAPI
IsProcessInIsolatedWindowsEnvironment(
    _Out_ BOOL *isProcessInIsolatedWindowsEnvironment
    );

#endif /* (NTDDI_VERSION >= NTDDI_WIN10_VB) */
#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
