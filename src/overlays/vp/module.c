#include "common.h"

s32 func_80800000_vpmodule(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (((arg0 >= 0x4B0) && (arg0 < 0x6A4)) || ((arg0 >= 0x834) && (arg0 < 0x898))) {
        return 1;
    }
    if ((arg0 >= 0xC8) && (arg0 < 0x12C)) {
        return 2;
    }
    if ((arg0 >= 0x1F4) && (arg0 < 0x258)) {
        return 3;
    }
    if ((arg0 >= 0x64) && (arg0 < 0xC8)) {
        return 4;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_0.s")

typedef struct {
    s32 unk0;
    void (*update)(void *, void *);
    void (*free)(void *);
    s32 unkC;
    s32 unk10;
} ModuleEntry;
extern ModuleEntry D_808008C0_vpmodule[];

void vpmodule_entrypoint_1(u8 *arg0, void *arg1) {
    void heap_free(void *);
    u8 *temp_s1;
    u8 *var_s0;

    var_s0 = arg0 + 8;
    temp_s1 = ((*(s32 *)((s8 *)(arg1) + (0x2C))) * 8) + arg0 + 8;
    if (var_s0 < temp_s1) {
        do {
            D_808008C0_vpmodule[*var_s0].free(*(void **)(var_s0 + 4));
            var_s0 += 8;
        } while (var_s0 < temp_s1);
    }
    heap_free(arg0);
}

void vpmodule_entrypoint_2(u8 *arg0, void *arg1) {
    u8 *temp_s3;
    u8 *var_s0;

    var_s0 = arg0 + 8;
    temp_s3 = ((*(s32 *)((s8 *)arg1 + 0x2C)) * 8) + arg0 + 8;
    if (var_s0 < temp_s3) {
        do {
            if (var_s0[1] != 0) {
                D_808008C0_vpmodule[*var_s0].update(*(void **)(var_s0 + 4), arg1);
            }
            var_s0 += 8;
        } while (var_s0 < temp_s3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/vpmodule_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/module/func_808005C4_vpmodule.s")

s32 vpmodule_entrypoint_4(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u32 temp_t0;
    u32 var_v1;

    var_v1 = arg0 + 8;
    temp_t0 = ((*(s32 *)((s8 *)(arg1) + (0x2C))) * 8) + arg0 + 8;
    while (var_v1 < temp_t0) {
        s32 *record = (s32 *)(((s32 *)(arg1 + 0x30))[*(s16 *)(var_v1 + 2)] + arg1);
        if (arg2 == *record) {
            (*(s8 *)((s8 *)(var_v1) + (1))) = arg3;
            return 1;
        }
        var_v1 += 8;
    }
    return 0;
}
