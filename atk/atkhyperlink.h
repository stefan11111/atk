#ifndef __ATK_HYPERLINK_H__
#define __ATK_HYPERLINK_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkaction.h>

G_BEGIN_DECLS

/*
 * AtkHyperlink encapsulates a link or set of links in a hypertext document.
 *
 * It implements the AtkAction interface.
 */

/**
 *AtkHyperlinkStateFlags:
 *@ATK_HYPERLINK_IS_INLINE: Link is inline
 *
 *Describes the type of link
 **/ 
typedef enum 
{
  ATK_HYPERLINK_IS_INLINE = 1 << 0
} AtkHyperlinkStateFlags;

#define ATK_TYPE_HYPERLINK                        (atk_hyperlink_get_type ())
#define ATK_HYPERLINK(obj)                        (G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_HYPERLINK, AtkHyperlink))
#define ATK_HYPERLINK_CLASS(klass)                (G_TYPE_CHECK_CLASS_CAST ((klass), ATK_TYPE_HYPERLINK, AtkHyperlinkClass))
#define ATK_IS_HYPERLINK(obj)                     (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_HYPERLINK))
#define ATK_IS_HYPERLINK_CLASS(klass)             (G_TYPE_CHECK_CLASS_TYPE ((klass), ATK_TYPE_HYPERLINK))
#define ATK_HYPERLINK_GET_CLASS(obj)              (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_HYPERLINK, AtkHyperlinkClass))

typedef struct _AtkHyperlink                      AtkHyperlink;
typedef struct _AtkHyperlinkClass                 AtkHyperlinkClass;

struct _AtkHyperlink
{
  GObject parent;
};

struct _AtkHyperlinkClass
{
  GObjectClass parent;

  gchar*           (* get_uri)             (AtkHyperlink     *link_,
                                            gint             i);
  AtkObject*       (* get_object)          (AtkHyperlink     *link_,
                                            gint             i);
  gint             (* get_end_index)       (AtkHyperlink     *link_);
  gint             (* get_start_index)     (AtkHyperlink     *link_);
  gboolean         (* is_valid)            (AtkHyperlink     *link_);
  gint	           (* get_n_anchors)	   (AtkHyperlink     *link_);
  guint	           (* link_state)	   (AtkHyperlink     *link_);
  gboolean         (* is_selected_link)    (AtkHyperlink     *link_);

  /* Signals */
  void             ( *link_activated)      (AtkHyperlink     *link_);
  AtkFunction      pad1;
};

ATK_AVAILABLE_IN_ALL
GType            atk_hyperlink_get_type             (void);

ATK_AVAILABLE_IN_ALL
gchar*           atk_hyperlink_get_uri              (AtkHyperlink     *link_,
                                                     gint             i);

ATK_AVAILABLE_IN_ALL
AtkObject*       atk_hyperlink_get_object           (AtkHyperlink     *link_,
                                                     gint             i);

ATK_AVAILABLE_IN_ALL
gint             atk_hyperlink_get_end_index        (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
gint             atk_hyperlink_get_start_index      (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
gboolean         atk_hyperlink_is_valid             (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
gboolean         atk_hyperlink_is_inline             (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
gint		 atk_hyperlink_get_n_anchors        (AtkHyperlink     *link_);

ATK_DEPRECATED
gboolean         atk_hyperlink_is_selected_link     (AtkHyperlink     *link_);

G_END_DECLS

#endif /* __ATK_HYPERLINK_H__ */
