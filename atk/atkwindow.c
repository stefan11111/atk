

#include "atkwindow.h"
#include "atkmarshal.h"

enum {
  ACTIVATE,
  CREATE,
  DEACTIVATE,
  DESTROY,
  MAXIMIZE,
  MINIMIZE,
  MOVE,
  RESIZE,
  RESTORE,
  LAST_SIGNAL
};

typedef AtkWindowIface AtkWindowInterface;

long unsigned int atk_window_get_type(void)
{
    return 0;
}
