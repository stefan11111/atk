#include "config.h"

#include "atkvalue.h"

struct _AtkRange {
  gdouble lower;
  gdouble upper;
  gchar *description;
};

AtkRange *
atk_range_copy (AtkRange *src)
{
    return 0;
}

void
atk_range_free (AtkRange *range)
{
}

G_DEFINE_BOXED_TYPE (AtkRange, atk_range, atk_range_copy,
                     atk_range_free)

AtkRange*
atk_range_new  (gdouble   lower_limit,
                gdouble   upper_limit,
                const gchar *description)
{
    return 0;
}

gdouble
atk_range_get_lower_limit  (AtkRange *range)
{
    return 0;
}

gdouble
atk_range_get_upper_limit (AtkRange *range)
{
    return 0;
}

const gchar*
atk_range_get_description  (AtkRange *range)
{
    return 0;
}
