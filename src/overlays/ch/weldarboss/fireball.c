#include "common.h"

OSThread *chweldarbossfireball_entrypoint_0(void)
{
    extern u8 D_80800410_chweldarbossfireball[];

    return (OSThread *) D_80800410_chweldarbossfireball;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_8080000C_chweldarbossfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_808000C4_chweldarbossfireball.s")

void func_8080017C_chweldarbossfireball(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x34)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_808001B4_chweldarbossfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_80800214_chweldarbossfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_80800284_chweldarbossfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fireball/func_808002E0_chweldarbossfireball.s")

void func_80800404_chweldarbossfireball(s32 arg0) {
}
