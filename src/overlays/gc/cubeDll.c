#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/func_808000B8_gccubeDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/func_80800230_gccubeDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/func_808003A0_gccubeDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/cubeDll/gccubeDll_entrypoint_3.s")

void gccubeDll_entrypoint_4(s32 arg0, s32 arg1) {
    s32 func_80800230_gccubeDll(s32, s32);
    s32 _gsmaker_entrypoint_16(s32, s32);
    void func_80800868_gccubeDll(s32, s32);
    func_80800230_gccubeDll(arg1, 0);
    _gsmaker_entrypoint_16(arg1, 1);
    func_80800868_gccubeDll(arg0, arg1);
}

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

/* extern */

u32 gccubeDll_entrypoint_7(void) {
    void func_800BE52C(s32 *, s32 *);
    Prop *func_800E9D68(s16 *);
    u32 func_800E9D90(s16 *);
    struct CubeProp { u8 pad[0x10]; u32 value : 11; u32 other : 21; };
    u32 temp_t7;
    s32 sp30;
    s32 sp2C;
    struct CubeProp *temp_v0;
    struct CubeProp *var_s0;
    u32 var_s1;

    var_s1 = 0;
    func_800BE52C(&sp30, &sp2C);
    if ((u32)sp30 < (u32)sp2C) {
        do {
            var_s0 = (struct CubeProp *)func_800E9D68((s16 *)sp30);
            temp_v0 = (struct CubeProp *)func_800E9D90((s16 *)sp30);
            if (var_s0 < temp_v0) {
                do {
                    temp_t7 = var_s0->value;
                    var_s0++;
                    if (var_s1 < temp_t7) {
                        var_s1 = temp_t7;
                    }
                } while (var_s0 < temp_v0);
            }
            sp30 += 8;
        } while ((u32)sp30 < (u32)sp2C);
    }
    return var_s1;
}
