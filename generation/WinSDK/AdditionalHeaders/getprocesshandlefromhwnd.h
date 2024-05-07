#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

HANDLE WINAPI GetProcessHandleFromHwnd(
  _In_ HWND hwnd
);

#ifdef __cplusplus
}
#endif