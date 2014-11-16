#ifndef __TYPES_H__
#define __TYPES_H__

#include "amf.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef WORDS_BIGENDIAN

#  define swap_uint16(x) (x)
#  define swap_int16(x) (x)
#  define swap_uint32(x) (x)
#  define swap_number64(x) (x)

#else /* WORDS_BIGENDIAN */
/* swap 16 bits integers */
#  define swap_uint16(x) ((((x) & 0x00FFU) << 8) | (((x) & 0xFF00U) >> 8))
#  define swap_sint16(x) ((((x) & 0x00FF) << 8) | (((x) & 0xFF00) >> 8))

/* swap 32 bits integers */
#  define swap_uint32(x) ((((x) & 0x000000FFU) << 24) | \
    (((x) & 0x0000FF00U) << 8)  | \
    (((x) & 0x00FF0000U) >> 8)  | \
    (((x) & 0xFF000000U) >> 24))

/* swap 64 bits doubles */
number64_t swap_number64(number64_t);

#endif /* WORDS_BIGENDIAN */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TYPES_H__ */
