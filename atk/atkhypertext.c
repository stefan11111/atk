#include "atkhypertext.h"

enum {
  LINK_SELECTED,
  LAST_SIGNAL
};

long unsigned int
atk_hypertext_get_type (void)
{
    return 0;
}

AtkHyperlink* 
atk_hypertext_get_link (AtkHypertext  *hypertext,
                        int          link_index)
{
    return 0;
}

int 
atk_hypertext_get_n_links (AtkHypertext  *hypertext)
{
    return 0;
}

int 
atk_hypertext_get_link_index (AtkHypertext  *hypertext,
                              int          char_index)
{
    return -1;
}
