/*++

Copyright (c) 1990-1999,  Microsoft Corporation  All rights reserved.

Module Name:

    colordlg.h

Abstract:

    This module contains the header information for the Win32 color dialog.

Revision History:

--*/


#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_COLORDLG
#define _INC_COLORDLG

#define DLG_COLOR          10

#define COLOR_HUESCROLL   700	       /* color dialog */
#define COLOR_SATSCROLL   701
#define COLOR_LUMSCROLL   702
#define COLOR_HUE         703
#define COLOR_SAT         704
#define COLOR_LUM         705
#define COLOR_RED         706
#define COLOR_GREEN       707
#define COLOR_BLUE        708
#define COLOR_CURRENT     709
#define COLOR_RAINBOW     710
#define COLOR_SAVE        711
#define COLOR_ADD         712
#define COLOR_SOLID       713
#define COLOR_TUNE        714
#define COLOR_SCHEMES     715
#define COLOR_ELEMENT     716
#define COLOR_SAMPLES     717
#define COLOR_PALETTE     718
#define COLOR_MIX         719
#define COLOR_BOX1        720
#define COLOR_CUSTOM1     721

#define COLOR_HUEACCEL    723
#define COLOR_SATACCEL    724
#define COLOR_LUMACCEL    725
#define COLOR_REDACCEL    726
#define COLOR_GREENACCEL  727
#define COLOR_BLUEACCEL   728

#define COLOR_SOLID_LEFT     730
#define COLOR_SOLID_RIGHT    731

#define NUM_BASIC_COLORS   48
#define NUM_CUSTOM_COLORS  16

#endif  /* !_INC_COLORDLG */
