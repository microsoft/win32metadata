#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _MENUEX_TEMPLATE_HEADER {
  WORD  wVersion;
  WORD  wOffset;
  DWORD dwHelpId;
} MENUEX_TEMPLATE_HEADER;

typedef struct _MENUEX_TEMPLATE_ITEM {
  DWORD dwType;
  DWORD dwState;
  UINT  uId;
  WORD  wFlags;
  WCHAR szText[1];
} MENUEX_TEMPLATE_ITEM;

typedef struct _MENUTEMPLATEEX {
    union {
            struct {
            MENUITEMTEMPLATEHEADER mitHeader;
            MENUITEMTEMPLATE miTemplate[ANYSIZE_ARRAY];
        } Menu;
            struct {
            MENUEX_TEMPLATE_HEADER mexHeader;
            MENUEX_TEMPLATE_ITEM mexItem[ANYSIZE_ARRAY];
        } MenuEx;
  };
} MENUTEMPLATEEX;

#ifdef __cplusplus
}
#endif