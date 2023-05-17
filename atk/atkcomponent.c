#include "config.h"

#include "atkcomponent.h"

enum {
  BOUNDS_CHANGED,
  LAST_SIGNAL
};

GType
atk_component_get_type (void)
{
    return 0;
}

guint
atk_component_add_focus_handler (AtkComponent    *component,
                                 AtkFocusHandler handler)
{
    return 0;
}

void
atk_component_remove_focus_handler (AtkComponent    *component,
                                    guint           handler_id)
{
}

gboolean
atk_component_contains (AtkComponent    *component,
                        gint            x,
                        gint            y,
                        AtkCoordType    coord_type)
{
    return 0;
}

AtkObject*
atk_component_ref_accessible_at_point (AtkComponent    *component,
                                       gint            x,
                                       gint            y,
                                       AtkCoordType    coord_type)
{
    return 0;
}

void
atk_component_get_extents    (AtkComponent    *component,
                              gint            *x,
                              gint            *y,
                              gint            *width,
                              gint            *height,
                              AtkCoordType    coord_type)
{
}

void
atk_component_get_position   (AtkComponent    *component,
                              gint            *x,
                              gint            *y,
                              AtkCoordType    coord_type)
{
}

void
atk_component_get_size       (AtkComponent    *component,
                              gint            *width,
                              gint            *height)
{
}

AtkLayer
atk_component_get_layer (AtkComponent *component) 
{
    return 0;
}

gint
atk_component_get_mdi_zorder (AtkComponent *component) 
{
    return 0;
}

gdouble
atk_component_get_alpha (AtkComponent    *component)
{
    return 0;
}

gboolean
atk_component_grab_focus (AtkComponent    *component)
{
    return 0;
}

gboolean
atk_component_set_extents   (AtkComponent    *component,
                             gint            x,
                             gint            y,
                             gint            width,
                             gint            height,
                             AtkCoordType    coord_type)
{
    return 0;
}

gboolean
atk_component_set_position   (AtkComponent    *component,
                              gint            x,
                              gint            y,
                              AtkCoordType    coord_type)
{
    return 0;
}

gboolean
atk_component_set_size       (AtkComponent    *component,
                              gint            x,
                              gint            y)
{
    return 0;
}

gboolean
atk_component_scroll_to (AtkComponent  *component,
                         AtkScrollType  type)
{
    return 0;
}

gboolean
atk_component_scroll_to_point (AtkComponent *component,
                               AtkCoordType  coords,
                               gint          x,
                               gint          y)
{
    return 0;
}

GType
atk_rectangle_get_type (void)
{
    return 0;
}

