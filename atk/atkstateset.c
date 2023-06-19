#include "config.h"

#include "atkobject.h"
#include "atkstateset.h"

#define ATK_STATE(state_enum)             ((unsigned long long)((unsigned long long)1 << ((state_enum)%64)))

struct _AtkRealStateSet
{
  GObject parent;

  unsigned long long state;
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

unsigned char
atk_state_set_is_empty (AtkStateSet   *set)
{
    return 1;
}

unsigned char
atk_state_set_add_state (AtkStateSet   *set,
                         unsigned long long  type)
{
    return 0;
}

void
atk_state_set_add_states (AtkStateSet   *set,
                          unsigned long long  *types,
                          int          n_types)
{
}

void
atk_state_set_clear_states (AtkStateSet   *set)
{
}

unsigned char
atk_state_set_contains_state (AtkStateSet   *set,
                              unsigned long long  type)
{
    return 0;
}

unsigned char
atk_state_set_contains_states (AtkStateSet   *set,
                               unsigned long long  *types,
                               int          n_types)
{
    return 0;
}

unsigned char
atk_state_set_remove_state (AtkStateSet  *set,
                            unsigned long long type)
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
