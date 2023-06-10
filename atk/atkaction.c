#include "config.h"

#include "atkaction.h"

long unsigned int
atk_action_get_type (void)
{
    return 0;
}

gboolean
atk_action_do_action (AtkAction *obj,
                      int      i)
{
    return 0;
}

int
atk_action_get_n_actions  (AtkAction *obj)
{

    return 0;
}

const char*
atk_action_get_description (AtkAction *obj,
                            int      i)
{
    return 0;
}

const char*
atk_action_get_name (AtkAction *obj,
                     int      i)
{
    return 0;
}

const char*
atk_action_get_localized_name (AtkAction *obj,
                               int      i)
{
    return 0;
}

const char*
atk_action_get_keybinding (AtkAction *obj,
                           int      i)
{
    return 0;
}

gboolean
atk_action_set_description (AtkAction   *obj,
                            int        i,
                            const char *desc)
{
    return 0;
}
