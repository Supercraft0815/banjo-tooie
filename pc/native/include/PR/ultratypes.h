#ifndef _ULTRATYPES_H_
#define _ULTRATYPES_H_

#include <stdint.h>
#include <stddef.h>

/* N64 words remain 32 bits even on LP64 hosts. Pointers use the host ABI. */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef unsigned long long u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef long long s64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef float f32;
typedef double f64;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#endif
