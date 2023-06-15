

#include "atkstreamablecontent.h"

long unsigned int
atk_streamable_content_get_type (void)
{
    return 0;
}

int
atk_streamable_content_get_n_mime_types (AtkStreamableContent *streamable)
{
    return 0;
}

const char*
atk_streamable_content_get_mime_type (AtkStreamableContent *streamable,
                                      int                 i)
{
    return 0;
}

void*
atk_streamable_content_get_stream (AtkStreamableContent *streamable,
                                   const char          *mime_type)
{
    return 0;
}

const char*
atk_streamable_content_get_uri (AtkStreamableContent *streamable,
				const char          *mime_type)
{
    return 0;
}
