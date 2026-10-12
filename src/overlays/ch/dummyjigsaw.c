#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dummyjigsaw/func_80800000_chdummyjigsaw.s")

/* extern */

s32 func_80800128_chdummyjigsaw(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFA88(Unk80132ED0 *);
    if ((arg1 == 0x3E) && arg0->unk64_20) {
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}

OSThread *chdummyjigsaw_entrypoint_0(void)
{
    extern u8 D_80800190_chdummyjigsaw[];

    return (OSThread *) D_80800190_chdummyjigsaw;
}
