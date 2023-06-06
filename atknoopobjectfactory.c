#include "config.h"

#include "atkobject.h"
#include "atknoopobject.h"
#include "atknoopobjectfactory.h"

GType
atk_no_op_object_factory_get_type (void)
{
    return 0;
}

AtkObjectFactory* 
atk_no_op_object_factory_new (void)
{
    return 0;
}
