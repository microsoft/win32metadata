//***************************************************************************
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
//  wbemtime.h
//
//  Purpose: declares the WBEMTime and WBEMTimeSpan objects which are 
//  similar to the MFC CTime and CTimeSpan objects.  The WBEM versions
//  are capable of storing down to the nsec and also have functions for
//  Creating from and getting BSTRs.
//
//  Note; The current implementation of WBEMTime does not support dates 
//  before 1601;
//
//***************************************************************************

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef WBEMTIME_HEADERFILE_IS_INCLUDED
#define WBEMTIME_HEADERFILE_IS_INCLUDED

#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define INVALID_TIME 0xffffffffffffffff

#include <polarity.h>
#include <time.h>
#pragma warning( disable : 4290 ) // Ignore 'C++ Exception Specification ignored'
#include <ProvExce.h>

///////////////////////////////////////////////////////////////////////////
// WBEMTimeSpan - This class holds time span values. 

class POLARITY WBEMTimeSpan 
{
private:

    ULONGLONG m_Time;
    friend class WBEMTime;

public:

    WBEMTimeSpan ()                                             { m_Time = INVALID_TIME ; }
    WBEMTimeSpan ( const BSTR bstrDMTFFormat )                  { *this = bstrDMTFFormat ; }

    WBEMTimeSpan ( 

        int iDays , 
        int iHours , 
        int iMinutes ,  
        int iSeconds , 
        int iMSec=0 , 
        int iUSec=0, 
        int iNSec=0 
    ) ;

    WBEMTimeSpan operator+ (const WBEMTimeSpan &uAdd ) const ;
    const WBEMTimeSpan &operator+= ( const WBEMTimeSpan &uAdd ) ;

    WBEMTimeSpan operator- (const WBEMTimeSpan &uSub ) const ;
    const WBEMTimeSpan &operator-= ( const WBEMTimeSpan &uSub ) ;

    const WBEMTimeSpan &operator= ( const BSTR pDMTFFormat ) ; 

    BOOL operator== ( const WBEMTimeSpan &a ) const             { return m_Time == a.m_Time ; }
    BOOL operator!= ( const WBEMTimeSpan &a ) const             { return m_Time != a.m_Time ; }
    BOOL operator<  ( const WBEMTimeSpan &a ) const             { return m_Time < a.m_Time ; }
    BOOL operator<= ( const WBEMTimeSpan &a ) const             { return m_Time <= a.m_Time ; }
    BOOL operator>  ( const WBEMTimeSpan &a ) const             { return m_Time > a.m_Time ; }
    BOOL operator>= ( const WBEMTimeSpan &a ) const             { return m_Time >= a.m_Time ; }

    BSTR GetBSTR ( void ) const throw ( CHeap_Exception ) ;

    bool IsOk () const                                          { return m_Time != INVALID_TIME ? true : false; }
    ULONGLONG GetTime () const                                  { return m_Time ; }
    void Clear ( void )                                         { m_Time = INVALID_TIME ; }
    
    // These are all deprecated
    WBEMTimeSpan ( const FILETIME &ft ) ;
    WBEMTimeSpan ( const time_t & t ) ;
    const WBEMTimeSpan &operator= ( const FILETIME &ft ) ;
    const WBEMTimeSpan &operator= ( const time_t &t ) ;
    BOOL Gettime_t ( time_t *ptime_t ) const ;
    BOOL GetFILETIME ( FILETIME *pst ) const ;

};

///////////////////////////////////////////////////////////////////////////
// WBEMTime - This class holds time values. 

class POLARITY WBEMTime 
{
public:

    WBEMTime ()                                                 { m_uTime = INVALID_TIME ; }
    WBEMTime ( const BSTR bstrDMTFFormat )                      { *this = bstrDMTFFormat ; }
    WBEMTime ( const SYSTEMTIME &st )                           { *this = st ; }
    WBEMTime ( const FILETIME &ft )                             { *this = ft ; }
    WBEMTime ( const struct tm &tmin )                          { *this = tmin ; }
    WBEMTime ( const time_t &t )                                { *this = t ; }

    WBEMTime        operator+ ( const WBEMTimeSpan &uAdd ) const ;
    const WBEMTime &operator+=( const WBEMTimeSpan &ts ) ;

    WBEMTimeSpan    operator- ( const WBEMTime &sub ) ;

    WBEMTime        operator- ( const WBEMTimeSpan &sub ) const;
    const WBEMTime &operator-=( const WBEMTimeSpan &sub );

    const WBEMTime &operator= ( const BSTR bstrDMTFFormat ) ; 
    const WBEMTime &operator= ( const SYSTEMTIME &st ) ;
    const WBEMTime &operator= ( const FILETIME &ft ) ;
    const WBEMTime &operator= ( const struct tm &tmin ) ;
    const WBEMTime &operator= ( const time_t & t) ;

    BOOL operator== ( const WBEMTime &a ) const                 { return m_uTime == a.m_uTime ; }
    BOOL operator!= ( const WBEMTime &a ) const                 { return m_uTime != a.m_uTime ; }
    BOOL operator<  ( const WBEMTime &a ) const                 { return m_uTime < a.m_uTime ; }
    BOOL operator<= ( const WBEMTime &a ) const                 { return m_uTime <= a.m_uTime ; }
    BOOL operator>  ( const WBEMTime &a ) const                 { return m_uTime > a.m_uTime ; }
    BOOL operator>= ( const WBEMTime &a ) const                 { return m_uTime >= a.m_uTime ; }

    BSTR GetBSTR ( void ) const throw ( CHeap_Exception ) ;
    BOOL GetStructtm (struct tm *ptm ) const;
    BOOL Gettime_t ( time_t *ptime_t ) const;
    BOOL GetSYSTEMTIME ( SYSTEMTIME *pst ) const;
    BOOL GetFILETIME ( FILETIME *pst ) const;

    BOOL SetDMTF ( const BSTR wszText ) ;
    BSTR GetDMTF ( BOOL bLocal = FALSE ) const throw ( CHeap_Exception ) ;

    BSTR GetDMTFNonNtfs(void) const ;

    void Clear ( void )                                         { m_uTime = INVALID_TIME ; }

    bool IsOk () const                                          { return m_uTime != INVALID_TIME ? true : false; }
    ULONGLONG GetTime () const                                  { return m_uTime ; }

    static LONG WINAPI GetLocalOffsetForDate(const struct tm *tmin);
    static LONG WINAPI GetLocalOffsetForDate(const SYSTEMTIME *pst);
    static LONG WINAPI GetLocalOffsetForDate(const FILETIME *pft);
    static LONG WINAPI GetLocalOffsetForDate(const time_t &t);

private:
    ULONGLONG m_uTime;
};


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif
