#ifndef __ATK_GOBJECT_ACCESSIBLE_H__
#define __ATK_GOBJECT_ACCESSIBLE_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_GOBJECT_ACCESSIBLE            (atk_gobject_accessible_get_type ())
#define ATK_GOBJECT_ACCESSIBLE(obj)            (obj)
#define ATK_GOBJECT_ACCESSIBLE_CLASS(klass)    (klass)
#define ATK_IS_GOBJECT_ACCESSIBLE(obj)         0
#define ATK_IS_GOBJECT_ACCESSIBLE_CLASS(klass) 0
#define ATK_GOBJECT_ACCESSIBLE_GET_CLASS(obj)  (*(void**)(obj))

typedef struct _AtkGObjectAccessible                AtkGObjectAccessible;
typedef struct _AtkGObjectAccessibleClass           AtkGObjectAccessibleClass;

struct _AtkGObjectAccessible
{
  AtkObject parent;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_gobject_accessible_get_type (void);

struct _AtkGObjectAccessibleClass
{
  AtkObjectClass parent_class;

  AtkFunction pad1;
  AtkFunction pad2;
};

ATK_AVAILABLE_IN_ALL
AtkObject *atk_gobject_accessible_for_object      (GObject           *obj);
ATK_AVAILABLE_IN_ALL
GObject   *atk_gobject_accessible_get_object      (AtkGObjectAccessible *obj);



#endif /* __ATK_GOBJECT_ACCESSIBLE_H__ */
