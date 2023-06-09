#ifndef __ATK_SOCKET_H__
#define __ATK_SOCKET_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkversion.h>



#define ATK_TYPE_SOCKET               (atk_socket_get_type ())
#define ATK_SOCKET(obj)               (obj)
#define ATK_IS_SOCKET(obj)            0
#define ATK_SOCKET_CLASS(klass)       (klass)
#define ATK_IS_SOCKET_CLASS(klass)    0
#define ATK_SOCKET_GET_CLASS(obj)     (*(void**)(obj))

typedef struct _AtkSocket         AtkSocket;
typedef struct _AtkSocketClass    AtkSocketClass;

struct _AtkSocket
{
  AtkObject parent;

  /*< private >*/
  char* embedded_plug_id;
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_socket_get_type (void);

struct _AtkSocketClass
{
  AtkObjectClass parent_class;
  
  /* to be subscribed to by atk-bridge */

  /*< protected >*/
  void (* embed) (AtkSocket *obj, const char* plug_id);
};

ATK_AVAILABLE_IN_ALL
AtkObject*    atk_socket_new           (void);
ATK_AVAILABLE_IN_ALL
void          atk_socket_embed         (AtkSocket* obj, const char* plug_id);
ATK_AVAILABLE_IN_ALL
unsigned char      atk_socket_is_occupied   (AtkSocket* obj);



#endif /* __ATK_SOCKET_H__ */
