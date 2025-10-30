/***************************************************************************
 *
 *  msacmdlg.h
 *
 *  Copyright (c) 1991-1995 Microsoft Corporation.  All Rights Reserved.
 *
 *  Description:
 *      Audio Compression Manager Common Dialogs Identifiers
 *
 ***************************************************************************/

#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#define DLG_ACMFORMATCHOOSE_ID              70
#define IDD_ACMFORMATCHOOSE_BTN_HELP        9
#define IDD_ACMFORMATCHOOSE_CMB_CUSTOM      100
#define IDD_ACMFORMATCHOOSE_CMB_FORMATTAG   101
#define IDD_ACMFORMATCHOOSE_CMB_FORMAT      102
#define IDD_ACMFORMATCHOOSE_BTN_SETNAME     103
#define IDD_ACMFORMATCHOOSE_BTN_DELNAME     104


#define DLG_ACMFILTERCHOOSE_ID              71
#define IDD_ACMFILTERCHOOSE_BTN_HELP        9
#define IDD_ACMFILTERCHOOSE_CMB_CUSTOM      100
#define IDD_ACMFILTERCHOOSE_CMB_FILTERTAG   101
#define IDD_ACMFILTERCHOOSE_CMB_FILTER      102
#define IDD_ACMFILTERCHOOSE_BTN_SETNAME     103
#define IDD_ACMFILTERCHOOSE_BTN_DELNAME     104


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


