#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/skeleton/subaddieskeleton_entrypoint_0.s")

/* extern */

void subaddieskeleton_entrypoint_1(Unk80132ED0 **arg0, s32 arg1, s32 arg2) {
    void func_800DBEFC(s32 *, s32, s32);
    void *data = (*arg0)->unk4;
    func_800DBEFC(data, arg1, arg2);
}

s32 subaddieskeleton_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    Actor *func_80106790(Unk80132ED0 *);
    void *subaddieskeleton_entrypoint_4(Actor *);
    void func_800DBEFC(s32 *, s32, s32);
    Actor *actor;
    void *data;

    actor = func_80106790(arg0);
    if (actor->unk7C_12) {
        data = subaddieskeleton_entrypoint_4(actor);
        if (data != NULL) {
            func_800DBEFC(data, arg1, arg2);
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/skeleton/subaddieskeleton_entrypoint_3.s")

/* extern */

void *subaddieskeleton_entrypoint_4(Actor *arg0) {
    s32 func_80102F74(Actor *, s32);
    OSThread *func_80104130(void);
    void *var_v1;

    var_v1 = arg0->unk0->unk4;
    if (var_v1 != 0) {
        return var_v1;
    } else {
        if (func_80102F74(arg0, 2) != 0) {
            var_v1 = func_80104130();
        } else {
            var_v1 = 0;
        }
    }
    return var_v1;
}
