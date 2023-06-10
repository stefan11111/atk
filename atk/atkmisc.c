#include "config.h"

#include "atkmisc.h"

long unsigned int
atk_misc_get_type (void)
{
    return 0;
}

void
atk_misc_threads_enter (AtkMisc *misc)
{
}

void
atk_misc_threads_leave (AtkMisc *misc)
{
}

AtkMisc *atk_misc_instance = 0;

const AtkMisc *
atk_misc_get_instance (void)
{
  return 0;
}
