#ifndef __ATK_VALUE_H__
#define __ATK_VALUE_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>
#include <atk/atkrange.h>



#define ATK_TYPE_VALUE                    (atk_value_get_type ())
#define ATK_IS_VALUE(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_VALUE)
#define ATK_VALUE(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_VALUE, AtkValue)
#define ATK_VALUE_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_VALUE, AtkValueIface))

#ifndef _TYPEDEF_ATK_VALUE_
#define _TYPEDEF_ATK_VALUE__
typedef struct _AtkValue AtkValue;
#endif
typedef struct _AtkValueIface AtkValueIface;

typedef enum
{
  ATK_VALUE_VERY_WEAK,
  ATK_VALUE_WEAK,
  ATK_VALUE_ACCEPTABLE,
  ATK_VALUE_STRONG,
  ATK_VALUE_VERY_STRONG,
  ATK_VALUE_VERY_LOW,
  ATK_VALUE_LOW,
  ATK_VALUE_MEDIUM,
  ATK_VALUE_HIGH,
  ATK_VALUE_VERY_HIGH,
  ATK_VALUE_VERY_BAD,
  ATK_VALUE_BAD,
  ATK_VALUE_GOOD,
  ATK_VALUE_VERY_GOOD,
  ATK_VALUE_BEST,
  ATK_VALUE_LAST_DEFINED
}AtkValueType;

struct _AtkValueIface
{
  long unsigned int* parent;

  /*<deprecated>*/
  void     (* get_current_value) (AtkValue     *obj,
                                  GValue       *value);
  void     (* get_maximum_value) (AtkValue     *obj,
                                  GValue       *value);
  void     (* get_minimum_value) (AtkValue     *obj,
                                  GValue       *value);
  unsigned char (* set_current_value) (AtkValue     *obj,
                                  const GValue *value);
  void     (* get_minimum_increment) (AtkValue   *obj,
				      GValue     *value);
  /*</deprecated>*/
  void     (* get_value_and_text) (AtkValue *obj,
                                   gdouble *value,
                                   char  **text);
  AtkRange*(* get_range)          (AtkValue *obj);
  gdouble  (* get_increment)      (AtkValue *obj);
  GSList*  (* get_sub_ranges)     (AtkValue *obj);
  void     (* set_value)          (AtkValue     *obj,
                                   const gdouble new_value);

};

ATK_AVAILABLE_IN_ALL
long unsigned int            atk_value_get_type (void);

ATK_DEPRECATED_IN_2_12_FOR(atk_value_get_value_and_text)
void      atk_value_get_current_value (AtkValue     *obj,
                                       GValue       *value);

ATK_DEPRECATED_IN_2_12_FOR(atk_value_get_range)
void     atk_value_get_maximum_value  (AtkValue     *obj,
                                       GValue       *value);
ATK_DEPRECATED_IN_2_12_FOR(atk_value_get_range)
void     atk_value_get_minimum_value  (AtkValue     *obj,
                                       GValue       *value);
ATK_DEPRECATED_IN_2_12_FOR(atk_value_set_value)
unsigned char atk_value_set_current_value  (AtkValue     *obj,
                                       const GValue *value);
ATK_DEPRECATED_IN_2_12_FOR(atk_value_get_increment)
void     atk_value_get_minimum_increment  (AtkValue     *obj,
					   GValue       *value);

ATK_AVAILABLE_IN_2_12
void      atk_value_get_value_and_text (AtkValue *obj,
                                        gdouble *value,
                                        char  **text);
ATK_AVAILABLE_IN_2_12
AtkRange* atk_value_get_range          (AtkValue *obj);
ATK_AVAILABLE_IN_2_12
gdouble   atk_value_get_increment      (AtkValue *obj);
ATK_AVAILABLE_IN_2_12
GSList*   atk_value_get_sub_ranges     (AtkValue *obj);
ATK_AVAILABLE_IN_2_12
void      atk_value_set_value          (AtkValue     *obj,
                                        const gdouble new_value);
/* AtkValueType methods */
ATK_AVAILABLE_IN_ALL
const char* atk_value_type_get_name           (AtkValueType value_type);
ATK_AVAILABLE_IN_ALL
const char* atk_value_type_get_localized_name (AtkValueType value_type);



#endif /* __ATK_VALUE_H__ */
