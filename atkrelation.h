#ifndef __ATK_RELATION_H__
#define __ATK_RELATION_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

G_BEGIN_DECLS

#include <glib-object.h>
#include <atk/atkrelationtype.h>
#include <atk/atkversion.h>

#define ATK_TYPE_RELATION                         (atk_relation_get_type ())
#define ATK_RELATION(obj)                         (G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_RELATION, AtkRelation))
#define ATK_RELATION_CLASS(klass)                 (G_TYPE_CHECK_CLASS_CAST ((klass), ATK_TYPE_RELATION, AtkRelationClass))
#define ATK_IS_RELATION(obj)                      (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_RELATION))
#define ATK_IS_RELATION_CLASS(klass)              (G_TYPE_CHECK_CLASS_TYPE ((klass), ATK_TYPE_RELATION))
#define ATK_RELATION_GET_CLASS(obj)               (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_RELATION, AtkRelationClass))

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
GType atk_relation_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkRelationType       atk_relation_type_register      (const gchar     *name);
ATK_AVAILABLE_IN_ALL
const gchar*          atk_relation_type_get_name      (AtkRelationType type);
ATK_AVAILABLE_IN_ALL
AtkRelationType       atk_relation_type_for_name      (const gchar     *name);

/*
 * Create a new relation for the specified key and the specified list
 * of targets.
 */
ATK_AVAILABLE_IN_ALL
AtkRelation*          atk_relation_new                (AtkObject       **targets,
                                                       gint            n_targets,
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
gboolean              atk_relation_remove_target      (AtkRelation     *relation,
                                                       AtkObject       *target);

G_END_DECLS

#endif /* __ATK_RELATION_H__ */