/*++

Copyright (c) Microsoft Corporation

Module Name:

    afunix.h

Abstract:

    This file contains the definitions for the AF_UNIX socket address family.

--*/

#ifndef _AFUNIX_
#define _AFUNIX_

#pragma once

#define UNIX_PATH_MAX 108

typedef struct sockaddr_un
{
     ADDRESS_FAMILY sun_family;     /* AF_UNIX */
     char sun_path[UNIX_PATH_MAX];  /* pathname */
} SOCKADDR_UN, *PSOCKADDR_UN;

#define SIO_AF_UNIX_GETPEERPID _WSAIOR(IOC_VENDOR, 256) // Returns ULONG PID of the connected peer process

#endif /* _AFUNIX_ */