#ifndef G_BEGIN_DECLS
# define G_BEGIN_DECLS
#endif

#ifndef G_END_DECLS
# define G_END_DECLS
#endif

#ifndef _
# define  _(String) ((char *) g_dgettext (GETTEXT_PACKAGE, String))
#endif
/*
#ifndef G_ENCODE_VERSION
# define G_ENCODE_VERSION(major, minor) ((major) << 16 | (minor) << 8)
#endif

#ifndef G_GNUC_CONST
# define G_GNUC_CONST
#endif

#ifndef NULL
# define NULL 0
#endif
*/
typedef char gchar;
/*
typedef unsigned int guint;
typedef void* gpointer;

typedef GObject;
typedef GObjectClass;
typedef long unsigned int GType;

typedef struct _GObject                  GObject;
typedef struct _GObjectClass             GObjectClass;
typedef struct _GObject                  GInitiallyUnowned;
typedef struct _GObjectClass             GInitiallyUnownedClass;
typedef struct _GObjectConstructParam    GObjectConstructParam;
*/
