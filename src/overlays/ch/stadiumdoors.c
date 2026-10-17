#include "common.h"

void func_80800000_chstadiumdoors(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 _gcfrontend_entrypoint_9(s32);

    switch (arg0->unk74_7) {
        case 0x33:
            if (func_800DA298(0x576)) {
                arg0->unk70_10 = 3;
                arg0->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x60);
            }
            break;
        case 0x34:
            if (func_800DA298(0x5E)) {
                arg0->unk70_10 = 3;
                arg0->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x61);
            }
            break;
        case 0x35:
            if (func_800DA298(0x5F)) {
                arg0->unk70_10 = 3;
                arg0->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x62);
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stadiumdoors/func_808000FC_chstadiumdoors.s")

OSThread *chstadiumdoors_entrypoint_0(void)
{
    extern u8 D_80800280_chstadiumdoors[];

    return (OSThread *) D_80800280_chstadiumdoors;
}
