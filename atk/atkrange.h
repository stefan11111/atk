#ifndef __ATK_RANGE_H__
#define __ATK_RANGE_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkversion.h>

#define ATK_TYPE_RANGE         (atk_range_get_type ())

typedef struct _AtkRange AtkRange;

/* AtkRange methods */
ATK_AVAILABLE_IN_2_12
long unsigned int atk_range_get_type (void);

ATK_AVAILABLE_IN_2_12
AtkRange*    atk_range_copy (AtkRange *src);
ATK_AVAILABLE_IN_2_12
void         atk_range_free (AtkRange *range);

ATK_AVAILABLE_IN_2_12
double      atk_range_get_lower_limit  (AtkRange    *range);
ATK_AVAILABLE_IN_2_12
double      atk_range_get_upper_limit  (AtkRange    *range);
ATK_AVAILABLE_IN_2_12
const char* atk_range_get_description  (AtkRange    *range);
ATK_AVAILABLE_IN_2_12
AtkRange*    atk_range_new              (double      lower_limit,
                                         double      upper_limit,
                                         const char *description);



#endif /* __ATK_RANGE_H__ */
