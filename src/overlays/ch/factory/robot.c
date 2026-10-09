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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80800DC4_chfactoryrobot.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801D08_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80801D7C_chfactoryrobot.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_808021D4_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80802240_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80802398_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_80802470_chfactoryrobot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/robot/func_808025D4_chfactoryrobot.s")
