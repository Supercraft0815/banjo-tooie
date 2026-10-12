#include "common.h"

OSThread *chklungophial_entrypoint_0(void)
{
    extern u8 D_80800C30_chklungophial[];

    return (OSThread *) D_80800C30_chklungophial;
}

OSThread *chklungophial_entrypoint_1(void)
{
    extern u8 D_80800C78_chklungophial[];

    return (OSThread *) D_80800C78_chklungophial;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_80800018_chklungophial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_80800204_chklungophial.s")

/* extern */

s32 func_8080038C_chklungophial(s32 arg0, s32 arg1, volatile s32 arg2) {
    s32 func_808003C8_chklungophial(s32, s32);
    int ret;
    if (arg1 == 0x40) {
        func_808003C8_chklungophial(arg0, 0);
        ret = 1;
    } else {
        return 0;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_808003C8_chklungophial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_808006B4_chklungophial.s")

void func_80800820_chklungophial(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_80800828_chklungophial.s")

s32 func_80800980_chklungophial(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor*, u32);
    switch (arg1) {
        case 0x4F:
            func_80101FDC(arg0, 2U);
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_808009BC_chklungophial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/phial/func_80800AEC_chklungophial.s")
