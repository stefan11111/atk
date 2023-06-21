#include "config.h"

#include "atkobjectfactory.h"
#include "atknoopobjectfactory.h"

AtkObject* 
atk_object_factory_create_accessible (AtkObjectFactory *factory,
                                      void*          obj)
{
    return 0;
} 

void 
atk_object_factory_invalidate (AtkObjectFactory *factory)
{
}

long unsigned int
atk_object_factory_get_accessible_type (AtkObjectFactory *factory)
{
    return 0;
}

long unsigned int
atk_object_factory_get_type(void)
{
    return 0;
}
