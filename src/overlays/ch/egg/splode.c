#include "common.h"

OSThread *cheggsplode_entrypoint_0(void)
{
    extern u8 D_80800994_cheggsplode[];

    return (OSThread *) D_80800994_cheggsplode;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080000C_cheggsplode.s")

s32 func_808002A8_cheggsplode(Actor *arg0, s32 arg1, s32 arg2) {
    s8 func_800BF8E4(void);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_800D3948(void);
    void *func_80100094(Actor *, u32);
    extern u32 D_808009DC_cheggsplode;
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
        s32 unk10;
    } *sp1C;
    s32 temp_v0;
    s32 var_v0;

    sp1C = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x9F:
            if (func_800D3948() == 0) {
                sp1C->unk6 = 1;
            }
            return 1;
        case 0x95:
            if (func_800BF8E4() > 0) {
                temp_v0 = func_800C8A98();
                sp1C->unk10 = temp_v0;
                func_800C8E84(temp_v0, &D_808009DC_cheggsplode);
                func_800C8CB8(sp1C->unk10, arg0->position);
            }
            return 1;
        default:
            return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/splode/func_8080035C_cheggsplode.s")

void func_8080041C_cheggsplode(Actor *arg0) {
    void func_800187B4(s32, f32, f32, f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800E1610(s32, f32, f32, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F54F0(s32);
    s32 func_800F6BE4(s32);
    void *func_80100094(Actor *, u32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    void func_808006F0_cheggsplode(Actor *);
    void func_80800778_cheggsplode(Actor *, s32);
    extern s32 D_808008B0_cheggsplode;
    extern s32 D_80800980_cheggsplode;
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
        s32 unk10;
    } *sp34;
    s32 var_s1;

    sp34 = func_80100094(arg0, 0);
    var_s1 = sp34->unk0;
    if (func_800F6BE4(var_s1) == 0) {
        var_s1 = func_800F54E4();
    }
    sp34->unk8 = 0.0f;
    func_800E1610(0, 20.0f, 0.6f, arg0->position);
    func_800187B4(func_800F54F0(var_s1), 0.85f, 0.45f, 0.6f);
    arg0->position[1] += 60.0f;
    func_800BABB8(0, arg0->position, NULL, 1.0f, &D_808008B0_cheggsplode);
    if (sp34->unk4 != 5) {
        func_808006F0_cheggsplode(arg0);
    }
    func_8010D930(6, -1, arg0->position, &D_80800980_cheggsplode);
    sp34->unk10 = 0;
    if (func_800F6BE4(var_s1) != 0) {
        func_80800778_cheggsplode(arg0, var_s1);
    }
}

/* extern */

f32 func_80800548_cheggsplode(s32 arg0) {
    s32 func_800F693C(s32);
    s32 func_800F6BE4(s32);
    if (func_800F6BE4(arg0) != 0) {
        return func_800F693C(arg0) != 0 ? 250.0f : 190.0f;
    }
    return 190.0f;
}

void cheggsplode_entrypoint_1(Actor **arg0, s32 arg1, s32 arg2) {
    Actor *func_801084B0(s32, Actor **);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
    } *data;

    actor = func_801084B0(0x2B2, arg0);
    data = func_80100094(actor, 0);
    data->unk6 = 0;
    data->unk4 = arg2;
    data->unk0 = arg1;
    if (arg2 != 4) {
        if (arg2 == 6) {
            actor->unk70_10 = 3;
            data->unkC = 350.0f;
        }
    } else {
        actor->unk70_10 = 2;
        data->unkC = func_80800548_cheggsplode(arg1);
    }
}

void cheggsplode_entrypoint_2(f32 *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Actor *func_80108474(u32, f32 *, s32);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
    } *data;

    actor = func_80108474(0x2B2, arg0, (s32)arg1);
    data = func_80100094(actor, 0);
    data->unk0 = arg2;
    data->unk4 = arg3;
    data->unk6 = arg4 == 0;
    if (arg3 == 5) {
        actor->unk70_10 = 4;
        data->unkC = func_80800548_cheggsplode(arg2);
    }
}

void func_808006F0_cheggsplode(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808009E8_cheggsplode;
    u16 var_v0;
    s32 temp_a0;

    temp_a0 = func_800B53A4(6);
    var_v0 = arg0->unk70_10 == 3 ? 0x875 : 0x9B1;
    func_800BA670(temp_a0, var_v0);
    func_800BABB8(temp_a0, arg0->position, arg0->position, 0.25f, &D_808009E8_cheggsplode);
    func_800BA22C(temp_a0, 6);
}

/* extern */

void func_80800778_cheggsplode(Actor *arg0, s32 arg1) {
    s32 func_800D3948();
    s32 func_800F6BE4(s32);
    s32 func_800F6CC8(s32);
    void *func_80100094(Actor *, u32);
    if ((func_800D3948() == 0) && (func_800F6BE4(arg1) != 0) && (func_800F6CC8(arg1) != 0)) {
        (*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (6))) = 1;
    }
}

/* extern */

s32 func_808007D4_cheggsplode(s32 arg0, s32 arg1) {
    s32 func_800F6478(s32);
    if (func_800F6478(arg1) == 0) {
        return 0;
    }
    return 1;
}
