#include "config.h"

#include "atkselection.h"

enum {
  SELECTION_CHANGED,
  LAST_SIGNAL
};

long unsigned int
atk_selection_get_type (void)
{
    return 0;
}

gboolean
atk_selection_add_selection (AtkSelection *obj,
                             gint         i)
{
    return 0;
}

gboolean
atk_selection_clear_selection (AtkSelection *obj)
{
    return 0;
}

AtkObject*
atk_selection_ref_selection (AtkSelection *obj,
                             gint         i)
{
    return 0;
}

gint
atk_selection_get_selection_count (AtkSelection *obj)
{
    return 0;
}

gboolean
atk_selection_is_child_selected (AtkSelection *obj,
                                 gint         i)
{
    return 0;
}

gboolean
atk_selection_remove_selection (AtkSelection *obj,
                                gint         i)
{
    return 0;
}

gboolean
atk_selection_select_all_selection (AtkSelection *obj)
{
    return 0;
}
