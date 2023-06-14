#ifndef __ATK_STATE_SET_H__
#define __ATK_STATE_SET_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/_glib-object.h>
#include <atk/atkobject.h>
#include <atk/atkstate.h>



#define ATK_TYPE_STATE_SET                        (atk_state_set_get_type ())
#define ATK_STATE_SET(obj)                        (obj)
#define ATK_STATE_SET_CLASS(klass)                (klass)
#define ATK_IS_STATE_SET(obj)                     0
#define ATK_IS_STATE_SET_CLASS(klass)             0
#define ATK_STATE_SET_GET_CLASS(obj)              (*(void**)(obj))

typedef struct _AtkStateSetClass       AtkStateSetClass;


struct _AtkStateSet
{
  struct GObject parent;

};

struct _AtkStateSetClass
{
  struct GObjectClass parent;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_state_set_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkStateSet*    atk_state_set_new               (void);
ATK_AVAILABLE_IN_ALL
unsigned char        atk_state_set_is_empty          (AtkStateSet  *set);
ATK_AVAILABLE_IN_ALL
unsigned char        atk_state_set_add_state         (AtkStateSet  *set,
                                                 unsigned long long type);
ATK_AVAILABLE_IN_ALL
void            atk_state_set_add_states        (AtkStateSet  *set,
                                                 unsigned long long *types,
                                                 int         n_types);
ATK_AVAILABLE_IN_ALL
void            atk_state_set_clear_states      (AtkStateSet  *set);
ATK_AVAILABLE_IN_ALL
unsigned char        atk_state_set_contains_state    (AtkStateSet  *set,
                                                 unsigned long long type);
ATK_AVAILABLE_IN_ALL
unsigned char        atk_state_set_contains_states   (AtkStateSet  *set,
                                                 unsigned long long *types,
                                                 int         n_types);
ATK_AVAILABLE_IN_ALL
unsigned char        atk_state_set_remove_state      (AtkStateSet  *set,
                                                 unsigned long long type);
ATK_AVAILABLE_IN_ALL
AtkStateSet*    atk_state_set_and_sets          (AtkStateSet  *set,
                                                 AtkStateSet  *compare_set);
ATK_AVAILABLE_IN_ALL
AtkStateSet*    atk_state_set_or_sets           (AtkStateSet  *set,
                                                 AtkStateSet  *compare_set);
ATK_AVAILABLE_IN_ALL
AtkStateSet*    atk_state_set_xor_sets          (AtkStateSet  *set,
                                                 AtkStateSet  *compare_set);



#endif /* __ATK_STATE_SET_H__ */
