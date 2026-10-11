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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800724_chwaspnestgame.s")

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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_808012D0_chwaspnestgame.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_808019D4_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801A10_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801B9C_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801CE4_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801D28_chwaspnestgame.s")
