#include "config.h"

#include "atkobjectfactory.h"
#include "atknoopobjectfactory.h"

AtkObject* 
atk_object_factory_create_accessible (AtkObjectFactory *factory,
                                      GObject          *obj)
{
    return 0;
} 

void 
atk_object_factory_invalidate (AtkObjectFactory *factory)
{
}

GType
atk_object_factory_get_accessible_type (AtkObjectFactory *factory)
{
    return G_TYPE_INVALID;
}

GType
atk_object_factory_get_type(void)
{
    return G_TYPE_INVALID;
}
