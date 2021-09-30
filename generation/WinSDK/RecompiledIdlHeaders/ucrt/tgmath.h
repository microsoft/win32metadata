//
// tgmath.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// The type-generic math library.
//
#pragma once
#ifndef _TGMATH
#define _TGMATH

#include <corecrt.h>

#if (_CRT_HAS_CXX17 == 1) && !defined(_CRT_USE_C_TGMATH_H)

#include <ctgmath>

#else // ^^^^ /std:c++17 ^^^^ // vvvv _CRT_USE_C_TGMATH_H vvvv

#ifndef _CRT_SILENCE_NONCONFORMING_TGMATH_H

#pragma message(_CRT_WARNING_MESSAGE("UCRT4000", \
    "The Universal CRT implementation of tgmath.h does not conform to the C99 standard. " \
    "Functionality equivalent to the type-generic functions provided by tgmath.h is available " \
    "in <ctgmath> when compiling as C++. " \
    "If compiling in C++17 mode or higher (/std:c++17), this header will automatically include <ctgmath> instead. " \
    "You can define _CRT_SILENCE_NONCONFORMING_TGMATH_H to acknowledge that you have received this warning."))

#endif // _CRT_SILENCE_NONCONFORMING_TGMATH_H

#include <math.h>
#include <complex.h>

#endif // (_CRT_HAS_CXX17 == 1) && !defined(_CRT_USE_C_TGMATH_H)
#endif // _TGMATH
