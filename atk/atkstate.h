#ifndef __ATK_STATE_H__
#define __ATK_STATE_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkversion.h>

typedef enum
{
  ATK_STATE_INVALID,
  ATK_STATE_ACTIVE,
  ATK_STATE_ARMED,
  ATK_STATE_BUSY,
  ATK_STATE_CHECKED,
  ATK_STATE_DEFUNCT,
  ATK_STATE_EDITABLE,
  ATK_STATE_ENABLED,
  ATK_STATE_EXPANDABLE,
  ATK_STATE_EXPANDED,
  ATK_STATE_FOCUSABLE,
  ATK_STATE_FOCUSED,
  ATK_STATE_HORIZONTAL,
  ATK_STATE_ICONIFIED,
  ATK_STATE_MODAL,
  ATK_STATE_MULTI_LINE,
  ATK_STATE_MULTISELECTABLE,
  ATK_STATE_OPAQUE,
  ATK_STATE_PRESSED,
  ATK_STATE_RESIZABLE,
  ATK_STATE_SELECTABLE,
  ATK_STATE_SELECTED,
  ATK_STATE_SENSITIVE,
  ATK_STATE_SHOWING,
  ATK_STATE_SINGLE_LINE,
  ATK_STATE_STALE,
  ATK_STATE_TRANSIENT,
  ATK_STATE_VERTICAL,
  ATK_STATE_VISIBLE,
  ATK_STATE_MANAGES_DESCENDANTS,
  ATK_STATE_INDETERMINATE,
  ATK_STATE_TRUNCATED,
  ATK_STATE_REQUIRED,
  ATK_STATE_INVALID_ENTRY,
  ATK_STATE_SUPPORTS_AUTOCOMPLETION,
  ATK_STATE_SELECTABLE_TEXT,
  ATK_STATE_DEFAULT,
  ATK_STATE_ANIMATED,
  ATK_STATE_VISITED,
  ATK_STATE_CHECKABLE,
  ATK_STATE_HAS_POPUP,
  ATK_STATE_HAS_TOOLTIP,
  ATK_STATE_READ_ONLY,
  ATK_STATE_COLLAPSED,
  ATK_STATE_LAST_DEFINED
} AtkStateType;

typedef unsigned long long      AtkState;

ATK_AVAILABLE_IN_ALL
unsigned long long atk_state_type_register            (const char *name);

ATK_AVAILABLE_IN_ALL
const char*          atk_state_type_get_name   (unsigned long long type);
ATK_AVAILABLE_IN_ALL
unsigned long long          atk_state_type_for_name   (const char  *name);



#endif /* __ATK_STATE_H__ */
