#include "config.h"
#include "atkhyperlink.h"

enum
{
  LINK_ACTIVATED,

  LAST_SIGNAL
};

enum
{
  PROP_0,  /* gobject convention */

  PROP_SELECTED_LINK,
  PROP_NUMBER_ANCHORS,
  PROP_END_INDEX,
  PROP_START_INDEX,
  PROP_LAST
};

long unsigned int atk_hyperlink_get_type()
{
    return 0;
}

char*
atk_hyperlink_get_uri (AtkHyperlink *link,
                       int         i)
{
    return 0;
}

AtkObject*
atk_hyperlink_get_object (AtkHyperlink *link,
                          int         i)
{
    return 0;
}

int
atk_hyperlink_get_end_index (AtkHyperlink *link)
{
    return 0;
}

int
atk_hyperlink_get_start_index (AtkHyperlink *link)
{
    return 0;
}

unsigned char
atk_hyperlink_is_valid (AtkHyperlink *link)
{
    return 0;
}

unsigned char
atk_hyperlink_is_inline (AtkHyperlink *link)
{
    return 0;
}

int
atk_hyperlink_get_n_anchors (AtkHyperlink *link)
{
    return 0;
}

unsigned char
atk_hyperlink_is_selected_link (AtkHyperlink *link)
{
    return 0;
}
