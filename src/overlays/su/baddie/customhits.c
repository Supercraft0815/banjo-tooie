#include "common.h"

void subaddiecustomhits_entrypoint_0(void **arg0, s32 arg1) {
    void func_800EC358(void *, s32);

    func_800EC358(*arg0, arg1);
    (*(u8 *)((s8 *)(arg0) + (0x74))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x74))) & 0xFF7F) | 0x80);
}

OSThread *subaddiecustomhits_entrypoint_1(void)
{
    extern u8 D_80800350_subaddiecustomhits[];

    return (OSThread *) D_80800350_subaddiecustomhits;
}

s32 subaddiecustomhits_entrypoint_2(Unk80132ED0 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 arg4) {
    s32 func_8001211C(void);
    s32 func_800AE0B8(s32 *);
    s16 func_800B1F8C(u8 *, f32 *, f32 *, f32, s32, void *, s32, f32, s32, s32);
    u8 *func_800B2824(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 *func_801027F4(u8 *);
    u8 *func_80103AA0(u8 *);
    void *func_801040A8(Actor *);
    OSThread *func_80104124(void);
    Actor *func_80106790(Unk80132ED0 *);
    s32 pad;
    u8 *sp48;
    u8 *sp44;
    s32 result;
    void *sp3C;
    Actor *actor;
    struct {
        f32 position[3];
        f32 value;
        s32 id;
        s32 frame;
    } *hit;
    struct MarkerId {
        u8 pad[0x12];
        u16 id : 15;
        u16 flag : 1;
    };

    actor = func_80106790(arg0);
    sp48 = func_80103AA0((u8 *)arg0);
    sp3C = func_801040A8(actor);
    if (sp48 == NULL || func_800AE0B8(sp3C) == 0) {
        return 0;
    }
    sp44 = func_800B2824(sp48);
    if (actor->scale == 0.0f) {
        result = 0;
    } else {
        result = func_800B1F8C(sp44, actor->position, func_801027F4((u8 *)actor), actor->scale, 0, sp3C, (s32)arg1, arg2, arg3, arg4);
    }
    if (result != 0) {
        hit = (void *)func_80104124();
        func_800EE7F8(hit->position, arg1);
        hit->value = arg2;
        hit->id = ((struct MarkerId *)arg0)->id;
        hit->frame = func_8001211C();
    }
    return result;
}

/* extern */

s32 subaddiecustomhits_entrypoint_3(Actor *arg0, f32 arg1[3], f32 arg2) {
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_80103DFC(Actor *, f32 *);
    f32 sp1C[3];

    func_80103DFC(arg0, sp1C);
    return func_800EFFB4(sp1C, (f32)(u16)arg0->pad68 * arg0->scale + arg2, arg1) == 0;
}

/* extern */

s32 subaddiecustomhits_entrypoint_4(Actor *arg0, f32 *arg1, f32 *arg2) {
    s32 func_8001211C(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_80103F38(Actor *, f32 *);
    OSThread *func_80104124(void);
    struct {
        f32 position[3];
        f32 value;
        s32 id;
        s32 frame;
    } *hit;
    f32 value;
    struct MarkerId {
        u8 pad[0x12];
        u16 id : 15;
        u16 flag : 1;
    };

    hit = (void *)func_80104124();
    if (hit->id == ((struct MarkerId *)arg0->unk0)->id) {
        if (func_8001211C() == hit->frame) {
            func_800EE7F8(arg1, hit->position);
            if (arg2 != NULL) {
                *arg2 = hit->value;
            }
            return 1;
        }
    }
    value = func_80103F38(arg0, arg1);
    if (arg2 != NULL) {
        *arg2 = value;
    }
    return 0;
}

f32 subaddiecustomhits_entrypoint_5(Actor *arg0, f32 *arg1) {
    f32 func_800EC75C(void *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_80103328(Actor *);
    struct CustomHitFlags {
        u32 pad[2];
        u32 unused : 30;
        u32 custom : 1;
        u32 last : 1;
    };
    Unk80132ED0 *marker;

    marker = arg0->unk0;
    if (!((struct CustomHitFlags *)marker->unk0)->custom) {
        return func_800EC75C(marker, arg1);
    }
    func_80103328(arg0);
    func_800EE7F8(arg1, arg0->position);
    return (f32)(u16)arg0->pad68 * arg0->scale * 1.15f;
}
