#include "common.h"

typedef struct {
    u8 start;
    u8 count;
    u8 unk2[10];
} GCFrontendRange;

/* extern */

void gcfrontend_entrypoint_0(void) {
    void func_800D3970(void);
    u8 gcfrontend_entrypoint_4(s32);
    u8 gcfrontend_entrypoint_5(s32);
    void gcfrontend_entrypoint_9(s32);
    s32 sp28[2];
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_800D3970();
    sp28[0] = gcfrontend_entrypoint_5(3);
    temp_v0 = gcfrontend_entrypoint_4(3);
    var_s0 = 0;
    if (temp_v0 > 0) {
        var_s1 = sp28[0];
        do {
            gcfrontend_entrypoint_9(var_s1);
            var_s0 += 1;
            var_s1 += 1;
        } while (var_s0 < temp_v0);
    }
}

s32 gcfrontend_entrypoint_1(s32 arg0) {
    s32 func_800DA298(s32);
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    s32 var_s0;
    s32 temp_s1;
    void *temp_v0;

    temp_v0 = (arg0 * 0xC) + (u8 *)&D_80800D80_gcfrontend;
    var_s0 = (*(s16 *)((s8 *)(temp_v0) + (2)));
    temp_s1 = (*(u8 *)((s8 *)(temp_v0) + (1))) + var_s0;
    if (var_s0 < temp_s1) {
loop_1:
        if (func_800DA298(var_s0) != 0) {
            return 1;
        }
        var_s0 += 1;
        if (var_s0 >= temp_s1) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    return 0;
}

int gcfrontend_entrypoint_2(void) {
    s32 gcfrontend_entrypoint_1(s32);
    return gcfrontend_entrypoint_1(0) || gcfrontend_entrypoint_1(1) || gcfrontend_entrypoint_1(2);
}

void gcfrontend_entrypoint_3(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_80800450_gcfrontend();
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    void *temp_v1;

    temp_v1 = (func_80800450_gcfrontend() * 0xC) + (u8 *)&D_80800D80_gcfrontend;
    func_800DA298(((*(s16 *)((s8 *)(temp_v1) + (2))) + arg0) - (*(u8 *)((s8 *)(temp_v1) + (0))));
}

u8 gcfrontend_entrypoint_4(s32 arg0) {
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    return *((u8 *)&D_80800D80_gcfrontend + arg0 * 0xC + 1);
}

u8 gcfrontend_entrypoint_5(s32 arg0) {
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    return *((u8 *)&D_80800D80_gcfrontend + arg0 * 0xC);
}

u8 gcfrontend_entrypoint_6(s32 arg0) {
    s32 func_80800450_gcfrontend();
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    u8 *temp_v1;

    temp_v1 = (func_80800450_gcfrontend() * 0xC) + (u8 *)&D_80800D80_gcfrontend;
    return *((u8 *)((*temp_v1 << 4) * -1) + (*(s32 *)(temp_v1 + 4) + arg0 * 0x10) + 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/frontend/gcfrontend_entrypoint_7.s")

s32 func_808002DC_gcfrontend(s32 arg0, s32 arg1) {
    void func_80800738_gcfrontend(void *, s32, s32, s32);
    extern s32 D_80800C9C_gcfrontend;
    void *temp_v0;

    temp_v0 = (arg0 * 0x10) + (u8 *)&D_80800C9C_gcfrontend;
    func_80800738_gcfrontend((u8 *)temp_v0 - 0xA00, (u8 *)temp_v0 - 0x9FC, *(u8 *)((u8 *)temp_v0 - 0x9F3), arg1);
}

void gcfrontend_entrypoint_8(s32 arg0, s32 arg1) {
    s32 func_808002DC_gcfrontend(s32, s32);
    s32 var_a1;

    if (arg1 != 0) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }
    func_808002DC_gcfrontend(arg0, var_a1);
}

void gcfrontend_entrypoint_9(s32 arg0) {
    s32 func_800DA544(s32);
    s32 func_80800450_gcfrontend();
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    void *temp_v1;

    temp_v1 = (func_80800450_gcfrontend() * 0xC) + (u8 *)&D_80800D80_gcfrontend;
    func_800DA544(((*(s16 *)((s8 *)(temp_v1) + (2))) + arg0) - (*(u8 *)((s8 *)(temp_v1) + (0))));
}

/* extern */

void gcfrontend_entrypoint_10(void) {
    s32 func_800D3CF8(s32);
    s32 func_808002DC_gcfrontend(s32, s32);
    func_800D3CF8(0);
    func_808002DC_gcfrontend(0xA0, -1);
}

/* extern */

void gcfrontend_entrypoint_11(void) {
    s32 gcfrontend_entrypoint_7(s32, s32);
    s32 func_800D3D04();
    gcfrontend_entrypoint_7(func_800D3D04(), 0);
}

/* extern */

void gcfrontend_entrypoint_12(void) {
    s32 func_800AA00C();
    s32 func_800AA074();
    func_800AA074();
    func_800AA00C();
    gcfrontend_entrypoint_10();
}

/* extern */

void gcfrontend_entrypoint_13(void) {
    s32 func_800D37D4();
    s32 func_808002DC_gcfrontend(s32, s32);
    func_800D37D4();
    func_808002DC_gcfrontend(0xA6, -1);
}

s32 func_80800450_gcfrontend(s32 arg0) {
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    int i;
    int end;
    int start;
    for (i = 0; i < 4; i++) {
        end = D_80800D80_gcfrontend[i].start + D_80800D80_gcfrontend[i].count;
        start = D_80800D80_gcfrontend[i].start;
        if (arg0 >= start && arg0 < end) {
            return i;
        }
    }
    return 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/frontend/func_80800520_gcfrontend.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/frontend/func_8080068C_gcfrontend.s")

/* extern */

void func_80800738_gcfrontend(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800A791C(s32, s32, s32);
    s32 func_800D39A8();
    s32 func_800D39DC(s32);
    s32 func_800D3B24();
    s32 func_800EA334(s32);
    s32 func_80800520_gcfrontend(s32);
    s32 func_8080068C_gcfrontend(s32 *, s32 *);
    s32 sp1C;
    s32 sp18;

    sp1C = (s32) (*(s16 *)((s8 *)(arg0) + (2)));
    sp18 = (s32) (*(s16 *)((s8 *)(arg0) + (0)));
    func_800D39A8();
    func_800D39DC(arg3);
    if (arg1 != 0) {
        func_800D3B24();
        func_80800520_gcfrontend(arg1);
        func_8080068C_gcfrontend(&sp18, &sp1C);
    }
    if (arg2 == 0) {
        func_800EA334(0);
    }
    func_800A791C(sp18, sp1C, 1);
}

s16 gcfrontend_entrypoint_14(s32 arg0) {
    s32 func_80800450_gcfrontend();
    extern GCFrontendRange D_80800D80_gcfrontend[4];
    void *temp_v1;

    temp_v1 = (func_80800450_gcfrontend() * 0xC) + (u8 *)&D_80800D80_gcfrontend;
    return *(s16 *)((u8 *)((*(u8 *)temp_v1 << 1) * -1) + (*(s32 *)((u8 *)temp_v1 + 8) + arg0 * 2));
}
