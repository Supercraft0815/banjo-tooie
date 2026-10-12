#include "common.h"

s32 gldialog_entrypoint_0(void) {
    return 0;
}

int gldialog_entrypoint_1(u8 *arg0) {
    return (arg0[0] == 0xFD) && (arg0[1] == 0x6A);
}

void gldialog_entrypoint_2(void) {
    extern u32 D_801275E0[];
    u32 *p = D_801275E0;
    p += 8;
    p[0] = 0;
    p[1] = -1;
}

void gldialog_entrypoint_3(void) {
}

s32 gldialog_entrypoint_4(s32 arg0) {
    extern u32 D_801275E0[];
    s32 func_800D674C(s32);
    void func_800D70D0(s32);
    void func_800D71F4(s32);
    u8 *temp_v1_2;
    register s32 value;
    register s32 temp_v0;

    D_801275E0[8] = func_800D674C(arg0);
    func_800D70D0(1);
    func_800D71F4(1);
    temp_v1_2 = (u8 *)D_801275E0[8];
    temp_v1_2++;
    temp_v1_2 += gldialog_entrypoint_0() * 2;
    value = *temp_v1_2++;
    value += *temp_v1_2++ << 8;
    temp_v0 = D_801275E0[8] + value;
    D_801275E0[9] = arg0;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dialog/gldialog_entrypoint_5.s")
