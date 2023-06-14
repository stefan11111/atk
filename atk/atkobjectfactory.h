#ifndef __ATK_OBJECT_FACTORY_H__
#define __ATK_OBJECT_FACTORY_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/_glib-object.h>
#include <atk/atkobject.h>



#define ATK_TYPE_OBJECT_FACTORY                     (atk_object_factory_get_type ())
#define ATK_OBJECT_FACTORY(obj)                     (obj)
#define ATK_OBJECT_FACTORY_CLASS(klass)             (klass)
#define ATK_IS_OBJECT_FACTORY(obj)                  0
#define ATK_IS_OBJECT_FACTORY_CLASS(klass)          0
#define ATK_OBJECT_FACTORY_GET_CLASS(obj)           (*(void**)(obj))

typedef struct _AtkObjectFactory                AtkObjectFactory;
typedef struct _AtkObjectFactoryClass           AtkObjectFactoryClass;

struct _AtkObjectFactory
{
  struct GObject parent;
};

struct _AtkObjectFactoryClass
{
  GObjectClass parent_class;

  void** (* create_accessible) ();
  void       (* invalidate)        ();
  long unsigned int      (* get_accessible_type)    (void);

  AtkFunction pad1;
  AtkFunction pad2;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_object_factory_get_type(void);


ATK_AVAILABLE_IN_ALL
void* atk_object_factory_create_accessible ();
ATK_AVAILABLE_IN_ALL
void       atk_object_factory_invalidate ();
ATK_AVAILABLE_IN_ALL
long unsigned int      atk_object_factory_get_accessible_type ();



#endif /* __GTK_OBJECT_FACTORY_H__ */
