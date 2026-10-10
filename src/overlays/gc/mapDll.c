#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/func_80800000_gcmapDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/func_8080045C_gcmapDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/func_808005A8_gcmapDll.s")

/* extern */

void func_80800668_gcmapDll(s32 arg0, u8 *arg1, s32 arg2) {
    s32 func_800BF744(s16, s16);
    s32 var_s1;
    u8 *var_s0;

    var_s1 = 0;
    if (arg2 > 0) {
        var_s0 = arg1;
        do {
            func_800BF744((*(s16 *)((s8 *)(var_s0) + (0))), (*(s16 *)((s8 *)(var_s0) + (2))));
            var_s1 += 1;
            var_s0 += 4;
        } while (var_s1 != arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/func_80800A94_gcmapDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapDll/gcmapDll_entrypoint_5.s")

/* extern */

void gcmapDll_entrypoint_6(void *arg0, s32 arg1) {
    s32 _dbtex_entrypoint_0(s32);
    s32 func_800B27FC(s32);
    s32 func_800D5B24();
    s32 func_800D674C(u16);
    void *func_80800000_gcmapDll(s32);
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_80800000_gcmapDll(arg1);
    sp1C = temp_v0;
    if ((*(u16 *)((s8 *)(temp_v0) + (2))) != 0) {
        func_800D5B24();
        (*(s32 *)((s8 *)(arg0) + (0x24))) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C((*(u16 *)((s8 *)(sp1C) + (2))))));
    }
    if ((*(u16 *)((s8 *)(sp1C) + (4))) != 0) {
        func_800D5B24();
        (*(s32 *)((s8 *)(arg0) + (0x50))) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C((*(u16 *)((s8 *)(sp1C) + (4))))));
    }
}
