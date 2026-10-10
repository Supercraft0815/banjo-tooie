#include "common.h"

s32 func_80800000_vpmodule(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (((arg0 >= 0x4B0) && (arg0 < 0x6A4)) || ((arg0 >= 0x834) && (arg0 < 0x898))) {
        return 1;
    }
    if ((arg0 >= 0xC8) && (arg0 < 0x12C)) {
        return 2;
    }
    if ((arg0 >= 0x1F4) && (arg0 < 0x258)) {
        return 3;
    }
    if ((arg0 >= 0x64) && (arg0 < 0xC8)) {
        return 4;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/func_808005C4_vpmodule.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_4.s")
