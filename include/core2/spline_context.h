#ifndef BT_CORE2_SPLINE_CONTEXT_H
#define BT_CORE2_SPLINE_CONTEXT_H
#include "common.h"

#ifdef BT_NATIVE
typedef struct {
#ifdef BT_ILP32
    u8 reserved : 6, fixed : 1, used : 1;
    u8 padding;
#else
    u8 used, fixed;
#endif
    s16 position[3];
    union { void *object; Unk80132ED0 *marker; };
} NativeSplineTarget;

typedef struct {
    u8 counters[128], initial_counters[128];
    Unk80132ED0 *actors[33];
    s16 handle0, handle1;
    s32 count, pad18C;
    f32 value0, value1;
    s32 asset;
    s32 *offsets;
    s32 unk1A0;
    NativeSplineTarget *cache;
    u8 map;
#ifdef BT_ILP32
    u8 padding[7];
#else
    u32 *commands;
    s32 command_size;
#endif
} NativeSplineContext;

extern NativeSplineContext D_8012BE70;
#define native_spline_context D_8012BE70
#define SPLINE_FIELD(ctx, field, original) (((NativeSplineContext *)(ctx))->field)
#ifdef BT_ILP32
#include <stddef.h>
_Static_assert(sizeof(NativeSplineTarget) == 0x0C, "spline target layout");
_Static_assert(offsetof(NativeSplineContext, actors) == 0x100, "spline actor table");
_Static_assert(offsetof(NativeSplineContext, handle0) == 0x184, "spline handles");
_Static_assert(offsetof(NativeSplineContext, count) == 0x188, "spline count");
_Static_assert(offsetof(NativeSplineContext, offsets) == 0x19C, "spline script offsets");
_Static_assert(offsetof(NativeSplineContext, cache) == 0x1A4, "spline target cache");
_Static_assert(offsetof(NativeSplineContext, map) == 0x1A8, "spline map flag");
_Static_assert(sizeof(NativeSplineContext) == 0x1B0, "spline state");
#endif
#else
#define SPLINE_FIELD(ctx, field, original) (original)
#endif
#endif
