//
// wchar.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// All of the types, macros, and function declarations for all wide-character
// related functionality.  Most of the functionality is in the #included
// <corecrt_wxxxx.h> headers, which are also #included by other public headers.
//
#pragma once
#ifndef _INC_WCHAR // include guard for 3rd party interop
#define _INC_WCHAR

#include <corecrt.h>
#include <corecrt_memcpy_s.h>
#include <corecrt_wconio.h>
#include <corecrt_wctype.h>
#include <corecrt_wdirect.h>
#include <corecrt_wio.h>
#include <corecrt_wprocess.h>
#include <corecrt_wstdio.h>
#include <corecrt_wstdlib.h>
#include <corecrt_wstring.h>
#include <corecrt_wtime.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <vcruntime_string.h>
#if !defined(_M_CEE)
#include <intrin.h>
#if defined(__clang__) && (defined(_M_ARM64) || defined(_M_ARM64EC))
#include <arm_neon.h>
#endif
#endif

#pragma warning(push)
#pragma warning(disable: _UCRT_DISABLED_WARNINGS)
_UCRT_DISABLE_CLANG_WARNINGS

_CRT_BEGIN_C_HEADER



#define WCHAR_MIN 0x0000
#define WCHAR_MAX 0xffff



typedef wchar_t _Wint_t;



#if _CRT_FUNCTIONS_REQUIRED

    _Check_return_opt_ _Success_(return != 0) _Ret_z_
    _ACRTIMP wchar_t* __cdecl _wsetlocale(
        _In_       int            _Category,
        _In_opt_z_ wchar_t const* _Locale
        );

    _Check_return_opt_
    _ACRTIMP _locale_t __cdecl _wcreate_locale(
        _In_   int            _Category,
        _In_z_ wchar_t const* _Locale
        );



    _ACRTIMP wint_t __cdecl btowc(
        _In_ int _Ch
        );

    _ACRTIMP size_t __cdecl mbrlen(
        _In_reads_bytes_opt_(_SizeInBytes) _Pre_opt_z_ char const* _Ch,
        _In_                                           size_t      _SizeInBytes,
        _Inout_                                        mbstate_t*  _State
        );

    _ACRTIMP size_t __cdecl mbrtowc(
        _Pre_maybenull_ _Post_z_                       wchar_t*    _DstCh,
        _In_reads_bytes_opt_(_SizeInBytes) _Pre_opt_z_ char const* _SrcCh,
        _In_                                           size_t      _SizeInBytes,
        _Inout_                                        mbstate_t*  _State
        );

    _Success_(return == 0)
    _ACRTIMP errno_t __cdecl mbsrtowcs_s(
        _Out_opt_                         size_t*      _Retval,
        _Out_writes_opt_z_(_Size)         wchar_t*     _Dst,
        _In_                              size_t       _Size,
        _Deref_pre_opt_z_                 char const** _PSrc,
        _In_                              size_t       _N,
        _Inout_                           mbstate_t*   _State
        );

    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(
        _Success_(return == 0)
        errno_t, mbsrtowcs_s,
        _Out_opt_                         size_t*,      _Retval,
        _Post_z_                          wchar_t,      _Dest,
        _Inout_ _Deref_prepost_opt_valid_ char const**, _PSource,
        _In_                              size_t,       _Count,
        _Inout_                           mbstate_t*,   _State
        )

    __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE(
        _Success_(return == 0) _ACRTIMP, mbsrtowcs,
        _Out_writes_opt_z_(_Count),           wchar_t,      _Dest,
        _Deref_pre_opt_z_                 char const**, _PSrc,
        _In_                              size_t,       _Count,
        _Inout_                           mbstate_t*,   _State
        )

    _Success_(return == 0)
    _ACRTIMP errno_t __cdecl wcrtomb_s(
        _Out_opt_                        size_t*    _Retval,
        _Out_writes_opt_z_(_SizeInBytes) char*      _Dst,
        _In_                             size_t     _SizeInBytes,
        _In_                             wchar_t    _Ch,
        _Inout_opt_                      mbstate_t* _State
        );

    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(
        _Success_(return == 0)
        errno_t, wcrtomb_s,
        _Out_opt_                 size_t*,    _Retval,
        _Out_writes_opt_z_(_Size) char,       _Dest,
        _In_                      wchar_t,    _Source,
        _Inout_opt_               mbstate_t*, _State
        )

    __DEFINE_CPP_OVERLOAD_STANDARD_FUNC_0_2_SIZE(
        _ACRTIMP, wcrtomb,
        _Pre_maybenull_ _Post_z_, char,       _Dest,
        _In_                      wchar_t,    _Source,
        _Inout_opt_              mbstate_t*, _State
        )

    _Success_(return == 0)
    _ACRTIMP errno_t __cdecl wcsrtombs_s(
        _Out_opt_                                         size_t*         _Retval,
        _Out_writes_bytes_to_opt_(_SizeInBytes, *_Retval) char*           _Dst,
        _In_                                              size_t          _SizeInBytes,
        _Inout_ _Deref_prepost_z_                         wchar_t const** _Src,
        _In_                                              size_t          _Size,
        _Inout_opt_                                       mbstate_t*      _State
        );

    __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(
        _Success_(return == 0)
        errno_t, wcsrtombs_s,
        _Out_opt_                 size_t*,         _Retval,
        _Out_writes_opt_z_(_Size) char,            _Dest,
        _Inout_ _Deref_prepost_z_ wchar_t const**, _PSrc,
        _In_                      size_t,          _Count,
        _Inout_opt_               mbstate_t*,      _State
        )

    __DEFINE_CPP_OVERLOAD_STANDARD_NFUNC_0_3_SIZE(
        _ACRTIMP, wcsrtombs,
        _Pre_maybenull_ _Post_z_, char,            _Dest,
        _Inout_ _Deref_prepost_z_ wchar_t const**, _PSource,
        _In_                      size_t,          _Count,
        _Inout_opt_               mbstate_t*,      _State
        )

    _ACRTIMP int __cdecl wctob(
        _In_ wint_t _WCh
        );

    #if __STDC_WANT_SECURE_LIB__

        _Success_(return == 0)
        errno_t __CRTDECL wmemcpy_s(
            _Out_writes_to_opt_(_N1, _N) wchar_t*       _S1,
            _In_                         rsize_t        _N1,
            _In_reads_opt_(_N)           wchar_t const* _S2,
            _In_                         rsize_t        _N
            );

        _Success_(return == 0)
        errno_t __CRTDECL wmemmove_s(
            _Out_writes_to_opt_(_N1, _N) wchar_t*       _S1,
            _In_                         rsize_t        _N1,
            _In_reads_opt_(_N)           wchar_t const* _S2,
            _In_                         rsize_t        _N
            );

    #endif // __STDC_WANT_SECURE_LIB__

    __inline int __CRTDECL fwide(
        _In_opt_ FILE* _F,
        _In_     int   _M
        )
    {
        _CRT_UNUSED(_F);
        return (_M);
    }

    __inline int __CRTDECL mbsinit(
        _In_opt_ mbstate_t const* _P
        )
    {
        return _P == NULL || _P->_Wchar == 0;
    }

    #if !defined(_M_CEE)
    #if (defined(_M_IX86) && !defined(_M_HYBRID_X86_ARM64)) || (defined(_M_X64) && !defined(_M_ARM64EC))
    extern int _Avx2WmemEnabled;
    __declspec(selectany) int _Avx2WmemEnabledWeakValue = 0;
    #if defined(_M_IX86)
    #pragma comment(linker, "/alternatename:__Avx2WmemEnabled=__Avx2WmemEnabledWeakValue")
    #else
    #pragma comment(linker, "/alternatename:_Avx2WmemEnabled=_Avx2WmemEnabledWeakValue")
    #endif
    #endif
    #endif

    __inline wchar_t _CONST_RETURN* __CRTDECL wmemchr(
        _In_reads_(_N) wchar_t const* _S,
        _In_           wchar_t        _C,
        _In_           size_t         _N
        )
    {
        size_t Count = 0;

    #if !defined(_M_CEE)

        unsigned long Index = 0;
        wchar_t const* S = _S;

    #if defined(_M_ARM64) || defined(_M_ARM64EC) || defined(_M_HYBRID_X86_ARM64)
        if (_N >= 4)
        {
            uint16x8_t V2 = vdupq_n_u16(_C);

            while (Count + 8 <= _N)
            {
                uint16x8_t V1 = vreinterpretq_u16_u8(vld1q_u8((unsigned char const *)S));
                V1 = vceqq_u16(V1, V2);
                unsigned __int64 Mask = vget_lane_u64(vreinterpret_u64_u8(vshrn_n_u16(V1, 4)), 0);
                if (Mask != 0)
                {
                    _BitScanForward64(&Index, Mask);
                    Index >>= 3;
                    return (wchar_t _CONST_RETURN*)&_S[Count + Index];
                }

                Count += 8;
                S += 8;
            }

            if (Count + 4 <= _N)
            {
                uint16x8_t V1 = vdupq_lane_u64(vreinterpret_u16_u8(vld1_u8((unsigned char const *)S)), 0);
                V1 = vceqq_u16(V1, V2);
                unsigned int Mask = vget_lane_u32(vreinterpret_u32_u8(vshrn_n_u16(V1, 4)), 0);
                if (Mask != 0)
                {
                    _BitScanForward(&Index, Mask);
                    Index >>= 3;
                    return (wchar_t _CONST_RETURN*)&_S[Count + Index];
                }

                Count += 4;
            }
        }

    #elif defined(_M_IX86) || defined(_M_X64) 

    #if !defined(__clang__) || defined(__AVX2__)
        if (_Avx2WmemEnabled && _N >= 16)
        {
            __m256i V2 = _mm256_broadcastw_epi16(_mm_cvtsi32_si128(_C));

            do
            {
                __m256i V1 = _mm256_loadu_si256((__m256i const*)S);
                V1 = _mm256_cmpeq_epi16(V1, V2);
                unsigned int Mask = (unsigned int)_mm256_movemask_epi8(V1);
                if (Mask != 0)
                {
                    _BitScanForward(&Index, Mask);
                    Index >>= 1;
                    return (wchar_t _CONST_RETURN*)&_S[Count + Index];
                }
                Count += 16;
                S += 16;
            } while (Count + 16 <= _N);
        }
    #endif

        if (Count + 4 <= _N)
        {
            __m128i V2 = _mm_set1_epi16((short)_C);

            while (Count + 8 <= _N)
            {
                __m128i V1 = _mm_loadu_si128((__m128i const*)S);
                V1 = _mm_cmpeq_epi16(V1, V2);
                unsigned short Mask = (unsigned short)_mm_movemask_epi8(V1);
                if (Mask != 0)
                {
                    _BitScanForward(&Index, Mask);
                    Index >>= 1;
                    return (wchar_t _CONST_RETURN*)&_S[Count + Index];
                }
                Count += 8;
                S += 8;
            }

            if (Count + 4 <= _N)
            {
                __m128i V1 = _mm_loadu_si64(S);
                V1 = _mm_cmpeq_epi16(V1, V2);
                unsigned char Mask = (unsigned char)_mm_movemask_epi8(V1);
                if (Mask != 0)
                {
                    _BitScanForward(&Index, Mask);
                    Index >>= 1;
                    return (wchar_t _CONST_RETURN*)&_S[Count + Index];
                }

                Count += 4;
            }
        }

    #endif // defined(_M_IX86) || defined(_M_X64)
    #endif // !defined(_M_CEE)

        for (; Count < _N; ++Count)
        {
            if (_S[Count] == _C)
            {
                return (wchar_t _CONST_RETURN*)&_S[Count];
            }
        }

        return NULL;
    }

    __inline int __CRTDECL wmemcmp(
        _In_reads_(_N) wchar_t const* _S1,
        _In_reads_(_N) wchar_t const* _S2,
        _In_           size_t         _N
        )
    {
        size_t Count = 0;

    #if !defined(_M_CEE)

        unsigned long Index = 0;
        wchar_t const* S1 = _S1;
        wchar_t const* S2 = _S2;

    #if defined(_M_ARM64) || defined(_M_ARM64EC) || defined(_M_HYBRID_X86_ARM64)

        while (Count + 8 <= _N)
        {
            uint16x8_t V1 = vreinterpretq_u16_u8(vld1q_u8((unsigned char const *)S1));
            uint16x8_t V2 = vreinterpretq_u16_u8(vld1q_u8((unsigned char const *)S2));
            V1 = vceqq_u16(V1, V2);
            unsigned __int64 Mask = vget_lane_u64(vreinterpret_u64_u8(vshrn_n_u16(V1, 4)), 0);
            Mask = ~Mask;
            if (Mask != 0)
            {
                _BitScanForward64(&Index, Mask);
                Index >>= 3;
                return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
            }

            Count += 8;
            S1 += 8;
            S2 += 8;
        }

        if (Count + 4 <= _N)
        {
            uint16x4_t V1 = vreinterpret_u16_u8(vld1_u8((unsigned char const *)S1));
            uint16x4_t V2 = vreinterpret_u16_u8(vld1_u8((unsigned char const *)S2));
            V1 = veor_u16(V1, V2);
            unsigned __int64 Mask = vget_lane_u64(V1, 0);
            if (Mask != 0)
            {
                _BitScanForward64(&Index, Mask);
                Index >>= 4;
                return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
            }

            Count += 4;
        }

    #elif defined(_M_IX86) || defined(_M_X64)

    #if !defined(__clang__) || defined(__AVX2__)
        if (_Avx2WmemEnabled)
        {
            while (Count + 16 <= _N)
            {
                __m256i V1 = _mm256_loadu_si256((__m256i const*)S1);
                __m256i V2 = _mm256_loadu_si256((__m256i const*)S2);
                V1 = _mm256_cmpeq_epi16(V1, V2);
                unsigned int Mask = (unsigned int)_mm256_movemask_epi8(V1);
                if (Mask != 0xffffffff)
                {
                    _BitScanForward(&Index, ~Mask);
                    Index >>= 1;
                    return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
                }
                Count += 16;
                S1 += 16;
                S2 += 16;
            }
        }
    #endif

        while (Count + 8 <= _N)
        {
            __m128i V1 = _mm_loadu_si128((__m128i const*)S1);
            __m128i V2 = _mm_loadu_si128((__m128i const*)S2);
            V1 = _mm_cmpeq_epi16(V1, V2);
            unsigned short Mask = (unsigned short)_mm_movemask_epi8(V1);
            if (Mask != 0xffff)
            {
                _BitScanForward(&Index, (unsigned long)~Mask);
                Index >>= 1;
                return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
            }
            Count += 8;
            S1 += 8;
            S2 += 8;
        }

    #if defined(_M_IX86)
        if (Count + 4 <= _N)
        {
            __m128i V1 = _mm_loadu_si64(S1);
            __m128i V2 = _mm_loadu_si64(S2);
            V1 = _mm_cmpeq_epi16(V1, V2);
            unsigned char Mask = (unsigned char)_mm_movemask_epi8(V1);
            if (Mask != 0xff)
            {
                _BitScanForward(&Index, (unsigned long)~Mask);
                Index >>= 1;
                return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
            }

            Count += 4;
        }
    #else
        if (Count + 4 <= _N)
        {
            unsigned __int64 V1 = *(unsigned __int64*)S1;
            unsigned __int64 V2 = *(unsigned __int64*)S2;
            if (V1 != V2)
            {
                _BitScanForward64(&Index, (V1 ^ V2));
                Index >>= 4;
                return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
            }

            Count += 4;
        }
    #endif // defined(_M_IX86)
    #endif // defined(_M_IX86) || defined(_M_X64)
    #endif // !defined(_M_CEE)

        for (; Count < _N; ++Count)
        {
            if (_S1[Count] != _S2[Count])
            {
                return _S1[Count] < _S2[Count] ? -1 : 1;
            }
        }

        return 0;
    }

    _Post_equal_to_(_S1)
    _At_buffer_(_S1, _Iter_, _N, _Post_satisfies_(_S1[_Iter_] == _S2[_Iter_]))
    __inline _CRT_INSECURE_DEPRECATE_MEMORY(wmemcpy_s)
    wchar_t* __CRTDECL wmemcpy(
        _Out_writes_all_(_N) wchar_t*       _S1,
        _In_reads_(_N)       wchar_t const* _S2,
        _In_                 size_t         _N
        )
    {
        #pragma warning(suppress: 6386) // Buffer overrun
        return (wchar_t*)memcpy(_S1, _S2, _N*sizeof(wchar_t));
    }

    __inline _CRT_INSECURE_DEPRECATE_MEMORY(wmemmove_s)
    wchar_t* __CRTDECL wmemmove(
        _Out_writes_all_opt_(_N) wchar_t*       _S1,
        _In_reads_opt_(_N)       wchar_t const* _S2,
        _In_                     size_t         _N
        )
    {
        #pragma warning(suppress: 6386) // Buffer overrun
        return (wchar_t*)memmove(_S1, _S2, _N*sizeof(wchar_t));
    }

    _Post_equal_to_(_S)
    _At_buffer_(_S, _Iter_, _N, _Post_satisfies_(_S[_Iter_] == _C))
    __inline wchar_t* __CRTDECL wmemset(
        _Out_writes_all_(_N) wchar_t* _S,
        _In_                 wchar_t  _C,
        _In_                 size_t   _N
        )
    {
        wchar_t *_Su = _S;
        for (; 0 < _N; ++_Su, --_N)
        {
            *_Su = _C;
        }
        return _S;
    }

    #ifdef __cplusplus

        extern "C++" inline wchar_t* __CRTDECL wmemchr(
            _In_reads_(_N) wchar_t* _S,
            _In_           wchar_t  _C,
            _In_           size_t   _N
            )
        {
            wchar_t const* const _SC = _S;
            return const_cast<wchar_t*>(wmemchr(_SC, _C, _N));
        }

    #endif // __cplusplus

#endif // _CRT_FUNCTIONS_REQUIRED


_CRT_END_C_HEADER
_UCRT_RESTORE_CLANG_WARNINGS
#pragma warning(pop) // _UCRT_DISABLED_WARNINGS
#endif // _INC_WCHAR
