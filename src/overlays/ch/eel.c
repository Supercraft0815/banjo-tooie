#include "common.h"

/* extern */

void func_80800000_cheel(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct {
        s32 unk0;
        f32 unk4[9];
        f32 unk28[9];
        f32 unk4C[9];
        f32 unk70[9];
        f32 unk94[9];
        f32 unkB8[9];
    } *data;
    s32 i;

    data = func_80100094(arg0, 0U);
    for (i = 0; i < 9; i++) {
        data->unk28[i] = 0.0f;
        data->unk4[i] = 0.0f;
        data->unk94[i] = 0.0f;
        data->unk70[i] = 0.0f;
        data->unk4C[i] = 0.0f;
        data->unkB8[i] = 0.0f;
    }
}

/* extern */

void func_808000B4_cheel(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_80801200_cheel(Actor *, s32);
    union {
        Actor actor;
        struct {
            u8 pad0[0x18];
            f32 pad18[3];
            f32 unk24;
            f32 unk28[3];
            f32 unk34;
            u8 pad38[0x3B];
            u8 pad73 : 7;
            u8 unk73_0 : 1;
        } eel;
    } *data = (void *)arg0;

    func_80800000_cheel(arg0);
    data->eel.unk34 = 0.0f;
    func_80801200_cheel(arg0, 1);
    func_800EE7F8(data->eel.unk28, arg0->position);
    data->eel.unk73_0 = 1;
    arg0->unk64_25 = 1;
    data->eel.unk24 = arg0->scale * 1000.0f;
}

void func_80800128_cheel(Actor *arg0) {
    void func_800C8B84(s32);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(s32 *)((s8 *)(temp_v0) + (0xDC))) != 0) {
        sp1C = temp_v0;
        func_800C8B84((*(s32 *)((s8 *)(temp_v0) + (0xDC))));
        (*(s32 *)((s8 *)(sp1C) + (0xDC))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80800168_cheel.s")

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x70];
        u32 unk70_25 : 7;
        u32 pad70_10 : 15;
        u32 unk70_4 : 6;
        u32 pad70_0 : 4;
    } eel;
} EelActor;

s32 func_8080020C_cheel(EelActor *arg0) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp24[3];
    s32 result;

    func_800EEC30(sp24, arg0->actor.rotation[0], arg0->actor.rotation[1], 200.0f);
    func_800EF04C(sp24, arg0->actor.position);
    result = func_800CC338(&sp24, arg0->eel.unk70_25 - 1, arg0->eel.unk70_4 - 1);
    if (result != -1) {
        arg0->eel.unk70_4 = result + 1;
        return 1;
    }
    return 0;
}

/* extern */

s32 func_808002A0_cheel(u8 *arg0) {
    s32 func_800EFFB4(u8 *, s32, u8 *, u8 *);
    f32 func_800F1DCC(f32, f32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_800F1DCC((*(f32 *)((s8 *)(arg0) + (0x48))), (*(f32 *)((s8 *)(arg0) + (0x54))));
    var_f2 = temp_f0;
    if (temp_f0 < 0.0f) {
        var_f2 = -temp_f0;
    }
    if ((var_f2 < 30.0f) || (func_800EFFB4(arg0 + 0x18, 0x43480000, arg0 + 4, arg0) != 0)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_8080031C_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80800D60_cheel.s")

/* extern */

void func_80801120_cheel(Actor *arg0) {
    void *func_800CC63C(s32, s32);
    f32 func_800EEB40(f32 *, f32 *);
    struct EelRegion {
        f32 position[3];
        s16 unkC;
        s16 height;
        f32 radius;
    } *region;
    f32 y;
    f32 actorY;
    f32 height;
    s32 flag;
    union EelActorView {
        Actor actor;
        struct {
            u32 prefix[28];
            u32 regionGroup : 7;
            u32 unused : 15;
            u32 regionIndex : 6;
            u32 remaining : 4;
        } regions;
    } *eel = (void *)arg0;

    region = func_800CC63C(eel->regions.regionGroup - 1, eel->regions.regionIndex - 1);
    y = region->position[1];
    actorY = arg0->position[1];
    height = region->height;
    if (y + height <= actorY || actorY <= y - height) {
        ((f32 *)arg0->actorData)[1] = y;
    }
    flag = func_800EEB40(arg0->position, region->position) == 0.0f;
    if ((f32)flag < region->radius) {
        ((f32 *)arg0->actorData)[0] = region->position[0];
        ((f32 *)arg0->actorData)[2] = region->position[2];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80801200_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80801330_cheel.s")

OSThread *cheel_entrypoint_0(void)
{
    extern u8 D_80801644_cheel[];

    return (OSThread *) D_80801644_cheel;
}
