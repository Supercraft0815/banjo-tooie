#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/subaddiestore_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/subaddiestore_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800260_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800330_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_808003AC_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_808004FC_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800AD8_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800B24_subaddiestore.s")

s32 func_80800F98_subaddiestore(u8 *arg0) {
    s32 var_v1;
    for (var_v1 = 0; var_v1 < 3; var_v1++) {
        if (((s16 *)(arg0 + 0x82))[var_v1] != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800FD0_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80801054_subaddiestore.s")
