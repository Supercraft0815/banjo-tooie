#include "common.h"

OSThread *ch1pfreeze_entrypoint_0(void)
{
    extern u8 D_80800420_ch1pfreeze[];

    return (OSThread *) D_80800420_ch1pfreeze;
}

void func_8080000C_ch1pfreeze(s32 arg0) 
{
}
/* extern */

void func_80800014_ch1pfreeze(Actor *arg0) { if ((s32) arg0->unk70_10 < 4) { func_800F7B9C(*(s32 *)func_80100094(arg0, 0), 0xF); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_80800054_ch1pfreeze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_8080014C_ch1pfreeze.s")

s32 func_80800294_ch1pfreeze(Actor *arg0, s32 arg1, s32 arg2) {
    void func_808002D0_ch1pfreeze(s16*, s32);
    switch (arg1) {
        case 0x4:
            func_808002D0_ch1pfreeze((s16 *) arg0, 0x4);
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_808002D0_ch1pfreeze.s")

/* extern */

s32 ch1pfreeze_entrypoint_1(s32 arg0) {
    f32 func_800F5F24(u32);
    Actor *sp2C;
    f32 sp20[3];
    void *temp_v0;
    void func_808002D0_ch1pfreeze(s16 *, s32);

    func_800F5A00(arg0, sp20);
    sp2C = func_80108474(0x2C5, sp20, 0);
    temp_v0 = func_80100094(sp2C, 0);
    *(s32 *)temp_v0 = arg0;
    *(f32 *)((s8 *)sp2C + 0x48) = func_800F5F24(arg0);
    func_808002D0_ch1pfreeze((s16 *)sp2C, 2);
    return (*(s32 *)((s8 *)sp2C + 0));
}
