#include "common.h"

u8 *func_80800000_fxfontstring(u8 *arg0) {
    if (*arg0 != 0) {
        do {
            arg0++;
        } while (*arg0 != 0);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/fontstring/fxfontstring_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/fontstring/fxfontstring_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/fontstring/fxfontstring_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/fontstring/fxfontstring_entrypoint_3.s")
