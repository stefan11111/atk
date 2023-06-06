#include "config.h"

#include <glib-object.h>

#include "atk.h"

GType
atk_relation_set_get_type (void)
{
    return 0;
}

AtkRelationSet*
atk_relation_set_new (void)
{
    return 0;
}

gboolean
atk_relation_set_contains (AtkRelationSet   *set,
                           AtkRelationType  relationship)
{
    return 0;
}

void
atk_relation_set_remove (AtkRelationSet *set,
                         AtkRelation    *relation)
{
}

void
atk_relation_set_add (AtkRelationSet *set,
                      AtkRelation    *relation)
{
}

gint
atk_relation_set_get_n_relations (AtkRelationSet *set)
{
    return 0;
}

AtkRelation*
atk_relation_set_get_relation (AtkRelationSet *set,
                               gint           i)
{
    return 0;
}

AtkRelation*
atk_relation_set_get_relation_by_type (AtkRelationSet  *set,
                                       AtkRelationType relationship)
{
    return 0;
}

void
atk_relation_set_add_relation_by_type (AtkRelationSet  *set,
                                       AtkRelationType relationship,
                                       AtkObject       *target)
{
}

gboolean
atk_relation_set_contains_target (AtkRelationSet  *set,
                                  AtkRelationType relationship,
                                  AtkObject       *target)
{
    return 0;
}
