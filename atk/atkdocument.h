#ifndef __ATK_DOCUMENT_H__
#define __ATK_DOCUMENT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atkutil.h>



#define ATK_TYPE_DOCUMENT                   (atk_document_get_type ())
#define ATK_IS_DOCUMENT(obj)                 ((obj), ATK_TYPE_DOCUMENT)
#define ATK_DOCUMENT(obj)                    ((obj), ATK_TYPE_DOCUMENT, AtkDocument)
#define ATK_DOCUMENT_GET_IFACE(obj)         ( ((obj), ATK_TYPE_DOCUMENT, AtkDocumentIface))

#ifndef _TYPEDEF_ATK_DOCUMENT_
#define _TYPEDEF_ATK_DOCUMENT_
typedef struct _AtkDocument AtkDocument;
#endif
typedef struct _AtkDocumentIface AtkDocumentIface;

struct _AtkDocumentIface
{
  long unsigned int* parent;
  const char*          ( *get_document_type) (AtkDocument              *document);
  void*              ( *get_document)      (AtkDocument              *document);

  const char*          ( *get_document_locale) (AtkDocument              *document);
  AtkAttributeSet *     ( *get_document_attributes) (AtkDocument        *document);
  const char*          ( *get_document_attribute_value) (AtkDocument   *document,
                                                          const char   *attribute_name);
  unsigned char              ( *set_document_attribute) (AtkDocument         *document,
                                                    const char         *attribute_name,
                                                    const char         *attribute_value);
  int                  ( *get_current_page_number) (AtkDocument *document);
  int                  ( *get_page_count) (AtkDocument *document);
};

ATK_AVAILABLE_IN_ALL
long unsigned int  atk_document_get_type             (void);

ATK_DEPRECATED_IN_2_12
const char*          atk_document_get_document_type (AtkDocument   *document);

ATK_DEPRECATED_IN_2_12
void* atk_document_get_document (AtkDocument   *document);

ATK_DEPRECATED_IN_2_8_FOR(atk_object_get_object_locale)
const char*          atk_document_get_locale (AtkDocument *document);

ATK_AVAILABLE_IN_ALL
AtkAttributeSet*      atk_document_get_attributes (AtkDocument *document);
ATK_AVAILABLE_IN_ALL
const char*          atk_document_get_attribute_value (AtkDocument *document,
                                                        const char *attribute_name);
ATK_AVAILABLE_IN_ALL
unsigned char              atk_document_set_attribute_value (AtkDocument *document,
                                                        const char *attribute_name,
                                                        const char *attribute_value);
ATK_AVAILABLE_IN_2_12
int                  atk_document_get_current_page_number (AtkDocument *document);
ATK_AVAILABLE_IN_2_12
int                  atk_document_get_page_count      (AtkDocument *document);



#endif /* __ATK_DOCUMENT_H__ */
