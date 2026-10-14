#include "common.h"

s32 sucoasterdata_entrypoint_0(void **arg0) { extern s32 D_808003C0_sucoasterdata; extern s32 D_8080041C_sucoasterdata; u8 *var_a0; s32 var_v1; u32 temp_t7; temp_t7 = *(u32 *)((u8 *)*arg0 + 0x24) >> 22; var_v1 = 1; if (temp_t7 == *(u16 *)&D_808003C0_sucoasterdata) { return 0; } var_a0 = (u8 *)&D_8080041C_sucoasterdata; loop_3: if (temp_t7 == *(u16 *)var_a0) { return var_v1; } if (temp_t7 == *(u16 *)(var_a0 + 0x5C)) { return var_v1 + 1; } if (temp_t7 == *(u16 *)(var_a0 + 0xB8)) { return var_v1 + 2; } if (temp_t7 == *(u16 *)(var_a0 + 0x114)) { return var_v1 + 3; } var_v1 += 4; var_a0 += 0x170; if (var_v1 == 9) { return 0; } goto loop_3; }

void *sucoasterdata_entrypoint_1(s32 arg0) {
    extern s32 D_808003C0_sucoasterdata;
    return (u8 *)&D_808003C0_sucoasterdata + arg0 * 0x5C;
}

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

s32 sucoasterdata_entrypoint_3(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0xF0;
    case 1:
        return 0xD2;
    case 2:
        return 0xB4;
    case 3:
        return 0x12C;
    case 4:
        return 0x78;
    case 5:
        return 0x12C;
    case 6:
        return 0xC8;
    case 7:
        return 0xAA;
    case 8:
        return 0xC8;
    default:
        return 0;
    }
}

s32 sucoasterdata_entrypoint_4(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0x140;
    case 1:
        return 0x12C;
    case 2:
        return 0x154;
    case 3:
        return 0x168;
    case 4:
        return 0x190;
    case 5:
        return 0x17C;
    case 6:
        return 0x1A4;
    case 7:
        return 0x1B8;
    case 8:
        return 0x1CC;
    default:
        return 0;
    }
}

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
