struct __declspec(uuid("12345678-1234-1234-1234-123456789abc")) IRetvalSources
{
    virtual /* [propget] */ int get_Both(
        /* [out][retval] */ _Out_retval_ int* value) = 0;
    virtual /* [propget] */ int get_MidlOnly(
        /* [out][retval] */ int* value) = 0;
    virtual /* [propget] */ int get_SalOnly(
        _Out_retval_ int* value) = 0;
    virtual /* [propget] */ int get_Plain(
        /* [out] */ int* value) = 0;
};
