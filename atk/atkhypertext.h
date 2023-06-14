#ifndef __ATK_HYPERTEXT_H__
#define __ATK_HYPERTEXT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atkhyperlink.h>



#define ATK_TYPE_HYPERTEXT                    (atk_hypertext_get_type ())
#define ATK_IS_HYPERTEXT(obj)                 0
#define ATK_HYPERTEXT(obj)                    (obj)
#define ATK_HYPERTEXT_GET_IFACE(obj)          (*(void**)(obj))

#ifndef _TYPEDEF_ATK_HYPERTEXT_
#define _TYPEDEF_ATK_HYPERTEXT_
typedef struct _AtkHypertext AtkHypertext;
#endif
typedef struct _AtkHypertextIface AtkHypertextIface;

struct _AtkHypertextIface
{
  long unsigned int* parent;

  AtkHyperlink*(* get_link)                 (AtkHypertext       *hypertext,
                                             int               link_index);
  int         (* get_n_links)              (AtkHypertext       *hypertext);
  int         (* get_link_index)           (AtkHypertext       *hypertext,
                                             int               char_index);

  /*
   * signal handlers
   */
  void         (* link_selected)            (AtkHypertext       *hypertext,
                                             int               link_index);
};
ATK_AVAILABLE_IN_ALL
long unsigned int atk_hypertext_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkHyperlink* atk_hypertext_get_link       (AtkHypertext *hypertext,
                                            int          link_index);
ATK_AVAILABLE_IN_ALL
int          atk_hypertext_get_n_links    (AtkHypertext *hypertext);
ATK_AVAILABLE_IN_ALL
int          atk_hypertext_get_link_index (AtkHypertext *hypertext,
                                            int          char_index);



#endif /* __ATK_HYPERTEXT_H__ */
