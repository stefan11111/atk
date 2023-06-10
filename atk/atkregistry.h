#ifndef __ATK_REGISTRY_H__
#define __ATK_REGISTRY_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/_glib-object.h>
#include "atkobjectfactory.h"



#define ATK_TYPE_REGISTRY                (atk_registry_get_type ())
#define ATK_REGISTRY(obj)                ( ((obj), ATK_TYPE_REGISTRY, AtkRegistry))
#define ATK_REGISTRY_CLASS(klass)       ( ((klass), ATK_TYPE_REGISTRY, AtkRegistryClass))
#define ATK_IS_REGISTRY(obj)            ( ((obj), ATK_TYPE_REGISTRY))
#define ATK_IS_REGISTRY_CLASS(klass)     ( ((klass), ATK_TYPE_REGISTRY))
#define ATK_REGISTRY_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_REGISTRY, AtkRegistryClass))

struct _AtkRegistry
{
  GObject    parent;
  GHashTable *factory_type_registry;
  GHashTable *factory_singleton_cache;
};

struct _AtkRegistryClass
{
  GObjectClass    parent_class;
};

typedef struct _AtkRegistry             AtkRegistry;
typedef struct _AtkRegistryClass        AtkRegistryClass;


ATK_AVAILABLE_IN_ALL
long unsigned int             atk_registry_get_type         (void);
ATK_AVAILABLE_IN_ALL
void              atk_registry_set_factory_type (AtkRegistry *registry,
                                                 long unsigned int type,
                                                 long unsigned int factory_type);
ATK_AVAILABLE_IN_ALL
long unsigned int             atk_registry_get_factory_type (AtkRegistry *registry,
						 long unsigned int type);
ATK_AVAILABLE_IN_ALL
AtkObjectFactory* atk_registry_get_factory      (AtkRegistry *registry,
                                                 long unsigned int type);

ATK_AVAILABLE_IN_ALL
AtkRegistry*      atk_get_default_registry      (void);



#endif /* __ATK_REGISTRY_H__ */

