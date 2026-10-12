#include "common.h"

void subaddieaudioloop_entrypoint_0(u8 *arg0, f32 arg1) {
    void func_800C31DC(u8 id, f32);
    if (arg0[0x5F] != 0) {
        func_800C31DC(arg0[0x5F], arg1);
    }
}

/* extern */

void subaddieaudioloop_entrypoint_1(u8 *arg0, s32 sample_rate) {
    void func_800C3058(u8, s32);

    if (arg0[0x5F] != 0) {
        func_800C3058(arg0[0x5F], sample_rate);
    }
}

/* extern */

void subaddieaudioloop_entrypoint_2(void *arg0) {
    u8 subaddieaudioloop_entrypoint_3(u8);
    (*(u8 *)((s8 *)(arg0) + (0x5F))) = subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x5F))));
}

u8 subaddieaudioloop_entrypoint_3(u8 arg0) {
    s32 func_800C2FDC(u8 id);
    if (arg0 != 0) {
        func_800C2FDC(arg0);
        arg0 = 0;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioloop/subaddieaudioloop_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioloop/subaddieaudioloop_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioloop/subaddieaudioloop_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioloop/subaddieaudioloop_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioloop/subaddieaudioloop_entrypoint_8.s")
