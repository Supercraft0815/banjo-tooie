#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "angler_native.inc"
#else
#include "common.h"
#ifdef BT_NATIVE
#include "core2/geometry_callbacks.h"
#endif

void func_80800000_trangler(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct entry { s32 data[9]; f32 value; };
    struct list { u8 data[0x11]; s8 count; u8 pad[2]; struct entry *start; struct entry *end; };
    void func_80019224(f32 *, f32 *);
    void func_800B237C(void *, f32 *, f32 *);
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    s32 func_800DF8B4(s32 *);
    f32 func_800DF8C4(f32 *);
    void func_800DF900(u8 *);
    void *func_8010E810(void);
    void *func_8010E924(s32, f32 *, f32, f32);
    void mlMtxPop(void);
    s32 current;
    f32 center[3];
    f32 norm;
    f32 scale;
    s32 amount;
    struct list *list;
    void *actor;

    list = func_8010E810();
    if (arg1 < 0) {
        amount = -arg1;
    } else {
        amount = arg1;
    }
    list->end = list->start + amount;
    func_800B237C((void *)func_800DF8B4(arg0), center, &norm);
    actor = arg0;
    scale = func_800DF8C4(actor);
    func_80019224(center, center);
    norm *= scale;
    func_800DF900(actor);
    if (arg2 != 0) {
        BT_IDO_ONLY(((struct entry *)func_8010E924(arg2, center, norm, scale))->value = -1.0f;) BT_NATIVE_ONLY({ struct entry *e = func_8010E924(arg2, center, norm, scale); if (e) e->value = -1.0f; })  // NULL when the light is out of range (Lord Woo Fak Fak lure at x 7168); the N64 would fault at 0x24
    }
    current = func_800C8760(0, 1);
    while (current != 0) {
        func_8010E924(current, center, norm, scale);
        current = func_800C878C(current, 0, 1);
    }
    list->count = ((s32)((u8 *)list->start - (u8 *)list) - 0x1C) / 40;
    mlMtxPop();
}

void trangler_entrypoint_0(BT_NATIVE_ONLY(struct GeometryRenderData *arg0) BT_IDO_ONLY(s32 *arg0), s32 arg1, BT_NATIVE_ONLY(void *arg2) BT_IDO_ONLY(s32 arg2), BT_NATIVE_ONLY(const f32 *arg3) BT_IDO_ONLY(s32 arg3)) {
    struct state {
        s32 *actor;
        s32 data[3];
        s8 value;
        u8 pad[3];
        s32 *start;
        s32 *end;
        s32 entries[1];
    };
    void *func_8010E810(void);
    int func_800DF8D4(s32 *);
    void func_80800000_trangler(s32 *, s32, s32, s32);
    void func_800C87B8(s32 *);
    s32 func_800DF8B4(s32 *);
    s32 func_800DF8CC(s32 *);
    s32 func_800DF8BC(s32 *);
    void func_8010EBE4(s32, s32, s32);
    struct state *state;
    s32 third;
    s32 second;
    s32 first;

    state = func_8010E810();
    state->actor = arg0;
    state->value = func_800DF8D4(arg0);
    state->start = state->entries;
    func_80800000_trangler(arg0, (arg1 >> 16) & 0xFFFF, arg1 & 0xFFFF, arg3);
    func_800C87B8(state->data);
    first = func_800DF8B4(arg0);
    second = func_800DF8CC(arg0);
    third = func_800DF8BC(arg0);
    func_8010EBE4(first, second, third);
}

#endif
