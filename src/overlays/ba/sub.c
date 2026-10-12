#include "common.h"

s32 basub_entrypoint_0() 
{
    return 0x6C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/func_80800008_basub.s")

/* extern */

void func_808000CC_basub(u8 *arg0) {
    s32 func_80800008_basub(s32, s32);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x130)))) + (0x58))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x130)))) + (0x5E))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x130)))) + (0x54))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x130)))) + (0x5D))) = 0;
    func_80800008_basub((s32)arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/func_80800110_basub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/func_80800254_basub.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/func_80800358_basub.s")

/* extern */

void func_80800458_basub(void *arg0, s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    s32 temp_a0;
    s32 var_s0;

    var_s0 = 0;
    do {
        temp_a0 = (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x130))) + var_s0)) + (0x2C)));
        if (temp_a0 != 0) {
            func_8010114C(temp_a0, arg1, (*(s32 *)((s8 *)(arg0) + (0x184))));
        }
        var_s0 += 4;
    } while (var_s0 != 0x28);
}

void func_808004C8_basub(u8 *arg0) {
    s32 i;

    for (i = 0; i < 10; i++) {
        (*(s32 **)(arg0 + 0x130))[i + 11] = 0;
    }
    (*(s32 **)(arg0 + 0x130))[10] = 0;
}

void basub_entrypoint_1(s32 arg0)
{
    func_80800458_basub(arg0,0x5);
}

f32 basub_entrypoint_2(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x130)));
    if ((*(f32 *)((s8 *)(temp_v0) + (4))) > 0.0f) {
        return (*(f32 *)((s8 *)(temp_v0) + (0)));
    }
    return 0.0f;
}

void basub_entrypoint_3(u8 *arg0, f32 arg1, f32 arg2) {
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x130)));
    if (!((*(f32 *)((s8 *)(temp_v0) + (4))) > 0.0f)) {
        (*(f32 *)((s8 *)(temp_v0) + (0))) = arg1;
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x130)))) + (4))) = arg2;
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x130)));
        (*(f32 *)((s8 *)(temp_v0) + (8))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (4)));
    }
}

/* extern */

void basub_entrypoint_4(void) {
    s32 _chping_entrypoint_0(s32);
    void *func_800F53D0();
    _chping_entrypoint_0((*(s32 *)((s8 *)(func_800F53D0()) + (0x184))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/basub_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/basub_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/basub_entrypoint_7.s")

void basub_entrypoint_8(void *arg0, s32 arg1) {
    u8 temp_v1;
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x130)));
    temp_v1 = (*(u8 *)((s8 *)(temp_v0) + (0x5E)));
    if (((*(s32 *)((s8 *)(temp_v0) + (0x28))) + temp_v1) < 0xA) {
        (*(u8 *)((s8 *)(temp_v0) + (0x5E))) = (u8) (temp_v1 + 1);
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x58))) = 0.35f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/func_80800834_basub.s")

/* extern */

void basub_entrypoint_9(void *arg0) {
    s32 _bawobble_entrypoint_2(void *);
    s32 func_800C2FDC(u8);
    func_80800458_basub(arg0, 0x2C);
    func_800C2FDC((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0xC))));
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0xC))) = 0;
    _bawobble_entrypoint_2(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/basub_entrypoint_10.s")

void basub_entrypoint_11(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 304) + 16) = arg1;
}

void basub_entrypoint_12(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 304) + 24) = arg1;
}

void basub_entrypoint_13(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 304) + 36) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sub/basub_entrypoint_14.s")

void basub_entrypoint_15(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x68))) = 3000.0f;
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x5F))) = 6;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x60))) = 0.8f;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x64))) = 0.28f;
        return;
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x68))) = 1500.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x5F))) = 3;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x60))) = 0.8f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x64))) = 0.28f;
}
