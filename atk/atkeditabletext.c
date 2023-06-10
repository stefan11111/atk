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
			              int start_offset,
                                      int end_offset)
{
    return 0;
}

void 
atk_editable_text_set_text_contents (AtkEditableText  *text,
                                     const char      *string)
{
}

void 
atk_editable_text_insert_text (AtkEditableText  *text,
                               const char      *string,
                               int             length,
                               int             *position)
{
}

void 
atk_editable_text_copy_text (AtkEditableText  *text,
                             int             start_pos,
                             int             end_pos)
{
}

void 
atk_editable_text_cut_text  (AtkEditableText  *text,
                             int             start_pos,
                             int             end_pos)
{
}

void 
atk_editable_text_delete_text (AtkEditableText  *text,
                               int             start_pos,
                               int             end_pos)
{
}

void 
atk_editable_text_paste_text (AtkEditableText  *text,
                              int             position)
{
}
