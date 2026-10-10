#include "common.h"

OSThread *chdinofoot_entrypoint_0(void)
{
    extern u8 D_80800818_chdinofoot[];

    return (OSThread *) D_80800818_chdinofoot;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_8080000C_chdinofoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_80800084_chdinofoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_808002A8_chdinofoot.s")

/* extern */

void func_80800310_chdinofoot(s32 arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_0();
    s32 _subaddiefade_entrypoint_1(s32, s32);
    s32 func_80101870(s32, s32);
    s32 sp1C;

    sp1C = _subaddiefade_entrypoint_0();
    _subaddiefade_entrypoint_1(arg0, 0xFF);
    func_80101870(arg0, arg1);
    _subaddiefade_entrypoint_1(arg0, sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_8080035C_chdinofoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_80800408_chdinofoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_80800480_chdinofoot.s")

/* extern */

s32 func_8080055C_chdinofoot(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_8010CD28(void *);
    s32 func_80800408_chdinofoot();
    if (func_80800408_chdinofoot() != 0) {
        (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x18)));
        (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x20)));
        (*(f32 *)((s8 *)(arg0) + (0x48))) = func_800136E4(func_8010CD28(arg0) + 180.0f);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_808005C4_chdinofoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/foot/func_808006BC_chdinofoot.s")
