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

long unsigned int
atk_text_get_type (void)
{
    return 0;
}

char*
atk_text_get_text (AtkText      *text,
                   int         start_offset,
                   int         end_offset)
{
    return 0;
}

unsigned short
atk_text_get_character_at_offset (AtkText      *text,
                                  int         offset)
{
    return 0;
}

char*
atk_text_get_text_after_offset (AtkText          *text,
                                int             offset,
                                AtkTextBoundary  boundary_type,
 				int             *start_offset,
				int		 *end_offset)
{
    return 0;
}

char*
atk_text_get_text_at_offset (AtkText          *text,
                             int             offset,
                             AtkTextBoundary  boundary_type,
			     int             *start_offset,
			     int             *end_offset)
{
    return 0;
}

char*
atk_text_get_text_before_offset (AtkText          *text,
                                 int             offset,
                                 AtkTextBoundary  boundary_type,
				 int             *start_offset,
				 int		  *end_offset)
{
    return 0;
}

char* atk_text_get_string_at_offset (AtkText *text,
                                      int offset,
                                      AtkTextGranularity granularity,
                                      int *start_offset,
                                      int *end_offset)
{
    return 0;
}

int
atk_text_get_caret_offset (AtkText *text)
{
    return -1;
}

void
atk_text_get_character_extents (AtkText *text,
                                int offset,
                                int *x,
                                int *y,
                                int *width,
                                int *height,
                                AtkCoordType coords)
{
}

AtkAttributeSet* 
atk_text_get_run_attributes (AtkText          *text,
                             int             offset,
                             int             *start_offset,
                             int             *end_offset)
{
    return 0;
}

AtkAttributeSet*
atk_text_get_default_attributes (AtkText          *text)
{
    return 0;
}

int
atk_text_get_character_count (AtkText *text)
{
    return -1;
}

int
atk_text_get_offset_at_point (AtkText *text,
                              int x,
                              int y,
			      AtkCoordType coords)
{
    return -1;
}

int
atk_text_get_n_selections (AtkText *text)
{
    return -1;
}

char*
atk_text_get_selection (AtkText *text, 
                        int    selection_num,
                        int    *start_offset,
                        int    *end_offset)
{
    return 0;
}

gboolean
atk_text_add_selection (AtkText *text, 
                        int    start_offset,
                        int    end_offset)
{
    return 0;
}

gboolean
atk_text_remove_selection (AtkText *text, 
                           int    selection_num)
{
    return 0;
}

gboolean
atk_text_set_selection (AtkText *text, 
                        int    selection_num,
                        int    start_offset, 
                        int    end_offset)
{
    return 0;
}

gboolean
atk_text_set_caret_offset (AtkText *text,
                           int    offset)
{
    return 0;
}

void
atk_text_get_range_extents (AtkText          *text,
                            int             start_offset,
                            int             end_offset,
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
atk_text_attribute_register (const char *name)
{
    return 0;
}

const char*
atk_text_attribute_get_name (AtkTextAttribute attr)
{
    return 0;
}

AtkTextAttribute
atk_text_attribute_for_name (const char *name)
{
    return 0;
}

const char*
atk_text_attribute_get_value (AtkTextAttribute attr,
                              int             index)
{
    return 0;
}

gboolean
atk_text_scroll_substring_to (AtkText       *text,
                              int          start_offset,
                              int          end_offset,
                              AtkScrollType type)
{
    return 0;
}

gboolean
atk_text_scroll_substring_to_point (AtkText      *text,
                                    int         start_offset,
                                    int         end_offset,
                                    AtkCoordType coords,
                                    int         x,
                                    int         y)
{
    return 0;
}

void
atk_text_free_ranges (AtkTextRange **ranges)
{
}
