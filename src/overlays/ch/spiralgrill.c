#include "common.h"

OSThread *chspiralgrill_entrypoint_0(void)
{
    extern u8 D_80800180_chspiralgrill[];

    return (OSThread *) D_80800180_chspiralgrill;
}

void func_8080000C_chspiralgrill(Actor *arg0) {
    void func_80109EEC(s16 *arg0, s32 arg1);
    void func_8010A800(Actor*, s32);
    func_8010A800(arg0, 0);
    func_80109EEC((s16 *) arg0, 0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spiralgrill/func_8080003C_chspiralgrill.s")
