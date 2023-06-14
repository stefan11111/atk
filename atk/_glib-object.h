#include <glib-object.h>

#ifndef G_ENCODE_VERSION
# define G_ENCODE_VERSION(major, minor) ((major) << 16 | (minor) << 8)
#endif

#ifndef __GOBJECT_BLOAT__
#define __GOBJECT_BLOAT__

struct GObject{
    void* g_type_instance;
    unsigned int ref_count;
    void* qdata;
};
#endif
/*
typedef struct{
    void* g_type_class;
    void* construct_properties;
    void* constructor;
    void* set_property;
    void* get_property;
    void* dispose;
    void* finalize;
    void* dispatch_properties_changed;
    void* notify;
    void* constructed;
    int flags;
    int n_construct_properties;
    void* pspecs;
    int n_pspecs;
    void* padding[3];
} GObjectClass;
#endif
*/
/*
typedef GObject;
typedef GObjectClass;

typedef struct _GObject                  GObject;
typedef struct _GObjectClass             GObjectClass;
typedef struct _GObject                  GInitiallyUnowned;
typedef struct _GObjectClass             GInitiallyUnownedClass;
typedef struct _GObjectConstructParam    GObjectConstructParam;
*/

