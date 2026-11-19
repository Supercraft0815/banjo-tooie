#ifndef CORE2_BOUNDS_H
#define CORE2_BOUNDS_H

#include "common.h"

typedef struct {
    s32 count;
    u8 *entries;  /* 0x1C-byte records */
} BoundGroup;

typedef struct {
    BoundGroup groups[3];
    u8 enabled[200];
    u8 *pool;  /* 0x18-byte items */
} BoundContext;

extern BoundContext D_8012AE80;

#if defined(BT_NATIVE)
void _gcboundDll_entrypoint_0(BoundContext *);
void _gcboundDll_entrypoint_1(BoundContext *);
void _gcboundDll_entrypoint_2(BoundContext *);
void _gcboundDll_entrypoint_3(BoundContext *, s32, s16 *, s32, s32, s32, s32, s32);
void _gcboundDll_entrypoint_4(BoundContext *, s32, s16 *, s32, s32, s32);
void _gcboundDll_entrypoint_5(BoundContext *, s32, s16 *, s32, s32, s32, s32);
void _gcboundDll_entrypoint_6(BoundContext *);
void _gcboundDll_entrypoint_7(BoundContext *);
void _gcboundDll_entrypoint_8(BoundContext *);
#endif

#endif
