#ifndef __ATK_ACTION_H__
#define __ATK_ACTION_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_ACTION                    (atk_action_get_type ())
#define ATK_IS_ACTION(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_ACTION)
#define ATK_ACTION(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_ACTION, AtkAction)
#define ATK_ACTION_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_ACTION, AtkActionIface))

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
  unsigned char                (*do_action)         ();
  int                    (*get_n_actions)     ();
  const char*            (*get_description)   ();
  const char*            (*get_name)          ();
  const char*            (*get_keybinding)    ();
  unsigned char                (*set_description)   ();
  const char*            (*get_localized_name)();
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_action_get_type (void);

ATK_AVAILABLE_IN_ALL
unsigned char   atk_action_do_action                ();
ATK_AVAILABLE_IN_ALL
int   atk_action_get_n_actions            ();
ATK_AVAILABLE_IN_ALL
const char*          atk_action_get_description  ();
ATK_AVAILABLE_IN_ALL
const char*          atk_action_get_name         ();
ATK_AVAILABLE_IN_ALL
const char*          atk_action_get_keybinding   ();
ATK_AVAILABLE_IN_ALL
unsigned char              atk_action_set_description  ();

ATK_AVAILABLE_IN_ALL
const char* atk_action_get_localized_name ();



#endif /* __ATK_ACTION_H__ */
