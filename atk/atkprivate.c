#include "config.h"

#include <string.h>
#include <locale.h>

#include <glib-object.h>
#include <glib/gi18n-lib.h>

#include "atkprivate.h"

#ifdef G_OS_WIN32

#define STRICT
#include <windows.h>
#undef STRICT

BOOL WINAPI
DllMain (HINSTANCE hinstDLL,
         DWORD     fdwReason,
         LPVOID    lpvReserved)
{
    return 1;
}

#undef ATK_LOCALEDIR

#define ATK_LOCALEDIR get_atk_locale_dir()

#endif

void
_gettext_initialization (void)
{
}

void
_compact_name (gchar *name)
{
}
