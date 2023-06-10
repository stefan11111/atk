#ifndef __ATK_TEXT_H__
#define __ATK_TEXT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/_glib-object.h>
#include <atk/atkobject.h>
#include <atk/atkutil.h>
#include <atk/atkcomponent.h>

G_BEGIN_DECLS

typedef enum
{
  ATK_TEXT_ATTR_INVALID = 0,
  ATK_TEXT_ATTR_LEFT_MARGIN,
  ATK_TEXT_ATTR_RIGHT_MARGIN,
  ATK_TEXT_ATTR_INDENT,
  ATK_TEXT_ATTR_INVISIBLE,
  ATK_TEXT_ATTR_EDITABLE,
  ATK_TEXT_ATTR_PIXELS_ABOVE_LINES,
  ATK_TEXT_ATTR_PIXELS_BELOW_LINES,
  ATK_TEXT_ATTR_PIXELS_INSIDE_WRAP,
  ATK_TEXT_ATTR_BG_FULL_HEIGHT,
  ATK_TEXT_ATTR_RISE,
  ATK_TEXT_ATTR_UNDERLINE,
  ATK_TEXT_ATTR_STRIKETHROUGH,
  ATK_TEXT_ATTR_SIZE,
  ATK_TEXT_ATTR_SCALE,
  ATK_TEXT_ATTR_WEIGHT,
  ATK_TEXT_ATTR_LANGUAGE,
  ATK_TEXT_ATTR_FAMILY_NAME,
  ATK_TEXT_ATTR_BG_COLOR,
  ATK_TEXT_ATTR_FG_COLOR,
  ATK_TEXT_ATTR_BG_STIPPLE,
  ATK_TEXT_ATTR_FG_STIPPLE,
  ATK_TEXT_ATTR_WRAP_MODE,
  ATK_TEXT_ATTR_DIRECTION,
  ATK_TEXT_ATTR_JUSTIFICATION,
  ATK_TEXT_ATTR_STRETCH,
  ATK_TEXT_ATTR_VARIANT,
  ATK_TEXT_ATTR_STYLE,
  ATK_TEXT_ATTR_TEXT_POSITION,
  ATK_TEXT_ATTR_LAST_DEFINED
} AtkTextAttribute;

ATK_AVAILABLE_IN_ALL
AtkTextAttribute         atk_text_attribute_register   (const char *name);


#define ATK_TYPE_TEXT                    (atk_text_get_type ())
#define ATK_IS_TEXT(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_TEXT)
#define ATK_TEXT(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_TEXT, AtkText)
#define ATK_TEXT_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_TEXT, AtkTextIface))

#ifndef _TYPEDEF_ATK_TEXT_
#define _TYPEDEF_ATK_TEXT_
typedef struct _AtkText AtkText;
#endif
typedef struct _AtkTextIface AtkTextIface;

typedef enum {
  ATK_TEXT_BOUNDARY_CHAR,
  ATK_TEXT_BOUNDARY_WORD_START,
  ATK_TEXT_BOUNDARY_WORD_END,
  ATK_TEXT_BOUNDARY_SENTENCE_START,
  ATK_TEXT_BOUNDARY_SENTENCE_END,
  ATK_TEXT_BOUNDARY_LINE_START,
  ATK_TEXT_BOUNDARY_LINE_END
} AtkTextBoundary;

typedef enum {
  ATK_TEXT_GRANULARITY_CHAR,
  ATK_TEXT_GRANULARITY_WORD,
  ATK_TEXT_GRANULARITY_SENTENCE,
  ATK_TEXT_GRANULARITY_LINE,
  ATK_TEXT_GRANULARITY_PARAGRAPH
} AtkTextGranularity;

typedef struct _AtkTextRectangle AtkTextRectangle;

struct _AtkTextRectangle {
  int x;
  int y;
  int width;
  int height;
};

typedef struct _AtkTextRange AtkTextRange;

struct _AtkTextRange {
  AtkTextRectangle bounds;
  int start_offset;
  int end_offset;
  char* content;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_text_range_get_type (void);

typedef enum {
    ATK_TEXT_CLIP_NONE,
    ATK_TEXT_CLIP_MIN,
    ATK_TEXT_CLIP_MAX,
    ATK_TEXT_CLIP_BOTH
} AtkTextClipType;

struct _AtkTextIface
{
  long unsigned int* parent;

  char*         (* get_text)                     (AtkText          *text,
                                                   int             start_offset,
                                                   int             end_offset);
  char*         (* get_text_after_offset)        (AtkText          *text,
                                                   int             offset,
                                                   AtkTextBoundary  boundary_type,
						   int             *start_offset,
						   int             *end_offset);
  char*         (* get_text_at_offset)           (AtkText          *text,
                                                   int             offset,
                                                   AtkTextBoundary  boundary_type,
						   int             *start_offset,
						   int             *end_offset);
  unsigned short       (* get_character_at_offset)      (AtkText          *text,
                                                   int             offset);
  char*         (* get_text_before_offset)       (AtkText          *text,
                                                   int             offset,
                                                   AtkTextBoundary  boundary_type,
 						   int             *start_offset,
						   int             *end_offset);
  int           (* get_caret_offset)             (AtkText          *text);
  AtkAttributeSet* (* get_run_attributes)         (AtkText	    *text,
						   int	  	    offset,
						   int             *start_offset,
						   int	 	    *end_offset);
  AtkAttributeSet* (* get_default_attributes)     (AtkText	    *text);
  void           (* get_character_extents)        (AtkText          *text,
                                                   int             offset,
                                                   int             *x,
                                                   int             *y,
                                                   int             *width,
                                                   int             *height,
                                                   AtkCoordType	    coords);
  int           (* get_character_count)          (AtkText          *text);
  int           (* get_offset_at_point)          (AtkText          *text,
                                                   int             x,
                                                   int             y,
                                                   AtkCoordType	    coords);
  int		 (* get_n_selections)		  (AtkText          *text);
  char*         (* get_selection)	          (AtkText          *text,
						   int		    selection_num,
						   int		    *start_offset,
						   int		    *end_offset);
  unsigned char       (* add_selection)		  (AtkText          *text,
						   int		    start_offset,
						   int		    end_offset);
  unsigned char       (* remove_selection)		  (AtkText          *text,
						   int             selection_num);
  unsigned char       (* set_selection)		  (AtkText          *text,
						   int		    selection_num,
						   int		    start_offset,
						   int		    end_offset);
  unsigned char       (* set_caret_offset)             (AtkText          *text,
                                                   int             offset);

  /*
   * signal handlers
   */
  void		 (* text_changed)                 (AtkText          *text,
                                                   int             position,
                                                   int             length);
  void           (* text_caret_moved)             (AtkText          *text,
                                                   int             location);
  void           (* text_selection_changed)       (AtkText          *text);

  void           (* text_attributes_changed)      (AtkText          *text);


  void           (* get_range_extents)            (AtkText          *text,
                                                   int             start_offset,
                                                   int             end_offset,
                                                   AtkCoordType     coord_type,
                                                   AtkTextRectangle *rect);

  AtkTextRange** (* get_bounded_ranges)           (AtkText          *text,
                                                   AtkTextRectangle *rect,
                                                   AtkCoordType     coord_type,
                                                   AtkTextClipType  x_clip_type,
                                                   AtkTextClipType  y_clip_type);

  char*         (* get_string_at_offset)         (AtkText            *text,
                                                   int               offset,
                                                   AtkTextGranularity granularity,
                                                   int               *start_offset,
                                                   int               *end_offset);

  unsigned char       (* scroll_substring_to)          (AtkText          *text,
                                                   int             start_offset,
                                                   int             end_offset,
                                                   AtkScrollType    type);
  unsigned char       (* scroll_substring_to_point)    (AtkText          *text,
                                                   int             start_offset,
                                                   int             end_offset,
                                                   AtkCoordType     coords,
                                                   int             x,
                                                   int             y);
};

ATK_AVAILABLE_IN_ALL
long unsigned int            atk_text_get_type (void);


ATK_AVAILABLE_IN_ALL
char*        atk_text_get_text                           (AtkText          *text,
                                                           int             start_offset,
                                                           int             end_offset);
ATK_AVAILABLE_IN_ALL
unsigned short      atk_text_get_character_at_offset            (AtkText          *text,
                                                           int             offset);
ATK_DEPRECATED_IN_2_10_FOR(atk_text_get_string_at_offset)
char*        atk_text_get_text_after_offset              (AtkText          *text,
                                                           int             offset,
                                                           AtkTextBoundary  boundary_type,
							   int             *start_offset,
							   int	            *end_offset);
ATK_DEPRECATED_IN_2_10_FOR(atk_text_get_string_at_offset)
char*        atk_text_get_text_at_offset                 (AtkText          *text,
                                                           int             offset,
                                                           AtkTextBoundary  boundary_type,
							   int             *start_offset,
							   int             *end_offset);
ATK_DEPRECATED_IN_2_10_FOR(atk_text_get_string_at_offset)
char*        atk_text_get_text_before_offset             (AtkText          *text,
                                                           int             offset,
                                                           AtkTextBoundary  boundary_type,
							   int             *start_offset,
							   int	            *end_offset);
ATK_AVAILABLE_IN_2_10
char*        atk_text_get_string_at_offset               (AtkText            *text,
                                                           int               offset,
                                                           AtkTextGranularity granularity,
                                                           int               *start_offset,
                                                           int               *end_offset);
ATK_AVAILABLE_IN_ALL
int          atk_text_get_caret_offset                   (AtkText          *text);
ATK_AVAILABLE_IN_ALL
void          atk_text_get_character_extents              (AtkText          *text,
                                                           int             offset,
                                                           int             *x,
                                                           int             *y,
                                                           int             *width,
                                                           int             *height,
                                                           AtkCoordType	    coords);
ATK_AVAILABLE_IN_ALL
AtkAttributeSet* atk_text_get_run_attributes              (AtkText	    *text,
						           int	  	    offset,
						           int             *start_offset,
						           int	 	    *end_offset);
ATK_AVAILABLE_IN_ALL
AtkAttributeSet* atk_text_get_default_attributes          (AtkText	    *text);
ATK_AVAILABLE_IN_ALL
int          atk_text_get_character_count                (AtkText          *text);
ATK_AVAILABLE_IN_ALL
int          atk_text_get_offset_at_point                (AtkText          *text,
                                                           int             x,
                                                           int             y,
                                                           AtkCoordType	    coords);
ATK_AVAILABLE_IN_ALL
int          atk_text_get_n_selections			  (AtkText          *text);
ATK_AVAILABLE_IN_ALL
char*        atk_text_get_selection			  (AtkText          *text,
							   int		    selection_num,
							   int             *start_offset,
							   int             *end_offset);
ATK_AVAILABLE_IN_ALL
unsigned char      atk_text_add_selection                      (AtkText          *text,
							   int             start_offset,
							   int             end_offset);
ATK_AVAILABLE_IN_ALL
unsigned char      atk_text_remove_selection                   (AtkText          *text,
							   int		    selection_num);
ATK_AVAILABLE_IN_ALL
unsigned char      atk_text_set_selection                      (AtkText          *text,
							   int		    selection_num,
							   int             start_offset,
							   int             end_offset);
ATK_AVAILABLE_IN_ALL
unsigned char      atk_text_set_caret_offset                   (AtkText          *text,
                                                           int             offset);
ATK_AVAILABLE_IN_ALL
void          atk_text_get_range_extents                  (AtkText          *text,

                                                           int             start_offset,
                                                           int             end_offset,
                                                           AtkCoordType     coord_type,
                                                           AtkTextRectangle *rect);
ATK_AVAILABLE_IN_ALL
AtkTextRange**  atk_text_get_bounded_ranges               (AtkText          *text,
                                                           AtkTextRectangle *rect,
                                                           AtkCoordType     coord_type,
                                                           AtkTextClipType  x_clip_type,
                                                           AtkTextClipType  y_clip_type);
ATK_AVAILABLE_IN_ALL
void          atk_text_free_ranges                        (AtkTextRange     **ranges);
ATK_AVAILABLE_IN_ALL
void 	      atk_attribute_set_free                      (AtkAttributeSet  *attrib_set);
ATK_AVAILABLE_IN_ALL
const char*  atk_text_attribute_get_name                 (AtkTextAttribute attr);
ATK_AVAILABLE_IN_ALL
AtkTextAttribute       atk_text_attribute_for_name        (const char      *name);
ATK_AVAILABLE_IN_ALL
const char*  atk_text_attribute_get_value                (AtkTextAttribute attr,
                                                           int             index_);

ATK_AVAILABLE_IN_ALL
unsigned char      atk_text_scroll_substring_to                (AtkText          *text,
                                                           int             start_offset,
                                                           int             end_offset,
                                                           AtkScrollType    type);

ATK_AVAILABLE_IN_ALL
unsigned char      atk_text_scroll_substring_to_point          (AtkText          *text,
                                                           int             start_offset,
                                                           int             end_offset,
                                                           AtkCoordType     coords,
                                                           int             x,
                                                           int             y);

G_END_DECLS

#endif /* __ATK_TEXT_H__ */
