#include "config.h"

#include <string.h>
#include <glib-object.h>
#include "atk.h"

enum {
  PROP_0,

  PROP_RELATION_TYPE,
  PROP_TARGET,
  PROP_LAST
};

GType
atk_relation_get_type (void)
{
    return 0;
}

AtkRelationType
atk_relation_type_register (const gchar *name)
{
    return 0;
}

const gchar*
atk_relation_type_get_name (AtkRelationType type)
{
    return 0;
}

AtkRelationType
atk_relation_type_for_name (const gchar *name)
{
    return 0;
}

AtkRelation*
atk_relation_new (AtkObject       **targets,
                  gint            n_targets,
                  AtkRelationType relationship)
{
    return 0;
}

AtkRelationType
atk_relation_get_relation_type (AtkRelation *relation)
{
    return 0;
}

GPtrArray*
atk_relation_get_target (AtkRelation *relation)
{
    return 0;
}

void
atk_relation_add_target (AtkRelation *relation,
                         AtkObject   *target)
{
}

gboolean
atk_relation_remove_target (AtkRelation *relation,
                            AtkObject *target)
{
    return 0;
}