#ifndef __ATK_DOCUMENT_H__
#define __ATK_DOCUMENT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atkutil.h>

G_BEGIN_DECLS

#define ATK_TYPE_DOCUMENT                   (atk_document_get_type ())
#define ATK_IS_DOCUMENT(obj)                G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_DOCUMENT)
#define ATK_DOCUMENT(obj)                   G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_DOCUMENT, AtkDocument)
#define ATK_DOCUMENT_GET_IFACE(obj)         (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_DOCUMENT, AtkDocumentIface))

#ifndef _TYPEDEF_ATK_DOCUMENT_
#define _TYPEDEF_ATK_DOCUMENT_
typedef struct _AtkDocument AtkDocument;
#endif
typedef struct _AtkDocumentIface AtkDocumentIface;

struct _AtkDocumentIface
{
  long unsigned int* parent;
  const gchar*          ( *get_document_type) (AtkDocument              *document);
  gpointer              ( *get_document)      (AtkDocument              *document);

  const gchar*          ( *get_document_locale) (AtkDocument              *document);
  AtkAttributeSet *     ( *get_document_attributes) (AtkDocument        *document);
  const gchar*          ( *get_document_attribute_value) (AtkDocument   *document,
                                                          const gchar   *attribute_name);
  gboolean              ( *set_document_attribute) (AtkDocument         *document,
                                                    const gchar         *attribute_name,
                                                    const gchar         *attribute_value);
  gint                  ( *get_current_page_number) (AtkDocument *document);
  gint                  ( *get_page_count) (AtkDocument *document);
};

ATK_AVAILABLE_IN_ALL
long unsigned int  atk_document_get_type             (void);

ATK_DEPRECATED_IN_2_12
const gchar*          atk_document_get_document_type (AtkDocument   *document);

ATK_DEPRECATED_IN_2_12
gpointer atk_document_get_document (AtkDocument   *document);

ATK_DEPRECATED_IN_2_8_FOR(atk_object_get_object_locale)
const gchar*          atk_document_get_locale (AtkDocument *document);

ATK_AVAILABLE_IN_ALL
AtkAttributeSet*      atk_document_get_attributes (AtkDocument *document);
ATK_AVAILABLE_IN_ALL
const gchar*          atk_document_get_attribute_value (AtkDocument *document,
                                                        const gchar *attribute_name);
ATK_AVAILABLE_IN_ALL
gboolean              atk_document_set_attribute_value (AtkDocument *document,
                                                        const gchar *attribute_name,
                                                        const gchar *attribute_value);
ATK_AVAILABLE_IN_2_12
gint                  atk_document_get_current_page_number (AtkDocument *document);
ATK_AVAILABLE_IN_2_12
gint                  atk_document_get_page_count      (AtkDocument *document);

G_END_DECLS

#endif /* __ATK_DOCUMENT_H__ */
