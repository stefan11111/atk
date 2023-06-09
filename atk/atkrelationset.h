#ifndef __ATK_RELATION_SET_H__
#define __ATK_RELATION_SET_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

G_BEGIN_DECLS

#include <atk/_glib-object.h>
#include <atk/atkobject.h>
#include <atk/atkrelation.h>

#define ATK_TYPE_RELATION_SET                     (atk_relation_set_get_type ())
#define ATK_RELATION_SET(obj)                     (G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_RELATION_SET, AtkRelationSet))
#define ATK_RELATION_SET_CLASS(klass)             (G_TYPE_CHECK_CLASS_CAST ((klass), ATK_TYPE_RELATION_SET, AtkRelationSetClass))
#define ATK_IS_RELATION_SET(obj)                  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_RELATION_SET))
#define ATK_IS_RELATION_SET_CLASS(klass)          (G_TYPE_CHECK_CLASS_TYPE ((klass), ATK_TYPE_RELATION_SET))
#define ATK_RELATION_SET_GET_CLASS(obj)           (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_RELATION_SET, AtkRelationSetClass))

typedef struct _AtkRelationSetClass       AtkRelationSetClass;


struct _AtkRelationSet
{
  GObject parent;

  GPtrArray *relations;
};

struct _AtkRelationSetClass
{
  GObjectClass parent;

  AtkFunction pad1;
  AtkFunction pad2;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_relation_set_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkRelationSet* atk_relation_set_new                  (void);
ATK_AVAILABLE_IN_ALL
gboolean        atk_relation_set_contains             (AtkRelationSet  *set,
                                                       AtkRelationType relationship);
ATK_AVAILABLE_IN_ALL
gboolean        atk_relation_set_contains_target      (AtkRelationSet  *set,
                                                       AtkRelationType relationship,
                                                       AtkObject       *target);
ATK_AVAILABLE_IN_ALL
void            atk_relation_set_remove               (AtkRelationSet  *set,
                                                       AtkRelation     *relation);
ATK_AVAILABLE_IN_ALL
void            atk_relation_set_add                  (AtkRelationSet  *set,
                                                       AtkRelation     *relation);
ATK_AVAILABLE_IN_ALL
int            atk_relation_set_get_n_relations      (AtkRelationSet  *set);
ATK_AVAILABLE_IN_ALL
AtkRelation*    atk_relation_set_get_relation         (AtkRelationSet  *set,
                                                       int            i);
ATK_AVAILABLE_IN_ALL
AtkRelation*    atk_relation_set_get_relation_by_type (AtkRelationSet  *set,
                                                       AtkRelationType relationship);
ATK_AVAILABLE_IN_ALL
void            atk_relation_set_add_relation_by_type (AtkRelationSet  *set,
                                                       AtkRelationType relationship,
                                                       AtkObject       *target);

G_END_DECLS

#endif /* __ATK_RELATION_SET_H__ */
