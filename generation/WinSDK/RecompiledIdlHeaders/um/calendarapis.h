#include <windows.h>
#include <WinNls.h>

#ifdef __cplusplus
extern "C" {
#endif

enum CALDATETIME_DATEUNIT {
  EraUnit, 
  YearUnit, 
  MonthUnit, 
  WeekUnit, 
  DayUnit, 
  HourUnit, 
  MinuteUnit, 
  SecondUnit, 
  TickUnit
};

typedef struct _caldatetime {
  CALID CalId;
  UINT Era;
  UINT Year;
  UINT Month;
  UINT Day;
  UINT DayOfWeek;
  UINT Hour;
  UINT Minute;
  UINT Second;
  ULONG Tick;
} CALDATETIME, *LPCALDATETIME;

BOOL GetCalendarSupportedDateRange(
  _In_ CALID Calendar,
  _Out_ LPCALDATETIME lpCalMinDateTime,
  _Out_ LPCALDATETIME lpCalMaxDateTime
);

BOOL GetCalendarDateFormatEx(
  _In_ LPCWSTR lpszLocale,
  _In_ DWORD dwFlags,
  _In_ const LPCALDATETIME lpCalDateTime,
  _In_ LPCWSTR lpFormat,
  _Out_ LPWSTR lpDateStr,
  _In_ int cchDate
);

BOOL ConvertSystemTimeToCalDateTime(
  _In_ const SYSTEMTIME *lpSysTime,
  _In_ CALID calId,
  _Out_ LPCALDATETIME lpCalDateTime
);

BOOL UpdateCalendarDayOfWeek(
  _Inout_ LPCALDATETIME lpCalDateTime
);

BOOL AdjustCalendarDate(
  _Inout_ LPCALDATETIME lpCalDateTime,
  _In_ CALDATETIME_DATEUNIT calUnit,
  _Out_ INT amount
);

BOOL ConvertCalDateTimeToSystemTime(
  _In_ const LPCALDATETIME lpCalDateTime,
  _Out_ SYSTEMTIME *lpSysTime
);

BOOL IsCalendarLeapYear(
  _In_ CALID calId,
  _In_ UINT year,
  _In_ UINT era
);

#ifdef __cplusplus
}
#endif