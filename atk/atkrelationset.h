#ifndef __ATK_RELATION_SET_H__
#define __ATK_RELATION_SET_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atkrelation.h>

#define ATK_TYPE_RELATION_SET                     (atk_relation_set_get_type ())
#define ATK_RELATION_SET(obj)                     (obj)
#define ATK_RELATION_SET_CLASS(klass)             (klass)
#define ATK_IS_RELATION_SET(obj)                  0
#define ATK_IS_RELATION_SET_CLASS(klass)          0
#define ATK_RELATION_SET_GET_CLASS(obj)           (*(void**)(obj))

typedef struct _AtkRelationSetClass       AtkRelationSetClass;


struct _AtkRelationSet
{
  struct GObject parent;

  void *relations;
};

struct _AtkRelationSetClass
{
  struct GObjectClass parent;

  AtkFunction pad1;
  AtkFunction pad2;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_relation_set_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkRelationSet* atk_relation_set_new                  (void);
ATK_AVAILABLE_IN_ALL
unsigned char        atk_relation_set_contains             (AtkRelationSet  *set,
                                                       AtkRelationType relationship);
ATK_AVAILABLE_IN_ALL
unsigned char        atk_relation_set_contains_target      (AtkRelationSet  *set,
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



#endif /* __ATK_RELATION_SET_H__ */
