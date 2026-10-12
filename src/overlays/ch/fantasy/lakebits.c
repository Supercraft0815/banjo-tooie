#include "common.h"

/* extern */

void chfantasylakebits_entrypoint_0(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    Vtx *end;

    actor = func_80106790(arg4);
    end = arg2 + arg3;
    if (arg2 < end) {
        do {
            arg2->v.cn[0] = 255;
            arg2->v.cn[1] = 255;
            arg2->v.cn[2] = 0;
            arg2++;
            arg1++;
            arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + actor->actorData[3];
        } while (arg2 < end);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/lakebits/func_8080007C_chfantasylakebits.s")

/* extern */

void func_80800300_chfantasylakebits(s32 arg0, s16 arg1) {
    s32 _idwibble_entrypoint_5(s32, s16);
    s32 _idworld_entrypoint_4(s32, s32);
    s32 func_800BEA88(s32);
    s32 temp_v0;

    temp_v0 = _idworld_entrypoint_4(func_800BEA88(1), 1);
    if (temp_v0 != 0) {
        _idwibble_entrypoint_5(temp_v0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/lakebits/func_80800344_chfantasylakebits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/lakebits/func_80800570_chfantasylakebits.s")

OSThread *chfantasylakebits_entrypoint_1(void)
{
    extern u8 D_80800A30_chfantasylakebits[];

    return (OSThread *) D_80800A30_chfantasylakebits;
}

/* extern */

void func_808006F4_chfantasylakebits(s32 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    if ((func_800DA298(0x327) != 0) || (func_800DA298(0x9FC) != 0)) {
        func_800FFA88(*arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/lakebits/func_8080073C_chfantasylakebits.s")

OSThread *chfantasylakebits_entrypoint_2(void)
{
    extern u8 D_80800AF0_chfantasylakebits[];

    return (OSThread *) D_80800AF0_chfantasylakebits;
}
