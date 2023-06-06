#include "config.h"

#include "atk.h"

guint
atk_get_major_version (void)
{
  return ATK_MAJOR_VERSION;
}


guint
atk_get_minor_version (void)
{
  return ATK_MINOR_VERSION;
}

guint
atk_get_micro_version (void)
{
  return ATK_MICRO_VERSION;
}

guint
atk_get_binary_age (void)
{
  return ATK_BINARY_AGE;
}

guint
atk_get_interface_age (void)
{
  return ATK_INTERFACE_AGE;
}
