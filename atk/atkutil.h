/* ATK -  Accessibility Toolkit
 * Copyright 2001 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __ATK_UTIL_H__
#define __ATK_UTIL_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_UTIL                   (atk_util_get_type ())
#define ATK_IS_UTIL(obj)                (0)
#define ATK_UTIL(obj)                   (obj)
#define ATK_UTIL_CLASS(klass)                   (klass)
#define ATK_IS_UTIL_CLASS(klass)                (klass)
#define ATK_UTIL_GET_CLASS(obj)                 (G_TYPE_INSTANCE_GET_CLASS ((obj), ATK_TYPE_UTIL, AtkUtilClass))


#ifndef _TYPEDEF_ATK_UTIL_
#define _TYPEDEF_ATK_UTIL_
typedef struct _AtkUtil      AtkUtil;
typedef struct _AtkUtilClass AtkUtilClass;
typedef struct _AtkKeyEventStruct AtkKeyEventStruct;
#endif

typedef void  (*AtkEventListener) (AtkObject* obj);

typedef void  (*AtkEventListenerInit) (void);

typedef int  (*AtkKeySnoopFunc)  (AtkKeyEventStruct *event,
				   void* user_data);

struct _AtkKeyEventStruct {
  int type;
  unsigned int state;
  unsigned int keyval;
  int length;
  char *string;
  unsigned short keycode;
  unsigned int timestamp;	
};

typedef enum
{
  ATK_KEY_EVENT_PRESS,
  ATK_KEY_EVENT_RELEASE,
  ATK_KEY_EVENT_LAST_DEFINED
} AtkKeyEventType;

struct _AtkUtil
{
  __GObject parent;
};

struct _AtkUtilClass
{
   __GObjectClass parent;
   unsigned int        (* add_global_event_listener)    (void* listener,
						  const char        *event_type);
   void         (* remove_global_event_listener) (unsigned int               listener_id);
   unsigned int	(* add_key_event_listener) 	 (AtkKeySnoopFunc     listener,
						  void* data);
   void         (* remove_key_event_listener)    (unsigned int               listener_id);
   AtkObject*   (* get_root)                     (void);
   const char* (* get_toolkit_name)             (void);
   const char* (* get_toolkit_version)          (void);
};
ATK_AVAILABLE_IN_ALL
long unsigned int atk_util_get_type (void);

typedef enum {
  ATK_XY_SCREEN,
  ATK_XY_WINDOW,
  ATK_XY_PARENT
}AtkCoordType;

ATK_DEPRECATED_IN_2_10
unsigned int    atk_add_focus_tracker     (AtkEventListener      focus_tracker);
ATK_DEPRECATED_IN_2_10
void     atk_remove_focus_tracker  (unsigned int                tracker_id);
ATK_DEPRECATED_IN_2_10
void     atk_focus_tracker_init    (AtkEventListenerInit  init);
ATK_DEPRECATED_IN_2_10
void     atk_focus_tracker_notify  (AtkObject            *object);
ATK_AVAILABLE_IN_ALL
unsigned int	atk_add_global_event_listener (void* listener,
				       const char        *event_type);
ATK_AVAILABLE_IN_ALL
void	atk_remove_global_event_listener (unsigned int listener_id);
ATK_AVAILABLE_IN_ALL
unsigned int	atk_add_key_event_listener (AtkKeySnoopFunc listener, void* data);
ATK_AVAILABLE_IN_ALL
void	atk_remove_key_event_listener (unsigned int listener_id);

ATK_AVAILABLE_IN_ALL
AtkObject* atk_get_root(void);
ATK_AVAILABLE_IN_ALL
AtkObject* atk_get_focus_object (void);

ATK_AVAILABLE_IN_ALL
const char *atk_get_toolkit_name (void);
ATK_AVAILABLE_IN_ALL
const char *atk_get_toolkit_version (void);
ATK_AVAILABLE_IN_ALL
const char *atk_get_version (void);

#define ATK_DEFINE_TYPE(TN, t_n, T_P)			       ATK_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, 0, {})

#define ATK_DEFINE_TYPE_WITH_CODE(TN, t_n, T_P, _C_)	      _ATK_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, 0) {_C_;} _ATK_DEFINE_TYPE_EXTENDED_END()

#define ATK_DEFINE_ABSTRACT_TYPE(TN, t_n, T_P)		       ATK_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, G_TYPE_FLAG_ABSTRACT, {})

#define ATK_DEFINE_ABSTRACT_TYPE_WITH_CODE(TN, t_n, T_P, _C_) _ATK_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, G_TYPE_FLAG_ABSTRACT) {_C_;} _ATK_DEFINE_TYPE_EXTENDED_END()

#define ATK_DEFINE_TYPE_EXTENDED(TN, t_n, T_P, _f_, _C_)      _ATK_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, _f_) {_C_;} _ATK_DEFINE_TYPE_EXTENDED_END()

#define _ATK_DEFINE_TYPE_EXTENDED_BEGIN(TypeName, type_name, TYPE, flags)

#endif /* __ATK_UTIL_H__ */
