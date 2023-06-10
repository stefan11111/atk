#ifndef __ATK_HYPERLINK_IMPL_H__
#define __ATK_HYPERLINK_IMPL_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atkhyperlink.h>



#define ATK_TYPE_HYPERLINK_IMPL          (atk_hyperlink_impl_get_type ())
#define ATK_IS_HYPERLINK_IMPL(obj)        ((obj), ATK_TYPE_HYPERLINK_IMPL)
#define ATK_HYPERLINK_IMPL(obj)              ((obj), ATK_TYPE_HYPERLINK_IMPL, AtkHyperlinkImpl)
#define ATK_HYPERLINK_IMPL_GET_IFACE(obj)    ((obj), ATK_TYPE_HYPERLINK_IMPL, AtkHyperlinkImplIface)

#ifndef _TYPEDEF_ATK_HYPERLINK_IMPL_
#define _TYPEDEF_ATK_HYPERLINK_IMPL__

typedef struct _AtkHyperlinkImpl AtkHyperlinkImpl;
#endif
typedef struct _AtkHyperlinkImplIface AtkHyperlinkImplIface;

struct _AtkHyperlinkImplIface
{
  long unsigned int* parent;
    
  AtkHyperlink*  (* get_hyperlink) (AtkHyperlinkImpl *impl);
};

ATK_AVAILABLE_IN_ALL
long unsigned int            atk_hyperlink_impl_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkHyperlink    *atk_hyperlink_impl_get_hyperlink (AtkHyperlinkImpl *impl);



#endif /* __ATK_HYPERLINK_IMPL_H__ */
