#include "common.h"

OSThread *chlightdemon_entrypoint_0(void)
{
    extern u8 D_80800140_chlightdemon[];

    return (OSThread *) D_80800140_chlightdemon;
}

/* extern */

void func_8080000C_chlightdemon(u8 *arg0) {
    s32 func_800C8CB8(s32, u8 *, u8 *);
    s32 func_80105834();
    func_80105834();
    func_800C8CB8((*(s32 *)((s8 *)(arg0) + (0x28))), arg0 + 4, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/demon/func_8080003C_chlightdemon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/demon/func_80800060_chlightdemon.s")

/* extern */

void func_808000D8_chlightdemon(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F581C(s32);
    s32 func_800F796C(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F581C(temp_v0) & 0x08000000) {
        func_800F796C(sp1C, 3);
    }
}

OSThread *chlightdemon_entrypoint_1(void)
{
    extern u8 D_8080019C_chlightdemon[];

    return (OSThread *) D_8080019C_chlightdemon;
}
