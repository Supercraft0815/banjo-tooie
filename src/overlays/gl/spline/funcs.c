#include "common.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_spline.h"
#include "native_actor.h"
#else
#define SPLINE_FIELD(ctx, field, original) (original)
#endif
struct Unk800C7A68;

s32 glsplinefuncs_entrypoint_0(s32 arg0, s32 *arg1, f32 *arg2, f32 *arg3, s32 arg4, f32 *arg5, f32 *arg6) {
    void *func_8001B798(s16);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    void *func_800D7400(void);
    void *func_800D7520(s32);
    u8 *state;
    s16 *ids;
    u8 *data;
    u8 *first;
    u8 *entry;
    u8 *end;
    s32 i;

    state = func_800D7400();
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    *arg5 = *arg6 = -9999.0f;
    if (!native_spline_context.count || arg4 < -1 || arg4 >= native_spline_context.count) return 0;
#endif
    ids = func_8001B798(SPLINE_FIELD(state, handle1, *(s16 *)(state + 0x186)));
    *arg5 = -9999.0f;
    *arg6 = -9999.0f;
    if (arg4 != -1) {
        data = func_8001B798(ids[arg4]);
        first = data + 4;
        entry = first;
        end = data + *(s32 *)data * 20 + 4;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        while (entry < end && arg0 != (*(u32 *)(entry + 16) >> 21)) {
#else
        while (arg0 != (*(u32 *)(entry + 16) >> 21) && entry < end) {
#endif
            entry += 20;
        }
        if (entry < end) {
            if ((*(u32 *)(entry + 4) & 1) == 1) {
                if (!(*(u32 *)(entry + 12) & 1) && ((*(u32 *)(entry + 4) << 25) >> 29) == 7) {
                    *arg5 = (f32)(*(u32 *)(entry + 12) >> 23);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
                    *arg6 = (f32)((*(u32 *)(entry + 4) >> 7) & 0x1FF);
#else
                    *arg6 = (f32)((u32)*(u16 *)(entry + 6) >> 7);
#endif
                }
            }
            *arg1 = arg4;
            *arg2 = *(f32 *)entry;
            func_800C7A68(func_800D7520(arg4), *(f32 *)entry, arg3);
            return 1;
        }
    }
    for (i = 0; i < SPLINE_FIELD(state, count, *(s32 *)(state + 0x188)); i++) {
        if (i != arg4) {
            data = func_8001B798(ids[i]);
            first = data + 4;
        entry = first;
            end = data + *(s32 *)data * 20 + 4;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        while (entry < end && arg0 != (*(u32 *)(entry + 16) >> 21)) {
#else
        while (arg0 != (*(u32 *)(entry + 16) >> 21) && entry < end) {
#endif
                entry += 20;
            }
            if (entry < end) {
                if ((*(u32 *)(entry + 4) & 1) == 1) {
                    if (!(*(u32 *)(entry + 12) & 1) && ((*(u32 *)(entry + 4) << 25) >> 29) == 7) {
                        *arg5 = (f32)(*(u32 *)(entry + 12) >> 23);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
                    *arg6 = (f32)((*(u32 *)(entry + 4) >> 7) & 0x1FF);
#else
                    *arg6 = (f32)((u32)*(u16 *)(entry + 6) >> 7);
#endif
                    }
                }
                *arg1 = i;
                *arg2 = *(f32 *)entry;
                func_800C7A68(func_800D7520(i), *(f32 *)entry, arg3);
                return 1;
            }
        }
    }
    return 0;
}

#if !defined(BT_NATIVE) || defined(BT_ILP32)
typedef struct {
    s32 word;
} SplineSpawnWord;
#endif

void glsplinefuncs_entrypoint_1(s32 arg0, SplineSpawnWord arg1, s32 arg2) {
#ifdef BT_NATIVE_LITTLE_ENDIAN
    typedef struct {
        u32 bit0:1;
        s32 signedId:10;
        u32 pad0:21;
        f32 unk4, unk8, progress;
    } PathState;
#else
    typedef struct {
        s16 unk0;
        s16 pad2:5;
        s16 signedId:10;
        s16 bit0:1;
        f32 unk4;
        f32 unk8;
        f32 progress;
    } PathState;
#endif
    typedef struct {
        u8 unused0[0x44];
        f32 rotation[3];
        f32 unk50;
        u8 unused54[0x20];
        u32 unused74:27;
        u32 splineFlag:1;
        u32 unused77:4;
    } SplineActor;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    void func_800D87D4(s32 *, s32);
#endif
    void *func_80105494(Actor *);
    Actor *func_80108474(u32, f32 *, s32);
    s32 glsplinefuncs_entrypoint_0(s32, s32 *, f32 *, f32 *, s32, f32 *, f32 *);
    s32 sp5C;
    s32 pad[2];
    s32 sp50;
    s32 sp4C;
    f32 sp48;
    f32 sp3C[3];
    f32 sp38;
    f32 sp34;
    void *sp30;
    SplineActor *object;
    PathState *state;

    sp5C = arg0;
    if (((u8 *)&arg0)[0]) {} /* Preserve IDO's incoming argument home. */
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    state = (void *)*(s32 *)&arg2;
#endif
    sp4C = (arg1.word >> 12) & 0x3F;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (sp4C >= 33 || !glsplinefuncs_entrypoint_0(arg1.word & 0xFFF, &sp50, &sp48, sp3C, arg2, &sp38, &sp34)) return;
#else
    glsplinefuncs_entrypoint_0((arg1.word &= 0xFFF), &sp50, &sp48, sp3C, (s32)state, &sp38, &sp34);
#endif
    sp30 = func_80108474(sp5C, sp3C, (s32) sp38);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (!sp30) return;
#endif
    state = func_80105494(sp30);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    if (!state) state = func_8010556C(sp30);
#endif
    object = sp30;
    state->signedId = sp50;
    state->progress = sp48;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    ((Actor *)object)->unk50 = sp34;
    ((Actor *)object)->rotation[0] = sp34;
    ((Actor *)object)->pad74_0 |= 16;
#else
    object->unk50 = sp34;
    object->rotation[0] = sp34;
    object->splineFlag = 1;
#endif
    if (sp4C != 0) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        func_800D87D4(sp30, sp4C);
#else
        func_800D87D4((s32 *)sp30, sp4C);
#endif
    }
}
