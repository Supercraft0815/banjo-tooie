#include "common.h"

void func_80800000_chcolldoors(Actor *arg0)
{
    s32 func_800DA298(s32);
    s32 flag;

    switch (arg0->unk74_7) {
        case 0x33:
            flag = func_800DA298(0x577);
            break;
        case 0x34:
            flag = func_800DA298(0x368);
            break;
        case 0x35:
            flag = func_800DA298(0x369);
            break;
    }
    if (flag) {
        arg0->position[1] += 250.0f;
        arg0->unk70_10 = 3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/colldoors/func_808000B8_chcolldoors.s")

OSThread *chcolldoors_entrypoint_0(void)
{
    extern u8 D_80800280_chcolldoors[];

    return (OSThread *) D_80800280_chcolldoors;
}
