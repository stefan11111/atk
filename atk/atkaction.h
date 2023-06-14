#ifndef __ATK_ACTION_H__
#define __ATK_ACTION_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_ACTION                    (atk_action_get_type ())
#define ATK_IS_ACTION(obj)                 0
#define ATK_ACTION(obj)                    (obj)
#define ATK_ACTION_GET_IFACE(obj)          (*(void**)(obj))

#ifndef _TYPEDEF_ATK_ACTION_
#define _TYPEDEF_ATK_ACTION_
typedef struct _AtkAction AtkAction;
#endif
typedef struct _AtkActionIface AtkActionIface;

struct _AtkActionIface
{
  /*< private >*/
  long unsigned int* parent;

  /*< public >*/
  unsigned char                (*do_action)         (AtkAction         *action,
                                                int              i);
  int                    (*get_n_actions)     (AtkAction         *action);
  const char*            (*get_description)   (AtkAction         *action,
                                                int              i);
  const char*            (*get_name)          (AtkAction         *action,
                                                int              i);
  const char*            (*get_keybinding)    (AtkAction         *action,
                                                int              i);
  unsigned char                (*set_description)   (AtkAction         *action,
                                                int              i,
                                                const char       *desc);
  const char*            (*get_localized_name)(AtkAction         *action,
						int              i);
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_action_get_type (void);

ATK_AVAILABLE_IN_ALL
unsigned char   atk_action_do_action                (AtkAction         *action,
                                            int              i);
ATK_AVAILABLE_IN_ALL
int   atk_action_get_n_actions            (AtkAction *action);
ATK_AVAILABLE_IN_ALL
const char*          atk_action_get_description  (AtkAction         *action,
                                                   int              i);
ATK_AVAILABLE_IN_ALL
const char*          atk_action_get_name         (AtkAction         *action,
                                                   int              i);
ATK_AVAILABLE_IN_ALL
const char*          atk_action_get_keybinding   (AtkAction         *action,
                                                   int              i);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_action_set_description  (AtkAction         *action,
                                                   int              i,
                                                   const char       *desc);

ATK_AVAILABLE_IN_ALL
const char* atk_action_get_localized_name (AtkAction       *action,
						     int            i);



#endif /* __ATK_ACTION_H__ */
