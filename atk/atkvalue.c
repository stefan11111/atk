#include "config.h"

#include "atkvalue.h"
#include "atkmarshal.h"
#include "atk-enum-types.h"
#include "atkprivate.h"

enum {
  VALUE_CHANGED,
  LAST_SIGNAL
};

/* These are listed here for extraction by intltool */
#if 0

N_("very weak")

N_("weak")

N_("acceptable")

N_("strong")

N_("very strong")

N_("very low")

N_("medium")

N_("high")

N_("very high")

N_("very bad")

N_("bad")

N_("good")

N_("very good")

N_("best")
#endif

long unsigned int
atk_value_get_type (void)
{
    return 0;
}

void
atk_value_get_current_value (AtkValue *obj,
                             GValue   *value)
{
}

void
atk_value_get_maximum_value  (AtkValue *obj,
                              GValue   *value)
{
}

void
atk_value_get_minimum_value (AtkValue *obj,
                             GValue   *value)
{
}

void
atk_value_get_minimum_increment (AtkValue *obj,
                             GValue   *value)
{
}

unsigned char
atk_value_set_current_value (AtkValue       *obj, 
                             const GValue   *value)
{
    return 0;
}

void
atk_value_get_value_and_text (AtkValue *obj,
                              gdouble *value,
                              char  **text)
{
}

AtkRange*
atk_value_get_range (AtkValue *obj)
{
    return 0;
}

gdouble
atk_value_get_increment (AtkValue *obj)
{
    return 0;
}

GSList*
atk_value_get_sub_ranges (AtkValue *obj)
{
    return 0;
}

void
atk_value_set_value (AtkValue     *obj,
                     const gdouble new_value)
{
}

const char*
atk_value_type_get_name (AtkValueType value_type)
{
    return 0;
}

const char*
atk_value_type_get_localized_name (AtkValueType value_type)
{
    return 0;
}
