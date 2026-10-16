#include "common.h"

s32 func_80800000_suexpressmorph(s32 arg0) {
    extern s16 D_80801324_suexpressmorph;
    extern s32 D_8080132C_suexpressmorph;
    s32 *var_v0;
    s32 var_v1;

    var_v0 = &D_8080132C_suexpressmorph;
    var_v1 = 1;
    if (arg0 == D_80801324_suexpressmorph) {
        return 0;
    }
    for (;;) {
        if (arg0 == *(s16 *)(var_v0 + 1)) return var_v1;
        if (arg0 == *(s16 *)(var_v0 + 4)) return var_v1 + 1;
        if (arg0 == *(s16 *)(var_v0 + 7)) return var_v1 + 2;
        if (arg0 == *(s16 *)(var_v0 + 10)) return var_v1 + 3;
        var_v1 += 4;
        var_v0 += 12;
        if (var_v1 == 0x11) return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/suexpressmorph_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/func_808000EC_suexpressmorph.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/expressmorph/func_808002BC_suexpressmorph.s")

struct MorphEntry {
    f32 (*data)[9];
    s16 id;
    u8 unk6;
    u8 count;
    s32 unk8;
};

void suexpressmorph_entrypoint_1(u8 *arg0) {
    s32 func_808000EC_suexpressmorph(f32 *, void *);
    s32 func_808002BC_suexpressmorph(f32 *, void *);
    extern struct MorphEntry D_80801320_suexpressmorph[];
    struct MorphEntry *var_v0;
    f32 sp28[3];
    s32 var_v1;

    var_v0 = &D_80801320_suexpressmorph[*(s16 *)(arg0 + 2)];
    for (var_v1 = 0; var_v1 < (s32)var_v0->count; var_v1++) {
        sp28[var_v1] = var_v0->data[arg0[5]][var_v1 + 1];
        var_v0 = &D_80801320_suexpressmorph[*(s16 *)(arg0 + 2)];
    }
    func_808002BC_suexpressmorph(sp28, arg0);
    func_808000EC_suexpressmorph(sp28, arg0);
}

void suexpressmorph_entrypoint_2(u8 *arg0, void *arg1) {
    struct MorphFlags {
        u8 pad[0x17];
        u8 other : 7;
        u8 active : 1;
    };
    s32 pad0;
    u8 *sp38;
    s32 sp34;
    s32 pad;
    u8 *sp2C;
    u8 *morph;
    s32 _dbmorph_entrypoint_3(u8 *, u8 *, s32, u8, u8 *);
    s32 _dbmorph_entrypoint_4(u8 *, u8 *, s32, u8, s32);
    s32 func_800AE080(s16);
    u8 *func_800B2768(u8 *);
    s32 func_800B2840(s32);
    u8 *func_80103AA0(u8 *);
    s32 func_80103CDC(u8 *, u8 *);
    extern u8 D_80801328_suexpressmorph[];

    sp38 = func_80103AA0(*(u8 **)arg1);
    if (sp38 != NULL) {
        morph = (u8 *)func_80103CDC(arg1, sp38);
        if (morph != NULL) {
            sp34 = func_800B2840((s32)sp38);
            sp2C = func_800B2768(sp38);
            _dbmorph_entrypoint_3(sp2C, morph, sp34, arg0[6], arg0 + 8);
            if (D_80801328_suexpressmorph[*(s16 *)(arg0 + 2) * 12] & 1) {
                ((struct MorphFlags *)morph)->active = 1;
                _dbmorph_entrypoint_4(sp2C, morph, sp34, arg0[6], func_800AE080(*(s16 *)(*(u8 **)arg1 + 0x10)));
            }
        }
    }
}

/* extern */

void suexpressmorph_entrypoint_3(s16 *arg0, s16 arg1) {
    s32 func_80800000_suexpressmorph(s32);
    *arg0 = arg1;
    arg0[1] = func_80800000_suexpressmorph(*arg0);
}

void suexpressmorph_entrypoint_4(s8 *arg0, s32 arg1) {
    arg0[6] = arg1;
}

void suexpressmorph_entrypoint_5(s16 *arg0, s16 arg1) {
    extern struct MorphEntry D_80801320_suexpressmorph[];
    s32 var_a0;
    f32 *var_v0;
    f32 *var_v1;
    s32 count;

    suexpressmorph_entrypoint_3(arg0, arg1);
    ((s8 *)arg0)[5] = 0;
    ((s8 *)arg0)[6] = 1;
    var_v0 = (f32 *)((u8 *)arg0 + 8);
    count = D_80801320_suexpressmorph[arg0[1]].count;
    var_v1 = (f32 *)(count * 4 + (u8 *)arg0 + 8);
    var_a0 = 0;
    if ((s32)count > 0) {
        do {
            *var_v0 = 0.0f;
            *var_v1 = 0.0f;
            var_a0++;
            var_v0++;
            var_v1++;
        } while (var_a0 < (s32)D_80801320_suexpressmorph[arg0[1]].count);
    }
}
