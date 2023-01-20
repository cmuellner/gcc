typedef unsigned char u_char;
typedef signed char s_char;
typedef unsigned short u_short;
typedef signed short s_short;
typedef unsigned int u_int;
typedef signed int s_int;
typedef unsigned int u_ll __attribute__((mode(DI)));
typedef signed int s_ll __attribute__((mode(DI)));

#include "stdint.h"

#define PRE_STORE(T, ATTR)		\
  ATTR T *				\
  T ## _pre_store (T *p, T v)		\
  {					\
    *++p = v;				\
    return p;				\
  }

#define POST_STORE(T, ATTR)		\
  ATTR T *				\
  T ## _post_store (T *p, T v)		\
  {					\
    *p++ = v;				\
    return p;				\
  }

#define POST_STORE_VEC(T, VT, OP, ATTR)	\
  ATTR T *				\
  VT ## _post_store (T * p, VT v)	\
  {					\
    OP (p, v);				\
    p += sizeof (VT) / sizeof (T);	\
    return p;				\
  }

#define PRE_LOAD(T, ATTR)		\
  ATTR void				\
  T ## _pre_load (T *p)			\
  {					\
    ATTR extern void f ## T (T*,T);	\
    T x = *++p;				\
    f ## T (p, x);			\
  }

#define POST_LOAD(T, ATTR)		\
  ATTR void				\
  T ## _post_load (T *p)		\
  {					\
    ATTR extern void f ## T (T*,T);	\
    T x = *p++;				\
    f ## T (p, x);			\
  }

#define POST_LOAD_VEC(T, VT, OP, ATTR)	\
  ATTR void				\
  VT ## _post_load (T * p)		\
  {					\
    ATTR extern void f ## T (T*,T);	\
    VT x = OP (p, v);			\
    p += sizeof (VT) / sizeof (T);	\
    f ## T (p, x);			\
  }

#define MV_LOAD_1(RS2_TYPE, RET_TYPE)	\
  RET_TYPE   	\
  mv_load_1_ ## RS2_TYPE ## _ ## RET_TYPE (RS2_TYPE *a, int b)  \
  {					\
    return a[b];  \
  }

#define MV_LOAD_2(RS2_TYPE, RET_TYPE)	\
  RET_TYPE   	\
  mv_load_2_ ## RS2_TYPE ## _ ## RET_TYPE (  \
  RS2_TYPE rs1, RS2_TYPE rs2, int a)		\
  {					\
    return (*((RET_TYPE*)(uintptr_t)(rs1 + (rs2 << a))));  \
  }

#define MV_LOAD_3(RS2_TYPE, CONV_TYPE, RET_TYPE)	\
  RET_TYPE   	\
  mv_load_3_ ## RS2_TYPE ## _ ## CONV_TYPE ## _ ## RET_TYPE (  \
  RS2_TYPE rs1, RS2_TYPE rs2, int a)		\
  {					\
    CONV_TYPE c = (CONV_TYPE) rs2;   \
    return (*((RET_TYPE*)(uintptr_t)(rs1 + (c << a))));  \
  }

#define MV_LOAD_4(RS2_TYPE, CONV_TYPE, TMP_RET_TYPE)	\
  uintptr_t   	\
  mv_load_4_ ## RS2_TYPE ## _ ## CONV_TYPE ## _ ## TMP_RET_TYPE (  \
  RS2_TYPE rs1, RS2_TYPE rs2, int a)		\
  {					\
    CONV_TYPE c = (CONV_TYPE) rs2;   \
    return (*((TMP_RET_TYPE*)(uintptr_t)(rs1 + (c << a))));  \
  }

#define MV_STORE_1(RS2_TYPE, CONV_TYPE, STORE_TYPE)	\
  void   	\
  mv_store_1_ ## RS2_TYPE ## _ ## CONV_TYPE ## _ ## STORE_TYPE (  \
  RS2_TYPE rs1, RS2_TYPE rs2, int a, int st_val)		\
  {					\
    CONV_TYPE c = (CONV_TYPE) rs2;   \
    STORE_TYPE* addr = (STORE_TYPE*)(uintptr_t)(rs1 + (c << a));  \
    *addr = st_val;  \
  }

#define MV_LOAD_1_AND_2(RS2_TYPE, RET_TYPE)	\
  MV_LOAD_1(RS2_TYPE, RET_TYPE)  \
  MV_LOAD_2(RS2_TYPE, RET_TYPE)
