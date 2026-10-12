#include "common.h"

u8 *func_80800000_fxfontstring(u8 *arg0) {
    if (*arg0 != 0) {
        do {
            arg0++;
        } while (*arg0 != 0);
    }
    return arg0;
}

/* extern */

void fxfontstring_entrypoint_0(u8 *arg0, s32 arg1) { u8 *p; p = func_80800000_fxfontstring(arg0); *p++ = 0xFD; if (arg1 != 0) { *p = 0x68; } else { *p = 0x6C; } p++; *p = 0; }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/fontstring/fxfontstring_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/fontstring/fxfontstring_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/fontstring/fxfontstring_entrypoint_3.s")
