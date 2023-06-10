#include "config.h"

#include "atkcomponent.h"

enum {
  BOUNDS_CHANGED,
  LAST_SIGNAL
};

long unsigned int
atk_component_get_type (void)
{
    return 0;
}

unsigned int
atk_component_add_focus_handler (AtkComponent    *component,
                                 AtkFocusHandler handler)
{
    return 0;
}

void
atk_component_remove_focus_handler (AtkComponent    *component,
                                    unsigned int           handler_id)
{
}

unsigned char
atk_component_contains (AtkComponent    *component,
                        int            x,
                        int            y,
                        AtkCoordType    coord_type)
{
    return 0;
}

AtkObject*
atk_component_ref_accessible_at_point (AtkComponent    *component,
                                       int            x,
                                       int            y,
                                       AtkCoordType    coord_type)
{
    return 0;
}

void
atk_component_get_extents    (AtkComponent    *component,
                              int            *x,
                              int            *y,
                              int            *width,
                              int            *height,
                              AtkCoordType    coord_type)
{
}

void
atk_component_get_position   (AtkComponent    *component,
                              int            *x,
                              int            *y,
                              AtkCoordType    coord_type)
{
}

void
atk_component_get_size       (AtkComponent    *component,
                              int            *width,
                              int            *height)
{
}

AtkLayer
atk_component_get_layer (AtkComponent *component) 
{
    return 0;
}

int
atk_component_get_mdi_zorder (AtkComponent *component) 
{
    return 0;
}

gdouble
atk_component_get_alpha (AtkComponent    *component)
{
    return 0;
}

unsigned char
atk_component_grab_focus (AtkComponent    *component)
{
    return 0;
}

unsigned char
atk_component_set_extents   (AtkComponent    *component,
                             int            x,
                             int            y,
                             int            width,
                             int            height,
                             AtkCoordType    coord_type)
{
    return 0;
}

unsigned char
atk_component_set_position   (AtkComponent    *component,
                              int            x,
                              int            y,
                              AtkCoordType    coord_type)
{
    return 0;
}

unsigned char
atk_component_set_size       (AtkComponent    *component,
                              int            x,
                              int            y)
{
    return 0;
}

unsigned char
atk_component_scroll_to (AtkComponent  *component,
                         AtkScrollType  type)
{
    return 0;
}

unsigned char
atk_component_scroll_to_point (AtkComponent *component,
                               AtkCoordType  coords,
                               int          x,
                               int          y)
{
    return 0;
}

long unsigned int
atk_rectangle_get_type (void)
{
    return 0;
}

