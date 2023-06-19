#include "config.h"

#include "atk.h"
#include "atknoopobject.h"

long unsigned int
atk_no_op_object_get_type (void)
{
    return 0;
}

AtkObject*
atk_no_op_object_new (GObject *obj)
{
    return 0;
}

