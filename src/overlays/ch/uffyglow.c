#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffyglow/func_80800000_chchuffyglow.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffyglow/func_80800180_chchuffyglow.s")

void func_80800484_chchuffyglow(s32 arg0) 
{
}
void func_8080048C_chchuffyglow(s32 arg0) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    _subaddiefade_entrypoint_1(arg0, 0);
    ((Actor *)arg0)->unk58 = 5.0f;
    ((Actor *)arg0)->unk64_20 = 1;
}

/* extern */

void chchuffyglow_entrypoint_0(s32 arg0) {
    s32 *func_80106790();
    void *func_801084B0(s32, s32 **);
    s32 *sp24;
    s32 pad[2];

    sp24 = func_80106790();
    (*(s32 *)((s8 *)(func_801084B0(0x30E, &sp24)) + (0x3C))) = (s32) *sp24;
}

OSThread *chchuffyglow_entrypoint_1(void)
{
    extern u8 D_808005B0_chchuffyglow[];

    return (OSThread *) D_808005B0_chchuffyglow;
}
