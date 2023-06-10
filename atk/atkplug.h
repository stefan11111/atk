#ifndef __ATK_PLUG_H__
#define __ATK_PLUG_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkversion.h>



#define ATK_TYPE_PLUG               (atk_plug_get_type ())
#define ATK_PLUG(obj)               ( ((obj), ATK_TYPE_PLUG, AtkPlug))
#define ATK_IS_PLUG(obj)            ( ((obj), ATK_TYPE_PLUG))
#define ATK_PLUG_CLASS(klass)       ( ((klass), ATK_TYPE_PLUG, AtkPlugClass))
#define ATK_IS_PLUG_CLASS(klass)    ( ((klass), ATK_TYPE_PLUG))
#define ATK_PLUG_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_PLUG, AtkPlugClass))

typedef struct _AtkPlug         AtkPlug;
typedef struct _AtkPlugClass    AtkPlugClass;

struct _AtkPlug
{
  AtkObject parent;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_plug_get_type (void);

struct _AtkPlugClass
{
  AtkObjectClass parent_class;
  
  /* to be subscribed to by atk-bridge */

  /*< protected >*/
  char* (* get_object_id) (AtkPlug* obj);
};

ATK_AVAILABLE_IN_ALL
AtkObject*    atk_plug_new       (void);
ATK_AVAILABLE_IN_2_36
void          atk_plug_set_child (AtkPlug *plug, AtkObject *child);
ATK_AVAILABLE_IN_ALL
char*        atk_plug_get_id    (AtkPlug* plug);



#endif /* __ATK_PLUG_H__ */
