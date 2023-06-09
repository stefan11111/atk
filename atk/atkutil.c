#include "config.h"

#include "atkutil.h"
#include "atkmarshal.h"

typedef struct _AtkUtilListenerInfo AtkUtilListenerInfo;
struct _AtkUtilListenerInfo
{
  gint key;
  guint signal_id;
  gulong hook_id;
};

long unsigned int
atk_util_get_type (void)
{
  return G_TYPE_OBJECT;
}

typedef struct _FocusTracker FocusTracker;

struct _FocusTracker {
  guint index;
};

void
atk_focus_tracker_init (AtkEventListenerInit    init)
{
}

guint
atk_add_focus_tracker (AtkEventListener   focus_tracker)
{
    return 0;
}

void
atk_remove_focus_tracker (guint            tracker_id)
{
}

void
atk_focus_tracker_notify (AtkObject       *object)
{
}

guint
atk_add_global_event_listener (GSignalEmissionHook listener,
			       const gchar        *event_type)
{
    return 0;
}

void
atk_remove_global_event_listener (guint listener_id)
{
}

guint
atk_add_key_event_listener (AtkKeySnoopFunc listener, gpointer data)
{
    return 0;
}

void
atk_remove_key_event_listener (guint listener_id)
{
}
AtkObject*
atk_get_root (void)
{
    return 0;
}

AtkObject*
atk_get_focus_object (void)
{
    return 0;
}

const gchar*
atk_get_toolkit_name (void)
{
    return 0;
}

const gchar*
atk_get_toolkit_version (void)
{
    return 0;
}

const gchar *
atk_get_version (void)
{
  return VERSION;
}
