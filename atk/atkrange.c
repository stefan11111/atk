#include "config.h"

#include "atkvalue.h"

struct _AtkRange {
  double lower;
  double upper;
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
atk_range_new  (double   lower_limit,
                double   upper_limit,
                const char *description)
{
    return 0;
}

double
atk_range_get_lower_limit  (AtkRange *range)
{
    return 0;
}

double
atk_range_get_upper_limit (AtkRange *range)
{
    return 0;
}

const char*
atk_range_get_description  (AtkRange *range)
{
    return 0;
}
