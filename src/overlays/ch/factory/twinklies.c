#include "common.h"

OSThread *chfactorytwinklies_entrypoint_0(void)
{
    extern u8 D_80802218_chfactorytwinklies[];

    return (OSThread *) D_80802218_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_1(void)
{
    extern u8 D_80802260_chfactorytwinklies[];

    return (OSThread *) D_80802260_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_2(void)
{
    extern u8 D_808022A8_chfactorytwinklies[];

    return (OSThread *) D_808022A8_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_3(void)
{
    extern u8 D_808022F0_chfactorytwinklies[];

    return (OSThread *) D_808022F0_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_4(void)
{
    extern u8 D_80802338_chfactorytwinklies[];

    return (OSThread *) D_80802338_chfactorytwinklies;
}

OSThread *chfactorytwinklies_entrypoint_5(void)
{
    extern u8 D_80802380_chfactorytwinklies[];

    return (OSThread *) D_80802380_chfactorytwinklies;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800048_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808001A0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080040C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080064C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808006C0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800748_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808009EC_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800A84_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800B80_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800D00_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800DE0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80800E9C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080105C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80801108_chfactorytwinklies.s")

s32 func_80801174_chfactorytwinklies(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    if (arg1 == 0x1348) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0xA0))) + 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808011B0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808013BC_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080145C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808014B0_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80801608_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_8080171C_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_808018A0_chfactorytwinklies.s")

void func_80801D58_chfactorytwinklies(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (*(s32 *)((s8 *)(arg0) + (0x50)));
    if (temp_a3 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x50))) = _chlightfader_entrypoint_1(temp_a3, 1.0f, 2);
    }
}

/* extern */

s32 func_80801D94_chfactorytwinklies(s32 arg0, s32 arg1, u8 *arg2) {
    s32 func_80801DD8_chfactorytwinklies(s32, u32);
    u8 **ptr = &arg2;
    switch (arg1) {
    case 0x3E:
        func_80801DD8_chfactorytwinklies(arg0, (u32)*(u16 *)(*ptr + 0x1A) >> 5);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80801DD8_chfactorytwinklies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80801ED0_chfactorytwinklies.s")

f32 func_80801F5C_chfactorytwinklies(void *arg0) { switch (*(s32 *)((u8 *)arg0 + 0x2C)) { case 0: return 900.0f; case 1: return 700.0f; default: return 500.0f; } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/twinklies/func_80801FAC_chfactorytwinklies.s")

/* extern */
s32 func_80802020_chfactorytwinklies(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800D9078((f32 *) (arg0 + 0x28));
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, 0.0f, -250.0f);
    return sp24;
}

/* extern */

s32 func_8080207C_chfactorytwinklies(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp28;

    sp28 = func_800D9078((f32 *) (arg0 + 0x28));
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, -250.0f, 0.0f);
    return sp28;
}
