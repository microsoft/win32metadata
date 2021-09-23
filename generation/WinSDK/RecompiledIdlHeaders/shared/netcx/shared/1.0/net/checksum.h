// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


#include <net/checksumtypes.h>

EXTERN_C_START

inline
NET_PACKET_CHECKSUM *
NetExtensionGetPacketChecksum(
    NET_EXTENSION const * Extension,
    UINT32 Index
    )
{
    return (NET_PACKET_CHECKSUM *)NetExtensionGetData(Extension, Index);
}

EXTERN_C_END

#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#pragma endregion

