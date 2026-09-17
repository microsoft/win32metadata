#include "main.cpp"
#include <powrprof.h>

static_assert(POWER_PLATFORM_ROLE_V1 == 1);
static_assert(POWER_PLATFORM_ROLE_V2 == 2);
#if NTDDI_VERSION >= NTDDI_WIN8
static_assert(POWER_PLATFORM_ROLE_VERSION == 2);
#else
static_assert(POWER_PLATFORM_ROLE_VERSION == 1);
#endif
static_assert(DEVICE_NOTIFY_SERVICE_HANDLE == 1);
static_assert(DEVICE_NOTIFY_CALLBACK == 2);
static_assert(DEVICE_NOTIFY_WINDOW_HANDLE == 0);
static_assert(DEVICE_NOTIFY_ALL_INTERFACE_CLASSES == 4);

static_assert(__is_same(decltype(POWER_PLATFORM_ROLE_VERSION), int));
static_assert(__is_same(decltype(POWER_PLATFORM_ROLE_V1), int));
static_assert(__is_same(decltype(POWER_PLATFORM_ROLE_V2), int));
static_assert(__is_same(decltype(DEVICE_NOTIFY_SERVICE_HANDLE), int));
static_assert(__is_same(decltype(DEVICE_NOTIFY_CALLBACK), int));
static_assert(__is_same(decltype(DEVICE_NOTIFY_WINDOW_HANDLE), int));
static_assert(__is_same(decltype(DEVICE_NOTIFY_ALL_INTERFACE_CLASSES), int));
static_assert(__is_same(HPOWERNOTIFY, PVOID));
static_assert(__is_same(PHPOWERNOTIFY, HPOWERNOTIFY*));
static_assert(__is_same(decltype(&CallNtPowerInformation), LONG (WINAPI *)(POWER_INFORMATION_LEVEL, PVOID, ULONG, PVOID, ULONG)));
static_assert(__is_same(decltype(&GetPwrCapabilities), BOOLEAN (WINAPI *)(PSYSTEM_POWER_CAPABILITIES)));
static_assert(__is_same(decltype(&PowerDeterminePlatformRoleEx), POWER_PLATFORM_ROLE (WINAPI *)(ULONG)));
static_assert(__is_same(decltype(&PowerRegisterSuspendResumeNotification), DWORD (WINAPI *)(DWORD, HANDLE, PHPOWERNOTIFY)));
static_assert(__is_same(decltype(&PowerUnregisterSuspendResumeNotification), DWORD (WINAPI *)(HPOWERNOTIFY)));
