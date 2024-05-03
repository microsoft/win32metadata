#include <windows.h>
#include <appmodel.h>

#ifdef __cplusplus
extern "C" {
#endif

enum PackageInfo3Type
{
	PackageInfo3Type_PackageInfoGeneration = 16,
} PackageInfoType;

HRESULT GetCurrentPackageInfo3(
  _In_ UINT32                                 flags,
  _In_ PackageInfo3Type                       packageInfoType,
  _Inout_ UINT32                             *bufferLength,
  _Out_writes_bytes_opt_(*bufferLength) void *buffer,
  _Out_opt_ UINT32                           *count
);

#ifdef __cplusplus
}
#endif