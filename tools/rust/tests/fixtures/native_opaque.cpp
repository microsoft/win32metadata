class _Win32_NativeOpaque_ OpaqueBase
{
public:
    virtual ~OpaqueBase();
    int state;
};

class _Win32_NativeOpaque_ OpaqueDerived : public OpaqueBase
{
public:
    int detail;
};

// Clang propagates the definition's annotation onto this unannotated redeclaration.
class OpaqueBase;

class PlainClass
{
public:
    virtual ~PlainClass();
    int state;
};

static_assert(sizeof(OpaqueBase) == sizeof(PlainClass));
static_assert(alignof(OpaqueBase) == alignof(PlainClass));
static_assert(!__is_trivially_copyable(OpaqueBase));
static_assert(!__is_standard_layout(OpaqueBase));
static_assert(__is_base_of(OpaqueBase, OpaqueDerived));

extern "C" _Win32_ImportLibrary_("opaque.dll") void UseOpaque(
    OpaqueBase* direct, const OpaqueBase* constant,
    OpaqueBase** output, OpaqueDerived* derived);
extern "C" _Win32_ImportLibrary_("opaque.dll") void UsePlain(
    PlainClass* direct, const PlainClass* constant, PlainClass** output);

#if defined(TEST_OPAQUE_VALUE_PARAMETER)
extern "C" void TakeOpaqueValue(OpaqueBase value);
#elif defined(TEST_OPAQUE_VALUE_RETURN)
extern "C" OpaqueBase ReturnOpaqueValue();
#elif defined(TEST_OPAQUE_VALUE_FIELD)
struct OpaqueValueField { OpaqueBase value; };
#elif defined(TEST_OPAQUE_VALUE_ARRAY)
struct OpaqueValueArray { OpaqueBase values[2]; };
#endif
