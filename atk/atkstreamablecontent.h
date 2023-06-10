#ifndef __ATK_STREAMABLE_CONTENT_H__
#define __ATK_STREAMABLE_CONTENT_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_STREAMABLE_CONTENT           (atk_streamable_content_get_type ())
#define ATK_IS_STREAMABLE_CONTENT(obj)        G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_STREAMABLE_CONTENT)
#define ATK_STREAMABLE_CONTENT(obj)           G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_STREAMABLE_CONTENT, AtkStreamableContent)
#define ATK_STREAMABLE_CONTENT_GET_IFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_STREAMABLE_CONTENT, AtkStreamableContentIface))

#ifndef _TYPEDEF_ATK_STREAMABLE_CONTENT
#define _TYPEDEF_ATK_STREAMABLE_CONTENT
typedef struct _AtkStreamableContent AtkStreamableContent;
#endif
typedef struct _AtkStreamableContentIface AtkStreamableContentIface;

struct _AtkStreamableContentIface
{
  long unsigned int* parent;

  /*
   * Get the number of mime types supported by this object
   */
  int                      (* get_n_mime_types)  (AtkStreamableContent     *streamable);
  /*
   * Gets the specified mime type supported by this object.
   * The mime types are 0-based so the first mime type is 
   * at index 0, the second at index 1 and so on.  The mime-type
   * at index 0 should be considered the "default" data type for the stream.
   *
   * This assumes that the strings for the mime types are stored in the
   * AtkStreamableContent. Alternatively the const could be removed
   * and the caller would be responsible for calling g_free() on the
   * returned value.
   */
  const char*              (* get_mime_type)     (AtkStreamableContent     *streamable,
                                                   int                     i);
  /*
   * One possible implementation for this method is that it constructs the
   * content appropriate for the mime type and then creates a temporary
   * file containing the content, opens the file and then calls
   * g_io_channel_unix_new_fd().
   */
  GIOChannel*               (* get_stream)        (AtkStreamableContent     *streamable,
                                                   const char              *mime_type);

/*
 * Returns a string representing a URI in IETF standard format
 * (see http://www.ietf.org/rfc/rfc2396.txt) from which the object's content
 * may be streamed in the specified mime-type.
 * If mime_type is 0, the URI for the default (and possibly only) mime-type is
 * returned.
 *
 * returns 0 if the mime-type is not supported, or if no URI can be 
 * constructed.  Note that it is possible for get_uri to return 0 but for
 * get_stream to work nonetheless, since not all GIOChannels connect to URIs.
 */
    const  char*           (* get_uri)           (AtkStreamableContent     *streamable,
                                                   const char              *mime_type);


  AtkFunction               pad1;
  AtkFunction               pad2;
  AtkFunction               pad3;
};
ATK_AVAILABLE_IN_ALL
long unsigned int                  atk_streamable_content_get_type (void);

ATK_AVAILABLE_IN_ALL
int                   atk_streamable_content_get_n_mime_types (AtkStreamableContent     *streamable);

ATK_AVAILABLE_IN_ALL
const char*           atk_streamable_content_get_mime_type    (AtkStreamableContent     *streamable,
                                                                int                     i);
ATK_AVAILABLE_IN_ALL
GIOChannel*             atk_streamable_content_get_stream       (AtkStreamableContent     *streamable,
                                                                 const char              *mime_type);

ATK_AVAILABLE_IN_ALL
const char*           atk_streamable_content_get_uri          (AtkStreamableContent     *streamable,
                                                                const char              *mime_type);



#endif /* __ATK_STREAMABLE_CONTENT_H__ */
