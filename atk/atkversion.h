#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#ifndef __ATK_VERSION_H__
#define __ATK_VERSION_H__

#define ATK_MAJOR_VERSION (2)

#define ATK_MINOR_VERSION (38)

#define ATK_MICRO_VERSION (1)

#define ATK_BINARY_AGE    (23811)

#define ATK_INTERFACE_AGE (1)

#define ATK_CHECK_VERSION(major,minor,micro)                          \
    (ATK_MAJOR_VERSION > (major) ||                                   \
     (ATK_MAJOR_VERSION == (major) && ATK_MINOR_VERSION > (minor)) || \
     (ATK_MAJOR_VERSION == (major) && ATK_MINOR_VERSION == (minor) && \
      ATK_MICRO_VERSION >= (micro)))

#ifndef _ATK_EXTERN
#define _ATK_EXTERN extern
#endif

#define ATK_VERSION_2_2       (G_ENCODE_VERSION (2, 2))

#define ATK_VERSION_2_4       (G_ENCODE_VERSION (2, 4))

#define ATK_VERSION_2_6       (G_ENCODE_VERSION (2, 6))

#define ATK_VERSION_2_8       (G_ENCODE_VERSION (2, 8))

#define ATK_VERSION_2_10       (G_ENCODE_VERSION (2, 10))

#define ATK_VERSION_2_12       (G_ENCODE_VERSION (2, 12))

#define ATK_VERSION_2_14       (G_ENCODE_VERSION (2, 14))

#define ATK_VERSION_2_30       (G_ENCODE_VERSION (2, 30))

#define ATK_VERSION_2_36       (G_ENCODE_VERSION (2, 36))

#if (ATK_MINOR_VERSION % 2)
#define ATK_VERSION_CUR_STABLE         (G_ENCODE_VERSION (ATK_MAJOR_VERSION, ATK_MINOR_VERSION + 1))
#else
#define ATK_VERSION_CUR_STABLE         (G_ENCODE_VERSION (ATK_MAJOR_VERSION, ATK_MINOR_VERSION))
#endif

/* evaluates to the previous stable version */
#if (ATK_MINOR_VERSION % 2)
#define ATK_VERSION_PREV_STABLE        (G_ENCODE_VERSION (ATK_MAJOR_VERSION, ATK_MINOR_VERSION - 1))
#else
#define ATK_VERSION_PREV_STABLE        (G_ENCODE_VERSION (ATK_MAJOR_VERSION, ATK_MINOR_VERSION - 2))
#endif

#ifndef ATK_VERSION_MIN_REQUIRED
# define ATK_VERSION_MIN_REQUIRED      (ATK_VERSION_CUR_STABLE)
#elif ATK_VERSION_MIN_REQUIRED == 0
# undef  ATK_VERSION_MIN_REQUIRED
# define ATK_VERSION_MIN_REQUIRED      (ATK_VERSION_CUR_STABLE + 2)
#endif

#if !defined (ATK_VERSION_MAX_ALLOWED) || (ATK_VERSION_MAX_ALLOWED == 0)
# undef ATK_VERSION_MAX_ALLOWED
# define ATK_VERSION_MAX_ALLOWED      (ATK_VERSION_CUR_STABLE)
#endif

/* sanity checks */
#if ATK_VERSION_MIN_REQUIRED > ATK_VERSION_CUR_STABLE
#error "ATK_VERSION_MIN_REQUIRED must be <= ATK_VERSION_CUR_STABLE"
#endif
#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_MIN_REQUIRED
#error "ATK_VERSION_MAX_ALLOWED must be >= ATK_VERSION_MIN_REQUIRED"
#endif
#if ATK_VERSION_MIN_REQUIRED < ATK_VERSION_2_2
#error "ATK_VERSION_MIN_REQUIRED must be >= ATK_VERSION_2_2"
#endif

#ifdef ATK_DISABLE_DEPRECATION_WARNINGS
#define ATK_DEPRECATED _ATK_EXTERN
#define ATK_DEPRECATED_FOR(f) _ATK_EXTERN
#define ATK_UNAVAILABLE(maj,min) _ATK_EXTERN
#else
#define ATK_DEPRECATED G_DEPRECATED _ATK_EXTERN
#define ATK_DEPRECATED_FOR(f) G_DEPRECATED_FOR(f) _ATK_EXTERN
#define ATK_UNAVAILABLE(maj,min) G_UNAVAILABLE(maj,min) _ATK_EXTERN
#endif

#define ATK_AVAILABLE_IN_ALL _ATK_EXTERN

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_2
# define ATK_DEPRECATED_IN_2_2                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_2_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_2                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_2_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_2
# define ATK_AVAILABLE_IN_2_2                 ATK_UNAVAILABLE(2, 2)
#else
# define ATK_AVAILABLE_IN_2_2                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_4
# define ATK_DEPRECATED_IN_2_4                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_4_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_4                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_4_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_4
# define ATK_AVAILABLE_IN_2_4                 ATK_UNAVAILABLE(2, 4)
#else
# define ATK_AVAILABLE_IN_2_4                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_6
# define ATK_DEPRECATED_IN_2_6                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_6_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_6                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_6_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_6
# define ATK_AVAILABLE_IN_2_6                 ATK_UNAVAILABLE(2, 6)
#else
# define ATK_AVAILABLE_IN_2_6                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_8
# define ATK_DEPRECATED_IN_2_8                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_8_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_8                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_8_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_8
# define ATK_AVAILABLE_IN_2_8                 ATK_UNAVAILABLE(2, 8)
#else
# define ATK_AVAILABLE_IN_2_8                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_10
# define ATK_DEPRECATED_IN_2_10                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_10_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_10                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_10_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_10
# define ATK_AVAILABLE_IN_2_10                 ATK_UNAVAILABLE(2, 10)
#else
# define ATK_AVAILABLE_IN_2_10                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_12
# define ATK_DEPRECATED_IN_2_12                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_12_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_12                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_12_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_12
# define ATK_AVAILABLE_IN_2_12                 ATK_UNAVAILABLE(2, 12)
#else
# define ATK_AVAILABLE_IN_2_12                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_14
# define ATK_DEPRECATED_IN_2_14                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_14_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_14                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_14_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_14
# define ATK_AVAILABLE_IN_2_14                 ATK_UNAVAILABLE(2, 14)
#else
# define ATK_AVAILABLE_IN_2_14                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_30
# define ATK_DEPRECATED_IN_2_30                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_30_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_30                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_30_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_30
# define ATK_AVAILABLE_IN_2_30                 ATK_UNAVAILABLE(2, 30)
#else
# define ATK_AVAILABLE_IN_2_30                 _ATK_EXTERN
#endif

#if ATK_VERSION_MIN_REQUIRED >= ATK_VERSION_2_36
# define ATK_DEPRECATED_IN_2_36                ATK_DEPRECATED
# define ATK_DEPRECATED_IN_2_36_FOR(f)         ATK_DEPRECATED_FOR(f)
#else
# define ATK_DEPRECATED_IN_2_36                _ATK_EXTERN
# define ATK_DEPRECATED_IN_2_36_FOR(f)         _ATK_EXTERN
#endif

#if ATK_VERSION_MAX_ALLOWED < ATK_VERSION_2_36
# define ATK_AVAILABLE_IN_2_36                 ATK_UNAVAILABLE(2, 36)
#else
# define ATK_AVAILABLE_IN_2_36                 _ATK_EXTERN
#endif

ATK_AVAILABLE_IN_2_8
unsigned int atk_get_major_version (void);
ATK_AVAILABLE_IN_2_8
unsigned int atk_get_minor_version (void);
ATK_AVAILABLE_IN_2_8
unsigned int atk_get_micro_version (void);
ATK_AVAILABLE_IN_2_8
unsigned int atk_get_binary_age    (void);
ATK_AVAILABLE_IN_2_8
unsigned int atk_get_interface_age (void);

#define atk_major_version atk_get_major_version ()
#define atk_minor_version atk_get_minor_version ()
#define atk_micro_version atk_get_micro_version ()
#define atk_binary_age atk_get_binary_age ()
#define atk_interface_age atk_get_interface_age ()

#endif /* __ATK_VERSION_H__ */
