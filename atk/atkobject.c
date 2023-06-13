#include "config.h"

#include <atk/_glib-object.h>

#include "atk.h"
#include "atkmarshal.h"
#include "atkprivate.h"

enum
{
  PROP_0,  /* gobject convention */

  PROP_NAME,
  PROP_DESCRIPTION,
  PROP_PARENT,      /* ancestry has changed */
  PROP_VALUE,
  PROP_ROLE,
  PROP_LAYER,
  PROP_MDI_ZORDER,
  PROP_TABLE_CAPTION,
  PROP_TABLE_COLUMN_DESCRIPTION,
  PROP_TABLE_COLUMN_HEADER,
  PROP_TABLE_ROW_DESCRIPTION,
  PROP_TABLE_ROW_HEADER,
  PROP_TABLE_SUMMARY,
  PROP_TABLE_CAPTION_OBJECT,
  PROP_HYPERTEXT_NUM_LINKS,
  PROP_ACCESSIBLE_ID,
  PROP_LAST         /* gobject convention */
};

enum {
  CHILDREN_CHANGED,
  FOCUS_EVENT,
  PROPERTY_CHANGE,
  STATE_CHANGE,
  VISIBLE_DATA_CHANGED,
  ACTIVE_DESCENDANT_CHANGED,
  
  LAST_SIGNAL
};

typedef struct {
  char *accessible_id;
} AtkObjectPrivate;

static int AtkObject_private_offset;

static void            atk_object_class_init        (AtkObjectClass  *klass);
static void            atk_object_init              (AtkObject       *accessible,
                                                     AtkObjectClass  *klass);

static unsigned int atk_object_signals[LAST_SIGNAL] = { 0, };

static void* parent_class = 0;

static const char* const atk_object_name_property_name = "accessible-name";
static const char* const atk_object_name_property_description = "accessible-description";
static const char* const atk_object_name_property_parent = "accessible-parent";
static const char* const atk_object_name_property_value = "accessible-value";
static const char* const atk_object_name_property_role = "accessible-role";
static const char* const atk_object_name_property_component_layer = "accessible-component-layer";
static const char* const atk_object_name_property_component_mdi_zorder = "accessible-component-mdi-zorder";
static const char* const atk_object_name_property_table_caption = "accessible-table-caption";
static const char* const atk_object_name_property_table_column_description = "accessible-table-column-description";
static const char* const atk_object_name_property_table_column_header = "accessible-table-column-header";
static const char* const atk_object_name_property_table_row_description = "accessible-table-row-description";
static const char* const atk_object_name_property_table_row_header = "accessible-table-row-header";
static const char* const atk_object_name_property_table_summary = "accessible-table-summary";
static const char* const atk_object_name_property_table_caption_object = "accessible-table-caption-object";
static const char* const atk_object_name_property_hypertext_num_links = "accessible-hypertext-nlinks";

struct GTypeInfo {
  short class_size;
  void* base_init;
  void* base_finalize;
  void* class_init;
  void* class_finalize;
  void* class_data;
  short instance_size;
  short n_preallocs;
  void* instance_init;
};

static void bloat()
{
}

long unsigned int
atk_object_get_type (void)
{
  static long unsigned int type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkObjectClass),
        0,
        0,
        atk_object_class_init,
        0,
        0,
        sizeof (AtkObject),
        0,
        bloat,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkObject", &typeInfo, 0) ;

      AtkObject_private_offset =
        g_type_add_instance_private (type, sizeof (AtkObjectPrivate));
    }
  return type;
}

static inline void*
atk_object_get_instance_private (AtkObject *self)
{
  return (G_STRUCT_MEMBER_P (self, AtkObject_private_offset));
}

static void
atk_object_class_init (AtkObjectClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  parent_class = g_type_class_peek_parent (klass);

  if (AtkObject_private_offset != 0)
    g_type_class_adjust_private_offset (klass, &AtkObject_private_offset);

  gobject_class->set_property = bloat;
  gobject_class->get_property = bloat;
  gobject_class->finalize = bloat;
  gobject_class->notify = bloat;

  klass->get_name = bloat;
  klass->get_description = bloat;
  klass->get_parent = bloat;
  klass->get_n_children = 0;
  klass->ref_child = 0;
  klass->get_index_in_parent = 0;
  klass->ref_relation_set = bloat;
  klass->get_role = bloat;
  klass->get_layer = bloat;
  klass->get_mdi_zorder = 0;
  klass->initialize = bloat;
  klass->ref_state_set = bloat;
  klass->set_name = bloat;
  klass->set_description = bloat;
  klass->set_parent = bloat;
  klass->set_role = bloat;
  klass->get_object_locale = bloat;

  /*
   * We do not define default signal handlers here
   */
  klass->children_changed = 0;
  klass->focus_event = 0;
  klass->property_change = 0;
  klass->visible_data_changed = 0;
  klass->active_descendant_changed = 0;

  g_object_class_install_property (gobject_class,
                                   PROP_NAME,
                                   g_param_spec_string (atk_object_name_property_name,
                                                        0,
                                                        0,
                                                        0,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_PARENT,
                                   g_param_spec_object (atk_object_name_property_parent,
                                                        0,
                                                        0,
                                                        ATK_TYPE_OBJECT,
                                                        G_PARAM_READWRITE));
}

long unsigned int
atk_implementor_get_type (void)
{
    return 0;
}

const char*
atk_object_get_name (AtkObject *accessible)
{
    return 0;
}

const char*
atk_object_get_description (AtkObject *accessible)
{
    return 0;
}

AtkObject*
atk_object_get_parent (AtkObject *accessible)
{
  AtkObjectClass *klass;

  klass = ATK_OBJECT_GET_CLASS (accessible);
  if (klass->get_parent)
    return (klass->get_parent) (accessible);
  else
    return 0;
}

AtkObject*
atk_object_peek_parent (AtkObject *accessible)
{
  return 0;
}

int
atk_object_get_n_accessible_children (AtkObject *accessible)
{
    return 0;
}

AtkObject*
atk_object_ref_accessible_child (AtkObject   *accessible,
                                 int        i)
{
    return 0;
}

AtkRelationSet*
atk_object_ref_relation_set (AtkObject *accessible)
{
    return 0;
}
AtkRole
atk_role_register (const char *name)
{
    return 0;
}

AtkRole
atk_object_get_role (AtkObject *accessible) 
{
    return ATK_ROLE_UNKNOWN;
}

AtkLayer
atk_object_get_layer (AtkObject *accessible) 
{
    return ATK_LAYER_INVALID;
}

int
atk_object_get_mdi_zorder (AtkObject *accessible) 
{
    return G_MININT;
}

AtkStateSet*
atk_object_ref_state_set (AtkObject *accessible) 
{
    return 0;
}
int
atk_object_get_index_in_parent (AtkObject *accessible)
{
    return -1;
}

void
atk_object_set_name (AtkObject    *accessible,
                     const char  *name)
{
}

void
atk_object_set_description (AtkObject   *accessible,
                            const char *description)
{
}

void
atk_object_set_parent (AtkObject *accessible,
                       AtkObject *parent)
{
}

void
atk_object_set_role (AtkObject *accessible, 
                     AtkRole   role)
{
}

unsigned int
atk_object_connect_property_change_handler (AtkObject *accessible,
                                            AtkPropertyChangeHandler *handler)
{
    return 0;
}

void
atk_object_remove_property_change_handler  (AtkObject *accessible,
                                            unsigned int      handler_id)
{
}

void
atk_object_notify_state_change (AtkObject *accessible,
                                unsigned long long  state,
                                unsigned char  value)
{
}

AtkObject *
atk_implementor_ref_accessible (AtkImplementor *implementor)
{
    return 0;
}

AtkAttributeSet *
atk_object_get_attributes (AtkObject                  *accessible)
{
    return 0;
	
}

void
atk_object_initialize (AtkObject  *accessible,
                       void*   data)
{
  AtkObjectClass *klass;

  klass = ATK_OBJECT_GET_CLASS (accessible);
  if (klass->initialize)
    klass->initialize (accessible, data);
}


const char*
atk_role_get_name (AtkRole role)
{
    return 0;
}

const char*
atk_role_get_localized_name (AtkRole role)
{
    return 0;
}

const char*
atk_object_get_object_locale (AtkObject *accessible)
{
    return 0;
}

AtkRole
atk_role_for_name (const char *name)
{
    return 0;
}

unsigned char
atk_object_add_relationship (AtkObject       *object,
                             AtkRelationType relationship,
                             AtkObject       *target)
{
    return 0;
}

unsigned char
atk_object_remove_relationship (AtkObject       *object,
                                AtkRelationType relationship,
                                AtkObject       *target)
{
    return 0;
}

const char*
atk_object_get_accessible_id (AtkObject *accessible)
{
    return 0;
}

void
atk_object_set_accessible_id (AtkObject *accessible, const char *id)
{
}
