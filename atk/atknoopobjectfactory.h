#ifndef __ATK_NO_OP_OBJECT_FACTORY_H__
#define __ATK_NO_OP_OBJECT_FACTORY_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobjectfactory.h>



#define ATK_TYPE_NO_OP_OBJECT_FACTORY                (atk_no_op_object_factory_get_type ())
#define ATK_NO_OP_OBJECT_FACTORY(obj)               (obj)
#define ATK_NO_OP_OBJECT_FACTORY_CLASS(klass)       (klass)
#define ATK_IS_NO_OP_OBJECT_FACTORY(obj)            0
#define ATK_IS_NO_OP_OBJECT_FACTORY_CLASS(klass)    0
#define ATK_NO_OP_OBJECT_FACTORY_GET_CLASS(obj)     (*(void**)(obj))

typedef struct _AtkNoOpObjectFactory                 AtkNoOpObjectFactory;
typedef struct _AtkNoOpObjectFactoryClass            AtkNoOpObjectFactoryClass;

struct _AtkNoOpObjectFactory
{
  AtkObjectFactory parent;
};

struct _AtkNoOpObjectFactoryClass
{
  AtkObjectFactoryClass parent_class;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_no_op_object_factory_get_type(void);

ATK_AVAILABLE_IN_ALL
AtkObjectFactory *atk_no_op_object_factory_new(void);



#endif /* __ATK_NO_OP_OBJECT_FACTORY_H__ */
