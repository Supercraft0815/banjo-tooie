#include "common.h"

/* extern */

void func_80800000_chgoldfish(u8 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    s32 func_808005F0_chgoldfish(u8 *, s32);
    s32 func_80800BA8_chgoldfish(u8 *, u8 *);
    if (func_800DA298(0x1BF) != 0) {
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
        return;
    }
    if (func_800DA298(0x1DA) != 0) {
        func_808005F0_chgoldfish(arg0, 6);
    } else if (func_800DA298(0x51E) != 0) {
        func_808005F0_chgoldfish(arg0, 3);
    }
    (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x38)));
    (*(f32 *)((s8 *)(arg0) + (0x4C))) = 90.0f;
    func_80800BA8_chgoldfish(arg0, arg0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_8080009C_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_808004AC_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_808005F0_chgoldfish.s")

void func_80800924_chgoldfish(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_80800D4C_chgoldfish;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_80800D4C_chgoldfish);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800964_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800AB4_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800BA8_chgoldfish.s")

OSThread *chgoldfish_entrypoint_0(void)
{
    extern u8 D_80800D94_chgoldfish[];

    return (OSThread *) D_80800D94_chgoldfish;
}
