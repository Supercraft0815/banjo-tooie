#include "ch/transparentfish.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparentfish/func_80800000_chtransparentfish.s")

void func_80800204_chtransparentfish(Actor *arg0) {
    f32 _subaddiejoy_entrypoint_3();
    void func_80102BAC(Actor *, f32, f32, f32);
    s32 func_8010BA80(Actor *, s32, s32);
    f32 speed;

    speed = _subaddiejoy_entrypoint_3() * 300.0f;
    func_80102BAC(arg0, 0.5f, 0.5, 5.0f);
    if (((f32 *)arg0->actorData)[3] <= speed) {
        ((f32 *)arg0->actorData)[3] = speed;
    } else {
        ((f32 *)arg0->actorData)[3] -= ((f32 *)arg0->actorData)[3] * 0.02f;
        if (((f32 *)arg0->actorData)[3] < 30.0f) {
            ((f32 *)arg0->actorData)[3] = 0.0f;
        }
    }
    func_8010BA80(arg0, 0x200006, 0x20);
}

/* extern */

void func_808002B8_chtransparentfish(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 func_80800B60_chtransparentfish();
    s32 func_80800EE0_chtransparentfish(s32);
    if (func_800DA298(FLAG3_9F4_UNK) == 0) {
        func_800DA544(FLAG3_9F4_UNK);
        func_80800B60_chtransparentfish();
    }
    arg0->unk6C_0 = func_80800EE0_chtransparentfish(arg0->pad6C_21);
    ((f32 *)arg0->actorData)[3] = 150.0f;
    ((f32 *)arg0->actorData)[7] = 150.0f;
    ((f32 *)arg0->actorData)[5] = (f32) _subaddiesect_entrypoint_1(arg0);
}

void func_80800348_chtransparentfish(Actor *actor)
{
    void _subaddiesect_entrypoint_0(Actor *, s32, s32);
    void func_80800AC4_chtransparentfish(Actor *, f32 *, s32);
    s32 func_800F54E4(void);
    s32 func_800F52B8(s32, Unk80132ED0 *);
    s32 func_800F690C(s32);
    f32 func_80103EAC(Actor *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80102CCC(Actor *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, u32 *, s32, f32, s32 *);
    s32 func_800BA994(s32, s32, s16, s32, s32, s32, s32);
    void func_800BA22C(s32, s32);
    void func_80800204_chtransparentfish(Actor *);
    void func_80800000_chtransparentfish(Actor *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101CDC(Actor *, f32);
    void func_80102BAC(Actor *, f32, f32, f32);
    void func_80102C58(void *, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_8010BA80(Actor *, s32, s32);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F0DC0(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    extern s32 D_80801050_chtransparentfish[];
    struct TransparentFishFlags {
        u32 unused : 2;
        u32 active : 1;
    };
    s32 flag;
    f32 position[3];
    f32 height;
    f32 factor;
    s32 emitter;

    _subaddiesect_entrypoint_0(actor, (s32)((f32 *)actor->actorData)[5], 11);
    func_80800AC4_chtransparentfish(actor, 0, actor->unk7C_12);
    if (func_800F52B8(func_800F54E4(), actor->unk0) != 20) {
        flag = func_800F690C(func_800F54E4());
        height = func_80103EAC(actor);
        factor = flag ? 0.5f : 0.25f;
        func_800EFA4C(position, actor->position[0], actor->position[1] + factor * height, actor->position[2]);
        factor = flag ? 0.75f : 0.5f;
        _sudeflect_entrypoint_0(position, 0.0f, factor * height, 30);
    }
    if (func_80101E14(actor, 0.01f) && func_80102CCC(actor)) {
        emitter = func_800B53A4(10);
        func_800BABB8(emitter, actor->actorData, 0, actor->scale, D_80801050_chtransparentfish);
        func_800BA994(emitter, (s16)actor->rotation[0], (s16)(actor->rotation[1] - 35.0f),
            (s16)(((f32 *)actor->actorData)[3] * 1.1f), (s16)actor->rotation[0],
            (s32)(actor->rotation[1] + 35.0f), (s32)(((f32 *)actor->actorData)[3] * 2.0f));
        func_800BA22C(emitter, 10);
    }
    if (actor->unk70_10 == 1) {
        if (((struct TransparentFishFlags *)((u8 *)actor + 0x64))->active) {
            func_80800204_chtransparentfish(actor);
            func_80101CDC(actor, func_800F10B4(((f32 *)actor->actorData)[3], 0.0f, 300.0f, 3.0f, 1.5f));
        } else {
            func_80800000_chtransparentfish(actor);
            func_80102BAC(actor, 0.05f, 0.05f, 4.0f);
            func_80102C58(actor, 0.05f, 0.01f, 0.5f);
            ((f32 *)actor->actorData)[3] = func_800F15F8(((f32 *)actor->actorData)[3], ((f32 *)actor->actorData)[7], 2.0f);
            if (func_8010BA80(actor, 38, 16)) {
                actor->unk54 += 10.0f;
            }
        }
        ((f32 *)actor->actorData)[4] = func_800F0DC0(func_800F1DCC(actor->rotation[1], actor->unk54) * 0.5f, 15.0f);
        actor->rotation[2] = func_800F1FF0(actor->rotation[2], ((f32 *)actor->actorData)[4], 0.01f, 0.005f, 0.1f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparentfish/func_80800690_chtransparentfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparentfish/func_8080078C_chtransparentfish.s")

void func_80800AC4_chtransparentfish(Actor *arg0, f32 *arg1, s32 arg2) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *temp_v0;
    Actor *var_v1;
    s32 pad;

    temp_v0 = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
    var_v1 = temp_v0;
    if (temp_v0 != NULL) {
        if (arg1 != 0) {
            func_800EE7F8(temp_v0->position, arg1);
            var_v1 = temp_v0;
        }
        var_v1->unk64_16 = arg2;
    }
}

void func_80800B30_chtransparentfish(s32 arg0)
{
    func_800DA524(FLAG3_9F4_UNK);
}

OSThread *chtransparentfish_entrypoint_0(void)
{
    extern u8 D_80801098_chtransparentfish[];

    return (OSThread *) D_80801098_chtransparentfish;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparentfish/func_80800B60_chtransparentfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparentfish/func_80800E10_chtransparentfish.s")

s32 func_80800EE0_chtransparentfish(s32 arg0) {
    extern s32 B_808010E0_chtransparentfish[20][3];
    s32 i;

    for (i = 0; i < 20; i++) {
        if (arg0 == B_808010E0_chtransparentfish[i][0]) {
            return B_808010E0_chtransparentfish[i][2];
        }
    }
    return 0;
}
