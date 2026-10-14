#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800000_chevilmumbo.s")

/* extern */

void func_80800098_chevilmumbo(s32 arg0) {
    s32 _capod_entrypoint_3(s32);
    _capod_entrypoint_3(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808000BC_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800144_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808001F4_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800290_chevilmumbo.s")

void func_80800300_chevilmumbo(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F990(s32 *, s32);
    extern s32 D_80804294_chevilmumbo;
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F990(&D_80804294_chevilmumbo, 0x43480000);
}

/* extern */

void func_80800354_chevilmumbo(Actor *arg0, s16 arg1, s32 arg2) {
    s32 func_800C05B8(s32, s32, f32 *, Unk80132ED0 *, s32, s32, s16);
    s32 var_a1;
    s32 var_v0;

    if (arg0->unk64_20) {
        var_v0 = 0x77;
    } else {
        var_v0 = 0x10;
    }
    if (arg2 != 0) {
        var_v0 = arg2;
    }
    if (arg1 == 0xCEB) {
        var_a1 = 0x46;
    } else {
        var_a1 = 7;
    }
    func_800C05B8(arg1, var_a1, arg0->position, arg0->unk0, 0, 0, var_v0);
    arg0->unk74_30 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808003DC_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800670_chevilmumbo.s")

void func_80800774_chevilmumbo(Actor *arg0) {
    func_801032B0(arg0, 0x816, arg0->unk0->unk16);
    arg0->unk64_20 = 1;
    _suexpression_entrypoint_4(func_80100094(arg0, 1), 0x77);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808007C4_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800C50_chevilmumbo.s")

/* extern */

int func_80800E50_chevilmumbo(Actor *arg0) {
    f32 func_800F1DCC(f32, f32);
    f32 temp_f0;
    int var_v0;

    temp_f0 = func_800F1DCC(arg0->unk54, arg0->rotation[1]);
    if ((temp_f0 < -3.0f) || (var_v0 = 1, (temp_f0 > 3.0f))) {
        var_v0 = 0;
        arg0->rotation[1] += temp_f0 * 0.1f;
        return var_v0;
    }
    return var_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800ECC_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800F60_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80800FF8_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808010C4_chevilmumbo.s")

void func_808011B8_chevilmumbo(s32 arg0) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80804304_chevilmumbo;
    s32 temp_a0;

    temp_a0 = arg0 + 4;
    func_800BBCB8(temp_a0, temp_a0, 0x3F800000, 1, &D_80804304_chevilmumbo);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808011F4_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_8080129C_chevilmumbo.s")

void func_808023E8_chevilmumbo(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_8080241C_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80802618_chevilmumbo.s")

OSThread *chevilmumbo_entrypoint_0(void)
{
    extern u8 D_80804460_chevilmumbo[];

    return (OSThread *) D_80804460_chevilmumbo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_8080300C_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808030AC_chevilmumbo.s")

void func_80803358_chevilmumbo(u8 *arg0) {
    void func_800C8B84(s32);
    if (((Actor *)arg0)->unk6C_0 != 0) {
        func_800C8B84(((Actor *)arg0)->unk6C_0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80803388_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_808034C8_chevilmumbo.s")

/* extern */

void func_808035A8_chevilmumbo(u8 *arg0, s32 arg1) {
    s32 func_800D674C(s32);
    s32 func_800DE448(u8 *, u8 *, s32, s32, s32);
    s32 func_800DF830(s32);
    s32 func_801018A4(u8 *, s32);
    s32 func_80101970();
    (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) -(*(f32 *)((s8 *)(arg0) + (0x44)));
    func_80101970();
    func_800DF830(2);
    func_800DE448(arg0 + 4, arg0 + 0x44, (*(s32 *)((s8 *)(arg0) + (0x38))), 0, func_800D674C(0x69E));
    func_801018A4(arg0, arg1);
    (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) -(*(f32 *)((s8 *)(arg0) + (0x44)));
}

OSThread *chevilmumbo_entrypoint_1(void)
{
    extern u8 D_808044F0_chevilmumbo[];

    return (OSThread *) D_808044F0_chevilmumbo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_8080362C_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80803700_chevilmumbo.s")

void func_80803918_chevilmumbo(s32 arg0) 
{
}
/* extern */

void func_80803920_chevilmumbo(s32 arg0) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    s32 func_8080362C_chevilmumbo(s32, s32);
    func_800EFA4C(arg0 + 0x18, -130.0f, 0.0f, -430.0f);
    func_8080362C_chevilmumbo(arg0, 1);
}

s32 func_8080395C_chevilmumbo(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xB) {
        return 3;
    }
    return 0;
}

OSThread *chevilmumbo_entrypoint_2(void)
{
    extern u8 D_80804544_chevilmumbo[];

    return (OSThread *) D_80804544_chevilmumbo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_8080398C_chevilmumbo.s")

void func_80803A24_chevilmumbo(s32 arg0, s32 arg1) {
    struct State {
        u8 pad[0x72];
        u8 state : 6;
        u8 other : 2;
    };
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 temp;

    switch (arg1) {
    case 2:
        *(f32 *)(arg0 + 0x28) = 0.3f;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    case 3:
        *(f32 *)(arg0 + 0x2C) = 1.0f;
        *(f32 *)(arg0 + 0x38) = 1.0f;
        *(f32 *)(arg0 + 0x28) = 0.15f;
        break;
    case 4:
        *(f32 *)(arg0 + 0x38) = 1.0f;
        temp = func_800F10B4(*(f32 *)(arg0 + 0x2C), 0.0f, 1.0f, 0.0f, 0.2f);
        *(f32 *)(arg0 + 0x28) = temp;
        if (temp == 0.0f) {
            *(f32 *)(arg0 + 0x28) += 0.01f;
        }
        break;
    case 5:
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    }
    ((struct State *)arg0)->state = arg1;
}

void func_80803B28_chevilmumbo(s32 arg0)
{
    func_80803A24_chevilmumbo(arg0,0x2);
}

void func_80803B48_chevilmumbo(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80803B50_chevilmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilmumbo/func_80803C88_chevilmumbo.s")

OSThread *chevilmumbo_entrypoint_3(void)
{
    extern u8 D_8080458C_chevilmumbo[];

    return (OSThread *) D_8080458C_chevilmumbo;
}
