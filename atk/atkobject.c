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
  gchar *accessible_id;
} AtkObjectPrivate;

static gint AtkObject_private_offset;

static void            atk_object_class_init        (AtkObjectClass  *klass);
static void            atk_object_init              (AtkObject       *accessible,
                                                     AtkObjectClass  *klass);
static AtkRelationSet* atk_object_real_ref_relation_set 
                                                    (AtkObject       *accessible);
static void            atk_object_real_initialize   (AtkObject       *accessible,
                                                     gpointer        data);
static void            atk_object_real_set_property (GObject         *object,
                                                     guint            prop_id,
                                                     const GValue    *value,
                                                     GParamSpec      *pspec);
static void            atk_object_real_get_property (GObject         *object,
                                                     guint            prop_id,
                                                     GValue          *value,
                                                     GParamSpec      *pspec);
static void            atk_object_finalize          (GObject         *object);
static const gchar*    atk_object_real_get_name     (AtkObject       *object);
static const gchar*    atk_object_real_get_description
                                                   (AtkObject       *object);
static AtkObject*      atk_object_real_get_parent  (AtkObject       *object);
static AtkRole         atk_object_real_get_role    (AtkObject       *object);
static AtkLayer        atk_object_real_get_layer   (AtkObject       *object);
static AtkStateSet*    atk_object_real_ref_state_set
                                                   (AtkObject       *object);
static void            atk_object_real_set_name    (AtkObject       *object,
                                                    const gchar     *name);
static void            atk_object_real_set_description
                                                   (AtkObject       *object,
                                                    const gchar     *description);
static void            atk_object_real_set_parent  (AtkObject       *object,
                                                    AtkObject       *parent);
static void            atk_object_real_set_role    (AtkObject       *object,
                                                    AtkRole         role);
static void            atk_object_notify           (GObject         *obj,
                                                    GParamSpec      *pspec);
static const gchar*    atk_object_real_get_object_locale
                                                   (AtkObject       *object);

static guint atk_object_signals[LAST_SIGNAL] = { 0, };

static gpointer parent_class = NULL;

static const gchar* const atk_object_name_property_name = "accessible-name";
static const gchar* const atk_object_name_property_description = "accessible-description";
static const gchar* const atk_object_name_property_parent = "accessible-parent";
static const gchar* const atk_object_name_property_value = "accessible-value";
static const gchar* const atk_object_name_property_role = "accessible-role";
static const gchar* const atk_object_name_property_component_layer = "accessible-component-layer";
static const gchar* const atk_object_name_property_component_mdi_zorder = "accessible-component-mdi-zorder";
static const gchar* const atk_object_name_property_table_caption = "accessible-table-caption";
static const gchar* const atk_object_name_property_table_column_description = "accessible-table-column-description";
static const gchar* const atk_object_name_property_table_column_header = "accessible-table-column-header";
static const gchar* const atk_object_name_property_table_row_description = "accessible-table-row-description";
static const gchar* const atk_object_name_property_table_row_header = "accessible-table-row-header";
static const gchar* const atk_object_name_property_table_summary = "accessible-table-summary";
static const gchar* const atk_object_name_property_table_caption_object = "accessible-table-caption-object";
static const gchar* const atk_object_name_property_hypertext_num_links = "accessible-hypertext-nlinks";

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

long unsigned int
atk_object_get_type (void)
{
  static long unsigned int type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkObjectClass),
        NULL,
        NULL,
        atk_object_class_init,
        NULL,
        NULL,
        sizeof (AtkObject),
        0,
        atk_object_init,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkObject", &typeInfo, 0) ;

      AtkObject_private_offset =
        g_type_add_instance_private (type, sizeof (AtkObjectPrivate));
    }
  return type;
}

static inline gpointer
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

  gobject_class->set_property = atk_object_real_set_property;
  gobject_class->get_property = atk_object_real_get_property;
  gobject_class->finalize = atk_object_finalize;
  gobject_class->notify = atk_object_notify;

  klass->get_name = atk_object_real_get_name;
  klass->get_description = atk_object_real_get_description;
  klass->get_parent = atk_object_real_get_parent;
  klass->get_n_children = NULL;
  klass->ref_child = NULL;
  klass->get_index_in_parent = NULL;
  klass->ref_relation_set = atk_object_real_ref_relation_set;
  klass->get_role = atk_object_real_get_role;
  klass->get_layer = atk_object_real_get_layer;
  klass->get_mdi_zorder = NULL;
  klass->initialize = atk_object_real_initialize;
  klass->ref_state_set = atk_object_real_ref_state_set;
  klass->set_name = atk_object_real_set_name;
  klass->set_description = atk_object_real_set_description;
  klass->set_parent = atk_object_real_set_parent;
  klass->set_role = atk_object_real_set_role;
  klass->get_object_locale = atk_object_real_get_object_locale;

  /*
   * We do not define default signal handlers here
   */
  klass->children_changed = NULL;
  klass->focus_event = NULL;
  klass->property_change = NULL;
  klass->visible_data_changed = NULL;
  klass->active_descendant_changed = NULL;

  _gettext_initialization ();

  g_object_class_install_property (gobject_class,
                                   PROP_NAME,
                                   g_param_spec_string (atk_object_name_property_name,
                                                        _("Accessible Name"),
                                                        _("Object instance’s name formatted for assistive technology access"),
                                                        NULL,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_DESCRIPTION,
                                   g_param_spec_string (atk_object_name_property_description,
                                                        _("Accessible Description"),
                                                        _("Description of an object, formatted for assistive technology access"),
                                                        NULL,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_PARENT,
                                   g_param_spec_object (atk_object_name_property_parent,
                                                        _("Accessible Parent"),
                                                        _("Parent of the current accessible as returned by atk_object_get_parent()"),
                                                        ATK_TYPE_OBJECT,
                                                        G_PARAM_READWRITE));

  /**
   * AtkObject:accessible-value:
   *
   * Numeric value of this object, in case being and AtkValue.
   *
   * Deprecated: Since 2.12. Use atk_value_get_value_and_text() to get
   * the value, and value-changed signal to be notified on their value
   * changes.
   */
  g_object_class_install_property (gobject_class,
                                   PROP_VALUE,
                                   g_param_spec_double (atk_object_name_property_value,
                                                        _("Accessible Value"),
                                                        _("Is used to notify that the value has changed"),
                                                        0.0,
                                                        G_MAXDOUBLE,
                                                        0.0,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_ROLE,
                                   g_param_spec_enum   (atk_object_name_property_role,
                                                        _("Accessible Role"),
                                                        _("The accessible role of this object"),
                                                        ATK_TYPE_ROLE,
                                                        ATK_ROLE_UNKNOWN,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_LAYER,
                                   g_param_spec_int    (atk_object_name_property_component_layer,
                                                        _("Accessible Layer"),
                                                        _("The accessible layer of this object"),
                                                        0,
                                                        G_MAXINT,
                                                        0,
                                                        G_PARAM_READABLE));
  g_object_class_install_property (gobject_class,
                                   PROP_MDI_ZORDER,
                                   g_param_spec_int    (atk_object_name_property_component_mdi_zorder,
                                                        _("Accessible MDI Value"),
                                                        _("The accessible MDI value of this object"),
                                                        G_MININT,
                                                        G_MAXINT,
                                                        G_MININT,
                                                        G_PARAM_READABLE));

  /**
   * AtkObject:accessible-table-caption:
   *
   * Table caption.
   *
   * Deprecated: Since 1.3. Use table-caption-object instead.
   */
  g_object_class_install_property (gobject_class,
                                   PROP_TABLE_CAPTION,
                                   g_param_spec_string (atk_object_name_property_table_caption,
                                                        _("Accessible Table Caption"),
                                                        _("Is used to notify that the table caption has changed; this property should not be used. accessible-table-caption-object should be used instead"),
                                                        NULL,
                                                        G_PARAM_READWRITE));
  /**
   * AtkObject:accessible-table-column-header:
   *
   * Accessible table column header.
   *
   * Deprecated: Since 2.12. Use atk_table_get_column_header() and
   * atk_table_set_column_header() instead.
   */
  g_object_class_install_property (gobject_class,
                                   PROP_TABLE_COLUMN_HEADER,
                                   g_param_spec_object (atk_object_name_property_table_column_header,
                                                        _("Accessible Table Column Header"),
                                                        _("Is used to notify that the table column header has changed"),
                                                        ATK_TYPE_OBJECT,
                                                        G_PARAM_READWRITE));

  /**
   * AtkObject:accessible-table-column-description:
   *
   * Accessible table column description.
   *
   * Deprecated: Since 2.12. Use atk_table_get_column_description()
   * and atk_table_set_column_description() instead.
   */
  g_object_class_install_property (gobject_class,
                                   PROP_TABLE_COLUMN_DESCRIPTION,
                                   g_param_spec_string (atk_object_name_property_table_column_description,
                                                        _("Accessible Table Column Description"),
                                                        _("Is used to notify that the table column description has changed"),
                                                        NULL,
                                                        G_PARAM_READWRITE));

  /**
   * AtkObject:accessible-table-row-header:
   *
   * Accessible table row header.
   *
   * Deprecated: Since 2.12. Use atk_table_get_row_header() and
   * atk_table_set_row_header() instead.
   */
  g_object_class_install_property (gobject_class,
                                   PROP_TABLE_ROW_HEADER,
                                   g_param_spec_object (atk_object_name_property_table_row_header,
                                                        _("Accessible Table Row Header"),
                                                        _("Is used to notify that the table row header has changed"),
                                                        ATK_TYPE_OBJECT,
                                                        G_PARAM_READWRITE));
  /**
   * AtkObject:accessible-table-row-description:
   *
   * Accessible table row description.
   *
   * Deprecated: Since 2.12. Use atk_table_get_row_description() and
   * atk_table_set_row_description() instead.
   */
  g_object_class_install_property (gobject_class,
                                   PROP_TABLE_ROW_DESCRIPTION,
                                   g_param_spec_string (atk_object_name_property_table_row_description,
                                                        _("Accessible Table Row Description"),
                                                        _("Is used to notify that the table row description has changed"),
                                                        NULL,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_TABLE_SUMMARY,
                                   g_param_spec_object (atk_object_name_property_table_summary,
                                                        _("Accessible Table Summary"),
                                                        _("Is used to notify that the table summary has changed"),
                                                        ATK_TYPE_OBJECT,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_TABLE_CAPTION_OBJECT,
                                   g_param_spec_object (atk_object_name_property_table_caption_object,
                                                        _("Accessible Table Caption Object"),
                                                        _("Is used to notify that the table caption has changed"),
                                                        ATK_TYPE_OBJECT,
                                                        G_PARAM_READWRITE));
  g_object_class_install_property (gobject_class,
                                   PROP_HYPERTEXT_NUM_LINKS,
                                   g_param_spec_int    (atk_object_name_property_hypertext_num_links,
                                                        _("Number of Accessible Hypertext Links"),
                                                        _("The number of links which the current AtkHypertext has"),
                                                        0,
                                                        G_MAXINT,
                                                        0,
                                                        G_PARAM_READABLE));

  /**
   * AtkObject::children-changed:
   * @atkobject: the object which received the signal.
   * @arg1: The index of the added or removed child. The value can be
   * -1. This is used if the value is not known by the implementor
   * when the child is added/removed or irrelevant.
   * @arg2: (type AtkObject): A gpointer to the child AtkObject which was added or
   * removed. If the child was removed, it is possible that it is not
   * available for the implementor. In that case this pointer can be
   * NULL.
   *
   * The signal "children-changed" is emitted when a child is added or
   * removed form an object. It supports two details: "add" and
   * "remove"
   */
  atk_object_signals[CHILDREN_CHANGED] =
    g_signal_new ("children_changed",
		  G_TYPE_FROM_CLASS (klass),
		  G_SIGNAL_RUN_LAST | G_SIGNAL_DETAILED,
		  G_STRUCT_OFFSET (AtkObjectClass, children_changed),
		  NULL, NULL,
		  g_cclosure_marshal_VOID__UINT_POINTER,
		  G_TYPE_NONE,
		  2, G_TYPE_UINT, G_TYPE_POINTER);

  /**
   * AtkObject::focus-event:
   * @atkobject: the object which received the signal
   * @arg1: a boolean value which indicates whether the object gained
   * or lost focus.
   *
   * The signal "focus-event" is emitted when an object gained or lost
   * focus.
   *
   * Deprecated: 2.9.4: Use the #AtkObject::state-change signal instead.
   */
  atk_object_signals[FOCUS_EVENT] =
    g_signal_new ("focus_event",
		  G_TYPE_FROM_CLASS (klass),
		  G_SIGNAL_RUN_LAST,
		  G_STRUCT_OFFSET (AtkObjectClass, focus_event), 
		  NULL, NULL,
		  g_cclosure_marshal_VOID__BOOLEAN,
		  G_TYPE_NONE,
		  1, G_TYPE_BOOLEAN);
  /**
   * AtkObject::property-change:
   * @atkobject: the object which received the signal.
   * @arg1: (type AtkPropertyValues): an #AtkPropertyValues containing the new
   * value of the property which changed.
   *
   * The signal "property-change" is emitted when an object's property
   * value changes. @arg1 contains an #AtkPropertyValues with the name
   * and the new value of the property whose value has changed. Note
   * that, as with GObject notify, getting this signal does not
   * guarantee that the value of the property has actually changed; it
   * may also be emitted when the setter of the property is called to
   * reinstate the previous value.
   *
   * Toolkit implementor note: ATK implementors should use
   * g_object_notify() to emit property-changed
   * notifications. #AtkObject::property-changed is needed by the
   * implementation of atk_add_global_event_listener() because GObject
   * notify doesn't support emission hooks.
   */
  atk_object_signals[PROPERTY_CHANGE] =
    g_signal_new ("property_change",
                  G_TYPE_FROM_CLASS (klass),
                  G_SIGNAL_RUN_LAST | G_SIGNAL_DETAILED,
                  G_STRUCT_OFFSET (AtkObjectClass, property_change),
                  (GSignalAccumulator) NULL, NULL,
                  g_cclosure_marshal_VOID__POINTER,
                  G_TYPE_NONE, 1,
                  G_TYPE_POINTER);

  /**
   * AtkObject::state-change:
   * @atkobject: the object which received the signal.
   * @arg1: The name of the state which has changed
   * @arg2: A boolean which indicates whether the state has been set or unset.
   *
   * The "state-change" signal is emitted when an object's state
   * changes.  The detail value identifies the state type which has
   * changed.
   */
  atk_object_signals[STATE_CHANGE] =
    g_signal_new ("state_change",
                  G_TYPE_FROM_CLASS (klass),
                  G_SIGNAL_RUN_LAST | G_SIGNAL_DETAILED,
                  G_STRUCT_OFFSET (AtkObjectClass, state_change),
                  (GSignalAccumulator) NULL, NULL,
                  atk_marshal_VOID__STRING_BOOLEAN,
                  G_TYPE_NONE, 2,
                  G_TYPE_STRING,
                  G_TYPE_BOOLEAN);

  /**
   * AtkObject::visible-data-changed:
   * @atkobject: the object which received the signal.
   *
   * The "visible-data-changed" signal is emitted when the visual
   * appearance of the object changed.
   */
  atk_object_signals[VISIBLE_DATA_CHANGED] =
    g_signal_new ("visible_data_changed",
                  G_TYPE_FROM_CLASS (klass),
                  G_SIGNAL_RUN_LAST,
                  G_STRUCT_OFFSET (AtkObjectClass, visible_data_changed),
                  (GSignalAccumulator) NULL, NULL,
                  g_cclosure_marshal_VOID__VOID,
                  G_TYPE_NONE, 0);

  /**
   * AtkObject::active-descendant-changed:
   * @atkobject: the object which received the signal.
   * @arg1: (type AtkObject): the newly focused object.
   *
   * The "active-descendant-changed" signal is emitted by an object
   * which has the state ATK_STATE_MANAGES_DESCENDANTS when the focus
   * object in the object changes. For instance, a table will emit the
   * signal when the cell in the table which has focus changes.
   */
  atk_object_signals[ACTIVE_DESCENDANT_CHANGED] =
    g_signal_new ("active_descendant_changed",
		  G_TYPE_FROM_CLASS (klass),
		  G_SIGNAL_RUN_LAST | G_SIGNAL_DETAILED,
		  G_STRUCT_OFFSET (AtkObjectClass, active_descendant_changed),
		  NULL, NULL,
		  g_cclosure_marshal_VOID__POINTER,
		  G_TYPE_NONE,
		  1, G_TYPE_POINTER);
}


static void
atk_object_init  (AtkObject        *accessible,
                  AtkObjectClass   *klass)
{
}

long unsigned int
atk_implementor_get_type (void)
{
    return 0;
}

const gchar*
atk_object_get_name (AtkObject *accessible)
{
    return 0;
}

const gchar*
atk_object_get_description (AtkObject *accessible)
{
    return 0;
}

AtkObject*
atk_object_get_parent (AtkObject *accessible)
{
  AtkObjectClass *klass;

  g_return_val_if_fail (ATK_IS_OBJECT (accessible), NULL);

  klass = ATK_OBJECT_GET_CLASS (accessible);
  if (klass->get_parent)
    return (klass->get_parent) (accessible);
  else
    return NULL;
}

AtkObject*
atk_object_peek_parent (AtkObject *accessible)
{
  return 0;
}

gint
atk_object_get_n_accessible_children (AtkObject *accessible)
{
    return 0;
}

AtkObject*
atk_object_ref_accessible_child (AtkObject   *accessible,
                                 gint        i)
{
    return 0;
}

AtkRelationSet*
atk_object_ref_relation_set (AtkObject *accessible)
{
    return 0;
}
AtkRole
atk_role_register (const gchar *name)
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

gint
atk_object_get_mdi_zorder (AtkObject *accessible) 
{
    return G_MININT;
}

AtkStateSet*
atk_object_ref_state_set (AtkObject *accessible) 
{
    return 0;
}
gint
atk_object_get_index_in_parent (AtkObject *accessible)
{
    return -1;
}

void
atk_object_set_name (AtkObject    *accessible,
                     const gchar  *name)
{
}

void
atk_object_set_description (AtkObject   *accessible,
                            const gchar *description)
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

guint
atk_object_connect_property_change_handler (AtkObject *accessible,
                                            AtkPropertyChangeHandler *handler)
{
    return 0;
}

void
atk_object_remove_property_change_handler  (AtkObject *accessible,
                                            guint      handler_id)
{
}

void
atk_object_notify_state_change (AtkObject *accessible,
                                AtkState  state,
                                gboolean  value)
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

static AtkRelationSet*
atk_object_real_ref_relation_set (AtkObject *accessible)
{
    return 0;
}

static void
atk_object_real_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
}

static void
atk_object_real_get_property (GObject      *object,
                              guint         prop_id,
                              GValue       *value,
                              GParamSpec   *pspec)
{
}

static void
atk_object_finalize (GObject *object)
{
}

static const gchar*
atk_object_real_get_name (AtkObject *object)
{
  return 0;
}

static const gchar*
atk_object_real_get_description (AtkObject *object)
{
  return 0;
}

static AtkObject*
atk_object_real_get_parent (AtkObject       *object)
{
  return 0;
}

static AtkRole
atk_object_real_get_role (AtkObject       *object)
{
  return 0;
}

static AtkLayer
atk_object_real_get_layer (AtkObject       *object)
{
  return 0;
}

static AtkStateSet*
atk_object_real_ref_state_set (AtkObject *accessible) 
{
    return 0;
}

static void
atk_object_real_set_name (AtkObject       *object,
                          const gchar     *name)
{
}

static void
atk_object_real_set_description (AtkObject       *object,
                                 const gchar     *description)
{
}

static void
atk_object_real_set_parent (AtkObject       *object,
                            AtkObject       *parent)
{
}

static void
atk_object_real_set_role (AtkObject *object,
                          AtkRole   role)
{
}

void
atk_object_initialize (AtkObject  *accessible,
                       gpointer   data)
{
  AtkObjectClass *klass;

  g_return_if_fail (ATK_IS_OBJECT (accessible));

  klass = ATK_OBJECT_GET_CLASS (accessible);
  if (klass->initialize)
    klass->initialize (accessible, data);
}

static void
atk_object_notify (GObject     *obj,
                   GParamSpec  *pspec)
{
}

const gchar*
atk_role_get_name (AtkRole role)
{
    return 0;
}

const gchar*
atk_role_get_localized_name (AtkRole role)
{
    return 0;
}

static const gchar*
atk_object_real_get_object_locale (AtkObject *object)
{
    return 0;
}

const gchar*
atk_object_get_object_locale (AtkObject *accessible)
{
    return 0;
}

AtkRole
atk_role_for_name (const gchar *name)
{
    return 0;
}

gboolean
atk_object_add_relationship (AtkObject       *object,
                             AtkRelationType relationship,
                             AtkObject       *target)
{
    return 0;
}

gboolean
atk_object_remove_relationship (AtkObject       *object,
                                AtkRelationType relationship,
                                AtkObject       *target)
{
    return 0;
}

const gchar*
atk_object_get_accessible_id (AtkObject *accessible)
{
    return 0;
}

void
atk_object_set_accessible_id (AtkObject *accessible, const gchar *id)
{
}

static void
atk_object_real_initialize (AtkObject *accessible,
                            gpointer  data)
{
}
