// Missing from SDK but present in docs
// https://github.com/microsoft/win32metadata/issues/1566

class IMemoryAllocator
{
public:
  virtual void* Allocate(ULONG cbSize) = 0;
  virtual void Free(void* pv) = 0;
};
