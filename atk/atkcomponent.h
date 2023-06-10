#ifndef __ATK_COMPONENT_H__
#define __ATK_COMPONENT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include "atk/atkobject.h"
#include <atk/atkutil.h>



typedef enum {
  ATK_SCROLL_TOP_LEFT,
  ATK_SCROLL_BOTTOM_RIGHT,
  ATK_SCROLL_TOP_EDGE,
  ATK_SCROLL_BOTTOM_EDGE,
  ATK_SCROLL_LEFT_EDGE,
  ATK_SCROLL_RIGHT_EDGE,
  ATK_SCROLL_ANYWHERE
} AtkScrollType;

#define ATK_TYPE_COMPONENT                    (atk_component_get_type ())
#define ATK_IS_COMPONENT(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_COMPONENT)
#define ATK_COMPONENT(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_COMPONENT, AtkComponent)
#define ATK_COMPONENT_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_COMPONENT, AtkComponentIface))

#ifndef _TYPEDEF_ATK_COMPONENT_
#define _TYPEDEF_ATK_COMPONENT_
typedef struct _AtkComponent AtkComponent;
#endif
typedef struct _AtkComponentIface  AtkComponentIface;

typedef void (*AtkFocusHandler) ();

typedef struct _AtkRectangle       AtkRectangle;

struct _AtkRectangle
{
  int x;
  int y;
  int width;
  int height;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_rectangle_get_type (void);

#define ATK_TYPE_RECTANGLE (atk_rectangle_get_type ())

struct _AtkComponentIface
{
  /*< private >*/
  long unsigned int* parent;

  /*< public >*/
  unsigned int          (* add_focus_handler)  ();

  unsigned char       (* contains)           ();

  AtkObject*    (* ref_accessible_at_point)  ();
  void          (* get_extents)         ();
  void                     (* get_position)     ();
  void                     (* get_size)                 ();
  unsigned char                 (* grab_focus)               ();
  unsigned char                 (* set_extents)      ();
  unsigned char                 (* set_position)     ();
  unsigned char                 (* set_size)         ();
  	
  AtkLayer                 (* get_layer)        ();
  int                     (* get_mdi_zorder)   ();


  void                     (* bounds_changed)   ();
  gdouble                  (* get_alpha)        ();


  unsigned char                (*scroll_to)          ();

  unsigned char                (*scroll_to_point)    ();
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_component_get_type (void);

#endif /* __ATK_COMPONENT_H__ */
