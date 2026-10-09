#include "common.h"

s32 basnowball_entrypoint_0() 
{
    return 0x30;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_80800008_basnowball.s")

f32 func_80800084_basnowball(s32 arg0) {
    extern f32 D_80801020_basnowball[];
    return ((f32 *)&D_80801020_basnowball)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_80800098_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_808000C0_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_80800110_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_80800150_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_808001B8_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_2.s")

f32 basnowball_entrypoint_3(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 272) + 8);
}

f32 basnowball_entrypoint_4(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 272) + 28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_5.s")

/* extern */

s32 basnowball_entrypoint_6(void) {
    s32 func_800A1718();
    return func_800A1718() >= 5;
}

void basnowball_entrypoint_7(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x110)))) + (0x2C))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_8.s")

void basnowball_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 272) + 12) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_808007CC_basnowball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/func_8080099C_basnowball.s")

void basnowball_entrypoint_11(s32 arg0)
{
    func_800F796C(arg0,0x3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/snowll/basnowball_entrypoint_12.s")
