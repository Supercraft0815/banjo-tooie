#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/multi/subaddiemulti_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/multi/subaddiemulti_entrypoint_1.s")

/* extern */

void subaddiemulti_entrypoint_2(void) {
    s32 func_800F6438(s32);
    s32 func_800F82D4(s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_800F82D4(var_s0, 0);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/multi/subaddiemulti_entrypoint_3.s")

/* extern */

void subaddiemulti_entrypoint_4(s32 arg0) {
    s32 func_800F5EF8(s32);
    s32 func_800F6438(s32);
    s32 _ncfixposrot_entrypoint_8(s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            _ncfixposrot_entrypoint_8(func_800F5EF8(var_s0), arg0);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/multi/subaddiemulti_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/multi/subaddiemulti_entrypoint_6.s")
