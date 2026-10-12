#include "common.h"

/* extern */

void gcsectionDll_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _gclevel_entrypoint_2();
    s32 _gcstatusDll_entrypoint_11();
    s32 func_8001A578(s32);
    s32 func_800A13B0(s32);
    s32 func_800F9178();
    s32 gcsectionDll_entrypoint_2(s32);
    s32 gcsectionDll_entrypoint_3(s32, s32);
    s32 temp_v0;

    temp_v0 = _gclevel_entrypoint_2();
    if ((temp_v0 >= 0xF) && (temp_v0 < 0x20)) {
        if (gcsectionDll_entrypoint_3(gcsectionDll_entrypoint_2(arg0), 0x20) != 0) {
            func_8001A578(_gcstatusDll_entrypoint_11());
        } else if (arg0 == 0x189) {
            func_8001A578(0);
        }
        func_800F9178();
        func_800A13B0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionDll/gcsectionDll_entrypoint_1.s")

s16 *func_808000F0_gcsectionDll(s32 arg0, s32 arg1) {
    extern s16 D_80800212_gcsectionDll[][3];
    s16 *p = &D_80800212_gcsectionDll[0][2];
    while (*p != 0) {
        if (arg0 == *p) return p;
        p += 3;
    }
    if (arg1 != 0) return NULL;
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/sectionDll/gcsectionDll_entrypoint_2.s")

s32 gcsectionDll_entrypoint_3(s32 arg0, s32 arg1) {
    extern s16 D_80800212_gcsectionDll[][3];
    return (D_80800212_gcsectionDll[arg0][0] & arg1) ? 1 : 0;
}

u8 gcsectionDll_entrypoint_4(s32 arg0) {
    return (*(u8 *)((s8 *)(func_808000F0_gcsectionDll(arg0, 0)) + (4)));
}

/* extern */

s32 gcsectionDll_entrypoint_5(s32 arg0) {
    if (func_808000F0_gcsectionDll(arg0, 1) != 0) {
        return 1;
    }
    return 0;
}
