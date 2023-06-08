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
AtkTextAttribute         atk_text_attribute_register   (const gchar *name);


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
  gint x;
  gint y;
  gint width;
  gint height;
};

typedef struct _AtkTextRange AtkTextRange;

struct _AtkTextRange {
  AtkTextRectangle bounds;
  gint start_offset;
  gint end_offset;
  gchar* content;
};

ATK_AVAILABLE_IN_ALL
GType atk_text_range_get_type (void);

typedef enum {
    ATK_TEXT_CLIP_NONE,
    ATK_TEXT_CLIP_MIN,
    ATK_TEXT_CLIP_MAX,
    ATK_TEXT_CLIP_BOTH
} AtkTextClipType;

struct _AtkTextIface
{
  GTypeInterface parent;

  gchar*         (* get_text)                     (AtkText          *text,
                                                   gint             start_offset,
                                                   gint             end_offset);
  gchar*         (* get_text_after_offset)        (AtkText          *text,
                                                   gint             offset,
                                                   AtkTextBoundary  boundary_type,
						   gint             *start_offset,
						   gint             *end_offset);
  gchar*         (* get_text_at_offset)           (AtkText          *text,
                                                   gint             offset,
                                                   AtkTextBoundary  boundary_type,
						   gint             *start_offset,
						   gint             *end_offset);
  gunichar       (* get_character_at_offset)      (AtkText          *text,
                                                   gint             offset);
  gchar*         (* get_text_before_offset)       (AtkText          *text,
                                                   gint             offset,
                                                   AtkTextBoundary  boundary_type,
 						   gint             *start_offset,
						   gint             *end_offset);
  gint           (* get_caret_offset)             (AtkText          *text);
  AtkAttributeSet* (* get_run_attributes)         (AtkText	    *text,
						   gint	  	    offset,
						   gint             *start_offset,
						   gint	 	    *end_offset);
  AtkAttributeSet* (* get_default_attributes)     (AtkText	    *text);
  void           (* get_character_extents)        (AtkText          *text,
                                                   gint             offset,
                                                   gint             *x,
                                                   gint             *y,
                                                   gint             *width,
                                                   gint             *height,
                                                   AtkCoordType	    coords);
  gint           (* get_character_count)          (AtkText          *text);
  gint           (* get_offset_at_point)          (AtkText          *text,
                                                   gint             x,
                                                   gint             y,
                                                   AtkCoordType	    coords);
  gint		 (* get_n_selections)		  (AtkText          *text);
  gchar*         (* get_selection)	          (AtkText          *text,
						   gint		    selection_num,
						   gint		    *start_offset,
						   gint		    *end_offset);
  gboolean       (* add_selection)		  (AtkText          *text,
						   gint		    start_offset,
						   gint		    end_offset);
  gboolean       (* remove_selection)		  (AtkText          *text,
						   gint             selection_num);
  gboolean       (* set_selection)		  (AtkText          *text,
						   gint		    selection_num,
						   gint		    start_offset,
						   gint		    end_offset);
  gboolean       (* set_caret_offset)             (AtkText          *text,
                                                   gint             offset);

  /*
   * signal handlers
   */
  void		 (* text_changed)                 (AtkText          *text,
                                                   gint             position,
                                                   gint             length);
  void           (* text_caret_moved)             (AtkText          *text,
                                                   gint             location);
  void           (* text_selection_changed)       (AtkText          *text);

  void           (* text_attributes_changed)      (AtkText          *text);


  void           (* get_range_extents)            (AtkText          *text,
                                                   gint             start_offset,
                                                   gint             end_offset,
                                                   AtkCoordType     coord_type,
                                                   AtkTextRectangle *rect);

  AtkTextRange** (* get_bounded_ranges)           (AtkText          *text,
                                                   AtkTextRectangle *rect,
                                                   AtkCoordType     coord_type,
                                                   AtkTextClipType  x_clip_type,
                                                   AtkTextClipType  y_clip_type);

  gchar*         (* get_string_at_offset)         (AtkText            *text,
                                                   gint               offset,
                                                   AtkTextGranularity granularity,
                                                   gint               *start_offset,
                                                   gint               *end_offset);

  gboolean       (* scroll_substring_to)          (AtkText          *text,
                                                   gint             start_offset,
                                                   gint             end_offset,
                                                   AtkScrollType    type);
  gboolean       (* scroll_substring_to_point)    (AtkText          *text,
                                                   gint             start_offset,
                                                   gint             end_offset,
                                                   AtkCoordType     coords,
                                                   gint             x,
                                                   gint             y);
};

ATK_AVAILABLE_IN_ALL
GType            atk_text_get_type (void);


ATK_AVAILABLE_IN_ALL
gchar*        atk_text_get_text                           (AtkText          *text,
                                                           gint             start_offset,
                                                           gint             end_offset);
ATK_AVAILABLE_IN_ALL
gunichar      atk_text_get_character_at_offset            (AtkText          *text,
                                                           gint             offset);
ATK_DEPRECATED_IN_2_10_FOR(atk_text_get_string_at_offset)
gchar*        atk_text_get_text_after_offset              (AtkText          *text,
                                                           gint             offset,
                                                           AtkTextBoundary  boundary_type,
							   gint             *start_offset,
							   gint	            *end_offset);
ATK_DEPRECATED_IN_2_10_FOR(atk_text_get_string_at_offset)
gchar*        atk_text_get_text_at_offset                 (AtkText          *text,
                                                           gint             offset,
                                                           AtkTextBoundary  boundary_type,
							   gint             *start_offset,
							   gint             *end_offset);
ATK_DEPRECATED_IN_2_10_FOR(atk_text_get_string_at_offset)
gchar*        atk_text_get_text_before_offset             (AtkText          *text,
                                                           gint             offset,
                                                           AtkTextBoundary  boundary_type,
							   gint             *start_offset,
							   gint	            *end_offset);
ATK_AVAILABLE_IN_2_10
gchar*        atk_text_get_string_at_offset               (AtkText            *text,
                                                           gint               offset,
                                                           AtkTextGranularity granularity,
                                                           gint               *start_offset,
                                                           gint               *end_offset);
ATK_AVAILABLE_IN_ALL
gint          atk_text_get_caret_offset                   (AtkText          *text);
ATK_AVAILABLE_IN_ALL
void          atk_text_get_character_extents              (AtkText          *text,
                                                           gint             offset,
                                                           gint             *x,
                                                           gint             *y,
                                                           gint             *width,
                                                           gint             *height,
                                                           AtkCoordType	    coords);
ATK_AVAILABLE_IN_ALL
AtkAttributeSet* atk_text_get_run_attributes              (AtkText	    *text,
						           gint	  	    offset,
						           gint             *start_offset,
						           gint	 	    *end_offset);
ATK_AVAILABLE_IN_ALL
AtkAttributeSet* atk_text_get_default_attributes          (AtkText	    *text);
ATK_AVAILABLE_IN_ALL
gint          atk_text_get_character_count                (AtkText          *text);
ATK_AVAILABLE_IN_ALL
gint          atk_text_get_offset_at_point                (AtkText          *text,
                                                           gint             x,
                                                           gint             y,
                                                           AtkCoordType	    coords);
ATK_AVAILABLE_IN_ALL
gint          atk_text_get_n_selections			  (AtkText          *text);
ATK_AVAILABLE_IN_ALL
gchar*        atk_text_get_selection			  (AtkText          *text,
							   gint		    selection_num,
							   gint             *start_offset,
							   gint             *end_offset);
ATK_AVAILABLE_IN_ALL
gboolean      atk_text_add_selection                      (AtkText          *text,
							   gint             start_offset,
							   gint             end_offset);
ATK_AVAILABLE_IN_ALL
gboolean      atk_text_remove_selection                   (AtkText          *text,
							   gint		    selection_num);
ATK_AVAILABLE_IN_ALL
gboolean      atk_text_set_selection                      (AtkText          *text,
							   gint		    selection_num,
							   gint             start_offset,
							   gint             end_offset);
ATK_AVAILABLE_IN_ALL
gboolean      atk_text_set_caret_offset                   (AtkText          *text,
                                                           gint             offset);
ATK_AVAILABLE_IN_ALL
void          atk_text_get_range_extents                  (AtkText          *text,

                                                           gint             start_offset,
                                                           gint             end_offset,
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
const gchar*  atk_text_attribute_get_name                 (AtkTextAttribute attr);
ATK_AVAILABLE_IN_ALL
AtkTextAttribute       atk_text_attribute_for_name        (const gchar      *name);
ATK_AVAILABLE_IN_ALL
const gchar*  atk_text_attribute_get_value                (AtkTextAttribute attr,
                                                           gint             index_);

ATK_AVAILABLE_IN_ALL
gboolean      atk_text_scroll_substring_to                (AtkText          *text,
                                                           gint             start_offset,
                                                           gint             end_offset,
                                                           AtkScrollType    type);

ATK_AVAILABLE_IN_ALL
gboolean      atk_text_scroll_substring_to_point          (AtkText          *text,
                                                           gint             start_offset,
                                                           gint             end_offset,
                                                           AtkCoordType     coords,
                                                           gint             x,
                                                           gint             y);

G_END_DECLS

#endif /* __ATK_TEXT_H__ */
