#include "common.h"

OSThread *chelectricfence_entrypoint_0(void)
{
    extern u8 D_808004C0_chelectricfence[];

    return (OSThread *) D_808004C0_chelectricfence;
}

/* extern */

void func_8080000C_chelectricfence(s32 arg0) {
    s32 func_800EA05C();
    s32 func_80104004(s32, s32, s32);
    s32 func_8010A570(s32);
    s32 func_8010A624(s32);
    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
        func_8010A570(arg0);
    }
    func_80104004(arg0, arg0 + 0x18, arg0 + 0x28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/electricfence/func_80800060_chelectricfence.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/electricfence/func_8080010C_chelectricfence.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/electricfence/chelectricfence_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/electricfence/chelectricfence_entrypoint_2.s")
