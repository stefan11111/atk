

#include "atkobjectfactory.h"
#include "atknoopobjectfactory.h"

void*
atk_object_factory_create_accessible ()
{
    return 0;
}

void
atk_object_factory_invalidate ()
{
}

long unsigned int
atk_object_factory_get_accessible_type ()
{
    return 0;
}

long unsigned int
atk_object_factory_get_type(void)
{
    return 0;
}
