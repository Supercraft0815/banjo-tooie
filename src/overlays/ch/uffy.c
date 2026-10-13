#include "common.h"

OSThread *chchuffy_entrypoint_0(void)
{
    extern u8 D_80802434_chchuffy[];

    return (OSThread *) D_80802434_chchuffy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_8080000C_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80800110_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808001DC_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80800264_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/chchuffy_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80800398_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80800410_chchuffy.s")

/* extern */

void func_80800524_chchuffy(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_80800410_chchuffy(Actor *, s32);
    s32 var_s0;
    Actor *actor;
    u32 *temp_v0;

    actor = arg0;
    (*(s32 *)((s8 *)(func_80100094(actor, 0U)) + (0x2A8))) = 0x9DD;
    for (var_s0 = 0; var_s0 < 10; var_s0++) {
        func_80800410_chchuffy(actor, var_s0);
    }
    temp_v0 = actor->unk0->unk0;
    (*(u8 *)((s8 *)(temp_v0) + (0xA))) = (u8) (((*(u8 *)((s8 *)(temp_v0) + (0xA))) & 0xFF07) | 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_8080059C_chchuffy.s")

void func_80800818_chchuffy(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11((*(Unk80132ED0 **)((s8 *)(arg0) + (0))), arg1, arg2, arg0 + 4, 0x6FU);
    ((struct Flags *)arg0)->flag = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80800864_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808009CC_chchuffy.s")

struct Entry { s16 pad[2]; s16 value; s16 tail; };
extern struct Entry D_8080247C_chchuffy[];

void func_80800EF4_chchuffy(Unk80132ED0 *arg0) { void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32); s32 func_80800110_chchuffy(s32); s32 temp_v0; temp_v0 = func_80800110_chchuffy(4); if (D_8080247C_chchuffy[temp_v0].value != -1) { _capod_entrypoint_13(arg0->unk0, 0, D_8080247C_chchuffy[temp_v0].value, 0x2830); } }

void func_80800F54_chchuffy(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    s32 _chintrotext_entrypoint_2(s32);
    s32 func_80800110_chchuffy(s32);
    s32 temp_v0;

    temp_v0 = func_80800110_chchuffy(4);
    if (D_8080247C_chchuffy[temp_v0].tail != -1) {
        _capod_entrypoint_13(arg0->unk0, NULL, D_8080247C_chchuffy[temp_v0].tail, 0x2830U);
        _chintrotext_entrypoint_2(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80800FBC_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_8080115C_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_8080130C_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808013E8_chchuffy.s")

/* extern */

void func_8080167C_chchuffy(s32 *arg0) {
    s32 _capod_entrypoint_14();
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_21();
    s32 func_800D9290();
    if (_glcutDll_entrypoint_19(0x72) != 0) {
        _capod_entrypoint_14();
        func_800D9290();
        _glcutDll_entrypoint_21();
        return;
    }
    *arg0 = 0xD0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808016D0_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808017D4_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808018F8_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808019A4_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80801B8C_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80801C78_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80801CF8_chchuffy.s")

void func_80801D3C_chchuffy(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808025E4_chchuffy;
    f32 *temp_a0;

    temp_a0 = (f32 *)((u8 *)func_80100094(arg0, 0) + 8);
    if (arg0->unk7C_12) {
        func_800BBCB8(temp_a0, 0, 1.0f, arg1, &D_808025E4_chchuffy);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80801D94_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80801DDC_chchuffy.s")

void func_80801EAC_chchuffy(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 _subaddieaudioloop_entrypoint_7(u8, u8 *, s32, s32 *, s32);
    extern s32 D_80802690_chchuffy;
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    *sp24 = _subaddieaudioloop_entrypoint_7(*temp_v0, temp_v0 + 0x20, 1, &D_80802690_chchuffy, (*(s32 *)((s8 *)(arg0) + (0x70))) & 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80801F04_chchuffy.s")

/* extern */

void func_80801F84_chchuffy(s32 arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24(arg0 + 0x4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80801FA4_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80802060_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80802164_chchuffy.s")

OSThread *chchuffy_entrypoint_2(void)
{
    extern u8 D_808026F4_chchuffy[];

    return (OSThread *) D_808026F4_chchuffy;
}
