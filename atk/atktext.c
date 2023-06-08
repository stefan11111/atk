#include "config.h"

#include "atk.h"
#include "atkmarshal.h"

enum {
  TEXT_CHANGED,
  TEXT_CARET_MOVED,
  TEXT_SELECTION_CHANGED,
  TEXT_ATTRIBUTES_CHANGED,
  TEXT_INSERT,
  TEXT_REMOVE,
  LAST_SIGNAL
};

GType
atk_text_get_type (void)
{
    return 0;
}

gchar*
atk_text_get_text (AtkText      *text,
                   gint         start_offset,
                   gint         end_offset)
{
    return 0;
}

gunichar
atk_text_get_character_at_offset (AtkText      *text,
                                  gint         offset)
{
    return 0;
}

gchar*
atk_text_get_text_after_offset (AtkText          *text,
                                gint             offset,
                                AtkTextBoundary  boundary_type,
 				gint             *start_offset,
				gint		 *end_offset)
{
    return 0;
}

gchar*
atk_text_get_text_at_offset (AtkText          *text,
                             gint             offset,
                             AtkTextBoundary  boundary_type,
			     gint             *start_offset,
			     gint             *end_offset)
{
    return 0;
}

gchar*
atk_text_get_text_before_offset (AtkText          *text,
                                 gint             offset,
                                 AtkTextBoundary  boundary_type,
				 gint             *start_offset,
				 gint		  *end_offset)
{
    return 0;
}

gchar* atk_text_get_string_at_offset (AtkText *text,
                                      gint offset,
                                      AtkTextGranularity granularity,
                                      gint *start_offset,
                                      gint *end_offset)
{
    return 0;
}

gint
atk_text_get_caret_offset (AtkText *text)
{
    return -1;
}

void
atk_text_get_character_extents (AtkText *text,
                                gint offset,
                                gint *x,
                                gint *y,
                                gint *width,
                                gint *height,
                                AtkCoordType coords)
{
}

AtkAttributeSet* 
atk_text_get_run_attributes (AtkText          *text,
                             gint             offset,
                             gint             *start_offset,
                             gint             *end_offset)
{
    return 0;
}

AtkAttributeSet*
atk_text_get_default_attributes (AtkText          *text)
{
    return 0;
}

gint
atk_text_get_character_count (AtkText *text)
{
    return -1;
}

gint
atk_text_get_offset_at_point (AtkText *text,
                              gint x,
                              gint y,
			      AtkCoordType coords)
{
    return -1;
}

gint
atk_text_get_n_selections (AtkText *text)
{
    return -1;
}

gchar*
atk_text_get_selection (AtkText *text, 
                        gint    selection_num,
                        gint    *start_offset,
                        gint    *end_offset)
{
    return 0;
}

gboolean
atk_text_add_selection (AtkText *text, 
                        gint    start_offset,
                        gint    end_offset)
{
    return 0;
}

gboolean
atk_text_remove_selection (AtkText *text, 
                           gint    selection_num)
{
    return 0;
}

gboolean
atk_text_set_selection (AtkText *text, 
                        gint    selection_num,
                        gint    start_offset, 
                        gint    end_offset)
{
    return 0;
}

gboolean
atk_text_set_caret_offset (AtkText *text,
                           gint    offset)
{
    return 0;
}

void
atk_text_get_range_extents (AtkText          *text,
                            gint             start_offset,
                            gint             end_offset,
                            AtkCoordType     coord_type,
                            AtkTextRectangle *rect)
{
}

AtkTextRange**
atk_text_get_bounded_ranges (AtkText          *text,
                             AtkTextRectangle *rect,
                             AtkCoordType      coord_type,
                             AtkTextClipType   x_clip_type,
                             AtkTextClipType   y_clip_type)
{
    return 0;
}

void
atk_attribute_set_free (AtkAttributeSet *attrib_set)
{
}

AtkTextAttribute
atk_text_attribute_register (const gchar *name)
{
    return 0;
}

const gchar*
atk_text_attribute_get_name (AtkTextAttribute attr)
{
    return 0;
}

AtkTextAttribute
atk_text_attribute_for_name (const gchar *name)
{
    return 0;
}

const gchar*
atk_text_attribute_get_value (AtkTextAttribute attr,
                              gint             index)
{
    return 0;
}

gboolean
atk_text_scroll_substring_to (AtkText       *text,
                              gint          start_offset,
                              gint          end_offset,
                              AtkScrollType type)
{
    return 0;
}

gboolean
atk_text_scroll_substring_to_point (AtkText      *text,
                                    gint         start_offset,
                                    gint         end_offset,
                                    AtkCoordType coords,
                                    gint         x,
                                    gint         y)
{
    return 0;
}

void
atk_text_free_ranges (AtkTextRange **ranges)
{
}
