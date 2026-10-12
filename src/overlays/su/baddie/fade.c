#include "su/baddiefade.h"

u32 subaddiefade_entrypoint_0(u8 *arg0) {
    return arg0[155];
}

void subaddiefade_entrypoint_1(void *arg0, s32 arg1) {
    (*(u8 *)((s8 *)arg0 + 0x79)) = (u8)((*(u8 *)((s8 *)arg0 + 0x79)) & 0xFFFC);
    (*(s8 *)((s8 *)arg0 + 0x9B)) = arg1;
}

void subaddiefade_entrypoint_2(void *arg0) {
    (*(s8 *)((s8 *)(arg0) + (0x9B))) = 0;
    (*(u8 *)((s8 *)(arg0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x79))) & 0xFFFC) | 1);
}

void subaddiefade_entrypoint_3(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x79))) & 0xFFFC) | 2);
}

void subaddiefade_entrypoint_4(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x79))) & 0xFFFC) | 1);
}

void subaddiefade_entrypoint_5(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x79))) & 0xFFFC) | 3);
}

void subaddiefade_entrypoint_6(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v1;
    s32 var_v1_2;

    temp_v0 = (*(u8 *)((s8 *)(arg0) + (0x9B))) + arg1;
    var_v1 = temp_v0 >= 0x100 ? 0xFF : temp_v0;
    if (var_v1 < 0) {
        (*(u8 *)((s8 *)(arg0) + (0x9B))) = 0U;
        return;
    }
    var_v1_2 = temp_v0 >= 0x100 ? 0xFF : temp_v0;
    (*(u8 *)((s8 *)(arg0) + (0x9B))) = (u8) var_v1_2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_7.s")

/* extern */

void subaddiefade_entrypoint_8(void *arg0, s32 arg1) {
    s8 func_800F0D90(s32, s32, s32);
    (*(s8 *)((s8 *)(arg0) + (0x9B))) = func_800F0D90(arg1, 0, 0xFF);
}

void subaddiefade_entrypoint_9(void *arg0, f32 *arg1) {
    s32 func_800F2EE0();
    func_800F2EE0(arg1, (u8 *)arg0 + 0x98);
}

void subaddiefade_entrypoint_10(void *arg0, f32 *arg1) {
    s32 func_800F2EFC();
    func_800F2EFC(arg1, (u8 *)arg0 + 0x98);
}

/* extern */

void subaddiefade_entrypoint_11(u8 *arg0, u8 *arg1) {
    void func_800F2F20(void *arg0, void *arg1);
    void func_80800450_subaddiefade();
    struct Flags {
        u8 padding[0x70];
        u32 upper : 29;
        u32 flag : 1;
        u32 lower : 2;
    };
    s32 sp1C[3];

    if (((struct Flags *)arg0)->flag) {
        func_80800450_subaddiefade(sp1C, arg1, arg0);
        func_800F2F20(arg0 + 0x98, sp1C);
        return;
    }
    func_800F2F20(arg0 + 0x98, arg1);
}

/* extern */

void subaddiefade_entrypoint_12(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800EFA88(void *, s32, s32, s32);
    s32 sp1C[3];

    func_800EFA88(sp1C, arg1, arg2, arg3);
    subaddiefade_entrypoint_11(arg0, (u8 *)sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_13.s")

void func_80800450_subaddiefade(s32 *arg0, u8 *arg1) {
    s32 temp_f16;

    temp_f16 = (s32) ((f32) ((*(s32 *)((s8 *)(arg1) + (0))) + (*(s32 *)((s8 *)(arg1) + (4))) + (*(s32 *)((s8 *)(arg1) + (8)))) / 3.0f);
    arg0[0] = temp_f16;
    arg0[1] = temp_f16;
    arg0[2] = temp_f16;
}

/* extern */

void subaddiefade_entrypoint_14(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800C87DC(void *, s32, s32, s32);
    s32 sp1C[3];

    func_800C87DC(sp1C, arg1, arg2, arg3);
    subaddiefade_entrypoint_11(arg0, (u8 *)sp1C);
}
