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

/* extern */

s32 subaddieaudioloop_entrypoint_4(Actor *arg0, f32 *arg1, u32 arg2, u32 *arg3) {
    u8 subaddieaudioloop_entrypoint_7(u8, f32 *, u32, u32 *, s32);
    u32 temp_v0;
    u8 id = arg0->unk5F;
    u32 flag = arg0->pad70_0;

    temp_v0 = subaddieaudioloop_entrypoint_7(id, arg1, arg2, arg3, flag & 1);
    arg0->unk5F = temp_v0;
    return arg0->unk5F != 0;
}

/* extern */

void subaddieaudioloop_entrypoint_5(Actor *arg0, f32 *arg1, u32 arg2, s32 arg3, u32 *arg4) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_8010D640(s32);
    f32 sp1C[3];

    if (arg2 != 0) {
        func_8010D640(sp1C);
        if (arg3 == -1) {
            arg3 = 0xBB8;
        }
        if ((f32) (arg3 * arg3) < func_800EEB40(sp1C, arg1)) {
            arg2 = 0;
        }
    }
    subaddieaudioloop_entrypoint_4(arg0, arg1, arg2, arg4);
}

/* extern */

void subaddieaudioloop_entrypoint_6(u8 arg0, f32 *arg1, u32 arg2, s32 arg3, u32 *arg4, s32 arg5) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_8010D640(s32);
    u8 subaddieaudioloop_entrypoint_7(u8, f32 *, u32, u32 *, s32);
    f32 sp24[3];

    if (arg2 != 0) {
        func_8010D640(sp24);
        if (arg3 == -1) {
            arg3 = 0xBB8;
        }
        if ((f32) (arg3 * arg3) < func_800EEB40(sp24, arg1)) {
            arg2 = 0;
        }
    }
    subaddieaudioloop_entrypoint_7(arg0, arg1, arg2, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioloop/subaddieaudioloop_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/audioloop/subaddieaudioloop_entrypoint_8.s")
