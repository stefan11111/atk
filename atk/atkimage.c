#include "config.h"

#include "atkimage.h"

long unsigned int
atk_image_get_type (void)
{
    return 0;
}

const char*
atk_image_get_image_description (AtkImage *image)
{
    return 0;
}

void
atk_image_get_image_size (AtkImage *image, 
                          int      *width,
                          int      *height)
{
}

unsigned char
atk_image_set_image_description (AtkImage        *image,
                                 const char     *description)
{
    return 0;
}

void     
atk_image_get_image_position (AtkImage *image,
                        int *x,
		        int *y,
    		        AtkCoordType coord_type)
{
}

const char*
atk_image_get_image_locale (AtkImage   *image)
{
    return 0;
}
