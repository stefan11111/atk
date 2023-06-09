#ifndef __ATK_HYPERLINK_H__
#define __ATK_HYPERLINK_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkaction.h>



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
#define ATK_HYPERLINK(obj)                        (obj)
#define ATK_HYPERLINK_CLASS(klass)                (klass)
#define ATK_IS_HYPERLINK(obj)                     0
#define ATK_IS_HYPERLINK_CLASS(klass)             0
#define ATK_HYPERLINK_GET_CLASS(obj)              (*(void**)(obj))

typedef struct _AtkHyperlink                      AtkHyperlink;
typedef struct _AtkHyperlinkClass                 AtkHyperlinkClass;

struct _AtkHyperlink
{
  __GObject parent;
};

struct _AtkHyperlinkClass
{
  __GObjectClass parent;

  char*           (* get_uri)             (AtkHyperlink     *link_,
                                            int             i);
  AtkObject*       (* get_object)          (AtkHyperlink     *link_,
                                            int             i);
  int             (* get_end_index)       (AtkHyperlink     *link_);
  int             (* get_start_index)     (AtkHyperlink     *link_);
  unsigned char         (* is_valid)            (AtkHyperlink     *link_);
  int	           (* get_n_anchors)	   (AtkHyperlink     *link_);
  unsigned int	           (* link_state)	   (AtkHyperlink     *link_);
  unsigned char         (* is_selected_link)    (AtkHyperlink     *link_);

  /* Signals */
  void             ( *link_activated)      (AtkHyperlink     *link_);
  AtkFunction      pad1;
};

ATK_AVAILABLE_IN_ALL
long unsigned int            atk_hyperlink_get_type             (void);

ATK_AVAILABLE_IN_ALL
char*           atk_hyperlink_get_uri              (AtkHyperlink     *link_,
                                                     int             i);

ATK_AVAILABLE_IN_ALL
AtkObject*       atk_hyperlink_get_object           (AtkHyperlink     *link_,
                                                     int             i);

ATK_AVAILABLE_IN_ALL
int             atk_hyperlink_get_end_index        (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
int             atk_hyperlink_get_start_index      (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
unsigned char         atk_hyperlink_is_valid             (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
unsigned char         atk_hyperlink_is_inline             (AtkHyperlink     *link_);

ATK_AVAILABLE_IN_ALL
int		 atk_hyperlink_get_n_anchors        (AtkHyperlink     *link_);

ATK_DEPRECATED
unsigned char         atk_hyperlink_is_selected_link     (AtkHyperlink     *link_);



#endif /* __ATK_HYPERLINK_H__ */
