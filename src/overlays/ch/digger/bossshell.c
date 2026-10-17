#include "common.h"

OSThread *chdiggerbossshell_entrypoint_0(void)
{
    extern u8 D_80800560_chdiggerbossshell[];

    return (OSThread *) D_80800560_chdiggerbossshell;
}

OSThread *chdiggerbossshell_entrypoint_1(void)
{
    extern u8 D_808005A8_chdiggerbossshell[];

    return (OSThread *) D_808005A8_chdiggerbossshell;
}

/* extern */

void func_80800018_chdiggerbossshell(Actor *arg0) {
    void func_800EEC30(f32 *, f32, f32, f32);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 func_80102D78(Actor *, f32 *);
    f32 sp34;
    f32 sp30;
    f32 temp_f0;
    f32 *temp_a1;

    temp_a1 = (f32 *)arg0->actorData;
    temp_f0 = func_800EFB8C(arg0->position, temp_a1);
    sp30 = arg0->position[1] - ((f32 *)arg0->actorData)[1];
    arg0->rotation[0] = 45.0f;
    sp34 = temp_f0;
    arg0->rotation[1] = func_80102D78(arg0, temp_a1);
    func_800EEC30((f32 *)&arg0->actorData[4], arg0->rotation[0], arg0->rotation[1], sqrtf((sp34 * sp34 * 9800.0f) / (sp34 + sp30)));
}

/* extern */

void func_808000B4_chdiggerbossshell(Actor *arg0) {
    void _fxegg_entrypoint_5(f32 *, f32 *, f32);
    f32 func_800D8FF8(void);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800F1A88(f32 *, f32 *);
    void func_808001EC_chdiggerbossshell(Actor *);
    f32 sp2C;

    if (arg0->unk70_10 == 1) {
        sp2C = func_800D8FF8();
        _fxegg_entrypoint_5(arg0->position, (f32 *)&arg0->actorData[4], 1.0f);
        func_800EF174(arg0->position, (f32 *)&arg0->actorData[4], func_800D8FF8());
        if (((f32 *)arg0->actorData)[1] > arg0->position[1]) {
            arg0->position[1] = ((f32 *)arg0->actorData)[1];
            func_808001EC_chdiggerbossshell(arg0);
        }
        ((f32 *)arg0->actorData)[5] = ((f32 *)arg0->actorData)[5] + -9800.0f * sp2C;
        func_800F1A88((f32 *)&arg0->actorData[4], arg0->rotation);
        arg0->rotation[0] = arg0->rotation[0] + 90.0f;
    }
}

/* extern */

s32 func_80800188_chdiggerbossshell(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFAB0(Actor *);
    void func_808001EC_chdiggerbossshell(Actor *);
    Actor *func_80800330_chdiggerbossshell(Actor *);
    switch (arg1) {
        case 0x40:
            func_808001EC_chdiggerbossshell(arg0);
            break;
        case 0x3D:
            func_800FFAB0(func_80800330_chdiggerbossshell(arg0));
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808001EC_chdiggerbossshell(Actor *arg0) {
    s32 *_fxgenlist_entrypoint_2(void);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_808002CC_chdiggerbossshell(f32 *);
    extern s32 D_808005F0_chdiggerbossshell;
    f32 position[3];

    func_800EE7F8(position, arg0->position);
    position[1] += 50.0f;
    func_800BBCB8(position, NULL, 1.4f, 1, _fxgenlist_entrypoint_2());
    _subaddieaudioquick_entrypoint_2(arg0, position, &D_808005F0_chdiggerbossshell);
    func_800E1610(0, 20.0f, 0.9f, arg0->position);
    func_80018820(0, 2.0f, 0.25f);
    position[1] += 50.0f;
    func_808002CC_chdiggerbossshell(position);
    func_8010A570(arg0);
    func_80101FDC(arg0, 2);
    func_80108B04(arg0, 0);
}

void func_808002CC_chdiggerbossshell(f32 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32);
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, f32 *);
    s32 func_800C8E54(s32, s32, s32);
    s32 func_800C8E84(s32, s32 *);
    extern s32 D_80800600_chdiggerbossshell;
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800C8A98();
    sp1C = temp_v0;
    func_800C8CB8(temp_v0, arg0);
    func_800C8E84(sp1C, &D_80800600_chdiggerbossshell);
    func_800C8E54(sp1C, 0x44160000, 0x447A0000);
    _chlightfader_entrypoint_1(sp1C, 0x3FB33333, 5);
}

/* extern */

Actor *func_80800330_chdiggerbossshell(Actor *arg0) {
    f32 func_800136E4(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80102FDC(Actor *, f32);
    s32 func_80103140(Actor *, u32, u16);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    f32 func_8010CD28(Actor *);
    f32 var_f20;
    s32 var_s1;
    Actor *temp_v0;
    f32 position[3];

    var_f20 = func_8010CD28(arg0) + arg0->unk54;
    func_800EE7F8(position, arg0->position);
    if (position[1] < 7500.0f) {
        position[1] = 7500.0f;
    }
    position[1] += 60.0f;
    for (var_s1 = 0; var_s1 != 4; var_s1++) {
        temp_v0 = func_80108528(0x4F4, position, (s32) var_f20, &arg0);
        func_80102FDC(temp_v0, arg0->scale);
        func_80103140(temp_v0, (var_s1 + 0x905) & 0xFFFF, 0);
        *(f32 *)&temp_v0->actorData[3] = *(f32 *)&arg0->actorData[3];
        var_f20 = func_800136E4(var_f20 + 90.0f);
    }
    return arg0;
}

void func_8080044C_chdiggerbossshell(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 1.75f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossshell/func_8080045C_chdiggerbossshell.s")

/* extern */

s32 func_808004C8_chdiggerbossshell(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800504_chdiggerbossshell(s32 arg0);
    switch (arg1) {
    case 0x40:
        func_80800504_chdiggerbossshell(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800504_chdiggerbossshell(s32 arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FFAB0(Actor *);
    void func_8010A570(Actor *);
    extern s32 D_8080060C_chdiggerbossshell;
    s32 temp_a0;

    temp_a0 = arg0 + 4;
    func_800BBCB8(temp_a0, temp_a0, 1.0f, 3, &D_8080060C_chdiggerbossshell);
    func_8010A570(arg0);
    func_800FFAB0(arg0);
}
