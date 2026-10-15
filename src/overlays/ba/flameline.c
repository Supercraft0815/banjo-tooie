#include "common.h"

s32 baflameline_entrypoint_0() 
{
    return 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/func_80800184_baflameline.s")

/* extern */

void baflameline_entrypoint_2(void *arg0) {
    s32 func_800B5450(s32, void *);
    s32 func_800C2FDC(u8, void *);
    s32 func_800C8B84(s32, void *);
    s32 temp_a0;
    void *var_v0;

    func_800C2FDC((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x84)))) + (0x20))), arg0);
    var_v0 = (*(void **)((s8 *)(arg0) + (0x84)));
    temp_a0 = (*(s32 *)((s8 *)(var_v0) + (0x24)));
    if (temp_a0 != 0) {
        func_800C8B84(temp_a0, arg0);
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x84)))) + (0x24))) = 0;
        var_v0 = (*(void **)((s8 *)(arg0) + (0x84)));
    }
    func_800B5450((*(s32 *)((s8 *)(var_v0) + (0x1C))), arg0);
}

void baflameline_entrypoint_3(u8 *arg0) {
    s32 func_800B53A4(s32);
    s32 func_800B5534(s32);
    s32 func_800BF8E4();
    s8 func_800C4350(s32, s32, s32 *);
    s32 func_800C8A98();
    s32 func_800C8F64(s32, s32);
    s32 func_800C8FE0(s32, s32);
    s32 func_800EFD24(u8 *);
    extern s32 D_80800784_baflameline;
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0x84))));
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0x84))) + 0xC);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x18))) = 1.0f;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x1C))) = func_800B53A4(0x28);
    func_800B5534((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x1C))));
    if (func_800BF8E4() > 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))) = func_800C8A98();
        func_800C8F64((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))), 0xB);
        func_800C8FE0((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))), 0);
    } else {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x24))) = 0;
    }
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x84)))) + (0x20))) = func_800C4350(0, 0, &D_80800784_baflameline);
}

/* extern */

void baflameline_entrypoint_4(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))));
}

/* extern */

void baflameline_entrypoint_5(void *arg0) {
    s32 func_800EE7F8(s32);
    s32 func_800EF2A0(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);
    func_800EF2A0((*(s32 *)((s8 *)(arg0) + (0x84))) + 0xC);
}

void baflameline_entrypoint_6(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 132) + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flameline/baflameline_entrypoint_7.s")
