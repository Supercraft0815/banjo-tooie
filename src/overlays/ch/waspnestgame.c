#include "common.h"

OSThread *chwaspnestgame_entrypoint_0(void)
{
    extern u8 D_80801F80_chwaspnestgame[];

    return (OSThread *) D_80801F80_chwaspnestgame;
}

OSThread *chwaspnestgame_entrypoint_1(void)
{
    extern u8 D_80801FC8_chwaspnestgame[];

    return (OSThread *) D_80801FC8_chwaspnestgame;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800018_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_808002EC_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800400_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_8080047C_chwaspnestgame.s")

s32 func_80800724_chwaspnestgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    void func_80800018_chwaspnestgame(Actor *, s32);
    void func_80800B80_chwaspnestgame(Actor *);
    void func_80800C7C_chwaspnestgame(Actor *, s32);
    void func_80800D7C_chwaspnestgame(Actor *, s32);
    s32 func_80800DE4_chwaspnestgame(Actor *, s32);
    s32 func_80800EB8_chwaspnestgame(void *, s32, s32);
    void func_80800F98_chwaspnestgame(Actor *, s32, s32);
    extern s16 D_80801F76_chwaspnestgame[];
    u8 *sp34;
    s32 sp30;
    s16 *sp2C;
    s32 sp28;

    sp34 = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x95:
            if ((func_800D0A9C(0x4B, 1) && !func_800D0B68(0x4B, 1)) ||
                (func_800D0A9C(0x18, 4) && !func_800D0B68(0x18, 4))) {
                *(f32 *)((u8 *)arg0 + 0x58) = 0.5f;
                func_80101FDC(arg0, 5);
            } else {
                func_80090708(2);
                if (func_800D395C()) {
                    _susubgame_entrypoint_5(arg0, sp34 + 0x24, 5, 1, 0);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x144D, 6, 0, 0x99);
                } else if (func_800DA298(0x6E6)) {
                    _susubgame_entrypoint_5(arg0, sp34 + 0x24, 5, 1, 0);
                    sp28 = !func_800D0A9C(0x4B, 1);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, -!func_800D0A9C(0x18, 4) - sp28 + 0x144B, 6, 0, 0x99);
                } else {
                    _susubgame_entrypoint_6(arg0, sp34 + 0x24, 8, 0x20, 0);
                    sp28 = !func_800D0A9C(0x4B, 1);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, -!func_800D0A9C(0x18, 4) - sp28 + 0x1407, 6, 0, 0x99);
                    func_800DA544(0);
                    func_80108B04(arg0, 0);
                }
                func_80800018_chwaspnestgame(arg0, 1);
            }
            break;
        case 0x3D:
            if (arg2 > 0) {
                func_80800C7C_chwaspnestgame(arg0, arg2);
            } else if (arg2 < 0) {
                func_80800D7C_chwaspnestgame(arg0, -arg2);
            } else {
                func_80800B80_chwaspnestgame(arg0);
            }
            break;
        case 0x2E:
            sp2C = (s16 *)&arg2;
            func_80800F98_chwaspnestgame(arg0, sp2C[0], sp2C[1]);
            break;
        case 0x30:
            sp2C = (s16 *)&arg2;
            return func_80800EB8_chwaspnestgame(arg0, sp2C[0], sp2C[1]);
        case 0x2F:
            sp2C = (s16 *)&arg2;
            sp30 = sp2C[1];
            func_80101180(0x1E4, 0x45, 0);
            _susubgame_entrypoint_6(arg0, sp34 + 0x24, D_80801F76_chwaspnestgame[sp30], 0x20, 0);
            func_80108B04(arg0, -sp30);
            break;
        case 0xB:
            return func_80800DE4_chwaspnestgame(arg0, arg2);
        case 0x57:
            return _susubgame_entrypoint_3(arg0, sp34 + 0x24, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            func_80101180(0x1E4, 0x45, 0);
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xCEB, 0x46, 0, 0x99);
            func_80101FDC(arg0, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800AF8_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800B80_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800C00_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800C7C_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800D7C_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800DE4_chwaspnestgame.s")

s32 func_80800EB8_chwaspnestgame(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800D211C(s32);

    switch (arg1) {
        case 0x1405:
        case 0x1449:
            return arg2 ? 0x32 : 0x28;
        case 0x1406:
        case 0x144A:
            return 0x32;
        case 0x1409:
            return 0x3C;
        case 0x140E:
        case 0x144C:
            return *(s32 *)((u8 *)arg0 + 0x24);
        case 0x140F:
        case 0x1450:
            if (arg2 == 0) {
                return *(s32 *)((u8 *)arg0 + 0x24);
            }
        default:
            return func_800D211C(0x87);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800F98_chwaspnestgame.s")

/* extern */

void func_80801260_chwaspnestgame(Unk80132ED0 *arg0, s32 arg1) {
    void *func_80106790();
    void *temp_v0;

    temp_v0 = func_80106790(arg0);
    (*(s32 *)((s8 *)(temp_v0) + (0x24))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x24))) + arg1);
    (*(s32 *)((s8 *)(temp_v0) + (0x34))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x34))) - 1);
}

/* extern */

void func_8080129C_chwaspnestgame(void) {
    void *func_80106790();
    void *temp_v0;

    temp_v0 = func_80106790();
    (*(s32 *)((s8 *)(temp_v0) + (0x34))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x34))) - 1);
}

void func_808012C8_chwaspnestgame(s32 arg0) 
{
}
/* extern */

void func_808012D0_chwaspnestgame(void *arg0) {
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 func_8010D600(s32 *);
    s32 sp1C[3];

    func_8010D600(sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80102D78(arg0, sp1C);
    func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x43340000);
    func_808012C8_chwaspnestgame((s32) arg0);
}

void func_80801324_chwaspnestgame(f32 *arg0, f32 arg1, f32 arg2) {
    void func_800EF334(f32 vec[3], f32 scale);
    if (arg1 != 0.0f) {
        func_800EF334(arg0, arg2 / arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801364_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_808014BC_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801590_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_808017DC_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801880_chwaspnestgame.s")

/* extern */

void func_80801954_chwaspnestgame(s32 arg0) {
    s32 func_800DA298(s32);
    f32 func_800EEB40(s32, s32);
    s32 func_8010A570(s32);
    s32 func_80801364_chwaspnestgame(s32, s32);
    if (func_800EEB40(arg0 + 0x18, arg0 + 4) > 1.0f) {
        func_80801364_chwaspnestgame(arg0, 2);
    } else {
        func_80801364_chwaspnestgame(arg0, 1);
    }
    if (func_800DA298(0) != 0) {
        func_8010A570(arg0);
    }
}

/* extern */

void func_808019D4_chwaspnestgame(Actor *arg0) {
    s32 func_8010DCB4(s32);
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    if ((temp_t6 == 2) || (temp_t6 == 5)) {
        func_8010DCB4(0xA);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801A10_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801B9C_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801CE4_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801D28_chwaspnestgame.s")
