#include "config.h"

#include <atk/_glib-object.h>

#include "atkobject.h"
#include "atkstateset.h"

#define ATK_STATE(state_enum)             ((AtkState)((guint64)1 << ((state_enum)%64)))

struct _AtkRealStateSet
{
  GObject parent;

  AtkState state;
};

typedef struct _AtkRealStateSet      AtkRealStateSet;

long unsigned int
atk_state_set_get_type (void)
{
    return 0;
}

AtkStateSet*
atk_state_set_new (void)
{
  return 0;
}

gboolean
atk_state_set_is_empty (AtkStateSet   *set)
{
    return 1;
}

gboolean
atk_state_set_add_state (AtkStateSet   *set,
                         AtkStateType  type)
{
    return 0;
}

void
atk_state_set_add_states (AtkStateSet   *set,
                          AtkStateType  *types,
                          int          n_types)
{
}

void
atk_state_set_clear_states (AtkStateSet   *set)
{
}

gboolean
atk_state_set_contains_state (AtkStateSet   *set,
                              AtkStateType  type)
{
    return 0;
}

gboolean
atk_state_set_contains_states (AtkStateSet   *set,
                               AtkStateType  *types,
                               int          n_types)
{
    return 0;
}

gboolean
atk_state_set_remove_state (AtkStateSet  *set,
                            AtkStateType type)
{
    return 0;
}

AtkStateSet*
atk_state_set_and_sets (AtkStateSet  *set,
                        AtkStateSet  *compare_set)
{
    return 0;
}

AtkStateSet*
atk_state_set_or_sets (AtkStateSet  *set,
                       AtkStateSet  *compare_set)
{
    return 0;
}

AtkStateSet*
atk_state_set_xor_sets (AtkStateSet  *set,
                        AtkStateSet  *compare_set)
{
    return 0;
}
