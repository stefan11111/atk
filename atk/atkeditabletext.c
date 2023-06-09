#include "config.h"

#include "atkeditabletext.h"

long unsigned int
atk_editable_text_get_type (void)
{
    return 0;
}

gboolean
atk_editable_text_set_run_attributes (AtkEditableText *text,
                                      AtkAttributeSet *attrib_set,
			              gint start_offset,
                                      gint end_offset)
{
    return 0;
}

void 
atk_editable_text_set_text_contents (AtkEditableText  *text,
                                     const gchar      *string)
{
}

void 
atk_editable_text_insert_text (AtkEditableText  *text,
                               const gchar      *string,
                               gint             length,
                               gint             *position)
{
}

void 
atk_editable_text_copy_text (AtkEditableText  *text,
                             gint             start_pos,
                             gint             end_pos)
{
}

void 
atk_editable_text_cut_text  (AtkEditableText  *text,
                             gint             start_pos,
                             gint             end_pos)
{
}

void 
atk_editable_text_delete_text (AtkEditableText  *text,
                               gint             start_pos,
                               gint             end_pos)
{
}

void 
atk_editable_text_paste_text (AtkEditableText  *text,
                              gint             position)
{
}
