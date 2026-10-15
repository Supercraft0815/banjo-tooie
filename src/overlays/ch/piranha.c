#include "common.h"

/* extern */

void func_80800000_chpiranha(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    s32 func_800DA3B8(s32, s32);
    func_80100074(arg0, 0U, 0U);
    arg0->unk3C = NULL;
    func_800DA3B8(0x6A8, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080003C_chpiranha.s")

void func_80800218_chpiranha(Actor *arg0, u32 arg1) { if (arg0->unk70_10 == 7) { arg0->unk64_16 = 1; } func_80101FDC(arg0, arg1); if (arg1 == 7) { arg0->unk64_16 = 0; } }

void func_80800280_chpiranha(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x6E) = (*(u16 *)((u8 *)arg0 + 0x6E) & 0xFE00) | (((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) & 0x1FF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_808002A0_chpiranha.s")

f32 func_80800CAC_chpiranha(void) {
    void func_8008FFBC(s32);
    f32 sp1C[3];
    f32 result;

    func_8008FFBC((s32)sp1C);
    result = sp1C[1];
    result = sp1C[0] * sp1C[0] + result * result + sp1C[2] * sp1C[2];
    return result;
}

/* extern */

void func_80800CEC_chpiranha(s32 arg0, s32 arg1, f32 arg2, f32 *arg3, f32 arg4, f32 arg5) {
    f32 func_800DC178(f32, f32);
    s32 func_800EFA4C(s32, f32, f32, f32);
    f32 func_800EFC7C(void *, void *);
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    s32 var_s0;

    var_s0 = 0;
    temp_f22 = -arg2;
loop_1:
    temp_f24 = func_800DC178(temp_f22, arg2);
    temp_f26 = func_800DC178(temp_f22, arg2);
    func_800EFA4C(arg1, temp_f24, temp_f26, func_800DC178(temp_f22, arg2));
    var_s0 += 1;
    if (var_s0 < 0xA) {
        if (func_800EFC7C(arg0, arg1) < (arg2 * arg2)) {
            goto loop_1;
        }
    }
    *arg3 = func_800DC178(arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800DD0_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800EFC_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080106C_chpiranha.s")

void func_80801210_chpiranha(f32 *arg0, f32 arg1, f32 arg2) {
    void func_800EF334(f32 vec[3], f32 scale);
    if (arg1 != 0.0f) {
        func_800EF334(arg0, arg2 / arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80801250_chpiranha.s")

/* extern */

void func_80801420_chpiranha(Actor *arg0) {
    f32 func_800EFC7C(void *, void *);
    void *func_80100094(Actor *, u32);
    s32 func_80800DD0_chpiranha(Actor *, u8 *);
    s32 func_80801250_chpiranha(u8 *, u8 *, u8 *, s32, f32, u8 *, f32 *);
    u32 var_s2;
    u8 *temp_s1;
    u8 *var_s0;
    f32 sp58[3];

    var_s0 = func_80100094(arg0, 0);
    var_s2 = 0;
    var_s0 += 0x1C;
    for (; var_s2 < arg0->unk6C_0; var_s2++) {
            temp_s1 = var_s0 + 0x18;
            func_80801250_chpiranha(temp_s1, var_s0, var_s0 + 0xC, (*(s32 *)((s8 *)(var_s0) + (0x2C))), 150.0f, var_s0 + 0x24, sp58);
            if (func_800EFC7C(var_s0, temp_s1) < 2500.0f) {
                func_80800DD0_chpiranha(arg0, var_s0);
            }
            var_s0 += 0x30;
    }
}

/* extern */

void func_80801508_chpiranha(s32 arg0) {
    s32 func_8010C500();
    s32 func_8010C9B0(s32, s32);
    void func_80800218_chpiranha(Actor *, u32);
    if ((func_8010C500() != 0) && (func_8010C9B0(arg0 + 4, 0x384) != 0)) {
        func_80800218_chpiranha(arg0, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080154C_chpiranha.s")

s32 func_80801638_chpiranha(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    return arg0->unk3C != NULL ?
        ((u32)*(u16 *)((s8 *)arg0->unk3C + 0x12) >> 1) != *(s32 *)((s8 *)func_80100094(arg0, 0U) + 0x18) : 1;
}

void func_80801690_chpiranha(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80801B10_chpiranha;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_80801B10_chpiranha);
}

/* extern */

s32 *func_808016D0_chpiranha(u8 *arg0) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, f32 *);
    s32 pad;
    s32 *sp28;
    f32 sp24;
    f32 sp20;
    s32 *temp_v0;

    sp28 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), 0x211, -1, &sp24);
    temp_v0 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), 0x199, -1, &sp20);
    if ((temp_v0 != NULL) && (sp28 == NULL)) {
        sp28 = temp_v0;
    }
    if ((temp_v0 != NULL) && (sp28 != NULL) && ((sp20 < sp24) || (sp24 > 500.0f))) {
        sp28 = temp_v0;
        sp24 = sp20;
    }
    temp_v0 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), 0x19A, -1, &sp20);
    if ((temp_v0 != NULL) && (sp28 == NULL)) {
        sp28 = temp_v0;
    }
    if ((temp_v0 != NULL) && (sp28 != NULL) && ((sp20 < sp24) || (sp24 > 500.0f))) {
        sp28 = temp_v0;
        sp24 = sp20;
    }
    if (sp28 != NULL) {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = (s32) *sp28;
    } else {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = 0;
    }
    if (sp24 > 500.0f) {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = 0;
    }
    return sp28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080182C_chpiranha.s")

OSThread *chpiranha_entrypoint_0(void)
{
    extern u8 D_80801B60_chpiranha[];

    return (OSThread *) D_80801B60_chpiranha;
}

OSThread *chpiranha_entrypoint_1(void)
{
    extern u8 D_80801BA8_chpiranha[];

    return (OSThread *) D_80801BA8_chpiranha;
}

OSThread *chpiranha_entrypoint_2(void)
{
    extern u8 D_80801BF0_chpiranha[];

    return (OSThread *) D_80801BF0_chpiranha;
}
