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
#define ATK_IS_COMPONENT(obj)                  ((obj), ATK_TYPE_COMPONENT)
#define ATK_COMPONENT(obj)                     ((obj), ATK_TYPE_COMPONENT, AtkComponent)
#define ATK_COMPONENT_GET_IFACE(obj)          ( ((obj), ATK_TYPE_COMPONENT, AtkComponentIface))

#ifndef _TYPEDEF_ATK_COMPONENT_
#define _TYPEDEF_ATK_COMPONENT_
typedef struct _AtkComponent AtkComponent;
#endif
typedef struct _AtkComponentIface  AtkComponentIface;

typedef void (*AtkFocusHandler) (AtkObject* object, unsigned char focus_in);

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
  unsigned int          (* add_focus_handler)  (AtkComponent          *component,
                                         AtkFocusHandler        handler);

  unsigned char       (* contains)           (AtkComponent          *component,
                                         int                   x,
                                         int                   y,
                                         AtkCoordType           coord_type);

  AtkObject*    (* ref_accessible_at_point)  (AtkComponent     *component,
                                         int                   x,
                                         int                   y,
                                         AtkCoordType           coord_type);
  void          (* get_extents)         (AtkComponent          *component,
                                         int                  *x,
                                         int                  *y,
                                         int                  *width,
                                         int                  *height,
                                         AtkCoordType          coord_type);
  void                     (* get_position)     (AtkComponent   *component,
                                                 int           *x,
                                                 int           *y,
                                                 AtkCoordType   coord_type);
  void                     (* get_size)                 (AtkComponent   *component,
                                                         int           *width,
                                                         int           *height);
  unsigned char                 (* grab_focus)               (AtkComponent   *component);
  void                     (* remove_focus_handler)      (AtkComponent  *component,
                                                          unsigned int         handler_id);
  unsigned char                 (* set_extents)      (AtkComponent   *component,
                                                 int           x,
                                                 int           y,
                                                 int           width,
                                                 int           height,
                                                 AtkCoordType   coord_type);
  unsigned char                 (* set_position)     (AtkComponent   *component,
                                                 int           x,
                                                 int           y,
                                                 AtkCoordType   coord_type);
  unsigned char                 (* set_size)         (AtkComponent   *component,
                                                 int           width,
                                                 int           height);
  	
  AtkLayer                 (* get_layer)        (AtkComponent   *component);
  int                     (* get_mdi_zorder)   (AtkComponent   *component);


  void                     (* bounds_changed)   (AtkComponent   *component,
                                                 AtkRectangle   *bounds);
  gdouble                  (* get_alpha)        (AtkComponent   *component);


  unsigned char                (*scroll_to)          (AtkComponent   *component,
                                                 AtkScrollType   type);

  unsigned char                (*scroll_to_point)    (AtkComponent   *component,
                                                 AtkCoordType    coords,
                                                 int            x,
                                                 int            y);
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_component_get_type (void);

/* convenience functions */
ATK_DEPRECATED_IN_2_10
unsigned int                atk_component_add_focus_handler      (AtkComponent    *component,
                                                           AtkFocusHandler handler);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_component_contains               (AtkComponent    *component,
                                                            int            x,
                                                            int            y,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
AtkObject*            atk_component_ref_accessible_at_point(AtkComponent    *component,
                                                            int            x,
                                                            int            y,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
void                  atk_component_get_extents            (AtkComponent    *component,
                                                            int            *x,
                                                            int            *y,
                                                            int            *width,
                                                            int            *height,
                                                            AtkCoordType    coord_type);
ATK_DEPRECATED_IN_2_12_FOR(atk_component_get_extents)
void                  atk_component_get_position           (AtkComponent    *component,
                                                            int            *x,
                                                            int            *y,
                                                            AtkCoordType    coord_type);
ATK_DEPRECATED_IN_2_12_FOR(atk_component_get_extents)
void                  atk_component_get_size               (AtkComponent    *component,
                                                            int            *width,
                                                            int            *height);
ATK_AVAILABLE_IN_ALL
AtkLayer              atk_component_get_layer              (AtkComponent    *component);
ATK_AVAILABLE_IN_ALL
int                  atk_component_get_mdi_zorder         (AtkComponent    *component);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_component_grab_focus             (AtkComponent    *component);
ATK_DEPRECATED_IN_2_10
void                  atk_component_remove_focus_handler   (AtkComponent    *component,
                                                            unsigned int           handler_id);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_component_set_extents            (AtkComponent    *component,
                                                            int            x,
                                                            int            y,
                                                            int            width,
                                                            int            height,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_component_set_position           (AtkComponent    *component,
                                                            int            x,
                                                            int            y,
                                                            AtkCoordType    coord_type);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_component_set_size               (AtkComponent    *component,
                                                            int            width,
                                                            int            height);
ATK_AVAILABLE_IN_ALL
gdouble               atk_component_get_alpha              (AtkComponent    *component);

ATK_AVAILABLE_IN_2_30
unsigned char              atk_component_scroll_to              (AtkComponent    *component,
                                                            AtkScrollType   type);

ATK_AVAILABLE_IN_2_30
unsigned char              atk_component_scroll_to_point        (AtkComponent    *component,
                                                            AtkCoordType    coords,
                                                            int            x,
                                                            int            y);



#endif /* __ATK_COMPONENT_H__ */
