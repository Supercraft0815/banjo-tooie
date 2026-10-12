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

s32 vpmodule_entrypoint_4(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u32 temp_t0;
    u32 var_v1;

    var_v1 = arg0 + 8;
    temp_t0 = ((*(s32 *)((s8 *)(arg1) + (0x2C))) * 8) + arg0 + 8;
    while (var_v1 < temp_t0) {
        s32 *record = (s32 *)(((s32 *)(arg1 + 0x30))[*(s16 *)(var_v1 + 2)] + arg1);
        if (arg2 == *record) {
            (*(s8 *)((s8 *)(var_v1) + (1))) = arg3;
            return 1;
        }
        var_v1 += 8;
    }
    return 0;
}
