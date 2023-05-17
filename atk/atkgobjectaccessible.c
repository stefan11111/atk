#include "config.h"

#include <atk/atkgobjectaccessible.h>
#include <atk/atkregistry.h>
#include <atk/atkutil.h>

GType
atk_gobject_accessible_get_type (void)
{
    return 0;
}

AtkObject*
atk_gobject_accessible_for_object (GObject *obj)
{
    return 0;
}

GObject *
atk_gobject_accessible_get_object (AtkGObjectAccessible *obj)
{
    return 0;
}
