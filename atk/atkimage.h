#ifndef __ATK_IMAGE_H__
#define __ATK_IMAGE_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atkutil.h>



#define ATK_TYPE_IMAGE                   (atk_image_get_type ())
#define ATK_IS_IMAGE(obj)                G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_IMAGE)
#define ATK_IMAGE(obj)                   G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_IMAGE, AtkImage)
#define ATK_IMAGE_GET_IFACE(obj)         (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_IMAGE, AtkImageIface))

#ifndef _TYPEDEF_ATK_IMAGE_
#define _TYPEDEF_ATK_IMAGE_
typedef struct _AtkImage AtkImage;
#endif
typedef struct _AtkImageIface AtkImageIface;

struct _AtkImageIface
{
  long unsigned int* parent;
  void          	( *get_image_position)    (AtkImage		 *image,
                                                   int                  *x,
				                   int	                 *y,
    			                           AtkCoordType	         coord_type);
  const char*          ( *get_image_description) (AtkImage              *image);
  void                  ( *get_image_size)        (AtkImage              *image,
                                                   int                  *width,
                                                   int                  *height);
  unsigned char              ( *set_image_description) (AtkImage              *image,
                                                   const char           *description);
  const char*          ( *get_image_locale)      (AtkImage              *image);
};

ATK_AVAILABLE_IN_ALL
long unsigned int  atk_image_get_type             (void);

ATK_AVAILABLE_IN_ALL
const char* atk_image_get_image_description (AtkImage   *image);

ATK_AVAILABLE_IN_ALL
void     atk_image_get_image_size        (AtkImage           *image,
                                          int               *width,
                                          int               *height);

ATK_AVAILABLE_IN_ALL
unsigned char atk_image_set_image_description (AtkImage           *image,
                                          const char       *description);
ATK_AVAILABLE_IN_ALL
void     atk_image_get_image_position    (AtkImage	     *image,
                                          int               *x,
					  int	             *y,
    					  AtkCoordType	     coord_type);

ATK_AVAILABLE_IN_ALL
const char* atk_image_get_image_locale (AtkImage   *image);



#endif /* __ATK_IMAGE_H__ */
