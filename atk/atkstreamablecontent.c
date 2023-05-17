#include "config.h"

#include "atkstreamablecontent.h"

GType
atk_streamable_content_get_type (void)
{
    return 0;
}

gint
atk_streamable_content_get_n_mime_types (AtkStreamableContent *streamable)
{
    return 0;
}

const gchar*
atk_streamable_content_get_mime_type (AtkStreamableContent *streamable,
                                      gint                 i)
{
    return 0;
}

GIOChannel*
atk_streamable_content_get_stream (AtkStreamableContent *streamable,
                                   const gchar          *mime_type)
{
    return 0;
}

const gchar*
atk_streamable_content_get_uri (AtkStreamableContent *streamable,
				const gchar          *mime_type)
{
    return 0;
}
