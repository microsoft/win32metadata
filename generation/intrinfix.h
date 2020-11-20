/*
    An update to VS 2019 broke intrin0.h for us:

    #ifdef __clang__
    // This looks like a circular include but it is not because clang overrides <intrin.h> with their specific version.
    // See further discussion in LLVM-47099.
    #include <intrin.h>

    But our compiler isn't using the clang header, it's using the VS header at:
    C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Tools\MSVC\14.28.29333\include\intrin.h
*/
#define __MACHINE(X)        __MACHINEZ(X)
#define __MACHINEWVMPURE(X) X;

#define __MACHINEZ(X)       /* NOTHING */
#define __MACHINEX86           __MACHINE
#define __MACHINEX64           __MACHINE
#define __MACHINEX86_X64       __MACHINE
#define __MACHINEARM           __MACHINE
#define __MACHINEARM64         __MACHINE
#define __MACHINEARM_ARM64     __MACHINE
#define __MACHINEARM_ARM64_X64 __MACHINE
#define __MACHINEARM64_X64     __MACHINE
#define __MACHINECHPEX86ARM64  __MACHINE
