#include "config.h"

#include "atkregistry.h"
#include "atknoopobjectfactory.h"

void
atk_registry_set_factory_type (AtkRegistry *registry,
                               GType type,
                               GType factory_type)
{
}

GType
atk_registry_get_factory_type (AtkRegistry *registry,
                               GType type)
{
    return 0;
}

AtkObjectFactory*
atk_registry_get_factory (AtkRegistry *registry,
                          GType type)
{
    return 0;
}

AtkRegistry*
atk_get_default_registry (void)
{
    return 0;
}
