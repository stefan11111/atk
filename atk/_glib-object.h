/* void* g_type_class_peek_parent() (*((void**)(ptr) + 6)) + 8 */

#ifndef __ATK_H_INSIDE__
#ifndef __function_bloat__
#define __function_bloat__
extern unsigned long long g_type_register_static();
extern int g_type_add_instance_private();
extern void g_type_class_adjust_private_offset();
extern void g_object_class_install_property();
extern void* g_param_spec_string();
extern void* g_param_spec_object();
#endif
#endif

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
    void* wasted[3];
};
#endif
