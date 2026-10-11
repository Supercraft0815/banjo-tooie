#include "common.h"

/* extern */

void func_80800000_ncpoducam(u8 *arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24(arg0 + 4);
    func_800EFD24(arg0 + 0x10);
    func_800EFD24(arg0 + 0x24);
    func_800EFD24(arg0 + 0x30);
    (*(s8 *)((s8 *)(arg0) + (0x63))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x50))) = 40.0f;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_0.s")

/* extern */

void ncpoducam_entrypoint_1(s16 arg0) {
    s32 func_8001B798(s16);
    func_8001B798(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_2.s")

void ncpoducam_entrypoint_3(void *arg0, void *arg1) {
    (*(void **)((s8 *)(arg0) + (0x1C))) = arg1;
    (*(u32 *)((s8 *)(arg0) + (0x20))) = ((u32) (*(u16 *)((u8 *)arg1 + 0x12))) >> 1;
}

void ncpoducam_entrypoint_4(s16 *arg0, s32 arg1) {
    arg0[36] = arg1;
}

s32 ncpoducam_entrypoint_5(s16 *arg0) {
    return arg0[36];
}

void func_80800160_ncpoducam(u8 *arg0) {
    s32 func_8001B754(s16);
    s16 temp_a0;
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(arg0) + (0)));
    if (temp_a1 != 0) {
        func_8001B754(temp_a1);
        (*(s16 *)((s8 *)(arg0) + (0))) = 0;
    }
    temp_a0 = (*(s16 *)((s8 *)(arg0) + (2)));
    if (temp_a0 != 0) {
        func_8001B754(temp_a0);
        (*(s16 *)((s8 *)(arg0) + (2))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_808001F0_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_8080021C_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_808003A8_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800704_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_808007D0_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800854_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800944_ncpoducam.s")

/* extern */

void func_80800A18_ncpoducam(u8 *arg0) {
    s32 _susplinet_entrypoint_17(s32);
    s32 _susplinet_entrypoint_7(s32, s32, u8 *);
    f32 _susplinet_entrypoint_8(s32, s32);
    s32 func_8001B798(s16);
    s32 temp_v0;

    temp_v0 = func_8001B798((*(s16 *)((s8 *)(arg0) + (2))));
    _susplinet_entrypoint_17(temp_v0);
    _susplinet_entrypoint_7(temp_v0, 0, arg0 + 4);
    _susplinet_entrypoint_7(temp_v0, 1, arg0 + 0x10);
    (*(f32 *)((s8 *)(arg0) + (0x50))) = _susplinet_entrypoint_8(temp_v0, 0);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = _susplinet_entrypoint_8(temp_v0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800A94_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800B74_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800CB8_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800D28_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800F64_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80801274_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_8080145C_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_10.s")

/* extern */

void ncpoducam_entrypoint_11(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x3C);
}
