#ifndef __ATK_COMPONENT_H__
#define __ATK_COMPONENT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include "atk/atkobject.h"
#include <atk/atkutil.h>

G_BEGIN_DECLS

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

typedef void (*AtkFocusHandler) (AtkObject* object, gboolean focus_in);

typedef struct _AtkRectangle       AtkRectangle;

struct _AtkRectangle
{
  gint x;
  gint y;
  gint width;
  gint height;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_rectangle_get_type (void);

#define ATK_TYPE_RECTANGLE (atk_rectangle_get_type ())

struct _AtkComponentIface
{
  /*< private >*/
  long unsigned int* parent;

  /*< public >*/
  guint          (* add_focus_handler)  (AtkComponent          *component,
                                         AtkFocusHandler        handler);

  gboolean       (* contains)           (AtkComponent          *component,
                                         gint                   x,
                                         gint                   y,
                                         AtkCoordType           coord_type);

  AtkObject*    (* ref_accessible_at_point)  (AtkComponent     *component,
                                         gint                   x,
                                         gint                   y,
                                         AtkCoordType           coord_type);
  void          (* get_extents)         (AtkComponent          *component,
                                         gint                  *x,
                                         gint                  *y,
                                         gint                  *width,
                                         gint                  *height,
                                         AtkCoordType          coord_type);
  void                     (* get_position)     (AtkComponent   *component,
                                                 gint           *x,
                                                 gint           *y,
                                                 AtkCoordType   coord_type);
  void                     (* get_size)                 (AtkComponent   *component,
                                                         gint           *width,
                                                         gint           *height);
  gboolean                 (* grab_focus)               (AtkComponent   *component);
  void                     (* remove_focus_handler)      (AtkComponent  *component,
                                                          guint         handler_id);
  gboolean                 (* set_extents)      (AtkComponent   *component,
                                                 gint           x,
                                                 gint           y,
                                                 gint           width,
                                                 gint           height,
                                                 AtkCoordType   coord_type);
  gboolean                 (* set_position)     (AtkComponent   *component,
                                                 gint           x,
                                                 gint           y,
                                                 AtkCoordType   coord_type);
  gboolean                 (* set_size)         (AtkComponent   *component,
                                                 gint           width,
                                                 gint           height);
  	
  AtkLayer                 (* get_layer)        (AtkComponent   *component);
  gint                     (* get_mdi_zorder)   (AtkComponent   *component);


  void                     (* bounds_changed)   (AtkComponent   *component,
                                                 AtkRectangle   *bounds);
  gdouble                  (* get_alpha)        (AtkComponent   *component);


  gboolean                (*scroll_to)          (AtkComponent   *component,
                                                 AtkScrollType   type);

  gboolean                (*scroll_to_point)    (AtkComponent   *component,
                                                 AtkCoordType    coords,
                                                 gint            x,
                                                 gint            y);
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_component_get_type (void);

/* convenience functions */
ATK_DEPRECATED_IN_2_10
guint                atk_component_add_focus_handler      (AtkComponent    *component,
                                                           AtkFocusHandler handler);
ATK_AVAILABLE_IN_ALL
gboolean              atk_component_contains               (AtkComponent    *component,
                                                            gint            x,
                                                            gint            y,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
AtkObject*            atk_component_ref_accessible_at_point(AtkComponent    *component,
                                                            gint            x,
                                                            gint            y,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
void                  atk_component_get_extents            (AtkComponent    *component,
                                                            gint            *x,
                                                            gint            *y,
                                                            gint            *width,
                                                            gint            *height,
                                                            AtkCoordType    coord_type);
ATK_DEPRECATED_IN_2_12_FOR(atk_component_get_extents)
void                  atk_component_get_position           (AtkComponent    *component,
                                                            gint            *x,
                                                            gint            *y,
                                                            AtkCoordType    coord_type);
ATK_DEPRECATED_IN_2_12_FOR(atk_component_get_extents)
void                  atk_component_get_size               (AtkComponent    *component,
                                                            gint            *width,
                                                            gint            *height);
ATK_AVAILABLE_IN_ALL
AtkLayer              atk_component_get_layer              (AtkComponent    *component);
ATK_AVAILABLE_IN_ALL
gint                  atk_component_get_mdi_zorder         (AtkComponent    *component);
ATK_AVAILABLE_IN_ALL
gboolean              atk_component_grab_focus             (AtkComponent    *component);
ATK_DEPRECATED_IN_2_10
void                  atk_component_remove_focus_handler   (AtkComponent    *component,
                                                            guint           handler_id);
ATK_AVAILABLE_IN_ALL
gboolean              atk_component_set_extents            (AtkComponent    *component,
                                                            gint            x,
                                                            gint            y,
                                                            gint            width,
                                                            gint            height,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
gboolean              atk_component_set_position           (AtkComponent    *component,
                                                            gint            x,
                                                            gint            y,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
gboolean              atk_component_set_size               (AtkComponent    *component,
                                                            gint            width,
                                                            gint            height);
ATK_AVAILABLE_IN_ALL
gdouble               atk_component_get_alpha              (AtkComponent    *component);

ATK_AVAILABLE_IN_2_30
gboolean              atk_component_scroll_to              (AtkComponent    *component,
                                                            AtkScrollType   type);

ATK_AVAILABLE_IN_2_30
gboolean              atk_component_scroll_to_point        (AtkComponent    *component,
                                                            AtkCoordType    coords,
                                                            gint            x,
                                                            gint            y);

G_END_DECLS

#endif /* __ATK_COMPONENT_H__ */
