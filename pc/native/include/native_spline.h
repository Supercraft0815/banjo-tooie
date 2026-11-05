#ifndef BT_NATIVE_SPLINE_H
#define BT_NATIVE_SPLINE_H
#include "common.h"

typedef struct {
    u8 used, fixed;
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
    u32 *commands;
    s32 command_size;
} NativeSplineContext;

typedef struct { s32 word; } SplineSpawnWord;
s32 glsplinefuncs_entrypoint_0(s32, s32 *, f32 *, f32 *, s32, f32 *, f32 *);
void glsplinefuncs_entrypoint_1(s32, SplineSpawnWord, s32);
void glsplinecs_entrypoint_1(NativeSplineContext *, Actor *);
Actor *native_spline_actor(NativeSplineContext *, Actor *, s32);
s32 *native_spline_script(NativeSplineContext *, s32, s32 *);
s32 native_spline_command_words(s32 *, s32, s32);
extern NativeSplineContext native_spline_context;
void native_spline_clear_commands(NativeSplineContext *);
int native_spline_load_commands(NativeSplineContext *, s32);
#define SPLINE_ACTOR(actor, field, original) (((Actor *)(actor))->field)
#define SPLINE_FIELD(ctx, field, original) (((NativeSplineContext *)(ctx))->field)
void glsplineDll_entrypoint_0(void *);
void glsplineDll_entrypoint_1(void *);
void glsplineDll_entrypoint_2(u8 *);
s32 glsplinefind_entrypoint_0(s32, f32 *);
s32 glsplinefind_entrypoint_1(s32);
s32 glsplinefind_entrypoint_2(s32 *);
s32 glsplinefind_entrypoint_3(f32 *);
s32 glsplinefind_entrypoint_4(s32 *, s32 *);
void *func_800D7400(void);
void func_800D740C(void);
void func_800D7418(void);
void func_800D743C(void);
void func_800D7460(void);
s32 func_800D7488(s16, s16);
void *func_800D7520(s32);
u8 *func_800D7570(s32);
s32 func_800D75DC(s32, f32);
f32 func_800D7708(s32, f32, s32);
void func_800D8674(void);
void func_800D86F0(s32, f32, f32 *);
void func_800D8744(void);
void func_800D87B0(void);
void func_800D87D4(Actor *, s32);
Unk80132ED0 *func_800D87EC(s32);
void func_800D8808(s32);

#endif
