#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/func_808000B8_gccubeDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/func_80800230_gccubeDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/func_808003A0_gccubeDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_4.s")

/* extern */

void func_80800868_gccubeDll(s32 arg0, s32 arg1) {
    s32 func_800CE308();
    func_800CE308();
}

/* extern */

void gccubeDll_entrypoint_5(struct gccubeDll_entrypoint_5_arg *arg0) {
    struct gccubeDll_entrypoint_5_arg { s32 *base; u8 pad[0x20]; s32 count; };
    s32 _gccollectDll_entrypoint_8(void *);
    s32 var_s0;

    var_s0 = 0;
    if (arg0->count > 0) {
        do {
            _gccollectDll_entrypoint_8((u8 *)arg0->base + (var_s0 << 3));
            var_s0 += 1;
        } while (var_s0 < arg0->count);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_7.s")
