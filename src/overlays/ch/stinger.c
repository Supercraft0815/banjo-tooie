#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800000_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_8080015C_chstinger.s")

void func_80800218_chstinger(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}

void func_8080025C_chstinger(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800264_chstinger.s")

/* extern */

s32 func_808003B0_chstinger(s32 arg0) {
    s32 func_800EA068(s32);
    s32 func_800F7A7C(s32, s8, s32, s32, s32 *);
    s8 *func_80100094(s32, s32);
    s32 func_80800264_chstinger(s32, s32 *);
    s32 sp2C[3];
    s32 sp28;
    s32 temp_v0;

    if (func_800EA068(0x4000) != 0) {
        temp_v0 = func_80800264_chstinger(arg0, sp2C);
        sp28 = temp_v0;
        if (temp_v0 >= 0) {
            func_800F7A7C(sp28, *func_80100094(arg0, 0), 1, 3, sp2C);
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800420_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/chstinger_entrypoint_0.s")

s32 func_80800774_chstinger(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80109EEC(s16*, s32);
    switch (arg1) {
        case 0x95:
            func_80109EEC((s16 *) arg0, 0x10);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chstinger_entrypoint_1(void)
{
    extern u8 D_80800870_chstinger[];

    return (OSThread *) D_80800870_chstinger;
}
