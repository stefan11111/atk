#include "config.h"

#include "atkdocument.h"

enum {
  LOAD_COMPLETE,
  RELOAD,
  LOAD_STOPPED,
  PAGE_CHANGED,
  LAST_SIGNAL
};

long unsigned int atk_document_get_type(void)
{
    return 0;
}

const gchar*
atk_document_get_document_type (AtkDocument *document)
{
    return 0;
}

gpointer 
atk_document_get_document (AtkDocument *document)
{
    return 0;
}

const gchar *
atk_document_get_locale (AtkDocument *document)
{
    return 0;
}

AtkAttributeSet *
atk_document_get_attributes (AtkDocument *document)
{
    return 0;
}

const gchar *
atk_document_get_attribute_value (AtkDocument *document, 
				  const gchar *attribute_name)
{
    return 0;
}

gboolean
atk_document_set_attribute_value (AtkDocument *document, 
				  const gchar *attribute_name,
				  const gchar *attribute_value)
{
    return 0;
}

gint
atk_document_get_current_page_number (AtkDocument *document)
{
    return 0;
}

gint
atk_document_get_page_count (AtkDocument *document)
{
    return 0;
}
