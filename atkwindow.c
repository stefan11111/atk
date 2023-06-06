#include "config.h"

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
G_DEFINE_INTERFACE (AtkWindow, atk_window, ATK_TYPE_OBJECT)

static void atk_window_default_init()
{
}