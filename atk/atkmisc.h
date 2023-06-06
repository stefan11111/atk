#ifndef __ATK_MISC_H__
#define __ATK_MISC_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <glib-object.h>
#include <atk/atkversion.h>

/* We prefix variable declarations so they can
 * properly get exported in Windows DLLs.
 */
#ifndef ATK_VAR
#  ifdef G_PLATFORM_WIN32
#    ifdef ATK_STATIC_COMPILATION
#      define ATK_VAR extern
#    else /* !ATK_STATIC_COMPILATION */
#      ifdef ATK_COMPILATION
#        ifdef DLL_EXPORT
#          define ATK_VAR _ATK_EXTERN
#        else /* !DLL_EXPORT */
#          define ATK_VAR extern
#        endif /* !DLL_EXPORT */
#      else /* !ATK_COMPILATION */
#        define ATK_VAR extern __declspec(dllimport)
#      endif /* !ATK_COMPILATION */
#    endif /* !ATK_STATIC_COMPILATION */
#  else /* !G_PLATFORM_WIN32 */
#    define ATK_VAR _ATK_EXTERN
#  endif /* !G_PLATFORM_WIN32 */
#endif /* ATK_VAR */

G_BEGIN_DECLS

#define ATK_TYPE_MISC                   (atk_misc_get_type ())
#define ATK_IS_MISC(obj)                G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_MISC)
#define ATK_MISC(obj)                   G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_MISC, AtkMisc)
#define ATK_MISC_CLASS(klass)                   (G_TYPE_CHECK_CLASS_CAST ((klass), ATK_TYPE_MISC, AtkMiscClass))
#define ATK_IS_MISC_CLASS(klass)                (G_TYPE_CHECK_CLASS_TYPE ((klass), ATK_TYPE_MISC))
#define ATK_MISC_GET_CLASS(obj)                 (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_MISC, AtkMiscClass))


#ifndef _TYPEDEF_ATK_MISC_
#define _TYPEDEF_ATK_MISC_
typedef struct _AtkMisc      AtkMisc;
typedef struct _AtkMiscClass AtkMiscClass;
#endif

struct _AtkMisc
{
  GObject parent;
};

ATK_VAR AtkMisc *atk_misc_instance;

struct _AtkMiscClass
{
   GObjectClass parent;
   void   (* threads_enter)                     (AtkMisc *misc);
   void   (* threads_leave)                     (AtkMisc *misc);
   gpointer vfuncs[32]; /* future bincompat */
};

ATK_DEPRECATED_IN_2_12
GType atk_misc_get_type (void);

ATK_DEPRECATED_IN_2_12
void     atk_misc_threads_enter  (AtkMisc *misc);
ATK_DEPRECATED_IN_2_12
void     atk_misc_threads_leave  (AtkMisc *misc);
ATK_DEPRECATED_IN_2_12
const AtkMisc *atk_misc_get_instance (void);

G_END_DECLS

#endif /* __ATK_MISC_H__ */