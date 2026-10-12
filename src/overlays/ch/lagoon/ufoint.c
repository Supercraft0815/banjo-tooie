#include "common.h"

OSThread *chlagoonufoint_entrypoint_0(void)
{
    extern u8 D_80801948_chlagoonufoint[];

    return (OSThread *) D_80801948_chlagoonufoint;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_8080000C_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_808001A0_chlagoonufoint.s")

void func_80800240_chlagoonufoint(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void* func_80100094(Actor*, u32);
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 0U)) != 0) {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0U));
    }
    _susubgame_entrypoint_11(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_80800294_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_808004D8_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_808005D0_chlagoonufoint.s")

OSThread *chlagoonufoint_entrypoint_1(void)
{
    extern u8 D_808019C0_chlagoonufoint[];

    return (OSThread *) D_808019C0_chlagoonufoint;
}

OSThread *chlagoonufoint_entrypoint_2(void)
{
    extern u8 D_80801A28_chlagoonufoint[];

    return (OSThread *) D_80801A28_chlagoonufoint;
}

OSThread *chlagoonufoint_entrypoint_3(void)
{
    extern u8 D_80801A90_chlagoonufoint[];

    return (OSThread *) D_80801A90_chlagoonufoint;
}

void func_80800744_chlagoonufoint(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_800DA298(s32);
    extern s32 D_80801AD8_chlagoonufoint;
    extern s32 D_80801AF4_chlagoonufoint;
    s32 *var_a2;

    if (func_800DA298(0x9F0) != 0) {
        var_a2 = &D_80801AF4_chlagoonufoint;
    } else {
        var_a2 = &D_80801AD8_chlagoonufoint;
    }
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, var_a2);
}

/* extern */

s32 func_8080078C_chlagoonufoint(void) {
    s32 *_subaddiefind_entrypoint_2(s32, s32);
    return *_subaddiefind_entrypoint_2(0x1C5, 0);
}

/* extern */

void func_808007B4_chlagoonufoint(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    f32 func_800DC0C0();
    s32 func_80101EE4(void *, f32);
    s32 func_80102424(void *, s32);
    (*(s32 *)((s8 *)(arg0) + (0x3C))) = func_8080078C_chlagoonufoint();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 3);
    }
    if (((u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) << 0xB) >> 0x14) == 0x1C7) {
        func_80101EE4(arg0, func_800DC0C0());
    }
}

void func_80800820_chlagoonufoint(Actor *arg0, f32 *arg1) {
    u8 func_800C4350(s32, f32[3], s32 *);
    extern s32 D_80801B10_chlagoonufoint;
    u8 var_a3;
    Actor *actor;
    Actor **saved_actor = &arg0;
    u8 handle;

    var_a3 = arg0->unk5F;
    if (var_a3 == 0) {
        handle = func_800C4350(0, arg1, &D_80801B10_chlagoonufoint);
        actor = *saved_actor;
        actor->unk5F = handle;
        var_a3 = actor->unk5F;
    }
    func_800C4350(var_a3 & 0xFF, arg1, NULL);
}

/* extern */

void func_80800878_chlagoonufoint(s32 arg0, s32 arg1) {
    s32 func_800C4104(s32, s32, s32, s32, f32, f32);
    func_800C4104(arg1, 0x3F800000, 0x55F0, arg0 + 4, 500.0f, 1000.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_808008C8_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_80800CD4_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_80800E00_chlagoonufoint.s")

OSThread *chlagoonufoint_entrypoint_4(void)
{
    extern u8 D_80801B68_chlagoonufoint[];

    return (OSThread *) D_80801B68_chlagoonufoint;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_80800E80_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_80800F48_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_80800FD4_chlagoonufoint.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/func_808012A4_chlagoonufoint.s")

/* extern */

s32 func_8080135C_chlagoonufoint(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_808012A4_chlagoonufoint();
    switch (arg1) {
    case 0x40:
        func_808012A4_chlagoonufoint(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/chlagoonufoint_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoint/chlagoonufoint_entrypoint_6.s")
