#include "common.h"

s32 sucoasterflydata_entrypoint_0(void **arg0) {
    extern s32 D_80800290_sucoasterflydata;
    u32 id;
    s32 i;

    id = *(u32 *)((u8 *)*arg0 + 0x24) >> 22;
    for (i = 0; i < 5; i++) {
        if (id == *(u16 *)((u8 *)&D_80800290_sucoasterflydata + i * 0x28)) {
            return i;
        }
    }
    return 0;
}

void *sucoasterflydata_entrypoint_1(s32 arg0) {
    extern s32 D_80800290_sucoasterflydata;
    return (void *) ((arg0 * 5) * 8 + (u8 *) &D_80800290_sucoasterflydata);
}

s32 *sucoasterflydata_entrypoint_2(u32 arg0, s32 *arg1) {
    extern s32 D_80800358_sucoasterflydata;
    extern s32 D_808003AC_sucoasterflydata;
    extern s32 D_808003F4_sucoasterflydata;
    extern s32 D_8080043C_sucoasterflydata;
    switch (arg0) {
    case 0:
        *arg1 = 7;
        return &D_80800358_sucoasterflydata;
    case 1:
    case 2:
        *arg1 = 6;
        return &D_808003AC_sucoasterflydata;
    case 3:
        *arg1 = 6;
        return &D_808003F4_sucoasterflydata;
    case 4:
        *arg1 = 6;
        return &D_8080043C_sucoasterflydata;
    default:
        *arg1 = 0;
        return NULL;
    }
}

s32 sucoasterflydata_entrypoint_3(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x12C;
    case 1:
        return 0xFA;
    case 2:
        return 0xFA;
    case 3:
        return 0x12C;
    case 4:
        return 0x12C;
    default:
        return 0;
    }
}

s32 sucoasterflydata_entrypoint_4(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x190;
    case 1:
        return 0x12C;
    case 2:
        return 0x12C;
    case 3:
        return 0x190;
    case 4:
        return 0x190;
    default:
        return 0;
    }
}

s32 sucoasterflydata_entrypoint_5(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x320;
    case 1:
        return 0x258;
    case 2:
        return 0x258;
    case 3:
        return 0x4B0;
    case 4:
        return 0x3E8;
    default:
        return 0;
    }
}
