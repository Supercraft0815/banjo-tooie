#include "common.h"

s32 gldialog_entrypoint_0(void) {
    return BT_NATIVE_ONLY(bt_language() +) 0;
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

BtIntPtr gldialog_entrypoint_4(s32 arg0) {
    extern u32 D_801275E0[];
    BtIntPtr func_800D674C(s32);
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

void gldialog_entrypoint_5(volatile s32 arg0) {
    s32 func_800D6CEC(s32);
    s32 func_800D70F8(s32, s32);
    s32 func_800D721C(s32, s32);
    extern u32 D_801275E0[];
    extern u32 D_80127600[];
    u32 *p;
    func_800D721C(D_801275E0[9], 0);
    func_800D70F8(D_801275E0[9], 0);
    func_800D6CEC(D_801275E0[9]);
    p = D_80127600;
    p[0] = 0;
    p[1] = -1;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u32 D_801275E0 [ 2 ] BT_DATA(4, bss_core2bss1_0_1, 0x580);
u32 D_80127600 [ 3 ] BT_DATA(4, bss_core2bss1_0_1, 0x5A0);
#endif
