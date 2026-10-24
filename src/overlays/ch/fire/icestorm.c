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

void func_80800018_chfireicestorm(Actor *arg0) {
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 func_800A9C98(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void func_80800558_chfireicestorm(Actor *, u32);
    f32 sp44[3];
    f32 sp38[3];
    enum flag_e sp34;
    enum flag_e sp30;

    func_800DA524(FLAG3_9FB_UNK);
    if (arg0->unk74_7 != 0x32) {
        arg0->unk64_20 = 1;
    } else {
        arg0->unk64_20 = 0;
    }
    sp34 = arg0->unk64_20 ? FLAG_1D5_PROGRESS_CHILLY_WILLY_DEFEATED : FLAG_1D6_PROGRESS_CHILLI_BILLI_DEFEATED;
    sp30 = arg0->unk64_20 ? FLAG_43E_FTT_HFP_INTRO_TEXT_CHILLY_WILLY : FLAG_43F_FTT_HFP_INTRO_TEXT_CHILLI_BILLI;
    if (func_800A9C98()) {
        func_800DA524(sp34);
        func_800DA544(sp30);
    }
    if (func_800DA298(sp34)) {
        func_800FFAB0(arg0);
        return;
    }
    if (func_800A9C98()) {
        arg0->unk58 = 5.0f;
    } else {
        arg0->unk58 = 30.0f;
    }
    if (func_800DA298(sp30)) {
        func_80800558_chfireicestorm(arg0, 3);
    }
    arg0->unk64_19 = func_800DA298(FLAG_049_PHYSICAL_HFP_StoneBuildingBroken) || arg0->unk64_20;
    if (!arg0->unk64_19) {
        _subaddiemarker_entrypoint_1(arg0, 0x320, 0x32, sp38, 1);
        func_800EE7F8((f32 *)arg0->actorData, sp38);
        _subaddiemarker_entrypoint_1(arg0, 0x320, 0x33, sp38, 1);
        func_800EE7F8((f32 *)&arg0->actorData[4], sp38);
    }
}

void func_808001CC_chfireicestorm(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_16(void);
    s32 func_800A9C98(void);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F55FC(s32);
    s32 func_800F6478(s32);
    void func_80108B04(Actor *, u32);
    void func_80800558_chfireicestorm(Actor *, u32);
    void func_80800940_chfireicestorm(s32);
    s32 func_80800980_chfireicestorm(Actor *, u32, u32);
    s32 func_808009C8_chfireicestorm(Actor *);
    s32 sp24;
    u32 state;

    sp24 = func_800F54E4();
    if (func_800F6478(sp24) && !(func_800F55FC(sp24) & 0x20000000)) {
        state = arg0->unk70_10;
        switch (state) {
        case 1:
            if (func_800D90A4(&arg0->unk58) && _subaddiedialog_entrypoint_16()) {
                if (func_80800980_chfireicestorm(arg0, arg0->unk64_20 ? 0x12D0 : 0x12CF, 4)) {
                    func_80800940_chfireicestorm((s32)arg0);
                    func_80800558_chfireicestorm(arg0, 2);
                }
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58)) {
                func_80800940_chfireicestorm((s32)arg0);
                func_80800558_chfireicestorm(arg0, 4);
            }
            break;
        case 4:
            if (!func_800DA298(FLAG2_6CD_UNK) && !func_800A9C98()) {
                if (func_800D9078(&arg0->unk58)) {
                    func_80800558_chfireicestorm(arg0, 3);
                } else if (func_800D9078((f32 *)&arg0->actorData[3]) && !func_808009C8_chfireicestorm(arg0)) {
                    func_80108B04(arg0, 0);
                    *(f32 *)&arg0->actorData[3] = func_800DC178(3.0f, 4.0f);
                }
            }
            break;
        }
    }
}

void func_80800360_chfireicestorm(s32 arg0)
{
    func_800DA524(FLAG3_9FB_UNK);
}

s32 func_80800384_chfireicestorm(Actor *arg0, s32 arg1, s32 arg2) {
    void func_8080048C_chfireicestorm(Actor *);
    void func_80800558_chfireicestorm(Actor *, u32);
    Actor *func_80800608_chfireicestorm(Actor *);
    Actor *func_808007EC_chfireicestorm(Actor *);

    switch (arg1) {
        case 0x2E:
            switch (*(s16 *)&arg2) {
                case 0x12CF:
                    func_800DA544(FLAG_43F_FTT_HFP_INTRO_TEXT_CHILLI_BILLI);
                    break;
                case 0x12D0:
                    func_800DA544(FLAG_43E_FTT_HFP_INTRO_TEXT_CHILLY_WILLY);
                    break;
            }
            func_80800558_chfireicestorm(arg0, 4);
            break;
        case 0x3D:
            switch (arg2) {
                case 0:
                    if (!func_800DA298(FLAG2_6CD_UNK)) {
                        func_80800608_chfireicestorm(arg0);
                    }
                    break;
                case 1:
                    func_808007EC_chfireicestorm(arg0);
                    break;
            }
            break;
        case 0x95:
            func_8080048C_chfireicestorm(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

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

Actor *func_80800608_chfireicestorm(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    u32 func_800F54E4(void);
    f32 func_800F5BF0(s32, f32 *);
    void func_80102FDC(Actor *, f32);
    s32 func_80103140(Actor *, u32, u16);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800E80_chfireicestorm;
    extern s32 D_80800E94_chfireicestorm;
    Actor *child;
    f32 sp40[3];
    f32 sp34[3];

    func_800F5BF0(func_800F54E4(), sp40);
    func_800EE7F8(sp34, sp40);
    sp34[0] += func_800DC178(-100.0f, 100.0f);
    sp34[1] += 2500.0f;
    sp34[2] += func_800DC178(-100.0f, 100.0f);
    child = func_80108528(0x4FD, sp34, 0, &arg0);
    child->unk64_20 = arg0->unk64_20;
    func_80102FDC(child, func_800DC178(0.95f, 1.25f));
    func_800EFB24(&child->actorData[4], sp40, sp34);
    func_800EF368((f32 *)&child->actorData[4], func_800DC178(2750.0f, 3250.0f));
    func_800EFA4C((f32 *)child->actorData, func_800DC178(50.0f, 100.0f), 0.0f, func_800DC178(5.0f, 10.0f));
    func_80103140(child, (u16)(arg0->unk64_20 ? 0x814 : 0x815), child->unk0->unk16);
    func_8010D930(4, child->unk70_0, sp34, child->unk64_20 ? &D_80800E94_chfireicestorm : &D_80800E80_chfireicestorm);
    return arg0;
}

Actor *func_808007EC_chfireicestorm(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _subaddieDll_entrypoint_0(Actor *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_80102FDC(Actor *, f32);
    s32 func_80103140(Actor *, u32, u16);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_8010A570(Actor *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800E80_chfireicestorm;
    Actor *temp_v0;
    f32 sp38[3];
    f32 sp2C[3];

    func_800EE7F8(sp2C, (f32 *)arg0->actorData);
    func_800EE7F8(sp38, (f32 *)&arg0->actorData[4]);
    temp_v0 = func_80108528(0x4FD, sp2C, 0, &arg0);
    temp_v0->unk3C = arg0->unk0;
    temp_v0->unk64_20 = 0;
    temp_v0->unk64_19 = 1;
    func_80102FDC(temp_v0, 2.0f);
    func_8010A570(temp_v0);
    _subaddieDll_entrypoint_0(temp_v0);
    func_800EFB24(&temp_v0->actorData[4], sp38, sp2C);
    func_800EF368((f32 *)&temp_v0->actorData[4], 2000.0f);
    func_800EFA4C((f32 *)temp_v0->actorData, func_800DC178(50.0f, 100.0f), 0.0f, func_800DC178(5.0f, 10.0f));
    func_80103140(temp_v0, 0x815, temp_v0->unk0->unk16);
    if (!temp_v0->unk64_19) {
        func_8010D930(4, temp_v0->unk70_0, sp2C, &D_80800E80_chfireicestorm);
    }
    _capod_entrypoint_13(temp_v0->unk0, 0, 0x27, 0x10);
    return arg0;
}

/* extern */

void func_80800940_chfireicestorm(s32 arg0) {
    s32 func_800C3FF0(s32, s32, s32);
    func_800C3FF0(0x605, 0x3F4CCCCD, 0x7FFF);
    func_800C3FF0(0x604, 0x3F800000, 0x7FFF);
}

s32 func_80800980_chfireicestorm(Actor *arg0, u32 arg1, u32 arg2) {
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

void func_80800A50_chfireicestorm(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    void _subaddiefade_entrypoint_3(Actor *);
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    s32 func_80101180(s32, s32, s32);
    void func_80800D0C_chfireicestorm(Actor *);
    void func_80800DC8_chfireicestorm(Actor *);
    void func_80800E08_chfireicestorm(Actor *);
    extern s32 D_80800F38_chfireicestorm;
    void *sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;

    if (arg0->unk70_10 == 1) {
        sp30 = func_800D8FF8();
        func_800EFA20(sp58, &arg0->actorData[4], sp30);
        func_800EE780(sp4C, arg0->position, sp58);
        sp64 = func_800C6A7C(arg0->position, sp4C, sp34, 0x20020);
        func_800EE7F8(arg0->position, sp4C);
        if (arg0->unk64_19) {
            _subaddieaudioloop_entrypoint_5(arg0, arg0->position, 1, 1500, &D_80800F38_chfireicestorm);
        }
        if (sp64 != NULL) {
            if (arg0->unk64_19) {
                func_80101180(0x4A4, 0x40, 0);
            }
            func_80800D0C_chfireicestorm(arg0);
        } else if (func_800D9078(&arg0->unk58)) {
            _subaddiefade_entrypoint_3(arg0);
        }
        func_800EFA20(sp40, arg0->actorData, sp30);
        func_800EF04C(arg0->rotation, sp40);
        if (arg0->unk64_20) {
            func_80800E08_chfireicestorm(arg0);
            return;
        }
        func_80800DC8_chfireicestorm(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/icestorm/func_80800BA4_chfireicestorm.s")

void func_80800D0C_chfireicestorm(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_80018820(s32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_80101FDC(Actor *, u32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800F68_chfireicestorm;
    extern s32 D_80800F7C_chfireicestorm;
    s32 *var_a3;
    u32 var_a2;

    var_a2 = 0x14;
    if (!arg0->unk64_19) {
        var_a2 = 0x1C;
    }
    _chexploder_entrypoint_3(arg0, arg0->position, var_a2);
    func_800E1610(2, 150.0f, 0.85f, arg0->position);
    func_80018820(0, 2.0f, 0.3f);
    if (arg0->unk64_20) {
        var_a3 = &D_80800F68_chfireicestorm;
    } else {
        var_a3 = &D_80800F7C_chfireicestorm;
    }
    func_8010D930(4, arg0->unk70_0, arg0->position, var_a3);
    func_80101FDC(arg0, 2);
}

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
