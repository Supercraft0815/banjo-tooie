#include "common.h"

OSThread *chfactoryrobot_entrypoint_0(void)
{
    extern u8 D_80802928_chfactoryrobot[];

    return (OSThread *) D_80802928_chfactoryrobot;
}

OSThread *chfactoryrobot_entrypoint_1(void)
{
    extern u8 D_80802970_chfactoryrobot[];

    return (OSThread *) D_80802970_chfactoryrobot;
}

OSThread *chfactoryrobot_entrypoint_2(void)
{
    extern u8 D_808029B8_chfactoryrobot[];

    return (OSThread *) D_808029B8_chfactoryrobot;
}

/* extern */

void func_80800024_chfactoryrobot(void *arg0) {
    s32 func_80105010();
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x30))) = 20.0f;
    func_80105010();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800058_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800264_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800360_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800424_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800508_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_808005D4_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_808006DC_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_808007C4_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800920_chfactoryrobot.s")

/* extern */

void func_80800DC4_chfactoryrobot(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800C8B84(volatile s32);
    void *func_80100094(Actor *, u32);
    u8 *sp2C;
    s32 temp_a0;
    s32 var_s1;
    u8 temp_v0_2;
    u8 *temp_v0;
    u8 *var_s0;

    temp_v0 = func_80100094(arg0, 0);
    var_s1 = 0;
    var_s0 = temp_v0;
    sp2C = temp_v0;
    do {
        temp_v0_2 = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(var_s0) + (8))));
        var_s1 += 1;
        var_s0 += 1;
        (*(s8 *)((s8 *)(var_s0) + (7))) = temp_v0_2;
    } while (var_s1 != 2);
    temp_a0 = (*(s32 *)((s8 *)(sp2C) + (0x14)));
    if (temp_a0 != 0) {
        func_800C8B84(temp_a0);
        (*(s32 *)((s8 *)(sp2C) + (0x14))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800E40_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800FFC_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801160_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801278_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_8080183C_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801954_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801A80_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801B3C_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801BB0_chfactoryrobot.s")

s32 func_80801C50_chfactoryrobot(s32 arg0) {
    s32 func_80101074(s32 *);
    extern s32 D_80802AD4_chfactoryrobot;
    func_80101074(&D_80802AD4_chfactoryrobot);
    return 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801C7C_chfactoryrobot.s")

/* extern */

void func_80801D08_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad[0x70];
        u32 leading : 22;
        u32 state : 6;
        u32 trailing : 4;
    } RobotState;
    s32 func_800EA05C(void);
    void *func_80100094(Actor *, u32);
    u8 *data;
    RobotState *flags;

    data = func_80100094(arg0, 0);
    flags = (RobotState *)arg0;
    if (flags->state == 0) {
        flags->state = 1;
    }
    if (func_800EA05C() == 0x101) {
        data[0x12] = 1;
    } else {
        data[0x12] = 0;
    }
}

void func_80801D7C_chfactoryrobot(Actor *arg0) {
    typedef struct {
        u8 pad[0x64];
        u32 leading : 11;
        u32 sounded : 1;
        u32 trailing : 20;
    } RobotFlags;
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _chmrtannoy_entrypoint_0(void);
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sudialog_entrypoint_0(s32, s32);
    s32 func_8008FDC4(void);
    void func_800D1254(s32, s32, f32 *);
    s32 func_800D2498(s32, s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    int func_800F00A4(f32 *, f32, f32, f32, f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_800F1418(s32, s32);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D23C(void);
    extern s32 D_80802AEC_chfactoryrobot;
    u8 *data;
    Unk80132ED0 **cursor;
    s32 i;
    s32 nearby;
    f32 *position;
    f32 pos6[3];
    s32 done6;
    f32 height6;
    f32 pos7[3];
    s32 done7;
    f32 height7;

    data = func_80100094(arg0, 0);
    position = (f32 *)((u8 *)arg0 + 4);
    func_800F4F34(func_800F54E4(), position, 100.0f, 80.0f);
    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        if (*(Unk80132ED0 **)((u8 *)arg0 + 0x3C) == NULL) {
            func_80101FDC(arg0, 3);
        } else if (*(f32 *)((u8 *)func_80106790(*(Unk80132ED0 **)((u8 *)arg0 + 0x3C)) + 0x58) > 0.0f && data[0x14] == 0) {
            _sudialog_entrypoint_0(0x364, 4);
            i = 0;
            if (data[0x10] < data[0x11]) {
                nearby = 0;
                if (i < data[0x10]) {
                    cursor = (Unk80132ED0 **)data;
                    do {
                        if (func_800F00A4(position, 150.0f, 800.0f, 0.0f,
                                (f32 *)((u8 *)func_80106790(*cursor) + 4))) {
                            nearby = 1;
                            break;
                        }
                        i++;
                        cursor++;
                    } while (i < data[0x10]);
                }
                if (!nearby) {
                    func_80108B04(arg0, 0);
                    func_80101FDC(arg0, 2);
                    *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(1.5f, 2.5f);
                }
            }
        }
        break;
    case 2:
        if (func_800D9078((f32 *)((u8 *)arg0 + 0x58))) {
            func_80101FDC(arg0, 1);
        }
        break;
    case 4:
        if (func_8010D23C() && func_8010C500(arg0) && (func_8008FDC4() & 0x08000000)) {
            _capod_entrypoint_13(*(s32 *)arg0, 0, 0xC, 0x30);
            func_80101FDC(arg0, 6);
            ((u8 *)arg0)[0x65] &= ~0x10;
            *(f32 *)((u8 *)arg0 + 0x58) = 1.0f;
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x133B, 7, position, 0xA3);
        }
        break;
    case 6:
        done6 = func_800D9078((f32 *)((u8 *)arg0 + 0x58));
        height6 = func_800F12D4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 1.0f, -200.0f, 300.0f);
        func_800EE7F8(pos6, position);
        pos6[1] += height6;
        func_800D1254(0x39, 1, pos6);
        if (!((RobotFlags *)arg0)->sounded && *(f32 *)((u8 *)arg0 + 0x58) < 0.7f) {
            _subaddieaudioquick_entrypoint_2((s32)arg0, (s32)position, &D_80802AEC_chfactoryrobot);
            ((RobotFlags *)arg0)->sounded = 1;
        }
        if (done6) {
            func_80101FDC(arg0, 9);
        }
        break;
    case 7:
        done7 = func_800D9078((f32 *)((u8 *)arg0 + 0x58));
        height7 = func_800F12D4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 1.0f, 300.0f, -200.0f);
        func_800EE7F8(pos7, position);
        pos7[1] += height7;
        func_800D1254(0x39, 1, pos7);
        if (done7) {
            func_80101FDC(arg0, 10);
            func_800DA544(0x1BB);
        }
        break;
    case 8:
        func_800D2498(0x101, data[0x13], 0);
        if (func_800D9078((f32 *)((u8 *)arg0 + 0x58))) {
            func_80101FDC(arg0, 9);
        }
        break;
    case 9:
        func_800D2498(0x101, data[0x13], 0);
        if (data[0x10] < func_800F1418(data[0x11], data[0x13]) && data[0x14] == 0) {
            func_80108B04(arg0, 0);
            func_80101FDC(arg0, 8);
            *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(1.5f, 2.5f);
        }
        break;
    case 3:
    case 5:
    case 10:
        break;
    }
    data[0x14] = 0;
}

/* extern */

void func_8080219C_chfactoryrobot(void *arg0) {
    s32 func_800E8C08(s32, u8, void *);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x28)));
    if (temp_a1 != 0) {
        func_800E8C08(temp_a1 & 0xFF, temp_a1, arg0);
        (*(u8 *)((s8 *)(arg0) + (0x28))) = 0U;
    }
}

/* extern */

void func_808021D4_chfactoryrobot(void *arg0, s32 arg1) {
    u8 func_800D731C(u16);
    s32 func_800DBE60(u8, s32, s32);
    s32 func_800E8C58(u8);
    s32 func_801015D0();
    u8 sp1F;
    s32 sp18;
    s32 temp_v0_2;
    u8 temp_v0;

    func_801015D0();
    temp_v0 = func_800D731C((*(u16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0)))) + (0x14))));
    sp1F = temp_v0;
    if (temp_v0 != 0) {
        temp_v0_2 = func_800E8C58((*(u8 *)((s8 *)(arg0) + (0x28))));
        sp18 = temp_v0_2;
        func_800DBE60(sp1F, 0, temp_v0_2);
        func_800DBE60(sp1F, 1, sp18);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80802240_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80802398_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80802470_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_808025D4_chfactoryrobot.s")
