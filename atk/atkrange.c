#include "config.h"

#include "atkvalue.h"

struct _AtkRange {
  gdouble lower;
  gdouble upper;
  char *description;
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

AtkRange*
atk_range_new  (gdouble   lower_limit,
                gdouble   upper_limit,
                const char *description)
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

const char*
atk_range_get_description  (AtkRange *range)
{
    return 0;
}
