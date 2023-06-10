#ifndef __ATK_RELATION_H__
#define __ATK_RELATION_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif



#include <atk/_glib-object.h>
#include <atk/atkrelationtype.h>
#include <atk/atkversion.h>

#define ATK_TYPE_RELATION                         (atk_relation_get_type ())
#define ATK_RELATION(obj)                         ( ((obj), ATK_TYPE_RELATION, AtkRelation))
#define ATK_RELATION_CLASS(klass)                 ( ((klass), ATK_TYPE_RELATION, AtkRelationClass))
#define ATK_IS_RELATION(obj)                      ( ((obj), ATK_TYPE_RELATION))
#define ATK_IS_RELATION_CLASS(klass)              ( ((klass), ATK_TYPE_RELATION))
#define ATK_RELATION_GET_CLASS(obj)               ( ((obj), ATK_TYPE_RELATION, AtkRelationClass))

typedef struct _AtkRelation            AtkRelation;
typedef struct _AtkRelationClass       AtkRelationClass;

struct _AtkRelation
{
  GObject parent;

  GPtrArray       *target;
  AtkRelationType relationship;
};

struct _AtkRelationClass
{
  GObjectClass parent;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_relation_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkRelationType       atk_relation_type_register      (const char     *name);
ATK_AVAILABLE_IN_ALL
const char*          atk_relation_type_get_name      (AtkRelationType type);
ATK_AVAILABLE_IN_ALL
AtkRelationType       atk_relation_type_for_name      (const char     *name);

/*
 * Create a new relation for the specified key and the specified list
 * of targets.
 */
ATK_AVAILABLE_IN_ALL
AtkRelation*          atk_relation_new                (AtkObject       **targets,
                                                       int            n_targets,
                                                       AtkRelationType relationship);
/*
 * Returns the type of a relation.
 */
ATK_AVAILABLE_IN_ALL
AtkRelationType       atk_relation_get_relation_type  (AtkRelation     *relation);
/*
 * Returns the target list of a relation.
 */
ATK_AVAILABLE_IN_ALL
GPtrArray*            atk_relation_get_target         (AtkRelation     *relation);
ATK_AVAILABLE_IN_ALL
void                  atk_relation_add_target         (AtkRelation     *relation,
                                                       AtkObject       *target);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_relation_remove_target      (AtkRelation     *relation,
                                                       AtkObject       *target);



#endif /* __ATK_RELATION_H__ */
