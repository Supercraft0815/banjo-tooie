#include "common.h"

void gcboundDll_entrypoint_0(u8 *arg0) {
    s32 i;

    (*(s32 *)(arg0 + 4)) = 0;
    (*(s32 *)(arg0 + 0)) = 0;
    (*(s32 *)(arg0 + 0xC)) = 0;
    (*(s32 *)(arg0 + 8)) = 0;
    (*(s32 *)(arg0 + 0x14)) = 0;
    (*(s32 *)(arg0 + 0x10)) = 0;
    for (i = 0; i < 0xC8; i++) {
        arg0[i + 0x18] = 1;
    }
    (*(s32 *)(arg0 + 0xE0)) = 0;
}

/* extern */

void gcboundDll_entrypoint_1(void *arg0) {
    s32 func_800B42FC(s32, s32);
    s32 heap_alloc(s32);
    (*(s32 *)((s8 *)(arg0) + (4))) = heap_alloc(0);
    (*(s32 *)((s8 *)(arg0) + (0xC))) = heap_alloc(0);
    (*(s32 *)((s8 *)(arg0) + (0x14))) = heap_alloc(0);
    (*(s32 *)((s8 *)(arg0) + (0xE0))) = func_800B42FC(0x18, 0xA);
}

/* extern */

void func_808000AC_gcboundDll(s32 arg0, s32 *arg1, u32 *arg2) {
    s32 func_800B422C(s32, s32);
    s32 heap_free(u32);
    u32 temp_s1;
    u32 var_a3;
    u32 var_s0;

    var_a3 = *arg2;
    if (var_a3 != 0) {
        var_s0 = var_a3;
        temp_s1 = (*arg1 * 0x1C) + var_a3;
        if (var_a3 < temp_s1) {
            do {
                func_800B422C(arg0 + 0xE0, var_s0 + 0x18);
                var_s0 += 0x1C;
            } while (var_s0 < temp_s1);
            var_a3 = *arg2;
        }
        heap_free(var_a3);
        *arg2 = 0;
        *arg1 = 0;
    }
}

/* extern */

void gcboundDll_entrypoint_2(s32 arg0) {
    s32 func_800B42DC(s32);
    func_808000AC_gcboundDll(arg0, (s32 *) arg0, arg0 + 4);
    func_808000AC_gcboundDll(arg0, arg0 + 8, arg0 + 0xC);
    func_808000AC_gcboundDll(arg0, arg0 + 0x10, arg0 + 0x14);
    func_800B42DC((*(s32 *)((s8 *)(arg0) + (0xE0))));
    (*(s32 *)((s8 *)(arg0) + (0xE0))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_808001A8_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80800280_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_5.s")

s32 func_80800630_gcboundDll(u8 *arg0, s16 *arg1) {
    s32 func_800B42A0(u8 *, s16 *);
    return func_800B42A0(*(u8 **)(arg0 + 0xE0), arg1 + 12);
}

s32 func_80800654_gcboundDll(u8 *arg0, s16 *arg1) {
    return arg1[13] * 0x18 + func_80800630_gcboundDll(arg0, arg1);
}

void func_80800688_gcboundDll(u8 *arg0, s16 *arg1)
{
    func_80800630_gcboundDll(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_808006A8_gcboundDll.s")

void func_808006E0_gcboundDll()
{
    func_808006A8_gcboundDll();
}

s32 func_80800700_gcboundDll(u8 *arg0, s16 *arg1)
{
    return func_80800654_gcboundDll(arg0, arg1);
}

/* extern */

void func_80800720_gcboundDll(s32 arg0, s32 arg1, u32 arg2) {
    s32 func_80800EBC_gcboundDll(s32, u32);
    u32 temp_s1;
    u32 var_s0;

    temp_s1 = (arg1 * 0x1C) + arg2;
    var_s0 = arg2;
    if (arg2 < temp_s1) {
        do {
            func_80800EBC_gcboundDll(arg0, var_s0);
            var_s0 += 0x1C;
        } while (var_s0 < temp_s1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_808008D8_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80800CA8_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80800D40_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/gcboundDll_entrypoint_8.s")

void func_80800E6C_gcboundDll(u8 *arg0, u8 *arg1) { void rare_memcpy(void *, void *, int); u8 sp18[0x18]; rare_memcpy(sp18, arg0, 0x18); rare_memcpy(arg0, arg1, 0x18); rare_memcpy(arg1, sp18, 0x18); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80800EBC_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80800F6C_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_8080132C_gcboundDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80801370_gcboundDll.s")

/* extern */

void func_808013D4_gcboundDll(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80801370_gcboundDll(s32, s32, s32, s32, s32);
    func_80801370_gcboundDll((*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (4))), arg3, arg1, arg2);
}

void func_8080141C_gcboundDll(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80801370_gcboundDll(s32, s32, s32, s32, s32);
    func_80801370_gcboundDll((*(s32 *)((s8 *)(arg0) + (8))), (*(s32 *)((s8 *)(arg0) + (0xC))), arg2, arg1, 0);
}

void func_80801450_gcboundDll(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80801370_gcboundDll(s32, s32, s32, s32, s32);
    func_80801370_gcboundDll((*(s32 *)((s8 *)(arg0) + (0x10))), (*(s32 *)((s8 *)(arg0) + (0x14))), arg2, arg1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/boundDll/func_80801484_gcboundDll.s")
