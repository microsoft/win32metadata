// Missing from SDK but present in docs
// https://github.com/microsoft/win32metadata/issues/1566

#include <win32metadata_annotations.h>

class IMemoryAllocator
{
public:
  virtual void* Allocate(ULONG cbSize) = 0;
  virtual void Free(_WIN32META_ANNOTATION_("win32metadata:in") _WIN32META_ANNOTATION_("win32metadata:out") void* pv) = 0;
};
