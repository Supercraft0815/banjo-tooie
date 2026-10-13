#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/skeleton/subaddieskeleton_entrypoint_0.s")

/* extern */

void subaddieskeleton_entrypoint_1(void **arg0) {
    s32 func_800DBEFC(s32);
    func_800DBEFC((*(s32 *)((s8 *)(*arg0) + (4))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/skeleton/subaddieskeleton_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/skeleton/subaddieskeleton_entrypoint_3.s")

/* extern */

s32 subaddieskeleton_entrypoint_4(Unk80132ED0 *arg0) {
    s32 func_80102F74(Unk80132ED0 *, s32);
    OSThread *func_80104130(void);
    s32 var_v1;

    var_v1 = arg0->unk0[1];
    if (var_v1 != 0) {
        return var_v1;
    } else {
        if (func_80102F74(arg0, 2) != 0) {
            var_v1 = (s32)func_80104130();
        } else {
            var_v1 = 0;
        }
    }
    return var_v1;
}
