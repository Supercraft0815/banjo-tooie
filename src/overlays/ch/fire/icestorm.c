#include "ch/fireicestorm.h"

OSThread *chfireicestorm_entrypoint_0(void)
{
    extern u8 D_80800EA8_chfireicestorm[];

    return (OSThread *) D_80800EA8_chfireicestorm;
}

OSThread *chfireicestorm_entrypoint_1(void)
{
    extern u8 D_80800EF0_chfireicestorm[];

    return (OSThread *) D_80800EF0_chfireicestorm;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_80800018_chfireicestorm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_808001CC_chfireicestorm.s")

void func_80800360_chfireicestorm(s32 arg0)
{
    func_800DA524(FLAG3_9FB_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_80800384_chfireicestorm.s")

/* extern */

void func_8080048C_chfireicestorm(Actor *arg0) {
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    s32 func_800BEA88(s32);
    s32 func_800EA090(void);
    void func_800FFAB0(Actor *);
    s32 sp2C;
    volatile s32 sp28;
    s32 pad;
    s32 sp20;
    s32 sp1C;
    s32 temp_v0;
    s32 var_v1;

    sp2C = 0;
    sp28 = 0;
    temp_v0 = func_800EA090();
    var_v1 = sp28;
    if (arg0->unk64_20) {
        if (temp_v0 == 6) {
            sp2C = 1;
        }
        if (temp_v0 == 0xA) {
            sp2C = 1;
            var_v1 = 1;
        }
    }
    if (var_v1 != 0) {
        sp20 = func_800BEA88(0);
        sp1C = func_800BEA88(1);
        if (sp20 != 0) {
            _idworldmake_entrypoint_1(sp20, 0x596, 1, 1);
        }
        if (sp1C != 0) {
            _idworldmake_entrypoint_1(sp1C, 0x65E, 2, 1);
        }
    }
    if (sp2C != 0) {
        func_800FFAB0(arg0);
    }
}

void func_80800558_chfireicestorm(Actor *arg0, u32 arg1) {
    s32 func_800A9C98(void);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 sp24;

    sp24 = 0;
    func_80101FDC(arg0, arg1);
    switch (arg1) {
        case 3:
            if (func_800A9C98() != 0) {
                arg0->unk58 = 5.0f;
            } else {
                arg0->unk58 = 30.0f;
            }
            break;
        case 4:
            sp24 = 1;
            arg0->unk58 = 15.0f;
            ((f32 *)arg0->actorData)[3] = func_800DC178(3.0f, 4.0f);
            break;
    }
    func_800DA3B8(FLAG3_9FB_UNK, sp24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_80800608_chfireicestorm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_808007EC_chfireicestorm.s")

/* extern */

void func_80800940_chfireicestorm(s32 arg0) {
    s32 func_800C3FF0(s32, s32, s32);
    func_800C3FF0(0x605, 0x3F4CCCCD, 0x7FFF);
    func_800C3FF0(0x604, 0x3F800000, 0x7FFF);
}

void func_80800980_chfireicestorm(Actor *arg0, u32 arg1, u32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    u32 var_v0;

    var_v0 = arg0->unk64_20 ? 0x75 : 0x76;
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, NULL, var_v0);
}

/* extern */

s32 func_808009C8_chfireicestorm(Actor *arg0) {
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    if (arg0->unk64_19) {
        return 0;
    }
    if (func_800DA298(FLAG3_A24_UNK) != 0) {
        func_80101FDC(arg0, 5);
        func_80108B04(arg0, 1);
        arg0->unk64_19 = 1;
        return 1;
    }
    return 0;
}

void func_80800A40_chfireicestorm(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 8.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_80800A50_chfireicestorm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_80800BA4_chfireicestorm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_80800D0C_chfireicestorm.s")

void func_80800DC8_chfireicestorm(Actor *arg0) {
    s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
    extern s32 D_80800F94_chfireicestorm;
    func_800BBCB8(arg0->position, 0, arg0->scale, 1, &D_80800F94_chfireicestorm);
}

void func_80800E08_chfireicestorm(Actor *arg0) {
    s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
    extern s32 D_80800FCC_chfireicestorm;
    extern s32 D_80800FFC_chfireicestorm;
    func_800BBCB8(arg0->position, 0, arg0->scale, 1, &D_80800FCC_chfireicestorm);
    func_800BBCB8(arg0->position, 0, arg0->scale, 2, &D_80800FFC_chfireicestorm);
}
