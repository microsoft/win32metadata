// Synthetic fixture: a name-only export, a named export with an explicit ordinal, and an ordinal-only (NONAME) export.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int __stdcall FixtureByName(int value) { return value + 1; }
int __stdcall FixtureNamedWithOrdinal(int value) { return value + 10; }
int __stdcall FixtureByOrdinal(int value) { return value + 100; }

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
    (void)instance; (void)reason; (void)reserved;
    return TRUE;
}
