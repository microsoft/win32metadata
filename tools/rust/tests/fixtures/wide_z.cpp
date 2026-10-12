typedef wchar_t WCHAR;
typedef const WCHAR* PCWSTR;

static_assert(sizeof(WCHAR) == 2);
static_assert(__is_same(WCHAR, wchar_t));

extern "C" _Win32_ImportLibrary_("wide-z.dll") void CaptureWide(
    _In_z_ const WCHAR* named,
    _In_z_ const wchar_t* direct,
    _In_ const WCHAR* unterminated,
    _In_ const unsigned short* numeric);
