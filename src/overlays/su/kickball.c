#include "common.h"

void func_80800000_sukickball(s32 arg0, s32 arg1, f32 *arg2, f32 arg3) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF830(s32);
    s32 func_801039E4(s32);
    struct kickball_vector { f32 v[3]; };
    extern struct kickball_vector D_80801200_sukickball;
    struct kickball_vector sp24 = D_80801200_sukickball;

    func_800DF830(3);
    func_800DE448(arg2, sp24.v, arg3, NULL, func_801039E4(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_0.s")

void sukickball_entrypoint_1(Actor *arg0, void *arg1) {
    extern s32 D_80801218_sukickball[];
    func_800DF744(1, D_80801218_sukickball[arg0->unk6C_0]);
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_80800000_sukickball((s32)arg0->unk3C, (s32)arg1, (f32 *)arg0->position, 0.5f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_5.s")

/* extern */

s32 sukickball_entrypoint_6(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)((s32)func_80100094(arg0, 0U) + arg1 + 0xA))) == 2;
}

/* extern */

s32 sukickball_entrypoint_7(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)((s32)func_80100094(arg0, 0U) + arg1 + 0xA))) == 1;
}

/* extern */

s32 sukickball_entrypoint_8(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return ((s32 *)func_80100094(arg0, 0U))[arg1 + 4];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_9.s")

/* extern */
void sukickball_entrypoint_10(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + arg1 + 0x34)) = (s8)arg2;
}

/* extern */

void sukickball_entrypoint_11(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + arg1 + 0x34)) = 0;
}

/* extern */

u8 sukickball_entrypoint_12(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return ((u8 *)func_80100094(arg0, 0))[arg1 + 0x34];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_13.s")

void sukickball_entrypoint_14(Actor *arg0) {
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 func_80102D78(Actor *, void *);
    f32 sukickball_entrypoint_15(s32);

    arg0->unk54 = func_80102D78(arg0, arg0->actorData);
    if (arg0->unk70_10 == 3) {
        arg0->unk54 = sukickball_entrypoint_15(arg0->unk6C_0);
    }
    if (func_80102CF4(arg0, 0x41000000) == 0) {
        func_80102B2C(arg0, 8.0f);
    }
}

f32 sukickball_entrypoint_15(s32 arg0) {
    extern f32 D_80801234_sukickball[];
    return ((f32 *)&D_80801234_sukickball)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/kickball/sukickball_entrypoint_16.s")

/* extern */

void sukickball_entrypoint_17(Actor *arg0) {
    void func_800F8294(s32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 sukickball_entrypoint_16(s32, f32 *);
    f64 pad;
    f32 sp2C[3];
    s32 var_s0;

    if (((u8 *)func_80100094(arg0, 0U))[0x39] != 3) {
        for (var_s0 = 0; var_s0 != 4; var_s0++) {
            if (sukickball_entrypoint_6(arg0, var_s0) != 0) {
                sukickball_entrypoint_16(var_s0, sp2C);
                func_800F8294(var_s0, sp2C);
            }
        }
    }
}

void sukickball_entrypoint_18(Actor *arg0) {
    void func_800D2748(s32, s32);
    void *func_80100094(Actor *, u32);

    switch (((u8 *)func_80100094(arg0, 0U))[0x39]) {
    case 0:
    case 1:
    case 2:
        func_800D2748(0xC3, 0x2D);
        break;
    case 4:
        func_800D2748(0xC3, 0x1F);
        break;
    }
    func_800D2748(0xC4, 0x20);
    func_800D2748(0xC5, 0x21);
    func_800D2748(0xC6, 0x22);
}

/* extern */

void sukickball_entrypoint_19(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800D24E8(s32, s32, s32);
    void func_800D2770(s32, s32);
    s32 func_800D28A0(s32);
    void *func_80100094(Actor *, u32);
    s32 var_s0;
    s32 var_s1;
    u8 *temp_s2;

    temp_s2 = func_80100094(arg0, 0U);
    var_s0 = 0;
    if (arg2 > 0) {
        do {
            var_s1 = var_s0 + 0xC3;
            if ((*(u8 *)((s8 *)(temp_s2) + (0x38))) == 0) {
                var_s1 = var_s0 + 0xC3;
                func_800D2770(var_s1, 0);
            } else {
                func_800D24E8(var_s1, ((s32 *)temp_s2)[var_s0 + 8], 0);
            }
            if ((arg1 != 0) && ((*(u8 *)((s8 *)((temp_s2 + var_s0)) + (0x30))) != 0)) {
                func_800D28A0(var_s1);
            }
            var_s0 += 1;
        } while (var_s0 != arg2);
    }
    (*(u8 *)((s8 *)(temp_s2) + (0x38))) = 1U;
}
