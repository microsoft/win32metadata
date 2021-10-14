
//
//  WIDEMATH.H
//
//  Portable (x86, x64, arm, arm64) 64-bit and 128-bit arithmetic math functions.
//
//  These are broken up into two main categories:
//
//    - wide integer operations, e.g. 128-bit add, sub, mul, div, shifts, rotates
//    - wide packed vector operations, e.g. 64-bit and 128-bit SIMD primitives
//
//  These functions are all implemented using portable 64-bit integer arithmetic.
//  Portability is achieved by using no CPU-specific intrinsics, types, or ASM.
//

#pragma once

#ifdef __cplusplus

extern "C"
{

#endif

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

typedef union uint128_t
{
    uint64_t   Q[2];
    uint32_t   D[4];
    uint16_t   W[8];
    uint8_t    B[16];

} uint128_t;

#define _BITS_PER_BYTE (8)
#define _BITS_PER_WORD (16)
#define _BITS_PER_LONG (32)
#define _BITS_PER_QUAD (64)

#define _WIDEMASK_BYTE (0x0101010101010101ull)
#define _WIDEMASK_WORD (0x0001000100010001ull)
#define _WIDEMASK_LONG (0x0000000100000001ull)
#define _WIDEMASK_QUAD (0x0000000000000001ull)

// Note that this is bit-reversed from the polynomial in the Intel manual
#define _CRC32_POLYNOMIAL (0x105EC76F1ull)

uint64_t POPCNT64(uint64_t X);

int64_t SMUL128(int64_t X, int64_t Y, int64_t *ResultHiOut);

uint64_t UMUL128(uint64_t X, uint64_t Y, uint64_t *ResultHiOut);

int64_t SDIV128(int64_t DividendHi, int64_t DividendLo, int64_t Divisor, int64_t *Remainder);

uint64_t UDIV128(uint64_t DividendHi, uint64_t DividendLo, uint64_t Divisor, uint64_t *Remainder);

uint64_t PADC64(uint64_t X, uint64_t Y, uint64_t C, uint64_t Mask);

uint64_t PADD64(uint64_t X, uint64_t Y, uint64_t Mask);

uint64_t PSUB64(uint64_t X, uint64_t Y, uint64_t Mask);

uint64_t PADDSI64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

uint64_t PADDSU64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

static __forceinline
uint64_t PAND64(uint64_t X, uint64_t Y)
{
    return X & Y;
}

static __forceinline
uint64_t PANDN64(uint64_t X, uint64_t Y)
{
    return (~X) & Y;
}

uint64_t PAVG64(uint64_t X, uint64_t Y, uint64_t Mask);

uint64_t PCMPEQ64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

uint64_t PCMPGT64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

int PEXTRW64(uint64_t X, unsigned Imm);

uint64_t PHADDSW64(uint64_t X, uint64_t Y);
uint64_t PHADDW64(uint64_t X, uint64_t Y);
uint64_t PHADDD64(uint64_t X, uint64_t Y);
uint64_t PHSUBSW64(uint64_t X, uint64_t Y);
uint64_t PHSUBW64(uint64_t X, uint64_t Y);
uint64_t PHSUBD64(uint64_t X, uint64_t Y);

uint64_t PINSRW64(uint64_t X, uint64_t Y, unsigned Imm);

uint64_t PMADDDD64(uint64_t X, uint64_t Y);
uint64_t PMADDUBSW64(uint64_t X, uint64_t Y);
uint64_t PMADDWD64(uint64_t X, uint64_t Y);

uint64_t PMAXI64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

uint64_t PMAXU64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

uint64_t PMINI64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

uint64_t PMINU64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

int PMOVMSKB64(uint64_t X);

uint64_t PMULHRSW64(uint64_t X, uint64_t Y);

uint64_t PMULHW64(uint64_t X, uint64_t Y);

uint64_t PMULLW64(uint64_t X, uint64_t Y);

uint64_t PMULHUW64(uint64_t X, uint64_t Y);

uint64_t PMULUDQ64(uint64_t X, uint64_t Y);

static __forceinline
uint64_t POR64(uint64_t X, uint64_t Y)
{
    return X | Y;
}

uint64_t PSADBW64(uint64_t X, uint64_t Y);

uint64_t PSIGN64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

uint64_t PSUBSI64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);
uint64_t PSUBSU64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

uint64_t PSLL64(uint64_t X, uint64_t ShiftCount, uint64_t Mask, unsigned DataWidth);
uint64_t PSRA64(uint64_t X, uint64_t ShiftCount, uint64_t Mask, unsigned DataWidth);
uint64_t PSRL64(uint64_t X, uint64_t ShiftCount, uint64_t Mask, unsigned DataWidth);

uint64_t PSHUFB64(uint64_t X, uint64_t Y);
uint64_t PSHUFW64(uint64_t Y, int Imm);

uint64_t PUNPCK64(uint64_t X, uint64_t Y, uint64_t SwizzleBytes);

static __forceinline
uint64_t PXOR64(uint64_t X, uint64_t Y)
{
    return X ^ Y;
}

uint64_t PACKSSWB64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);
uint64_t PACKUSWB64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);
uint64_t PACKSSDW64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);
uint64_t PACKUSDW64(uint64_t X, uint64_t Y, uint64_t Mask, unsigned DataWidth);

//
//  128-bit versions mainly just do pairs of the 64-bit versions.
//

uint128_t PACKSSWB128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PACKUSWB128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PACKSSDW128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PACKUSDW128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);

uint128_t PABS128(uint128_t Y, uint64_t Mask, unsigned DataWidth);

uint128_t PADD128(uint128_t X, uint128_t Y, uint64_t Mask);
uint128_t PADDSI128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PADDSU128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);

uint128_t PAND128(uint128_t X, uint128_t Y);
uint128_t PANDN128(uint128_t X, uint128_t Y);

uint128_t PALIGNR128(uint128_t X, uint128_t Y, uint64_t ShiftCount);

uint128_t PAVG128(uint128_t X, uint128_t Y, uint64_t Mask);

uint128_t PBLENDVB128(uint128_t X, uint128_t Y, uint128_t Mask);
uint128_t PBLENDW128(uint128_t X, uint128_t Y, unsigned Mask);

uint128_t PCLMULQDQ128(uint128_t X, uint128_t Y, unsigned Imm);

uint128_t PCMPEQ128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PCMPGT128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);

uint32_t PCMPESTRF128(uint128_t X, int LenX, uint128_t Y, int LenY, int Imm);
uint32_t PCMPESTRI128(uint128_t X, int LenX, uint128_t Y, int LenY, int Imm, uint32_t *Eflags);
uint128_t PCMPESTRM128(uint128_t X, int LenX, uint128_t Y, int LenY, int Imm, uint32_t *Eflags);
uint32_t PCMPISTRF128(uint128_t X, uint128_t Y, unsigned Imm);
uint32_t PCMPISTRI128(uint128_t X, uint128_t Y, unsigned Imm, uint32_t *Eflags);
uint128_t PCMPISTRM128(uint128_t X, uint128_t Y, unsigned Imm, uint32_t *Eflags);

int PEXTRB128(uint128_t X, unsigned Imm);
int PEXTRW128(uint128_t X, unsigned Imm);
int PEXTRD128(uint128_t X, unsigned Imm);
int64_t PEXTRQ128(uint128_t X, unsigned Imm);

uint128_t PMADDWD128(uint128_t X, uint128_t Y);
uint128_t PHADDPW128(uint128_t X, uint128_t Y);
uint128_t PHADDSW128(uint128_t X, uint128_t Y);
uint128_t PHADDW128(uint128_t X, uint128_t Y);
uint128_t PHADDD128(uint128_t X, uint128_t Y);

uint128_t PHMINPOSUW128(uint128_t Y);

uint128_t PHSUBSW128(uint128_t X, uint128_t Y);
uint128_t PHSUBW128(uint128_t X, uint128_t Y);
uint128_t PHSUBD128(uint128_t X, uint128_t Y);

uint128_t PINSRB128(uint128_t X, uint64_t Y, unsigned Imm);
uint128_t PINSRD128(uint128_t X, uint64_t Y, unsigned Imm);
uint128_t PINSRQ128(uint128_t X, uint64_t Y, unsigned Imm);
uint128_t PINSRW128(uint128_t X, uint64_t Y, unsigned Imm);

uint128_t PMADDDD128(uint128_t X, uint128_t Y);
uint128_t PMADDUBSW128(uint128_t X, uint128_t Y);
uint128_t PMADDWD128(uint128_t X, uint128_t Y);

uint128_t PMAXI128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PMAXU128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);

uint128_t PMINI128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PMINU128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);

int PMOVMSKB128(uint128_t X);

uint128_t PMOVSXBW128(uint64_t X);
uint128_t PMOVSXBD128(uint64_t X);
uint128_t PMOVSXBQ128(uint64_t X);
uint128_t PMOVSXWD128(uint64_t X);
uint128_t PMOVSXWQ128(uint64_t X);
uint128_t PMOVSXDQ128(uint64_t X);

uint128_t PMOVZXBW128(uint64_t X);
uint128_t PMOVZXBD128(uint64_t X);
uint128_t PMOVZXBQ128(uint64_t X);
uint128_t PMOVZXWD128(uint64_t X);
uint128_t PMOVZXWQ128(uint64_t X);
uint128_t PMOVZXDQ128(uint64_t X);

uint128_t PMULDQ128(uint128_t X, uint128_t Y);
uint128_t PMULHRSW128(uint128_t X, uint128_t Y);
uint128_t PMULHUW128(uint128_t X, uint128_t Y);
uint128_t PMULHW128(uint128_t X, uint128_t Y);
uint128_t PMULLD128(uint128_t X, uint128_t Y);
uint128_t PMULLW128(uint128_t X, uint128_t Y);
uint128_t PMULUDQ128(uint128_t X, uint128_t Y);

uint128_t POR128(uint128_t X, uint128_t Y);

uint128_t PSADBW128(uint128_t X, uint128_t Y);

uint128_t PSIGN128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);

uint128_t PSLL128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PSLLDQ(uint128_t X, uint64_t ShiftCount);
uint128_t PSRA128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PSRL128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PSRLDQ(uint128_t X, uint64_t ShiftCount);

uint128_t PSUB128(uint128_t X, uint128_t Y, uint64_t Mask);
uint128_t PSUBSI128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);
uint128_t PSUBSU128(uint128_t X, uint128_t Y, uint64_t Mask, unsigned DataWidth);

uint128_t PSHUFB128(uint128_t X, uint128_t Y);
uint128_t PSHUFD128(uint128_t Y, int Imm);

uint32_t PTESTC128(uint128_t X, uint128_t Y);
uint32_t PTESTZ128(uint128_t X, uint128_t Y);

uint128_t PUNPCK128(uint128_t X, uint128_t Y, uint64_t SwizzleBytes);
uint128_t PUNPCKH128(uint128_t X, uint128_t Y, uint64_t SwizzleBytes);
uint128_t PUNPCKHBW128(uint128_t X, uint128_t Y);
uint128_t PUNPCKHWD128(uint128_t X, uint128_t Y);
uint128_t PUNPCKHDQ128(uint128_t X, uint128_t Y);
uint128_t PUNPCKLBW128(uint128_t X, uint128_t Y);
uint128_t PUNPCKLWD128(uint128_t X, uint128_t Y);
uint128_t PUNPCKLDQ128(uint128_t X, uint128_t Y);
uint128_t PUNPCKQ128(uint128_t X, uint128_t Y);
uint128_t PUNPCKHQ128(uint128_t X, uint128_t Y);

uint128_t PXOR128(uint128_t X, uint128_t Y);

//
//  SSE floating point related operations
//

uint128_t MOVDDUP128(uint128_t X);

uint128_t MOVSLDUP128(uint128_t X);
uint128_t MOVSHDUP128(uint128_t X);

int MOVMSKPD128(uint128_t X);
int MOVMSKPS128(uint128_t X);

uint128_t MPSADBW128(uint128_t X, uint128_t Y, unsigned Imm);

unsigned UCOMIS64(uint64_t X, uint64_t Y, unsigned IsDouble);
unsigned UCOMISS128(uint128_t X, uint128_t Y);
unsigned UCOMISD128(uint128_t X, uint128_t Y) ;

uint128_t ADDPD128(uint128_t X, uint128_t Y);
uint128_t ADDPS128(uint128_t X, uint128_t Y);
uint128_t ADDSD128(uint128_t X, uint128_t Y);
uint128_t ADDSS128(uint128_t X, uint128_t Y);

uint64_t ADDSD64(uint64_t X, uint64_t Y);
unsigned ADDSS64(uint64_t X, uint64_t Y);

uint128_t ADDSUBPD128(uint128_t X, uint128_t Y);
uint128_t ADDSUBPS128(uint128_t X, uint128_t Y);

uint128_t AESDEC128(uint128_t X, uint128_t Y);
uint128_t AESDECLAST128(uint128_t X, uint128_t Y);
uint128_t AESENC128(uint128_t X, uint128_t Y);
uint128_t AESENCLAST128(uint128_t X, uint128_t Y);
uint128_t AESIMC128(uint128_t Y);
uint128_t AESKEYGENASSIST128(uint128_t Y, unsigned Imm);

uint128_t BLENDPD128(uint128_t X, uint128_t Y, unsigned Mask);
uint128_t BLENDPS128(uint128_t X, uint128_t Y, unsigned Mask);
uint128_t BLENDVPD128(uint128_t X, uint128_t Y, uint128_t Mask);
uint128_t BLENDVPS128(uint128_t X, uint128_t Y, uint128_t Mask);

uint64_t CMPSD64(uint64_t X, uint64_t Y, int Operation);
unsigned CMPSS64(uint64_t X, uint64_t Y, int Operation);
uint128_t CMPPD128(uint128_t X, uint128_t Y, int Operation);
uint128_t CMPPS128(uint128_t X, uint128_t Y, int Operation);

uint128_t CLMULQDQ64(uint64_t X, uint64_t Y);

uint32_t _CRC64(uint32_t X, uint64_t Y, uint64_t Polynomial, unsigned Datawidth);

uint32_t _CVTSI2SS32(int32_t I32);
uint32_t CVTSI2SS64S(int64_t I64, uint16_t *FPStatus);
uint32_t CVTSI2SS64(int64_t I64);

uint128_t CVTDQ2PS128(uint128_t X);

uint64_t CVTSI2SD64S(int64_t I64, uint16_t *FPStatus);
uint64_t CVTSI2SD64(int64_t I64);

uint128_t CVTSI2SD80(int64_t I64);
uint128_t CVTSD2SD80(int64_t F64);

uint128_t CVTDQ2PD128(uint64_t X);

uint128_t CVTPI2PD128(uint64_t X);

uint64_t CVTPI2PS128(uint64_t X);

uint32_t CVTSD2SS64S(uint64_t X, uint16_t * FPStatus);
uint32_t CVTSD2SS64(uint64_t X);
uint128_t CVTSD2SS128(uint128_t X, uint128_t Y);

uint64_t CVTSS2SD64(uint64_t X);
uint128_t CVTSS2SD128(uint128_t X, uint128_t Y);

uint32_t _CVTSD2SI32(uint64_t X, unsigned RoundingMode);
uint64_t _CVTSD2SI64(uint64_t X, unsigned RoundingMode);
uint32_t _CVTSS2SI32(uint32_t X, unsigned RoundingMode);

uint128_t CVTPD2DQ128(uint128_t X, unsigned RoundingMode);
uint128_t CVTTPD2DQ128(uint128_t X);

uint128_t CVTPS2DQ128(uint128_t X, unsigned RoundingMode);
uint128_t CVTTPS2DQ128(uint128_t X);

uint64_t CVTPD2PI128(uint128_t X, unsigned RoundingMode);
uint64_t CVTTPD2PI128(uint128_t X);

uint64_t CVTPS2PI128(uint64_t X, unsigned RoundingMode);
uint64_t CVTTPS2PI128(uint64_t X);

uint128_t CVTSI2SD128(uint128_t X, int64_t Y);
uint128_t CVTSI2SS128(uint128_t X, int64_t Y);

uint128_t DIVPD128(uint128_t X, uint128_t Y);
uint128_t DIVPS128(uint128_t X, uint128_t Y);
uint128_t DIVSD128(uint128_t X, uint128_t Y);
uint128_t DIVSS128(uint128_t X, uint128_t Y);

uint64_t DIVSD64(uint64_t X, uint64_t Y);
unsigned DIVSS64(uint64_t X, uint64_t Y);

uint128_t DPPD128(uint128_t X, uint128_t Y, unsigned Imm);
uint128_t DPPS128(uint128_t X, uint128_t Y, unsigned Imm);

uint128_t HADDPD128(uint128_t X, uint128_t Y);
uint128_t HADDPS128(uint128_t X, uint128_t Y);

uint128_t HSUBPD128(uint128_t X, uint128_t Y);
uint128_t HSUBPS128(uint128_t X, uint128_t Y);

uint128_t INSERTPS128(uint128_t X, uint128_t Y, unsigned Imm);

uint128_t MAXPD128(uint128_t X, uint128_t Y);
uint128_t MAXPS128(uint128_t X, uint128_t Y);
uint128_t MAXSD128(uint128_t X, uint128_t Y);
uint128_t MAXSS128(uint128_t X, uint128_t Y);

uint64_t MAXSD64(uint64_t X, uint64_t Y);
unsigned MAXSS64(uint64_t X, uint64_t Y);

uint128_t MINPD128(uint128_t X, uint128_t Y);
uint128_t MINPS128(uint128_t X, uint128_t Y);
uint128_t MINSD128(uint128_t X, uint128_t Y);
uint128_t MINSS128(uint128_t X, uint128_t Y);

uint64_t MINSD64(uint64_t X, uint64_t Y);
unsigned MINSS64(uint64_t X, uint64_t Y);

uint128_t MULPD128(uint128_t X, uint128_t Y);
uint128_t MULPS128(uint128_t X, uint128_t Y);
uint128_t MULSD128(uint128_t X, uint128_t Y);
uint128_t MULSS128(uint128_t X, uint128_t Y);

uint64_t MULSD64(uint64_t X, uint64_t Y);
unsigned MULSS64(uint64_t X, uint64_t Y);

uint128_t ROUNDSD128(uint128_t X, uint128_t Y, unsigned RoundingMode);
uint128_t ROUNDSS128(uint128_t X, uint128_t Y, unsigned RoundingMode);
uint128_t ROUNDPD128(uint128_t Y, unsigned RoundingMode);
uint128_t ROUNDPS128(uint128_t Y, unsigned RoundingMode);

unsigned RCPSS64(uint64_t Y);
uint128_t RCPSS128(uint128_t Y);
uint128_t RCPPS128(uint128_t Y);

unsigned RSQRTSS64(uint64_t Y);
uint128_t RSQRTSS128(uint128_t Y);
uint128_t RSQRTPS128(uint128_t Y);

uint128_t SQRTPD128(uint128_t Y);
uint128_t SQRTPS128(uint128_t Y);
uint128_t SQRTSD128(uint128_t X, uint128_t Y);
uint128_t SQRTSS128(uint128_t Y);

unsigned SQRTSS64(uint64_t X);
uint64_t SQRTSD64(uint64_t X);

uint128_t SHUFPD128(uint128_t X, uint128_t Y, unsigned Imm);
uint128_t SHUFPS128(uint128_t X, uint128_t Y, unsigned Imm);

uint128_t SUBPD128(uint128_t X, uint128_t Y);
uint128_t SUBPS128(uint128_t X, uint128_t Y);
uint128_t SUBSD128(uint128_t X, uint128_t Y);
uint128_t SUBSS128(uint128_t X, uint128_t Y);

uint64_t SUBSD64(uint64_t X, uint64_t Y);
unsigned SUBSS64(uint64_t X, uint64_t Y);

uint128_t UNPCKHPD128(uint128_t X, uint128_t Y);
uint128_t UNPCKHPS128(uint128_t X, uint128_t Y);
uint128_t UNPCKLPD128(uint128_t X, uint128_t Y);
uint128_t UNPCKLPS128(uint128_t X, uint128_t Y);

//
// Misc.
//

uint128_t SETZERO(void);

uint128_t BROADCAST128(uint64_t X, unsigned DataWidth);

void CPUIDEX64(int CPUInfo[4], int Function, int Subfunction);

uint64_t RDTSC64(void);
uint64_t RDTSCP64(unsigned int *p);

void _FXRSTOR(void const *);
void _FXRSTOR64(void const *);
void _FXSAVE(void *);
void _FXSAVE64(void *);

#ifdef __cplusplus

}  // extern "C"

#endif

