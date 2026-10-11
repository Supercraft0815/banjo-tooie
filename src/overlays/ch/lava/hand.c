#include "common.h"

void func_80800000_chlavahand(void *arg0) {
    struct Flags {
        u8 pad0 : 7;
        u8 flag0 : 1;
        u8 pad1 : 7;
        u8 flag1 : 1;
    };
    ((struct Flags *)((u8 *)arg0 + 0x64))->flag0 = 1;
    ((struct Flags *)((u8 *)arg0 + 0x64))->flag1 = 0;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x38)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800024_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800124_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800910_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800A30_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800AAC_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800D8C_chlavahand.s")

OSThread *chlavahand_entrypoint_0(void)
{
    extern u8 D_808013D0_chlavahand[];

    return (OSThread *) D_808013D0_chlavahand;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800E0C_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_80800FB4_chlavahand.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/hand/func_808011BC_chlavahand.s")

OSThread *chlavahand_entrypoint_1(void)
{
    extern u8 D_80801418_chlavahand[];

    return (OSThread *) D_80801418_chlavahand;
}
