#include "common.h"

s32 func_80800000_suexpressmorph(s32 arg0) {
    extern s16 D_80801324_suexpressmorph;
    extern s32 D_8080132C_suexpressmorph;
    s32 *var_v0;
    s32 var_v1;

    var_v0 = &D_8080132C_suexpressmorph;
    var_v1 = 1;
    if (arg0 == D_80801324_suexpressmorph) {
        return 0;
    }
    for (;;) {
        if (arg0 == *(s16 *)(var_v0 + 1)) return var_v1;
        if (arg0 == *(s16 *)(var_v0 + 4)) return var_v1 + 1;
        if (arg0 == *(s16 *)(var_v0 + 7)) return var_v1 + 2;
        if (arg0 == *(s16 *)(var_v0 + 10)) return var_v1 + 3;
        var_v1 += 4;
        var_v0 += 12;
        if (var_v1 == 0x11) return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/func_808000EC_suexpressmorph.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/func_808002BC_suexpressmorph.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_2.s")

/* extern */

void suexpressmorph_entrypoint_3(s16 *arg0, s16 arg1) {
    s32 func_80800000_suexpressmorph(s32);
    *arg0 = arg1;
    arg0[1] = func_80800000_suexpressmorph(*arg0);
}

void suexpressmorph_entrypoint_4(s8 *arg0, s32 arg1) {
    arg0[6] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_5.s")
