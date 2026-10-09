#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/falldie/func_80800000_bsdronefalldie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/falldie/bsdronefalldie_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/falldie/bsdronefalldie_entrypoint_1.s")

/* extern */

void bsdronefalldie_entrypoint_2(s32 arg0) {
    s32 func_80099AA8(s32);
    s32 func_8009E6EC();
    if (func_8009E6EC() != 0x91) {
        func_80099AA8(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/falldie/bsdronefalldie_entrypoint_3.s")
