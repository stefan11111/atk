#ifndef __ATK_SELECTION_H__
#define __ATK_SELECTION_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_SELECTION                        (atk_selection_get_type ())
#define ATK_IS_SELECTION(obj)                     0
#define ATK_SELECTION(obj)                        (obj)
#define ATK_SELECTION_GET_IFACE(obj)              (*(void**)(obj))

#ifndef _TYPEDEF_ATK_SELECTION_
#define _TYPEDEF_ATK_SELECTION_
typedef struct _AtkSelection AtkSelection;
#endif
typedef struct _AtkSelectionIface AtkSelectionIface;

struct _AtkSelectionIface
{
  long unsigned int* parent;

  unsigned char     (* add_selection)        (AtkSelection   *selection,
                                         int           i);
  unsigned char     (* clear_selection)      (AtkSelection   *selection);
  AtkObject*   (* ref_selection)        (AtkSelection   *selection,
                                         int           i);
  int         (* get_selection_count)  (AtkSelection   *selection);
  unsigned char     (* is_child_selected)    (AtkSelection   *selection,
                                         int           i);
  unsigned char     (* remove_selection)     (AtkSelection   *selection,
                                         int           i);
  unsigned char     (* select_all_selection) (AtkSelection   *selection);

  /* signal handlers */
  
  void         (*selection_changed)     (AtkSelection   *selection);
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_selection_get_type (void);

ATK_AVAILABLE_IN_ALL
unsigned char     atk_selection_add_selection        (AtkSelection   *selection,
                                                 int           i);

ATK_AVAILABLE_IN_ALL
unsigned char     atk_selection_clear_selection      (AtkSelection   *selection);

ATK_AVAILABLE_IN_ALL
AtkObject*   atk_selection_ref_selection        (AtkSelection   *selection,
                                                 int           i);

ATK_AVAILABLE_IN_ALL
int         atk_selection_get_selection_count  (AtkSelection   *selection);

ATK_AVAILABLE_IN_ALL
unsigned char     atk_selection_is_child_selected    (AtkSelection   *selection,
                                                 int           i);

ATK_AVAILABLE_IN_ALL
unsigned char     atk_selection_remove_selection     (AtkSelection   *selection,
                                                 int           i);

ATK_AVAILABLE_IN_ALL
unsigned char     atk_selection_select_all_selection (AtkSelection   *selection);



#endif /* __ATK_SELECTION_H__ */
