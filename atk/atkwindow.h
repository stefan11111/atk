#ifndef __ATK_WINDOW_H__
#define __ATK_WINDOW_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_WINDOW                    (atk_window_get_type ())
#define ATK_IS_WINDOW(obj)                 0
#define ATK_WINDOW(obj)                    (obj)
#define ATK_WINDOW_GET_IFACE(obj)          (*(void**)(obj))

typedef struct _AtkWindow AtkWindow; /* Dummy typedef */
typedef struct _AtkWindowIface AtkWindowIface;

struct _AtkWindowIface
{
  long unsigned int* parent;
};

ATK_AVAILABLE_IN_2_2
long unsigned int atk_window_get_type (void);


#endif /* __ATK_WINDOW_H__ */
