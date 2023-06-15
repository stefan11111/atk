

#include "atkobject.h"
#include "atknoopobject.h"
#include "atknoopobjectfactory.h"

long unsigned int
atk_no_op_object_factory_get_type (void)
{
    return 0;
}

AtkObjectFactory* 
atk_no_op_object_factory_new (void)
{
    return 0;
}
