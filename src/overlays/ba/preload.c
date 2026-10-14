#include "common.h"

void func_80800000_bapreload(void *arg0, s32 arg1, s16 *arg2, s16 *arg3) {
    s32 func_800A940C(s32);
    s32 func_800EA068(s32);
    extern s32 D_808002F0_bapreload;
    extern s32 D_80800300_bapreload;
    extern s32 D_80800310_bapreload;
    extern s32 D_80800320_bapreload;
    struct PreloadEntry { s16 first; s16 second; };
    struct PreloadEntry *table;
    s32 index;

    switch (arg1) {
    case 6:
        table = (void *)&D_80800310_bapreload;
        break;
    case 12:
        table = (void *)&D_80800320_bapreload;
        break;
    case 11:
        table = (void *)&D_80800300_bapreload;
        break;
    case 1:
        table = (void *)&D_808002F0_bapreload;
        break;
    case 17:
        *arg2 = 0x60E;
        *arg3 = 0;
        return;
    default:
        *arg2 = 0x607;
        *arg3 = 0;
        return;
    }
    if (func_800EA068(0x20) != 0) {
        index = func_800A940C(*(s32 *)((s8 *)arg0 + 0x184));
    } else {
        index = *(s32 *)((s8 *)arg0 + 0x184);
    }
    table += index;
    *arg2 = table->first;
    *arg3 = table->second;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/preload/bapreload_entrypoint_0.s")

s32 bapreload_entrypoint_1(s32 arg0, s32 *arg1) {
    s32 func_8009EA2C(void);
    extern s16 D_808002A2_bapreload;
    s32 var_v1;

    var_v1 = *(s16 *)((s32)&D_808002A2_bapreload + arg0 * 4);
    *arg1 = 0;
    switch (arg0) {
    case 0xB:
        if (func_8009EA2C() != 0) {
            var_v1 = 0x62E;
        }
        break;
    case 1:
    case 0xA:
        if (func_8009EA2C() != 0) {
            *arg1 = 1;
        }
        break;
    }
    return var_v1;
}
