#ifndef __ATK_EDITABLE_TEXT_H__
#define __ATK_EDITABLE_TEXT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atktext.h>



#define ATK_TYPE_EDITABLE_TEXT                    (atk_editable_text_get_type ())
#define ATK_IS_EDITABLE_TEXT(obj)                 0
#define ATK_EDITABLE_TEXT(obj)                    (obj)
#define ATK_EDITABLE_TEXT_GET_IFACE(obj)          (*(void**)(obj))

#ifndef _TYPEDEF_ATK_EDITABLE_TEXT_
#define _TYPEDEF_ATK_EDITABLE_TEXT_
typedef struct _AtkEditableText AtkEditableText;
#endif
typedef struct _AtkEditableTextIface AtkEditableTextIface;

struct _AtkEditableTextIface
{
  long unsigned int* parent_interface;

  unsigned char (* set_run_attributes) (AtkEditableText  *text,
                                   AtkAttributeSet  *attrib_set,
                                   int		    start_offset,
 				   int		    end_offset);
  void   (* set_text_contents)    (AtkEditableText  *text,
                                   const char      *string);
  void   (* insert_text)          (AtkEditableText  *text,
                                   const char      *string,
                                   int             length,
                                   int             *position);
  void   (* copy_text)            (AtkEditableText  *text,
                                   int             start_pos,
                                   int             end_pos);
  void   (* cut_text)             (AtkEditableText  *text,
                                   int             start_pos,
                                   int             end_pos);
  void   (* delete_text)          (AtkEditableText  *text,
                                   int             start_pos,
                                   int             end_pos);
  void   (* paste_text)           (AtkEditableText  *text,
                                   int             position);
};
ATK_AVAILABLE_IN_ALL
long unsigned int atk_editable_text_get_type (void);


ATK_AVAILABLE_IN_ALL
unsigned char atk_editable_text_set_run_attributes (AtkEditableText          *text,
                                               AtkAttributeSet  *attrib_set,
                                               int    	        start_offset,
 					       int	        end_offset);
ATK_AVAILABLE_IN_ALL
void atk_editable_text_set_text_contents    (AtkEditableText  *text,
                                             const char      *string);
ATK_AVAILABLE_IN_ALL
void atk_editable_text_insert_text          (AtkEditableText  *text,
                                             const char      *string,
                                             int             length,
                                             int             *position);
ATK_AVAILABLE_IN_ALL
void atk_editable_text_copy_text            (AtkEditableText  *text,
                                             int             start_pos,
                                             int             end_pos);
ATK_AVAILABLE_IN_ALL
void atk_editable_text_cut_text             (AtkEditableText  *text,
                                             int             start_pos,
                                             int             end_pos);
ATK_AVAILABLE_IN_ALL
void atk_editable_text_delete_text          (AtkEditableText  *text,
                                             int             start_pos,
                                             int             end_pos);
ATK_AVAILABLE_IN_ALL
void atk_editable_text_paste_text           (AtkEditableText  *text,
                                             int             position);



#endif /* __ATK_EDITABLE_TEXT_H__ */
