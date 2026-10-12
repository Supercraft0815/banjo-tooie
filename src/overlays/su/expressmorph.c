#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/func_80800000_suexpressmorph.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/func_808000EC_suexpressmorph.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/func_808002BC_suexpressmorph.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_2.s")

/* extern */

void suexpressmorph_entrypoint_3(s16 *arg0, s16 arg1) {
    s16 func_80800000_suexpressmorph(s16);
    *arg0 = arg1;
    arg0[1] = func_80800000_suexpressmorph(*arg0);
}

void suexpressmorph_entrypoint_4(s8 *arg0, s32 arg1) {
    arg0[6] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_5.s")
