#include "config.h"

#include <atk/atkgobjectaccessible.h>
#include <atk/atkregistry.h>
#include <atk/atkutil.h>

long unsigned int
atk_gobject_accessible_get_type (void)
{
    return 0;
}

AtkObject*
atk_gobject_accessible_for_object (void* obj)
{
    return 0;
}

void*
atk_gobject_accessible_get_object (AtkGObjectAccessible *obj)
{
    return 0;
}
