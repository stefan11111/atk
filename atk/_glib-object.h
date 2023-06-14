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

struct GObjectClass{
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
    void* flags;
    void* n_construct_properties;
    void* pspecs;
    void* n_pspecs;
};
#endif
