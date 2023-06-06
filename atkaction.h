#ifndef __ATK_ACTION_H__
#define __ATK_ACTION_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>

G_BEGIN_DECLS

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
  GTypeInterface parent;

  /*< public >*/
  gboolean                (*do_action)         (AtkAction         *action,
                                                gint              i);
  gint                    (*get_n_actions)     (AtkAction         *action);
  const gchar*            (*get_description)   (AtkAction         *action,
                                                gint              i);
  const gchar*            (*get_name)          (AtkAction         *action,
                                                gint              i);
  const gchar*            (*get_keybinding)    (AtkAction         *action,
                                                gint              i);
  gboolean                (*set_description)   (AtkAction         *action,
                                                gint              i,
                                                const gchar       *desc);
  const gchar*            (*get_localized_name)(AtkAction         *action,
						gint              i);
};

ATK_AVAILABLE_IN_ALL
GType atk_action_get_type (void);

ATK_AVAILABLE_IN_ALL
gboolean   atk_action_do_action                (AtkAction         *action,
                                            gint              i);
ATK_AVAILABLE_IN_ALL
gint   atk_action_get_n_actions            (AtkAction *action);
ATK_AVAILABLE_IN_ALL
const gchar*          atk_action_get_description  (AtkAction         *action,
                                                   gint              i);
ATK_AVAILABLE_IN_ALL
const gchar*          atk_action_get_name         (AtkAction         *action,
                                                   gint              i);
ATK_AVAILABLE_IN_ALL
const gchar*          atk_action_get_keybinding   (AtkAction         *action,
                                                   gint              i);
ATK_AVAILABLE_IN_ALL
gboolean              atk_action_set_description  (AtkAction         *action,
                                                   gint              i,
                                                   const gchar       *desc);

ATK_AVAILABLE_IN_ALL
const gchar* atk_action_get_localized_name (AtkAction       *action,
						     gint            i);

G_END_DECLS

#endif /* __ATK_ACTION_H__ */
