#include "config.h"

#include "atk.h"

#include <string.h>

#define NUM_POSSIBLE_STATES               (sizeof(AtkState)*8)

AtkStateType
atk_state_type_register (const gchar *name)
{
    return 0;
}

const gchar*
atk_state_type_get_name (AtkStateType type)
{
    return 0;
}

AtkStateType
atk_state_type_for_name (const gchar *name)
{

    return 0;
}
