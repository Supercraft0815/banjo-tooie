#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/data/sucoasterdata_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/data/sucoasterdata_entrypoint_1.s")

s32 sucoasterdata_entrypoint_2(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x3C;
    case 1:
        return 0x3C;
    case 2:
        return 0x5A;
    case 3:
        return 0x78;
    case 4:
        return 0x32;
    case 5:
        return 0x78;
    case 6:
        return 0x50;
    case 7:
        return 0x28;
    case 8:
        return 0x78;
    default:
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/data/sucoasterdata_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/data/sucoasterdata_entrypoint_4.s")

s32 *sucoasterdata_entrypoint_5(u32 arg0, s32 arg1, s32 *arg2) {
    extern s32 D_808006FC_sucoasterdata;
    extern s32 D_80800750_sucoasterdata;
    extern s32 D_808007A4_sucoasterdata;
    extern s32 D_808007F8_sucoasterdata;
    extern s32 D_8080084C_sucoasterdata;
    extern s32 D_808008A0_sucoasterdata;
    extern s32 D_808008F4_sucoasterdata;
    extern s32 D_80800948_sucoasterdata;
    extern s32 D_80800990_sucoasterdata;

    switch (arg0) {
    case 0:
        *arg2 = 7;
        return &D_8080084C_sucoasterdata;
    case 1:
        *arg2 = 7;
        return &D_80800990_sucoasterdata;
    case 3:
        switch (arg1) {
        case 0x327:
            *arg2 = 7;
            return &D_808006FC_sucoasterdata;
        case 0x328:
            *arg2 = 7;
            return &D_80800750_sucoasterdata;
        case 0x329:
            *arg2 = 7;
            return &D_808007A4_sucoasterdata;
        case 0x32A:
            *arg2 = 7;
            return &D_808007F8_sucoasterdata;
        }
        break;
    case 5:
        *arg2 = 7;
        return &D_808008A0_sucoasterdata;
    case 6:
        *arg2 = 7;
        return &D_808008F4_sucoasterdata;
    case 7:
        *arg2 = 6;
        return &D_80800948_sucoasterdata;
    }
    *arg2 = 0;
    return 0;
}
