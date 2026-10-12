#include "common.h"

OSThread *chstatueboss_entrypoint_0(void)
{
    extern u8 D_80802748_chstatueboss[];

    return (OSThread *) D_80802748_chstatueboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_8080000C_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800298_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800934_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800B74_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800BE0_chstatueboss.s")

void func_80800D30_chstatueboss(Actor *arg0) {
    extern s16 D_808025C0_chstatueboss[][6];
    s32 index;
    s32 i;
    s32 offset;
    u8 *data;

    data = func_80100094(arg0, 0U);
    index = *(s16 *)(data + 0x84);
    for (i = 0; D_808025C0_chstatueboss[index][i] != -1; i++) {
        offset = D_808025C0_chstatueboss[index][i];
        data[offset] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800DA8_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_808010A0_chstatueboss.s")

s32 func_808011A0_chstatueboss(s32 arg0) {
    extern s16 D_808027D4_chstatueboss[];
    return ((s16 *)&D_808027D4_chstatueboss)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_808011B4_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_8080124C_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801320_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801448_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801518_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801640_chstatueboss.s")

OSThread *chstatueboss_entrypoint_1(void)
{
    extern u8 D_808027E8_chstatueboss[];

    return (OSThread *) D_808027E8_chstatueboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801694_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801724_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801804_chstatueboss.s")

void func_80801A6C_chstatueboss(Actor *arg0, f32 arg1) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern u32 D_80802790_chstatueboss;
    if (_subaddieaudioquick_entrypoint_3(arg0, (f32 *) ((u8 *) arg0 + 4), &D_80802790_chstatueboss, arg1) != 0) {
        func_800E15CC(0, 20.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
    }
}

void func_80801AC4_chstatueboss(s32 arg0, s32 arg1) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808027F8_chstatueboss;
    _subaddieaudioloop_entrypoint_4((Actor *) arg0, (f32 *) ((u8 *) arg0 + 4), arg1, &D_808027F8_chstatueboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801AF0_chstatueboss.s")

void func_80801C78_chstatueboss(s32 arg0) {
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    extern s32 D_80802850_chstatueboss;
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80802850_chstatueboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801CA0_chstatueboss.s")

void func_80801E24_chstatueboss(Actor *arg0, u32 arg1, u32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    void _capod_entrypoint_14(void);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x1CD))) != 0) {
        arg2 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(arg0->unk0, NULL, arg1, arg2);
    (*(s8 *)((s8 *)(sp1C) + (0x1CD))) = 1;
}

void func_80801E90_chstatueboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x1CD))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_14();
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x1CD))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801ECC_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801F74_chstatueboss.s")

void func_808020EC_chstatueboss(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    Actor* func_801084B0(s32, Actor**);
    u8 *sp1C;
    Actor *sp18;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = func_801084B0(0x44F, &arg0);
    sp18 = temp_v0;
    func_80102FDC(temp_v0, arg0->scale);
    (*(Unk80132ED0 **)((s8 *)(sp1C) + (0x8C))) = (Unk80132ED0 *) sp18->unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80802144_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80802268_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_8080232C_chstatueboss.s")
